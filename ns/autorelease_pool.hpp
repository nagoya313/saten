#ifndef SATEN_NS_AUTORELEASE_POOL_HPP_
#define SATEN_NS_AUTORELEASE_POOL_HPP_
#include <memory>
#import <UIKit/UIKit.h>
#include <boost/noncopyable.hpp>
#include <saten/ns/delete.hpp>

namespace saten { namespace ns {
class auto_release_pool : boost::noncopyable {
 public:
  auto_release_pool()
   : pool_([[NSAutoreleasePool alloc] init]) {}
    
 private:
  std::unique_ptr<NSAutoreleasePool, drain_delete> pool_;
};
}}

#endif
