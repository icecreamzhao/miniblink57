/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======
#include "gm.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "gm.h"
=======
>>>>>>> miniblink49

#include "SkBlurImageFilter.h"
#include "SkColorFilterImageFilter.h"
#include "SkDropShadowImageFilter.h"
<<<<<<< HEAD
#include "SkSpecialImage.h"
=======
#include "SkTestImageFilters.h"
>>>>>>> miniblink49

class FailImageFilter : public SkImageFilter {
public:
    class Registrar {
    public:
<<<<<<< HEAD
        Registrar()
        {
            SkFlattenable::Register("FailImageFilter",
                FailImageFilter::CreateProc,
                FailImageFilter::GetFlattenableType());
        }
    };
    static sk_sp<SkImageFilter> Make()
    {
        return sk_sp<SkImageFilter>(new FailImageFilter);
=======
        Registrar() {
            SkFlattenable::Register("FailImageFilter",
                                    FailImageFilter::CreateProc,
                                    FailImageFilter::GetFlattenableType());
        }
    };
    static FailImageFilter* Create() {
        return SkNEW(FailImageFilter);
>>>>>>> miniblink49
    }

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(FailImageFilter)

protected:
<<<<<<< HEAD
    FailImageFilter()
        : INHERITED(nullptr, 0, nullptr)
    {
    }

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override
    {
        return nullptr;
=======
    FailImageFilter() : INHERITED(0, NULL) {}

    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override {
        return false;
>>>>>>> miniblink49
    }

private:
    typedef SkImageFilter INHERITED;
};

static FailImageFilter::Registrar gReg0;

<<<<<<< HEAD
sk_sp<SkFlattenable> FailImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 0);
    return FailImageFilter::Make();
}

#ifndef SK_IGNORE_TO_STRING
void FailImageFilter::toString(SkString* str) const
{
=======
SkFlattenable* FailImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 0);
    return FailImageFilter::Create();
}

#ifndef SK_IGNORE_TO_STRING
void FailImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("FailImageFilter: (");
    str->append(")");
}
#endif

class IdentityImageFilter : public SkImageFilter {
public:
    class Registrar {
    public:
<<<<<<< HEAD
        Registrar()
        {
            SkFlattenable::Register("IdentityImageFilter",
                IdentityImageFilter::CreateProc,
                IdentityImageFilter::GetFlattenableType());
        }
    };
    static sk_sp<SkImageFilter> Make(sk_sp<SkImageFilter> input)
    {
        return sk_sp<SkImageFilter>(new IdentityImageFilter(std::move(input)));
=======
        Registrar() {
            SkFlattenable::Register("IdentityImageFilter",
                                    IdentityImageFilter::CreateProc,
                                    IdentityImageFilter::GetFlattenableType());
        }
    };
    static IdentityImageFilter* Create(SkImageFilter* input = NULL) {
        return SkNEW_ARGS(IdentityImageFilter, (input));
>>>>>>> miniblink49
    }

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(IdentityImageFilter)
<<<<<<< HEAD

protected:
    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override
    {
        offset->set(0, 0);
        return sk_ref_sp<SkSpecialImage>(source);
    }

private:
    IdentityImageFilter(sk_sp<SkImageFilter> input)
        : INHERITED(&input, 1, nullptr)
    {
    }

=======
protected:
    IdentityImageFilter(SkImageFilter* input) : INHERITED(1, &input) {}

    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override {
        *result = src;
        offset->set(0, 0);
        return true;
    }

private:
>>>>>>> miniblink49
    typedef SkImageFilter INHERITED;
};

static IdentityImageFilter::Registrar gReg1;

<<<<<<< HEAD
sk_sp<SkFlattenable> IdentityImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    return IdentityImageFilter::Make(common.getInput(0));
}

#ifndef SK_IGNORE_TO_STRING
void IdentityImageFilter::toString(SkString* str) const
{
=======
SkFlattenable* IdentityImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    return IdentityImageFilter::Create(common.getInput(0));
}

