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

		static void GenMeanVarInfo(const Instances& instances, string outFile,  string outFile2,
			string featureName = "")
		{
			int featureNum = instances.FeatureNum();
			dvec means(featureNum, 0);
			dvec mins(featureNum, std::numeric_limits<double>::max());
			dvec maxes(featureNum, std::numeric_limits<double>::min());
			dvec posMeans(featureNum, 0);
			dvec negMeans(featureNum, 0);
			dvec posMins(featureNum, std::numeric_limits<double>::max());
			dvec negMins(featureNum, std::numeric_limits<double>::max());
			dvec posMaxes(featureNum, std::numeric_limits<double>::min());
			dvec negMaxes(featureNum, std::numeric_limits<double>::min());
			dvec vars(featureNum, 0);
			dvec posVars(featureNum, 0);
			dvec negVars(featureNum, 0);

			uint64 instanceNum = instances.Count();
			uint64 posNum = 0, negNum = 0;
			{
				ProgressBar pb(instanceNum);
				for (uint64 i = 0; i < instanceNum; i++)
				{
					++pb;
					const InstancePtr& instance = instances[i];
					if (instance->IsPositive())
					{
						instance->features.ForEach([&](int index, double value)
						{
							double val2 = pow(value, 2);
							means[index] += value;
							vars[index] += val2;
							posMeans[index] += value;
							posVars[index] += val2;
							if (value > maxes[index])
							{
								maxes[index] = value;
							}
							if (value > posMaxes[index])
							{
								posMaxes[index] = value;
							}
							if (value < mins[index])
							{
								mins[index] = value;
							}
							if (value < posMins[index])
							{
								posMins[index] = value;
							}
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
							if (value > maxes[index])
							{
								maxes[index] = value;
							}
							if (value > negMaxes[index])
							{
								negMaxes[index] = value;
							}
							if (value < mins[index])
							{
								mins[index] = value;
							}
							if (value < negMins[index])
							{
								negMins[index] = value;
							}
						});
						negNum++;
					}
				}
			}
			MeanVar(means, vars, featureNum, instanceNum);
			MeanVar(posMeans, posVars, featureNum, posNum);
			MeanVar(negMeans, negVars, featureNum, negNum);

			//--------------------save result
			{
				LOG(INFO) << "Write result to " << outFile;
				ofstream ofs(outFile);
				LOG(INFO) << "Write csv result to " << outFile2;
				ofstream ofs2(outFile2);
				ofs << "FeatureName\tMean\tPosMean\tNegMean\tPosMin\tNegMin\tPosMax\tNegMax\tVar\tPosVar\tNegVar" << endl;
				ofs2 << "FeatureName\tMean\tPosMean\tNegMean\tPosMin\tNegMin\tPosMax\tNegMax\tVar\tPosVar\tNegVar" << endl;
				if (featureName.empty())
				{
					ProgressBar pb(featureNum);
					for (int i = 0; i < featureNum; i++)
					{
						pb.progress(i);
						if (gezi::are_same(mins[i], maxes[i]))
						{
							if (VLOG_IS_ON(1))
							{
								fmt::print_colored(fmt::RED, "{}:{} is always taking value: {} - {}\n", i, instances.FeatureNames()[i], mins[i], maxes[i]);
							}
						}
						ofs << instances.FeatureNames()[i] << "\t"
							<< "mean:" << means[i] << "\t"
							<< "min:" << mins[i] << "\t"
							<< "max:" << maxes[i] << "\t"
							<< "posMean:" << posMeans[i] << "\t"
							<< "negMean:" << negMeans[i] << "\t"
							<< "posMin:" << posMins[i] << "\t"
							<< "negMin:" << negMins[i] << "\t"
							<< "posMax:" << posMaxes[i] << "\t"
							<< "negMax:" << negMaxes[i] << "\t"
							<< "var:" << vars[i] << "\t"
							<< "posVar:" << posVars[i] << "\t"
							<< "negVar:" << negVars[i] << "\t"
							<< endl;

						ofs2 << instances.FeatureNames()[i] << "\t" << means[i] << "\t" << maxes[i] << "\t"
							<< posMeans[i] << "\t" << negMeans[i] << "\t" << posMins[i] << "\t" << negMins[i] << "\t"
							<< posMaxes[i] << "\t" << negMaxes[i] << "\t" << vars[i] << "\t" << posVars[i] << "\t" << negVars[i]
							<< "\t" << endl;
					}
				}
				else
				{
					for (int i = 0; i < featureNum; i++)
					{
						if (instances.FeatureNames()[i] == featureName)
						{
							std::cout << "FeatureName\tMean\tPosMean\tNegMean\tVar\tPosVar\tNegVar" << endl;
							std::cout << instances.FeatureNames()[i] << "\t"
								<< "mean:" << means[i] << "\t"
								<< "min:" << mins[i] << "\t"
								<< "max:" << maxes[i] << "\t"
								<< "posMean:" << posMeans[i] << "\t"
								<< "negMean:" << negMeans[i] << "\t"
								<< "posMin:" << posMins[i] << "\t"
								<< "negMin:" << negMins[i] << "\t"
								<< "posMax:" << posMaxes[i] << "\t"
								<< "negMax:" << negMaxes[i] << "\t"
								<< "var:" << vars[i] << "\t"
								<< "posVar:" << posVars[i] << "\t"
								<< "negVar:" << negVars[i] << "\t"
								<< endl;
							return;
						}
					}
					LOG(WARNING) << "Not find feature name: " << featureName;
				}
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
