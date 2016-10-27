#ifndef INCLUDE__PREDICTION__CALIBRATE__CALIBRATOR_H_
#define INCLUDE__PREDICTION__CALIBRATE__CALIBRATOR_H_
#include "common_util.h"
#include "random_util.h"
#include "Prediction/Instances/Instances.h"
namespace gezi {
class CalibratorStore
{
public:
CalibratorStore();
struct Node
{
Float target;
Float weight;
Float score;
Node(Float target_, Float weight_, Float score_);
bool operator < (const Node& other) const;
void Set(Float target_, Float weight_, Float score_);
};
enum StoreType
{
StoreType__enum__Replace,
StoreType__enum__Aggregate,
};
void Add(Float score, bool IsPositiveTarget, Float weight);
void Sort();
vector<Node>& Nodes();
static int RandSeed();
private:
vector<Node> nodes;
int maxNumSamples;
int itemsSeen;
Float storedWeight;
StoreType type;
RandomPtr rand;
bool sorted;
};
typedef shared_ptr<CalibratorStore> CalibratorStorePtr;
class Calibrator : public LoadSave
{
public:
virtual ~Calibrator();
virtual Float PredictProbability(Float output);
virtual string Name();
template<typename MarginFunc>
void Train(const Instances& instances, MarginFunc marginFunc);
void Train(const vector<Float>& predictions, const Instances& instances);
template<typename MarginFunc>
void Train(const Instances& instances, MarginFunc marginFunc, size_t maxCount);
void Train(const Fvec& scores, const BitArray& labels, const Fvec& weights);
void Train(const Fvec& scores, const BitArray& labels);
virtual void ProcessTrainingExample(Float output, bool clicked, Float weight = 1.0);
virtual void FinishTraining();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
typedef shared_ptr<Calibrator> CalibratorPtr;
class CalibratorWrapper : public Calibrator
{
public:
virtual ~CalibratorWrapper();
virtual void ProcessTrainingExample(Float output, bool clicked, Float weight);
virtual void FinishTraining();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
virtual void TrainModel(CalibratorStore& data);
private:
CalibratorStorePtr _data;
};
}
//CEREAL_REGISTER_TYPE(gezi::CalibratorWrapper);
#endif
