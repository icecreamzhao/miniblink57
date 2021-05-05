
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#import "SkOptionsTableView.h"
#import "SkSampleNSView.h"
#import <Cocoa/Cocoa.h>
@interface HelloWorldDelegate : NSObject <NSApplicationDelegate> {
    NSWindow* fWindow;
    SkSampleNSView* fView;
    SkOptionsTableView* fOptions;
}

@property (assign) IBOutlet NSWindow* fWindow;
@property (assign) IBOutlet SkSampleNSView* fView;
@property (assign) IBOutlet SkOptionsTableView* fOptions;

- (IBAction)toiPadSize:(id)sender;

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)sender;

@end
