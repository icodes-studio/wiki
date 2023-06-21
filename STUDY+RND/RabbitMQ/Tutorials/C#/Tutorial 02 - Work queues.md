## Tutorial.2 - "Work queues"
> *Distributing tasks among workers*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Work Queues — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-two-dotnet.html)

‌
![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-two.png)
‌

## # Preparation
- **Work Queues**
    - *aka: Task Queues*
    - 분산처리 시스템을 구축하기 위해 사용.
    - 여러 작업자(worker)로 분산하는 데 사용할 큐를 생성.
    - This concept is especially useful in web applications where it's impossible to handle a complex task during a short HTTP request window.

- **Program overview**
    - 점이 찍힌 복잡한 작업을 나타내는 문자열을 보냄.
    - 문자열을 받으면 점 하나에 1초 Thread.Sleep() 호출
    - 예를 들어 Hello...로 보낸 작업은 3초 딜레이.
    - 작업자가 바쁜 경우 어떻게 효율적으로 분산처리 시킬지 알아보기 위한 간단한 시뮬레이션.

- **Generate two projects**
    - Like tutorial one we need to generate two projects.
        ```
        dotnet new console --name NewTask
        mv NewTask/Program.cs NewTask/NewTask.cs
        dotnet new console --name Worker
        mv Worker/Program.cs Worker/Worker.cs
        cd NewTask
        dotnet add package RabbitMQ.Client
        cd ../Worker
        dotnet add package RabbitMQ.Client
        ```

- **NewTask.cs**
    - 일단 아래 코드로 업데이트 (완성된 전체코드 아님)
        ```
        using System;
        using RabbitMQ.Client;
        using System.Text;
         
        class NewTask
        {
            public static void Main(string[] args)
            {
                var factory = new ConnectionFactory() { HostName = "localhost" };
                using (var connection = factory.CreateConnection())
                using (var channel = connection.CreateModel())
                {
                    channel.QueueDeclare(
                        queue: "task_queue",
                        durable: false,
                        exclusive: false,
                        autoDelete: false,
                        arguments: null);
         
                    var message = GetMessage(args);
                    var body = Encoding.UTF8.GetBytes(message);
         
                    channel.BasicPublish(
                        exchange: "",
                        routingKey: "task_queue",
                        basicProperties: null,
                        body: body);
         
                    Console.WriteLine(" [x] Sent {0}", message);
                }
         
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
            }
         
            private static string GetMessage(string[] args)
            {
                return ((args.Length > 0) ? string.Join(" ", args) : "Hello World!");
            }
        }
        ```

    - 이전 튜토리얼 Send.cs와 다른 부분
        - *큐 이름 변경 - task_queue*
        - *프로그램 아규먼트로 메시지를 입력받음.*

- **Workers.cs**
    - 일단 아래 코드로 업데이트 (완성된 전체코드 아님)
        ```
        using System;
        using RabbitMQ.Client;
        using RabbitMQ.Client.Events;
        using System.Text;
        using System.Threading;
         
        class Worker
        {
            public static void Main()
            {
                var factory = new ConnectionFactory() { HostName = "localhost" };
                using (var connection = factory.CreateConnection())
                using (var channel = connection.CreateModel())
                {
                    channel.QueueDeclare(
                        queue: "task_queue",
                        durable: false,
                        exclusive: false,
                        autoDelete: false,
                        arguments: null);
         
                    Console.WriteLine(" [*] Waiting for messages.");
         
                    var consumer = new EventingBasicConsumer(channel);
                    consumer.Received += (model, ea) =>
                    {
                        byte[] body = ea.Body.ToArray();
                        var message = Encoding.UTF8.GetString(body);
                        Console.WriteLine(" [x] Received {0}", message);
         
                        int dots = message.Split('.').Length - 1;
                        Thread.Sleep(dots * 1000);
                        Console.WriteLine(" [x] Done");
                    };
         
                    channel.BasicConsume(
                        queue: "task_queue",
                        autoAck: true,
                        consumer: consumer);
         
                    Console.WriteLine(" Press [enter] to exit.");
                    Console.ReadLine();
                }
            }
        }
        ```

    - 이전 튜토리얼 Rceive.cs와 다른 부분
        - *큐 이름 변경 - task_queue*
        - *메시지 중 도트(.) 갯수만큼 1초 딜레이*

‌
　

## # Round-robin dispatching
- **One of the advantages of using a Task Queue**
    - 작업을 쉽게 병렬화할 수 있다.
    - 태스크가 많아서 처리가 밀리는 경우, 더 많은 Worker를 추가하여 쉽게 스케일링 할 수 있다.
