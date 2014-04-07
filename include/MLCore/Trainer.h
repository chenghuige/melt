/**
 *  ==============================================================================
 *
 *          \file   MLCore/Trainer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-06 20:47:13.472915
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__TRAINER_H_
#define M_L_CORE__TRAINER_H_
#include "common_def.h"
#include "Prediction/Instances/Instances.h"
#include "MLCore/Predictor.h"
namespace gezi {

class Trainer 
{
public:
	void Train(Instances& instances)
	{
		_trainingSchema = instances.schema;

		Initialize(instances);

		InnerTrain(instances);

		Finalize(instances);
	}

	const HeaderSchema& TrainingSchema() const
	{
		return _trainingSchema;
	}

	virtual PredictorPtr CreatePredictor() = 0;

protected:
	virtual void Initialize(Instances& instances)
	{

	}
	virtual void InnerTrain(Instances& instances)
	{

	}

	virtual void Finalize(Instances& instances)
	{

	}
private:
	HeaderSchema _trainingSchema;
};

typedef shared_ptr<Trainer> TrainerPtr;

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TRAINER_H_
