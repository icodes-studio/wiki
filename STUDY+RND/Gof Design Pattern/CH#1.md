## 소프트웨어 개발이란?

***"원하는 목적(Goal)을 달성하기 위해 기준이 되는 개념이나 철학(Paradigm)을 바탕으로 특정한 과정(Process)을 거쳐 소프트웨어적인 해결책(Solution)을 만들어내는 것"***


　

## 소프트웨어 개발 개념 또는 철학에는 어떤 것들이 있을까?

- **구조적 프로그래밍(Structured Programming)**
    - 기능(Function or Process) 위주
    - 소프트웨어를 기능 위주의 관점으로 바라보면서 원하는 기능을 하향식으로 세분화, 구체화 시켜 해결책을 만듬.
    - 하향식(TopDown), 분할정복(Divide & Conquer) 접근
    - 그래서 OOP보다 해결책을 좀 더 빨리 만들어낸다.
    - 해결책이 트리구조를 이루므로 OOP보다 구조가 간단하다.
    - 그래서 서브시스템에 대한 정의가 쉽다.
    - 개발 이후 수정에 대한 유지보수가 어렵다.
    - 코드나 모듈 재사용이 OOP에 비해 어렵다.
    - 한 부분의 변경에 의해 영향받는 범위를 구분짓기 어려움.
    - 기능 위주이므로 실세계와의 개념적 대응이 힘듬.

- **객체지향 프로그래밍(Object-Oriented Programming)**
    - 데이터(Data) 위주
    - 소프트웨어를 데이터 위주의 관점으로 바라보면서 구체적인 데이터들 간의 상호 관계를 정의함으로써 원하는 목적을 달성할 수 있는 해결책을 만들어내는 것.
    - 상향식(BottomUp), 상호관계 정의
    - 사용할 데이터와 조작할 인터페이스 객체를 먼저 정의하고
    - 객체들 간을 상호관련시킴으로써 해결책을 만드는 2단계.
    - 그래서 복잡한 네트워크 구조로 해결책이 만들어진다.
    - 그래서 서브시스템에 대한 정의가 어렵다.
    - 2단계 구현 방식이기 때문에 설계를 강요한다.
    - 개발 이후 수정에 대한 유지보수가 쉽다.
    - 코드나 모듈 재사용이 수월하다.
    잘 변화하지 않는 데이터를 기준으로 객체를 정의했기 때문에 객체를 단위로 재사용이 이루어질 수 있고 클래스 상속을 통해 기존 클래스를 재사용하여 확장하면서도 이전 프로그램을 수정할 필요가 없기 때문.
    - 객체를 통한 실세계와의 개념적 대응이 비교적 쉽다.


　

## 소프트웨어 개발 과정은 무엇이며 어떻게 구성되어 있을까?

- 일반적인 소프트웨어 개발 과정

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/waterfall.png)

- **요구사항 명세 단계**
    - 소프트웨어 개발의 목적을 명확히 이해하고 공유.
    - 구체적인 요구사항에 대해 논리적이고 합리적인지 검토.
    - 필요시 요구 사항을 조율하거나 조정.
    - eg. 기획서 작성 및 리뷰

- **요구사항 분석 단계**
    - 기능(Function), 행위(Behavior), 데이터(Data) 측면에서 요구사항을 체계적이고 구체적으로 분석.
    - 소프트웨어가 실행될 환경에 대해서도 분석, 검토 수행.
    - eg. 기술협의

- **기본설계 단계**
    - 개발할 소프트웨어의 전반적인 아키텍쳐 구상.
    - 구성 요소 간 프로토콜 정의 및 사용자 인터페이스 결정.
    - 데이터베이스를 사용할 경우 데이터베이스 스키마를 설계.

- **상세설계 단계**
    - 프로그램 구현을 위한 구체적인 자료구조와 알고리즘 결정.

- **구현 단계**
    - 상세설계된 결과물을 프로그래밍 언어를 사용해서 코딩.

- **테스팅 단계**
    - 단위 테스트: 구현된 개별 모듈이 잘 작동하는지.
    - 통합 테스트: 각 모듈들을 통합해서 제대로 동작하는지.
    - 적합성 테스트: 요구사항과 정확히 일치하게 동작하는지.
    - 시스템 테스트: 실제 실행 환경을 대상으로 장애복구나 보안, 안정성, 성능 등에 대한 점검을 수행.

