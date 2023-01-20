<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkScanPriv_DEFINED
#define SkScanPriv_DEFINED

#include "SkBlitter.h"
#include "SkScan.h"
=======

#ifndef SkScanPriv_DEFINED
#define SkScanPriv_DEFINED

#include "SkScan.h"
#include "SkBlitter.h"
>>>>>>> miniblink49

class SkScanClipper {
public:
    SkScanClipper(SkBlitter* blitter, const SkRegion* clip, const SkIRect& bounds,
<<<<<<< HEAD
        bool skipRejectTest = false);

    SkBlitter* getBlitter() const { return fBlitter; }
    const SkIRect* getClipRect() const { return fClipRect; }

private:
    SkRectClipBlitter fRectBlitter;
    SkRgnClipBlitter fRgnBlitter;
    SkBlitter* fBlitter;
    const SkIRect* fClipRect;
=======
                  bool skipRejectTest = false);

    SkBlitter*      getBlitter() const { return fBlitter; }
    const SkIRect*  getClipRect() const { return fClipRect; }

private:
    SkRectClipBlitter   fRectBlitter;
    SkRgnClipBlitter    fRgnBlitter;
    SkBlitter*          fBlitter;
    const SkIRect*      fClipRect;
>>>>>>> miniblink49
};

// clipRect == null means path is entirely inside the clip
void sk_fill_path(const SkPath& path, const SkIRect* clipRect,
<<<<<<< HEAD
    SkBlitter* blitter, int start_y, int stop_y, int shiftEdgesUp,
    const SkRegion& clipRgn);
=======
                  SkBlitter* blitter, int start_y, int stop_y, int shiftEdgesUp,
                  const SkRegion& clipRgn);
>>>>>>> miniblink49

// blit the rects above and below avoid, clipped to clip
void sk_blit_above(SkBlitter*, const SkIRect& avoid, const SkRegion& clip);
void sk_blit_below(SkBlitter*, const SkIRect& avoid, const SkRegion& clip);

#endif
