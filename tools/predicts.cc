/**
 *  ==============================================================================
 *
 *          \file   predicts.cc
 *
 *        \author   chenghuige
 *
 *          \date   2016-06-18 10:49:58.882419
 *
 *  \Description:  awk '{$1=$2=""; print}' -F"\t" feature.txt | ./predicts > result.txt
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
DEFINE_int32(level, 0, "min log level");
DEFINE_string(m, "model", "modelPath");
DEFINE_int32(si, 0, "startIndex| start from 0 default or start from 1 like libsvm");
DEFINE_bool(useCustomModel, false, "");

void run()
{
	string modelPath = FLAGS_m;
	auto predictor = PredictorFactory::LoadPredictor(modelPath, FLAGS_useCustomModel);
	int startIndex = FLAGS_si;
	string line;
	while (getline(std::cin, line))
	{
		Vector fe(line, startIndex);
		cout << predictor->Predict(fe) << endl;
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
