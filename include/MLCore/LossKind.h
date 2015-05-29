/**
 *  ==============================================================================
 *
 *          \file   MLCore/LossKind.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-27 11:08:15.420538
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__LOSS_KIND_H_
#define M_L_CORE__LOSS_KIND_H_

namespace gezi {

enum class LossKind
{
	Unknown = 0,
	GoldStandard = 1, //(ideal case)又被称为0-1 loss， 记录分类错误的次数
	Squared = 2, //(linear regression) L2 error
	Logistic = 3, // (logistic regression, cross entropy error) gbdt binary classification
	Hinge = 4, //Hinge (SVM, soft margin)
	Exponential =5, //Exponential loss (Boosting) 
};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__LOSS_KIND_H_
