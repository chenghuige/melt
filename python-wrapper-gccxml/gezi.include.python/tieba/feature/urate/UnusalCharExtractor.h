#ifndef TIEBA_FEATURE_URATE__UNUSAL_CHAR_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__UNUSAL_CHAR_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class UnusalCharExtractor : public UrateExtractor
{
public:
UnusalCharExtractor(string name = "UnusalChar");
virtual void init();
virtual void extract();
protected:
private:
};
}
}
#endif
