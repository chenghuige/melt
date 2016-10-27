#ifndef TIEBA_URATE_URATE_FEATURES_H_
#define TIEBA_URATE_URATE_FEATURES_H_
#include "feature/Features.h"
#include "tieba/feature/urate/SundryExtractor.h"
#include "tieba/feature/urate/UserExtractor.h"
#include "tieba/feature/urate/MediaExtractor.h"
#include "tieba/feature/urate/NumberExtractor.h"
#include "tieba/feature/urate/IpExtractor.h"
#include "tieba/feature/urate/TimeExtractor.h"
#include "tieba/feature/urate/ForumExtractor.h"
#include "tieba/feature/urate/TextExtractor.h"
#include "tieba/feature/urate/UnusalCnExtractor.h"
#include "tieba/feature/urate/UnusalCharExtractor.h"
#include "tieba/feature/urate/TextScoreExtractor.h"
#include "tieba/feature/urate/PlsaTopicExtractor.h"
#include "tieba/feature/urate/TitleSimExtractor.h"
#include "tieba/feature/urate/ContentSimExtractor.h"
#include "tieba/feature/urate/LanguageModelExtractor.h"
#include "tieba/feature/urate/SequenceExtractor.h"
#include "tieba/feature/urate/DictMatchExtractor.h"
#include "tieba/feature/urate/ImgExtrator.h"
namespace gezi {
namespace tieba {
inline void add_urate_features(FeaturesExtractorMgr& mgr);
inline Features gen_urate_features(uint64 pid, string historyPath = "./history", bool useFetch = true, bool forceFetch = false, int historyNum = 25);
inline Features gen_urate_features(uint64 pid, UrateInfo& info, string historyPath = "./history", bool useFetch = true, bool forceFetch = false, int historyNum = 25);
inline void adjust(double& score, const gezi::tieba::UrateInfo& uinfo);
}
}
#endif
