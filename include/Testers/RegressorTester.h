/**
 *  ==============================================================================
 *
 *          \file   Testers/RegressorTester.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-12 08:46:15.842250
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TESTERS__REGRESSOR_TESTER_H_
#define TESTERS__REGRESSOR_TESTER_H_
#include "Tester.h"
namespace gezi {
	class RegressionMetrics : public DatasetMetrics
	{
	public:
		virtual vector<string> PerInstanceColumnNames() override
		{
			return vector<string>({ "Predicted", "L1-loss", "L2-loss" });
		}

		virtual vector<string> Names() override
		{
			return vector<string>({"L1(avg)", "L2(avg)", "RMS(avg)"});
		}
		/// <summary>
		/// Process an instance and aggregate metrics
		/// </summary>
		virtual Fvec ProcessInstance(Float label, Float prediction, Float probability, Float weight) override
		{
			vector<Float> results(3, std::numeric_limits<Float>::quiet_NaN());
			if (std::isnan(label))
			{
				return results;
			}
			
			sumWeights += weight;
			Float currL1Loss = std::abs(label - prediction);
			totalL1Loss += currL1Loss * weight;
			totalL2Loss += currL1Loss * currL1Loss * weight;

			results[0] = prediction;
			results[1] = currL1Loss;
			results[2] = currL1Loss * currL1Loss;
			return results;
		}
		
		virtual void Finish() override
		{
			_results = Fvec{
				sumWeights > 0 ? totalL1Loss / sumWeights : 0,
				sumWeights > 0 ? totalL2Loss / sumWeights : 0,
				sumWeights > 0 ? std::sqrt(totalL2Loss / sumWeights) : 0,
			};
		}
		
	private:
		Float sumWeights = 0;
		Float totalL1Loss = 0, totalL2Loss = 0;
	};

	class RegressorTester : public Tester
	{
	public:
		virtual PredictionKind GetPredictionKind()
		{
			return PredictionKind::Regression;
		}

		virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics()
		{
			return vector<DatasetMetricsPtr>({ make_shared<RegressionMetrics>() });
		}
	protected:
	private:

	};

}  //----end of namespace gezi

#endif  //----end of TESTERS__REGRESSOR_TESTER_H_
