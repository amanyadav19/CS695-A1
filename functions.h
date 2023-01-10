#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "civetweb.h"

char *url_to_index[] = {"/", "/square", "/cube","/helloworld", "/pingpong", "/arithmetic/prime", "/arithmetic/fibonacci"};

int empty(struct mg_connection *conn, char* inp, int n);
// int square(struct mg_connection *conn, int n=1);
int square(struct mg_connection *conn, char* inp, int n);
// int cube(struct mg_connection *conn, int n=1);
int cube(struct mg_connection *conn, char* inp, int n);
int helloworld(struct mg_connection *conn, char* inp, int n);
int pingpong(struct mg_connection *conn, char* inp, int n);
// int prime(struct mg_connection *conn, int n=2);
int prime(struct mg_connection *conn, char* inp, int n);
int fib(int n);
// int fibonacci(struct mg_connection *conn, int k=1);
int fibonacci(struct mg_connection *conn, char* inp, int n);
#endif