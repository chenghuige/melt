/**
 *  ==============================================================================
 *
 *          \file   BinNormalizer.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-16 18:25:43.413195
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef BIN_NORMALIZER_CPP_
#define BIN_NORMALIZER_CPP_
#include "Prediction/Normalization/BinNormalizer.h"

DEFINE_int32(maxbins, 1000, "Maximum number of distinct values (bins) per feature");
namespace gezi {

void BinNormalizer::ParseArgs()  
{
	maxBins = FLAGS_maxbins;
};

}  //----end of namespace gezi

#endif  //----end of BIN_NORMALIZER_CPP_
