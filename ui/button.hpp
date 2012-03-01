#ifndef SATEN_UI_BUTTON_HPP_
#define SATEN_UI_BUTTON_HPP_
#import <boost/container/vector.hpp>
#include <saten/ns/string.hpp>
#include <saten/ns/target_selector.hpp>
#include <saten/ui/widget.hpp>

namespace saten { namespace ui {
class button : public shared_view<UIButton> {
 public:
  explicit button(UIButtonType type)
      : shared_view(ns::object_ptr<UIButton>([UIButton buttonWithType:type])) {}
  
  template <typename Action>
  void add_action(Action action, UIControlEvents events) {
    ns::target_selector ts(action);
    [objc_view() addTarget:ts.target() 
                    action:ts.action() 
          forControlEvents:events];
    ts_.push_back(ts);
  }
  
  void set_title(const ns::string &title, UIControlState state) {
    [objc_view() setTitle:title.ns_string() forState:state];
  }
  
  ns::string title_for_state(UIControlState state) const {
    return [objc_view() titleForState:state];
  }
  
 private:
  boost::container::vector<ns::target_selector> ts_;
};
}}

#endif
