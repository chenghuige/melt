#ifndef TIME_UTIL_H_
#define TIME_UTIL_H_
#ifndef GCCXML
//#include <boost/date_time/posix_time/posix_time.hpp>
#endif
#include <boost/progress.hpp>
#include <glog/logging.h>
#include <string>
#include "common_def.h"
using std::string;
namespace gezi {
inline string get_now_time_str();
inline string to_time_str(uint64 time);
class MicrosecTimer
{
public:
MicrosecTimer();
~MicrosecTimer();
void restart();
double elapsed();
double elapsed_ms();
private:
#ifndef GCCXML
boost::posix_time::ptime _start_time;
#endif
};
typedef MicrosecTimer Timer;
class AutoTimer
{
public:
string _prefix;
MicrosecTimer _timer;
int _level;
AutoTimer(string prefix, int level = 2);
~AutoTimer();
};
class Noticer
{
public:
Noticer(string info = "Noticer", int level = 0, bool caclTime = true);
~Noticer();
private:
string _info;
Timer* _timer;
int _level;
};
class Notifer
{
public:
Notifer(string info = "Notifer", int level = 0);
~Notifer();
private:
string _info;
Timer _timer;
int _level;
};
#ifndef GCCXML
#include "datetime_util.h"
template<typename _Key,
template<class _Kty, class _Ty, typename...> class _Map = std::unordered_map>
class TimerMap
{
public:
typedef _Key Key;
typedef _Map<Key, int64> Map;
typedef typename Map::iterator iterator;
typedef typename Map::const_iterator const_iterator;
public:
TimerMap();
TimerMap(int64 span);
TimerMap(int capacity);
TimerMap(int64 span, int capacity);
void set_capacity(int capacity);
void SetCapacity(int capacity);
void SetSpan(int span);
bool count(const Key& key);
private:
Map _map;
int64 _span;
};
#endif
}
#endif
