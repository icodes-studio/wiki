# CHAPTER 2 - Building Layouts
    ● 새로운 Rect Transform
    ● Unity UI 캔버스
    ● 레이아웃과 그룹화 시스템
    ● Unity Event와 새로운 EventSystem
*https://docs.unity3d.com/2023.2/Documentation/Manual/PositioningGameObjects.html*


　

- **RECT TRANSFORM**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/class-RectTransform.html*
    - 본디 스프라이트 시스템(Unity 4.3)에서 2D 영역을 지정하는 기능으로 시작됨.
    - 이후 Unity 2D UI를 위한 Rect Transform 컴포넌트로 발전됨.


　

- **RECT TOOL**
    - 씬 뷰에서 바로 UI 요소의 크기를 조절하는 툴.
    - 씬 뷰에서 바로 Rect Transform을 수정할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/rect_tool.png)
    - 각 꼭짓점마다 하나씩 네 개의 컨트롤 포인트가 나타나며, 이 포인트를 조작하여 피벗 포인트를 기준으로 UI의 크기를 조정.
    - \<Shift\> 버튼을 누른 채로 가장자리 컨트롤 포인트를 움직이면 종횡비를 그대로 유지하면서 크기 조정 가능.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/recttool-scene.png)


　

- **피벗 모드와 공간 모드**
    - 평소 UI를 조작할 때는 Pivot 과 Local 을 설정하면 좋다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/GUI_Pivot_Local_Buttons.png)
    - Center
        > - 선택 영역의 중앙이 피벗 포인트 역할을 한다.
        > - Pivot 값 기준으로 회전 또는 스케일 편집되는 것이 아니라 강제로 중앙을 기준으로 회전 또는 스케일 편집이 된다.
        > - 에디터에서 편집할 때만 적용된다는 것을 명심해야 한다! 런타임에는 당연히 피벗 포인트가 기준이 된다.
    - Pivot
        > - 피벗 포인트에서 마우스를 끌면 피벗 포인트 위치 조정.
        > - 피벗 포인트 기준으로 회전이나 스케일 편집이 된다.
    - Global
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/global.png)
        > - 오브젝트가 회전되어 있더라도 선택 영역은 같이 회전하지 않는다.
        > - 즉, 방향 이동 기즈모가 글로벌 기준으로 고정되어 있다.
    - Local
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/local.png)
        > - 오브젝트가 회전되었다면 선택 영역도 같이 회전한다.
        > - 결국 방향 이동 기즈모가 회전에 맞게 같이 돌아가므로, 회전에 맞게 이동시키기 편하다.


　

- **RECT TRANSFORM 컴포넌트**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/class-RectTransform.html*
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
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/blueprintmode.png)
        > - 회전에 상관없이 선택 영역이 고정된 상태로 크기 조절 가능
        > - 공간 모드 - Global과 동일하게 동작한다.
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
        > - y=0 : 오브젝트의 최 하단, y=1 : 오브젝트의 최 상단.
        > - **피벗이 (0.5, 0.5)일 경우 스케일 & 회전**
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/centerpivot.gif)
        > - **피벗이 (0, 0.5)일 경우 스케일 & 회전**
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/leftpivot.gif)


　

　

# # CANVAS
    ● UI를 그리는 일종의 그림판 같은 역할을 한다.
    ● 모든 UI 요소는 Canvas 안에 위치해야 한다.
    ● 그려지는 순서는 하이어러키 순서와 동일
    ● 씬이 2D인지 3D 인지에 상관없이 UI를 배치할 수 있다.
    ● 각 UI를 3D 공간에서 서로 나누어 배치할 수도 있다.
*https://docs.unity3d.com/2023.2/Documentation/Manual/UICanvas.html*


　

