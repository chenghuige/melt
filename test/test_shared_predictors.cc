/** 
 *  ==============================================================================
 * 
 *          \file   test_shared_predictors.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-04-15 13:02:37.512414
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define _DEBUG
#define private public
#define protected public
#include "common_util.h"
#include "Wrapper/SharedPredictors.h"
#include "Wrapper/SharedPredictor.h"

using namespace std;
using namespace gezi;
DEFINE_int32(level, 0, "min log level");

TEST(shared_predictors, func)
{
	Vector fe("0,0,0,5.64897,1,0,1,1,0,1,6,10,6,0,6,2,0,0,1,0,0.693147,0,0,0.693147,6.85307,1.98208,5.51745,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.75,0.75,0,3.18324,0.16643,0,0,12,0,0.0769231,0.239049,0,0,3.18324,0.16643,4.4,0,0,0,4.4,14.0063,4.4,4.4,0,0,0,0,0,0,0,0,1,1,1,1,0.7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,10,-0.88,0,-0.88,-0.89,0.000111111,-3,0,-0.89,0.000111111,0,1,0,0,0,1,0,0,0,1,0,0,-0.89,-0.886667,-0.89,-0.888,1,1,1,1,1,1,1,1,1,1,0,0.00996016,0,10,0,2,0,0,0,0,0,0,2.5,5.75,0.1,1,0,1,0,0,0,0,0,0,0,0,1,0,10,10");

	/*{
		auto predictor = PredictorFactory::LoadPredictor("../tools/model.fastrank/");
		double out;
		double probablity = predictor->Predict(fe, out);
		Pval2(out, probablity);

		Predictors p;
		p.push_back(predictor);
		Pval((p[0]->Predict(fe, out)));
	}
	Predictors p = wrapper::PredictorFactory::LoadPredictors();

	SharedConf::init();
	
	{
		double out;
		double probablity = wrapper::SharedPredictor::Instance()->Predict(fe, out);
		Pval2(out, probablity);
	}*/
	//{
	//	if (wrapper::SharedPredictors::Size() > 1)
	//	{
	//		double out;
	//		double probablity = wrapper::SharedPredictors::Instance(1)->Predict(fe, out);
	//		Pval2(out, probablity);
	//	}
	//}
	//{
	//	if (wrapper::SharedPredictors::Size() > 1)
	//	{
	//		double out;
	//		double probablity = wrapper::SharedPredictors::Instance(1)->Predict(fe, out);
	//		Pval2(out, probablity);
	//	}
	//}

	for (int i = 0; i < 1000; i++)
	{
		wrapper::SharedPredictors::Instance(1)->Predict(fe);
	}
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
	//boost::progress_timer timer;
	
	return RUN_ALL_TESTS();
}
