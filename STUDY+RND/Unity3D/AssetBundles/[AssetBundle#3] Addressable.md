## # Addressables

- ***References***
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
    - *https://planek.tistory.com/22*
    - [*Unity Blog Addressable 소개*](https://blogs.unity3d.com/kr/2019/07/15/addressable-asset-system/)
    - [*Unity Addressable 1.13 메뉴얼*](https://docs.unity3d.com/Packages/com.unity.addressables@1.13/manual/index.html)
    - [*Unity Addressable Tutorial*](https://learn.unity.com/tutorials/?k=%5B%22lang%3Aen%22%2C%22lang%3Ako%22%2C%22q%3Aaddressable%22%5D&ob=starts)
    - [*Official: 어드레서블 애셋 시스템*](https://blog.unity.com/kr/games/addressable-asset-system)
    - [*Official: Addressables-Sample*](https://github.com/Unity-Technologies/Addressables-Sample)    


　

## # 설치 및 준비

- ***Settingup***
    - ***Package Manager***에서 ***Addressables*** 패키지를 설치한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr1.png)
    - 메뉴 ***Window ‣ Asset Management ‣ Addressables ‣ Groups*** 항목을 선택하여 ***Addressables Groups*** 윈도우를 연다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr2.png)
    - ***Create Addressables Settings*** 버튼 클릭.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr3.png)
    - 프로젝트뷰에 ***AddressableAssetsData*** 라는 폴더가 생겼다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr4.png)
    - ***Addressables Groups*** 윈도우는 이렇게 바뀌었다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr6.png)


　

## # 애셋 로드

- ***Settingup***
    - 애셋을 어드레서블로 로드하기 위해서는 인스펙터에서 ***Addressable*** 항목을 선택해야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr7.png)
    - ***Addressable*** 항목을 선택하면 바로 옆에 어드레스가 자동으로 생성되는데, 이 값으로 애셋을 로드할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr8.png)
    - 이 값은 다른 어드레스와 겹치지만 않는다면 원하는 대로 수정할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr9.png)
    - 큐브 프리팹을 생성하는 스크립트를 만들어서 버튼 오브젝트에 바인딩 해주자.
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;

        public class InstantiateCube : MonoBehaviour
        {
            Button button;

            void Start()
            {
                button = GetComponent<Button>();
                button.onClick.AddListener(OnCreateCube);
            }

            void OnCreateCube()
            {
                // 로드와 인스턴스 생성을 동시에 수행
                Addressables.InstantiateAsync("Cube", new Vector3(0, 0, 0), Quaternion.identity);
            }
        }
        ```
    - 버튼을 클릭하면 큐브가 생성되는 것을 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr11.png)
    - 필요에 따라 로드와 생성을 분리시킬 수도 있다.
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class InstantiateCube : MonoBehaviour
        {
            Button button;

            void Start()
            {
                button = GetComponent<Button>();
                button.onClick.AddListener(OnCreateCube);
            }

            void OnCreateCube()
            {
                // "Cube" 애셋 로드
                Addressables.LoadAssetAsync<GameObject>("Cube").Completed += OnLoadCompleted;
            }

            void OnLoadCompleted(AsyncOperationHandle<GameObject> obj)
            {
                // 로드된 "Cube" 애셋에서 게임 오브젝트 인스턴싱
                GameObject resultObject = obj.Result;
                Instantiate(resultObject, new Vector3(0, 0, 0), Quaternion.identity);
            }
        }
        ```
    - 참고로, 이름을 하드코딩하지 말고 ***AssetReference*** 필드를 사용하는 방법이 좀 더 세련되시겠다.
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;

        public class InstantiateCube : MonoBehaviour
        {
            Button button;
            [SerializeField] AssetReference assetReference;

            void Start()
            {
                button = GetComponent<Button>();
                button.onClick.AddListener(OnCreateCube);
            }

            void OnCreateCube()
            {
                assetReference.InstantiateAsync(new Vector3(0, 0, 0), Quaternion.identity);
            }
        }
        ```
    - 어드레서블 애셋을 입력받을 수 있는 인스펙터 필드가 보인다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr14.png)
    - 창을 띄워서 선택하거나
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr15.png)
    - 프리팹을 드래그하여 바인딩한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr5.png)
    - 버튼을 누르면 같은 결과를 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr11.png)


　

## # 프로파일러와 디버깅

- ***Addressables Event Viewer***
    - 어드레서블 전용 프로파일러(이벤트뷰어) 툴이 제공된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr16.png)
    - 메뉴 ***Window ‣ Asset Management ‣ Addressables ‣ Event Viewer*** 항목을 선택하여 이벤트 뷰어를 띄울 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr17.png)
    - 이벤트 뷰어를 사용하려면 ***AddressableAssetSettings*** 인스펙터에서 ***Send Profiler Events*** 필드를 선택해야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr18.png)
    - 어드레서블 애셋을 로드하기 시작하면 프로파일링을 시작한다. 아래는 큐브를 36개 생성했을 때의 모습니다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr19.png)


　

## # 애셋 언로드

- ***References***
    > *https://www.youtube.com/watch?v=yoBzTpJYN44&t=1972s*
    > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr25.png)
- ***LoadAssetAsync, InstantiateAsync에 맞게 해제***
    - ***LoadAssetAsync*** 함수로 로드한 애셋은 ***Release*** 함수로 언로드
    - ***InstantiateAsync*** 함수로 로드 및 생성한 오브젝트는 ***ReleaseInstance*** 함수로 언로드
- ***Addressable, AssetReference 클래스 각각에 언로드 함수 존재***
    - *Addressables.Release*
    - *Addressables.ReleaseInstance*
    - *Addressables.Release*
    - *Addressables.ReleaseInstance*
- ***동작확인***    
    - 아래 스크립트를 만들어 Cube 프리팹에 바인딩하고,
        ```
        using UnityEngine;
        using UnityEngine.AddressableAssets;

        public class Destructer : MonoBehaviour
        {
            void Start()
            {
                Invoke("ReleaseObj", 1f);
            }

            void ReleaseObj()
            {
                Addressables.ReleaseInstance(gameObject);
            }
        }
        ```
    - 프로파일러를 확인하면 카운트가 줄어드는 모습을 확인할 수 있다.
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
        > - 프로필은 어떤 식으로 설정했는지 저장하는 용도인데
        > - 좀 쉽게 말하자면 테스트 버전, 서버 있는 버전, 서버 없는 버전 뭐 이런 상황이 있다며
        > - 버전마다 어드레서블 설정이 모두 다를 것이다.
        > - 이 설정을 상황에 따라 매번 다시 설정하는 것보다.
        > - 그냥 버전마다 나눠놓으면 번거롭게 매번 설정할 필요가 없이 원하는 프로필만 선택하면 된다.
    - 프로필을 눌러 Manage Profiles를 클릭하고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr51.png)
    - 창이 뜨면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr52.png)
    - Create를 눌러서 Profile을 선택하자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr53.png)
    - 프로필이 생성되었다면 이름을 적당하게 바꿔준 뒤
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr54.png)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr55.png)
    - 다시 어드레서블 그룹 창으로 가서 프로필을 방금 만든 걸로 바꿔주자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr56.png)
    - 이제 Tools 드롭 다운을 눌러 Inspect System Settings를 누르거나
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr57.png)
    - 위 파일을 그냥 클릭하면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr58.png)
    - 인스펙터에 이런 창이 뜬다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr59.png)
    - 혹시나 프로필이 안 바뀌었는지 확인해보고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr60.png)
    - 카탈로그의 Build Remote Catalog를 체크해 준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr61.png)
    - 그러면 이렇게 바뀌게 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr62.png)
    - 카탈로그가 뭐냐면...
    - 빌드 된 번들의 위치 정보나 또 어떤 식으로 가져올 것인지에 대한 설정들의 묶음이다.
    - 그래서 우리는 remote로도 사용할 것이기 때문에 Build Remote Catalog를 체크해 주었다.
    - 그리고 각 Path는 앞에 remote가 붙어있는 놈으로 선택해주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr63.png)
    - 로컬과 차이를 간단하게 설명하자면
    - 로컬 패스는 프로젝트 내부에 번들이 생성되고 내부에서 불러오지만
    - 리모트 패스는 기본 경로가 이렇게 프로젝트(에셋 폴더 또는 라이브러리 폴더)밖에 ServerData라는 폴더로 설정이 되어있다..
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr64.png)
    - 그 안엔 실제로 빌드 시 이렇게 번들이 들어 가있다. 나중에 이걸 서버에 넣어주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr65.png)
- ***2편***
    - 카탈로그(Catalog)는 각 어드레스와 자산을 매핑(연결) 하며, 원한다면 매핑을 변경하여 불러올 번들의 위치와 로드 방법 등을 설정할 수 있다.
    - 그러기 위해선 이렇게 Build Remote Catalog를 활성화해주어야 한다.
    - 이것을 체크해 주면 리모트 서버에 저장하기 위한 카탈로그 사본을 생성한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr66.png)
    - 직접 빌드 해보기 위해 플레이 모드를 Existing으로 바꾼 뒤
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr67.png)
    - 체크한 채로 어드레서블 빌드를 하면 이런 식으로 catalog json, hash 파일이 생성된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr68.png)
        > - 번들이 없는 이유는 아직 번들은 이 폴더에 빌드 하겠다고 설정을 안 했기 때문. 나중에 할 거임.
    - json 파일을 열어서 그중 m_Keys 부분만 보면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr69.png)
        > - 이렇게 번들과, 어드레스 정보가 있는 것을 확인할 수 있다.
        > - 그렇기 때문에 나중에 우리는 번들과 함께 이 카탈로그 사본도 함께 서버에 넣어 주어야 한다.
    - Disable Catalog Update 옵션을 키면 카탈로그가 초기화될 타이밍에 버전 체크를 하지 않는다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr70.png)
    - 카탈로그의 버전 관리를 할 수 있고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr71.png)
    - 예를 들어 1이라고 버전을 지정해준 채로 빌드 했을 때
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr72.png)
    - 이렇게 기존과 다른 파일이 생기는데...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr73.png)
    - 1버전을 입력한 채로 한 번 더 빌드 하면, 이렇게 같은 버전의 파일을 덮어쓴다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr74.png)
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr75.png)
    - 그러면 궁금증이 들 수 있는데 버전이 아예 없으면 안 덮어쓰나? 다시 이렇게 비워두고 빌드를 하면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr76.png)
    - 그렇다! 안 덮어쓰고 새로 생긴다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr77.png)
    - 때문에 지저분하게 파일을 계속 생성하지 않고도 
    - 버전 관리할 때 유용하게 쓰일 수 있는 기능이다.
    - 당연히 숫자뿐만 아니라 
    - Android, IOS, WIndow 등 플랫폼 단위로 나누어서 관리할 수도 있다.
    - 실제로 숫자보단 대부분의 경우 플랫폼 단위로 버전 관리를 하게 될 것이다.(이건 뇌피셜임)
    - 아래와 같이 생성된 카탈로그들을 식별하는 것이 바로 "addressables_content_state.bin" 파일이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr78.png)
    - 열어보면 대충 이런 식으로 적혀있는데 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr79.png)
    - 카탈로그 정보가 들어있는 것을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr80.png)
        > 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr81.png)
    - ​확실하게 하기 위해 버전을 수정해 보았다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr82.png)
    - 역시나 같은 결과를 확인할 수 있었다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr83.png)
    - 아래 이미지처럼 각 플랫폼마다 "addressables_content_state.bin"을 두어서 해당하는 원하는 버전의 카탈로그만 따로 식별이 가능하기 때문에, 여러 플랫폼에서 하나의 빌드로 충돌 없이 각각 여러 버전을 함께 넣는 것이 가능한 것이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr84.png)
        > 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr85.png)
    - 말이 조금 복잡한데, 배포한 앱을 다시 빌드 및 배포하지 않고 수정한 에셋을 바로 적용시키는 예시를 들어보자면
    - 윈도우에서 Product 버전 카탈로그로 빌드 해서 배포한 경우를 가정했을 때
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr86.png)
    - 윈도우 환경에서 해당 앱은 Product 버전의 카탈로그만 식별을 할 것이기 때문에 product 버전 카탈로그에 등록된 위치의 번들이기만 하면 정상 작동한다.
    - 그렇기 때문에 에셋을 수정하고 product 버전의 카탈로그와 함께 번들을 빌드 하면 되는데
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr87.png)
    - 우리가 일일이 addressables_content_state.bin 파일을 열어서 버전을 확인하고
    - 해당 버전으로 카탈로그를 수정해서 빌드 하는 것은 비효율적이니
    - 배포 직후 번들을 다시 빌드 하지 않았다는 가정하에
    - (카탈로그 버전을 수정하고 번들을 빌드 하면 addressables_content_state.bin 정보가 바뀌기 때문) 
    - 아래 버튼을 눌러서 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr88.png)
    - addressables_content_state.bin 파일을 열러주면 해당 정보를 토대로  번들만 생성해 준다.
    - (addressables_content_state.bin에 있는 카탈로그 정보를 기준으로 생성하기 때문에 다시 카탈로그를 생성할 이유가 없기 때문)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr89.png)
    - 그리고 새로 빌드 한 번들을 서버에서 이전의 번들과 교체하기만 하면 
    - 수정된 에셋을 따로 앱 빌드 없이 바로바로 적용이 가능해진다.
    - 자 여기까지 어드레서블의 카탈로그에 대해서 이야기를 해보았다.
    - 그냥 한 줄로만 정리하자면
    - "귀찮게 매번 빌드 및 배포하지 않고도 에셋을 수정해서 적용시킬 수 있는데 그 중심에 카탈로그가 있다"
    - 라는 말이다.
    - 몰라도 사용하는 데는 당장 사용하는데 문제가 없겠지만
    - 상용 프로젝트에 사용하려면 반드시 알아야 한다고 생각한다.
    - 내 생각엔 이 카탈로그가 어드레서블 에셋 시스템의 핵심이지 않을까 싶다.
- ***3편***
    - 아래 예제는 스폰 버튼을 누르면 캐릭터를 생성하는데
    - 서버에서 내가 부르려는 어드레드 또는 레이블과 의존성을 가지는 모든 번들들을 통째로 다운받아 사용하는 방법과
    - 필요한 에셋만 하나가 포함된 번들만 다운받아 사용하는 방법을 보여준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr90.png)
    - 먼저 작성한 코드를 보자
    - 아래 코드는 우리가 이때까지 사용해온 방식으로 오브젝트를 생성하는 방식이다. (필요한 거 하나씩 다운로드하는 방법)
        ```
        using UnityEngine;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class Spawner : MonoBehaviour
        {
            private GameObject Character = null;

            [Header("캐릭터의 어드레스를 입력해 주세요!")]
            [SerializeField] private string CharacterAddress = string.Empty;

            private void Start()
            {
                Character = null;
            }

            public void _ClickSpawn()
            {

                //Character가 null포인터가 아니라면
                //해당 인스턴스를 제거.

                if (!ReferenceEquals(Character, null))
                {
                    ReleaseObj();
                }


                //캐릭터를 스폰 한다.
                Spawn();

            }

            void Spawn()
            {
                Addressables.InstantiateAsync(CharacterAddress, new Vector3(Random.Range(-2f, 2f), 5, 0), Quaternion.identity).Completed +=
                    (AsyncOperationHandle<GameObject> obj) =>
                    {
                        Character = obj.Result;
                    };

            }

            void ReleaseObj()
            {
                //객체가 삭제될 때 메모리 해제를 위해 레퍼런스 카운트 -1 및 오브젝트인스턴스 제거.
                Addressables.ReleaseInstance(Character);
            }

        }
        ```
    - 아래 코드는 번들을 한방에 다운받는 방법이다. DownloadDependenciesAsync("레이블")로 다운로드할 수 있고, GetDownloadSizeAsync("레이블")로 미리 사이즈를 확인할 수도 있다.
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class BundleDown : MonoBehaviour
        {
            [SerializeField] Text SizeText;

            [Space]
            [Header("다운로드를 원하는 번들 또는 번들들에 포함된 레이블중 아무거나 입력해주세요.")]
            [SerializeField] string LableForBundleDown = string.Empty;

            public void _Click_BundleDown()
            {
                Addressables.DownloadDependenciesAsync(LableForBundleDown).Completed +=
                    (AsyncOperationHandle Handle) =>
                    {
                        //DownloadPercent프로퍼티로 다운로드 정도를 확인할 수 있음.
                        //ex) float DownloadPercent = Handle.PercentComplete;

                        Debug.Log("다운로드 완료!");

                        //다운로드가 끝나면 메모리 해제.
                        Addressables.Release(Handle);

                    };
            }

            public void _Click_CheckTheDownloadFileSize()
            {
                //크기를 확인할 번들 또는 번들들에 포함된 레이블을 인자로 주면 됨.
                //long타입으로 반환되는게 특징임.
                Addressables.GetDownloadSizeAsync(LableForBundleDown).Completed +=
                    (AsyncOperationHandle<long> SizeHandle) =>
                    {
                        string sizeText = string.Concat(SizeHandle.Result, " byte");

                        SizeText.text = sizeText;

                        //메모리 해제.
                        Addressables.Release(SizeHandle);
                    };


            }
        }
        ```
