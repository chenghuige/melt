#ifndef XAPIAN_INCLUDED_EDITDISTANCE_H
#define XAPIAN_INCLUDED_EDITDISTANCE_H
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
template<class CHR>
struct edist_seq
{
edist_seq(const CHR * ptr_, int len_);
const CHR * ptr;
int len;
};
template<class CHR>
class edist_state
{
void operator=(const edist_state &);
edist_state(const edist_state &);
edist_seq<CHR> seq1;
edist_seq<CHR> seq2;
int * fkp;
int fkp_cols;
int maxdist;
int calc_index(int k, int p) const;
public:
edist_state(const CHR * ptr1, int len1, const CHR * ptr2, int len2);
~edist_state();
int get_f_kp(int k, int p) const;
void set_f_kp(int k, int p, int val);
bool is_transposed(int pos1, int pos2) const;
void edist_calc_f_kp(int k, int p);
};
template<class CHR>
void edist_state<CHR>::edist_calc_f_kp(int k, int p);
#define INF 1000000
edist_state<CHR>::edist_state(const CHR * ptr1, int len1,
const CHR * ptr2, int len2)
: seq1(ptr1, len1), seq2(ptr2, len2), maxdist(len2)
{
int fkp_rows;
fkp_cols;
fkp;
for (int k;
{
for (int p;
{
if (p == abs(k) - 1)
{
if (k < 0)
{
set_f_kp(k, p, abs(k) - 1);
}
else
{
set_f_kp(k, p, -1);
}
}
else if (p < abs(k))
{
set_f_kp(k, p, -INF);
}
}
}
}
template<class CHR>
edist_state<CHR>::~edist_state();
static int
seqcmp_editdist(const CHR * ptr1, int len1, const CHR * ptr2, int len2,
int max_distance);
inline int edit_distance_unsigned(const unsigned * ptr1, int len1,
const unsigned * ptr2, int len2,
int max_distance);
inline int edit_distance(const char * ptr1, int len1,
const char * ptr2, int len2,
int max_distance);
inline int edit_distance_ch(const char * ptr1, int len1,
const char * ptr2, int len2,
int max_distance);
inline int edit_distance_ch(const std::string& s1, const std::string& s2, int max_diff);
#endif
