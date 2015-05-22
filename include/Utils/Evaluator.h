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

#include "performance_evaluate.h"

namespace gezi {
	class Evaluator
	{
	public:
		virtual string Name() = 0;
		virtual bool LowerIsBetter()
		{
			return true;
		}
		virtual double Evaluate(vector<EvaluateNode>& results) = 0;
	};

	class StreamingEvaluator
	{
	public:
		void Add(Float label, Float prediction, Float weight = 1.0)
		{
			_results.push_back(EvaluateNode(label, prediction, weight));
		}
		virtual double Evaluate() = 0;
	protected:
		vector<EvaluateNode> _results;
	};

	typedef shared_ptr<Evaluator> EvaluatorPtr;
	typedef shared_ptr<StreamingEvaluator> StreamingEvaluatorPtr;

	//auc can be used for binary classification or ranking
	class AucEvaluator : public Evaluator
	{
	public:
		virtual string Name()
		{
			return "AUC";
		}
		virtual bool LowerIsBetter() override
		{
			return false;
		}
		virtual double Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::auc(results);
		}
	};

	class AucStreamingEvaluator : public StreamingEvaluator
	{
	public:
		virtual double Evaluate() override
		{
			return ev::auc(_results);
		}
	};

	class L1Evaluator : public Evaluator
	{
	public:
		virtual string Name()
		{
			return "L1";
		}
		virtual double Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::l1(results);
		}
	};

	class L1StreamingEvaluator : public StreamingEvaluator
	{
	public:
		virtual double Evaluate() override
		{
			return ev::l1(_results);
		}
	};

	class L2Evaluator : public Evaluator
	{
	public:
		virtual string Name()
		{
			return "L2";
		}
		virtual double Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::l2(results);
		}
	};

	class L2StreamingEvaluator : public StreamingEvaluator
	{
	public:
		virtual double Evaluate() override
		{
			return ev::l2(_results);
		}
	};

	class RMSEEvaluator : public Evaluator
	{
	public:
		virtual string Name()
		{
			return "RMSE";
		}
		virtual double Evaluate(vector<EvaluateNode>& results) override
		{
			return ev::rmse(results);
		}
	};

	class RMSEStreamingEvaluator : public StreamingEvaluator
	{
	public:
		virtual double Evaluate() override
		{
			return ev::rmse(_results);
		}
	};
}  //----end of namespace gezi

#endif  //----end of UTILS__EVALUATOR_H_
