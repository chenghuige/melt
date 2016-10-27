#ifndef CONF_UTIL_H_
#define CONF_UTIL_H_
#include <string>
#ifndef __GNUC__
#define NO_BAIDU_DEP
#endif
#ifndef NO_BAIDU_DEP
#ifndef NO_BAIDU_CONF
#include "Configure.h"
#endif
#endif
#include "log_util.h"
#include "debug_util.h"
#include "string_util.h"
#include "Exception.h"
#include "string_util.h"
#ifndef NO_BAIDU_DEP
#include "convert_type.h"
#endif
namespace gezi
{
inline int parse_int_param(string name, string line);
inline string parse_string_param(string name, string line);
inline double parse_double_param(string name, string line);
inline bool parse_bool_param(string name, string line);
#ifndef NO_BAIDU_DEP
#ifndef NO_BAIDU_CONF
using comcfg::Configure;
class SharedConf
{
public:
//static comcfg::Configure& get_conf();
//static comcfg::Configure& conf();
//static comcfg::Configure* instance();
static bool init(string config_file = "strategy.conf", string dir = "./conf");
};
inline void set_val(const comcfg::Configure& conf, string key, string& val);
inline void set_val(const comcfg::Configure& conf, string field, string key, string& val);
inline string get_val(const comcfg::Configure& conf, string key, string default_val);
inline string get_val(const comcfg::Configure& conf, string field, string key, string default_val);
inline void set_val(const comcfg::Configure& conf, string key, int& val);
inline void set_val(const comcfg::Configure& conf, string field, string key, int& val);
inline int get_val(const comcfg::Configure& conf, string key, int default_val);
inline int get_val(const comcfg::Configure& conf, string field, string key, int default_val);
inline void set_val(const comcfg::Configure& conf, string key, bool& val);
inline void set_val(const comcfg::Configure& conf, string field, string key, bool& val);
inline void set_val(const comcfg::Configure& conf, string key, long long& val);
inline void set_val(const comcfg::Configure& conf, string field, string& key, long long& val);
inline long long get_val(const comcfg::Configure& conf, string key, long long default_val);
inline long long get_val(const comcfg::Configure& conf, string field, string& key, long long default_val);
inline void set_val(const comcfg::Configure& conf, string key, double& val);
inline void set_val(const comcfg::Configure& conf, string field, string key, double& val);
inline double get_val(const comcfg::Configure& conf, string key, double default_val);
inline double get_val(const comcfg::Configure& conf, string field, string key, double default_val);
inline void get_val(const comcfg::Configure& conf, char* dest,
string key, string default_val);
inline void get_val(const comcfg::Configure& conf, char* dest,
string field, string key, string default_val);
#endif
#endif
}
#ifndef NO_BAIDU_DEP
#ifndef NO_BAIDU_CONF
#define SCONF(s)\
gezi::set_val(gezi::SharedConf::conf(), section, gezi::conf_trim(#s), s)
#define SCONF_CLASS(root,s)\
gezi::set_val(gezi::SharedConf::conf(), section, gezi::conf_trim(#s), root.s)
#define SCONF2(s,default_value)\
s = gezi::get_val(gezi::SharedConf::conf(), section, gezi::conf_trim(#s), default_value)
#define SCONF_(s,default_value)\
gezi::get_val(gezi::SharedConf::conf(), section, gezi::conf_trim(#s), default_value)
#define SCONF2_CLASS(root,s,default_value)\
root.s = gezi::get_val(gezi::SharedConf::conf(), section, gezi::conf_trim(#s), default_value)
#define PSCONF(s, field)\
gezi::set_val(gezi::SharedConf::conf(), field, gezi::conf_trim(#s), s)
#define PSCONF_WITHNAME(s, name, field)\
gezi::set_val(gezi::SharedConf::conf(), field, name, s)
#define PSCONF2(s,field, default_value)\
s = gezi::get_val(gezi::SharedConf::conf(), field, gezi::conf_trim(#s), default_value)
#define PSCONF_(s,field, default_value)\
gezi::get_val(gezi::SharedConf::conf(), field, gezi::conf_trim(#s), default_value)
#define CONF(s)\
gezi::set_val(conf, section, gezi::conf_trim(#s), s)
#define CONF_CLASS(root,s)\
gezi::set_val(conf, section, gezi::conf_trim(#s), root.s)
#define CONF2(s,default_value)\
s = gezi::get_val(conf, section, gezi::conf_trim(#s), default_value)
#define CONF2_CLASS(root,s,default_value)\
root.s = gezi::get_val(conf, section, gezi::conf_trim(#s), default_value)
#define PCONF(s, field)\
gezi::set_val(conf, field, gezi::conf_trim(#s), s)
#define PCONF_CLASS(root,s, field)\
gezi::set_val(conf, field, gezi::conf_trim(#s), root.s)
#define PCONF2(s,field, default_value)\
s = gezi::get_val(conf, field, gezi::conf_trim(#s), default_value)
#define PCONF2_CLASS(root, s,field, default_value)\
root.s = gezi::get_val(conf, field, gezi::conf_trim(#s), default_value)
#define NPSCONF(s, name, field)\
gezi::set_val(gezi::SharedConf::conf(), field, name + "_" + gezi::conf_trim(#s), s)
#define CONF_TRY_VAL(s)\
gezi::set_val(conf, gezi::conf_trim(#s), s)
#define CONF_TRY_PROP(s,field)\
gezi::set_val(conf, field, gezi::conf_trim(#s), s)
#define CONF_TRY_MEMBER_VAL(root, s)\
gezi::set_val(conf, gezi::conf_trim(#s), root.s)
#define CONF_TRY_MEMBER_PROP(root, s,field)\
gezi::set_val(conf, field, gezi::conf_trim(#s), root.s)
#define CONF_GET_VAL(s,default_value)\
s = gezi::get_val(conf, gezi::conf_trim(#s), default_value)
#define CONF_GET_PROP(s,field,default_value)\
s = gezi::get_val(conf, field, gezi::conf_trim(#s), default_value)
#define CONF_GET_MEMBER_VAL(root, s,default_value)\
root.s = gezi::get_val(conf, gezi::conf_trim(#s), default_value)
#define CONF_GET_MEMBER_PROP(root, s,field,default_value)\
root.s = gezi::get_val(conf, field, gezi::conf_trim(#s), default_value)
#define CONF_STRCPY_VAL(root, s,default_value)\
string VAL_STRCPY_##s##result = gezi::get_val(conf, gezi::conf_trim(#s), default_value); \
strncpy(root, VAL_STRCPY_##s##result.c_str(), VAL_STRCPY_##s##result.length()); \
root[VAL_STRCPY_##s##result.length()] = '\0'
#define CONF_STRCPY_PROP(root, s,field,default_value)\
string PROP_STRCPY_##s##result; \
PROP_STRCPY_##s##result = gezi::get_val(conf, field, gezi::conf_trim(#s), default_value); \
strncpy(root, PROP_STRCPY_##s##result.c_str(), PROP_STRCPY_##s##result.length()); \
root[PROP_STRCPY_##s##result.length()] = '\0'
#endif
#endif
#endif
