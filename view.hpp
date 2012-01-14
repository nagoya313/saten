#ifndef SATEN_VIEW_HPP_
#define SATEN_VIEW_HPP_
#import <UIKit/UIKit.h>
#import <boost/noncopyable.hpp>
#import "color.hpp"
#import "objective_ptr.hpp"

namespace saten { namespace ui {
template <typename View = UIView>
class view : boost::noncopyable {
 public:
  explicit view(View *v) : view_(v) {} 
  
  explicit view(const saten::objective_ptr<View> &view)
      : view_(view) {}
  
  explicit view(const CGRect &rect)
      : view_(make_objective([[View alloc] initWithFrame:rect])) {}
    
  virtual ~view() = default;
    
  template <typename View_>
  void add_subview(const view<View_> &subview) {
    [view_.get() addSubview:subview.get_objc_ui()];
  }
    
  CGRect get_frame() const {
    return view_.get().frame;
  }
    
  void set_frame(const CGRect &frame) {
    view_.get().frame = frame;
  }
    
  CGRect get_bounds() const {
    return view_.get().bounds;
  }
    
  void set_bounds(const CGRect &bounds) {
    view_.get().bounds = bounds;
  }
  
  CGRect get_center() const {
    return view_.get().center;
  }
  
  void set_center(const CGRect &center) {
    view_.get().center = center;
  }
  
  color get_background_color() const {
    return color(view_.get().backgroundColor);
  }
    
  void set_background_color(const color &c) {
    view_.get().backgroundColor = c.get_ui_color();
  }
    
  View *get_objc_ui() const {
    return view_.get();
  }
    
 private:
  saten::objective_ptr<View> view_;
};
}}

#endif
