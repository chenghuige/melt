#ifndef LOG_UTIL_H_
#define LOG_UTIL_H_
#include <string>
#include <glog/logging.h>
#ifndef NO_BAIDU_DEP
#ifdef USE_BAIDU_LOG
#include "com_log.h"
#include "ul_log.h"
#ifdef LOG_FATAL
#undef LOG_FATAL
#endif
#ifdef LOG_ERROR
#undef LOG_ERROR
#endif
#ifdef LOG_WARNING
#undef LOG_WARNING
#endif
#ifdef LOG_DEBUG
#undef LOG_DEBUG
#endif
#ifdef LOG_INFO
#undef LOG_INFO
#endif
#ifdef LOG_NOTICE
#undef LOG_NOTICE
#endif
#define FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG_FATAL(fmt, arg...) do { \
com_writelog(COMLOG_FATAL, "[%d]: " fmt, __LINE__, ## arg); \
} while (0)
#define LOG_ERROR(fmt, arg...) do { \
com_writelog(COMLOG_FATAL, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_WARNING(fmt, arg...) do { \
com_writelog(COMLOG_WARNING, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_INFO(fmt, arg...) do { \
com_writelog(COMLOG_NOTICE, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_NOTICE(fmt, arg...) do { \
com_writelog(COMLOG_NOTICE, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_TRACE(fmt, arg...) do { \
com_writelog(COMLOG_TRACE, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_DEBUG(fmt, arg...) do { \
com_writelog(COMLOG_DEBUG, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_SDF(event, log_id, fmt, arg...) do { \
com_writelog(event, "[%u]" fmt, log_id, ## arg); \
} while (0)
#define LOG_SELF(type, fmt, arg...) do { \
com_writelog(type, "[%s:%d:%s]: " fmt, FILE__, __LINE__, __FUNCTION__, ## arg); \
} while (0)
#define LOG_RECORD(type, fmt, arg...) do { \
com_writelog(type, fmt, ## arg); \
} while (0)
namespace gezi
{
class LogHelper
{
public:
LogHelper(int log_level = 16);
static void set_level(int log_level);
LogHelper(const std::string& conf_file, const std::string& conf_path = "./conf");
~LogHelper();
};
class ThreadLogHelper
{
public:
ThreadLogHelper();
~ThreadLogHelper();
};
}
#endif
#endif
#endif
