#ifndef TIEBA_RSC_RSC_THREADS_INFO_H_
#define TIEBA_RSC_RSC_THREADS_INFO_H_
#include "other/CachedFetcher.h"
#include "tieba/get_parsed_info.h"
#include "container/lru_containers.h"
#include "tools/ip.h"
namespace gezi {
namespace tieba {
namespace rsc {
struct ReplyInfo
{
uint64 tid;
uint userId;
uint64 pid;
uint64 ip;
uint64 time;
double threadRatio;
};
struct RscThreadsInfo
{
RscThreadsInfo();
template<typename ThreadInfoFetcher, typename UserInfoFetcher>
void Fetch(string substr_, vector<ReplyInfo>& tids, ThreadInfoFetcher& threadFetcher, UserInfoFetcher& userFetcher,
bool isOnline = false, string historyDir = "./history");
void Extract();
string substr;
vector<ThreadInfo> threadsInfo;
map<uint, UserInfo> usersInfo;
map<uint64, ReplyInfo> replysInfo;
map<uint64, ThreadInfo> threadNodeMap;
map<uint64, int> uidCountMap;
map<uint64, int> ipCountMap;
map<uint64, int> uidDistinctCountMap;
map<uint64, set<uint64> > uidsetPerIp;
map<uint64, set<uint64> > ipsetPerUid;
map<uint64, set<string> > addressSetPerUid;
map<uint64, int> numIpsPerUidMap;
map<uint64, int> numUidsPerIpMap;
map<uint64, int> numAddressesPerUidMap;
set<uint64> uidSet;
set<uint64> notSelfUpUidSet;
set<uint64> ipSet;
set<string> addressSet;
//static IpFinder& ipFinder();
IpFinder& _ipFinder;
};
}
}
}
#endif
