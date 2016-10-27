#ifndef NUMERIC__BIN_FINDER_H_
#define NUMERIC__BIN_FINDER_H_
#include "Numeric/find_bins.h"
namespace gezi {
class BinFinder
{
private:
vector<pair<Float, Float> > _binLowerUpperBounds;
vector<pair<int, Float> > _countValues;
public:
Fvec FindBins(Fvec& values, int maxBins);
Fvec FindBins(Fvec& values, int len, int maxBins);
void FindBins(Fvec& values, int maxBins, Fvec& binUpperBounds, Fvec& binMedians);
void FindBins(Fvec& values, int len, int maxBins, Fvec& binUpperBounds, Fvec& binMedians);
};
}
#endif
