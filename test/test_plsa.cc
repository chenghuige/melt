/** 
 *  ==============================================================================
 * 
 *          \file   test_plsa.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-08-09 21:49:18.858384
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "Segmentor.h"
#include "Identifer.h"
#include "TopicModel/PLSA/PLSAModel.h"

using namespace std;
using namespace gezi;

DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf,false, "");
DEFINE_int32(num, 1, "");
DEFINE_string(i, "", "input file");
DEFINE_string(o, "", "output file");

void run()
{
	string content = "月薪5000/月临时工公司直招 联系人张主管 联系电话15895436427";

	Identifer identifer;
	identifer.Load("./identifer.bin");

	Segmentor seg;
	Segmentor::init();

	svec words = seg.segment(content);


	map<int, Float> m;
	for (string key : words)
	{
		int id = identifer.id(key);
		if (id >= 0)
		{
			add_value(m, id, 1.0);
		}
	}

	vector<pair<int, Float> > contents;
	for (auto& item : m)
	{
		contents.push_back(make_pair(item.first, item.second));
	}

	plsa::PLSAModel model("./pzw.idx");

	Fvec results = model.Inference(contents);
	Pvec(results);
}

int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	FLAGS_minloglevel = FLAGS_level;

	run();

	return 0;
}
