#ifndef TIEBA_INFO_DELETE_INFO_H_
#define TIEBA_INFO_DELETE_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
namespace gezi {
namespace tieba {
inline bool is_deleted(uint64 id, string type);
inline bool is_thread_deleted(uint64 tid);
inline bool is_post_deleted(uint64 pid);
inline void parse_delete_info_(const Json::Value& jsonDelInfo, DeleteInfo& deleteInfo, string type);
inline DeleteInfo get_delete_info(uint64 id, string type);
inline DeleteInfo get_thread_delete_info(uint64 tid);
inline DeleteInfo get_post_delete_info(uint64 pid);
inline set<uint64> is_deletes(const vector<uint64>& ids_, string type, bool allowError = true);
inline set<uint64> is_threads_deleted(const vector<uint64>& tids, bool allowError = true);
inline set<uint64> get_deleted_threads(const vector<uint64>& tids, bool allowError = true);
inline set<uint64> is_posts_deleted(const vector<uint64>& pids, bool allowError = true);
inline set<uint64> get_deleted_posts(const vector<uint64>& pids, bool allowError = true);
inline map<uint64, DeleteInfo> get_deletes_info(const vector<uint64>& ids_, string type, bool allowError = true);
inline map<uint64, DeleteInfo> get_threads_delete_info(const vector<uint64>& tids, bool allowError = true);
inline map<uint64, DeleteInfo> get_posts_delete_info(const vector<uint64>& pids, bool allowError = true);
inline int get_posts_delete_info(const vector<uint64>& pids, const vector<uint64>& tids, int maxCount = 50);
inline bool get_post_deleted_info(uint64 pid, uint64 tid, bool& isPostDeleted, bool& isThreadDeleted);
}
}
#endif
