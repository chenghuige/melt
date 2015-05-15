/**
 *  ==============================================================================
 *
 *          \file   test_active_select.cc
 *
 *        \author   chenghuige
 *
 *          \date   2015-04-29 10:55:23.142064
 *
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"

#include "Prediction/Instances/instances_util.h"
#include "MLCore/TrainerFactory.h"
#include "MLCore/Predictor.h"
#include "MLCore/PredictorFactory.h"

#include "Matrix.h"

using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level");
DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_int32(sample, 10000, "sample candidates count");
DEFINE_bool(perf, false, "");
DECLARE_uint64(num);
DECLARE_string(m);
DECLARE_string(i);
DECLARE_string(o);

struct Node
{
	InstancePtr inst;
	double score;

	Node(InstancePtr inst_, double score_)
		:inst(inst_), score(score_)
	{

	}
	Node()
	{

	}
	bool operator < (const Node& other) const
	{
		return score > other.score;
	}
};

void run()
{
	auto predictor = PredictorFactory::LoadPredictor(FLAGS_m);
	predictor->SetNormalizeCopy();
	auto instances = create_instances(FLAGS_i);
	vector<Node> vec;
	for (auto& inst : instances)
	{
		vec.push_back(Node(inst, 1.0/ (1 + abs(predictor->Output(inst)))));
		//vec.push_back(Node(inst, 1.0));
	}
	
	gezi::partial_sort(vec, FLAGS_sample);

	vec.resize(FLAGS_sample);

	vector<double> l2norms(FLAGS_sample, 0);
	for (size_t i = 0; i < FLAGS_sample; i++)
	{
		l2norms[i] = sqrt(vec[i].inst->features.SquaredNorm());
	}

	gezi::ufo::Matrix<double> m(FLAGS_sample, FLAGS_sample, 1);

	LOG(INFO) << "Begin cos sim calc";
	ProgressBar bar(FLAGS_sample);
	for (size_t i = 0; i < FLAGS_sample; i++)
	{
		bar++;
		for (size_t j = i + 1; j < FLAGS_sample; j++)
		{
			m(i, j) = cos(vec[i].inst->features, vec[j].inst->features, l2norms[i], l2norms[j]);
			m(j, i) = m(i, j);
		}
	}

	vector<double> sim_vec(FLAGS_sample);

	for (size_t i = 0; i < FLAGS_sample; i++)
	{
		double sim = 0;
		for (size_t j = 0; j < FLAGS_sample; j++)
		{
			if (i != j)
			{
				sim += m(i, j);
			}
		}
		sim /= FLAGS_sample;
		sim_vec[i] = sim;
		//vec[i].score *= sim;
		vec[i].score += sim;
	}

	std::sort(vec.begin(), vec.end());

	vector<int> indexes(FLAGS_sample, 0);
	for (size_t i = 0; i < FLAGS_sample; i++)
	{
		indexes[i] = i;
	}
	for (size_t k = 1; k < FLAGS_num; k++)
	{
		double maxScore = -1;
		double index = k;
		for (size_t c = k; c < FLAGS_sample; c++)
		{//选取一个距离相对已选点集合较远的
			double minDistScore = 1024;
			for (size_t i = 0; i < k; i++)
			{ //选取最近的点
				double distScore = 1 - m(indexes[k], indexes[c]);
				if (distScore < minDistScore)
				{
					minDistScore = distScore;
				}
			}
			double score = vec[indexes[c]].score + minDistScore;
			if (score > maxScore)
			{
				index = c;
				maxScore = score;
			}
		}
		std::swap(indexes[k], indexes[index]);
	}



	//{
	//	double mostSim = 0;
	//	int l, r;
	//	for (size_t i = 0; i < FLAGS_sample; i++)
	//	{
	//		for (size_t j = i + 1; j < FLAGS_sample; j++)
	//		{
	//			if (m(i, j) > mostSim)
	//			{
	//				mostSim = m(i, j);
	//				l = i;
	//				r = j;
	//			}
	//		}
	//	}
	//	Pval3(mostSim, l, r);
	//	Pval2(vec[l].inst->name, vec[r].inst->name);
	//	Pval(vec[l].inst->features.str());
	//	Pval(vec[r].inst->features.str());
	//}

	LOG(INFO) << "Finish cos sim calc";	

	Instances outInstances(instances.schema);
	for (int i = 0; i < FLAGS_num; i++)
	{
		outInstances.push_back(vec[indexes[i]].inst);
	}
	write(outInstances, FLAGS_o);
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
