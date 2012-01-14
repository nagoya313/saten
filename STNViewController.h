#import <UIKit/UIKit.h>

namespace saten { namespace ui {
class view_controller;
}}

@interface STNViewController : UIViewController {
 @private
  saten::ui::view_controller *controller_;
}

@property(assign, nonatomic) saten::ui::view_controller *controller;

@end
