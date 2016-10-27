#ifndef DATETIME_UTIL_H_
#define DATETIME_UTIL_H_
//#include <boost/date_time/posix_time/posix_time.hpp>
#include "common_util.h"
#ifndef GCCXML
using namespace boost::gregorian;
using namespace boost::posix_time;
#endif
namespace gezi
{
inline int get_hour(int64 timestamp);
inline int64 now_time();
static const int kOneDay = 86400;
static const int kOneHour = 3600;
static const int kOneMinute = 60;
}
#endif
