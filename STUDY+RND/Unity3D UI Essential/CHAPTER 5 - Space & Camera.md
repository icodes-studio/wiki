# CHAPTER 5 - 화면공간, 월드공간, 카메라
    ● 지금까지 살펴본 플랫한 2D UI를 3D 공간으로 확장해보자.
    ● 데드 스페이스 시리즈의 3D 인벤토리는 좋은 예가 될 것이다.
    
![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/deadspace2-010.jpg)


　

- **Screen Space - Overlay**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/class-Canvas.html*
    - 카메라에 독립적으로 UI를 오버레이 하는 형식으로 작동.
    - 해상도 변경 시 스크린에 일치하도록 캔버스가 자동으로 크기 변경됨.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-overlay.png)
    - Pixel Perfect
        > - UI 엘리먼트에 대해 [***픽셀 퍼펙트***](https://docs.unity3d.com/ScriptReference/Canvas-pixelPerfect.html)렌더링을 수행.
        > - 퍼포먼스 부분에서 손해를 보는 부분이 있다.
    - Sort Order
        > - 여러개 Overlay 캔버스가 있는 경우, 그리는 순서
        > - 낮은 순서의 캔버스는 아래에 그려진다.


　

- **Screen Space - Camera**
    - 캔버스가 그려질 카메라를 선택하여 UI를 렌더링 한다.
    - 3D 원근법으로 UI를 그릴 때 유리하다.
    - 해상도 변경 또는 카메라의 frustrum을 변경한 경우, 캔버스도 자동으로 일치하도록 크기 변경됨.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-camera.png)
    - Render Camera
        > - 캔버스가 그려질 카메라.
    - Plane Distance
        > - 캔버스가 카메라로부터 떨어진 거리.
    - Sorting Layer
        > - 캔버스가 다른 캔버스 또는 스프라이트 렌더링 컴포넌트와 함께 씬에 사용되는 경우(eg. Sprite Renderer), 캔버스가 어떤 스프라이트 소팅 레이어에 렌더링 될 것인지 설정.
    - Order in Layer
        > - 선택된 소팅 레이어에서 캔버스가 그려지는 순서.
        > - 낮은 순서의 캔버스는 아래에 그려진다.


　

- **World Space**
    - 캔버스가 씬에서 오브젝트처럼 동작한다.
    - UI 요소는 오브젝트 배치에 따라 앞면 혹은 뒷면에 그려짐.
    - 3D 월드에 속하는 인터페이스 UI의 일부로써 유용하다.
    - AKA, ***"Diegetic Interface"***
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/canvas-worldspace.png)
    - Event Camera
        > - UI 이벤트를 처리하는 데 사용할 카메라
        > - 즉, EventSystem이 어떤 카메라를 사용할지 결정.
        > - 지정하지 않으면 Main Camera가 디폴트로 사용.


　

- **렌더링 카메라**
    - **Screen Space - Camera** 모드는 UI를 렌더링 하는 카메라가 필요하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/render-camera.png)
    - Main Camera 같은 다른 카메라와는 완전히 독립적이다.
    - UI의 렌더링 설정값을 결정한다.
- **Camera Component**
    - Options
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/camera-options.png)
- **Clear flags**
    - 카메라 렌더링 패스 중 어느 부분을 클리어할지 결정.
    - 결국 배경 빈 공간은 이 Clear flags에 따라 초기화된다.
    - Skybox
        > - 배경을 Skybox로 클리어한다.
    - Solid Color
        > - 배경을 지정한 단색으로 클리어한다.
    - **Depth only**
        > - 오브젝트의 Z 깊이를 무시하고 카메라 Depth 렌더링 순서에 따라서 그린다.
        > - 이전 화면은 지우지 않고 그 위에 그린다.
        > - 예를 들어 벽을 렌더링 하는 카메라와 사람을 렌더링 하는 카메라가 별도로 있을 때, 벽 안에 사람이 있다 하더라도 사람 렌더링 카메라의 Depth only 옵션이 켜지면 사람이 보인다는 말이다. **투시기능**을 구현할 때 유용하겠다.
        > - 아래 그림에서 맨 왼쪽 큐브는 별도 카메라에서 렌더링 되며 Depth가 작기 때문에 뒤에 배치된다.
        > - 심지어 UI도 거리무시, 다른 카메라의 UI 밑에 깔리고 있다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/cube.gif)
    - **Don't Clear**
        > - 배경을 갱신 않고 이전 화면 위에 그린다.
        > - 다른 카메라의 오브젝트 Z 깊이는 유지된다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/cube2.gif)
