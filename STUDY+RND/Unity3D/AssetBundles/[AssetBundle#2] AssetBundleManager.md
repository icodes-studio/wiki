# AssetBundleManager
*Simple AssetBundle management*


　

## # AssetBundleManager.Initialized
*public bool Initialized*

- **Description**
    - 매니저가 성공적으로 초기화 되었는지 아닌지 반환한다.
    - 초기화 되었다는 것은 플랫폼(엔트리포인트) 매니페스트를 성공적으로 로드했다는 것을 의미한다.


　

## # AssetBundleManager.Manifest
*public AssetBundleManifest Manifest*

- **Description**
    - Object for the platform(entry-point) manifest


　

## # AssetBundleManager.ManifestType
*public ManifestType ManifestType*

- **Description**
    - 애셋번들 매니페스트 타입을 반환한다.
        - None: 에러 또는 정의되지 않는 상태
        - Remote: 원격지에서 다운로드한 번들
        - LocalCached: 로컬 캐시에서 로드한 번들
        - StreamingAssets: 스트리밍 애셋 폴더에서 로드한 번들







　

- ***References***
    - *https://github.com/SadPandaStudios/AssetBundleManager/tree/master*










        /// <summary>
        /// Initializes the base-uri used for AssetBundle calls.
        /// The manager will load the manifest file located at base-url/[PlatformName].
        /// </summary>
        /// <param name="uri">base uri</param>
        /// <returns>this</returns>
        public AssetBundleManager Initialize(string uri)
        {
            return Initialize(new[] { uri ?? string.Empty });
        }

        /// <summary>
        /// Initializes a list of base-uris used for AssetBundle calls.
        /// The manager will load the manifest file located at base-url/[PlatformName].
        /// If access to one uri is denied, the manager will try to access the next uri.
        /// </summary>
        /// <param name="uri">List of base-uris</param>
        /// <returns>this</returns>
        public AssetBundleManager Initialize(string[] uris)
        {
            baseUris = new string[uris.Length];

            for (int i = 0; i < uris.Length; i++)
            {
                var builder = new StringBuilder(uris[i]);

                if (uris[i].EndsWith("/") == false)
                    builder.Append("/");

                builder.Append(platformName).Append("/");
                baseUris[i] = builder.ToString();
            }

            return this;
        }

        /// <summary>
        /// Load the platform(entry-point) manifest file.
        /// Downloads the AssetBundle manifest and prepares the system for bundle management.
        /// Uses the platform name as the manifest name.
        /// </summary>
        /// <param name="callback">Called when the loading is complete</param>
        public void Startup(Action<bool> callback)
        {
            Startup(platformName, true, callback);
        }

        /// <summary>
        /// Load the platform(entry-point) manifest file.
        /// </summary>
        /// <param name="manifestName">The name of the manifest file to download.</param>
        /// <param name="refresh">Always try to download a new manifest even if one has already been cached.</param>
        /// <param name="callback">Called when the loading is complete</param>
        public void Startup(string manifestName, bool refresh, Action<bool> callback)
        {
            if (baseUris == null || baseUris.Length == 0)
                throw new Exception("You need to set the base uri before you can initialize.");

            LoadManifest(manifestName, refresh, bundle => callback(bundle != null));
        }

        /// <summary>
        /// Load the platform(entry-point) manifest file.
        /// </summary>
        /// <param name="manifestName">Manifest name</param>
        /// <param name="refresh">Load without using cache or not</param>
        /// <param name="callback">Callback to be called when loading is complete</param>
        private void LoadManifest(string manifestName, bool refresh, Action<AssetBundle> callback)
        {
            if (downloadCallbacks.TryGetValue(ManifestDownloadKey, out var downloadCallback))
            {
                downloadCallback.References++;
                downloadCallback.OnComplete += callback;
                return;
            }

            downloadCallbacks.Add(ManifestDownloadKey, new AssetBundleDownloadCallback(callback));
            ManifestType = ManifestType.Remote;

            uint manifestVersion = 1;

            if (refresh)
            {
                manifestVersion = (uint)PlayerPrefs.GetInt(ManifestVersionKey, 0) + 1;
                while (Caching.IsVersionCached(manifestName, new Hash128(0, 0, 0, manifestVersion)))
                {
                    manifestVersion++;
                }
            }

            LoadManifest(manifestName, manifestVersion, 0);
        }

        /// <summary>
        /// Load the platform(entry-point) manifest file.
        /// </summary>
        /// <param name="manifestName">Manifest name</param>
        /// <param name="version">Local cached version</param>
        /// <param name="index">Index for base-uris</param>
        private void LoadManifest(string manifestName, uint version, int index)
        {
            downloader = new AssetBundleDownloader(baseUris[index]);

            if (Application.isEditor == false)
            {
                downloader = new AssetBundleDownloaderStreamingAsset(
                    manifestName,
                    platformName,
                    downloader,
                    defaultPriority);
            }

            downloader.Handle(new AssetBundleDownloadCommand
            {
                BundleName = manifestName,
                Version = version,
                OnComplete = manifest =>
                {
                    var max = baseUris.Length - 1;
                    if (manifest == null && index < max && version > 1)
                    {
                        Debug.LogFormat($"Unable to download manifest from [{baseUris[index]}], attempting [{baseUris[index + 1]}]");
                        LoadManifest(manifestName, version, index + 1);
                    }
                    else if (manifest == null && index >= max && version > 1 && ManifestType != ManifestType.LocalCached)
                    {
                        ManifestType = ManifestType.LocalCached;
                        Debug.LogFormat($"Unable to download manifest, attempting to use one previously downloaded (version [{version}]).");
                        LoadManifest(manifestName, version - 1, index);
                    }
                    else
                    {
                        OnLoadManifest(manifest, manifestName, version);
                    }
                }
            });
        }

        /// <summary>
        /// Called when the manifest has finished loading, whether successful or not.
        /// </summary>
        /// <param name="manifest">AssetBundle object for the loaded manifest</param>
        /// <param name="manifestName">Name of loaded manifest</param>
        /// <param name="version">Version of loaded manifest</param>
        private void OnLoadManifest(AssetBundle manifest, string manifestName, uint version)
        {
            if (manifest == null)
            {
                Debug.LogError("AssetBundleManifest not found.");

                var streamingAssetsDownloader = downloader as AssetBundleDownloaderStreamingAsset;
                if (streamingAssetsDownloader != null)
                {
                    ManifestType = ManifestType.StreamingAssets;
                    Manifest = streamingAssetsDownloader.GetManifest();

                    if (Manifest != null)
                    {
                        Debug.LogWarning("Falling back to streaming assets for bundle information.");
                    }
                }
            }
            else
            {
                Manifest = manifest.LoadAsset<AssetBundleManifest>("assetbundlemanifest");
                PlayerPrefs.SetInt(ManifestVersionKey, (int)version);
                Caching.ClearOtherCachedVersions(manifestName, new Hash128(0, 0, 0, version));
            }

            if (Manifest == null)
            {
                ManifestType = ManifestType.None;
            }
            else
            {
                Initialized = true;
            }

            var callback = downloadCallbacks[ManifestDownloadKey];
            downloadCallbacks.Remove(ManifestDownloadKey);
            callback.OnComplete?.Invoke(manifest);
            manifest?.Unload(false);
        }

        /// <summary>
        /// Loading from Unity's StreamingAsset folder.
        /// Sets the base-uri used for AssetBundle calls to the StreamingAssets folder.
        /// </summary>
        public AssetBundleManager UseStreamingAssets()
        {
#if UNITY_ANDROID
            var url = $"{Application.streamingAssetsPath}/{AssetBundleUtility.AssetFolder}/";
#else
            var url = $"file:///{Application.streamingAssetsPath}/{AssetBundleUtility.AssetFolder}/";
#endif
            return Initialize(new[] { url });
        }

        /// <summary>
        /// Loading from the Simulation folder.
        /// Sets the base-uri used for AssetBundle calls to the one created by the AssetBundleBuilder when the bundles are built.
        /// Used for easier testing in the editor
        /// </summary>
        public AssetBundleManager UseSimulation()
        {
            return Initialize(new[] { $"file://{Application.dataPath}/../{AssetBundleUtility.AssetFolder}/" });
        }

        /// <summary>
        /// Implementing Dispose
        /// Unload(true) for all loaded AssetBundles
        /// </summary>
        public void Dispose()
        {
            foreach (var cache in activeBundles.Values)
                cache.AssetBundle?.Unload(true);

            activeBundles.Clear();
        }
    }
}
