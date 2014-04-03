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
			vec.ForEachAll([this](int index, Float value)
			{
				_offsets[index] = value;
				_scales[index] = value;
			});
			_isFirst = false;
		}
		else
		{ //set lower and upper bound for each index
			/*	vec.ForEachAll([this](int index, Float value)
				{
				if (value < _offsets[index])
				{
				_offsets[index] = value;
				}
				if (value > _scales[index])
				{
				_scales[index] = value;
				}
				});*/

			////理论上 上面这个正确 下面这个可能存在问题同TLC 比如 -13 0 但是速度原因 选择下面 
			//理论上只有比如 -13 0  0  0 后面都是 0 或者都是 -5 -4 -3 这样 那么最大值没有取到实际的 0
			// -13 -12 0
			//可能性很小文本分类中不会存在 其他即时存在也影响很小 另外生成特征时候尽量用[0-n)的范围
			vec.ForEach([this](int index, Float value)
			{
				if (value < _offsets[index])
				{
					_offsets[index] = value;
				}
				if (value > _scales[index])
				{
					_scales[index] = value;
				}
			});
		}
	}

	virtual void Finalize()
	{
		for (size_t i = 0; i < _featureNum; i++)
		{
			_scales[i] -= _offsets[i];
		}
		CheckOffsetScale();
	}
protected:
private:
	bool _isFirst = true;
	
};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
