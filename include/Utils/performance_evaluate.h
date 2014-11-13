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
	//	第三种方法实际上和上述第二种方法是一样的，但是复杂度减小了。它也是首先对score从大到小排序，然后令最大score对应的sample 的rank为n，第二大score对应sample的rank为n - 1，以此类推。然后把所有的正类样本的rank相加，再减去正类样本的score为最 小的那M个值的情况。得到的就是所有的样本中有多少对正类样本的score大于负类样本的score。然后再除以M×N。即 AUC=((所有的正例位置相加)-M*(M+1))/(M*N) 另外，特别需要注意的是，再存在score相等的情况时，对相等score的样本，需要 赋予相同的rank(无论这个相等的score是出现在同类样本还是不同类的样本之间，都需要这样处理)。具体操作就是再把所有这些score相等的样本 的rank取平均。然后再使用上述公式。
	//http://www.tuicool.com/articles/qYNNF3
	/*2. 正样本M个，负样本N个，做交叉，总共会产生M*N个样本对，统计一下在这些样本对中有多少正样本的score大于负样本的score，例如有K对，那么AUC的值就是K / (M*N)
		举例说明一下：
		样本：y = 1，y = 1， y = 1， y = -1， y = -1， y = -1
		模型1的预测：0.8，0.7，0.3，0.5，0.6，0.9
		模型2的预测：0.1， 0.8， 0.9， 0.5， 0.85， 0.2
		模型1：正样本score大于负样的对包括(y1, y4)(y1, y5)(y2, y4)(y2, y5)。所以AUC值为4 / 9
		模型2：正样本score大于负样本的对包括(y2, y4)(y2, y6)(y3, y4)(y3, y5)(y3, y6)。所以AUC的值为5 / 9
		所以模型2要比模型1好
		这种算法的复杂度为O(n ^ 2)其中n = (M + N)也就是样本的数量
		3. 方法3跟方法2是一样的，只不过做了一些处理减小了复杂度，首先按照score进行排序，得分最大的为n，第二大的为n - 1，依次类推，最小一个即为1，那么AUC的计算方法为：AUC = ((正样本的排序之和)-m*(m + 1) / 2) / (M*N)。
		看公式有点抽象，用上面的例子解释一下
		模型1：首先对预测的score进行排序，排序后的样本为：负（6），正（5），正（4），负（3），负（2），正（1）
		AUC的值为：(（5 + 4 + 1） - 3 * （3 + 1） / 2) / (3 * 3) = 4 / 9。可以看到跟方法二的计算结果一致，我们看一下这个计算公式，首先分子上后面的部分M*（M + 1） / 2。是不是很熟悉，小学就知道，上底加下底括号起来除以2，既是求梯形的面积公式，也是求连续值的公式，例如1 + 2 + 3 + 4。在这里指的就是所有的正样本的得分都小于所有的负样本的得分的情况下，计算出来的值。前半部分指的是实际的情况下正样本的排序。应该比较好理解了吧*/
	inline Float auc(vector<std::tuple<int, Float, Float> >& results, bool needSort = true)
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
		Float oldOut = std::numeric_limits<Float>::infinity();
		Float result = 0;

		for (auto& item : results)
		{
			int label = std::get<0>(item);
			Float output = std::get<1>(item);
			Float weight = std::get<2>(item);
			//Pval3(label, output, weight);
			if (output != oldOut) //存在相同值得情况是特殊处理的
			{
				result += 0.5 * (oldTruePos + truePos) * (falsePos - oldFalsePos);
				//Pval((0.5 * (oldTruePos + truePos) * (falsePos - oldFalsePos)));
				//Pval4(oldTruePos, truePos, oldFalsePos, falsePos);
				oldOut = output;
				oldFalsePos = falsePos;
				oldTruePos = truePos;
			}
			if (label > 0)
				truePos += weight;
			else
				falsePos += weight;
		}
		//Pval((0.5 * (oldTruePos + truePos) * (falsePos - oldFalsePos)));
		result += 0.5 * (oldTruePos + truePos) * (falsePos - oldFalsePos);
		Float AUC = result / (truePos * falsePos);
		return AUC;
	}


	//-----------------below depreciated
	class BinaryClassificationEvaluator
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

	typedef shared_ptr<BinaryClassificationEvaluator> BinaryClassficationEvaluatorPtr;
	class AucEvaluator : public BinaryClassificationEvaluator
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
