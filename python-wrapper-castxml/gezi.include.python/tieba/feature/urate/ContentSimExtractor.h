#ifndef TIEBA_FEATURE_URATE__CONTENT_SIM_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__CONTENT_SIM_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "tieba/feature/feature_extractor_util.h"
namespace gezi {
namespace tieba {
class ContentSimExtractor : public UrateExtractor
{
public:
ContentSimExtractor(const string& name = "ContentSim");
virtual void init();
virtual void extract();
private:
double simSum(vector<string>& newContents);
double simF1(vector<string>& contents, vector<string>& vec);
double simF2(vector<string>& contents, vector<string>& vec);
};
}
}
#endif
