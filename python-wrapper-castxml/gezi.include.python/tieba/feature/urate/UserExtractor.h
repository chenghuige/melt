#ifndef TIEBA_FEATURE_URATE__USER_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__USER_EXTRACTOR_H_
#include "common_util.h"
#include "feature/Features.h"
#include "tieba/info_def.h"
#include "tieba/urate/urate_info.h"
#include "tieba/tieba_util.h"
#include "tools/uname_util.h"
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class UserExtractor : public UrateExtractor
{
public:
UserExtractor(bool useNowPostInfo = true,
bool useHistoryPostNum = true,
string name = "User");
#ifndef GCCXML
static map<string, double>& nameCnFreqMap();
map<string, double>& _nameCnFreqMap = nameCnFreqMap();
#endif
virtual void extract();
private:
bool _useNowPostInfo;
bool _useHistoryPostNum;
};
}
}
#endif
