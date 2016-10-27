#ifndef TIEBA_FEATURE_URATE__TIME_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__TIME_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class TimeExtractor : public UrateExtractor
{
public:
TimeExtractor(string name = "Time");
static void extract_bins(const vector<int64>& times, int binNum, int startHour,
int& firstBin, vector<double>& binValues);
void ExtractBins();
void ExtractHoursCovered();
static void calc_delta_count(const vector<int64>& deltas, const ivec& intervals,
ivec& counts);
void ExtractDeltaCount(const vector<int64>& deltas, string name = "");
void ExtractDeltas();
void ExtractBehaviorChanges();
virtual void extract();
protected:
private:
};
}
}
#endif
