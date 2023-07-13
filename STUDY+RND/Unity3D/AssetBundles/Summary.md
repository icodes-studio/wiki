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
    - 인스펙터 하단에 왼쪽 드롭다운을 사용하여 에셋번들 이름을 할당하고, 오른쪽 드롭다운을 사용하여 배리언트(Variant)를 할당한다.
    - 새 애셋번들 이름을 생성 하려면 New 버튼 클릭하고 이름 입력.
    - 하위 폴더를 추가하려면 /를 이용해 폴더 이름을 구분한다.


　

- ***Variant?***
    - 별도로 설명하자.


　

- ***Build the AssetBundles***
    - Assets 폴더에서 Editor 폴더를 생성하고, 폴더에 다음과 같은 콘텐츠의 스크립트를 입력합니다.
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
    - For more details about this, see documentation on Building AssetBundles.


　

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
    - 원격지로부터 로드하거나 로컬 파일에 바로 접근할 수 없는 플랫폼의 경우 UnityWebRequestAssetBundle API를 사용한다.
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
