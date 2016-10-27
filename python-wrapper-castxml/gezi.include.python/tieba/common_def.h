#ifndef TIEBA_COMMON_DEF_H_
#define TIEBA_COMMON_DEF_H_
#include <map>
#include <boost/any.hpp>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;
namespace gezi {
namespace tieba {
typedef map<string, vector<string> > VecHistoryType;
typedef map<string, double> DoubleHistoryType;
typedef map<string, boost::any> AnyHistoryType;
typedef VecHistoryType HistoryType;
}
}
#endif
