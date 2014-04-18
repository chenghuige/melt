
#include "common_util.h"
#include "Run/Melt.h"

DEFINE_string(c, "cv", "command: Options are: Train, Test, CV (cross validation), TrainTest, FeatureSelection, CreateInstances, Norm, Check");
DEFINE_string(ci, "", "commandInput: Some commands need additional input like split data you need to iput like 1:1");
DEFINE_string(cl, "LinearSVM", "classifierName: Classifier to use");
DEFINE_string(cls, "", "classifierSettings: Classifier settings");

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

DEFINE_string(test, "", "testDatafile: Data file used for test");
DEFINE_string(valid, "", "Data file used for training validation (with IValidatingPredictor classifiers)");

DEFINE_string(m, "model", "modelFolder under result folder");
DEFINE_bool(mc, false, " modelfileCode:Gen model file to save in C++ code £¿ (for Train or TrainTest)");
DEFINE_bool(mt, false, "modelfileText:  Gen model file to save in text format ? (for Train or TrainTest");

DEFINE_string(rd, "./result", "resultDir: where to put the result data");
DEFINE_int32(ri, 0, "resultIndex: the name ouf out file like 0.model.txt 0.model 0.inst.txt");

DEFINE_bool(norm, true, "Normalize features");
DEFINE_string(normalizer, "MinMax", "Which normalizer?");
DEFINE_string(nf, "", "normalzierfile: specified the output normalzier text");

DEFINE_string(fn, "", "featureName:");
DEFINE_string(ev, "evaluate.simple/evaluate.simple ", "evaluate: use what to evalute the result");

DEFINE_bool(calibrate, true, "calibrateOutput: use calibrator to gen probability?");
DEFINE_string(calibrator, "sigmoid", "calibratorName: sigmoid/platt naive pav");
DEFINE_bool(pn, false, "preNormalize:");

DEFINE_string(oformat, "unknown", "ouput file format if unknow using it's input format");

namespace gezi {
	void Melt::ParseArguments()
	{
		_cmd.command = FLAGS_c;
		_cmd.commandInput = FLAGS_ci;
		_cmd.classifierName = FLAGS_cl;
		_cmd.classifierSettings = FLAGS_cls;
		_cmd.datafile = FLAGS_i;
		_cmd.outfile = FLAGS_o;
		_cmd.normalizerfile = FLAGS_nf;
		_cmd.testDatafile = FLAGS_test;
		_cmd.validationDatafile = FLAGS_valid;
		_cmd.modelFolder = FLAGS_m;
		_cmd.modelfileCode = FLAGS_mc;
		_cmd.modelfileText = FLAGS_mt;
		_cmd.numFolds = FLAGS_k;
		_cmd.numRuns = FLAGS_nr;

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

		_cmd.featureName = FLAGS_fn;

		_cmd.resultDir = FLAGS_rd;
		_cmd.resultIndex = FLAGS_ri;


		_cmd.preNormalize = FLAGS_pn;
		_cmd.evaluate = FLAGS_ev;

		_cmd.outputFileFormat = FLAGS_oformat;
	}
} //end of namespace gezi