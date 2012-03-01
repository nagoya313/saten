#import <saten/ui/STNViewController.h>
#import <boost/assert.hpp>
#import <saten/ui/view_controller.hpp>

namespace saten { namespace ui {
class view_controller_accessor {
 public:
  explicit view_controller_accessor(view_controller *c) 
      : controller_(c) {} 
  
  void load_view() {
    controller_->load_view();
  }
  
  void view_will_appear(bool animated) {
    controller_->view_will_appear(animated);
  }
  
  void view_did_appear(bool animated) {
    controller_->view_did_appear(animated);
  }
  
  void view_will_disappear(bool animated) {
    controller_->view_will_disappear(animated);
  }
  
  void view_did_disappear(bool animated) {
    controller_->view_did_disappear(animated);
  }
  
 private:
  view_controller *controller_;
};
}}

using accessor = saten::ui::view_controller_accessor;

@implementation STNViewController

- (id)initWithController:(saten::ui::view_controller *)controller {
  if (self = [super init]) {
    BOOST_ASSERT(controller);
    controller_ = controller;
  }
  return self;
}

- (void)loadView {
  BOOST_ASSERT(controller_);
  [super loadView];
  accessor(controller_).load_view();
}

- (void)viewWillAppear:(BOOL)animated {
  BOOST_ASSERT(controller_);
  accessor(controller_).view_will_appear(animated);
}

- (void)viewDidAppear:(BOOL)animated {
  BOOST_ASSERT(controller_);
  accessor(controller_).view_did_appear(animated);
}

- (void)viewWillDisappear:(BOOL)animated {
  BOOST_ASSERT(controller_);
  accessor(controller_).view_will_disappear(animated);
}

- (void)viewDidDisappear:(BOOL)animated {
  BOOST_ASSERT(controller_);
  accessor(controller_).view_did_disappear(animated);
}

@end