#ifndef SK_IGNORE_TO_STRING
void IdentityImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("IdentityImageFilter: (");
    str->append(")");
}
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static void draw_paint(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setImageFilter(std::move(imf));
=======
static void draw_paint(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setImageFilter(imf);
>>>>>>> miniblink49
    paint.setColor(SK_ColorGREEN);
    canvas->save();
    canvas->clipRect(r);
    canvas->drawPaint(paint);
    canvas->restore();
}

<<<<<<< HEAD
static void draw_line(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    paint.setImageFilter(imf);
    paint.setStrokeWidth(r.width() / 10);
    canvas->drawLine(r.fLeft, r.fTop, r.fRight, r.fBottom, paint);
}

static void draw_rect(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
=======
static void draw_line(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    paint.setImageFilter(imf);
    paint.setStrokeWidth(r.width()/10);
    canvas->drawLine(r.fLeft, r.fTop, r.fRight, r.fBottom, paint);
}

static void draw_rect(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setColor(SK_ColorYELLOW);
    paint.setImageFilter(imf);
    SkRect rr(r);
<<<<<<< HEAD
    rr.inset(r.width() / 10, r.height() / 10);
    canvas->drawRect(rr, paint);
}

static void draw_path(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
=======
    rr.inset(r.width()/10, r.height()/10);
    canvas->drawRect(rr, paint);
}

static void draw_path(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setColor(SK_ColorMAGENTA);
    paint.setImageFilter(imf);
    paint.setAntiAlias(true);
<<<<<<< HEAD
    canvas->drawCircle(r.centerX(), r.centerY(), r.width() * 2 / 5, paint);
}

static void draw_text(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
=======
    canvas->drawCircle(r.centerX(), r.centerY(), r.width()*2/5, paint);
}

static void draw_text(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setImageFilter(imf);
    paint.setColor(SK_ColorCYAN);
    paint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface(&paint);
<<<<<<< HEAD
    paint.setTextSize(r.height() / 2);
=======
    paint.setTextSize(r.height()/2);
>>>>>>> miniblink49
    paint.setTextAlign(SkPaint::kCenter_Align);
    canvas->drawText("Text", 4, r.centerX(), r.centerY(), paint);
}

<<<<<<< HEAD
static void draw_bitmap(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setImageFilter(std::move(imf));
=======
static void draw_bitmap(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setImageFilter(imf);
>>>>>>> miniblink49

    SkIRect bounds;
    r.roundOut(&bounds);

    SkBitmap bm;
    bm.allocN32Pixels(bounds.width(), bounds.height());
    bm.eraseColor(SK_ColorTRANSPARENT);
    SkCanvas c(bm);
<<<<<<< HEAD
    draw_path(&c, r, nullptr);
=======
    draw_path(&c, r, NULL);
>>>>>>> miniblink49

    canvas->drawBitmap(bm, 0, 0, &paint);
}

<<<<<<< HEAD
=======
static void draw_sprite(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setImageFilter(imf);

    SkIRect bounds;
    r.roundOut(&bounds);

    SkBitmap bm;
    bm.allocN32Pixels(bounds.width(), bounds.height());
    bm.eraseColor(SK_ColorTRANSPARENT);
    SkCanvas c(bm);
    draw_path(&c, r, NULL);

    SkPoint loc = { r.fLeft, r.fTop };
    canvas->getTotalMatrix().mapPoints(&loc, 1);
    canvas->drawSprite(bm,
                       SkScalarRoundToInt(loc.fX), SkScalarRoundToInt(loc.fY),
                       &paint);
}

>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

class ImageFiltersBaseGM : public skiagm::GM {
public:
<<<<<<< HEAD
    ImageFiltersBaseGM() { }

protected:
    SkString onShortName() override
    {
=======
    ImageFiltersBaseGM () {}

protected:
    SkString onShortName() override {
>>>>>>> miniblink49
        return SkString("imagefiltersbase");
    }

    SkISize onISize() override { return SkISize::Make(700, 500); }

<<<<<<< HEAD
    void draw_frame(SkCanvas* canvas, const SkRect& r)
    {
=======
    void draw_frame(SkCanvas* canvas, const SkRect& r) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setColor(SK_ColorRED);
        canvas->drawRect(r, paint);
    }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
        void (*drawProc[])(SkCanvas*, const SkRect&, sk_sp<SkImageFilter>) = {
            draw_paint,
            draw_line,
            draw_rect,
            draw_path,
            draw_text,
            draw_bitmap,
        };

        auto cf = SkColorFilter::MakeModeFilter(SK_ColorRED, SkXfermode::kSrcIn_Mode);
        sk_sp<SkImageFilter> filters[] = {
            nullptr,
            IdentityImageFilter::Make(nullptr),
            FailImageFilter::Make(),
            SkColorFilterImageFilter::Make(std::move(cf), nullptr),
            SkBlurImageFilter::Make(12.0f, 0.0f, nullptr),
            SkDropShadowImageFilter::Make(
                10.0f, 5.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
                nullptr),
        };
=======
    void onDraw(SkCanvas* canvas) override {
        void (*drawProc[])(SkCanvas*, const SkRect&, SkImageFilter*) = {
            draw_paint,
            draw_line, draw_rect, draw_path, draw_text,
            draw_bitmap,
            draw_sprite
        };

        SkColorFilter* cf = SkColorFilter::CreateModeFilter(SK_ColorRED,
                                                     SkXfermode::kSrcIn_Mode);
        SkImageFilter* filters[] = {
            NULL,
            IdentityImageFilter::Create(),
            FailImageFilter::Create(),
            SkColorFilterImageFilter::Create(cf),
            SkBlurImageFilter::Create(12.0f, 0.0f),
            SkDropShadowImageFilter::Create(10.0f, 5.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode),
        };
        cf->unref();
>>>>>>> miniblink49

        SkRect r = SkRect::MakeWH(SkIntToScalar(64), SkIntToScalar(64));
        SkScalar MARGIN = SkIntToScalar(16);
        SkScalar DX = r.width() + MARGIN;
        SkScalar DY = r.height() + MARGIN;

        canvas->translate(MARGIN, MARGIN);
        for (size_t i = 0; i < SK_ARRAY_COUNT(drawProc); ++i) {
            canvas->save();
            for (size_t j = 0; j < SK_ARRAY_COUNT(filters); ++j) {
                drawProc[i](canvas, r, filters[j]);

                draw_frame(canvas, r);
                canvas->translate(0, DY);
            }
            canvas->restore();
            canvas->translate(DX, 0);
        }
<<<<<<< HEAD
=======

        for(size_t j = 0; j < SK_ARRAY_COUNT(filters); ++j) {
            SkSafeUnref(filters[j]);
        }
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new ImageFiltersBaseGM;)
=======
DEF_GM( return new ImageFiltersBaseGM; )
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

/*
 *  Want to test combos of filter and LCD text, to be sure we disable LCD in the presence of
 *  a filter.
 */
class ImageFiltersTextBaseGM : public skiagm::GM {
    SkString fSuffix;
<<<<<<< HEAD

public:
    ImageFiltersTextBaseGM(const char suffix[])
        : fSuffix(suffix)
    {
    }

protected:
    SkString onShortName() override
    {
=======
public:
    ImageFiltersTextBaseGM(const char suffix[]) : fSuffix(suffix) {}

protected:
    SkString onShortName() override {
>>>>>>> miniblink49
        SkString name;
        name.printf("%s_%s", "textfilter", fSuffix.c_str());
        return name;
    }

    SkISize onISize() override { return SkISize::Make(512, 342); }

<<<<<<< HEAD
    void drawWaterfall(SkCanvas* canvas, const SkPaint& origPaint)
    {
=======
    void drawWaterfall(SkCanvas* canvas, const SkPaint& origPaint) {
>>>>>>> miniblink49
        const uint32_t flags[] = {
            0,
            SkPaint::kAntiAlias_Flag,
            SkPaint::kAntiAlias_Flag | SkPaint::kLCDRenderText_Flag,
        };
        SkPaint paint(origPaint);
<<<<<<< HEAD
        sk_tool_utils::set_portable_typeface(&paint);
=======
>>>>>>> miniblink49
        paint.setTextSize(30);

        SkAutoCanvasRestore acr(canvas, true);
        for (size_t i = 0; i < SK_ARRAY_COUNT(flags); ++i) {
            paint.setFlags(flags[i]);
            canvas->drawText("Hamburgefons", 11, 0, 0, paint);
            canvas->translate(0, 40);
        }
    }

    virtual void installFilter(SkPaint* paint) = 0;

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;

        canvas->translate(20, 40);

        for (int doSaveLayer = 0; doSaveLayer <= 1; ++doSaveLayer) {
            SkAutoCanvasRestore acr(canvas, true);
            for (int useFilter = 0; useFilter <= 1; ++useFilter) {
                SkAutoCanvasRestore acr2(canvas, true);

                SkPaint paint;
                if (useFilter) {
                    this->installFilter(&paint);
                }
                if (doSaveLayer) {
<<<<<<< HEAD
                    canvas->saveLayer(nullptr, &paint);
                    paint.setImageFilter(nullptr);
=======
                    canvas->saveLayer(NULL, &paint);
                    paint.setImageFilter(NULL);
>>>>>>> miniblink49
                }
                this->drawWaterfall(canvas, paint);

                acr2.restore();
                canvas->translate(250, 0);
            }
            acr.restore();
            canvas->translate(0, 200);
        }
    }
<<<<<<< HEAD

=======
    
>>>>>>> miniblink49
private:
    typedef GM INHERITED;
};

class ImageFiltersText_IF : public ImageFiltersTextBaseGM {
public:
<<<<<<< HEAD
    ImageFiltersText_IF()
        : ImageFiltersTextBaseGM("image")
    {
    }

    void installFilter(SkPaint* paint) override
    {
        paint->setImageFilter(SkBlurImageFilter::Make(1.5f, 1.5f, nullptr));
    }
};
DEF_GM(return new ImageFiltersText_IF;)

class ImageFiltersText_CF : public ImageFiltersTextBaseGM {
public:
    ImageFiltersText_CF()
        : ImageFiltersTextBaseGM("color")
    {
    }

    void installFilter(SkPaint* paint) override
    {
        paint->setColorFilter(SkColorFilter::MakeModeFilter(SK_ColorBLUE, SkXfermode::kSrcIn_Mode));
    }
};
DEF_GM(return new ImageFiltersText_CF;)
=======
    ImageFiltersText_IF() : ImageFiltersTextBaseGM("image") {}

    void installFilter(SkPaint* paint) override {
        paint->setImageFilter(SkBlurImageFilter::Create(1.5f, 1.5f))->unref();
    }
};
DEF_GM( return new ImageFiltersText_IF; )

class ImageFiltersText_CF : public ImageFiltersTextBaseGM {
public:
    ImageFiltersText_CF() : ImageFiltersTextBaseGM("color") {}

    void installFilter(SkPaint* paint) override {
        paint->setColorFilter(SkColorFilter::CreateModeFilter(SK_ColorBLUE, SkXfermode::kSrcIn_Mode))->unref();
    }
};
DEF_GM( return new ImageFiltersText_CF; )

>>>>>>> miniblink49
