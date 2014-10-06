/**
 *  ==============================================================================
 *
 *          \file   melt.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-02-02 12:36:22.355574
 *
 *  \Description:  
 *  ==============================================================================
 */

#define private public
#define protected public
#define NO_BAIDU_DEP
#include "common_util.h"
#include "Run/Melt.h"
using namespace std;
using namespace gezi;
DEFINE_int32(vl, 0, "vlog level");
DECLARE_string(c);

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;
	string usage = "Melt is a machine learning toolkit";
	google::SetUsageMessage(usage);

	Melt melt;
	if (FLAGS_c != "help"
		&& !(FLAGS_c == "write_text_model" || FLAGS_c == "wtm" 
		|| FLAGS_c == "binary_model_to_text" || FLAGS_c == "bm2t") 
		&& !(FLAGS_c == "text_model_to_binary" || FLAGS_c == "tm2b") 
		&& melt.Cmd().datafile.empty())
	{
		if (s >= argc)
		{
			google::ShowUsageWithFlags(argv[0]);
			LOG(WARNING) << "No input data file use -i filename or just input filename after ./melt";
			LOG(INFO) << "For eaxmaple: ./melt feature.txt -c train -cl gbdt";
			LOG(INFO) << "Default command is cross validation 5 fold: ./melt feature.txt";
			LOG(INFO) << "For more commands: ./melt -c help";
			LOG(INFO) << "try ./melt --helpmatch Melt #for spcific classifer setting use like --helpmatch LinearSvm";
			return -1;
		}
		melt.Cmd().datafile = argv[s];
	}
	melt.RunExperiments();
	return 0;
}

