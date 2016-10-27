#ifndef TIEBA_INFO_POST_INFO_H_
#define TIEBA_INFO_POST_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
#include "tools/content_process.h"
#include "tieba/info/url_info.h"
namespace gezi {
namespace tieba {
inline bool get_post_info(uint64 pid, string& title, string& content);
inline void parse_post_info(const Json::Value& m, PostInfo& info);
inline PostInfo get_post_info(uint64 pid);
inline ExtendedPostInfo get_extended_post_info(uint64 pid);
inline vector<PostInfo> get_posts_info(const vector<uint64>& pids_, bool allowError = true);
inline map<uint64, PostInfo> get_posts_info_map(const vector<uint64>& pids_);
inline void parse_img_info(const Json::Value& m, ImgInfo& info);
inline ImgInfo get_img_info(uint64 pid, int64 createTime);
}
}
#endif
