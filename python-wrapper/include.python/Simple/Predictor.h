#ifndef SIMPLE__PREDICTOR_H_
#define SIMPLE__PREDICTOR_H_
#include <vector>
#include <utility>
namespace gezi {
namespace simple {
class Predictor
{
public:
double Output(std::vector<double>& values);
double Predict(std::vector<double>& values);
double Predict(std::vector<double>& values, double& output);
double Output(std::vector<int>& indices, std::vector<double>& values);
double Predict(std::vector<int>& indices, std::vector<double>& values);
double Predict(std::vector<int>& indices, std::vector<double>& values, double& output);
public:
void* _predictor;
};
}
}
#endif
