#define HTTPSERVER_IMPL

#include "httpserver.h"
#include "router/router.h"
#include <stdio.h>

struct http_server_s* server;

void handle_request(struct http_request_s* req) {
    routeRequest(req);
}

void handle_sig(int sig) {
    free(server);
    exit(0);
}

int main(void) {
    fflush(stdout);
	signal(SIGINT, handle_sig);
    server = http_server_init(8080, handle_request);
    printf("Listening on port 8080\n");
    http_server_listen(server);
    return 0;
}