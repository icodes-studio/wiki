## Tutorial.2 - Publish/Subscribe/Routing/Topics

> *Receiving messages selectively*
>
> [*https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BListen*](https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BListen)
>
> [*https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BSend*](https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BSend)

　

　

## # Overview

- **공식 튜토리얼 중 이 예제가 커버하는 영역**
  - [*3. Publish/Subscribe (using fanout)*](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%23/Tutorial%2003%20-%20PublishSubscribe.md)
  - [*4. Routing (using direct)*](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%23/Tutorial%2004%20-%20Routing.md)
  - [*5. Topics*](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Tutorials/C%23/Tutorial%2005%20-%20Topics.md)

- **참고**
  - [*rabbitmq-c/amqp_listen.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_listen.c)
  - [*rabbitmq-c/amqp_sendstring.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_sendstring.c)
  - [*rabbitmq-c/amqp_consumer.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_consumer.c)
  - [*rabbitmq-c/amqp\_exchange\_declare.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/amqp_exchange_declare.c)
  - [*rabbitmq-c/utils.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/examples/utils.c)


　

## # Setup

- **프로젝트 생성**
    - [***Listen***](https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BListen)
        - Console App
        - 컨슈머(Consumer)
        - 큐와 익스체인지를 특정 키로 바인딩 하고 수신 대기.
    - [***Send***](https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BSend)
        - Console App
        - 퍼블리셔(Publisher)
        - 지정한 익스체인지로 메시지 발행
    - [***Common***](https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BCommon)
        - Static library (.lib)
        - 튜토리얼에서 사용하는 공용 유틸리티 헬퍼
    - ***프로젝트 설정은...***
        - [***C Tutorial.1 - "Hello World!" 참고***](https://nwiki.neowiz.com/pages/viewpage.action?pageId=143443061)


　

## # Final code

- ***Listen.cpp -*** [***Final code***](https://github.com/icoder/C-RabbitMQ/-/blob/master/Tutorials/C%2BListen/Listen.cpp)
    - 컨슈머(Consumer)
    - 큐와 익스체인지를 특정 키로 바인딩 하고 수신 대기.
        ```
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
                fprintf(stderr, "Usage: listen host port exchange type binding\n");
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
        ```
- ***Send.cpp -*** [***Final code***](https://github.com/icoder/C-RabbitMQ/-/blob/master/Tutorials/C%2BSend/Send.cpp)
    - 퍼블리셔(Publisher)
    - 지정한 익스체인지로 메시지 발행
        ```
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
        ```
- ***Common.cpp -*** [***Final code***](https://github.com/icoder/study/-/blob/master/RabbitMQ/Tutorials%2BC/Common/Common.cpp)
    - 튜토리얼에서 사용하는 공용 유틸리티 헬퍼
        ```
        #include <ctype.h>
        #include <stdarg.h>
        #include <stdio.h>
        #include <stdlib.h>
         
        #include "Common.h"
         
        void error(int x, char const* context)
        {
            if (x < 0)
            {
                fprintf(stderr, "%s: %s\n", context, amqp_error_string2(x));
                exit(1);
            }
        }
         
        void error(const char* fmt, ...)
        {
            va_list ap;
            va_start(ap, fmt);
            vfprintf(stderr, fmt, ap);
            va_end(ap);
            fprintf(stderr, "\n");
            exit(1);
        }
         
        void error(amqp_rpc_reply_t x, char const* context)
        {
            switch (x.reply_type)
            {
            case AMQP_RESPONSE_NORMAL:
                return;
            case AMQP_RESPONSE_NONE:
                fprintf(stderr, "%s: missing RPC reply type!\n", context);
                break;
            case AMQP_RESPONSE_LIBRARY_EXCEPTION:
                fprintf(stderr, "%s: %s\n", context, amqp_error_string2(x.library_error));
                break;
            case AMQP_RESPONSE_SERVER_EXCEPTION:
                switch (x.reply.id)
                {
                    case AMQP_CONNECTION_CLOSE_METHOD:
                    {
                        amqp_connection_close_t* m = (amqp_connection_close_t*)x.reply.decoded;
                        fprintf(
                            stderr,
                            "%s: server connection error %uh, message: %.*s\n",
                            context,
                            m->reply_code,
                            (int)m->reply_text.len,
                            (char*)m->reply_text.bytes);
                        break;
                    }
                    case AMQP_CHANNEL_CLOSE_METHOD:
                    {
                        amqp_channel_close_t* m = (amqp_channel_close_t*)x.reply.decoded;
                        fprintf(
                            stderr,
                            "%s: server channel error %uh, message: %.*s\n",
                            context,
                            m->reply_code,
                            (int)m->reply_text.len,
                            (char*)m->reply_text.bytes);
                        break;
                    }
                    default:
                    {
                        fprintf(
                            stderr,
                            "%s: unknown server error, method id 0x%08X\n",
                            context,
                            x.reply.id);
                        break;
                    }
                }
                break;
            }
            exit(1);
        }
         
        static int equals(int* a, int* b)
        {
            for (int i = 0; i < 16; i++)
            {
                if (a[i] != b[i])
                    return 0;
            }
            return 1;
        }
         
        static void dump(long count, int numinrow, int* chs)
        {
            printf("%08lX:", count - numinrow);
         
            if (numinrow > 0)
            {
                for (int i = 0; i < numinrow; i++)
                {
                    if (i == 8)
                        printf(" :");
                    printf(" %02X", chs[i]);
                }
                for (int i = numinrow; i < 16; i++)
                {
                    if (i == 8)
                        printf(" :");
                    printf("   ");
                }
                printf("  ");
                for (int i = 0; i < numinrow; i++)
                {
                    if (isprint(chs[i]))
                        printf("%c", chs[i]);
                    else
                        printf(".");
                }
            }
            printf("\n");
        }
         
        void dump(void const* buffer, size_t len)
        {
            unsigned char* buf = (unsigned char*)buffer;
            long count = 0;
            int numinrow = 0;
            int chs[16];
            int oldchs[16] = { 0 };
            int showed_dots = 0;
         
            for (size_t i = 0; i < len; i++)
            {
                int ch = buf[i];
                if (numinrow == 16)
                {
                    if (equals(oldchs, chs))
                    {
                        if (!showed_dots)
                        {
                            showed_dots = 1;
                            printf("          .. .. .. .. .. .. .. .. : .. .. .. .. .. .. .. ..\n");
                        }
                    }
                    else
                    {
                        showed_dots = 0;
                        dump(count, numinrow, chs);
                    }
         
                    for (int j = 0; j < 16; j++)
                    {
                        oldchs[j] = chs[j];
                    }
                    numinrow = 0;
                }
                count++;
                chs[numinrow++] = ch;
            }
         
            dump(count, numinrow, chs);
         
            if (numinrow != 0)
            {
                printf("%08lX:\n", count);
            }
        }
        ```


　

## # Putting it all together

- Arrange for a RabbitMQ or other AMQP server to be running on `localhost` at TCP port number 5672.
- **In one terminal, run**
    ```
    listen localhost 5672 direct_logs direct error
    ```
- **In another terminal,**
    ```
    send localhost 5672 direct_logs direct error "hello world"
    ```
- **You should see output similar to the following in the listener's terminal window:**
    ```
    Delivery 1, exchange direct_logs routingkey error
    Content-type: text/plain
    ­―­―­――
    00000000: 68 65 6C 6C 6F 20 77 6F : 72 6C 64                 hello world
    0000000B:
    ```