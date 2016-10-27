#ifndef TIEBA_URATE_GET_URATE_INFO_H_
#define TIEBA_URATE_GET_URATE_INFO_H_
#include "tieba/urate/urate_info.h"
#include "tieba/get_parsed_info.h"
#include "tools/content_process.h"
#include "serialize_util.h"
#include <sstream>
namespace gezi {
namespace tieba {
inline void get_urate_info_from_uid(uint64 uid, UrateInfo& urateInfo);
inline UrateInfo get_urate_info_from_uid(uint64 uid);
inline UrateInfo get_urate_info(uint64 pid, bool needHistory = true, int historyNum = 25, bool needUrlInfo = true);
inline string get_serialized_urate_info_str(uint64 pid, bool needHistory = true, int historyNum = 25, bool needUrlInfo = true);
inline UrateInfo get_full_urate_info(uint64 pid, int historyNum = 25, bool needUrl = true);
inline UrateInfo get_urate_info_from_file(string pid, string historyPath = "./history");
}
}
#endif
