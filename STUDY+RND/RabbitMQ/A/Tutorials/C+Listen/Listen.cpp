#include <stdio.h>
#include <stdlib.h>
#include <rabbitmq-c/amqp.h>
#include <rabbitmq-c/tcp_socket.h>

#include "Common.h"

int main(int argc, char const* const* argv)
{
    char const* host;
    int port, status;
    char const* exchange;
    char const* type;
    char const* binding;
    amqp_socket_t* socket = NULL;
    amqp_connection_state_t connection;
    amqp_bytes_t queue;

    if (argc < 6)
    {
        fprintf(stderr, "Usage: listen host port exchange type bindingkey\n");
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    exchange = argv[3];
    type = argv[4];
    binding = argv[5];

    ///
    /// CREATE CONNECTION ///
    ///
    connection = amqp_new_connection();
    socket = amqp_tcp_socket_new(connection);
    if (!socket)
    {
        error("creating TCP socket");
    }

    status = amqp_socket_open(socket, host, port);
    if (status)
    {
        error("opening TCP socket");
    }

    error(amqp_login(
        /*state*/ connection,
        /*vhost*/ "/",
        /*channel_max*/ 0,
        /*frame_max*/ AMQP_DEFAULT_FRAME_SIZE,
        /*heartbeat*/ AMQP_DEFAULT_HEARTBEAT,
        /*sasl_method*/ AMQP_SASL_METHOD_PLAIN,
        /*username*/ "guest",
        /*password*/ "guest"), "Logging in");

    ///
    /// CREATE CHANNEL ///
    ///
    amqp_channel_open(connection, 1);
    error(amqp_get_rpc_reply(connection), "Opening channel");

    ///
    /// DECLARE EXCHANGE ///
    ///
    amqp_exchange_declare(
        /*state*/ connection,
        /*channel*/ 1,
        /*exchange*/ amqp_cstring_bytes(exchange),
        /*type*/ amqp_cstring_bytes(type),
        /*passive*/ 0,
        /*durable*/ 0,
        /*auto_delete*/ 0,
        /*internal*/ 0,
        /*arguments*/ amqp_empty_table);

    error(amqp_get_rpc_reply(connection), "Declaring exchange");

    ///
    /// DECLARE QUEUE ///
    ///
    auto declare = amqp_queue_declare(
        /*state*/ connection,
        /*channel*/ 1,
        /*queue*/ amqp_empty_bytes,
        /*passive*/ 0,
        /*durable*/ 0,
        /*exclusive*/ 0,
        /*auto_delete*/ 1,
        /*arguments*/ amqp_empty_table);

    error(amqp_get_rpc_reply(connection), "Declaring queue");

    queue = amqp_bytes_malloc_dup(declare->queue);
    if (queue.bytes == NULL)
    {
        fprintf(stderr, "Out of memory while copying queue name");
        return 1;
    }

    ///
    /// QUEUE+EXCHANGE BINDING ///
    ///
    amqp_queue_bind(
        /*state*/ connection,
        /*channel*/ 1,
        /*queue*/ queue,
        /*exchange*/ amqp_cstring_bytes(exchange),
        /*routing_key*/ amqp_cstring_bytes(binding),
        /*arguments*/ amqp_empty_table);

    error(amqp_get_rpc_reply(connection), "Binding queue");

    ///
    /// BASIC CONSUMING ///
    ///
    amqp_basic_consume(
        /*state*/ connection,
        /*channel*/ 1,
        /*queue*/ queue,
        /*consumer_tag*/ amqp_empty_bytes,
        /*no_local*/ 0,
        /*no_ack*/ 1,
        /*exclusive*/ 0,
        /*arguments*/ amqp_empty_table);

    error(amqp_get_rpc_reply(connection), "Consuming");

    /// 
    /// MESSAGE POLLING & DUMP
    ///
    while (true)
    {
        amqp_maybe_release_buffers(connection);

        amqp_envelope_t envelope;
        auto response = amqp_consume_message(connection, &envelope, NULL, 0);
        if (AMQP_RESPONSE_NORMAL != response.reply_type)
        {
            // TODO: Add more code here
            // See Also: https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_consumer.c
            break;
        }

        printf(
            "Delivery %u, exchange %.*s routingkey %.*s\n",
            (unsigned)envelope.delivery_tag,
            (int)envelope.exchange.len,
            (char*)envelope.exchange.bytes,
            (int)envelope.routing_key.len,
            (char*)envelope.routing_key.bytes);

        if (envelope.message.properties._flags & AMQP_BASIC_CONTENT_TYPE_FLAG)
        {
            printf(
                "Content-type: %.*s\n",
                (int)envelope.message.properties.content_type.len,
                (char*)envelope.message.properties.content_type.bytes);
        }

        printf("----\n");
        dump(envelope.message.body.bytes, envelope.message.body.len);
        amqp_destroy_envelope(&envelope);
    }

    ///
    /// RELEASING ///
    ///
    amqp_bytes_free(queue);

    error(amqp_channel_close(connection, 1, AMQP_REPLY_SUCCESS), "Closing channel");
    error(amqp_connection_close(connection, AMQP_REPLY_SUCCESS), "Closing connection");
    error(amqp_destroy_connection(connection), "Ending connection");

    return 0;
}
