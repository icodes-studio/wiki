## # Addressables

- ***References***
    - *https://planek.tistory.com/22*
    - [*Unity Blog Addressable 소개*](https://blogs.unity3d.com/kr/2019/07/15/addressable-asset-system/)
    - [*Unity Addressable 1.13 메뉴얼*](https://docs.unity3d.com/Packages/com.unity.addressables@1.13/manual/index.html)
    - [*Unity Addressable Tutorial*](https://learn.unity.com/tutorials/?k=%5B%22lang%3Aen%22%2C%22lang%3Ako%22%2C%22q%3Aaddressable%22%5D&ob=starts)
    - [*Official: 어드레서블 애셋 시스템*](https://blog.unity.com/kr/games/addressable-asset-system)
    - [*Official: Addressables-Sample*](https://github.com/Unity-Technologies/Addressables-Sample)
    - [*YouTube 동영상- Unite Seoul 2019*](https://youtu.be/yoBzTpJYN44)
    - [*YouTube 동영상 - 감귤오렌지*](https://www.youtube.com/playlist?list=PLmRK0lH8TNCo7K4xmLpEov4llbVTwf29s)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(1). 설치 및 준비*](https://blog.naver.com/cdw0424/221636733877)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(2). 애셋 로드*](https://blog.naver.com/cdw0424/221636783259)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(3). 프로파일러와 디버깅*](https://blog.naver.com/cdw0424/221636822258)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(4). 애셋 언로드*](https://blog.naver.com/cdw0424/221637349195)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(5). 씬 로드와 언로드*](https://blog.naver.com/cdw0424/221637763395)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(6). 빌드 후 실제 사용*](https://blog.naver.com/cdw0424/221638017138)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(7). 서버에서 다운로드하기 1편*](https://blog.naver.com/cdw0424/221755856111)
    - [*유니티(Unity) - Addressable(어드레서블) 사용법(8). 서버에서 다운로드하기 2편 - Catalog 이해*](https://blog.naver.com/cdw0424/221756844361)
    - [*유니티 엔진 유니티(Unity) - Addressable(어드레서블) 사용법(9). 서버에서 다운로드하기 3편*](https://blog.naver.com/cdw0424/221764918184)
    - [*유니티 엔진 유니티(Unity) - Addressable(어드레서블) 사용법(10). 외부 서버 없이 서버 기능 테스트하기*](https://blog.naver.com/cdw0424/222090659316)
    - [*유니티(Unity) - Addressables(어드레서블) 애셋*](https://blog.naver.com/cdw0424/221630503021)
    - [*유니티(Unity) - Addressables.MergeMode*](https://blog.naver.com/cdw0424/221637975547)
    - [*유니티(Unity) - Addressables.DownloadDependenciesAsync(오브젝트에 종속된 애셋들 가져오기)*](https://blog.naver.com/cdw0424/221651296509)
    - [*유니티(Unity) - 어드레서블(Addressables)로 게임시작시 콘텐츠 다운로드 하는 법*](https://blog.naver.com/cdw0424/221715381599)
    - [*유니티(Unity) - 어드레서블 소개 영상보기*](https://blog.naver.com/cdw0424/221721464836)
    - [*유니티(Unity) - 어드레서블 LoadAssetAsync() 사용법 영상보기*](https://blog.naver.com/cdw0424/221725042422)
    - [*유니티(Unity) - 어드레서블(2) InstantiateAsync() 사용법 영상보기*](https://blog.naver.com/cdw0424/221748882936)
    - [*유니티(Unity) - 어드레서블(3) ReleaseInstance()사용법 영상 보기*](https://blog.naver.com/cdw0424/221751617965)
    - [*유니티(Unity) - 어드레서블 안드로이드 머티리얼 문제 발생 시*](https://blog.naver.com/cdw0424/221754866636)
    - [*유니티(Unity) - 어드레서블(4) 서버와 함께 사용하기! (영상 보기)*](https://blog.naver.com/cdw0424/221782318097)
    - [*유니티(Unity) - 어드레서블 보라색 머티리얼 문제*](https://blog.naver.com/cdw0424/222102502420)
    - [*어드레서블 동기식 표현 지원*](https://blog.naver.com/cdw0424/222431929501)
    - [*유니티(Unity) - Addressable(어드레서블) DownloadDependenciesAsync 경로*](https://blog.naver.com/cdw0424/222593119206)


　

## # 설치 및 준비
- ***Settingup***
    - 패키지 매니저에서 어드레서블 패키지를 설치한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr1.png)
    - 메뉴 ***Window > Asset Management > Addressables > Groups*** 항목을 선택한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr2.png)
    - Create Addressables Settings 버튼 클릭
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr3.png)
    - ***AddressableAssetsData*** 라는 폴더가 생기고,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr4.png)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr5.png)
    - 아까 열었던 Addressables 윈도우는 이렇게 바뀐다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr6.png)


　

## # 애셋 로드

- ***Loading***
    - 애셋을 어드레서블로 로드하기 위해서는 해당 애셋의 인스펙터에서 Addressable 체크박스를 선택해야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr7.png)
    - 체크를 해주면 바로 옆에 어드레스가 자동으로 생성되는데, 이 값으로 파일을 로드 해 올 것이다. 일종의 닉네임 정도로 생각해두자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr8.png)
    - 우리가 알아보기 편하게 다른 어드레스와 겹치지만 않는다면 원하는 대로 수정할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr9.png)
    - 이제 이 큐브 프리팹을 생성하는 버튼과 그 스크립트를 만들어서 넣어주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr10.png)
    - 버튼을 클릭하니 정상적으로 큐브가 생성되는 걸 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr11.png)
    - 필요에 따라 로드와 생성을 분리시킬 수도 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr12.png)
    - 참고로, 이름을 하드코딩하지 말고 ***AssetReference*** 필드를 인스펙터로 바인딩해서 사용하는 방법이 좀 더 세련되시겠다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr13.png)
    - 인스펙터 필드를 만드니, 이런 드랍다운 버튼이 생기고 선택 가능한 어드레서블에셋들이 나열된다. 큐브를 선택하고,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr14.png)
    - 두 번째 표시처럼 함수를 사용해주면 이때까지와 같은 결과를 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr15.png)


　

## # 프로파일러와 디버깅

- ***Profiling***
    - 어드레서블이 정말 좋은 건 이렇게 따로 어드레서블전용 프로파일러 툴을 제공한다는 것이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr16.png)
    - 프로파일러는 아래 사진과 같은 경로에 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr17.png)
    - 프로파일러를 사용하려면 ***AddressableAssetSettings*** 인스펙터에서 Send Profiler Events를 체크해주어야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr18.png)
    - 체크를 했다면 플레이하고 어드레서블 프로파일러를 보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr19.png)
    - 아무런 변화가 없다! 클리어 버튼을 눌러도 변화가 없다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr20.png)
    - 그 이유는 이 프로파일러는 어드레서블에셋을 하나라도 로드하기 시작한 시점부터 시작되기 때문이다.
    - 큐브 생성 버튼을 누르고 다시 클리어 버튼을 눌러주면 
    - 어드레서블 에셋을 로드하기 시작하면 해당 씬의 모든 어드레서블에대해서 프로파일링을 시작한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr21.png)
    - 큐브 생성 버튼을 한번 눌렀을 때의 프로파일러 모습인데 
    - 맨 아랫줄에 보면 생성시킨 리소스의 정보와 옆에 그래픽 중간에 1이라는 숫자가 보인다.
    - 이 숫자는 해당 오브젝트의 개수가 되겠다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr22.png)
    - 12번 더 눌렀더니 총 13개가 된 모습을  볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr23.png)
    - 외에도, 프레임, 모노의 힙 정보, 생성된 시점 등 성능에 관해 중요한 주요 정보들을 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr24.png)


　

