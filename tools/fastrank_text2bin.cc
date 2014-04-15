/**
 *  ==============================================================================
 *
 *          \file   fastrank_text2bin.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-14 18:26:53.908806
 *
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Predictors/PredictorFactory.h"
using namespace std;
using namespace gezi;

DEFINE_int32(level, 0, "min log level");

void run(string modelText, string binModelPath)
{
	FastRankPredictor predictor;
	predictor.LoadText(modelText);
	Vector fe("");
	double out, probablity;
	{
		probablity = predictor.Predict(fe, out);
		Pval2(out, probablity);
	}
	predictor.Save(binModelPath);
	{//check if is the same 
		auto predictor2 = PredictorFactory::LoadPredictor(binModelPath);
		double out2;
		double probablity2 = predictor2->Predict(fe, out2);
		Pval2(out2, probablity2);
		CHECK_DOUBLE_EQ(out, out2);
		CHECK_DOUBLE_EQ(probablity, probablity2);
	}
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	FLAGS_minloglevel = FLAGS_level;

	run(argv[s], argv[s + 1]);

	return 0;
}
