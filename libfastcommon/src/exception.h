/**
* Copyright (C) 2016 Happy Fish / YuQing / qqsun8819 
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
*
* This is a C++ version of FastDFS, plus other new features by qqsun8819
**/

#ifndef FASTDFS_EXCEPTION_H 
#define FASTDFS_EXCEPTION_H 

#include <exception>
#include <string>
#define FASTDFS_THROW(ExClass, args...)                           \
    do                                                         \
    {                                                          \
        ExClass e(args);                                       \
        e.Init(__FILE__, __PRETTY_FUNCTION__, __LINE__);       \
        throw e;                                               \
    }                                                          \
    while (false)     

#define FASTDFS_DEFINE_EXCEPTION(ExClass, Base)               \
    ExClass(const std::string& msg = "") throw()              \
    : Base(msg)  {}                                           \
    ~ExClass() throw() {}                                     \
    /* override */ std::string GetClassName() const           \
    {                                                         \
        return #ExClass;                                      \
    }

namespace fastdfs
{
namespace common
{

class ExceptionBase : public std::exception {
    public:
        ExceptionBase(const std::string& msg = "") throw();
        virtual ~ExceptionBase() throw();
        void Init(const char* file, const char* func, int line);
        virtual std::string GetClassName() const;

        virtual std::string GetMessage() const;

        const char* what() const throw();

        const std::string& ToString() const;

        std::string GetStackTrace() const;

    protected:
        std::string mMsg;
        const char* mFile;
        const char* mFunc;
        int mLine;

    private:
        enum { MAX_STACK_TRACE_SIZE = 50 };
        void* mStackTrace[MAX_STACK_TRACE_SIZE];
        size_t mStackTraceSize;
        mutable std::string mWhat;
};

}
}
#endif