## # 에셋 언로드

- ***Unloading***
    - 다 사용한 자원들은 메모리에서 내려주는 게 중요하다.
        > *https://youtu.be/yoBzTpJYN44*
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr25.png)
    - 어드레서블 1.1.10 버전인 현재 ReleaseAsset이라는 함수는 보이지 않는다. 아마 Release로 이름이 바뀐듯...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr26.png)
    - 인스턴티에이트로 생성한 경우는 ReleaseInstance로 해제한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr27.png)
    - 해제를 해주니 카운트가 줄어드는 모습을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr28.png)


　

## # 씬 로드와 언로드

- ***Scene Loading & Unloading***
    - 적당히 씬을 하나 만들어주고
        >![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr29.png)
    - 어드레서블 체크 후 이름을 정해 줬다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr30.png)
    - 씬을 로드할 때는 LoadSceneAsync이라는 함수가 따로 있어서 사용하면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr31.png)
- ***Subscene Loading***
    - 기존 씬에 합쳐서 씬을 로드하는 경우
    - 먼저 씬을 로딩하는 스크립트를 만들어주고,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr32.png)
    - SceneInstance를 쓰는 이유는 Addressables.UnloadSceneAsync()함수가 매개변수로 SceneInstance를 받기 때문이다. 
    - 버튼을 클릭하면 loadSubSceneFn() 함수를 실행하게 추가해주었다.
    - "5Cube"라는 어드레스를 가진 씬을 LoadSceneMode.Additive라는 매개변수를 이용해 본래 씬에다가 합쳐 준다.    
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr33.png)
    - 로드가 완료될 때 이벤트를 등록해서 OnSceneLoaded() 함수를 실행한다.
        ```
        Addressables.LoadSceneAsync("5Cube", LoadSceneMode.Additive).Completed += OnSceneLoaded
        ```
    - OnSceneLoaded() 함수를 보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr34.png)
    - Succeeded면 m_LoadedScene 필드에 결과를 저장해준다. 이때 저장해둔 값은 나중에 언로드 할 때 쓰인다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr35.png)
    - 언로드의 경우 m_LoadedScene 변수를 비워줘야 하는데 new를 통해 새로운 객체를 넣어줬다. null을 안 넣은 이유는 SceneInstance 형식이 구조체(Struct)라 적당한 값으로 초기화해준 것이다. <- default 사용을 고려하라
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr36.png)
    - 코드전문
        ```
        using System.Collections;
        using System.Collections.Generic;
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;
        using UnityEngine.SceneManagement;
        using UnityEngine.ResourceManagement.AsyncOperations;
        using UnityEngine.ResourceManagement.ResourceProviders;

        public class LoadSubScene : MonoBehaviour
        {
            Button Btn;
            [SerializeField] Text text;
            bool m_ReadyToLoad = true;//로드 가능한 상태인가를 체크.
            SceneInstance m_LoadedScene;// 불러온 씬의 인스턴스를 저장해두는변수.

            // Start is called before the first frame update
            void Start()
            {
                Btn = GetComponent<Button>();

                Btn.onClick.AddListener(loadSubSceneFn);
            }

            void loadSubSceneFn()
            {

                if (m_ReadyToLoad)
                    Addressables.LoadSceneAsync("5Cube", LoadSceneMode.Additive).Completed += OnSceneLoaded;
                else
                {
                    Addressables.UnloadSceneAsync(m_LoadedScene).Completed += OnSceneUnloaded;
                }

            }

            void OnSceneLoaded(AsyncOperationHandle<SceneInstance> obj)
            {
                if (obj.Status == AsyncOperationStatus.Succeeded)
                {
                    text.text = "언로드 5Cube";
                    m_LoadedScene = obj.Result;
                    m_ReadyToLoad = false;
                }
                else
                {
                    Debug.LogError("로드 실패");
                }
            }

            void OnSceneUnloaded(AsyncOperationHandle<SceneInstance> obj)
            {
                if (obj.Status == AsyncOperationStatus.Succeeded)
                {
                    text.text = "다시 로드 하기";
                    m_ReadyToLoad = true;
                    m_LoadedScene = new SceneInstance();
                }
                else
                {
                    Debug.LogError("언로드 실패");
                }
            }

        }
        ```


　

