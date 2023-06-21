## **RabbitMQ C by alanxz**
> [*GitHub - alanxz/rabbitmq-c: RabbitMQ C client*](https://github.com/alanxz/rabbitmq-c)
>
>　

　

## **# Setup & Build**

- **GitHub**
    - [*GitHub - alanxz/rabbitmq-c: RabbitMQ C client*](https://github.com/alanxz/rabbitmq-c)

- **CMake**
    - cmake-gui 실행
    - *eg. C:\\Program Files\\CMake\\bin\\cmake-gui.exe*
    - **Configure 실행**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake.png)

        > - Where is the source code: ***...\\Projects\\RabbitMQ-C\\***
        > - Where to build the binaries: ***...\\Projects\\RabbitMQ-C\\***
        > - Configure 클릭
        > - Visual Studio 버전 선택
        > - Finish 클릭

    - **에러 수정**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake1.png)
        - 위 그림처럼 에러가 발생할 거임.
    - **ENABLE_SSL_SUPPORT 언체크**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake2.png)
        - ENABLE_SSL_SUPPORT 언체크하고 다시 Configure 실행
        - *or... Optionally install* [*OpenSSL*](http://www.openssl.org/) *v1.1.1+ to enable support for connecting to RabbitMQ over SSL/TLS*
    - **Generate 실행**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake3.png)
        - ***솔루션(rabbitmq-c.sln)*** 생성됨
- **Build**
  - *ALL_BUILD > Rebuild*


　

## **# 주요 프로젝트**

- **rabbitmq**
    - *Configuration Type:* ***Dynamic Library (.dll)***
    - *Target Name:* ***rabbitmq.4***
    - *Output:* ***$(SolutionDir)\\librabbitmq\\$(Configuration)***
        > - *rabbitmq.4.dll*
        > - *rabbitmq.4.lib*
        > - *rabbitmq.4.pdb*
- **rabbitmq-static**
    - *Configuration Type:* ***Static Library (.lib)***
    - *Target Name:* ***librabbitmq.4***
    - *Output:* ***$(SolutionDir)\\librabbitmq\\$(Configuration)***
        > - *librabbitmq.4.lib*
- **test_basic**
    - ***rabbitmap-static*** *라이브러리를 사용하는 **Basic Publish/Consume** 테스트*
    - *Configuration Type:* ***Application (.exe)***
    - *Target Name:* ***test_basic***
    - *Output:* ***$(SolutionDir)\\tests\\$(Configuration)***
        > - *test_basic.exe*
        > - *test_basic.pdb*


　

## **# Running the examples**

- **GitHub**
    - 예제만 따로 모아 놓은 프로젝트가 있다.
    - 라이브러리 솔루션 만들 때 ***BUILD_EXAMPLES*** 필드를 체크하고 만들었다면 라이브러리 솔루션에 자동으로 포함되어 있을 것이다.
    - 여기서는 EXAMPLES 솔루션을 별도로 생성할 때 발생하는 문제와 해결책을 설명 함.
    - [*rabbitmq-c/examples at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/tree/master/examples)
- **CMake**
    - cmake-gui 실행
    - Where is the source code: ***...\\Projects\\RabbitMQ-C\\examples***
    - Where to build the binaries: ***...\\Projects\\RabbitMQ-C\\examples***
    - ***Configure*** 실행
    - 이런 저런 에러는 걍 무시
    - ***Generate*** 실행하고 솔루션 생성

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/rabbitmq-c-examples.png)

    - ***Project.sln*** 비쥬얼 스튜디오 오픈
- **Build**
    - *ALL_BUILD > Rebuild*
- **빌드 에러 수정**
    - 각 프로젝트에 추가 환경 설정 필요.
    - **examples-common**
        > - *C/C++ > General > Additional Include Directories* > ***../include 추가***
    - **그 외 모든 프로젝트**
        > - *C/C++ > General > Additional Include Directories* > ***../include 추가***
        > - *Linker > General > Additional Library Directories* > ***../librabbitmq/$(Configuration) 추가***
        > - *Linker > Input* > ***rabbitmq.4.lib 추가***
- **실행 실패 대응**
    - rabbitmq.4.dll 없음
    - rabbitmq.4.dll 준비
        > - ***...\\Projects\\RabbitMQ-C\\librabbitmq\\$(Configuration)\\rabbitmq.4.dll*** 파일을
        > - ***...\\Projects\\RabbitMQ-C\\examples\\$(Configuration)\\*** 위치에 복사
- **프로젝트 간략 설명**
    - ***amqp_bind***
        > - 큐 바인딩 예제
        > - [*rabbitmq-c/amqp_bind.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_bind.c)
    - ***amqp_connect_timeout***
        > - 서버 소켓 연결 타임아웃 처리 예제
        > - [*rabbitmq-c/amqp_connect_timeout.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_connect_timeout.c)
    - ***amqp_consumer***
        > - 컨슈머 상세 예외 핸들링 예제
        > - [*rabbitmq-c/amqp_consumer.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_consumer.c)
    - ***amqp_exchange_declare***
        > - 익스체인지 생성 예제
        > - [*rabbitmq-c/amqp_exchange_declare.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_exchange_declare.c)
    - ***amqp_listen***
        > - 컨슈머 대표 예제#1
        > - 내부에서 동적으로 생성한 큐를 바인딩
        > - [*rabbitmq-c/amqp_listen.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_listen.c)
    - ***amqp_listenq***
        > - 컨슈머 대표 예제#2
        > - 외부에서 입력받은 큐를 바로 사용
        > - [*rabbitmq-c/amqp_listenq.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_listenq.c)
    - ***amqp_producer***
        > - 대용량 메시지를 발행하는 예제
        > - [*rabbitmq-c/amqp_producer.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_producer.c)
    - ***amqp_rpc_sendstring_client***
        > - RPC 클라이언트 예제
        > - RPC 서버 예제는 없는 듯...
        > - [*rabbitmq-c/amqp_rpc_sendstring_client.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_rpc_sendstring_client.c)
    - ***amqp_sendstring***
        > - 퍼블리셔 대표 예제
        > - [*rabbitmq-c/amqp_sendstring.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_sendstring.c)
    - ***amqp_unbind***
        > - 큐 바인딩 해제하기
        > - [*rabbitmq-c/amqp_unbind.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_unbind.c)
    - ***examples-common***
        > - 예제에서 사용하는 공용 헬퍼 라이브러리
        > - [*rabbitmq-c/utils.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/utils.c)
        > - [*rabbitmq-c/platform_utils.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/win32/platform_utils.c)


- **예제(퍼블리싱+컨슈밍) 테스트**
    - Arrange for a RabbitMQ or other AMQP server to be running on `localhost`at TCP port number 5672.
    - In one terminal, run
        ```
        cd examples\Debug
        amqp_listen localhost 5672 amq.direct test
        ```
    - In another terminal,
        ```
        cd examples\Debug
        amqp_sendstring localhost 5672 amq.direct test "hello world"
        ```
    - You should see output similar to the following in the listener's
        terminal window:
        ```
        Delivery 1, exchange amq.direct routingkey test
        Content-type: text/plain
        ――――
        00000000: 68 65 6C 6C 6F 20 77 6F : 72 6C 64                 hello world
        0000000B:
        ```
