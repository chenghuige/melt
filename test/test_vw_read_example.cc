/**
 *  ==============================================================================
 *
 *          \file   test_vw_read_example.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-19 17:58:54.319374
 *
 *  \Description:
 *
 *  ==============================================================================
 */

#define _DEBUG
#define private public
#define protected public
#include "common_util.h"

#include "vowpalwabbit/parser.h"
#include "vowpalwabbit/simple_label.h"
#include "vowpalwabbit/parse_args.h"
#include "vowpalwabbit/vw.h"
#include "vowpalwabbit/example.h"

using namespace std;
using namespace gezi;
DEFINE_int32(vl, 5, "vlog level");
DEFINE_string(i, "", "input");
DEFINE_string(o, "", "output");
DEFINE_string(type, "simple", "");

vw* _vw;
example* _example;
TEST(vw_read_example, func)
{
	_vw = VW::initialize("");

	{
		string line = "1 |n 1:1 2:0.333333 3:1 2230301:1";
		_example = VW::read_example(*_vw, const_cast<char*>(line.c_str()));
		Pval(((*_example).indices.end - (*_example).indices.begin));
		Pval(((*_example).atomics[0].end - (*_example).atomics[0].begin));
		Pval(_example->num_features);
	}

	{
		string line = "1 |n 5:0.0606061 6:0.5 7:1 8:1 9:1 10:1 11:1 12:1 13:0.0588235 14:1 15:0.333333 16:1 17:1 18:1 19:0.2 20:1 21:1 22:1 23:0.2 24:1 25:1 26:1 27:0.0740741 28:1 29:0.666667 30:1 31:0.0196078 32:1 33:0.1 34:1 35:1 36:1 37:0.333333 38:1 39:1 40:1 41:1 42:1 43:1 44:1 45:0.333333 46:1 47:1 48:1 49:0.5 50:1 51:1 52:0.5 53:0.25 54:1 55:1 56:1 57:0.5 58:0.5 59:1 60:1 61:0.5 62:1 63:1 64:1 65:0.25 66:0.5 67:1 68:1 69:1 70:1 71:1 72:1 73:0.5 74:1 75:1 76:1 77:0.333333 78:1 79:1 80:0.5 81:1 82:1 83:1 2230301:1";
		_example = VW::read_example(*_vw, const_cast<char*>(line.c_str()));
		Pval(((*_example).indices.end - (*_example).indices.begin));
		Pval(((*_example).atomics[0].end - (*_example).atomics[0].begin));
		Pval(_example->num_features);
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
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	return RUN_ALL_TESTS();
}
