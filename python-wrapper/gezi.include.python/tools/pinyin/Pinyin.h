#ifndef TOOLS_PINYIN__PINYIN_H_
#define TOOLS_PINYIN__PINYIN_H_
#include "tools/pinyin/IPYFactory.h"
#include "tools/pinyin/IPYNotation.h"
#include "common_util.h"
namespace gezi {
class Pinyin
{
public:
virtual ~Pinyin();
static void Load(string dictPath);
static string Convert(string input);
protected:
private:
//static NLP::Pinyin::IPYNotation*& PyNotaion();
};
}
#endif
