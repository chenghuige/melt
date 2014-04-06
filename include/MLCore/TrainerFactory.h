/**
 *  ==============================================================================
 *
 *          \file   MLCore/TrainerFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-06 21:25:59.801819
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__TRAINER_FACTORY_H_
#define M_L_CORE__TRAINER_FACTORY_H_

namespace gezi {

class TrainerFactory 
{
public:
	~TrainerFactory() = default;
	TrainerFactory() = default;
	TrainerFactory(TrainerFactory&&) = default;
	TrainerFactory& operator = (TrainerFactory&&) = default;
	TrainerFactory(const TrainerFactory&) = default;
	TrainerFactory& operator = (const TrainerFactory&) = default;
public:

protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TRAINER_FACTORY_H_
