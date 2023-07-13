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
        - 이 번들 옵션은 LZMA 압축 포맷을 사용한다.
        - LZMA 압축된 번들을 사용하기 위해서는 먼저 전체 번들의 압축을 해제해야 한다. 
        - 따라서 파일 크기는 가장 작아지지만, 압축 해제 때문에 로드 시간이 조금 길어지게 된다. 
        - LZMA 압축을 사용하는 것은 파일 크기가 작기 때문에 외부 호스트에서 AssetBundle을 다운로드하는 경우만 권장된다.
        - UnityWebRequestAssetBundle을 통해 로드된 LZMA 압축 애셋번들은 자동으로 LZ4 압축으로 다시 압축되고 로컬 파일 시스템에 캐시된다.
    - ***BuildAssetBundleOptions.UncompressedAssetBundle**
        - 전혀 압축되지 않는 방식으로 번들을 빌드한다. 
        - 다운로드할 파일 크기가 크다는 단점이 있지만, 다운로드된 파일을 로드하는 속도는 빠르다.
    - ***BuildAssetBundleOptions.ChunkBasedCompression***
        - 이 번들 옵션은 LZ4 압축 메서드를 사용한다.
        - LZMA 압축 포맷보다 압축된 파일 크기가 크지만 애셋을 사용하기 전에 모든 번들의 압축을 풀 필요가 없어 좀 더 빠르다.
        - 또한 압축되지 않은 번들과 비슷한 로드 속도를 가지게 되지만 디스크의 용량은 적게 차지한다.
- ***BuildTarget***
    - 애셋번들을 사용할 타겟 플랫폼이 무엇인지 빌드 파이프라인에 알려준다.
    - 빌드 타겟의 리스트는 [***BuildTarget***](https://docs.unity3d.com/kr/2022.3/ScriptReference/BuildTarget.html)을 참조.
    - 빌드 타겟에 하드 코딩을 하기를 원치 않는다면 `EditorUserBuildSettings.activeBuildTarget` 옵션 사용.
    - 위의 스크립트 예제를 따른 경우 ***Assets > Build AssetBundles*** 을 클릭하여 프로세스를 시작한다.
    - 애셋번들마다 애셋번들의 이름으로된 파일과 애셋번들 이름 + “.manifest”로 된 파일이 생성된다.
    - To learn more about how to use this bundle and the manifest object, see documentation on [***Using AssetBundles Natively***](https://docs.unity3d.com/kr/2022.3/Manual/AssetBundles-Native.html).
- ***The AssetBundle File***
    - .manifest 확장자가 없는 파일로서 애셋을 로드하기 위해 런타임 시점에 로드해야 하는 파일이다.
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
    - UnityEngine.Objects 중 하나 이상이 다른 번들에 있는 UnityEngine.Object에 대한 참조를 포함하는 경우 해당 애셋번들은 다른 애셋번들에 종속성이 생긴다.
    - 하지만, UnityEngine.Object가 애셋번들에 포함되지 않은 UnityEngine.Object에 대한 참조를 포함하는 경우는 종속성이 발생하지 않는다. 이 경우 번들이 의존하는 오브젝트의 복사본은 애셋번들을 빌드할 때 복사된다.
    - 애셋번들이 종속성을 포함하는 경우, 인스턴스화하는 오브젝트가 로딩되기 이전에 종속성을 가지는 번들이 로딩되도록 해야 한다.
    - Unity 엔진은 종속성을 자동으로 로딩하지 않는다.
- ***Consider the following example, a Material in Bundle 1 references a Texture in Bundle 2:***
    - 번들 1에 있는 머티리얼을 로딩하기 전에 번들 2를 메모리에 로딩해야 한다. 
    - 번들 1과 번들 2를 로딩하는 순서는 중요하지 않다.
    - 중요한 것은 번들 1 의 머티리얼이 로딩되기 이전에 번들 2 가 로딩되어야만 한다는 것이다.
- ***Duplicated information across AssetBundles***
    - 기본적으로 Unity는 애셋번들 간의 중복 정보를 최적화하지 않는다.
    - 즉 프로젝트의 여러 애셋번들에 동일한 정보(예: 여러 프리팹에서 사용되는 머티리얼)가 포함될 수 있음을 의미한다.
    - 이러한 공통 애셋은 메모리 리소스와 로딩 시간에 영향을 미칠 수 있다.
    - 여기서는 Unity가 애셋번들 간의 중복 정보를 관리하는 방법과 최적화를 적용하는 방법에 대해 설명한다.
- ***Editor setup***
    - 기본적으로 Unity는 중복 정보를 저장하는 데 필요한 메모리를 줄이거나 최소화하기 위해 최적화를 수행하지 않는다.
    - 빌드 생성 중에 Unity는 애셋번들 내에서 암시적으로 참조된 애셋 복제본을 빌드한다.
    - 이러한 중복을 방지하려면 머티리얼 등과 같은 공통 애셋을 자체 애셋번들에 할당해야한다.
    - 예를 들어 자체 애셋번들에 할당된 두 개의 프리팹이 있는 애플리케이션이 있을 수 있다.
    - 이 두 프리팹은 모두 애셋번들에 할당되지 않은 동일한 머티리얼을 공유한다. 
    - 이 머티리얼은 애셋번들에 할당되지 않은 텍스처를 참조한다.
    - CreateAssetBundles 예제를 사용하여 애셋번들을 빌드하면, 생성된 각 애셋번들에 머티리얼(해당 셰이더, 참조된 텍스처 포함)이 포함된다.
    - 아래 이미지에서 보이듯, 프리팹 파일의 크기는 각각 ***383KB***와 ***377KB***이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundleDuplicate.png)
    - 프로젝트에 더 많은 수의 Prefab이 포함된 경우 이 동작은 최종 설치 프로그램 크기와 두 AssetBundle이 로드될 때 런타임 메모리 공간에 영향을 미칩니다.
    - Unity는 동일한 머티리얼의 각 복사본을 고유한 머티리얼로 간주하기 때문에 에셋번들 간의 데이터 중복은 일괄 처리에도 영향을 미칩니다.
    - 데이터 중복을 방지하려면 머티리얼 및 참조된 자산을 자체 모듈 머티리얼 AssetBundle에 할당하십시오.
    - 텍스처 종속성은 빌드 프로세스 중에 자동으로 AssetBundle에 포함되기 때문에 Material에만 태그를 지정하면 됩니다.
    - 이제 AssetBundle을 다시 빌드하면 생성된 출력에 Material 및 관련 Texture가 포함된 별도의 modulematerials AssetBundle(359KB)이 포함됩니다.
    - 이렇게 하면 Prefab에 대한 다른 AssetBundle의 크기가 크게 줄어듭니다(이전 반복의 약 380KB에서 약 20KB로 감소).
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/AssetBundleSeparate.png)
- ***Runtime loading***
    - 공용 애셋을 단일 애셋번들로 만드는 경우 종속성에 주의하세요.
    - 특히 프리팹을 사용하여 모듈을 인스턴스화하면 머티리얼이 로드되지 않습니다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/MaterialNotLoaded.png)
    - 이 문제를 해결하려면 모듈에 속한 에셋 번들을 로드하기 전에 머티리얼 에셋 번들을 메모리에 로드하십시오.
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













　

　

　

　

　

