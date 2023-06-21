## Tutorial.7 - Publisher Confirms
> *Reliable publishing with publisher confirms*
>
> [*RabbitMQ tutorial - Reliable Publishing with Publisher Confirms — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-seven-dotnet.html)
>

　

## # Overview

- **Publisher Confirms**
    - 안정적인 신뢰성 있는 퍼블리싱 구현.
    - Publisher Confirms 환경이 활성화(enable) 되면,
    - 클라이언트 메시지가 브로커에서 처리 되었음을 확인할 수 있다.
- **Enabling Publisher Confirms on a Channel**
    - Publisher Confirms는 AMQP 0.9.1를 위한 ***RabbitMQ extension*** 이다.
    - SO, 기본적으로는 활성화되어 있지 않다.
    - ***ConfirmSelect*** 메서드를 사용하여 활성화해야 한다.
        ```
        var channel = connection.CreateModel();
        channel.ConfirmSelect();
        ```


　

## Strategy #1: Publishing Messages Individually

- **The simplest approach**
    - 메시지를 퍼블리시하고 컨펌을 기다리기
        ```
        while (ThereAreMessagesToPublish())
        {
            byte[] body = ...;
            IBasicProperties properties = ...;
            channel.BasicPublish(exchange, queue, properties, body);
            // uses a 5 second timeout
            channel.WaitForConfirmsOrDie(new TimeSpan(0, 0, 5));
        }
        ```
    - 메시지 퍼블리시 후...
    - ***Channel.WaitForConfirmsOrDie(TimeSpan)*** 메서드로 컨펌 대기
    - 메시지가 컨펌되는 즉시 메서드 리턴
    - 메시지가 제한 시간 내에 컨펌되지 않거나 메시지가 ***nack-ed***(브로커가 어떤 이유로 인해 메시지를 처리할 수 없음을 의미)하는 경우 메서드는 예외 발생.
    - 예외 처리는 일반적으로 오류 로그를 남기거나 전송을 재 시도 한다.
- **A Major drawback**
    - 동기 시퀀스로 운용되므로 퍼블리싱 속도가 크게 느려진다.
    - 그럼에도 일부 간단한 응용 프로그램에는 충분할 수도 있다.
    - 암튼, 느리다!
- **Are Publisher Confirms Asynchronous?**
    - 오해하지 마세요!
    - 내부적으로 브로커는 메시지를 비동기식으로 확인한다.
    - WaitForConfirmsOrDie 메소드는 그저 동기 헬퍼 정도로 이해하자!


　

## Strategy #2: Publishing Messages in Batches

- **To improve upon our previous example**
    - 메시지 배치를 퍼블리시하고 이 전체 배치가 컨펌 될 때까지 대기.
    - 다음 예에서는 100개의 배치를 사용.
        ```
        var batchSize = 100;
        var outstandingMessageCount = 0;
        while (ThereAreMessagesToPublish())
        {
            byte[] body = ...;
            IBasicProperties properties = ...;
            channel.BasicPublish(exchange, queue, properties, body);
            outstandingMessageCount++;
            if (outstandingMessageCount == batchSize)
            {
                channel.WaitForConfirmsOrDie(new TimeSpan(0, 0, 5));
                outstandingMessageCount = 0;
            }
        }
        if (outstandingMessageCount > 0)
        {
            channel.WaitForConfirmsOrDie(new TimeSpan(0, 0, 5));
        }
        ```
    - 개별 메시지 컨펌 방식보다 처리량이 크게 향상된다.
    - 원격 RabbitMQ 노드의 경우 최대 20-30배.
    - **단점은...**
        - 실패 시 무엇이 잘못되었는지 정확히 알지 못한다.
        - 여전히 동기 방식으로, 메시지 퍼블리시 블락 발생.


　

## Strategy #3: Handling Publisher Confirms Asynchronously

- **The broker confirms published messages asynchronously**
    - 컨펌을 노티 받기 위한 콜백 등록.
        ```
        var channel = connection.CreateModel();
        channel.ConfirmSelect();
        channel.BasicAcks += (sender, ea) =>
        {
            // code when message is confirmed
        };
        channel.BasicNacks += (sender, ea) =>
        {
            //code when message is nack-ed
        };
        ```
    - one for confirmed messages
    - one for nack-ed messages
- **Both callbacks have a corresponding EventArgs parameter**
    - ***delivery tag***
        - The sequence number identifying the confirmed or nack-ed message.
        - We will see shortly how to correlate it with the published message.
    - ***multiple***
        - this is a boolean value.
        - If false, only one message is confirmed/nack-ed,
        - If true, all messages with a lower or equal sequence number are confirmed/nack-ed.
