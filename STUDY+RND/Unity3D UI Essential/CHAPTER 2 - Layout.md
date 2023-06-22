## CHAPTER 2 - 레이아웃 만들기
    ● 새로운 Rect Transform
    ● Unity UI 캔버스
    ● 레이아웃과 그룹화 시스템
    ● Unity Event와 새로운 EventSystem

　

　

- **RECT TRANSFORM**
    - 본디 스프라이트 시스템(에디터)에서 시작됨.
    - Unity UI를 위한 Rect Transform 컴포넌트로 발전됨.


　

- **RECT TOOL**
    - 씬 에디터에서 바로 UI 요소의 크기를 조절하는 툴.
    - 씬 에디터에서 바로 Rect Transform을 수정할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/rect_tool.png)
    - 각 꼭짓점마다 하나씩 네 개의 컨트롤 포인트가 나타나며, 이 포인트를 조작하여 피벗 포인트를 기준으로 UI의 크기를 조정.
    - \<Shift\> 버튼을 누른 채로 가장자리 컨트롤 포인트를 움직이면 종횡비를 그대로 유지하면서 크기 조정 가능.
    - 꼭짓점 바깥 부근을 조작하여 회전 가능.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/recttool-scene.png)

　

- **피벗 모드와 공간 모드**
    - 버튼을 누르면 모드가 토글 된다.
    - 평소 UI를 조작할 때는 Pivot 과 Local 을 설정하면 좋다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/GUI_Pivot_Local_Buttons.png)
    - Center
        > - 선택 영역의 중앙이 피벗 포인트 역할을 한다.
        > - Pivot 값 기준으로 회전 또는 스케일 편집되는 것이 아니라 강제로 중앙을 기준으로 회전 또는 스케일 편집이 된다.
        > - 중앙 위치를 마우스로 끌면 Rect 전체가 화면에서 움직인다.
    - Pivot
        > - 피벗 포인트에서 마우스를 끌면 피벗 포인트 위치 조정.
        > - 피벗 포인트 기준으로 회전이나 스케일 편집이 된다.
    - Global
        > - Rect가 회전되어 있더라도 선택 영역은 같이 회전하지 않고 오브젝트가 회전한 공간 전체가 선택 영역이 된다.
    - Local
        > - 선택 영역은 항상 오브젝트 크기에 딱 맞게 정의된다. 오브젝트가 회전되었다면 선택 영역도 회전된다.


　

- **RECT TRANSFORM 컴포넌트**
    - Unity UI 전용 Transform 컴포넌트
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/rect_transform.png)
    - 컴포넌트에는 Width, Height, Anchors, Pivot, 등등의 속성이 있다.
        > - Width : UI의 넓이
        > - Height : UI의 높이
        > - 등등등...
        > - 이들 위치와 크기 필드의 종류는 앵커 값에 따라 달라진다.
        > - Rotation, Scale 필드는 기존 Transform 컴포넌트와 같은 값 사용.
    - **Pos X, Pos Y, Pos Z**
        > - 고정 크기 모드인 경우 활성화 된다.
        > - Rect Transform Pivot 포인트의 X, Y, Z 위치.
    - **Width, Height**
        > - 고정 크기 모드인 경우 활성화된다.
        > - Rect Transform의 너비와 높이.
    - **Left, Top, Right, Bottom**
        > - 가변 크기 모드인 경우 활성화된다.
        > - 상위 하이어러키 Rect Transform의 모서리 기준으로 영역 포인트의 오프셋 값을 의미한다.
    - **Blueprint mode**
        > - 회전에 상관없이 선택영역이 고정된 상태로 크기 조절 가능
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/blueprintmode.png)
    - **Raw edit mode**
        > - 앵커 또는 피벗 필드의 값을 변경하면 사각형이 포지션을 유지하도록 하기 위해 일반적으로 포지션 값이 자동조정 된다.
        > - 이를 원하지 않는다면 인스펙터에 있는 **R 버튼**을 클릭하여 Raw edit mode를 사용할 수 있다.
    - Raw edit mode **OFF** - Pos X 값 보정 됨
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/raweditmode-off.png)
    - Raw edit mode **ON** - Pos X 값 보정 안 되고 위치 이동.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/raweditmode-on.png)
    - **Anchors**
        > - Rect Transform의 레이아웃을 제어합니다.
        > - ***"Chapter 4. 앵커를 찾아서"*** 에서 좀 더 자세히...
    - **Anchor Presets**
        > - Rect Transform의 앵커 포인트를 변경하는 시각적인 방법.
        > - ***"Chapter 4. 앵커를 찾아서"*** 에서 좀 더 자세히...
    - **Pivot**
        > - UI의 중심을 나타낸다.
        > - 피벗을 기준으로 UI의 위치, 크기, 회전이 변경된다.
        > - x=0 : 오브젝트의 맨 좌측, x=1 : 오브젝트의 맨 우측.
        > - y=0 : 오브젝트의 최하단, y=1 : 오브젝트의 최상단.
        > - **피벗이 (0.5, 0.5)일 경우 스케일 & 회전**
        > - ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/centerpivot.gif)
        > - **피벗이 (0, 0.5)일 경우 스케일 & 회전**
        > - ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/leftpivot.gif)

　

　