- **[RENDER MODE] Screen Space - Overlay**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/class-Canvas.html*
    - 카메라 독립적으로 UI를 최상위에 오버레이 하는 방식.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CanvasOverlay.png)
    - 해상도 변경 시 스크린에 일치하도록 캔버스가 자동으로 크기 변경됨.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-overlay.png)
    - Pixel Perfect
        > - UI 엘리먼트에 대해 [***픽셀 퍼펙트***](https://docs.unity3d.com/ScriptReference/Canvas-pixelPerfect.html)렌더링을 수행.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/pixelperfect.gif)
        > - 퍼포먼스 부분에서 손해를 보는 부분이 있다.
    - Sort Order
        > - 여러 개 Overlay 캔버스가 있는 경우, 그리는 순서
        > - 낮은 순서의 캔버스는 아래에 그려진다.


　

- **[RENDER MODE] Screen Space - Camera**
    - 캔버스가 그려질 카메라를 선택하여 UI를 렌더링 한다.
    - 게임 오브젝트를 UI 앞이나 뒤에 배치할 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CanvasCamera.png)
    - 해상도 변경 또는 카메라의 frustum을 변경한 경우, 캔버스도 자동으로 일치하도록 크기 변경됨.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-camera.png)
    - Render Camera
        > - 캔버스가 그려질 카메라.
        > - 지정하지 않으면 Overlay 모드처럼 동작.
    - Plane Distance
        > - 캔버스가 카메라로부터 떨어진 거리.
    - Sorting Layer
        > - 캔버스가 다른 캔버스 또는 스프라이트 렌더링 컴포넌트와 함께 씬에 사용되는 경우(eg. Sprite Renderer), 캔버스가 어떤 스프라이트 소팅 레이어에 렌더링 될 것인지 설정.
    - Order in Layer
        > - 선택된 소팅 레이어에서 캔버스가 그려지는 순서.
        > - 낮은 순서의 캔버스는 아래에 그려진다.


　

- **[RENDER MODE] World Space**
    - 캔버스가 씬에서 오브젝트처럼 동작한다.
    - UI 요소는 오브젝트 배치에 따라 앞면 혹은 뒷면에 그려짐.
    - 3D 월드에 속하는 인터페이스 UI의 일부로써 유용하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CanvasWorldSpace.png)
    - ***AKA,*** ***"Diegetic Interface"***
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-worldspace.png)
    - Event Camera
        > - UI 이벤트를 처리하는 데 사용할 카메라
        > - 즉, EventSystem이 어떤 카메라를 사용할지 결정.
        > - 지정하지 않으면 Main Camera가 디폴트로 사용.


　

- **CANVAS SCALER**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-CanvasScaler.html*
    - UI 요소의 전체적인 **스케일과 픽셀 밀도**를 제어하는 데 사용.
    - 글꼴 크기와 이미지 경계 등 캔버스 아래의 모든 요소에 영향 미침.


　

- **[CANVAS SCALER] UI Scale Mode**
    - 캔버스에서 UI 요소가 스케일 되는 방법을 결정한다.


　

- **[UI SCALE MODE] Constant Pixel Size**
    - 화면 크기에 관계없이 동일한 픽셀 크기로 유지된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constantphysicalsize.gif)
    - **Options**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constantpixelsize.png)
    - **Scale Factor**
        > - 모든 UI 요소를 이 배율로 스케일 한다.
        > - 화면 중앙을 중심으로 스케일 됨.
    - **Reference Pixels Per Unit**
        > - 스프라이트에 이 ‘Pixels Per Unit’ 설정값이 적용된 경우 스프라이트 1픽셀이 UI 유닛 하나에 해당.
        > - Set Native Size 눌러보면 느낌 팍 옴.
        > - \<Sprite의 Pixels Per Unit> / \<Canvas Scaler의 Reference Pixels Per Unit\> = Pixels Per Unit
        > - 예를 들어 Sprite의 Pixels Per Unit 값이 100 이고 Canvas Scaler의 Reference Pixels Per Unit 값이 50이면 2 Pixels Per Unit으로 유닛 하나 공간에 픽셀 2개가 찍히게 되므로 크기가 절반으로 줄어든다.


　

