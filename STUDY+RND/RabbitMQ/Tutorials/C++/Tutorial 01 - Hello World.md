## Tutorial.1 "Hello World!"
> *The simplest thing that does something*
>
> [*RabbitMQ tutorial - "Hello World!" — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-one-dotnet.html)

　

## # Introduction

- **공식 C# 튜토리얼 중 이 예제가 커버하는 영역**
  - *https://www.rabbitmq.com/tutorials/tutorial-one-dotnet.html*
  ‌
- **C++ 프로젝트 세팅은 아래 문서 참고**
  - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md*
  - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%2B%2B/Tutorial%2000%20-%20Setup.md*


　

## # Sending

- *Publisher는 RabbitMQ에 접속하고 메시지 보낸 후 종료*
- [***Send.cpp - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BSend/Send.cpp)
    ```
    #include <stdio.h>
    #include <SimpleAmqpClient/SimpleAmqpClient.h>
     
    using namespace std;
    using namespace AmqpClient;
     
    int main()
    {
        Channel::OpenOpts opts;
        opts.host = "localhost";
        opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
        Channel::ptr_t channel = Channel::Open(opts);
     
        string queue = channel->DeclareQueue(
            /*queue_name*/ "hello",
            /*passive*/ false,
            /*durable*/ false,
            /*exclusive*/ false,
            /*auto_delete*/ false);
     
        string body("Hello World!");
        channel->BasicPublish(
            /*exchange_name*/ "",
            /*routing_key*/ queue,
            /*message*/ BasicMessage::Create(body));
     
        printf(" [x] Sent %s\n", body.c_str());
        system("pause");
    }
    ```


　‌

## # Receiving

- *Publisher는 메시지 보낸 후 종료했었지만, Consumer는 계속 실행하여 메시지 수신하고 출력*
- [***Receive.cpp - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BReceive/Receive.cpp)
    ```
    #include <stdio.h>
    #include <thread>
    #include <SimpleAmqpClient/SimpleAmqpClient.h>
     
    using namespace std;
    using namespace AmqpClient;
     
    void receive(Channel::ptr_t channel, string consumer)
    {
        while (true)
        {
            Envelope::ptr_t envelope;
            if (channel->BasicConsumeMessage(consumer, envelope))
            {
                string body = envelope->Message()->Body();
                printf(" [x] Received %s\n", body.c_str());
            }
        }
    }
     
    int main()
    {
        Channel::OpenOpts opts;
        opts.host = "localhost";
        opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
        Channel::ptr_t channel = Channel::Open(opts);
     
        string queue = channel->DeclareQueue(
            /*queue_name*/ "hello",
            /*passive*/ false,
            /*durable*/ false,
            /*exclusive*/ false,
            /*auto_delete*/ false);
     
        string consumer = channel->BasicConsume(
            /*queue*/ queue,
            /*consumer_tag*/ "",
            /*no_local*/ true,
            /*no_ack*/ true);
     
        thread worker(receive, channel, consumer);
        worker.detach();
     
        system("pause");
    }
    ```

‌
　

## # Putting it all together

- Open two terminals.
- You can run the clients in any order, as both declares the queue. We will run the consumer first so you can see it waiting for and then receiving the message:
  ```
  cd Tutorials\BIN
  C++Receive
  ```
- Then run the producer:
  ```
  cd Tutorials\BIN
  C++Send
  ```
- The consumer will print the message it gets from the publisher via RabbitMQ. The consumer will keep running, waiting for messages, so try restarting the publisher several times.