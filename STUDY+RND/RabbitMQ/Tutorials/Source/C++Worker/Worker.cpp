#include <stdio.h>
#include <thread>
#include <SimpleAmqpClient/SimpleAmqpClient.h>

using namespace std;
using namespace AmqpClient;

vector<string> split(string input, char delimiter)
{
    string t;
    stringstream s(input);
    vector<string> result;
    while (getline(s, t, delimiter))
        result.push_back(t);
    return result;
}

void receive(Channel::ptr_t channel, string consumer)
{
    while (true)
    {
        Envelope::ptr_t envelope;
        if (channel->BasicConsumeMessage(consumer, envelope))
        {
            string body = envelope->Message()->Body();
            printf(" [x] Received %s\n", body.c_str());

            int dots = (int)split(body, '.').size() - 1;
            this_thread::sleep_for(chrono::milliseconds(dots * 1000));
            printf(" [x] Done\n");

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
        /*queue_name*/ "task_queue",
        /*passive*/ false,
        /*durable*/ true,
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

    printf(" [*] Waiting for messages.\n");

    thread worker(receive, channel, consumer);
    worker.detach();

    system("pause");
}
