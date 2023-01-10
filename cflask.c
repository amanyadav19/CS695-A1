#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "civetweb.h"
#include "functions.h"
#include "functionslist.h"

// This function will be called by civetweb on every new request.
static int begin_request_handler(struct mg_connection *conn)
{
    const struct mg_request_info *request_info = mg_get_request_info(conn);
    for(int i = 0; i < 7; i++) {
        printf("%s\n", url_to_index[i]);
        if (!strcmp(request_info->uri, url_to_index[i])) {
            printf("here\n");
            const char *var_name1 = "str";
            const char *var_name2 = "num";
            char dst1[1000];
            char dst2[1000];
            if(request_info->query_string != NULL) {
                int r1 = mg_get_var2(request_info->query_string,
                                strlen(request_info->query_string),
                                var_name1,
                                dst1,
                                sizeof(dst1),
                                0);
                int r2 = mg_get_var2(request_info->query_string,
                                strlen(request_info->query_string),
                                var_name2,
                                dst2,
                                sizeof(dst2),
                                0);
                int x;
                if(r2==-1) {
                    x = 0;
                }
                else {
                    sscanf(dst2, "%d", &x);
                }

                if(r1 == -1) {
                    fp[i](conn, NULL, x);
                }
                else {
                    fp[i](conn, dst1, x);
                }                
            }
            
            fp[i](conn, NULL, 0);
            break;
        }
    }
    /* Mark request as processed */
    return 1;
}

int main(int argc, char* argv[])
{
    struct mg_context *ctx;
    struct mg_callbacks callbacks;
    if(argc != 3){
        printf("%s\n", "<PORT> <NUM_THREADS> arguments required");
        exit(EXIT_FAILURE);
    }
    
    // List of options. Last element must be NULL.
    const char *options[] = {"listening_ports", argv[1], "num_threads", argv[2], NULL};
    // Prepare callbacks structure. We have only one callback, the rest are NULL.
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = begin_request_handler;

    // Start the web server.
    ctx = mg_start(&callbacks, NULL, options);

    // Wait until user hits "enter". Server is running in separate thread.
    // Navigating to http://localhost:8080 will invoke begin_request_handler().
    getchar();

    // Stop the server.
    mg_stop(ctx);

    return 0;
}
