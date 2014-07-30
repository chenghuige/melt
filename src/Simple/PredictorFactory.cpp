/**
 *  ==============================================================================
 *
 *          \file   PredictorFactory.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-26 09:34:14.603965
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTOR_FACTORY_CPP_
#define PREDICTOR_FACTORY_CPP_

#include "Simple/PredictorFactory.h"
#include "MLCore/PredictorFactory.h"
#include "MLCore/Predictor.h"
namespace gezi {
	namespace simple {
		vector<PredictorPtr> _predictors;
		Predictor PredictorFactory::LoadPredictor(std::string path)
		{
			_predictors.push_back(gezi::PredictorFactory::LoadPredictor(path));
			Predictor predictor;
			predictor._predictor = _predictors.back().get();
			return predictor;
		} //@FIXME 为什么这里面需要vector来hold指针,如果直接内部一个shared ptr为甚返回的predictor会访问内部_predictor无效 已经被释放了呢 但是貌似直接输入参数引用的话ok,参考gezi test下面的test_shared_ptr.cc最后的用法,按说那个也是用普通指针去接的.get
	}
}  //----end of namespace gezi

#endif
