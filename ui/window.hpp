#ifndef SATEN_UI_WINDOW_HPP_
#define SATEN_UI_WINDOW_HPP_
#include <saten/ui/widget.hpp>

namespace saten { namespace ui {
class window : public shared_view<UIWindow> {
 public:
  explicit window(const cg::rect &rect) 
      : shared_view(ns::make_object([[UIWindow alloc] initWithFrame:rect])) {}
  
  void make_key_and_visible() {
    [objc_view() makeKeyAndVisible];
  }
};
}}

#endif
