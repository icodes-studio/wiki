# CHAPTER 7 - Addition
    ● Sprite Atlas
    ● TextMesh Pro


　

## Sprite Atlas

- **Overview**
    - 유니티에서 아틀라스(Atlas) 는 여러 개의 스프라이트(Sprite)를 한 장의 큰 텍스쳐에 모아놓은 것이라고 볼 수 있다.
    - 게임에는 UI와 배경, 캐릭터, 이펙트 등등에 수많은 텍스쳐 들이 사용되는데 각 텍스쳐 별로 렌더링 할 때마다 한번의 드로우콜이 발생하게 된다.
    - 게임 내에 UI 요소들 별로 별도의 텍스쳐로 나뉘어져 있다면 총 20개의 UI 요소가 있다고 가정했을 때 20번의 드로우콜이 발생하게 된다.
    - 그런데 이 20개의 각각의 텍스쳐들을 한장의 텍스쳐에 모아놓고 UV 좌표를 조절해 UI 요소들이 사용한다면 드로우콜을 1회로 줄일 수 있다.
    - 게임의 퍼포먼스에 드로우콜이 얼마나 큰 영향을 미치는지 감안한다면 아틀라스의 사용은 선택이 아니라 필수이다.
    - 유니티에서는 예전부터 [*Sprite Packer*](https://learnandcreate.tistory.com/131) 라는 툴을 통해 아틀라스를 제작하고 사용할 수 있었다.
    - 하지만 2019 이상부터 레거시라는 꼬리표가 달리고 [***Sprite Atlas***](https://skuld2000.tistory.com/28)가 사용된다. 또한 2020 이상부터는 Sprite Atlas만 사용 가능하다.
 
- **Settings**
    - 아틀라스를 사용하려면 먼저 유니티의 Edit > Project Setting 창을 열고 Sprite Packer 항목을 확인
    - Unity 2019.2.5f1 버전을 기준으로 아래의 화면이 보인다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-settings.png)
    - **1. Enabled For Builds(Legacy Sprite Packer)**
        > - 기존의 스프라이트 패커를 사용한다.
        > - 빌드 시에만 아틀라스를 생성, 로드 한다.
        > - 유니티 에디터의 Play 모드에서 실행하면 아틀라스가 아닌 각각의 스프라이트를 사용한다.
    - **2. Always Enabled(Legacy Sprite Packer)**
        > - 기존의 스프라이트 패커를 사용하여 아틀라스를 생성한다.
        > - 빌드 시 뿐만 아니라 유니티 에디터의 Play 모드에서 실행해도 아틀라스를 생성, 로드 한다.
        > - 다만 플레이 모드가 아닌 SceneView의 일반 에디트 모드에서는 아틀라스를 사용하지 않는다.
    - **3. Enabled For Builds**
        > - 새로운 Sprite Atlas 를 사용한다.
        > - 빌드 시에만 아틀라스를 생성, 로드 한다.
        > - 유니티 에디터의 Play 모드에서 실행하면 아틀라스가 아닌 각각의 스프라이트를 사용한다.
    - **4. Always Enabled**
        > - 새로운 Sprite Atlas 를 사용한다.
        > - 빌드 시 뿐만 아니라 유니티 에디터의 Play 모드에서 실행해도 아틀라스를 생성, 로드 한다.
        > - 다만 플레이 모드가 아닌 SceneView의 일반 에디트 모드에서는 아틀라스를 사용하지 않는다.

- **Sprite Atlas 생성하기**
    - 기존 스프라이트 팩커의 경우 각각의 스프라이트에 태그를 입력하면 이 태그를 기준으로 팩커가 스프라이트를 팩킹하는 방식이었으나 
    - 스프라이트 아틀라스는 그와 달리 아틀라스 파일을 생성한 후 여기에 팩킹할 스프라이트 들을 직접 추가하는 방식이다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create.png)
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create2.png)
    - 적당한 위치에 빈 스프라이트 아틀라스를 Create 한다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create3.png)



- ***See Also***
    - ***https://docs.unity3d.com/2023.2/Documentation/Manual/class-SpriteAtlas.html***
    - ***https://skuld2000.tistory.com/28***
    - ***https://hannom.tistory.com/202***
    - ***https://everyday-devup.tistory.com/62***
    - ***https://young-94.tistory.com/85***
    - [***https://maintaining.tistory.com/***](https://maintaining.tistory.com/entry/Unity-%EC%8A%A4%ED%94%84%EB%9D%BC%EC%9D%B4%ED%8A%B8-%EC%95%84%ED%8B%80%EB%9D%BC%EC%8A%A4Sprite-Atlas-%EC%82%AC%EC%9A%A9-%EB%B0%A9%EB%B2%95)


　

## TextMesh Pro

- **...**
    - ...

- ***See Also***
    - ***https://docs.unity3d.com/2023.1/Documentation/Manual/com.unity.textmeshpro.html***
    - ***https://www.kodeco.com/22175776-introduction-to-textmesh-pro-in-unity***
    - ***https://m.blog.naver.com/cdw0424/221641217203***
