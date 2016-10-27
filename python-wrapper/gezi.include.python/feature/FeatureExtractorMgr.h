#ifndef FEATURE_EXTRACTOR_MGR_H_
#define FEATURE_EXTRACTOR_MGR_H_
#include "FeatureExtractor.h"
namespace gezi
{
class FeatureExtractorMgr
{
public:
virtual ~FeatureExtractorMgr();
void add(FeatureExtractor* extractor);
void extract(Feature* feature);
FeatureExtractor* extractor();
vector<FeatureExtractor*>& extractors();
private:
vector<FeatureExtractor*> _extractors;
};
}
#endif
