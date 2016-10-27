#ifndef STRINGUIL
#define STRINGUIL

#include <string>
using std::string;

#include <string>
#include <vector>

#include "format.h" //放在最前面 有和convert_type.h的宏的冲突处理 

#ifdef WIN32
#ifndef NO_BAIDU_DEP
#define NO_BAIDU_DEP
#endif //---- NO_BAIDU_DEP
#else
#include <iconv.h> //for safe @TODO  can remove ?
#endif //---- WIN32

//@TODO baidu depend will move to LOCAL
#ifndef NO_BAIDU_DEP
#include "chinese.h"
#include "encoding_convert.h"
#endif

#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/remove_if.hpp>

#include "wstring_util.h"
#include "common_def.h"
#include "reg_util.h"
#include "stl_util.h"

namespace gezi
{
	inline string haha(string s)
	{
		return s + "gezi";
	}
	
	inline string conf_trim(string input)
	{
		//string input = boost::to_lower_copy(input_);
		if (input.size() > 1)
		{
			if (input[input.size() - 1] == '_')
			{
				return input.substr(0, input.size() - 1);
			}
			else if (input[0] == '_')
			{
				return input.substr(1);
			}
		}
		return input;
	}
}

namespace gezi2
{

	inline string haha(string s)
	{
		return s + "gezi2";
	}
	inline string haha2(string s)
	{
		return s + "gezi2";
	}
}

#endif