- **Round-robin dispatching**
    - 먼저 Worker가 어떻게 동작하는지 살펴보자.
    - 두 개 콘솔에 Worker 프로그램을 구동.
        ```
        # shell 1
        cd Worker
        dotnet run
        # => Press [enter] to exit.
        ```
        ```
        # shell 2
        cd Worker
        dotnet run
        # => Press [enter] to exit.
        ```
    - 세 번 째 콘솔에서 새로운 태스크들을 발행.
        ```
        # shell 3
        cd NewTask
        dotnet run "First message."
        dotnet run "Second message.."
        dotnet run "Third message..."
        dotnet run "Fourth message...."
        dotnet run "Fifth message....."
        ```
    - 두 Worker 프로그램은 아래처럼 동작할 것이다.
        ```
        # shell 1
        # => Press [enter] to exit.
        # => [x] Received First message.
        # => [x] Done
        # => [x] Received Third message...
        # => [x] Done
        # => [x] Received Fifth message.....
        # => [x] Done
        ```
        ```
        # shell 2
        # => Press [enter] to exit.
        # => [x] Received Second message..
        # => [x] Done
        # => [x] Received Fourth message....
        # => [x] Done
        ```
    - 기본적으로...
        - 각 메시지를 Consumer들에게 순서대로 보냄.
        - 이러한 메시지 배포 방식을 ***"Round-Robin"*** 이라고 한다.
    - 문제점
        - Worker가 busy 해도 순서가 되면 무조건 디스패치.
        - 바쁜 놈은 바쁘고 한가한 놈은 한가해 질수 있다.
        - 메시지 응답을 활용하여 효율적인 디스패치를 구현할수 있다.

‌
　

## # Message acknowledgment
- **메시지 응답이 필요한 또 다른 이유**
    - 작업을 수행하는 데 몇 초가 걸릴 수 있다.
    - 긴 작업을 시작한 Consumer가 작업 도중 죽어버리면 어떻게 될까?
    - 현재 테스트 중인 코드를 사용하면, 메시지는 Consumer에게 전달되면 바로 삭제됨.
    - 결국, 아직 처리되지 않은 메시지는 날라감.
    - 작업이 다른 Worker에게 전달되기를 원한다!
- **RabbitMQ supports message acknowledgments**
    - Consumer가 특정 메시지를 수신하고 처리했으며 RabbitMQ가 이를 자유롭게 삭제할 수 있음을 알리기 위해 ACK 전송.
    - Consumer가 ACK를 보내지 않고 죽으면 RabbitMQ는 메시지가 완전히 처리되지 않았다고 판단하고 다시 큐에 넣는다.
    - 동시에 다른 Consumer에게 빠르게 다시 전달.
    - 이런 구조로 메시지가 손실되지 않도록 할 수 있다.
    - ACK 응답 타임아웃
        - 30 minutes by default
        - You can increase this timeout as described in [***Delivery Acknowledgement Timeout***](https://www.rabbitmq.com/consumers.html#acknowledgement-timeout)
- **코드 업데이트** - *Worker.cs*
    - After the existing WriteLine, add a call to ***BasicAck*** and update BasicConsume with ***autoAck:false***
        ```
            Console.WriteLine(" [x] Done");
         
            // Note: it is possible to access the channel via
            //       ((EventingBasicConsumer)sender).Model here
            channel.BasicAck(deliveryTag: ea.DeliveryTag, multiple: false);
        };
        channel.BasicConsume(
            queue: "hello",
            autoAck: false,
            consumer: consumer);
        ```
    - 메시지를 처리하는 동안 Worker를 죽이면 다른 Worker에게 메시지가 다시 전달된다.
- **Forgotten acknowledgment**
    - BasicAck를 날리지 않는 것은 흔한 실수.
    - BUT, 결과는 심각.
    - RabbitMQ는 메시지를 해제할 수 없기 때문에 점점 더 많은 메모리를 사용하게 된다.
    - 이러한 실수를 디버깅하기 위해 rabbitmqctl을 사용하여 messages_unacknowledged 필드를 확인 할 수 있다.
        ```
        rabbitmqctl.bat list_queues name messages_ready messages_unacknowledged
        ```
    - 또는 Management UI 확인

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/unacked.png)

‌
　

## # Message durability
- **If RabbitMQ server stops**
    - RabbitMQ 서버가 죽으면 메시지와 태스크는 날라간다.
    - 메시지가 손실되지 않도록 하려면 큐와 메시지에 관련 속성(durable, persistent)을 설정해야 한다.
- **Queue에 durable 속성 설정**
    - NewTask.cs, Worker.cs 둘 다 코드 업데이트
    - 큐의 durable 속성을 true로 설정
    - ***주의: 기존에 durable:false로 생성된 큐는 미리 삭제 해야한다.***
        ```
        channel.QueueDeclare(
            queue: "task_queue",
            durable: true,
            exclusive: false,
            autoDelete: false,
            arguments: null);
        ```
- **발행 메시지에 persistent 속성 설정**
    - NewTask.cs 코드 업데이트
    - 발행 메시지 persistent 속성을 true로 설정
        ```
        var properties = channel.CreateBasicProperties();
        properties.Persistent = true;
        　
        channel.BasicPublish(
            exchange: "",
            routingKey: "task_queue",
            basicProperties: properties,
            body: body);
        ```