## # 빌드 후 실제 사용.

- ***Play Mode***
    - 지금까지 내용은 에디터에서만 작동을 할 것이다.
    - 어드레서블 윈도우의 상단부에 위치한 플레이 모드를 보면 Fast Mode라고 되어있을 건데
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr37.png)
    - 각각의 모드를 설명해 보자면 아래와 같다.
        > - Fast Mode: 패키징 되지 않은(= 번들로 만들지 않은 = 그룹으로 묶기만 하고 빌드를 하지 않아서 따로 파일이 존재하지 않을 때) 상태에서도 바로바로 플레이가 가능한 모드이다. 작업 중인 컴퓨터의 에셋 데이터베이스에서 바로바로 정보를 가져오기 때문에 실제로 어드레서블에셋들이 그룹화되어있지 않다. 
        > - Virtual Mode: 플레이를 누르면 사전 빌드 단계를 거쳐서 그룹화된 번들 파일들을 생성한 후 플레이 된다. 따라서 실제 그룹화가 되어있고, 그 정보에서 데이터를 불러온다. 그래서 프로파일링 할 때 유용하다. 하지만 데이터가 계속해서 활성화되어 있기 때문에 실제 빌드 시 작동은 하지만 메모리에 이점이 전혀 없다.
        > - Packed Play Mode: 실제 빌드를 통해 그룹화된 파일을 생성해야만 이 모드로 플레이(재생)가 된다. 실제 빌드 시 사용하며 평소에 자주자주 빌드 파일을 업데이트해주는 습관을 들이는 게 좋다.
    - 빌드를 하면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr38.png)
    - 빌드 내용이 담긴 bin 파일이 생긴다. (번들아님)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr39.png)
    - 이 빈 파일이 생기고 나서 Packed Play Mode로 플레이를 해보면 정상적으로 플레이가 가능해지고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr40.png)
    - 프로파일러를 열어보면 자동으로 생성된 번들 파일에서 데이터를 가져오는 걸 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr41.png)
    - 참고로 어드레서블 시스템은 기존 에셋번들 시스템을 더 사용하기 편하게 제공하기 위해 래핑 된 것이다. 에셋 번들 위에서 돌고 있는 게 어드레서블 시스템이라는 말이다. 그러니 에셋 번들 시스템이 없어지는가 하는 등의 걱정은 하지 않아도 될 것 같다.
        > *https://youtu.be/iauWgEXjkEY*


　

