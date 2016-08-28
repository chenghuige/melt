/**
 *  ==============================================================================
 *
 *          \file   Testers/Tester.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-12 08:43:43.467924
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TESTERS__TESTER_H_
#define TESTERS__TESTER_H_
#include "common_util.h"
#include "MLCore/Predictor.h"
#include "Testers/DatasetMetrics.h"

namespace gezi {
	/************************************************************************/
	/* Tester
		1. 逐行处理测试文件写预测结果到文件  同时不同的Tester可以有不同的输出field
		2. 逐行处理的过程中进行统计，比如错分数目等等,可调用多个工具类比如 Auc PrecisionRecall 或者干脆统一一个
		*/
	/************************************************************************/
	class Tester
	{
	public:
		virtual ~Tester() {}
		virtual PredictionKind GetPredictionKind() = 0;
		virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics() = 0;

		void WriteHeader(Instances& instances)
		{
			if (runIdx != -1)
			{
				ofs << "RunIndex\t";
			}
			if (foldIdx != -1)
			{
				ofs << "FoldIndex\t";
			}
			ofs << instances.schema.instanceNameHeaderString;
			if (hasRankingMetric)
			{
				ofs << "\tGroupKey";
			}
			ofs << "\t" << datasetMetrics[0]->LabelColumnName();
			if (hasWeights)
			{
				ofs << "\tWeight";
			}

			//@TODO select_many not work as this , how to use?
			//auto perInstanceColumns = from(datasetMetrics) >> select_many([](const DatasetMetricsPtr& m) { return m->PerInstanceColumnNames(); }) >> to_vector();
			svec perInstanceColumns = gezi::join_vec<string>(datasetMetrics, [](const DatasetMetricsPtr& a) { return a->PerInstanceColumnNames(); });
			if (!perInstanceColumns.empty())
			{
				ofs << "\t" << gezi::join(perInstanceColumns, "\t");
			}
			ofs << endl;
		}

		static string InstanceName(InstancePtr instance)
		{
			string name;
			if (!instance->name.empty())
			{
				name = instance->name;
			}
			else if (!instance->names.empty())
			{
				name = gezi::join(instance->names, "\t");
			}

			if (startswith(name, '_'))
			{
				name = name.substr(1);
			}
			return name;
		}

		/// <summary>
		/// print the per-instance line into the output file
		/// </summary>
		void PrintInstanceOutput(int64 instanceCnt, InstancePtr instance, const vector<double>& instanceMetrics, string groupKey = "")
		{
			if (runIdx != -1)
			{
				ofs << runIdx << "\t";
			}
			if (foldIdx != -1)
			{
				ofs << foldIdx << "\t";
			}

			string name = InstanceName(instance);
			if (name.empty())
			{
				ofs << instanceCnt << "\t";
			}
			else
			{
				ofs << name << "\t";
			}

			if (!groupKey.empty())
			{
				ofs << groupKey << "\t";
			}

			ofs << instance->label;
			
			if (hasWeights)
			{
				ofs << "\t" << instance->weight;
			}

			for (auto& v : instanceMetrics)
			{
				ofs << "\t" << v;
			}

			ofs << endl;
		}

		virtual void ProcessInstances(Instances instances, PredictorPtr predictor) 
		{
			//这个地方用omp反而更慢了,如果predictor内部用了openmp的话  @TODO better handle this
			//			vector<Float> predictions(instances.size(), 0);
			//			vector<Float> probabilities(instances.size(), std::numeric_limits<double>::quiet_NaN());
			//#pragma omp parallel for
			//			for (size_t i = 0; i < instances.size(); i++)
			//			{
			//				probabilities[i] = predictor->Predict(instances[i], predictions[i]);
			//			}

			//@TODO test instances考虑streaming方式？
			vector<Float> predictions;
			auto probabilities = predictor->BulkPredict(instances, predictions);

			for (size_t i = 0; i < instances.size(); i++)
			{
				auto instance = instances[i];
				Float label = instance->label;
				Float weight = instance->weight;
				//Float prediction = 0, probability = std::numeric_limits<double>::quiet_NaN();
				//probability = predictor->Predict(instance, prediction);
				Float prediction = predictions[i];
				Float probability = probabilities[i];
				dvec perInstanceOutputs = gezi::join_vec<double>(datasetMetrics, [&](const DatasetMetricsPtr& datasetMetric) { return datasetMetric->ProcessInstance(label, prediction, probability, weight); });
				if (ofs.is_open())
				{
					PrintInstanceOutput(i, instance, perInstanceOutputs);
				}
				//如果是交叉验证为了得到一个全局结果 这里有重复计算
				if (isCrossValidationMode)
				{
					gezi::join_vec<double>(globalDatasetMetrics, [&](const DatasetMetricsPtr& datasetMetric) { return datasetMetric->ProcessInstance(label, prediction, probability, weight); });
				}
			}

			FinalizeProcessInstances();
		}

		void Finalize()
		{
			if (isCrossValidationMode)
			{
				fmt::print_line("OVERALL RESULTS");
				fmt::print_line("---------------------------------------");
				for (auto& datasetMetric : globalDatasetMetrics)
				{
					datasetMetric->Print();
				}
			}
		}

		//可以一个Tester连续使用Test datasetMetrics = ConstructDatasetMetrics();确保结果清空每次
		void Test(Instances& instances, PredictorPtr predictor, string lossOutfile = "")
		{
			datasetMetrics = ConstructDatasetMetrics();

			if (isCrossValidationMode && globalDatasetMetrics.empty())
			{
				globalDatasetMetrics = ConstructDatasetMetrics();
			}

			if (!lossOutfile.empty() && !ofs.is_open())
			{
				ofs.open(lossOutfile);
			}

			if (writeTSVHeader && ofs.is_open())
			{
				WriteHeader(instances);
			}

			ProcessInstances(instances, predictor);
		}

	protected:
		void FinalizeProcessInstances()
		{
			for (auto& datasetMetric : datasetMetrics)
			{
				datasetMetric->Print();
			}
			fmt::print_line(foldSeparatorString);
		}

	public:
		bool writeTSVHeader = true;
		int runIdx = -1;
		int foldIdx = -1;

		bool collectOutputsAndLabels = false;
		bool hasWeights = false;
		bool hasRankingMetric = false;

		ofstream ofs; //输出inst文件使用
		vector<DatasetMetricsPtr> datasetMetrics;
		vector<DatasetMetricsPtr> globalDatasetMetrics; //交叉验证时使用
		string foldSeparatorString = "----------------------------------------------------------------------------------------";

		bool isCrossValidationMode = false; //交叉验证的时候用true来表示需要一个每轮结果累加的Tester
	protected:
	private:
	};

	typedef shared_ptr<Tester> TesterPtr;

}  //----end of namespace gezi

#endif  //----end of TESTERS__TESTER_H_