- **Note on Message Persistence**
    - 이러한 메시지 persistent 방식은 완벽한 복구를 보장하지 못한다.
    - 으... 응?
    - Although it tells RabbitMQ to save the message to disk, there is still a short time window when RabbitMQ has accepted a message and hasn't saved it yet. Also, RabbitMQ doesn't do fsync(2) for every message -- it may be just saved to cache and not really written to the disk.
    - The persistence guarantees aren't strong, but it's more than enough for our simple task queue.
    - 강력한 복구 시나리오를 적용하려면 [***Publisher Confirms 레퍼런스***](https://www.rabbitmq.com/confirms.html)참고.
    - [***7번째 튜토리얼 - Publisher Confirms***](https://www.rabbitmq.com/tutorials/tutorial-seven-dotnet.html)에서도 쉽게 설명하고 있음.

‌
　

## # Fair Dispatch
- **디스패치 개선**
    - 바쁜 놈은 바쁘고 한가한 놈은 한가 하게 운영 될 수 있다.
    - 메시지가 큐에 들어올 때 RabbitMQ가 Worker들의 상태를 살피지 않고 무조건 순서대로 디스패치를 하기 때문.
    - 즉, Consumer의 unacknowledged messages의 갯수는 고려하지 않는다.
- **BasicQos 메서드 호출 with prefetchCount=1**
    - Worker에게 한 번에 하나 이상의 메시지를 주지 않도록 한다.
    - 즉, ACK를 받기 전까지 이 Worker에게 메시지 디스패치 안 됨.
    - 대신 아직 사용 중이 아닌 다음 작업자에게 전달.
- **코드 업데이트** - *Worker.cs*
    - After the existing QueueDeclare in Worker.cs add the call to BasicQos:
        ```
        channel.QueueDeclare(
            queue: "task_queue",
            durable: true,
            exclusive: false,
            autoDelete: false,
            arguments: null);
        channel.BasicQos(prefetchSize: 0, prefetchCount: 1, global: false);
        ```

        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/prefetch-count.png)


　‌

## # Putting it all together
- Open two terminals.
- Run the consumer (worker) first so that the topology (primarily the queue) is in place.
- [***Here is its complete code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/Worker/Worker.cs)
    ```
    using System;
    using System.Text;
    using System.Threading;
    using RabbitMQ.Client;
    using RabbitMQ.Client.Events;
     
    class Worker
    {
        public static void Main()
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.QueueDeclare(
                    queue: "task_queue",
                    durable: true,
                    exclusive: false,
                    autoDelete: false,
                    arguments: null);
     
                channel.BasicQos(prefetchSize: 0, prefetchCount: 1, global: false);
     
                Console.WriteLine(" [*] Waiting for messages.");
     
                var consumer = new EventingBasicConsumer(channel);
                consumer.Received += (model, ea) =>
                {
                    byte[] body = ea.Body.ToArray();
                    var message = Encoding.UTF8.GetString(body);
                    Console.WriteLine(" [x] Received {0}", message);
     
                    int dots = message.Split('.').Length - 1;
                    Thread.Sleep(dots * 1000);
                    Console.WriteLine(" [x] Done");
     
                    // here channel could also be accessed as ((EventingBasicConsumer)sender).Model
                    channel.BasicAck(deliveryTag: ea.DeliveryTag, multiple: false);
                };
     
                channel.BasicConsume(
                    queue: "task_queue",
                    autoAck: false,
                    consumer: consumer);
     
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
            }
        }
    }
    ```
- Now run the task publisher.
- [***Its final code is...***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/NewTask/NewTask.cs)
    ```
    using System;
    using System.Text;
    using RabbitMQ.Client;
     
    class NewTask
    {
        public static void Main(string[] args)
        {
            var factory = new ConnectionFactory() { HostName = "localhost" };
            using (var connection = factory.CreateConnection())
            using (var channel = connection.CreateModel())
            {
                channel.QueueDeclare(
                    queue: "task_queue",
                    durable: true,
                    exclusive: false,
                    autoDelete: false,
                    arguments: null);
     
                var message = GetMessage(args);
                var body = Encoding.UTF8.GetBytes(message);
                var properties = channel.CreateBasicProperties();
                properties.Persistent = true;
     
                channel.BasicPublish(
                    exchange: "",
                    routingKey: "task_queue",
                    basicProperties: properties,
                    body: body);
     
                Console.WriteLine(" [x] Sent {0}", message);
            }
     
            Console.WriteLine(" Press [enter] to exit.");
            Console.ReadLine();
        }
     
        private static string GetMessage(string[] args)
        {
            return ((args.Length > 0) ? string.Join(" ", args) : "Hello World!");
        }
    }
    ```
