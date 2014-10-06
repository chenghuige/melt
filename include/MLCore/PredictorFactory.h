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
namespace gezi {

class PredictorFactory 
{
public:
	static PredictorPtr CreatePredictor(string name)
	{
		boost::to_lower(name);
		if (contains(name, "linear"))
		{
			return make_shared<LinearPredictor>();
		}
		else if (contains(name, "fastrank"))
		{
			return make_shared<FastRankPredictor>();
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
