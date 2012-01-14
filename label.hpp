#ifndef SATEN_LABEL_HPP_
#define SATEN_LABEL_HPP_
#import "color.hpp"
#import "view.hpp"

namespace saten { namespace ui {
class label : public view<UILabel> {
 public:  
  explicit label(NSString *text, const CGRect &frame)
      : view(frame) {
    get_objc_ui().text = text;
  }
  
  NSString *get_text() const {
    return get_objc_ui().text;
  }
  
  void set_text(NSString *text) {
    get_objc_ui().text = text;
  }
  
  UIFont *get_font() const {
    return get_objc_ui().font;
  }
  
  void set_font(UIFont *font) {
    get_objc_ui().font = font;
  }
  
  color get_text_color() const {
    return color(get_objc_ui().textColor);
  }
  
  void set_text_color(const color &c) {
    get_objc_ui().textColor = c.get_ui_color();
  }
};
}}

#endif
