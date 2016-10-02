#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>
#include "logger.h"
#include "hash.h"

struct ValueData
{
    int v1;
    int v2;
};
int main(int argc, char *argv[])
{
    HashArray hasharr;
    hash_init(&hasharr, Time33Hash, 32, 0.75);  
    char* key = "abc";
    ValueData* value = (ValueData* ) malloc(sizeof(ValueData));
    value->v1 = 1;
    value->v2 = 2;
    hash_insert(&hasharr, key, strlen(key), value);
}
	
