#ifndef GEZI_TIEBA_FEATURE_URATE__DEFORM_EXTRACTOR_H_
#define GEZI_TIEBA_FEATURE_URATE__DEFORM_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "deformation-procs/deformation_text.h"
namespace gezi {
namespace tieba {
class DeformExtractor : public UrateExtractor
{
public:
DeformExtractor(const string& name = "Deform");
virtual void init();
int NumDeforms(string str);
virtual void extract();
protected:
private:
//static deformation_text& deformation();
};
}
}
#endif
