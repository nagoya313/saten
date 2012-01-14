#ifndef SATEN_COLOR_HPP_
#define SATEN_COLOR_HPP_
#import <UIKit/UIKit.h>
#import "objective_ptr.hpp"

namespace saten { namespace ui {
class color {
 public:
  explicit color(UIColor *c) : color_(c) {}
  
  static color create_white() {
    return color([UIColor whiteColor]);
  }
  
  static color create_black() {
    return color([UIColor blackColor]);
  }
  
  static color create_dark_gray() {
    return color([UIColor darkGrayColor]);
  }
  
  static color create_loght_gray() {
    return color([UIColor lightGrayColor]);
  }
  
  static color create_gray() {
    return color([UIColor grayColor]);
  }
  
  static color create_red() {
    return color([UIColor redColor]);
  }
  
  static color create_green() {
    return color([UIColor greenColor]);
  }
  
  static color create_blue() {
    return color([UIColor blueColor]);
  }
  
  static color create_cyan() {
    return color([UIColor cyanColor]);
  }
  
  static color create_yellow() {
    return color([UIColor yellowColor]);
  }
  
  static color create_magenta() {
    return color([UIColor magentaColor]);
  }
  
  static color create_orange() {
    return color([UIColor orangeColor]);
  }
  
  static color create_purple() {
    return color([UIColor purpleColor]);
  }
  
  static color create_brown() {
    return color([UIColor brownColor]);
  }
  
  static color create_clear() {
    return color([UIColor clearColor]);
  }

  UIColor *get_ui_color() const {
    return color_.get();
  }
  
 private:
  saten::objective_ptr<UIColor> color_;
};
}}

#endif
