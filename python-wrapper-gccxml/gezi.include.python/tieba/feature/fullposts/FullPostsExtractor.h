#ifndef TIEBA_FEATURE_FULLPOSTS__FULL_POSTS_EXTRACTOR_H_
#define TIEBA_FEATURE_FULLPOSTS__FULL_POSTS_EXTRACTOR_H_
#include "tieba/fullposts/extended_fullposts_info.h"
#include "feature/Features.h"
namespace gezi {
namespace tieba {
class FullPostsExtractor : public FeaturesExtractor
{
public:
//using FeaturesExtractor::FeaturesExtractor;
public:
//static ExtendedFullPostsInfo& info();
ExtendedFullPostsInfo& _info;
size_t size();
};
}
}
#endif
