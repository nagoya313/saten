#ifndef SATEN_UI_HPP_
#define SATEN_UI_HPP_
#import <UIKit/UIKit.h>
#import <boost/noncopyable.hpp>
#import "color.hpp"
#import "objective_ptr.hpp"

namespace saten { namespace {
template <typename View>
class ui : boost::noncopyable {
 public:
  explicit ui(const saten::objective_ptr<View> &view)
      : view_(view) {}
  
  virtual ~ui() = default;
  
  template <typename View_>
  void add_subview(const ui<View_> &subview) {
    [view_.get() addSubview:subview.get_objc_ui()];
  }
  
  CGRect get_frame() const {
    view_.get().frame;
  }
  
  void set_frame(const CGRect &frame) {
    view_.get().frame = frame;
  }
  
  CGRect get_bounds() const {
    view_.get().bounds;
  }
  
  void set_bounds(const CGRect &bounds) {
    view_.get().bounds = bounds;
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
