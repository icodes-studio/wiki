## # Addressable Assets
    ● 어드레서블 시스템은 기존 에셋번들 시스템을 더 사용하기 편하게 제공하기 위해 래핑 된 것이다.
    ● 애셋번들 위에서 돌고 있는 게 어드레서블 시스템이라는 말이다.
    ● 그러니 애셋번들 시스템이 없어지는가? 하는 걱정은 말자.
*https://blog.unity.com/kr/games/addressable-asset-system*


　

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
    - 큐브 프리팹을 로드하는 스크립트를 만들어서 버튼 오브젝트에 바인딩 해주자.
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
    - 세팅 인스펙터는 ***Window ‣ Asset Management ‣ Addressables ‣ Settings*** 메뉴 항목을 선택해서도 띄울 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr20.png)
    - 어드레서블 애셋을 로드하기 시작하면 프로파일링을 시작한다. 아래는 큐브를 36개 생성했을 때의 이벤트 뷰어 모습이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr19.png)


　

## # 애셋 언로드

- ***References***
    - *https://www.youtube.com/watch?v=yoBzTpJYN44&t=1972s*
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr25.png)
- ***LoadAssetAsync, InstantiateAsync에 맞게 해제***
    - ***LoadAssetAsync*** 함수로 로드한 애셋은 ***Release*** 함수로 언로드
    - ***InstantiateAsync*** 함수로 로드 및 생성한 오브젝트는 ***ReleaseInstance*** 함수로 언로드
- ***Addressable, AssetReference 클래스 각각에 언로드 함수 존재***
    - *Addressables.Release*
    - *Addressables.ReleaseInstance*
    - *AssetReference.Release*
    - *AssetReference.ReleaseInstance*
- ***동작확인***
    - 큐브 오브젝트를 생성하는 스크립트를 만들어서 버튼 오브젝트에 바인딩.
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
                Addressables.InstantiateAsync("Cube", new Vector3(0, 0, 0), Quaternion.identity);
            }
        }
        ```
    -  릴리즈하는 스크립트를 만들어 Cube 프리팹에 바인딩.
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
    - 실행하고 이벤트 뷰어를 확인하면 카운트가 줄어드는 모습을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr28.png)
    - ***AssetReference.ReleaseInstance*** 함수를 사용하는 예제 하나만 더 살펴보자
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class InstantiateCube : MonoBehaviour
        {
            Button button;
            GameObject temp;
            [SerializeField] AssetReference assetReference;

            void Start()
            {
                button = GetComponent<Button>();
                button.onClick.AddListener(OnCreateCube);
            }

            void OnCreateCube()
            {
                assetReference.InstantiateAsync(new Vector3(0, 0, 0), Quaternion.identity).Completed +=
                    (AsyncOperationHandle<GameObject> op) =>
                    {
                        temp = op.Result;
                        Invoke("ReleaseDestroy", 3f);
                    };
            }

            void ReleaseDestroy()
            {
                assetReference.ReleaseInstance(temp);
            }
        }
        ```
    - ***Addressable.Release*** 함수를 사용하는 예제 하나만 더 살펴보자.
        ```
        using System.Collections;
        using UnityEngine;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class InstantiateCube : MonoBehaviour
        {
            GameObject temp;
            AsyncOperationHandle<GameObject> opHandle;

            public IEnumerator Start()
            {
                opHandle = Addressables.LoadAssetAsync<GameObject>("Cube");
                yield return opHandle;

                if (opHandle.Status == AsyncOperationStatus.Succeeded)
                    temp = Instantiate(opHandle.Result);

                Invoke("ReleaseDestroy", 1f);
            }

            void ReleaseDestroy()
            {
                Destroy(temp);
                Addressables.Release(opHandle);
            }
        }
        ```


　

## # 씬 로드와 언로드

- ***LoadSceneAsync***
    - 씬을 하나 만들고 어드레서블 체크 후 이름을 정해 주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr29.png)
    - 씬을 로드하는 ***LoadSceneAsync*** 함수가 따로 준비되어 있다.
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;

        public class NextScene : MonoBehaviour
        {
            public string nextSceneAddress;
            Button nextButton;

            void Start()
            {
                nextButton = GetComponent<Button>();
                nextButton.onClick.AddListener(OnClickButton);
            }

            void OnClickButton()
            {
                Addressables.LoadSceneAsync(nextSceneAddress);
            }
        }
        ```
    - 버튼에 위 스크립트를 바인딩 시키고, 이동할 씬 어드레스를 지정하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr30.png)
    - 버튼을 클릭하여 씬 로딩 동작을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr31.png)
- ***UnloadSceneAsync***
    - 씬 언로드를 테스트하기 위해 ***LoadSceneMode.Additive*** 옵션으로 중복 씬을 로드하고 제대로 제거가 되는지 살펴보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr32.png)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr33.png)
    - 아래 코드를 작성하고 버튼 오브젝트에 바인딩하여 테스트.
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;
        using UnityEngine.SceneManagement;
        using UnityEngine.ResourceManagement.AsyncOperations;
        using UnityEngine.ResourceManagement.ResourceProviders;

        public class LoadSubScene : MonoBehaviour
        {
            [SerializeField] Text text;

            Button button;
            bool readyToLoad = true;
            SceneInstance loadedScene;

            void Start()
            {
                button = GetComponent<Button>();
                button.onClick.AddListener(OnLoadSubScene);
            }

            void OnLoadSubScene()
            {
                if (readyToLoad)
                    Addressables.LoadSceneAsync("5Cube", LoadSceneMode.Additive).Completed += OnSceneLoaded;
                else
                    Addressables.UnloadSceneAsync(loadedScene).Completed += OnSceneUnloaded;
            }

            void OnSceneLoaded(AsyncOperationHandle<SceneInstance> obj)
            {
                if (obj.Status == AsyncOperationStatus.Succeeded)
                {
                    text.text = "언로드 5Cube";
                    loadedScene = obj.Result;
                    readyToLoad = false;
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
                    readyToLoad = true;
                    loadedScene = default;
                }
                else
                {
                    Debug.LogError("언로드 실패");
                }
            }
        }
        ```


　

