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
