/**
 *  ==============================================================================
 *
 *          \file   PredictoryFactory.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-31 01:12:21.474996
 *
 *  \Description:
 *  ==============================================================================
 */
#include "MLCore/PredictorFactory.h"
#include "Predictors/LinearPredictor.h"
#include "Predictors/GbdtPredictor.h"
#ifndef MELT_NO_THIRD_PREDICTOR
#include "Predictors/LibSVMPredictor.h"
#include "Predictors/VWPredictor.h"
#endif
#include "Predictors/EnsemblePredictor.h"
namespace gezi{
	namespace {
		enum class PredictorType
		{
			//-------------- BinaryClassification
			Unknown,
			Linear,
			GbdtBinaryClassification,
			RandomForest,
			DecisionTree,
			KernalSVM,
			BinaryNeuralNetwork,
			VW,
			LibSVM,
			Ensemble,
			//------------- Regression
			GbdtRegression,
		};

		const  map<string, PredictorType> _predictorTypes = {
			{ "unknown", PredictorType::Unknown },
			{ "linear", PredictorType::Linear },
			{ "linearsvm", PredictorType::Linear },
			{ "sofia", PredictorType::Linear },
			{ "liblinear", PredictorType::Linear },
			{ "fastrank", PredictorType::GbdtBinaryClassification },
			{ "fr", PredictorType::GbdtBinaryClassification },
			{ "gbdt", PredictorType::GbdtBinaryClassification },
			{ "randomforest", PredictorType::RandomForest },
			{ "rf", PredictorType::RandomForest },
			{ "decisiontree", PredictorType::DecisionTree },
			{ "dt", PredictorType::DecisionTree },
			{ "kernalsvm", PredictorType::KernalSVM },
			{ "ksvm", PredictorType::KernalSVM },
			{ "binaryneuralnetwork", PredictorType::BinaryNeuralNetwork },
			{ "neural", PredictorType::BinaryNeuralNetwork },
			{ "vw", PredictorType::VW },
			{ "ensemble", PredictorType::Ensemble },
			{ "libsvm", PredictorType::LibSVM },
			{ "fastrankregression", PredictorType::GbdtRegression },
			{ "gbdtregression", PredictorType::GbdtRegression },
			{ "frr", PredictorType::GbdtRegression },
			{ "gbrt", PredictorType::GbdtRegression },
		};
	} //------------- anoymous namespace
	PredictorPtr PredictorFactory::CreatePredictor(string name)
	{
		name = arg(name);

		PredictorType predictorType = _predictorTypes[name];
		switch (predictorType)
		{
			//------ Binary Classification
		case PredictorType::Linear:
			return make_shared<LinearPredictor>();
		case  PredictorType::GbdtBinaryClassification:
			return make_shared<GbdtPredictor>();
#ifndef MELT_NO_THIRD_PREDICTOR
		case  PredictorType::LibSVM:
			return make_shared<LibSVMPredictor>();
		case PredictorType::VW:
			return make_shared<VWPredictor>();
#endif
		case PredictorType::Ensemble:
			return make_shared<EnsemblePredictor>();
			//---- Regression
		case PredictorType::GbdtRegression:
			return make_shared<GbdtRegressionPredictor>();
		default:
			break;
		}

		LOG(WARNING) << name << " is not supported now, return nullptr";
		return nullptr;
	}

	PredictorPtr PredictorFactory::CreatePredictor(string name, string path)
	{
		PredictorPtr predictor = CreatePredictor(name);
		if (predictor != nullptr)
		{
			predictor->Load(path);
		}
		else
		{
			LOG(WARNING) << "CreatePredictor fail! path: " << path << " name: " << name;
		}
		return predictor;
	}

	//Mostly used
	PredictorPtr PredictorFactory::LoadPredictor(string path)
	{
		string name = read_file(path + "/model.name.txt");
		PredictorPtr predictor = CreatePredictor(name);
		if (predictor != nullptr)
		{
			predictor->Load(path);
		}
		else
		{
			LOG(WARNING) << "CreatePredictor fail! path: " << path << " name: " << name;
		}
		return predictor;
	}

	//主要用于线性分类器 用于接受其他外部分类器的结果转换为melt接受的文本格式后载入
	PredictorPtr PredictorFactory::CreatePredictorFromTextFormat(string name, string path)
	{
		PredictorPtr predictor = CreatePredictor(name);
		if (predictor != nullptr)
		{
			predictor->LoadText(path);
		}
		else
		{
			LOG(WARNING) << "CreatePredictor fail! path: " << path << " name: " << name;
		}
		return predictor;
	}

	PredictorPtr PredictorFactory::LoadTextPredictor(string path)
	{
		string name = read_file(path + "/model.name.txt");
		PredictorPtr predictor = CreatePredictor(name);
		if (predictor != nullptr)
		{
			predictor->LoadText(path);
		}
		else
		{
			LOG(WARNING) << "CreatePredictor fail! path: " << path << " name: " << name;
		}
		return predictor;
	}

	Predictors PredictorFactory::LoadPredictors(const svec& paths)
	{
		Predictors predictors;
		for (string path : paths)
		{
			predictors.push_back(LoadPredictor(path));
		}
		return predictors;
	}
}  //----end of namespace gezi
