#ifndef TIEBA_FEATURE_URATE__MEDIA_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__MEDIA_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class MediaExtractor : public UrateExtractor
{
public:
MediaExtractor(string name = "Media");
virtual void init();
void ExtractCurrentPost();
void ExtractCount();
void ExtractCountInOnePost(const vector<svec>& inVec, string name);
void ExtractUrlHostRank();
virtual void extract();
protected:
private:
dvec _hostRanks;
double _defaultHostRank;
};
}
}
#endif
