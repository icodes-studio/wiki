## # 외부 서버 없이 서버 기능 테스트하기.

*https://blog.naver.com/cdw0424/222090659316*

- 유니티 로컬 호스팅 서비스 준비
    - 메뉴 ***Window ‣ Asset Management ‣ Addressables ‣ Hosting*** 항목을 선택하여 호스팅 창을 연다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr123.png)
    - 좌측 상단에 위치한 ***Create*** 버튼을 눌러서 ***Local Hosting*** 항목을 선택하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr124.png)
    - ***Enable*** 필드를 체크하면 아이피 주소와 포트 번호가 나온다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr126.png)
    - 아이피와 포트 번호를 확인할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr128.png)
        > - *잠시후 이 값을 http://[PrivateIpAddress]:[HostingServicePort] 이렇게 사용할 예정이다.*
    - 이어서 프로필을 하나 새로 추가하고 Remote를 ***Editor Hosted*** 모드로 변경하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr130.png)
    - 그리고 이름을 적당하게 바꿔준 뒤 remotepath들을 수정해 주자.
    - 빌드 패스는 원래 적혀있던 ServerData를 HostedData라고 고쳐주고
    - 로드 패스는 http://[PrivateIpAddress]:[HostingServicePort]를 넣어주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D/AssetBundles/Assets/addr131.png)
    - 그런 다음 어드레서블 인스펙터창을 열고 기존 프로필을 방금 만들어준 프로필로 설정해 주자.
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