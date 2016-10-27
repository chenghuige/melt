#ifndef REDIS_CLIENT_H_
#define REDIS_CLIENT_H_
#include "RedisClientManager.h"
#include "common_util.h"
namespace gezi {
class RedisClient
{
public:
RedisClient();
RedisClient(string confFile, string confDir = "./conf");
~RedisClient();
int Init(string confFile = "redis_client.conf", string confDir = "./conf");
store::RedisClient* init(string confFile = "redis_client.conf", string confDir = "./conf");
store::RedisClient* GetClient();
int ZrangeFirstNElementWithScores(string key, int num, vector<string>& values, vector<double>& scores, int step = 200, bool allowError = true);
template<typename Func>
int ZrangeFirstNElementWithScores(string key, int num, vector<string>& values, vector<double>& scores, Func func, int step = 200, bool allowError = true);
template<typename Func>
int ZrangeFirstNElementWithScores(string key, int num, Func func, int step = 200, bool allowError = true);
template<typename Func>
int ZrangeFirstNElementWithScoresIf(string key, int num, Func func, int step = 200, bool allowError = true);
int ZrangeWithScores(string key, int first, int last, vector<string>& values, vector<double>& scores);
template<typename Func>
int ZrangeWithScores(string key, int first, int last, vector<string>& values, vector<double>& scores, Func func);
template<typename Func>
int ZrangeWithScores(string key, int first, int last, Func func);
int Zrange(string key, int first, int last, vector<string>& values);
int ZrangeFirstNElement(string key, int num, vector<string>& values, int step = 200, bool allowError = true);
vector<string> ZrangeFirstNElement(string key, int num, int step = 200, bool allowError = true);
template<typename Func>
int ZrangeFirstNElement(string key, int num, Func func, int step = 200, bool allowError = true);
vector<string> Zrange(string key, int first, int last);
int Get(string key, string& value) const;
int count(string key) const;
typedef pair<string, string>* iterator;
iterator find(string key);
//iterator end();
string at(string key) const;
string& operator[] (string key);
string operator[] (string key) const;
protected:
private:
store::RedisClientManager _clientManager;
store::RedisClient* _client;
pair<string, string> _item;
};
}
#endif
