/** 
 *  ==============================================================================
 * 
 *          \file   plsa.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-08-06 10:15:45.276324
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "TopicModel/PLSA/PLSAModel.h"
using namespace std;
using namespace gezi;
using namespace gezi::plsa;

DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf,false, "");
DEFINE_int32(num, 1, "");
DEFINE_string(i, "", "input file");
DEFINE_string(o, "", "output file");

void run()
{
	PLSAModel plsaModel(100, 1000);
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	FLAGS_minloglevel = FLAGS_level;

	run();

	return 0;
}
