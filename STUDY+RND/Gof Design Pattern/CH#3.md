## 제품군별 객체 생성 문제

- **객체를 생성하기 위해 설계 단계에서부터 고민할 필요가 있을까?**
    - 객체를 생성하려면 자료형을 알아야 한다.
    - 이를 어느 레벨까지 알게 할 것인가에 따라 클래스 간 관계가 달라짐.
    - 유연성이나 재사용성, 효율성 등에 영향을 미치는 주요 변수이다.

- **제품군 이란?**
    - 예를 들어 자동차의 경우 엔진, 기어, 조향장치, 브레이크, 바퀴 등등의 제품이 있는데 이들을 자동차 모델별로 모아놓은 것.
    - 동일한 역할을 수행하는 클래스라도 운영체제나 플랫폼에 따라 서로 다른 클래스가 존재한다.
    - 운영체제나 플랫폼이 달라지면 내부 구현도 달라지기 때문.
    - 다룰 클래스가 많아지면 사용하기가 쉽지 않다.

　

　

***"특정 운영체제나 플랫폼을 위한 클래스들만 자동으로 선별해서 객체를 생성시킬 수 있는 방법은 없을까?"***

　

　

## 컴파일러를 개발하기 위한 설계

- ***컴파일러의 구성요소.***
    - Scanner: 원시코드를 토큰 단위로 자름
    - Parser: 구문 분석
    - Code Generator: 중간코드 및 기계어 생성
    - Optimizer: 생성된 코드의 최적화

- **멀티 시스템 지원 컴파일러 개발에서의 문제**
    - Code Generator는 각 시스템마다 다르다 - 각 CPU 종류 별로 사용하는 기계어가 다름
    - 운영체제 별로도 각 클래스 구현은 다르다 - 독립적인 네이티브 시스템 콜을 사용할 일이 있다.
    - Windows
        > - WindowsScanner
        > - WindowsParser
        > - WindowsCodeGenerator
        > - WindowsOptimizer
    - Linux
        > - LinuxScanner
        > - LinuxParser
        > - LinuxCodeGenerator
        > - LinuxOptimizer

　

　

***"컴파일러가 실행된다면 각 환경에서 동작하는 클래스 객체들만 생성되어야 한다. 그렇다면 이런 사실을 어떻게 명확히 보장받을 수 있을까?"***

　

　

## 기본적인 방법: 조건 비교 방식

- 조건에 따라 생성하고 사용하는 객체를 달리하는 방법
    ```
    using System;
    using System.Runtime.InteropServices;

    namespace Example.Compiler.N1
    {
        abstract class Scanner
        {
            public abstract void Run();
        };

        abstract class Parser
        {
            public abstract void Run();
        };

        abstract class CodeGenerator
        {
            public abstract void Run();
        };

        abstract class Optimizer
        {
            public abstract void Run();
        };

        class WindowsScanner : Scanner
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class WindowsParser : Parser
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class WindowsCodeGenerator : CodeGenerator
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class WindowsOptimizer : Optimizer
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxScanner : Scanner
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxParser : Parser
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxCodeGenerator : CodeGenerator
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxOptimizer : Optimizer
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class Program
        {
            static void Scan()
            {
                Scanner scanner;
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    scanner = new WindowsScanner();
                }
                else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
                {
                    scanner = new LinuxScanner();
                }
                else
                {
                    throw new Exception(RuntimeInformation.OSDescription + " does not supported");
                }
                scanner.Run();
            }

            static void Parse()
            {
                Parser parser;
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    parser = new WindowsParser();
                }
                else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
                {
                    parser = new LinuxParser();
                }
                else
                {
                    throw new Exception(RuntimeInformation.OSDescription + " does not supported");
                }
                parser.Run();
            }

            static void CodeGenerate()
            {
                CodeGenerator codeGenerator;
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    codeGenerator = new WindowsCodeGenerator();
                }
                else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
                {
                    codeGenerator = new LinuxCodeGenerator();
                }
                else
                {
                    throw new Exception(RuntimeInformation.OSDescription + " does not supported");
                }
                codeGenerator.Run();
            }

            static void Optimize()
            {
                Optimizer optimizer;
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    optimizer = new WindowsOptimizer();
                }
                else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
                {
                    optimizer = new LinuxOptimizer();
                }
                else
                {
                    throw new Exception(RuntimeInformation.OSDescription + " does not supported");
                }
                optimizer.Run();
            }

            static void Main(string[] args)
            {
                Scan();
                Parse();
                CodeGenerate();
                Optimize();
            }
        }
    }
    ```

