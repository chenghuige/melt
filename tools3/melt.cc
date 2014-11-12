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

const char* const kVersion = "1-0-0-10";

void ShowHelp()
{
	cout << "\n";
	cout << "	Default command is cross validation: <./melt feature.txt> will do 5 fold cross validation using LinearSVM trainer with it's default settings\n";
	fmt::print_colored(fmt::RED, "	For more commands: <./melt -c help>\n");
	fmt::print_colored(fmt::RED, "	Show supported trainers: <./melt -c helptrainers>\n");
	cout << "	Try <./melt --helpmatch Melt> for melt common settings\n";
	cout << "	Try <./melt --helpmatch Instance> for melt input instances parser settings\n";
	cout << "	For spcific classifer setting use like <./melt --helpmatch LinearSVM.cpp>, <./melt --helpmatch FastRank.cpp>\n";
	cout << "	The default trainer is LinearSVM, for other trainers use -cl, eg. <./melt feature.txt -c train -cl gbdt> will train feature.txt using gbdt trainer\n";
	cout << "	The default input is melt dense or sparse input, you can use LibSVM format input, but need to add <-format libsvm>\n";
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	google::SetVersionString(kVersion);

	for (size_t i = 0; i < argc; i++)
	{
		string arg = argv[i];
		if (arg == "-help" || arg == "--help" || arg == "-h" || arg == "--h")
		{
			ShowHelp();
			cout << endl;
			break;
		}
	}

	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	Melt melt;
	if (FLAGS_c != "help" && FLAGS_c != "helptrainers" && FLAGS_c != "help_trainers"
		&& !(FLAGS_c == "write_text_model" || FLAGS_c == "wtm" || FLAGS_c == "binary_model_to_text" || FLAGS_c == "bm2t")
		&& !(FLAGS_c == "text_model_to_binary" || FLAGS_c == "tm2b")
		&& melt.Cmd().datafile.empty())
	{
		if (s >= argc)
		{
			google::ShowUsageWithFlags(argv[0]);
			cout << "	No input data file use -i filename or just input filename after ./melt\n";
			ShowHelp();
			return -1;
		}
		melt.Cmd().datafile = argv[s];
	}
	melt.RunExperiments();
	return 0;
}

