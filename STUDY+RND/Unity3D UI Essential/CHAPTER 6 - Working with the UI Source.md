# CHAPTER 6 - UI 소스 다루기
    ● Event System에 대해
    ● 이벤트와 델리게이트
    ● 다양한 예제
    ● 오픈소스의 정의와 활용 방법


　

- **Event System**
    - *https://docs.unity3d.com/2023.2/Documentation/Manual/EventSystem.html*
    - The primary roles of the Event System are as follows:
        > - Manage which GameObject is considered selected
        > - Manage which Input Module is in use
        > - Manage Raycasting (if required)
        > - Updating all Input Modules as required


　

- **Event System Loop**
    - 이벤트 시스템 루프
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/eventsystemloop.png)
        > - **Event System:** EventSystem은 씬에 존재하는 모든 활성화된 입력 시스템을 제대로 가지고 있는지 검사한다.
        > - **Scanning:** 입력 시스템으로부터 현재 상태를 가져온다.
        > - **Raycasting:** 레이캐스팅 시스템을 작동 시킨다. 이를 통해 사용자가 입력한 값에 대해 어떤 게임 오브젝트가 반응하는지를 결정한다. 그리고 이에 해당하는 게임 오브젝트에게 알려 관련 이벤트가 발생하게 된다.
        > - **Resulting:** EventSystem에 대한 프로세싱이 끝나면, 렌더링 단계로 넘어가 캔버스를 씬에 그린다.


　

- **Raycasters**
    - EventSystem은 Raycast를 검사하는 용도로 사용된다.
    - Raycasters are used for figuring out what the pointer is over.
    - There are 3 provided Raycasters that exist by default:
        > - Graphic Raycaster - Used for UI elements
        > - Physics 2D Raycaster - Used for 2D physics elements
        > - Physics Raycaster - Used for 3D physics elements


　

　

# # 이벤트 다루기
    ● 새로운 UnityEvent 로직
    ● 델리게이트 활용


　

- **이벤트가 발생하면 콘솔에 내용 출력하기**
    - SimpleEvent.cs
        ```
        ...
        ```