## CANVAS
    ● UI를 그리는 일종의 그림판 같은 역할을 한다.
    ● 모든 UI 요소는 Canvas 안에 위치해야 한다.
    ● 그려지는 순서는 하이어러키 순서와 동일씬이 2D인지 3D 인지에 상관없이 UI를 배치할 수 있다.
    ● 각 UI를 3D 공간에서 서로 나누어 배치할 수도 있다.
*https://docs.unity3d.com/kr/2021.1/Manual/UICanvas.html*

　

- **CANVAS - RENDER MODE**
    - ***"Chapter 5. 화면 공간, 월드 공간, 카메라"*** 에서 좀 더 자세히...
    - **Screen Space - Overlay**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CanvasOverlay.png)
        > - 카메라 독립적으로 UI를 최상위에 오버레이 하는 방식.
        > - 해상도 변경 시 스크린에 일치하도록 자동으로 크기 변경됨.
        > - ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-overlay.png)
        > - Pixel Perfect
        > > - UI 엘리먼트에 대해 [***픽셀 퍼펙트***](https://docs.unity3d.com/ScriptReference/Canvas-pixelPerfect.html)렌더링을 수행.
        > > - ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/pixelperfect.gif)
        > > - 퍼포먼스 부분에서 손해를 보는 부분이 있다.
        > - Sort Order
        > > - 여러 개 Overlay 캔버스가 있는 경우, 그리는 순서
        > > - 낮은 순서의 캔버스는 아래에 그려진다.
    - **Screen Space - Camera**
        > - 공식문서에 있는 아래 그림은 설명하기 좀 애매해.
        > - 캔버스가 그려질 카메라를 선택하여 UI를 렌더링 한다.
        > - 게임 오브젝트를 UI 앞이나 뒤에 배치할 수 있다.
        > - 3D 원근법으로 UI를 그릴 때 유리하다.
        > - 해상도 변경 또는 카메라의 frustum을 변경한 경우, 캔버스도 자동으로 일치하도록 크기 변경됨.
        > - Render Camera
        > - 캔버스가 그려질 카메라.
        > - 지정하지 않으면 Overlay 모드처럼 동작.
        > - Plane Distance
        > - 캔버스가 카메라로부터 떨어진 거리.
        > - Sorting Layer
        > - 캔버스가 다른 캔버스 또는 스프라이트 렌더링 컴포넌트와 함께 씬에 사용되는 경우(eg. Sprite Renderer), 캔버스가 어떤 스프라이트 소팅 레이어에 렌더링 될 것인지 설정.
        > - Order in Layer
        > - 선택된 소팅 레이어에서 캔버스가 그려지는 순서.
        > - 낮은 순서의 캔버스는 아래에 그려진다.
    - **World Space**
        > - 공식문서에 있는 아래 그림은 설명하기 좀 애매해.
        > - 캔버스가 씬에서 오브젝트처럼 동작한다.
        > - UI 요소는 오브젝트 배치에 따라 앞면 혹은 뒷면에 그려짐.
        > - 3D 월드에 속하는 인터페이스 UI의 일부로써 유용하다.
        > - AKA, ***"Diegetic Interface"***
        > - Event Camera
        > - UI 이벤트를 처리하는 데 사용할 카메라
        > - 즉, EventSystem이 어떤 카메라를 사용할지 결정.
        > - 지정하지 않으면 Main Camera가 디폴트로 사용.

![canvas-worldspace.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/78dc3ea9434e395440cc539c1ab77758/canvas-worldspace.png)

![CanvasWorldSpace.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/4c06b9f252ff0d9f7bbb5ff5f1a0fa99/CanvasWorldSpace.png)

![canvas-camera.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/58ec7a3a75d37eedf7aeab6b4118cf60/canvas-camera.png)

