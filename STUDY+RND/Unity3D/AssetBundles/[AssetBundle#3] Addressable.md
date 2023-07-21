## # Addressables

- ***References***
    - *https://planek.tistory.com/22*
    - [*Unity Blog Addressable 소개*](https://blogs.unity3d.com/kr/2019/07/15/addressable-asset-system/)
    - [*Unity Addressable 1.13 메뉴얼*](https://docs.unity3d.com/Packages/com.unity.addressables@1.13/manual/index.html)
    - [*Unity Addressable Tutorial*](https://learn.unity.com/tutorials/?k=%5B%22lang%3Aen%22%2C%22lang%3Ako%22%2C%22q%3Aaddressable%22%5D&ob=starts)
    - [*Official: 어드레서블 애셋 시스템*](https://blog.unity.com/kr/games/addressable-asset-system)
    - [*Official: Addressables-Sample*](https://github.com/Unity-Technologies/Addressables-Sample)
    - [*YouTube 동영상*](https://www.youtube.com/playlist?list=PLmRK0lH8TNCo7K4xmLpEov4llbVTwf29s)
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
    - 인스펙터 필드를 만드니, 이런 드롭아웃 버튼이 생기고 선택 가능한 어드레서블에셋들이 나열된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr14.png)
