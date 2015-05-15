/**
 *  ==============================================================================
 *
 *          \file   Predictors/FastRankPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-13 18:24:51.525674
 *
 *  \Description: 
 *              
 *  ==============================================================================
 */

#ifndef PREDICTORS__FAST_RANK_PREDICTOR_H_
#define PREDICTORS__FAST_RANK_PREDICTOR_H_
#include "Identifer.h"
#include "MLCore/Predictor.h"
#include "Trainers/FastRank/OnlineRegressionTree.h"
namespace gezi {

	class FastRankPredictor : public Predictor
	{
	public:
		virtual string Name() override
		{
			return "FastRank";
		}

		FastRankPredictor() = default;

		FastRankPredictor(vector<OnlineRegressionTree>& trees, CalibratorPtr calibrator, 
			svec&& featureNames)
			:Predictor(nullptr, calibrator, featureNames)
		{
			_trees.swap(trees);
		}

		FastRankPredictor(string modelPath)
		{
			Load(modelPath);
		}

		//Load Tlc format的文本模型文件
		virtual void LoadText(string file) override
		{
			Identifer identifer;

			_textModelPath = file;
			LoadSave::Load(file);

			svec lines = read_lines(file);

			size_t i = 0;
			for (; i < lines.size(); i++)
			{
				if (startswith(lines[i], "[FeatureNames]"))
				{
					i++;
					break;
				}
			}
			int featureNum = parse_int_param("FeatureNum=", lines[i++]);
			Pval(featureNum);
			for (int j = 0; j < featureNum; j++)
			{
				identifer.add(lines[i++]);
			}

			for (; i < lines.size(); i++)
			{
				if (startswith(lines[i], "[TreeEnsemble]"))
				{
					i++;
					break;
				}
			}

			int inputs = parse_int_param("Inputs=", lines[i++]);
			Pval(inputs);
			int treeNum = parse_int_param("Evaluators=", lines[i++]) - 2; //-sum tree -sigmoid
			Pval(treeNum);

			svec fnames(inputs);
			for (int j = 0; j < inputs; j++)
			{
				for (; i < lines.size(); i++)
				{
					if (startswith(lines[i], "[Input:"))
					{
						i += 2;
						break;
					}
				}
				fnames[j] = parse_string_param("Name=", lines[i++]);
			}

			for (int j = 0; j < treeNum; j++)
			{
				for (; i < lines.size(); i++)
				{
					if (startswith(lines[i], "[Evaluator:"))
					{
						i += 2;
						break;
					}
				}
				int maxLeaves = parse_int_param("NumInternalNodes=", lines[i++]);
				PVAL(maxLeaves);
				{
					OnlineRegressionTree tree;
					string splits = parse_string_param("SplitFeatures=", lines[i++]);
					tree._splitFeature = from(split(splits, '\t')) >> select([&](string a)
					{
						int index = identifer.id(fnames[INT(split(a, ':')[1]) - 1]);
						CHECK_GE(index, 0);
						return index;
					}) >> to_vector();

					string splitGains = parse_string_param("SplitGain=", lines[i++]);
					tree._splitGain = from(split(splitGains)) >> select([](string a) { return DOUBLE(a); }) >> to_vector();

					string gainPvalues = parse_string_param("GainPValue=", lines[i++]);
					tree._gainPValue = from(split(gainPvalues)) >> select([](string a) { return DOUBLE(a); }) >> to_vector();

					string lefts = parse_string_param("LTEChild=", lines[i++]);
					tree._lteChild = from(split(lefts)) >> select([](string a) { return INT(a); }) >> to_vector();
					string rights = parse_string_param("GTChild=", lines[i++]);
					tree._gtChild = from(split(rights)) >> select([](string a) { return INT(a); }) >> to_vector();

					string thrsholds = parse_string_param("Threshold=", lines[i++]);
					tree._threshold = from(split(thrsholds)) >> select([](string a) { return DOUBLE(a); }) >> to_vector();

					string outputs = parse_string_param("Output=", lines[i++]);
					tree._leafValue = from(split(outputs)) >> select([](string a) { return DOUBLE(a); }) >> to_vector();
					_trees.emplace_back(tree);
				}
			}

			for (; i < lines.size(); i++)
			{
				if (startswith(lines[i], "[Evaluator:"))
				{
					i += 2;
					break;
				}
			}

			for (; i < lines.size(); i++)
			{
				if (startswith(lines[i], "[Evaluator:"))
				{
					i += 3;
					break;
				}
			}

			//--------------设置特征名称
			_featureNames = move(identifer.keys());

			for (auto& tree : _trees)
			{
				tree._featureNames = &_featureNames;
			}

			//-------------calibrator
			double paramB = -parse_double_param("Bias=", lines[i]);
			double paramA = -parse_double_param("Weights=", lines[i + 3]);
			Pval2(paramA, paramB);
			_calibrator = make_shared<SigmoidCalibrator>(paramA, paramB);
		}

