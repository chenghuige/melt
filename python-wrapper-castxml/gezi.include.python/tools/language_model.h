#ifndef TOOLS_LANGUAGE_MODEL_H_
#define TOOLS_LANGUAGE_MODEL_H_
#include "common_util.h"
#include "DictCalFactory.h"
#include "tools/LanguageModel.h"
namespace gezi {
inline double language_model_score(string sentence);
inline double language_model_score(string sentence, string modelPath, int order = 3, double oovPunish = -10);
inline double language_model_score_cnwords(string sententce);
inline double language_model_score_cnwords(string sententce, string modelPath, int order = 3, double oovPunish = -10);
}
#endif
