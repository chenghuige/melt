#ifndef TIEBA_INFO_USER_INFO_H_
#define TIEBA_INFO_USER_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
namespace gezi {
namespace tieba {
inline void parse_user_post_num_info_(const Json::Value& root, UserPostNumInfo& info);
inline UserPostNumInfo get_user_post_num_info_(string url);
inline UserPostNumInfo get_user_post_num_info(uint uid);
inline UserPostNumInfo get_user_post_num_info(uint uid, uint forumId);
inline UserLikeForumInfo get_user_like_forum_info(uint uid);
inline void parse_user_info_(const Json::Value& m, UserInfo& info, bool needFollowInfo, bool needPassInfo);
inline UserInfo get_user_info(uint uid, bool needFollowInfo = true, bool needPassInfo = true);
inline vector<UserInfo> get_users_info(const vector<uint> uids_,
bool needFollowInfo = true, bool needPassInfo = true);
inline map<uint, UserInfo> get_users_info_map(const vector<uint> uids_, bool needFollowInfo = true, bool needPassInfo = true);
}
}
#endif
