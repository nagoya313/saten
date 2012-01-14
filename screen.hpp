#ifndef SATEN_SCREEN_HPP_
#define SATEN_SCREEN_HPP_
#import <memory>
#import <UIKit/UIKit.h>
#import <boost/noncopyable.hpp>
#import "objective_ptr.hpp"

namespace saten { namespace ui {
class screen : boost::noncopyable {
 public:
  static std::unique_ptr<screen> get_main_screen() {
    return std::unique_ptr<screen>(new screen());
  }
  
  CGRect get_bounds() const {
    return [screen_.get() bounds];
  }
  
  CGRect get_application_frame() const {
    return [screen_.get() applicationFrame];
  }
  
 private:
  screen() : screen_([UIScreen mainScreen]) {}
  
  saten::objective_ptr<UIScreen> screen_;
};
}}

#endif
