/**
 *  ==============================================================================
 *
 *          \file   calibrate.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-11 01:03:08.334409
 *
 *  \Description: ÊäÈë true output Êä³ö true output probability
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Prediction/Calibrate/SigmoidCalibrator.h"
using namespace std;
using namespace gezi;

DEFINE_int32(logv, 4, "16 debug, 8 trace, 4 online");
DEFINE_string(logdir, "./log", "");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf, false, "");
DEFINE_int32(num, 1, "");
DEFINE_string(in, "", "input file");
DEFINE_string(out, "", "output file");

void run()
{
	SigmoidCalibrator calibrator;
	{
		ifstream ifs(FLAGS_in);
		string line;
		while (getline(ifs, line))
		{
			string label_, output_;
			split(line, "\t ", label_, output_);
			double label = DOUBLE(label_);
			double output = DOUBLE(output_);
			calibrator.ProcessTrainingExample(output, label > 0, 1);
		}
	}
	calibrator.FinishTraining();
	{
		ofstream ofs(FLAGS_out);
		ofs << "True\tOutput\tProbability" << endl;
		ifstream ifs(FLAGS_in);
		string line;
		while (getline(ifs, line))
		{
			string label_, output_;
			split(line, "\t ", label_, output_);
			double output = DOUBLE(output_);
			double prob = calibrator.PredictProbability(output);
			ofs << label_ << "\t" << output_ << "\t" << prob << endl;
		}
	}
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	FLAGS_log_dir = FLAGS_logdir;
	if (FLAGS_logv >= 4)
	{
		FLAGS_stderrthreshold = 0;
	}
	//  LogHelper log_helper(FLAGS_logv);
	LogHelper::set_level(FLAGS_logv);

	run();

	return 0;
}
