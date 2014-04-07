/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/NormalizerFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-02 10:28:30.961808
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__NORMALIZER_FACTORY_H_
#define PREDICTION__NORMALIZATION__NORMALIZER_FACTORY_H_

#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Normalization/MinMaxNormalizer.h"
#include "Prediction/Normalization/GaussianNormalizer.h"
#include "Prediction/Normalization/BinNormalizer.h"
namespace gezi {
	class NormalizerFactory
	{
	public:
		static NormalizerPtr CreateNormalizer(const string& name_)
		{
			string name = boost::to_lower_copy(name_);
			if (name == "minmax")
			{
				return make_shared<MinMaxNormalizer>();
			}
			if (name == "gaussian")
			{
				return make_shared<GaussianNormalizer>();
			}
			if (name == "bin")
			{
				return make_shared<BinNormalizer>();
			}
			LOG(WARNING) << name_ << " is not supported now, do not use normalzier, return null";
			return nullptr;
		}
		
		static NormalizerPtr CreateNormalizer(const string& name, const string& normalizerFile)
		{
			NormalizerPtr normalizer = CreateNormalizer(name);
			if (normalizer != nullptr)
			{
				normalizer->Load(normalizerFile);
			}
			return normalizer;
		}

	protected:
	private:

	};

} //end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_FACTORY_H_
