/**
 *  ==============================================================================
 *
 *          \file   Run/CVFoldCreator.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-31 07:18:51.652013
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef RUN__C_V_FOLD_CREATOR_H_
#define RUN__C_V_FOLD_CREATOR_H_
#include "Prediction/Instances/Instance.h"
#include "Run/MeltArguments.h"
namespace gezi {

	class CVFoldCreator
	{
	public:
		static ivec CreateFoldIndices(const ListInstances& data, const MeltArguments& cmd,
			const RandomEngine& rng)
		{
			if (cmd.foldsSequential)
				return CreateFoldIndicesSequential(data, cmd.numFolds, rng);
			if (cmd.stratify)
				return CreateFoldIndicesStratified(data, cmd.numFolds);
			return CreateFoldIndicesBalanced(data, cmd.numFolds);
		}

		//对每一个instance给一个分组编号，确保每一组的正反比例一致 most commonly used
		static ivec CreateFoldIndicesBalanced(const ListInstances& data, int numFolds)
		{
			ivec foldIndices(data.size(), -1);
			int numPos = 0, numNeg = 0, numUnlabeled = 0;
			for (InstancePtr instance : data)
			{
				if (instance->label > 0)
					numPos++;
				else if (instance->label <= 0)
					numNeg++;
				else
					numUnlabeled++;
			}
			int numPosPerFold = numPos / numFolds;
			int numNegPerFold = numNeg / numFolds;
			int numUnlabeledPerFold = numUnlabeled / numFolds;

			LOG(INFO) << format("In every fold, positives: %d negatives: %d unlabeled: %d") % numPosPerFold % numNegPerFold % numUnlabeledPerFold;

			int currPosFold = 0, currNegFold = 0, numCurrPos = 0, numCurrNeg = 0;
			for (size_t i = 0; i < data.size(); i++)
			{
				if (data[i]->label > 0)
				{
					foldIndices[i] = currPosFold;
					numCurrPos++;
					if (numCurrPos >= numPosPerFold)
					{
						currPosFold++;
						if (currPosFold >= numFolds)
						{
							currPosFold = 0;
							numCurrPos = numPosPerFold;
						}
						else
						{
							numCurrPos = 0;
						}
					}
				}
				else
				{
					foldIndices[i] = currNegFold;
					numCurrNeg++;
					if (numCurrNeg >= numNegPerFold)
					{
						currNegFold++;
						if (currNegFold >= numFolds)
						{
							currNegFold = 0;
							numCurrNeg = numNegPerFold;
						}
						else
						{
							numCurrNeg = 0;
						}
					}
				}
			}
			return foldIndices;
		}

		//@TODO why  //not test
		/// assign each instance to a fold sequentially.
		/// To "even out" the remaninder, randomly assign an extra instance to every fold
		static ivec CreateFoldIndicesSequential(ListInstances data, int numFolds, const RandomEngine& rng)
		{
			LOG(INFO) << "Create " << numFolds << " folds by sequential assignment";

			ivec foldIndices(data.size(), -1);
			ivec foldCnts(numFolds, 0);

			RandomDouble rand(rng);

			int instancesPerFold = data.size() / numFolds;
			int instanceIdx = 0;
			int moduloInstancesAssigned = 0;

			for (int foldIdx = 0; foldIdx < numFolds; foldIdx++)
			{
				for (int j = 0; j < instancesPerFold; j++)
				{
					foldIndices[instanceIdx++] = foldIdx;
					foldCnts[foldIdx]++;
				}
				// assign one extra for remainder to get balanced folds
				if (instanceIdx < data.size() && rand.Next() < (1.0 * (data.size() % numFolds) - moduloInstancesAssigned) / (numFolds - foldIdx))
				{
					foldIndices[instanceIdx++] = foldIdx;
					foldCnts[foldIdx]++;
					moduloInstancesAssigned++;
				}
			}
			while (instanceIdx < data.size())
			{
				foldIndices[instanceIdx++] = numFolds - 1;
				foldCnts[numFolds - 1]++;
			}

			Pvec(foldCnts);

			return foldIndices;
		}
		//@TODO 支持按照第一个name group进行交叉验证 例如 每天的评估数据一个tag  20天数据 做20次交叉验证
		//用其余天的数据train 特定某天数据test
		static ivec CreateFoldIndicesStratified(const ListInstances& data, int numFolds)
		{
			ivec result;
			return result;
		}

		static void CreateFolds(const Instances& data, Float trainProportion,
			ivec& instanceFoldIndices, int foldIdx, int numFolds,
			Instances& trainData, Instances& testData,
			const RandomEngine& rng)
		{
			trainData.CopySchema(data.schema);
			testData.CopySchema(data.schema);

			//@TODO 样本数目不会超过int
			// assign instances to either testData (if instance is in foldIdx), or trainData
			for (int i = 0; i < data.Size(); i++)
			{
				if (instanceFoldIndices[i] == foldIdx)
				{
					testData.Add(data[i]);
				}
				else if (instanceFoldIndices[i] < numFolds)
				{
						trainData.Add(data[i]);
				}
			}

			// remove (1-trainProportion)% of instances from the training fold if necessary
			// (for learning curve experiments)
			trainData.ShrinkData(trainProportion, rng);
		}
	};

}  //----end of namespace gezi

#endif  //----end of RUN__C_V_FOLD_CREATOR_H_
