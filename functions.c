#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "civetweb.h"

// for /
int empty(struct mg_connection *conn, char* inp, int n) {
    char content[10000];

    // Prepare the message we're going to send
    int content_length = snprintf(content, sizeof(content),
                                "Hello World");
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}

// for /square
int square(struct mg_connection *conn, char* inp, int n) {
    char content[10000];

    // Prepare the message we're going to send
    char stri[1000];
    sprintf(stri, "%d", n*n);
    int content_length = snprintf(content, sizeof(content),
                                "%s", stri);
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}

// for /cube
int cube(struct mg_connection *conn, char*inp, int n) {
    char content[10000];
    char stri[1000];
    sprintf(stri, "%d", n*n*n);
    // Prepare the message we're going to send
    int content_length = snprintf(content, sizeof(content),
                                "%s", stri);
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}

// for /helloworld
int helloworld(struct mg_connection *conn, char* inp, int n) {
    char content[10000];
    int content_length;
    if(inp!=NULL) {
        char dest[10000];
        strcpy(dest, "Hello, ");
        strcat(dest, inp);
        // Prepare the message we're going to send
        content_length = snprintf(content, sizeof(content),
                                "%s", dest);
    } else {
        content_length = snprintf(content, sizeof(content),
                                "Hello");
    }
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}

// for /pingpong
int pingpong(struct mg_connection *conn, char* inp, int n) {
    char content[10000];
    int content_length;
    if(inp!=NULL) {
        // Prepare the message we're going to send
        content_length = snprintf(content, sizeof(content),
                                "%s", inp);
    } else {
        content_length = snprintf(content, sizeof(content),
                                "PingPong");
    }
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}

// for /arithmetic/prime
int prime(struct mg_connection *conn, char* inp, int n) {
    // source : https://www.programiz.com/c-programming/examples/prime-number

    int i, flag = 0;
    // 0 and 1 are not prime numbers
    // change flag to 1 for non-prime number
    if (n == 0 || n == 1)
        flag = 1;

    for (i = 2; i <= n / 2; ++i) {

        // if n is divisible by i, then n is not prime
        // change flag to 1 for non-prime number
        if (n % i == 0) {
        flag = 1;
        break;
        }
    }
    char content[10000];
    int content_length;
    if(flag==0) {
        // Prepare the message we're going to send
        content_length = snprintf(content, sizeof(content),
                                "YES");
    } else {
        content_length = snprintf(content, sizeof(content),
                                "NO");
    }
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}

int fib(int n)
{
    if (n <= 1) {
        return n;
    }
 
    return fib(n - 1) + fib(n - 2);
}

// for /arithmetic/fibonacci
int fibonacci(struct mg_connection *conn, char* inp, int n) {
    char content[10000];
    int content_length;
        // Prepare the message we're going to send
    char str[1000];
    sprintf(str, "%d", fib(n));
    content_length = snprintf(content, sizeof(content),
                                "%s", str);
    // Send HTTP reply to the client
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);
    return 1;
}