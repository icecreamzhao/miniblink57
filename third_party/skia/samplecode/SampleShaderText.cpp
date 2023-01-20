/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleCode.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkView.h"

static void makebm(SkBitmap* bm, int w, int h)
{
    bm->allocN32Pixels(w, h);
    bm->eraseColor(SK_ColorTRANSPARENT);

    SkCanvas canvas(*bm);
    SkScalar s = SkIntToScalar(w < h ? w : h);
    SkPoint pts[] = { { 0, 0 }, { s, s } };
    SkColor colors[] = { SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE };
    SkScalar pos[] = { 0, SK_Scalar1 / 2, SK_Scalar1 };
    SkPaint paint;

    paint.setDither(true);
    paint.setShader(SkGradientShader::MakeLinear(pts, colors, pos,
        SK_ARRAY_COUNT(colors), SkShader::kClamp_TileMode));
    canvas.drawPaint(paint);
}

static sk_sp<SkShader> MakeBitmapShader(SkShader::TileMode tx, SkShader::TileMode ty,
    int w, int h)
{
    static SkBitmap bmp;
    if (bmp.isNull()) {
        makebm(&bmp, w / 2, h / 4);
    }
    return SkShader::MakeBitmapShader(bmp, tx, ty);
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"

static void makebm(SkBitmap* bm, int w, int h) {
    bm->allocN32Pixels(w, h);
    bm->eraseColor(SK_ColorTRANSPARENT);

    SkCanvas    canvas(*bm);
    SkScalar s = SkIntToScalar(w < h ? w : h);
    SkPoint     pts[] = { { 0, 0 }, { s, s } };
    SkColor     colors[] = { SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE };
    SkScalar    pos[] = { 0, SK_Scalar1/2, SK_Scalar1 };
    SkPaint     paint;

    paint.setDither(true);
    paint.setShader(SkGradientShader::CreateLinear(pts, colors, pos,
                                    SK_ARRAY_COUNT(colors), SkShader::kClamp_TileMode))->unref();
    canvas.drawPaint(paint);
}

static SkShader* MakeBitmapShader(SkShader::TileMode tx, SkShader::TileMode ty,
                           int w, int h) {
    static SkBitmap bmp;
    if (bmp.isNull()) {
        makebm(&bmp, w/2, h/4);
    }
    return SkShader::CreateBitmapShader(bmp, tx, ty);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

struct GradData {
<<<<<<< HEAD
    int fCount;
    const SkColor* fColors;
=======
    int             fCount;
    const SkColor*  fColors;
>>>>>>> miniblink49
    const SkScalar* fPos;
};

static const SkColor gColors[] = {
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK
};

static const GradData gGradData[] = {
<<<<<<< HEAD
    { 2, gColors, nullptr },
    { 5, gColors, nullptr },
};

static sk_sp<SkShader> MakeLinear(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm)
{
    return SkGradientShader::MakeLinear(pts, data.fColors, data.fPos, data.fCount, tm);
}

static sk_sp<SkShader> MakeRadial(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm)
{
    SkPoint center;
    center.set(SkScalarAve(pts[0].fX, pts[1].fX),
        SkScalarAve(pts[0].fY, pts[1].fY));
    return SkGradientShader::MakeRadial(center, center.fX, data.fColors,
        data.fPos, data.fCount, tm);
}

static sk_sp<SkShader> MakeSweep(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm)
{
    SkPoint center;
    center.set(SkScalarAve(pts[0].fX, pts[1].fX),
        SkScalarAve(pts[0].fY, pts[1].fY));
    return SkGradientShader::MakeSweep(center.fX, center.fY, data.fColors, data.fPos, data.fCount);
}

static sk_sp<SkShader> Make2Conical(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm)
{
    SkPoint center0, center1;
    center0.set(SkScalarAve(pts[0].fX, pts[1].fX),
        SkScalarAve(pts[0].fY, pts[1].fY));
    center1.set(SkScalarInterp(pts[0].fX, pts[1].fX, SkIntToScalar(3) / 5),
        SkScalarInterp(pts[0].fY, pts[1].fY, SkIntToScalar(1) / 4));
    return SkGradientShader::MakeTwoPointConical(
        center1, (pts[1].fX - pts[0].fX) / 7,
        center0, (pts[1].fX - pts[0].fX) / 2,
        data.fColors, data.fPos, data.fCount, tm);
}

typedef sk_sp<SkShader> (*GradMaker)(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm);
=======
    { 2, gColors, NULL },
    { 5, gColors, NULL },
};

static SkShader* MakeLinear(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm) {
    return SkGradientShader::CreateLinear(pts, data.fColors, data.fPos, data.fCount, tm);
}

static SkShader* MakeRadial(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm) {
    SkPoint center;
    center.set(SkScalarAve(pts[0].fX, pts[1].fX),
               SkScalarAve(pts[0].fY, pts[1].fY));
    return SkGradientShader::CreateRadial(center, center.fX, data.fColors,
                                          data.fPos, data.fCount, tm);
}

static SkShader* MakeSweep(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm) {
    SkPoint center;
    center.set(SkScalarAve(pts[0].fX, pts[1].fX),
               SkScalarAve(pts[0].fY, pts[1].fY));
    return SkGradientShader::CreateSweep(center.fX, center.fY, data.fColors, data.fPos, data.fCount);
}

static SkShader* Make2Conical(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm) {
    SkPoint center0, center1;
    center0.set(SkScalarAve(pts[0].fX, pts[1].fX),
                SkScalarAve(pts[0].fY, pts[1].fY));
    center1.set(SkScalarInterp(pts[0].fX, pts[1].fX, SkIntToScalar(3)/5),
                SkScalarInterp(pts[0].fY, pts[1].fY, SkIntToScalar(1)/4));
    return SkGradientShader::CreateTwoPointConical(
                            center1, (pts[1].fX - pts[0].fX) / 7,
                            center0, (pts[1].fX - pts[0].fX) / 2,
                            data.fColors, data.fPos, data.fCount, tm);
}

typedef SkShader* (*GradMaker)(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm);
>>>>>>> miniblink49

static const GradMaker gGradMakers[] = {
    MakeLinear, MakeRadial, MakeSweep, Make2Conical
};

///////////////////////////////////////////////////////////////////////////////

class ShaderTextView : public SampleView {
public:
<<<<<<< HEAD
    ShaderTextView()
    {
=======
    ShaderTextView() {
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
            SampleCode::TitleR(evt, "Shader Text");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        const char text[] = "Shaded Text";
        const int textLen = SK_ARRAY_COUNT(text) - 1;
        static int pointSize = 36;

        int w = pointSize * textLen;
        int h = pointSize;

        SkPoint pts[2] = {
            { 0, 0 },
            { SkIntToScalar(w), SkIntToScalar(h) }
        };
<<<<<<< HEAD
        SkScalar textBase = SkIntToScalar(h / 2);
=======
        SkScalar textBase = SkIntToScalar(h/2);
>>>>>>> miniblink49

        SkShader::TileMode tileModes[] = {
            SkShader::kClamp_TileMode,
            SkShader::kRepeat_TileMode,
            SkShader::kMirror_TileMode
        };

<<<<<<< HEAD
        static const int gradCount = SK_ARRAY_COUNT(gGradData) * SK_ARRAY_COUNT(gGradMakers);
        static const int bmpCount = SK_ARRAY_COUNT(tileModes) * SK_ARRAY_COUNT(tileModes);
        sk_sp<SkShader> shaders[gradCount + bmpCount];
=======
        static const int gradCount = SK_ARRAY_COUNT(gGradData) *
                                     SK_ARRAY_COUNT(gGradMakers);
        static const int bmpCount = SK_ARRAY_COUNT(tileModes) *
                                    SK_ARRAY_COUNT(tileModes);
        SkShader* shaders[gradCount + bmpCount];
>>>>>>> miniblink49

        int shdIdx = 0;
        for (size_t d = 0; d < SK_ARRAY_COUNT(gGradData); ++d) {
            for (size_t m = 0; m < SK_ARRAY_COUNT(gGradMakers); ++m) {
                shaders[shdIdx++] = gGradMakers[m](pts,
<<<<<<< HEAD
                    gGradData[d],
                    SkShader::kClamp_TileMode);
=======
                                                   gGradData[d],
                                                   SkShader::kClamp_TileMode);
>>>>>>> miniblink49
            }
        }
        for (size_t tx = 0; tx < SK_ARRAY_COUNT(tileModes); ++tx) {
            for (size_t ty = 0; ty < SK_ARRAY_COUNT(tileModes); ++ty) {
                shaders[shdIdx++] = MakeBitmapShader(tileModes[tx],
<<<<<<< HEAD
                    tileModes[ty],
                    w / 8, h);
=======
                                                     tileModes[ty],
                                                     w/8, h);
>>>>>>> miniblink49
            }
        }

        SkPaint paint;
        paint.setDither(true);
        paint.setAntiAlias(true);
        paint.setTextSize(SkIntToScalar(pointSize));

        canvas->save();
        canvas->translate(SkIntToScalar(20), SkIntToScalar(10));

        SkPath path;
        path.arcTo(SkRect::MakeXYWH(SkIntToScalar(-40), SkIntToScalar(15),
<<<<<<< HEAD
                       SkIntToScalar(300), SkIntToScalar(90)),
            SkIntToScalar(225), SkIntToScalar(90),
            false);
=======
                                    SkIntToScalar(300), SkIntToScalar(90)),
                                    SkIntToScalar(225), SkIntToScalar(90),
                                    false);
