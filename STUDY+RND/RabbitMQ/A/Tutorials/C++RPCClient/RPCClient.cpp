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
