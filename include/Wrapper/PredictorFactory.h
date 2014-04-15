/**
 *  ==============================================================================
 *
 *          \file   Wrapper/PredictorFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-15 11:51:55.436143
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef WRAPPER__PREDICTOR_FACTORY_H_
#define WRAPPER__PREDICTOR_FACTORY_H_
#include "Predictors/PredictorFactory.h"
namespace gezi {
	namespace wrapper {
		//输入的路径都在shared conf 中配置
		class PredictorFactory
		{
		public:
			static Predictors LoadPredictors();
		protected:
		private:

		};

	}  //----end of namespace wrapper
}  //----end of namespace gezi

#endif  //----end of WRAPPER__PREDICTOR_FACTORY_H_
