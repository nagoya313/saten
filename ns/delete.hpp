#ifndef SATEN_NS_DELETE_HPP_
#define SATEN_NS_DELETE_HPP_
#import <Foundation/Foundation.h>

namespace saten { namespace ns {
struct drain_delete {
  void operator ()(NSAutoreleasePool *obj) const {
    [obj drain];
  }
};
  
struct release_delete {
  void operator ()(NSObject *obj) const {
    [obj release];
  }
};
}}

#endif
