#ifndef TIEBA_URATE_EXTENDED_URATE_INFO_H_
#define TIEBA_URATE_EXTENDED_URATE_INFO_H_
#include "tieba/urate/urate_info.h"
#include "tieba/feature/feature_extractor_util.h"
#include "tools/ip.h"
namespace gezi {
namespace tieba {
struct ExtendedUrateInfo : public UrateInfo
{
public:
ExtendedUrateInfo();
ExtendedUrateInfo(const UrateInfo& urateInfo);
//ExtendedUrateInfo(UrateInfo&& urateInfo);
void Init();
static string name();
void ExtractUrls();
void ExtractPics();
void ExtractAts();
void ExtractEmails();
void ExtractVideos();
void ExtractAudios();
void ExtractNumbers();
void ExtractNormedNumbers();
void ExtractHtmlFilteredContents();
void ExtractGbkDualContents();
void ExtractNormalizedContents();
void ExtractCnContents();
void ExtractNormalizedTitles();
void ExtractCnTitles();
void ExtractNormalizedFilteredContents();
void ExtractLocations();
void ExtractOriginalLocations();
void ExtractThreadReplyHtmlFilteredContents();
void ExtractThreadReplyNormalizedContents();
void ExtractThreadReplyCnContents();
void ExtractThreadReplyTitles();
void ExtractThreadReplyNormalizedTitles();
void ExtractThreadReplyCnTitles();
void ExtractFilteredContents();
int Type();
int64 NowTime();
private:
void SetHistorySize();
void SetType();
void ShrinkHistory();
void AdjustLikedForums();
public:
vector<svec> urlsVec;
vector<svec> picsVec;
vector<svec> atsVec;
vector<svec> videosVec;
vector<svec> emailsVec;
vector<bool> audiosVec;
vector<svec> numbersVec;
vector<svec> normedNumbersVec;
svec htmlFilteredContents;
svec& GetHtmlFilteredContents();
svec normalizedContents;
svec cnContents;
svec filteredContents;
svec normalizedFilteredContents;
svec gbkDualContents;
svec threadHtmlFilteredContents;
svec threadCnContents;
svec threadNormalizedContents;
svec replyHtmlFilteredContents;
svec replyCnContents;
svec replyNormalizedContents;
svec threadTitles;
svec threadNormalizedTitles;
svec threadCnTitles;
svec replyTitles;
svec replyNormalizedTitles;
svec replyCnTitles;
svec normalizedTitles;
svec cnTitles;
svec originalLocations;
svec locations;
int historySize;
UserPostsInfo originalPostsInfo;
private:
bool _type;
public:
static void InitIpFinder();
//static IpFinder& ipFinder();
public:
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
}
}
#endif
