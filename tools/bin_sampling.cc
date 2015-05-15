/**
 *  ==============================================================================
 *
 *          \file   bin_sampling.cc
 *
 *        \author   chenghuige
 *
 *          \date   2015-04-20 16:52:52.960550
 *
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Prediction/Instances/InstanceParser.h"
#include "Prediction/Instances/instances_util.h"
#include "MLCore/Predictor.h"
#include "MLCore/PredictorFactory.h"
using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");
DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf, false, "");

DEFINE_int32(ninsts, 100, "instance count of output file");
DEFINE_int32(nbins, 1, "");
DEFINE_string(in, "", "input file");
DEFINE_string(out, "", "output file");
DECLARE_string(m);
DECLARE_uint64(rs);



void run()
{
	if (FLAGS_in.empty())
	{
		LOG(FATAL) << "Need input file";
		return;
	}
	if (FLAGS_out.empty())
	{
		FLAGS_out = GetOutputFileName(FLAGS_in, "binSampled");
	}

	PredictorPtr predictor;
	{
		Noticer nt("Loading predictor");
		predictor = PredictorFactory::LoadPredictor(FLAGS_m);
		CHECK(predictor != nullptr);
	}

	Instances instances = create_instances(FLAGS_in);

	if (FLAGS_ninsts > instances.size())
	{
		LOG(FATAL) << "Input file instance num is less than " << FLAGS_ninsts;
		return;
	}

	instances.Randomize(random_engine(FLAGS_rs));

	vector<int> binCounts(FLAGS_nbins, 0);
	int countPerBin = FLAGS_ninsts / FLAGS_nbins;
	int total = countPerBin * FLAGS_ninsts;
	int extra = FLAGS_ninsts - total;
	double thre = 1.0 / FLAGS_nbins;
	int count = 0;

	Instances oinstances(instances.schema);
	for (int i = 0; i < instances.size(); i++)
	{
		double score = predictor->Predict(instances[i]);
		int bin = score / thre;
		if (binCounts[bin] != countPerBin)
		{
			binCounts[bin]++;
			count++;
			oinstances.Add(instances[i]);
			Pval(score);
			if (count == total)
			{
				for (int j = 0; j < extra; j++)
				{
					oinstances.Add(instances[i + 1 + j]);
				}
				break;
			}
		}
	}

	write(oinstances, FLAGS_out);
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	FLAGS_minloglevel = FLAGS_level;
	LogHelper::set_level(FLAGS_level);
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	run();

	return 0;
}