![CanvasCamera.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/5720a40bee89b9c3e09cb9dbc35d1a26/CanvasCamera.png)

![%ED%8C%8C%EC%9D%BC\_000.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/8145f7ecb7565830f8483af5a36e91a1/%ED%8C%8C%EC%9D%BC_000.gif)

![canvas-overlay.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/0c6ec86e5023dc1a7ed4277bfab0503a/canvas-overlay.png)

![CanvasOverlay.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/6cbae767662208b2aa8fc658235c0ab1/CanvasOverlay.png)

　

- **CANVAS SCALER**
  - UI 요소의 전체적인 **스케일과 픽셀 밀도**를 제어하는 데 사용.
  - 글꼴 크기와 이미지 경계 등 캔버스 아래의 모든 요소에 영향 미침.

　

- **CANVAS SCALER - UI SCALE MODE**
  - 캔버스에서 UI 요소가 스케일 되는 방법을 결정한다.
  - **Constant Pixel Size**
    - 화면 크기에 관계없이 동일한 픽셀 크기로 유지된다.
    - **Options**
    - **Scale Factor**
      - 모든 UI 요소를 이 배율로 스케일 한다.
      - 화면 중앙을 중심으로 스케일 됨.
    - **Reference Pixels Per Unit**
      - 스프라이트에 이 ‘Pixels Per Unit’ 설정값이 적용된 경우 스프라이트 1픽셀이 UI 유닛 하나에 해당.
      - Set Native Size 눌러보면 느낌 팍 옴.
      - <Sprite's> / <Canvas Scaler's> = Pixels Per Unit
      - 뭐, 요런 느낌이랄까...
  - **Scale With Screen Size**
    - 해상도에 따라 UI 요소가 작아지거나 커진다.
    - **Options**
    - **Reference Resolution**
      - UI 레이아웃에 적합한 해상도를 지정.
      - UI가 커지고 작아질 기준 해상도
      - 이 해상도 기준으로 아트웍 리소스 작업 추천.
    - **Screen Match Mode**
      - 해상도의 종횡비가 레퍼런스 해상도에 맞지 않는 경우 캔버스 영역을 스케일 하는 데 사용.
      - **Match Width or Height**
        - 캔버스 영역의 너비 또는 높이 또는 그 사이 어딘가를 기준으로 캔버스를 스케일.
        - 캔버스가 레퍼런스보다 커지면 레터박스.
        - 캔버스가 레퍼런스보다 작아지면 잘림.
        - **Match**
          기준점 설정 (너비, 높이 or 그 사이)
      - **Expand**
        - 캔버스 크기가 레퍼런스보다 더 작아지지 않도록 캔버스를 수평 또는 수직 확장.
        - 레터박스는 생겨도 잘리진 않는다.
      - **Shrink**
        - 캔버스 크기가 레퍼런스보다 커지지 않도록 캔버스를 수평 또는 수직으로 자른다.
        - 잘리긴 해도 레터박스는 생기지 않는다.
    - **Reference Pixels Per Unit**
      - 스프라이트에 이 ‘Pixels Per Unit’ 설정값이 적용된 경우 스프라이트 1픽셀이 UI 유닛 하나에 해당.
  - **Constant Physical Size**
    - 화면 크기에 관계없이 UI가 동일한 물리적인 크기로 유지.
    - 포지션과 크기가 포인트 등의 물리적인 단위로 지정된다.
    - 그러려면 기기의 화면 DPI가 정확하게 보고되어야 한다.
    - **Physical Unit**
      - 포지션 및 크기를 지정하는 물리적 단위.
      - [_**참고#1 **_](https://spoqa.github.io/2012/07/06/pixel-and-point.html "‌"), [_**참고#2**_](https://chpofo.tistory.com/30 "‌")
        - Centimeters
        - Millimeters
        - Inches
        - Points
        - Picas
    - **Fallback Screen DPI**
      - 화면 DPI를 알 수 없는 경우 가정되는 DPI ???
    - **Default Sprite DPI**
      - ‘Pixels Per Unit’ 설정이 ‘Reference Pixels Per Unit’ 설정과 일치하는 스프라이트에 사용할 DPI
    - **Reference Pixels Per Unit**
      - 스프라이트에 이 ‘Pixels Per Unit’ 설정값이 적용된 경우 DPI는 ‘Default Sprite DPI’ 설정과 일치.
  - **World**
    - 캔버스가 World Space로 설정된 경우의 UI 스케일 모드.
    - **Dynamic Pixels Per Unit**
      - UI에서 동적으로 생성되는 비트맵(예: 텍스트)에 사용할 유닛당 픽셀의 양.
      - 변경하면서 Text UI 크기와 선명도 보면 느낌 팍 옴.
    - **Reference Pixels Per Unit**
      - 스프라이트에 이 ‘Pixels Per Unit’ 설정이 있는 경우 스프라이트의 픽셀 하나가 월드의 유닛 하나에 해당합니다. ’Reference Pixels Per Unit’을 1로 설정하면 스프라이트의 ‘Pixels Per Unit’ 설정이 그대로 사용된다.
      - Set Native Size 눌러보면 느낌 팍 옴.
      - <Sprite's> / <Canvas Scaler's> = Pixels Per Unit
      - 뭐, 요런 느낌이랄까...

![canvasscaler-world.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/4b0fa87e0184d531bb121fea7d986afb/canvasscaler-world.png)

![constantphysicalsize.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/2874df818cca7ea036a39b90de25bbd4/constantphysicalsize.png)

![screenmatchmode.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/a72ce0e68cd13c6a3e857474378e8370/screenmatchmode.gif)

![scalewithscreensize.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/d01a35be78221c086df704536f9c15a6/scalewithscreensize.png)

![ScaleWithScreenSize.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/bc6824f9542182a9a314b9b548327873/ScaleWithScreenSize.gif)

![constantpixelsize.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/38e9e78f1ba2e8a4186a683593620ee2/constantpixelsize.png)

![constantphysicalsize.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/d11e2d866f62ea39ee108fe8fa9054d8/constantphysicalsize.gif)

　

- **GRAPHIC RAYCASTER**
  - 캔버스에 있는 그래픽을 감시하고 어떤 그래픽에 충돌했는지 결정.
  - Ignore Reversed Graphics
    - UI가 카메라 방향에 뒤집혀 있을 때 충돌 처리를 할지 말지.
  - Blocking Objects
    - 레이캐스트가 블락킹 될 오브젝트(컬라이더)의 종류
    - 2D, 3D, Everything, None(블락킹될 오브젝트 없음)
  - Blocking Mask
    - 레이캐스트가 블락킹 될 렌더링 레이어 지정

![graphicraycaster.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/095f55512e95bee4b43ee86d1245c8b8/graphicraycaster.png)

　

- **CANVAS RENDERER**
  - 게임 오브젝트를 사용해 캔버스에 시각적인 것을 렌더링 하려면 CanvasRenderer 컴포넌트를 추가해야 한다. 기본적으로 모든 UI 컨트롤에는 이 컴포넌트가 추가되어 있으며 삭제할 수 없다.
  - Cull Transparent Mesh
    - 알파값이 0이 되면 렌더링할 때 아예 취급하지 않도록 무시.
    - 최적화 옵션.

![canvasrenderer.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/475cacda71641c8fdda095fd055f67fa/canvasrenderer.png)

　

- **CANVAS GROUP**
  - 나와 자식 UI 엘리먼트를 묶은 후 속성을 동시에 수정하는 기능.
  - Alpha
    - 그룹 내 모든 UI 엘리먼트들의 투명도 조절
  - Interactable
    - 그룹 내 모든 UI 엘리먼트들이 입력 이벤트를 받을지 말지.
  - Blocks Raycasts
    - 그룹 내 모든 UI 엘리먼트들이 레이캐스트를 무시할지 여부.
    - Physics.Raycast에는 적용되지 않는다.
  - Ignore Parent Groups
    - 상위 그룹의 설정을 무시할지 설정.
    - 언체크 하면 속성은 상속됨. Alpha 값은 중첩(MUL) 표현됨.
  ‌
  ‌
  ‌

![99273A4D5D639B3D0C.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/38df5aad7e7d000398d8f58cabea816e/99273A4D5D639B3D0C.gif)

![99DCC53B5D6397C913.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/47cc0bbe9f1109a8ad5ca156451f57df/99DCC53B5D6397C913.gif)

![9970B44B5D63971504.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/58d7ff0d1be13bce90f435872e91168e/9970B44B5D63971504.png)

![99743E385D5E5E5331.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/2328759e3a3dee53f1e2a2229b112fa2/99743E385D5E5E5331.gif)

![canvasgroup.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/baaadcd5ff33e054d26e6aec2dd5010d/canvasgroup.png)

## 자동 레이아웃 그룹

> 수평, 수직, 그리드 그룹의 세 종류가 있다.이 그룹을 통해 UI를 자동 얼라인하여 배치할 수 있다.그룹은 하이어러키상 중첩해서 사용할 수 있다.

---

- **HORIZONTAL LAYOUT GROUP**
  - 하위 게임 오브젝트를 자동으로 한 행에 배열한다.
  - eg. 인앱 결제 상점 아이템
  - Usage...
    - 1) 씬 안에 Canvas를 생성한다.
    - 2) Canvas에 우 클릭하여 빈 게임 오브젝트 생성
    - 3) 오브젝트의 이름을 "HorizontalLayoutGroup"로 변경
    - 4) 여기에 Horizontal Layout Group 컴포넌트 추가
    - 5) "HorizontalLayoutGroup" 오브젝트 Width 값을 300으로
    - 6) 이 오브젝트의 하위로 세 개의 UI/Image 추가.
    - 7) Image 컴포넌트에 Source Image를 원하는 Sprite로 설정.
  - Image 오브젝트가 가로로 예쁘게 얼라인 되었다.
  - 인스펙터 창에서 Horizontal Layout Group은 아래와 같다.
  - **Padding**
    - 그룹의 마진(left, top, right, bottom)을 설정.
  - **Spacing**
    - 하위 엘리먼트들 사이의 간격을 일괄 설정.
  - **Child Alignment**
    - 하위 엘리먼트들을 레이아웃 그룹 내에서 어느 위치를 중심으로 정렬할 것인지 지정.
  - **Control Child Size**
    - 하위 엘리먼트의 너비, 높이를 리사이징 할지 여부.
    - Child Force Expand 옵션이나 Layout Element 컴포넌트 등과 조합되어 사용됐을 때 좀 더 의미가 있을 듯.
    - 단독 사용하면 원본 이미지보다 작게 리사이징만 된다.
  - **Use Child Scale**
    - 하위 엘리먼트의 스케일 값도 고려해서 배열한다.
    - 2019 버전부터 사용 가능
  - **Child Force Expand**
    - 각 하위 엘리먼트가 그룹 영역 안에서 최대한으로 넓은 공간을 차지하도록 간격을 띄워서 배열한다.
    - 엘리먼트 간의 간격은 균일하게 조정됨.
    - Control Child Size 옵션과 같이 사용되면 그룹 영역의 공간을 모두 차지하도록 컨트롤이 리사이징되어 배열된다.
  - **사용 예**

