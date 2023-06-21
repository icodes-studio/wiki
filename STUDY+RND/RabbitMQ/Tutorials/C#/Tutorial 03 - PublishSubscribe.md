## Tutorial.3 - Publish/Subscribe
> *Sending messages to many consumers at once*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Publish/Subscribe — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-three-dotnet.html)

　‌

‌　

## # Publish/Subscribe

- **개요**
    - 지금까지 한 Task가 한 Worker에게 전달되는 것을 알아봄.
    - 여기서는 여러 Consumer들에게 메시지가 전달되는 것을 알아본다.
    - 이러한 패턴을 ***"Publish/Subscribe"*** 라고 한다.

- **Simple Logging System**
    - 패턴을 설명하기 위해 간단한 로깅 시스템을 구축할 거임.
    - 동일한 로그 메시지를 수신하는 Receiver Program(Consumer) 두 개.
    - 수신한 로그를 ***"파일에 저장"*** 하는 Consumer 하나.
    - 동시에 로그를 ***"화면에 표시"*** 하는 Consumer 하나.

‌
　

## # Exchanges

- **Let's quickly go over what we covered in the previous tutorials**
    - Producer는 메시지를 보내는 애플리케이션.
    - Queue는 메시지를 저장하는 버퍼.
    - Consumer는 메시지를 수신하는 애플리케이션.
- **Now it's time to introduce the full messaging model in Rabbit**
    - Producer는 Exchange에 메시지를 보낸다.
    - Exchange의 한쪽에서는 Producer로부터 메시지를 수신.
    - Exchange의 다른 쪽에서는 Queue로 메시지 푸시.
    - Exchange는 수신한 메시지로 무엇을 해야 하는지 정확히 알고 있어야 한다.
        - 특정 Queue에 추가해야 할지...
        - 여러 Queue에 추가해야 할지...
        - 아니면 갈곳이 없어 폐기해야 할지...
        - 이에 대한 규칙은 ***"Exchange type"*** 에 따라 정의 된다.

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/exchanges.png)

- **Exchange Type**
    - direct
    - topic
    - headers
    - ***fanout*** - *여기서 자세히 알아볼 타입*

- **Fanout**
    - ***"logs"*** 이름을 가지는 ***Fanout*** 타입의 익스체인지를 만들자.
        ```
        channel.ExchangeDeclare("logs", ExchangeType.Fanout);
        ```
    - 이 Exchange와 바인딩 된 모든 Queue로 메시지 브로드캐스트

- **Listing exchanges**
    - 서버의 익스체인지 목록을 확인하려면 rabbitmqctl.bat 명령어 사용
        ```
        rabbitmqctl.bat list_exchanges
        ```
    - 또는 Management UI로 확인 가능

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/current-exchanges.png)

    - In this list there will be some amq.\* exchanges and the default (unnamed) exchange. ***These are created by default*** , but it is unlikely you'll need to use them at the moment.

- **The default exchange**
    - 이전 튜토리얼에서 우리는 익스체인지에 대해 아무것도 몰랐지만, 큐에 메시지를 보낼수 있었다.
    - 그게 가능했던 이유는 ***"디폴트 익스체인지(공백 문자로 지정)"*** 를 사용했기 때문.
    - 이전에 어떻게 메시지를 보냈는지 기억해보자.
        ```
        var message = GetMessage(args);
        var body = Encoding.UTF8.GetBytes(message);
        channel.BasicPublish(
            exchange: "",
            routingKey: "hello",
            basicProperties: null,
            body: body);
        ```
    - 생성되는 모든 큐는 자동으로 디폴트 익스체인지에 바인딩된다.
    - 디폴트 익스체인지는 direct 타입
    - 메시지는 routingKey에 지정된 이름을 가진 큐에 라우팅된다.

- **Now, we can publish to our named exchange instead:**
    - 익스체인지 이름은 ***"logs"***
        ```
        var message = GetMessage(args);
        var body = Encoding.UTF8.GetBytes(message);
        channel.BasicPublish(
            exchange: "logs",
            routingKey: "",
            basicProperties: null,
            body: body);
        ```
    - *Tip: A routingKey value is ignored for fanout exchanges.*



‌

## # Temporary queues
- **Logger의 Queue**
    - 이전 튜토리얼에서는 큐에 이름을 지정하여 생성했고...
    - Producer와 Consumer가 동일한 큐 이름을 가리키도록 했다.
    - Producer와 Consumer간에 큐를 공유하려면 이름을 지정하는 것이 중요.
    - 하지만, 로거는 일부가 아닌 모든 로그 메시지를 수신해야 한다.
    - 또한, 이전 메시지가 아닌 현재 flowing 메시지에만 관심이 있다.
