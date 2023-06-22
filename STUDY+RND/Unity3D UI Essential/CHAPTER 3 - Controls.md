## CHAPTER 3 - 컨트롤 배우기
    ● 새로운 UI 프레임워크의 기본 컨트롤
    ● 새로운 컨트롤을 사용한 예제
    ● 새로운 컨트롤 내비게이션 시스템

　

　

- **들어가며**
    - 기본 컨트롤들
        > - Text 컨트롤
        > - Image와 RawImage 컨트롤
        > - Button 컨트롤
        > - Toggle 컨트롤
        > - Scrollbar와 Slider 컨트롤
    - 이 정도만 이해하고 있어도 기본적인 작업은 모두 가능.
    - 이들을 조합해 새로운 컨트롤들을 만들 수 있다.


　

- **드로우 콜 최적화**
    - 성능을 향상을 위해 이미지를 스프라이트 한 장에 합쳐 사용.
    - [Sprite Packer](https://learnandcreate.tistory.com/131)를 사용하는 방법
    - [Sprite Atlas](https://skuld2000.tistory.com/28)를 사용하는 방법
    - 기존에는 Sprite Packer를 사용했으나 2019버전 이상에서는 레거시로 사라지고 Sprite Atlas가 사용된다.

　

　

## TEXT 컨트롤/컴포넌트
    ● UI 시스템에 텍스트를 표현하고자 할 때 사용.
    ● TextMeshPro를 사용할 수도 있다. 따로 설명하자.
https://docs.unity3d.com/kr/2019.4/Manual/com.unity.textmeshpro.html


　

- **컨트롤 추가**
    - 새로 컨트롤 추가하는 방법
        > - 메뉴에서: GameObject / UI / Text
        > - 하이어러키에서: Create / UI / Text
        > - 하이어러키에서: 마우스 우 클릭 / UI / Text
    - 오브젝트에 컴포넌트 추가하는 방법
        > - 메뉴에서: Component / UI / Text
        > - 인스펙터에서: Add Component / UI / Text


　

- **TEXT COMPONENT**
    - 컨트롤을 추가한 화면과 인스펙터
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/text-control.png)
    - **Text**
        > - 화면에 표시될 텍스트를 설정한다.
    - **Font**
        > - 사용할 폰트를 지정.
        > - 폰트 생성 방법은 따로 설명.
    - **Font Style**
        > - Normal
        > - Bold
        > - Italic
        > - Bold And Italic
    - **Font Size**
        > - 폰트 크기를 지정
    - **Line Spacing**
        > - 줄 간격 설정
    - **Rich Text**
        > - 리치 텍스트 지원 유무.
        > - 볼드: \<b\>...\</b\>
        > - 이탤릭: \<i\>...\</i\>
        > - 컬러: \<color=\#rrggbbaa\>...\</color\>
        > - 크기: \<size=50\>...\</size\>
    - **Alignment**
        > - 텍스트가 컨트롤 안에서 어떻게 정렬될지 결정한다.
        > - [왼쪽 / 가운데 / 오른쪽], [위 / 중앙 / 아래]
    - **Horizontal Overflow**
        > - 텍스트가 컨트롤 가로영역을 벗어날 때 처리방법.
        > - Wrap
        > - Overflow
    - **Vertical Overflow**
        > - 텍스트가 컨트롤 세로 영역을 벗어날 때 처리 방법.
        > - Truncate
        > - Overflow
    - **Best Fit**
        > - 폰트 크기를 조정해서 텍스트가 컨트롤 영역 안에 들어감.
        > - Min Size / Max Size 폰트 크기 범위 지정 가능.
    - **Color**
        > - 폰트 색상 지정
    - **Material**
        > - 텍스트를 렌더링 할 기본 재질을 설정.

- **간단한 FPS 컨트롤**
  - 스크립트 제어 부분은 스킵.

　

　

## INPUT FIELD 컨트롤/컴포넌트
    ● 텍스트 입력 컨트롤


　

- **컨트롤 추가**
    - / UI / Input Field 메뉴로 컨트롤 추가.
    - 빈 입력 필드
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_InputFieldExample.png)
    - 텍스트가 입력된 입력 필드
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_InputFieldExample2.png)


　

