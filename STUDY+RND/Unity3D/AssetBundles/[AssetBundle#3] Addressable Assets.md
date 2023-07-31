## # Addressable Assets
    ● 어드레서블 애셋 시스템을 이용하여 주소를 통해 애셋을 요청할 수 있다.
    ● 애셋(예: 프리팹)이 “어드레서블”로 표시되면 어디에서든 호출할 수 있는 주소가 생성된다.
    ● 애셋 위치(로컬 또는 원격)에 관계없이 시스템은 애셋과 해당 종속성을 찾아 반한다.
    ● 어드레서블 애셋 시스템은 애셋 번들을 대체하는 기술이 아니다. 
    ● 애셋 번들을 쉽고 효율적이게 사용하는 유틸리티라고 보면 된다.
    ● 근데 쉬운 거 맞음?
*https://blog.unity.com/kr/games/addressable-asset-system*


　

## # 설치 및 준비

*https://blog.naver.com/cdw0424/221636733877*

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

*https://blog.naver.com/cdw0424/221636783259*

- ***Settingup***
    - 테스트 할 애셋으로 ***Cube 프리팹***을 하나 만들자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr0.png)
    - 애셋을 어드레서블로 로드하기 위해서는 인스펙터에서 ***Addressable*** 항목을 선택해야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr7.png)
    - ***Addressable*** 항목을 선택하면 바로 옆에 어드레스가 자동으로 생성되는데, 이 값으로 애셋을 로드할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr8.png)
    - 이 값은 다른 어드레스와 겹치지만 않는다면 원하는 대로 수정할 수 있다. ***Cube***로 변경.
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
                Addressables.LoadAssetAsync<GameObject>("Cube").Completed += OnLoadCompleted;
            }

            void OnLoadCompleted(AsyncOperationHandle<GameObject> obj)
            {
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

*https://blog.naver.com/cdw0424/221636822258*

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

*https://blog.naver.com/cdw0424/221637349195*

- ***API sets***
    - *https://www.youtube.com/watch?v=yoBzTpJYN44&t=1972s*
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr25.png)
    - ***LoadAssetAsync, InstantiateAsync에 맞게 해제***
        > - ***LoadAssetAsync*** 함수로 로드한 애셋은 ***Release*** 함수로 언로드
        > - ***InstantiateAsync*** 함수로 로드 및 생성한 오브젝트는 ***ReleaseInstance*** 함수로 언로드
    - ***Addressable, AssetReference 클래스 각각에 언로드 함수 존재***
        > - *Addressables.Release*
        > - *Addressables.ReleaseInstance*
        > - *AssetReference.Release*
        > - *AssetReference.ReleaseInstance*
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

        public class ReleaseCube : MonoBehaviour
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

https://blog.naver.com/cdw0424/221637763395

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

*https://blog.naver.com/cdw0424/221638017138*

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


　

## # 서버에서 다운로드하기 #1

*https://blog.naver.com/cdw0424/221755856111*

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
        > - 빌드 된 번들의 위치 정보나, 어떤 식으로 가져올 것인지에 대한 설정들의 묶음이다.
        > - 우리는 원격으로 사용할 것이기 때문에 ***Build Remote Catalog***를 체크해 주었다.
    - ***Build & Load Paths***는 ***Remote***로 선택하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr63.png)
    - 로컬 패스는 프로젝트 내부에 번들이 생성되지만, 리모트 패스는 기본 경로가 이렇게 프로젝트 밖의 ***ServerData*** 폴더로 설정된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr64.png)
    - 그 안엔 실제로 빌드 시 이렇게 번들이 들어가 있다. 나중에 이걸 서버에 넣어주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr65.png)
    - 지금 위 폴더를 살펴보면 번들이 없는데, 아직 번들을 이 폴더에 빌드 하겠다고 설정을 안 했기 때문이다. 나중에 할 거임.


　

# 서버에서 다운로드하기 #2

*https://blog.naver.com/cdw0424/221756844361*

