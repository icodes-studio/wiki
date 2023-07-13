## # Overview

- ***AssetBundles***
    - 플랫폼별 비코드 에셋(예: 모델, 텍스처, 프리팹, 오디오 클립, 씬 전체)이 들어 있는 아카이브 파일이며 런타임 시점에 로드할 수 있다.
    - 서로 종속성을 가질 수 있다. 예를 들어 한 에셋 번들의 머티리얼이 다른 에셋 번들의 텍스처를 참조할 수 있다.
    - 효율적인 네트워크 전송을 위해 빌트인 알고리즘을(LZMA 및 LZ4) 사용하여 압축할 수 있다.
    - 초기 설치 크기를 줄이고, 언로드를 통해 런타임 메모리의 압박을 줄일 수 있다.


　

　

## # AssetBundle workflow

- ***Note:***
    - *여기서는 빌트인 **BuildPipeline.BuildAssetBundles()** API를 사용하여 애셋번들을 생성하는 방법을 설명한다.*
    - *권장되는 방법은 [**어드레서블 패키지(Addressables package)**](https://docs.unity3d.com/Packages/com.unity.addressables@1.21/manual/index.html)를 사용하는 것이다.*


　

- ***Assigning Assets to AssetBundles***
    - 프로젝트 뷰에서 번들에 할당할 에셋을 선택.
    - 인스펙터 하단에 왼쪽 드롭다운을 사용하여 ***에셋번들 이름을*** 지정하고, 오른쪽 드롭다운을 사용하여 ***배리언트(Variant)***를 지정.
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
    - 이렇게 하면 에셋번들 이름으로 레이블이 지정된 모든 에셋을 가져와서 assetBundleDirectory에 정의된 경로의 폴더에 배치한다.


　

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
    ● There are certain strategies to consider when setting up your bundles.
    ● These grouping strategies are meant to be used however you see fit for your specific project.
    ● Feel free to mix and match these strategies as you see fit.

- ***Logical Entity Grouping***
    - 프로젝트 관점에서, 애셋의 기능적인 부분에 따라 애셋번들을 그룹핑 하는 방법.
    - 여기에는 사용자 인터페이스, 캐릭터, 환경, 그리고 애플리케이션 라이프 사이클 내내 자주 나타날 수 있는 모든 것이 포함된다.
    - 모든 것이 컨텐츠에 따라 논리적으로 구분되어 있으므로 DLC(DownLoadable Content)에 적합하다.
    - 번들을 만드는 개발자가 프로젝트와 컨텐츠의 구현에 대해(애셋이 사용되는 시기와 위치) 정확히 알고 있어야 한다.
    - ***Examples***
        - 사용자 인터페이스 화면의 모든 텍스처 및 레이아웃 데이터 번들링
        - 캐릭터에 대한 모든 모델 및 애니메이션 번들링
        - 게임 레벨 스테이지 간에 공통으로 사용되는 배경에 대한 텍스쳐 및 모델 데이터 번틀링

- ***Type Grouping***
    - 오디오 트랙이나 언어팩 파일 등 타입이 비슷한 에셋을 하나의 에셋 번들에 할당한다.
    - 여러 플랫폼에서 사용될 에셋 번들을 빌드하는 데 상대적으로 효과적인 전략 중 하나이다.

- ***Concurrent Content Grouping***
    - 동시에 로드되고 사용될 에셋을 하나의 번들로 묶는 개념. 가장 일반적인 이용 사례는 씬 기반 번들.
    - 애셋번들 내 한 애셋이 해당 번들의 다른 애셋에 동시에 사용된다는 것을 확신하는 경우.
    - 번들에 포함된 애셋 하나에 종속성이 있으면 로드 시간이 크게 증가한다.

- ***어떤 전략을 따르든 관계없이, 아래의 추가 팁을 항상 염두에 두는 것이 좋다.***
    - 자주 업데이트되는 오브젝트는 변경 빈도가 낮은 오브젝트와 별개의 애셋번들로 나누어라.
    - 동시에 로드될 가능성이 큰 오브젝트(모델, 텍스처 및 애니메이션 등)를 그룹화하라.
    - 애셋번들 간에 공통으로 사용하는 애셋은 별도의 공용 에셋 번들로 종속성을 옮겨라.
    - SD 또는 HD 에셋처럼 두 오브젝트 집합이 동시에 로드될 가능성이 거의 없는 경우 각기 다른 애셋번들로 나누어라.
    - 오브젝트 그룹이 단순히 같은 오브젝트의 다른 버전에 불과할 경우, 애셋번들 배리언트(Variant)를 고려하라.




















　

　

　

　

　

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