- **문제점**
    - 프로그램 곳곳에 조건 비교 문장이 존재한다.
    - OSX와 같은 운영체제에서도 컴파일러를 실행시키고자 한다면?
    - 새로운 조건을 추가할 일이 발생한 것이고 프로그램 전체를 찾아다니며 일일이 수정해야 한다.

- **반론#1: 얼추 일부 공간에 조건 비교 문장이 존재하는데 무슨...**
    - 전체 코드가 펼쳐 있다고 생각해 봐라. -_-;
    - 예제는 예제일 뿐...

- **반론#2: Main 함수를 이렇게 구성하면 간단하잖아!**
    ```
    static void Main(string[] args)
    {
        Scanner scanner;
        Parser parser;
        CodeGenerator codeGenerator;
        Optimizer optimizer;

        if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
        {
            scanner = new WindowsScanner();
            parser = new WindowsParser();
            codeGenerator = new WindowsCodeGenerator();
            optimizer = new WindowsOptimizer();
        }
        else
        {
            scanner = new LinuxScanner();
            parser = new LinuxParser();
            codeGenerator = new LinuxCodeGenerator();
            optimizer = new LinuxOptimizer();
        }

        scanner.Run();
        parser.Run();
        codeGenerator.Run();
        optimizer.Run();
    }
    ```

- **현실적으로 생각해 보자.**
    - 필요하지도 않은 무거운 객체를 미리 생성해 둔다는 건 성능 하락
    - 중간에 문법 에러가 발생할 수도 있고
    - 일부 기능은 상황에 따라 스킵 될 수도 있다.
    - 통상적으로 같은 제품들은 종류별로 여러 개가 만들어짐.
    - 근본적으로 여러 개의 조건 비교문이 퍼지는 문제를 회피하기 힘듬.

- **좀 더 나은 방법: 객체 생성 전담 클래스 활용 방식**
    - 문제의 원인은 변경될 가능성이 많은 프로그램 부분이 전체 프로그램의 곳곳에 퍼져 있다는 것.
    - **그래서 뭘 할 거야?** - 객체 생성만 한곳으로 모으자!
    - **왜?** - 다양한 환경을 지원해야 하기 때문에 유지보수 이슈가 많아질 거야. 그런데 변경에 소요되는 비용이 커지면 곤란해!
    - **어떻게 할 거야?** - 변경 가능성이 많은 정보를 클래스 내부로 숨기자.
    - **왜?** - 클래스를 활용하여 이렇게 정보은닉(Information Hiding) 하면 변경 대상폭을 줄여줄 수 있어. 나중에 프로그램에 대한 변경 요청이 있더라도 그 범위를 최소화할 수 있는 장점을 가지게 돼.

　

　

## 1차 클래스 설계 - 객체 생성 전담 클래스를 활용
  ‌
- **CompilerFactory**
    > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/compiler-factory.png)
    - 각 컴파일러 구성 클래스의 객체들 생성을 담당.
    - 각 메소드들 내부에 조건 비교 문장이 있다.
    - 기반 클래스 타입을 반환하므로 Client 입장에서는 시스템 환경에 따른 조건 비교없이 소스코드를 작성할 수 있다.
    - 정리: 시스템 환경에 따른 조건 비교 문장이 CompilerFactory 클래스 내부에만 존재하게 되기 때문에 새로운 조건이 추가되거나 이전 조건을 변경시켜야 할 경우 프로그램 전체를 찾아다니며 수정을 해야 하는 비용을 없앨 수 있다.

- **문제점**
    - 여전히 컴파일러 모듈 소스코드 내에 여러 비교 문장이 존재
    - 새로운 조건을 추가해야 하는 경우 여전히 이전 코드를 면밀히 분석해서 수정해야 함.
    - 이전 소스코드와는 무관하게 독립적으로 추가할 수 없다.
    - ***모듈이 바이너리로만 존재한다면 문제는 더 심각해진다.***

