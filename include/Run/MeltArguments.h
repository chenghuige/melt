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
		string fullArguments;
		//c|Options are: Train, Test, CV (cross validation), TrainTest, FeatureSelection, CreateInstances
		string command = "cv"; //c|
		string commandInput = ""; //ci|
		string classifierName = "LinearSvm";//cl|
		string classifierSettings = ""; //cls|
		size_t num = 0;
		int numFolds = 5;
		int numRuns = 1;
		int numThreads = 0;
		bool useThreadsCV = true;
		unsigned randSeed = 0;
		string datafile = "";
		string outfile = ""; //o| specify the output file
		bool saveOutputFile = true; //sf| save the output file
		string normalizerfile = ""; //nf| normalzier output file
		string testDatafile = ""; //test| Data file used for test
		string validationDatafile = "";
		string modelFolder = "model"; //m|
		bool modelfile = false; //mf|
		bool modelfileCode = false; //mc|
		string codeType = "c"; //
		bool modelfileText = false; //mt|
		bool modelfileXml = false; //mxml|
		bool modelfileJson = false; //mjson|
		bool modelfileFeature = false; //mfeature| feature info, usually means feature importance
		bool saveNormalizerText = false; //snt|
		bool saveCalibratorText = false; //sct|
		string featureName = ""; //fn|
		bool stratify = false;
		bool foldsSequential = false;
		double trainProportion = 1.0;

		bool selfTest = false; //st| when -c train will test the train data its self after training

		bool selfEvaluate = false; //se|when trainer is validatingTrainer, will self evaluate during training
		bool selfEvaluate2 = false;
		int evaluateFrequency = 1; //efreq|when trainer is validatingTrainer, will self evaluate every evaluateFrequency round
		double evaluateFraction = 0.0; //efrac|when trainer is ValidatingTrainer will split evaluateFraction instances to use as evaluation set

		bool earlyStop = false;
		int earlyStopCheckFrequency = 1;
		int earlyStopRounds = 10;
		bool earlyStopUseBestStage = false;

		string modelDir = "";
		string outDir = "";
		string resultDir = "./result";
		string resultFile = "";
		int resultIndex = 0;

		string evaluateScript = "";

		bool preNormalize = false;

		//----------分类器公用选项
		bool normalizeFeatures = true; //norm| Normalize features?
		string normalizerName = "MinMax"; //normalizer| Which normalizer?

		string calibratorName = "sigmoid"; //calibrator| Which calibrator?

		string evaluatorNames = ""; //evaluator|evaluators for ValidatingTrainers(Inside Trainer) or for CrsossValidation train, test.. 

		string inputFileFormat = "normal"; //if | input file format
		string outputFileFormat = "unknown";//of| output file format
	};
}  //----end of namespace gezi

#endif  //----end of RUN__MELT_ARGUMENTS_H_
