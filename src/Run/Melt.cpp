#define NO_BAIDU_DEP
#include "common_util.h"
#include "Run/Melt.h"

DEFINE_string(c, "cv", "command: Options are: Train, Test, CV (cross validation), TrainTest, FeatureSelection, CreateInstances, Norm, Check");
DEFINE_string(ci, "", "commandInput: Some commands need additional input like split data you need to iput like 1:1");
DEFINE_string(cl, "LinearSVM", "classifierName: Classifier to use");
DEFINE_string(cls, "", "classifierSettings: Classifier settings, this is now only used for third part classifers like sofia,vw,liblinear eg.<-cls -B=1,-s=5>");

//---------------cross validation 
DEFINE_int32(k, 5, "numFolds: Number of folds in k-fold cross-validation");
DEFINE_int32(nr, 1, "numRuns: numRuns: Number of runs of cross-validation");
DEFINE_bool(strat, false, "Stratify instances during cross-validation (instances with same name up to '|' get assigned to same fold");
DEFINE_bool(foldSeq, false, "foldSequence: instances sequentially during cross - validation");

//========== MODIFYING TRAIN/TEST DATA: learning curves, stratifying, skipping certain instances
//===============================================================================================
// learning curve experiments are done via trainProportion
DEFINE_double(tp, 1.0, "trainProportion: Fraction of training data to use (if < 1.0), or max training items");

DEFINE_uint64(rs, 0, "0 means random, 1 means can reproduce | randSeed: controls wether the expermient can reproduce");
DEFINE_int32(nt, 0, "num of threads, default 0 means use threads num according to processor num");
DEFINE_string(i, "", "datafile: Input data file used for train or cross validation, you can also put data file just after exe like: ./melt datafile");
DEFINE_string(o, "", "outfile: specified output file(not modelfile)");
DEFINE_bool(sof, true, "saveOutputFile: wehter save the outputfile");

DEFINE_string(test, "", "testDatafile: Data file used for test");
DEFINE_string(valid, "", "Data file used for training validation (with IValidatingPredictor classifiers)");

DEFINE_string(m, "model", "modelFolder");
DEFINE_bool(mf, false, " modelfile: Gen model file£¿ (for TrainTest)");
DEFINE_bool(mc, false, " modelfileCode: Gen model file to save in C++ code £¿ (for Train or TrainTest)");
DEFINE_string(codeType, "cpp", "Which language for modelfileCode ? default is cpp->model.cpp, or c->model.c or py for python -> model.py, php -> mode.php");
DEFINE_bool(mt, false, "modelfileText:  Gen model file to save in text format ? (for Train or TrainTest");
DEFINE_bool(mxml, false, "modelfileXml:  Gen model file to save in xml format ? (for Train or TrainTest");
DEFINE_bool(mjson, false, "modelfileJson:  Gen model file to save in json format ? (for Train or TrainTest");
DEFINE_bool(snt, false, "saveNormalizerText: wether save normalizer as text/xml/json");
DEFINE_bool(sct, false, "saveCalibratorText: wether save calibrator as text/xml/json");
DEFINE_bool(st, false, "selftTest: when -c train will test the train data its self after training");

DEFINE_string(rd, "./result", "resultDir: where to put the result data");
DEFINE_string(rf, "", "resultFile: not used in cross validation which use resultDir only, can be used in test or train-test, if set FLAGS_rf than will write result to resultFile instead of to resultDir/0.inst.txt or resultDir/n.inst.txt if you set Flags_ri");
DEFINE_int32(ri, 0, "resultIndex: the name ouf out file like 0.model.txt 0.model 0.inst.txt");

DEFINE_uint64(num, 0, "choose num instances or use as other number realted meaning");

DEFINE_bool(norm, true, "Normalize features");
DEFINE_string(normalizer, "MinMax", "Which normalizer? can also try gaussian or bin");

