#ifndef SATEN_WINDOW_HPP_
#define SATEN_WINDOW_HPP_
#import "view.hpp"

namespace saten { namespace ui {
class window : public view<UIWindow> {
public:
  explicit window(const CGRect &rect)
      : view([[UIWindow alloc] initWithFrame:rect]) {}
  
  void make_key_and_visible() {
    [get_objc_ui() makeKeyAndVisible];
  }
};
}}

#endif
