#ifndef TIEBA_INFO_THREAD_INFO_H_
#define TIEBA_INFO_THREAD_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
namespace gezi {
namespace tieba {
inline vector<ThreadInfo> get_threads_info(const svec& tidVec, bool need_abstract = true, bool allowError = true);
inline vector<ThreadInfo> get_threads_info(const vector<uint64>& tidVec, bool need_abstract = true, bool allowError = true);
inline map<uint64, ThreadInfo> get_threads_info_map(const vector<uint64>& tidVec, bool need_abstract = true);
inline ThreadInfo get_thread_info(uint64 threadId, bool need_abstract = true, bool allowError = true);
inline FullPostsInfo get_full_posts_info(uint64 threadId, int resNum = 100, int offset = 0, int hasComment = 0, uint64 postId = 0);
}
}
#endif