- ***4편(서버 업로드)***
    - 이제 실제로 사용해 보도록 하겠다. 우선 서버가 있어야 하는데 "아마존 S3"를 사용하기로 했다.
        > *https://aws.amazon.com/ko/s3/*
    - s3의 콘솔에 로그인하고 버킷을 만들자 버킷 이름은 중복이 안되므로 자신만의 고유한 이름으로 작명하면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr91.png)
    - 다른 건 중요하지 않고 원활한 진행을 위해 이 부분(모든 퍼블릭 액세스 차단) 항목을 체크 해제하자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr92.png)
    - 그 뒤엔 전부 다음을 눌러 버킷을 생성하자.
    - 버킷이 생성되었다면 아무 파일이나 하나 올려보자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr93.png)
    - 그럼 이렇게 파일이 올라가고, 파일을 눌러보면 이렇게 주소가 나오는데
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr94.png)
    - 맨 마지막 파일 이름 대신 [BuildTarget]를 추가해서 복사해 두자.
    - 그리고 위 파일은 주소를 알아내기 위해 넣은 의미 없는 파일이니 지워주도록 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr95.png)
    - 어드레서블창을 키고 프로파일을 수정하기 위해 Manage Profiles를 찾아서 클릭하자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr96.png)
    - 이게 버전마다 위치가 다른 경우가 많은데 창에서 못 찾으면 아래 이미지처럼 어드레서블 세팅에도 있으니 확인해 보길 바란다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr97.png)
    - 창이 뜨면 빨간 동그라미가 있는 RemoteLoadPath에다가 기존 값을 지우고 아까 복사한 주소를 넣어주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr98.png)
    - 그런 다음 다시 그룹창으로 가서 그룹을 하나 만들어주고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr99.png)
    - 우 클릭을 통해 그룹 설정을 열어주자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr100.png)
    - 인스펙터를 확인해보면 설정이 열려있는 걸 확인할 수 있다.
    - 그리고 이 그룹은 리모트 즉 서버용으로 사용할 거니까 빌드와 로드 패스를 각각 리모트 빌드와 리모트 로드로 바꿔주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr101.png)
    - 이제 이 그룹으로 에셋을 넣어준 뒤 번들 식별을 위해 Character라는 레이블을 달아두도록 하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr102.png)
    - 그리고 처음 나온 두 스크립트를 아무 오브젝트에 넣은 뒤 값을 설정해준 다음
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr103.png)
    - 어드레서블 설정으로 가서 카탈로그를 설정해주면 모든 준비가 끝난다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr104.png)
    - 이제 번들을 빌드 해보자. 플레이 모드를 Use Existing Build로 수정하고 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr105.png)
    - 빌드 하면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr106.png)
    - 프로젝트 폴더 안에 ServerData라는 폴더가 생기고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr107.png)
    - 그 안에 빌드 한 플랫폼에 해당하는 폴더가 있으며 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr108.png)
    - 또 그 안에 카탈로그와 번들이 빌드 된 걸 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr109.png)
    - 이전 경로로 다시 돌아온 뒤
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr110.png)
    - 플랫폼 폴더를 통째로 서버에 업로드해주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr111.png)
    - 마지막으로 작업을 눌러서 퍼블릭 설정을 해주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr112.png)
    - 모든 준비가 끝났으니 프로젝트를 빌드 해서 실행해보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr113.png)
    - 스폰 버튼을 누르면 캐릭터가 잘 나오는 것을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr114.png)
    - 앱을 종료하고 다시 에디터로 가서 바꾸고 초록머리 캐릭터를 빨간 머리 캐릭터로 바꾸기 위해
    - 빨간 머리 에셋의 어드레스를 이전 초록머리의 어드레스랑 같은 이름으로 만들어 준 뒤
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr115.png)
    - 초록머리 어드레스를 지우고 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr116.png)
    - 빨간 머리 캐릭터를 리모트 그룹으로 옮겨 주고 레이블도 다시 지정해준 뒤 번들을 빌드 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr117.png)
    - 서버에서 기존 파일을 지우고 방금 새로 만든 번들과 카탈로그 파일들을 넣어주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr118.png)
    - 이때 유저는 앱을 다시 새로 다운로드하지 않았고 기존의 앱을 다시 실행한다. 
    - 다시 스폰을 눌러주면 캐릭터가 바뀐 것을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr119.png)
    - 다운로드 사이즈를 받아오는 것도 문제가 없다. 이렇게 앱을 재배포하지 않고서도 콘텐츠를 수정할 수 있으니 매우 편리하고 합리적이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr120.png)
