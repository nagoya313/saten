#ifndef SATEN_VIEW_HPP_
#define SATEN_VIEW_HPP_
#import <UIKit/UIKit.h>
#import <boost/enable_shared_from_this.hpp>
#import <boost/make_shared.hpp>
#import <boost/noncopyable.hpp>
#import <boost/shared_ptr.hpp>
#import "color.hpp"
#import "objective_ptr.hpp"

namespace saten { namespace ui {
template <typename View = UIView>
class view : public boost::enable_shared_from_this<view<View>>, boost::noncopyable {
 public:
  static boost::shared_ptr<view<View>> create(View *v) {
    return boost::make_shared<view<View>>(v);
  }
  
  static boost::shared_ptr<view<View>> create(const CGRect &rect) {
    return boost::make_shared<view<View>>(rect);
  }
  
  static boost::shared_ptr<view<View>> create(const saten::objective_ptr<View> &v) {
    return boost::make_shared<view<View>>(v);
  }
    
  virtual ~view() = default;
    
  template <typename View_>
  void add_subview(const boost::shared_ptr<View_> &subview) {
    [view_.get() addSubview:subview->get_objc_ui()];
  }
  
  template <typename View_>
  void bring_subview_to_front(const boost::shared_ptr<View_> &subview) {
    [view_.get() bringSubviewToFront:subview->get_objc_ui()];
  }
  
  void remove_from_super_view() {
    [view_.get() removeFromSuperView];
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
  
  void size_to_fit() {
    [view_.get() sizeToFit];
  }
  
 protected:
  explicit view(View *v) : view_(v) {}
  
  explicit view(const saten::objective_ptr<View> &v)
      : view_(v) {}
  
  explicit view(const CGRect &rect)
      : view_(make_objective([[View alloc] initWithFrame:rect])) {}
  
  template<class T, class Arg1, class... Args>
  friend boost::shared_ptr< T > boost::make_shared( Arg1 && arg1, Args && ... args);
  
 private:
  saten::objective_ptr<View> view_;
};
}}

#endif
