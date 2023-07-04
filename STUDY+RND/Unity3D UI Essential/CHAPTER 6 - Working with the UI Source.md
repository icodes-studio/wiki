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
    ● UnityEvent 활용
    ● 내장 이벤트 인터페이스 활용
    ● 사용자 정의 이벤트 활용


　

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


　

- **UnityEvent에 매개변수 사용하기**
    - 먼저 원하는 매개변수 패턴을 사용하여 새로운 클래스 타입을 ***UnityEvent\<T\>*** 클래스를 상속받아 정의
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
    - 이벤트 핸들러를 아래 그림과 같이 등록.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stringevent1.png)
    - 코드에서 등록한 핸들러와 인스펙터에서 등록한 핸들러가 각기 다른 스트링 인자를 받아 호출되는 모습을 볼 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stringevent2.png)


　

- **내장 이벤트 인터페이스**
    - ***포인터 이벤트***
        > - ***IPointerEnterHandler:*** 포인터(커서, 마우스 등)가 UI 오브젝트의 Rect Transform 영역에 들어갈 때 발생.
        > - ***IPointerExitHandler:*** 포인터가 UI 오브젝트의 Rect Transform 영역에서 나올 때 발생.
        > - ***IPointerDownHandler:*** 선택 가능한 UI 컨트롤(eg. 버튼)에 키 다운 입력이 들어오면 발생.
        > - ***IPointerUpHandler:*** 선택 가능한 UI 컨트롤에 키 업 입력이 들어오면 발생.
        > - ***IPointerClickHandler:*** 선택 가능한 UI 컨트롤을 클릭하면 발생.
    - ***드래그 핸들러 이벤트***
        > - ***IInitializePotentialDragHandler:*** 드래그가 시작된 지점을 감지
        > - ***IBeginDragHandler:*** 드래그 액션이 시작될 때 발생
        > - ***IDragHandler:*** UI 컴포넌트를 드래그(eg. 누르고 이동)할 때 발생
        > - ***IEndDragHandler:*** UI 컴포넌트에 대해 드래그가 끝날 때 발생.
        > - ***IDropHandler:*** IEndDragHandler와 같은 순간에 발생하지만 드래그 데이터를 포함하지는 않는다.
    - ***그 밖의 핸들러 이벤트***
        > - ***IScrollHandler:*** 입력 장치에서 스크롤이 감지될 때(eg. 마우스 휠) 발생.
        > - ***IUpdateSelectedHandler:*** 선택된 UI 컨트롤의 상태가 업데이트 되거나 변화할 때 발생.
        > - ***ISelectHandler:*** UI 컨트롤이 선택되거나 포커스를 얻을 때 발생.
        > - ***IDeselectHandler:*** UI 컨트롤의 선택이 해제되거나 포커스를 잃을 때 발생.
        > - ***IMoveHandler:*** UI 컨트롤이 움직이라는 입력을 받았을 때 발생
        > - ***ISubmitHandler:*** Submit 입력을 받았을 때(default. `Enter`키) 발생
        > - ***ICancelHandler:*** Cancel 입력을 받았을 때(default. `Esc`키) 발생


　

- **내장 이벤트 인터페이스 사용하기**
    - UI 엘리먼트에 마우스를 가져갔을 때 툴팁을 띄우는 간단한 스크립트를 생각해 보자.
        ```
        using UnityEngine;
        using UnityEngine.EventSystems;

        public class Tooltip : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler
        {
            private bool displayed = false;
            public RectTransform item;
            private Vector3 offset;

            private void Start()
            {
                offset = new Vector3(0, item.sizeDelta.y, 0);
                item.gameObject.SetActive(displayed);
            }

            public void OnPointerEnter(PointerEventData eventData)
            {
                displayed = true;
                item.transform.position = transform.position + offset;
                item.gameObject.SetActive(displayed);
            }

            public void OnPointerExit(PointerEventData eventData)
            {
                displayed = false;
                item.gameObject.SetActive(displayed);
            }
        }
        ```
    - 코드 보면 대충 사용법은 알겠지?
        > - 하얀색 UI 위로 마우스를 가져가면 툴팁이 뜨고, 치우면 사라지도록 만들어보자!
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tooltip.png)
    - 이 예제에서 사용한 방식은 가장 기본적인 것으로서 `Screen Space - Overlay` 캔버스에서만 작동한다.
    - `Screen Space - Camera` 또는 `World Space` 캔버스에서 사용하고 싶다면 마우스 위치를 변환해야 한다.
    - 더 자세한 내용은 ***UIWindowBase*** 예제를 확인하자.


　

- **사용자 정의 이벤트와 핸들러 만들기**
    - 이벤트를 새로 만들려면 다음과 같은 정보를 정의해야 한다.
        > - 사용자 정의 이벤트 데이터 구조 (BaseEventData에서 확장)
        > - 사용자 정의 이벤트 인터페이스 (IEventSystemHandler에서 확장)
        > - Execute 함수를 포함한 정적 컨테이너 클래스
        > - [옵션] 이벤트를 처리하고 실행하기 위한 입력 모듈(BaseInputModule에서 확장)
        > - 인터페이스를 구현하는 클래스나 게임 오브젝트.
    - **AlarmSystem.cs**
        ```
        using UnityEngine;
        using UnityEngine.EventSystems;

        public class AlarmEventData : BaseEventData
        {
            public Vector3 data;
            public AlarmEventData(EventSystem system, Vector3 data) : base(system)
            {
                this.data = data;
            }
        }

        public interface IAlarmHandler : IEventSystemHandler
        {
            void OnAlarmTrigger(AlarmEventData data);
        }

        public static class MyAlarmTriggerEvents
        {
            private static void Execute(IAlarmHandler handler, BaseEventData data)
            {
                handler?.OnAlarmTrigger(ExecuteEvents.ValidateEventData<AlarmEventData>(data));
            }

            public static ExecuteEvents.EventFunction<IAlarmHandler> AlaramEventHandler
            {
                get { return Execute; }
            }
        }
        ```
    - **AlarmScannerModule.cs**
        ```
        using UnityEngine;
        using UnityEngine.EventSystems;

        public class AlarmScannerModule : BaseInputModule
        {
            public GameObject[] targets;
            private Vector3 triggeredCameraLocation;
            private bool triggered;

            // 활성화된 입력 모듈에서 매 틱마다 실행
            public override void Process()
            {
                if (targets == null || targets.Length == 0)
                    return;

                if (triggered == true)
                    return;

                // TODO: 트리거된 알람을 위한 로직을 여기에 추가할 것
                // TODO: 지금은 일단 그냥 리턴
                triggeredCameraLocation = Vector3.zero;

                if (triggeredCameraLocation != Vector3.zero)
                {
                    triggered = true;
                    var data = new AlarmEventData(eventSystem, triggeredCameraLocation);
                    foreach (var target in targets)
                        ExecuteEvents.Execute(target, data, MyAlarmTriggerEvents.AlaramEventHandler);
                }
            }
        }
        ```


　

　

# # Roll a Ball 예제
    ● Unity 튜토리얼 사이트에서 제공하는 Roll a Ball 예제 활용
    ● 경고판을 밟으면 주위의 안드로이드 적들이 달려드는 기능 구현

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/rollaball.png)

*https://learn.unity.com/project/roll-a-ball-1*

*https://github.com/davidgaroro/unity-3d-roll-a-ball*


　

- ****
    - ...