- **패턴 활용 방법: Abstract Factory 패턴**
    - **WHAT?** - 새로운 구성요소를 추가, 확장시키기 위한 좋은 방법을 찾아야 해.
    - **WHY?** - 이 제품의 주 목적은 유연한 멀티플랫폼 지원 컴파일러야 그런데 좀 전에 말했던 문제점이 있어.
    - **HOW?** - 기반 팩토리 클래스에서는 인터페이스만을 제공하고, 이를 상속받아서 각 환경별로 팩토리 클래스를 구현할 거야.
    - **WHY?** - 기반 팩토리 클래스를 클라이언트가 참조하게 하고 상속받은 클래스가 객체를 생성하고 반환하면 OOP 다형성을 이용해서 컴파일러 모듈 소스코드를 손대지 않고도 기능을 쉽게 확장할 수 있어.
    - **WHAT?** - 생성 인터페이스들만 제공하는 기본 팩토리 클래스를 만들고 이를 상속받아서 각 환경별로 실제 컴파일러 모듈을 생성하고 반환하는 팩토리 클래스를 만들 거야. 그리고 생성 인터페이스 메소드는 오버라이딩 해서 환경에 맞는 컴파일러 구성요소를 생성하고 반환하게 할 거야.
    - **WHY?** - 이 컴파일러 모듈은 보안상 소스를 제공하지 않는 게 기본 정책이야. 소스를 제공한다고 해도 쓰는 사람이 모듈 소스코드까지 분석하면서 기능 확장을 할 시간이 없어. 그리고 어쩔 수 없이 새로운 환경을 대응해야 한다고 치자. 컴파일러 모듈에 손을 대면 클라이언트 입장에서 모듈 업데이트 이슈에 대해 버전 관리가 너무 힘들어져.
    - **HOW?** - 운영체제 환경은 클라이언트에서 한 번만 조건 비교해서 적합한 환경별 팩토리 클래스를 선택하게 하고 필요에 따라 선택된 팩토리 클래스를 사용해서 컴파일러 구성요소 객체를 생성하고 사용하게 할 거야. 그리고 각 환경 별 팩토리 클래스는 컴파일러 구성요소의 상위 클래스 타입을 반환하게 할 거야.
    - **WHY?** - ...

　

　

## 2차 클래스 설계
    - CompilerFactory 클래스를 WindowsCompilerFactory 클래스와 LinuxCompilerFactory 클래스로 구분하여 CompilerFactory 클래스의 하위 클래스로 두고 외부 Client에서는 CompilerFactory 클래스의 자료형과 인터페이스를 사용하게 만든다면, 컴파일러 모듈 내부에 시스템 환경에 따른 비교 문장을 둘 필요가 없어진다. 물론 클라이언트에서는 한 번의 조건 비교로 주어진 환경에 해당하는 팩토리 클래스를 선택하고 각 컴파일러 모듈의 객체를 생성하는데 사용할 수 있다.
    
    > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Gof%20Design%20Pattern/Assets/abstractfactory.png)
    
    ```
    using System;
    using System.Runtime.InteropServices;

    namespace Example.Compiler.N2
    {
        abstract class Scanner
        {
            public abstract void Run();
        };

        abstract class Parser
        {
            public abstract void Run();
        };

        abstract class CodeGenerator
        {
            public abstract void Run();
        };

        abstract class Optimizer
        {
            public abstract void Run();
        };

        class WindowsScanner : Scanner
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class WindowsParser : Parser
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class WindowsCodeGenerator : CodeGenerator
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class WindowsOptimizer : Optimizer
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxScanner : Scanner
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxParser : Parser
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxCodeGenerator : CodeGenerator
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        class LinuxOptimizer : Optimizer
        {
            public override void Run() => Console.WriteLine(ToString());
        };

        abstract class CompilerFactory
        {
            public abstract Scanner CreateScanner();
            public abstract Parser CreateParser();
            public abstract CodeGenerator CreateCodeGenerator();
            public abstract Optimizer CreateOptimizer();
        }

        class WindowsCompilerFactory : CompilerFactory
        {
            public override Scanner CreateScanner() => new WindowsScanner();
            public override Parser CreateParser() => new WindowsParser();
            public override CodeGenerator CreateCodeGenerator() => new WindowsCodeGenerator();
            public override Optimizer CreateOptimizer() => new WindowsOptimizer();
        }

        class LinuxCompilerFactory : CompilerFactory
        {
            public override Scanner CreateScanner() => new LinuxScanner();
            public override Parser CreateParser() => new LinuxParser();
            public override CodeGenerator CreateCodeGenerator() => new LinuxCodeGenerator();
            public override Optimizer CreateOptimizer() => new LinuxOptimizer();
        }

        class Program
        {
            static void Main(string[] args)
            {
                CompilerFactory factory;
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    factory = new WindowsCompilerFactory();
                }
                else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
                {
                    factory = new LinuxCompilerFactory();
                }
                else
                {
                    Console.WriteLine(RuntimeInformation.OSDescription + " does not supported");
                    return;
                }

                factory.CreateScanner().Run();
                factory.CreateParser().Run();
                factory.CreateCodeGenerator().Run();
                factory.CreateOptimizer().Run();
            }
        }
    }
    ```
        > - 클라이언트에 해당하는 Main() 함수에서 어떤 제품군을 생성할 것인지를 결정하기 위해 조건 비교 문장을 사용한다.
        > - 그러나 일단 어떤 제품군을 생성할 지만 결정되면 더 이상의 조건 비교 문장은 사용할 필요가 없다.
        > - OOP 다형성(Polymorphism)을 활용하는 모범적 사례

　

