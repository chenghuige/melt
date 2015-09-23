/** 
 *  ==============================================================================
 * 
 *          \file   test_load_libsvm.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2015-05-17 16:44:08.145241
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
using namespace std;
using namespace gezi;
DEFINE_int32(vl, 5, "vlog level");
DEFINE_string(i, "", "input");
DEFINE_string(o, "", "output");
DEFINE_string(type, "simple", "");

TEST(load_libsvm, func)
{
	auto instances = create_instances(FLAGS_i);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;
	
	return RUN_ALL_TESTS();
}
