/** 
 *  ==============================================================================
 * 
 *          \file   fastrank2gcc3.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2015-05-19 10:47:13.203122
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Predictors/GbdtPredictor.h"

using namespace std;
using namespace gezi;

DEFINE_string(what, "fastrank2gcc3 will translate ./model_path/model.bin to ./model_path/model.bin.gcc3 wihch can be used by GbdtPredictor without gcc4 dependency, notice you must use sigmoid calibrator", "");
DEFINE_int32(vl, 0, "vlog level");
DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf,false, "");
DEFINE_int32(num, 1, "");
DEFINE_string(m, "model", "input model path");
DEFINE_string(o, "", "output file");

void save(const OnlineRegressionTree& tree, ofstream& ofs)
{
	PVAL3(tree.NumLeaves, tree._maxOutput, tree._weight);
	write_elem(tree.NumLeaves, ofs);
	write_elem(tree._maxOutput, ofs);
	write_elem(tree._weight, ofs);
	write_vec(tree._gainPValue, ofs);
	write_vec(tree._lteChild, ofs);
	write_vec(tree._gtChild, ofs);
	write_vec(tree._leafValue, ofs);
	write_vec(tree._threshold, ofs);
	write_vec(tree._splitFeature, ofs);
	write_vec(tree._splitGain, ofs);
	write_vec(tree._previousLeafValue, ofs);
}

void run()
{
		GbdtPredictor predictor(FLAGS_m);
		ofstream ofs(FLAGS_m + "/model.bin.gcc3", ios::binary);
		int ntrees = predictor._trees.size();
		Pval(ntrees);
		write_elem(ntrees, ofs);
		for (int i = 0; i < ntrees; i++)
		{
			save(predictor._trees[i], ofs);
		}

		//dynamic will do rtti if not SigmoidCalibrator will be null ptr
		auto calibrator = dynamic_pointer_cast<SigmoidCalibrator>(predictor._calibrator);
		double paramA = -2.0, paramB = 0.0;
		if (calibrator == nullptr)
		{
			LOG(INFO) << "No calibrator or other type calibrator will use default param sigmoid calibrator";
		}
		else
		{
			paramA = calibrator->paramA;
			paramB = calibrator->paramB;
		}
		write_elem(paramA, ofs);
		write_elem(paramB, ofs);
}

int main(int argc, char *argv[])
{
		google::InitGoogleLogging(argv[0]);
		google::InstallFailureSignalHandler();
		google::SetVersionString(get_version());
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
