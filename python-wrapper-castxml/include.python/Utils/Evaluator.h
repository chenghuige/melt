#ifndef UTILS__EVALUATOR_H_
#define UTILS__EVALUATOR_H_
#include "evaluate.h"
#include "Prediction/Instances/Instance.h"
namespace gezi {
namespace ev = evaluate;
class Evaluator
{
public:
virtual string Name() const = 0;
virtual bool LowerIsBetter() const;
virtual bool UseProbability() const;
virtual Float Evaluate(const vector<Float>& predictions, const vector<InstancePtr>& instances);
virtual Float Evaluate(const vector<Float>& predictions, const vector<Float>& probabilities, const vector<InstancePtr>& instances);
virtual Float Evaluate(const vector<Float>& predictions, const vector<Float>& labels, const vector<Float>& weights);
virtual Float Evaluate(vector<EvaluateNode>& results);
void Add(Float label, Float prediction, Float weight = 1.0);
virtual Float Finalize();
protected:
void Clear();
Float Evaluate();
virtual Float Evaluate(const vector<Float>& predictions, const vector<EvaluateInstancePtr>& instances);
protected:
vector<Float> _predictions;
vector<shared_ptr<EvaluateInstance> > _instances;
};
typedef shared_ptr<Evaluator> EvaluatorPtr;
template<typename Derived>
class EvaluatorImpl : public Evaluator
{
public:
virtual string Name() const = 0;
virtual bool LowerIsBetter() const;
virtual Float Evaluate(const vector<Float>& predictions, const vector<InstancePtr>& instances);
protected:
virtual Float Evaluate(const vector<Float>& predictions, const vector<EvaluateInstancePtr>& instances);
};
template<typename Derived>
class OuputEvaluatorImpl : public EvaluatorImpl < Derived >
{
public:
virtual bool UseProbability() const;
};
class AucEvaluator : public OuputEvaluatorImpl<AucEvaluator>
{
public:
virtual string Name() const;
virtual bool LowerIsBetter() const;
virtual Float Evaluate(vector<EvaluateNode>& results);
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class L1Evaluator : public EvaluatorImpl<L1Evaluator>
{
public:
virtual string Name() const;
virtual Float Evaluate(vector<EvaluateNode>& results);
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class L2Evaluator : public EvaluatorImpl<L2Evaluator>
{
public:
virtual string Name() const;
virtual Float Evaluate(vector<EvaluateNode>& results);
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class RMSEEvaluator : public EvaluatorImpl<RMSEEvaluator>
{
public:
virtual string Name() const;
virtual Float Evaluate(vector<EvaluateNode>& results);
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class GoldStandardEvaluator : public EvaluatorImpl < GoldStandardEvaluator >
{
public:
virtual string Name() const;
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class GoldStandardOutputEvaluator : public OuputEvaluatorImpl < GoldStandardOutputEvaluator >
{
public:
virtual string Name() const;
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class LogLossEvaluator : public EvaluatorImpl < LogLossEvaluator >
{
public:
virtual string Name() const;
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class LogLossOutputEvaluator : public OuputEvaluatorImpl < LogLossOutputEvaluator >
{
public:
virtual string Name() const;
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class HingeLossEvaluator : public OuputEvaluatorImpl < HingeLossEvaluator >
{
public:
virtual string Name() const;
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
class ExpLossEvaluator : public OuputEvaluatorImpl < ExpLossEvaluator >
{
public:
virtual string Name() const;
template<typename Vec>
static Float EvaluateInstances(const vector<Float>& predictions, const Vec& instances);
};
}
#endif
