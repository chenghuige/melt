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

namespace gezi {

class IterativeTrainer 
{
public:
	~IterativeTrainer() = default;
	IterativeTrainer() = default;
	IterativeTrainer(IterativeTrainer&&) = default;
	IterativeTrainer& operator = (IterativeTrainer&&) = default;
	IterativeTrainer(const IterativeTrainer&) = default;
	IterativeTrainer& operator = (const IterativeTrainer&) = default;
public:

protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__ITERATIVE_TRAINER_H_
