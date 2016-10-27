#ifndef WRAPPER__SHARED_PREDICTORS_H_
#define WRAPPER__SHARED_PREDICTORS_H_
#include "Wrapper/PredictorFactory.h"
namespace gezi {
class SharedPredictors
{
public:
//static PredictorPtr& Instance(string modelPath);
//static PredictorPtr& Instance(int index = 0);
//static PredictorPtr& LastInstance();
//static Predictors& GetPredictors();
static void Init();
static int Size();
static int size();
static void PrintInfo();
};
}
#endif
