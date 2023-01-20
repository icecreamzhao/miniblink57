<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkShader.h"
#include "SkString.h"

<<<<<<< HEAD
static void create_gradient(SkBitmap* bm)
{
=======
static void create_gradient(SkBitmap* bm) {
>>>>>>> miniblink49
    SkASSERT(1 == bm->width());
    const int height = bm->height();

    float deltaB = 255.0f / height;
    float blue = 255.0f;

    SkAutoLockPixels lock(*bm);
    for (int y = 0; y < height; y++) {
<<<<<<< HEAD
        *bm->getAddr32(0, y) = SkColorSetRGB(0, 0, (U8CPU)blue);
=======
        *bm->getAddr32(0, y) = SkColorSetRGB(0, 0, (U8CPU) blue);
>>>>>>> miniblink49
        blue -= deltaB;
    }
}

// Test out the special case of a tiled 1xN texture. Test out opacity,
// filtering and the different tiling modes
class ConstXTileBench : public Benchmark {
<<<<<<< HEAD
    SkPaint fPaint;
    SkString fName;
    bool fDoFilter;
    bool fDoTrans;
    bool fDoScale;
=======
    SkPaint             fPaint;
    SkString            fName;
    bool                fDoFilter;
    bool                fDoTrans;
    bool                fDoScale;
>>>>>>> miniblink49
    static const int kWidth = 1;
    static const int kHeight = 300;

public:
    ConstXTileBench(SkShader::TileMode xTile,
<<<<<<< HEAD
        SkShader::TileMode yTile,
        bool doFilter,
        bool doTrans,
        bool doScale)
        : fDoFilter(doFilter)
        , fDoTrans(doTrans)
        , fDoScale(doScale)
    {
=======
                    SkShader::TileMode yTile,
                    bool doFilter,
                    bool doTrans,
                    bool doScale)
        : fDoFilter(doFilter)
        , fDoTrans(doTrans)
        , fDoScale(doScale) {
>>>>>>> miniblink49
        SkBitmap bm;

        bm.allocN32Pixels(kWidth, kHeight, true);
        bm.eraseColor(SK_ColorWHITE);

        create_gradient(&bm);

<<<<<<< HEAD
        fPaint.setShader(SkShader::MakeBitmapShader(bm, xTile, yTile));
=======
        SkShader* s = SkShader::CreateBitmapShader(bm, xTile, yTile);
        fPaint.setShader(s)->unref();
>>>>>>> miniblink49

        fName.printf("constXTile_");

        static const char* gTileModeStr[SkShader::kTileModeCount] = { "C", "R", "M" };
        fName.append(gTileModeStr[xTile]);
        fName.append(gTileModeStr[yTile]);

        if (doFilter) {
            fName.append("_filter");
        }

        if (doTrans) {
            fName.append("_trans");
        }

        if (doScale) {
            fName.append("_scale");
        }
    }

protected:
<<<<<<< HEAD
    virtual const char* onGetName()
    {
        return fName.c_str();
    }

    virtual void onDraw(int loops, SkCanvas* canvas)
    {
=======
    virtual const char* onGetName() {
        return fName.c_str();
    }

    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint(fPaint);
        this->setupPaint(&paint);
        paint.setFilterQuality(fDoFilter ? kLow_SkFilterQuality
                                         : kNone_SkFilterQuality);
        if (fDoTrans) {
            paint.setColor(SkColorSetARGBMacro(0x80, 0xFF, 0xFF, 0xFF));
        }

        SkRect r;

        if (fDoScale) {
            r = SkRect::MakeWH(SkIntToScalar(2 * 640), SkIntToScalar(2 * 480));
            canvas->scale(SK_ScalarHalf, SK_ScalarHalf);
        } else {
            r = SkRect::MakeWH(SkIntToScalar(640), SkIntToScalar(480));
        }

        SkPaint bgPaint;
        bgPaint.setColor(SK_ColorWHITE);

        for (int i = 0; i < loops; i++) {
            if (fDoTrans) {
                canvas->drawRect(r, bgPaint);
            }

            canvas->drawRect(r, paint);
        }
    }

private:
    typedef Benchmark INHERITED;
};

// Scaled benches are trending towards free.  Seems like caching.
// TODO(mtklein, reed): fix and reenable

//DEF_BENCH(return new ConstXTileBench(SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, false, false, true))
DEF_BENCH(return new ConstXTileBench(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode, false, false, false))
//DEF_BENCH(return new ConstXTileBench(SkShader::kMirror_TileMode, SkShader::kMirror_TileMode, false, false, true))

DEF_BENCH(return new ConstXTileBench(SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, true, false, false))
//DEF_BENCH(return new ConstXTileBench(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode, true, false, true))
DEF_BENCH(return new ConstXTileBench(SkShader::kMirror_TileMode, SkShader::kMirror_TileMode, true, false, false))

//DEF_BENCH(return new ConstXTileBench(SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, false, true, true))
DEF_BENCH(return new ConstXTileBench(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode, false, true, false))
//DEF_BENCH(return new ConstXTileBench(SkShader::kMirror_TileMode, SkShader::kMirror_TileMode, false, true, true))

DEF_BENCH(return new ConstXTileBench(SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, true, true, false))
//DEF_BENCH(return new ConstXTileBench(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode, true, true, true))
DEF_BENCH(return new ConstXTileBench(SkShader::kMirror_TileMode, SkShader::kMirror_TileMode, true, true, false))
