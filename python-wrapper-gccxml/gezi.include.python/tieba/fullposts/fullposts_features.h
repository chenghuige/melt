#ifndef TIEBA_FULLPOSTS_FULLPOSTS_FEATURES_H_
#define TIEBA_FULLPOSTS_FULLPOSTS_FEATURES_H_
#include "feature/Features.h"
#include "tieba/feature/fullposts/DingtieExtractor.h"
#include "tieba/feature/fullposts/SequenceExtractor.h"
#include "tieba/feature/fullposts/TextScoreExtractor.h"
#include "tieba/urate/urate_features.h"
#include "tieba/get_info.h"
#include "other/CachedFetcher.h"
namespace gezi {
namespace tieba {
inline void add_fullposts_features(FeaturesExtractorMgr& mgr);
inline Features gen_fullposts_features(uint64 tid, int num, string historyPath, string urateHistoryPath, bool useFetch = true, bool forceFetch = false);
template<typename Fetcher>
inline Features gen_fullposts_features(uint64 tid, int num, Fetcher& fetcher);
}
}
#endif
