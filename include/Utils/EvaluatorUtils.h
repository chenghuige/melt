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
		static vector<EvaluatorPtr> GetEvaluators(TrainerPtr trainer)
		{
			vector<EvaluatorPtr> vec = GetEvaluators(trainer->GetPredictionKind());
			EvaluatorPtr evaluator = GetEvaluator(trainer->GetLossKind());
			if (evaluator != nullptr)
			{
				vec.push_back(evaluator);
			}
			return vec;
		}

		//每个Trainer训练过程会优化一个LossFunction根据这个种类 返回对应的Evaluator
		static EvaluatorPtr GetEvaluator(LossKind lossKind)
		{
			switch (lossKind)
			{
			case LossKind::Squared:
				return make_shared<L2Evaluator>();
			case LossKind::Logistic:
				return make_shared<LogLossOutputEvaluator>();
			case LossKind::Exponential:
				return make_shared<ExpLossEvaluator>();
			case  LossKind::Hinge:
				return make_shared<HingeLossEvaluator>();
			case LossKind::GoldStandard:
				return make_shared<GoldStandardOutputEvaluator>();
			default:
				return nullptr;
			}
			return nullptr;
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
			else if (evaluatorName == "logprob")
			{
				return make_shared<LogLossEvaluator>();
			}
			else if (evaluatorName == "log")
			{//just for experiment verify
				return make_shared<LogLossOutputEvaluator>();
			}
			else if (evaluatorName == "goldprob")
			{
				return make_shared<GoldStandardEvaluator>();
			}
			else if (evaluatorName == "gold")
			{
				return make_shared<GoldStandardOutputEvaluator>();
			}
			else if (evaluatorName == "exp")
			{
				return make_shared<ExpLossEvaluator>();
			}
			else if (evaluatorName == "hinge")
			{
				return make_shared<HingeLossEvaluator>();
			}
			LOG(WARNING) << "Not supported evaluator: " << evaluatorName;
			return nullptr;
		}

		static vector<EvaluatorPtr> GetEvaluators(PredictionKind predictionKind)
		{
			typedef vector<EvaluatorPtr> Vec;
			if (predictionKind == PredictionKind::BinaryClassification)
			{
				return Vec{ make_shared<AucEvaluator>() };
			}
			else if (predictionKind == PredictionKind::Regression)
			{
				return Vec{ make_shared<RMSEEvaluator>() };
			}
			return Vec();
		}

		static vector<EvaluatorPtr> CreateEvaluators(string evaluatorNames)
		{
			vector<EvaluatorPtr> evaluators;
			vector<string> evaluatorNamesVec = gezi::split(evaluatorNames, ',');
			for (string evaluatorName : evaluatorNamesVec)
			{
				EvaluatorPtr evaluator = CreateEvaluator(evaluatorName);
				CHECK(evaluator != nullptr);
				evaluators.push_back(evaluator);
			}
			return evaluators;
		}

		static vector<string> GetEvaluatorsNames(const vector<EvaluatorPtr>& evaluators)
		{
			return from(evaluators) >> select([](const EvaluatorPtr& a){return a->Name(); }) >> to_vector();
		}

	protected:
	private:

	};

}  //----end of namespace gezi

#endif  //----end of UTILS__EVALUATOR_UTILS_H_
