#ifndef __OTL_H__
#define __OTL_H__
#if defined(OTL_INCLUDE_0)
#include "otl_include_0.h"
#endif
#define OTL_VERSION_NUMBER (0x0400F0L)
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#if !defined(OTL_ANSI_CPP_11_RVAL_REF_SUPPORT)
#define OTL_ANSI_CPP_11_RVAL_REF_SUPPORT
#endif
#if !defined(OTL_ANSI_CPP_11_NULLPTR_SUPPORT)
#define OTL_ANSI_CPP_11_NULLPTR_SUPPORT
#endif
#else
#if !defined(OTL_ANSI_CPP_11_NULLPTR_SUPPORT)
#if !defined(__cplusplus_cli)
#define nullptr 0
#endif
#endif
#endif
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
#pragma warning (disable:4351)
#pragma warning (disable:4290)
#define OTL_STRCAT_S(dest,dest_sz,src) strcat_s(dest,dest_sz,src)
#define OTL_STRCPY_S(dest,dest_sz,src) strcpy_s(dest,dest_sz,src)
#define OTL_STRNCPY_S(dest,dest_sz,src,count) strncpy_s(dest,dest_sz,src,count)
#else
#define OTL_STRCAT_S(dest,dest_sz,src) strcat(dest,src)
#define OTL_STRCPY_S(dest,dest_sz,src) strcpy(dest,src)
#define OTL_STRNCPY_S(dest,dest_sz,src,count) strncpy(dest,src,count)
#endif
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#if !defined(OTL_UNCAUGHT_EXCEPTION_ON) && !(defined(_MSC_VER)&&(_MSC_VER==1200))
#define OTL_UNCAUGHT_EXCEPTION_ON
#endif
#if !defined(OTL_TRACE_LEVEL)
#define OTL_TRACE_FORMAT_TZ_DATETIME(s)
#define OTL_TRACE_FORMAT_DATETIME(s)
#else
#if !defined(OTL_TRACE_FORMAT_DATETIME)
#define OTL_TRACE_FORMAT_TZ_DATETIME(s)                         \
s.month<<"/"<<s.day<<"/"<<s.year                                \
<<" "<<s.hour<<":"<<s.minute<<":"<<s.second<<"."<<s.fraction    \
<<" "<<s.tz_hour<<":"<<s.tz_minute
#define OTL_TRACE_FORMAT_DATETIME(s)                            \
s.month<<"/"<<s.day<<"/"<<s.year                                \
<<" "<<s.hour<<":"<<s.minute<<":"<<s.second<<"."<<s.fraction
#endif
#endif
#if defined(OTL_ORA11G)
#define OTL_ORA10G_R2
#endif
#if defined(OTL_ORA11G_R2)
#define OTL_ORA10G_R2
#endif
#if defined(OTL_STREAM_LEGACY_BUFFER_SIZE_TYPE)
typedef short int otl_stream_buffer_size_type;
#else
typedef int otl_stream_buffer_size_type;
#endif
#if defined(OTL_ODBC_MULTI_MODE)
#define OTL_ODBC
#define OTL_ODBC_SQL_EXTENDED_FETCH_ON
#endif
#if defined(OTL_ODBC_MSSQL_2005)
#define OTL_ODBC
#endif
#if defined(OTL_ODBC_MSSQL_2008)
#define OTL_ODBC
#define OTL_ODBC_MSSQL_2005
#endif
#if defined(OTL_IODBC_BSD)
#define OTL_ODBC
#define OTL_ODBC_UNIX
#endif
#if defined(OTL_ODBC_TIMESTEN_WIN)
#define OTL_ODBC_TIMESTEN
#define OTL_ODBC
#define OTL_ODBC_SQL_EXTENDED_FETCH_ON
#define ODBCVER 0x0250
#include <timesten.h>
#endif
#if defined(OTL_ODBC_TIMESTEN_UNIX)
#define OTL_ODBC_TIMESTEN
#define OTL_ODBC
#define OTL_ODBC_UNIX
#define OTL_ODBC_SQL_EXTENDED_FETCH_ON
#include <timesten.h>
#endif
#if defined(OTL_ODBC_ENTERPRISEDB)
#define OTL_ODBC_POSTGRESQL
#endif
#if defined(OTL_ODBC_POSTGRESQL)
#define OTL_ODBC
#endif
#if !defined(OTL_ODBC_zOS) && !defined (OTL_ANSI_CPP)
#define OTL_ANSI_CPP
#endif
#if defined(OTL_ODBC_zOS)
#define OTL_ODBC_UNIX
#define OTL_ODBC_SQL_EXTENDED_FETCH_ON
#endif
#if defined(OTL_ORA8I)
#define OTL_ORA8
#define OTL_ORA8_8I_REFCUR
#define OTL_ORA8_8I_DESC_COLUMN_SCALE
#endif
#if defined(OTL_ORA10G)||defined(OTL_ORA10G_R2)
#define  OTL_ORA9I
#define OTL_ORA_NATIVE_TYPES
#endif
#if defined(OTL_ORA9I)
#define OTL_ORA8
#define OTL_ORA8_8I_REFCUR
#define OTL_ORA8_8I_DESC_COLUMN_SCALE
#endif
#if defined(OTL_ODBC_MYSQL)
#define OTL_ODBC
#endif
#if defined(OTL_ODBC_XTG_IBASE6)
#define OTL_ODBC
#endif
#define OTL_VALUE_TEMPLATE
#if defined(OTL_ODBC_UNIX) && !defined(OTL_ODBC)
#define OTL_ODBC
#endif
#if defined(OTL_BIND_VAR_STRICT_TYPE_CHECKING_ON)
#define OTL_CHECK_BIND_VARS                     \
if(strcmp(type_arr,"INT")==0||                \
strcmp(type_arr,"UNSIGNED")==0||           \
strcmp(type_arr,"SHORT")==0||              \
strcmp(type_arr,"LONG")==0||               \
strcmp(type_arr,"FLOAT")==0||              \
strcmp(type_arr,"DOUBLE")==0||             \
strcmp(type_arr,"TIMESTAMP")==0||          \
strcmp(type_arr,"TZ_TIMESTAMP")==0||       \
strcmp(type_arr,"LTZ_TIMESTAMP")==0||      \
strcmp(type_arr,"BIGINT")==0||             \
strcmp(type_arr,"CHAR")==0||               \
strcmp(type_arr,"CHARZ")==0||              \
strcmp(type_arr,"DB2DATE")==0||            \
strcmp(type_arr,"DB2TIME")==0||            \
strcmp(type_arr,"VARCHAR_LONG")==0||       \
strcmp(type_arr,"RAW_LONG")==0||           \
strcmp(type_arr,"RAW")==0||                \
strcmp(type_arr,"CLOB")==0||               \
strcmp(type_arr,"BLOB")==0||               \
strcmp(type_arr,"NCHAR")==0||              \
strcmp(type_arr,"NCLOB")==0||              \
strcmp(type_arr,"REFCUR")==0)              \
;                                           \
else                                          \
return 0;
#else
#define OTL_CHECK_BIND_VARS
#endif
#if defined(OTL_EXPLICIT_NAMESPACES)
#if defined(OTL_DB2_CLI)
#define OTL_ODBC_NAMESPACE_BEGIN namespace db2 {
#define OTL_ODBC_NAMESPACE_PREFIX db2::
#define OTL_ODBC_NAMESPACE_END }
#else
#define OTL_ODBC_NAMESPACE_BEGIN namespace odbc {
#define OTL_ODBC_NAMESPACE_PREFIX odbc::
#define OTL_ODBC_NAMESPACE_END }
#endif
#define OTL_ORA7_NAMESPACE_BEGIN namespace oracle {
#define OTL_ORA7_NAMESPACE_PREFIX oracle::
#define OTL_ORA7_NAMESPACE_END }
#define OTL_ORA8_NAMESPACE_BEGIN namespace oracle {
#define OTL_ORA8_NAMESPACE_PREFIX oracle::
#define OTL_ORA8_NAMESPACE_END }
#else
#if defined(OTL_ODBC)&&!defined(OTL_ORA8)&& \
!defined(OTL_ORA7)&&!defined(OTL_DB2_CLI) \
|| !defined(OTL_ODBC)&&defined(OTL_ORA8)&& \
!defined(OTL_ORA7)&&!defined(OTL_DB2_CLI) \
|| !defined(OTL_ODBC)&&!defined(OTL_ORA8)&& \
defined(OTL_ORA7)&&!defined(OTL_DB2_CLI) \
|| !defined(OTL_ODBC)&&!defined(OTL_ORA8)&& \
!defined(OTL_ORA7)&&defined(OTL_DB2_CLI)
#define OTL_ODBC_NAMESPACE_BEGIN
#define OTL_ODBC_NAMESPACE_PREFIX
#define OTL_ODBC_NAMESPACE_END
#define OTL_ORA7_NAMESPACE_BEGIN
#define OTL_ORA7_NAMESPACE_PREFIX
#define OTL_ORA7_NAMESPACE_END
#define OTL_ORA8_NAMESPACE_BEGIN
#define OTL_ORA8_NAMESPACE_PREFIX
#define OTL_ORA8_NAMESPACE_END
#endif
#if defined(OTL_ODBC) && defined(OTL_ORA7) && \
!defined(OTL_ORA8) && !defined(OTL_DB2_CLI)
#define OTL_ODBC_NAMESPACE_BEGIN namespace odbc{
#define OTL_ODBC_NAMESPACE_PREFIX odbc::
#define OTL_ODBC_NAMESPACE_END }
#define OTL_ORA7_NAMESPACE_BEGIN namespace oracle {
#define OTL_ORA7_NAMESPACE_PREFIX oracle::
#define OTL_ORA7_NAMESPACE_END }
#define OTL_ORA8_NAMESPACE_BEGIN
#define OTL_ORA8_NAMESPACE_PREFIX
#define OTL_ORA8_NAMESPACE_END
#endif
#if defined(OTL_ODBC) && !defined(OTL_ORA7) && \
defined(OTL_ORA8) && !defined(OTL_DB2_CLI)
#define OTL_ODBC_NAMESPACE_BEGIN namespace odbc{
#define OTL_ODBC_NAMESPACE_PREFIX odbc::
#define OTL_ODBC_NAMESPACE_END }
#define OTL_ORA8_NAMESPACE_BEGIN namespace oracle {
#define OTL_ORA8_NAMESPACE_PREFIX oracle::
#define OTL_ORA8_NAMESPACE_END }
#define OTL_ORA7_NAMESPACE_BEGIN
#define OTL_ORA7_NAMESPACE_PREFIX
#define OTL_ORA7_NAMESPACE_END
#endif
#if !defined(OTL_ODBC) && defined(OTL_ORA7) && \
!defined(OTL_ORA8) && defined(OTL_DB2_CLI)
#define OTL_ORA7_NAMESPACE_BEGIN namespace oracle {
#define OTL_ORA7_NAMESPACE_PREFIX oracle::
#define OTL_ORA7_NAMESPACE_END }
#define OTL_ORA8_NAMESPACE_BEGIN
#define OTL_ORA8_NAMESPACE_PREFIX
#define OTL_ORA8_NAMESPACE_END
#define OTL_ODBC_NAMESPACE_BEGIN namespace db2 {
#define OTL_ODBC_NAMESPACE_PREFIX db2::
#define OTL_ODBC_NAMESPACE_END }
#endif
#if !defined(OTL_ODBC) && !defined(OTL_ORA7) && \
defined(OTL_ORA8) && defined(OTL_DB2_CLI)
#define OTL_ORA8_NAMESPACE_BEGIN namespace oracle {
#define OTL_ORA8_NAMESPACE_PREFIX oracle::
#define OTL_ORA8_NAMESPACE_END }
#define OTL_ORA7_NAMESPACE_BEGIN
#define OTL_ORA7_NAMESPACE_PREFIX
#define OTL_ORA7_NAMESPACE_END
#define OTL_ODBC_NAMESPACE_BEGIN namespace db2 {
#define OTL_ODBC_NAMESPACE_PREFIX db2::
#define OTL_ODBC_NAMESPACE_END }
#endif
#endif
#if (defined(OTL_ORA7_TIMESTAMP_STR)||defined(OTL_ORA7_STRING_TO_TIMESTAMP)) \
&& defined(OTL_ORA_TIMESTAMP)
#error Invalid combination: OTL_ORA_TIMESTAMP and \
OTL_ORA7_TIMESTAMP_STR/OTL_ORA7_STRING_TO_TIMESTAMP
#endif
#if defined(OTL_ORA_MAP_BIGINT_TO_LONG) && \
defined(OTL_BIGINT_TO_STR) && \
defined(OTL_STR_TO_BIGINT)
#error OTL_ORA_MAP_BIGINT_TO_LONG cannot be used when \
OTL_BIGINT_TO_STR and OTL_STR_TO_BIGINT are defined
#endif
#if defined(OTL_STL) && defined(OTL_UNICODE_STRING_TYPE)
#error Invalid combination: OTL_STL and OTL_UNICODE_STRING_TYPE
#endif
#if defined(OTL_ORA_UTF8) && !defined(OTL_ORA10G) && \
!defined(OTL_ORA_10G_R2) && !defined(OTL_ORA9I)
#error Invalid combination: OTL_ORA_UTF8 can only be used with OTL_ORA9I or higher
#endif
#if defined(OTL_ORA_UTF8) && defined(OTL_UNICODE)
#error Invalid combination: OTL_ORA_UTF8 and OTL_UNICODE are mutually exclusive
#endif
#if defined(OTL_ODBC) && defined(OTL_DB2_CLI)
#error Invalid combination: OTL_ODBC && OTL_DB2_CLI together
#endif
#if defined(OTL_ORA7) && defined(OTL_ORA8)
#error Invalid combination: OTL_ORA7 && OTL_ORA8(I) together
#endif
#if defined (OTL_ORA7) && defined(OTL_ORA8)
#error Invalid combination: OTL_ORA7 && OTL_ORA8(I) together
#endif
#if defined(OTL_ORA_OCI_ENV_CREATE) && \
(!defined(OTL_ORA8I) && !defined(OTL_ORA9I) && \
!defined(OTL_ORA10G) && !defined(OTL_ORA10G_R2))
#error OTL_ORA_OCI_ENV_CREATE can be only defined when OTL_ORA8I, OTL_ORA9I, OTL_ORA10G, OTL_ORA10G_R2, or OTL_ORA11G is defined
#endif
#if defined(OTL_TRACE_LEVEL)
#if !defined(OTL_TRACE_LINE_PREFIX)
#define OTL_TRACE_LINE_PREFIX "OTL TRACE ==> "
#endif
#if defined(OTL_UNICODE_CHAR_TYPE) && !defined(OTL_UNICODE)
#error OTL_UNICODE needs to be defined if OTL_UNICODE_CHAR_TYPE is defined
#endif
#if defined(OTL_UNICODE_STRING_TYPE) && !defined(OTL_UNICODE_CHAR_TYPE)
#error OTL_UNICODE_CHAR_TYPE needs to be defined if OTL_UNICODE_STRING_TYPE is defined
#endif
#if defined(OTL_UNICODE_STRING_TYPE) && !defined(OTL_UNICODE_CHAR_TYPE)
#error OTL_UNICODE_CHAR_TYPE needs to be defined if OTL_UNICODE_STRING_TYPE is defined
#endif
#if defined(OTL_UNICODE_STRING_TYPE) && !defined(OTL_UNICODE)
#error OTL_UNICODE needs to be defined if OTL_UNICODE_STRING_TYPE is defined
#endif
#if defined(OTL_UNICODE_EXCEPTION_AND_RLOGON) && !defined(OTL_UNICODE_CHAR_TYPE)
#error OTL_UNICODE_CHAR_TYPE needs to be defined if OTL_UNICODE_EXCEPTION_AND_RLOGON is defined
#endif
#if !defined(OTL_TRACE_LINE_SUFFIX)
#if defined(OTL_UNICODE)
#define OTL_TRACE_LINE_SUFFIX L"\n"
#else
#define OTL_TRACE_LINE_SUFFIX "\n"
#endif
#endif
#if !defined(OTL_TRACE_STREAM_OPEN)
#define OTL_TRACE_STREAM_OPEN                   \
if(OTL_TRACE_LEVEL & 0x4){                    \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;    \
OTL_TRACE_STREAM<<"otl_stream(this=";       \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);    \
OTL_TRACE_STREAM<<")::open(buffer_size=";   \
OTL_TRACE_STREAM<<arr_size;                 \
OTL_TRACE_STREAM<<", sqlstm=";              \
OTL_TRACE_STREAM<<sqlstm;                   \
OTL_TRACE_STREAM<<", connect=";             \
OTL_TRACE_STREAM<<OTL_RCAST(void*,&db);     \
OTL_TRACE_STREAM<<", implicit_select=";     \
OTL_TRACE_STREAM<<implicit_select;          \
if(sqlstm_label){                           \
OTL_TRACE_STREAM<<", label=";             \
OTL_TRACE_STREAM<<sqlstm_label;           \
}                                           \
OTL_TRACE_STREAM<<");";                     \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;    \
}
#endif
#if !defined(OTL_TRACE_STREAM_OPEN2)
#define OTL_TRACE_STREAM_OPEN2                          \
if(OTL_TRACE_LEVEL & 0x4){                            \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;            \
OTL_TRACE_STREAM<<"otl_stream(this=";               \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);            \
OTL_TRACE_STREAM<<")::open(buffer_size=";           \
OTL_TRACE_STREAM<<arr_size;                         \
OTL_TRACE_STREAM<<", sqlstm=";                      \
OTL_TRACE_STREAM<<sqlstm;                           \
OTL_TRACE_STREAM<<", connect=";                     \
OTL_TRACE_STREAM<<OTL_RCAST(void*,&db);             \
if(ref_cur_placeholder){                            \
OTL_TRACE_STREAM<<", ref_cur_placeholder=";       \
OTL_TRACE_STREAM<<ref_cur_placeholder;            \
}                                                   \
if(sqlstm_label){                                   \
OTL_TRACE_STREAM<<", label=";                     \
OTL_TRACE_STREAM<<sqlstm_label;                   \
}                                                   \
OTL_TRACE_STREAM<<");";                             \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;            \
}
#endif
#if !defined(OTL_TRACE_DIRECT_EXEC)
#define OTL_TRACE_DIRECT_EXEC                             \
if(OTL_TRACE_LEVEL & 0x2){                              \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;              \
OTL_TRACE_STREAM<<"otl_cursor::direct_exec(connect="; \
OTL_TRACE_STREAM<<OTL_RCAST(void*,&connect);          \
OTL_TRACE_STREAM<<",sqlstm=\"";                       \
OTL_TRACE_STREAM<<sqlstm;                             \
OTL_TRACE_STREAM<<"\",exception_enabled=";            \
OTL_TRACE_STREAM<<exception_enabled;                  \
OTL_TRACE_STREAM<<");";                               \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;              \
}
#endif
#if !defined(OTL_TRACE_SYNTAX_CHECK)
#define OTL_TRACE_SYNTAX_CHECK                             \
if(OTL_TRACE_LEVEL & 0x2){                               \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;               \
OTL_TRACE_STREAM<<"otl_cursor::syntax_check(connect="; \
OTL_TRACE_STREAM<<OTL_RCAST(void*,&connect);           \
OTL_TRACE_STREAM<<",sqlstm=\"";                        \
OTL_TRACE_STREAM<<sqlstm;                              \
OTL_TRACE_STREAM<<"\"";                                \
OTL_TRACE_STREAM<<");";                                \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;               \
}
#endif
#if !defined(OTL_TRACE_FUNC)
#define OTL_TRACE_FUNC(level,class_name,func_name,args) \
if(OTL_TRACE_LEVEL & level){                          \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;            \
OTL_TRACE_STREAM<<class_name;                       \
OTL_TRACE_STREAM<<"(this=";                         \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);            \
OTL_TRACE_STREAM<<")::" func_name "(";              \
OTL_TRACE_STREAM<<args;                             \
OTL_TRACE_STREAM<<");";                             \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;            \
}
#endif
#if !defined(OTL_TRACE_EXCEPTION)
#define OTL_TRACE_EXCEPTION(code,msg,stm_text,var_info) \
if(OTL_TRACE_LEVEL & 0x20){                           \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;            \
OTL_TRACE_STREAM<<"otl_exception, code=";           \
OTL_TRACE_STREAM<<code;                             \
OTL_TRACE_STREAM<<", msg=";                         \
char* c=OTL_RCAST(char*,msg);                       \
while(*c && *c!='\n'){                              \
OTL_TRACE_STREAM<<*c;                             \
++c;                                              \
}                                                   \
OTL_TRACE_STREAM<<", stm_text=";                    \
OTL_TRACE_STREAM<<stm_text;                         \
OTL_TRACE_STREAM<<", var_info=";                    \
OTL_TRACE_STREAM<<var_info;                         \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;            \
}
#endif
#if !defined(OTL_TRACE_RLOGON_ORA7) && defined(OTL_ORA7)
#define OTL_TRACE_RLOGON_ORA7(level,class_name,func_name,       \
connect_str,auto_commit)          \
if(OTL_TRACE_LEVEL & level){                                  \
char temp_connect_str[2048];                                \
const char* c1=OTL_RCAST(const char*,connect_str);          \
char* c2=temp_connect_str;                                  \
while(*c1 && *c1!='/'){                                     \
*c2=*c1;                                                  \
++c1; ++c2;                                               \
}                                                           \
if(*c1=='/'){                                               \
*c2=*c1;                                                  \
++c1; ++c2;                                               \
while(*c1 && *c1!='@'){                                   \
*c2='*';                                                \
++c1; ++c2;                                             \
}                                                         \
if(*c1=='@'){                                             \
while(*c1){                                             \
*c2=*c1;                                              \
++c1; ++c2;                                           \
}                                                       \
}                                                         \
}                                                           \
*c2=0;                                                      \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;                    \
OTL_TRACE_STREAM<<class_name;                               \
OTL_TRACE_STREAM<<"(this=";                                 \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);                    \
OTL_TRACE_STREAM<<")::" func_name "(";                      \
OTL_TRACE_STREAM<<"connect_str=\"";                         \
OTL_TRACE_STREAM<<temp_connect_str;                         \
OTL_TRACE_STREAM<<"\", auto_commit=";                       \
OTL_TRACE_STREAM<<auto_commit;                              \
OTL_TRACE_STREAM<<");";                                     \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;                    \
}
#endif
#if !defined(OTL_TRACE_RLOGON_ORA8) && defined(OTL_ORA8)
#define OTL_TRACE_RLOGON_ORA8(level,class_name,func_name,               \
tnsname,userid,passwd,                    \
auto_commit)                              \
if(OTL_TRACE_LEVEL & level){                                          \
char temp_connect_str[2048];                                        \
OTL_STRCPY_S(temp_connect_str,sizeof(temp_connect_str),userid);     \
OTL_STRCAT_S(temp_connect_str,sizeof(temp_connect_str),"/");        \
size_t sz=strlen(passwd);                                           \
for(size_t i=0;i<sz;++i)                                            \
OTL_STRCAT_S(temp_connect_str,sizeof(temp_connect_str),"*");      \
size_t tns_sz=strlen(tnsname);                                      \
if(tns_sz>0){                                                       \
OTL_STRCAT_S(temp_connect_str,sizeof(temp_connect_str),"@");      \
OTL_STRCAT_S(temp_connect_str,sizeof(temp_connect_str),tnsname);  \
}                                                                   \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;                            \
OTL_TRACE_STREAM<<class_name<<"(this=";                             \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);                            \
OTL_TRACE_STREAM<<")::" func_name "(";                              \
OTL_TRACE_STREAM<<"connect_str=\"";                                 \
OTL_TRACE_STREAM<<temp_connect_str;                                 \
OTL_TRACE_STREAM<<"\", auto_commit=";                               \
OTL_TRACE_STREAM<<auto_commit <<");";                               \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;                            \
}
#endif
#if !defined(OTL_TRACE_RLOGON_ODBC)&&(defined(OTL_ODBC)||defined(OTL_DB2_CLI))
#define OTL_TRACE_RLOGON_ODBC(level,class_name,func_name,                       \
tnsname,userid,passwd,                            \
auto_commit)                                      \
if(OTL_TRACE_LEVEL & level){                                                  \
char temp_connect_str2[2048];                                               \
OTL_STRCPY_S(temp_connect_str2,sizeof(temp_connect_str2),userid);           \
OTL_STRCAT_S(temp_connect_str2,sizeof(temp_connect_str2),"/");              \
size_t sz=strlen(passwd);                                                   \
for(size_t i=0;i<sz;++i)                                                    \
OTL_STRCAT_S(temp_connect_str2,sizeof(temp_connect_str2),"*");            \
size_t tns_sz=strlen(tnsname);                                              \
if(tns_sz>0){                                                               \
OTL_STRCAT_S(temp_connect_str2,sizeof(temp_connect_str2),"@");            \
OTL_STRCAT_S(temp_connect_str2,sizeof(temp_connect_str2),tnsname);        \
}                                                                           \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;                                    \
OTL_TRACE_STREAM<<class_name;                                               \
OTL_TRACE_STREAM<<"(this=";                                                 \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);                                    \
OTL_TRACE_STREAM<<")::" func_name "(";                                      \
OTL_TRACE_STREAM<<"connect_str=\"";                                         \
OTL_TRACE_STREAM<<temp_connect_str2;                                        \
OTL_TRACE_STREAM<<"\", auto_commit=";                                       \
OTL_TRACE_STREAM<<auto_commit;                                              \
OTL_TRACE_STREAM<<");";                                                     \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_SUFFIX;                                    \
}
#endif
#if !defined(OTL_TRACE_RLOGON_ODBC_W)&& \
(defined(OTL_ODBC)||defined(OTL_DB2_CLI))
#define OTL_TRACE_RLOGON_ODBC_W(level,class_name,func_name,     \
tnsname,userid,passwd,            \
auto_commit)                      \
if(OTL_TRACE_LEVEL & level){                                  \
OTL_TRACE_STREAM<<OTL_TRACE_LINE_PREFIX;                    \
OTL_TRACE_STREAM<<class_name;                               \
OTL_TRACE_STREAM<<L"(this=";                                \
OTL_TRACE_STREAM<<OTL_RCAST(void*,this);                    \
OTL_TRACE_STREAM<<L")::" func_name L"(";                    \
OTL_TRACE_STREAM<<L"connect_str=\"";                        \
OTL_TRACE_STREAM<<userid<<L"
