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
		static NormalizerPtr CreateNormalizer(string name)
		{
			boost::to_lower(name);
			if (name == "minmax" || name == "minmaxnormalizer")
			{
				return make_shared<MinMaxNormalizer>();
			}
			if (name == "gaussian" || name == "gaussiannormalizer")
			{
				return make_shared<GaussianNormalizer>();
			}
			if (name == "bin" || name = "binnormalizer")
			{
				return make_shared<BinNormalizer>();
			}
			LOG(WARNING) << name << " is not supported now, do not use normalzier, return nullptr";
			return nullptr;
		}
		
		static NormalizerPtr CreateNormalizer(string name, string path)
		{
			NormalizerPtr normalizer = CreateNormalizer(name);
			if (normalizer != nullptr)
			{
				normalizer->Load(path);
			}
			return normalizer;
		}

	protected:
	private:

	};

} //end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_FACTORY_H_
