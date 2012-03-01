#ifndef SATEN_CG_SIZE_HPP_
#define SATEN_CG_SIZE_HPP_
#import <UIKit/UIKit.h>

namespace saten { namespace cg {
class size {
 public:
  size(const CGSize &s) 
      : width_(s.width), height_(s.height) {}
    
  size(float width, float height) 
      : width_(width), height_(height) {}
    
  void set_width(float width) {
    width_ = width;
  }
  
  float width() const {
    return width_;
  }
  
  void set_height(float height) {
    height_ = height;
  }
    
  float height() const {
    return height_;
  }
    
  operator CGSize() const {
    return CGSizeMake(width_, height_);
  }
    
 private:
  float width_;
  float height_;
};
}}

#endif
