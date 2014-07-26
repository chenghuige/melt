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

using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");

void run(string modelPath, string feature)
{
	auto predictor = PredictorFactory::LoadPredictor(modelPath);
	Vector fe(feature);
	double out;
	double probablity = predictor->Predict(fe, out);
	Pval2(out, probablity);
	fe.MakeSparse();
	LOG(INFO) << "After make sparse";
	probablity = predictor->Predict(fe, out);
	Pval2(out, probablity);
	fe.MakeDense();
	LOG(INFO) << "After make dense, notice for sparse will make length at most 1024000";
	probablity = predictor->Predict(fe, out);
	Pval2(out, probablity);
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
