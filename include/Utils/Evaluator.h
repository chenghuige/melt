/**
 *  ==============================================================================
 *
 *          \file   Utils/Evaluator.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-22 16:36:39.427367
 *
 *  \Description: MELT中Tester和Evaluator区别 Tester更加针对Melt框架定制化，写文件 写默认的一些test多个数据
 *                主要为了显示方便，Evauator每个只负责一项输出，可以自由组合更灵活， 不写文件
 *  ==============================================================================
 */

#ifndef UTILS__EVALUATOR_H_
#define UTILS__EVALUATOR_H_

#include "evaluate.h"
#include "Prediction/Instances/Instance.h"
namespace gezi {
	namespace ev = evaluate;
	class Evaluator
	{
	public:
		virtual string Name() const = 0;
		virtual bool LowerIsBetter() const
		{
			return true;
		}
		//--主要接口
		//virtual Float Evaluate(const vector<Float>& predictions, const Instances& instances)
		//{
		//	return 0;
		//}

		virtual Float Evaluate(const vector<Float>& predictions, const vector<InstancePtr>& instances)
		{
			return 0;
		}

		virtual Float Evaluate(const vector<Float>& predictions, const vector<Float>& labels, const vector<Float>& weights)
		{
			if (weights.empty())
			{
				weights.resize(predictions.size(), 1.0);
			}
			vector<EvaluateInstancePtr> instances;
			for (size_t i = 0; i < predictions.size(); i++)
			{
				instances.push_back(make_shared<EvaluateInstance>(labels[i], weights[i]));
			}
			return Evaluate(predictions, instances);
		}

		//------不再维护
		virtual Float Evaluate(vector<EvaluateNode>& results)
		{
			vector<Float> predictions;
			vector<EvaluateInstancePtr> instances;
			for (auto& item : results)
			{
				predictions.push_back(item.prediction);
				instances.push_back(make_shared<EvaluateInstance>(item.label, item.weight));
			}
			return Evaluate(predictions, instances);
		}

		//--------below for streaming evaluator now only used in ClassiferTester.h 
		void Add(Float label, Float prediction, Float weight = 1.0)
		{
			_predictions.push_back(prediction);
			_instances.push_back(make_shared<EvaluateInstance>(label, weight));
		}
		virtual Float Finalize()
		{
			Float score = Evaluate();
			Clear();
			return score;
		}
	protected:
		void Clear()
		{
			_instances.clear();
			_predictions.clear();
		}

		Float Evaluate()
		{
			return Evaluate(_predictions, _instances);
		}

		virtual Float Evaluate(const vector<Float>& predictions, const vector<EvaluateInstancePtr>& instances)
		{
			return 0;
		}
	protected:
		vector<Float> _predictions;
		vector<shared_ptr<EvaluateInstance> > _instances;
	};

	typedef shared_ptr<Evaluator> EvaluatorPtr;

	template<typename Derived>
	class EvaluatorImpl : public Evaluator
	{
	public:
		virtual string Name() const = 0;
		virtual bool LowerIsBetter() const
		{
			return true;
		}

		//virtual Float Evaluate(const vector<Float>& predictions, const Instances& instances)
		//{
		//	return Derived::EvaluateInstances(predictions, instances);
		//}

		virtual Float Evaluate(const vector<Float>& predictions, const vector<InstancePtr>& instances)
		{
			return Derived::EvaluateInstances(predictions, instances);
		}

	protected:
		virtual Float Evaluate(const vector<Float>& predictions, const vector<EvaluateInstancePtr>& instances)
		{
			return Derived::EvaluateInstances(predictions, instances);
		}
	
	};

	//auc can be used for binary classification or ranking
	class AucEvaluator : public EvaluatorImpl<AucEvaluator>
	{
	public:
		virtual string Name() const
		{
			return "AUC";
		}
		virtual bool LowerIsBetter() const override
		{
			return false;
		}
		
		//--不再维护
		virtual Float Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::auc(results);
		}

		template<typename Vec>
		static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances)
		{
			return ev::auc(predictions, instances);
		}
	};

	class L1Evaluator : public EvaluatorImpl<L1Evaluator>
	{
	public:
		virtual string Name() const
		{
			return "L1";
		}
		virtual Float Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::l1(results);
		}

		template<typename Vec>
		static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances)
		{
			return ev::l1(predictions, instances);
		}
	};


	class L2Evaluator : public EvaluatorImpl<L2Evaluator>
	{
	public:
		virtual string Name() const
		{
			return "L2";
		}
		virtual Float Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::l2(results);
		}

		template<typename Vec>
		static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances)
		{
			return ev::l2(predictions, instances);
		}
	};

	class RMSEEvaluator : public EvaluatorImpl<RMSEEvaluator>
	{
	public:
		virtual string Name() const
		{
			return "RMSE";
		}
		virtual Float Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::rmse(results);
		}

		template<typename Vec>
		static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances)
		{
			return ev::rmse(predictions, instances);
		}
	};

}  //----end of namespace gezi

#endif  //----end of UTILS__EVALUATOR_H_
