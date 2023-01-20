<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SampleCode.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkCornerPathEffect.h"
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkCornerPathEffect.h"
#include "SkCullPoints.h"
>>>>>>> miniblink49
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
<<<<<<< HEAD
#include "SkView.h"

static void create_bitmap(SkBitmap* bitmap)
{
=======

static void create_bitmap(SkBitmap* bitmap) {
>>>>>>> miniblink49
    const int W = 100;
    const int H = 100;
    bitmap->allocN32Pixels(W, H);

    SkCanvas canvas(*bitmap);
    canvas.drawColor(SK_ColorRED);
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
<<<<<<< HEAD
    canvas.drawCircle(SkIntToScalar(W) / 2, SkIntToScalar(H) / 2, SkIntToScalar(W) / 2, paint);
=======
    canvas.drawCircle(SkIntToScalar(W)/2, SkIntToScalar(H)/2, SkIntToScalar(W)/2, paint);
>>>>>>> miniblink49
}

class WritePixelsView : public SampleView {
    SkPath fPath;
<<<<<<< HEAD

public:
    WritePixelsView() { }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
    {
=======
public:
    WritePixelsView() {}

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "WritePixels");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        SkBitmap bitmap;
        create_bitmap(&bitmap);
        int x = bitmap.width() / 2;
        int y = bitmap.height() / 2;

        SkBitmap subset;
        bitmap.extractSubset(&subset, SkIRect::MakeXYWH(x, y, x, y));

        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));

        canvas->writePixels(bitmap, 0, 0);
        canvas->writePixels(subset, 0, 0);
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new WritePixelsView; }
static SkViewRegister reg(MyFactory);
