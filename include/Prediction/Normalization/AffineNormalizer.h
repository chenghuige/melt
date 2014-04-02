/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/AffineNormalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 17:07:57.638996
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
#include "Prediction/Normalization/Normalizer.h"
namespace gezi {

	class AffineNormalizer : public Normalizer
	{
	public:
		AffineNormalizer()
		{
			_func = [this](int index, Float& value)
			{
				/*	if (_scales[index] <= 0)
					{
					value = 0;
					}
					else if (_trunct)*/
				if (_trunct)
				{
					if (value >= _offsets[index] + _scales[index])
						value = _upper;
					else if (value <= _offsets[index])
						value = _lower;
					else
						value = _lower + _range * (value - _offsets[index]) / _scales[index];
				}
				else
				{
					value = _lower + _range * (value - _offsets[index]) / _scales[index];
				}
			};
		}

		virtual void Begin() override
		{
			_offsets.resize(_featureNum, 0);
			_scales.resize(_featureNum, 0);
		}

		virtual void Finalize() override
		{

		}

		void CheckOffsetScale()
		{
			for (int i = 0; i < _numFeatures; i++)
			{
				if (_scales[i] <= 0)
				{ //按照TLC 如果是始终值一样 仍然维持原样 不scale 不置为0 @TODO
					//无效特征 始终是6的比如 还是6 不变成0 @TODO 需要置为0？
					LOG(WARNING) << "Feature " << i << " : " << _featureNames[i]
						<< " always take value " << _offsets[i];
				}
				else if (_offsets[i] != _lower || _scales[i] != _upper)
				{ //like [0,1] range will not need to transform
					_scaleIndices.push_back(i);
				}
				else if (_trunct)
				{ //如果要截断即使[0,1]也需要scale可能， 注意只可能会是在线部分用trunct 离线test部分？@TODO only test trunct ?
					_scaleIndices.push_back(i);
				}
			}
		}

		virtual void NormalizeCore(Vector& vec) override
		{
			Normalize(vec, _func);
		}

	protected:
		Fvec _offsets;
		Fvec _scales;
	private:
		std::function<Float(int, Float)> _func;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
