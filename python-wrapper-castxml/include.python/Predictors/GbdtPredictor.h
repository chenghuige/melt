#ifndef PREDICTORS__GBDT_PREDICTOR_H_
#define PREDICTORS__GBDT_PREDICTOR_H_
#include "Identifer.h"
#include "file_util.h"
#include "MLCore/Predictor.h"
#include "Trainers/Gbdt/OnlineRegressionTree.h"
namespace gezi {
class GbdtPredictor : public Predictor
{
public:
virtual string Name();
GbdtPredictor();
//GbdtPredictor(vector<OnlineRegressionTree>& trees, CalibratorPtr calibrator,
//svec&& featureNames);
//GbdtPredictor(vector<OnlineRegressionTree>& trees, svec&& featureNames);
GbdtPredictor(vector<OnlineRegressionTree>& trees, CalibratorPtr calibrator,
const FeatureNamesVector& featureNames);
GbdtPredictor(vector<OnlineRegressionTree>& trees, const FeatureNamesVector& featureNames);
GbdtPredictor(vector<OnlineRegressionTree>& trees);
GbdtPredictor(string modelPath);
//static string& TextFilePattern();
bool LoadTLCText(string file);
bool LoadLightGBMText(string file);
virtual bool LoadText_(string file);
virtual void Save_(string file);
virtual void CustomSave_(string path);
virtual void SaveXml_(string file);
virtual void SaveJson_(string file);
virtual void SaveCode_(string file, CodeType codeType);
virtual bool Load_(string file);
virtual bool CustomLoad_(string path);
void PrintFeatureGain(Vector& features, bool sortByAbsGain = true, int level = 0);
map<int, double> GainMap(Vector& features);
virtual string ToGainSummary(Vector& features, bool sortByAbsGain = true);
#ifdef _DEBUG
void PrintTreeScores(bool sortByScore = false, bool reverse = true, int maxTreeNum = -1) const;
#endif
protected:
virtual Float Margin(Vector& features);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
vector<OnlineRegressionTree>& Trees();
const vector<OnlineRegressionTree>& Trees() const;
private:
//void LoadTree(std::ifstream& ifs, OnlineRegressionTree& tree);
//void SaveTree(const OnlineRegressionTree& tree, ofstream& ofs);
//void SaveCCode(ofstream& ofs);
//void SavePhpCode(ofstream& ofs);
//void SavePythonCode(ofstream& ofs);
//void SaveTreeAsCCode(const OnlineRegressionTree& tree, ofstream& ofs);
//void SaveTreeAsPhpCode(const OnlineRegressionTree& tree, ofstream& ofs);
//void SaveTreeAsPythonCode(const OnlineRegressionTree& tree, ofstream& ofs);
//void ToCCode(const OnlineRegressionTree& tree, ofstream& ofs, int node);
//void ToPhpCode(const OnlineRegressionTree& tree, ofstream& ofs, int node);
//void ToPythonCode(const OnlineRegressionTree& tree, ofstream& ofs, int node);
protected:
#ifdef _DEBUG
public:
vector<OnlineRegressionTree::DebugNode> _debugNodes;
#endif
#ifdef PYTHON_WRAPPER
public:
#endif
vector<OnlineRegressionTree> _trees;
};
class GbdtRegressionPredictor : public GbdtPredictor
{
public:
//using GbdtPredictor::GbdtPredictor;
virtual string Name();
virtual PredictionKind GetPredictionKind();
};
class GbdtRankingPredictor : public GbdtPredictor
{
//using GbdtPredictor::GbdtPredictor;
virtual string Name();
virtual PredictionKind GetPredictionKind();
};
}
//CEREAL_REGISTER_TYPE(gezi::GbdtPredictor);
#endif
