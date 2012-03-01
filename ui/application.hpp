#ifndef SATEN_UI_APPLICATION_HPP_
#define SATEN_UI_APPLICATION_HPP_
#import <UIKit/UIKit.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace saten { namespace ui {
class application_delegate : boost::noncopyable {
 public:
  virtual ~application_delegate() {}
    
 protected:
  virtual bool did_finish_launching() {
    return true;
  }
    
  virtual void application_will_resign_active() {}
  virtual void application_didEnter_background() {}
  virtual void application_will_enter_foreground() {}
  virtual void application_did_become_active() {}
  virtual void application_will_terminate() {}
    
  friend class application_delegate_accessor;
};
  
int application_main(int argc, 
                     char **argv,
                     const boost::shared_ptr<application_delegate> &delegate);
}}

#endif
