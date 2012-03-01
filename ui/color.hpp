#ifndef SATEN_UI_COLOR_HPP_
#define SATEN_UI_COLOR_HPP_
#import <UIKit/UIKit.h>
#include <saten/ns/object_ptr.hpp>

namespace saten { namespace ui {
class color {
 public:
  color(UIColor *c) : color_(c) {}
  
  color(float red, float green, float blue, float alpha)
      : color_(ns::make_object([[UIColor alloc] initWithRed:red
                                                      green:green
                                                       blue:blue
                                                      alpha:alpha])) {}
  
  static color white_color() {
    return color([UIColor whiteColor]);
  }
  
  static color black_color() {
    return color([UIColor blackColor]);
  }
  
  static color dark_gray_color() {
    return color([UIColor darkGrayColor]);
  }
  
  static color loght_gray_color() {
    return color([UIColor lightGrayColor]);
  }
  
  static color gray_color() {
    return color([UIColor grayColor]);
  }
  
  static color red_color() {
    return color([UIColor redColor]);
  }
  
  static color green_color() {
    return color([UIColor greenColor]);
  }
  
  static color blue_color() {
    return color([UIColor blueColor]);
  }
  
  static color cyan_color() {
    return color([UIColor cyanColor]);
  }
  
  static color yellow_color() {
    return color([UIColor yellowColor]);
  }
  
  static color magenta_color() {
    return color([UIColor magentaColor]);
  }
  
  static color orange_color() {
    return color([UIColor orangeColor]);
  }
  
  static color purple_color() {
    return color([UIColor purpleColor]);
  }
  
  static color brown_color() {
    return color([UIColor brownColor]);
  }
  
  static color clear_color() {
    return color([UIColor clearColor]);
  }

  operator UIColor *() const {
    return color_.get();
  }
  
 private:
  ns::object_ptr<UIColor> color_;
};
}}

#endif
