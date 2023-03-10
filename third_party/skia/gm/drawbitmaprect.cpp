/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkImage.h"
#include "SkImage_Base.h"
#include "SkMathPriv.h"
#include "SkShader.h"
#include "SkSurface.h"
#include "gm.h"

#if SK_SUPPORT_GPU
#include "SkGr.h"
#endif

static SkBitmap make_chessbm(int w, int h)
{
    SkBitmap bm;
    bm.allocN32Pixels(w, h);

    for (int y = 0; y < bm.height(); y++) {
        uint32_t* p = bm.getAddr32(0, y);
        for (int x = 0; x < bm.width(); x++) {
            p[x] = ((x + y) & 1) ? SK_ColorWHITE : SK_ColorBLACK;
        }
    }
    bm.unlockPixels();
    return bm;
}

static sk_sp<SkImage> makebm(SkCanvas* origCanvas, SkBitmap* resultBM, int w, int h)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(w, h);

    auto surface(origCanvas->makeSurface(info));
    if (nullptr == surface) {
        // picture canvas will return null, so fall-back to raster
        surface = SkSurface::MakeRaster(info);
    }

    SkCanvas* canvas = surface->getCanvas();

    canvas->clear(SK_ColorTRANSPARENT);

    SkScalar wScalar = SkIntToScalar(w);
    SkScalar hScalar = SkIntToScalar(h);

    SkPoint pt = { wScalar / 2, hScalar / 2 };

    SkScalar radius = 4 * SkMaxScalar(wScalar, hScalar);

    SkColor colors[] = { SK_ColorRED, SK_ColorYELLOW,
        SK_ColorGREEN, SK_ColorMAGENTA,
        SK_ColorBLUE, SK_ColorCYAN,
        SK_ColorRED };

    SkScalar pos[] = { 0,
        SK_Scalar1 / 6,
        2 * SK_Scalar1 / 6,
        3 * SK_Scalar1 / 6,
        4 * SK_Scalar1 / 6,
        5 * SK_Scalar1 / 6,
        SK_Scalar1 };

    SkPaint paint;
    SkRect rect = SkRect::MakeWH(wScalar, hScalar);
    SkMatrix mat = SkMatrix::I();
    for (int i = 0; i < 4; ++i) {
        paint.setShader(SkGradientShader::MakeRadial(
            pt, radius,
            colors, pos,
            SK_ARRAY_COUNT(colors),
            SkShader::kRepeat_TileMode,
            0, &mat));
        canvas->drawRect(rect, paint);
        rect.inset(wScalar / 8, hScalar / 8);
        mat.postScale(SK_Scalar1 / 4, SK_Scalar1 / 4);
    }

    auto image = surface->makeImageSnapshot();

    SkBitmap tempBM;

#if SK_SUPPORT_GPU
    if (GrTexture* texture = as_IB(image)->peekTexture()) {
        GrWrapTextureInBitmap(texture, image->width(), image->height(), image->isOpaque(), &tempBM);
    } else
#endif
    {
        image->asLegacyBitmap(&tempBM, SkImage::kRO_LegacyBitmapMode);
    }

    // Let backends know we won't change this, so they don't have to deep copy it defensively.
    tempBM.setImmutable();
    *resultBM = tempBM;

    return image;
}

static void canvasproc(SkCanvas* canvas, SkImage*, const SkBitmap& bm, const SkIRect& srcR,
    const SkRect& dstR)
{
    canvas->drawBitmapRect(bm, srcR, dstR, nullptr);
}

static void imageproc(SkCanvas* canvas, SkImage* image, const SkBitmap&, const SkIRect& srcR,
    const SkRect& dstR)
{
    canvas->drawImageRect(image, srcR, dstR, nullptr);
}

typedef void DrawRectRectProc(SkCanvas*, SkImage*, const SkBitmap&, const SkIRect&, const SkRect&);

static const int gSize = 1024;
static const int gBmpSize = 2048;

class DrawBitmapRectGM : public skiagm::GM {
public:
    DrawBitmapRectGM(DrawRectRectProc proc, const char suffix[])
        : fProc(proc)
    {
        fName.set("drawbitmaprect");
        if (suffix) {
            fName.append(suffix);
        }
    }

