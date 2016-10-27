/**
 *  ==============================================================================
 *
 *          \file   MLCore/PredictorFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-10 08:04:52.394292
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__PREDICTOR_FACTORY_H_
#define PREDICTORS__PREDICTOR_FACTORY_H_

#include "common_util.h"
#include "MLCore/Predictor.h"

namespace gezi {

  class PredictorFactory
  {
  public:
    static PredictorPtr CreatePredictor(string name);
    static PredictorPtr CreatePredictor(string name, string path);
    //Mostly used
    static PredictorPtr LoadPredictor(string path, string modelName = "", bool isText = false, bool useCustomModel = false);
    //主要用于线性分类器 用于接受其他外部分类器的结果转换为melt接受的文本格式后载入
    static PredictorPtr CreatePredictorFromTextFormat(string name, string path);
    static PredictorPtr LoadTextPredictor(string path, string modelName = "");
    static Predictors LoadPredictors(const svec& paths);

  protected:
  private:

  };

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__PREDICTOR_FACTORY_H_
