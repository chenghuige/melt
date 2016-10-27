#ifndef TIEBA_INFO_URL_INFO_H_
#define TIEBA_INFO_URL_INFO_H_
#include "tieba/get_info.h"
#include "tieba/info_def.h"
namespace gezi {
namespace tieba {
inline string get_url_info_params_(const vector<string>& urls);
inline map<string, UrlInfo> get_urls_info_map(const vector<string>& urls);
inline vector<UrlInfo> get_urls_info(const vector<string>& urls);
inline UrlInfo get_url_info(string url);
}
}
#endif