- ***이제 마지막으로 다운로드에 대한 개념을 정리해보자.***
    - 어드레서블의 서버에서 로드한다는 말은 결국 번들을 다운받는다는 말과 같다.
        > - 예를 들어 
        > - "과일"이라는 번들에서 "사과"만 로드하더라도
        > - 나는 "과일"이라는 번들을 다운받은것이다.
        > - 때문에 이 다음번에 인터넷이 연결되어 있지 않아도
        > - 이미 로드한 "사과"에셋 또는 "과일"번들에 포함된 에셋들을 사용할 수 있다.
        > - (하나의 에셋만 로드한 직후 인터넷을 모두 끈상태로 같은 번들에 포함된 다른 에셋을 로드한 결과 로드됨)
    - 다운로드에는 번들 하나만 다운로드하는 방법과 여러개를 한방에 다운로드하는 방법이 있다.
        > - 하나씩 : LoadAsset, Inastantate 등등
        > - 한방에 : DownloadDependenciesAsync
    - DownloadDependenciesAsync(레이블)에서 레이블이라는 값을 가지는 번들을 모두 다운로드한다.
        > - 예를 들어 
        > - "과일"번들에 "망고"라는 에셋이 있고 "동남아 음식"이라는 레이블이 지정되어 있으며,
        > - "곡식"번들, "쌀"에셋, "동남아 음식"레이블이 있고,
        > - "과자"번들,"빠다코코낫"에셋,"한국 과자"레이블이 있을 때
        > - DownloadDependenciesAsync(동남아 음식)이라고 작성하면
        > - "과일","곡식"번들만 다운로드한다.
    - LoadAssets(레이블)을 사용할 땐 레이블이 지정된 에셋을 모두 가져온다.
        > - 우선
        > - LoadAsset과 LoadAssets가 다른 점을 인식하자.
        > - LoadAsset는 하나의 에셋만 리턴하고
        > - LoadAssets는 같은 레이블이 지정된 에셋들을 배열에 담아 리턴한다.
        > - 예를 들어
        > - "EBS 캐릭터"번들, "펭수"에셋, "펭귄"
        > - "EBS 캐릭터"번들, "뚝딱이"에셋, "도깨비"
        > - "EBS 캐릭터"번들, "뽀로로"에셋, "펭귄"
        > - 일 때
        > - LoadAssets(펭귄)을 사용하면
        > - 펭수, 뽀로로 에셋이 리턴된다.
    - 이미 다운로드한 번들이라도 서버에 해당 번들이 수정되어 있다면 다시 변경된 에셋a만 다운로드하는게 아니라 번들을 통째로 지우고 다시 다운받는다.
        > - 예를 들어
        > - "펭귄"어드레스를 가진 
        > - "뽀로로" 에셋을 "펭수"에셋으로 바꾸고 
        > - 그렇게 빌드 한 번들을 서버에 올리면
        > - 사용자는 기존의 번들 대신 교체된 새로운 번들을 통째로 다시 다운받아온다.
    - 인터넷이 연결된 상태라면 앱 실행 후 최초 로드할 때마다 번들 변경사항을 검토한다.(뇌피셜)
        > - 예를 들어
        > - 앱 사용 중간에 펭귄 번들의 "뽀로로"를 "펭수"로 바꿔도 앱 사용 중간엔 바뀌지 않는다.
        > - (사실 중간에 바뀌면 유저가 혼란해하기 때문에 바뀌게 할 수 있어도 안 바뀌는 게 맞음)
        > - 앱을 종료 후 다시 실행하고 처음 번들에 접근할 때 변경사항을 검토하고 
        > - 해당되는 에셋은 변경된 에셋을 다운로드한다.
    - GetDownloadSizeAsync()는 한번 받은적이 있으면 0을 반환한다.
        > - 공식문서의 GetDownloadSizeAsync() 설명 부분을 보면
        > - If you wish to ask the user for consent prior to download, use Addressables.GetDownloadSize() to return how much space is needed to download the content from a given address or label. Note that this takes into account any previously downloaded bundles that are still in Unity's asset bundle cache.
        > - 라고 적혀 있는데, 이미 다운 받은 경우 새로운 내용이 없다면 0을 반환 한다는 이야기로 추정된다.
        > - 실험 해본 결과 한번 다운받은 뒤 번들이 변경되지 않았다면 다운받지 않는다.
    - 여러개의 번들 중 하나의 번들을 수정하였다면 그 번들만 다시 다운받을수있다.
        > - DownloadDependenciesAsync(레이블)에 영향을 받는 번들이 5개있고
        > - 그 중 1개의 번들만 수정되었다면 그 1개만 다시 다운받는다.
