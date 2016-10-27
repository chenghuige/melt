#ifndef TIEBA_FEATURE_URATE__UNUSAL_CN_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__UNUSAL_CN_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class UnusalCnExtractor : public UrateExtractor
{
public:
UnusalCnExtractor(string name = "UnusalCn");
virtual void init();
double GetCommonCnRatio(string content);
int GetCommonCnCount(string content);
virtual void extract();
protected:
private:
//static set<string>& commonCns();
};
}
}
#endif