![ChildControlsSize.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/93fd4d603cca9a0b7019cf23e8a350b2/ChildControlsSize.gif)

![horizontallayoutgroup.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/b77098f0ce27864bfe508f780c761b47/horizontallayoutgroup.png)

![horizontallayoutgroup-100.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/4216536c64e8974f11e010a74f21d5ea/horizontallayoutgroup-100.png)

　

- **VERTICAL LAYOUT GROUP**
  - 하위 게임 오브젝트를 자동으로 한 **열(Vertical)**에 배열한다.
  - Horizontal Layout Group과 비교해 사용법은 같다.

　

- **GRID LAYOUT GROUP**
  - 하위 엘리먼트의 배열을 그리드 구조 안에서 배열한다.
  - 사용법은 수평, 수직 레이아웃 그룹과 거의 동일
  - "GridLayoutGroup" 게임 오브젝트의 Width, Height를 200 설정
  - 하위로 세 개 말고 네 개의 UI/ImageI 추가해봐.
  - 그러면 아래와 같은 모습이 될 거야.
  - **Rect Transform**
    - 레이아웃의 영역 지정
  - **Padding**
    - 그룹의 마진(left, top, right, bottom)을 설정.
  - **Cell Size**
    - 하위 엘리먼트의 내부 셀 크기를 정의한다.
    - 최대한 많은 엘리먼트가 들어갈 수 있도록 자동 리사이즈됨?
    - 셀이 더 들어갈 수 없는 상황이라면 리사이즈는 취소됨?
  - **Spacing**
    - 하위 엘리먼트들 사이의 간격을 일괄 설정.
    - X축, Y축 별도 설정.
  - **Start Corner**
    - 첫 번째 셀이 그리드 어디에서부터 그려질지 결정.
      - Upper Left
      - Upper Right
      - Lower Left
      - Lower Right
  - **Start Axis**
    - Start Corner를 시작으로 어떤 방향으로 그려질지 설정.
    - Horizontal
    - Vertical
  - **Child Alignment**
    - 하위 엘리먼트들의 앵커 모드 설정.
  - **Constraint**
    - Fixed Row Count
      - 행의 최대 개수를 제한
    - Fixed Column Count
      - 열의 최대 개수를 제한
    - Flexible
      - 개수에 제한을 걸지 않음

