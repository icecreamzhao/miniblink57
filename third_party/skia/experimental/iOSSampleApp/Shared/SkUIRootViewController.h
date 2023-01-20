
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#import <UIKit/UIKit.h>

@interface SkUIRootViewController : UITableViewController <UITableViewDataSource> {
@private
<<<<<<< HEAD
    UIPopoverController* popoverController;
    UIBarButtonItem* popoverButtonItem;
    NSMutableArray* fSamples;
}
@property (nonatomic, retain) UIPopoverController* popoverController;
@property (nonatomic, retain) UIBarButtonItem* popoverButtonItem;
=======
    UIPopoverController *popoverController;
    UIBarButtonItem *popoverButtonItem;
    NSMutableArray* fSamples;
}
@property (nonatomic, retain) UIPopoverController *popoverController;
@property (nonatomic, retain) UIBarButtonItem *popoverButtonItem;
>>>>>>> miniblink49

- (void)addItem:(NSString*)anItem;

@end
