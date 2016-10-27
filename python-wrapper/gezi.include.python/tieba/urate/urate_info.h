#ifndef TIEBA_URATE_URATE_INFO_H_
#define TIEBA_URATE_URATE_INFO_H_
#include "tieba/info_def.h"
#include "serialize_util.h"
#include <sstream>
namespace gezi {
namespace tieba {
struct UrateInfo
{
uint64 postId;
PostInfo nowPostInfo;
UserPostsInfo postsInfo;
UserInfo userInfo;
UserLikeForumInfo userLikeForumInfo;
UserPostNumInfo userPostNumInfo;
ImgInfo imginfo;
map<uint, UserPostNumInfo> userPostNumInForum;
map<string, UrlInfo> urlInfoMap;
vector<vector<string> > urlsVec;
bool isWhiteTitle;
bool IsValid();
int type();
size_t size();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
inline string get_urate_info_str(const UrateInfo& info);
}
}
#endif
