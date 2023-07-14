## # Overview

- ***AssetBundles***
    - 플랫폼별 비코드 애셋(예: 모델, 텍스처, 프리팹, 오디오 클립, 씬 전체)이 들어 있는 아카이브 파일이며 런타임 시점에 로드할 수 있다.
    - 서로 종속성을 가질 수 있다. 예를 들어 한 애셋번들의 머티리얼이 다른 애셋번들의 텍스처를 참조할 수 있다.
    - 효율적인 네트워크 전송을 위해 빌트인 알고리즘을(LZMA 및 LZ4) 사용하여 압축할 수 있다.
    - 초기 설치 크기를 줄이고, 언로드를 통해 런타임 메모리의 압박을 줄일 수 있다.


　

## # AssetBundle workflow

- ***Note***
    - 여기서는 빌트인 ***BuildPipeline.BuildAssetBundles()*** API를 사용하여 애셋번들을 생성하는 방법을 설명한다.
    - 권장되는 방법은 [***어드레서블 패키지(Addressables package)***](https://docs.unity3d.com/Packages/com.unity.addressables@1.21/manual/index.html)를 사용하는 것이다.
- ***Assigning Assets to AssetBundles***
    - 프로젝트 뷰에서 번들에 할당할 애셋을 선택.
    - 인스펙터 하단에 왼쪽 드롭다운을 사용하여 ***애셋번들 이름을*** 지정하고, 오른쪽 드롭다운을 사용하여 ***배리언트(Variant)***를 지정.
    - 새 애셋번들 이름을 생성 하려면 ***New*** 버튼 클릭하고 이름 입력.
    - 하위 폴더를 추가하려면 /를 이용해 폴더 이름을 구분한다.
- ***Build the AssetBundles***
    - ***Assets*** 폴더에서 ***Editor*** 폴더를 생성하고, 폴더에 다음과 같은 콘텐츠의 스크립트를 입력합니다.
        ```
        using UnityEditor;
        using System.IO;

        public class CreateAssetBundles
        {
            [MenuItem("Assets/Build AssetBundles")]
            static void BuildAllAssetBundles()
            {
                string assetBundleDirectory = "Assets/AssetBundles";
                if (Directory.Exists(assetBundleDirectory) == false)
                    Directory.CreateDirectory(assetBundleDirectory);

                BuildPipeline.BuildAssetBundles(
                    assetBundleDirectory,
                    BuildAssetBundleOptions.None,
                    BuildTarget.StandaloneWindows);
            }
        }
        ```
    - 이 스크립트는 Assets 메뉴 하단에 작성한 코드를 실행하는 ***Build AssetBundles*** 메뉴 아이템을 생성한다.
    - Build AssetBundles 항목을 클릭하면 빌드 다이얼로그와 함께 진행 표시줄이 표시된다.
    - 이렇게 하면 애셋번들 이름으로 레이블이 지정된 모든 애셋을 가져와서 assetBundleDirectory에 정의된 경로의 폴더에 배치한다.
- ***Loading AssetBundles and Assets***
    - 로컬 스토리지에서 로드하려는 경우 ***AssetBundles.LoadFromFile*** API를 사용한다.
        ```
        public class LoadFromFileExample : MonoBehaviour
        {
            void Start()
            {
                var myLoadedAssetBundle = AssetBundle.LoadFromFile(
                    Path.Combine(Application.streamingAssetsPath, "myassetBundle"));

                if (myLoadedAssetBundle == null)
                {
                    Debug.Log("Failed to load AssetBundle!");
                    return;
                }
                var prefab = myLoadedAssetBundle.LoadAsset<GameObject>("MyObject");
                Instantiate(prefab);
            }
        }
        ```
    - 원격지로부터 로드하거나 로컬 파일에 바로 접근할 수 없는 플랫폼의 경우 ***UnityWebRequestAssetBundle*** API를 사용한다.
        ```
        IEnumerator InstantiateObject()
        {
            string url = "file:///" + Application.dataPath + "/AssetBundles/" + assetBundleName;
            var request = UnityEngine.Networking.UnityWebRequestAssetBundle.GetAssetBundle(url, 0);
            yield return request.Send();
            AssetBundle bundle = UnityEngine.Networking.DownloadHandlerAssetBundle.GetContent(request);
            GameObject cube = bundle.LoadAsset<GameObject>("Cube");
            GameObject sprite = bundle.LoadAsset<GameObject>("Sprite");
            Instantiate(cube);
            Instantiate(sprite);
        }
        ```


　

## # Preparing Assets for AssetBundles

- ***Note***
    - There are certain strategies to consider when setting up your bundles.
    - These grouping strategies are meant to be used however you see fit for your specific project.
    - Feel free to mix and match these strategies as you see fit.
- ***Logical Entity Grouping***
    - 프로젝트 관점에서, 애셋의 기능적인 부분에 따라 애셋번들을 그룹핑 하는 방법.
    - 여기에는 사용자 인터페이스, 캐릭터, 환경, 그리고 애플리케이션 라이프 사이클 내내 자주 나타날 수 있는 모든 것이 포함된다.
    - 모든 것이 컨텐츠에 따라 논리적으로 구분되어 있으므로 ***DLC(DownLoadable Content)*** 방식에 적합하다.
    - 번들을 만드는 개발자가 프로젝트와 컨텐츠의 구현에 대해(애셋이 사용되는 시기와 위치) 정확히 알고 있어야 한다.
    - ***Examples***
        - 사용자 인터페이스 화면의 모든 텍스처 및 레이아웃 데이터 번들링
        - 캐릭터에 대한 모든 모델 및 애니메이션 번들링
        - 게임 레벨 스테이지 간에 공통으로 사용되는 배경에 대한 텍스쳐 및 모델 데이터 번틀링
- ***Type Grouping***
    - 오디오 트랙이나 언어팩 파일 등 타입이 비슷한 애셋을 하나의 애셋번들에 할당한다.
    - 여러 플랫폼에서 사용될 애셋번들을 빌드하는 데 상대적으로 효과적인 전략 중 하나이다.
- ***Concurrent Content Grouping***
    - 동시에 로드되고 사용될 애셋을 하나의 번들로 묶는 개념. 가장 일반적인 이용 사례는 씬 기반 번들.
    - 애셋번들 내 한 애셋이 해당 번들의 다른 애셋에 동시에 사용된다는 것을 확신하는 경우.
    - 번들에 포함된 애셋 하나에 종속성이 있으면 로드 시간이 크게 증가한다.
- ***Here are some additional tips that are good to keep in mind across the board:***
    - 자주 업데이트되는 오브젝트는 변경 빈도가 낮은 오브젝트와 별개의 애셋번들로 나누어라.
    - 동시에 로드될 가능성이 큰 오브젝트(모델, 텍스처 및 애니메이션 등)를 그룹화하라.
    - 애셋번들 간에 공통으로 사용하는 애셋은 별도의 공용 애셋번들로 종속성을 옮겨라.
    - SD 또는 HD 애셋처럼 두 오브젝트 집합이 동시에 로드될 가능성이 거의 없는 경우 각기 다른 애셋번들로 나누어라.
    - 오브젝트 그룹이 단순히 같은 오브젝트의 다른 버전에 불과할 경우, 애셋번들 배리언트(Variant)를 고려하라.


　

## # Building AssetBundles

- ***Note***
    - This section describes the creation of AssetBundles using the built-in ***BuildPipeline.BuildAssetBundles()*** API.
    - A recommended, and more user friendly, alternative is to use the ***[Addressables](http://docs.unity3d.com/Packages/com.unity.addressables@latest/index.html)*** package.
- ***[BuildAssetBundleOptions](https://docs.unity3d.com/kr/2022.3/ScriptReference/BuildAssetBundleOptions.html)***
    - ***BuildAssetBundleOptions.None***
        - ***LZMA*** 압축 포맷을 사용한다.
        - ***LZMA*** 압축된 번들을 사용하기 위해서는 먼저 전체 번들의 압축을 해제해야 한다. 
        - 따라서 파일 크기는 가장 작아지지만, 압축 해제 때문에 로드 시간이 조금 길어지게 된다. 
        - ***LZMA*** 압축을 사용하는 것은 파일 크기가 작기 때문에 외부 호스트에서 AssetBundle을 다운로드하는 경우만 권장된다.
        - ***LZMA*** 애셋번들이 로드되어 압축 해제되면 이어서 자동으로 ***LZ4*** 압축으로 다시 압축되고 로컬 파일 시스템에 캐시된다.
    - ***BuildAssetBundleOptions.UncompressedAssetBundle***
        - 압축되지 않는 방식으로 번들을 빌드한다. 
        - 다운로드할 파일 크기가 크다는 단점이 있지만, 다운로드된 파일을 로드하는 속도는 빠르다.
    - ***BuildAssetBundleOptions.ChunkBasedCompression***
        - ***LZ4*** 압축 메서드를 사용한다.
        - LZMA 압축 포맷보다 압축된 파일 크기가 크지만 애셋을 사용하기 전에 모든 번들의 압축을 풀 필요가 없어 좀 더 빠르다.
        - 또한 압축되지 않은 번들과 비슷한 로드 속도를 가지게 되지만 디스크의 용량은 적게 차지한다.
- [***BuildTarget***](https://docs.unity3d.com/kr/2022.3/ScriptReference/BuildTarget.html)
    - 애셋번들을 사용할 타겟 플랫폼이 무엇인지 빌드 파이프라인에 알려준다.
    - 애셋번들마다 애셋번들의 이름으로된 파일과 애셋번들 이름 + “.manifest”로 된 파일이 생성된다.
    - To learn more about how to use this bundle and the manifest object, see documentation on [***Using AssetBundles Natively***](https://docs.unity3d.com/kr/2022.3/Manual/AssetBundles-Native.html).
- ***The AssetBundle File***
    - 애셋번들 파일은 다수의 파일을 내부적으로 포함하는 아카이브.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundles-Building-0.png)
- ***The Manifest File***
    - 번들에 대한 CRC(Cyclic Redundancy Check) 데이터 및 종속성 데이터와 같은 정보가 포함된다. 
        ```
        ManifestFileVersion: 0
        CRC: 2422268106
        Hashes:
        AssetFileHash:
            serializedVersion: 2
            Hash: 8b6db55a2344f068cf8a9be0a662ba15
        TypeTreeHash:
            serializedVersion: 2
            Hash: 37ad974993dbaa77485dd2a0c38f347a
        HashAppended: 0
        ClassTypes:
        - Class: 91
        Script: {instanceID: 0}
        Assets:
        Asset_0: Assets/Mecanim/StateMachine.controller
        Dependencies: {}
        ```
    - A manifest file is also generated for the Manifest Bundle.
    - This file records how AssetBundles relate, and what their dependencies are.
        ```
        ManifestFileVersion: 0
        AssetBundleManifest:
        AssetBundleInfos:
            Info_0:
            Name: scene1assetbundle
            Dependencies: {}
        ```


　

## # AssetBundle Dependencies

- ***Note***
    - Objects 중 하나 이상이 다른 번들에 있는 Object에 대한 참조를 포함하는 경우 해당 애셋번들은 다른 애셋번들에 종속성이 생긴다.
    - 하지만, 애셋번들에 포함되지 않은 Object에 대한 참조를 하는 경우는 종속성이 발생하지 않는다. 단순 복사된다.
    - Unity 엔진은 이러한 애셋번들 간의 종속성을 자동으로 로딩하지 않는다.
- ***Consider the following example, a Material in Bundle 1 references a Texture in Bundle 2:***
    - 번들 1에 있는 머티리얼을 로딩하기 전에 번들 2를 메모리에 로딩해야 한다. 
    - 번들 1과 번들 2를 로딩하는 순서는 중요하지 않다.
    - 중요한 것은 번들 1 의 머티리얼이 로딩되기 이전에 번들 2 가 로딩되어야만 한다는 것이다.
- ***Duplicated information across AssetBundles***
    - 기본적으로 Unity는 애셋번들 간의 중복 정보를 최적화하지 않는다.
    - 즉 프로젝트의 여러 애셋번들에 동일한 정보(예: 여러 프리팹에서 사용되는 머티리얼)가 포함될 수 있음을 의미한다.
    - 이러한 공통 애셋은 메모리 리소스와 로딩 시간에 영향을 미칠 수 있다.
- ***Editor setup***
    - 위와 같은 상황을 실제로 테스트 해보면 각 번들의 크기는 각각 ***383KB***와 ***377KB***이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundleDuplicate.png)
    - 반면, 머티리얼 등과 같은 공통 애셋을 별도 애셋번들로 만들고 빌드하면,
    - 공용 번들인 modulematerials AssetBundle(359KB)이 새로 포함되고 각 번들의 크기는 약 380KB에서 약 20KB로 감소.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundleSeparate.png)
- ***Runtime loading***
    - 공용 애셋을 단일 애셋번들로 만들어 사용하는 경우 종속성에 주의해서 로드해야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/MaterialNotLoaded.png)
    - 이 문제를 해결하려면 모듈 애셋번들을 로드하기 전에 머티리얼 애셋번들을 로드해야 한다.
        ```
        using System.IO;
        using UnityEngine;

        public class InstantiateAssetBundles : MonoBehaviour
        {
            void Start()
            {
                var materialsAB = AssetBundle.LoadFromFile(
                    Path.Combine(Application.dataPath, Path.Combine("AssetBundles", "modulesmaterials")));

                var moduleAB = AssetBundle.LoadFromFile(
                    Path.Combine(Application.dataPath, Path.Combine("AssetBundles", "example-prefab")));

                if (moduleAB == null)
                {
                    Debug.Log("Failed to load AssetBundle!");
                    return;
                }
                var prefab = moduleAB.LoadAsset<GameObject>("example-prefab");
                Instantiate(prefab);
            }
        }
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/MaterialLoaded.png)


　

## # Using AssetBundles Natively

- ***애셋 번들 로드 API***
    - [***AssetBundle.LoadFromMemoryAsync***](https://docs.unity3d.com/ScriptReference/AssetBundle.LoadFromMemoryAsync.html?_ga=1.226802969.563709772.1479226228)
    - [***AssetBundle.LoadFromFile***](https://docs.unity3d.com/ScriptReference/AssetBundle.LoadFromFile.html?_ga=1.259297550.563709772.1479226228)
    - [***WWW.LoadfromCacheOrDownload***](https://docs.unity3d.com/ScriptReference/WWW.LoadFromCacheOrDownload.html?_ga=1.226802969.563709772.1479226228)
    - [***UnityWebRequestAssetBundle***](https://docs.unity3d.com/ScriptReference/Networking.UnityWebRequestAssetBundle.html?_ga=1.259297550.563709772.1479226228)의 [***DownloadHandlerAssetBundle(Unity 5.3 이상)***](https://docs.unity3d.com/ScriptReference/Networking.DownloadHandlerAssetBundle.html?_ga=1.264500235.563709772.1479226228)


- [***AssetBundle.LoadFromMemoryAsync***](https://docs.unity3d.com/ScriptReference/AssetBundle.LoadFromMemoryAsync.html?_ga=1.226802969.563709772.1479226228)
    - 애셋번들 데이터가 포함된 바이트 배열을 사용한다.
    - 번들이 LZMA로 압축된 경우 애셋번들 로드 중에 압축을 해제. LZ4로 압축된 번들은 압축된 상태로 로드.
        ```
        using UnityEngine;
        using System.Collections;
        using System.IO;

        public class Example : MonoBehaviour
        {
            IEnumerator LoadFromMemoryAsync(string path)
            {
                AssetBundleCreateRequest createRequest = AssetBundle.LoadFromMemoryAsync(File.ReadAllBytes(path));
                yield return createRequest;
                AssetBundle bundle = createRequest.assetBundle;
                var prefab = bundle.LoadAsset<GameObject>("MyObject");
                Instantiate(prefab);
            }
        }
        ```
- [***AssetBundle.LoadFromFile***](https://docs.unity3d.com/ScriptReference/AssetBundle.LoadFromFile.html?_ga=1.259297550.563709772.1479226228)
    - 이 API는 로컬 스토리지에서 압축되지 않은 번들을 로드할 때 매우 효율적이다.
    - LoadFromFile은 번들이 압축되지 않았거나 청크(LZ4) 압축된 경우 번들을 디스크에서 직접 로드한다.
    - 전체가 압축된(LZMA) 번들을 이 메서드로 로드하면 번들을 메모리에 로드하기 전에 압축이 해제된다.
        ```
        using System.IO;
        using UnityEngine;

        public class LoadFromFileExample : MonoBehaviour
        {
            void Start()
            {
                var myLoadedAssetBundle = AssetBundle.LoadFromFile(
                    Path.Combine(Application.streamingAssetsPath, "myassetBundle"));

                if (myLoadedAssetBundle == null)
                {
                    Debug.Log("Failed to load AssetBundle!");
                    return;
                }
                var prefab = myLoadedAssetBundle.LoadAsset<GameObject>("MyObject");
                Instantiate(prefab);
            }
        }
        ```
- [***UnityWebRequestAssetBundle***](https://docs.unity3d.com/ScriptReference/Networking.UnityWebRequestAssetBundle.html?_ga=1.259297550.563709772.1479226228)
    - 애셋번들을 처리하는 전용 API.
        ```
        using UnityEngine.Networking;

        IEnumerator InstantiateObject()
        {
            string uri = "file:///" + Application.dataPath + "/AssetBundles/" + assetBundleName; 
            UnityWebRequestAssetBundle request = UnityWebRequestAssetBundle.GetAssetBundle(uri, 0);
            yield return request.SendWebRequest();
            AssetBundle bundle = DownloadHandlerAssetBundle.GetContent(request);
            GameObject cube = bundle.LoadAsset<GameObject>("Cube");
            GameObject sprite = bundle.LoadAsset<GameObject>("Sprite");
            Instantiate(cube);
            Instantiate(sprite);
        }
        ```
- **Loading Assets from AssetBundles**
    - 애셋번들로부터 애셋 로드하기
        ```
        T objectFromBundle = bundleObject.LoadAsset<T>(assetName);
        ```
    - ***LoadAsset*** 및 ***LoadAllAssets*** 각각에 Async를 추가한 ***LoadAssetAsync*** 또는 ***LoadAllAssetsAsync***를 선택할 수 있다.
    - 동기 방식으로 애셋 하나 로드하기
        ```
        GameObject gameObject = loadedAssetBundle.LoadAsset<GameObject>(assetName);
        ```
    - 동기 방식으로 모든 애셋 로드하기
        ```
        Unity.Object[] objectArray = loadedAssetBundle.LoadAllAssets();
        ```
    - 비동기 방식으로 애셋 하나 로드하기
        ```
        AssetBundleRequest request = loadedAssetBundleObject.LoadAssetAsync<GameObject>(assetName);
        yield return request;
        var loadedAsset = request.asset;
        ```
    - 비동기 방식으로 모든 애셋 로드하기
        ```
        AssetBundleRequest request = loadedAssetBundle.LoadAllAssetsAsync();
        yield return request;
        var loadedAssets = request.allAssets;
        ```
- ***Loading AssetBundle Manifests***
    - 애셋번들의 종속성을 다루는 경우에 애셋번들 매니페스트를 로드하면 매우 유용할 수 있다.
        ```
        AssetBundle assetBundle = AssetBundle.LoadFromFile(manifestFilePath);
        AssetBundleManifest manifest = assetBundle.LoadAsset<AssetBundleManifest>("AssetBundleManifest");
        ```
    - 매니페스트 오브젝트를 통해 ***AssetBundleManifest*** API를 호출하여 애셋번들에 대한 정보를 얻을 수 있다.
    - 이 정보에는 에셋 번들에 대한 종속성 데이터, 해시 데이터 및 배리언트 데이터가 포함된다.
    - 아래 코드에서는 이름이 ***“assetBundle”***인 애셋번들의 종속성을 모두 로드한다고 가정하자.
        ```
        AssetBundle assetBundle = AssetBundle.LoadFromFile(manifestFilePath);
        AssetBundleManifest manifest = assetBundle.LoadAsset<AssetBundleManifest>("AssetBundleManifest");
        string[] dependencies = manifest.GetAllDependencies("assetBundle");
        foreach(string dependency in dependencies)
        {
            AssetBundle.LoadFromFile(Path.Combine(assetBundlePath, dependency));
        }
        ```


　

## # Managing Loaded AssetBundles

- ***Note:*** *애셋번들을 직접 관리하기보다 [**어드레서블 애셋**](https://docs.unity3d.com/Packages/com.unity.addressables@1.21/manual/index.html) 사용을 권장합니다.*
- ***See also:*** *Unity 학습 튜토리얼 참고 - [**Managing Loaded AssetBundles**](https://learn.unity.com/tutorial/assets-resources-and-assetbundles#Managing_Loaded_Assets)*

- ***AssetBundle.Unload***
    - Unity에서는 오브젝트가 액티브 씬에서 제거될 경우 자동으로 언로드되지 않습니다.
    - 에셋 정리는 특정 시간에 실행되고, 수동으로 실행할 수도 있습니다.
    - 에셋 번들을 로드하고 언로드할 시기를 아는 것은 중요합니다.
    - 에셋 번들을 잘못 언로드하면 메모리에 오브젝트가 중복으로 저장되거나 텍스처가 누락되는 등의 바람직하지 않은 상황이 발생할 수 있습니다.
    - 에셋 번들 관리에 대해 알아야 하는 가장 중요한 것은 AssetBundle.Unload(bool) 또는 AssetBundle.UnloadAsync(bool)을 호출해야 하는 시기입니다.
    - 그리고 true 또는 false를 함수 호출에 전달해야 하는지 여부도 중요합니다.
    - 언로드는 에셋 번들을 언로드하는 함수로, 정적이지 않습니다.
    - 이 API는 호출되는 에셋 번들의 헤더 정보를 언로드합니다.
    - 인수는 에셋 번들에서 인스턴스화하는 모든 오브젝트도 언로드해야 하는지 나타냅니다.
    - AssetBundle.Unload(true)는 AssetBundle에서 로드된 모든 게임 오브젝트 및 해당 종속성을 언로드합니다.
    - 복사된 게임 오브젝트(예: 인스턴스화된 게임 오브젝트)는 더 이상 AssetBundle에 속하지 않기 때문에 여기에 포함되지 않습니다.
    - 이러한 경우가 발생하면 해당 AssetBundle에서 로드되고 여기에 여전히 속해 있는 텍스처가 씬의 게임 오브젝트에서 사라지고 Unity에서 누락 텍스처로 취급됩니다.
    - 아래 그림과 같이 머티리얼 M이 에셋 번들 AB에서 로드되어 프리팹 P에서 사용된다고 가정해 보겠습니다.
    - AB.Unload(true)가 호출될 경우 액티브 씬에 있는 M의 모든 인스턴스도 언로드되고 제거됩니다.
    - AB.Unload(false)를 대신 호출할 경우 M과 AB의 현재 인스턴스 체인이 끊어집니다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundles-Native-1.png)
    - 나중에 AB가 다시 로드되고 AB.LoadAsset()이 호출될 경우, Unity는 M의 기존 복사본을 새로 로드된 머티리얼에 다시 연결하지 않습니다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundles-Native-2.png)
    - 프리팹 P의 다른 인스턴스를 생성한 경우 M의 기존 복사본을 사용하지 않습니다. 대신 M 복사본 두 개가 로드됩니다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundles-Native-3.png)
    - AssetBundle.Unload(false)를 사용하면 일반적으로 이상적인 상황으로 이어지지 않습니다.
    - 대부분의 프로젝트에서는 AssetBundle.Unload(true)를 사용하고 오브젝트가 중복되지 않도록 하는 메서드를 채택해야 합니다.
    - 일반적으로 다음 두 가지 메서드가 사용됩니다.
        - 애플리케이션 수명 중에 임시 에셋 번들이 언로드되는 시점(예: 레벨 간 또는 화면 로딩 중)을 분명히 정의하는 방법
        - 개별 오브젝트에 대해 레퍼런스 카운트를 유지하고 모든 구성 오브젝트가 사용되지 않을 때만 에셋 번들을 언로드하는 방법. 이 방법을 사용하면 애플리케이션이 메모리 중복 없이 개별 오브젝트를 언로드하고 다시 로드할 수 있습니다.
    - 애플리케이션이 AssetBundle.Unload(false)를 사용해야 하는 경우 개별 오브젝트를 다음 두 가지 방법으로만 언로드할 수 있습니다.
        - 원치 않는 오브젝트에 대한 모든 레퍼런스를 씬과 코드에서 모두 제거하는 방법. 이 작업을 수행한 후 Resources.UnloadUnusedAssets를 호출합니다.
        - 씬을 추가하지 않고 로드하는 방법. 이 방법을 사용하면 현재 씬의 모든 오브젝트가 제거되고 Resources.UnloadUnusedAssets이 자동으로 호출됩니다.








　

　

　

　

　

- https://docs.unity3d.com/Manual/AssetBundlesIntro.html
- https://medium.com/dreamarofficial/using-assetbundles-in-your-next-game-or-application-9899251a998e
- https://planek.tistory.com/22

　

- https://young-94.tistory.com/11
- https://kukuta.tistory.com/192

　

　

- Unity Blog Addressable 소개 : https://blogs.unity3d.com/kr/2019/07/15/addressable-asset-system/
- Unity Addressable 1.13 메뉴얼 : https://docs.unity3d.com/Packages/com.unity.addressables@1.13/manual/index.html
- Unity Addressable Tutorial : https://learn.unity.com/tutorials/?k=%5B%22lang%3Aen%22%2C%22lang%3Ako%22%2C%22q%3Aaddressable%22%5D&ob=starts

　

　

- [Official: 어드레서블 애셋 시스템](https://blog.unity.com/kr/games/addressable-asset-system)
- [Official: Addressables-Sample](https://github.com/Unity-Technologies/Addressables-Sample)

　

　

- https://www.youtube.com/playlist?list=PLmRK0lH8TNCo7K4xmLpEov4llbVTwf29s

- [유니티(Unity) - Addressable(어드레서블) 사용법(1). 설치 및 준비](https://blog.naver.com/cdw0424/221636733877)
- [유니티(Unity) - Addressable(어드레서블) 사용법(2). 애셋 로드](https://blog.naver.com/cdw0424/221636783259)
- [유니티(Unity) - Addressable(어드레서블) 사용법(3). 프로파일러와 디버깅](https://blog.naver.com/cdw0424/221636822258)
- [유니티(Unity) - Addressable(어드레서블) 사용법(4). 애셋 언로드](https://blog.naver.com/cdw0424/221637349195)
- [유니티(Unity) - Addressable(어드레서블) 사용법(5). 씬 로드와 언로드](https://blog.naver.com/cdw0424/221637763395)
- [유니티(Unity) - Addressable(어드레서블) 사용법(6). 빌드 후 실제 사용](https://blog.naver.com/cdw0424/221638017138)
- [유니티(Unity) - Addressable(어드레서블) 사용법(7). 서버에서 다운로드하기 1편](https://blog.naver.com/cdw0424/221755856111)
- [유니티(Unity) - Addressable(어드레서블) 사용법(8). 서버에서 다운로드하기 2편 - Catalog 이해](https://blog.naver.com/cdw0424/221756844361)
- [유니티 엔진 유니티(Unity) - Addressable(어드레서블) 사용법(9). 서버에서 다운로드하기 3편](https://blog.naver.com/cdw0424/221764918184)
- [유니티 엔진 유니티(Unity) - Addressable(어드레서블) 사용법(10). 외부 서버 없이 서버 기능 테스트하기.](https://blog.naver.com/cdw0424/222090659316)

　

- [유니티(Unity) - Addressables(어드레서블) 애셋](https://blog.naver.com/cdw0424/221630503021)
- [유니티(Unity) - Addressables.MergeMode](https://blog.naver.com/cdw0424/221637975547)
- [유니티(Unity) - Addressables.DownloadDependenciesAsync(오브젝트에 종속된 애셋들 가져오기)](https://blog.naver.com/cdw0424/221651296509)
- [유니티(Unity) - 어드레서블(Addressables)로 게임시작시 콘텐츠 다운로드 하는 법](https://blog.naver.com/cdw0424/221715381599)
- [유니티(Unity) - 어드레서블 소개 영상보기](https://blog.naver.com/cdw0424/221721464836)
- [유니티(Unity) - 어드레서블 LoadAssetAsync() 사용법 영상보기](https://blog.naver.com/cdw0424/221725042422)
- [유니티(Unity) - 어드레서블(2) InstantiateAsync() 사용법 영상보기](https://blog.naver.com/cdw0424/221748882936)
- [유니티(Unity) - 어드레서블(3) ReleaseInstance()사용법 영상 보기](https://blog.naver.com/cdw0424/221751617965)
- [유니티(Unity) - 어드레서블 안드로이드 머티리얼 문제 발생 시](https://blog.naver.com/cdw0424/221754866636)
- [유니티(Unity) - 어드레서블(4) 서버와 함께 사용하기! (영상 보기)](https://blog.naver.com/cdw0424/221782318097)
- [유니티(Unity) - 어드레서블 보라색 머티리얼 문제](https://blog.naver.com/cdw0424/222102502420)
- [어드레서블 동기식 표현 지원](https://blog.naver.com/cdw0424/222431929501)
- [유니티(Unity) - Addressable(어드레서블) DownloadDependenciesAsync 경로](https://blog.naver.com/cdw0424/222593119206)

　

　

　

　

　

　

　

　

　

　

　

　

- [사원수 공부 자료](https://blog.naver.com/cdw0424/221787035761)