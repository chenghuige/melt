#ifndef TIEBA_FEATURE_URATE__NUMBER_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__NUMBER_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class NumberExtractor : public UrateExtractor
{
public:
NumberExtractor(string name = "Number");
virtual void init();
virtual void extract();
protected:
private:
};
}
}
#endif
