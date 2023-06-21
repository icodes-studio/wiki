## Tutorial.6 - RPC
> *Request/reply pattern example*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - RPC — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-six-dotnet.html)
>　

　

## # Remote procedure call (RPC)

- **시스템 개요**
    - 원격 컴퓨터에서 기능(function)을 실행하고 결과를 기다려야 하는 경우.
    - 이러한 패턴은 Remote procedure call (RPC)로 알려져 있다.
    - 피보나치 수를 반환하는 RPC 시스템을 구축해 보자.
- **클라이언트 인터페이스 설계**
    - RPC 요청을 보내고 응답이 수신될 때까지 대기 후 결과 반환.
        ```
        var rpcClient = new RPCClient();
        Console.WriteLine(" [x] Requesting fib(30)");
        var response = rpcClient.Call("30");
        Console.WriteLine(" [.] Got '{0}'", response);
        rpcClient.Close();
        ```
- **A note on RPC**
    - RPC를 잘못 사용하면 구조가 개판이 된다.
    - 함수 호출이 로컬인지 또는 느린 RPC 인지 인식하지 못할 때.
    - 이러한 혼란은 스파게티 코드를 만들어 낼 수 있다.
    - **Consider the following advice**
        - 어떤 함수 호출이 로컬이고, 어떤 것이 원격인지 확실히 하라.
        - 시스템을 문서화하라. 구성 요소 간 종속성을 명확하게 하라.
        - 에러 및 예외 상황을 잘 핸들링 하라. (eg. timeout)
        - 의심스러운 경우 RPC를 피하고 비동기 처리를 사용하라.


　

## # Callback queue

- **Callback queue**
    - 응답을 받으려면 요청과 함께 '콜백' 큐 주소를 보내야 한다.
        ```
        var props = channel.CreateBasicProperties();
        props.ReplyTo = replyQueueName;
        　
        var messageBytes = Encoding.UTF8.GetBytes(message);
        channel.BasicPublish(
            exchange: "",
            routingKey: "rpc_queue",
            basicProperties: props,
            body: messageBytes);
        　
        // ... then code to read a response message from the callback_queue ...
        ```
- **Message properties**
    - AMQP 0-9-1 프로토콜은 14가지 메시지 속성을 정의한다.
    - 하지만 다음을 제외하고 대부분의 속성은 거의 사용되지 않는다.
        - **Persistent**
            - 메시지 persistent 유무 지정
            - [*두 번째 튜토리얼 참고*](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%23/Tutorial%2002%20-%20Work%20queues.md)
        - **DeliveryMode**
            - Persistent 속성과 같은 것을 처리한다.
        - **ContentType**
            - 인코딩의 mime-type을 기술한다.
            - *eg. application/json*
        - **ReplyTo**
            - 콜백 큐 이름을 지정하는 데 사용된다.
        - **CorrelationId**
            - RPC 응답을 요청과 매칭 시킬 때 사용하는 필드
            - 일반적인 Req/Ans 통신구조에서 사용되는 유니크 키


　

## # Correlation Id

- **콜백 큐 생성**
    - 모든 RPC 요청에 콜백 큐를 생성하는 것은 비효율적이다.
    - 클라이언트 당 하나의 콜백 큐를 생성.
- **콜백 큐를 하나만 생성하고 운용하면...**
    - 응답을 받았을 때 이 응답이 어떤 요청에 대한 응답인지 알아야 한다.
    - 이 경우 ***CorrelationId*** 속성을 사용할 수 있다.
    - 각 요청에 대해 유니크한 값으로 보내고 그대로 받는 구조.
    - 나중에 메시지를 수신하면 이 속성을 살펴보고 어떤 요청에 대한 응답 인지를 판단하고 핸들링을 분기할 수 있다.
    - 알 수 없는 CorrelationId 값이 보이면 걍 무시.
- **알 수 없는 CorrelationId 값이 생긴다고?**
    - You may ask, why should we ignore unknown messages in the callback queue, rather than failing with an error? It's due to a possibility of a race condition on the server side. Although unlikely, it is possible that the RPC server will die just after sending us the answer, but before sending an acknowledgment message for the request. If that happens, the restarted RPC server will process the request again. That's why on the client we must handle the duplicate responses gracefully, and the RPC should ideally be idempotent.


　

