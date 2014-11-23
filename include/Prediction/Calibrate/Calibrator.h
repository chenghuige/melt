/**
 *  ==============================================================================
 *
 *          \file   include/Prediction/Calibrate/Calibrator.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-08 13:06:01.507769
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef INCLUDE__PREDICTION__CALIBRATE__CALIBRATOR_H_
#define INCLUDE__PREDICTION__CALIBRATE__CALIBRATOR_H_

#include "common_util.h"
#include "random_util.h"
#include "Prediction/Instances/Instances.h"
namespace gezi {

	class CalibratorStore
	{
	public:
		CalibratorStore()
		{
			rand = make_shared<Random>(RandSeed());
		}
		struct Node
		{
			Float target = 0;
			Float weight = 0;
			Float score = 0;
			Node(Float target_, Float weight_, Float score_)
				:target(target_), weight(weight_), score(score_)
			{

			}

			bool operator < (const Node& other) const
			{
				if (score == other.score)
				{
					if (weight == other.weight)
					{
						return target < other.target;
					}
					return weight < other.weight;
				}
				return score < other.score;
			}

			void Set(Float target_, Float weight_, Float score_)
			{
				target = target_;
				weight = weight_;
				score = score_;
			}
		};

		enum class StoreType { Replace, Aggregate };

		//@TODO add suport for Aggregate
		//@TODO LazySortList ?
		void Add(Float score, bool IsPositiveTarget, Float weight)
		{
			itemsSeen++;
			float target = (IsPositiveTarget ? 1 : 0);
			if (itemsSeen < maxNumSamples)
			{
				nodes.push_back(Node(target, weight, score));
				storedWeight += weight;

				if (sorted && nodes.size() > 1)
				{
					sorted = !(nodes.back() < nodes[nodes.size() - 2]);
				}
			}
			else
			{
				int draw = rand->Next(itemsSeen); // 0 to items_seen - 1

				if (draw < maxNumSamples) // keep it 
				{
					Sort();
					//@TODO _nodes[draw] = Node(target,weight,score)»áÂýÂð
					nodes[draw].Set(target, weight, score);

					if (sorted)
					{
						if (draw == 0)
						{
							sorted = !(nodes[1] < nodes[0]);
						}
						else if (draw == nodes.size() - 1)
						{
							sorted = !(nodes.back() < nodes[nodes.size() - 2]);
						}
						else
						{
							sorted = !(nodes[draw] < nodes[draw - 1] || nodes[draw + 1] < nodes[draw]);
						}
					}
				}
			}
		}

		void Sort()
		{
			if (!sorted)
			{
				std::sort(nodes.begin(), nodes.end());
				sorted = true;
			}
		}
		vector<Node>& Nodes()
		{
			return nodes;
		}

		static int RandSeed()
		{
			static int randSeed = 0;
			return randSeed++;
		}
	private:
		vector<Node> nodes;
		int maxNumSamples = 1000000;

		int itemsSeen = 0;
		Float storedWeight = 0;
		StoreType type = StoreType::Replace;
		RandomPtr rand = nullptr;
		bool sorted = false;
	};

	typedef shared_ptr<CalibratorStore> CalibratorStorePtr;
	class Calibrator : public LoadSave
	{
	public:
		virtual ~Calibrator() {}
		/// Given a classifier output, produce the probability
		virtual Float PredictProbability(Float output)
		{
			return 0.5;
		}

		virtual string Name() override
		{
			return "Calibrator";
		}

		template<typename MarginFunc>
		void Train(Instances& instances, MarginFunc marginFunc)
		{
			ProgressBar pb(instances.Count(), Name() + " calibrating");
			for (InstancePtr instance : instances)
			{
				++pb;
				ProcessTrainingExample(marginFunc(instance), instance->label > 0, instance->weight);
			}
			FinishTraining();
		}

		template<typename MarginFunc>
		void Train(Instances& instances, MarginFunc marginFunc, size_t maxCount)
		{
			size_t dealCount = std::min((size_t)maxCount, instances.Count());
			ProgressBar pb(dealCount, Name() + " calibrating");
			for (InstancePtr instance : instances) 
			{
				++pb;
				if (pb.counter() >= dealCount)
				{
					break;
				}
				ProcessTrainingExample(marginFunc(instance), instance->label > 0, instance->weight);
			}
			FinishTraining();
		}

		void Train(const Fvec& scores, const BitArray& labels, const Fvec& weights)
		{
			int len = scores.size();
			ProgressBar pb(len, Name() + " calibrating");
			for (int i = 0; i < len; i++)
			{
				++pb;
				Float weight = weights.empty() ? 1 : weights[i];
				ProcessTrainingExample(scores[i], labels[i], weight);
			}
			FinishTraining();
		}

		void Train(const Fvec& scores, const BitArray& labels)
		{
			int len = scores.size();
			ProgressBar pb(len, Name() + " calibrating");
			for (int i = 0; i < len; i++)
			{
				++pb;
				ProcessTrainingExample(scores[i], labels[i], 1);
			}
			FinishTraining();
		}

		virtual void ProcessTrainingExample(Float output, bool clicked, Float weight)
		{

		}

		virtual void FinishTraining()
		{

		}
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
		}
	};
	typedef shared_ptr<Calibrator> CalibratorPtr;

	class CalibratorWrapper : public Calibrator
	{
	public:
		virtual ~CalibratorWrapper() {}
		/// Training calibrators:  provide the classifier output and the class label
		virtual void ProcessTrainingExample(Float output, bool clicked, Float weight) override
		{
			if (_data == nullptr)
				_data = make_shared<CalibratorStore>();
			_data->Add(output, clicked, weight);
		}

		virtual void FinishTraining()
		{
			_data->Sort();
			TrainModel(*_data);
		}

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			//ar & boost::serialization::base_object<Calibrator>(*this);
			ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Calibrator);
		}

	protected:

		virtual void TrainModel(CalibratorStore& data)
		{

		}
	private:
		CalibratorStorePtr _data = nullptr;
	};


}  //----end of namespace gezi

#endif  //----end of INCLUDE__PREDICTION__CALIBRATE__CALIBRATOR_H_
