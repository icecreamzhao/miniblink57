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

#include "DecodeFile.h"
#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkXfermode.h"

static sk_sp<SkShader> make_bitmapfade(const SkBitmap& bm)
=======
#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkXfermode.h"
#include "SkComposeShader.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"

static SkShader* make_bitmapfade(const SkBitmap& bm)
>>>>>>> miniblink49
{
    SkPoint pts[2];
    SkColor colors[2];

    pts[0].set(0, 0);
    pts[1].set(0, SkIntToScalar(bm.height()));
    colors[0] = SK_ColorBLACK;
    colors[1] = SkColorSetARGB(0, 0, 0, 0);
<<<<<<< HEAD
    auto shaderA = SkGradientShader::MakeLinear(pts, colors, nullptr, 2, SkShader::kClamp_TileMode);

    auto shaderB = SkShader::MakeBitmapShader(bm,
        SkShader::kClamp_TileMode, SkShader::kClamp_TileMode);

    return SkShader::MakeComposeShader(std::move(shaderB), std::move(shaderA),
        SkXfermode::Make(SkXfermode::kDstIn_Mode));
=======
    SkShader* shaderA = SkGradientShader::CreateLinear(pts, colors, NULL, 2, SkShader::kClamp_TileMode);

    SkShader* shaderB = SkShader::CreateBitmapShader(bm,
                        SkShader::kClamp_TileMode, SkShader::kClamp_TileMode);

    SkXfermode* mode = SkXfermode::Create(SkXfermode::kDstIn_Mode);

    SkShader* shader = new SkComposeShader(shaderB, shaderA, mode);
    shaderA->unref();
    shaderB->unref();
    mode->unref();

    return shader;
>>>>>>> miniblink49
}

class ShaderView : public SampleView {
public:
<<<<<<< HEAD
    sk_sp<SkShader> fShader;
    SkBitmap fBitmap;

    ShaderView()
    {
        decode_file("/skimages/logo.gif", &fBitmap);
=======
    SkShader*   fShader;
    SkBitmap    fBitmap;

    ShaderView() {
        SkImageDecoder::DecodeFile("/skimages/logo.gif", &fBitmap);
>>>>>>> miniblink49

        SkPoint pts[2];
        SkColor colors[2];

        pts[0].set(0, 0);
        pts[1].set(SkIntToScalar(100), 0);
        colors[0] = SK_ColorRED;
        colors[1] = SK_ColorBLUE;
<<<<<<< HEAD
        auto shaderA = SkGradientShader::MakeLinear(pts, colors, nullptr, 2, SkShader::kClamp_TileMode);
=======
        SkShader* shaderA = SkGradientShader::CreateLinear(pts, colors, NULL, 2, SkShader::kClamp_TileMode);
>>>>>>> miniblink49

        pts[0].set(0, 0);
        pts[1].set(0, SkIntToScalar(100));
        colors[0] = SK_ColorBLACK;
        colors[1] = SkColorSetARGB(0x80, 0, 0, 0);
<<<<<<< HEAD
        auto shaderB = SkGradientShader::MakeLinear(pts, colors, nullptr, 2, SkShader::kClamp_TileMode);

        fShader = SkShader::MakeComposeShader(std::move(shaderA), std::move(shaderB),
            SkXfermode::Make(SkXfermode::kDstIn_Mode));
=======
        SkShader* shaderB = SkGradientShader::CreateLinear(pts, colors, NULL, 2, SkShader::kClamp_TileMode);

        SkXfermode* mode = SkXfermode::Create(SkXfermode::kDstIn_Mode);

        fShader = new SkComposeShader(shaderA, shaderB, mode);
        shaderA->unref();
        shaderB->unref();
        mode->unref();
    }
    virtual ~ShaderView() {
        SkSafeUnref(fShader);
>>>>>>> miniblink49
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Shaders");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->drawBitmap(fBitmap, 0, 0);

        canvas->translate(SkIntToScalar(20), SkIntToScalar(120));

        SkPaint paint;
<<<<<<< HEAD
        SkRect r;
=======
        SkRect  r;
>>>>>>> miniblink49

        paint.setColor(SK_ColorGREEN);
        canvas->drawRectCoords(0, 0, SkIntToScalar(100), SkIntToScalar(100), paint);
        paint.setShader(fShader);
        canvas->drawRectCoords(0, 0, SkIntToScalar(100), SkIntToScalar(100), paint);

        canvas->translate(SkIntToScalar(110), 0);

        int w = fBitmap.width();
        int h = fBitmap.height();
        w = 120;
        h = 80;
        r.set(0, 0, SkIntToScalar(w), SkIntToScalar(h));

<<<<<<< HEAD
        paint.setShader(nullptr);
        canvas->drawRect(r, paint);
        paint.setShader(make_bitmapfade(fBitmap));
        canvas->drawRect(r, paint);
    }

    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
        this->inval(nullptr);
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

    bool onClick(Click* click) override
    {
=======
        paint.setShader(NULL);
        canvas->drawRect(r, paint);
        paint.setShader(make_bitmapfade(fBitmap))->unref();
        canvas->drawRect(r, paint);
    }

    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
        this->inval(NULL);
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

    bool onClick(Click* click)  override {
>>>>>>> miniblink49
        return this->INHERITED::onClick(click);
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new ShaderView; }
static SkViewRegister reg(MyFactory);
