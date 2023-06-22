## Tutorial.4 - Routing
> *Receiving messages selectively*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Routing — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-four-dotnet.html)
>
>　

　

## # Introduction

- **공식 C# 튜토리얼 중 이 예제가 커버하는 영역**
    - *https://www.rabbitmq.com/tutorials/tutorial-four-dotnet.html*
  ‌
- **C++ 프로젝트 세팅은 아래 문서 참고**
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md*
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%2B%2B/Tutorial%2000%20-%20Setup.md*


　‌

## # Final code

- [***EmitLogDirect.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BEmitLogDirect/EmitLogDirect.cpp)
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
            /*exchange_name*/ "direct_logs",
            /*exchange_type*/ "direct",
            /*passive*/ false,
            /*durable*/ false,
            /*auto_delete*/ false);
     
        string severity = (argc > 1) ? argv[1] : "info";
        string body = (argc > 2) ? argv[2] : "Hello World!";
     
        channel->BasicPublish(
            /*exchange_name*/ "direct_logs",
            /*routing_key*/ severity,
            /*message*/ BasicMessage::Create(body));
     
        printf(" [x] Sent '%s':'%s'\n", severity.c_str(), body.c_str());
        system("pause");
    }
    ```
  ‌
- [***ReceiveLogsDirect.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BReceiveLogsDirect/ReceiveLogsDirect.cpp)
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
            printf("Usage: %s [info] [warning] [error]\n", argv[0]);
            system("pause");
            return 1;
        }
     
        Channel::OpenOpts opts;
        opts.host = "localhost";
        opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
        Channel::ptr_t channel = Channel::Open(opts);
     
        channel->DeclareExchange(
            /*exchange_name*/ "direct_logs",
            /*exchange_type*/ "direct",
            /*passive*/ false,
            /*durable*/ false,
            /*auto_delete*/ false);
     
        string queue = channel->DeclareQueue("");
        for (int i = 1; i < argc; ++i)
        {
            channel->BindQueue(
                /*queue_name*/ queue,
                /*exchange_name*/ "direct_logs",
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

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-four.png)

- **If you want to save only 'warning' and 'error' (and not 'info') log messages to a file, just open a console and type:**
  ```
  cd Tutorials\BIN
  C++ReceiveLogsDirect warning error > logs_from_rabbit.log
  ```
- **If you'd like to see all the log messages on your screen, open a new terminal and do:**
  ```
  cd Tutorials\BIN
  C++ReceiveLogsDirect info warning error
  # => [*] Waiting for logs. To exit press CTRL+C
  ```
- **And, for example, to emit an error log message just type:**
  ```
  cd Tutorials\BIN
  C++EmitLogDirect error "Run. Run. Or it will explode."
  # => [x] Sent 'error':'Run. Run. Or it will explode.'
  ```