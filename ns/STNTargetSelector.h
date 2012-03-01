#import <Foundation/Foundation.h>
#import <functional>

@interface STNTargetSelector : NSObject {
 @private
  std::function<void ()> func_;
}

- (id)initWithFunction:(std::function<void ()>)func;
- (void)call;

@end
