/**
 *  ==============================================================================
 *
 *          \file   Trainers/BoostedTree/RegressionTree.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-10 12:07:25.902949
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TRAINERS_BOOSTEDTREE__REGRESSION_TREE_H_
#define TRAINERS_BOOSTEDTREE__REGRESSION_TREE_H_
#include "common_util.h"
namespace gezi {

class RegressionTree 
{
public:
	~RegressionTree() = default;
	RegressionTree() = default;
	RegressionTree(RegressionTree&&) = default;
	RegressionTree& operator = (RegressionTree&&) = default;
	RegressionTree(const RegressionTree&) = default;
	RegressionTree& operator = (const RegressionTree&) = default;

	RegressionTree(int maxLeaves)
	{
		int internalNodeNum = maxLeaves - 1;
		_splitFeature.resize(internalNodeNum, 0);
		_splitGain.resize(internalNodeNum, 0);
		_gainPValue.resize(internalNodeNum, 0);
		_previousLeafValue.resize(internalNodeNum, 0);
		_threshold.resize(internalNodeNum, 0);
		_lteChild.resize(internalNodeNum, 0);
		_gtChild.resize(internalNodeNum, 0);
		_leafValue.resize(maxLeaves);
	}

public:
	//@TODO  BITWISE COPY?
	//namespace boost {  namespace serialization {
 //    template <class Archive>
 //    void serialize(Archive& ioArchive, BigStruct& ioStruct, const unsigned
 //int iVersion)
 //    {
 //      ioArchive & ioStruct.m1;
 //      ioArchive & ioStruct.m2;
	//		....
 //    } } }
 //#include <boost/serialization/is_bitwise_serializable.hpp>
 //BOOST_IS_BITWISE_SERIALIZABLE(BigStruct);
 //}}}
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & _gainPValue;
			ar & _gtChild;
			ar & _leafValue;
			ar & _lteChild;
			ar & _maxOutput;
			ar & _numLeaves;
			ar & _previousLeafValue;
			ar & _splitFeature;
			ar & _splitGain;
			ar & _threshold;
			ar & _weight;
		}
protected:
private:
		dvec _gainPValue;
		ivec _gtChild;
		dvec _leafValue;
		ivec _lteChild;
		double _maxOutput = 0;
		int _numLeaves = 1;
		dvec _previousLeafValue;
		ivec _splitFeature;
		dvec _splitGain;
		uvec _threshold; //fastrank¿Ô√Ê «uit ?@TODO
		double _weight = 1.0;
};

}  //----end of namespace gezi

#endif  //----end of TRAINERS_BOOSTEDTREE__REGRESSION_TREE_H_