- **TEXT FIELD COMPONENT**

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_InputFieldInspector.png)    

    - **Interactable**
        > - 입력 필드가 상호작용 가능한지 여부.
        > - 언체크 되면 컨트롤이 비활성화 된다.
    - **Transition**
        > - 컨트롤 상태 별 전환 효과
        > - [이거보고 자세히 정리 하자](https://docs.unity3d.com/kr/2021.1/Manual/script-SelectableTransition.html)
    - **Navigation**
        > - UI 요소 내비게이션이 어떻게 제어될지 결정.
        > - [이거 보고 자세히 정리하자](https://docs.unity3d.com/kr/2021.1/Manual/script-SelectableNavigation.html)
    - **Text Component**
        > - 입력받은 텍스트를 표시할 Text 컨트롤
    - **Text**
        > - 초기 입력 텍스트
    - **Character Limit**
        > - 최대 입력 문자(유니코드) 수
    - **Content Type**
        > - **Standard:** 어떤 문자라도 입력될 수 있다.
        > - **Autocorrected:** 자동완성 지원 모드
        > - **Integer Number:** 숫자만 입력 가능 모드
        > - **Decimal Number:** 구두점 포함 숫자만 입력가능 모드
        > - **Alphanumeric:** 알파벳과 숫자만 입력 가능 모드
        > - **Name:** 문자만 입력 가능 모드. 첫 알파벳은 대문자.
        > - **E-mail address:** 이메일 형태의 문자만 입력 가능 모드
        > - **Password:** 패스워드 입력 모드
        > - **Pin:** 핀 넘버 입력 모드
        > - **Custom:** Line Type, Input Type, Keyboard Type, Character Validation 속성을 조합하여 입력 모드를 구성한다.
    - **Line Type**
        > - **Single Line:** 한 줄 입력 모드
        > - **Multi Line Submit:** Enter시 onEndEdit 이벤트 발생
        > - **Multi Line Newline:** Enter시 줄 바꿈
    - **Placeholder**
        > - 입력받기 전에 표시될 Text 컨트롤
    - **Caret Blink Rate**
        > - 캐릿 깜박임 속도
    - **Caret Width**
        > - 캐릿 두께
    - **Custom Caret Color**
        > - 캐릿 색상
    - **Selection Color**
        > - 텍스트 선택영역의 배경 색상
    - **Hide Mobile Input**
        > - 모바일 디바이스의 온스크린 키보드에 붙어있는 네이티브 입력창을 없앤다. 이 속성은 iOS 디바이스에서만 동작한다.

　

　

## 그림자와 기타 효과
    ● 일반적으로는 셰이더를 사용하면 된다. 근데 진입장벽 있음.
    ● 유니티는 실시간으로 버텍스 수정할 수 있는 방법도 제공.
    ● 이러한 효과는 IVertexModifier 인터페이스에 기반을 두고 있다.
    ● 이렇게 만들어진 효과 중 하나가 Shadow 컴포넌트이다.
    ● Outline 컴포넌트도 있음.


　

- **SHADOW COMPONENT**
    - Text와 Image 같은 그래픽 컴포넌트에 간단한 그림자를 추가한다.
    - 그래픽 컴포넌트와 같은 게임 오브젝트에 위치해야 한다.
    - 효과 적용 전
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/shadow1.png)
    - 효과 적용 후
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/shadow2.png)
    - Options
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/shadow3.png)
    - Effect Color
        > - 그림자 색상
    - Effect Distance
        > - 그림자가 떨어진 벡터 옵셋
    - Use Graphic Alpha
        > - 그래픽 컴포넌트 알파 값과의 혼합 유무.


　

- **OUTLINE COMPONENT**
    - Text와 Image 같은 그래픽 컴포넌트에 간단한 테두리를 추가한다.
    - 효과 적용 전
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/outline1.png)
    - 효과 적용 후
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/outline2.png)
    - Options
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/outline3.png)
    - Effect Color
        > - 테두리 색상
    - Effect Distance
        > - 테두리가 떨어진 벡터 옵셋
    - Use Graphic Alpha
        > - 그래픽 컴포넌트 알파 값과의 혼합 유무.

　

　

## IMAGE 컨트롤/컴포넌트
    ● Unity UI에서 텍스쳐를 그리는 가장 기본적인 방법.
    ● Image 컴포넌트를 제대로 활용하기 위해서는 2D Sprite Package 먼저.


　

- **2D SPRITE PACKAGE**
    - 별도 설치해야 하는 경우
    - ***"Menu / Window / Package Manager"*** 선택.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/package_manager.png)
    - 만약 곧바로 2D Sprite Package가 보이지 않으면 왼쪽 상단의 Packages 탭 아래의 [+] 버튼 옆에 있는 버튼을 클릭해서 All Packages를 선택하면 설치 가능한 모든 패키지가 나온다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/allpackages.png)
    - 그중에서 2D Sprite를 선택하고 Install 버튼을 클릭한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/2dsprite.png)
    - 이제 Sprite Editor를 사용할 수 있다.
    - 설명하면서 빈번히 Sprite Editor 등장할 거임.    


　

- **SPRITE 무엇?**
    - 이미지 리소스를 텍스쳐(Texture)라고 부른다.
    - 이 텍스쳐 중에서도 Image 컴포넌트나 스프라이트 렌더러에서 사용되는 리소스들을 스프라이트(Sprite)라고 한다.
    - 보통 유니티 프로젝트에 임포트 되는 텍스쳐들은 자동으로 Texture Type이 Default로 정해진다. Default는 주로 3D 모델 오브젝트의 텍스쳐로 사용되는 타입이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/texturetype.png)
    - UI에 사용하기 위해서는 Texture Type을 Sprite로 변경해야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/sprite2D.png)


　