- **[UI SCALE MODE] Scale With Screen Size**
    - 해상도에 따라 UI 요소가 작아지거나 커진다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ScaleWithScreenSize.gif)
    - **Options**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/scalewithscreensize.png)
    - **Reference Resolution**
        > - UI 레이아웃에 적합한 해상도를 지정.
        > - UI가 커지고 작아질 기준 해상도
        > - 이 해상도 기준으로 아트웍 리소스 작업 추천.
    - **Screen Match Mode**
        > - 해상도의 종횡비가 레퍼런스 해상도에 맞지 않는 경우 캔버스 영역을 스케일 하는 데 사용.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/screenmatchmode.gif)
    - **Screen Match Mode: Match Width or Height**
        > - **Match**로 캔버스 기준(너비, 높이 or 그 사이)을 설정 하고 그 기준으로 캔버스를 스케일 한다.
        > - 즉, 캔버스 크기가 레퍼런스보다 커지면 레터박스가 생기고 레퍼런스보다 작아지면 잘리게 되므로
        > - 만약 Width로 Match 기준을 몰빵했다치면 디바이스 해상도에 따라 위 아래로 레터박스가 생기거나 잘리는 상황이 발생한다.
    - **Screen Match Mode: Expand**
        > - 캔버스 크기가 레퍼런스보다 더 작아지지 않도록 캔버스를 수평 또는 수직 확장.
        > - 레터박스는 생겨도 잘리진 않는다.
    - **Screen Match Mode: Shrink**
        > - 캔버스 크기가 레퍼런스보다 커지지 않도록 캔버스를 수평 또는 수직으로 자른다.
        > - 잘리긴 해도 레터박스는 생기지 않는다.


　

- **[UI SCALE MODE] Constant Physical Size**
    - 화면 크기에 관계없이 UI가 동일한 물리적인 크기로 유지.
    - 포지션과 크기가 포인트 등의 물리적인 단위로 지정된다.
    - 그러려면 기기의 화면 DPI가 정확하게 보고되어야 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constantphysicalsize.png)
    - **Physical Unit**
        > - 포지션 및 크기를 지정하는 물리적 단위.
        > - [***참고: 픽셀과 포인트***](https://spoqa.github.io/2012/07/06/pixel-and-point.html)
        > - [***참고: CSS 크기단위***](https://chpofo.tistory.com/30)
        > - Centimeters
        > - Millimeters
        > - Inches
        > - Points
        > - Picas
    - **Fallback Screen DPI**
        > - 화면 DPI를 알 수 없는 경우 가정되는 DPI ???
    - **Default Sprite DPI**
        > - ‘Pixels Per Unit’ 설정이 ‘Reference Pixels Per Unit’ 설정과 일치하는 스프라이트에 사용할 DPI
    - **Reference Pixels Per Unit**
        > - 스프라이트에 이 ‘Pixels Per Unit’ 설정값이 적용된 경우 DPI는 ‘Default Sprite DPI’ 설정과 일치.


　

- **[UI SCALE MODE] World**
    - 캔버스가 World Space로 설정된 경우의 UI 스케일 모드.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvasscaler-world.png)
    - **Dynamic Pixels Per Unit**
        > - UI에서 동적으로 생성되는 비트맵(예: 텍스트)에 사용할 유닛당 픽셀의 양.
        > - 변경하면서 Text UI 크기와 선명도 보면 느낌 팍 옴.


　　

- **GRAPHIC RAYCASTER**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-GraphicRaycaster.html*
    - 캔버스에 있는 그래픽을 감시하고 어떤 그래픽에 충돌했는지 결정.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/graphicraycaster.png)
    - Ignore Reversed Graphics
        > - UI가 카메라 방향에 뒤집혀 있을 때 충돌 처리를 할지 말지.
    - Blocking Objects
        > - 레이캐스트가 충돌했을 때 블락킹할(더 이상 레이캐스트를 뒤로 전달하지 않고 무시할) 오브젝트(컬라이더)의 종류
        > - 2D, 3D, All, None(즉, 모든 물체에 대해 충돌)
    - Blocking Mask
        > - Blocking Objects 기능이 동작할 레이어 지정


　

- **CANVAS RENDERER**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/class-CanvasRenderer.html*
    - 게임 오브젝트를 사용해 캔버스에 시각적인 것을 렌더링 하려면 CanvasRenderer 컴포넌트를 추가해야 한다.
    - 기본적으로 모든 UI 컨트롤에는 이 컴포넌트가 추가되어 있으며 삭제할 수 없다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvasrenderer.png)
    - Cull Transparent Mesh
        > - 알파값이 0이 되면 렌더링할 때 아예 취급하지 않도록 무시.
        > - 최적화 옵션.


　

