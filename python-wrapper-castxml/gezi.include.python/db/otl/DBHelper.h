#ifndef DBHELPER_H_
#define DBHELPER_H_
#define OTL_ODBC
#define OTL_STL
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_ODBC_MYSQL
#define OTL_ODBC_UNIX
#include <string>
#include <vector>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include "db/otlv4.h"
#include "common_def.h"
#include "conf_util.h"
#include "debug_util.h"
#include <gflags/gflags.h>
DEFINE_string(where, "", "where in sql");
using std::string;
using std::vector;
using boost::format;
namespace gezi
{
class DBHelper
{
private:
string DBType;
string Driver, Option, Font;
string IP, Port, DB, User, Pwd;
string From;
string Out;
string Select, Where, DataType, DataTypes;
string Sql;
otl_connect _conn;
const static int kBuffSize = 1024;
enum SqlDataType
{
IntType, StringType
};
public:
DBHelper();
DBHelper(string config_file, string section = "", string dir = "./conf");
~DBHelper();
void logOff();
void init(string config_file, string section = "", string dir = "./conf");
void reset(string config_file, string section = "", string dir = "./conf");
void process();
template<typename Func>
void process(const Func& func);
template<typename Func>
void process_(const Func& func);
template<typename Func>
void process_write(const Func& func);
string getOutFileName();
string getFrom();
string getTable();
string getWhere();
string getSql();
private:
void readConfig(string config_file, string section, string dir);
public:
string getDBFile_mysql();
string getDBFile_sqlserver();
string getDBFile();
void initDB();
void initSql();
void initSql2();
void setSql(string sql);
void setSelect(string select);
void setFrom(string from);
void setTable(string from);
void setWhere(string where);
template<typename T>
void processWrite();
void processWrite_int_str();
void processWrite_int_int_str();
void processWrite_mix();
template<typename OutStream, typename T>
void readWrite(otl_stream& os, int len, T& data, OutStream& out);
template<typename OutStream>
void readWrite_int_str(otl_stream& os, int len, OutStream& out);
template<typename OutStream>
void readWrite_int_int_str(otl_stream& os, int len, OutStream& out);
template<typename OutStream>
void readWrite_mix(otl_stream& os, vector<int>& type, OutStream& out);
bool execute();
bool execute(string sql);
bool drop(string table);
bool create(string table);
bool insert(string table);
};
}
#endif
