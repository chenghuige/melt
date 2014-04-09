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
		string classifierName = "LinearSvm";//cl|
		string classifierSettings = ""; //cls|
		int numFolds = 5;
		int numRuns = 1;
		int numThreads = 0;
		int randSeed = 0;
		string datafile = "";
		string outfile = ""; //o|specify the output file
		string normalizerfile = ""; //nf|normalzier output file
		string testDatafile = ""; //test|Data file used for test
		string validationDatafile = "";
		string modelfile = "";
		string modelfileCode = "";
		string modelfileText = "";
		string featureName = ""; //fn|
		bool stratify = false;
		bool foldsSequential = false;
		double trainProportion = 1.0;

		string modelDir = "";
		string outDir = "";
		string resultDir = "./result";
		int resultIndex = 0;

		//----------分类器公用选项
		bool normalizeFeatures = true; //norm:Normalize features?
		string normalizerName = "MinMax"; //Which normalizer?
	};
}  //----end of namespace gezi

#endif  //----end of RUN__MELT_ARGUMENTS_H_
