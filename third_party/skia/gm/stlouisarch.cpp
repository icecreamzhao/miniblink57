/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkPath.h"
#include "SkTArray.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkTArray.h"
>>>>>>> miniblink49

namespace skiagm {

// this GM tests hairlines which fill nearly the entire render target
class StLouisArchGM : public GM {
protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
=======
    SkString onShortName() override {
>>>>>>> miniblink49
        return SkString("stlouisarch");
    }

    SkISize onISize() override { return SkISize::Make((int)kWidth, (int)kHeight); }

<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
        {
            SkPath* bigQuad = &fPaths.push_back();
            bigQuad->moveTo(0, 0);
            bigQuad->quadTo(kWidth / 2, kHeight, kWidth, 0);
=======
    void onOnceBeforeDraw() override {
        {
            SkPath* bigQuad = &fPaths.push_back();
            bigQuad->moveTo(0, 0);
            bigQuad->quadTo(kWidth/2, kHeight, kWidth, 0);
>>>>>>> miniblink49
        }

        {
            SkPath* degenBigQuad = &fPaths.push_back();
            SkScalar yPos = kHeight / 2 + 10;
            degenBigQuad->moveTo(0, yPos);
            degenBigQuad->quadTo(0, yPos, kWidth, yPos);
        }

<<<<<<< HEAD
=======

>>>>>>> miniblink49
        {
            SkPath* bigCubic = &fPaths.push_back();
            bigCubic->moveTo(0, 0);
            bigCubic->cubicTo(0, kHeight,
<<<<<<< HEAD
                kWidth, kHeight,
                kWidth, 0);
=======
                              kWidth, kHeight,
                              kWidth, 0);
>>>>>>> miniblink49
        }

        {
            SkPath* degenBigCubic = &fPaths.push_back();
            SkScalar yPos = kHeight / 2;
            degenBigCubic->moveTo(0, yPos);
            degenBigCubic->cubicTo(0, yPos,
<<<<<<< HEAD
                0, yPos,
                kWidth, yPos);
=======
                                   0, yPos,
                                   kWidth, yPos);
>>>>>>> miniblink49
        }

        {
            SkPath* bigConic = &fPaths.push_back();
            bigConic->moveTo(0, 0);
<<<<<<< HEAD
            bigConic->conicTo(kWidth / 2, kHeight, kWidth, 0, .5);
=======
            bigConic->conicTo(kWidth/2, kHeight, kWidth, 0, .5);
>>>>>>> miniblink49
        }

        {
            SkPath* degenBigConic = &fPaths.push_back();
            SkScalar yPos = kHeight / 2 - 10;
            degenBigConic->moveTo(0, yPos);
            degenBigConic->conicTo(0, yPos, kWidth, yPos, .5);
        }
    }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->save();
        canvas->scale(1, -1);
        canvas->translate(0, -kHeight);
        for (int p = 0; p < fPaths.count(); ++p) {
            SkPaint paint;
            paint.setARGB(0xff, 0, 0, 0);
            paint.setAntiAlias(true);
            paint.setStyle(SkPaint::kStroke_Style);
            paint.setStrokeWidth(0);
            canvas->drawPath(fPaths[p], paint);
        }
        canvas->restore();
    }

    const SkScalar kWidth = 256;
    const SkScalar kHeight = 256;

private:
    SkTArray<SkPath> fPaths;
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new StLouisArchGM; }
static GMRegistry reg(MyFactory);

}
