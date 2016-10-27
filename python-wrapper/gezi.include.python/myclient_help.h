#ifndef  MYCLIENT_HELP_H_
#define  MYCLIENT_HELP_H_
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <string.h>
#include "myclient_include.h"
#include "config_help.h"
#include "common_help.h"
#include "debug_help.h"
#include "ul_log_help.h"
class DBStream;
class DBHelper
{
protected:
MyclientServerConf* _client_conf;
MyclientPool* _pool;
MysqlConnection* _p_conn;
std::string _sql;
int _db_num;
int _dbsource_num;
public:
DBHelper();
virtual ~DBHelper();
void log_off();
bool init(const std::string& path, const std::string& config_file, const std::string& section = "", int dbsource_num = 1);
bool init(int dbnum, const std::string& path, const std::string& config_file, const std::string& section = "", int dbsource_num = 1);
bool reset(const std::string& path, const std::string& config_file, const std::string& section = "");
std::string sql() const;
int db_num() const;
int execute(MyclientRes& res, bool is_need_reconnect = false);
int execute(const std::string& _sql, MyclientRes& res, bool is_need_reconnect = false);
void perror();
bool read_config(const std::string& path, const std::string& config_file, const std::string & my_section, int dbsource_num = 1);
bool init_db();
};
class DBOper : public DBHelper
{
private:
MyclientRes _res;
public:
~DBOper();
MyclientRes& res();
int execute(bool is_need_reconnect = false);
int execute(const std::string & _sql, bool is_need_reconnect = false);
template<typename _Func>
void process_rows(_Func func);
template<typename _Func>
void process(_Func func);
};
inline size_t get_nrows(const MyclientRes& res);
inline bool to_bool_sql(const char* input);
inline int get_ncols(const std::string& sql);
#endif
