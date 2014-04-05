/**
 *  ==============================================================================
 *
 *          \file   Utils/FeatureStatus.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-04 15:37:08.135276
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TOOLS__FEATURE_STATUS_H_
#define TOOLS__FEATURE_STATUS_H_

#include "common_util.h"
#include "Prediction/Instances/Instances.h"

namespace gezi {

	class FeatureStatus
	{
	public:
		static void GenMeanVarInfo(const Instances& instances, const string outFile)
		{
			int featureNum = instances.FeatureNum();
			dvec means(featureNum, 0);
			dvec vars(featureNum, 0);

			dvec posMeans(featureNum, 0);
			dvec posVars(featureNum, 0);

			dvec negMeans(featureNum, 0);
			dvec negVars(featureNum, 0);

			uint64 instanceNum = instances.Count();
			uint64 posNum = 0, negNum = 0;

			ProgressBar pb(instanceNum);
//#pragma omp parallel for
			for (uint64 i = 0; i < instanceNum; i++)
			{
				pb.progress(i);
				InstancePtr& instance = instances[i];
				if (instance->IsPositive())
				{
					instance->features.ForEach([&](int index, double value)
					{
						double val2 = pow(value, 2);
						means[index] += value;
						vars[index] += val2;
						posMeans[index] += value;
						posVars[index] += val2;
					});
					posNum++;
				}
				else
				{
					instance->features.ForEach([&](int index, double value)
					{
						double val2 = pow(value, 2);
						means[index] += value;
						vars[index] += val2;
						negMeans[index] += value;
						negVars[index] += val2;
					});
					negNum++;
				}
			}
			MeanVar(means, vars, featureNum, instanceNum);
			MeanVar(posMeans, posVars, featureNum, posNum);
			MeanVar(negMeans, negVars, featureNum, negNum);

			//--------------------save result
			LOG(INFO) << "Write result to " << outFile;
			ofstream ofs(outFile);
			ofs << "FeatureName\tMean\tPosMean\tNegMean\tVar\tPosVar\tNegVar" << endl;
			for (int i = 0; i < featureNum; i++)
			{
				ofs << instances.FeatureNames()[i] << "\t"
					<< means[i] << "\t"
					<< posMeans[i] << "\t"
					<< negMeans[i] << "\t"
					<< vars[i] << "\t"
					<< posVars[i] << "\t"
					<< negVars[i] << "\t"
					<< endl;
			}
		}
	protected:
	private:
		static void MeanVar(dvec& means, dvec& vars, int featureNum, uint64 instanceNum)
		{
			for (int i = 0; i < featureNum; i++)
			{
				double x = means[i] / (instanceNum - 1) * means[i] / instanceNum;
				means[i] /= instanceNum;
				double y = vars[i] / (instanceNum - 1);
				vars[i] = y - x;
			}
		}
	};

}  //----end of namespace gezi

#endif  //----end of UTILS__FEATURE_STATUS_H_
