#ifndef M_L_CORE__TRAINER_FACTORY_H_
#define M_L_CORE__TRAINER_FACTORY_H_
#include "MLCore/Trainer.h"
namespace gezi {
class TrainerFactory
{
public:
static TrainerPtr CreateTrainer(string name_);
static void PrintTrainersInfo();
protected:
private:
};
}
#endif