![grid-axis.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/e84378f10211fe844718216f63aca222/grid-axis.png)

![gridlayoutgroup.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/4fdcb5b5a1e89618aac67313e3f08fec/gridlayoutgroup.png)

　

## 레이아웃 옵션

> 레이아웃 그룹 컴포넌트는 잘 동작하지만 디테일이 떨어져.세밀한 부분까지 제어하기 위해 아래 컴포넌트가 제공됨.이들 컴포넌트들은 앞서 설명한 레이아웃 그룹 컴포넌트의 일부 기능을 무시하거나 재정의 하므로 사용에 유의가 필요하다.Layout ElementContent Size FitterAspect Ratio FitterScroll RectsMasks

---

- **LAYOUT ELEMENT**
  - 레이아웃 그룹 하위 요소들에 Layout Element 컴포넌트 추가.
  - 레이아웃 그룹의 리사이징 기본 기능을 커스터마이징 한다.
  - 사실 좀 더 정확히 말하자면, 레이아웃 그룹이 하위 엘리먼트들을 리사이징하기 위해서 각 하위 UI 컨트롤들이 가지고 있는 최소, 선호 또는 가변 크기 값(대부분의 UI 컨트롤은 내부적으로 Layout Element 속성을 포함)을 가지고 계산하는데, 이 Layout Element 컴포넌트는 이들 값을 변경하는 역할을 한다. 다시 말해, 부모의 레이아웃 그룹은 Control Child Size 옵션이 켜져 있고 Child Force Expand 옵션이 꺼져 있어야 이 컴포넌트의 의미가 있겠다.
  - **Ignore Layout**
    - 체크하면 레이아웃 그룹으로 정렬을 하지 않는다.
    - 스크립트에서 직접 수치를 지정할 때 사용.
  - **Min Width**
    - 자동 리사이징 될 때의 최소 가로크기
  - **Min Height**
    - 자동 리사이징 될 때의 최소 세로크기
  - **Preferred Width, Height**
    - 자동 리사이징 될 때의 최대(선호) 크기
    - 말 그대로 이 크기를 선호하면서 정렬되게 한다는 것이지, 꼭 이 길이로 설정된다는 것은 아님. Min을 우선적으로 하고 그룹 크기 내에서 될 수 있으면 Preferred 크기에 최대한 가깝게 되게끔 한다.
    - 부모 레이아웃 그룹의 Child Force Expand 옵션이 켜져 있으면 의미가 없다. 걍 최대 리사이즈 됨.
  - **Flexible Width, Height**
    - 책에서는 엘리먼트가 어느 비율만큼 차지할지를 지정?
    - 레퍼런스 문서에서는 레이아웃 요소가 형제 레이아웃에 상대적으로 채워야 하는 (추가 사용 가능한) 너비의 상대적 크기. 즉 남는 여백을 얼만큼 차지하는지 지정한다고 하는데... 0과 0이 아닌 값의 느낌으로 동작한다.
    - 유니티 버그인지 내가 병신인 건지... 잘 모르겠다.
    - 좀 더 찾아보자!
  - **Layout Priority**
    - 레이아웃 속성 중첩 사용 시 의미 있음.
    - UI 컨트롤이 디폴트로 가지고 있는 Layout Priority는 0
    - Layout Priority가 가장 높은 컴포넌트 속성 값을 사용.
    - Priority가 같으면 각 속성 값 중 가장 큰 값 사용.
  - **사용 예**