- **Culling Mask**
    - 카메라 시야 안에 어떤 엘리먼트를 그릴 것인지 설정한다.
    - 기본 값은 UI만 그리도록 설정되어 있지만...
    - 경우에 따라 3D 오브젝트를 UI 앞에 그릴 필요도 있다.
- **Projection**
    - Perspective
        > - 3D 원근법 카메라
        > - UI가 원근감 있게 표현된다.
    - Orthographic
        > - 2D 평면 카메라
        > - Screen Space - Overlay 뷰와 동일한 모습.
- **Field of View (FOV)**
    - Projection 옵션이 Perspective 일 때 활성화.
    - 카메라의 화각을 결정한다. 보통 60 권장
    - 화각이 넓을수록 면은 더 휘어지게 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Dolly-Zoom-Animation.gif)
- **Physical Camera**
    - *https://docs.unity3d.com/2021.1/Documentation/Manual/PhysicalCameras.html*
- **Clipping Planes**
    - 시작 평면과 끝 평면을 정해놓고 그 안의 것만 렌더링.
    - 카메라가 표현하는 최소(Near), 최대(Far) 거리 포인트 지정
- **Viewport Rect**
    - 카메라의 뷰포인트 크기를 조정한다.
    - 화면의 왼쪽, 아래쪽이 0, 오른쪽, 위쪽이 1.
    - X, Y는 시작 지점, W는 너비, H는 높이.
    - 디폴트는 X=0, Y=0, W=1, H=1로 되어 있어 화면에 꽉 참.
    - X=0, W=0.5, Y=0, H=0.5로 바꿔보면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/viewport-1.jpg)
    - X=0.5, W=0.5, Y=0.5, H=0.5로 바꿔보면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/viewport-2.jpg)
    - 응용하면 VR 컨텐츠를 만들거나
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/viewport-3.jpg)
    - 미니맵을 만들거나 할 수 있으려나?
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/minimap.png)
- **Depth**
    - 카메라 드로우 순서로 값이 작은 카메라를 먼저 그림.
    - 즉, 값이 큰 카메라는 값이 작은 카메라 위에 그려진다.
    - 다만, 카메라 Clear flags 옵션을 Don't Clear로 지정하면 Z 깊이에 따라 앞뒤가 결정된다.
- **Rendering Path**
    - *https://docs.unity3d.com/2021.1/Documentation/Manual/RenderingPaths.html*
- **Target Texture**
    - 카메라 화면을 Render Texture에 실시간으로 그린다.
    - Render Texture가 지정되면 화면에는 그려지지 않는다.
    - 복잡하거나 렌더링 비용이 큰 컨텐츠를 Render Texture에 그려놓고 활용하는 사례가 있다.
- **Occlusion Culling**
    - 한 오브젝트가 다른 오브젝트에 의해 가려져서 카메라에 보이지 않을 때 오브젝트의 렌더링을 비활성화하는 최적화 기능.    
- **HDR**
    - *https://docs.unity3d.com/2021.1/Documentation/Manual/HDR.html*
    - **H**igh **D**ynamic **R**ange 렌더링을 켜거나 끈다.
