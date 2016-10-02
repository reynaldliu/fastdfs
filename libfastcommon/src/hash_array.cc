/**
* Copyright (C) 2016 Happy Fish / YuQing / qqsun8819 
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* This is a C++ version of FastDFS, plus other new features by qqsun8819
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include "pthread_func.h"
#include "hash_array.h"

namespace fastdfs
{
namespace common
{

    HashArray::HashArray(const HashFunc& func, const unsigned int capacity, const double load_factor, const int64_t maxbytes, const bool bMallocValue):hash_func(func), max_bytes(maxbytes), is_malloc_value(bMallocValue) {
        unsigned int *pprime;
        unsigned int *prime_end;
        int result;
        prime_end = prime_array + PRIME_ARRAY_SIZE;
        for (pprime = prime_array; pprime != prime_end; pprime++) {
            if (*pprime > capacity) {
                capacity = pprime;
                break;
            }
        }

        //if ((result=_hash_alloc_buckets(pHash, 0)) != 0) {

        if (load_factor >= 0.00 && load_factor <= 1.00) 
            load_factor_ = load_factor;
        else
            load_factor_ = 0.50;
    }




}
}
