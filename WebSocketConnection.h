#pragma once

#include <libwebsockets.h>

class WebSocketConnection {

public:
    static void runServer(int port);

private:
    static int callback(struct lws* wsi,
        enum lws_callback_reasons reason,
        void* user,
        void* in,
        size_t len);
};

