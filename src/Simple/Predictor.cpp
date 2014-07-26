/**
 *  ==============================================================================
 *
 *          \file   Predictor.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-26 09:34:06.790060
 *
 *  \Description:
 *  ==============================================================================
 */

#include "Simple/Predictor.h"
#include "MLCore/Predictor.h"
namespace gezi {
	namespace simple {
		double Predictor::Output(std::vector<double>& values)
		{
			return (static_cast<gezi::Predictor*>(_predictor))->Output(values);
		}

		double Predictor::Predict(std::vector<double>& values)
		{
			return  (static_cast<gezi::Predictor*>(_predictor))->Predict(values);
		}

		double Predictor::Predict(std::vector<double>& values, double& output)
		{
			return  (static_cast<gezi::Predictor*>(_predictor))->Predict(values, output);
		}

		double Predictor::Output(std::vector<double>& indices, std::vector<double>& values)
		{
			return (static_cast<gezi::Predictor*>(_predictor))->Output(indices, values);
		}

		double Predictor::Predict(std::vector<double>& indices, std::vector<double>& values)
		{
			return  (static_cast<gezi::Predictor*>(_predictor))->Predict(indices, values);
		}

		double Predictor::Predict(std::vector<double>& indices, std::vector<double>& values, double& output)
		{
			return  (static_cast<gezi::Predictor*>(_predictor))->Predict(indices, values, output);
		}
	}
}  //----end of namespace gezi