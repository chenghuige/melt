/**
 *  ==============================================================================
 *
 *          \file   test_loadtext.cc
 *
 *        \author   chenghuige
 *
 *          \date   2016-07-03 08:49:17.124048
 *
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "MLCore/PredictorFactory.h"
#include "Predictors/GbdtPredictor.h"
using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");
DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf, false, "");
DEFINE_int32(num, 1, "");
DEFINE_string(i, "./dataset/model.tlc/", "input file");
DEFINE_string(o, "", "output file");
DEFINE_string(fe, "", "input feature");

void run()
{
	{
		auto predictor = PredictorFactory::LoadTextPredictor(FLAGS_i);
		Pval(predictor->Predict(""));
	}
	{
	GbdtRegressionPredictor predictor;
	predictor.LoadText(FLAGS_i);
	Vector fe(FLAGS_fe);

	Pval(fe[137]);

	double out;
	double probablity = predictor.Predict(fe, out);

	Pval2(out, probablity);

	predictor.Trees()[0].Print();
	predictor.Trees()[0].Print(fe);

	//double result = 0;
	//for (auto& tree : predictor.Trees())
	//{
	//	result += tree.Output(fe);
	//	Pval(result);
	//}
}
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	google::SetVersionString(get_version());
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	FLAGS_minloglevel = FLAGS_level;
	//LogHelper::set_level(FLAGS_level);
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	run();

	return 0;
}
