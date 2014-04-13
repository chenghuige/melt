/**
 *  ==============================================================================
 *
 *          \file   Trainers/FastRank/RegressionTree.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-10 12:07:25.902949
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TRAINERS_FASTRANK__REGRESSION_TREE_H_
#define TRAINERS_FASTRANK__REGRESSION_TREE_H_
#include "common_util.h"
namespace gezi {
	//只是读入 通过TLC文本文件
	class RegressionTree
	{
	public:
		~RegressionTree() = default;
		RegressionTree(RegressionTree&&) = default;
		RegressionTree& operator = (RegressionTree&&) = default;
		RegressionTree(const RegressionTree&) = default;
		RegressionTree& operator = (const RegressionTree&) = default;

		RegressionTree(svec& featureNames)
			:_featureNames(featureNames)
		{

		}

	public:

		//输入特征 遍历树 输出叶子节点的数值
		Float GetOutput(const Vector& features) const
		{
			int node = 0;
			svec paths;
			while (node >= 0)
			{
				if (features[_splitFeature[node]] <= _threshold[node])
				{
#ifdef _DEBUG
					paths.push_back(_featureNames[_splitFeature[node]] + " " +
						STR(features[_splitFeature[node]]) + " <= " + STR(_threshold[node]));
#endif // _DEBUG
					node = _lteChild[node];
				}
				else
				{
#ifdef _DEBUG
					paths.push_back(_featureNames[_splitFeature[node]] + " " +
						STR(features[_splitFeature[node]]) + " > " + STR(_threshold[node]));
#endif // _DEBUG
					node = _gtChild[node];
				}
			}
#ifdef _DEBUG
			if (_leafValue[~node] > 0)
			{
				PVEC(paths);
				Pval_(_leafValue[~node], "PositiveOutput:");
			}
#endif // _DEBUG
			return _leafValue[~node];
		}

	protected:
	private:
	public:
		dvec _gainPValue;
		ivec _gtChild;
		dvec _leafValue;
		ivec _lteChild;
		double _maxOutput = 0;
		int _numLeaves = 1;
		dvec _previousLeafValue;
		ivec _splitFeature;
		dvec _splitGain;
		dvec _threshold;
		double _weight = 1.0;
		svec& _featureNames;
	};

}  //----end of namespace gezi

#endif  //----end of TRAINERS_FASTRANK__REGRESSION_TREE_H_
