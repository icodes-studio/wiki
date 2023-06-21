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
