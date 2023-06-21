## Tutorial.1 "Hello World!"
> - *The simplest thing that does something*
> - ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - "Hello World!" — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-one-dotnet.html)

　

　

## # Introduction
- **RabbitMQ는 메시지 브로커**
    - 메시지를 수락하고 전달.
    - 우체국으로 생각할 수 있다.
    - 게시하려는 우편물을 우체통에 넣으면 편지 배달부가 결국 우편물을 받는 사람에게 배달할 것이라고 확신할 수 있다.
    - 가장 큰 차이점은 종이 대신 이진 데이터를 다룬 다는 것.
- **전문용어**
    - _**Producing**_
        - 메시지 보내기.
        - 메시지를 보내는 프로그램은 _Producer_

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/producer.png)

    - _**A queue**_
        - RabbitMQ 내부에 있는 우편함의 이름.
        - 메시지는 큐 내부에만 저장할 수 있다.
        - 큐는 호스트의 메모리 및 디스크 크기에 의해서만 제한되므로, 본질적으로 큰 메시지 버퍼이다.
        - 많은 Producer가 한 개 큐로 가는 메시지를 보낼 수 있고 많은 Consumer가 한 개 큐에서 데이터 수신을 시도할 수 있다.

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/queue.png)

    - _**Consuming**_
        - Consumer는 메시지 수신을 기다리는 프로그램.

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/consumer.png)

    - Producer, Consumer 및 Broker가 동일한 호스트에 상주할 필요는 없다.
    - 애플리케이션은 Producer와 Consumer 모두가 될 수도 있다.


　

## # "Hello World"
- 두 개의 프로그램을 작성
    - 하나의 메시지를 보내는 - _**Producer**_
    - 메시지를 받아 출력하는 - _**Consumer**_
    - 메시지 - _**"Hello World"**_

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-one.png)

- **The .NET client library**
    - 메시징을 위한 개방형 범용 프로토콜인 * **AMQP 0-9-1 ** *을 사용.
    - RabbitMQ에서 제공하는 .NET 클라이언트를 사용.
    - 클라이언트는 .NET Core 및 .NET Framework 4.5.1 이상을 지원.
    - 여기서는 RabbitMQ .NET 클라이언트 5.0 및 .NET Core를 사용.
    - Windows에서 _**Powershell **_을 사용하고 있다고 가정.


　

## # Setup
- **.NET Core toolchain PATH 설정 확인**
    ```
    dotnet --help
    ```
    - 위 명령의 도움말이 잘 나오는지 확인.
- **Publisher와 Consumer를 위한 두 개의 콘솔 프로젝트 생성**
    ```
    dotnet new console --name Send
    mv Send/Program.cs Send/Send.cs
    dotnet new console --name Receive
    mv Receive/Program.cs Receive/Receive.cs
    ```
    - Send와 Receive 이름을 가지는 새로운 디렉토리 생성됨.
    - CS 파일은 이름 좀 예쁘게 바꿔주고...
- **RabbitMQ.Client 라이브러리 패키지 추가**
    ```
    cd Send
    dotnet add package RabbitMQ.Client
    cd ../Receive
    dotnet add package RabbitMQ.Client
    ```
    - 준비 완료


　

## # Sending
- Publisher는 RabbitMQ에 접속하고 메시지 보낸 후 종료

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/sending.png)

- _**Send.cs -**_ [_**Final code**_](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/Send/Send.cs "‌")
    - 필요한 namespace 추가
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;    
    ```
    - 클래스 셋업
    ```
    class Send
    {
        public static void Main()
        {
            ...
        }
    }
    ```
    - 서버 Connection 생성
    - 소켓 연결 추상화로 프로토콜 버전 협상 및 인증 등을 처리
    - 여기서는 로컬 머신의 RabbitMQ 노드에 연결
    - 작업할 채널(세션)을 만듬.
    ```
    class Send
    {
        public static void Main()
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                ...
            }
        }
    }
    ```
    - 메시지를 보내기 위해 큐를 선언 (없으면 생성)
    - 메시지를 byte array로 인코딩한 후 전송(Publish)
    - 전송 완료 후 channel과 connection은 dispose 됨.
    ```
    using System;
    using RabbitMQ.Client;
    using System.Text;
    　
    class Send
    {
        public static void Main()
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using(var connection = factory.CreateConnection())
            using(var channel = connection.CreateModel())
            {
                channel.QueueDeclare(
                    queue: "hello",
                    durable: false,
                    exclusive: false,
                    autoDelete: false,
                    arguments: null);
    　
                string message = "Hello World!";
                var body = Encoding.UTF8.GetBytes(message);
    　
                channel.BasicPublish(
                    exchange: "",
                    routingKey: "hello",
                    basicProperties: null,
                    body: body);
                Console.WriteLine(" [x] Sent {0}", message);
            }
    　
            Console.WriteLine(" Press [enter] to exit.");
            Console.ReadLine();
        }
    }
    ```


　

## # Receiving
- Publisher는 메시지 보낸 후 종료했었지만, Consumer는 계속 실행하여 메시지 수신하고 출력

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/receiving.png)
  ‌
- _**Receive.cs -**_ [_**Final code**_](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/Receive/Receive.cs "‌")
    - 필요한 namespace 추가
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;
    using RabbitMQ.Client.Events;
    ```
    - 클랫스 셋업은 publisher와 동일함.
    ```
    class Receive
    {
        public static void Main()
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.QueueDeclare(
                    queue: "hello",
                    durable: false,
                    exclusive: false,
                    autoDelete: false,
                    arguments: null);
                ...
            }
        }
    }
    ```
- 큐에서 메시지 전달받기
    ```
    using RabbitMQ.Client;using RabbitMQ.Client.Events;
    using System;
    using System.Text;
    　
    class Receive
    {
        public static void Main()
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using(var connection = factory.CreateConnection())
            using(var channel = connection.CreateModel())
            {
                channel.QueueDeclare(
                    queue: "hello",
                    durable: false,
                    exclusive: false,
                    autoDelete: false,
                    arguments: null);
    　
                var consumer = new EventingBasicConsumer(channel);
                consumer.Received += (model, ea) =>
                {
                    var body = ea.Body.ToArray();
                    var message = Encoding.UTF8.GetString(body);
                    Console.WriteLine(" [x] Received {0}", message);
                };
                channel.BasicConsume(
                    queue: "hello",
                    autoAck: true,
                    consumer: consumer);
    　
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
            }
        }
    }
    ```


　

## # Putting it all together
- Open two terminals.
- You can run the clients in any order, as both declares the queue. We will run the consumer first so you can see it waiting for and then receiving the message:
    ```
    cd Receive
    dotnet run
    ```
- Then run the producer:
    ```
    cd Send
    dotnet run
    ```
- The consumer will print the message it gets from the publisher via RabbitMQ. The consumer will keep running, waiting for messages, so try restarting the publisher several times.