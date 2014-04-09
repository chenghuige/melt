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

#include "Predictors/LinearPredictor.h"

#include "serialize_util.h"
#include "serialization/shared_ptr_helper.hpp"
#include "serialization/shared_ptr.hpp"

using namespace std;
using namespace gezi;
DEFINE_int32(level, 0, "min log level");
DEFINE_string(i, "", "input");
DEFINE_string(o, "", "output");
DEFINE_string(type, "simple", "");

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
