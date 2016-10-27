#ifndef PROCESSORMGR_H_
#define PROCESSORMGR_H_
#include "IProcessor.h"
#include "ProcessorMgr.h"
#include <vector>
namespace gezi
{
using namespace std;
template<typename T>
class ProcessorMgr
{
public:
typedef IProcessor<T> Processor;
virtual ~ProcessorMgr();
T excute(const T & src);
T process(const T & src);
void add(Processor* processor);
private:
vector<Processor*> processor_list_;
};
typedef ProcessorMgr<string> StringProcessorMgr;
}
#endif
