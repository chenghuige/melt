/** 
 *  ==============================================================================
 * 
 *          \file   test_auc.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-07-25 17:30:45.246314
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define _DEBUG
#define private public
#define protected public
#include "common_util.h"
#include "Utils/performance_evaluate.h"
using namespace std;
using namespace gezi;
DEFINE_int32(vl, 0, "vlog level");
//DEFINE_string(i, "~/data/0.inst.txt", "input");
DECLARE_string(i);
//DEFINE_string(o, "", "output");
DEFINE_string(type, "simple", "");

TEST(auc, func)
{
	ifstream ifs(FLAGS_i);
	string line;
	int count = 0;

	AucEvaluator evaluator;
	while (getline(ifs, line))
	{
		count++;
		if (count == 1)
		{
			continue;
		}
		svec vec = split(line, "\t ");
		int label = INT(vec[1]);
		double out = DOUBLE(vec[4]);
		evaluator.Add(label, out);
	}
	Pval(evaluator.Finish());
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
