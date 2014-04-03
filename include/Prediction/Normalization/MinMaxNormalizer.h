/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/MinMaxNormalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-02 10:30:54.515916
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_

#include "Prediction/Normalization/AffineNormalizer.h"
namespace gezi {

	class MinMaxNormalizer : public AffineNormalizer
	{
	public:
		virtual void Process(const Vector& vec)
		{
			if (_isFirst)
			{
				_counts.resize(_featureNum, 1);
				vec.ForEachAll([this](int i, Float value)
				{
					_offsets[i] = value;
					_scales[i] = value;
				});
				_isFirst = false;
			}
			else
			{ //set lower and upper bound for each i
				///理论上只有比如 -13 0  0  0 后面都是 0 或者都是 -5 -4 -3 这样 那么最大值没有取到实际的 0
				//或者比如 3 4 5 ... 最小值没有取到实际的 0  貌似TLC这个地方有问题 没有特殊处理？
				vec.ForEach([this](int i, Float value)
				{
					_counts[i]++;
					this->SetOffsetScale(i, value); //need this->
				});
				_total++;
			}
		}

		//@TODO lambda里面再调用这个不行 那么直接把这个类成员函数 传给ForEach?
		void SetOffsetScale(int i, Float value)
		{
			if (value < _offsets[i])
			{
				_offsets[i] = value;
			}
			if (value > _scales[i])
			{
				_scales[i] = value;
			}
		}

		virtual void Finalize()
		{
			for (size_t i = 0; i < _featureNum; i++)
			{
				if (_counts[i] != _total)
				{ //这个特征在prepare的所有instance中 存在0值, TLC没有做这个 应该是bug 部分归一后没有到[0,1]可能
			/*		if (0 < _offsets[i] || 0 > _scales[i])
					{
						Pval5(i, _offsets[i], _scales[i], _counts[i], _total);
					}*/
					SetOffsetScale(i, 0);
				}
				_scales[i] -= _offsets[i];
			}
			CheckOffsetAndScale();
		}
	protected:
	private:
		bool _isFirst = true;
		vector<uint64> _counts;
		uint64 _total = 1;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
