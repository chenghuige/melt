#include <iostream>
#include <vector>
#include "common_util.h"
using namespace std;

//enum color
//{
//    red,
//    green,
//    black
//};
namespace abc {
enum class color
{
    red,
    green,
    black
};
}

class Base
{
public:
    virtual int age() = 0;
    //virtual int age()
    //{
    //    return 0;
    //}
};

typedef shared_ptr<Base> BasePtr;

class Old : public Base
{
public:
    virtual int age() override
    {
        return 100;
    }
};
class Young : public Base
{
public:
    virtual int age() override
    {
        return 10;
    }
};

namespace gezi {

        class Example {
            public:
                void haha()
                {
                    cout << "haha";
                }
            };
}
//enum class face { good, bad };
class Example{
public:
abc::color GetColor()
{
    return abc::color::green;
}

BasePtr CreateBase(string name)
{
    if (name == "old")
        return make_shared<Old>();
    else 
        return make_shared<Young>();
}

void setcoror(abc::color color_ = abc::color::black)
{
}

void setcoror2(int x, 
    abc::color color_ = abc::color::black)
{
}
    //color GetColor()
    //{
    //    return color::green;
    //}

//    face GetFace()
//    {
//        return face::good;
//    }

    void say_hello()
    {
        cout << "hello";
    }

    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    template<typename T>
    void swap2(T& x, T& y)
    {
        T temp = x;
        x = y;
        y = temp;
    }

    void swap3(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    static bool& ok()
    {
        static bool _ok = true;
        return _ok;
    }

#ifndef GCCXML
    int& value(int index)
    {
        return _vec[index];    
    }

#endif 
    static bool set_ok(bool ok_ = true)
    {
        ok() = ok_;
    }

    static bool is_ok() 
    {
        return ok();    
    }

    void add(int x)
    {
        _vec.push_back(x);    
    }

    typedef vector<int>::iterator iterator;
    typedef vector<int>::const_iterator const_iterator;
    iterator begin()
    {
        return _vec.begin();        
    }
    vector<int> _vec;
    
};
