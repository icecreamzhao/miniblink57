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
#include "Resources.h"
#include "SkCanvas.h"
#include "SkStream.h"
#include "SkSurface.h"
#include "SkTypeface.h"
<<<<<<< HEAD
#include "gm.h"

class DFTextGM : public skiagm::GM {
public:
    DFTextGM()
    {
        this->setBGColor(0xFFFFFFFF);
    }

protected:
    void onOnceBeforeDraw() override
    {
        fEmojiTypeface = sk_tool_utils::emoji_typeface();
        fEmojiText = sk_tool_utils::emoji_sample_text();
    }

    SkString onShortName() override
    {
        SkString name("dftext");
        name.append(sk_tool_utils::platform_os_emoji());
        return name;
    }

    SkISize onISize() override
    {
=======

class DFTextGM : public skiagm::GM {
public:
    DFTextGM() {
        this->setBGColor(0xFFFFFFFF);
        fTypeface = NULL;
    }

    virtual ~DFTextGM() {
        SkSafeUnref(fTypeface);
    }

protected:
    void onOnceBeforeDraw() override {
        fTypeface = GetResourceAsTypeface("/fonts/Funkster.ttf");
    }

    SkString onShortName() override {
        return SkString("dftext");
    }

    SkISize onISize() override {
>>>>>>> miniblink49
        return SkISize::Make(1024, 768);
    }

    static void rotate_about(SkCanvas* canvas,
        SkScalar degrees,
<<<<<<< HEAD
        SkScalar px, SkScalar py)
    {
=======
        SkScalar px, SkScalar py) {
>>>>>>> miniblink49
        canvas->translate(px, py);
        canvas->rotate(degrees);
        canvas->translate(-px, -py);
    }

<<<<<<< HEAD
    virtual void onDraw(SkCanvas* inputCanvas) override
    {
        SkScalar textSizes[] = { 9.0f, 9.0f * 2.0f, 9.0f * 5.0f, 9.0f * 2.0f * 5.0f };
        SkScalar scales[] = { 2.0f * 5.0f, 5.0f, 2.0f, 1.0f };
=======
    virtual void onDraw(SkCanvas* inputCanvas) override {
#ifdef SK_BUILD_FOR_ANDROID
        SkScalar textSizes[] = { 9.0f, 9.0f*2.0f, 9.0f*5.0f, 9.0f*2.0f*5.0f };
#else
        SkScalar textSizes[] = { 11.0f, 11.0f*2.0f, 11.0f*5.0f, 11.0f*2.0f*5.0f };
#endif
        SkScalar scales[] = { 2.0f*5.0f, 5.0f, 2.0f, 1.0f };
>>>>>>> miniblink49

        // set up offscreen rendering with distance field text
#if SK_SUPPORT_GPU
        GrContext* ctx = inputCanvas->getGrContext();
<<<<<<< HEAD
        SkISize size = onISize();
        SkImageInfo info = SkImageInfo::MakeN32(size.width(), size.height(), kPremul_SkAlphaType,
            sk_ref_sp(inputCanvas->imageInfo().colorSpace()));
        SkSurfaceProps canvasProps(SkSurfaceProps::kLegacyFontHost_InitType);
        uint32_t gammaCorrect = inputCanvas->getProps(&canvasProps)
            ? canvasProps.flags() & SkSurfaceProps::kGammaCorrect_Flag
            : 0;
        SkSurfaceProps props(SkSurfaceProps::kUseDeviceIndependentFonts_Flag | gammaCorrect,
            SkSurfaceProps::kLegacyFontHost_InitType);
        auto surface(SkSurface::MakeRenderTarget(ctx, SkBudgeted::kNo, info, 0, &props));
        SkCanvas* canvas = surface ? surface->getCanvas() : inputCanvas;
=======
        SkImageInfo info = SkImageInfo::MakeN32Premul(onISize());
        SkSurfaceProps props(SkSurfaceProps::kUseDistanceFieldFonts_Flag,
                             SkSurfaceProps::kLegacyFontHost_InitType);
        SkAutoTUnref<SkSurface> surface(SkSurface::NewRenderTarget(ctx, SkSurface::kNo_Budgeted,
                                                                   info, 0, &props));
        SkCanvas* canvas = surface.get() ? surface->getCanvas() : inputCanvas;
>>>>>>> miniblink49
        // init our new canvas with the old canvas's matrix
        canvas->setMatrix(inputCanvas->getTotalMatrix());
#else
        SkCanvas* canvas = inputCanvas;
#endif
        // apply global scale to test glyph positioning
        canvas->scale(1.05f, 1.05f);
        canvas->clear(0xffffffff);

        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setSubpixelText(true);

<<<<<<< HEAD
        sk_tool_utils::set_portable_typeface(&paint, "serif");
=======
        sk_tool_utils::set_portable_typeface(&paint, "Times New Roman", SkTypeface::kNormal);
>>>>>>> miniblink49

        const char* text = "Hamburgefons";
        const size_t textLen = strlen(text);

        // check scaling up
        SkScalar x = SkIntToScalar(0);
        SkScalar y = SkIntToScalar(78);
        for (size_t i = 0; i < SK_ARRAY_COUNT(textSizes); ++i) {
            SkAutoCanvasRestore acr(canvas, true);
            canvas->translate(x, y);
            canvas->scale(scales[i], scales[i]);
            paint.setTextSize(textSizes[i]);
            canvas->drawText(text, textLen, 0, 0, paint);
<<<<<<< HEAD
            y += paint.getFontMetrics(nullptr) * scales[i];
=======
            y += paint.getFontMetrics(NULL)*scales[i];
>>>>>>> miniblink49
        }

        // check rotation
        for (size_t i = 0; i < 5; ++i) {
            SkScalar rotX = SkIntToScalar(10);
            SkScalar rotY = y;

            SkAutoCanvasRestore acr(canvas, true);
            canvas->translate(SkIntToScalar(10 + i * 200), -80);
            rotate_about(canvas, SkIntToScalar(i * 5), rotX, rotY);
            for (int ps = 6; ps <= 32; ps += 3) {
                paint.setTextSize(SkIntToScalar(ps));
                canvas->drawText(text, textLen, rotX, rotY, paint);
<<<<<<< HEAD
                rotY += paint.getFontMetrics(nullptr);
=======
                rotY += paint.getFontMetrics(NULL);
>>>>>>> miniblink49
            }
        }

        // check scaling down
        paint.setLCDRenderText(true);
        x = SkIntToScalar(680);
        y = SkIntToScalar(20);
        size_t arraySize = SK_ARRAY_COUNT(textSizes);
        for (size_t i = 0; i < arraySize; ++i) {
            SkAutoCanvasRestore acr(canvas, true);
            canvas->translate(x, y);
            SkScalar scaleFactor = SkScalarInvert(scales[arraySize - i - 1]);
            canvas->scale(scaleFactor, scaleFactor);
            paint.setTextSize(textSizes[i]);
            canvas->drawText(text, textLen, 0, 0, paint);
<<<<<<< HEAD
            y += paint.getFontMetrics(nullptr) * scaleFactor;
=======
            y += paint.getFontMetrics(NULL)*scaleFactor;
>>>>>>> miniblink49
        }

        // check pos text
        {
            SkAutoCanvasRestore acr(canvas, true);

            canvas->scale(2.0f, 2.0f);

<<<<<<< HEAD
            SkAutoTArray<SkPoint> pos(SkToInt(textLen));
=======
            SkAutoTArray<SkPoint>  pos(SkToInt(textLen));
>>>>>>> miniblink49
            SkAutoTArray<SkScalar> widths(SkToInt(textLen));
            paint.setTextSize(textSizes[0]);

            paint.getTextWidths(text, textLen, &widths[0]);

            SkScalar x = SkIntToScalar(340);
            SkScalar y = SkIntToScalar(75);
            for (unsigned int i = 0; i < textLen; ++i) {
                pos[i].set(x, y);
                x += widths[i];
            }

            canvas->drawPosText(text, textLen, &pos[0], paint);
        }

<<<<<<< HEAD
        // check gamma-corrected blending
        const SkColor fg[] = {
            0xFFFFFFFF,
            0xFFFFFF00,
            0xFFFF00FF,
            0xFF00FFFF,
            0xFFFF0000,
            0xFF00FF00,
            0xFF0000FF,
            0xFF000000,
        };

        paint.setColor(0xFFF7F3F7);
        SkRect r = SkRect::MakeLTRB(670, 215, 820, 397);
        canvas->drawRect(r, paint);

        x = SkIntToScalar(680);
        y = SkIntToScalar(235);
        paint.setTextSize(SkIntToScalar(19));
=======

        // check gamma-corrected blending
        const SkColor fg[] = {
            0xFFFFFFFF,
            0xFFFFFF00, 0xFFFF00FF, 0xFF00FFFF,
            0xFFFF0000, 0xFF00FF00, 0xFF0000FF,
            0xFF000000,
        };

        paint.setColor(0xFFF1F1F1);
        SkRect r = SkRect::MakeLTRB(670, 250, 820, 460);
        canvas->drawRect(r, paint);

        x = SkIntToScalar(680);
        y = SkIntToScalar(270);
#ifdef SK_BUILD_FOR_ANDROID
        paint.setTextSize(SkIntToScalar(19));
#else
        paint.setTextSize(SkIntToScalar(22));
#endif
>>>>>>> miniblink49
        for (size_t i = 0; i < SK_ARRAY_COUNT(fg); ++i) {
            paint.setColor(fg[i]);

            canvas->drawText(text, textLen, x, y, paint);
<<<<<<< HEAD
            y += paint.getFontMetrics(nullptr);
        }

        paint.setColor(0xFF181C18);
        r = SkRect::MakeLTRB(820, 215, 970, 397);
        canvas->drawRect(r, paint);

        x = SkIntToScalar(830);
        y = SkIntToScalar(235);
        paint.setTextSize(SkIntToScalar(19));
=======
            y += paint.getFontMetrics(NULL);
        }

        paint.setColor(0xFF1F1F1F);
        r = SkRect::MakeLTRB(820, 250, 970, 460);
        canvas->drawRect(r, paint);

        x = SkIntToScalar(830);
        y = SkIntToScalar(270);
#ifdef SK_BUILD_FOR_ANDROID
        paint.setTextSize(SkIntToScalar(19));
#else
        paint.setTextSize(SkIntToScalar(22));
#endif
>>>>>>> miniblink49
        for (size_t i = 0; i < SK_ARRAY_COUNT(fg); ++i) {
            paint.setColor(fg[i]);

            canvas->drawText(text, textLen, x, y, paint);
<<<<<<< HEAD
            y += paint.getFontMetrics(nullptr);
=======
            y += paint.getFontMetrics(NULL);
>>>>>>> miniblink49
        }

        // check skew
        {
            paint.setLCDRenderText(false);
            SkAutoCanvasRestore acr(canvas, true);
            canvas->skew(0.0f, 0.151515f);
            paint.setTextSize(SkIntToScalar(32));
            canvas->drawText(text, textLen, 745, 70, paint);
        }
        {
            paint.setLCDRenderText(true);
            SkAutoCanvasRestore acr(canvas, true);
            canvas->skew(0.5f, 0.0f);
            paint.setTextSize(SkIntToScalar(32));
<<<<<<< HEAD
            canvas->drawText(text, textLen, 580, 125, paint);
        }

        // check color emoji
        if (fEmojiTypeface) {
            paint.setTypeface(fEmojiTypeface);
            paint.setTextSize(SkIntToScalar(19));
            canvas->drawText(fEmojiText, strlen(fEmojiText), 670, 90, paint);
        }
=======
            canvas->drawText(text, textLen, 580, 230, paint);
        }

        // check color emoji
        paint.setTypeface(fTypeface);
#ifdef SK_BUILD_FOR_ANDROID
        paint.setTextSize(SkIntToScalar(19));
#else
        paint.setTextSize(SkIntToScalar(22));
#endif
        canvas->drawText(text, textLen, 670, 100, paint);

>>>>>>> miniblink49
#if SK_SUPPORT_GPU
        // render offscreen buffer
        if (surface) {
            SkAutoCanvasRestore acr(inputCanvas, true);
            // since we prepended this matrix already, we blit using identity
            inputCanvas->resetMatrix();
<<<<<<< HEAD
            inputCanvas->drawImage(surface->makeImageSnapshot().get(), 0, 0, nullptr);
=======
            SkImage* image = surface->newImageSnapshot();
            inputCanvas->drawImage(image, 0, 0, NULL);
            image->unref();
>>>>>>> miniblink49
        }
#endif
    }

private:
<<<<<<< HEAD
    sk_sp<SkTypeface> fEmojiTypeface;
    const char* fEmojiText;
=======
    SkTypeface* fTypeface;
>>>>>>> miniblink49

    typedef skiagm::GM INHERITED;
};

<<<<<<< HEAD
DEF_GM(return new DFTextGM;)
=======
DEF_GM( return SkNEW(DFTextGM); )
>>>>>>> miniblink49
