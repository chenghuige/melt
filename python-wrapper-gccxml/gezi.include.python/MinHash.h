#ifndef MINHASH_H_
#define MINHASH_H_
#include "MultiHash.h"
#include "common_util.h"
#include <limits>
#include <sstream>
namespace gezi
{
using namespace std;
class MinHash : MultiHash
{
private:
string _separator;
int _hashNum;
int _groupNum;
public:
MinHash();
MinHash(int hashNum, int interval);
template<typename T>
void GetSuperShingleFeature(const vector<T>& input, vector<uint>& superShingles);
template<typename T>
void GetSuperShingleFeature(const vector<T>& input, int hashNum, int interval,  vector<uint>& superShingles);
template<typename T>
void GetSketches(const vector<T>& input, int n, vector<uint>& sketches);
template<typename T>
void GetSketches(const vector<T>& input, vector<uint>& sketches);
static double GetSim(const vector<uint>& lfeatures, const vector<uint>& rfeatures);
void GetSuperShingles(const vector<uint>& features, int groupNum, vector<uint>& superShingles);
};
}
#endif
