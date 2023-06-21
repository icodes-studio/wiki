## RabbitMQ C++ by alanxz
> [*GitHub - alanxz/SimpleAmqpClient: Simple C++ Interface to rabbitmq-c*](https://github.com/alanxz/SimpleAmqpClient)
>
> ‌

　

## # Setup & Build

- **GitHub**
    - [*GitHub - alanxz/SimpleAmqpClient: Simple C++ Interface to rabbitmq-c*](https://github.com/alanxz/SimpleAmqpClient)
    - ***D:\Projects\RabbitMQ-C++\\*** *위치로 받았다고 가정*
- **Pre-requisites**
    - [***boost-1.47.0***](http://www.boost.org/) ***or newer*** *(uses chrono, system internally in addition to other header based libraries such as sharedptr and noncopyable)*
    - [***rabbitmq-c***](http://github.com/alanxz/rabbitmq-c) *you'll need version 0.8.0 or better.*
    - [***cmake 3.5+***](http://www.cmake.org/) *what is needed for the build system*
    - [***google test***](https://github.com/google/googletest) *https://github.com/google/googletest*
    - [***Doxygen***](http://www.stack.nl/~dimitri/doxygen/) *OPTIONAL only necessary to generate API documentation*
- **CMake**
    - **CMake** 셋업 과정은 [***RabbitMQ C by alanxz***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md) 참고
    - the source code location: ***D:/Projects/RabbitMQ-C++***
    - the binaries location: ***D:/Projects/RabbitMQ-C++***
    - Boost_INCLUDE_DIR: ***C:/boost_1_76_0***
    - Rabbitmqc_INCLUDE_DIR: ***D:/Projects/RabbitMQ-C/include***
    - Rabbitmqc_LIBRARY: ***D:/Projects/RabbitMQ-C/librabbitmq/Debug/rabbitmq.4.lib***
    - ENABLE_SSL_SUPPORT: ***unchecked***
    - ENABLE_TESTING: ***checked***
        > - *하위 **/third-party/** 폴더에* [***googletest***](https://github.com/google/googletest) *받아놔야 한다.*
        > - *컴팔 링킹 에러가 발생하는데... 아직 확인 중...*
- **Build**
    - *솔루션 **SimpleAmqpClient.sln** 오픈*
    - *ALL_BUILD > Rebuild*
- **빌드 에러 수정**
    - 그대로 빌드하면 아래 에러 다수 발생
        ```
        fatal error C1021: invalid preprocessor command 'warning'
        ```
    - 원인: ***#warning*** *preprocessor directives* 인식 실패
    - **해결방법**
        > - 간단히 #warning 구문을 지우던가...
        > - ***#pragma message***를 사용 하던가...
        ```
        #ifdef _MSC_VER
        #pragma message("amqp.h is deprecated, use rabbitmq-c/amqp.h instead.")
        #else
        #warning "amqp.h is deprecated, use rabbitmq-c/amqp.h instead."
        #endif
        ```
        > - ***[[deprecated]]*** *attributes*를 사용 하던가...
        > - ***__declspec(deprecated)***를 사용 하던가...


　

## # 주요 프로젝트

- **SimpleAmqpClient**
    - *Configuration Type:* ***Dynamic Library (.dll)***
    - *Target Name:* ***SimpleAmqpClient.7***
    - *Output Directory:* ***$(SolutionDir)\\$(Configuration)***
        > - *SimpleAmqpClient.7.dll*
        > - *SimpleAmqpClient.7.lib*
        > - *SimpleAmqpClient.7.pdb*
- **test_api**
    - *Configuration Type:* ***Application (.exe)***
    - *Target Name:* ***test_api***
    - *Output Directory:* ***$(SolutionDir)\\testing\\$(Configuration)***
    - ***Description:***
        > - [***googletest***](https://github.com/google/googletest) *외부 라이브러리를 사용하는 유닛 테스트*
        > - ***/third-party/*** *폴더에* ***googletest*** *받고 CMake 돌리면 되는데...*
        > - *컴팔 링킹 에러가 발생하고 있다.*
        > - *아직 확인 중...*
