#ifndef WRAPPER__PREDICTOR_FACTORY_H_
#define WRAPPER__PREDICTOR_FACTORY_H_
#include "common_util.h"
#include "MLCore/PredictorFactory.h"
DECLARE_string(model_dir);
namespace gezi {
namespace wrapper {
class PredictorFactory
{
public:
static Predictors LoadPredictors();
protected:
private:
};
}
}
#endif
