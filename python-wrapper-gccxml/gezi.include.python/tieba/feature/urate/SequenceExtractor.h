#ifndef TIEBA_FEATURE_URATE__SEQUENCE_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__SEQUENCE_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class SequenceExtractor : public UrateExtractor
{
public:
SequenceExtractor(string name = "Sequence");
virtual void init();
struct Node
{
bool hasPic;
bool hasAt;
bool hasUrl;
bool hasAny;
bool isShortContent;
bool hasSecondFloor;
};
virtual void extract();
protected:
private:
};
}
}
#endif