- **CANVAS GROUP**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/class-CanvasGroup.html*
    - 나와 자식 UI 엘리먼트를 묶은 후 속성을 동시에 수정하는 기능.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvasgroup.png)
    - Alpha
        > - 그룹 내 모든 UI 엘리먼트들의 투명도 조절
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvasgroupalpha.gif)
    - Interactable
        > - 그룹 내 모든 UI 엘리먼트들이 입력 이벤트를 받을지 말지.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvasgroupinteractable.gif)
    - Blocks Raycasts
        > - 그룹 내 모든 UI 엘리먼트들이 레이캐스트를 무시할지 여부.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/blockraycast.gif)
    - Ignore Parent Groups
        > - 상위 그룹의 설정을 무시할지 설정.
        > - 언체크 하면 속성은 상속됨. Alpha 값은 중첩(MUL) 표현됨.


　

　

# # 자동 레이아웃 그룹
    ● 수평, 수직, 그리드 그룹의 세 종류가 있다.
    ● 이 그룹을 통해 UI를 자동 얼라인하여 배치할 수 있다.
    ● 그룹은 하이어러키상 중첩해서 사용할 수 있다.
*https://docs.unity3d.com/2023.2/Documentation/Manual/UIAutoLayout.html*


　

- **HORIZONTAL LAYOUT GROUP**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-HorizontalLayoutGroup.html*
    - 하위 게임 오브젝트를 자동으로 한 행에 배열한다.
    - *eg. 상점 아이템*
    - Usage...
        > - 1\) 씬 안에 Canvas를 생성한다.
        > - 2\) Canvas에 우 클릭하여 빈 게임 오브젝트 생성
        > - 3\) 오브젝트의 이름을 "HorizontalLayoutGroup"로 변경
        > - 4\) 여기에 Horizontal Layout Group 컴포넌트 추가
        > - 5\) "HorizontalLayoutGroup" 오브젝트 Width 값을 300으로
        > - 6\) 이 오브젝트의 하위로 세 개의 Image 추가.
        > - 7\) Image 컴포넌트에 Source Image를 원하는 Sprite로 설정.
    - Image 오브젝트가 가로로 예쁘게 얼라인 되었다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/horizontallayoutgroup-100.png)
    - Horizontal Layout Group 컴포넌트
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/horizontallayoutgroup.png)
    - **Padding**
        > - 그룹의 마진(left, top, right, bottom)을 설정.
    - **Spacing**
        > - 하위 엘리먼트들 사이의 간격을 일괄 설정.
    - **Child Alignment**
        > - 하위 엘리먼트들을 레이아웃 그룹 내에서 어느 위치를 중심으로 정렬할 것인지 지정.
    - **Reverse Alignment**
        > - 하위 엘리먼트들의 배치 순서를 반대로 설정.
    - **Control Child Size**
        > - 하위 엘리먼트의 너비, 높이를 그룹 영역 안에서 최대한 넓은 공간을 차지하도록 리사이징 할지 여부.
        > - Child Force Expand 옵션이나 Layout Element 컴포넌트 등과 조합되어 사용됐을 때 좀 더 의미가 있을 듯.
        > - 단독 사용하면 원본 이미지보다 작게 리사이징만 된다.
    - **Use Child Scale**
        > - 하위 엘리먼트의 스케일 값도 고려해서 배열한다.
    - **Child Force Expand**
        > - 각 하위 엘리먼트가 그룹 영역 안에서 최대한으로 넓은 공간을 차지하도록 간격을 띄워서 배열한다.
        > - 엘리먼트 간의 간격은 균일하게 조정됨.
        > - Control Child Size 옵션과 같이 사용되면 그룹 영역의 공간을 모두 차지하도록 컨트롤이 리사이징되어 배열된다.
    - **사용 예**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ChildControlsSize.gif)


　

- **VERTICAL LAYOUT GROUP**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-VerticalLayoutGroup.html*
    - 하위 게임 오브젝트를 자동으로 한 열(Vertical)에 배열한다.
    - Horizontal Layout Group과 비교해 사용법은 같다.


　

