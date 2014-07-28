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

	//测试任意给一个正类样本和一个负类样本，正类样本的score有多大的概率大于负类样本的score。有了这个定义，我们就得到了另外一中计算AUC的办法：得到这个概率。我们知道，在有限样本中我们常用的得到概率的办法就是通过频率来估计之。这种估计随着样本规模的扩大而逐渐逼近真实值。这 和上面的方法中，样本数越多，计算的AUC越准确类似，也和计算积分的时候，小区间划分的越细，计算的越准确是同样的道理。具体来说就是统计一下所有的 M×N(M为正类样本的数目，N为负类样本的数目)个正负样本对中，有多少个组中的正样本的score大于负样本的score。当二元组中正负样本的 score相等的时候，按照0.5计算。然后除以MN。实现这个方法的复杂度为O(n ^ 2)。n为样本数（即n = M + N）

	//	第三种方法实际上和上述第二种方法是一样的，但是复杂度减小了。它也是首先对score从大到小排序，然后令最大score对应的sample 的rank为n，第二大score对应sample的rank为n - 1，以此类推。然后把所有的正类样本的rank相加，再减去正类样本的score为最 小的那M个值的情况。得到的就是所有的样本中有多少对正类样本的score大于负类样本的score。然后再除以M×N。即
	//http://www.tuicool.com/articles/qYNNF3
	inline double auc(vector<std::tuple<int, Float, Float> >& results, bool needSort = true)
	{
		if (needSort)
		{
			stable_sort(results.begin(), results.end(),
				[](const std::tuple<int, Float, Float>& l, const std::tuple<int, Float, Float>& r) {
				return std::get<1>(l) > std::get<1>(r); });
		}

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
			Pval3(label, output, weight);
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
