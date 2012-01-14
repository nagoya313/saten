#ifndef SATEN_WINDOW_HPP_
#define SATEN_WINDOW_HPP_
#import "ui.hpp"

namespace saten { namespace ui {
class window : public ui<UIWindow> {
public:
  explicit window(const CGRect &rect)
      : ui([[UIWindow alloc] initWithFrame:rect]) {}
  
  void make_key_and_visible() {
    [get_objc_ui() makeKeyAndVisible];
  }
};
}}

#endif
