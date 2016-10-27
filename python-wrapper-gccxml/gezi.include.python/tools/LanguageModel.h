#ifndef TOOLS__LANGUAGE_MODEL_H_
#define TOOLS__LANGUAGE_MODEL_H_
#include "DictCalFactory.h"
namespace gezi {
class LanguageModel
{
public:
LanguageModel();
LanguageModel(string path, int order = 3, int oovPunish = -10);
~LanguageModel();
void Init(string modelPath, int order = 3, int oovPunish = -10);
inline double GetScore(string sentence);
inline double GetScoreFromCnWords(string sententce);
protected:
private:
const LangModel::AbstractScoreCal* _model;
};
}
#endif
