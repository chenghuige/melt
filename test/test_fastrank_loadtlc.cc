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
#define _DEBUG
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
DEFINE_string(fe, "", "input feature");
DEFINE_string(type, "simple", "");

TEST(fastrank_loadtlc, func)
{
	FastRankPredictor predictor;
	predictor.LoadText(FLAGS_i);

	//注意如果稀疏构造 必须用const 否则调用Float& opeartor[]
	const Vector fe(FLAGS_fe);

	Pval(fe[137]);

	double out;
	double probablity = predictor.Predict(fe, out);

	Pval2(out, probablity);


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