- ***Catalog 이해하기***
    - ***Build Remote Catalog***
        > - 각 어드레스와 자산(애셋)을 매핑하며, 원한다면 매핑을 변경하여 불러올 번들의 위치와 로드 방법 등을 설정할 수 있다.
        > - 그러기 위해선 이렇게 ***Build Remote Catalog*** 항목을 활성화해주어야 한다.
        > - 이것을 체크해 주면 리모트 서버에 저장하기 위한 카탈로그 사본을 생성한다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr66.png)
    - 직접 빌드 해보기 위해 플레이 모드를 ***Use Existing Build*** 모드로 바꾼 뒤,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr67.png)
    - 빌드를 하면 이런 식으로 catalog json, hash 파일이 생성된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr68.png)
        > - *번들이 없는 이유는 아직 번들을 이 폴더에 빌드 하겠다고 설정을 안 했기 때문. 나중에 할 거임.*
    - JSON 파일을 열어서 살펴보면,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr69.png)
        > - 이렇게 번들과, 어드레스 애셋 정보가 있는 것을 확인할 수 있다.
        > - 그렇기 때문에 나중에 우리는 번들과 함께 이 카탈로그 사본도 함께 서버(CDN)에 넣어 주어야 한다.
    - ***Only update catalogs manually*** 옵션을 키면 카탈로그가 초기화될 타이밍에 버전 체크를 하지 않는다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr70.png)
        > - ~~아직 이게 무슨말인지 정확히 모르겠다~~
    - ***Player Version Override*** 필드로 카탈로그의 버전을 관리를 할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr71.png)
    - 예를 들어, 이 값을 1로 지정하고 빌드 하면 1 버전 값을 가진 기존과 다른 파일이 생긴다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr73.png)
    - 이 값을 원래대로 ***[UnityEditor.PlayerSettings.bundleVersion]*** 값으로 돌려놓고, ***Plyaer ‣ Version*** 값을 ***999***로 바꿔보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr74.png)
    - 이 상태로 빌드하면 999 버전 값을 가진 카탈로그 파일이 생성된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr77.png)
    - 이렇게 생성된 카탈로그들을 식별하는 것이 바로 ***addressables_content_state.bin*** 파일이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr78.png)
    - 열어보면 대충 이런 식으로 적혀있는데, 카탈로그 버전 정보가 들어있는 것을 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr80.png)
    - 또한, 각 플랫폼마다 ***addressables_content_state.bin*** 파일이 존재하므로 플랫폼 별로 관리가 가능하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr84.png)
        > 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr85.png)


　

# 서버에서 다운로드하기 #3

*https://blog.naver.com/cdw0424/221764918184*

