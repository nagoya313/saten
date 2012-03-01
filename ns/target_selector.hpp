#ifndef SATEN_NS_TARGET_SELECTOR_
#define SATEN_NS_TARGET_SELECTOR_
#include <functional>
#import <Foundation/Foundation.h>
#include <saten/ns/STNTargetSelector.h>
#include <saten/ns/object_ptr.hpp>

namespace saten { namespace ns {
struct target_selector {
  template <typename Pred>
  explicit target_selector(Pred pred) 
      : id_(make_object([[STNTargetSelector alloc] initWithFunction:pred])) {}    
  
  id target() const {
    return id_.get();
  }
  
  SEL action() const {
    return @selector(call);
  }
  
 private:
  object_ptr<STNTargetSelector> id_;
};
}}

#endif
