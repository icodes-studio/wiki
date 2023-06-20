## # Install Erlang/OTP
- ***Downloads***
    > - [***Download - Erlang/OTP 25.1***](https://www.erlang.org/downloads)
    > - [*Download - OTP Versions Tree*](https://erlang.org/download/otp_versions_tree.html)
- [*64-bit supported version of Erlang for Windows*](https://www.rabbitmq.com/which-erlang.html)
- *Note that Erlang must be installed using an **administrative** account*


　

## # Install RabbitMQ Server
- ***Downloads***
    > - [***rabbitmq-server-3.10.7.exe***](https://github.com/rabbitmq/rabbitmq-server/releases/download/v3.10.7/rabbitmq-server-3.10.7.exe)
    > - [*Signature*](https://github.com/rabbitmq/rabbitmq-server/releases/download/v3.10.7/rabbitmq-server-3.10.7.exe.asc)
- [*Changelog*](https://www.rabbitmq.com/changelog.html)
- [*Release notes*](https://github.com/rabbitmq/rabbitmq-server/releases)


　

## # Run RabbitMQ
- **The RabbitMQ service starts automatically**
    > - Once both Erlang and RabbitMQ have been installed, a RabbitMQ node can be started as a Windows service.

- **Running RabbitMQ Server as an Application**
    > - It can be executed to start a node in foreground.
    ```
    rabbitmq-server.bat
    ```

- **Start the Broker as an Application**
    > - This will start a node in the background
    ```
    rabbitmq-server.bat -detached
    ```

- **Running RabbitMQ Server as a Service**
    > - Install the service by running
    ```
    rabbitmq-service.bat install
    ```

- **Start the Broker as a Service**
    > - To start the broker, execute
    ```
    rabbitmq-service.bat start
    ```


　

## # Managing the Service
- **Stopping a Node**
    > - To stop the broker or check its status, use rabbitmqctl.bat in sbin (as an administrator).
    ```
    rabbitmqctl.bat stop
    ```

- **Checking Node Status**
    > - The most basic node health check and displays some information about the node
    ```
    rabbitmqctl.bat status
    ```


　

## [# Management Plugin](https://www.rabbitmq.com/management.html)
- **Getting Started**
    > - It must be enabled before it can be used.
    ```
    rabbitmq-plugins enable rabbitmq_management
    ```
    > - Management UI: http://localhost:15672/
    > - Account: guest/guest


　

## # Log & Dump
- **Log**
    > - %RABBITMQ_LOG_BASE%\%RABBITMQ_NODENAME%(-sasl).log
    > - %APPDATA%\%RABBITMQ_SERVICENAME%\log\%RABBITMQ_NODENAME%.log
    > - ***eg. C:\Users\icoder\AppData\Roaming\RabbitMQ\log\rabbit@xxx.log***
- **Dump**
    > - %RABBITMQ_BASE%\erl_crash.dump
    > - %APPDATA%\%RABBITMQ_SERVICENAME%\erl_crash.dump
    > - ***eg. C:\Users\icoder\AppData\Roaming\RabbitMQ\erl_crash.dump***


　

## # Port Access
- **4369**: [epmd](https://www.erlang.org/doc/man/epmd.html), a peer discovery service used by RabbitMQ nodes and CLI tools.
- **5672, 5671**: used by AMQP 0-9-1 and 1.0 clients without and with TLS.
- **25672**: used for inter-node and CLI tools communication.
- **35672-35682**: used by CLI tools (Erlang distribution client ports) for communication with nodes.
- **15672**: [HTTP API](https://www.rabbitmq.com/management.html) clients, [management UI](https://www.rabbitmq.com/management.html) and [rabbitmqadmin](https://www.rabbitmq.com/management-cli.html) (only if the [management plugin](https://www.rabbitmq.com/management.html) is enabled).
- **61613, 61614**: [STOMP clients](https://stomp.github.io/stomp-specification-1.2.html) without and with TLS (only if the [STOMP plugin](https://www.rabbitmq.com/stomp.html) is enabled).
- **1883, 8883**: [MQTT clients](https://mqtt.org/) without and with TLS, if the [MQTT plugin](https://www.rabbitmq.com/mqtt.html) is enabled.
- **15674**: STOMP-over-WebSockets clients (only if the [Web STOMP plugin](https://www.rabbitmq.com/web-stomp.html) is enabled).
- **15675**: MQTT-over-WebSockets clients (only if the [Web MQTT plugin](https://www.rabbitmq.com/web-mqtt.html) is enabled).