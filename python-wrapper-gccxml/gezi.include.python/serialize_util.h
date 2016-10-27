#ifndef SERIALIZE_UTIL_H_
#define SERIALIZE_UTIL_H_
namespace serialize_util {
}
#ifdef GCCXML
#ifndef NO_CEREAL
#define NO_CEREAL
#endif
#endif
#ifdef NO_CEREAL
#include "string_util.h"
//#include <boost/serialization/nvp.hpp>
#define GEZI_SERIALIZATION_NVP(name)\
boost::serialization::make_nvp(gezi::conf_trim(#name).c_str(), name)
#ifdef BOOST_SERIALIZATION_NVP
#undef BOOST_SERIALIZATION_NVP
#endif
#define BOOST_SERIALIZATION_NVP(name)\
boost::serialization::make_nvp(gezi::conf_trim(#name).c_str(), name)
#ifndef BOOST_SERIALIZATION_BASE_OBJECT
#define BOOST_SERIALIZATION_BASE_OBJECT(name) \
boost::serialization::base_object<name>(*this)
#endif
#include "serialize_boost.h"
//namespace cereal { using boost::serialization::access; }
#define CEREAL_NVP GEZI_SERIALIZATION_NVP
#define CEREAL_BASE_OBJECT_NVP BOOST_SERIALIZATION_BASE_OBJECT_NVP
#define  CEREAL_BASE_OBJECT BOOST_SERIALIZATION_BASE_OBJECT
#else
#ifdef Uint
#undef Uint
#endif
#include "serialize_cereal.h"
#include "string_util.h"
#ifdef CEREAL_NVP
#undef CEREAL_NVP
#endif
#define  CEREAL_NVP(name)\
cereal::make_nvp(gezi::conf_trim(#name).c_str(), name)
#ifndef  CEREAL_BASE_OBJECT_NVP
#define CEREAL_BASE_OBJECT_NVP(name)                  \
cereal::make_nvp(BOOST_PP_STRINGIZE(name), \
cereal::base_class<name>(this)\
)
#endif
#ifndef CEREAL_BASE_OBJECT
#define  CEREAL_BASE_OBJECT(name) \
cereal::base_class<name>(this)
#endif
//namespace boost { namespace serialization { using boost::serialization::access; } }
#define  GEZI_SERIALIZATION_NVP CEREAL_NVP
#define  BOOST_SERIALIZATION_NVP CEREAL_NVP
#define  BOOST_SERIALIZATION_BASE_OBJECT_NVP CEREAL_BASE_OBJECT_NVP
#define  BOOST_SERIALIZATION_BASE_OBJECT CEREAL_BASE_OBJECT
#ifndef NO_BAIDU_DEP
#define Uint(inp) (unsigned int)(inp)
#endif
#endif
namespace ser = serialize_util;
#endif
