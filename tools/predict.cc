/**
 *  ==============================================================================
 *
 *          \file   predict.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-14 18:07:22.612175
 *
 *  \Description:  调用某个模型 对用户输入的一个特征 进行预测打分
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"

#include "MLCore/PredictorFactory.h"

DEFINE_string(m, "model", "modelPath");
DEFINE_string(f, "", "featureStr");

using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");

void run(string feature, string modelPath)
{
	auto predictor = PredictorFactory::LoadPredictor(modelPath);
	Vector fe(feature);
	double out;
	double probablity = predictor->Predict(fe, out);
	Pval2(out, probablity);
	if (FLAGS_v > 0)
	{
		predictor->Print(fe);
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
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	run(FLAGS_f, FLAGS_m);

	return 0;
}
