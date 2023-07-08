# CHAPTER 7 - Addition
    ● Sprite Atlas
    ● TextMesh Pro

- ***See Also***
    - ***https://docs.unity3d.com/2023.2/Documentation/Manual/class-SpriteAtlas.html***
    - ***https://skuld2000.tistory.com/28***
    - ***https://hannom.tistory.com/202***
    - ***https://everyday-devup.tistory.com/62***
    - ***https://young-94.tistory.com/85***
    - [***https://maintaining.tistory.com/***](https://maintaining.tistory.com/entry/Unity-%EC%8A%A4%ED%94%84%EB%9D%BC%EC%9D%B4%ED%8A%B8-%EC%95%84%ED%8B%80%EB%9D%BC%EC%8A%A4Sprite-Atlas-%EC%82%AC%EC%9A%A9-%EB%B0%A9%EB%B2%95)
    - ***https://docs.unity3d.com/2023.1/Documentation/Manual/com.unity.textmeshpro.html***
    - ***https://www.kodeco.com/22175776-introduction-to-textmesh-pro-in-unity***
    - ***https://m.blog.naver.com/cdw0424/221641217203***


　

## Sprite Atlas
    ● 관련 Project Setting 살펴보기
    ● Sprite Atlas 생성하기
    ● Sprite Atlas 속성 살펴보기
    ● Tight Packing 자세히 살펴보기
    ● 스크립트로 스프라이트 아틀라스 제어 및 사용하기


　

- **Overview**
    - **아틀라스(Atlas)**란 여러 개의 **스프라이트(Sprite)**를 한 장의 큰 텍스쳐에 모아놓은 것.
    - 렌더링 할 때 텍스쳐 별로 한 번의 **드로우콜**이 발생하게 된다.
    - 드로우 콜은 렌더링 성능에 영향을 미치는 비싼 작업.
    - 게임 내 n개의 UI 요소가 각기 다른 텍스쳐 스프라이트를 사용한다면 n번의 드로우콜이 발생.
    - 이들 각각의 텍스쳐들을 한장의 텍스쳐에 모아놓고 UI 요소들이 사용한다면 **드로우콜을 1회**로 줄일 수 있다.
    - 유니티에서는 예전부터 [*Sprite Packer*](https://learnandcreate.tistory.com/131) 라는 툴을 통해 아틀라스를 제작하고 사용할 수 있었다.
    - 하지만 2019 이상부터 레거시라는 꼬리표가 달리고 [***Sprite Atlas***](https://skuld2000.tistory.com/28)가 사용되더니 2020 이상부터는 ***Sprite Atlas***만 사용 가능하다.


　

- **Settings**
    - **메뉴 > Edit > Project Setting** 창을 열고 **Sprite Packer** 항목을 확인
    - **Unity 2019.2.10** 버전을 기준으로 아래의 화면이 보인다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-settings.png)
    - **Unity 2022.3.4** 버전을 기준으로 아래의 화면이 보인다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-settings2.png)
    - **Enabled For Builds(Legacy Sprite Packer)**
        > - 기존 스프라이트 패커를 사용한다.
        > - 빌드 시에만 아틀라스를 생성, 로드 한다.
        > - 에디터의 Play 모드에서 실행하면 아틀라스가 아닌 각각의 스프라이트를 사용한다.
    - **Always Enabled(Legacy Sprite Packer)**
        > - 기존 스프라이트 패커를 사용하여 아틀라스를 생성한다.
        > - 에디터의 Play 모드에서 실행해도 아틀라스를 생성, 로드 한다.
        > - 씬 뷰의 일반 에디트 모드에서는 아틀라스를 사용하지 않는다.
    - **Enabled For Builds**
        > - 새로운 스프라이트 아틀라스를 사용한다.
        > - 빌드 시에만 아틀라스를 생성, 로드 한다.
        > - 에디터의 Play 모드에서 실행하면 아틀라스가 아닌 각각의 스프라이트를 사용한다.
    - **Always Enabled**
        > - 새로운 스프라이트 아틀라스를 사용한다.
        > - 에디터의 Play 모드에서 실행해도 아틀라스를 생성, 로드 한다.
        > - 씬 뷰의 일반 에디트 모드에서는 아틀라스를 사용하지 않는다.
    - **Sprite Atlas V2**
        > - https://docs.unity3d.com/2022.1/Documentation/Manual/SpriteAtlasV2.html
        > - https://forum.unity.com/threads/sprite-atlas-v2-in-unity-2022-1.1327704/


　

- **Sprite Atlas 생성하기**
    - 기존 스프라이트 팩커의 경우 각각의 스프라이트에 태그를 입력하면 이 태그를 기준으로 팩커가 스프라이트를 팩킹하는 방식이었으나 
    - 스프라이트 아틀라스는 그와 달리 아틀라스 파일을 생성한 후 여기에 팩킹할 스프라이트 들을 직접 추가하는 방식이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create.png)
        > 
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create2.png)
    - 적당한 위치에 빈 스프라이트 아틀라스를 Create 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create3.png)


　

 - **Sprite Atlas 속성**
    - Inspector Window
        > ![](spriteatlas-property.png)
    - **Type**
        > - Type에는 Master와 Variant 2가지가 존재합니다.
        > - Master Type은 단말기 사양에 따라 Atlas를 변형하지 않고 묶은 Sprite Atlas를 사용하는 것입니다.
        > - Variant Type은 Master Type을 기준 값으로, 단말기 사양에 따라 Atlas를 변형하여 단말기에 따른 최적화를 하는 것입니다. 
        > - 즉, Sprite Atlas의 Size를 조절하여, 저사양 단말에서 메모리를 적게 사용할 수 있도록 합니다.
        >
        > ![](spriteatlas-property2.png)
    - **Including in Build**
        > - 옵션을 켠 경우 빌드 시에 Sprite Atlas를 포함하며, 빌드가 실행될 때 자동으로 Sprite Atlas가 메모리에 로드 됩니다.
        > - 옵션을 끈 경우 빌드시에 Sprite Atlas는 Resources 폴더에 있다면 포함되지만, 에셋번들인 경우 포함되지 않습니다. 사용하기 위해서는 Sprite Atlas를 메모리에 코드를 통해 로드한 후에 사용해야 합니다.
    - **Packing - Allow Rotation**
        > - Sprite Atlas를 패킹할 때 스프라이트가 회전할 수 있도록 허용하는 것으로, Atlas의 공간을 효과적으로 사용할 수 있지만, UI에서 회전한 오브젝트를 사용한 경우 예기치 않은 회전된 이미지가 출력될 수 있습니다. (UI에서는 사용 자제)
    - **Tight Packing**
        > - 기본 직사각형의 패킷 대신, 스프라이트의 아웃라인에 따라 패킹하는 것으로 Atals의 공간을 효과적으로 사용할 수 있지만, 아웃라인이 명확하지 않은 이미지에 대해서는 이미지간의 침범이 발생할 수 있습니다.
        > - 편잡할 이미지 선택 후 Window > 2D > Sprite Editor
        > ![](spriteatlas-property3.png)
        > - Custome Outline 선택 시, 스프라이트의 Outline 수정 가능
        > ![](spriteatlas-property4.png)
        > - 아웃 라인 수정
        > ![](spriteatlas-property5.png)
        > - 수정한 Outline이 Sprite Atlas에 적용되는 것을 확인
        > ![](spriteatlas-property6.png)
    - **Padding**
        > - Sprite Atlas 사이에 픽셀 수를 정의하는 것으로 인접한 이미지 사이의 겹침을 방지합니다.
    - **Objects For Packing**
        > - Sprite Atlas를 묶을 이미지를 넣는 곳입니다. 단 Sprite Atlas는 Sprite로 설정된 이미지만 가능합니다.


　

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
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking7.png)
    - 그리고 해당 UI 가 출력되는 컨트롤에 가서 Use Sprite Mesh 를 체크해 주면 끝.
    - 전체 사각형으로 가져올 떄 침범했던 공간을 이렇게 폴리곤 단위로 잘라서 알파 부분을 피해 그려주기 때문에 더이상 영역 침범 문제가 발생하지 않는다.
    - 단, UI 의 Use Sprite Mesh 체크박스는 Image Type 이 Simple 일 때에만 나오므로 Splite 나 Fill 등의 모드에서는 사용할 수 없다는 점을 유의할 것.


　

