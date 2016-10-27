#ifndef TIEBA_FEATURE_FEATURE_EXTRACTOR_UTIL_H_
#define TIEBA_FEATURE_FEATURE_EXTRACTOR_UTIL_H_
#include "common_util.h"
#include "tools/content_process.h"
namespace gezi {
namespace tieba {
inline double simFunc1(string s1, string s2);
inline double simFunc2(string s1, string s2);
inline bool strComp(const string &a, const string &b);
inline bool strComp2(const string &a, const string &b);
inline string filter_content(string content, int max_content_length);
}
}
#endif
