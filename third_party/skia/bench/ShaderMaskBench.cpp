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

#include "Benchmark.h"
#include "SkCanvas.h"
=======
#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkColorShader.h"
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkString.h"
#include "SkTemplates.h"

<<<<<<< HEAD
#define STR "Hamburgefons"
=======
#define STR     "Hamburgefons"
>>>>>>> miniblink49

enum FontQuality {
    kBW,
    kAA,
    kLCD
};

<<<<<<< HEAD
static const char* fontQualityName(const SkPaint& paint)
{
=======
static const char* fontQualityName(const SkPaint& paint) {
>>>>>>> miniblink49
    if (!paint.isAntiAlias()) {
        return "BW";
    }
    if (paint.isLCDRenderText()) {
        return "LCD";
    }
    return "AA";
}

class ShaderMaskBench : public Benchmark {
<<<<<<< HEAD
    SkPaint fPaint;
    SkString fText;
    SkString fName;
    FontQuality fFQ;

public:
    ShaderMaskBench(bool isOpaque, FontQuality fq)
    {
=======
    SkPaint     fPaint;
    SkString    fText;
    SkString    fName;
    FontQuality fFQ;
public:
    ShaderMaskBench(bool isOpaque, FontQuality fq)  {
>>>>>>> miniblink49
        fFQ = fq;
        fText.set(STR);

        fPaint.setAntiAlias(kBW != fq);
        fPaint.setLCDRenderText(kLCD == fq);
<<<<<<< HEAD
        fPaint.setShader(SkShader::MakeColorShader(isOpaque ? 0xFFFFFFFF : 0x80808080));
    }

protected:
    virtual const char* onGetName()
    {
=======
        fPaint.setShader(new SkColorShader(isOpaque ? 0xFFFFFFFF : 0x80808080))->unref();
    }

protected:
    virtual const char* onGetName() {
>>>>>>> miniblink49
        fName.printf("shadermask");
        fName.appendf("_%s", fontQualityName(fPaint));
        fName.appendf("_%02X", fPaint.getAlpha());
        return fName.c_str();
    }

<<<<<<< HEAD
    virtual void onDraw(int loops, SkCanvas* canvas)
    {
=======
    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        const SkIPoint dim = this->getSize();
        SkRandom rand;

        SkPaint paint(fPaint);
        this->setupPaint(&paint);
        // explicitly need these
        paint.setAlpha(fPaint.getAlpha());
        paint.setAntiAlias(kBW != fFQ);
        paint.setLCDRenderText(kLCD == fFQ);

        const SkScalar x0 = SkIntToScalar(-10);
        const SkScalar y0 = SkIntToScalar(-10);

        paint.setTextSize(SkIntToScalar(12));
        for (int i = 0; i < loops; i++) {
            SkScalar x = x0 + rand.nextUScalar1() * dim.fX;
            SkScalar y = y0 + rand.nextUScalar1() * dim.fY;
            canvas->drawText(fText.c_str(), fText.size(), x, y, paint);
        }

        paint.setTextSize(SkIntToScalar(48));
<<<<<<< HEAD
        for (int i = 0; i < loops / 4; i++) {
=======
        for (int i = 0; i < loops / 4 ; i++) {
>>>>>>> miniblink49
            SkScalar x = x0 + rand.nextUScalar1() * dim.fX;
            SkScalar y = y0 + rand.nextUScalar1() * dim.fY;
            canvas->drawText(fText.c_str(), fText.size(), x, y, paint);
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new ShaderMaskBench(true, kBW);)
DEF_BENCH(return new ShaderMaskBench(false, kBW);)
DEF_BENCH(return new ShaderMaskBench(true, kAA);)
DEF_BENCH(return new ShaderMaskBench(false, kAA);)
DEF_BENCH(return new ShaderMaskBench(true, kLCD);)
DEF_BENCH(return new ShaderMaskBench(false, kLCD);)
=======
DEF_BENCH( return new ShaderMaskBench(true,  kBW); )
DEF_BENCH( return new ShaderMaskBench(false, kBW); )
DEF_BENCH( return new ShaderMaskBench(true,  kAA); )
DEF_BENCH( return new ShaderMaskBench(false, kAA); )
DEF_BENCH( return new ShaderMaskBench(true,  kLCD); )
DEF_BENCH( return new ShaderMaskBench(false, kLCD); )
>>>>>>> miniblink49
