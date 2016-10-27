#ifndef TIEBA_FEATURE_URATE__FORUM_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__FORUM_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
namespace gezi {
namespace tieba {
class ForumExtractor : public UrateExtractor
{
public:
ForumExtractor(bool isOnline = true, string name = "Forum");
bool _isOnline;
#ifndef GCCXML
static map<string, int>& level1Identifer();
map<string, int>& _level1Identifer = level1Identifer();
static map<string, double>& rankIdentifer();
map<string, double>& _rankIdentifer = rankIdentifer();
#endif
virtual void extract();
protected:
private:
void ExtractInformation();
void ExtractRank();
void ExtractFormTitleMatch();
void ExtractLevel1Info();
};
}
}
#endif
