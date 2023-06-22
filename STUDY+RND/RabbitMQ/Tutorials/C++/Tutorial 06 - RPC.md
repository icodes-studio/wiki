## Tutorial.6 - RPC
> *Request/reply pattern example*
>
> ![](https://www.rabbitmq.com/favicon.ico) [*RabbitMQ tutorial - RPC — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-six-dotnet.html)
>
>　

　

## # Introduction

- **공식 C# 튜토리얼 중 이 예제가 커버하는 영역**
  - *https://www.rabbitmq.com/tutorials/tutorial-six-dotnet.html*
  ‌
- **C++ 프로젝트 세팅은 아래 문서 참고**
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C/Tutorial%2000%20-%20Setup.md*
    - *https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%2B%2B/Tutorial%2000%20-%20Setup.md*


　‌

## # Final code

- [***RPCServer.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BRPCServer/RPCServer.cpp)
    - We declare our fibonacci function.
    - 둘 이상의 서버 프로세스를 실행하는 경우 여러 서버에 로드를 균등하게 분산하기 위해서 ***channel.BasicQos***에서 ***prefetchCount*** 지정.
    - 응답은 ***receive*** 핸들러에서 바로 보낸다.
        ```
        #include <stdio.h>
        #include <thread>
        #include <SimpleAmqpClient/SimpleAmqpClient.h>
         
        using namespace std;
        using namespace AmqpClient;
         
        int fib(int n)
        {
            return (n == 0 || n == 1) ? n : fib(n - 1) + fib(n - 2);
        }
         
        void receive(Channel::ptr_t channel, string consumer)
        {
            while (true)
            {
                Envelope::ptr_t envelope;
                if (channel->BasicConsumeMessage(consumer, envelope))
                {
                    string response;
                    BasicMessage::ptr_t message = envelope->Message();
                    string correlationId = message->CorrelationId();
                    string replyTo = message->ReplyTo();
                    string body = message->Body();
         
                    try
                    {
                        printf(" [.] fib(%s)\n", body.c_str());
                        response = std::to_string(fib(std::stoi(body)));
                    }
                    catch (const runtime_error& e)
                    {
                        printf(" [.] %s\n", e.what());
                        response = "0";
                    }
         
                    BasicMessage::ptr_t reply = BasicMessage::Create(response);
                    reply->CorrelationId(correlationId);
                    channel->BasicPublish("", replyTo, reply);
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
                /*queue_name*/ "rpc_queue",
                /*passive*/ false,
                /*durable*/ false,
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
         
            printf(" [*] Waiting RPC requests.\n");
         
            thread worker(receive, channel, consumer);
            worker.detach();
         
            system("pause");
        }
        ```

- [***RPCClient.cs - Final code***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/A/Tutorials/C%2B%2BRPCClient/RPCClient.cpp)
  - 응답에 대한 ***exclusive*** 콜백 큐 선언 및 구독.
  - 유니크한 ***CorrelationId*** 키 생성 및 로컬 콜백 목록에 작업 Task와 함께 저장.
  - ***ReplyTo*** 및 ***CorrelationId*** 속성을 가지고 메시지 게시.
  - ***Call*** 메소드는 실제 RPC 요청 수행.
  - 응답시 ***CorrelationId***를 로컬 콜백 목록에서 룩업하여 일치하는 경우만 결과 반환.
        ```
        #include <SimpleAmqpClient/SimpleAmqpClient.h>
        #include <stdio.h>
        #include <future>
        #include <rpc.h>
         
        using namespace std;
        using namespace AmqpClient;
         
        string NewGuid()
        {
            GUID guid;
            size_t temp;
            char iid[129] = { 0, };
            wchar_t wiid[129] = { 0, };
         
            if (S_OK != CoCreateGuid(&guid))
                return iid;
         
            if (0 == StringFromGUID2(guid, wiid, 128))
                return iid;
         
            wcstombs_s(&temp, iid, 129, wiid, 128);
            return iid;
        }
         
        class RPCClient
        {
            private: string replyTo;
            private: string correlationId;
            private: Channel::ptr_t channel;
            private: string consumer;
         
            public: RPCClient()
            {
                Channel::OpenOpts opts;
                opts.host = "localhost";
                opts.auth = Channel::OpenOpts::BasicAuth("guest", "guest");
                channel = Channel::Open(opts);
                replyTo = channel->DeclareQueue("");
                correlationId = NewGuid();
                consumer = channel->BasicConsume(replyTo);
            }
         
            private: static string receive(const RPCClient* client)
            {
                while (true)
                {
                    Envelope::ptr_t envelope;
                    if (client->channel->BasicConsumeMessage(client->consumer, envelope))
                    {
                        BasicMessage::ptr_t message = envelope->Message();
                        if (client->correlationId == message->CorrelationId())
                            return message->Body();
                    }
                }
                return "";
            }
         
            public: string Call(string body)
            {
                BasicMessage::ptr_t message = BasicMessage::Create(body);
                message->ReplyTo(replyTo);
                message->CorrelationId(correlationId);
                channel->BasicPublish("", "rpc_queue", message);
         
                future<string> result = async(receive, this);
                return result.get();
            }
        };
         
        int main(int argc, const char* argv[])
        {
            RPCClient rpc;
            string number = (argc > 1) ? argv[1] : "30";
            printf(" [x] Requesting fib(%s)\n", number.c_str());
            string response = rpc.Call(number);
            printf(" [.] Got '%s'\n", response.c_str());
            system("pause");
        }
        ```


　

## **# Putting it all together**

---

- **Our RPC service is now ready. We can start the server**
  ```
  cd Tutorials\BIN
  C++RPCServer
  # => [x] Awaiting RPC requests
  ```
- **To request a fibonacci number run the client**
  ```
  cd Tutorials\BIN
  C++RPCClient
  # => [x] Requesting fib(30)
  ```
- **It has some important advantages**
  - RPC 서버가 너무 느리면, 간단히 스케일업 할 수 있다.
  - 새 콘솔 창에 두 번째 RPCServer를 띄우면 된다.
  - 클라이언트 입장에서는 바뀐 것 없다.
  - 결과적으로 RPC 클라이언트는 단일 RPC 요청에 대해 한 번의 네트워크 _**round trip**_만 필요하다.
- **More complex (but important) problems**
  - 실행 중인 서버가 없는 경우 클라이언트는 어떻게 반응해야 할까?
  - 클라이언트는 RPC 요청 타임아웃 처리가 필요할까?
  - 서버 예외가 발생하면 클라이언트로 전달해야 할까?
  - 처리하기 전에 올바르지 않은 입력을 막아야 한다.