- **GRID LAYOUT GROUP**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-GridLayoutGroup.html*
    - 하위 엘리먼트의 배열을 그리드 구조 안에서 배열한다.
    - 사용법은 수평, 수직 레이아웃 그룹과 거의 동일
    - "GridLayoutGroup" 게임 오브젝트의 Width, Height를 200 설정
    - 하위로 세 개 말고 네 개의 Image 추가해봐.
    - 그러면 아래와 같은 모습이 될 거야.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/gridlayoutgroup.png)
    - **Rect Transform**
        > - 레이아웃의 영역 지정
    - **Padding**
        > - 그룹의 마진(left, top, right, bottom)을 설정.
    - **Cell Size**
        > - 하위 엘리먼트의 내부 셀 크기를 정의한다.
        > - 최대한 많은 엘리먼트가 들어갈 수 있도록 자동 리사이즈됨?
        > - 셀이 더 들어갈 수 없는 상황이라면 리사이즈는 취소됨?
    - **Spacing**
        > - 하위 엘리먼트들 사이의 간격을 일괄 설정.
        > - X축, Y축 별도 설정.
    - **Start Corner**
        > - 첫 번째 셀이 그리드 어디에서부터 그려질지 결정.
        > - Upper Left
        > - Upper Right
        > - Lower Left
        > - Lower Right
    - **Start Axis**
        > - Start Corner를 시작으로 어떤 방향으로 그려질지 설정.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/grid-axis.png)
        > - Horizontal
        > - Vertical
    - **Child Alignment**
        > - 하위 엘리먼트들을 레이아웃 그룹 내에서 어느 위치를 중심으로 정렬할 것인지 지정.
    - **Constraint**
        > - Fixed Row Count: 행의 최대 개수를 제한
        > - Fixed Column Count: 열의 최대 개수를 제한
        > - Flexible: 개수에 제한을 걸지 않음


　

　

# # 레이아웃 옵션
    ● 세밀하게 레이아웃을 제어하기 위해 별도 컴포넌트가 제공된다.
    ● 이들 컴포넌트들은 앞서 설명한 레이아웃 그룹 컴포넌트의 일부 기능을 무시하거나 재정의 하므로 사용에 유의가 필요하다.
    ● Layout Element
    ● Content Size Fitter
    ● Aspect Ratio Fitter
    ● Scroll RectsMasks
*https://docs.unity3d.com/2023.2/Documentation/Manual/UIAutoLayout.html*


　

- **LAYOUT ELEMENT**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-LayoutElement.html*
    - 레이아웃 그룹 하위 요소들에 Layout Element 컴포넌트 추가.
    - 레이아웃 그룹의 리사이징 기본 기능을 커스터마이징 한다.
    - ***레이아웃 그룹의 Control Child Size 옵션이 켜져 있고 Child Force Expand 옵션이 꺼져 있어야 이 컴포넌트의 의미가 있겠다.***
    - 좀 더 정확히 말하자면, 레이아웃 그룹이 하위 엘리먼트들을 리사이징하기 위해서 각 하위 UI 컨트롤들이 가지고 있는 최소, 선호 또는 가변 크기 값(대부분의 UI 컨트롤은 내부적으로 Layout Element 속성을 포함)을 가지고 계산하는데, 이 Layout Element 컴포넌트는 이들 값을 변경하는 역할을 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/verticallayoutgroup-layoutelement.png)
    - **Ignore Layout**
        > - 체크하면 레이아웃 그룹으로 정렬을 하지 않는다.
        > - 스크립트에서 직접 수치를 지정할 때 사용.
    - **Min Width**
        > - 자동 리사이징 될 때의 최소 가로크기
    - **Min Height**
        > - 자동 리사이징 될 때의 최소 세로크기
    - **Preferred Width, Height**
        > - 자동 리사이징 될 때의 최대(선호) 크기
        > - 말 그대로 이 크기를 선호하면서 정렬되게 한다는 것이지, 꼭 이 길이로 설정된다는 것은 아님. Min을 우선적으로 하고 그룹 크기 내에서 될 수 있으면 Preferred 크기에 최대한 가깝게 되게끔 한다.
    - **Flexible Width, Height**
        > - 책에서는 엘리먼트가 어느 비율만큼 차지할지를 지정한다 하고...
        > - 레퍼런스 문서에서는 레이아웃 요소가 형제 레이아웃에 상대적으로 채워야 하는 (추가 사용 가능한) 너비의 상대적 크기. 즉 남는 여백을 얼만큼 차지하는지 지정한다고 하는데... 0과 0이 아닌 값의 느낌으로 동작한다.
        > - 유니티 버그인지 내가 병신인 건지... 잘 모르겠다.
    - **Layout Priority**
        > - 레이아웃 속성 중첩 사용 시 의미 있음.
        > - UI 컨트롤이 디폴트로 가지고 있는 Layout Priority는 0
        > - Layout Priority가 가장 높은 컴포넌트 속성 값을 사용.
        > - Priority가 같으면 각 속성 값 중 가장 큰 값 사용.
    - **사용 예**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/LayoutElement.gif)


　

