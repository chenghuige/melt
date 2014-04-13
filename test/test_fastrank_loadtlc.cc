/** 
 *  ==============================================================================
 * 
 *          \file   test_fastrank_loadtlc.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-04-13 20:18:15.362881
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Predictors/FastRankPredictor.h"
#include "Predictors/PredictorFactory.h"
using namespace std;
using namespace gezi;
DEFINE_int32(level, 0, "min log level");
//DEFINE_string(i, "", "input");
//DEFINE_string(o, "", "output");
DECLARE_string(i);
DECLARE_string(o);
DEFINE_string(type, "simple", "");

TEST(fastrank_loadtlc, func)
{
	FastRankPredictor predictor;
	predictor.Load("./data/0.model.txt");

	Vector fe("0	0	0	5.64897	1	0	1	1	0	1	6	10	6	0	6	2   0.693147	0	0	0.693147	6.85307	1.98208	5.51745	0	0	0	0	0	0	0	0	0	1	0   0.75	0.75	0	3.18324	0.16643	0	0	12	0	0.0769231	0.239049	0	0	3.18324	0.16643	4.4	0   4.4	14.0063	4.4	4.4	0	0	0	0	0	0	0	0	1	1	1	1	0.7	0	0   2.5	2.5	2.5	2.5	2.5	2.5	2.5	2.5	2.5	10	-0.88	0	-0.88	-0.89	0.000111111	-3	0	-0.80.000111111	0	1	0	0	0	1	0	0	0	1	0	0	-0.89	-0.886667	-0.89	-0.888	1	1	1	1	1	1	1	1	1	1	0	0.00996016	0	10	0	2	0   2.5	5.75	0.1	1	0	1	0	0	0	0	0	0	0	0	1	0	10	10");

	Pval(predictor.Output(fe));
	Pval(predictor.Predict(fe));
		
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
