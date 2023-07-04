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
    - Raycasters are used for figuring out what the pointer is over.
    - There are 3 provided Raycasters that exist by default:
        > - Graphic Raycaster - Used for UI elements
        > - Physics 2D Raycaster - Used for 2D physics elements
        > - Physics Raycaster - Used for 3D physics elements


　

　

# # 이벤트 다루기
    ● 새로운 UnityEvent 로직
    ● 델리게이트 활용


　

- **UnityEvent 살펴보기**
    - SimpleEvent.cs 이름으로 스크립트 파일을 준비한다.
        ```
        using UnityEngine;
        using UnityEngine.Events;

        public class SimpleEvent : MonoBehaviour
        {
            public UnityEvent unityEvent = new ();
            private void Awake() => unityEvent?.AddListener(OnEventDelegate);
            private void Start() => unityEvent?.Invoke();
            private void OnEventDelegate() => Debug.Log(nameof(OnEventDelegate));
            public void RunMeFromTheInspector() => Debug.Log(nameof(RunMeFromTheInspector));
        }
        ```
    - 빈 게임 오브젝트 하나 만들고 위 스크립트를 바인딩하면 인스펙터에 아래와 같이 표시된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/simple-event1.png)
    - 위에서 만든 게임 오브젝트와 ***RunMeFromTheInspector*** 메소드를 아래 그림처럼 등록하면,
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/simple-event2.png)
    - 코드에서 등록한 핸들러와 인스펙터에서 등록한 핸들러 두 메서드가 호출되는 모습을 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/event-console.png)


　

- **매개변수 사용하기**
    - 먼저 원하는 매개변수 패턴을 사용하여 새로운 클래스 타입을 UnityEvent\<T\> 클래스를 상속받아 정의
        ```
        using System;
        using UnityEngine.Events;

        [Serializable]
        public class StringUnityEvent : UnityEvent<string>
        {
        }
        ```
    - 위 타입을 사용하는 컴포넌트 스크립트 작성
        ```
        using UnityEngine;

        public class SimpleStringEvent : MonoBehaviour
        {
            public StringUnityEvent stringEvent = new ();
            private void Awake() => stringEvent?.AddListener(OnEventDelegate);
            private void Start() => stringEvent?.Invoke("Hello World");
            private void OnEventDelegate(string arg) => Debug.Log($"{nameof(OnEventDelegate)} - {arg}");
            public void RunMeFromTheInspector(string arg) => Debug.Log($"{nameof(RunMeFromTheInspector)} - {arg}");
        }
        ```
    - 이벤트 델리게이트를 아래 그림과 같이 등록.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stringevent1.png)
    - 코드에서 등록한 핸들러와 인스펙터에서 등록한 핸들러가 각기 다른 스트링 인자를 받아 호출되는 모습을 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stringevent2.png)


　
