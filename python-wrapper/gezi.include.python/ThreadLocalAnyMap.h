#ifndef THREAD_LOCAL_ANY_MAP_H_
#define THREAD_LOCAL_ANY_MAP_H_
namespace gezi {
#ifdef __GNUC__
class ThreadLocalAnyMap
{
public:
//static AnyMap& Instance();
};
typedef ThreadLocalAnyMap ThreadLocalData;
#endif
}
#endif