DEFINE_string(fn, "", "featureName:");
//@FIXME
//DEFINE_string(ev, "/home/users/chenghuige/rsc/app/search/sep/anti-spam/melt/tools3/evaluate/evaluate", "evaluate: use what to evalute the result, notice if not find this one will try to use local evaluate");
DEFINE_string(ev, "", "evaluate: use what to evalute the result like ~/tools/evaluate.py, notice if empty not find this one will try to use internal c++ evaluate, also this used for choosing interal evaluator like auc l1 l2..");
DEFINE_string(evaluator, "", "evaluatorName|which evaluator for cross validation only show one evaluator result | or evaluators for ValidatingTrainers");

DEFINE_bool(calibrate, true, "calibrateOutput: use calibrator to gen probability? if not will use logistice function which will map 0 to 0.5");
DEFINE_string(calibrator, "sigmoid", "calibratorName: sigmoid/platt naive pav");
DEFINE_uint64(numCali, 1000000, "maxCalibrationExamples: Number of instances to train the calibrator");
DEFINE_bool(pn, false, "preNormalize:if set true will normlize the whole data before cross validation start");

DEFINE_string(format, "unknow", "inputFileFormat: will not to set it for most cases will auto parse input file, like sparse(index starts 0), dense(index starts 0), libsvm(index starts 1), if other formats or sparse format without length info(like libsvm but index starts 0| like sparse but no length info) you must set -format sparse2 or -format sparse_no_length");
DEFINE_string(off, "unknown", "ouput_file_format: if unknow using it's input format");

DEFINE_bool(fast, false, "fast mode, will try fastest training, like calibrate = false");
DEFINE_bool(quiet, false, "quiet mode, will set vl= -1");

namespace gezi {
	void Melt::ParseArguments()
	{
		_cmd.command = FLAGS_c;
		_cmd.commandInput = FLAGS_ci;
		_cmd.classifierName = FLAGS_cl;
		_cmd.classifierSettings = FLAGS_cls;
		_cmd.datafile = FLAGS_i;
		_cmd.outfile = FLAGS_o;
		_cmd.outDir = FLAGS_o;
		_cmd.saveOutputFile = FLAGS_sof;
		_cmd.testDatafile = FLAGS_test;
		_cmd.validationDatafile = FLAGS_valid;
		_cmd.modelFolder = FLAGS_m;
		_cmd.modelfile = FLAGS_mf;
		_cmd.modelfileCode = FLAGS_mc;
		_cmd.codeType = FLAGS_codeType;
		_cmd.modelfileText = FLAGS_mt;
		_cmd.modelfileXml = FLAGS_mxml;
		_cmd.modelfileJson = FLAGS_mjson;

		_cmd.saveNormalizerText = FLAGS_snt;
		_cmd.saveCalibratorText = FLAGS_sct;

		_cmd.num = FLAGS_num;

		_cmd.numFolds = FLAGS_k;
		_cmd.numRuns = FLAGS_nr;

		_cmd.selfTest = FLAGS_st;

		if (FLAGS_rs == 0)
		{
			FLAGS_rs = random_seed();
		}
		_cmd.randSeed = FLAGS_rs;

		_cmd.stratify = FLAGS_strat;
		_cmd.numThreads = FLAGS_nt;
		_cmd.foldsSequential = FLAGS_foldSeq;
		_cmd.trainProportion = FLAGS_tp;

		_cmd.normalizeFeatures = FLAGS_norm;
		_cmd.normalizerName = FLAGS_normalizer;

		_cmd.calibratorName = FLAGS_calibrator;

		_cmd.featureName = FLAGS_fn;

		_cmd.resultDir = FLAGS_rd;
		_cmd.resultIndex = FLAGS_ri;
		_cmd.resultFile = FLAGS_rf;

		_cmd.preNormalize = FLAGS_pn;
	
		if (!FLAGS_ev.empty())
		{
			_cmd.evaluateScript = FLAGS_ev + " ";
			Pval(_cmd.evaluateScript);
		}

		_cmd.evaluatorNames = FLAGS_evaluator;
		_cmd.inputFileFormat = FLAGS_format;
		_cmd.outputFileFormat = FLAGS_off;

		if (FLAGS_fast)
		{
			FLAGS_calibrate = false;
		}
	}
} //end of namespace gezi
