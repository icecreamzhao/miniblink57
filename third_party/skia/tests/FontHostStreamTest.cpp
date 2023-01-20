/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkFontDescriptor.h"
#include "SkGraphics.h"
#include "SkPaint.h"
#include "SkPoint.h"
#include "SkRect.h"
#include "SkStream.h"
#include "SkTypeface.h"
#include "SkTypes.h"
#include "Test.h"

static const SkColor bgColor = SK_ColorWHITE;

<<<<<<< HEAD
static void create(SkBitmap* bm, SkIRect bound)
{
    bm->allocN32Pixels(bound.width(), bound.height());
}

static void drawBG(SkCanvas* canvas)
{
=======
static void create(SkBitmap* bm, SkIRect bound) {
    bm->allocN32Pixels(bound.width(), bound.height());
}

static void drawBG(SkCanvas* canvas) {
>>>>>>> miniblink49
    canvas->drawColor(bgColor);
}

/** Assumes that the ref draw was completely inside ref canvas --
    implies that everything outside is "bgColor".
    Checks that all overlap is the same and that all non-overlap on the
    ref is "bgColor".
 */
static bool compare(const SkBitmap& ref, const SkIRect& iref,
<<<<<<< HEAD
    const SkBitmap& test, const SkIRect& itest)
=======
                    const SkBitmap& test, const SkIRect& itest)
>>>>>>> miniblink49
{
    const int xOff = itest.fLeft - iref.fLeft;
    const int yOff = itest.fTop - iref.fTop;

    SkAutoLockPixels alpRef(ref);
    SkAutoLockPixels alpTest(test);

    for (int y = 0; y < test.height(); ++y) {
        for (int x = 0; x < test.width(); ++x) {
            SkColor testColor = test.getColor(x, y);
            int refX = x + xOff;
            int refY = y + yOff;
            SkColor refColor;
<<<<<<< HEAD
            if (refX >= 0 && refX < ref.width() && refY >= 0 && refY < ref.height()) {
=======
            if (refX >= 0 && refX < ref.width() &&
                refY >= 0 && refY < ref.height())
            {
>>>>>>> miniblink49
                refColor = ref.getColor(refX, refY);
            } else {
                refColor = bgColor;
            }
            if (refColor != testColor) {
                return false;
            }
        }
    }
    return true;
}

<<<<<<< HEAD
DEF_TEST(FontHostStream, reporter)
{
=======
DEF_TEST(FontHostStream, reporter) {
>>>>>>> miniblink49
    {
        SkPaint paint;
        paint.setColor(SK_ColorGRAY);
        paint.setTextSize(SkIntToScalar(30));

<<<<<<< HEAD
        paint.setTypeface(SkTypeface::MakeFromName("Georgia", SkFontStyle()));
=======
        SkTypeface* fTypeface = SkTypeface::CreateFromName("Georgia",
                                                           SkTypeface::kNormal);
        SkSafeUnref(paint.setTypeface(fTypeface));
>>>>>>> miniblink49

        SkIRect origRect = SkIRect::MakeWH(64, 64);
        SkBitmap origBitmap;
        create(&origBitmap, origRect);
        SkCanvas origCanvas(origBitmap);

        SkIRect streamRect = SkIRect::MakeWH(64, 64);
        SkBitmap streamBitmap;
        create(&streamBitmap, streamRect);
        SkCanvas streamCanvas(streamBitmap);

        SkPoint point = SkPoint::Make(24, 32);

        // Test: origTypeface and streamTypeface from orig data draw the same
        drawBG(&origCanvas);
        origCanvas.drawText("A", 1, point.fX, point.fY, paint);

<<<<<<< HEAD
        sk_sp<SkTypeface> typeface(SkToBool(paint.getTypeface()) ? sk_ref_sp(paint.getTypeface())
                                                                 : SkTypeface::MakeDefault());
        int ttcIndex;
        SkAutoTDelete<SkStreamAsset> fontData(typeface->openStream(&ttcIndex));
        sk_sp<SkTypeface> streamTypeface(SkTypeface::MakeFromStream(fontData.release()));
=======
        SkTypeface* origTypeface = paint.getTypeface();
        SkAutoTUnref<SkTypeface> aur;
        if (NULL == origTypeface) {
            origTypeface = aur.reset(SkTypeface::RefDefault());
        }

        int ttcIndex;
        SkAutoTDelete<SkStreamAsset> fontData(origTypeface->openStream(&ttcIndex));
        SkTypeface* streamTypeface = SkTypeface::CreateFromStream(fontData.detach());
>>>>>>> miniblink49

        SkFontDescriptor desc;
        bool isLocalStream = false;
        streamTypeface->getFontDescriptor(&desc, &isLocalStream);
        REPORTER_ASSERT(reporter, isLocalStream);

<<<<<<< HEAD
        paint.setTypeface(streamTypeface);
=======
        SkSafeUnref(paint.setTypeface(streamTypeface));
>>>>>>> miniblink49
        drawBG(&streamCanvas);
        streamCanvas.drawPosText("A", 1, &point, paint);

        REPORTER_ASSERT(reporter,
<<<<<<< HEAD
            compare(origBitmap, origRect, streamBitmap, streamRect));
=======
                        compare(origBitmap, origRect, streamBitmap, streamRect));
>>>>>>> miniblink49
    }
    //Make sure the typeface is deleted and removed.
    SkGraphics::PurgeFontCache();
}
