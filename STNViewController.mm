#import "STNViewController.h"
#import "view_controller.hpp"

@implementation STNViewController

@synthesize controller = controller_;

- (void)loadView {
  [super loadView];
  controller_->load_view();
}

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  controller_->view_will_appear(animated);
}

- (void)viewDidAppear:(BOOL)animated {
  [super viewDidAppear:animated];
  controller_->view_did_appear(animated);
}

- (void)viewWillDisappear:(BOOL)animated {
  controller_->view_will_disappear(animated);
  [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated {
  controller_->view_did_disappear(animated);
  [super viewDidDisappear:animated];
}

@end
