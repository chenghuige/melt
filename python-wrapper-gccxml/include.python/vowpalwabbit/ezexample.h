#pragma once
#include <stdio.h>
#include "../vowpalwabbit/parser.h"
#include "../vowpalwabbit/vw.h"
using namespace std;
typedef uint32_t fid;
struct vw_namespace
{
char namespace_letter;
public: vw_namespace(const char c) : namespace_letter(c);
};
class ezexample
{
private:
vw*vw_ref;
vw*vw_par_ref;
bool is_multiline;
char str[2];
example*ec;
bool we_create_ec;
vector<fid> past_seeds;
fid current_seed;
size_t quadratic_features_num;
float quadratic_features_sqr;
char current_ns;
bool ns_exists[256];
bool example_changed_since_prediction;
v_array<example*> example_copies;
ezexample(const ezexample & ex);
ezexample & operator=(const ezexample & ex);
example* get_new_example();
void setup_new_ezexample(vw*this_vw, bool multiline, vw*this_vw_parser);
void setup_for_predict();
public:
ezexample(vw*this_vw, bool multiline=false, vw*this_vw_parser=NULL);
ezexample(vw*this_vw, example*this_ec, bool multiline=false, vw*this_vw_parser=NULL);
~ezexample();
bool ensure_ns_exists(char c);
void addns(char c);
void remns();
inline fid addf(char to_ns, fid fint, float v);
inline fid addf(fid fint, float v);
void add_other_example_ns(example& other, char other_ns, char to_ns);
void add_other_example_ns(example& other, char ns);
void add_other_example_ns(ezexample& other, char other_ns, char to_ns);
void add_other_example_ns(ezexample& other, char ns                  );
inline ezexample& set_label(string label);
void mini_setup_example();
example* get();
float predict();
float predict_partial();
void train();
void clear_features();
void finish();
inline fid hash(string fstr);
inline fid hash(char*  fstr);
inline fid hash(char c, string fstr);
inline fid hash(char c, char*  fstr);
inline fid addf(fid    fint           );
inline fid addf(string fstr, float val);
inline fid addf(string fstr           );
inline fid addf(char ns, fid    fint           );
inline fid addf(char ns, string fstr, float val);
inline fid addf(char ns, string fstr           );
inline ezexample& operator()(const vw_namespace&n);
inline ezexample& operator()(fid         fint           );
inline ezexample& operator()(string      fstr           );
inline ezexample& operator()(const char* fstr           );
inline ezexample& operator()(fid         fint, float val);
inline ezexample& operator()(string      fstr, float val);
inline ezexample& operator()(const char* fstr, float val);
inline ezexample& operator()(char ns, fid         fint           );
inline ezexample& operator()(char ns, string      fstr           );
inline ezexample& operator()(char ns, const char* fstr           );
inline ezexample& operator()(char ns, fid         fint, float val);
inline ezexample& operator()(char ns, string      fstr, float val);
inline ezexample& operator()(char ns, const char* fstr, float val);
inline ezexample& operator()(  example&other, char other_ns, char to_ns);
inline ezexample& operator()(  example&other, char ns                  );
inline ezexample& operator()(ezexample&other, char other_ns, char to_ns);
inline ezexample& operator()(ezexample&other, char ns                  );
inline ezexample& operator--();
inline float      operator()();
};
