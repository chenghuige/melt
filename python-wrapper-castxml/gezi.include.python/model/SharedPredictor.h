#ifndef SHARED_PREDICTOR_H_
#define SHARED_PREDICTOR_H_
#include "Predictor.h"
class SharedPredictor
{
public:
//static Predictor* instance();
static int init();
private:
static Predictor _predictor;
};
#endif
