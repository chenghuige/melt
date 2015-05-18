/**
 *  ==============================================================================
 *
 *          \file   Simple/PredictorFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-26 09:32:58.616068
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef SIMPLE__PREDICTOR_FACTORY_H_
#define SIMPLE__PREDICTOR_FACTORY_H_
#include <string>
#include "Simple/Predictor.h"

namespace gezi {
	namespace simple {
		class PredictorFactory
		{
		public:
			static Predictor LoadPredictor(std::string path);
		};
	}
}  //----end of namespace gezi

#endif  //----end of SIMPLE__PREDICTOR_FACTORY_H_
