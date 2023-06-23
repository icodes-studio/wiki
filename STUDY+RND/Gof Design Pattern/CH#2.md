## 소프트웨어 설계 및 디자인 패턴

- **소프트웨어 설계란 무엇인가?**
    - 소프트웨어를 어떻게 만들어낼지를 결정하는 작업으로 '여러 가능한 방법 중 어느 하나를 선택'하는 **결정(Decision)**을 내리는 것.
    - 정답이 정해져 있는 것이 아님.
    - 그렇다고 좋은 설계와 나쁜 설계가 구분되지 않는 것도 아님.

- **좋은 설계는 어떤 특성을 갖추고 있을까?**
    - 구체적인 목적이나 상황, 환경에 따라 달라질 수 있다.
    - 그럼에도 보편타당한 특성은 아래와 같음.
        > - 이해 용이성(Understandability)
        > - 수정 용이성(Modifiability or Flexibility)
        > - 관리 용이성(Maintainability)
        > - 재사용 용이성(Reusability)
        > - 테스트 용이성(Testability)
        > - 높은 안정성(Reliability)
        > - 원하는 목적을 정확히 만족(Correctness)
        > - 적은 자원 최대의 성능 - 효율성(Efficiency)
        > - 상호 운영성(Interoperability)
    - BUT, 이러한 특성들을 모두 만족시키는 설계는 사실상 불가능.
    - WHY, 서로 간에 Trade-off가 있거덩
        > - 효율성을 따지면 코드가 복잡해져 이해 용이성이 떨어짐.
        > - 수정 용이성도 떨어질 테고...
    - 결국 설계 과정도 What-Why-How 생각 모델에 따라 구체적인 목적이나 상황에 맞추어 위 특성들 중 가장 우선해야 할 것들을 선별하고 그에 따라 설계를 하는 것이 최적의 설계(Optimal Design)를 이끌어낼 수 있는 방법이라고 할 수 있다.

- **좋은 소프트웨어를 설계하기 위한 도구**
    - What-Why-How 생각 모델에 따라 지금까지 얘기한 대로...
    - 이 대전제를 기반으로 아래와 같은 도구들을 사용할 수 있다.
        > - 추상화(Abstraction)와 구체화(Refinement)
        > - 모듈화(Modularization)와 계층화(Hierarchy)
        > - 정보은닉(Information Hiding)과 변경의 국지화(Localization of Change)
        > - 방법론(Methodology, Method) 및 지침(Guideline)

- **추상화(Abstraction)와 구체화(Refinement)**
    - 추상화란 구체적이고 복잡한 사실을 간략화시키는 것을 의미함.
    - 구체화란 구체적이고 상세한 사실을 계속해서 추가해나가는 것.
    - What-Why-How 생각모델에서 추상화 레벨로 표현된 것으로 서로 다른 방향을 가리키는 수직선이라고 볼 수 있다.
    - 설계 시 특정 관점과 무관한 사실들은 간략화시켜 생각하는 것이 편리하다. 반면 개발은 구체화되어가는 중요한 과정이므로 추상화와 구체화를 적절히 적용하며 설계할 필요가 있다.

- **모듈화(Modularization)와 계층화(Hierarchy)**
    - 모듈화란 소프트웨어를 모듈 단위로 분할(Decomposition) 시키는 것.
    - 모듈이란 요구 사항을 만족시키기 위한 개별 구성 요소.
    - 모듈 단위로 분할해서 구분 지어 다루는 것은 좋은 소프트웨어 설계.
    - 이해하기도 쉽고, 필요에 따라 재사용하거나 수정하기도 편리하다.
    - 낱개로 흩어져있는 모듈들은 잘 상호 연관돼야 한다.
    - 관계가 너무 복잡해지면 이해하기 힘들어지고 유지보수 및 재사용하기 어려워진다. 모듈 간 상호연관관계는 관리 가능한 형태로 구성하는 것이 바람직하다.
    - 그래서 계층화가 중요한 거야!!!
    - 계층화란 비슷한 목적의 모듈들을 같은 계층에 배치하고, 계층과 계층 간은 트리와 유사한 형태로 사용관계를 구성해 주는 것.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/module.png)
    - 단순히 so 파일이나 dll 바이너리로 빼내는 걸 의미하는 게 아냐!
    - 탑다운 형태의 디펜던시에 주목하자.

- **정보은닉(Information Hiding)과 변경의 국지화(Localization of Change)**
    - 정보은닉이란 상세한 결정 사항을 모듈 내부에 숨기고 외부에는 해당 모듈을 사용할 수 있는 인터페이스(Interface)만을 공개하는 것.
    - 모듈 내부의 결정 사항 변동에 따라 모듈 외부에서 그 영향을 받지 않게 하기 위한 방법이다. - 물론 인터페이스를 잘 설계해야지!
    - 정보은닉을 잘 적용하게 되면 요구 사항의 추가나 변동에 따라 소프트웨어의 변경이 필요할 경우 그 수정 범위를 특정 모듈 내부로 한정시킬 수 있게 된다.
    - 그 수정 범위가 한정되도록 만들어주는 것을 변경의 국지화라고 함.
    - 이를 통해 소프트웨어는 수정이나 관리 및 재사용이 쉬워진다.
    - 아래 그림은 변경의 국지화가 깨뜨려진 예
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/bad.png)
    - 아래 그림은 변경의 국지화가 잘 된 예
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/good.png)

