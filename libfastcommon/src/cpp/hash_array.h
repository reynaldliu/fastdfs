/**
* Copyright (C) 2016 Happy Fish / YuQing / qqsun8819 
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* This is a C++ version of FastDFS, plus other new features by qqsun8819
**/

#ifndef HASH_ARRAY_H
#define HASH_ARRAY_H

#include <tr1/functional>
#include <sys/types.h>
#include <pthread.h>
//#include "common_define.h"


namespace fastdfs
{
namespace common
{

    const static unsigned int prime_array[] = {
        1,              /* 0 */
        3,              /* 1 */
        17,             /* 2 */
        37,             /* 3 */
        79,             /* 4 */
        163,            /* 5 */
        331,            /* 6 */
        673,            /* 7 */
        1361,           /* 8 */
        2729,           /* 9 */
        5471,           /* 10 */
        10949,          /* 11 */
        21911,          /* 12 */
        43853,          /* 13 */
        87719,          /* 14 */
        175447,         /* 15 */
        350899,         /* 16 */
        701819,         /* 17 */
        1403641,        /* 18 */
        2807303,        /* 19 */
        5614657,        /* 20 */
        11229331,       /* 21 */
        22458671,       /* 22 */
        44917381,       /* 23 */
        89834777,       /* 24 */
        179669557,      /* 25 */
        359339171,      /* 26 */
        718678369,      /* 27 */
        1437356741,     /* 28 */
        2147483647      /* 29 (largest signed int prime) */
    };

#define PRIME_ARRAY_SIZE  30

struct HashNode
{
	int key_len;
	int value_len;
	int malloc_value_size;

	unsigned int hash_code;
	char *value;
	struct HashNode *next;
	char key[0];
};

typedef std::tr1::function<int (const void *key, const int key_len)> HashFunc;

class HashArray
{
public:
    HashArray(const HashFunc& func, const unsigned int capacity, const double load_factor, const int64_t max_bytes = 0, const bool bMallocValue = false);

    void insert();

private:
	HashNode **buckets;
	HashFunc hash_func;
	int item_count;
	unsigned int *capacity;
	double load_factor_;
	int64_t max_bytes;
	int64_t bytes_used;
	bool is_malloc_capacity;
	bool is_malloc_value;
};

}
}
#endif