- **IMAGE CONTROL / COMPONENT**
    - UI / Image 항목을 선택하여 Image 컨트롤 생성
    - Image 컴포넌트는 Sprite를 원본 이미지로 사용해야 한다.
    - Image 컴포넌트는 Raw Image 컴포넌트와 비슷하다.
    - 반면, Image 컴포넌트는 더 많은 디스플레이 옵션을 가진다.
    - 반면, Raw Image는 어떤 타입의 텍스쳐라도 사용 가능하다.
    - 웹에서 내려받은 이미지는 Raw Image를 써야겠지?
    - **Options**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/image-inspector.png)
    - **Source Image**
        > - 출력할 이미지 스프라이트
    - **Color**
        > - 이미지에 적용될 색상
        > - 버텍스 컬러로 지정되므로...
        > - 흰색으로 지정하면 원본 이미지 색상으로 출력.
        > - 원본 이미지의 검은색은 영향을 받지 않는다.
    - **Material**
        > - 이미지를 렌더링 할 때 사용될 재질
        > - 재질을 넣어서 흐리게 보이게 만든다거나 왜곡되어 보이게 하는 것처럼 특별한 효과를 넣고자 할 때 사용된다.
    - **Raycast Target**
        > - 레이캐스트 타겟으로 이미지를 사용할지 말지 지정
        > - 쉽게 말해 클릭 or 터치 대상으로 삼을지 말지.
    - **Preserve Aspect**
        > - Source Image의 원본 비율을 지켜서 그릴 것인지.
        > - 보통은 Image 컴포넌트가 부착된 게임 오브젝트의 너비와 높이에 따라서 그림의 비율이 변형되어서 화면에 그려지지만 Preserve Aspect를 체크하면 비율을 지킨 상태로 화면에 그려지게 할 수 있다.
        > - Image Type이 Simple 이거나 Filled 일 때만 사용됨.
    - **Set Native Size**
        > - 게임 오브젝트의 Width와 Height를 Source Image 해상도와 같게 만들어준다.
        > - Image Type이 Simple 이거나 Filled 일 때만 사용됨.
    - **Image Type**
        > - 이미지가 그려지는 방식을 결정.
        > - Source Image가 비어 있으면 안 보이니 참고하시고...
    - **Image Type : Simple**
        > - 원본 이미지 소스 그대로 출력.
    - **Image Type : Simple - Use Sprite Mesh**
        > - 그리는 영역을 지정할 때, 그냥 사각형 영역으로 그릴지 아니면 이미지의 알파 영역을 무시해서 오버드로우 안되게 최적화 할지.
        > - 구멍 숭숭 뚫린 큰 이미지 최적화 할 때 유용하다.
        > - 스프라이트의 Mesh Type이 "Tight" 여야 한다.
        > - Sprite Editor에서 Custom Outline 직접 조정 가능.
        > - *https://skuld2000.tistory.com/28*
        > - *https://mentum.tistory.com/293*
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/preserve.gif)
    - **Image Type : Sliced**
        > - 9 슬라이스 그리기 모드
        > - 9슬라이싱 하기 위해서는 프로젝트 뷰에서 적용할 스프라이트를 선택하고 인스펙터 뷰에서 **"Sprite Editor"** 버튼 클릭.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteeditor-button.png)
        > - 반복 부분을 나눠주고 Apply 버튼 누름.
        > - Border 값을 변경하는 것임.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/9slicing.gif)
        > - 이미지가 크기에 따라 늘어지지 않는다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/9slicing-result.png)
        > - **Fill Center**: 가운데 영역을 Color 색상으로 채울지 말지.
        > - **Pixels Per Unit Multiplier**: 유닛 당 픽셀 수 설정. Sprite의 Pixels Per Unit에 이 값이 곱해진다. (모서리) 해상도를 조절하는데 매우 유용하다.
    - **Image Type : Tiled**
        > - 이미지를 반복으로 그려주는 타입.
        > - 스프라이트에 Border 값을 주는 경우 패턴이 잘 연결될 수 있도록 주의가 필요하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/titled.gif)
        > - **Pixels Per Unit Multiplier**
        > - 　　● 유닛 당 픽셀 수 설정.
        > - 　　● Sprite의 Pixels Per Unit에 이 값이 곱해진다.
        > - 　　● 해상도, 스케일을 변경할 수 있다. (새 기능)
    - **Image Type : Filled**
        - 게이지 같은 연출을 표현할 때 주로 사용된다.
        - **Fill Method**
        - Radial 360
        - Radial 180
        - Radial 90
        - Vertical
        - Horizontal
        - **Fill Origin**
        - (게이지가) 차오르는 시작점
        - Fill Method가 Radial 360 일 때
            - Top, Bottom, Left, Right
        - Fill Method가 Radial 180 일 때
            - Top, Bottom, Left, Right
        - Fill Method가 Radial 90 일 때
            - Bottom Left
            - Bottom Right
            - Top Left
            - Top Right
        - Fill Method가 Vertical 일 때
            - Top, Bottom
        - Fill Method가 Horizontal 일 때
            - Left, Right
        - **Fill Amount**
        - 이미지를 어느 비율로 채울지 결정.
        - 0과 1 범위 내에서 조정한다.
        - **Clockwise**
        - 채워지는 방향이 시계방향인지 반대인지 설정.
        - Fill Method가 Radial 계열일 때만 작동

