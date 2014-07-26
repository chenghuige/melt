/**
 *  ==============================================================================
 *
 *          \file   PythonWrapper/PredictorFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-24 22:25:31.316432
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PYTHON_WRAPPER__PREDICTOR_FACTORY_H_
#define PYTHON_WRAPPER__PREDICTOR_FACTORY_H_
#include "PythonWrapper/Predictor.h"
namespace gezi {
	namespace py {
		class PyPredictorFactory
		{
		public:
			static PyPredictor LoadPredictor(string path);
		};
	}
}  //----end of namespace gezi

#endif  //----end of PYTHON_WRAPPER__PREDICTOR_FACTORY_H_
