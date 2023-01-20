
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#import "ReaderView.h"
#import "SkNSWindow.h"
@interface FileReaderWindow : SkNSWindow {
    IBOutlet SkNSView* fView;
    ReaderView* fReaderView;
}
@end
