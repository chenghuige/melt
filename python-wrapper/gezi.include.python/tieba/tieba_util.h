#ifndef TIEBA__TIEBA_UTIL_H_
#define TIEBA__TIEBA_UTIL_H_
#include "common_util.h"
namespace gezi {
namespace tieba {
inline uint64 reg_span(uint64 nowTime, uint64 regTime);
inline int reg_days(uint64 nowTime, uint64 regTime);
inline bool is_thread(string title);
inline string get_real_title(string title);
}
}
#endif
