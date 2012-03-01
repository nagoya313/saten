#ifndef SATEN_UI_VIEW_CONTROLLER_HPP_
#define SATEN_UI_VIEW_CONTROLLER_HPP_
#include <boost/noncopyable.hpp>
#import <saten/ui/STNViewController.h>
#include <saten/ns/object_ptr.hpp>
#include <saten/ui/widget.hpp>

namespace saten { namespace ui {
class view_controller_accessor;
  
class view_controller_view : public weak_view<UIView> {
 public:
  virtual ~view_controller_view() = default;
    
 private:
  view_controller_view() : weak_view(nil) {}
  
  void set_view(UIView *v) {
    set_objc_view(v);
  }
    
  friend class view_controller;
};
  
class view_controller : boost::noncopyable {
 public:
  view_controller() 
      : controller_(ns::make_object([[STNViewController alloc] initWithController:this])) {}
  
  virtual ~view_controller() = default;
  
  view_controller_view &view() {
    view_.set_view(controller_.get().view);
    return view_;
  }
  
 protected:
  friend class view_controller_accessor;
  
  virtual void load_view() {
    view_.set_view(controller_.get().view);
  }
  
  virtual void view_will_appear(bool animated) {
    [ns::object_cast<UIViewController *>([controller_.get() superclass]) viewWillAppear:animated];
  }
  
  virtual void view_did_appear(bool animated) {
    [ns::object_cast<UIViewController *>([controller_.get() superclass]) viewDidAppear:animated];
  }
  
  virtual void view_will_disappear(bool animated) {
    [ns::object_cast<UIViewController *>([controller_.get() superclass]) viewWillDisappear:animated];
  }
  
  virtual void view_did_disappear(bool animated) {
    [ns::object_cast<UIViewController *>([controller_.get() superclass]) viewDidDisappear:animated];
  }
  
 private:
  ns::object_ptr<STNViewController> controller_;
  view_controller_view view_;
};
}}

#endif
