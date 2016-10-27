#ifndef TIEBA_FULLPOSTS_RUN_RUN_FULLPOSTS_H_
#define TIEBA_FULLPOSTS_RUN_RUN_FULLPOSTS_H_
#include "common_util.h"
#include "tools/redis/RedisClient.h"
#include "tieba/fullposts/fullposts_features.h"
#include "container/lru_containers.h"
using namespace std;
using namespace gezi;
using namespace gezi::tieba;
DEFINE_int32(vl, 0, "vlog level");
DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf, false, "");
DEFINE_int32(num, 10, "");
DEFINE_uint64(tid, 3301924466, "");
DEFINE_string(i, "", "input file");
DEFINE_double(thre, 0.85, "");
DEFINE_string(ip_dingtie_key, "#!dt_ip!#", "相同ip不同uid");
DEFINE_int32(max_allowed_span, 3600, "只考虑扫描最近一小时的pid");
DEFINE_int32(buffer_size, 10, "for writing to db");
DEFINE_string(o, "fullposts.result.txt", "output file");
DEFINE_bool(write_db, false, "");
DEFINE_bool(multidelete, false, "");
DEFINE_string(db_exe, "write-db.py", "");
DEFINE_string(multidelete_exe, "multi-delete.py", "");
DEFINE_int32(nt, 12, "thread num");
int kMaxTids;
LruHashSet<uint64> _deletedTids(kMaxTids);
CachedFetcher<uint64, UrateInfo, LruHashMap> _fetcher(kMaxTids);
TimerMap<uint64, LruHashMap> _timerMap(60, kMaxTids);
PredictorPtr _predictor;
RedisClient _redisClient;
vector<string> _buffer;
void run(uint64 tid);
void init();
void run();
#endif
