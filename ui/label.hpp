#ifndef SATEN_UI_LABEL_HPP_
#define SATEN_UI_LABEL_HPP_
#include <saten/ns/string.hpp>
#include <saten/ui/color.hpp>
#include <saten/ui/widget.hpp>

namespace saten { namespace ui {
class label : public shared_view<UILabel> {
 public:  
  explicit label(const cg::rect &rect) 
      : shared_view(ns::make_object([[UILabel alloc] initWithFrame:rect])) {}
  
  ns::string text() const {
    return objc_view().text;
  }
  
  void set_text(const ns::string &text) {
    objc_view().text = text.ns_string();
  }
  
  UIFont *font() const {
    return objc_view().font;
  }
  
  void set_font(UIFont *font) {
    objc_view().font = font;
  }
  
  color text_color() const {
    return objc_view().textColor;
  }
  
  void set_text_color(const color &c) {
    objc_view().textColor = c;
  }
  
  UITextAlignment text_alignment() const {
    return objc_view().textAlignment;
  }
  
  void set_text_alignment(UITextAlignment alignment) {
    objc_view().textAlignment = alignment;
  }
  
  int number_of_lines() const {
    return objc_view().numberOfLines;
  }
  
  void set_number_of_lines(int lines) {
    objc_view().numberOfLines = lines;
  }
};
}}

#endif