- **The sequence number**
    - 퍼블리싱 전에 ***Channel.NextPublishSeqNo*** 메소드로 얻을 수 있다.
        ```
        var sequenceNumber = channel.NextPublishSeqNo;
        channel.BasicPublish(exchange, queue, properties, body);
        ```
    - 메시지를 시퀀스 번호와 매칭 시키는 간단한 방법은 Dictionary 사용.
        ```
        var outstandingConfirms = new ConcurrentDictionary<ulong, string>();
        // ... code for confirm callbacks will come later
        var body = "...";
        outstandingConfirms.TryAdd(channel.NextPublishSeqNo, body);
        channel.BasicPublish(exchange, queue, properties, Encoding.UTF8.GetBytes(body));
        ```
    - 콜백 떨어지면 확인하고 해당 시퀀스 번호 데이터 클리어
        ```
        var outstandingConfirms = new ConcurrentDictionary<ulong, string>();
        　
        void cleanOutstandingConfirms(ulong sequenceNumber, bool multiple)
        {
            if (multiple)
            {
                var confirmed = outstandingConfirms.Where(k => k.Key <= sequenceNumber);
                foreach (var entry in confirmed)
                {
                    outstandingConfirms.TryRemove(entry.Key, out _);
                }
            }
            else
            {
                outstandingConfirms.TryRemove(sequenceNumber, out _);
            }
        }
        　
        channel.BasicAcks += (sender, ea) => cleanOutstandingConfirms(ea.DeliveryTag, ea.Multiple);
        channel.BasicNacks += (sender, ea) =>
        {
            outstandingConfirms.TryGetValue(ea.DeliveryTag, out string body);
            Console.WriteLine($"Message with body {body} has been nack-ed. Sequence number: {ea.DeliveryTag}, multiple: {ea.Multiple}");
            cleanOutstandingConfirms(ea.DeliveryTag, ea.Multiple);
        };
        　
        // ... publishing code
        ```
    - 컨펌 발생시 Dictionary 정리하는 콜백이 보인다.
    - 이 콜백은 ***single*** 그리고 ***multiple*** 컨펌을 모두 처리한다.
    - ***Channel.BasicAcks*** 콜백에서는 바로 정리
    - ***Channel.BasicNacks*** 콜백에서는 메시지 본문 검색 후 경고. 그런 다음 Dictionary 정리.
- **Re-publishing nack-ed Messages?**
    - 컨펌 콜백에서 nack-ed 메시지를 다시 게시하고 싶을 수 있지만, 피해야 한다. 채널이 동작할 수 없는 I/O 스레드에서 확인 콜백이 전달되기 때문.
    - 제대로 하려면 퍼블리시 스레드가 폴링하는 큐를 하나 두고 여기에 nack-ed 메시지를 큐잉하는 게 좋다.
    - ***ConcurrentQueue*** 클래스는 좋은 자료형 후보가 되겠다.


　

## # Putting it all together

---

- The [***PublisherConfirms.cs***](https://github.com/rabbitmq/rabbitmq-tutorials/blob/main/dotnet/PublisherConfirms/PublisherConfirms.cs) class contains code for the techniques we covered. We can compile it, execute it as-is and see how they each perform
    ```
    dotnet run
    ```
- **The output will look like the following**
    ```
    Published 50,000 messages individually in 5,549 ms
    Published 50,000 messages in batch in 2,331 ms
    Published 50,000 messages and handled confirms asynchronously in 4,054 ms
    ```
    - 클라 서버가 동일한 시스템에 있는 경우 성능이 비슷하게 보인다.
    - 개별 퍼블리시 방식은 예상대로 성능이 저하되었다.
    - 하지만 비동기 방식의 결과는 다소 실망스럽다.
    - Publisher Confirms의 성능은 네트워크 상황에 꽤 디펜던시가 있다.
    - 그냥 현실적으로 원격 노드에서 테스트 하는 게 좋겠다.
- **To use a non-local node:**
    ```
    private static IConnection CreateConnection()
    {
        var factory = new ConnectionFactory { HostName = "remote-host", UserName = "remote-host", Password = "remote-password" };
        return factory.CreateConnection();
    }
    ```
- **Recompile the class, execute it again, and wait for the results**
    ```
    Published 50,000 messages individually in 231,541 ms
    Published 50,000 messages in batch in 7,232 ms
    Published 50,000 messages and handled confirms asynchronously in 6,332 ms
    ```
    - 이제야 개별 퍼블리시 방식이 좀 끔찍해 보인다.
    - 하지만 배치 퍼블리싱 방식과 비동기 방식의 차이가 미미하다.
    - 다만 이것만은 기억하자! 배치 퍼블리싱 방식은 실패 시 무엇이 잘못되었는지 정확히 알지 못한다. 반면 비동기 방식은 nack-ed 상황에서 에러 핸들링을 자세히 할 수 있다.