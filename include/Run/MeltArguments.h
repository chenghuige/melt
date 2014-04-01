/**
 *  ==============================================================================
 *
 *          \file   Run/MeltArguments.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-31 09:02:40.483583
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef RUN__MELT_ARGUMENTS_H_
#define RUN__MELT_ARGUMENTS_H_
#include "common_util.h"
namespace gezi {

	struct MeltArguments
	{
		//c|Options are: Train, Test, CV (cross validation), TrainTest, FeatureSelection, CreateInstances
		string command = "cv"; 
		string classifierName = "LinearSvm";
		string classifierSettings = "";
		int numFolds = 5;
		int numRuns = 1;
		int numThreads = 0;
		int randSeed = 0;
		string datafile = "";
		string testDatafile = "";
		string validationDatafile = "";
		string modelfile = "";
		string modelfileCode = "";
		string modelfileText = "";
		bool stratify = false;
		bool foldsSequential = false;
		double trainProportion = 1.0;
	};
}  //----end of namespace gezi

#endif  //----end of RUN__MELT_ARGUMENTS_H_
