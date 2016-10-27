#ifndef IDENTIFER_H_
#define IDENTIFER_H_
#include <glog/logging.h>
#include "common_def.h"
#include "serialize_util.h"
namespace gezi {
class Identifer
{
public:
typedef int IdType;
typedef vector<string>::iterator iterator;
typedef vector<string>::const_iterator const_iterator;
typedef unordered_map<string, IdType> HashMap;
typedef HashMap::const_iterator const_mapiter;
Identifer();
Identifer(string file);
public:
#ifndef PYTHON_WRAPPER
enum IdTypes
{
NullId = -1,
}
;
#else
static const int NullId = -1;
#endif
static const IdType null_id();
vector<string>& words();
#ifndef GCCXML
//iterator begin();
//iterator end();
const_iterator begin()const;
const_iterator end()const;
#endif
size_t size()const;
bool empty()const;
void clear();
inline string key(IdType id) const;
inline string key(IdType id, string defualtKey) const;
vector<string>& keys();
inline IdType id(string f) const;
inline IdType id(string f, IdType defaultVal) const;
inline bool has(string f) const;
inline IdType add(string f);
inline IdType add(string f, bool& isnew);
string last();
inline IdType add_unique(string f);
bool load(string file, string sep = "\t");
void save(string file);
string operator [] (int id) const;
const IdType operator () (string key) const;
void Load(string path);
void Save(string path);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
HashMap _hashdict;
vector<string> _index;
};
typedef vector<Identifer> Identifers;
template<typename T>
class ValueIdentifer : public Identifer
{
public:
ValueIdentifer();
ValueIdentifer(string file);
bool load(string file, int index = 1, string sep = "\t");
void save(string file);
void add(string key, T value);
void Save(string file);
void Load(string file);
T value(int index) const;
T get_value(string key) const;
T value(string key) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
private:
vector<T> _values;
};
typedef ValueIdentifer<int> IntIdentifer;
typedef ValueIdentifer<int64> Int64Identifer;
typedef ValueIdentifer<size_t> CountIdentifer;
typedef ValueIdentifer<double> DoubleIdentifer;
#ifdef PYTHON_WRAPPER
PYHACK(IntIdentifer);
PYHACK(Int64Identifer);
PYHACK(CountIdentifer);
PYHACK(DoubleIdentifer);
#endif
}
#endif
