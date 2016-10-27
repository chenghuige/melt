#ifndef PREDICTORS__RANDOM_PREDICTOR_H_
#define PREDICTORS__RANDOM_PREDICTOR_H_
#include "MLCore/Predictor.h"
#include "random_util.h"
namespace gezi {
class RandomPredictor : public Predictor
{
public:
RandomPredictor();
protected:
virtual Float Margin(Vector& features);
private:
RandomInt _randomInt;
};
}
#endif
