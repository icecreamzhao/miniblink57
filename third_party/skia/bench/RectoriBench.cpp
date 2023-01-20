/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkLayerDrawLooper.h"
#include "SkPaint.h"
<<<<<<< HEAD
#include "SkPath.h"
=======
>>>>>>> miniblink49
#include "SkRandom.h"

// This bench replicates a problematic use case of a draw looper used
// to create an inner blurred rect
class RectoriBench : public Benchmark {
public:
<<<<<<< HEAD
    RectoriBench() { }

protected:
    const char* onGetName() override
    {
        return "rectori";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    RectoriBench() {}

protected:

    const char* onGetName() override {
        return "rectori";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkRandom Random;

        for (int i = 0; i < loops; i++) {
            SkScalar blurSigma = Random.nextRangeScalar(1.5f, 25.0f);
<<<<<<< HEAD
            SkScalar size = Random.nextRangeScalar(20 * blurSigma, 50 * blurSigma);
=======
            SkScalar size = Random.nextRangeScalar(20*blurSigma, 50*blurSigma);
>>>>>>> miniblink49

            SkScalar x = Random.nextRangeScalar(0.0f, W - size);
            SkScalar y = Random.nextRangeScalar(0.0f, H - size);

            SkRect inner = { x, y, x + size, y + size };

            SkRect outer(inner);
            // outer is always outset either 2x or 4x the blur radius (we go with 2x)
<<<<<<< HEAD
            outer.outset(2 * blurSigma, 2 * blurSigma);
=======
            outer.outset(2*blurSigma, 2*blurSigma);
>>>>>>> miniblink49

            SkPath p;

            p.addRect(outer);
            p.addRect(inner);
            p.setFillType(SkPath::kEvenOdd_FillType);

            // This will be used to translate the normal draw outside the
            // clip rect and translate the blurred version back inside
            SkScalar translate = 2.0f * size;

            SkPaint paint;
<<<<<<< HEAD
            paint.setLooper(this->createLooper(-translate, blurSigma));
=======
            paint.setLooper(this->createLooper(-translate, blurSigma))->unref();
>>>>>>> miniblink49
            paint.setColor(0xff000000 | Random.nextU());
            paint.setAntiAlias(true);

            canvas->save();
            // clip always equals inner rect so we get the inside blur
            canvas->clipRect(inner);
            canvas->translate(translate, 0);
            canvas->drawPath(p, paint);
            canvas->restore();
        }
    }

private:
    enum {
        W = 640,
        H = 480,
    };

<<<<<<< HEAD
    sk_sp<SkDrawLooper> createLooper(SkScalar xOff, SkScalar sigma)
    {
=======
    SkLayerDrawLooper* createLooper(SkScalar xOff, SkScalar sigma) {
>>>>>>> miniblink49
        SkLayerDrawLooper::Builder looperBuilder;

        //-----------------------------------------------
        SkLayerDrawLooper::LayerInfo info;

        // TODO: add a color filter to better match what is seen in the wild
        info.fPaintBits = /* SkLayerDrawLooper::kColorFilter_Bit |*/
<<<<<<< HEAD
            SkLayerDrawLooper::kMaskFilter_Bit;
=======
                          SkLayerDrawLooper::kMaskFilter_Bit;
>>>>>>> miniblink49
        info.fColorMode = SkXfermode::kDst_Mode;
        info.fOffset.set(xOff, 0);
        info.fPostTranslate = false;

        SkPaint* paint = looperBuilder.addLayer(info);

<<<<<<< HEAD
        paint->setMaskFilter(SkBlurMaskFilter::Make(kNormal_SkBlurStyle, sigma,
            SkBlurMaskFilter::kHighQuality_BlurFlag));
=======
        SkMaskFilter* mf = SkBlurMaskFilter::Create(kNormal_SkBlurStyle,
                                                    sigma,
                                                    SkBlurMaskFilter::kHighQuality_BlurFlag);
        paint->setMaskFilter(mf)->unref();
>>>>>>> miniblink49

        //-----------------------------------------------
        info.fPaintBits = 0;
        info.fOffset.set(0, 0);

        paint = looperBuilder.addLayer(info);
<<<<<<< HEAD
        return looperBuilder.detach();
=======
        return looperBuilder.detachLooper();
>>>>>>> miniblink49
    }

    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new RectoriBench();)
=======
DEF_BENCH( return SkNEW_ARGS(RectoriBench, ()); )
>>>>>>> miniblink49
