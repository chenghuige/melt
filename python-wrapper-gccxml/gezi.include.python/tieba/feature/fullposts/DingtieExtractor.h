#ifndef TIEBA_FEATURE_FULLPOSTS__DINGTIE_EXTRACTOR_H_
#define TIEBA_FEATURE_FULLPOSTS__DINGTIE_EXTRACTOR_H_
#include "FullPostsExtractor.h"
#include "tools/uname_util.h"
#include "MatchDict.h"
namespace gezi {
namespace tieba {
class DingtieExtractor : public FullPostsExtractor
{
public:
DingtieExtractor(string name = "Dingtie");
virtual void init();
virtual void extract();
protected:
private:
//static MatchDict& shanqianDict();
};
}
}
#endif
