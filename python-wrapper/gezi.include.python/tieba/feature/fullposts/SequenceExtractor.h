#ifndef TIEBA_FEATURE_FULLPOSTS__SEQUENCE_EXTRACTOR_H_
#define TIEBA_FEATURE_FULLPOSTS__SEQUENCE_EXTRACTOR_H_
#include "FullPostsExtractor.h"
namespace gezi {
namespace tieba {
class FPSequenceExtractor : public FullPostsExtractor
{
public:
FPSequenceExtractor(string name = "FPSequence");
virtual void init();
struct ThreadNode
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
