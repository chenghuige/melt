#ifndef _MODEL_H_
#define _MODEL_H_
#include <string>
#include "feature/Feature.h"
#include "Score.h"
#include <vector>
using gezi::Feature;
using std::vector;
class Model
{
public:
virtual int load(const char*);
virtual ~Model();
Model(string modelType = "", int modelId = 0);
int init();
virtual int predict(Feature *, Score *);
virtual void predict(Feature& feature, vector<double>& result);
virtual double Predict(Feature& feature);
virtual void finalize();
double predict(Feature& feature, int index = 0);
double predict(Feature* feature, int index = 0);
virtual void setModelId(int id);
void setModelType(std::string type);
void setModelPath(std::string path);
virtual int getModelId() const;
std::string getModelPath();
std::string getModelType();
std::string path();
std::string type();
int id();
inline void printInfo();
private:
int _modelId;
std::string _modelType;
std::string _modelPath;
};
#endif
