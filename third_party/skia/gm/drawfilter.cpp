/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======
#include "gm.h"
>>>>>>> miniblink49
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkDrawFilter.h"
#include "SkPaint.h"
<<<<<<< HEAD
#include "gm.h"

#ifdef SK_SUPPORT_LEGACY_DRAWFILTER
=======
>>>>>>> miniblink49

/**
 * Initial test coverage for SkDrawFilter.
 * Draws two rectangles; if draw filters are broken, they will match.
 * If draw filters are working correctly, the first will be blue and blurred,
 * the second red and sharp.
 */

namespace {
class TestFilter : public SkDrawFilter {
public:
<<<<<<< HEAD
    bool filter(SkPaint* p, Type) override
    {
        p->setColor(SK_ColorRED);
        p->setMaskFilter(nullptr);
=======
    bool filter(SkPaint* p, Type) override {
        p->setColor(SK_ColorRED);
        p->setMaskFilter(NULL);
>>>>>>> miniblink49
        return true;
    }
};
}

class DrawFilterGM : public skiagm::GM {
<<<<<<< HEAD
    sk_sp<SkMaskFilter> fBlur;

protected:
    SkISize onISize() override
    {
        return SkISize::Make(320, 240);
    }

    SkString onShortName() override
    {
        return SkString("drawfilter");
    }

    void onOnceBeforeDraw() override
    {
        fBlur = SkBlurMaskFilter::Make(kNormal_SkBlurStyle,
            SkBlurMask::ConvertRadiusToSigma(10.0f),
            kLow_SkBlurQuality);
    }

    void onDraw(SkCanvas* canvas) override
    {
        SkPaint p;
        p.setColor(SK_ColorBLUE);
        p.setMaskFilter(fBlur);
        SkRect r = { 20, 20, 100, 100 };
        canvas->setDrawFilter(nullptr);
=======
    SkAutoTUnref<SkMaskFilter> fBlur;

protected:
    SkISize onISize() override {
        return SkISize::Make(320, 240);
    }

    SkString onShortName() override {
        return SkString("drawfilter");
    }

    void onOnceBeforeDraw() override {
        fBlur.reset(SkBlurMaskFilter::Create(kNormal_SkBlurStyle,
                    SkBlurMask::ConvertRadiusToSigma(10.0f),
                    kLow_SkBlurQuality));
    }

    void onDraw(SkCanvas* canvas) override {
        SkPaint p;
        p.setColor(SK_ColorBLUE);
        p.setMaskFilter(fBlur.get());
        SkRect r = { 20, 20, 100, 100 };
        canvas->setDrawFilter(NULL);
>>>>>>> miniblink49
        canvas->drawRect(r, p);
        TestFilter redNoBlur;
        canvas->setDrawFilter(&redNoBlur);
        canvas->translate(120.0f, 40.0f);
        canvas->drawRect(r, p);

        // Must unset if the DrawFilter is from the stack to avoid refcount errors!
<<<<<<< HEAD
        canvas->setDrawFilter(nullptr);
=======
        canvas->setDrawFilter(NULL);
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};

<<<<<<< HEAD
DEF_GM(return new DrawFilterGM;)

#endif
=======
static skiagm::GM* MyFactory(void*) { return new DrawFilterGM; }
static skiagm::GMRegistry reg(MyFactory);

>>>>>>> miniblink49
