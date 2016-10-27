#ifndef FEATURE_EXTRACTOR_H_
#define FEATURE_EXTRACTOR_H_
#include "Feature.h"
#include "feature/feature_util.h"
namespace gezi
{
class FeatureExtractor
{
public:
FeatureExtractor(string name = "");
virtual ~FeatureExtractor();
virtual void init();
virtual void extract();
void bind(Feature* feature);
virtual void process(Feature* feature);
string name();
inline Feature* feature();
inline void add(double value, string name = "");
template<typename Vec>
inline void add(Vec& values, string name = "");
inline void add(double* values, int n, string name = "");
protected:
string _name;
Feature* _feature;
};
}
#endif
