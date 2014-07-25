/**
 *  ==============================================================================
 *
 *          \file   performance_evaluate.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-25 15:07:01.534980
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PERFORMANCE_EVALUATE_H_
#define PERFORMANCE_EVALUATE_H_

#include "common_util.h"
namespace gezi {

	inline double auc(vector<std::tuple<int, Float, Float> >& results)
	{
		stable_sort(results.begin(), results.end(),
			[](const std::tuple<int, Float, Float>& l,const std::tuple<int, Float, Float>& r) {
			return std::get<1>(l) > std::get<1>(r); });

			Float oldFalsePos = 0;
			Float oldTruePos = 0;
			Float falsePos = 0;
			Float truePos = 0;
			Float oldOut = std::numeric_limits<double>::infinity();
			Float result = 0;

			for (auto& item : results)
			{
				int label = std::get<0>(item);
				Float output = std::get<1>(item);
				Float weight = std::get<2>(item);
				if (output != oldOut)
				{
					result += 0.5 * (oldTruePos + truePos) * (falsePos - oldFalsePos);
					oldOut = output;
					oldFalsePos = falsePos;
					oldTruePos = truePos;
				}
				if (label > 0)
					truePos += weight;
				else
					falsePos += weight;

			}
			result += 0.5 * (oldTruePos + truePos) * (falsePos - oldFalsePos);
			Float AUC = result / (truePos * falsePos);
			return AUC;
	}

	class BinaryClassficationEvaluator
	{
	public:
		virtual void Add(int label, Float output, Float weight = 1.0)
		{

		}

		virtual double Finish()
		{
			return 0;
		}
	};

	typedef shared_ptr<BinaryClassficationEvaluator> BinaryClassficationEvaluatorPtr;
	class AucEvaluator : public BinaryClassficationEvaluator
	{
	public:
		virtual void Add(int label, Float output, Float weight = 1.0) override
		{
			_results.push_back(std::make_tuple(label, output, weight));
		}

		virtual double Finish() override
		{
			return auc(_results);
		}
	private:
		vector<std::tuple<int, Float, Float> > _results;
	};

}  //----end of namespace gezi

#endif  //----end of PERFORMANCE_EVALUATE_H_
