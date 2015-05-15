/**
 *  ==============================================================================
 *
 *          \file   test_sim.cc
 *
 *        \author   chenghuige
 *
 *          \date   2015-04-28 14:39:37.345247
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
DEFINE_string(type, "simple", "");
DEFINE_bool(perf, false, "");
DEFINE_string(in, "", "input file");
DEFINE_string(out, "", "output file");


struct SortNode
{
	string name1;
	string name2;
	double sim;

	SortNode(string name1_, string name2_, double sim_)
		:name1(name1_), name2(name2_), sim(sim_)
	{

	}
};
void run()
{
	Instances instances = create_instances(FLAGS_in);

	Pval(instances.size());

	vector<double> l2norms(instances.size(), 0);
	for (size_t i = 0; i < instances.size(); i++)
	{
		l2norms[i] = sqrt(instances[i]->features.SquaredNorm());
	}

	vector<SortNode> vec;
	for (size_t i = 0; i < instances.size(); i++)
	{
		Pval(i);
		for (size_t j = i + 1; j < instances.size(); j++)
		{
			vec.push_back(SortNode(instances[i]->name, instances[j]->name,
				cos(instances[i]->features, instances[j]->features, l2norms[i], l2norms[j])));
		}
	}

	std::partial_sort(vec.begin(), vec.begin() + 100, vec.end(),
		[](const SortNode& l, const SortNode& r) { return l.sim > r.sim; });

	PrintVec3TopN(vec, name1, name2, sim, 100);

}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
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
