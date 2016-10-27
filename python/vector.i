%module libvector
%include "std_string.i"
%include "std_vector.i"
using std::string;
using std::vector;
namespace std {
  %template(ivec) vector<int>;
  %template(dvec) vector<double>;
  %template(svec) vector<string>;
};
%{
      /* Includes the header in the wrapper code */
      #include "../include/Numeric/Vector/Vector.h"
%}
  
/* Parse the header file to generate wrappers */
%include "../include/Numeric/Vector/Vector.h"
%include "../include/common_def.h"

