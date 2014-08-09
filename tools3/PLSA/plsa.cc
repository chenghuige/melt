/** 
 *  ==============================================================================
 * 
 *          \file   plsa.cc
 *
 *        \author   chenghuige   
 *
 *          \date   2014-08-06 10:15:45.276324
 *  
 *  \Description:
 *
 *  ==============================================================================
 */

#define private public
#define protected public
#include "common_util.h"
#include "TopicModel/PLSA/PLSAModel.h"
using namespace std;
using namespace gezi;
using namespace gezi::plsa;

DEFINE_int32(level, 0, "min log level");
DEFINE_string(type, "simple", "");
DEFINE_bool(perf,false, "");
DEFINE_int32(num, 1, "");
DEFINE_int32(iter, 20, "iterate num");
DEFINE_string(i, "", "input file");
DEFINE_int32(tnum, 100, "topic num");
DEFINE_string(dict, "./identifer.bin", "input dict file");
DEFINE_string(o, "", "output file");

#include "Identifer.h"
void run()
{
	Identifer identifer;
	identifer.Load(FLAGS_dict);
	Pval(identifer.size());
	PLSAModel plsaModel(FLAGS_tnum, identifer.size());

	ifstream ifs(FLAGS_i);
	string line;
	vector<DocInfo> docs;
	while (getline(ifs, line))
	{
		boost::trim(line);
		svec vec = gezi::split(line, '\t');
		map<int, int> m;
		DocInfo doc;
		for (string key : vec)
		{
			int id = identifer.id(key);
			if (id >= 0)
			{
				add_value(m, id, 1);
				doc.numWords++;
			}
		}
		for (auto& item : m)
		{
			doc.content.push_back(make_pair(item.first, item.second));
		}
		docs.emplace_back(doc);
	}

	plsaModel.Train(docs, FLAGS_iter);

	ofstream ofs("result.txt");
	for (int i = 0; i < FLAGS_tnum; i++)
	{
		ofs << "Topic: " << i << endl;
		plsaModel.PrintTopic(i, identifer, ofs);
	}
	
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
