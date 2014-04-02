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
			vec.ForEachAll([this](int index, Float value)
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
			CheckOffsetScale();
		}
	}
protected:
private:
	bool _isFirst = true;
	
};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
