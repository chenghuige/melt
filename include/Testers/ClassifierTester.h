/**
 *  ==============================================================================
 *
 *          \file   Testers/ClassifierTester.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-12 08:45:25.878259
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TESTERS__CLASSIFIER_TESTER_H_
#define TESTERS__CLASSIFIER_TESTER_H_

#include "Testers/Tester.h"

namespace gezi {


	class ClassificationPrecisionRecall : public DatasetMetrics
	{
	public:
		virtual string LabelColumnName() override
		{
			return "True";
		}
		virtual vector<string> PerInstanceColumnNames()
		{
			return vector<string>({ "Assigned", "Output", "Probability", "Log-loss" });
		}

		virtual dvec ProcessInstance(InstancePtr instance, PredictorPtr predictor) override
		{
			vector<double> results(4, std::numeric_limits<double>::quiet_NaN());

			double label = instance->label;
			double weight = instance->weight;
			double prediction, probability;
			probability = predictor->Predict(instance, prediction);

			if (std::isnan(label))
			{
				numUnlabeledInstances++;
				return results;
			}

			if (std::isnan(prediction))
				return results;

			if (label > 0)
			{
				if (prediction > 0)
					numTruePos += weight;
				else
					numFalseNeg += weight;
			}
			else
			{
				if (prediction <= 0)
					numTrueNeg += weight;
				else
					numFalsePos += weight;
			}
			results[0] = (prediction > 0 ? 1 : 0);
			results[1] = prediction;

			double currLogLoss;

			if (!std::isnan(probability))
			{
				if (label > 0)
				{
					currLogLoss = useLn ? -log(probability) : -log(probability) / log(2);
					numLogLossPositives += weight;
				}
				else
				{
					currLogLoss = useLn ? -log(1.0 - probability) : -log(1.0 - probability) / log(2);
					numLogLossNegatives += weight;
				}
			}
			else
			{
				currLogLoss = std::numeric_limits<double>::quiet_NaN();
			}

			if (currLogLoss > logTolerance || std::isinf(currLogLoss))
				currLogLoss = logTolerance;
			logLoss += currLogLoss * weight;

			results[2] = probability;
			results[3] = currLogLoss;
			return results;
		}

	protected:
		virtual void Finish() override
		{
			double accuracy = (numTrueNeg + numTruePos) / (numTruePos + numTrueNeg + numFalseNeg + numFalsePos);
			double recallPos = (numTruePos + numFalseNeg > 0)
				? numTruePos / (numTruePos + numFalseNeg) : 0;
			double precisionPos = (numTruePos + numFalsePos > 0)
				? numTruePos / (numTruePos + numFalsePos) : 0;
			double recallNeg = (numTrueNeg + numFalsePos > 0)
				? numTrueNeg / (numTrueNeg + numFalsePos) : 0;
			double precisionNeg = (numTrueNeg + numFalseNeg > 0)
				? numTrueNeg / (numTrueNeg + numFalseNeg) : 0;

			double logLossReduction = 0;
			if (numLogLossPositives + numLogLossNegatives > 0)
			{
				logLoss = logLoss / (numLogLossPositives + numLogLossNegatives);

				double priorPos = numLogLossPositives / (numLogLossPositives + numLogLossNegatives);
				priorLogLoss = PredictionUtil.Entropy(priorPos, useLn);
				logLossReduction = 100 * (priorLogLoss - logLoss) / priorLogLoss;
			}
		}

		virtual void Print_() override
		{
			Finish();

		}

	protected:
		double numTruePos = 0, numFalsePos = 0, numTrueNeg = 0, numFalseNeg = 0;
		int64 numUnlabeledInstances = 0;
		double logLoss = 0, priorLogLoss = 0;
		// need to keep separate in case NaNs in probability
		double numLogLossPositives, numLogLossNegatives;
		double trainPrior = -1;

		bool useLn = false;

		//// cutoff for log-loss tolerances (to prevent infinite loss)
		//[Argument(ArgumentType.AtMostOnce, HelpText = "Confidence threshold (log-loss limit)", ShortName = "logtol", DefaultValue = 30.0)]
		//public Double logTolerance = 30.0;
		double logTolerance = 30.0;

		double accuracy, precisionPos, recallPos, precisionNeg, recallNeg, logLoss, logLossReduction;
	};

	class ClassificationAUC : public DatasetMetrics
	{
	public:
		virtual string LabelColumnName() override
		{
			return "True";
		}
		virtual vector<string> PerInstanceColumnNames()
		{
			//return vector<string>({ "Test", "Haha"});
			return vector<string>();
		}
	};


	class ClassifierTester : public Tester
	{
	public:
		virtual PredictionKind GetPredictionKind()
		{
			return PredictionKind::BinaryClassification;
		}
		virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics()
		{
			return vector<DatasetMetricsPtr>({
				make_shared<ClassificationPrecisionRecall>(),
				make_shared<ClassificationAUC>()
			});
		}
	protected:
	private:

	};

}  //----end of namespace gezi

#endif  //----end of TESTERS__CLASSIFIER_TESTER_H_