- **방법론(Methodology, Method) 및 지침(Guideline)**
    - 소프트웨어의 생성부터 소멸까지 전 과정에서 수행해야 하는 일처리 방법이나 절차 등을 정리해놓은 것 - 문서화
    - 개개인의 부족함을 메꿀 수 있는 좋은 도구가 될 수 있다.
    - 정형화된 방법론이나 지침은 소프트웨어 개발을 표준화 시킨다.
        > - 코딩 컨벤션
        > - 인터페이스 노출 규칙
        > - DB 접근 방식, UI 구성 방식
        > - 라이브러리 및 외부 SDK 적용 분야에 대한 명세
        > - 각 개발 부서 간 RNR 정리
        > - etc...

- **디자인 패턴의 정의 및 유용성**
    - 설계? 경험만큼 확실한 것은 없다.
    - BUT, 모든 사람들이 충분한 경험을 갖고 있지는 않다.
    - 이런 사람들이 전문가 못지않게 소프트웨어 설계를 잘 하는 방법은?
    - 여러가지 설계 사례나 시니어 전문가들의 경험에 대한 지식과 노하우를 분석하고 공유하는 것.
    - 하지만 이런 것들은 너무 구체적이거나 너무 일반화된 것이어서 새로운 구체적인 문제에 적용하기 위해서는 또 다른 지식이나 노하우가 필요하기 때문에 한계가 있다.
    - 너무 일반적이지도, 또 너무 구체적이지도 않은 형태로 소프트웨어 설계를 위한 지식이나 노하우를 공유할 수 있는 방법을 위해 고안된 것이 바로...
    - ***Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides가 쓴 "Design Patterns: Elements of Reusable Object-Oriented Software"(Addison Wesley, 1995)***
    - 라는 책에서 제시한 디자인 패턴이다.
  

- **디자인 패턴 이해와 활용을 위한 이 책의 접근 방법**
    - 하지만 원서는 이해하는데 어렵고, 이해했어도 실제 활용을 잘 못해.
    - WHY?
    - 암기식으로 각 패턴이 어떤 구조, 어떤 형태로 동작하는지에만 집중.
    - 읽는 과정에서 스스로 어떻게 설계를 할지 전혀 고민해 보지 않는다.
    - 결국, 책을 읽을 때에는 이해를 한 듯하면서도 책을 덮고 문제를 해결하려 하면 기존에 하던 방식대로만 설계를 하고 만다.
    - **디자인 패턴에서 제시하는 구조 형태로 설계를 끼워 맞추려 한다.**
        > - 내가 디자인 패턴을 싫어하고 멀리했었던 이유. -_-;
        > - 각 패턴은 장단점을 가진다.
        > - 문제의 구체적인 목적이나 상황을 고려해야 하는데 말야...
    - 패턴이 제시하는 설계가 실제로 어떻게 구현되는지 이해하지 못함.
        > - 원서에도 예시 코드가 있지만 완전한 코드가 아니다.
        > - 돌려볼 수 없음.
    - 그래서 이 책에서는...
        > - 각 챕터 제목이 디자인 패턴의 이름이 아냐
        > - 무슨 문제를 해결하기 위한 목적으로 디자인 패턴이 고안된 것인지에 더 집중할 수 있도록 **해결해야 할 문제의 유형**을 챕터 제목으로 달았다.
        > - 내가 이 책을 사고 보았던 이유
        > - 소프트웨어 설계를 위한 출발점이 무엇인지 제시.
        > - 스스로 고민해 볼 수 있게 많은 질문을 던지고 있다.
        > - 설계를 이끌어내는 과정을 익힐 수 있다.
        > - 문제해결을 위한 설계를 이끌어낼 때 우선 일반적인 개발자들이 쉽게 떠올리는 설계를 먼저 언급하고 그 설계의 문제가 무엇이고 이를 극복하기 위한 방법은 없는지 반복적으로 질문하고 고민하게 하여 설계를 이끌어내는 과정과 디자인 패턴이 어떤 고민의 과정을 거쳐 유도된 것인지를 보여준다.
        > - 각 패턴의 장점뿐 아니라 단점도 충분히 언급.
        > - 맹목적으로 활용하지 않도록
        > - 상황에 맞는 패턴 적용 및 새로운 패턴 설계 능력 키움.
        > - 실행 가능한 샘플 소스코드 제공

　

***"이 모든 것들은 What-Why-How 생각 모델에 기반한 것이다. 즉 각각의 디자인 패턴이 무엇(What)을 위한 것인지를 먼저 파악하고, 그것을 달성하기 위해서는 어떤(How) 방식의 설계를 해야 하는지, 또 왜(Why) 그렇게 해야 하는지를 반복적으로 생각해보는 방식을 통해 디자인 패턴에 대한 이해를 증진시키고, 쉽게 활용할 수 있게 책의 내용을 구성한 것이다."***