- **CONTENT SIZE FITTER**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-ContentSizeFitter.html*
    - 자체 레이아웃 요소의 크기를 제어하는 기능을 수행.
    - 크기는 게임 오브젝트 레이아웃 요소 컴포넌트의 min 또는 preferred 크기에 따라 결정된다.
    - 즉, 레이아웃 요소는 ILayoutElement 인터페이스를 상속받는 Image 또는 Text 컴포넌트이거나, 레이아웃 그룹이거나, Layout Element 컴포넌트일 수 있다.
    - Content Size Fitter
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_ContentSizeFitterInspector.png)
    - Unconstrained
        > - 아무것도 하지 않음.
    - MinSize
        > - 너비 또는 높이를 하위 컨텐츠의 Min 값으로 제한.
    - PreferredSize
        > - 너비 또는 높이를 하위 컨텐츠의 Preferred 값으로 제한.
    - **레이아웃 그룹과 함께 사용하는 경우의 예**
        > - 1\) 씬에 Canvas 추가
        > - 2\) Canvas에 Image 추가 - 배경으로 사용
        > - 3\) Image 하위로 Text 세 개 추가
        > - 4\) Image 오브젝트에 Vertical Layout Group 추가
        > - 5\) Vertical Layout Group 컴포넌트에 Control Child Size 필드의 Width 항목 체크
        > - 6\) Image 오브젝트에 Content Size Fitter 추가
        > - 7\) Content Size Fitter의 Horizontal Fit 필드 값을 Preferred Size로 설정.
        > - 8\) Text 내용에 따라 배경 Image 가로 크기가 자동으로 변경 됨.
    - **Text UI 컨트롤과 함께 사용하는 경우의 예**
        > - Text 컴포넌트만 단독으로 사용한 경우, 텍스트 내용이 UI의 사이즈보다 커지면 옵션에 따라...
        > - 뒷부분이 잘리거나 - Truncate
        > - 영역을 넘어간다 - Overflow
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/TextUI.gif)
        > - Content Size Fitter를 사용하면 Transform 사이즈가 텍스트의 내용에 따라 자동으로 변하는 것을 확인할 수 있다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/TextUIContentSizeFitter.gif)
    - **피벗을 활용하는 예제**
        > - 콘텐츠 사이즈 피터로 인해 Rect Transform의 크기가 변경될 때는 UI의 피벗을 중심으로 조정되기 때문에, 피벗을 사용해서 UI의 크기가 조정되는 방향을 조절할 수 있다.
        > - 위 예제는 피벗이 중심에 있어서 양 방향으로 리사이징 됨.
        > - 아래 이미지를 보면 X Pivot을 0으로 변경해서 UI의 피벗을 가장 좌측으로 옮긴 결과, UI의 트랜스폼이 왼쪽에서 오른쪽으로 확장되는 것을 볼 수 있다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/TextUIPivot.gif)


　

- **ASPECT RATIO FITTER**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-AspectRatioFitter.html*
    - Aspect Ratio(종횡비) 값에 따라서 UI를 리사이즈 한다.
    - 화면 해상도 얘기가 아님. Rect Transform 리사이즈 얘기다.
    - 최소 및 선호 크기와 같은 레이아웃 정보를 고려하지 않는다.
    - **Options**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_AspectRatioFitterInspector.png)
    - **Aspect Mode**
        > - None: 종횡비 맞추지 않음
        > - Width Controls Height: 너비에 따라 높이가 조정된다. 즉, Height = Width * Aspect Ratio
        > - Height Controls Width: 높이에 따라 너비가 조정된다. 즉, Width = Height * Aspect Ratio
        > - Fit In Parent: 종횡비를 유지하면서 영역이 부모 영역 안에 들어가도록 너비, 높이, 포지션 및 앵커를 자동으로 조정한다. 부모 영역 안에 이 영역이 덮지 않는 공간이 있을 수 있다.
        > - Envelope Parent: 종횡비를 유지하면서 영역이 부모의 전체 영역을 덮도록 너비, 높이, 포지션 및 앵커를 자동으로 조정합니다. 이 영역은 부모 영역 밖으로 나올 수 있습니다.
    - **Aspect Ratio**
        > - 적용할 종횡비(너비 / 높이)
    - **적용 예**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/aspectratiofitter.png)


　

