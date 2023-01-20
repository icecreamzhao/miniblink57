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

#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkPath.h"
=======
#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkPaint.h"
>>>>>>> miniblink49
#include "SkView.h"

///////////////////////////////////////////////////////////////////////////////

class LayerMaskView : public SampleView {
public:
<<<<<<< HEAD
    LayerMaskView()
    {
=======
    LayerMaskView() {
>>>>>>> miniblink49
        this->setBGColor(0xFFDDDDDD);
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    virtual bool onQuery(SkEvent* evt)
    {
=======
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "LayerMask");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void drawMask(SkCanvas* canvas, const SkRect& r)
    {
=======
    void drawMask(SkCanvas* canvas, const SkRect& r) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);

        if (true) {
            SkBitmap mask;
            int w = SkScalarRoundToInt(r.width());
            int h = SkScalarRoundToInt(r.height());
            mask.allocN32Pixels(w, h);
            mask.eraseColor(SK_ColorTRANSPARENT);
            SkCanvas c(mask);
            SkRect bounds = r;
            bounds.offset(-bounds.fLeft, -bounds.fTop);
            c.drawOval(bounds, paint);

            paint.setXfermodeMode(SkXfermode::kDstIn_Mode);
            canvas->drawBitmap(mask, r.fLeft, r.fTop, &paint);
        } else {
            SkPath p;
            p.addOval(r);
            p.setFillType(SkPath::kInverseWinding_FillType);
            paint.setXfermodeMode(SkXfermode::kDstOut_Mode);
            canvas->drawPath(p, paint);
        }
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
        SkRect r;
        r.set(SkIntToScalar(20), SkIntToScalar(20), SkIntToScalar(120), SkIntToScalar(120));
        canvas->saveLayer(&r, nullptr);
=======
    virtual void onDrawContent(SkCanvas* canvas) {
        SkRect  r;
        r.set(SkIntToScalar(20), SkIntToScalar(20), SkIntToScalar(120), SkIntToScalar(120));
        canvas->saveLayer(&r, NULL);
>>>>>>> miniblink49
        canvas->drawColor(SK_ColorRED);
        drawMask(canvas, r);
        canvas->restore();
    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new LayerMaskView; }
static SkViewRegister reg(MyFactory);
