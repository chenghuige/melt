#ifndef MATCH_DICT_H_
#define MATCH_DICT_H_
#include "ul_dictmatch.h"
#include "log_util.h"
namespace gezi {
class MatchDict
{
public:
friend class MatchSearcher;
MatchDict();
~MatchDict();
bool init(string file);
bool Load(string file);
int search(string text, dm_pack_t* result);
int search_count(string text, dm_pack_t* result);
int search_count(string text);
int SearchCount(string text);
bool has_word(string text, int type = 1);
public:
//static dm_pack_t* dm_pack(int maxMatchCount = 1000);
static void free_dm_pack();
private:
dm_dict_t* _dict;
};
class MatchSearcher
{
public:
MatchSearcher(MatchDict* dict, int maxMatchCount = 1000);
MatchSearcher(const MatchDict& dict, int maxMatchCount = 1000);
int search_count(const MatchDict& dict, string text);
int search_count(MatchDict* dict, string text);
dm_pack_t* search(const MatchDict& dict, string text);
dm_pack_t* search(MatchDict* dict, string text);
int search_count(string text);
dm_pack_t* search(string text);
dm_pack_t* result();
bool has_word(string text);
int max_match_count();
private:
MatchDict* _dict;
dm_pack_t* _result;
int _maxMatchCount;
};
}
#endif
