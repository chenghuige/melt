/**
 *  ==============================================================================
 *
 *          \file   MLCore/IterativeTrainer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-06 20:59:42.796150
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__ITERATIVE_TRAINER_H_
#define M_L_CORE__ITERATIVE_TRAINER_H_

#include "ProgressBar.h"
#include "Trainer.h"

namespace gezi {

	class IterativeTrainer : public Trainer
	{
	public:
		virtual void BeginTrainingIteration()
		{

		}

		/// <summary>
		/// Process a given training example. 
		/// Update weights after observing a given example
		/// </summary>        
		virtual bool ProcessTrainingInstance(InstancePtr instance)
		{

		}

		/// Called after last case is sent. 
		/// Learner return true (bMoreIterations) if it wants another iteration of the data.  
		virtual void FinishTrainingIteration(bool& bMoreIterations);
		{

		}

		virtual void TrainingComplete()
		{

		}

		/// <summary>
		/// Train the classifier on a given set of instances
		/// </summary>
		virtual void InnerTrain(Instances& instances) override
		{
			bool continueTraining = true;
			long numMissingFeatureInstances = 0;
			int numCompletedIterations = 0;

			while (continueTraining)
			{
				numCompletedIterations++;
				BeginTrainingIteration();

				ProgressBar pb(instances.Count());
				int num = 0;
				for (Instance& instance : instances)
				{
					pb.progress(num);
					num++;
					continueTraining = ProcessTrainingInstance(instance);
					if (!continueTraining)
						break;
				}
				FinishTrainingIteration(out continueTraining);
			}

			TrainingComplete();
		}
	protected:
	private:

	};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__ITERATIVE_TRAINER_H_
