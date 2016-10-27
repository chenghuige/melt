#ifndef TOOLS_CONTENT_PROCESS_H_
#define TOOLS_CONTENT_PROCESS_H_
#include "string_util.h"
#include "reg_util.h"
#include "stl_util.h"
namespace gezi {
inline string strip_html(string src);
inline string strip_from(string src);
inline vector<string> get_pics(string src);
inline bool contains_pic(string src);
inline vector<string> get_ats(string src);
inline bool contains_at(string src);
inline vector<string> get_videos(string src);
inline bool contains_video(string src);
inline vector<string> get_emails(string src);
inline bool contains_emails(string src);
inline bool contains_audio(string src);
inline vector<string> get_urls(string src);
inline bool contains_url(string src);
inline vector<string> get_nums(string src);
inline bool contains_num(string src);
inline bool contains_any(string src, string type);
}
#endif
