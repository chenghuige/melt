#include <iostream>
#include <vector>
#include "common_util.h"
using namespace std;
namespace abc {
enum  color
{
color__enum__red,
color__enum__green,
color__enum__black,
};
}
class Base
{
public:
//virtual int age() = 0;
};
typedef shared_ptr<Base> BasePtr;
class Old : public Base
{
public:
virtual int age();
};
class Young : public Base
{
public:
virtual int age();
};
namespace gezi {
class Example
{
public:
void haha();
};
}
class Example
{
public:
abc::color GetColor();
BasePtr CreateBase(string name);
void setcoror(abc::color color_ = abc::color__enum__black);
void setcoror2(int x,
abc::color color_ = abc::color__enum__black);
void say_hello();
void swap(int* x, int* y);
template<typename T>
void swap2(T& x, T& y);
void swap3(int& x, int& y);
//static bool& ok();
#ifndef GCCXML
//int& value(int index);
#endif
static bool set_ok(bool ok_ = true);
static bool is_ok();
void add(int x);
typedef vector<int>::iterator iterator;
typedef vector<int>::const_iterator const_iterator;
//iterator begin();
vector<int> _vec;
};
