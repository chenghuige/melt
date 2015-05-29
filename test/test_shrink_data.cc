/** 
 *  ==============================================================================
 * 
 *          \file   test_shrink_data.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2015-05-29 12:01:51.200505
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"

#include "Prediction/Instances/instances_util.h"

using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");
DEFINE_int32(level, 0, "min log level");
DECLARE_string(i);

void run()
{
	auto instances = create_instances(FLAGS_i);
	instances.ShrinkData(0.8, random_engine(3));
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
