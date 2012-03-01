#ifndef SATEN_NS_STRING_HPP_
#define SATEN_NS_STRING_HPP_
#include <cstddef>
#import <Foundation/Foundation.h>
#include <saten/ns/object_ptr.hpp>

namespace saten { namespace ns {
class string {
 public:
  string(NSString *str) : str_(str) {}
  
  string(const string &rhs)
      : str_(make_object([rhs.str_.get() copy])) {}
  
  string &operator =(const string &rhs) {
    str_ = make_object([rhs.str_.get() copy]);
    return *this;
  }
  
  std::size_t length() const {
    return [str_.get() length];
  }
  
  NSString *ns_string() const {
    return str_.get();
  }
  
 private:
  object_ptr<NSString> str_;
};
  
inline
bool operator ==(const string &lhs, const string &rhs) {
  return [lhs.ns_string() isEqualToString:rhs.ns_string()];   
}
}}

#endif
