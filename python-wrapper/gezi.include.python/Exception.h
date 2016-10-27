#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <glog/logging.h>
#include <exception>
namespace gezi
{
class Exception : public std::exception
{
private:
string _msg;
public:
virtual ~Exception() throw();
Exception(string msg = "");
virtual const char *what() const throw();
};
}
#define THROW(s)\
{\
LOG(WARNING) << s;\
throw gezi::Exception(s);\
}
#endif
