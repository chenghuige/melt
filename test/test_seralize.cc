/** 
 *  ==============================================================================
 * 
 *          \file   test_seralize.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-04-09 20:18:28.024001
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"

#include "Prediction/Normalization/MinMaxNormalizer.h"
#include "Prediction/Calibrate/SigmoidCalibrator.h"
#include "Predictors/LinearPredictor.h"
#include "Trainers/SVM/LinearSVM.h"
#include "MLCore/TrainerFactory.h"
#include "Prediction/Instances/instances_util.h"

#include "Predictors/PredictorFactory.h"


using namespace std;
using namespace gezi;
DEFINE_int32(level, 0, "min log level");

TEST(test_seralize, func)
{
	{
		Predictor p;
		Pval(p._normalizeCopy);
		p.SetNormalizeCopy();
		Pval(p._normalizeCopy);
		serialize_util::save(p, "p.model");
	}
	{
		Predictor p;
		Pval(p._normalizeCopy);
		serialize_util::load("p.model", p);
		Pval(p._normalizeCopy);
	}
}

TEST(test_seralize2, func)
{
	{
		LinearPredictor p;
		Pval(p._normalizeCopy);
		p.SetNormalizeCopy();
		Pval(p._normalizeCopy);
		p._featureNames = { "abc", "def", "gh" };
		serialize_util::save(p, "p.model");
	}
	{
		LinearPredictor p;
		Pval(p._normalizeCopy);
		Pvec(p._featureNames);
		serialize_util::load("p.model", p);
		Pval(p._normalizeCopy);
		Pvec(p._featureNames);
		Pval((p._normalizer == nullptr));
	}
}

//如何序列化 表示多态指针
TEST(test_seralize3, func)
{

	/*{
		PredictorPtr p = make_shared<LinearPredictor>();
		shared_ptr<LinearPredictor> p2 = dynamic_pointer_cast<LinearPredictor>(p);
		Pval(p->_normalizeCopy);
		p->SetNormalizeCopy();
		Pval(p->_normalizeCopy);
		dynamic_cast<LinearPredictor*>(p.get())->_featureNames = { "abc", "def", "gh" };
		serialize_util::save(p, "p.model");
	}
	{
		PredictorPtr p = make_shared<LinearPredictor>();
		Pval(p->_normalizeCopy);
		Pvec(dynamic_cast<LinearPredictor*>(p.get())->_featureNames);
		serialize_util::load("p.model", p);
		Pval(p->_normalizeCopy);
		Pvec(dynamic_cast<LinearPredictor*>(p.get())->_featureNames);
	}*/
}

TEST(predict, func)
{
	Noticer nt("TrainTest!");
	{
		auto instances = create_instances("../data/feature.txt");
		CHECK_GT(instances.Count(), 0) << "Read 0 train instances, aborting experiment";
		auto trainer = TrainerFactory::CreateTrainer("LinearSVM");
		if (trainer == nullptr)
		{
			return;
		}
		trainer->Train(instances);
		auto predictor = trainer->CreatePredictor();
		predictor->Save("predictor");
		predictor->SaveText();
	}
	{
		auto predictor = PredictorFactory::LoadPredictor("predictor");
		auto testInstances = create_instances("../data/feature.txt");
		CHECK_GT(testInstances.Count(), 0) << "Read 0 test instances, aborting experiment";
		ofstream ofs("./0.inst.txt");
		ofs << "Instance\tTrue\tAssigned\tOutput\tProbability" << endl;
		int idx = 0;
		for (InstancePtr instance : testInstances)
		{
			double output;
			double probability = predictor->Predict(instance, output);
			string name = instance->name.empty() ? STR(idx) : instance->name;
			int assigned = output > 0 ? 1 : 0;
			ofs << name << "\t" << instance->label << "\t"
				<< assigned << "\t" << output << "\t"
				<< probability << endl;
			idx++;
		}
		string command = "python ../scripts/evaluate.py 0.inst.txt";
		system(command.c_str()); 
	}
	
	/*LOG(INFO) << "-------------------------------------Testing";
	auto testInstances = create_instances("../data/feature.txt");
	CHECK_GT(testInstances.Count(), 0) << "Read 0 test instances, aborting experiment";
	CHECK_EQ(instances.schema == testInstances.schema, 1);
	ofstream ofs("./0.inst.txt");
	ofs << "Instance\tTrue\tAssigned\tOutput\tProbability" << endl;
	int idx = 0;
	for (InstancePtr instance : testInstances)
	{
		double output;
		double probability = predictor->Predict(instance, output);
		string name = instance->name.empty() ? STR(idx) : instance->name;
		int assigned = output > 0 ? 1 : 0;
		ofs << name << "\t" << instance->label << "\t"
			<< assigned << "\t" << output << "\t"
			<< probability << endl;
		idx++;
	}
	string command = "python ../scripts/evaluate.py 0.inst.txt";
	system(command.c_str());*/
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
  boost::progress_timer timer;
  
  return RUN_ALL_TESTS();
}
