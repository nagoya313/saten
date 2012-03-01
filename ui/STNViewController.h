#import <UIKit/UIKit.h>

namespace saten { namespace ui {
class view_controller;
}}

@interface STNViewController : UIViewController {
 @private
  saten::ui::view_controller *controller_;
}

- (id)initWithController:(saten::ui::view_controller *)controller;

@end
