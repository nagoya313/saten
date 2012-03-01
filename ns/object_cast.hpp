#ifndef SATEN_NS_OBJECT_CAST_HPP_
#define SATEN_NS_OBJECT_CAST_HPP_
#include <type_traits>
#import <Foundation/Foundation.h>

namespace saten { namespace ns {
template <typename Target>
Target object_cast(id target) {
  return [target isKindOfClass:[typename std::remove_pointer<Target>::type class]] ? 
         target :
         nil;
}
}}

#endif
