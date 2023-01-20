/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkOSWindow_ios.h"
=======
>>>>>>> miniblink49
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>
<<<<<<< HEAD
=======
#include "SkOSWindow_ios.h"
>>>>>>> miniblink49

class SkEvent;
@class SkUIView;

@protocol SkUIViewOptionsDelegate <NSObject>
@optional
// Called when the view needs to handle adding an SkOSMenu
<<<<<<< HEAD
- (void)view:(SkUIView*)view didAddMenu:(const SkOSMenu*)menu;
- (void)view:(SkUIView*)view didUpdateMenu:(SkOSMenu*)menu;
@end

@interface SkUIView : UIView {
=======
- (void) view:(SkUIView*)view didAddMenu:(const SkOSMenu*)menu;
- (void) view:(SkUIView*)view didUpdateMenu:(SkOSMenu*)menu;
@end

@interface SkUIView : UIView  {
>>>>>>> miniblink49
    UINavigationItem* fTitleItem;
    SkOSWindow* fWind;
    id<SkUIViewOptionsDelegate> fOptionsDelegate;
}

<<<<<<< HEAD
@property (nonatomic, readonly) SkOSWindow* fWind;
=======
@property (nonatomic, readonly) SkOSWindow *fWind;
>>>>>>> miniblink49
@property (nonatomic, retain) UINavigationItem* fTitleItem;
@property (nonatomic, assign) id<SkUIViewOptionsDelegate> fOptionsDelegate;

- (id)initWithDefaults;
- (void)setUpWindow;
- (void)forceRedraw;
- (void)drawInRaster;

- (void)setSkTitle:(const char*)title;
- (void)onAddMenu:(const SkOSMenu*)menu;
- (void)onUpdateMenu:(SkOSMenu*)menu;
- (void)postInvalWithRect:(const SkIRect*)rectOrNil;
- (BOOL)onHandleEvent:(const SkEvent&)event;
- (void)getAttachmentInfo:(SkOSWindow::AttachmentInfo*)info;

@end
