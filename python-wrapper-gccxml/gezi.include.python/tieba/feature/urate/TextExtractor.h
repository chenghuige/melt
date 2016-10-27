#ifndef TIEBA_FEATURE_URATE__TEXT_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__TEXT_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class TextExtractor : public UrateExtractor
{
public:
TextExtractor(string name = "Text");
virtual void init();
double ExtractLengthMeanVar(svec& contents, double defaultLengthMean, string name = "");
double ExtractLengthMeanVar(svec& contents, double& lengthMean, double& threadLengthMean, double& replyLengthMean,
string name = "");
virtual void extract();
protected:
private:
};
}
}
#endif
