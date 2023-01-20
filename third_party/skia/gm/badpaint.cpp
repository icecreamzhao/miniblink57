/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkShader.h"
#include "gm.h"

/** This GM draws with invalid paints. It should draw nothing other than the background. */
class BadPaintGM : public skiagm::GM {
public:
    BadPaintGM() { }
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkShader.h"


/** This GM draws with invalid paints. It should draw nothing other than the background. */
class BadPaintGM : public skiagm::GM {
 public:
    BadPaintGM() {}
>>>>>>> miniblink49

protected:
    SkString onShortName() override { return SkString("badpaint"); }

    SkISize onISize() override { return SkISize::Make(100, 100); }

<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
=======
    void onOnceBeforeDraw() override {
>>>>>>> miniblink49
        SkBitmap emptyBmp;

        SkBitmap blueBmp;
        blueBmp.allocN32Pixels(10, 10);
        blueBmp.eraseColor(SK_ColorBLUE);

        SkMatrix badMatrix;
        badMatrix.setAll(0, 0, 0, 0, 0, 0, 0, 0, 0);

        // Empty bitmap.
        fPaints.push_back().setColor(SK_ColorGREEN);
<<<<<<< HEAD
        fPaints.back().setShader(SkShader::MakeBitmapShader(emptyBmp, SkShader::kClamp_TileMode,
            SkShader::kClamp_TileMode));

        // Non-invertible local matrix.
        fPaints.push_back().setColor(SK_ColorGREEN);
        fPaints.back().setShader(SkShader::MakeBitmapShader(blueBmp, SkShader::kClamp_TileMode,
            SkShader::kClamp_TileMode, &badMatrix));
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        fPaints.back().setShader(SkShader::CreateBitmapShader(emptyBmp, SkShader::kClamp_TileMode,
                                                              SkShader::kClamp_TileMode))->unref();

        // Non-invertible local matrix.
        fPaints.push_back().setColor(SK_ColorGREEN);
        fPaints.back().setShader(SkShader::CreateBitmapShader(blueBmp, SkShader::kClamp_TileMode,
                                                              SkShader::kClamp_TileMode,
                                                              &badMatrix))->unref();
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkRect rect = SkRect::MakeXYWH(10, 10, 80, 80);
        for (int i = 0; i < fPaints.count(); ++i) {
            canvas->drawRect(rect, fPaints[i]);
        }
    }

private:
    SkTArray<SkPaint> fPaints;

    typedef skiagm::GM INHERITED;
};

/////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new BadPaintGM;)
=======
DEF_GM( return SkNEW(BadPaintGM); )
>>>>>>> miniblink49
