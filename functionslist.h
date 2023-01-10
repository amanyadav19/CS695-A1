#include "functions.h"

int (*fp[]) (struct mg_connection *, char* , int) = {empty, square, cube, helloworld, pingpong, prime, fibonacci};