		virtual void Save_(string file) override
		{
			if (!_textModelPath.empty())
			{ //Hack 拷贝模型文本文件 便于跟踪
				string modelTextFile = file + ".txt";
				copy_file(_textModelPath, modelTextFile);
			}
			serialize_util::save(*this, file);
		}

		virtual void SaveXml_(string file) override
		{
			serialize_util::save_xml(*this, file);
		}

		virtual void SaveJson_(string file) override
		{
			serialize_util::save_json(*this, file);
		}

		virtual void Load_(string file) override
		{
			serialize_util::load(*this, file);
			for (auto& tree : _trees)
			{
				tree._featureNames = &_featureNames;
			}
		}

		void FeatureGainPrint(Vector& features, int level = 0)
		{
			VLOG(level) << "Per feature gain for this predict:\n" <<
				ToGainSummary(features);
		}

		map<int, double> GainMap(Vector& features)
		{
			map<int, double> m;
			if (_trees.empty())
			{
				return m;
			}

			for (auto& tree : _trees)
			{
				tree.GainMap(features, m);
			}
			
			return m;
		}

		string ToGainSummary(Vector& features)
		{
			map<int, double> m = GainMap(features);
	
			vector<pair<int, double> > sortedByGain;
			sort_map_by_absvalue_reverse(m, sortedByGain);

			stringstream ss;
			int id = 0;
			for (auto item : sortedByGain)
			{
				ss << setiosflags(ios::left) << setfill(' ') << setw(40)
					<< STR(id++) + ":" + _featureNames[item.first]
					<< "\t" << m[item.first] 
					<< "\t" << features[item.first]
					<< endl;
			}
			return ss.str();
		}
	protected:
		//注意都是非稀疏的输入应该 稀疏会影响速度 但是不影响结果 而且对于线上 即使稀疏快一点 也无所谓了...
		virtual Float Margin(Vector& features) override
		{
			Float result = 0;
#pragma omp parallel for reduction(+: result)
			for (size_t i = 0; i < _trees.size(); i++)
			{
				result += _trees[i].Output(features);
#ifdef _DEBUG
#pragma  omp critical
				{
					//if (_trees[i]._debugNode.score > 0)
					{
						_trees[i]._debugNode.id = i;
						_debugNodes.emplace_back(_trees[i]._debugNode);
					}
				}
#endif // _DEBUG
			}
#ifdef _DEBUG
			if (!_reverse)
				sort(_debugNodes.begin(), _debugNodes.end());
			else
				sort(_debugNodes.begin(), _debugNodes.end(), [](const OnlineRegressionTree::DebugNode& l,
				const OnlineRegressionTree::DebugNode& r)
			{
				return l.score < r.score;
			});
			int num = 0;
			for (OnlineRegressionTree::DebugNode& node : _debugNodes)
			{
				if (!_reverse && node.score >= 0 || _reverse && node.score <= 0)
				{
					VLOG(3) << "tree: " << node.id << "\t" << "score: " << node.score << "\t" << "depth: " << node.paths.size();
					PVEC(node.paths);
				}
				else
				{
					VLOG(1) << "Total " << num << " trees show";
					break;
				}
				num++;
			}
#endif // _DEBUG
			return result;
		}

		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
		/*	ar & boost::serialization::base_object<Predictor>(*this);
			ar & _trees;*/
			ar & CEREAL_BASE_OBJECT_NVP(Predictor);
			ar & CEREAL_NVP(_trees);
		}

		vector<OnlineRegressionTree>& Trees()
		{
			return _trees;
		}
#ifdef _DEBUG
		void SetReverse(bool reverse = true)
		{
			_reverse = reverse;
		}
#endif // _DEBUG

	private:
#ifdef _DEBUG
		vector<OnlineRegressionTree::DebugNode> _debugNodes;
		bool _reverse = false;
#endif // _DEBUG

		vector<OnlineRegressionTree> _trees;

		//temply used shared between load save function
		string _textModelPath;
	};

	class FastRankRegressionPredictor : public FastRankPredictor
	{
	public:
		using FastRankPredictor::FastRankPredictor;
		virtual PredictionKind GetPredictionKind()
		{
			return PredictionKind::Regression;
		}
	};
}  //----end of namespace gezi

#endif  //----end of PREDICTORS__FAST_RANK_PREDICTOR_H_
