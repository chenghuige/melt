#ifndef FACTORY_H_
#define FACTORY_H_
#include <map>
#include <string>
namespace gezi {
template<typename Ptr, typename Key = std::string>
class Factory
{
public:
void Register(Key id, Ptr ptr);
void Create(Key id);
protected:
private:
std::map<Key, Ptr> _map;
};
}
#endif
