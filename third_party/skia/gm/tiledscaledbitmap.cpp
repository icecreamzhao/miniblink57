<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD

=======
>>>>>>> miniblink49
#include "gm.h"

#include "Resources.h"
#include "SkBitmap.h"
<<<<<<< HEAD
=======
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkShader.h"
#include "SkStream.h"

<<<<<<< HEAD
/***
=======

 /***
>>>>>>> miniblink49
  *
  * This GM reproduces Skia bug 2904, in which a tiled bitmap shader was failing to draw correctly
  * when fractional image scaling was ignored by the high quality bitmap scaler.
  *
  ***/

namespace skiagm {

class TiledScaledBitmapGM : public GM {
public:
<<<<<<< HEAD
    TiledScaledBitmapGM()
    {
    }

protected:
    SkString onShortName() override
    {
        return SkString("tiledscaledbitmap");
    }

    SkISize onISize() override
    {
        return SkISize::Make(1016, 616);
    }

    static SkBitmap make_bm(int width, int height)
    {
=======

    TiledScaledBitmapGM() {
    }

protected:
    SkString onShortName() override {
        return SkString("tiledscaledbitmap");
    }

    SkISize onISize() override {
        return SkISize::Make(1016, 616);
    }

    static SkBitmap make_bm(int width, int height) {
>>>>>>> miniblink49
        SkBitmap bm;
        bm.allocN32Pixels(width, height);
        bm.eraseColor(SK_ColorTRANSPARENT);
        SkCanvas canvas(bm);
        SkPaint paint;
        paint.setAntiAlias(true);
<<<<<<< HEAD
        canvas.drawCircle(width / 2.f, height / 2.f, width / 4.f, paint);
        return bm;
    }

    void onOnceBeforeDraw() override
    {
        fBitmap = make_bm(360, 288);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        canvas.drawCircle(width/2.f, height/2.f, width/4.f, paint);
        return bm;
    }

    void onOnceBeforeDraw() override {
        fBitmap = make_bm(360, 288);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;

        paint.setAntiAlias(true);
        paint.setFilterQuality(kHigh_SkFilterQuality);

        SkMatrix mat;
<<<<<<< HEAD
        mat.setScale(121.f / 360.f, 93.f / 288.f);
        mat.postTranslate(-72, -72);

        paint.setShader(SkShader::MakeBitmapShader(fBitmap, SkShader::kRepeat_TileMode,
            SkShader::kRepeat_TileMode, &mat));
        canvas->drawRectCoords(8, 8, 1008, 608, paint);
=======
        mat.setScale(121.f/360.f, 93.f/288.f);
        mat.postTranslate(-72, -72);

        SkShader *shader = SkShader::CreateBitmapShader(fBitmap, SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, &mat);
        paint.setShader(shader);

        SkSafeUnref(shader);
        canvas->drawRectCoords(8,8,1008, 608, paint);
>>>>>>> miniblink49
    }

private:
    SkBitmap fBitmap;

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new TiledScaledBitmapGM;)
=======
DEF_GM(return SkNEW(TiledScaledBitmapGM);)

>>>>>>> miniblink49
}
