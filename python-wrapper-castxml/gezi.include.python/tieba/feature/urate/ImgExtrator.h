#ifndef TIEBA_FEATURE_URATE__IMG_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__IMG_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class ImgExtractor : public UrateExtractor
{
public:
ImgExtractor(string name = "Img");
virtual void extract();
protected:
private:
void ExtractInformation();
void ExtractOCR();
};
}
}
#endif
