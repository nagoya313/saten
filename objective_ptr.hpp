#ifndef SATEN_OBJECTIVE_PTR_HPP_
#define SATEN_OBJECTIVE_PTR_HPP_
#import <boost/assert.hpp>
#import <boost/intrusive_ptr.hpp>

inline 
void intrusive_ptr_add_ref(NSObject *obj) {
  BOOST_ASSERT(obj);
  [obj retain];
}

inline
void intrusive_ptr_release(NSObject *obj) {
  BOOST_ASSERT(obj);
  [obj release];
}


namespace saten {
template <typename T>
using objective_ptr = boost::intrusive_ptr<T>;
  
template <typename T>
objective_ptr<T> make_objective(T *t) {
  return objective_ptr<T>(t, false);
}
}

#endif
