#import "STNAppDelegate.h"
#import <Block.h>
#include <boost/assert.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <saten/ui/application.hpp>

namespace saten { namespace ui {
class application_delegate_accessor {
 public:
  explicit application_delegate_accessor(application_delegate *d) 
      : delegate_(d) {} 
    
  bool did_finish_launching() {
    return delegate_->did_finish_launching();
  }
  
 private:
  application_delegate *delegate_;
};
  
class delegate_singleton : boost::noncopyable {
 public:
  static delegate_singleton &instance() {
    static dispatch_once_t once;
    static std::unique_ptr<delegate_singleton> instance;
    dispatch_once(&once, ^{
      instance.reset(new delegate_singleton());
    });
    BOOST_ASSERT(instance);
    return *instance.get();
  }
    
  void set_delegate(const boost::shared_ptr<application_delegate> &delegate) {
    delegate_ = delegate;
  }
    
  boost::shared_ptr<application_delegate> delegate() const {
    return delegate_;
  }
    
 private:
  delegate_singleton() = default;
    
  boost::shared_ptr<application_delegate> delegate_;
};
  
int application_main(int argc, 
                     char **argv,
                     const boost::shared_ptr<application_delegate> &delegate) {
  delegate_singleton::instance().set_delegate(delegate);
  return UIApplicationMain(argc, 
                           argv, 
                           nil,
                           NSStringFromClass([STNAppDelegate class]));
}
}}

using accessor = saten::ui::application_delegate_accessor;
using singleton = saten::ui::delegate_singleton;

@implementation STNAppDelegate

- (BOOL)application:(UIApplication *)application 
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  return accessor(singleton::instance().delegate().get()).did_finish_launching();
}

- (void)applicationWillResignActive:(UIApplication *)application {
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
}

- (void)applicationWillTerminate:(UIApplication *)application {
}

@end
