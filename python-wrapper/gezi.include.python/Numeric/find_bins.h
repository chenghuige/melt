#ifndef NUMERIC_FIND_BINS_H_
#define NUMERIC_FIND_BINS_H_
#include "common_def.h"
#include "sort_util.h"
namespace gezi {
inline int find_distinct_counts(Fvec& values, vector<pair<int, Float> >& countValues);
inline int find_distinct_counts(Fvec& values, int len, vector<pair<int, Float> >& countValues);
inline Fvec find_bins(vector<pair<int, Float> >& countValues,
vector<pair<Float, Float> >& binLowerUpperBounds,
int maxBins, int sampleSize, int numDistinctValues);
inline Fvec find_bins_(Fvec& values, int maxBins,
vector<pair<Float, Float> >& binLowerUpperBounds,
vector<pair<int, Float> >& countValues);
inline Fvec find_bins_(Fvec& values, int len, int maxBins,
vector<pair<Float, Float> >& binLowerUpperBounds,
vector<pair<int, Float> >& countValues);
inline void find_medians(vector<pair<int, Float> >& countValues,
int numValues, int maxBins,
Fvec& binUpperBounds, Fvec& binMedians);
inline void find_bins_(Fvec& values, int maxBins,
vector<pair<Float, Float> >& binLowerUpperBounds,
vector<pair<int, Float> >& countValues,
Fvec& binUpperBounds, Fvec& binMedians);
inline void find_bins_(Fvec& values, int len, int maxBins,
vector<pair<Float, Float> >& binLowerUpperBounds,
vector<pair<int, Float> >& countValues,
Fvec& binUpperBounds, Fvec& binMedians);
inline Fvec find_bins(Fvec& values, int maxBins);
inline Fvec find_bins(Fvec& values, int len, int maxBins);
inline void find_bins(Fvec& values, int maxBins, Fvec& binUpperBounds, Fvec& binMedians);
inline void find_bins(Fvec& values, int len, int maxBins, Fvec& binUpperBounds, Fvec& binMedians);
}
#endif
