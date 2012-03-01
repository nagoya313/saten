#ifndef SATEN_UI_WIDGET_HPP_
#define SATEN_UI_WIDGET_HPP_
#import <UIKit/UIKit.h>
#include <boost/noncopyable.hpp>
#include <saten/ui/color.hpp>
#include <saten/ns/object_cast.hpp>
#include <saten/ns/object_ptr.hpp>
#include <saten/cg/rect.hpp>

namespace saten { namespace ui {
class widget : boost::noncopyable {
 public:
  explicit widget(UIView *view) : view_(view) {}
  
  virtual ~widget() = default;
  
  template <typename View>
  void add_subview(const View &view) {
    [view_ addSubview:view.objc_view()];
  }
  
  void remove_from_super_view() {
    [view_ removeFromSuperview];
  }
  
  cg::rect frame() const {
    return view_.frame;
  }
  
  void set_frame(const cg::rect &frame) {
    view_.frame = frame;
  }
  
  cg::rect bounds() const {
    return view_.bounds;
  }
  
  void set_bounds(const cg::rect &bounds) {
    view_.bounds = bounds;
  }
  
  cg::point center() const {
    return view_.center;
  }
  
  void set_center(const cg::point &center) {
    view_.center = center;
  }
  
  color background_color() const {
    return view_.backgroundColor;
  }
  
  void set_background_color(const color &c) {
    view_.backgroundColor = c;
  }
  
  void size_to_fit() {
    [view_ sizeToFit];
  }
  
  void set_objc_view(UIView *view) {
    view_ = view;
  }

 private:   
  UIView *view_;
};
  
template <typename View>
class shared_view : public widget {
 public:
  View *objc_view() const {
    return view_.get();
  }
  
 protected:
  explicit shared_view(const ns::object_ptr<View> &view) 
      : widget(view.get()), view_(view) {}
  
 private:
  ns::object_ptr<View> view_;
};
  
template <typename View>
class weak_view : public widget {
 public:
  View *objc_view() const {
    return view_;
  }
    
  void set_objc_view(View *view) {
    view_ = view;
    widget::set_objc_view(view_);
  }
    
 protected:
  explicit weak_view(View *view) 
      : widget(view), view_(view) {}
    
 private:
  View *view_;
};
}}

#endif
