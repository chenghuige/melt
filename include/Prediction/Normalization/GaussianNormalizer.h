/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/GaussianNormalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 17:08:29.526873
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__GAUSSIAN_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__GAUSSIAN_NORMALIZER_H_

#include "Prediction/Normalization/AffineNormalizer.h"
namespace gezi {

/// A normalizer that just scales each feature to 0-1 interval. 
class GaussianNormalizer : public AffineNormalizer
{
public:
	GaussianNormalizer() = default;

	GaussianNormalizer(string infile)
	{//通过文本载入Normalzier
		AffineNormalizer::Load(infile); //@FIXME构造函数调用虚函数? 
	}

	virtual string Name() override
	{
		return "GaussianNormalizer";
	}

	virtual void Process(const Vector& vec) override
	{
			vec.ForEach([this](int i, Float value)
			{
				_offsets[i] += value;
				_scales[i] += value * value;
				_counts[i]++;
			});
	}

	virtual void Begin() override
	{
		AffineNormalizer::Begin();
		_counts.resize(_numFeatures, 0);
	}

	virtual void Finish() override
	{
		for (int i = 0; i < _numFeatures; i++)
		{
			if (_counts[i] == 0)
				continue;
			_offsets[i] /= _counts[i];
			_scales[i] = sqrt(_scales[i] / _counts[i] - _offsets[i] * _offsets[i]);
		}
		
		AffineInit();
		_counts.clear();
	}

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<Normalizer>(*this);
		ar & boost::serialization::base_object<AffineNormalizer>(*this);
	}

protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__GAUSSIAN_NORMALIZER_H_
