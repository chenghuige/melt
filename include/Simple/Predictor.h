/**
 *  ==============================================================================
 *
 *          \file   Simple/Predictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-26 09:32:30.332895
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef SIMPLE__PREDICTOR_H_
#define SIMPLE__PREDICTOR_H_

#include <vector>
#include <utility>
namespace gezi {
	namespace simple {
		/*注意输入都不是const,输入的vector会被改变*/
		class Predictor
		{
		public:

			//----------------输入向量稠密表示,推荐,一般速度会更快(如gbdt预测)
			//输出回归实数值
			double Output(std::vector<double>& values);
			//输出[0-1]范围的概率值
			double Predict(std::vector<double>& values);
			//output返回回归实数值，函数返回[0-1]概率值
			double Predict(std::vector<double>& values, double& output);

			//----------------输入向量稠密表示
			double Output(std::vector<int>& indices, std::vector<double>& values);
			double Predict(std::vector<int>& indices, std::vector<double>& values);
			double Predict(std::vector<int>& indices, std::vector<double>& values, double& output);

		private:
			void* _predictor;
		};
	}
}  //----end of namespace gezi

#endif  //----end of SIMPLE__PREDICTOR_H_
