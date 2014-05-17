/**
 *  ==============================================================================
 *
 *          \file   fastrank_predict.cc
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
#include "Predictors/FastRankPredictor.h"
using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");
DEFINE_bool(r, false, "reverse: show trees from -.. to + .. if reverse == true");
DEFINE_int32(t, -1, "tree index to print");

void run(string modelPath, string feature)
{
	FastRankPredictor predictor(modelPath);
	predictor.SetReverse(FLAGS_r);
	Vector fe(feature);
	double out;
	double probablity = predictor.Predict(fe, out);
	Pval2(out, probablity);
	if (FLAGS_t >= 0)
	{
		predictor.Trees()[FLAGS_t].Print(fe);
	}
}


int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	string modelPath = argv[s];
	string feature;
	if (s + 1 < argc)
		feature = argv[s + 1];
	run(modelPath, feature);

	return 0;
}
