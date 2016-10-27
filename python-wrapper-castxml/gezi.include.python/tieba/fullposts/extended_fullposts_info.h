#ifndef TIEBA_FULLPOSTS_EXTENDED_FULLPOSTS_INFO_H_
#define TIEBA_FULLPOSTS_EXTENDED_FULLPOSTS_INFO_H_
#include "tieba/info_def.h"
#include "tieba/feature/feature_extractor_util.h"
#include "tools/ip.h"
namespace gezi {
namespace tieba {
struct ExtendedFullPostsInfo : public FullPostsInfo
{
ExtendedFullPostsInfo();
ExtendedFullPostsInfo(const FullPostsInfo& info);
//ExtendedFullPostsInfo(FullPostsInfo&& info);
void Init();
void SetSize();
void Shrink();
static string name();
size_t size();
protected:
void ExtractUrls();
void ExtractPics();
void ExtractAts();
void ExtractHtmlFilteredContents();
void ExtractFilteredContents();
void ExtractNormalizedContents();
void ExtractNormalizedFilteredContents();
void ExtractLocations();
void ExtractTop2Ips();
public:
int numConsideredPosts;
uint64 postId;
vector<svec> picsVec;
vector<svec> urlsVec;
vector<svec> atsVec;
vector<svec> numbersVec;
svec htmlFilteredContents;
svec normalizedContents;
svec filteredContents;
svec normalizedFilteredContents;
svec locations;
vector<uint64> top2Ips;
};
}
}
#endif
