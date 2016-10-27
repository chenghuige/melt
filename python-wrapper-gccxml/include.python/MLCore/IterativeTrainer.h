#ifndef M_L_CORE__ITERATIVE_TRAINER_H_
#define M_L_CORE__ITERATIVE_TRAINER_H_
#include "ProgressBar.h"
#include "Trainer.h"
namespace gezi {
interface IterativeTrainer : public ValidatingTrainer
{
public:
virtual void BeginTrainingIteration();
virtual bool ProcessTrainingInstance(InstancePtr instance);
virtual void FinishTrainingIteration(bool& bMoreIterations);
virtual void TrainingComplete();
virtual void InnerTrain(Instances& instances);
protected:
private:
};
}
#endif
