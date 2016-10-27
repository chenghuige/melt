#ifndef M_L_CORE__PREDICTOR_H_
#define M_L_CORE__PREDICTOR_H_
#include "common_util.h"
#include "serialize_util.h"
#include "statistic_util.h"
#include "Prediction/Normalization/NormalizerFactory.h"
#include "Prediction/Calibrate/CalibratorFactory.h"
#include "Prediction/Instances/Instance.h"
#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Calibrate/Calibrator.h"
#include "PredictionKind.h"
namespace gezi {
enum  CodeType
{
CodeType__enum__C,
CodeType__enum__Python,
CodeType__enum__Php,
};
class EnsemblePredictor;
class LoadSave;
class Predictor : public LoadSave
{
public:
Predictor();
virtual ~Predictor();
Predictor(NormalizerPtr normalizer, CalibratorPtr calibrator, const FeatureNamesVector& featureNames);
Predictor(CalibratorPtr calibrator, const FeatureNamesVector& featureNames);
Predictor(const FeatureNamesVector& featureNames);
virtual PredictionKind GetPredictionKind();
virtual string Name();
Predictor& SetPath(string path);
string Path();
Predictor& SetParam(string param);
Predictor& SetUseCustomModel(bool useCustomModel);
bool UseCustomModel() const;
string GetParam();
Float Output(Instance& instance);
virtual Float Output(InstancePtr instance);
map<string, Float> ToNamedFeatures(const Vector& features);
//void Print(const Vector& features, bool nonZeroOnly = false, std::ostream& ofs = std::cout);
Float Output(Vector& features);
Float Output(Fvec& values);
Float Output(ivec& indices, Fvec& values);
Float Predict(Instance& instance);
Float Predict(Fvec& values);
Float Predict(ivec& indices, Fvec& values);
virtual Float Output(string featureStr);
virtual Float Predict(string featureStr);
virtual Float Predict(string featureStr, Float& output);
virtual Float Predict(InstancePtr instance);
virtual Float Predict(Vector& features);
vector<Float> BulkPredict(vector<Vector>& featuresVector);
vector<Float> BulkPredict(vector<InstancePtr>& instances);
vector<Float> BulkPredict(vector<InstancePtr>& instances, vector<Float>& outputs);
virtual void InitThread();
Float Predict(Instance& instance, Float& output);
virtual Float Predict(InstancePtr instance, Float& output);
Float Predict(Vector& features, Float& output);
Float Predict(Fvec& values, Float& output);
Float Predict(ivec& indices, Fvec& values, Float& output);
Float Predict(const map<int, double>& m);
Float Output(const map<int, double>& m);
Float Predict(const map<int, double>& m, Float& output);
virtual Float Predict(Float output);
Predictor& SetNormalizeCopy(bool normalizeCopy = true);
virtual void Save();
virtual void SaveBin(string path);
virtual void Save(string path);
virtual void CustomSave();
virtual void CustomSave(string path);
virtual void CustomSave_(string path);
virtual void Save_(string file);
bool LoadNormalizerAndCalibrator(string path);
virtual bool LoadBin(string path);
void ReadPathAndSetParam_(string path);
virtual bool CustomLoad(string path);
virtual bool Load(string path);
virtual bool Load_(string file);
virtual void SaveXml(string file);
virtual void SaveXml_(string file);
virtual void SaveJson(string file);
virtual void SaveCode(string codeTypeStr = "cpp");
virtual void SaveJson_(string file);
virtual void SaveText(string file);
virtual void SaveText_(string file);
virtual void SaveCode_(string file, CodeType codeType);
void SaveXml();
void SaveJson();
void SaveText();
virtual void SaveFeaturesGain(int topNum = 0);
virtual bool CustomLoad_(string path);
virtual bool LoadText_(string file);
virtual bool LoadText(string path);
NormalizerPtr GetNormalizer();
void SetNormalizer(NormalizerPtr normalizer);
void SetCalibrator(CalibratorPtr calibrator);
CalibratorPtr& GetCalibrator();
Predictor& SetSaveNormalizerText(bool setSave = true);
Predictor& SetSaveCalibratorText(bool setSave = true);
static string ThirdModelName(string file);
//static bool& loadNormalizerAndCalibrator();
static void SetLoadNormalizerAndCalibrator(bool loadNormalizerAndCalibrator_ = true);
virtual string ToGainSummary(Vector& features, bool sortByAbsGain = true);
template<typename Vec>
string ToFeaturesGainSummary_(const Vec& gains, int topNum = 0);
virtual string ToFeaturesGainSummary(int topNum = 0);
void SetFeatureNames(const FeatureNamesVector& featureNames);
void SetFeatureGainVec(const vector<Float>& featureGainVec);
const FeatureNamesVector& FeatureNames() const;
//void SetFeatureGainVec(vector<Float>&& featureGainVec);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
friend class EnsemblePredictor;
virtual Float Margin(Vector& features);
private:
void SaveText_NormalizerAndCalibrator(bool saveNormalizer = true, bool saveCalibrator = true);
void SaveXml_NormalizerAndCalibrator(bool saveNormalizer = true, bool saveCalibrator = true);
void SaveJson_NormalizerAndCalibrator(bool saveNormalizer = true, bool saveCalibrator = true);
protected:
bool _normalizeCopy;
NormalizerPtr _normalizer;
CalibratorPtr _calibrator;
FeatureNamesVector _featureNames;
string _path;
string _param;
vector<Float> _featureGainVec;
private:
bool _saveNormalizerText;
bool _saveCalibratorText;
bool _useCustomModel;
};
class ProbabilityPredictor : public Predictor
{
public:
using Predictor::Predict;
virtual Float Predict(Float output);
};
typedef shared_ptr<Predictor> PredictorPtr;
typedef vector<PredictorPtr> Predictors;
}
#endif
