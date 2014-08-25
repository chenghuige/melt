/**
 *  ==============================================================================
 *
 *          \file   Wrapper/SharedPredictors.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-15 12:51:20.935057
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef WRAPPER__SHARED_PREDICTORS_H_
#define WRAPPER__SHARED_PREDICTORS_H_


#include "Wrapper/PredictorFactory.h"
namespace gezi {

class SharedPredictors
{
public:
	static PredictorPtr& Instance(int index = 0)
	{
		return  GetPredictors()[index];
	}

	static PredictorPtr& LastInstance()
	{
		return  GetPredictors().back();
	}

	static Predictors& GetPredictors()
	{
		static Predictors _predictors = wrapper::PredictorFactory::LoadPredictors();
		return _predictors;
	}

	static void Init()
	{
		GetPredictors();
	}

	static int Size()
	{
		return GetPredictors().size();
	}

	static int size()
	{
		return GetPredictors().size();
	}

	static void PrintInfo()
	{
		Pval(Size());
		int idx = 0;
		for (auto predictor : GetPredictors())
		{
			if (predictor != nullptr)
			{
				LOG(INFO) << idx << "\t" << predictor->Name() << "\t" << predictor->Path();
			}
			else
			{
				LOG(INFO) << idx << "\t" << "nullptr";
			}
			idx++;
		}
	}
};

}  //----end of namespace gezi

#endif  //----end of WRAPPER__SHARED_PREDICTORS_H_