## # 빌드 후 번들 사용

- ***Play Mode Script***
    - ***Addressables Groups*** 윈도우의 상단부에 위치한 ***Play Mode Script*** 항목을 보면 아래와 같다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr37.png)
    - ***Use Asset Database (fastest)***
        > - 애셋번들을 빌드하지 않고 애셋 데이터 베이스를 사용하여 바로 플레이가 가능한 모드
        > - 에디터에서 테스트할 때만 이용 가능하다.
    - ***Simulate Groups (advanced)***
        > - 가상의 번들을 빌드해 해당 번들을 확인하는데 사용한다.
        > - 번들 테스트 및 프로파일링 할 때 유용하다.
    - ***Use Existing Build (requires built groups)*** 
        > - 실제 애셋번들 빌드를 통해 그룹화된 파일을 생성해야만 이 모드로 플레이가 된다.
        > - 즉, 물리적으로 존재하는 번들을 직접 참조해서 애셋을 로드하는 방식.
    - 빌드를 하면,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr38.png)
    - 빌드 내용이 담긴 bin 파일이 생긴다. (번들아님)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr39.png)
    - ***Use Existing Build*** 모드로 플레이 하면, 번들 파일에서 데이터를 가져오는 걸 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr41.png)


　

## # 서버에서 다운로드하기

- ***Settingup***
    - 서버에 넣을 번들과 로컬에서 사용할 번들을 구분해보자. 우선, 우 클릭을 통해 그룹을 새로 생성한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr45.png)
    - 이렇게 생성된 그룹은 각각의 애셋 번들로 빌드 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr46.png)
    - 방금 만든 그룹을 ***RemoteAssets*** 이름으로 변경.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr47.png)
    - 각 어드레서블 애셋들을 새로 만든 그룹으로 옮겨주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr50.png)
    - 메뉴 ***Window ‣ Asset Management ‣ Addressables ‣ Profiles*** 항목을 선택하여 프로필 윈도우를 띄우자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr51.png)
    - ***Create ‣ Profile*** 항목을 선택하여 새 프로필 생성.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr53.png)
    - 프로필이 생성되면 이름을 적당하게 바꿔준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr55.png)
    - 다시 어드레서블 그룹으로 가서 프로필을 방금 만든 걸로 바꿔주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr56.png)
    - ***AddressableAssetSettings*** 인스펙터를 띄워보자. ***Tools ‣ Inspect System Settings*** 메뉴 선택.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr57.png)
    - 프로필이 잘 바뀌었는지 확인하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr60.png)
    - 다음으로, ***Catalog***의 ***Build Remote Catalog*** 필드를 체크해 준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr62.png)
    - 카탈로그가 뭐냐면...
        > - 빌드 된 번들의 위치 정보나 또 어떤 식으로 가져올 것인지에 대한 설정들의 묶음이다.
        > - 우리는 원격으로 사용할 것이기 때문에 ***Build Remote Catalog***를 체크해 주었다.
    - ***Build & Load Paths***는 ***Remote***로 선택하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr63.png)
    - 로컬 패스는 프로젝트 내부에 번들이 생성되지만, 리모트 패스는 기본 경로가 이렇게 프로젝트밖의 ***ServerData*** 폴더로 설정된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr64.png)
    - 그 안엔 실제로 빌드 시 이렇게 번들이 들어 가있다. 나중에 이걸 서버에 넣어주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr65.png)
    - 지금 위 폴더를 살펴보면 번들이 없는데, 아직 번들을 이 폴더에 빌드 하겠다고 설정을 안 했기 때문이다. 나중에 할 거임.


　

- ***Catalog 이해하기***
    - ***카탈로그(Catalog)란...***
        > - 각 어드레스와 자산(애셋)을 매핑하며, 원한다면 매핑을 변경하여 불러올 번들의 위치와 로드 방법 등을 설정할 수 있다.
        > - 그러기 위해선 이렇게 ***Build Remote Catalog*** 항목을 활성화해주어야 한다.
        > - 이것을 체크해 주면 리모트 서버에 저장하기 위한 카탈로그 사본을 생성한다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr66.png)
    - 직접 빌드 해보기 위해 플레이 모드를 Existing으로 바꾼 뒤,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr67.png)
    - 빌드를 하면 이런 식으로 catalog json, hash 파일이 생성된다.
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