- **구현 관련 추가 사항**
  - Factory 객체를 하나만 생성, 유지하는 방법.
    - Singleton 패턴 : CHAPTER 7
  - 복제를 통해 제품 객체를 생성하는 방법
    - Prototype 패턴 : CHAPTER 6
- **새로운 종류의 제품이 추가되었을 때의 문제**
  - Factory 클래스에 의해 생성되는 제품의 종류에 ErrorHandler가 새로 추가되어야 하는 상황이 발생한다면?
  - 새로운 종류의 제품에 해당하는 클래스 추가
    - ErrorHandler, WindowsErrorHandler, LinuxErrorHandler
  - 3개 Factory 클래스들도 각각 수정 - 메소드 추가
    - CreateErrorHandler()
  - 결국 아래와 같은 모습이 되시겠다. -_-;
  - 이런 문제를 해결할 수 있는 방법은 없을까?
    - 왜 Factory 클래스가 수정되어야 하는가?
    - 생성할 제품의 종류에 따라 다른 메소드를 가지기 때문.
    - 그러면 메소드를 하나로 통일하면 되겠네.
    - CreateProduct(int type) 뭐 이런 걸로...
    - 바보야! 인자 값에 따라 메소드 내부에서는 조건 비교를 하게 되잖아. 결국 새로운 제품이 추가되면 CreateProduct 메소드 내부를 수정해야 하는 건 바뀌지 않아!
    - CreateProduct의 인자로 조건 비교를 하지 않고도 제품 객체를 생성할 수 있는 무언가를 넘겨주면 되지 않을까?
    - 그게 뭔데?
    - CHAPTER 6. Prototype 패턴을 설명할 때 다시 다뤄보자.
    - 대가리 싸매고 고민을 해 보는 게 더 중요하다.
- **Abstract Factory 패턴 정리**
  - Abstract Factory 패턴의 일반적인 구조
  - Client가 참조하는 자료형은 상위의 추상 클래스들이다.
    - AbstractFactory
    - AbstractProductA
    - AbstractProductB
  - 물론 실제 만들어지는 객체는 각각의 하위 클래스에 해당하는 것
- **장점**
  - 클라이언트가 객체의 생성이나 구성에 독립적이도록 만들 수 있다.
  - 사용할 제품군을 쉽게 선택할 수 있다.
  - 제품들에 대한 클래스 라이브러리를 만들어야 하는데 그 인터페이스만 드러내고 구현은 숨기고 싶을 때 유용하다.
  - 객체가 생성되는 방식이나 과정 및 책임을 클라이언트가 모르도록 은닉하고 클래스들의 인터페이스만을 사용하게 하여 객체가 생성되는 방식이나 과정이 변경되더라도 그 부분이 국지화될 수 있다.
  - 제품군 간 교체가 쉽다
  - 생성되는 제품 객체가 항상 같은 제품군에 속하는 것을 확실히 보장.
- **단점**
  - 제품군의 개수가 늘어날수록 CreateFactory 클래스의 개수도 늘어나므로 설계가 복잡해지게 된다.
    - IOS, AOS, OSX, UNIX 추가 지원 가능성
    - HP, SUN, IBM, AIX, 지원 가능성
    - x86, x64 빌드를 모두 지원해야 한다면?
    - ARM Core Processor를 지원해야 한다면?
  - 제품군 내에 새로운 제품이 추가되어야 할 경우 모든 Factory 클래스를 수정해야 한다.

![Figure\_3-4.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/600a609bb16823191e1f65ab/82966d8e82d827f38744de1cd7fae76e/Figure_3-4.png)

![Figure\_3-3.png](https://trello-attachments.s3.amazonaws.com/6015292251f26c2a3ebf6054/600a609bb16823191e1f65ab/f0a68ceccca31feaee5c5ceef177e27e/Figure_3-3.png)

　

_**"여기서 또 한 번 강조하자면, Abstract Factory 패턴은 최선의 해결책이 아니라, 최적의 해결책이라는 사실이다. 따라서 여러분은 문제의 목적이나 상황이 변경되면 그에 맞추어 Abstract Factory 패턴의 설계를 변경, 적용할 수 있는 능력을 키워야 할 것이다."**_