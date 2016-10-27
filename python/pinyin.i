%module libpinyin
%include "std_string.i"
%include "std_vector.i"

%{
      /* Includes the header in the wrapper code */
      #include "../include/tools/pinyin/Pinyin.h"
%}
using std::string;
using std::vector;
namespace std {
  %template(ivec) vector<int>;
  %template(dvec) vector<double>;
  %template(svec) vector<string>;
};
  
/* Parse the header file to generate wrappers */
%include "../include/tools/pinyin/Pinyin.h"

