#ifndef SATEN_NS_OBJECT_PTR_HPP_
#define SATEN_NS_OBJECT_PTR_HPP_
#import <Foundation/Foundation.h>
#include <boost/intrusive_ptr.hpp>

inline 
void intrusive_ptr_add_ref(NSObject *obj) {
  [obj retain];
}

inline
void intrusive_ptr_release(NSObject *obj) {
  [obj release];
}

namespace saten { namespace ns {
template <typename T>
using object_ptr = boost::intrusive_ptr<T>;
  
template <typename T>
object_ptr<T> make_object(T *t) {
  return object_ptr<T>(t, false);
}
}}

#endif
