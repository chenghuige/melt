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
			_func = [this](int index, Float value)
			{
				if (_scales[index] <= 0)
				{
					return value;
				}

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
				return value;
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

		virtual void NormalizeCore(Vector& vec) override
		{
			Normalize(vec, _func);
		}

	protected:
		Fvec _offsets;
		Fvec _scales;
	private:
		std::function<Float(int,Float)> _func;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
