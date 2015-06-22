#include <iostream>
#include <vector>
using namespace std;

//enum color
//{
//    red,
//    green,
//    black
//};

enum class color
{
    red,
    green,
    black
};

//enum class face { good, bad };
class Example{
public:
color GetColor()
{
    return color::green;
}

void setcoror(color color_ = color::black)
{
}

void setcoror2(int x, 
    color color_ = color::black)
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

#ifndef GCCXML
    static bool& ok()
    {
        static bool _ok = true;
        return _ok;
    }

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
