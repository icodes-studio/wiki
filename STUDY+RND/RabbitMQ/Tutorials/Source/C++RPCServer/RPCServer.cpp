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
