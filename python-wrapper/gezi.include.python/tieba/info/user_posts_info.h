#ifndef TIEBA_INFO_USER_POSTS_INFO_H_
#define TIEBA_INFO_USER_POSTS_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
#include "tieba/info/forum_info.h"
namespace gezi {
namespace tieba {
inline UserPostsInfo get_user_posts_info(uint uid, int resNum = 25, bool needContent = true, uint64 endTime = 0, int orderType = 1, int offset = 0);
inline UserPostsInfo get_user_posts_info_until(const PostInfo& info, int resNum = 25, bool needContent = true, int orderType = 1, int offset = 0);
inline UserPostsInfo get_user_posts_info_until(uint64 pid, int resNum = 25, bool needContent = true, int orderType = 1, int offset = 0);
}
}
#endif
