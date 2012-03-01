#ifndef SATEN_CG_POINT_HPP_
#define SATEN_CG_POINT_HPP_
#import <UIKit/UIKit.h>

namespace saten { namespace cg {
class point {
 public:
  point(const CGPoint &p) : x_(p.x), y_(p.y) {}
  
  point(float x, float y) : x_(x), y_(y) {}
  
  void set_x(float x) {
    x_ = x;
  }
  
  float x() const {
    return x_;
  }
  
  void set_y(float y) {
    y_ = y;
  }
  
  float y() const {
    return y_;
  }
  
  operator CGPoint() const {
    return CGPointMake(x_, y_);
  }
  
 private:
  float x_;
  float y_;
};
}}

#endif
