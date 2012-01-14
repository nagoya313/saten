#ifndef SATEN_VIEW_HPP_
#define SATEN_VIEW_HPP_
#import "objective_ptr.hpp"
#import "ui.hpp"

namespace saten { namespace ui {
class view : public ui<UIView> {
 public:
  explicit view(UIView *view)
      : ui(view) {}
  
  explicit view(const CGRect &rect)
      : ui(saten::make_objective([[UIView alloc] initWithFrame:rect])) {}
};
}}

#endif
