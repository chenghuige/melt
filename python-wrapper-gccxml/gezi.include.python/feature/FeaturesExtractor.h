#ifndef FEATURE__FEATURES_EXTRACTOR_H_
#define FEATURE__FEATURES_EXTRACTOR_H_
#include "feature/FeatureVector.h"
#include "feature/features_util.h"
namespace gezi {
class FeaturesExtractor
{
public:
FeaturesExtractor(string name = "");
virtual ~FeaturesExtractor();
virtual void init();
virtual void extract();
bool is_filtered();
void bind(Features* features);
virtual void process(Features* features);
string name();
Features* features();
Features* feature();
void add(double value, string name = "");
template<typename Vec>
void add(Vec& values, string name = "");
void add(double* values, int n, string name = "");
protected:
string _name;
Features* _features;
bool _isFiltered;
};
#define ADD_FEATURE(value)\
_features->add(value, #value)
#define ADD_FEATURE_WITH_PREFIX(value, name)\
if (!name.empty())\
_features->add(value, name + "_" + #value);\
else\
ADD_FEATURE(value)
}
#endif
