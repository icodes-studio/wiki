# Installing on Windows
> ![](https://www.rabbitmq.com/favicon.ico)[*Installing on Windows — RabbitMQ*](https://www.rabbitmq.com/install-windows.html)

　

　

# Overview
이 가이드는 Windows에서 RabbitMQ 설치를 다룹니다. 여기서는 두 가지 권장 설치 옵션에 중점을 둡니다.

Using Chocolatey
Using the official installer as an administrative user
이 가이드에서는 Windows와 관련된 몇 가지 설치 후 주제도 다룹니다.

The basics of node configuration
CLI tool authentication
RabbitMQ Windows Service
Managing the node
Firewall and security tools effects
Log file location
Default user limitations
and more. These topics are covered in more details in the rest of documentation guides.

A separate companion guide covers known Windows-specific issues and ways to mitigate them.

　

# Using chocolatey
RabbitMQ 패키지는 Chocolatey를 통해 배포됩니다. 새 릴리스는 승인을 받는 데 시간이 걸릴 수 있으므로(때로는 몇 주), 이 옵션이 최신 릴리스를 제공한다고 보장할 수는 없습니다만, 요구되어지는 디펜던시들을 제대로 관리합니다.

Chocolatey를 사용하여 RabbitMQ를 설치하려면 커맨드라인 또는 파워쉘에서 다음 명령을 실행합니다.

choco install rabbitmq
많은 사례로 볼 때, Chocolatey는 최적의 설치 방법입니다. Chocolatey RabbitMQ 패키지는 오픈소스로 공개되어 있고 GitHub에서 찾을 수 있습니다.

　

# Using the Installer
공식 RabbitMQ 인스톨러는 모든 RabbitMQ 릴리스에 대해 제공됩니다.

Chocolatey를 통한 설치와 비교할 때 이 옵션은 윈도우즈 사용자에게 가장 큰 유연성을 제공하지만 인스톨러에 대한 몇 몇 요구 사항과 이해를 요구합니다.

한 번에 하나의 Erlang 버전만 설치해야 합니다.
Erlang은 어드민 계정을 사용하여 설치해야 합니다.
RabbitMQ도 어드민 계정으로 설치하는 것을 권장합니다.
설치 경로는 ASCII 문자만 포함해야 합니다. 경로의 디렉토리 이름에는 공백이 포함되지 않는 것을 권장합니다.
CLI 도구에서 사용하는 공유 비밀(shared secret) 파일을 수동으로 복사해야 할 수도 있습니다.
CLI 도구를 사용하려면 윈도우즈 콘솔이 UTF-8 모드에서 작동해야 합니다.
이러한 조건이 충족되지 않으면 윈도우즈 서비스 및 CLI 도구는 재 설치 해야 하거나 수동으로 무언가를 고쳐야 할 수도 있습니다.

This is covered in more detail in the Windows-specific Issues guide.

　

# Dependencies
RabbitMQ를 설치하려면 64비트 윈도우즈용 Erlang 버전이 필요합니다. 최신 바이너리 빌드는 Erlang/OTP Version Tree 또는 Download 페이지에서 얻을 수 있습니다.

Erlang은 어드민 계정을 사용하여 설치해야 합니다. 그렇지 않으면 RabbitMQ 윈도우즈 서비스 목록에 등록되지 않습니다.

지원되는 Erlang 버전이 설치되면, RabbitMQ 설치 프로그램인 rabbitmq-server-{version}.exe를 다운로드하여 실행합니다. 그러면 RabbitMQ가 윈도우즈 서비스로 설치되고 기본 환경 구성으로 시작됩니다.

　

# Direct Downloads
Description
Installer for Windows systems (from GitHub)
Download
rabbitmq-server-3.10.7.exe
Signature
Signature
　

# Run RabbitMQ Windows Service
Erlang과 RabbitMQ가 모두 설치되면, RabbitMQ 노드를 Windows 서비스로 시작할 수 있습니다. RabbitMQ 서비스는 사동으로 시작됩니다. RabbitMQ 윈도우즈 서비스는 시작(Start) 메뉴에서 관리할 수 있습니다.

　

# CLI Tools
RabbitMQ 노드는 주로 PowerShell의 CLI 도구를 사용하여 관리, 검사 및 운영됩니다.

윈도우즈 CLI 도구에는 다른 플랫폼의 그것과는 좀 다르게 .bat 확장자가 붙습니다. 예를 들어 윈도우즈의 rabbitmqctl은 rabbitmqctl.bat 스크립트로 호출됩니다.

이러한 도구가 작동하려면 Erlang 쿠키라는 공유 비밀(shared secret) 파일을 사용하여 RabbitMQ 노드를 인증할 수 있어야 합니다.

CLI tools guide 문서는 커맨드 라인 도구 사용과 관련된 대부분의 주제를 다룹니다.

다양한 RabbitMQ CLI 도구가 제공하는 명령을 탐색하려면help커맨드를 사용하세요.

# lists commands provided by rabbitmqctl.bat
rabbitmqctl.bat help
# lists commands provided by rabbitmq-diagnostics.bat
rabbitmq-diagnostics.bat help
# ...you guessed it!
rabbitmq-plugins.bat help
특정 커맨드에 대해 알아보려면 해당 이름을 도움말 인자로 전달하세요.

rabbitmqctl.bat help add_user
　

# Cookie File Location
윈도우즈에서 쿠키 파일 위치는 HOMEDRIVE 및 HOMEPATH 환경 변수의 설정 여부에 따라 다릅니다.

어드민이 아닌 계정을 사용하여 RabbitMQ를 설치하면, 노드 및 CLI 도구에서 사용하는 공유 비밀(shared secret) 파일이 올바른 위치에 배치되지 않습니다. 결국 rabbitmqctl.bat 및 기타 CLI 도구를 사용할 때 인증에 실패하게 됩니다.

이런 경우 아래 해결책이 있습니다.

RabbitMQ를 어드민 계정으로 다시 설치하세요.
.erlang.cookie 파일을 %SystemRoot% 또는 %SystemRoot%\system32\config\systemprofile에서 %HOMEDRIVE%%HOMEPATH% 위치로 수동 복사합니다.
　

# Node Configuration
서비스는 기본 설정을 사용하여 시작하고, 기본 인터페이스 및 포트로 컨넥션을 수신 대기합니다.

노드 환경 구성은 주로 configuration file을 사용하여 수행됩니다. 사용 가능한 여러 환경 변수를 사용하여 노드의 데이터 위치, configuration file 경로 등을 제어할 수 있습니다.

This is covered in more detail in the Configuration guide

환경 변수 변경시 주의 사항

환경 변수 설정 후 서비스 재 설치가 필요합니다. 서비스를 다시 시작하는 것 만으로는 충분하지 않습니다.

　

# Managing the Service
RabbitMQ 디렉토리 링크는 시작(Start) 메뉴에서 찾을 수 있습니다.

시작 메뉴에 보면, sbin dir에서 시작되는 커맨드 프롬프트 창에 대한 링크도 있습니다. 이건 커맨드 라인 도구를 실행하는 가장 편리한 방법입니다.

CLI 도구는 대상 RabbitMQ 노드를 인증해야 합니다.

　

# Stopping a Node
브로커를 중지하거나 상태를 확인하려면 sbin의 rabbitmqctl.bat를 사용하세요(관리자 권한으로).

rabbitmqctl.bat stop
　

# Checking Node Status
다음 명령은 가장 기본적인 노드헬스 체크를 수행하고 노드가 실행 중인 경우 해당 노드에 대한 일부 정보를 표시합니다.

# A basic health check of both the node and CLI tool connectivity/authentication
rabbitmqctl.bat status
작동하려면 두 가지 조건이 충족되어야 합니다.

노드가 실행 중이어야 합니다.
rabbitmqctl.bat 스크립트는 노드를 인증할 수 있어야 합니다.
See the CLI tools section and the Monitoring and Health Checks guide to learn more.

　

# Log Files and Management
서버 로그는 문제 해결 및 근본 원인 분석에서 매우 중요합니다. 로그 파일 위치, 로그 로테이션 등에 대해 알아보려면 Logging 그리고 File and Directory Location 문서를 참조하세요.

　

# Firewalls and Security Tools
방화벽 및 보안 도구로 인해 RabbitMQ 서비스 및 CLI 도구가 올바르게 작동하지 않을 수 있습니다. 이러한 도구는 RabbitMQ에서 사용하는 포트에 대한 액세스를 허용하도록 구성해야 합니다.
　

# Default User Access
브로커는 password guest로 user guest를 생성합니다. 구성되지 않은(Unconfigured) 클라이언트는 일반적으로 이러한 자격 증명을 사용합니다. 기본적으로 이러한 자격 증명은 localhost로 브로커에 연결할 때만 사용할 수 있으므로 다른 시스템에서 연결하기 전에 조치를 취해야 합니다.

See the documentation on access control for information on how to create more users and delete the guest user.

　

# Port Access
RabbitMQ 노드들은 클라이언트 및 CLI 도구 연결을 허용하기 위해 특정 포트들(오픈 서버 TCP 소켓)에 바인딩 됩니다. 안티바이러스 소프트웨어와 같은 다른 프로세스 및 도구로 인해 RabbitMQ가 포트에 바인딩 되지 않을 수 있습니다. 이럴 경우 노드는 시작에 실패할 것입니다.

CLI 도구, 클라이언트 라이브러리들 및 RabbitMQ 노드들도 컨넥션(클라이언트 TCP 소켓)을 엽니다. 방화벽은 노드와 CLI 도구가 서로 통신하는 것을 막을 수 있습니다. 다음 포트들에 액세스할 수 있는지 확인하세요.

4369: epmd, a peer discovery service used by RabbitMQ nodes and CLI tools
5672, 5671: used by AMQP 0-9-1 and 1.0 clients without and with TLS
25672: used for inter-node and CLI tools communication (Erlang distribution server port) and is allocated from a dynamic range (limited to a single port by default, computed as AMQP port + 20000). Unless external connections on these ports are really necessary (e.g. the cluster uses federation or CLI tools are used on machines outside the subnet), these ports should not be publicly exposed. See networking guide for details.
35672-35682: used by CLI tools (Erlang distribution client ports) for communication with nodes and is allocated from a dynamic range (computed as server distribution port + 10000 through server distribution port + 10010). See networking guide for details.
15672: HTTP API clients, management UI and rabbitmqadmin (only if the management plugin is enabled)
61613, 61614: STOMP clients without and with TLS (only if the STOMP plugin is enabled)
1883, 8883: MQTT clients without and with TLS, if the MQTT plugin is enabled
15674: STOMP-over-WebSockets clients (only if the Web STOMP plugin is enabled)
15675: MQTT-over-WebSockets clients (only if the Web MQTT plugin is enabled)
It is possible to configure RabbitMQ to use different ports and specific network interfaces.

　

# Upgrading Erlang VM
이전에 설치가 이미 되어 있고 Erlang VM을 32비트에서 64비트 버전으로 업그레이드하려는 경우, VM을 업그레이드하기 전에 브로커를 제거해야 합니다. 설치 프로그램은 다른 아키텍처의 Erlang VM과 함께 설치된 서비스를 중지하거나 제거할 수 없습니다.

　

# Dump File Location When Running as a Service
RabbitMQ가 서비스로 실행되는 동안 Erlang VM이 크래시나는 경우 덤프파일은 커런트 디렉터리에 남지 않습니다(서비스에 적합하지 않음). 대신에 RabbitMQ 서버의 기본 디렉토리에 erl_crash.dump 파일로 남겨집니다. 기본 디렉토리는 RABBITMQ_BASE 환경 변수에 의해 설정되고, 기본값은 %APPDATA%\%RABBITMQ_SERVICENAME% 입니다. 일반적으로는 %APPDATA%\RabbitMQ 입니다.

　

# Getting Help and Providing Feedback
If you have questions about the contents of this guide or any other topic related to RabbitMQ, don't hesitate to ask them on the RabbitMQ mailing list.

　

# Help Us Improve the Docs <3
If you'd like to contribute an improvement to the site, its source is available on GitHub. Simply fork the repository and submit a pull request. Thank you!