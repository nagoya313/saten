#ifndef SATEN_UI_VIEW_HPP_
#define SATEN_UI_VIEW_HPP_
#import <UIKit/UIKit.h>
#include <boost/assert.hpp>
#include <boost/noncopyable.hpp>
#include <saten/ui/widget.hpp>

namespace saten { namespace ui {  
class view : shared_view<UIView> {
 public:
  virtual ~view() = default;
  
 private:
};
}}

#endif
