/** 
 *  ==============================================================================
 * 
 *          \file   test_normalize.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-04-02 11:26:04.290198
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Prediction/Instances/InstanceParser.h"
#include "Prediction/Normalization/MinMaxNormalizer.h"
using namespace std;
using namespace gezi;
DEFINE_int32(level, 0, "min log level");
DEFINE_int32(idx, 0, "min log level");
DEFINE_string(i, "", "input");
DEFINE_string(o, "", "output");
DEFINE_string(type, "simple", "");

TEST(test_normalize, func)
{
	InstanceParser parser;
	Instances instances = parser.Parse(FLAGS_i);
	Pval(instances.Size());
	NormalizerPtr normalizer = make_shared<MinMaxNormalizer>();
	if (instances.Count() > FLAGS_idx)
	{
		Pval(instances[FLAGS_idx]->name);
		(*(instances[FLAGS_idx])).features.ForEach([](int index, double value)
		{
			LOG(INFO) << index << "\t" << value;
		});
		Pval(instances[FLAGS_idx]->IsDense());
	}

	Pval(instances[0]->IsDense());
	normalizer->PrepareAndNormalize(instances);
	if (instances.Count() > FLAGS_idx)
	{
		Pval(instances[FLAGS_idx]->name);
		(*(instances[FLAGS_idx])).features.ForEach([](int index, double value)
		{
			LOG(INFO) << index << "\t" << value;
		});
		Pval(instances[FLAGS_idx]->IsDense());
	}

	{
		Feature fe;
		fe.add(0, 3.0);
		fe.add(1, 1.0);
		fe.add(3, 0.0);
		fe.add(15, 8.0);
		normalizer->Normalize(fe);
		fe.ForEach([](int index, double value)
		{
			LOG(INFO) << index << "\t" << value;
		}); 
	}
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
  int s = google::ParseCommandLineFlags(&argc, &argv, false);
  if (FLAGS_log_dir.empty())
    FLAGS_logtostderr = true;
  FLAGS_minloglevel = FLAGS_level;
  boost::progress_timer timer;
  
  return RUN_ALL_TESTS();
}
