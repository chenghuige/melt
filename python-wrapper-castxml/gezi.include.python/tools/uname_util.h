#ifndef TOOLS_UNAME_UTIL_H_
#define TOOLS_UNAME_UTIL_H_
#include "common_util.h"
namespace gezi {
inline string name_pattern(string uname);
inline string simple_name_pattern(string uname);
inline vector<int> name_feature(string uname);
inline bool is_qq_name(string uname);
inline bool is_en_num_name(const vector<int>& nameFeatures);
inline bool is_en_num_name(string uname);
inline bool is_en_num_simple_name_pattern(string pattern);
}
#endif