## # 서버에서 다운로드하기

- ***1편***
    - Groups를 선택하고...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr42.png)
    - 어드레서블 세팅을 생성해주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr43.png)
    - 여기까지 잘 왔는가?
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr44.png)
    - 이제 서버에 넣을 번들과 로컬에서 사용할 번들을 구분해보자. 우 클릭을 통해 그룹을 새로 생성할 수 있고, 이렇게 생성된 그룹은 각각의 에셋 번들로 빌드 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr45.png)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr46.png)
    - 방금 만든 그룹의 이름을 RemoteAssets라고 지어 줬다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr47.png)
    - 이제 각 그룹에 에셋을 추가시켜주자. 우선 각 에셋에 어드레서블 체크를 해주고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr48.png)
    - 디폴트 그룹에 들어간 에셋들을
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr49.png)
    - 새로 만든 그룹으로 옮겨주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr50.png)
    - 이제 프로필을 새로 만들어주자
    - 프로필은 어떤 식으로 설정했는지 저장하는 용도인데
좀 쉽게 말하자면 테스트 버전, 서버 있는 버전, 서버 없는 버전 뭐 이런 상황이 있다며
버전마다 어드레서블 설정이 모두 다를 것이다.
이 설정을 상황에 따라 매번 다시 설정하는 것보다.
그냥 버전마다 나눠놓으면 번거롭게 매번 설정할 필요가 없이 원하는 프로필만 선택하면 된다.
설명은 이쯤하고

​
        