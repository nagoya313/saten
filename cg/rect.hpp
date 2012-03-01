#ifndef SATEN_CG_RECT_HPP_
#define SATEN_CG_RECT_HPP_
#import <UIKit/UIKit.h>
#include <saten/cg/point.hpp>
#include <saten/cg/size.hpp>

namespace saten { namespace cg {
class rect {
 public:
  rect(const CGRect &r) 
    : origin_(r.origin), size_(r.size) {}
    
  rect(float x, float y, float width, float height) 
      : origin_(x, y), size_(width, height) {}
  
  void set_origin(const cg::point &p) {
    origin_ = p;
  }
  
  cg::point origin() const {
    return origin_;
  }
  
  void set_size(const cg::size &s) {
    size_ = s;
  }
  
  cg::size size() const {
    return size_;
  }
  
  void set_x(float x) {
    origin_.set_x(x);
  }
  
  float x() const {
    return origin_.x();
  }
  
  void set_y(float y) {
    origin_.set_y(y);
  }
  
  float y() const {
    return origin_.y();
  }
  
  void set_widht(float width) {
    size_.set_width(width);
  }
    
  float width() const {
    return size_.width();
  }
  
  void set_height(float height) {
    size_.set_height(height);
  }
    
  float height() const {
    return size_.height();
  }
    
  operator CGRect() const {
    return CGRectMake(origin_.x(), 
                      origin_.y(), 
                      size_.width(), 
                      size_.height());
  }
    
 private:
  cg::point origin_;
  cg::size size_;
};
}}


#endif
