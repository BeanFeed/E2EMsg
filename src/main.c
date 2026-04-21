#define HTTPSERVER_IMPL

#include "httpserver.h"
#include <stdio.h>

struct http_server_s* server;

void handle_request(struct http_request_s* req) {
    struct http_string_s method = http_request_method(req);
    struct http_string_s target = http_request_target(req);
    printf("%.*s %.*s\n", (int)method.len, method.buf, (int)target.len, target.buf);
    struct http_string_s body = http_request_body(req);
    (void)body;

    struct http_response_s* response = http_response_init();
    http_response_status(response, 200);
    http_response_header(response, "Content-Type", "text/plain");
    http_respond(req, response);
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