![horizontal.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/6cd71814552a031f560edaf99616c5cb/horizontal.gif)

![vertical.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/215f321469822bd6342c0f9d07d06088/vertical.gif)

![radial90.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/a2578b770ec37aebbff42d185b25c79c/radial90.gif)

![radial180.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/573851d043d9b818fc5c2baa62e9067f/radial180.gif)

![radial360.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/307e15a9181658511d76fbb61c081106/radial360.gif)

![titled.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/94f7eb6ab40eb0c2e4fd3f8fad8f41eb/titled.gif)

![9slicing-result.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/c4c7229fe8580ff4df6d1540e560b206/9slicing-result.png)

![9slicing.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/0674fa02243d1ea4d7409788db1134ca/9slicing.gif)

![spriteeditor-button.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/f027deba7e2e22e729433ad6f166b64d/spriteeditor-button.png)

![preserve.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/9d78dba43be6a28b5e26ae7950979343/preserve.gif)

![image-inspector.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/e341551d828faf524acd8a1186e231a3/image-inspector.png)

![sprite2D.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/a5fe8b0c2efafe3ddec5970947cb9b67/sprite2D.png)

![texturetype.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/308a37728ce5ec1026ef17d3b5e34863/texturetype.png)

![2dsprite.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/818c9b7593bf1bfa235b93ceded18525/2dsprite.png)

![allpackages.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/9554e7497f900ab2d8dd33649c388137/allpackages.png)

![package\_manager.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/6a7cc14cd80ef5dfa316f6837d0f22f8/package_manager.png)

　

## BUTTON 컨트롤/컴포넌트

> 상호작용을 구현하기 위해 가장 많이 쓰이는 컨트롤사용자의 클릭에 반응하고, 액션을 시작하거나 확인하는 데 사용.Button 컨트롤은 여러 컴포넌트를 하나로 묶어놓은 것에 가깝다.새로운 컨트롤을 만들거나 조합하는데 좋은 레퍼런스가 되겠다.

---

- **컨트롤 추가**
  - / UI / Button 메뉴로 컨트롤 추가.
  - 실제 버튼 컨트롤에 포함된 요소들
    - Image 컴포넌트
    - Button 컴포넌트
    - Text 컴포넌트(하위 오브젝트)
  - Text 컴포넌트는 버튼 텍스트를 출력하고
  - Button 컴포넌트는 **Selectable** 컴포넌트를 상속받는다.
  - Image 컴포넌트는 버튼 이미지를 출력한다.
  - Image 컴포넌트의 중요한 다른 목적은 Button(Selectable) 컴포넌트가 입력 이벤트를 처리하기 위한 레이캐스터로써 필요하다는 것이다. 꼭 Image 컴포넌트가 아니어도 된다. 현재 레이캐스트 시스템과 상호작용하는 컴포넌트이기만 하면 된다. (eg. Raycast Target)
- **SELECTABLE COMPONENT**
  - 버튼, 슬라이더 등 인터랙션 컴포넌트들은 Selectable을 상속받는다.
  - 실제로 Selectable 컴포넌트의 인스펙터 내용이 동일하다.
  - Selectable 컴포넌트는 이벤트에 대응해 시각적인 액션을 수행.
  - Selectable 컴포넌트가 다루는 이벤트
    - Hover(Highlighted)
    - Pressed
  - **Options**
    - **Transition**
      - 컨트롤의 상태에 따라 선택한 Graphic의...
      - Color Tint
        - 색조를 변경.
      - Sprite Swap
        - 스프라이트를 변경
      - Animation
        - 애니메이션을 변경
      - None
        - 아무것도 안 함.
    - **Navigation**
      - 키보드 방향키로 다른 컨트롤 선택하는 방법
      - 잠시 후 따로 자세히 설명한다.
    - **Visualize**
      - 네비게이션 흐름을 씬 뷰에 시각화한다.
- **이벤트에 대응하기**
  - 스킵
