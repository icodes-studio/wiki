## Tutorial.3 - Publish/Subscribe
> *Sending messages to many consumers at once*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - Publish/Subscribe — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-three-dotnet.html)
>
>　

　

## # Introduction

- **공식 C# 튜토리얼 중 이 예제가 커버하는 영역**
  - *https://www.rabbitmq.com/tutorials/tutorial-three-dotnet.html*
  ‌
- **C++ 프로젝트 세팅은 아래 문서 참고**
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md*
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%2B%2B/Tutorial%2000%20-%20Setup.md*


　

## # Final code

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/python-three-overall.png)

- [***EmitLog.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BEmitLog/EmitLog.cpp)
    - We now want to publish messages to our _"logs"_ exchange.
    - A routingKey value is ignored for fanout exchanges.
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
                /*exchange_name*/ "logs",
                /*exchange_type*/ "fanout",
                /*passive*/ false,
                /*durable*/ false,
                /*auto_delete*/ false);
         
            string body = (argc > 1) ? argv[1] : "info: Hello World!";
            channel->BasicPublish(
                /*exchange_name*/ "logs",
                /*routing_key*/ "",
                /*message*/ BasicMessage::Create(body));
         
            printf(" [x] Sent %s\n", body.c_str());
            system("pause");
        }
        ```
- [***ReceiveLogs.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BReceiveLogs/ReceiveLogs.cpp)
    - 익스체인지에 바인딩된 큐가 없으면 메시지는 손실된다.
    - 즉, 컨슈머가 없으면 메시지는 안전하게 지워진다.
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
                    printf(" [x] %s\n", body.c_str());
                }
            }
        }
         
        int main()
        {
            Channel::OpenOpts opts;
            opts.host = "localhost";
            opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
            Channel::ptr_t channel = Channel::Open(opts);
         
            channel->DeclareExchange(
                /*exchange_name*/ "logs",
                /*exchange_type*/ "fanout",
                /*passive*/ false,
                /*durable*/ false,
                /*auto_delete*/ false);
         
            string queue = channel->DeclareQueue("");
            channel->BindQueue(
                /*queue_name*/ queue,
                /*exchange_name*/ "logs",
                /*routing_key*/ "");
         
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

- If you want to save logs to a file, just open a console and type:
    ```
    cd Tutorials\BIN
    C++ReceiveLogs > logs_from_rabbit.log
    ```
- If you wish to see the logs on your screen, spawn a new terminal and run:
    ```
    cd Tutorials\BIN
    C++ReceiveLogs
    ```
- And of course, to emit logs type:
    ```
    cd Tutorials\BIN
    C++EmitLog
    ```
- Using rabbitmqctl list_bindings you can verify that the code actually creates bindings and queues as we want. With two ReceiveLogs.cs programs running you should see something like:
    ```
    rabbitmqctl.bat list_bindings
    # => Listing bindings ...
    # => logs    exchange        amq.gen-JzTY20BRgKO-HjmUJj0wLg  queue           []
    # => logs    exchange        amq.gen-vso0PVvyiRIL2WoV3i48Yg  queue           []
    # => ...done.
    ```