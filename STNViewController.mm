#import "STNViewController.h"
#import "view_controller.hpp"

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

@implementation STNViewController

@synthesize controller = controller_;

- (void)loadView {
  [super loadView];
  saten::ui::view_controller_accessor(controller_).load_view();
}

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  saten::ui::view_controller_accessor(controller_).view_will_appear(animated);
}

- (void)viewDidAppear:(BOOL)animated {
  [super viewDidAppear:animated];
  saten::ui::view_controller_accessor(controller_).view_did_appear(animated);
}

- (void)viewWillDisappear:(BOOL)animated {
  saten::ui::view_controller_accessor(controller_).view_will_disappear(animated);
  [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated {
  saten::ui::view_controller_accessor(controller_).view_did_disappear(animated);
  [super viewDidDisappear:animated];
}

@end