- **애니메이션 버튼 만들기 실습**
  - [UI 리소스팩은 여기](http://opengameart.org/content/ui-pack)또는[여기서 다운로드](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/9a3ec3e10c6214e9b913dac428cba11a/UIpack.zip)
  - 리소스 팩에서**"/UIpack/Spritesheet/"**폴더 이동
  - **PNG**파일과**XML**파일 유니티로 가져오기
  - 리소스 팩에서**/UIpack/Font/"**폴더 이동
  - **TTF**파일 유니티로 가져오기
  - 애셋스토어에서**XML Texture Atlas Slicer**설치하기
  - **PNG**스프라이트의 Sprite Mode를**Multiple**변경 후
  - **"Assets / Slice Sprite Using XML"**스프라이트 슬라이싱
  - 유니티 하이어러키에 버튼 UI 추가
  - **"blue_button01.png"**스프라이트를 버튼 Source Image에 할당.
  - **"kenvector\_future\_thin"**폰트를 버튼 텍스트 Font에 할당.
  - 버튼 텍스트를**"START GAME"**으로 변경
  - 버튼의**Transition**속성을**Animation**으로 설정.
  - 버튼의**Auto Generate Animation**버튼을 클릭해서 기본적인 애니메이션 컨트롤러를 생성.
  - 버튼 게임 오브젝트에**Animator**컴포넌트가 추가되었음.
  - 프로젝트 뷰에서 "Button" 애니메이터를 더블클릭하면**Animator 편집창**을 띄울 수 있다.
  - 하이어러키 뷰에서 버튼 오브젝트를 선택하고**"Windows / Animation / Animation"**항목을 선택하여 Animation 창을 연다. Clips 드랍다운을 열어보면 다섯 개의 클립을 찾을 수 있다.
  - **Highlighted**클립을 선택한 후**Record**버튼을 눌러 녹화 시작.
  - 하이어러키 뷰에서 버튼의 Image 컴포넌트 Source Image를**"yellow_button02.png"**로 변경
  - 이어서 Rect Transform 컴포넌트의**Scale X, Y**를 각각 1.1로 변경
  - Record 버튼을 다시 눌러 녹화 중지.
  - 애니메이션 클립의 속성에서**Loop Time**언체크.
  - 같은 방법으로 각각의 애니메이션 클립을 수정한다.
  - 버튼의 위치와 스케일 등의 값은 이전 상태에 기반을 두기 때문에 애니메이션 클립에서 명시적으로 변경하지 않는 한, 초기값으로 자동 리셋된다.
  ‌

![button-animation.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/577c97d0989b66289bb1bdef4946391d/button-animation.png)

![animatoredit.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/c05a7aa18a7e930457474167a1a07788/animatoredit.png)

![superawesomegame.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/de0a78bd6dd060ce7348825374434f8c/superawesomegame.png)

![selectable.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/a555681aecf7f41e29f4e5a2b8581075/selectable.png)

![button.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/6032634ce953c34f08919df1/4c9b3cb53f6ad8d8aa6862decce6cc00/button.png)

‌

‌

## TOGGLE 컨트롤

> 사용자가 옵션을 켜거나 끌 수 있도록 하는 체크박스.선택하거나 선택하지 않거나...

![UI\_ToggleExample.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/a999865eabb3c55b0f13b0739ea236d8/UI_ToggleExample.png)

---

- **컨트롤 추가 및 하이어러키**
  - / UI / Toggle 메뉴로 컨트롤 추가.
  - 토글 컨트롤에 포함된 요소들
    - Toggle 컴포넌트
    - 배경으로 사용할 Image 컴포넌트(하위 오브젝트)
    - 체크 마크로 사용할 Image 컴포넌트(하위 오브젝트)
    - 라벨 텍스트를 표현할 Text 컴포넌트
  - Toggle 컴포넌트는 Button 컴포넌트와 마찬가지로 **Selectable** 컴포넌트를 상속받는다.
  - 버튼과 같은 방식으로 이벤트에 대응해 시각적인 액션을 수행.
- **TOGGLE 컴포넌트 전용 옵션**
  - Is On
    - Toggle의 초기 상태를 정의한다.
  - Toggle Transition
    - 토글을 켜고 끌 때 그래픽이 어떻게 보일지 정의한다.
    - 걍 깜빡이거나, 페이드 인/아웃 할 수 있다.
  - Graphic
    - Toggle을 켜고 끌 때 나타났다 사라지는 이미지
    - 좀 더 정확히 말하자면 해당 이미지 그래픽의 Canvas Renderer 알파값을 트위닝 해서 나타나거나 사라지게 한다.
    - 체크 마크 연출의 확장 가능성을 보여준다.
  - Group
    - 컨트롤들을 그룹화 시켜서 하나만 체크될 수 있도록 한다.
- **TOGGLE GROUP**
  - 여러 토글을 하나의 그룹으로 묶는다.
  - 해당 그룹 안에서는 한 번에 하나의 아이템만 체크할 수 있다.
  - 만드는 방법
    - 빈 게임 오브젝트를 생성하고 Toggle Group 컴포넌트 추가.
    - 하위 오브젝트로 토글 컨트롤을 배치한다.
    - 토글의 **Group** 속성으로 상위 Toggle Group 오브젝트 지정.
    - 토글의 **Is On** 속성을 끕니다.
    - 토글을 여러 개 복제한 후 적당한 위치 조정.
    - 필요에 따라 한 개 토글만 Is On 속성을 켠다.
- **동적 이벤트 속성**
  - 컴포넌트들의 내부 스크립트를 알아야 제대로 이해 및 활용 가능.
  - 스킵 하려 했으나 어쨌든 유니티 에디터 기능이기에 설명함.
  - 닥치고, 버튼과 달리 토글은 Boolean 상태를 갖고 있으므로 Dynamic Parameter를 사용할 수 있다. 토글의 상태(true/false)를 동적으로 넘겨 이벤트 디스패치를 할 수 있다는 말이다.
  - Dynamic bool 카테고리의 SetActive 메소드를 호출하면 토글의 상태 값이 SetActive 메소드의 인자로 자동 전달된다.
  - Static Parameters 카테고리의 SetActive 메소드를 호출하면 토글의 상태 값은 무시되고 고정된 인자 값을 정의할 수 있다.
  - Static Parameters 메소드를 이용하는 다른 유용한 예제.

![staticparameters2.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/24596c5f9aeebad3f488d2d5bfe1864b/staticparameters2.png)

![staticparameters-3.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/2e91b3163716867e8d531b8d94e0da53/staticparameters-3.png)

![dynamicparameter-setactive.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/eea4cf92f59756b8d302a0da7053666f/dynamicparameter-setactive.png)

![dynamicparameter.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/92f8631698e373ebd7d5f638eb91b810/dynamicparameter.png)

![toggle-group.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/97c67349cc92877162d25a713aa2ef59/toggle-group.png)

![UI\_ToggleGroupExample.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/da13b0e1315b544550c8531e736f28eb/UI_ToggleGroupExample.png)

![toggle.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/17ea5f4193c3026ffdcef4ac4c9a96aa/toggle.png)

　

## SLIDER 컨트롤

> 마우스를 드래그하여 미리 정해진 범위상 숫자 값을 선택할 수 있다.게임 난이도 설정이나 이미지 에디터 밝기 설정 등에 사용된다.기본 UI 컴포넌트들을 조합해 복잡한 컨트롤을 구축한 대표적 사례.

![UI\_SliderExample.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/5f1730779a22dcd6841b28656279b434/UI_SliderExample.png)

---

- **컨트롤 추가 및 하이어러키**
  - / UI / Slider 메뉴로 컨트롤 추가.
  - **Slider**
    - Slider 컴포넌트가 바인딩 된 게임 오브젝트
    - 딱 봐도, Selectable 컴포넌트를 포함한다.
    - 전반적인 슬라이더 컨트롤 제어 기능.
  - **Background**
    - 전체 컨트롤에 대한 배경 이미지.
  - **Fill Area**
    - 슬라이더 채움 영역 이미지가 표현될 영역
  - **Fill**
    - 슬라이더 채움 영역 이미지
    - 슬라이더 Value 값에 따라 이곳 앵커의 Max.X 값을 변경하여 이미지를 늘이거나 줄임.
  - **Handle Slide Area**
    - 슬라이더 핸들 이미지가 돌아다닐 영역
  - **Handle**
    - 슬라이더 핸들 이미지
    - 슬라이더 Value 값에 따라 이곳 앵커의 Min.X, Max.X 값을 변경하여 이미지를 이동.
- **SLIDER 컴포넌트**
  - Selectable 컴포넌트 부분 설명은 패스
  - Fill Rect
    - 컨트롤의 채움 영역에 사용하는 그래픽.
  - Handle Rect
    - 컨트롤의 슬라이딩 “핸들” 부분에 사용하는 그래픽.
  - Direction
    - 핸들을 드래그할 때 슬라이더의 값이 증가하는 방향.
    - 속성을 변경하면 배치가 자동 변경된다.
    - Left To Right
    - Right To Left
    - Bottom To Top
    - Top To Bottom
  - Min/Max Value
    - 슬라이더가 움직이거나 가질 수 있는 최대 또는 최솟값.
  - Whole Number
    - 슬라이더 Value 값을 정수로 제한할지 여부.
    - 기본 값은 부동 소수점(실수).
  - Value
    - 슬라이더의 위치 값을 설정.
    - Min, Max 범위 내에서 설정해야 한다.
  - On Value Changed
    - 슬라이더 Value 값이 변경되었을 때 발생되는 이벤트

![slidercomponent.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/1b9f61ca39b79aa40d971552280c73d4/slidercomponent.png)

![slider.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/cd8caa9852128696162393f1020abf13/slider.png)

　

## SCROLLBAR 컨트롤

> 스크롤바 컨트롤을 통해 사용자가 한 번에 볼 수 없는 이미지나 다른 보기 화면을 스크롤 하여 볼 수 있다. 비슷한 슬라이더 컨트롤은 스크롤링이 아니라 수치 값을 선택하는 데 사용한다는 점에 주목해야 한다. 흔한 예로는 텍스트 편집기 측면에 있는 수직 스크롤바나 큰 이미지나 지도의 일부를 보기 위한 수직 및 수평 스크롤바 등이 있다.

![UI\_ScrollbarExample.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/096aaf2385cc5bc6513a54c531481ce8/UI_ScrollbarExample.png)

---

- **컨트롤 추가 및 하이어러키**
  - / UI / Scrollbar 메뉴로 컨트롤 추가.
  - Scrollbar
    - Scrollbar 컴포넌트가 바인딩 되어 있다.
    - 배경 Image 컴포넌트가 바인딩 되어 있다.
  - Sliding Area
    - 프로그레스 핸들이 돌아다닐 영역
  - Handle
    - 프로그레스 핸들 이미지
    - 프로그레스의 Value 값 Size 값에 따라 앵커의 Min.X, Max.X 값을 변경하여 이미지를 이동하고 늘이거나 줄임.
- **SCROLLBAR 컴포넌트**
  - Selectable 컴포넌트 부분 설명은 패스
  - Handle Rect
    - 컨트롤의 슬라이딩 “핸들” 부분에 사용하는 그래픽.
  - Direction
    - 핸들을 드래그할 때 스크롤바의 값이 증가하는 방향.
    - 속성을 변경하면 배치가 자동 변경된다.
    - Left To Right
    - Right To Left
    - Bottom To Top
    - Top To Bottom
  - Value
    - 프로그레스의 위치 값을 설정.
    - 슬라이더와 달리 0과 1 범위 사이에서만 설정 가능.
  - Size
    - 스크롤바 핸들의 상대적 크기로 범위는 0 ~ 1.
    - 보통 스크롤바와 연동된 컨텐츠 전체 크기 중 보여지는 영역의 상대적 크기가 이 값이 된다.
  - Number of Steps
    - 스크롤바가 허용하는 스크롤 포지션 단계의 개수.
    - 고정된 간격이나 영역 사이를 움직이고 싶을 때 사용.
    - 6으로 설정하면 [0, 0.2, 0.4, 0.6, 0.8, 1] 지점만 움직인다.
- **스크롤바 활용하기 실습**
  - 아래 그림과 같이 스크롤 되는 이미지 뷰어를 만들 거임.
  - 사실 유니티 Scroll View 컨트롤과 거의 유사하다.
  - Canvas 아래 **Image** 컨트롤을 추가, 이름을 **"Scroll Border"**로 변경.
  - "Scroll Border" 오브젝트는 **컨텐츠 배경 테두리**로 쓰일 거임.
  - Width: 400, Height: 200 변경하고 적당한 이미지 지정
  - "Scroll Border" 하위로 빈 오브젝트 추가
  - 이름을 **"Scroll Rect"**로 변경.
  - 여기에 **Mask** 컴포넌트를 추가.
  - Image 컴포넌트를 별도로 추가해야 클리핑 되는 거 알지?
  - 테두리인 "Scroll Border"가 보여야 하니, 살짝 크기 조정.
  - **"Scroll Rect"** 하위로 **Image** 컨트롤 추가
  - 소스 이미지에 **큰 이미지** 할당하고 **Set Native Size** 클릭
  - "Scroll Rect" 오브젝트로 돌아가서...
  - 여기에 **Scroll Rect** 컴포넌트 추가하고 **Content** 속성에 바로 전에 만든 하위 이미지 오브젝트를 할당.
  - "Scroll Border" 하위로 **Scrollbar** 컨트롤 추가.
  - 이름을 **"Horizontal Scrollbar"**로 변경.
  - 이 컨트롤은 **가로 스크롤바**로 사용될 거임.
  - 그러므로 **Direction** 속성을 **"Left To Right"**로 변경.
  - 위치와 크기는 컨텐츠 하단에 적절히 배치
  - "Scroll Border" 하위로 **Scrollbar** 컨트롤 추가.
  - 이름을 **"Vertical Scrollbar"**로 변경.
  - 이 컨트롤은 **세로 스크롤바**로 사용될 거임.
  - 그러므로 **Direction** 속성을 **"Bottom To Top"**으로 변경.
  - 위치와 크기는 컨텐츠 오른쪽에 적절히 배치
  - "Scroll Rect" 오브젝트의 **Scroll Rect** 컴포넌트에서...
  - **Horizontal Scrollbar** 속성에 **"Horizontal Scrollbar"** 오브젝트 할당.
  - **Vertical Scrollbar** 속성에 **"Vertical Scrollbar"** 오브젝트 할당.
  - 참 쉽죠?

![imageviewer.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/1c3ce18c0f576339f27acab2f32bdb5c/imageviewer.png)

![scrollbar-component.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/9e8251d29d1994a2d825356b747c3680/scrollbar-component.png)

![scrollbar.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/2d84efd9e3d5bf2a61086016d54f63a4/scrollbar.png)

　

## DROPDOWN 컨트롤

> 사용자가 리스트에서 옵션을 선택할 수 있다.컨트롤은 현재 선택된 옵션을 보여준다.클릭하면 리스트가 나타나 새로운 옵션을 선택할 수 있게 된다.이후 리스트는 닫히며, 컨트롤에는 새로 선택된 옵션이 표시된다.리스트는 사용자가 컨트롤을 클릭하거나 캔버스의 아무 곳이나 클릭하는 경우에도 닫힌다.

![UI\_DropdownExampleOpen.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/a8ea0c3f7b384de4874d2fd980549a0c/UI_DropdownExampleOpen.png)

![UI\_DropdownExample.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/579f7288369541219ecf0cb051a12c7f/UI_DropdownExample.png)

---

- **컨트롤 추가 및 하이어러키**
  - / UI / Dropdown 메뉴로 컨트롤 추가.
  - 옵션 리스트는 인스펙터에서 지정하거나 코드에서 넣을 수 있다.
  - 각 옵션에는 텍스트 문자열이나 이미지를 지정할 수 있다.
  - 리스트에서 아이템을 클릭하면 On Value Changed 이벤트 발생.
  - 선택한 옵션의 zero-base 인덱스가 이벤트 인자로 전달된다.
  - **Template**
    - 드롭다운 리스트 탬플릿
  - **Caption Text**
    - 선택된 옵션의 텍스트를 유지하는 Text 컴포넌트
  - **Caption Image**
    - 선택된 옵션의 이미지를 유지하는 Image 컴포넌트
  - **Item Text**
    - 아이템 텍스트를 유지하는 Text 컴포넌트
  - **Item Image**
    - 아이템 이미지를 유지하는 Image 컴포넌트
  - **Value**
    - 선택된 옵션의 zero-based 식별 번호.
  - **Options**
    - 사용 가능한 옵션의 리스트.
    - 각 옵션별로 텍스트 문자열과 이미지를 지정할 수 있다.
- **템플릿 시스템**
  - 클릭할 때 나타나는 드롭다운 리스트를 구성하기 위한 템플릿을 자식 게임 오브젝트로 가진다.
  - 템플릿은 기본적으로 비활성화 상태이다.
  - Dropdown 컴포넌트의 Template 속성에 이 템플릿이 지정되어 있다.
  - 템플릿은 한 개의 Toggle 컨트롤 아이템이 있어야 한다.
  - 클릭하여 실제 드랍다운 리스트가 생성되면 이 토글 아이템은 리스트 내에 여러 개 복제된다. 아이템의 부모는 자동으로 크기가 조절되어 모든 항목이 안에 꼭 맞게 들어간다.
  - 간단한 드롭다운 설정 템플릿.
  - 스크롤뷰를 지원하는 더 복잡한 드롭다운 템플릿.
- **텍스트와 이미지 지원 셋업**
  - 드롭다운의 옵션 당 한 개의 텍스트와 이미지가 지원된다.
  - 드랍다운에서 셋업 되어야 사용할 수 있다.
  - Caption Text는 현재 선택된 옵션 텍스트를 유지하는 컴포넌트이다.
  - Item Text는 각각의 옵션 텍스트를 유지하는 컴포넌트이다.
  - Caption Image와 Item Image 속성이 둘 다 셋업 된 경우 이미지 드랍다운이 지원된다. 기본적으로는 설정되어 있지 않다.
- **드랍다운 리스트 배치**
  - 리스트 배치는 템플릿 Rect Transform 앵커 및 피벗에 의해 결정된다.
  - 리스트는 아래로 펼쳐지므로 템플릿의 피벗은 Y가 1이어야 한다.
  - 드랍다운 할 캔버스 공간이 부족하면 드랍업 된다.

![dropup.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/766228788c162226c594472f2980fdbf/dropup.png)

![UI\_DropdownHierarchyScrolling.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/d985cdca7d0bffde4dd8f54417eaaafc/UI_DropdownHierarchyScrolling.png)

![UI\_DropdownHierarchySimple.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/e40c1f4bf48484589688e36459a7a1fd/UI_DropdownHierarchySimple.png)

![dropdown.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/afcbb1df992a53eb649270f2959d82b5/dropdown.png)

　

## 컨트롤 내비게이션

> 방향키를 통해 컨트롤에서 컨트롤로 포커스를 옮겨가는 기능.

![navigation.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/95f14da5a512acc44b534f0ac196f31b/navigation.png)

---

- **NAVIGATION 옵션**
  - UI 요소 내비게이션이 어떻게 제어될지 결정한다.
  - 내비게이션 기능은 Selectable 컨트롤에만 적용된다.
  - **None**
    - 키보드 내비게이션을 사용하지 않는다.
    - 클릭이나 탭으로부터도 포커스를 받지 않도록 한다.
  - **Horizontal**
    - 수평으로 이동한다.
  - **Vertical**
    - 수직으로 이동한다.
  - **Automatic**
    - 사용자가 입력한 방향(상하좌우)에서 가장 가까운 컨트롤로 포커스를 옮겨가도록 한다.
  - **Explicit**
    - 컨트롤의 이동 방향을 명시적으로 지정한다.
    - Selectable 컨트롤만 지정 가능하다.
- **VISUALIZE 버튼**
  - 에디터 씬 뷰에서 내비게이션 흐름을 시각적으로 표시한다.

![GUIVisualizeNavigation.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/c28a5e5a27dc0ca45bad39e65ec7a818/GUIVisualizeNavigation.png)

![explicit.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/3234383b69679b895d27cad66bc13bc0/explicit.png)

![UI\_SelectableNavigation.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/60360feb1a0a7378aad15a1c/c2565fa83eb86371578be68d1e9c321a/UI_SelectableNavigation.png)

　

## 셰이더에 대해...

> 모든 UI 컨트롤에는 Material 속성이 있다.이 속성에 셰이더를 재질 값으로 지정하면 셰이더 적용 가능이건 따로 세션을 만들어 설명하자.