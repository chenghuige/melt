/**
 *  ==============================================================================
 *
 *          \file   Utils/EvaluatorUtils.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-22 21:54:55.262056
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef UTILS__EVALUATOR_UTILS_H_
#define UTILS__EVALUATOR_UTILS_H_

#include "Evaluator.h"
#include "MLCore/PredictionKind.h"
#include "MLCore/Trainer.h"
namespace gezi {

class EvaluatorUtils 
{
public:

	//跟进trainer的type给出默认的Evaluators
	static vector<EvaluatorPtr> GetEvaluators(PredictionKind predictionKind)
	{
		vector<EvaluatorPtr> evaluators;
		if (predictionKind == PredictionKind::BinaryClassification)
		{
			evaluators.push_back(make_shared<AucEvaluator>());
		}
		return evaluators;
	}

	static vector<EvaluatorPtr> GetEvaluators(TrainerPtr trainer)
	{
		return GetEvaluators(trainer->GetPredictionKind());
	}

	static EvaluatorPtr CreateEvaluator(string evaluatorName)
	{
		evaluatorName = gezi::arg(evaluatorName);
		if (evaluatorName == "auc")
		{
			return make_shared<AucEvaluator>();
		}
		else if (evaluatorName == "l1")
		{
			return make_shared<L1Evaluator>();
		}
		else if (evaluatorName == "l2")
		{
			return make_shared<L2Evaluator>();
		}
		else if (evaluatorName == "rmse")
		{
			return make_shared<RMSEEvaluator>();
		}
		LOG(WARNING) << "Not supported evaluator: " << evaluatorName;
		return nullptr;
	}

	static StreamingEvaluatorPtr GetStreamingEvaluator(PredictionKind predictionKind)
	{
		if (predictionKind == PredictionKind::BinaryClassification)
		{
			return make_shared<AucStreamingEvaluator>();
		}
		else if (predictionKind == PredictionKind::Regression)
		{
			return make_shared<RMSEStreamingEvaluator>();
		}
		return nullptr;
	}

	static StreamingEvaluatorPtr CreateStreamingEvaluator(string evaluatorName)
	{
		evaluatorName = gezi::arg(evaluatorName);
		if (evaluatorName == "auc")
		{
			return make_shared<AucStreamingEvaluator>();
		}
		else if (evaluatorName == "l1")
		{
			return make_shared<L1StreamingEvaluator>();
		}
		else if (evaluatorName == "l2")
		{
			return make_shared<L2StreamingEvaluator>();
		}
		else if (evaluatorName == "rmse")
		{
			return make_shared<RMSEStreamingEvaluator>();
		}
		LOG(WARNING) << "Not supported evaluator: " << evaluatorName;
		return nullptr;
	}

	static vector<EvaluatorPtr> CreateEvaluators(string evaluatorNames)
	{
		vector<EvaluatorPtr> evaluators;
		vector<string> evaluatorNamesVec = gezi::split(evaluatorNames, ','); 
		for (string evaluatorName : evaluatorNamesVec)
		{
			EvaluatorPtr evaluator = CreateEvaluator(evaluatorName);
			CHECK(evaluator != nullptr);
		}
		return evaluators;
	}

protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of UTILS__EVALUATOR_UTILS_H_
