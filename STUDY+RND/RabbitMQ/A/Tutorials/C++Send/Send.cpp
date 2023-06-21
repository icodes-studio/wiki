#include <stdio.h>
#include <SimpleAmqpClient/SimpleAmqpClient.h>

using namespace std;
using namespace AmqpClient;

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

    string body("Hello World!");
    channel->BasicPublish(
        /*exchange_name*/ "",
        /*routing_key*/ queue,
        /*message*/ BasicMessage::Create(body));

    printf(" [x] Sent %s\n", body.c_str());
    system("pause");
}
