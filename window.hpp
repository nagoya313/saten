#ifndef SATEN_WINDOW_HPP_
#define SATEN_WINDOW_HPP_
#import "view.hpp"

namespace saten { namespace ui {
class window : public view<UIWindow> {
public:
  static boost::shared_ptr<window> create(const CGRect &rect) {
    return boost::make_shared<window>(rect);
  }
  
  void make_key_and_visible() {
    [get_objc_ui() makeKeyAndVisible];
  }
  
 protected:
  explicit window(const CGRect &rect)
      : view([[UIWindow alloc] initWithFrame:rect]) {}
  
  template<class T, class Arg1, class... Args>
  friend boost::shared_ptr<T> boost::make_shared(Arg1 &&arg1, Args && ... args);
};
}}

#endif
