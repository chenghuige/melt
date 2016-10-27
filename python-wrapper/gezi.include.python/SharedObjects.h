#ifndef SHARED_OBJECTS_H_
#define SHARED_OBJECTS_H_
#include "common_util.h"
namespace gezi {
template<typename Obj>
static Obj ConstructObj(string path);
template<typename Obj, typename Func>
static Obj ConstructObj(Func func);
template<typename T>
class SharedObjects
{
public:
//static T& Instance(string path);
//template<typename Func>
//static T& Instance(string path, Func func);
//static T& instance(string path);
protected:
private:
};
}
#endif
