#ifndef _NORMALIZE_FILTER_H_
#define _NORMALIZE_FILTER_H_
#include "Feature.h"
#include "common_util.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <string.h>
namespace gezi
{
class FeatureNormalizer
{
public:
FeatureNormalizer(int startIndex = 1, bool useTruncate = false, int maxFeatureNum = 102400);
FeatureNormalizer& startIndex(int startIndex_);
FeatureNormalizer& useTruncate(bool useTruncate_);
FeatureNormalizer& maxFeatureNum(int maxFeatureNum_);
struct Pair
{
Pair();
Pair(double lower_, double upper_);
double lower;
double upper;
};
bool open(const char* file);
int featureNum();
void norm(int index, double value, vector<Feature::Node>& result);
int normalize(Feature* feature);
private:
int _featureNum;
vector<Pair> _pairs;
double _lower;
double _upper;
int _startIndex;
bool _useTruncate;
};
}
#endif
