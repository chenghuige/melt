#pragma once
#include "detail/decls.h"
#include "type_traits.h"
namespace mpi {
template <class MsgTy>
struct msg_impl
{
typedef MsgTy value_type;
msg_impl(value_type& v, int tag = 0);
//msg_impl(msg_impl<value_type>&& other);
inline typename mpi_type_traits<value_type>::element_addr_type addr() const;
inline const value_type& get() const;
inline size_t size() const;
inline MPI_Datatype type() const;
inline const int& tag() const;
inline int& tag();
private:
msg_impl(const msg_impl<value_type>& other) = delete;
msg_impl<value_type> operator=(const msg_impl<value_type>& other) = delete;
value_type&  m_data;
int 		 m_tag;
};
template <class T>
inline msg_impl<T> msg(T& raw, int tag=0);
}