![LayoutElement.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/5b8e1e56eb6404b680697401fe976f98/LayoutElement.gif)

![verticallayoutgroup-layoutelement.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/2cc142c6357cf8bca073df942a4f0031/verticallayoutgroup-layoutelement.png)

　

- **CONTENT SIZE FITTER**
  - 자체 레이아웃 요소의 크기를 제어하는 기능을 수행.
  - 크기는 게임 오브젝트 레이아웃 요소 컴포넌트의 min 또는 preferred 크기에 따라 결정된다. 즉, 레이아웃 요소는 ILayoutElement 인터페이스를 상속받는 Image 또는 Text 컴포넌트이거나, 레이아웃 그룹이거나, Layout Element 컴포넌트일 수 있다.
  - Content Size Fitter
  - Unconstrained
    - 아무것도 하지 않음.
  - MinSize
    - 너비 또는 높이를 하위 컨텐츠의 최소값으로 제한.
  - PreferredSize
    - 너비 또는 높이를 하위 컨텐츠의 Preferred 값으로 제한.
  - **레이아웃 그룹과 함께 사용하는 경우의 예**
    - 1) 씬에 Canvas 추가
    - 2) Canvas에 UI/Image 추가 - 배경으로 사용
    - 3) Image 하위로 UI/Text 세 개 추가
    - 4) Image 오브젝트에 Vertical Layout Group 추가
    - 5) Vertical Layout Group 컴포넌트에 Control Child Size 필드의 Width 항목 체크
    - 6) Image 오브젝트에 Content Size Fitter 추가
    - 7) Content Size Fitter의 Horizontal Fit 필드 값을 Preferred Size로 설정.
  - **작동원리(추측)**
    - Text UI에 텍스트가 입력되면 자체 Preferred Size가 변경.
    - Vertical Layout Group의 Control Child Size 옵션이 켜져 있기 때문에 하위 레이아웃 엘리먼트의 Preferred Size가 바뀌었으므로 크기 조절을 위해 계산 - 레이아웃 그룹 자체 Preferred Size도 변경됨.
    - Content Size Fitter가 변경된 레이아웃 그룹의 Preferred Size를 감지하고 자체 Transform 크기 변경.
    - 결국 배경 이미지 크기가 변경됨.
    - 뭐, 이런 느낌?
  - **Text UI 컨트롤과 함께 사용하는 경우의 예**
    - Text 컴포넌트만 단독으로 사용한 경우, 텍스트 내용이 UI의 사이즈보다 커지면 옵션에 따라...
    - 뒷부분이 잘리거나 - Truncate
    - 영역을 넘어간다 - Overflow
    - Content Size Fitter를 사용하면 Transform 사이즈가 텍스트의 내용에 따라 자동으로 변하는 것을 확인할 수 있다.
  - **피벗을 활용하는 예제**
    - 콘텐츠 사이즈 피터로 인해 Rect Transform의 크기가 변경될 때는 UI의 피벗을 중심으로 조정되기 때문에, 피벗을 사용해서 UI의 크기가 조정되는 방향을 조절할 수 있다.
    - 위 예제는 피벗이 중심에 있어서 양 방향으로 리사이징 됨.
    - 아래 이미지를 보면 X Pivot을 0으로 변경해서 UI의 피벗을 가장 좌측으로 옮긴 결과, UI의 트랜스폼이 왼쪽에서 오른쪽으로 확장되는 것을 볼 수 있다.
  - **콘텐츠 사이즈 피터를 활용한 스크롤 뷰 예제**
    - 음... 잠시 대기...
    - 가변버튼, 센터얼라인아이콘+텍스트, 다이아배경(최소유지+가변), 텍스트+버튼(이미지)

