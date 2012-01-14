#ifndef SATEN_VIEW_CONTROLLER_HPP_
#define SATEN_VIEW_CONTROLLER_HPP_
#import <memory>
#import <boost/noncopyable.hpp>
#import "STNViewController.h"
#import "objective_ptr.hpp"
#import "view.hpp"

namespace saten { namespace ui {
class view_controller : boost::noncopyable {
 public:
  view_controller() 
      : controller_(make_objective([[STNViewController alloc] init])) {
    controller_.get().controller = this; 
  }
  
  virtual ~view_controller() = default;
  
  std::unique_ptr<view<>> get_view() const {
    return std::unique_ptr<view<>>(new view<>(controller_.get().view));
  }
  
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
