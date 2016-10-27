#ifndef TIEBA_FEATURE_URATE__DICT_MATCH_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__DICT_MATCH_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "MatchDict.h"
#include "RegexSearcher.h"
namespace gezi {
namespace tieba {
class DictMatchExtractor : public UrateExtractor
{
public:
DictMatchExtractor(string name = "DictMatch");
virtual ~DictMatchExtractor();
bool ContainsBlack(string& content);
bool ContainsGray(string& content);
bool ContainsWhite(string& content);
bool containsBlackPattern(wstring& content);
bool ContainsContentBlackPattern(wstring& content);
bool ContainsGrayPattern(wstring& content);
int BlackCount(string& content);
int GrayCount(string& content);
void CalcTitleCounts(const svec& vec, int& m, int &n, int& x, int& y);
void CalcContentCounts(const svec& vec, int& m, int &n, int& x, int& y);
void FilterContents(svec& contents);
virtual void init();
virtual void extract();
private:
dm_pack_t* _result;
int _maxMatchCount;
private:
//static MatchDict& blackDict();
//static MatchDict& grayDict();
//static MatchDict& whiteDict();
//static RegexSearcher& blackRegSearcher();
//static RegexSearcher& contentBlackRegSearcher();
//static RegexSearcher& grayRegSearcher();
};
}
}
#endif
