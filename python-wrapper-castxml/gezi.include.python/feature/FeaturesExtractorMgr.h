#ifndef FEATURE__FEATURES_EXTRACTOR_MGR_H_
#define FEATURE__FEATURES_EXTRACTOR_MGR_H_
#include "feature/FeaturesExtractor.h"
namespace gezi {
class FeaturesExtractorMgr
{
public:
virtual ~FeaturesExtractorMgr();
void add(FeaturesExtractor* extractor);
void extract(Features& features);
void extract(Features* features);
FeaturesExtractor* extractor();
vector<FeaturesExtractor*>& extractors();
const vector<FeaturesExtractor*>& extractors() const;
private:
vector<FeaturesExtractor*> _extractors;
};
}
#endif
