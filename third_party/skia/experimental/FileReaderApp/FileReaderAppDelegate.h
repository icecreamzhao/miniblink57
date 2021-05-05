
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#import "SkNSWindow.h"
#import <Cocoa/Cocoa.h>
@interface FileReaderAppDelegate : NSObject <NSApplicationDelegate> {
    SkNSWindow* window;
}

@property (assign) IBOutlet SkNSWindow* window;
@end
