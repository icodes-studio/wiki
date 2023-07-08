# CHAPTER 7 - Addition
    ● Sprite Atlas
    ● TextMesh Pro


　

## Sprite Atlas - 2019
    ● Unity 2019.2.5f1 버전 기준으로 설명
    ● Sprite Atlas 생성하기
    ● Tight Packing
*https://skuld2000.tistory.com/28*

　

- **Overview**
    - 유니티에서 아틀라스(Atlas) 는 여러 개의 스프라이트(Sprite)를 한 장의 큰 텍스쳐에 모아놓은 것이라고 볼 수 있다.
    - 게임에는 UI와 배경, 캐릭터, 이펙트 등등에 수많은 텍스쳐 들이 사용되는데 각 텍스쳐 별로 렌더링 할 때마다 한번의 드로우콜이 발생하게 된다.
    - 게임 내에 UI 요소들 별로 별도의 텍스쳐로 나뉘어져 있다면 총 20개의 UI 요소가 있다고 가정했을 때 20번의 드로우콜이 발생하게 된다.
    - 그런데 이 20개의 각각의 텍스쳐들을 한장의 텍스쳐에 모아놓고 UV 좌표를 조절해 UI 요소들이 사용한다면 드로우콜을 1회로 줄일 수 있다.
    - 게임의 퍼포먼스에 드로우콜이 얼마나 큰 영향을 미치는지 감안한다면 아틀라스의 사용은 선택이 아니라 필수이다.
    - 유니티에서는 예전부터 [*Sprite Packer*](https://learnandcreate.tistory.com/131) 라는 툴을 통해 아틀라스를 제작하고 사용할 수 있었다.
    - 하지만 2019 이상부터 레거시라는 꼬리표가 달리고 [***Sprite Atlas***](https://skuld2000.tistory.com/28)가 사용된다.
    - 2020 이상부터는 Sprite Atlas만 사용 가능하다.


　

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
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create.png)
        > 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create2.png)
    - 적당한 위치에 빈 스프라이트 아틀라스를 Create 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create3.png)


　

- **Sprite Atlas Packing**
    - Object for Packing 칸에 있는 + 버튼을 클릭해서 원하는 스프라이트 또는 폴더를 선택한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlaspacking.png)
    - Asset 폴더 내의 모든 스프라이트와 해당 스프라이트 들이 들어있는 폴더들의 목록이 뜬다.
    - 여기에서 폴더 또는 스프라이트 들을 하나씩 선택해 추가해 줘야 한다.


　

- **스프라이트들을 한번에 등록하는 방법**
    - 아틀라스의 Inspector 뷰에서 우측 상단의 좌물쇠 버튼을 클릭
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlaspacking2.png)
    - 이후 Project 뷰에서 다른 오브젝트를 선택해도 Inspector 뷰에는 계속 아틀라스만 보인다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlaspacking3.png)
    - 이렇게 해놓고 Project 뷰에서 드래그를 하거나 Ctrl 키를 누른채로 선택을 해서 원하는 복수의 스프라이트 들을 선택한 후 마우스로 잡아서 아틀라스 인스펙터 뷰로 드래그 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlaspacking4.png)
    - 인스펙터 뷰의 Objects for Packing 타이틀이 있는 라인에 끌고 온 스프라이트 들을 놓아주면 아래 리스트에 한번에 주르륵 추가가 된다.
    - 단, 이 때 타이틀이 아닌 아래 슬롯 위치에서 마우스를 떼면 그중에 한개만 해당 슬롯에 들어가 버리므로 꼭 타이틀 라인에 놓아주어야 한다.
    - 아무튼 이렇게 원하는 스프라이트 들을 다 등록했다면 아틀라스 인스펙터 뷰 좌하단의 Pack Preview 버튼을 눌러준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlaspacking5.png)
    - 팩킹하는 프로그래스 창이 뜨고 잠시 기다리면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlaspacking6.png)
    - 이처럼 등록한 스프라이트들을 아틀라스로 묶어준다.
    - 만약 설정된 아틀라스 사이즈보다 더 많은 스프라이트가 추가 되었다면 스크린샷의 팝업 과 같이 하나의 아틀라스 파일 안에 다수의 페이지 형태로 나뉘어서 생성된다.
    - 이렇게 페이지로 나뉜 아틀라스는 비록 하나의 파일에서 관리하지만 엄연히 다른 아틀라스이므로 별도의 드로우콜이 발생되는 점을 유의하자.


　

- **Tight Packing 설정**
    - 다시 스프라이트 아틀라스를 클릭한 후 Inspector 창을 보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking.png)
    - 몇가지 선택 옵션이 있는데 가장 주의할 점은 저 Tight Packing 이다.
    - Tight Packing 은 말 그대로 아주 촘촘하게 스프라이트들을 배치해 주는 기능이다.
    - 해당 옵션을 끈 상태로 팩킹을 하면 자신의 스프라이트 사이즈 만큼의 공간을 확보한 상태로 아틀라스가 만들어진다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking2.png)
    - 만약 이 옵션을 사용하여 팩킹을 하게 되면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking3.png)
    - Allow Roatation 옵션이 체크 되어 있어 최적의 배치를 위해 이미지가 회전된 상태이다.
    - 중요한 것은 그게 아니라 자세히 보면 저 스프라이트의 사각 영역 내에 다른 텍스쳐들이 배치 된 것을 알 수 있다.
    - 즉, Tight Packing 은 스프라이트의 알파 처리 되어 있는 부분을 체크하여 이 공간도 빈 공간으로 인식, 더 촘촘하게 이미지를 배치하는 기능이다.
    - 문제는 이렇게 아틀라스를 배치 했으면 실제 사용할 때도 알아서 처리해주면 좋을텐데 그렇지가 못하다는 점이다.
    - 이렇게 타이트하게 겹친 스프라이트를 실제 사용해보면 알파 영역에 끼어든 텍스쳐들까지 함께 가져와서 출력시켜 버린다.
    - 이를 막기 위해 추가 작업이 필요하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking4.png)
    - 유니티의 Window -> 2D -> Sprite Editor 를 실행해 보자.
    - 만약 이 Sprite Editor 가 없다면 Package Magnager 에서 2D Sprite 를 Install 해주어야 한다.
    - 그리고 문제가 발생하는 해당 Sprite (Atlas 가 아니다) 를 클릭하면 Sprite Editor 에 그 Sprite 가 뜬다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking5.png)
    - 기본값이 SpriteEditor 로 되어 있는 콤보박스를 클릭해서 Custom Outline 으로 바꿔준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking6.png)
    - 그리고 Generate 버튼을 눌러주면 실제 출력될 공간을 기준으로 폴리곤을 생성해 준다.
    - 이제 Apply 를 눌러서 저장해 준다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ightpacking7.png)
    - 그리고 해당 UI 가 출력되는 컨트롤에 가서 Use Sprite Mesh 를 체크해 주면 끝.
    - 전체 사각형으로 가져올 떄 침범했던 공간을 이렇게 폴리곤 단위로 잘라서 알파 부분을 피해 그려주기 때문에 더이상 영역 침범 문제가 발생하지 않는다.
    - 단, UI 의 Use Sprite Mesh 체크박스는 Image Type 이 Simple 일 때에만 나오므로 Splite 나 Fill 등의 모드에서는 사용할 수 없다는 점을 유의할 것.


　

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
