#ifndef SOFIA_ML_METHODS_H__
#define SOFIA_ML_METHODS_H__
#include "sf-data-set.h"
#include "sf-sparse-vector.h"
#include "sf-weight-vector.h"
namespace sofia_ml {
enum LearnerType
{
PEGASOS,
MARGIN_PERCEPTRON,
PASSIVE_AGGRESSIVE,
LOGREG_PEGASOS,
LOGREG,
LMS_REGRESSION,
SGD_SVM,
ROMMA
};
enum EtaType
{
BASIC_ETA,
PEGASOS_ETA,
CONSTANT
};
void StochasticOuterLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
int num_iters,
SfWeightVector* w);
void BalancedStochasticOuterLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
int num_iters,
SfWeightVector* w);
void StochasticRocLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
int num_iters,
SfWeightVector* w);
void StochasticClassificationAndRocLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
float rank_step_probability,
int num_iters,
SfWeightVector* w);
void StochasticClassificationAndRankLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
float rank_step_probability,
int num_iters,
SfWeightVector* w);
void StochasticRankLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
int num_iters,
SfWeightVector* w);
void StochasticQueryNormRankLoop(const SfDataSet& training_set,
LearnerType learner_type,
EtaType eta_type,
float lambda,
float c,
int num_iters,
SfWeightVector* w);
float SingleSvmPrediction(const SfSparseVector& x,
const SfWeightVector& w);
float SingleLogisticPrediction(const SfSparseVector& x,
const SfWeightVector& w);
void SvmPredictionsOnTestSet(const SfDataSet& test_data,
const SfWeightVector& w,
vector<float>* predictions);
void LogisticPredictionsOnTestSet(const SfDataSet& test_data,
const SfWeightVector& w,
vector<float>* predictions);
float SvmObjective(const SfDataSet& data_set,
const SfWeightVector& w,
float lambda);
bool OneLearnerStep(LearnerType method,
const SfSparseVector& x,
float eta,
float c,
float lambda,
SfWeightVector* w);
bool OneLearnerRankStep(LearnerType method,
const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float c,
float lambda,
SfWeightVector* w);
bool SinglePegasosStep(const SfSparseVector& x,
float eta,
float lambda,
SfWeightVector* w);
bool SingleSgdSvmStep(const SfSparseVector& x,
float eta,
float lambda,
SfWeightVector* w);
bool SinglePegasosLogRegStep(const SfSparseVector& x,
float eta,
float lambda,
SfWeightVector* w);
bool SingleLogRegStep(const SfSparseVector& x,
float eta,
float lambda,
SfWeightVector* w);
bool SingleLeastMeanSquaresStep(const SfSparseVector& x,
float eta,
float lambda,
SfWeightVector* w);
bool SingleMarginPerceptronStep(const SfSparseVector& x,
float eta,
float c,
SfWeightVector* w);
bool SingleRommaStep(const SfSparseVector& x,
SfWeightVector* w);
bool SinglePegasosRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float lambda,
SfWeightVector* w);
bool SingleSgdSvmRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float lambda,
SfWeightVector* w);
bool SingleRommaRankStep(const SfSparseVector& a,
const SfSparseVector& b,
SfWeightVector* w);
bool SingleMarginPerceptronRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float c,
SfWeightVector* w);
bool SingleLeastMeanSquaresRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float c,
SfWeightVector* w);
bool SinglePegasosLogRegRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float lambda,
SfWeightVector* w);
bool SingleLogRegRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float eta,
float lambda,
SfWeightVector* w);
bool SinglePegasosRankWithTiesStep(const SfSparseVector& rank_a,
const SfSparseVector& rank_b,
const SfSparseVector& tied_a,
const SfSparseVector& tied_b,
float eta,
float lambda,
SfWeightVector* w);
bool SinglePassiveAggressiveStep(const SfSparseVector& x,
float lambda,
float max_step,
SfWeightVector* w);
bool SinglePassiveAggressiveRankStep(const SfSparseVector& a,
const SfSparseVector& b,
float lambda,
float max_step,
SfWeightVector* w);
void PegasosProjection(float lambda,
SfWeightVector* w);
void L2Regularize(float eta, float lambda, SfWeightVector* w);
void L2RegularizeSeveralSteps(float eta,
float lambda,
float effective_steps,
SfWeightVector* w);
}
#endif
