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
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkUtils.h"
#include "SkView.h"

<<<<<<< HEAD
static SkBitmap make_bitmap()
{
=======
static SkBitmap make_bitmap() {
>>>>>>> miniblink49
    SkPMColor c[256];
    for (int i = 0; i < 256; i++) {
        c[i] = SkPackARGB32(255 - i, 0, 0, 0);
    }

    SkBitmap bm;
    SkColorTable* ctable = new SkColorTable(c, 256);

    bm.allocPixels(SkImageInfo::Make(256, 256, kIndex_8_SkColorType,
<<<<<<< HEAD
                       kPremul_SkAlphaType),
        nullptr, ctable);
=======
                                     kPremul_SkAlphaType),
                   NULL, ctable);
>>>>>>> miniblink49
    ctable->unref();

    bm.lockPixels();
    const float cx = bm.width() * 0.5f;
    const float cy = bm.height() * 0.5f;
    for (int y = 0; y < bm.height(); y++) {
        float dy = y - cy;
        dy *= dy;
        uint8_t* p = bm.getAddr8(0, y);
        for (int x = 0; x < 256; x++) {
            float dx = x - cx;
            dx *= dx;
<<<<<<< HEAD
            float d = (dx + dy) / (cx / 2);
=======
            float d = (dx + dy) / (cx/2);
>>>>>>> miniblink49
            int id = (int)d;
            if (id > 255) {
                id = 255;
            }
            p[x] = id;
        }
    }
    bm.unlockPixels();
    return bm;
}

class BlurView : public SampleView {
<<<<<<< HEAD
    SkBitmap fBM;

public:
    BlurView()
    {
=======
    SkBitmap    fBM;
public:
    BlurView() {
>>>>>>> miniblink49
        if (false) { // avoid bit rot, suppress warning
            fBM = make_bitmap();
        }
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
            SampleCode::TitleR(evt, "Blur");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void drawBG(SkCanvas* canvas)
    {
        canvas->drawColor(0xFFDDDDDD);
    }

    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    void drawBG(SkCanvas* canvas) {
        canvas->drawColor(0xFFDDDDDD);
    }

    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        drawBG(canvas);

        SkBlurStyle NONE = SkBlurStyle(-999);
        static const struct {
            SkBlurStyle fStyle;
<<<<<<< HEAD
            int fCx, fCy;
        } gRecs[] = {
            { NONE, 0, 0 },
            { kInner_SkBlurStyle, -1, 0 },
            { kNormal_SkBlurStyle, 0, 1 },
            { kSolid_SkBlurStyle, 0, -1 },
            { kOuter_SkBlurStyle, 1, 0 },
=======
            int         fCx, fCy;
        } gRecs[] = {
            { NONE,                                 0,  0 },
            { kInner_SkBlurStyle,  -1,  0 },
            { kNormal_SkBlurStyle,  0,  1 },
            { kSolid_SkBlurStyle,   0, -1 },
            { kOuter_SkBlurStyle,   1,  0 },
>>>>>>> miniblink49
        };

        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setTextSize(25);
        canvas->translate(-40, 0);

        SkBlurMaskFilter::BlurFlags flags = SkBlurMaskFilter::kNone_BlurFlag;
        for (int j = 0; j < 2; j++) {
            canvas->save();
            paint.setColor(SK_ColorBLUE);
            for (size_t i = 0; i < SK_ARRAY_COUNT(gRecs); i++) {
                if (gRecs[i].fStyle != NONE) {
<<<<<<< HEAD
                    paint.setMaskFilter(SkBlurMaskFilter::Make(gRecs[i].fStyle,
                        SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(20)),
                        flags));
                } else {
                    paint.setMaskFilter(nullptr);
                }
                canvas->drawCircle(200 + gRecs[i].fCx * 100.f,
                    200 + gRecs[i].fCy * 100.f, 50, paint);
            }
            // draw text
            {
                paint.setMaskFilter(SkBlurMaskFilter::Make(kNormal_SkBlurStyle,
                    SkBlurMask::ConvertRadiusToSigma(4),
                    flags));
=======
                    SkMaskFilter* mf = SkBlurMaskFilter::Create(gRecs[i].fStyle,
                                      SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(20)),
                                      flags);
                    paint.setMaskFilter(mf)->unref();
                } else {
                    paint.setMaskFilter(NULL);
                }
                canvas->drawCircle(200 + gRecs[i].fCx*100.f,
                                   200 + gRecs[i].fCy*100.f, 50, paint);
            }
            // draw text
            {
                SkMaskFilter* mf = SkBlurMaskFilter::Create(kNormal_SkBlurStyle,
                                      SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(4)),
                                      flags);
                paint.setMaskFilter(mf)->unref();
>>>>>>> miniblink49
                SkScalar x = SkIntToScalar(70);
                SkScalar y = SkIntToScalar(400);
                paint.setColor(SK_ColorBLACK);
                canvas->drawText("Hamburgefons Style", 18, x, y, paint);
                canvas->drawText("Hamburgefons Style", 18, x, y + SkIntToScalar(50), paint);
<<<<<<< HEAD
                paint.setMaskFilter(nullptr);
=======
                paint.setMaskFilter(NULL);
>>>>>>> miniblink49
                paint.setColor(SK_ColorWHITE);
                x -= SkIntToScalar(2);
                y -= SkIntToScalar(2);
                canvas->drawText("Hamburgefons Style", 18, x, y, paint);
            }
            canvas->restore();
            flags = SkBlurMaskFilter::kHighQuality_BlurFlag;
            canvas->translate(350, 0);
        }
    }

private:
    typedef SkView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new BlurView; }
static SkViewRegister reg(MyFactory);
