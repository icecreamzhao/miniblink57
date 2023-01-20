<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#import "SkWindow.h"
#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
=======
#import <QuartzCore/QuartzCore.h>
#import <Cocoa/Cocoa.h>
#import "SkWindow.h"
>>>>>>> miniblink49
class SkEvent;
@class SkNSView;

@protocol SkNSViewOptionsDelegate <NSObject>
@optional
// Called when the view needs to handle adding an SkOSMenu
<<<<<<< HEAD
- (void)view:(SkNSView*)view didAddMenu:(const SkOSMenu*)menu;
- (void)view:(SkNSView*)view didUpdateMenu:(const SkOSMenu*)menu;
=======
- (void) view:(SkNSView*)view didAddMenu:(const SkOSMenu*)menu;
- (void) view:(SkNSView*)view didUpdateMenu:(const SkOSMenu*)menu;
>>>>>>> miniblink49
@end

@interface SkNSView : NSView {
    BOOL fRedrawRequestPending;

    NSString* fTitle;
    SkOSWindow* fWind;
#if SK_SUPPORT_GPU
    NSOpenGLContext* fGLContext;
#endif
    id<SkNSViewOptionsDelegate> fOptionsDelegate;
}

<<<<<<< HEAD
@property (nonatomic, readonly) SkOSWindow* fWind;
=======
@property (nonatomic, readonly) SkOSWindow *fWind;
>>>>>>> miniblink49
@property (nonatomic, retain) NSString* fTitle;
#if SK_SUPPORT_GPU
@property (nonatomic, retain) NSOpenGLContext* fGLContext;
#endif
@property (nonatomic, assign) id<SkNSViewOptionsDelegate> fOptionsDelegate;

- (id)initWithDefaults;
- (void)setUpWindow;
- (void)resizeSkView:(NSSize)newSize;
- (void)setSkTitle:(const char*)title;
- (void)onAddMenu:(const SkOSMenu*)menu;
- (void)onUpdateMenu:(const SkOSMenu*)menu;
- (void)postInvalWithRect:(const SkIRect*)rectOrNil;
- (BOOL)onHandleEvent:(const SkEvent&)event;

<<<<<<< HEAD
- (bool)attach:(SkOSWindow::SkBackEndTypes)attachType withMSAASampleCount:(int)sampleCount andGetInfo:(SkOSWindow::AttachmentInfo*)info;
=======
- (bool)attach:(SkOSWindow::SkBackEndTypes)attachType withMSAASampleCount:(int) sampleCount andGetInfo:(SkOSWindow::AttachmentInfo*) info;
>>>>>>> miniblink49
- (void)detach;
- (void)present;

- (void)setVSync:(bool)enable;

- (void)freeNativeWind;

@end
