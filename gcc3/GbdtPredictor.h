/**
 *  ==============================================================================
 *
 *          \file   GbdtPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-19 09:51:17.800366
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef GBDT_PREDICTOR_H_
#define GBDT_PREDICTOR_H_
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cmath>


namespace melt
{
	class GbdtPredictor;
	class RegressionTree
	{
	public:
		friend class GbdtPredictor;
		RegressionTree()
			:NumLeaves(1), _maxOutput(0.0), _weight(1.0)
		{

		}
	public:
		//输入特征 遍历树 输出叶子节点的数值
		double Output(const std::vector<double>& features)
		{
			int node = 0;
			while (node >= 0)
			{
				if (features[_splitFeature[node]] <= _threshold[node])
				{
					node = _lteChild[node];
				}
				else
				{
					node = _gtChild[node];
				}
			}

			return _leafValue[~node];
		}

	public:
		int NumLeaves;
	protected:
		std::vector<double> _gainPValue;
		std::vector<int> _lteChild;
		std::vector<int> _gtChild;
		std::vector<double> _leafValue;
		std::vector<double> _threshold;
		std::vector<int> _splitFeature;
		std::vector<double> _splitGain;
		double _maxOutput;
		std::vector<double> _previousLeafValue;
		double _weight;
	};

	template<typename _Node>
	void read_vec(std::ifstream& ifs, std::vector<_Node>& vec)
	{
		vec.clear();
		int len;
		ifs.read(reinterpret_cast<char*> (&len), sizeof(len));
		vec.resize(len);
		ifs.read(reinterpret_cast<char*> (&vec[0]), sizeof(_Node) * len);
	}

	template<typename T>
	void read_elem(std::ifstream& ifs, T& elem)
	{
		ifs.read(reinterpret_cast<char*> (&elem), sizeof(elem));
	}

	inline double sigmoid(double score, double A, double B)
	{
		return 1.0 / (1 + std::exp(A * score + B));
	}

	class GbdtPredictor
	{
	public:

		GbdtPredictor()
		{

		}

		GbdtPredictor(std::string path)
		{
			Load(path);
		}

		inline double Predict(const std::vector<double>& features)
		{
			return sigmoid(Output(features), _paramA, _paramB);
		}

		double Output(const std::vector<double>& features)
		{
			double result = 0;
			for (size_t i = 0; i < _trees.size(); i++)
			{
				result += _trees[i].Output(features);
			}
			return result;
		}

		inline double Predict(const std::vector<double>& features, double& output)
		{
			output = Output(features);
			return sigmoid(output, _paramA, _paramB);
		}

		void Load(std::string path)
		{
			std::ifstream ifs((path + "/model.bin.gcc3").c_str(), std::ios::binary);
			int ntrees;
			read_elem(ifs, ntrees);
			std::cout << "ntrees: " << ntrees << std::endl;
			_trees.resize(ntrees);
			for (int i = 0; i < ntrees; i++)
			{
				//std::cout << "Loading Tree: " << i << std::endl;
				LoadTree(ifs, _trees[i]);
			}
			read_elem(ifs, _paramA);
			read_elem(ifs, _paramB);
		}
	private:
		void LoadTree(std::ifstream& ifs, RegressionTree& tree)
		{
			read_elem(ifs, tree.NumLeaves);
			read_elem(ifs, tree._maxOutput);
			read_elem(ifs, tree._weight);
			//std::cout << tree.NumLeaves << " " << tree._maxOutput << " " << tree._weight << std::endl;
			read_vec(ifs, tree._gainPValue);
			read_vec(ifs, tree._lteChild);
			read_vec(ifs, tree._gtChild);
			read_vec(ifs, tree._leafValue);
			read_vec(ifs, tree._threshold);
			read_vec(ifs, tree._splitFeature);
			read_vec(ifs, tree._splitGain);
			read_vec(ifs, tree._previousLeafValue);
		}
	private:
		std::vector<RegressionTree> _trees;
		double _paramA;
		double _paramB;
	};

} //-----------end of namespace melt

#endif  //----end of GBDT_PREDICTOR_H_
