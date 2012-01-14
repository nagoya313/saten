#ifndef SATEN_LABEL_HPP_
#define SATEN_LABEL_HPP_
#import "color.hpp"
#import "view.hpp"

namespace saten { namespace ui {
class label : public view<UILabel> {
 public:  
  static boost::shared_ptr<label> create(NSString *text, 
                                         const CGRect &frame) {
    return boost::make_shared<label>(text, frame);
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
  
  UITextAlignment get_text_alignment() const {
    return get_objc_ui().textAlignment;
  }
  
  void set_text_alignment(UITextAlignment alignment) {
    get_objc_ui().textAlignment = alignment;
  }
  
  int get_number_of_lines() const {
    return get_objc_ui().numberOfLines;
  }
  
  void set_number_of_lines(int lines) {
    get_objc_ui().numberOfLines = lines;
  }
  
 protected:
  explicit label(NSString *text, const CGRect &frame)
      : view(frame) {
    get_objc_ui().text = text;
  } 
  
  template<class T, class Arg1, class... Args>
  friend boost::shared_ptr< T > boost::make_shared( Arg1 && arg1, Args && ... args);
};
}}

#endif
