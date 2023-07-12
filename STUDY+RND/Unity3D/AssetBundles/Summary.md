## AssetBundles

　

에셋 번들은 플랫폼별 비코드 에셋(예: 모델, 텍스처, 프리팹, 오디오 클립, 씬 전체)이 들어 있는 아카이브 파일이며 런타임 시점에 로드할 수 있습니다.
에셋 번들에는 서로 종속성을 표시할 수 있습니다.
예를 들어 한 에셋 번들의 머티리얼이 다른 에셋 번들의 텍스처를 참조할 수 있습니다.
효율적인 네트워크 전송을 위해 에셋 번들은 사용 요구 사항(LZMA 및 LZ4)에 따라 빌트인 알고리즘을 사용하여 압축할 수 있습니다.
에셋 번들은 다운로드 가능 콘텐츠(DLC)에 유용합니다.
초기 설치 크기를 줄이고, 최종 사용자 플랫폼용으로 에셋 로딩이 최적화되고, 런타임 메모리의 압박이 줄어듭니다.

***참고:***
    - 에셋 번들은 ScriptableObject처럼 코드 오브젝트 인스턴스의 직렬화된 데이터를 포함할 수 있습니다.
    - 하지만 클래스 정의 자체가 프로젝트 어셈블리 하나로 컴파일됩니다.
    - 에셋 번들에 직렬화된 오브젝트를 로드하면 Unity는 일치하는 클래스 정의를 찾고 그 인스턴스를 생성하고 직렬화된 값을 사용하여 해당 인스턴스 필드를 설정합니다.
    - 즉 아이템이 클래스 정의에 어떤 변화도 주지 않는 한 에셋 번들에서 게임에 새로운 아이템을 사용할 수 있습니다.

　

## What's in an AssetBundle?

ㄱ

“에셋 번들”은 서로 다르지만 관련 있는 두 가지를 의미할 수 있습니다.

첫 번째는 디스크상의 실제 파일입니다. 이 파일은 에셋 번들 아카이브라고 불립니다. 에셋 번들 아카이브는 폴더와 같은 컨테이너이며 안에 추가 파일을 보관합니다. 이러한 추가 파일들은 다음의 두 타입으로 나뉩니다.

직렬화된 파일 - 개별 오브젝트로 이루어져 있고 이 단일 파일에 작성되는 에셋을 보관합니다.
리소스 파일 - 특정 에셋(텍스처 및 오디오)에 대해 개별적으로 저장되는 바이너리 데이터 조각으로, Unity가 다른 스레드의 디스크에서 효율적으로 로드하도록 도와줍니다.
또한 “에셋 번들”은 특정 에셋 번들 아카이브에서 에셋을 로드하기 위해 코드를 통해 상호작용하는 실제 에셋 번들 오브젝트를 나타낼 수도 있습니다. 이 오브젝트에는 이 아카이브에 추가한 에셋의 모든 파일 경로 맵이 들어 있습니다.























- https://docs.unity3d.com/Manual/AssetBundlesIntro.html
- https://medium.com/dreamarofficial/using-assetbundles-in-your-next-game-or-application-9899251a998e
- https://planek.tistory.com/22

　

　

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
