#ifndef TOOLS_IP_H_
#define TOOLS_IP_H_
#include "common_def.h"
#include <string>
#include "tools/IpFinder.h"
namespace gezi {
inline string to_ipstr(uint64 ipl);
inline std::array<int, 4> to_iparray(uint64 ipl);
inline uint64 get_topn_ipgroup(uint64 ipl, int n);
inline void get_ipgroups(uint64 ipl, uint64& top3, uint64& top2, uint64& top1);
inline string get_address(IpFinder& ipFinder, uint64 ipl);
inline string get_location(IpFinder& ipFinder, uint64 ipl);
//inline static IpFinder& ipFinder();
}
#endif
