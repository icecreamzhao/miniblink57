/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkNinePatchIter.h"
#include "SkRect.h"

<<<<<<< HEAD
bool SkNinePatchIter::Valid(int width, int height, const SkIRect& center)
{
    return !center.isEmpty() && SkIRect::MakeWH(width, height).contains(center);
}

SkNinePatchIter::SkNinePatchIter(int w, int h, const SkIRect& c, const SkRect& dst)
{
=======
bool SkNinePatchIter::Valid(int width, int height, const SkIRect& center) {
    return !center.isEmpty() && SkIRect::MakeWH(width, height).contains(center);
}

SkNinePatchIter::SkNinePatchIter(int w, int h, const SkIRect& c, const SkRect& dst) {
>>>>>>> miniblink49
    SkASSERT(SkIRect::MakeWH(w, h).contains(c));

    fSrcX[0] = 0;
    fSrcX[1] = SkIntToScalar(c.fLeft);
    fSrcX[2] = SkIntToScalar(c.fRight);
    fSrcX[3] = SkIntToScalar(w);
<<<<<<< HEAD

=======
    
>>>>>>> miniblink49
    fSrcY[0] = 0;
    fSrcY[1] = SkIntToScalar(c.fTop);
    fSrcY[2] = SkIntToScalar(c.fBottom);
    fSrcY[3] = SkIntToScalar(h);
<<<<<<< HEAD

=======
    
>>>>>>> miniblink49
    fDstX[0] = dst.fLeft;
    fDstX[1] = dst.fLeft + SkIntToScalar(c.fLeft);
    fDstX[2] = dst.fRight - SkIntToScalar(w - c.fRight);
    fDstX[3] = dst.fRight;
<<<<<<< HEAD

=======
    
>>>>>>> miniblink49
    fDstY[0] = dst.fTop;
    fDstY[1] = dst.fTop + SkIntToScalar(c.fTop);
    fDstY[2] = dst.fBottom - SkIntToScalar(h - c.fBottom);
    fDstY[3] = dst.fBottom;
<<<<<<< HEAD

=======
    
>>>>>>> miniblink49
    if (fDstX[1] > fDstX[2]) {
        fDstX[1] = fDstX[0] + (fDstX[3] - fDstX[0]) * c.fLeft / (w - c.width());
        fDstX[2] = fDstX[1];
    }

    if (fDstY[1] > fDstY[2]) {
        fDstY[1] = fDstY[0] + (fDstY[3] - fDstY[0]) * c.fTop / (h - c.height());
        fDstY[2] = fDstY[1];
    }

    fCurrX = fCurrY = 0;
    fDone = false;
}

<<<<<<< HEAD
bool SkNinePatchIter::next(SkRect* src, SkRect* dst)
{
=======
bool SkNinePatchIter::next(SkRect* src, SkRect* dst) {
>>>>>>> miniblink49
    if (fDone) {
        return false;
    }

    const int x = fCurrX;
    const int y = fCurrY;
<<<<<<< HEAD
    SkASSERT(x >= 0 && x < 3);
    SkASSERT(y >= 0 && y < 3);

    src->set(fSrcX[x], fSrcY[y], fSrcX[x + 1], fSrcY[y + 1]);
    dst->set(fDstX[x], fDstY[y], fDstX[x + 1], fDstY[y + 1]);
    if (3 == ++fCurrX) {
        fCurrX = 0;
        fCurrY += 1;
        if (fCurrY >= 3) {
=======
    SkASSERT(x >= 0 && x < 4);
    SkASSERT(y >= 0 && y < 4);

    src->set(fSrcX[x], fSrcY[y], fSrcX[x + 1], fSrcY[y + 1]);
    dst->set(fDstX[x], fDstY[y], fDstX[x + 1], fDstY[y + 1]);
    if (4 == ++fCurrX) {
        fCurrX = 0;
        fCurrY += 1;
        if (fCurrY >= 4) {
>>>>>>> miniblink49
            fDone = true;
        }
    }
    return true;
}
