#ifndef TIEBA_GET_INFO_H_
#define TIEBA_GET_INFO_H_
#include "common_util.h"
#include "curl_util.h"
#include "json/json.h"
#include "random_util.h"
namespace gezi {
namespace tieba {
static const char* const kTiebaGetInfoName = "Tieba.GetInfo";
inline void get_field_method(string url, string& field, string& method);
inline string get_info_str(string url, int timeout = -1);
inline string get_posts_info_str(string pids);
inline string get_post_info_str(uint64 pid);
inline string get_post_info_str(const svec& pids);
inline string get_posts_info_str(const svec& pids);
inline string get_posts_info_str(const vector<uint64>& pids);
inline string get_threads_info_str(string tids_, bool need_abstract = true);
inline string get_threads_info_str(const svec& tids, bool need_abstract = true);
inline string get_threads_info_str(const vector<uint64>& tids, bool need_abstract = true);
inline string get_thread_info_str(uint64 tid, bool need_abstract = true);
inline string get_delete_info_str(string pids);
inline string get_user_fans(uint64 uid);
inline bool get_user_fans(uint64 uid, AnyMap& result);
inline bool get_user_fans(uint64 uid, int& follow_count, int& followed_count);
inline string get_full_posts_info_str(uint64 threadId, int resNum = 100, int offset = 0, int hasComment = 0, uint64 postId = 0);
inline string get_forum_id_str(string forumNames);
inline string get_forum_name_str(string params);
inline string get_forum_name_str(uint forumId);
inline string get_forum_name_str(const vector<uint>& forumIds);
inline string get_forum_info_str(string params);
inline string get_forum_info_str(uint forumId);
inline string get_forums_info_str(const vector<uint>& forumIds);
inline string get_img_info_str(uint64 pid, int64 createTime);
template<typename InfoType, typename Func>
inline InfoType try_get_info(uint64 id, Func func, string historyDir, bool useFetch = true, bool forceFetch = false,
string suffix = "", bool retry = true);
template<typename IdType, typename InfosType, typename Func>
void try_get_infos_(const vector<IdType>& ids, InfosType& infos, Func func, string historyDir, string historyName,
bool useFetch = true, bool forceFetch = false, string suffix = "");
template<typename InfoType, typename Func>
inline vector<InfoType> try_get_infos(const vector<uint64>& ids, Func func, string historyDir, string historyName,
bool useFetch = true, bool forceFetch = false, string suffix = "");
template<typename IdType, typename InfoType, typename Func>
inline map<IdType, InfoType> try_get_infos_map(const vector<IdType>& ids, Func func, string historyDir, string historyName,
bool useFetch = true, bool forceFetch = false, string suffix = "");
}
}
#endif
