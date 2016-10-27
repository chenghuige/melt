#ifndef TIEBA_FEATURE_URATE__TITLE_SIM_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__TITLE_SIM_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "tieba/feature/feature_extractor_util.h"
namespace gezi {
namespace tieba {
class TitleSimExtractor : public UrateExtractor
{
public:
TitleSimExtractor(string name = "TitleSim");
virtual void extract();
private:
double simSum(vector<string>& newContents);
double simF1(vector<string>& contents, vector<string>& vec);
};
}
}
#endif
