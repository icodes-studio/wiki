# AssetBundleManager

- *https://github.com/SadPandaStudios/AssetBundleManager/tree/master*
- *Simple AssetBundle management*
- ***Main Methods***
    - ***Initialize***: Initializes the base-uri used for AssetBundle calls.
    - ***Load***: Load the platform(entry-point) manifest file.
    - ***LoadBundle***: Downloads an AssetBundle or returns a cached AssetBundle if it has already been downloaded.
    - ***UnloadBundle***: Unloads an AssetBundle.
    - ***IsVersionCached***: Check to see if a specific asset bundle is cached or needs to be downloaded.


　

## # Initialize
*public AssetBundleManager Initialize(string uri)*

- ***Description***
    - Initializes the base-uri used for AssetBundle calls.
    - The manager will load the manifest file located at base-url/[PlatformName].
- ***Parameters***
    - ***string uri***: List of base-uris.


　

## # Initialize
*public AssetBundleManager Initialize(string[] uris)*

- ***Description***
    - Initializes a list of base-uris used for AssetBundle calls.
    - The manager will load the manifest file located at base-url/[PlatformName].
    - If access to one uri is denied, the manager will try to access the next uri.
- ***Parameters***
    ***string[] uris***: List of base-uris.


　

## # Load
*public void Load(Action\<bool\> callback)*

- ***Description***
    - Load the platform(entry-point) manifest file.
    - Downloads the AssetBundle manifest and prepares the system for bundle management.
    - Uses the platform name as the manifest name.
- ***Parameters***
    - ***Action\<bool\> callback***: Called when the loading is complete.


　

## # Load
*public void Load(string manifestName, bool refresh, Action\<bool\> callback)*

- ***Description***
    - Load the platform(entry-point) manifest file.
- ***Parameters***
    - ***string manifestName***: The name of the manifest file to download.
    - ***bool refresh***: Always try to download a new manifest even if one has already been cached.
    - ***Action\<bool\> callback***: Called when the loading is complete.


　

## # LoadBundle
*public void LoadBundle(string bundleName, Action\<AssetBundle\> callback)*

- ***Description***
    - Downloads an AssetBundle or returns a cached AssetBundle if it has already been downloaded.
    - Remember to call UnloadBundle(AssetBundle, bool) for every bundle you download once you are done with it.
- ***Parameters***
    - ***string bundleName***: Name of the bundle to download.
    - ***Action\<AssetBundle\> callback***: Action to perform when the bundle has been successfully downloaded.


　

## # LoadBundle
*public void LoadBundle(string bundleName, Action\<AssetBundle\> callback, DownloadSettings downloadSettings)*

- ***Description***
    - Downloads an AssetBundle or returns a cached AssetBundle if it has already been downloaded.
    - Remember to call UnloadBundle(AssetBundle, bool) for every bundle you download once you are done with it.
- ***Parameters***
    - ***string bundleName***: Name of the bundle to download.
    - ***Action\<AssetBundle\> callback***: Action to perform when the bundle has been successfully downloaded.
    - ***DownloadSettings downloadSettings***: 
        - Tell the function to use a previously downloaded version of the bundle if available.
        - If the bundle is currently "active" (it has not been unloaded) then the active bundle will be used regardless of this setting.
        - If it's important that a new version is downloaded then be sure it isn't active.


　

## # UnloadBundle
*public void UnloadBundle(AssetBundle bundle)*

- ***Description***
    - Unloads an AssetBundle.
    - Objects that were loaded from this bundle will need to be manually destroyed.
- ***Parameters***
    - ***AssetBundle bundle***: Bundle to unload.


　

## # UnloadBundle
*public void UnloadBundle(AssetBundle bundle, bool unloadAllLoadedObjects)*

- ***Description***
    - Unloads an AssetBundle.
- ***Parameters***
    - ***AssetBundle bundle***: Bundle to unload.
    - ***bool unloadAllLoadedObjects***: 
        - When true, all objects that were loaded from this bundle will be destroyed as well.
        - If there are game objects in your scene referencing those assets, the references to them will become missing.


　

## # UnloadBundle
*public void UnloadBundle(AssetBundle bundle, bool unloadAllLoadedObjects, bool force)*

- ***Description***
    - Unloads an AssetBundle.
- ***Parameters***
    - ***AssetBundle bundle***: Bundle to unload.
    - ***bool unloadAllLoadedObjects***: 
        - When true, all objects that were loaded from this bundle will be destroyed as well.
        - If there are game objects in your scene referencing those assets, the references to them will become missing.
    - ***bool force***: Unload the bundle even if ABM believes there are other dependencies on it.


　

## # Initialized
*public bool Initialized*

- ***Description***
    - Returns whether the manager was initialized successfully or not.


　

## # Manifest
*public AssetBundleManifest Manifest*

- ***Description***
    - Returns object for the platform(entry-point) manifest.


　

## # ManifestType
*public ManifestType ManifestType*

- ***Description***
    - Returns the AssetBundle manifest type.
        - None: an error or undefined condition.
        - Remote: Download bundles remotely.
        - LocalCached: Bundle loaded from local cache.
        - StreamingAssets: Bundle loaded from StreamingAssets folder.


　

## # UseStreamingAssets
*public AssetBundleManager UseStreamingAssets()*

- ***Description***
    - Loading from Unity's StreamingAsset folder.
    - Sets the base-uri used for AssetBundle calls to the StreamingAssets folder.


　

## # UseSimulation
*public AssetBundleManager UseSimulation()*

- ***Description***
    - Loading from the Simulation folder.
    - Sets the base-uri used for AssetBundle calls to the one created by the AssetBundleBuilder when the bundles are built.
    - Used for easier testing in the editor.


　

## # SetPrioritizationStrategy
*public AssetBundleManager SetPrioritizationStrategy(PrioritizationStrategy strategy)*

- ***Description***
    - Changes the strategy used to determine what should happen when an asset bundle exists in both the StreamingAssets and the remote server.
    - The default is to prioritize the remote asset over the StreamingAssets folder
- ***Parameters***
    - ***PrioritizationStrategy strategy***
        - Remote:
        - StreamingAssets:


　

## # IsVersionCached
*public bool IsVersionCached(string bundleName)*

- ***Description***
    - Check to see if a specific asset bundle is cached or needs to be downloaded.


　

## # Dispose

- ***Description***
    - Cleans up all downloaded bundles.
