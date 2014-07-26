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

#include "common_util.h"
#include "Run/Melt.h"
using namespace std;
using namespace gezi;
DEFINE_int32(vl, 0, "vlog level");

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
	if (melt.Cmd().datafile.empty())
	{
		if (s >= argc)
		{
			google::ShowUsageWithFlags(argv[0]);
			LOG(WARNING) << "No input data file use -i filename or just input filename after ./melt";
			LOG(INFO) << "try ./melt --helpmatch Melt #for spcific classifer setting use like --helpmatch LinearSvm";
			return -1;
		}
		melt.Cmd().datafile = argv[s];
	}
	melt.RunExperiments();
	return 0;
}

