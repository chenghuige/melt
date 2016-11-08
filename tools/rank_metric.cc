/**
 *  ==============================================================================
 *
 *          \file   rank_metric.cc
 *
 *        \author   chenghuige
 *
 *          \date   2016-11-1
 *
 *  \Description:
 *
 *  ==============================================================================
 */
#define _DEBUG
#define private public
#define protected public
#include "common_util.h"
#include "Testers/RankerTester.h"
using namespace std;
using namespace gezi;

void run()
{
  TesterPtr tester = make_shared<RankerTester>();
  tester->Test(std::cin);
}

int main(int argc, char *argv[])
{
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
  google::SetVersionString(get_version());
  int s = google::ParseCommandLineFlags(&argc, &argv, false);
  if (FLAGS_log_dir.empty())
    FLAGS_logtostderr = true;

  run();

  return 0;
}

