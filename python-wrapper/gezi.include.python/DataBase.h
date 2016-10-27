#ifndef DATABASE_H_
#define DATABASE_H_
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <string.h>
#include "myclient_include.h"
#include "common_util.h"
namespace gezi
{
class DBStream;
class DataBase
{
protected:
MyclientServerConf* _client_conf;
MyclientPool* _pool;
std::string _sql;
int _db_num;
int _dbsource_num;
public:
DataBase();
virtual ~DataBase();
void logOff();
void init(const std::string& config_file, const std::string& section = "",
const std::string& path = "./conf", int dbsource_num = 1);
void init(int dbnum, const std::string& config_file, const std::string& section = "",
const std::string& path = "./conf", int dbsource_num = 1);
void reset(const std::string& config_file, const std::string& section = "", const std::string& path = "./conf");
std::string sql() const;
int db_num() const;
inline int execute(MyclientRes& res, bool store = true);
inline int execute(MyclientRes* res, bool store = true);
int execute(const std::string& sql, MyclientRes& res, bool store = true);
int execute(const std::string& sql, MyclientRes* res, bool store = true);
void perror(MysqlConnection* p_conn);
void readConfig(const std::string& path, const std::string& config_file,
const std::string & section, int dbsource_num = 1);
void initDB();
};
class DBHelper : public DataBase
{
private:
MyclientRes _res;
public:
~DBHelper();
MyclientRes& res();
inline int execute();
inline int execute(const std::string & sql);
template<typename _Func>
void processRows(_Func func);
template<typename _Func>
void process(_Func func);
};
class SharedDataBase
{
public:
//static DataBase* instance();
//static DataBase& dataBase();
};
inline size_t get_nrows(const MyclientRes& res);
inline bool to_bool_sql(const char* input);
inline int get_ncols(const std::string& sql);
class DBStream
{
private:
int _col_index;
int _nrows;
int _ncols;
MYSQL_RES* _p_res;
MYSQL_ROW _p_row;
public:
DBStream();
DBStream(MyclientRes& res);
DBStream(DBHelper& oper);
void open(MyclientRes& res);
void open(DBHelper& oper);
bool is_open();
void seek(size_t pos);
bool eof();
template<typename T>
DBStream & operator >>(T& val);
DBStream & operator >>(bool& val);
DBStream & operator >>(char*& val);
DBStream & operator >>(void*& val);
DBStream & operator >>(std::string& val);
private:
void advance();
};
}
#endif
