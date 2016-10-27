#ifndef TIEBA_FEATURE_URATE__IP_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__IP_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class IpExtractor : public UrateExtractor
{
public:
IpExtractor(string name = "Ip");
virtual void init();
static bool IsForeignLocation(string location);
void Extract(const vector<uint64>& ips, const svec& locations,
const vector<int64>& times, int maxSpanHours);
virtual void extract();
protected:
private:
};
}
}
#endif
