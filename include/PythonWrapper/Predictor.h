/**
 *  ==============================================================================
 *
 *          \file   PythonWrapper/Predictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-24 22:25:17.751698
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PYTHON_WRAPPER__PREDICTOR_H_
#define PYTHON_WRAPPER__PREDICTOR_H_
#include "common_def.h"
#include "Numeric/Vector/Vector.h"
namespace gezi {
	namespace py {
		class Predictor
		{
		public:
			//---------basic function
			Float Output(Vector& features);
			Float Predict(Vector& features);
			Float Predict(Vector& features, Float& output);
			void Normalize(Vector& features);

			//--------can save json for debug
			void SaveJson(string file);
			void SaveJson();
		public:
			void* _predictor;
		};
	}
}  //----end of namespace gezi

#endif  //----end of PYTHON_WRAPPER__PREDICTOR_H_
