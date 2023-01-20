/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gm.h"

#include "Resources.h"
#include "SampleCode.h"
#include "SkAnimTimer.h"
#include "SkCanvas.h"
<<<<<<< HEAD
#include "SkData.h"
#include "SkGradientShader.h"
#include "SkInterpolator.h"
#include "SkPath.h"
#include "SkRandom.h"
#include "SkSurface.h"
#include "SkTime.h"

static sk_sp<SkSurface> make_surface(SkCanvas* canvas, const SkImageInfo& info)
{
    auto surface = canvas->makeSurface(info);
    if (!surface) {
        surface = SkSurface::MakeRaster(info);
=======
#include "SkInterpolator.h"
#include "SkSurface.h"
#include "SkRandom.h"
#include "SkTime.h"

static SkSurface* make_surface(SkCanvas* canvas, const SkImageInfo& info) {
    SkSurface* surface = canvas->newSurface(info);
    if (!surface) {
        surface = SkSurface::NewRaster(info);
>>>>>>> miniblink49
    }
    return surface;
}

<<<<<<< HEAD
static sk_sp<SkShader> make_shader(const SkRect& bounds)
{
    sk_sp<SkImage> image(GetResourceAsImage("mandrill_128.png"));
    if (!image) {
        return nullptr;
    }
    return image->makeShader(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode);
}

#define N 128
#define ANGLE_DELTA 3
#define SCALE_DELTA (SK_Scalar1 / 32)

static sk_sp<SkImage> make_image()
{
    SkImageInfo info = SkImageInfo::MakeN32(N, N, kOpaque_SkAlphaType);
    auto surface(SkSurface::MakeRaster(info));
=======
#define N   128
#define ANGLE_DELTA 3
#define SCALE_DELTA (SK_Scalar1 / 32)

static SkImage* make_image() {
    SkImageInfo info = SkImageInfo::MakeN32(N, N, kOpaque_SkAlphaType);
    SkAutoTUnref<SkSurface> surface(SkSurface::NewRaster(info));
>>>>>>> miniblink49
    SkCanvas* canvas = surface->getCanvas();
    canvas->drawColor(SK_ColorWHITE);

    SkPath path;
    path.setFillType(SkPath::kEvenOdd_FillType);

<<<<<<< HEAD
    path.addRect(SkRect::MakeWH(N / 2, N));
    path.addRect(SkRect::MakeWH(N, N / 2));
    path.moveTo(0, 0);
    path.lineTo(N, 0);
    path.lineTo(0, N);
    path.close();

    SkPaint paint;
    paint.setShader(make_shader(SkRect::MakeWH(N, N)));

    canvas->drawPath(path, paint);
    return surface->makeImageSnapshot();
}

static sk_sp<SkImage> zoom_up(SkSurface* origSurf, SkImage* orig)
{
    const SkScalar S = 16; // amount to scale up
    const int D = 2; // dimension scaling for the offscreen
    // since we only view the center, don't need to produce the entire thing

    SkImageInfo info = SkImageInfo::MakeN32(orig->width() * D, orig->height() * D,
        kOpaque_SkAlphaType);
    auto surface(origSurf->makeSurface(info));
=======
    path.addRect(SkRect::MakeWH(N/2, N));
    path.addRect(SkRect::MakeWH(N, N/2));
    path.moveTo(0, 0); path.lineTo(N, 0); path.lineTo(0, N); path.close();

    canvas->drawPath(path, SkPaint());
    return surface->newImageSnapshot();
}

static SkImage* zoom_up(SkImage* orig) {
    const SkScalar S = 8;    // amount to scale up
    const int D = 2;    // dimension scaling for the offscreen
    // since we only view the center, don't need to produce the entire thing
    
    SkImageInfo info = SkImageInfo::MakeN32(orig->width() * D, orig->height() * D,
                                            kOpaque_SkAlphaType);
    SkAutoTUnref<SkSurface> surface(orig->newSurface(info));
>>>>>>> miniblink49
    SkCanvas* canvas = surface->getCanvas();
    canvas->drawColor(SK_ColorWHITE);
    canvas->scale(S, S);
    canvas->translate(-SkScalarHalf(orig->width()) * (S - D) / S,
<<<<<<< HEAD
        -SkScalarHalf(orig->height()) * (S - D) / S);
    canvas->drawImage(orig, 0, 0, nullptr);

=======
                      -SkScalarHalf(orig->height()) * (S - D) / S);
    canvas->drawImage(orig, 0, 0, NULL);
    
>>>>>>> miniblink49
    if (S > 3) {
        SkPaint paint;
        paint.setColor(SK_ColorWHITE);
        for (int i = 1; i < orig->height(); ++i) {
            SkScalar y = SkIntToScalar(i);
            canvas->drawLine(0, y, SkIntToScalar(orig->width()), y, paint);
        }
        for (int i = 1; i < orig->width(); ++i) {
            SkScalar x = SkIntToScalar(i);
            canvas->drawLine(x, 0, x, SkIntToScalar(orig->height()), paint);
        }
    }
<<<<<<< HEAD
    return surface->makeImageSnapshot();
=======
    return surface->newImageSnapshot();
>>>>>>> miniblink49
}

struct AnimValue {
    SkScalar fValue;
    SkScalar fMin;
    SkScalar fMax;
    SkScalar fMod;

    operator SkScalar() const { return fValue; }

<<<<<<< HEAD
    void set(SkScalar value, SkScalar min, SkScalar max)
    {
=======
    void set(SkScalar value, SkScalar min, SkScalar max) {
>>>>>>> miniblink49
        fValue = value;
        fMin = min;
        fMax = max;
        fMod = 0;
    }

<<<<<<< HEAD
    void setMod(SkScalar value, SkScalar mod)
    {
=======
    void setMod(SkScalar value, SkScalar mod) {
>>>>>>> miniblink49
        fValue = value;
        fMin = 0;
        fMax = 0;
        fMod = mod;
    }

<<<<<<< HEAD
    SkScalar inc(SkScalar delta)
    {
=======
    SkScalar inc(SkScalar delta) {
>>>>>>> miniblink49
        fValue += delta;
        return this->fixUp();
    }

<<<<<<< HEAD
    SkScalar fixUp()
    {
=======
    SkScalar fixUp() {
>>>>>>> miniblink49
        if (fMod) {
            fValue = SkScalarMod(fValue, fMod);
        } else {
            if (fValue > fMax) {
                fValue = fMax;
            } else if (fValue < fMin) {
                fValue = fMin;
            }
        }
        return fValue;
    }
};

<<<<<<< HEAD
static void draw_box_frame(SkCanvas* canvas, int width, int height)
{
=======
static void draw_box_frame(SkCanvas* canvas, int width, int height) {
>>>>>>> miniblink49
    SkPaint p;
    p.setStyle(SkPaint::kStroke_Style);
    p.setColor(SK_ColorRED);
    SkRect r = SkRect::MakeIWH(width, height);
    r.inset(0.5f, 0.5f);
    canvas->drawRect(r, p);
    canvas->drawLine(r.left(), r.top(), r.right(), r.bottom(), p);
    canvas->drawLine(r.left(), r.bottom(), r.right(), r.top(), p);
}

class FilterQualityView : public SampleView {
<<<<<<< HEAD
    sk_sp<SkImage> fImage;
    AnimValue fScale, fAngle;
    SkSize fCell;
    SkInterpolator fTrans;
    SkMSec fCurrTime;
    bool fShowFatBits;

public:
    FilterQualityView()
        : fImage(make_image())
        , fTrans(2, 2)
        , fShowFatBits(true)
    {
=======
    SkAutoTUnref<SkImage> fImage;
    AnimValue             fScale, fAngle;
    SkSize              fCell;
    SkInterpolator      fTrans;
    SkMSec              fCurrTime;
    bool                fShowFatBits;

public:
    FilterQualityView() : fImage(make_image()), fTrans(2, 2), fShowFatBits(true) {
>>>>>>> miniblink49
        fCell.set(256, 256);

        fScale.set(1, SK_Scalar1 / 8, 1);
        fAngle.setMod(0, 360);

        SkScalar values[2];
        fTrans.setMirror(true);
        fTrans.setReset(true);

        fCurrTime = 0;

        fTrans.setRepeatCount(999);
        values[0] = values[1] = 0;
        fTrans.setKeyFrame(0, fCurrTime, values);
        values[0] = values[1] = 1;
        fTrans.setKeyFrame(1, fCurrTime + 2000, values);
    }

protected:
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "FilterQuality");
            return true;
        }
        SkUnichar uni;
        if (SampleCode::CharQ(*evt, &uni)) {
            switch (uni) {
<<<<<<< HEAD
            case '1':
                fAngle.inc(-ANGLE_DELTA);
                this->inval(nullptr);
                return true;
            case '2':
                fAngle.inc(ANGLE_DELTA);
                this->inval(nullptr);
                return true;
            case '3':
                fScale.inc(-SCALE_DELTA);
                this->inval(nullptr);
                return true;
            case '4':
                fScale.inc(SCALE_DELTA);
                this->inval(nullptr);
                return true;
            case '5':
                fShowFatBits = !fShowFatBits;
                this->inval(nullptr);
                return true;
            default:
                break;
=======
                case '1': fAngle.inc(-ANGLE_DELTA); this->inval(NULL); return true;
                case '2': fAngle.inc( ANGLE_DELTA); this->inval(NULL); return true;
                case '3': fScale.inc(-SCALE_DELTA); this->inval(NULL); return true;
                case '4': fScale.inc( SCALE_DELTA); this->inval(NULL); return true;
                case '5': fShowFatBits = !fShowFatBits; this->inval(NULL); return true;
                default: break;
>>>>>>> miniblink49
            }
        }
        return this->INHERITED::onQuery(evt);
    }

    void drawTheImage(SkCanvas* canvas, const SkISize& size, SkFilterQuality filter,
<<<<<<< HEAD
        SkScalar dx, SkScalar dy)
    {
=======
                      SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setFilterQuality(filter);

        SkAutoCanvasRestore acr(canvas, true);

        canvas->translate(dx, dy);

        canvas->translate(SkScalarHalf(size.width()), SkScalarHalf(size.height()));
        canvas->scale(fScale, fScale);
        canvas->rotate(fAngle);
<<<<<<< HEAD
        canvas->drawImage(fImage.get(), -SkScalarHalf(fImage->width()), -SkScalarHalf(fImage->height()),
            &paint);
=======
        canvas->drawImage(fImage, -SkScalarHalf(fImage->width()), -SkScalarHalf(fImage->height()),
                          &paint);
>>>>>>> miniblink49

        if (false) {
            acr.restore();
            draw_box_frame(canvas, size.width(), size.height());
        }
    }

<<<<<<< HEAD
    void drawHere(SkCanvas* canvas, SkFilterQuality filter, SkScalar dx, SkScalar dy)
    {
=======
    void drawHere(SkCanvas* canvas, SkFilterQuality filter, SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
        SkCanvas* origCanvas = canvas;
        SkAutoCanvasRestore acr(canvas, true);

        SkISize size = SkISize::Make(fImage->width(), fImage->height());

<<<<<<< HEAD
        sk_sp<SkSurface> surface;
        if (fShowFatBits) {
            // scale up so we don't clip rotations
            SkImageInfo info = SkImageInfo::MakeN32(fImage->width() * 2, fImage->height() * 2,
                kOpaque_SkAlphaType);
            surface = make_surface(canvas, info);
=======
        SkAutoTUnref<SkSurface> surface;
        if (fShowFatBits) {
            // scale up so we don't clip rotations
            SkImageInfo info = SkImageInfo::MakeN32(fImage->width() * 2, fImage->height() * 2,
                                                    kOpaque_SkAlphaType);
            surface.reset(make_surface(canvas, info));
>>>>>>> miniblink49
            canvas = surface->getCanvas();
            canvas->drawColor(SK_ColorWHITE);
            size.set(info.width(), info.height());
        } else {
            canvas->translate(SkScalarHalf(fCell.width() - fImage->width()),
<<<<<<< HEAD
                SkScalarHalf(fCell.height() - fImage->height()));
=======
                              SkScalarHalf(fCell.height() - fImage->height()));
>>>>>>> miniblink49
        }
        this->drawTheImage(canvas, size, filter, dx, dy);

        if (surface) {
<<<<<<< HEAD
            sk_sp<SkImage> orig(surface->makeImageSnapshot());
            sk_sp<SkImage> zoomed(zoom_up(surface.get(), orig.get()));
            origCanvas->drawImage(zoomed.get(),
                SkScalarHalf(fCell.width() - zoomed->width()),
                SkScalarHalf(fCell.height() - zoomed->height()));
        }
    }

    void drawBorders(SkCanvas* canvas)
    {
=======
            SkAutoTUnref<SkImage> orig(surface->newImageSnapshot());
            SkAutoTUnref<SkImage> zoomed(zoom_up(orig));
            origCanvas->drawImage(zoomed,
                                  SkScalarHalf(fCell.width() - zoomed->width()),
                                  SkScalarHalf(fCell.height() - zoomed->height()));
        }
    }

    void drawBorders(SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint p;
        p.setStyle(SkPaint::kStroke_Style);
        p.setColor(SK_ColorBLUE);

        SkRect r = SkRect::MakeWH(fCell.width() * 2, fCell.height() * 2);
        r.inset(SK_ScalarHalf, SK_ScalarHalf);
        canvas->drawRect(r, p);
        canvas->drawLine(r.left(), r.centerY(), r.right(), r.centerY(), p);
        canvas->drawLine(r.centerX(), r.top(), r.centerX(), r.bottom(), p);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        fCell.set(this->height() / 2, this->height() / 2);

        SkScalar trans[2];
        fTrans.timeToValues(fCurrTime, trans);

        for (int y = 0; y < 2; ++y) {
            for (int x = 0; x < 2; ++x) {
                int index = y * 2 + x;
                SkAutoCanvasRestore acr(canvas, true);
                canvas->translate(fCell.width() * x, fCell.height() * y);
                SkRect r = SkRect::MakeWH(fCell.width(), fCell.height());
                r.inset(4, 4);
                canvas->clipRect(r);
                this->drawHere(canvas, SkFilterQuality(index), trans[0], trans[1]);
            }
        }

        this->drawBorders(canvas);

        const SkScalar textX = fCell.width() * 2 + 30;

        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setTextSize(36);
        SkString str;
        str.appendScalar(fScale);
        canvas->drawText(str.c_str(), str.size(), textX, 100, paint);
<<<<<<< HEAD
        str.reset();
        str.appendScalar(fAngle);
        canvas->drawText(str.c_str(), str.size(), textX, 150, paint);

        str.reset();
        str.appendScalar(trans[0]);
        canvas->drawText(str.c_str(), str.size(), textX, 200, paint);
        str.reset();
        str.appendScalar(trans[1]);
        canvas->drawText(str.c_str(), str.size(), textX, 250, paint);
    }

    bool onAnimate(const SkAnimTimer& timer) override
    {
=======
        str.reset(); str.appendScalar(fAngle);
        canvas->drawText(str.c_str(), str.size(), textX, 150, paint);

        str.reset(); str.appendScalar(trans[0]);
        canvas->drawText(str.c_str(), str.size(), textX, 200, paint);
        str.reset(); str.appendScalar(trans[1]);
        canvas->drawText(str.c_str(), str.size(), textX, 250, paint);
    }

    bool onAnimate(const SkAnimTimer& timer) override {
>>>>>>> miniblink49
        fCurrTime = timer.msec();
        return true;
    }

<<<<<<< HEAD
    virtual bool handleKey(SkKey key)
    {
        this->inval(nullptr);
=======
    virtual bool handleKey(SkKey key) {
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FilterQualityView; }
static SkViewRegister reg(MyFactory);
