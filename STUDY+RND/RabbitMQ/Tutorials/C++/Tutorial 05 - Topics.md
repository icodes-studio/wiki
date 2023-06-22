## Tutorial.5 - Topics
> *Receiving messages based on a pattern*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Topics — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-five-dotnet.html)
>
>　

　

## # Introduction

- **공식 C# 튜토리얼 중 이 예제가 커버하는 영역**
  - *https://www.rabbitmq.com/tutorials/tutorial-five-dotnet.html*
  ‌
- **C++ 프로젝트 세팅은 아래 문서 참고**
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md*
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%2B%2B/Tutorial%2000%20-%20Setup.md*


　

## # Final code

- [***EmitLogTopic.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BEmitLogTopic/EmitLogTopic.cpp)
    ```
    #include <stdio.h>
    #include <SimpleAmqpClient/SimpleAmqpClient.h>
     
    using namespace std;
    using namespace AmqpClient;
     
    int main(int argc, const char* argv[])
    {
        Channel::OpenOpts opts;
        opts.host = "localhost";
        opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
        Channel::ptr_t channel = Channel::Open(opts);
     
        channel->DeclareExchange(
            /*exchange_name*/ "topic_logs",
            /*exchange_type*/ "topic",
            /*passive*/ false,
            /*durable*/ false,
            /*auto_delete*/ false);
     
        string routingKey = (argc > 1) ? argv[1] : "anonymous.info";
        string body = (argc > 2) ? argv[2] : "Hello World!";
     
        channel->BasicPublish(
            /*exchange_name*/ "topic_logs",
            /*routing_key*/ routingKey,
            /*message*/ BasicMessage::Create(body));
     
        printf(" [x] Sent '%s':'%s'\n", routingKey.c_str(), body.c_str());
        system("pause");
    }
    ```
  ‌
- [***ReceiveLogsTopic.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BReceiveLogsTopic/ReceiveLogsTopic.cpp)
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
                string routingKey = envelope->RoutingKey();
                printf(" [x] Received '%s':'%s'\n", routingKey.c_str(), body.c_str());
            }
        }
    }
     
    int main(int argc, const char* argv[])
    {
        if (argc < 2)
        {
            printf("Usage: %s [binding_key...]\n", argv[0]);
            system("pause");
            return 1;
        }
     
        Channel::OpenOpts opts;
        opts.host = "localhost";
        opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
        Channel::ptr_t channel = Channel::Open(opts);
     
        channel->DeclareExchange(
            /*exchange_name*/ "topic_logs",
            /*exchange_type*/ "topic",
            /*passive*/ false,
            /*durable*/ false,
            /*auto_delete*/ false);
     
        string queue = channel->DeclareQueue("");
        for (int i = 1; i < argc; ++i)
        {
            channel->BindQueue(
                /*queue_name*/ queue,
                /*exchange_name*/ "topic_logs",
                /*routing_key*/ argv[i]);
        }
     
        string consumer = channel->BasicConsume(
            /*queue*/ queue,
            /*consumer_tag*/ "",
            /*no_local*/ true,
            /*no_ack*/ true,
            /*exclusive*/ false);
     
        printf(" [*] Waiting for messages.\n");
     
        thread worker(receive, channel, consumer);
        worker.detach();
     
        system("pause");
    }
    ```


　

## # Putting it all together

- **To receive all the logs:**
  ```
  cd Toturials\BIN
  C++ReceiveLogsTopic "#"
  ```
- **To receive all logs from the facility "kern":**
  ```
  cd Toturials\BIN
  C++ReceiveLogsTopic "kern.*"
  ```
- **Or if you want to hear only about "critical" logs:**
  ```
  cd Toturials\BIN
  C++ReceiveLogsTopic "*.critical"
  ```
- **You can create multiple bindings:**
  ```
  cd Toturials\BIN
  C++ReceiveLogsTopic "kern.*" "*.critical"
  ```
- **And to emit a log with a routing key "kern.critical" type:**
  ```
  cd Toturials\BIN
  C++EmitLogTopic "kern.critical" "A critical kernel error"
  ```