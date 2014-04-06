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

namespace gezi {

class Trainer 
{
public:
	~Trainer() = default;
	Trainer() = default;
	Trainer(Trainer&&) = default;
	Trainer& operator = (Trainer&&) = default;
	Trainer(const Trainer&) = default;
	Trainer& operator = (const Trainer&) = default;
public:

protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TRAINER_H_
