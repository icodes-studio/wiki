## Installing on Windows Manually
> ![](https://www.rabbitmq.com/favicon.ico) [*Installing on Windows Manually — RabbitMQ*](https://www.rabbitmq.com/install-windows-manual.html)

　

　

## # Overview
- 이 가이드는 Windows에서 RabbitMQ를 수동으로 설치하고 구성하는 방법을 설명합니다.
- 일반적으로는 [**자동 옵션 설치**](https://www.rabbitmq.com/install-windows.html)를 권장 드립니다.


　

## # Install Erlang/OTP
- RabbitMQ를 설치하려면 64비트 윈도우즈용 [**Erlang**](https://www.rabbitmq.com/which-erlang.html) 버전이 필요합니다.
- 최신 바이너리 빌드는 [**Erlang/OTP Version Tree**](https://erlang.org/download/otp_versions_tree.html) 또는 [**Download**](https://www.erlang.org/downloads) 페이지에서 얻을 수 있습니다.
- 설치하면 Erlang은 시작 메뉴에 표시되고 64비트 설치의 경우 \erl{version}\bin\erl.exe는 C:\Program Files에 위치합니다.
- **Important**: 시스템에는 한 가지 버전의 Erlang만 설치되어 있어야 합니다. [Windows-specific Issues](https://www.rabbitmq.com/windows-quirks.html) 페이지를 참조하세요.

　

## # Make Sure ERLANG_HOME is Set
- 서비스로 실행되는 브로커 RabbitMQ가 기존에 설치되어 있고, 다른 아키텍처로 Erlang VM을 설치한 경우라면, ERLANG_HOME을 업데이트하기 전에 서비스를 제거해야 합니다.
- 실제 Erlang 설치 위치로 ERLANG_HOME을 설정하세요. e.g. C:\Program Files\erl{version} (full path).
- 이렇게 하면, RabbitMQ 배치 파일은 %ERLANG_HOME%\bin\erl.exe를 실행합니다.
- 시작 \> 설정 \> 제어판 \> 시스템 \> 고급 \> 환경 변수로 이동합니다.
- 이어서 시스템 환경 변수 ERLANG_HOME을 만들고 bin\erl.exe가 포함된 디렉토리의 전체 경로를 설정합니다.


　

## # Install RabbitMQ Server
- 지원되는 Erlang 버전이 설치되었는지 확인한 후, **rabbitmq-server-windows-3.10.7.zip**을 다운로드하세요.
- **Direct Downloads**
    > - Description
        > Installer for Windows systems (from [**GitHub**](https://github.com/rabbitmq/rabbitmq-server/releases))
    > - Download
        > [**rabbitmq-server-windows-3.10.7.zip**](https://github.com/rabbitmq/rabbitmq-server/releases/download/v3.10.7/rabbitmq-server-windows-3.10.7.zip)
    > - Signature
        > [Signature](https://github.com/rabbitmq/rabbitmq-server/releases/download/v3.10.7/rabbitmq-server-windows-3.10.7.zip.asc)
- C:\Program Files\RabbitMQ(또는 애플리케이션 파일에 적합한 위치)에 rabbitmq_server-3.10.7 폴더 이름으로 압축을 풉니다.


　

## # Synchronise the Erlang Cookie
- 얼랭 쿠키는 [RabbitMQ 노드](https://www.rabbitmq.com/clustering.html)와 [CLI 도구](https://www.rabbitmq.com/cli.html) 간의 인증에 사용되는 공유 비밀(shared secret)입니다.
- 이 값은 일반적으로 얼랭 쿠키 파일이라고 하는 파일에 저장됩니다.
- 서비스 계정이 사용하는 쿠키 파일과 rabbitmqctl.bat을 실행하는 사용자가 사용하는 쿠키 파일은 rabbitmqctl.bat 같은 CLI 도구가 작동하도록 동기화되어야 합니다.
- 클러스터의 모든 노드는 동일한 쿠키 값(쿠키 파일 내용)을 가져야 합니다.
- Please see [How CLI Tools Authenticate to Nodes (and Nodes to Each Other): the Erlang Cookie](https://www.rabbitmq.com/cli.html#erlang-cookie) for details.


　

## # CLI tools
- **rabbitmq_server-3.10.7\sbin** 디렉토리에는 RabbitMQ 서버 제어 커맨드를 실행하는 스크립트가 있습니다.
- RabbitMQ 서버는 애플리케이션 또는 서비스로 실행할 수 있습니다.
    > - [**rabbitmq-server.bat**](https://www.rabbitmq.com/man/rabbitmq-server.8.html) : 애플리케이션으로 브로커를 시작합니다.
    > - [**rabbitmq-service.bat**](https://www.rabbitmq.com/man/rabbitmq-service.8.html) : 서비스를 관리하고 브로커를 시작합니다.
    > - [**rabbitmqctl.bat**](https://www.rabbitmq.com/man/rabbitmqctl.8.html) : 실행 중인 브로커를 관리합니다.
- 실행 결과를 보려면, 관리자로 로그인하고 sbin 디렉토리의 커맨드 프롬프트에서 스크립트를 실행하면 됩니다.
- **Note**: Windows Vista(이상)에서는 권한을 높여야 합니다(e.g. 아이콘을 마우스 오른쪽 버튼으로 클릭하여 관리자 권한으로 실행 선택).
- 풀 경로를 사용하지 않고 sbin 디렉토리의 RabbitMQ 서버 및 CLI 도구를 실행하려면 시스템 경로를 설정하세요.
    > - "C:\Program Files\RabbitMQ\rabbitmq_server-3.10.7"에 대한 시스템 환경 변수(e.g. RABBITMQ_SERVER)를 하나 만드세요.
    > - 나중에 rabbitmq_server-3.10.7 위치가 변경 되거나 버전을 업그레이드하는 경우 이 값을 수정하세요.
    > - **";%RABBITMQ_SERVER%\sbin"** 문자열을 시스템 경로(aka %PATH%)에 추가합니다.
- 이제 모든 (관리자) 명령 프롬프트에서 rabbitmq 명령을 실행할 수 있을 거예요.
- 그리고... 혹, 시스템 경로에 RabbitMQ sbin 디렉토리를 포함하지 않았다면,
- 그냥 rabbitmq_server-3.10.7\sbin으로 이동하여 명령을 실행하세요.


　

## # Node Data Directory
- 기본적으로 RabbitMQ 로그와 노드의 데이터 디렉토리는 현재 사용자의 Application Data 디렉토리에 저장됩니다.
    > e.g. C:\Documents and Settings\%USERNAME%\Application Data 또는 C:\Users\%USERNAME%\AppData\Roaming.
- 명령 프롬프트에서 echo %APPDATA%를 실행하면 이 디렉토리 위치가 어디인지 찾아볼 수 있습니다.
- 또는 윈도우즈 시작 메뉴에서 %APPDATA%를 실행하면 해당 위치가 바로 열립니다.
- 노드가 다른 데이터 디렉토리를 사용할 수 있도록 [환경을 구성](https://www.rabbitmq.com/configure.html)할 수 있습니다. 아래 환경 변수들 중 하나를 사용해 보세요.
    > - RABBITMQ_BASE
    > - RABBITMQ_MNESIA_BASE
    > - RABBITMQ_MNESIA_DIR
    > - Please read the [relocation guide](https://www.rabbitmq.com/relocate.html) for a description of how each of these variables works.


　

## # Running RabbitMQ Server as an Application
- 애플리케이션은 sbin의 **rabbitmq-server.bat** 스크립트에 의해 시작됩니다.
- RabbitMQ 환경 변수 커스터마이즈
    > - 서비스는 기본 설정을 사용하여 그냥 잘 실행될 거예요. 
    > - [RabbitMQ environment를 커스터마이즈](https://www.rabbitmq.com/configure.html#customise-windows-environment) 하거나 [configuration 수정](https://www.rabbitmq.com/configure.html#configuration-files)하는 것들은 모두 가능합니다.
    > - **Important**: 환경 변수를 설정한 후엔, 노드를 재 시작해야 합니다.


　

## # Start the Broker as an Application
- Run the command
    ```
    rabbitmq-server.bat -detached
    ```
- 이 명령은 백그라운드에서 노드를 시작합니다(명령 프롬프트에 붙어서 실행되는 게 아님).
- 또는 Windows 탐색기에서 rabbitmq-server.bat를 실행하면 포그라운드에서 노드를 시작할 수 있습니다.
- 노드가 시작되면, 커맨드 프롬프트 창이 열리고 RabbitMQ 브로커가 성공적으로 시작되었음을 나타내는 짧은 시작 배너가 표시됩니다.
- 노드가 -detached 옵션 없이 시작된 경우, e.g. Windows 탐색기를 사용하는 경우, CLI 도구를 사용하여 애플리케이션을 제어하려면 커맨트 프롬프트 창이 추가로 필요합니다.


　

## # Running RabbitMQ Server as a Service
- 서비스는 사용자가 콘솔에 로그인할 필요 없이 시스템 계정의 보안 컨텍스트에서 실행됩니다.
- 이 방법은 **실제 라이브 서비스 용도에 적합**합니다. 서버는 서비스와 애플리케이션으로 동시에 실행되어서는 안됩니다.
- 서비스는 sbin의 **rabbitmq-service.bat** 스크립트를 사용하여 실행됩니다.
- RabbitMQ 환경 변수 커스터마이즈
    > - 서비스는 기본 설정을 사용하여 그냥 잘 실행될 거예요.
    > - [**RabbitMQ environment를 커스터마이즈**](https://www.rabbitmq.com/configure.html#customise-windows-environment) 하거나 [**configuration 수정**](https://www.rabbitmq.com/configure.html#configuration-files)하는 것들은 모두 가능합니다.
    > - **Important**: 환경 변수를 설정한 후엔, 서비스를 재 설치해야 합니다.


　

## # Install the Service
- Install the service by running
    ```
    rabbitmq-service.bat install
    ```
- **RABBITMQ_SERVICENAME**에 의해 정의된 이름을 가진 서비스가 이제 윈도우즈 서비스 제어판(Run services.msc)에 나타나야 합니다.


　

## # Managing the Service
- 서비스를 관리(설치, 제거, 시작, 중지, 활성화, 비활성화)하려면 **rabbitmq-service.bat** 명령을 사용하십시오.
- 또는 윈도우즈서비스 패널(services.msc)을 사용하여 서비스 스크립트와 동일한 기능 중 일부를 수행할 수 있습니다.


　

## # Start the Broker as a Service
- To start the broker, execute
    ```
    rabbitmq-service.bat start
    ```
- 이 명령의 출력이 "Service RABBITMQ_SERVICENAME started"이면 서비스가 성공적으로 시작된 것입니다.
- 서비스 패널에서 RABBITMQ_SERVICENAME이라는 서비스가 "Started" 상태로 보이는지 확인 하세요.
    > Start \> Run services.msc


　

## # Upgrading Erlang VM
- 이전에 설치가 이미 되어 있고 Erlang VM을 32비트에서 64비트 버전으로 업그레이드하려는 경우, VM을 업그레이드하기 전에 브로커를 제거해야 합니다.
- 설치 프로그램은 다른 아키텍처의 Erlang VM과 함께 설치된 서비스를 중지하거나 제거할 수 없습니다.


　

## # Managing the Service
- RabbitMQ 디렉토리 링크는 시작(Start) 메뉴에서 찾을 수 있습니다.
- 시작 메뉴에 보면, sbin dir에서 시작되는 커맨드 프롬프트 창에 대한 링크도 있습니다. 이건 [**커맨드 라인 도구**](https://www.rabbitmq.com/install-windows.html#cli)를 실행하는 가장 편리한 방법입니다.
- CLI 도구는 로컬에서 실행되는 [RabbitMQ 노드를 인증](https://www.rabbitmq.com/cli.html#erlang-cookie)해야 합니다. 여기에는 사용자에 대해서 올바른 위치에 배치해야 하는 공유 비밀(shared secret) 파일이 포함됩니다.


　

## # Stopping a Node
- 브로커를 중지하거나 상태를 확인하려면 sbin의 **rabbitmqctl.bat**를 사용하세요(관리자 권한으로).
    ```
    rabbitmqctl.bat stop
    ```


　

## # Checking Node Status
- 다음 명령은 가장 기본적인 [노드 헬스 체크](https://www.rabbitmq.com/monitoring.html#health-checks)를 수행하고 노드가 실행 중인 경우 해당 노드에 대한 일부 정보를 표시합니다.
    ```
    rabbitmqctl.bat status
    ```
- See [**RabbitMQ CLI tools guide**](https://www.rabbitmq.com/cli.html) and the [**Monitoring and Health Checks guide**](https://www.rabbitmq.com/monitoring.html) for details.


　

## # Log Files and Management
- 서버 로그는 문제 해결 및 근본 원인 분석에서 매우 중요합니다.
- 로그 파일 위치, 로그 로테이션 등에 대해 알아보려면 [Logging](https://www.rabbitmq.com/logging.html) 그리고 [File and Directory Location](https://www.rabbitmq.com/relocate.html) 문서를 참조하세요.


　

## # Troubleshooting When Running as a Service
- RabbitMQ가 서비스로 실행되는 동안 Erlang VM이 크래시나는 경우 덤프파일은 커런트 디렉터리에 남지 않습니다.
- 대신에 RabbitMQ 서버의 기본 디렉토리에 erl_crash.dump 파일로 남겨집니다.
- 기본 디렉토리는 RABBITMQ_BASE 환경 변수에 의해 설정되고, 기본값은 **%APPDATA%\%RABBITMQ_SERVICENAME%** 입니다.
- 일반적으로는 **%APPDATA%\RabbitMQ** 입니다.


　

## # Default User Access
- 브로커는 password guest로 user guest를 생성합니다.
- 구성되지 않은(Unconfigured) 클라이언트는 일반적으로 이러한 자격 증명을 사용합니다.
- 이러한 자격 증명은 localhost로 브로커에 연결할 때만 사용할 수 있으므로 다른 시스템에서 연결하기 전에 조치를 취해야 합니다.
- See the documentation on [access control](https://www.rabbitmq.com/access-control.html) for information on how to create more users and delete the guest user.


　

## # Port Access
- RabbitMQ 노드들은 클라이언트 및 CLI 도구 연결을 허용하기 위해 특정 포트들(오픈 서버 TCP 소켓)에 바인딩 됩니다.
- 안티바이러스 소프트웨어와 같은 다른 프로세스 및 도구로 인해 RabbitMQ가 포트에 바인딩 되지 않을 수 있습니다.
- 이럴 경우 노드는 시작에 실패할 것입니다.
- CLI 도구, 클라이언트 라이브러리들 및 RabbitMQ 노드들도 컨넥션(클라이언트 TCP 소켓)을 엽니다.
- 방화벽은 노드와 CLI 도구가 서로 통신하는 것을 막을 수 있습니다. 다음 포트들에 액세스할 수 있는지 확인하세요.
    > - **4369**: [epmd](https://www.erlang.org/doc/man/epmd.html), a peer discovery service used by RabbitMQ nodes and CLI tools.
    > - **5672, 5671**: used by AMQP 0-9-1 and 1.0 clients without and with TLS.
    > - **25672**: used for inter-node and CLI tools communication.
    > - **35672-35682**: used by CLI tools (Erlang distribution client ports) for communication with nodes.
    > - **15672**: [HTTP API](https://www.rabbitmq.com/management.html) clients, [management UI](https://www.rabbitmq.com/management.html) and [rabbitmqadmin](https://www.rabbitmq.com/management-cli.html) (only if the [management plugin](https://www.rabbitmq.com/management.html) is enabled).
    > - **61613, 61614**: [STOMP clients](https://stomp.github.io/stomp-specification-1.2.html) without and with TLS (only if the [STOMP plugin](https://www.rabbitmq.com/stomp.html) is enabled).
    > - **1883, 8883**: [MQTT clients](https://mqtt.org/) without and with TLS, if the [MQTT plugin](https://www.rabbitmq.com/mqtt.html) is enabled.
    > - **15674**: STOMP-over-WebSockets clients (only if the [Web STOMP plugin](https://www.rabbitmq.com/web-stomp.html) is enabled).
    > - **15675**: MQTT-over-WebSockets clients (only if the [Web MQTT plugin](https://www.rabbitmq.com/web-mqtt.html) is enabled).
- It is possible to [**configure RabbitMQ**](https://www.rabbitmq.com/configure.html) to use [**different ports and specific network interfaces**](https://www.rabbitmq.com/networking.html).


　

## # Windows-specific Issues
- We aim to make RabbitMQ a first-class citizen on Windows. However, sometimes there are circumstances beyond our control. Please consult the [**Windows-specific Issues**](https://www.rabbitmq.com/windows-quirks.html) page.


　

## # Getting Help and Providing Feedback
- If you have questions about the contents of this guide or any other topic related to RabbitMQ, don't hesitate to ask them on the [**RabbitMQ mailing list**](https://groups.google.com/g/rabbitmq-users).


　

## # Help Us Improve the Docs <3
- If you'd like to contribute an improvement to the site, its source is [**available on GitHub**](https://github.com/rabbitmq/rabbitmq-website). Simply fork the repository and submit a pull request. Thank you!