![TextUIPivot.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/6e36b1a4a98c174b842faf3bfe5abb1b/TextUIPivot.gif)

![TextUIContentSizeFitter.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/8f6f49adfd18f33ad521559d84b3610a/TextUIContentSizeFitter.gif)

![TextUI.gif](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/80252838ebe43ce963706faa38f3beb4/TextUI.gif)

![UI\_ContentSizeFitterInspector.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/601781e04f70403127bd7032/a82e6e135ec47c7251a2c56c554e808f/UI_ContentSizeFitterInspector.png)

　

- **ASPECT RATIO FITTER**
  - Aspect Ratio(종횡비) 값에 따라서 UI를 리사이즈 한다.
  - 화면 해상도 얘기가 아님. Rect Transform 리사이즈 얘기다.
  - 최소 및 선호 크기와 같은 레이아웃 정보를 고려하지 않는다.
  - **Options**
  - **Aspect Mode**
    - None
      - 종횡비 맞추지 않음
    - Width Controls Height
      - 너비에 따라 높이가 조정된다.
      - 즉, Height = Width * Aspect Ratio
    - Height Controls Width
      - 높이에 따라 너비가 조정된다.
      - 즉, Width = Height * Aspect Ratio
    - Fit In Parent
      - 종횡비를 유지하면서 영역이 부모 영역 안에 들어가도록 너비, 높이, 포지션 및 앵커를 자동으로 조정한다. 부모 영역 안에 이 영역이 덮지 않는 공간이 있을 수 있다.
    - Envelope Parent
      - 종횡비를 유지하면서 영역이 부모의 전체 영역을 덮도록 너비, 높이, 포지션 및 앵커를 자동으로 조정합니다. 이 영역은 부모 영역 밖으로 나올 수 있습니다.
  - **Aspect Ratio**
    - 적용할 종횡비(너비 / 높이)
  - **적용 예**

