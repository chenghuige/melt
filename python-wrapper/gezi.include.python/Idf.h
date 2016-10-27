#ifndef IDF_H_
#define IDF_H_
#include "Identifer.h"
#include "common_util.h"
namespace gezi {
class Idf
{
public:
virtual ~Idf();
Idf();
void add(string doc, string sep = "\t");
void add(const vector<string>& words);
void save(string file);
void save(string file, int minCount, int minIdf);
void show(int maxNum = 1024);
protected:
private:
void add(const set<string>& words);
private:
Identifer _identifer;
vector<int> _featureCounts;
int _instanceNum;
};
}
#endif
