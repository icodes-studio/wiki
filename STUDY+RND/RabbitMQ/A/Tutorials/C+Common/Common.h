#pragma once

#include <rabbitmq-c/amqp.h>

void error(const char* fmt, ...);
void error(int x, char const* context);
void error(amqp_rpc_reply_t x, char const* context);
void dump(void const* buffer, size_t len);