- **To solve that we need...**
    - RabbitMQ에 접속할 때마다 새로운 빈 큐가 필요.
    - 그러기 위해, 랜덤한 이름을 가지는 큐를 생성.
    - Consumer 연결을 끊으면 Queue가 자동으로 삭제되어야 한다.
- **when we supply no parameters to QueueDeclare()**
    - we create a...
    - **non-durable**
    - **exclusive**
    - **autodelete**
    - queue with a generated name:
        ```
        var queueName = channel.QueueDeclare().QueueName;
        ```
    - eg. queueName = ***amq.gen-JzTY20BRgKO-HjmUJj0wLg***

‌
　

## # Bindings

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/bindings.png)

- **QueueBind()**
    - We've already created a fanout exchange and a queue.
    - Now we need to tell the exchange to send messages to our queue.
    - That relationship between exchange and a queue is called a binding.
        ```
        channel.QueueBind(
            queue: queueName,
            exchange: "logs",
            routingKey: "");
        ```
    - From now on the logs exchange will append messages to our queue.
- **Listing bindings**
    - You can list existing bindings using, you guessed it,
        ```
        rabbitmqctl.bat list_bindings
        ```
    - Management UI에서도 확인 가능

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/list_bindings.png)

‌
　

## # Final code

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-three-overall.png)

- ***EmitLog.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/EmitLog/EmitLog.cs)
    - We now want to publish messages to our _"logs"_ exchange.
    - A routingKey value is ignored for fanout exchanges.
        ```
        using System;
        using System.Text;
        using RabbitMQ.Client;
         
        class EmitLog
        {
            public static void Main(string[] args)
            {
                var factory = new ConnectionFactory() { HostName = "localhost" };
                using (var connection = factory.CreateConnection())
                using (var channel = connection.CreateModel())
                {
                    channel.ExchangeDeclare(exchange: "logs", type: ExchangeType.Fanout);
         
                    var message = GetMessage(args);
                    var body = Encoding.UTF8.GetBytes(message);
         
                    channel.BasicPublish(
                        exchange: "logs",
                        routingKey: "",
                        basicProperties: null,
                        body: body);
         
                    Console.WriteLine(" [x] Sent {0}", message);
                }
         
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
            }
         
            private static string GetMessage(string[] args)
            {
                return ((args.Length > 0) ? string.Join(" ", args) : "info: Hello World!");
            }
        }
        ```

- ***ReceiveLogs.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/ReceiveLogs/ReceiveLogs.cs)
    - 익스체인지에 바인딩된 큐가 없으면 메시지는 손실된다.
    - 즉, 컨슈머가 없으면 메시지는 안전하게 지워진다.
        ```
        using System;
        using System.Text;
        using RabbitMQ.Client;
        using RabbitMQ.Client.Events;
         
        class ReceiveLogs
        {
            public static void Main()
            {
                var factory = new ConnectionFactory() { HostName = "localhost" };
                using (var connection = factory.CreateConnection())
                using (var channel = connection.CreateModel())
                {
                    channel.ExchangeDeclare(exchange: "logs", type: ExchangeType.Fanout);
         
                    var queueName = channel.QueueDeclare().QueueName;
                    channel.QueueBind(
                        queue: queueName,
                        exchange: "logs",
                        routingKey: "");
         
                    Console.WriteLine(" [*] Waiting for logs.");
         
                    var consumer = new EventingBasicConsumer(channel);
                    consumer.Received += (model, ea) =>
                    {
                        byte[] body = ea.Body.ToArray();
                        var message = Encoding.UTF8.GetString(body);
                        Console.WriteLine(" [x] {0}", message);
                    };
         
                    channel.BasicConsume(
                        queue: queueName,
                        autoAck: true,
                        consumer: consumer);
         
                    Console.WriteLine(" Press [enter] to exit.");
                    Console.ReadLine();
                }
            }
        }
        ```


　‌

## # Putting it all together

- If you want to save logs to a file, just open a console and type:
    ```
    cd ReceiveLogs
    dotnet run > logs_from_rabbit.log
    ```
- If you wish to see the logs on your screen, spawn a new terminal and run:
    ```
    cd ReceiveLogs
    dotnet run
    ```
- And of course, to emit logs type:
    ```
    cd EmitLog
    dotnet run
    ```
- Using rabbitmqctl list_bindings you can verify that the code actually creates bindings and queues as we want. With two ReceiveLogs.cs programs running you should see something like:
    ```
    rabbitmqctl.bat list_bindings
    # => Listing bindings ...
    # => logs    exchange        amq.gen-JzTY20BRgKO-HjmUJj0wLg  queue           []
    # => logs    exchange        amq.gen-vso0PVvyiRIL2WoV3i48Yg  queue           []
    # => ...done.
    ```