- **MSAA**
    - *https://docs.unity3d.com/kr/2019.4/Manual/PostProcessing-Antialiasing.html*
    - [*https://vallista.tistory.com*](https://vallista.tistory.com/entry/Unity3D-AntiAliasing-Anisotropic-Filtering-%EC%95%88%ED%8B%B0-%EC%97%90%EC%9D%BC%EB%A6%AC%EC%96%B4%EC%8B%B1-%EC%9D%B4%EB%B0%A9%EC%84%B1-%ED%95%84%ED%84%B0%EB%A7%81-%EC%A0%81%EC%9A%A9)
    - 메시 테두리에 **M**ulti **S**ample **A**nti **A**liasing 기능을 켜거나 끔.
    - 기능을 킨 경우 Graphics Settings 설정에 따른다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/aacomparison.png)
- **Allow Dynamic Resolution**
    - Dynamic Resolution 렌더링 기능을 켜거나 끈다.
    - *https://docs.unity3d.com/2021.1/Documentation/Manual/DynamicResolution.html*
- **Target Display**
    - Defines which external device to render to. Between 1 & 8.
    - A camera has up to 8 target display settings. The camera can be controlled to render to one of up to 8 monitors. This is supported only on PC, Mac and Linux. In Game View the chosen display in the Camera Inspector will be shown.


　

- **이벤트 카메라**
    - **World Space** 모드는 UI 이벤트를 처리하는데 사용할 카메라 필요.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/eventcamera.png)
    - 즉, 레이캐스팅 입력을 받기 위해 EventSystem이 어떤 카메라를 사용할지 결정해야 한다.
    - Event Camera가 지정되지 않으면 디폴트로 Main Camera가 사용됨.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/main-camera.png)


　

　

# # Screen Space 예제

　

- **Camera FOV 테스트**
    - 캔버스를 생성하고 Render Mode를 Screen Space - Camera로 설정.
    - 카메라를 생성하고 이름을 "UICamera"로 변경 후 속성을...
        > - Layer : UI
        > - Clear Flags : Don't Clear
        > - Field of View : 1
    - Canvas의 Render Camera를 "UICamera"로 설정.
    - Image를 추가하고 그 자식으로 Button 추가
    - 각 엘리먼트 트랜스폼의 Pos Z 값을 카메라에 근접 for TEST
        > - Image는 0
        > - Button은 -10
        > - Text는 -20
    - 게임 뷰로 전환하고 UICamera의 FOV 값을 바꿔서 넣어보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FOV.png)
    - Text는 FOV 160에서 사라진다. Near Plane을 지나쳐 그려지지 않음.
    - **이렇게 Z 깊이를 이용해 다양한 연출이 가능하다.**
    - 자, 이제 회전을 통한 원근감을 테스트해보자.
    - 각 UI 엘리먼트의 Pos Z 값 0으로 다시 초기화.
    - Image의 Rotation Y 값을 10으로 변경.
    - 게임 뷰로 전환하고 UICamera의 FOV 값을 바꿔서 넣어보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FOV2.png)
    - UI가 원근감 있게 표현되고 있다.


　

　

# # World Space 예제
    ● Screen Space - Camera 모드는 UI를 3D 공간상에 배치한다.
    ● 그리하여 3D 원근감과 각종 공간 효과를 사용할 수 있게 한다.
    ● 하지만 카메라로부터 일정 거리 떨어진 곳에 UI를 표현하는 방식.
    ● 데드 스페이스 시리즈의 3D 인벤토리 같은 것은 이런 방식으로 구현할 수 없고 World Space 모드를 사용하여 캔버스가 씬에서 오브젝트처럼 동작하게 해야 한다.
    ● 책의 예제는 배보다 배꼽이 더 커 보인다.
    ● Unity에서 제공하는 Standard Assets Example Project를 활용해서 하나 만들어보자.

- **Standard Assets Example Project 활용**
    - Standard Assets Example Project를 유니티에서 오픈.
    - /Assets/SampleScenes/Scenes/Car 씬 오픈.
    - 하이어러키 루트에 Canvas 추가
    - Canvas의 Render Mode를 World Space로 변경
    - Canvas의 스케일을 (0.1, 0.1, 0.1) 변경
    - Canvas의 위치를 (0, 4, 10) 변경
    - Button UI 추가
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/world-space-game.gif)
    - 끝!
