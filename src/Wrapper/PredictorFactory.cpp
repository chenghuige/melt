/**
 *  ==============================================================================
 *
 *          \file   PredictorFactory.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-15 12:08:55.314134
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTOR_FACTORY_CPP_
#define PREDICTOR_FACTORY_CPP_
#include "common_util.h"
#include "Wrapper/PredictorFactory.h"
DEFINE_string(model_dir, "", "首个模型dir 如果不为空则覆盖conf中配置");
namespace gezi {
	namespace wrapper {

		//Predictors PredictorFactory::LoadPredictors()
		//{
		//	gezi::PredictorFactory::LoadPredictor("./model.fastrank");
		//	Predictors predictors;
		//	if (!FLAGS_model_dir.empty())
		//	{
		//		predictors.push_back(gezi::PredictorFactory::LoadPredictor(FLAGS_model_dir));
		//		return predictors;
		//	}
		//	string section = "Predictor";
		//	int model_cnt = 1;
		//	SCONF(model_cnt);
		//	for (int i = 0; i < model_cnt; i++)
		//	{
		//		string name = (format("model_%d_dir") % i).str();
		//		string modelDir;
		//		gezi::set_val(gezi::SharedConf::conf(), section, gezi::conf_trim(name), modelDir);
		//		//predictors.push_back(gezi::PredictorFactory::LoadPredictor(modelDir));
		//		gezi::PredictorFactory::LoadPredictor(modelDir);
		//	}
		//	return predictors;
		//}

	}  //----end of namespace wrapper
}  //----end of namespace gezi

#endif  //----end of PREDICTOR_FACTORY_CPP_