    DrawRectRectProc* fProc;
    SkBitmap fLargeBitmap;
    sk_sp<SkImage> fImage;
    SkString fName;

protected:
    SkString onShortName() override { return fName; }

    SkISize onISize() override { return SkISize::Make(gSize, gSize); }

    void setupImage(SkCanvas* canvas)
    {
        fImage = makebm(canvas, &fLargeBitmap, gBmpSize, gBmpSize);
    }

    void onDraw(SkCanvas* canvas) override
    {
        if (!fImage) {
            this->setupImage(canvas);
        }

        SkRect dstRect = { 0, 0, SkIntToScalar(64), SkIntToScalar(64) };
        static const int kMaxSrcRectSize = 1 << (SkNextLog2(gBmpSize) + 2);

        static const int kPadX = 30;
        static const int kPadY = 40;
        SkPaint paint;
        paint.setAlpha(0x20);
        canvas->drawBitmapRect(fLargeBitmap, SkRect::MakeIWH(gSize, gSize), &paint);
        canvas->translate(SK_Scalar1 * kPadX / 2,
            SK_Scalar1 * kPadY / 2);
        SkPaint blackPaint;
        SkScalar titleHeight = SK_Scalar1 * 24;
        blackPaint.setColor(SK_ColorBLACK);
        blackPaint.setTextSize(titleHeight);
        blackPaint.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&blackPaint);
        SkString title;
        title.printf("Bitmap size: %d x %d", gBmpSize, gBmpSize);
        canvas->drawText(title.c_str(), title.size(), 0,
            titleHeight, blackPaint);

        canvas->translate(0, SK_Scalar1 * kPadY / 2 + titleHeight);
        int rowCount = 0;
        canvas->save();
        for (int w = 1; w <= kMaxSrcRectSize; w *= 4) {
            for (int h = 1; h <= kMaxSrcRectSize; h *= 4) {

                SkIRect srcRect = SkIRect::MakeXYWH((gBmpSize - w) / 2, (gBmpSize - h) / 2, w, h);
                fProc(canvas, fImage.get(), fLargeBitmap, srcRect, dstRect);

                SkString label;
                label.appendf("%d x %d", w, h);
                blackPaint.setAntiAlias(true);
                blackPaint.setStyle(SkPaint::kFill_Style);
                blackPaint.setTextSize(SK_Scalar1 * 10);
                SkScalar baseline = dstRect.height() + blackPaint.getTextSize() + SK_Scalar1 * 3;
                canvas->drawText(label.c_str(), label.size(),
                    0, baseline,
                    blackPaint);
                blackPaint.setStyle(SkPaint::kStroke_Style);
                blackPaint.setStrokeWidth(SK_Scalar1);
                blackPaint.setAntiAlias(false);
                canvas->drawRect(dstRect, blackPaint);

                canvas->translate(dstRect.width() + SK_Scalar1 * kPadX, 0);
                ++rowCount;
                if ((dstRect.width() + kPadX) * rowCount > gSize) {
                    canvas->restore();
                    canvas->translate(0, dstRect.height() + SK_Scalar1 * kPadY);
                    canvas->save();
                    rowCount = 0;
                }
            }
        }

        {
            // test the following code path:
            // SkGpuDevice::drawPath() -> SkGpuDevice::drawWithMaskFilter()
            SkIRect srcRect;
            SkPaint paint;
            SkBitmap bm;

            bm = make_chessbm(5, 5);
            paint.setFilterQuality(kLow_SkFilterQuality);

            srcRect.setXYWH(1, 1, 3, 3);
            paint.setMaskFilter(SkBlurMaskFilter::Make(
                kNormal_SkBlurStyle,
                SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(5)),
                SkBlurMaskFilter::kHighQuality_BlurFlag | SkBlurMaskFilter::kIgnoreTransform_BlurFlag));
            canvas->drawBitmapRect(bm, srcRect, dstRect, &paint);
        }
    }

private:
    typedef skiagm::GM INHERITED;
};

DEF_GM(return new DrawBitmapRectGM(canvasproc, nullptr);)
DEF_GM(return new DrawBitmapRectGM(imageproc, "-imagerect");)
