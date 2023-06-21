## Tutorial.5 - Topics
> *Receiving messages based on a pattern*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Topics — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-five-dotnet.html)
>
>　

　

## # Topics

- **로깅 시스템 개선**
    - 이전 튜토리얼에서 만든 Logging 시스템에 새 기능 추가.
    - 로그 레벨(severity)뿐만 아니라 로그가 발생된 소스 위치를 기반으로 로그를 구독할 수 있도록 업그레이드.
    - You might know this concept from the ***syslog unix tool***, which routes logs based on both severity (info/warn/crit...) and facility (auth/cron/kern...).
    - We need to learn about a more complex ***topic exchange***.
- **Topic exchange**
    - 점으로 구분된 단어 목록을 라우팅 키로 사용한다.
    - *eg. "stock.usd.nyse", "nyse.vmw", "quick.orange.rabbit"*
    - 최대 255바이트까지 사용 가능.
    - 특정 라우팅 키로 보낸 메시지는 일치하는 바인딩 키로 바인딩된 모든 큐에 전달된다.
    - **키 매칭에 와일드 문자 사용 - 패턴매칭**
        - \*(star)는 정확히 한 단어를 대체.
        - \#(hash)는 0개 이상의 단어를 대체.
- **예를 들어...**

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-five.png)

    - Q1은 모든 주황색 동물에 관심이 있다.
    - Q2는 토끼에 대한 모든 것, 게으른 동물에 대한 모든 것에 관심이 있다.
    - **이때의 메시지 라우팅은**
        - ***"quick.orange.rabbit"*** - Q1, Q2에 모두 전달
        - ***"lazy.orange.elephant"*** - Q1, Q2에 모두 전달
        - ***"quick.orange.fox"*** - Q1에 전달
        - ***"lazy.brown.fox"*** - Q2에 전달
        - ***"lazy.pink.rabbit"*** - Q2에 한 번만 전달
        - ***"quick.brown.fox"*** - 삭제
        - ***"orange"*** - 삭제
        - ***"quick.orange.male.rabbit"*** - 삭제.
        - ***"lazy.orange.male.rabbit"*** - Q2에 전달
- **Topic exchange can behave like other exchanges**
    - 바인딩 키로 "#"(hash)만 사용되면 **Fanout** 처럼 동작.
    - 바인딩 키로 "*"(star)와 "#"(hash)가 사용되지 않으면 **Direct** 처럼 동작.
    - 라우팅 패턴이 여러 개 일치하더라도 하나의 큐에는 메세지가 한 번만 전달.


　

## # Final code

- ***EmitLogTopic.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/EmitLogTopic/EmitLogTopic.cs)
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;
     
    class EmitLogTopic
    {
        public static void Main(string[] args)
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.ExchangeDeclare(exchange: "topic_logs", type: "topic");
     
                var routingKey = (args.Length > 0) ? args[0] : "anonymous.info";
                var message = (args.Length > 1) ? string.Join(" ", args.Skip(1).ToArray()) : "Hello World!";
                var body = Encoding.UTF8.GetBytes(message);
     
                channel.BasicPublish(
                    exchange: "topic_logs",
                    routingKey: routingKey,
                    basicProperties: null,
                    body: body);
     
                Console.WriteLine(" [x] Sent '{0}':'{1}'", routingKey, message);
            }
        }
    }
    ```
- ***ReceiveLogsTopic.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/ReceiveLogsTopic/ReceiveLogsTopic.cs)
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;
    using RabbitMQ.Client.Events;
     
    class ReceiveLogsTopic
    {
        public static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.Error.WriteLine("Usage: {0} [binding_key...]", Environment.GetCommandLineArgs()[0]);
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
                Environment.ExitCode = 1;
                return;
            }
     
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.ExchangeDeclare(exchange: "topic_logs", type: "topic");
                var queueName = channel.QueueDeclare(queue: "").QueueName;
     
                foreach (var bindingKey in args)
                {
                    channel.QueueBind(
                        queue: queueName,
                        exchange: "topic_logs",
                        routingKey: bindingKey);
                }
     
                Console.WriteLine(" [*] Waiting for messages. To exit press CTRL+C");
     
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


　

## # Putting it all together

- **To receive all the logs:**
    ```
    cd ReceiveLogsTopic
    dotnet run "#"
    ```
- **To receive all logs from the facility "kern":**
    ```
    cd ReceiveLogsTopic
    dotnet run "kern.*"
    ```
- **Or if you want to hear only about "critical" logs:**
    ```
    cd ReceiveLogsTopic
    dotnet run "*.critical"
    ```
- **You can create multiple bindings:**
    ```
    cd ReceiveLogsTopic
    dotnet run "kern.*" "*.critical"
    ```
- **And to emit a log with a routing key "kern.critical" type:**
    ```
    cd EmitLogTopic
    dotnet run "kern.critical" "A critical kernel error"
    ```