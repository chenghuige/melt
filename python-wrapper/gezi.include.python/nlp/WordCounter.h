#ifndef GEZI_NLP__WORD_COUNTER_H_
#define GEZI_NLP__WORD_COUNTER_H_
#include "common_util.h"
#include "sort_map_by_value.h"
#include "Identifer.h"
namespace gezi {
class WordCounter
{
public:
typedef std::pair<string, size_t> WordFreq;
WordCounter(size_t mostCommon = 0, size_t minCount = 0,
bool addUnknown = true, string unknownMark = "<UNK>",
bool saveCountInfo = true, string totalCountMark = "<TotalCount>");
void save(string file) const;
void save_text(string file) const;
CountIdentifer get_vocabulary();
void save_vocabulary(string file) const;
Identifer get_identifer();
void save_identifer(string file) const;
void save(string binFile, string countFile);
void add(string word);
void add(string word, size_t count);
void most_common(size_t topN);
void min_count(size_t minCount);
void finalize();
void finish();
protected:
private:
unordered_map<string, size_t> _dict;
vector<WordFreq> _ordered;
size_t _corpusSize;
size_t _unknownSize;
size_t _vocabSize;
bool _addUnknown;
string _unknownMark;
string _totalCountMark;
size_t _mostCommon;
size_t _minCount;
bool _saveCountInfo;
bool _finished;
};
}
#endif
