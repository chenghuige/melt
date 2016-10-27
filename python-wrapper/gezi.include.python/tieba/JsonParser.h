#ifndef TIEBA__JSON_PARSER_H_
#define TIEBA__JSON_PARSER_H_
#include "json/json.h"
#include "common_util.h"
#include "tieba/common_def.h"
namespace gezi {
namespace tieba {
class JsonParser
{
public:
struct Cmp
{
Json::Value& posts;
string time;
Cmp(Json::Value& posts_, string time_);
inline bool operator()(int i, int j);
};
static vector<int> sort(Json::Value& posts, string time);
static void getPostInfos(Json::Value& res, HistoryType& m);
static void getLikeInfos(Json::Value& res, HistoryType & m);
static void getUserInfos(Json::Value& res, HistoryType & m);
static void getPuserInfos(Json::Value& res, HistoryType & m);
static void getUrlScores(Json::Value& json, HistoryType & m);
static void getHistory(Json::Value& json, HistoryType & m);
static string filter(string input);
");
}
while (input.length() != pre_input.length());
do
{
pre_input;
boost::replace_all(input, "\"
}
", "\"
}
");
}
while (input.length() != pre_input.length());
do
{
pre_input;
boost::replace_all(input, "\"]", "\"]");
}
while (input.length() != pre_input.length());
do
{
pre_input;
boost::replace_all(input, "\"]", "\"]");
}
while (input.length() != pre_input.length());
boost::erase_all(input, "\"");
boost::erase_all(input, "\"");
boost::erase_all(input, "");
boost::erase_all(input, "");
return input;
