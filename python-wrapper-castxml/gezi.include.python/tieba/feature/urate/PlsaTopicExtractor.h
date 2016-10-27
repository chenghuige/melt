#ifndef TIEBA_FEATURE_URATE__PLSA_TOPIC_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__PLSA_TOPIC_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "TopicModel/PLSA/PLSAModel.h"
namespace gezi {
namespace tieba {
class PlsaTopicExtractor : public UrateExtractor
{
public:
PlsaTopicExtractor(bool onlyNow = true, string name = "PlsaTopic");
bool _onlyNow;
virtual void init();
Fvec GetTopics(int i);
virtual void extract();
protected:
private:
//static Identifer& identifer();
//static plsa::PLSAModel& model();
};
}
}
#endif
