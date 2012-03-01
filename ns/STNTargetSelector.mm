#import <saten/ns/STNTargetSelector.h>

@implementation STNTargetSelector

- (id)initWithFunction:(std::function<void ()>)func {
  if (self = [super init]) {
    func_ = func;
  }
  return self;
}

- (void)call {
  func_();
}

@end
