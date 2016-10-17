/**
* Copyright (C) 2016 Happy Fish / YuQing / qqsun8819 
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
*
* This is a C++ version of FastDFS, plus other new features by qqsun8819
**/

#ifndef FASTDFS_MUTEX_H 
#define FASTDFS_MUTEX_H 

#include <iostream>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>
#include <cstring>

#define FASTDFS_LOCK_SAFE(x) \
  do {                       \
    int r = (x);             \
    if (r != 0) { \
      int e = errno;  \
      std::cerr << "FASTDFS_LOCK_SAFE to abort() @ " << __FILE__ << ":" <<__LINE__ << " in " << __FUNCTION__ << std::endl \
      << "Ret:" << r << " errno:" << e << "(" << strerror(e) << ')' << std::endl; \
      abort();        \
    }                   \
  } while(false)


namespace fastdfs
{
namespace common
{

class Mutex {
  public:
    Mutex() {
      pthread_mutexattr_t mta;
      FASTDFS_LOCK_SAFE(pthread_mutexattr_init(&mta));
      FASTDFS_LOCK_SAFE(pthread_mutexattr_settype(&mta, PTHREAD_MUTEX_RECURSIVE));
      FASTDFS_LOCK_SAFE(pthread_mutex_init(&mutex, &mta));
      FASTDFS_LOCK_SAFE(pthread_mutexattr_destroy(&mta));
    }

    ~Mutex() {
      FASTDFS_LOCK_SAFE(pthread_mutex_destroy(&mutex));
    }

    void lock() {
      FASTDFS_LOCK_SAFE(pthread_mutex_lock(&mutex));
    }

    int trylock() {
      return pthread_mutex_trylock(&mutex);
    }

    void unlock() {
      FASTDFS_LOCK_SAFE(pthread_mutex_unlock(&mutex));
    }

    pthread_mutex_t& get_pthread_mutex() const {
      return mutex;
    }

  protected:
    mutable pthread_mutex_t mutex;
  private:
    Mutex(const Mutex&);
    Mutex& operator=(const Mutex&);
};

}
}
#endif


