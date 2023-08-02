# AssetBundleManager

- *Simple AssetBundle management*
- *https://github.com/SadPandaStudios/AssetBundleManager/tree/master*


　

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


　

## # Startup
*public void Startup(Action<bool> callback)*

- ***Description***
    - Load the platform(entry-point) manifest file.
    - Downloads the AssetBundle manifest and prepares the system for bundle management.
    - Uses the platform name as the manifest name.

- ***Parameters***
    - ***Action\<bool\> callback***: Called when the loading is complete.


　

## # Startup
*public void Startup(string manifestName, bool refresh, Action<bool> callback)*

- ***Description***
    - Load the platform(entry-point) manifest file.

- ***Parameters***
    - ***string manifestName***: The name of the manifest file to download.
    - ***bool refresh***: Always try to download a new manifest even if one has already been cached.
    - ***Action\<bool\> callback***: Called when the loading is complete.


　

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


　

## # Dispose

- ***Description***
    - Cleans up all downloaded bundles.

