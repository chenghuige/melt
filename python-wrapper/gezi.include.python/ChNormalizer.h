#ifndef GEZI_CH_NORMALIZER_H_
#define GEZI_CH_NORMALIZER_H_
#include "ul_ccode.h"
#include "string_def.h"
#include <glog/logging.h>
namespace gezi {
class ChNormalizer
{
public:
static void Load(string dir = "./data/ccode");
static void Init(string dir = "./data/ccode");
static string ToLower(string src);
static string ToSimplified(string src);
static string ToHalf(string src);
static string Normalize(string src, bool toLower = true, bool toSimplified = true, bool toHalf = true);
protected:
private:
};
class ThreadChNormalizer
{
public:
ThreadChNormalizer();
~ThreadChNormalizer();
};
}
#endif
