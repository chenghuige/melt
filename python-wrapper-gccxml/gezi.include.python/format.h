#ifndef FORMAT_H_
#define FORMAT_H_
#include "common_define.h"
#if IS_HIGH_COMPILER
#define INT INT_CPPFORMAT
#define UINT UINT_CPPFORMAT
#define STRING STRING_CPPFORMAT
#include "cppformat/format.h"
#undef INT
#undef UINT
#undef STRING
#ifndef NO_GEZI_CONVERT
#include "convert_type.h"
#endif
namespace fmt {
inline void print_line(StringRef format_str, ArgList args);
inline void print_colored_line(Color c, StringRef format_str, ArgList args);
FMT_VARIADIC(void, print_line, StringRef)
FMT_VARIADIC(void, print_colored_line, Color, StringRef)
}
namespace gezi {
}
#endif
#endif