- **스크립트로 아틀라스 사용하기**
    - Resource 폴더에 SpriteAtlas 준비
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-script2.png)
    - 오브젝트 생성
        > - 이미지랑 Sprite를 관리할 SpriteManager 빈 오브젝트와 스크립트를 생성한다.
        > - 물론 SpriteManager 오브젝트 없이 스크립트를 Image에 넣어서 사용해도 된다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-script.png)
    - 코드 작성
        ```
        public class SpriteManager : MonoBehaviour
        {
            public SpriteAtlas spriteAtlas; 

            public Image img;

            void Start()
            {
                // public으로 선언 시, 생략하고 드래그앤드롭으로 가능
                spriteAtlas = Resources.Load<SpriteAtlas>("SpriteAtlas"); 
            }

            void Update()
            {
                if (Input.GetMouseButtonDown(0)) 
                    img.sprite = SpriteReturn("sprite0"); // 좌클릭
                if (Input.GetMouseButtonDown(1)) 
                    img.sprite = SpriteReturn("sprite1"); // 우클릭
                if (Input.GetMouseButtonDown(2)) 
                    img.sprite = SpriteReturn("sprite2"); // 휠클릭
            }

            public Sprite SpriteReturn(string spriteName)
            {
                return spriteAtlas.GetSprite(spriteName);
            }
        }
        ```
    - 실행 결과
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-script.gif)


　




　

　

## TextMesh Pro

- **...**
    - ...

