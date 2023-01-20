
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#import "SkOptionsTableViewController.h"
#import "SkUIRootViewController.h"
#import "SkUIView.h"
#import <UIKit/UIKit.h>
=======
#import <UIKit/UIKit.h>
#import "SkOptionsTableViewController.h"
#import "SkUIRootViewController.h"
#import "SkUIView.h"
>>>>>>> miniblink49

class SampleWindow;
class SkData;
@interface SkUIDetailViewController : UIViewController {
    UIPopoverController* fPopOverController;
    SkOptionsTableViewController* fOptionsController;
    UIBarButtonItem* fPrintButton;
    UIBarButtonItem* fOptionsButton;
    SkData* fData;
    SkUIView* fSkUIView;
    SampleWindow* fWind;
}

@property (nonatomic, retain) UIBarButtonItem* fPrintButton;
@property (nonatomic, retain) UIBarButtonItem* fOptionsButton;
@property (nonatomic, retain) SkOptionsTableViewController* fOptionsController;
@property (nonatomic, assign) UIPopoverController* fPopOverController;

//Instance methods
- (void)populateRoot:(SkUIRootViewController*)root;
- (void)goToItem:(NSUInteger)index;
- (void)createButtons;
//UI actions
- (void)printContent;
- (void)presentOptions;

//SplitView popover management
<<<<<<< HEAD
- (void)showRootPopoverButtonItem:(UIBarButtonItem*)barButtonItem;
- (void)invalidateRootPopoverButtonItem:(UIBarButtonItem*)barButtonItem;
=======
- (void)showRootPopoverButtonItem:(UIBarButtonItem *)barButtonItem;
- (void)invalidateRootPopoverButtonItem:(UIBarButtonItem *)barButtonItem;
>>>>>>> miniblink49

@end
