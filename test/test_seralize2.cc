define BOOST_ALL_NO_LIB  
#include <iostream>  
#include <fstream>  
#include <boost/archive/text_iarchive.hpp>  
#include <boost/archive/text_oarchive.hpp>  
#include <boost/serialization/export.hpp>  
  
class A  
{  
public:  
    int a;  
    A() : a(0) {}  
    virtual void foo() = 0;  
    friend class boost::serialization::access;  
    template<class Archive>  
    void serialize(Archive & ar, const unsigned int version)  
    {  
        ar & a;  
    }  
};  
  
BOOST_SERIALIZATION_ASSUME_ABSTRACT(A)  
  
class A_1 : public A  
{  
public:  
    int a1;  
    A_1() { a=1; a1=11;}  
    virtual void foo() { std::cout << "A_1:" << a << ", " << a1 << std::endl; }  
    template<class Archive>  
    void serialize(Archive & ar, const unsigned int version)  
    {  
        ar & boost::serialization::base_object<A>(*this);  
        ar & a1;  
    }  
};  
  
BOOST_CLASS_EXPORT(A_1)  
  
class A_2 : public A  
{  
public:  
    int a2;  
    A_2() { a=2; a2=22;}  
    virtual void foo() { std::cout << "A_2:" << a << ", " << a2 << std::endl; }  
    template<class Archive>  
    void serialize(Archive & ar, const unsigned int version)  
    {  
        ar & boost::serialization::base_object<A>(*this);  
        ar & a2;  
    }  
};  
  
BOOST_CLASS_EXPORT(A_2)  
  
int main(int argc, char ** argv)  
{  
    A * pa = new A_2();  
    std::ofstream ofs("aaa.txt");  
    boost::archive::text_oarchive oa(ofs);  
    oa << pa;  
    ofs.close();  
  
    A * pa2;  
    std::ifstream ifs("aaa.txt");  
    boost::archive::text_iarchive ia(ifs);  
    ia >> pa2;  
    ifs.close();  
    return 0;  
}  