## # Summary

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-six.png)

- **Our RPC will work like this**
    - 클라 시작 시 ***anonymous exclusive callback queue*** 생성.
    - 한 RPC 요청에 두 속성을 가진 메시지를 보낸다.
        - ***ReplyTo***: 콜백 큐 지정_
        - ***CorrelationId***: 요청에 대한 유니크 키 값_
    - 요청은 ***"rpc_queue"*** 큐로 전송된다.
    - RPC 작업자(aka 서버)는 해당 큐에서 요청을 기다린다.
    - 요청이 들어오면, 작업을 수행하고...
    - 결과를 ***ReplyTo*** 속성에 명시된 큐에 담아서 응답 한다.
    - 클라는 콜백 큐에서 데이터를 기다린다.
    - 메시지를 응답 받으면 ***CorrelationId*** 속성을 확인하고...
    - 요청의 ***CorrelationId*** 키와 일치하는 경우만 리턴.


　

## # Final code

- ***RPCServer.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/RPCServer/RPCServer.cs)
    - We declare our fibonacci function.
    - 둘 이상의 서버 프로세스를 실행하는 경우 여러 서버에 로드를 균등하게 분산하기 위해서 ***channel.BasicQos***에서 ***prefetchCount*** 지정.
    - 응답은 ***consumer.Received*** 핸들러에서 바로 보낸다.
        ```
        using System;
        using RabbitMQ.Client;
        using RabbitMQ.Client.Events;
        using System.Text;
         
        class RPCServer
        {
            public static void Main()
            {
                var factory = new ConnectionFactory() { HostName = "localhost" };
                using (var connection = factory.CreateConnection())
                using (var channel = connection.CreateModel())
                {
                    channel.QueueDeclare(
                        queue: "rpc_queue",
                        durable: false,
                        exclusive: false,
                        autoDelete: false,
                        arguments: null);
         
                    channel.BasicQos(0, 1, false);
         
                    var consumer = new EventingBasicConsumer(channel);
                    channel.BasicConsume("rpc_queue", false, consumer);
                    Console.WriteLine(" [x] Awaiting RPC requests");
         
                    consumer.Received += (model, ea) =>
                    {
                        string response = null!;
         
                        var body = ea.Body.ToArray();
                        var props = ea.BasicProperties;
                        var replyProps = channel.CreateBasicProperties();
                        replyProps.CorrelationId = props.CorrelationId;
         
                        try
                        {
                            var message = Encoding.UTF8.GetString(body);
                            Console.WriteLine(" [.] fib({0})", message);
                            response = fib(int.Parse(message)).ToString();
                        }
                        catch (Exception e)
                        {
                            Console.WriteLine(" [.] " + e.Message);
                            response = "";
                        }
                        finally
                        {
                            var responseBytes = Encoding.UTF8.GetBytes(response);
                            channel.BasicPublish(
                                exchange: "",
                                routingKey: props.ReplyTo,
                                basicProperties: replyProps,
                                body: responseBytes);
         
                            channel.BasicAck(ea.DeliveryTag, false);
                        }
                    };
         
                    Console.WriteLine(" Press [enter] to exit.");
                    Console.ReadLine();
                }
            }
         
            /// <summary>
            /// Assumes only valid positive integer input.
            /// Don't expect this one to work for big numbers, and it's probably the slowest recursive implementation possible.
            /// </summary>
            private static int fib(int n)
            {
                if (n == 0 || n == 1)
                {
                    return n;
                }
         
                return fib(n - 1) + fib(n - 2);
            }
        }
        ```
