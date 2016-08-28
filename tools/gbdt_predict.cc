/**
 *  ==============================================================================
 *
 *          \file   gbdt_predict.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-14 18:27:45.210850
 *
 *  \Description:
 *
 *  ==============================================================================
 */
#define _DEBUG
#define private public
#define protected public
#include "common_util.h"
#include "MLCore/PredictorFactory.h"
#include "Predictors/GbdtPredictor.h"
using namespace std;
using namespace gezi;

DEFINE_int32(vl, 0, "vlog level, if you set to 3 you can see each tree score");

DEFINE_bool(pts, false, "print trees scores");
DEFINE_int32(n, -1, "print num trees scores if pts == true, if num < 0 print all trees scores");
DEFINE_bool(r, false, "reverse: show trees from -.. to + .. if reverse == true");

DEFINE_bool(s, true, "sortByGain|sort==true, will print by abs gain per feature, otherwise will print by feature id");
DEFINE_int32(t, -1, "tree index to print");
DEFINE_int32(si, 0, "startIndex| start from 0 default or start from 1 like libsvm");

DEFINE_string(m, "model", "modelPath");
DEFINE_string(f, "", "featureStr");

void run(string feature, string modelPath)
{
	//因为用了_DEBUG GbdtPredictor的debugNodes造成这里Load会core  @TODO,所以这里只能直接用GbdtPredictor了，GbdtRegression 和 GbdtRank唯一区别在于 PredictorKind不一样，预测的
	//probalibity和output一致
	//auto predictor = PredictorFactory::LoadPredictor(modelPath);
	GbdtPredictor predictor(modelPath);
	int startIndex = FLAGS_si;
	Vector fe(feature, startIndex);
	double predict;
	double probablity = predictor.Predict(fe, predict);
	string predictorName = read_file(modelPath + "/model.name.txt");
	VLOG(0) << "predictorName:" << predictorName << " -- Notice for non gbdt binary classification model, proababilty is meaning less";
	if (predictorName != "gbdt" && predictorName != "fastrank" && predictorName != "fr")
	{
		probablity = predict;
	}
	Pval2(predict, probablity);

	bool printTreesScores = FLAGS_pts;
	bool sort = FLAGS_s;
	bool reverse = FLAGS_r;
	int maxTrees = FLAGS_n;

	//--------------------打印所有树的得分
	if (printTreesScores)
	{
		VLOG(0) << "Print Trees Scores, sortByScore: " << sort << " revrese: " << reverse << " maxTreesPrint: " << maxTrees;
		predictor.PrintTreeScores(sort, reverse, maxTrees);
		return;
	}

	//-------------------打印某一颗树
	int treeIndex = FLAGS_t;
	if (treeIndex >= 0)
	{
		VLOG(0) << "Print tree: " << treeIndex;
		predictor.Trees()[treeIndex].Print(fe);
		return;
	}

	//--------------------打印单次预测的特征重要度(最常用)
	{
		VLOG(0) << "Per feature gain for this predict, sortByGain: " << sort << endl
			<< predictor.ToGainSummary(fe, sort);
		Pval2(predict, probablity);
	}
}



int main(int argc, char *argv[])
{
	google::InitGoogleLogging(argv[0]);
	google::InstallFailureSignalHandler();
	google::SetVersionString(get_version());
	int s = google::ParseCommandLineFlags(&argc, &argv, false);
	if (FLAGS_log_dir.empty())
		FLAGS_logtostderr = true;
	if (FLAGS_v == 0)
		FLAGS_v = FLAGS_vl;

	run(FLAGS_f, FLAGS_m);

	return 0;
}

