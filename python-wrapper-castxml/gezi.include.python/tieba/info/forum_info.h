#ifndef TIEBA_INFO_FORUM_INFO_H_
#define TIEBA_INFO_FORUM_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
namespace gezi {
namespace tieba {
inline uint get_forum_id(string forumName);
inline vector<uint> get_forum_ids(const svec& forumNames_, bool allowError = true);
inline string get_forum_name(uint forumId);
inline map<string, uint> get_forum_ids_map(const svec& forumNames_);
inline map<uint, string> get_forum_names_map(const vector<uint>& forumIds_);
inline vector<string> get_forum_names(const vector<uint>& forumIds);
inline ForumInfo get_forum_info(uint forumId);
inline ForumInfo get_forum_info(string forumName);
inline vector<ForumInfo> get_forums_info(vector<uint> forumIds_, bool allowError = true);
inline map<uint, ForumInfo> get_forums_info_map(vector<uint> forumIds_);
}
}
#endif
