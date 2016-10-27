#ifndef MYCLIENT_STREAM_H_
#define MYCLIENT_STREAM_H_
#include <string>
#include <boost/lexical_cast.hpp>
#include "myclient_help.h"
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
DBStream(DBOper& oper);
void open(MyclientRes& res);
void open(DBOper& oper);
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
typedef DBStream MyClientStream;
#endif