- ***RPCClient.cs -*** [***Final code***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/RPCClient/RPCClient.cs)
    - 응답에 대한 ***exclusive*** 콜백 큐 선언 및 구독.
    - 유니크한 ***CorrelationId*** 키 생성 및 로컬 콜백 목록에 작업 Task와 함께 저장.
    - ***ReplyTo*** 및 ***CorrelationId*** 속성을 가지고 메시지 게시.
    - ***CallAsync*** 메소드는 실제 RPC 요청 수행.
    - 응답시 ***CorrelationId***를 로컬 콜백 목록에서 룩업하여 해당하는 Task로 결과 반환.
        ```
        using RabbitMQ.Client;
        using RabbitMQ.Client.Events;
        using System;
        using System.Collections.Concurrent;
        using System.Text;
        using System.Threading;
        using System.Threading.Tasks;
         
        public class RPCClient
        {
            private const string QUEUE_NAME = "rpc_queue";
            private readonly IConnection connection;
            private readonly IModel channel;
            private readonly string replyQueueName;
            private readonly EventingBasicConsumer consumer;
            private readonly ConcurrentDictionary<string, TaskCompletionSource<string>> callbacks = new ConcurrentDictionary<string, TaskCompletionSource<string>>();
         
            public RPCClient()
            {
                var factory = new ConnectionFactory() { HostName = "localhost" };
                connection = factory.CreateConnection();
                channel = connection.CreateModel();
         
                replyQueueName = channel.QueueDeclare().QueueName;
                consumer = new EventingBasicConsumer(channel);
                consumer.Received += (model, ea) =>
                {
                    if (!callbacks.TryRemove(ea.BasicProperties.CorrelationId, out TaskCompletionSource<string>? tcs))
                        return;
         
                    var body = ea.Body.ToArray();
                    var response = Encoding.UTF8.GetString(body);
                    tcs.TrySetResult(response);
                };
         
                channel.BasicConsume(
                  consumer: consumer,
                  queue: replyQueueName,
                  autoAck: true);
            }
         
            public Task<string> CallAsync(string message, CancellationToken cancellationToken = default(CancellationToken))
            {
                var body = Encoding.UTF8.GetBytes(message);
                var correlationId = Guid.NewGuid().ToString();
                var tcs = new TaskCompletionSource<string>();
         
                callbacks.TryAdd(correlationId, tcs);
         
                IBasicProperties props = channel.CreateBasicProperties();
                props.CorrelationId = correlationId;
                props.ReplyTo = replyQueueName;
         
                channel.BasicPublish(
                    exchange: "",
                    routingKey: QUEUE_NAME,
                    basicProperties: props,
                    body: body);
         
                cancellationToken.Register(() => callbacks.TryRemove(correlationId, out var tmp));
                return tcs.Task;
            }
         
            public void Close()
            {
                channel.Close();
                connection.Close();
            }
        }
         
        public class RPC
        {
            public static void Main(string[] args)
            {
                Console.WriteLine("RPC Client");
         
                InvokeAsync(args.Length > 0 ? args[0] : "30").Wait();
         
                Console.WriteLine(" Press [enter] to exit.");
                Console.ReadLine();
            }
         
            private static async Task InvokeAsync(string number)
            {
                var rpc = new RPCClient();
         
                Console.WriteLine(" [x] Requesting fib({0})", number);
                var response = await rpc.CallAsync(number.ToString());
                Console.WriteLine(" [.] Got '{0}'", response);
         
                rpc.Close();
            }
        }
        ```


　

## # Putting it all together

- **Our RPC service is now ready. We can start the server**
    ```
    cd RPCServer
    dotnet run
    # => [x] Awaiting RPC requests
    ```
- **To request a fibonacci number run the client**
    ```
    cd RPCClient
    dotnet run
    # => [x] Requesting fib(30)
    ```
- **It has some important advantages**
    - RPC 서버가 너무 느리면, 간단히 스케일업 할 수 있다.
    - 새 콘솔 창에 두 번째 RPCServer를 띄우면 된다.
    - 클라이언트 입장에서는 바뀐 것 없다.
    - 결과적으로 RPC 클라이언트는 단일 RPC 요청에 대해 한 번의 네트워크 ***round trip***만 필요하다.
- **More complex (but important) problems**
    - 실행 중인 서버가 없는 경우 클라이언트는 어떻게 반응해야 할까?
    - 클라이언트는 RPC 요청 타임아웃 처리가 필요할까?
    - 서버 예외가 발생하면 클라이언트로 전달해야 할까?
    - 처리하기 전에 올바르지 않은 입력을 막아야 한다.
