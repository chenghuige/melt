#ifndef SHARED_IDENTIFERS_H_
#define SHARED_IDENTIFERS_H_
#include "Identifer.h"
namespace gezi {
class Identifer;
class SharedIdentifers
{
public:
//static Identifer& Instance();
//static Identifer& Instance(string path);
//static Identifer& instance(string path);
protected:
private:
};
template<typename T>
class ValueIdentifer;
template<typename T>
class SharedValueIdentifers
{
public:
static shared_ptr<ValueIdentifer<T> >& Instance(string path);
};
typedef SharedValueIdentifers<int> SharedIntIdentifers;
typedef SharedValueIdentifers<double> SharedDoubleIdentifers;
}
#endif
