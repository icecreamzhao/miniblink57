/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkGradientShader.h"
#include "SkSurface.h"
#include "SkSurfaceProps.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkGradientShader.h"
#include "SkSurface.h"
#include "SkSurfaceProps.h"
>>>>>>> miniblink49

#define W 200
#define H 100

<<<<<<< HEAD
static sk_sp<SkShader> make_shader()
{
=======
static SkShader* make_shader() {
>>>>>>> miniblink49
    int a = 0x99;
    int b = 0xBB;
    SkPoint pts[] = { { 0, 0 }, { W, H } };
    SkColor colors[] = { SkColorSetRGB(a, a, a), SkColorSetRGB(b, b, b) };
<<<<<<< HEAD
    return SkGradientShader::MakeLinear(pts, colors, nullptr, 2, SkShader::kClamp_TileMode);
}

static sk_sp<SkSurface> make_surface(GrContext* ctx, const SkImageInfo& info, SkPixelGeometry geo,
    int disallowAA, int disallowDither, bool gammaCorrect)
{
=======
    return SkGradientShader::CreateLinear(pts, colors, NULL, 2, SkShader::kClamp_TileMode);
}

static SkSurface* make_surface(GrContext* ctx, const SkImageInfo& info, SkPixelGeometry geo,
                               int disallowAA, int disallowDither) {
>>>>>>> miniblink49
    uint32_t flags = 0;
    if (disallowAA) {
        flags |= SkSurfaceProps::kDisallowAntiAlias_Flag;
    }
    if (disallowDither) {
        flags |= SkSurfaceProps::kDisallowDither_Flag;
    }
<<<<<<< HEAD
    if (gammaCorrect) {
        flags |= SkSurfaceProps::kGammaCorrect_Flag;
    }

    SkSurfaceProps props(flags, geo);
    if (ctx) {
        return SkSurface::MakeRenderTarget(ctx, SkBudgeted::kNo, info, 0, &props);
    } else {
        return SkSurface::MakeRaster(info, &props);
    }
}

static void test_draw(SkCanvas* canvas, const char label[])
{
=======

    SkSurfaceProps props(flags, geo);
    if (ctx) {
        return SkSurface::NewRenderTarget(ctx, SkSurface::kNo_Budgeted, info, 0, &props);
    } else {
        return SkSurface::NewRaster(info, &props);
    }
}

static void test_draw(SkCanvas* canvas, const char label[]) {
>>>>>>> miniblink49
    SkPaint paint;

    paint.setAntiAlias(true);
    paint.setLCDRenderText(true);
    paint.setDither(true);

<<<<<<< HEAD
    paint.setShader(make_shader());
    canvas->drawRect(SkRect::MakeWH(W, H), paint);
    paint.setShader(nullptr);
=======
    paint.setShader(make_shader())->unref();
    canvas->drawRect(SkRect::MakeWH(W, H), paint);
    paint.setShader(NULL);
>>>>>>> miniblink49

    paint.setColor(SK_ColorWHITE);
    paint.setTextSize(32);
    paint.setTextAlign(SkPaint::kCenter_Align);
<<<<<<< HEAD
    sk_tool_utils::set_portable_typeface(&paint);
=======
>>>>>>> miniblink49
    canvas->drawText(label, strlen(label), W / 2, H * 3 / 4, paint);
}

class SurfacePropsGM : public skiagm::GM {
public:
<<<<<<< HEAD
    SurfacePropsGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("surfaceprops");
    }

    SkISize onISize() override
    {
        return SkISize::Make(W * 4, H * 5);
    }

    void onDraw(SkCanvas* canvas) override
    {
        GrContext* ctx = canvas->getGrContext();

        // must be opaque to have a hope of testing LCD text
        const SkImageInfo info = SkImageInfo::MakeN32(W, H, kOpaque_SkAlphaType,
            sk_ref_sp(canvas->imageInfo().colorSpace()));
        SkSurfaceProps canvasProps(SkSurfaceProps::kLegacyFontHost_InitType);
        bool gammaCorrect = canvas->getProps(&canvasProps) && canvasProps.isGammaCorrect();

        const struct {
            SkPixelGeometry fGeo;
            const char* fLabel;
        } recs[] = {
            { kUnknown_SkPixelGeometry, "Unknown" },
            { kRGB_H_SkPixelGeometry, "RGB_H" },
            { kBGR_H_SkPixelGeometry, "BGR_H" },
            { kRGB_V_SkPixelGeometry, "RGB_V" },
            { kBGR_V_SkPixelGeometry, "BGR_V" },
        };

=======
    SurfacePropsGM() {}

protected:
    SkString onShortName() override {
        return SkString("surfaceprops");
    }

    SkISize onISize() override {
        return SkISize::Make(W * 4, H * 5);
    }

    void onDraw(SkCanvas* canvas) override {
        GrContext* ctx = canvas->getGrContext();

        // must be opaque to have a hope of testing LCD text
        const SkImageInfo info = SkImageInfo::MakeN32(W, H, kOpaque_SkAlphaType);

        const struct {
            SkPixelGeometry fGeo;
            const char*     fLabel;
        } rec[] = {
            { kUnknown_SkPixelGeometry, "Unknown" },
            { kRGB_H_SkPixelGeometry,   "RGB_H" },
            { kBGR_H_SkPixelGeometry,   "BGR_H" },
            { kRGB_V_SkPixelGeometry,   "RGB_V" },
            { kBGR_V_SkPixelGeometry,   "BGR_V" },
        };
    
>>>>>>> miniblink49
        SkScalar x = 0;
        for (int disallowAA = 0; disallowAA <= 1; ++disallowAA) {
            for (int disallowDither = 0; disallowDither <= 1; ++disallowDither) {
                SkScalar y = 0;
<<<<<<< HEAD
                for (const auto& rec : recs) {
                    auto surface(make_surface(ctx, info, rec.fGeo, disallowAA, disallowDither,
                        gammaCorrect));
                    if (!surface) {
                        SkDebugf("failed to create surface! label: %s AA: %s dither: %s\n",
                            rec.fLabel, (disallowAA == 1 ? "disallowed" : "allowed"),
                            (disallowDither == 1 ? "disallowed" : "allowed"));
                        continue;
                    }
                    test_draw(surface->getCanvas(), rec.fLabel);
                    surface->draw(canvas, x, y, nullptr);
=======
                for (size_t i = 0; i < SK_ARRAY_COUNT(rec); ++i) {
                    SkAutoTUnref<SkSurface> surface(make_surface(ctx, info, rec[i].fGeo,
                                                                 disallowAA, disallowDither));
                    test_draw(surface->getCanvas(), rec[i].fLabel);
                    surface->draw(canvas, x, y, NULL);
>>>>>>> miniblink49
                    y += H;
                }
                x += W;
            }
        }
    }

private:
    typedef GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new SurfacePropsGM)

#ifdef SK_DEBUG
static bool equal(const SkSurfaceProps& a, const SkSurfaceProps& b)
{
=======
DEF_GM( return new SurfacePropsGM )

#ifdef SK_DEBUG
static bool equal(const SkSurfaceProps& a, const SkSurfaceProps& b) {
>>>>>>> miniblink49
    return a.flags() == b.flags() && a.pixelGeometry() == b.pixelGeometry();
}
#endif

class NewSurfaceGM : public skiagm::GM {
public:
<<<<<<< HEAD
    NewSurfaceGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("surfacenew");
    }

    SkISize onISize() override
    {
        return SkISize::Make(300, 140);
    }

    static void drawInto(SkCanvas* canvas)
    {
        canvas->drawColor(SK_ColorRED);
    }

    void onDraw(SkCanvas* canvas) override
    {
        SkImageInfo info = SkImageInfo::MakeN32Premul(100, 100);

        auto surf(canvas->makeSurface(info, nullptr));
        if (!surf) {
            surf = SkSurface::MakeRaster(info);
        }
        drawInto(surf->getCanvas());

        sk_sp<SkImage> image(surf->makeImageSnapshot());
        canvas->drawImage(image, 10, 10, nullptr);

        auto surf2(surf->makeSurface(info));
=======
    NewSurfaceGM() {}

protected:
    SkString onShortName() override {
        return SkString("surfacenew");
    }

    SkISize onISize() override {
        return SkISize::Make(300, 140);
    }

    static void drawInto(SkCanvas* canvas) {
        canvas->drawColor(SK_ColorRED);
    }

    void onDraw(SkCanvas* canvas) override {
        SkImageInfo info = SkImageInfo::MakeN32Premul(100, 100);

        SkAutoTUnref<SkSurface> surf(canvas->newSurface(info, NULL));
        if (!surf.get()) {
            surf.reset(SkSurface::NewRaster(info));
        }
        drawInto(surf->getCanvas());

        SkAutoTUnref<SkImage> image(surf->newImageSnapshot());
        canvas->drawImage(image, 10, 10, NULL);

        SkAutoTUnref<SkSurface> surf2(image->newSurface(info, NULL));
>>>>>>> miniblink49
        drawInto(surf2->getCanvas());

        // Assert that the props were communicated transitively through the first image
        SkASSERT(equal(surf->props(), surf2->props()));

<<<<<<< HEAD
        sk_sp<SkImage> image2(surf2->makeImageSnapshot());
        canvas->drawImage(image2.get(), 10 + SkIntToScalar(image->width()) + 10, 10, nullptr);
=======
        SkAutoTUnref<SkImage> image2(surf2->newImageSnapshot());
        canvas->drawImage(image2, 10 + SkIntToScalar(image->width()) + 10, 10, NULL);
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new NewSurfaceGM)
=======
DEF_GM( return new NewSurfaceGM )

>>>>>>> miniblink49
