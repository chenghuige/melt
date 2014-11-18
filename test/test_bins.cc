/** 
 *  ==============================================================================
 * 
 *          \file   test_bins.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-04-26 21:17:01.839707
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define _DEBUG
#define private public
#define protected public
#include "common_util.h"
#include "Prediction/Instances/instances_util.h"
#include "Prediction/Normalization/BinNormalizer.h"

using namespace std;
using namespace gezi;
DEFINE_int32(level, 0, "min log level");
DEFINE_int32(idx, 0, "min log level");
DECLARE_string(i);

TEST(bins, func)
{
	Instances instances = create_instances(FLAGS_i);
	Pval(instances.Size());
	BinNormalizer normalizer; 
	normalizer.maxBins = 255;
	normalizer.RunNormalize(instances);
	int len = std::min(instances.NumFeatures(), 10);
	for (int i = 0; i < len; i++)
	{
		Pval(i);
		Pvec(normalizer.binUpperBounds[i]);
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
	//boost::progress_timer timer;
	
	return RUN_ALL_TESTS();
}
