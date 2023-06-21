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
    char const* routingkey;
    char const* message;
    amqp_socket_t* socket = NULL;
    amqp_connection_state_t connection;

    if (argc < 6)
    {
        fprintf(stderr, "Usage: send host port exchange type routingkey message\n");
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    exchange = argv[3];
    type = argv[4];
    routingkey = argv[5];
    message = argv[6];

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
    /// PUBLISHING ///
    ///
    amqp_basic_properties_t props;
    props._flags = AMQP_BASIC_CONTENT_TYPE_FLAG | AMQP_BASIC_DELIVERY_MODE_FLAG;
    props.content_type = amqp_cstring_bytes("text/plain");
    props.delivery_mode = 2; /* persistent delivery mode */
    error(amqp_basic_publish(
        /*state*/ connection,
        /*channel*/ 1,
        /*exchange*/ amqp_cstring_bytes(exchange),
        /*routing_key*/ amqp_cstring_bytes(routingkey),
        /*mandatory*/ 0,
        /*immediate*/ 0,
        /*properties*/ &props,
        /*body*/ amqp_cstring_bytes(message)), "Publishing");

    ///
    /// RELEASING ///
    ///
    error(amqp_channel_close(connection, 1, AMQP_REPLY_SUCCESS), "Closing channel");
    error(amqp_connection_close(connection, AMQP_REPLY_SUCCESS), "Closing connection");
    error(amqp_destroy_connection(connection), "Ending connection");

    return 0;
}