>>>>>>> miniblink49
        path.close();

        static const int testsPerCol = 8;
        static const int rowHeight = 60;
        static const int colWidth = 300;
        canvas->save();
        for (size_t s = 0; s < SK_ARRAY_COUNT(shaders); s++) {
            canvas->save();
<<<<<<< HEAD
            size_t i = 2 * s;
            canvas->translate(SkIntToScalar((i / testsPerCol) * colWidth),
                SkIntToScalar((i % testsPerCol) * rowHeight));
            paint.setShader(shaders[s]);
=======
            size_t i = 2*s;
            canvas->translate(SkIntToScalar((i / testsPerCol) * colWidth),
                              SkIntToScalar((i % testsPerCol) * rowHeight));
            paint.setShader(shaders[s])->unref();
>>>>>>> miniblink49
            canvas->drawText(text, textLen, 0, textBase, paint);
            canvas->restore();
            canvas->save();
            ++i;
            canvas->translate(SkIntToScalar((i / testsPerCol) * colWidth),
<<<<<<< HEAD
                SkIntToScalar((i % testsPerCol) * rowHeight));
            canvas->drawTextOnPath(text, textLen, path, nullptr, paint);
=======
                              SkIntToScalar((i % testsPerCol) * rowHeight));
            canvas->drawTextOnPath(text, textLen, path, NULL, paint);
>>>>>>> miniblink49
            canvas->restore();
        }
        canvas->restore();
    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new ShaderTextView; }
static SkViewRegister reg(MyFactory);
