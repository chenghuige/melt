#ifndef TIEBA_FEATURE_RSC_THREAD__RSC_THREAD_EXTRACTOR_H_
#define TIEBA_FEATURE_RSC_THREAD__RSC_THREAD_EXTRACTOR_H_
#include "feature/features_util.h"
#include "tieba/rsc/rsc_threads_info.h"
#include "RscThreadTextScoreExtractor.h"
#include "RscThreadDictMatchExtractor.h"
#include "tools/uname_util.h"
namespace gezi {
namespace tieba {
namespace rsc {
class RscThreadExtractor : public RscThreadsInfo
{
public:
inline vector<pair<Features, ThreadInfo> > GetFeatures(string substr_, vector<ReplyInfo>& tids,
bool isOnline = false, string historyDir = "./history");
private:
//static set<uint64>& tidSet();
set<uint64>& _tidSet;
static map<uint64, int>& labelMap();
map<uint64, int>& _labelMap = labelMap();
static LruMap<uint64, bool>& dealMap();
LruMap<uint64, bool>& _dealMap = dealMap();
static CachedFetcher<uint64, tieba::ThreadInfo, LruHashMap>& threadsFetcher();
static CachedFetcher<uint, tieba::UserInfo, LruHashMap>& usersFetcher();
//static RscThreadTextScoreExtractor& textScoreExtractor();
//static RscThreadDictMatchExtractor& dictMatchExtractor();
};
}
}
}
#endif
