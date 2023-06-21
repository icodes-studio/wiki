## Tutorial.4 - Routing
> *Receiving messages selectively*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Routing — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-four-dotnet.html)

　‌

‌　

## # Routing & Binding

- **로깅 시스템 개선**
    - 이전 튜토리얼에서 만든 Logging 시스템에 새 기능 추가.
    - 메시지의 일부만 선택적으로 구독하는 시스템.
    - 모든 로그 메시지를 구독하여 화면에 출력하는 로거
    - 디스크 절약을 위해 중요한 오류 메시지만 파일에 저장하는 로거

- **선택적 바인딩**
    - 이전 튜토리얼에서는 큐를 익스체인지에 바인딩 할때 ***routingKey*** 인자를 사용하지 않았다.
        ```
        channel.QueueBind(
            queue: queueName,
            exchange: "logs",
            routingKey: "");
        ```
    - ***routingKey*** 인자를 바인딩 키로 사용해 보자.
        ```
        channel.QueueBind(
            queue: queueName,
            exchange: "direct_logs",
            routingKey: "black");
        ```
    - 바인딩 키의 의미는 익스체인지 타입에 따라 다르다.
    - ***Fanout:*** *바인딩 키는 아무 의미 없음.*
    - ***Direct:*** *라우팅 키와 바인딩 키가 일치하는 큐로 메시지 이동.*

‌
　

## # Direct exchange

- **로깅 시스템 개선**
    - 이전 로깅 시스템은 모든 메시지를 모든 컨슈머에게 브로드캐스트.
    - 로그 레벨(severity)에 따라 메시지를 필터링할 수 있도록 확장해보자.
    - For example we may want the script which is writing log messages to the disk to only receive ***critical errors*** , and ***not waste disk space*** on warning or info log messages.

- **Fanout vs Direct**
    - Fanout 방식은 그저 생각없이 브로드캐스팅만 한다.
    - 확장성 없음.
    - 여기서는 ***"Direct"*** 방식을 사용할 거임.
    - 메시지는 라우팅 키와 바인딩 키가 정확히 일치하는 큐로 이동.

- **To illustrate that, consider the following setup**
    - Q1은 ***"orange"*** 키로 바인딩.
    - Q2는 ***"black"*** 그리고 ***"green"*** 두 키로 바인딩
    - 이러한 설정에서 ***"orange"*** 라우팅 키로 익스체인지에 게시되는 메시지는 Q1으로 라우팅 된다.
    - ***"black"*** 또는 ***"green"*** 라우팅 키가 있는 메시지는 Q2로 전달된다.
    - 그 외 다른 메시지는 삭제.

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/direct-exchange.png)

- **Multiple bindings**
    - 동일한 바인딩 키로 여러 큐를 바인딩 할 수 있다.
    - 즉, ***"black"*** 을 사용하여 X와 Q1 사이에 바인딩을 추가할 수 있다.
    - 이 경우 Direct는 Fanout처럼 작동
    - 즉, 라우팅 키가 black인 메시지는 Q1과 Q2 모두에 전달.

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/direct-exchange-multiple.png)

‌
　

## # Emitting logs

- **로깅 시스템 개선**
    - Fanout 대신 ***Direct*** 익스체인지에 메시지를 보낸다.
    - 로그 레벨(severity)을 라우팅 키로 사용한다.
    - 그런 식으로 수신 스크립트는 로그 레벨을 선택할 수 있다.
- **We need to create an exchange first:**
    ```
    channel.ExchangeDeclare(exchange: "direct_logs", type: "direct");
    ```
- **And we're ready to send a message:**
    ```
    var body = Encoding.UTF8.GetBytes(message);
    channel.BasicPublish(
        exchange: "direct_logs",
        routingKey: severity,
        basicProperties: null,
        body: body);
    ```
    - 로그 레벨은 ***'info', 'warning', 'error'*** 중 하나라고 가정하자.

‌
　

## # Subscribing

- **로그 레벨에 따른 큐 바인딩**
    ```
    var queueName = channel.QueueDeclare().QueueName;
    　
    foreach(var severity in args)
    {
        channel.QueueBind(
            queue: queueName,
            exchange: "direct_logs",
            routingKey: severity);
    }
    ```

‌
　

## # Final code

- ***EmitLogDirect.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/EmitLogDirect/EmitLogDirect.cs)
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;
     
    class EmitLogDirect
    {
        public static void Main(string[] args)
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.ExchangeDeclare(exchange: "direct_logs", type: "direct");
     
                var severity = (args.Length > 0) ? args[0] : "info";
                var message = (args.Length > 1) ? string.Join(" ", args.Skip(1).ToArray()) : "Hello World!";
                var body = Encoding.UTF8.GetBytes(message);
     
                channel.BasicPublish(
                    exchange: "direct_logs",
                    routingKey: severity,
                    basicProperties: null,
                    body: body);
     
                Console.WriteLine(" [x] Sent '{0}':'{1}'", severity, message);
            }
     
            Console.WriteLine(" Press [enter] to exit.");
            Console.ReadLine();
        }
    }
    ```
- ***ReceiveLogsDirect.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/ReceiveLogsDirect/ReceiveLogsDirect.cs)
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;
    using RabbitMQ.Client.Events;
     
    class ReceiveLogsDirect
    {
        public static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.Error.WriteLine("Usage: {0} [info] [warning] [error]", Environment.GetCommandLineArgs()[0]);
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
                Environment.ExitCode = 1;
                return;
            }
     
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.ExchangeDeclare(exchange: "direct_logs", type: "direct");
                var queueName = channel.QueueDeclare().QueueName;
     
                foreach (var severity in args)
                {
                    channel.QueueBind(
                        queue: queueName,
                        exchange: "direct_logs",
                        routingKey: severity);
                }
     
                Console.WriteLine(" [*] Waiting for messages.");
     
                var consumer = new EventingBasicConsumer(channel);
                consumer.Received += (model, ea) =>
                {
                    var body = ea.Body.ToArray();
                    var message = Encoding.UTF8.GetString(body);
                    var routingKey = ea.RoutingKey;
                    Console.WriteLine(" [x] Received '{0}':'{1}'", routingKey, message);
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

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-four.png)

- **If you want to save only 'warning' and 'error' (and not 'info') log messages to a file, just open a console and type:**
    ```
    cd ReceiveLogsDirect
    dotnet run warning error > logs_from_rabbit.log
    ```
- **If you'd like to see all the log messages on your screen, open a new terminal and do:**
    ```
    cd ReceiveLogsDirect
    dotnet run info warning error
    # => [*] Waiting for logs. To exit press CTRL+C
    ```
- **And, for example, to emit an error log message just type:**
    ```
    cd EmitLogDirect
    dotnet run error "Run. Run. Or it will explode."
    # => [x] Sent 'error':'Run. Run. Or it will explode.'
    ```