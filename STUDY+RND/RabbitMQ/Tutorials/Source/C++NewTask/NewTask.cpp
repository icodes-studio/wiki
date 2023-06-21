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
