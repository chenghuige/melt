#pragma once
#include <mpi.h>
#include <list>
#include <array>
#include <algorithm>
#include <complex>
namespace mpi {
template <class T>
struct mpi_type_traits
{
typedef T element_type;
typedef T* element_addr_type;
//static inline MPI_Datatype get_type(T&& raw);
static inline size_t get_size(T& raw);
static inline element_addr_type get_addr(T& raw);
};
#define PRIMITIVE(Type, MpiType) \
template<> \
inline MPI_Datatype mpi_type_traits<Type>::get_type(Type&&) { \
return MpiType; \
}
PRIMITIVE(char, 				MPI::CHAR);
PRIMITIVE(wchar_t,				MPI::WCHAR);
PRIMITIVE(short, 				MPI::SHORT);
PRIMITIVE(int, 					MPI::INT);
PRIMITIVE(long, 				MPI::LONG);
PRIMITIVE(signed char, 			MPI::SIGNED_CHAR);
PRIMITIVE(unsigned char, 		MPI::UNSIGNED_CHAR);
PRIMITIVE(unsigned short, 		MPI::UNSIGNED_SHORT);
PRIMITIVE(unsigned int,			MPI::UNSIGNED);
PRIMITIVE(unsigned long,		MPI::UNSIGNED_LONG);
PRIMITIVE(unsigned long long,	MPI::UNSIGNED_LONG_LONG);
PRIMITIVE(float, 				MPI::FLOAT);
PRIMITIVE(double, 				MPI::DOUBLE);
PRIMITIVE(long double,			MPI::LONG_DOUBLE);
PRIMITIVE(bool,						MPI::BOOL);
PRIMITIVE(std::complex<float>,		MPI::COMPLEX);
PRIMITIVE(std::complex<double>,		MPI::DOUBLE_COMPLEX);
PRIMITIVE(std::complex<long double>,	MPI::LONG_DOUBLE_COMPLEX);
#undef PRIMITIVE
template <class T>
struct mpi_type_traits<const T>
{
typedef const typename mpi_type_traits<T>::element_type element_type;
typedef const typename mpi_type_traits<T>::element_addr_type element_addr_type;
static inline size_t get_size(const T& elem);
static inline MPI_Datatype get_type(const T& elem);
static inline element_addr_type get_addr(const T& elem);
};
template <class T>
struct mpi_type_traits<std::vector<T>>
{
typedef T element_type;
typedef T* element_addr_type;
static inline size_t get_size(std::vector<T>& vec);
//static inline MPI_Datatype get_type(std::vector<T>&& vec);
static inline element_addr_type get_addr(std::vector<T>& vec);
};
template <class T, size_t N>
struct mpi_type_traits<std::array<T,N>>
{
inline static size_t get_size(const std::array<T,N>& vec);
inline static MPI_Datatype get_type(const std::array<T,N>& vec);
static inline const T* get_addr(const std::array<T,N>& vec);
};
template <class T>
struct mpi_type_traits<std::list<T>>
{
static inline size_t get_size(const std::list<T>& vec);
static MPI_Datatype get_type(const std::list<T>& l);
static inline const T* get_addr(const std::list<T>& list);
};
}
