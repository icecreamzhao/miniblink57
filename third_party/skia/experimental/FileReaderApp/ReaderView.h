
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkBitmap.h"
#include "SkColor.h"
#include "SkView.h"
=======
#include "SkView.h"
#include "SkColor.h"
#include "SkBitmap.h"
>>>>>>> miniblink49

/*
 * Pipe Reader with File IO. This view reads from the data file produced by the
 * Pipe Writer.
 */

class ReaderView : public SkView {
public:
    ReaderView();
    virtual void draw(SkCanvas* canvas);

private:
<<<<<<< HEAD
    int fFilePos;
    int fFront;
    int fBack;
=======
    int     fFilePos;
    int     fFront;
    int     fBack;
>>>>>>> miniblink49
    SkColor fBGColor;
    SkBitmap fBufferBitmaps[2];
    typedef SkView INHERITED;
};
