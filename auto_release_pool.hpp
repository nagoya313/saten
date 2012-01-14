#ifndef SATEN_AUTO_RELEASE_POOL_HPP_
#define SATEN_AUTO_RELEASE_POOL_HPP_
#import <UIKit/UIKit.h>
#import <boost/noncopyable.hpp>

namespace saten {
class auto_release_pool : boost::noncopyable {
 public:
  auto_release_pool()
      : pool_([[NSAutoreleasePool alloc] init]) {}
    
  ~auto_release_pool() {
    [pool_ drain];
  }
    
 private:
  NSAutoreleasePool *pool_;
};
}

#endif