- ***코드준비***
    - 캐릭터(큐브)를 소환하는 예제를 작성해보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr90.png)
        > - *Spawn: 누르면 캐릭터(큐브) 생성*
        > - *Download: 의존성을 가지는 모든 번들들을 통째로 다운로드*
        > - *Sizeof: 다운로드할 파일 크기 가져오기*
    - ***캐릭터 소환 코드 - Spawner.cs***
        ```
        using UnityEngine;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class Spawner : MonoBehaviour
        {
            private GameObject character;
            [SerializeField] private string characterAddress;

            public void OnClickSpawn()
            {
                if (ReferenceEquals(character, null) == false)
                    ReleaseCharacter();

                Spawn();
            }

            void Spawn()
            {
                Addressables.InstantiateAsync(
                    characterAddress, new Vector3(Random.Range(-2f, 2f), 5, 0), Quaternion.identity).Completed +=
                    (AsyncOperationHandle<GameObject> obj) =>
                    {
                        character = obj.Result;
                    };

            }

            void ReleaseCharacter()
            {
                Addressables.ReleaseInstance(character);
            }
        }
        ```
    - ***번들 다운로드 코드 - BundleDownload.cs***
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.AddressableAssets;
        using UnityEngine.ResourceManagement.AsyncOperations;

        public class BundleDown : MonoBehaviour
        {
            [SerializeField] Text sizeText;
            [SerializeField] string lableForBundleDown = string.Empty;

            public void OnClickDownload()
            {
                Addressables.DownloadDependenciesAsync(lableForBundleDown).Completed +=
                    (AsyncOperationHandle handle) =>
                    {
                        Debug.Log("Download Completed!");
                        Addressables.Release(handle);
                    };
            }

            public void OnClickDownloadFileSize()
            {
                Addressables.GetDownloadSizeAsync(lableForBundleDown).Completed +=
                    (AsyncOperationHandle<long> handle) =>
                    {
                        sizeText.text = $"{handle.Result} byte";
                        Addressables.Release(handle);
                    };
            }
        }
        ```


　

- ***서버(CDN) 준비***
    - 우선 서버(CDN)가 있어야 하는데 ***Amazon S3***를 사용해보자
        > ![https://aws.amazon.com/ko/s3/](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/amazon-s3-960x504.png)
        > - *https://aws.amazon.com/ko/s3/*        
    - 콘솔에 로그인하고 S3 버킷을 만들자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr86.png)
    - 버킷 이름은 중복이 안되므로 자신만의 고유한 이름으로 작명하면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr91.png)
    - 원활한 진행을 위해 ***모든 퍼블릭 액세스 차단*** 항목을 체크 ***해제*** 하자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr92.png)
    - 퍼블릭 접근을 위해, 버킷 정책을 아래와 같이 편집한다. ARN 이름은 속성 탭에서 확인할 수 있다.
        ```
        {
            "Version": "2012-10-17",
            "Statement": [
                {
                    "Sid": "Stmt1405592139000",
                    "Effect": "Allow",
                    "Principal": "*",
                    "Action": "s3:*",
                    "Resource": [
                        "ARN 이름/*",
                        "ARN 이름"
                    ]
                }
            ]
        }
        ```
    - 또는 객체 소유권 설정에서 ***ACL 활성화*** 옵션을 키고 업로드한 파일을 퍼블릭으로 만들어도 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr95.png)
    - 버킷에 아무 파일이나 하나 올려보자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr93.png)
    - 업로드된 파일 속성을 보면 이렇게 웹 주소가 나온다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr94.png)
    - 객체 URL을 클릭했을 때, 아래 처럼 ***AccessDenied*** 에러코드가 떨어지면 문제가 있는 거다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr21.png)
    - ACL 활성화 옵션을 킨 경우라면, ***ACL을 사용하여 퍼블릭으로 설정*** 항목을 선택하고 접근이 되는지 확인해보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr22.png)
    - 모두 문제가 없다면, 객체 URL에서 맨 마지막 파일 이름 대신 ***[BuildTarget]*** 문자열을 추가해서 잠시 복사해 두자.
        ```
        https://s3.ap-northeast-2.amazonaws.com/버킷이름/[BuildTarget]
        ```


　

- ***번들 준비 및 업로드***
    - 프로필 추가를 위해 ***Manage Profiles*** 메뉴를 선택하여 ***Addressables Profiles*** 창을 연다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr96.png)
    - 프로필 창 띄우는 방법이 유니티 버전마다 조금씩 다른데... 어드레서블 세팅 인스펙터에도 있고,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr97.png)
    - 메뉴 ***Window ‣ Asset Management ‣ Addressables ‣ Profiles*** 항목을 선택하여 띄울 수도 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr51.png)
    - 암튼, 프로필 창이 뜨면 ***Remote.LoadPath*** 필드에 기존 값을 지우고 아까 복사한 주소를 넣어주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr98.png)
    - 그런 다음 다시 그룹창으로 가서 그룹을 하나 만들어주고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr99.png)
    - 우 클릭을 통해 그룹 설정을 열자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr100.png)
    - 이 그룹은 리모트 즉 서버용으로 사용할 거니까 ***Build & Load Paths*** 필드를 ***Remote*** 모드로 변경한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr101.png)
    - 이제 이 그룹으로 애셋을 넣어준 뒤, 번들 식별을 위해 ***Character*** 라는 레이블을 달아두도록 하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr102.png)
    - 그리고 처음에 만들었던 두 스크립트를 적당한 오브젝트에 적당히 바인딩하고 적당히 값을 넣은다음...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr103.png)
    - 어드레서블 설정으로 가서 카탈로그를 설정해주면 모든 준비가 끝난다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr104.png)
    - 이제 번들을 빌드 해보자. 플레이 모드를 ***Use Existing Build*** 모드로 수정하고 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr105.png)
    - 빌드 하면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr106.png)
    - 프로젝트 폴더 안에 ***ServerData*** 폴더가 생기고
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr107.png)
    - 그 안에 플랫폼에 해당하는 폴더가 있으며, 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr108.png)
    - 또 그 안에 카탈로그와 번들이 빌드 된 걸 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr109.png)
    - ***StandaloneWindows64*** 플랫폼 폴더를 통째로 S3에 업로드하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr111.png)
    - 마지막으로 작업을 눌러서 퍼블릭 설정을 해주면 된다. (버킷 정책을 모두 Allow로 편집한 경우는 필요 없음)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr112.png)
    - 모든 준비가 끝났으니 게임을 실행해보자. Spawn 버튼을 누르면 큐브가 잘 나오는지 확인하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr114.png)


　

- ***번들 업데이트***
    - 큐브의 재질을 변경해서 번들을 업데이트 해보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr115.png)
    - 큐브의 모양이 좀 달라지도록 적당히 모습을 바꿔주고...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr116.png)
    - 번들을 빌드 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr106.png)
    - 서버에서 기존 파일을 지우고 방금 새로 빌드한 번들과 카탈로그 파일들을 넣어주자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr118.png)
    - 다운로드 사이즈도 새로 잘 받아온다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr120.png)
        > - *참고: GetDownloadSizeAsync()는 한번 받은적이 있으면 0을 반환한다.*
    - 다시 스폰 해보면 모습이 바뀐 큐브를 로드한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr119.png)


　

## # 외부 서버 없이 서버 기능 테스트하기.

*https://blog.naver.com/cdw0424/222090659316*

- 잘 안되네...