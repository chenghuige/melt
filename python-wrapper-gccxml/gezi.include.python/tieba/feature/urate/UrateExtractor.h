#ifndef TIEBA_FEATURE_URATE__URATE_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__URATE_EXTRACTOR_H_
#include "tieba/urate/extended_urate_info.h"
#include "tieba/urate/get_urate_info.h"
#include "feature/Features.h"
namespace gezi {
namespace tieba {
class UrateExtractor : public FeaturesExtractor
{
public:
//using FeaturesExtractor::FeaturesExtractor;
static size_t size();
static int type();
bool IsThread();
static size_t original_size();
public:
//static ExtendedUrateInfo& info();
ExtendedUrateInfo& _info;
};
}
}
#endif
