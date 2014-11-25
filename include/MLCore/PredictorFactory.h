/**
 *  ==============================================================================
 *
 *          \file   Predictors/PredictorFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-10 08:04:52.394292
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__PREDICTOR_FACTORY_H_
#define PREDICTORS__PREDICTOR_FACTORY_H_

#include "Predictors/LinearPredictor.h"
#include "Predictors/FastRankPredictor.h"
#include "Predictors/LibSVMPredictor.h"
#include "Predictors/VWPredictor.h"
namespace gezi {

	class PredictorFactory
	{
	public:
		enum class PredictorType
		{
			Unknown,
			Linear,
			BinaryClassificationFastRank,
			RandomForest,
			DecisionTree,
			KernalSVM,
			BinaryNeuralNetwork,
			VW,
			LibSVM,
		};

		static PredictorPtr CreatePredictor(string name)
		{
			map<string, PredictorType> _predictorTypes = {
				{ "unknown", PredictorType::Unknown },
				{ "linear", PredictorType::Linear },
				{ "linearsvm", PredictorType::Linear },
				{ "sofia", PredictorType::Linear },
				{ "liblinear", PredictorType::Linear },
				{ "binaryclassificationfastrank", PredictorType::BinaryClassificationFastRank },
				{ "randomforest", PredictorType::RandomForest },
				{ "decisiontree", PredictorType::DecisionTree },
				{ "kernalsvm", PredictorType::KernalSVM },
				{ "binaryneuralnetwork", PredictorType::BinaryNeuralNetwork },
				{ "vw", PredictorType::VW },
				{ "libsvm", PredictorType::LibSVM },
			};

			name = arg(name);

			PredictorType predictorType = _predictorTypes[name];
			switch (predictorType)
			{
			case PredictorType::Linear:
				return make_shared<LinearPredictor>();
			case  PredictorType::BinaryClassificationFastRank:
				return make_shared<FastRankPredictor>();
			case  PredictorType::LibSVM:
				return make_shared<LibSVMPredictor>();
			case PredictorType::VW:
				return make_shared<VWPredictor>();
			default:
				break;
			}


			LOG(WARNING) << name << " is not supported now, return nullptr";
			return nullptr;
		}

		static PredictorPtr CreatePredictor(string name, string path)
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
		static PredictorPtr LoadPredictor(string path)
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
		static PredictorPtr CreatePredictorFromTextFormat(string name, string path)
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

		static PredictorPtr LoadTextPredictor(string path)
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

		static Predictors LoadPredictors(const svec& paths)
		{
			Predictors predictors;
			for (string path : paths)
			{
				predictors.push_back(LoadPredictor(path));
			}
			return predictors;
		}
	protected:
	private:

	};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__PREDICTOR_FACTORY_H_
