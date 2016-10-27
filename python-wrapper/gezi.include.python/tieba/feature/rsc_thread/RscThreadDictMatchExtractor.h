#ifndef TIEBA_FEATURE_RSC_THREAD__RSC_THREAD_DICT_MATCH_EXTRACTOR_H_
#define TIEBA_FEATURE_RSC_THREAD__RSC_THREAD_DICT_MATCH_EXTRACTOR_H_
#include "MatchDict.h"
#include "RegexSearcher.h"
#include "feature/features_util.h"
namespace gezi {
namespace tieba {
namespace rsc {
class RscThreadDictMatchExtractor
{
public:
RscThreadDictMatchExtractor();
void getBlackMatchCount(string content, Features& fe);
private:
gezi::MatchDict _blackDict;
int _maxMatchCount;
RegexSearcher _blackRegSearcher;
};
}
}
}
#endif
