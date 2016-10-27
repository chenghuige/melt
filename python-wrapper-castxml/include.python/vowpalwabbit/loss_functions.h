#pragma once
#include <string>
#include "parse_primitives.h"
using namespace std;
class loss_function
{
public :
//virtual float getLoss(shared_data*, float prediction, float label) = 0;
//virtual float getUpdate(float prediction, float label, float eta_t, float norm) = 0;
//virtual float getUnsafeUpdate(float prediction, float label, float eta_t, float norm) = 0;
//virtual float getRevertingWeight(shared_data*, float prediction, float eta_t) = 0;
//virtual float getSquareGrad(float prediction, float label) = 0;
//virtual float first_derivative(shared_data*, float prediction, float label) = 0;
//virtual float second_derivative(shared_data*, float prediction, float label) = 0;
virtual ~loss_function();
;
};
loss_function* getLossFunction(void*, string funcName, float function_parameter = 0);