![1.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/c04c45ead36ffa50ca8d9d56d663712b/1.png)

![UI\_AspectRatioFitterInspector.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/1057f481fe0f3d7c5202a999b190320f/UI_AspectRatioFitterInspector.png)

　

- **SCROLL RECT**
  - 레이아웃 그룹 내 컨텐츠를 스크롤 할 때 사용.
  - 꼭 레이아웃 그룹일 필요는 없으며 스크롤 가능한 UI 컨트롤이면 상관없다. 그나저나 이게 왜 이 시점에 등장하는지... ٩(๑´0`๑)۶
  - _**3장 '컨트롤 배우기' **_에서 좀 더 복잡한 예를 살펴볼 예정.
  - 닥치고 예제
    - 1) 씬에 Canvas 추가.
    - 2) Canvas 하위로 빈 게임 오브젝트 추가하고,
    - 3) 이 오브젝트 이름을 "ScrollRectArea"로 변경.
    - 4) "ScrollRectArea"의 Width 값을 300으로 설정.
    - 5) 이 오브젝트에 Scroll Rect 컴포넌트 추가.
    - 6) 이 오브젝트 하위에 빈 게임 오브젝트 추가하고,
    - 7) 이름을 "Content"로 변경
    - 8) "Content"의 Width를 1000으로 설정.
    - 9) "Content" 게임 오브젝트를 선택한 후 Horizontal Layout Group 컴포넌트를 추가.
    - 10) "Content" 하위에 Image 컴포넌트를 몇 개 추가.
    - 11) "ScrollRectArea" 게임 오브젝트에 바인딩 되어있는 Scroll Rect 컴포넌트의 Content 속성으로 "Content" 게임 오브젝트를 할당합니다.
  - **Options**
  - **Content**
    - Scroll Rect 안의 컨텐츠를 포함하는 Rect Transform을 지정.
  - **Horizontal / Vertical**
    - 컨텐츠 영역의 스크롤 방향.
  - **Movement Type**
    - 스크롤 움직임 스타일을 지정한다.
    - **Unrestricted**
      - 제약 없이 움직인다. 심지어 화면이 스크롤 영역을 벗어나도 움직일 수 있다.
    - **Elastic**
      - 영역을 벗어난 경우 튕겨서 제자리로 돌아옴.
      - Elasticity 값을 변경하여 탄성 조절 가능.
    - **Clamped**
      - 스크롤 영역 안에서 고정된 움직임을 보임.
      - 영역을 벗어나면 바로 멈춤.
  - **Inertia**
    - 스크롤 움직임에 관성 물리법칙을 적용할지 말지.
    - Deceleration Rate 값으로 감속량 조절 가능.
  - **Scroll Sensitivity**
    - 사용자 스크롤 액션에 대한 스크롤 감도 조정.
  - **Viewport**
    - 표시하고자 하는 콘텐츠가 보여질 곳.
    - 컨텐츠의 부모 뷰포트 Rect Transform.
  - **Horizontal/Vertical Scrollbar**
    - 가로/세로 스크롤바 UI 지정
    - Visibility
      - 스크롤바를 계속 보이게 할지
      - 필요 없을 때 자동으로 스크롤바를 숨길지
      - 선택적으로 뷰포트도 확장할지 말지.
    - Spacing
      - 스크롤바와 뷰포트 간의 공간.

![scrollrect.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/2cdb26f4ac8ccfa25e93a519cb80c0f2/scrollrect.png)

　

- **MASK**
  - 하위 컴포넌트가 보여지는 영역을 지정한다.
  - 단독으로 사용했을 때는 아무 의미 없고 Image 등의 Graphic 컴포넌트와 함께 사용해서 마스킹 영역을 지정해야 한다.
  - 앞의 예제에서...
    - "ScrollRectArea" 오브젝트에 Mask 컴포넌트 추가.
    - Image 컴포넌트 소스 이미지의 알파값으로 마스킹 됨.
    - Image 컴포넌트에 이미지가 없으면 RT 영역만 뚫림.
  - 아래 그림처럼 "ScrollRectArea" 영역만 보여짐

![mask.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/602b4ca63ce3a8326605cb9a/00b3aa6ea436f132e04c78c6334af7f5/mask.png)

　

- **RECTMASK2D**
  - _<잠시대기>_
  