<<<<<<< HEAD
#import "SkEvent.h"
#import "SkOSMenu.h"
#import "SkOptionListController.h"
#import "SkUIView.h"
#import <UIKit/UIKit.h>
=======
#import <UIKit/UIKit.h>
#import "SkOptionListController.h"
#import "SkOSMenu.h"
#import "SkEvent.h"
#import "SkUIView.h"
>>>>>>> miniblink49
@interface SkOptionItem : NSObject {
    UITableViewCell* fCell;
    const SkOSMenu::Item* fItem;
}
@property (nonatomic, assign) const SkOSMenu::Item* fItem;
@property (nonatomic, retain) UITableViewCell* fCell;

@end

<<<<<<< HEAD
@interface SkOptionListItem : SkOptionItem {
=======
@interface SkOptionListItem : SkOptionItem{
>>>>>>> miniblink49
    SkOptionListController* fOptions;
}
@property (nonatomic, retain) SkOptionListController* fOptions;

@end

@interface SkOptionsTableViewController : UITableViewController <UINavigationControllerDelegate, SkUIViewOptionsDelegate> {
    NSMutableArray* fItems;
    const SkTDArray<SkOSMenu*>* fMenus;
    SkOptionListItem* fCurrentList;
}

@property (nonatomic, retain) NSMutableArray* fItems;
@property (nonatomic, retain) SkOptionListItem* fCurrentList;

- (void)registerMenus:(const SkTDArray<SkOSMenu*>*)menus;
- (void)updateMenu:(SkOSMenu*)menu;
- (void)loadMenu:(SkOSMenu*)menu;

- (UITableViewCell*)createAction:(NSString*)title;
- (UITableViewCell*)createSlider:(NSString*)title min:(float)min max:(float)max default:(float)value;
- (UITableViewCell*)createSwitch:(NSString*)title default:(BOOL)state;
- (UITableViewCell*)createTriState:(NSString*)title default:(int)index;
- (UITableViewCell*)createTextField:(NSString*)title default:(NSString*)value;
- (UITableViewCell*)createList:(NSString*)title default:(NSString*)value;

@end
