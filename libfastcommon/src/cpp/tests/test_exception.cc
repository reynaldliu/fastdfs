#include "exception.h"
#include <iostream>

using namespace std;
using namespace fastdfs::common;

class TestException : public ExceptionBase
{
  public:
    FASTDFS_DEFINE_EXCEPTION(TestException, ExceptionBase);
};

class Foo {
  public:
    void exception_func() {
      FASTDFS_THROW(TestException, "Foo exception thrown");
    }
};

class Bar {
  public:
    void catch_func() {
      try {
        Foo f1;
        f1.exception_func();
      } catch (TestException& e) {
        cout << e.what() << endl;
      }
    }
};



int main()
{
  Bar b1;
  b1.catch_func();
  return 0;
}

