## RabbitMQ C by alanxz
> [*GitHub - alanxz/rabbitmq-c: RabbitMQ C client*](https://github.com/alanxz/rabbitmq-c)

　

　

## # Setup & Build

- **GitHub**
    - [*GitHub - alanxz/rabbitmq-c: RabbitMQ C client*](https://github.com/alanxz/rabbitmq-c)
    - ***"D:\Projects\RabbitMQ-C\"*** *위치로 받았다고 가정*
- **CMake**
    - cmake-gui 실행
    - *eg. C:\Program Files\CMake\bin\cmake-gui.exe*
    - **Configure 실행**
    
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake.png)
        - Where is the source code: ***D:\Projects\RabbitMQ-C\***
        - Where to build the binaries: ***D:\Projects\RabbitMQ-C\***
        - Configure 클릭
        - Visual Studio 버전 선택
        - Finish 클릭
    - **Error 발생**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake1.png)

        - 위 그림처럼 에러가 발생할 거임.
    - **ENABLE\\_SSL\\_SUPPORT 언체크**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake2.png)

        - ENABLE\\_SSL\\_SUPPORT 언체크하고 다시 Configure 실행
        - *or... Optionally install* [*OpenSSL*](http://www.openssl.org/) *v1.1.1+ to enable support for connecting to RabbitMQ over SSL/TLS*
    - **Generate 실행**

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/cmake3.png)

        - ***솔루션(rabbitmq-c.sln)*** 생성됨
- **Build**
  - *ALL_BUILD > Rebuild*


　

## # 주요 프로젝트

- **rabbitmq**
  - _Configuration Type: **Dynamic Library (.dll)**_
  - _Target Name: **rabbitmq.4**_
  - _Output: **$(SolutionDir)\librabbitmq\$(Configuration)**_
    - _rabbitmq.4.dll_
    - _rabbitmq.4.lib_
    - _rabbitmq.4.pdb_
- **rabbitmq-static**
  - _Configuration Type: **Static Library (.lib)**_
  - _Target Name: **librabbitmq.4**_
  - _Output: **$(SolutionDir)\librabbitmq\$(Configuration)**_
    - _librabbitmq.4.lib_
- **test_basic**
  - _Configuration Type: **Application (.exe)**_
  - _Target Name: **test_basic**_
  - _Output: **$(SolutionDir)\tests\$(Configuration)**_
    - _test_basic.exe_
    - _test_basic.pdb_
  - _Description: **rabbitmap-static** 라이브러리를 사용하는 **Basic Publish/Consume** 테스트_

　

## **# Running the examples**

---

- **GitHub**
  - 예제만 따로 모아 놓은 프로젝트가 있다.
  - 라이브러리 솔루션 만들 때 _**BUILD_EXAMPLES**_ 필드를 체크하고 만들었다면 라이브러리 솔루션에 자동으로 포함되어 있을 것이다.
  - 여기서는 EXAMPLES 솔루션을 별도로 생성할 때 발생하는 문제와 해결책을 설명 함.
  - [_rabbitmq-c/examples at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/tree/master/examples)
- **CMake**
  - cmake-gui 실행
  - Where is the source code: _**D:\Projects\RabbitMQ-C\examples**_
  - Where to build the binaries: _**D:\Projects\RabbitMQ-C\examples**_
  - _**Configure**_ 실행
  - 이런 저런 에러는 걍 무시
  - _**Generate**_ 실행하고 솔루션 생성
  - _**Project.sln**_ 비쥬얼 스튜디오 오픈
- **Build**
  - _ALL_BUILD > Rebuild_
- **빌드 실패**
  - 각 프로젝트에 추가 환경 설정 필요.
  - **examples-common**
    - _C/C++ > General > Additional Include Directories_
      _**../include 추가**_
  - **그 외 모든 프로젝트**
    - _C/C++ > General > Additional Include Directories_
      _**../include 추가**_
    - _Linker > General > Additional Library Directories_
      _**../librabbitmq/$(Configuration) 추가**_
    - _Linker > Input_
      _**rabbitmq.4.lib 추가**_
- **실행 실패**
  - rabbitmq.4.dll 없음
  - rabbitmq.4.dll 준비
    - _**D:\Projects\RabbitMQ-C\librabbitmq\$(Configuration)\rabbitmq.4.dll **_파일을
    - _**D:\Projects\RabbitMQ-C\examples\$(Configuration)\ **_위치에 복사
- **프로젝트 간략 설명**
  - _**amqp_bind**_
    - 큐 바인딩 예제
    - [_rabbitmq-c/amqp_bind.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_bind.c)
  - _**amqp\_connect\_timeout**_
    - 서버 소켓 연결 타임아웃 처리 예제
    - [_rabbitmq-c/amqp\_connect\_timeout.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_connect_timeout.c)
  - _**amqp_consumer**_
    - 컨슈머 상세 예외 핸들링 예제
    - [_rabbitmq-c/amqp_consumer.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_consumer.c)
  - _**amqp\_exchange\_declare**_
    - 익스체인지 생성 예제
    - [_rabbitmq-c/amqp\_exchange\_declare.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_exchange_declare.c)
  - _**amqp_listen**_
    - 컨슈머 대표 예제#1
    - 내부에서 동적으로 생성한 큐를 바인딩
    - [_rabbitmq-c/amqp_listen.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_listen.c)
  - _**amqp_listenq**_
    - 컨슈머 대표 예제#2
    - 외부에서 입력받은 큐를 바로 사용
    - [_rabbitmq-c/amqp_listenq.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_listenq.c)
  - _**amqp_producer**_
    - 대용량 메시지를 발행하는 예제
    - [_rabbitmq-c/amqp_producer.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_producer.c)
  - _**amqp\_rpc\_sendstring_client**_
    - RPC 클라이언트 예제
    - RPC 서버 예제는 없는 듯...
    - [_rabbitmq-c/amqp\_rpc\_sendstring_client.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_rpc_sendstring_client.c)
  - _**amqp_sendstring**_
    - 퍼블리셔 대표 예제
    - [_rabbitmq-c/amqp_sendstring.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_sendstring.c)
  - _**amqp_unbind**_
    - 큐 바인딩 해제하기
    - [_rabbitmq-c/amqp_unbind.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_unbind.c)
  - _**examples-common**_
    - 예제에서 사용하는 공용 헬퍼 라이브러리
    - [_rabbitmq-c/utils.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/utils.c)
    - [_rabbitmq-c/platform_utils.c at master · alanxz/rabbitmq-c_](https://github.com/alanxz/rabbitmq-c/blob/master/examples/win32/platform_utils.c)


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
  