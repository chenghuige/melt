/**
 *  ==============================================================================
 *
 *          \file   Trainers/Gbdt/OnlineRegressionTree.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-10 12:07:25.902949
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TRAINERS_GBDT__ONLINE_REGRESSION_TREE_H_
#define TRAINERS_GBDT__ONLINE_REGRESSION_TREE_H_
#include "common_util.h"
namespace gezi {
	//只是读入 通过TLC文本文件
	class GbdtPredictor;
	class OnlineRegressionTree
	{
	public:
		friend class GbdtPredictor;
		~OnlineRegressionTree() = default;
		OnlineRegressionTree() = default;
		OnlineRegressionTree(OnlineRegressionTree&&) = default;
		OnlineRegressionTree& operator = (OnlineRegressionTree&&) = default;
		OnlineRegressionTree(const OnlineRegressionTree&) = default;
		OnlineRegressionTree& operator = (const OnlineRegressionTree&) = default;

	public:

		//输入特征 遍历树 输出叶子节点的数值
		Float Output(Vector& features)
		{
			int index = GetLeaf(features);
#ifdef _DEBUG
			_debugNode.score = _leafValue[index];
#endif // _DEBUG
			return _leafValue[index];
		}

		void GainMap(Vector& features, map<int, double>& m)
		{
			if (NumLeaves == 1)
			{
				return;
			}
			int node = 0, preNode = 0;
			while (node >= 0)
			{
				preNode = node;
				if (features[_splitFeature[node]] <= _threshold[node])
				{
					node = _lteChild[node];
				}
				else
				{
					node = _gtChild[node];
				}

				double nowValue = node >= 0 ? _previousLeafValue[node] : _leafValue[~node];
				add_value(m, _splitFeature[preNode], nowValue - _previousLeafValue[preNode]);
			}
		}

		void Print(int node = 0, int depth = 0)
		{
			for (int i = 0; i < depth; i++)
			{
				std::cerr << "|  ";
			}
			if (node < 0)
			{
				std::cerr << _leafValue[~node] << endl;
			}
			else
			{
				std::cerr << (*_featureNames)[_splitFeature[node]] << " <= " << _threshold[node] << " ?" << endl;
				Print(_lteChild[node], depth + 1);
				Print(_gtChild[node], depth + 1);
			}
		}

		void Print(const Vector& features, int node = 0, int depth = 0, string suffix = "$")
		{
			Print(features, OnlineRegressionTree::_threshold, node, depth, suffix);
		}

		template<typename T, typename U>
		void Print(const T& features, const U& threshold, int node = 0, int depth = 0, string suffix = "$")
		{
			for (int i = 0; i < depth; i++)
			{
				std::cerr << "|  ";
			}
			std::cerr << suffix;

			if (node < 0)
			{
				if (!suffix.empty())
					std::cerr << "[" << _leafValue[~node] << "]" << endl;
				else
					std::cerr << _leafValue[~node] << endl;
			}
			else
			{
				std::cerr << boost::format("[%d] %s %.5f <= %.5f ?") %_splitFeature[node] % (*_featureNames)[_splitFeature[node]] %
					features[_splitFeature[node]] % threshold[node] << endl;
				string lsuffix = "", rsuffix = "";
				if (!suffix.empty())
				{
					if (features[_splitFeature[node]] <= threshold[node])
						lsuffix = "$";
					else
						rsuffix = "$";
				}
				Print(features, threshold, _lteChild[node], depth + 1, lsuffix);
				Print(features, threshold, _gtChild[node], depth + 1, rsuffix);
			}
		}

		int GetLeaf(const Vector& features)
		{
			return GetLeaf_(features, OnlineRegressionTree::_threshold);
		}

		void SetFeatureNames(const FeatureNamesVector& featureNames)
		{
			_featureNames = &featureNames;
		}

		FeatureNamesVector& FeatureNames()
		{
			return *_featureNames;
		}

		const FeatureNamesVector& FeatureNames() const
		{
			return *_featureNames;
		}

	protected:
		template<typename T, typename U>
		int GetLeaf_(const T& features, const U& threshold)
		{
			if (NumLeaves == 1)
			{ //training may has this case? @TODO
				return 0;
			}
			int node = 0;
			while (node >= 0)
			{
#ifdef _DEBUG
				_debugNode.paths.push_back((*_featureNames)[_splitFeature[node]]);
#endif // _DEBU
				if (features[_splitFeature[node]] <= threshold[node])
				{
					node = _lteChild[node];
				}
				else
				{

					node = _gtChild[node];
				}
			}
			return ~node; //~ means -node - 1 (~-3) --- [2]
		}
	public:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			/*	ar & NumLeaves;

				ar & _gainPValue;
				ar & _gtChild;
				ar & _leafValue;
				ar & _lteChild;
				ar & _maxOutput;
				ar & _previousLeafValue;
				ar & _splitFeature;
				ar & _splitGain;
				ar & _threshold;
				ar & _weight;*/
			//ar & _featureNames; //不要序列化指针

			ar & GEZI_SERIALIZATION_NVP(NumLeaves);

			ar & GEZI_SERIALIZATION_NVP(_gainPValue);
			ar & GEZI_SERIALIZATION_NVP(_gtChild);
			ar & GEZI_SERIALIZATION_NVP(_leafValue);
			ar & GEZI_SERIALIZATION_NVP(_lteChild);
			ar & GEZI_SERIALIZATION_NVP(_maxOutput);
			ar & GEZI_SERIALIZATION_NVP(_previousLeafValue);
			ar & GEZI_SERIALIZATION_NVP(_splitFeature);
			ar & GEZI_SERIALIZATION_NVP(_splitGain);
			ar & GEZI_SERIALIZATION_NVP(_threshold);
			ar & GEZI_SERIALIZATION_NVP(_weight);
		}
#ifdef _DEBUG
		struct DebugNode
		{
			int id;
			svec paths;
			double score;
			bool operator < (const DebugNode& other) const
			{
				return score > other.score;
			}
		};
		DebugNode _debugNode;
#endif // _DEBUG
	public:
		int NumLeaves = 1;
	protected:
		dvec _gainPValue;
		ivec _lteChild;
		ivec _gtChild;
		dvec _leafValue;
		dvec _threshold;
		ivec _splitFeature;
		dvec _splitGain;
		double _maxOutput = 0;
		dvec _previousLeafValue;
		double _weight = 1.0;
		//svec* _featureNames;
		FeatureNamesVector* _featureNames = NULL;
	};

}  //----end of namespace gezi

#endif  //----end of TRAINERS_GBDT__ONLINE_REGRESSION_TREE_H_