- **SCROLL RECT**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/script-ScrollRect.html*
    - 레이아웃 그룹 내 컨텐츠를 스크롤 할 때 사용.
    - 사실... 꼭 레이아웃 그룹일 필요는 없으며 스크롤 가능한 UI 컨트롤이면 상관없다.
    - ***3장 '컨트롤 배우기'*** 에서 좀 더 복잡한 예를 살펴볼 예정.
    - 닥치고 예제
        > - 1\) 씬에 Canvas 추가.
        > - 2\) Canvas 하위로 빈 게임 오브젝트 추가하고,
        > - 3\) 이 오브젝트 이름을 "ScrollRectArea"로 변경.
        > - 4\) "ScrollRectArea"의 Width 값을 300으로 설정.
        > - 5\) 이 오브젝트에 Scroll Rect 컴포넌트 추가.
        > - 6\) 이 오브젝트 하위에 빈 게임 오브젝트 추가하고,
        > - 7\) 이름을 "Content"로 변경
        > - 8\) "Content"의 Width를 1000으로 설정.
        > - 9\) "Content" 게임 오브젝트를 선택한 후 Horizontal Layout Group 컴포넌트를 추가.
        > - 10\) "Content" 하위에 Image 컴포넌트를 몇 개 추가.
        > - 11\) "ScrollRectArea" 게임 오브젝트에 바인딩 되어있는 Scroll Rect 컴포넌트의 Content 속성으로 "Content" 게임 오브젝트를 할당합니다.
    - **Options**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/scrollrect.png)
    - **Content**
        > - Scroll Rect 안의 컨텐츠를 포함하는 Rect Transform을 지정.
    - **Horizontal / Vertical**
        > - 컨텐츠 영역의 스크롤 방향.
    - **Movement Type**
        > - 스크롤 움직임 스타일을 지정한다.
        > - **Unrestricted**: 제약 없이 움직인다. 심지어 화면이 스크롤 영역을 벗어나도 움직일 수 있다.
        > - **Elastic**: 영역을 벗어난 경우 튕겨서 제자리로 돌아옴. Elasticity 값을 변경하여 탄성 조절 가능.
        > - **Clamped**: 스크롤 영역 안에서 고정된 움직임을 보임. 영역을 벗어나면 바로 멈춤.
    - **Inertia**
        > - 스크롤 움직임에 관성 물리법칙을 적용할지 말지.
        > - Deceleration Rate 값으로 감속량 조절 가능.
    - **Scroll Sensitivity**
        > - 사용자 스크롤 액션에 대한 스크롤 감도 조정.
    - **Viewport**
        > - 표시하고자 하는 콘텐츠가 보여질 곳.
        > - 컨텐츠의 부모 뷰포트 Rect Transform.
    - **Horizontal/Vertical Scrollbar**
        > - 가로/세로 스크롤바 UI 지정
        > - **Visibility**: 스크롤바를 계속 보이게 할지. 필요 없을 때 자동으로 스크롤바를 숨길지. 선택적으로 뷰포트도 확장할지 말지.
        > - **Spacing**: 스크롤바와 뷰포트 간의 공간.


　

- **MASK**
    - 하위 컴포넌트가 보여지는 영역을 지정한다.
    - 단독으로 사용했을 때는 아무 의미 없고 Image 등의 Graphic 컴포넌트와 함께 사용해서 마스킹 영역을 지정해야 한다.
    - 앞의 예제에서...
        > - "ScrollRectArea" 오브젝트에 Mask 컴포넌트와 Image 컴포넌트 추가.
        > - Image 컴포넌트 소스 이미지의 알파값으로 마스킹 됨.
        > - 소스 이미지가 없으면 RT 영역만 뚫림.
    - 아래 그림처럼 "ScrollRectArea" 영역만 보여짐
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/mask.png)
