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
