#ifndef TIEBA_FEATURE_URATE__LANGUAGE_MODEL_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__LANGUAGE_MODEL_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "tools/language_model.h"
namespace gezi {
namespace tieba {
class LanguageModelExtractor : public UrateExtractor
{
public:
LanguageModelExtractor(string name = "LanguageModel");
private:
double _defaultValue;
public:
double LmScore(string title);
virtual void init();
virtual void extract();
private:
double lmScore(string s);
};
}
}
#endif