- ***추가***
    - 퍼센트 출력 방법
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr121.png)
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr122.png)


　

## # 외부 서버 없이 서버 기능 테스트하기.

- 유니티 로컬 Hosting 서비스
    - 로컬 서버를 이용해서 테스트하는 워크플로우
    - 아래 이미지와 같은 경로를 통해 호스팅 창을 열고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr123.png)
    - 좌측 상단에 위치한 Create 버튼을 눌러서 Local Hosting을 클릭해 주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr124.png)
    - 그러면 오른쪽에 이런 화면이 나오는데
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr125.jpg)
    - 아무것도 건드리지 말고 그저 Enable만 체크해 주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr126.png)
    - 그러면 이렇게 ip 주소와 포트 번호가 나오는데
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr127.png)
    - 아이피와 포트 번호 각각 앞에 있는 변수에 우 클릭을 하고 키를 복사한 뒤 메모장에다가 붙여넣기를 하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr128.png)
        > - [PrivateIpAddress]
        > - [HostingServicePort]
        > - 그럼 위와 같은 뒤 변수가 복사되는데
        > - 이걸 http://[PrivateIpAddress]:[HostingServicePort] 이렇게 작성해 주면 된다.
    - 프로필 설정 창을 열고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr129.png)
    - 프로필을 하나 추가해준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr130.png)
    - 그리고 이름을 적당하게 바꿔준 뒤 remotepath들을 수정해 주자.
    - 빌드 패스는 원래 적혀있던 ServerData를 HostedData라고 고쳐주고
    - 로드 패스는 http://[PrivateIpAddress]:[HostingServicePort]를 넣어주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr131.png)
    - 그런 다음 어드레서블 인스펙터창을 열고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr132.png)
    - 기존 프로필을
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr133.png)
    - 방금 만들어준 프로필로 설정해 주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr134.png)
    - 다른 서버 관련 설정들은 이전에 한대로...
    - 이렇게 해주고 번들을 빌드 한 뒤 게임을 빌드하고 나서 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr135.png)
    - 게임 실행 후 다운로드할 번들 사이즈를 가져오면 잘 가져오는 것을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr136.png)
    - 이때 다운로드를 하고 나서, 가져올 사이즈가 0인 걸 확인하고 번들 정보만 변경시켰을 경우 다시 다운로드할 수 있는지 확인해보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr137.png)
    - 우선 혹시나 쓸데없는 캐시가 덮어써지는 것을 방지하기 위해 빌드 캐시를 먼저 clean시켜주고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr138.png)
    - 2번 번들에서 펭수를 빼보았다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr139.png)
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr140.png)
    - 빌드 업데이트를 클릭하고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr141.png)
    - state가 담긴 bin 파일을 기준으로 하여 번들을 업데이트해 주었다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr142.png)
    - 그리고 앱 빌드 없이 바로 아까 빌드 해 놓은 게임을 연 뒤 다시 사이즈를 가져 와보면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr143.png)
    - 정보가 변경된 두 번째 번들만 다시 다운로드해 오는 것을 확인할 수 있다. 
    - 이로써 앱을 다시 빌드 하지 않고도 콘텐츠를 수정할 수 있었으며
    - 따로 아마존과 같은 서버를 이용하지 않고도 서버 테스트를 할 수 있는 것을 확인해보았다.
