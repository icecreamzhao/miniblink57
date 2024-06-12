// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ui/base/ios/cru_context_menu_controller.h"

#include <algorithm>

#include "base/ios/weak_nsobject.h"
#include "base/logging.h"
#import "base/mac/scoped_nsobject.h"
#include "ui/base/device_form_factor.h"
#import "ui/base/ios/cru_context_menu_holder.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/strings/grit/ui_strings.h"

// Abstracts system implementation of popovers and action sheets.
@protocol CRUContextMenuControllerImpl<NSObject>

// Whether the context menu is visible.
@property(nonatomic, readonly, getter=isVisible) BOOL visible;

// Displays a context menu.
- (void)showWithHolder:(CRUContextMenuHolder*)menuHolder
               atPoint:(CGPoint)localPoint
                inView:(UIView*)view;
@end

// Backs up CRUContextMenuController by using UIAlertController.
@interface CRUAlertController : NSObject<CRUContextMenuControllerImpl>
// Redefined to readwrite.
@property(nonatomic, readwrite, getter=isVisible) BOOL visible;
@end

// Displays a context menu. Implements Bridge pattern.
@implementation CRUContextMenuController {
  // Implementation specific for iOS version.
  base::scoped_nsprotocol<id<CRUContextMenuControllerImpl>> _impl;
}

- (BOOL)isVisible {
  return [_impl isVisible];
}

- (instancetype)init {
  self = [super init];
  if (self) {
    _impl.reset([[CRUAlertController alloc] init]);
  }
  return self;
}

- (void)showWithHolder:(CRUContextMenuHolder*)menuHolder
               atPoint:(CGPoint)point
                inView:(UIView*)view {
  DCHECK(menuHolder.itemCount);
  // Check that the view is still visible on screen, otherwise just return and
  // don't show the context menu.
  if (![view window] && ![view isKindOfClass:[UIWindow class]])
    return;
  [_impl showWithHolder:menuHolder atPoint:point inView:view];
}

@end

@implementation CRUAlertController
@synthesize visible = _visible;

- (CGSize)sizeForTitleThatFitsMenuWithHolder:(CRUContextMenuHolder*)menuHolder
                                     atPoint:(CGPoint)point
                                      inView:(UIView*)view {
  // Presenting and dismissing a dummy UIAlertController flushes a screen.
  // As a workaround return an estimation of the space available depending
  // on the device's type.
  const CGFloat kAvailableWidth = 320;
  const CGFloat kAvailableHeightTablet = 200;
  const CGFloat kAvailableHeightPhone = 100;
  if (ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET) {
    return CGSizeMake(kAvailableWidth, kAvailableHeightTablet);
  }
  return CGSizeMake(kAvailableWidth, kAvailableHeightPhone);
}

- (void)showWithHolder:(CRUContextMenuHolder*)menuHolder
               atPoint:(CGPoint)point
                inView:(UIView*)view {
  UIAlertController* alert = [UIAlertController
      alertControllerWithTitle:menuHolder.menuTitle
                       message:nil
                preferredStyle:UIAlertControllerStyleActionSheet];
  alert.popoverPresentationController.sourceView = view;
  alert.popoverPresentationController.sourceRect =
      CGRectMake(point.x, point.y, 1.0, 1.0);

  // Add the actions.
  base::WeakNSObject<CRUAlertController> weakSelf(self);
  [menuHolder.itemTitles enumerateObjectsUsingBlock:^(NSString* itemTitle,
                                                      NSUInteger itemIndex,
                                                      BOOL*) {
    void (^actionHandler)(UIAlertAction*) = ^(UIAlertAction* action) {
      [menuHolder performActionAtIndex:itemIndex];
      [weakSelf setVisible:NO];
    };
    [alert addAction:[UIAlertAction actionWithTitle:itemTitle
                                              style:UIAlertActionStyleDefault
                                            handler:actionHandler]];
  }];

  // Cancel button goes last, to match other browsers.
  void (^cancelHandler)(UIAlertAction*) = ^(UIAlertAction* action) {
    [weakSelf setVisible:NO];
  };
  UIAlertAction* cancel_action =
      [UIAlertAction actionWithTitle:l10n_util::GetNSString(IDS_APP_CANCEL)
                               style:UIAlertActionStyleCancel
                             handler:cancelHandler];
  [alert addAction:cancel_action];

  // Present sheet/popover using controller that is added to view hierarchy.
  UIViewController* topController = view.window.rootViewController;
  while (topController.presentedViewController)
    topController = topController.presentedViewController;
  [topController presentViewController:alert animated:YES completion:nil];
  self.visible = YES;
}

@end
