
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#import "SkUISplitViewController.h"
#import <UIKit/UIKit.h>

@interface AppDelegate_iPad : NSObject <UIApplicationDelegate> {
@private
    ;
=======
#import <UIKit/UIKit.h>
#import "SkUISplitViewController.h"

@interface AppDelegate_iPad : NSObject <UIApplicationDelegate> {
@private;
>>>>>>> miniblink49
    UIWindow* window;
    SkUISplitViewController* splitViewController;
}
@property (nonatomic, retain) IBOutlet UIWindow* window;
@property (nonatomic, retain) IBOutlet SkUISplitViewController* splitViewController;

@end
