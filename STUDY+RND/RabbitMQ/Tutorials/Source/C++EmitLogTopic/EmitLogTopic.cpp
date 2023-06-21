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
        /*exchange_name*/ "topic_logs",
        /*exchange_type*/ "topic",
        /*passive*/ false,
        /*durable*/ false,
        /*auto_delete*/ false);

    string routingKey = (argc > 1) ? argv[1] : "anonymous.info";
    string body = (argc > 2) ? argv[2] : "Hello World!";

    channel->BasicPublish(
        /*exchange_name*/ "topic_logs",
        /*routing_key*/ routingKey,
        /*message*/ BasicMessage::Create(body));

    printf(" [x] Sent '%s':'%s'\n", routingKey.c_str(), body.c_str());
    system("pause");
}
