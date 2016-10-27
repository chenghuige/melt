#ifndef GEZI_NLP__VOCABULARY_H_
#define GEZI_NLP__VOCABULARY_H_
#include "Identifer.h"
namespace gezi {
class Vocabulary : public CountIdentifer
{
public:
Vocabulary(string file,
int num_reserved_ids = 0,
string start_word = "<S>",
string end_word = "</S>",
string unk_word = "<UNK>");
size_t size() const;
inline IdType id(string key) const;
inline IdType id(string key, IdType default_val) const;
size_t freq(IdType index) const;
size_t count(IdType index) const;
string key(IdType index) const;
size_t value(int index) const;
size_t get_value(string key) const;
size_t value(string key) const;
size_t freq(string key) const;
size_t count(string key) const;
int num_reserved_ids() const;
IdType start_id() const;
IdType end_id() const;
IdType unk_id() const;
string start_word() const;
string end_word() const;
string unk_word() const;
protected:
private:
IdType _start_id;
IdType _end_id;
IdType _unk_id;
int _num_reserved_ids;
string _start_word;
string _end_word;
string _unk_word;
};
}
#endif
