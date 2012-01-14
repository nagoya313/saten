#ifndef SATEN_VIEW_CONTROLLER_HPP_
#define SATEN_VIEW_CONTROLLER_HPP_
#import <boost/make_shared.hpp>
#import <boost/noncopyable.hpp>
#import <boost/shared_ptr.hpp>
#import "STNViewController.h"
#import "objective_ptr.hpp"
#import "view.hpp"

namespace saten { namespace ui {
class view_controller_accessor;
  
class view_controller : boost::noncopyable {
 public:
  view_controller() 
      : controller_(make_objective([[STNViewController alloc] init])) {
    controller_.get().controller = this; 
  }
  
  virtual ~view_controller() = default;
  
  boost::shared_ptr<view<>> get_view() const {
    auto v = controller_.get().view;
    return boost::make_shared<view<>>(v);
  }
  
 protected:
  friend class view_controller_accessor;
  
  virtual void load_view() {}
  virtual void view_will_appear(bool animated) {}
  virtual void view_did_appear(bool animated) {}
  virtual void view_will_disappear(bool animated) {}
  virtual void view_did_disappear(bool animated) {}
  
 private:
  saten::objective_ptr<STNViewController> controller_;
};
}}

#endif