- https://docs.unity3d.com/Manual/AssetBundlesIntro.html
- https://medium.com/dreamarofficial/using-assetbundles-in-your-next-game-or-application-9899251a998e
- https://planek.tistory.com/22

　

- https://young-94.tistory.com/11
- https://kukuta.tistory.com/192

　

　

- Unity Blog Addressable 소개 : https://blogs.unity3d.com/kr/2019/07/15/addressable-asset-system/
- Unity Addressable 1.13 메뉴얼 : https://docs.unity3d.com/Packages/com.unity.addressables@1.13/manual/index.html
- Unity Addressable Tutorial : https://learn.unity.com/tutorials/?k=%5B%22lang%3Aen%22%2C%22lang%3Ako%22%2C%22q%3Aaddressable%22%5D&ob=starts

　

　

- [Official: 어드레서블 에셋 시스템](https://blog.unity.com/kr/games/addressable-asset-system)
- [Official: Addressables-Sample](https://github.com/Unity-Technologies/Addressables-Sample)

　

　

- https://www.youtube.com/playlist?list=PLmRK0lH8TNCo7K4xmLpEov4llbVTwf29s

- [유니티(Unity) - Addressable(어드레서블) 사용법(1). 설치 및 준비](https://blog.naver.com/cdw0424/221636733877)
- [유니티(Unity) - Addressable(어드레서블) 사용법(2). 에셋 로드](https://blog.naver.com/cdw0424/221636783259)
- [유니티(Unity) - Addressable(어드레서블) 사용법(3). 프로파일러와 디버깅](https://blog.naver.com/cdw0424/221636822258)
- [유니티(Unity) - Addressable(어드레서블) 사용법(4). 에셋 언로드](https://blog.naver.com/cdw0424/221637349195)
- [유니티(Unity) - Addressable(어드레서블) 사용법(5). 씬 로드와 언로드](https://blog.naver.com/cdw0424/221637763395)
- [유니티(Unity) - Addressable(어드레서블) 사용법(6). 빌드 후 실제 사용](https://blog.naver.com/cdw0424/221638017138)
- [유니티(Unity) - Addressable(어드레서블) 사용법(7). 서버에서 다운로드하기 1편](https://blog.naver.com/cdw0424/221755856111)
- [유니티(Unity) - Addressable(어드레서블) 사용법(8). 서버에서 다운로드하기 2편 - Catalog 이해](https://blog.naver.com/cdw0424/221756844361)
- [유니티 엔진 유니티(Unity) - Addressable(어드레서블) 사용법(9). 서버에서 다운로드하기 3편](https://blog.naver.com/cdw0424/221764918184)
- [유니티 엔진 유니티(Unity) - Addressable(어드레서블) 사용법(10). 외부 서버 없이 서버 기능 테스트하기.](https://blog.naver.com/cdw0424/222090659316)

　

- [유니티(Unity) - Addressables(어드레서블) 에셋](https://blog.naver.com/cdw0424/221630503021)
- [유니티(Unity) - Addressables.MergeMode](https://blog.naver.com/cdw0424/221637975547)
- [유니티(Unity) - Addressables.DownloadDependenciesAsync(오브젝트에 종속된 에셋들 가져오기)](https://blog.naver.com/cdw0424/221651296509)
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
