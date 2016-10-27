#ifndef  __PREDICTOR_H_
#define  __PREDICTOR_H_
#include "Model.h"
#include "feature/FeatureNormalizer.h"
#include <vector>
using gezi::FeatureNormalizer;
DECLARE_string(model_type);
class Predictor
{
public:
typedef vector<Model*> ModelList;
typedef vector<FeatureNormalizer*> NormalizerList;
virtual ~Predictor();
double Predict(Feature&);
int predict(Feature *, Score *, int index = 0);
double predict(Feature*, int index = 0, int inner_index = 0);
double predict(Feature&, int index = 0, int inner_index = 0);
double predict(string featureStr, int index = 0, int inner_index = 0);
void predict(Feature*, vector<Score>* result);
void predict(Feature&, vector<double>& result, int index = 0);
void predict(Feature&, vector<vector<double> >& result);
void predict(string featureStr, vector<Score>& result);
void predict(string featureStr, vector<double>& result);
virtual int init();
virtual size_t getModelCnt() const;
//Model* model();
virtual Model* getModel(int index) const;
//FeatureNormalizer* normalizer();
virtual FeatureNormalizer* getNormalizer(int index) const;
inline ModelList& modelList();
inline NormalizerList& filterList();
void addModel(Model* model);
void add(Model* model);
void insertModel(Model* model);
void insert(Model* model);
void addNormalizer(FeatureNormalizer* filter);
void add(FeatureNormalizer* filter);
void insertNormalizer(FeatureNormalizer* filter);
void insert(FeatureNormalizer* filter);
inline int modelNum();
private:
ModelList _modelList;
NormalizerList _filterList;
};
#endif
