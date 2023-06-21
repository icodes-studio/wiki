## Tutorial.1 - "Hello World!"
> *The simplest thing that does something*
>
> *https://github.com/icoder/C-RabbitMQ/-/tree/master/Tutorials/C%2BHelloWorld*

　

　

## # Overview

- **참고**
  - [*RabbitMQ tutorial - "Hello World!" — RabbitMQ*](https://www.rabbitmq.com/tutorials/tutorial-one-dotnet.html)
  - [*rabbitmq-c/test_basic.c at master · alanxz/rabbitmq-c*](https://github.com/alanxz/rabbitmq-c/blob/master/tests/test_basic.c)


　

## # Setup

- **Console App 프로젝트 생성**

    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/RabbitMQ/Assets/C++ConsoleApp.png)

- **프로젝트 환경설정**
    - *C/C++ > General > Additional Include Directories*
        - ***...\Projects\RabbitMQ-C\include***
        - ***...\Projects\RabbitMQ-C\librabbitmq***
    - *Linker > General > Additional Library Directories*
        - ***...\Projects\RabbitMQ-C\librabbitmq\$(Configuration)***
    - *Linker > Input > Additional Dependencies*
        - ***rabbitmq.4.lib***
    - *rabbitmq.4.dll 복사*
        - from: ***...\Projects\RabbitMQ-C\librabbitmq\$(Configuration)***
        - to: ***$(SolutionDir)$(Platform)\$(Configuration)\\***



　

## # Final code

- ***HelloWorld.cpp -*** [***Final code***](https://github.com/icoder/C-RabbitMQ/-/blob/master/Tutorials/C%2BHelloWorld/HelloWorld.cpp)
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    #include <amqp_time.h>
    #include <rabbitmq-c/amqp.h>
    #include <rabbitmq-c/tcp_socket.h>
     
    int main()
    {
        const int channel = 1;
        const char message[] = "Hello World!";
        const char queue[] = "hello";
     
        ///
        /// CREATE CONNECTION ///
        ///
        amqp_connection_state_t connection = amqp_new_connection();
        amqp_socket_t* socket = amqp_tcp_socket_new(connection);
        assert(socket);
     
        auto r1 = amqp_socket_open(socket, "localhost", AMQP_PROTOCOL_PORT);
        assert(r1 == AMQP_STATUS_OK);
     
        auto r2 = amqp_login(
            /*state*/ connection,
            /*vhost*/ "/",
            /*channel_max*/ 1,
            /*frame_max*/ AMQP_DEFAULT_FRAME_SIZE,
            /*heartbeat*/ AMQP_DEFAULT_HEARTBEAT,
            /*sasl_method*/ AMQP_SASL_METHOD_PLAIN,
            /*username*/ "guest",
            /*password*/ "guest");
        assert(r2.reply_type == AMQP_RESPONSE_NORMAL);
     
        ///
        /// CREATE CHANNEL ///
        ///
        auto r3 = amqp_channel_open(connection, channel);
        assert(r3 != NULL);
     
        ///
        /// DECLARE QUEUE ///
        ///
        auto r4 = amqp_queue_declare(
            /*state*/ connection,
            /*channel*/ channel,
            /*queue*/ amqp_cstring_bytes(queue),
            /*passive*/ 0,
            /*durable*/ 0,
            /*exclusive*/ 0,
            /*auto_delete*/ 1,
            /*arguments*/ amqp_empty_table);
        assert(r4 != NULL);
     
        ///
        /// PUBLISHING ///
        ///
        amqp_bytes_t message_bytes = amqp_cstring_bytes(message);
        amqp_basic_properties_t properties;
        properties._flags = 0;
        properties._flags |= AMQP_BASIC_DELIVERY_MODE_FLAG;
        properties.delivery_mode = AMQP_DELIVERY_NONPERSISTENT;
     
        auto r5 = amqp_basic_publish(
            /*state*/ connection,
            /*channel*/ channel,
            /*exchange*/ amqp_cstring_bytes(""),
            /*routing_key*/ amqp_cstring_bytes(queue),
            /*mandatory*/ 1,
            /*immediate*/ 0,
            /*properties*/ &properties,
            /*body*/ message_bytes);
        assert(r5 == 0);
     
        ///
        /// CONSUMING ///
        ///
        auto r6 = amqp_basic_consume(
            /*state*/ connection,
            /*channel*/ channel,
            /*queue*/ amqp_cstring_bytes(queue),
            /*consumer_tag*/ amqp_empty_bytes,
            /*no_local*/ 0,
            /*no_ack*/ 1,
            /*exclusive*/ 0,
            /*arguments*/ amqp_empty_table);
        assert(r6 != NULL);
     
        ///
        /// MESSAGE POLLING
        ///
        amqp_envelope_t envelope;
        struct timeval timeout = { 5, 0 };
        auto r7 = amqp_consume_message(
            /*state*/ connection,
            /*envelope*/ &envelope,
            /*timeout*/ &timeout,
            /*flags*/ 0);
        assert(r7.reply_type == AMQP_RESPONSE_NORMAL);
     
        ///
        /// PRINTING - Hello World! ///
        ///
        uint64_t bodySize = envelope.message.body.len;
        char* body = (char*)malloc(bodySize);
        if (body != NULL)
        {
            memcpy(body, envelope.message.body.bytes, bodySize);
            assert(bodySize == strlen(message));
            assert(strncmp(message, body, bodySize) == 0);
            printf("%.*s\n", (int)bodySize, body);
            free(body);
        }
     
        ///
        /// RELEASING ///
        ///
        amqp_destroy_envelope(&envelope);
     
        auto r8 = amqp_connection_close(connection, AMQP_REPLY_SUCCESS);
        assert(r8.reply_type == AMQP_RESPONSE_NORMAL);
     
        auto r9 = amqp_destroy_connection(connection);
        assert(r9 == AMQP_STATUS_OK);
    }
    ```