- **유지보수 단계**
    - 추가, 변경 요구 사항을 검토하고 반영.
    - 장애나 오류발생 시 이에 대한 대처 및 복구.
    - 지속적인 모니터링 및 시스템 운영 등을 수행.

　

　

***"그렇다면 소프트웨어를 개발하는 데 있어 왜 이렇게 개념이나 철학(Paradigm)을 따지고, 개발과정(Process)을 언급하는 것일까? 그것은 바로 원하는 목적을 수행할 수 있는 수많은 해결책(Solution) 중에서 최적의 해결책(Optimal Solution)을 찾아내기 위해서다."***

‌　

　

## WHAT-WHY-HOW 생각모델

- **최적의 해결책이란 무엇인가?**
    - 언제, 어디서나 가장 적합한 해결책을 가리키는 최선의 해결책(The Best Solution) 과는 다른 것.
    - 주어진 환경이나 상황에 가장 적합한 해결책을 말함.
    - 주어진 환경이나 상황이 바뀌면 최적의 해결책도 바뀐다.
    - 최소의 비용으로 최대의 효과를 보기 위해서임.
    - "Hello World!" 문자열 하나 출력하는 데에도 많은 방법들이 존재.
        > - 문자열을 상수 값으로 정의하는 방법.
        > - 프로그램 실행인자로 문자열을 받아 출력하는 방법.
        > - 표준입력을 통해 문자열을 입력받아 출력하는 방법.
        > - WWW를 통해 문자열을 받아 출력하는 방법.
        > - etc...

- **어떻게 최적의 해결책을 만들어낼 수 있을까?**
    - 소프트웨어 개발은 추상화(Abstraction) 레벨을 구체화시켜나가면서 무엇을(What) 어떻게(How) 할지를 반복해나가는 과정.
        > - What-How Thinking Model은 Well-known model.
        > - What: "Hello World!" 문자열을 출력
        > - How: 파일로부터 문자열을 받아서 출력
        > - 여기까지가 추상화 레벨 0단계
        > - 1단계에서는 0단계의 How가 **다시** What이 되고
        > - How는 파일에서 어떻게 문자열을 입력받을 것인지, 입력받은 문자열은 어디에 저장할 것이지, 저장된 문자열은 어떻게 출력할 것인지 와 같이 정의됨.
        > - 이렇게 계속 추상화 레벨을 점차 구체화하면서 What-How를 반복해서 최종적으로 How 부분을 충분히 구체화시키게 되면 해결책을 만들 수 있는 방법론.
    - 이러한 What-How 생각모델은 해결책은 만들 수 있지만, 최적의 해결책을 만들어 내기는 힘들다고 저자는 생각함.

- ***"WHAT-WHY-HOW 생각 모델"*** 제시.
    - ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/what-why-how.png)
        > - 무엇(What)을 해야 할 때, 왜(Why) 그것을 해야 하는가?
        > - 어떻게(How) 하려 할 때, 왜(Why) 그렇게 해야 하는가?
        > - ...를 계속 생각하며 검증하는 것.
        > - 왜 그것을 해야 하는가의 검증 기준은 원하는 **목적(Goal)**
        > - 왜 그렇게 해야 하는가의 검증 기준은 어떤 것이 **최적(Optimization)**의 방법인가가 될 것이다.
        > - 목적이나 최적이란 단순히 겉으로 드러난 것만을 기준으로 하면 안 된다. 주어진 상황이나 환경, 스케쥴이나 전략, 가용한 자원이나 예산, 상충하는 목적들 간의 우선순위, 향후 유지 보수나 스펙 확장 또는 재개발 계획 등등을 종합적으로 고려한 것이어야 한다.

- **What-Why-How 생각모델을 제시하고 강조하는 이유**
    - 이러한 생각을 바탕으로 디자인 패턴들을 분석하고 이해해야...
    - 그래야 실전에서 문제가 주어졌을 때 활용할 수 있고
    - 새로운 패턴을 스스로 만들어 낼 수 있다.
    - 단 하나의 디자인 패턴을 읽더라도 어떤 종류의 문제를 풀기 위한 것이고, 그 문제는 어떤 목적을 달성하기 위한 것이며, 문제를 해결하기 위한 방법에는 어떤 것들이 있을 수 있는지를 왜(Why)라는 질문을 지속적으로 던지면서 따져보고 이해해야 제대로 활용할 수 있다.
