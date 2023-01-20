/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkPath.h"
#include "SkShader.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkShader.h"
#include "SkBlurMaskFilter.h"
>>>>>>> miniblink49

namespace skiagm {

/**
 * Stress test the GPU samplers by rendering a textured glyph with a mask and
 * an AA clip
 */
class SamplerStressGM : public GM {
public:
    SamplerStressGM()
<<<<<<< HEAD
        : fTextureCreated(false)
        , fMaskFilter(nullptr)
    {
    }

protected:
    SkString onShortName() override
    {
        return SkString("gpusamplerstress");
    }

    SkISize onISize() override
    {
=======
    : fTextureCreated(false)
    , fShader(NULL)
    , fMaskFilter(NULL) {
    }

    virtual ~SamplerStressGM() {
    }

protected:

    SkString onShortName() override {
        return SkString("gpusamplerstress");
    }

    SkISize onISize() override {
>>>>>>> miniblink49
        return SkISize::Make(640, 480);
    }

    /**
     * Create a red & green stripes on black texture
     */
<<<<<<< HEAD
    void createTexture()
    {
=======
    void createTexture() {
>>>>>>> miniblink49
        if (fTextureCreated) {
            return;
        }

        static const int xSize = 16;
        static const int ySize = 16;

        fTexture.allocN32Pixels(xSize, ySize);
        SkPMColor* addr = fTexture.getAddr32(0, 0);

        for (int y = 0; y < ySize; ++y) {
            for (int x = 0; x < xSize; ++x) {
<<<<<<< HEAD
                addr[y * xSize + x] = SkPreMultiplyColor(SK_ColorBLACK);

                if ((y % 5) == 0) {
                    addr[y * xSize + x] = SkPreMultiplyColor(SK_ColorRED);
                }
                if ((x % 7) == 0) {
                    addr[y * xSize + x] = SkPreMultiplyColor(SK_ColorGREEN);
=======
                addr[y*xSize+x] = SkPreMultiplyColor(SK_ColorBLACK);

                if ((y % 5) == 0) {
                    addr[y*xSize+x] = SkPreMultiplyColor(SK_ColorRED);
                }
                if ((x % 7) == 0) {
                    addr[y*xSize+x] = SkPreMultiplyColor(SK_ColorGREEN);
>>>>>>> miniblink49
                }
            }
        }

        fTextureCreated = true;
    }

<<<<<<< HEAD
    void createShader()
    {
        if (fShader) {
=======
    void createShader() {
        if (fShader.get()) {
>>>>>>> miniblink49
            return;
        }

        createTexture();

<<<<<<< HEAD
        fShader = SkShader::MakeBitmapShader(fTexture, SkShader::kRepeat_TileMode,
            SkShader::kRepeat_TileMode);
    }

    void createMaskFilter()
    {
        if (fMaskFilter) {
=======
        fShader.reset(SkShader::CreateBitmapShader(fTexture,
                                                   SkShader::kRepeat_TileMode,
                                                   SkShader::kRepeat_TileMode));
    }

    void createMaskFilter() {
        if (fMaskFilter.get()) {
>>>>>>> miniblink49
            return;
        }

        const SkScalar sigma = 1;
<<<<<<< HEAD
        fMaskFilter = SkBlurMaskFilter::Make(kNormal_SkBlurStyle, sigma);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        fMaskFilter.reset(SkBlurMaskFilter::Create(kNormal_SkBlurStyle, sigma));
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        createShader();
        createMaskFilter();

        canvas->save();

        // draw a letter "M" with a green & red striped texture and a
        // stipple mask with a round rect soft clip
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setTextSize(72);
<<<<<<< HEAD
        paint.setShader(fShader);
        paint.setMaskFilter(fMaskFilter);
        sk_tool_utils::set_portable_typeface(&paint);

        SkRect temp;
        temp.set(SkIntToScalar(115),
            SkIntToScalar(75),
            SkIntToScalar(144),
            SkIntToScalar(110));
=======
        paint.setShader(fShader.get());
        paint.setMaskFilter(fMaskFilter.get());

        SkRect temp;
        temp.set(SkIntToScalar(115),
                 SkIntToScalar(75),
                 SkIntToScalar(144),
                 SkIntToScalar(110));
>>>>>>> miniblink49

        SkPath path;
        path.addRoundRect(temp, SkIntToScalar(5), SkIntToScalar(5));

        canvas->clipPath(path, SkRegion::kReplace_Op, true); // AA is on

        canvas->drawText("M", 1,
<<<<<<< HEAD
            SkIntToScalar(100), SkIntToScalar(100),
            paint);
=======
                         SkIntToScalar(100), SkIntToScalar(100),
                         paint);
>>>>>>> miniblink49

        canvas->restore();

        // Now draw stroked versions of the "M" and the round rect so we can
        // see what is going on
        SkPaint paint2;
        paint2.setColor(SK_ColorBLACK);
        paint2.setAntiAlias(true);
        paint2.setTextSize(72);
        paint2.setStyle(SkPaint::kStroke_Style);
        paint2.setStrokeWidth(1);
<<<<<<< HEAD
        sk_tool_utils::set_portable_typeface(&paint2);
        canvas->drawText("M", 1,
            SkIntToScalar(100), SkIntToScalar(100),
            paint2);

        paint2.setColor(sk_tool_utils::color_to_565(SK_ColorGRAY));
=======
        canvas->drawText("M", 1,
                         SkIntToScalar(100), SkIntToScalar(100),
                         paint2);

        paint2.setColor(SK_ColorGRAY);
>>>>>>> miniblink49

        canvas->drawPath(path, paint2);
    }

private:
<<<<<<< HEAD
    SkBitmap fTexture;
    bool fTextureCreated;
    sk_sp<SkShader> fShader;
    sk_sp<SkMaskFilter> fMaskFilter;
=======
    SkBitmap      fTexture;
    bool          fTextureCreated;
    SkAutoTUnref<SkShader>     fShader;
    SkAutoTUnref<SkMaskFilter> fMaskFilter;
>>>>>>> miniblink49

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new SamplerStressGM; }
static GMRegistry reg(MyFactory);

}
