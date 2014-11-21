/** 
 *  ==============================================================================
 * 
 *          \file   test_normalize_copy.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-11-21 08:15:06.453647
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
#include "Prediction/Normalization/MinMaxNormalizer.h"
using namespace std;
using namespace gezi;
DEFINE_int32(vl, 5, "vlog level");
DEFINE_string(in, "", "input");
DEFINE_string(out, "", "output");
DEFINE_string(type, "simple", "");

void RunNormalize()
{
	ofstream ofs("temp1");
	auto instances = create_instances(FLAGS_in);
	NormalizerPtr normalizer = make_shared<MinMaxNormalizer>();
	normalizer->RunNormalize(instances);

	normalizer->SaveText("temp1.text");

	ofs << instances.size() << endl;
	for (InstancePtr instance: instances)
	{
		ofs << instance->label << " ";
		instance->features.ForEach([&](int index, Float value) {
			ofs << index << " " << value << ",";
		});
		ofs << endl;
	}
}

void RunNormalizeCopy()
{
	ofstream ofs("temp2");
	auto instances = create_instances(FLAGS_in);
	NormalizerPtr normalizer = make_shared<MinMaxNormalizer>();
	Instances newInstances = normalizer->RunNormalizeCopy(instances);

	normalizer->SaveText("temp2.text");

	ofs << newInstances.size() << endl;
	for (InstancePtr instance : newInstances)
	{
		ofs << instance->label << " ";
		instance->features.ForEach([&](int index, Float value) {
			ofs << index << " " << value << ",";
		});
		ofs << endl;
	}
}

void RunNormalizeAndCopy()
{
	ofstream ofs("temp3");
	ofstream ofs2("temp4");

	auto instances = create_instances(FLAGS_in);
	NormalizerPtr normalizer = make_shared<MinMaxNormalizer>();
	Instances newInstances = normalizer->RunNormalizeCopy(instances);
	normalizer->SaveText("temp4.text");
	normalizer->RunNormalize(instances);
	normalizer->SaveText("temp3.text");

	ofs << instances.size() << endl;
	for (InstancePtr instance : instances)
	{
		ofs << instance->label << " ";
		instance->features.ForEach([&](int index, Float value) {
			ofs << index << " " << value << ",";
		});
		ofs << endl;
	}

	ofs2 << newInstances.size() << endl;
	for (InstancePtr instance : newInstances)
	{
		ofs2 << instance->label << " ";
		instance->features.ForEach([&](int index, Float value) {
			ofs2 << index << " " << value << ",";
		});
		ofs2 << endl;
	}
}


TEST(normalize_copy, func)
{
	RunNormalize();
	RunNormalizeCopy();
	RunNormalizeAndCopy();
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
