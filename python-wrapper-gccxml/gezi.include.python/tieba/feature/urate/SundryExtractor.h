#ifndef TIEBA_FEATURE__SUNDRY_EXTRACTOR_H_
#define TIEBA_FEATURE__SUNDRY_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class SundryExtractor : public UrateExtractor
{
public:
SundryExtractor(string name = "Sundry");
virtual void extract();
protected:
private:
};
}
}
#endif
