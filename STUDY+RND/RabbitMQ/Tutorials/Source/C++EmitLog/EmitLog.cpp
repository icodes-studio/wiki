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
