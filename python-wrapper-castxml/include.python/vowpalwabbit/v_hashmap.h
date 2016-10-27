#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "v_array.h"
{
public:
struct hash_elem
{
bool   occupied;
K      key;
V      val;
size_t hash;
};
bool (*equivalent)(void*,K&,K&);
bool (*equivalent_no_data)(K&,K&);
V default_value;
v_array<hash_elem> dat;
size_t last_position;
size_t num_occupants;
void*eq_data;
size_t base_size()
{
return dat.end_array-dat.begin;
}
void set_default_value(V def)
{
default_value;
}
void init_dat(size_t min_size, V def, bool (*eq)(void*,K&,K&), void*eq_dat=NULL)
{
dat;
if (min_size < 1023) min_size;
dat.resize(min_size, true);
default_value;
equivalent;
equivalent_no_data;
eq_data;
last_position;
num_occupants;
}
void init(size_t min_size, V def, bool (*eq)(K&,K&))
{
dat;
if (min_size < 1023) min_size;
dat.resize(min_size, true);
default_value;
equivalent;
equivalent_no_data;
eq_data;
last_position;
num_occupants;
}
void init(size_t min_size, bool (*eq)(K&,K&))
{
dat;
if (min_size < 1023) min_size;
dat.resize(min_size, true);
equivalent;
equivalent_no_data;
eq_data;
last_position;
num_occupants;
}
v_hashmap(size_t min_size, V def, bool (*eq)(void*,K&,K&), void*eq_dat=NULL)
{
init_dat(min_size, def, eq, eq_dat);
}
v_hashmap(size_t min_size, V def, bool (*eq)(K&,K&))
{
init(min_size, def, eq);
}
v_hashmap()
{
init(1023, NULL);
}
void set_equivalent(bool (*eq)(void*,K&,K&), void*eq_dat=NULL)
{
equivalent;
}
void set_equivalent(bool (*eq)(K&,K&))
{
equivalent_no_data;
}
void delete_v()
{
dat.delete_v();
}
~v_hashmap()
{
delete_v();
}
void clear()
{
if (num_occupants;
memset(dat.begin, 0, base_size()*sizeof(hash_elem));
last_position;
num_occupants;
}
void* iterator_next(void* prev)
{
hash_elem* e;
if (e;
e++;
while (e != dat.end_array)
{
if (e->occupied)
return e;
e++;
}
return NULL;
}
void* iterator()
{
hash_elem* e;
while (e != dat.end_array)
{
if (e->occupied)
return e;
e++;
}
return NULL;
}
V* iterator_get_value(void* el)
{
hash_elem* e;
return &e->val;
}
void iter(void (*func)(K,V))
{
for (hash_elem* e;
{
if (e->occupied)
{
func(e->key, e->val);
}
}
}
void put_after_get_nogrow(K& key, size_t hash, V val)
{
dat[last_position].occupied;
dat[last_position].key;
dat[last_position].val;
dat[last_position].hash;
}
void double_size()
{
v_array<hash_elem>tmp;
tmp.resize(num_occupants+10, true);
for (hash_elem* e;
if (e->occupied)
tmp.push_back(*e);
dat.resize(base_size()*2, true);
memset(dat.begin, 0, base_size()*sizeof(hash_elem));
for (hash_elem* e;
{
get(e->key, e->hash);
put_after_get_nogrow(e->key, e->hash, e->val);
}
tmp.delete_v();
}
bool is_equivalent(K& key, K& key2)
{
if ((equivalent == NULL) && (equivalent_no_data == NULL))
return true;
else if (equivalent != NULL)
return equivalent(eq_data, key, key2);
else
return equivalent_no_data(key, key2);
}
V& get(K key, size_t hash)
{
size_t sz;
size_t first_position;
last_position;
while (true)
{
if (!dat[last_position].occupied)
return default_value;
if ((dat[last_position].hash == hash) && is_equivalent(key, dat[last_position].key))
return dat[last_position].val;
last_position++;
if (last_position >= sz)
last_position;
if (last_position == first_position)
{
std::cerr << "error: v_hashmap did not grow enough!" << std::endl;
throw std::exception();
}
}
}
bool contains(K& key, size_t hash)
{
size_t sz;
size_t first_position;
last_position;
while (true)
{
if (!dat[last_position].occupied)
return false;
if ((dat[last_position].hash == hash) && is_equivalent(key, dat[last_position].key))
return true;
last_position++;
if (last_position >= sz)
last_position;
if (last_position == first_position)
{
std::cerr << "error: v_hashmap did not grow enough!" << std::endl;
throw std::exception();
}
}
}
void put_after_get(K& key, size_t hash, V val)
{
if (!dat[last_position].occupied)
{
num_occupants++;
if (num_occupants*4 >= base_size())
{
double_size();
get(key, hash);
}
}
put_after_get_nogrow(key, hash, val);
}
void put(K& key, size_t hash, V val)
{
get(key, hash);
put_after_get(key, hash, val);
}
};
void test_v_hashmap();
