/**
 *  ==============================================================================
 *
 *          \file   gbdt_predict.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-14 18:27:45.210850
 *
 *  \Description:
 *
 *  ==============================================================================
 */
#define _DEBUG
#define private public
#define protected public
#include "common_util.h"
#include "Predictors/GbdtPredictor.h"
using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");
DEFINE_bool(r, false, "reverse: show trees from -.. to + .. if reverse == true");
DEFINE_int32(t, -1, "tree index to print");
DEFINE_int32(start_index, 0, "start from 0 default or start from 1 like libsvm");

DEFINE_string(m, "model", "modelPath");
DEFINE_string(f, "", "featureStr");

void run(string feature, string modelPath)
{
	GbdtPredictor predictor(modelPath);
	predictor.SetReverse(FLAGS_r);
	Vector fe(feature, FLAGS_start_index);
	double out;
	double probablity = predictor.Predict(fe, out);
	Pval2(out, probablity);
	if (FLAGS_t >= 0)
	{
		predictor.Trees()[FLAGS_t].Print(fe);
	}
	predictor.FeatureGainPrint(fe);
	Pval2(out, probablity);
}


int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	google::SetVersionString(get_version());
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	run(FLAGS_f, FLAGS_m);

	return 0;
}

