## Tutorial.2 - Work queues
> *Distributing tasks among workers*
>
> [*RabbitMQ tutorial - Work Queues — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-two-dotnet.html)

　

　

## # Introduction

- **공식 C# 튜토리얼 중 이 예제가 커버하는 영역**
    - *https://www.rabbitmq.com/tutorials/tutorial-two-dotnet.html*
  ‌
- **C++ 프로젝트 세팅은 아래 문서 참고**
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md*
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%2B%2B/Tutorial%2000%20-%20Setup.md*


　

## # Putting it all together

- Open two terminals.
- Run the consumer (worker) first so that the topology (primarily the queue) is in place.
- [***Here is its complete code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BWorker/Worker.cpp)
    ```
    #include <stdio.h>
    #include <thread>
    #include <SimpleAmqpClient/SimpleAmqpClient.h>
     
    using namespace std;
    using namespace AmqpClient;
     
    vector<string> split(string input, char delimiter)
    {
        string t;
        stringstream s(input);
        vector<string> result;
        while (getline(s, t, delimiter))
            result.push_back(t);
        return result;
    }
     
    void receive(Channel::ptr_t channel, string consumer)
    {
        while (true)
        {
            Envelope::ptr_t envelope;
            if (channel->BasicConsumeMessage(consumer, envelope))
            {
                string body = envelope->Message()->Body();
                printf(" [x] Received %s\n", body.c_str());
     
                int dots = (int)split(body, '.').size() - 1;
                this_thread::sleep_for(chrono::milliseconds(dots * 1000));
                printf(" [x] Done\n");
     
                channel->BasicAck(envelope);
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
            /*queue_name*/ "task_queue",
            /*passive*/ false,
            /*durable*/ true,
            /*exclusive*/ false,
            /*auto_delete*/ false);
     
        string consumer = channel->BasicConsume(
            /*queue*/ queue,
            /*consumer_tag*/ "",
            /*no_local*/ true,
            /*no_ack*/ false,
            /*exclusive*/ false);
     
        channel->BasicQos(
            /*consumer_tag*/ consumer,
            /*message_prefetch_count*/ 1);
     
        printf(" [*] Waiting for messages.\n");
     
        thread worker(receive, channel, consumer);
        worker.detach();
     
        system("pause");
    }
    ```
- Now run the task publisher.
- [***Its final code is...***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BNewTask/NewTask.cpp)
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
     
        string queue = channel->DeclareQueue(
            /*queue_name*/ "task_queue",
            /*passive*/ false,
            /*durable*/ true,
            /*exclusive*/ false,
            /*auto_delete*/ false);
     
        string body = (argc > 1) ? argv[1] : "Hello World!";
        BasicMessage::ptr_t message = BasicMessage::Create(body);
        message->DeliveryMode(BasicMessage::delivery_mode_t::dm_persistent);
     
        channel->BasicPublish(
            /*exchange_name*/ "",
            /*routing_key*/ queue,
            /*message*/ message);
     
        printf(" [x] Sent %s\n", body.c_str());
        system("pause");
    }
    ```
