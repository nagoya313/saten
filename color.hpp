#ifndef SATEN_COLOR_HPP_
#define SATEN_COLOR_HPP_
#import <UIKit/UIKit.h>
#import "objective_ptr.hpp"

namespace saten {
class color {
 public:
  static color create_white() {
    return color([UIColor whiteColor]);
  }
  
  UIColor *get_ui_color() const {
    return color_.get();
  }
  
 private:
  explicit color(UIColor *c) : color_(c) {}
  
  saten::objective_ptr<UIColor> color_;
};
}

#endif
