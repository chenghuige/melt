#ifndef IPROCESSOR_H_
#define IPROCESSOR_H_
#include <string>
#include <iostream>
namespace gezi {
using namespace std;
template<typename T>
class IProcessor
{
public:
//virtual T process(const T &) = 0;
virtual ~IProcessor();
};
typedef IProcessor<string> IStringProcessor;
class SampleStringProcessor :public IStringProcessor
{
public:
virtual ~SampleStringProcessor();
virtual string process(string input);
};
class SampleStringProcessor2 :public IStringProcessor
{
public:
virtual ~SampleStringProcessor2();
virtual string process(string input);
};
}
#endif
