#ifndef SATEN_UI_SCREEN_HPP_
#define SATEN_UI_SCREEN_HPP_
#include <memory>
#import <UIKit/UIKit.h>
#include <boost/noncopyable.hpp>
#include <saten/ns/object_ptr.hpp>
#include <saten/cg/rect.hpp>

namespace saten { namespace ui {
class screen : boost::noncopyable {
 public:
  static std::unique_ptr<screen> main_screen() {
    return std::unique_ptr<screen>(new screen());
  }
    
  cg::rect bounds() const {
    return [screen_.get() bounds];
  }
    
  cg::rect application_frame() const {
    return [screen_.get() applicationFrame];
  }
    
 private:
  screen() : screen_([UIScreen mainScreen]) {}
    
  ns::object_ptr<UIScreen> screen_;
};
}}

#endif
