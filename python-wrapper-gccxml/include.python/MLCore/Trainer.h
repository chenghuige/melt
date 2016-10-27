#ifndef M_L_CORE__TRAINER_H_
#define M_L_CORE__TRAINER_H_
#include "common_def.h"
#include "random_util.h"
#include "Prediction/Instances/Instances.h"
#include "MLCore/Predictor.h"
#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Calibrate/Calibrator.h"
#include "Utils/Evaluator.h"
#include "statistic_util.h"
#include "MLCore/LossKind.h"
namespace gezi {
interface Trainer : public WithArgs, public WithHelp
{
public:
//virtual PredictorPtr CreatePredictor() = 0;
virtual PredictionKind GetPredictionKind();
virtual LossKind GetLossKind();
virtual void Train(Instances& instances);
virtual void TryInitializeNormalizer(Instances& instances, bool isStreaming);
const HeaderSchema& TrainingSchema() const;
virtual string GetParam();
RandomPtr GetRandom();
NormalizerPtr GetNormalizer();
CalibratorPtr GetCalibrator();
void SetNormalizeCopy(bool normalizeCopy = true);
void SetNormalizer(NormalizerPtr normalizer);
void SetCalibrator(CalibratorPtr calibrator);
void SetStreaming();
virtual unsigned GetRandSeed() const;
void SetRandSeed(unsigned randSeed);
protected:
virtual void Init();
virtual void Initialize(Instances& instances);
virtual void InnerTrain(Instances& instances);
virtual void Finalize(Instances& instances);
protected:
HeaderSchema _trainingSchema;
bool _isStreaming;
unsigned _randSeed;
RandomPtr _rand;
RandomRangePtr _randRange;
NormalizerPtr _normalizer;
CalibratorPtr _calibrator;
FeatureNamesVector _featureNames;
int _numFeatures;
bool _normalizeCopy;
//static Instances& normalizedInstances();
Instances* _instances;
};
typedef shared_ptr<Trainer> TrainerPtr;
interface ValidatingTrainer : public Trainer
{
public:
//using Trainer::Trainer;
ValidatingTrainer();
using Trainer::Train;
virtual void Train(Instances& instances, vector<Instances>& validationInstances, vector<EvaluatorPtr>& evaluators);
//virtual void Train(Instances& instances, vector<Instances>&& validationInstances, vector<EvaluatorPtr>&& evaluators);
int BestIteration() const;
bool Validating() const;
protected:
bool Evaluate(int round, bool forceEvaluate = false);
void EvaluateOnce();
virtual void GenPredicts();
template<typename Func>
void DoGenPredicts(Func func);
template<typename Func>
void DoAddPredicts(Func func);
template<typename Func>
void DoPredicts(Func func);
virtual void GenProabilites();
virtual void EvaluatePredicts();
virtual void StoreBestStage();
virtual void RestoreBestStage();
private:
void PrintEvaluateResult(int round);
void InitEarlyStop();
bool IsBetter(Float now, Float before);
bool CheckEarlyStop();
public:
ValidatingTrainer& SetEvaluateFrequency(int freq);
ValidatingTrainer& SetSelfEvaluate(bool evaluate);
ValidatingTrainer& SetSelfEvaluate2(bool evaluate);
void SetScale(double scale);
void SetSelfEvaluateInstances(const Instances& instances);
ValidatingTrainer& SetEarlyStop(bool earlyStop = true);
ValidatingTrainer& SetEarlyStopCheckFrequency(int earlyStopCheckFrequency);
ValidatingTrainer& SetEarlyStopRounds(int stopRounds);
ValidatingTrainer& SetUseBestStage(bool useBestStage = true);
public:
vector<Fvec> Scores;
vector<Fvec> Probabilities;
Fvec TrainScores;
Fvec TrainProbabilities;
protected:
bool _validating;
bool _selfEvaluate;
bool _selfEvaluate2;
int _evaluateFrequency;
vector<Fvec> _evaluateResults;
vector<Instances> _validationSets;
vector<EvaluatorPtr> _evaluators;
vector<string> _valdationSetNames;
Float _scale;
bool _earlyStop;
int _earlyStopCheckFrequency;
int _stopRounds;
bool _useBestStage;
int _bestCheckIteration;
int _roundsAfterBestIteration;
int _checkCounts;
Float _bestScore;
int _round;
};
}
#endif
