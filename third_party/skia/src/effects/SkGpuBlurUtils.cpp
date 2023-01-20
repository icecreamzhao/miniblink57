/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkGpuBlurUtils.h"

#include "SkRect.h"

#if SK_SUPPORT_GPU
<<<<<<< HEAD
#include "GrCaps.h"
#include "GrContext.h"
#include "GrDrawContext.h"
#include "effects/GrConvolutionEffect.h"
#include "effects/GrMatrixConvolutionEffect.h"

#define MAX_BLUR_SIGMA 4.0f

static void scale_irect_roundout(SkIRect* rect, float xScale, float yScale)
{
    rect->fLeft = SkScalarFloorToInt(SkScalarMul(rect->fLeft, xScale));
    rect->fTop = SkScalarFloorToInt(SkScalarMul(rect->fTop, yScale));
    rect->fRight = SkScalarCeilToInt(SkScalarMul(rect->fRight, xScale));
    rect->fBottom = SkScalarCeilToInt(SkScalarMul(rect->fBottom, yScale));
}

static void scale_irect(SkIRect* rect, int xScale, int yScale)
{
    rect->fLeft *= xScale;
    rect->fTop *= yScale;
    rect->fRight *= xScale;
    rect->fBottom *= yScale;
}

#ifdef SK_DEBUG
static inline int is_even(int x)
{
    return !(x & 1);
}
#endif

static void shrink_irect_by_2(SkIRect* rect, bool xAxis, bool yAxis)
{
    if (xAxis) {
        SkASSERT(is_even(rect->fLeft) && is_even(rect->fRight));
        rect->fLeft /= 2;
        rect->fRight /= 2;
    }
    if (yAxis) {
        SkASSERT(is_even(rect->fTop) && is_even(rect->fBottom));
        rect->fTop /= 2;
        rect->fBottom /= 2;
    }
}

static float adjust_sigma(float sigma, int maxTextureSize, int* scaleFactor, int* radius)
{
=======
#include "effects/GrConvolutionEffect.h"
#include "effects/GrMatrixConvolutionEffect.h"
#include "GrContext.h"
#include "GrCaps.h"
#include "GrDrawContext.h"
#endif

namespace SkGpuBlurUtils {

#if SK_SUPPORT_GPU

#define MAX_BLUR_SIGMA 4.0f

static void scale_rect(SkRect* rect, float xScale, float yScale) {
    rect->fLeft   = SkScalarMul(rect->fLeft,   xScale);
    rect->fTop    = SkScalarMul(rect->fTop,    yScale);
    rect->fRight  = SkScalarMul(rect->fRight,  xScale);
    rect->fBottom = SkScalarMul(rect->fBottom, yScale);
}

static float adjust_sigma(float sigma, int maxTextureSize, int *scaleFactor, int *radius) {
>>>>>>> miniblink49
    *scaleFactor = 1;
    while (sigma > MAX_BLUR_SIGMA) {
        *scaleFactor *= 2;
        sigma *= 0.5f;
        if (*scaleFactor > maxTextureSize) {
            *scaleFactor = maxTextureSize;
            sigma = MAX_BLUR_SIGMA;
        }
    }
    *radius = static_cast<int>(ceilf(sigma * 3.0f));
    SkASSERT(*radius <= GrConvolutionEffect::kMaxKernelRadius);
    return sigma;
}

static void convolve_gaussian_1d(GrDrawContext* drawContext,
<<<<<<< HEAD
    const GrClip& clip,
    const SkIRect& dstRect,
    const SkIPoint& srcOffset,
    GrTexture* texture,
    Gr1DKernelEffect::Direction direction,
    int radius,
    float sigma,
    bool useBounds,
    float bounds[2])
{
    GrPaint paint;
    paint.setGammaCorrect(drawContext->isGammaCorrect());
    sk_sp<GrFragmentProcessor> conv(GrConvolutionEffect::MakeGaussian(
        texture, direction, radius, sigma, useBounds, bounds));
    paint.addColorFragmentProcessor(std::move(conv));
    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
    SkMatrix localMatrix = SkMatrix::MakeTrans(-SkIntToScalar(srcOffset.x()),
        -SkIntToScalar(srcOffset.y()));
    drawContext->fillRectWithLocalMatrix(clip, paint, SkMatrix::I(),
        SkRect::Make(dstRect), localMatrix);
}

static void convolve_gaussian_2d(GrDrawContext* drawContext,
    const GrClip& clip,
    const SkIRect& dstRect,
    const SkIPoint& srcOffset,
    GrTexture* texture,
    int radiusX,
    int radiusY,
    SkScalar sigmaX,
    SkScalar sigmaY,
    const SkIRect* srcBounds)
{
    SkMatrix localMatrix = SkMatrix::MakeTrans(-SkIntToScalar(srcOffset.x()),
        -SkIntToScalar(srcOffset.y()));
    SkISize size = SkISize::Make(2 * radiusX + 1, 2 * radiusY + 1);
    SkIPoint kernelOffset = SkIPoint::Make(radiusX, radiusY);
    GrPaint paint;
    paint.setGammaCorrect(drawContext->isGammaCorrect());
    SkIRect bounds = srcBounds ? *srcBounds : SkIRect::EmptyIRect();

    sk_sp<GrFragmentProcessor> conv(GrMatrixConvolutionEffect::MakeGaussian(
        texture, bounds, size, 1.0, 0.0, kernelOffset,
        srcBounds ? GrTextureDomain::kDecal_Mode : GrTextureDomain::kIgnore_Mode,
        true, sigmaX, sigmaY));
    paint.addColorFragmentProcessor(std::move(conv));
    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
    drawContext->fillRectWithLocalMatrix(clip, paint, SkMatrix::I(),
        SkRect::Make(dstRect), localMatrix);
}

static void convolve_gaussian(GrDrawContext* drawContext,
    const GrClip& clip,
    const SkIRect& srcRect,
    GrTexture* texture,
    Gr1DKernelEffect::Direction direction,
    int radius,
    float sigma,
    const SkIRect* srcBounds,
    const SkIPoint& srcOffset)
{
    float bounds[2] = { 0.0f, 1.0f };
    SkIRect dstRect = SkIRect::MakeWH(srcRect.width(), srcRect.height());
    if (!srcBounds) {
        convolve_gaussian_1d(drawContext, clip, dstRect, srcOffset, texture,
            direction, radius, sigma, false, bounds);
        return;
    }
    SkIRect midRect = *srcBounds, leftRect, rightRect;
    midRect.offset(srcOffset);
    SkIRect topRect, bottomRect;
    if (direction == Gr1DKernelEffect::kX_Direction) {
        bounds[0] = SkIntToFloat(srcBounds->left()) / texture->width();
        bounds[1] = SkIntToFloat(srcBounds->right()) / texture->width();
        topRect = SkIRect::MakeLTRB(0, 0, dstRect.right(), midRect.top());
        bottomRect = SkIRect::MakeLTRB(0, midRect.bottom(), dstRect.right(), dstRect.bottom());
        midRect.inset(radius, 0);
        leftRect = SkIRect::MakeLTRB(0, midRect.top(), midRect.left(), midRect.bottom());
        rightRect = SkIRect::MakeLTRB(midRect.right(), midRect.top(), dstRect.width(), midRect.bottom());
        dstRect.fTop = midRect.top();
        dstRect.fBottom = midRect.bottom();
    } else {
        bounds[0] = SkIntToFloat(srcBounds->top()) / texture->height();
        bounds[1] = SkIntToFloat(srcBounds->bottom()) / texture->height();
        topRect = SkIRect::MakeLTRB(0, 0, midRect.left(), dstRect.bottom());
        bottomRect = SkIRect::MakeLTRB(midRect.right(), 0, dstRect.right(), dstRect.bottom());
        midRect.inset(0, radius);
        leftRect = SkIRect::MakeLTRB(midRect.left(), 0, midRect.right(), midRect.top());
        rightRect = SkIRect::MakeLTRB(midRect.left(), midRect.bottom(), midRect.right(), dstRect.height());
        dstRect.fLeft = midRect.left();
        dstRect.fRight = midRect.right();
    }
    if (!topRect.isEmpty()) {
        drawContext->clear(&topRect, 0, false);
    }

    if (!bottomRect.isEmpty()) {
        drawContext->clear(&bottomRect, 0, false);
    }
    if (midRect.isEmpty()) {
        // Blur radius covers srcBounds; use bounds over entire draw
        convolve_gaussian_1d(drawContext, clip, dstRect, srcOffset, texture,
            direction, radius, sigma, true, bounds);
    } else {
        // Draw right and left margins with bounds; middle without.
        convolve_gaussian_1d(drawContext, clip, leftRect, srcOffset, texture,
            direction, radius, sigma, true, bounds);
        convolve_gaussian_1d(drawContext, clip, rightRect, srcOffset, texture,
            direction, radius, sigma, true, bounds);
        convolve_gaussian_1d(drawContext, clip, midRect, srcOffset, texture,
            direction, radius, sigma, false, bounds);
    }
}

namespace SkGpuBlurUtils {

sk_sp<GrDrawContext> GaussianBlur(GrContext* context,
    GrTexture* origSrc,
    bool gammaCorrect,
    const SkIRect& dstBounds,
    const SkIRect* srcBounds,
    float sigmaX,
    float sigmaY)
{
    SkASSERT(context);
=======
                                 GrRenderTarget* rt,
                                 const GrClip& clip,
                                 const SkRect& srcRect,
                                 const SkRect& dstRect,
                                 GrTexture* texture,
                                 Gr1DKernelEffect::Direction direction,
                                 int radius,
                                 float sigma,
                                 bool useBounds,
                                 float bounds[2]) {
    GrPaint paint;
    SkAutoTUnref<GrFragmentProcessor> conv(GrConvolutionEffect::CreateGaussian(
        paint.getProcessorDataManager(), texture, direction, radius, sigma, useBounds, bounds));
    paint.addColorProcessor(conv);
    drawContext->drawNonAARectToRect(rt, clip, paint, SkMatrix::I(), dstRect, srcRect);
}

static void convolve_gaussian_2d(GrDrawContext* drawContext,
                                 GrRenderTarget* rt,
                                 const GrClip& clip,
                                 const SkRect& srcRect,
                                 const SkRect& dstRect,
                                 GrTexture* texture,
                                 int radiusX,
                                 int radiusY,
                                 SkScalar sigmaX,
                                 SkScalar sigmaY,
                                 bool useBounds,
                                 SkIRect bounds) {
    SkISize size = SkISize::Make(2 * radiusX + 1,  2 * radiusY + 1);
    SkIPoint kernelOffset = SkIPoint::Make(radiusX, radiusY);
    GrPaint paint;
    SkAutoTUnref<GrFragmentProcessor> conv(GrMatrixConvolutionEffect::CreateGaussian(
            paint.getProcessorDataManager(),
            texture, bounds, size, 1.0, 0.0, kernelOffset,
            useBounds ? GrTextureDomain::kClamp_Mode : GrTextureDomain::kIgnore_Mode,
            true, sigmaX, sigmaY));
    paint.addColorProcessor(conv);
    drawContext->drawNonAARectToRect(rt, clip, paint, SkMatrix::I(), dstRect, srcRect);
}

static void convolve_gaussian(GrDrawContext* drawContext,
                              GrRenderTarget* rt,
                              const GrClip& clip,
                              const SkRect& srcRect,
                              const SkRect& dstRect,
                              GrTexture* texture,
                              Gr1DKernelEffect::Direction direction,
                              int radius,
                              float sigma,
                              bool cropToSrcRect) {
    float bounds[2] = { 0.0f, 1.0f };
    if (!cropToSrcRect) {
        convolve_gaussian_1d(drawContext, rt, clip, srcRect, dstRect, texture,
                             direction, radius, sigma, false, bounds);
        return;
    }
    SkRect lowerSrcRect = srcRect, lowerDstRect = dstRect;
    SkRect middleSrcRect = srcRect, middleDstRect = dstRect;
    SkRect upperSrcRect = srcRect, upperDstRect = dstRect;
    SkScalar size;
    SkScalar rad = SkIntToScalar(radius);
    if (direction == Gr1DKernelEffect::kX_Direction) {
        bounds[0] = SkScalarToFloat(srcRect.left()) / texture->width();
        bounds[1] = SkScalarToFloat(srcRect.right()) / texture->width();
        size = srcRect.width();
        lowerSrcRect.fRight = srcRect.left() + rad;
        lowerDstRect.fRight = dstRect.left() + rad;
        upperSrcRect.fLeft = srcRect.right() - rad;
        upperDstRect.fLeft = dstRect.right() - rad;
        middleSrcRect.inset(rad, 0);
        middleDstRect.inset(rad, 0);
    } else {
        bounds[0] = SkScalarToFloat(srcRect.top()) / texture->height();
        bounds[1] = SkScalarToFloat(srcRect.bottom()) / texture->height();
        size = srcRect.height();
        lowerSrcRect.fBottom = srcRect.top() + rad;
        lowerDstRect.fBottom = dstRect.top() + rad;
        upperSrcRect.fTop = srcRect.bottom() - rad;
        upperDstRect.fTop = dstRect.bottom() - rad;
        middleSrcRect.inset(0, rad);
        middleDstRect.inset(0, rad);
    }
    if (radius >= size * SK_ScalarHalf) {
        // Blur radius covers srcRect; use bounds over entire draw
        convolve_gaussian_1d(drawContext, rt, clip, srcRect, dstRect, texture,
                            direction, radius, sigma, true, bounds);
    } else {
        // Draw upper and lower margins with bounds; middle without.
        convolve_gaussian_1d(drawContext, rt, clip, lowerSrcRect, lowerDstRect, texture,
                             direction, radius, sigma, true, bounds);
        convolve_gaussian_1d(drawContext, rt, clip, upperSrcRect, upperDstRect, texture,
                             direction, radius, sigma, true, bounds);
        convolve_gaussian_1d(drawContext, rt, clip, middleSrcRect, middleDstRect, texture,
                             direction, radius, sigma, false, bounds);
    }
}

GrTexture* GaussianBlur(GrContext* context,
                        GrTexture* srcTexture,
                        bool canClobberSrc,
                        const SkRect& rect,
                        bool cropToRect,
                        float sigmaX,
                        float sigmaY) {
    SkASSERT(context);

>>>>>>> miniblink49
    SkIRect clearRect;
    int scaleFactorX, radiusX;
    int scaleFactorY, radiusY;
    int maxTextureSize = context->caps()->maxTextureSize();
    sigmaX = adjust_sigma(sigmaX, maxTextureSize, &scaleFactorX, &radiusX);
    sigmaY = adjust_sigma(sigmaY, maxTextureSize, &scaleFactorY, &radiusY);
<<<<<<< HEAD
    SkASSERT(sigmaX || sigmaY);

    SkIPoint srcOffset = SkIPoint::Make(-dstBounds.x(), -dstBounds.y());
    SkIRect localDstBounds = SkIRect::MakeWH(dstBounds.width(), dstBounds.height());
    SkIRect localSrcBounds;
    SkIRect srcRect;
    if (srcBounds) {
        srcRect = localSrcBounds = *srcBounds;
        srcRect.offset(srcOffset);
        srcBounds = &localSrcBounds;
    } else {
        srcRect = localDstBounds;
    }

    scale_irect_roundout(&srcRect, 1.0f / scaleFactorX, 1.0f / scaleFactorY);
    scale_irect(&srcRect, scaleFactorX, scaleFactorY);

    // setup new clip
    GrFixedClip clip(localDstBounds);

    sk_sp<GrTexture> srcTexture(sk_ref_sp(origSrc));

    SkASSERT(kBGRA_8888_GrPixelConfig == srcTexture->config() || kRGBA_8888_GrPixelConfig == srcTexture->config() || kSRGBA_8888_GrPixelConfig == srcTexture->config() || kSBGRA_8888_GrPixelConfig == srcTexture->config() || kAlpha_8_GrPixelConfig == srcTexture->config());

    const int width = dstBounds.width();
    const int height = dstBounds.height();
    const GrPixelConfig config = srcTexture->config();

    const SkSurfaceProps props(gammaCorrect ? SkSurfaceProps::kGammaCorrect_Flag : 0,
        SkSurfaceProps::kLegacyFontHost_InitType);

    sk_sp<GrDrawContext> dstDrawContext(context->newDrawContext(SkBackingFit::kApprox,
        width, height, config,
        0, kDefault_GrSurfaceOrigin,
        &props));
    if (!dstDrawContext) {
        return nullptr;
    }

    // For really small blurs (certainly no wider than 5x5 on desktop gpus) it is faster to just
    // launch a single non separable kernel vs two launches
    if (sigmaX > 0.0f && sigmaY > 0.0f && (2 * radiusX + 1) * (2 * radiusY + 1) <= MAX_KERNEL_SIZE) {
        // We shouldn't be scaling because this is a small size blur
        SkASSERT((1 == scaleFactorX) && (1 == scaleFactorY));

        convolve_gaussian_2d(dstDrawContext.get(), clip, localDstBounds, srcOffset,
            srcTexture.get(), radiusX, radiusY, sigmaX, sigmaY, srcBounds);

        return dstDrawContext;
    }

    sk_sp<GrDrawContext> tmpDrawContext(context->newDrawContext(SkBackingFit::kApprox,
        width, height, config,
        0, kDefault_GrSurfaceOrigin,
        &props));
    if (!tmpDrawContext) {
        return nullptr;
    }

    sk_sp<GrDrawContext> srcDrawContext;

    SkASSERT(SkIsPow2(scaleFactorX) && SkIsPow2(scaleFactorY));

    for (int i = 1; i < scaleFactorX || i < scaleFactorY; i *= 2) {
        GrPaint paint;
        paint.setGammaCorrect(gammaCorrect);
        SkMatrix matrix;
        matrix.setIDiv(srcTexture->width(), srcTexture->height());
        SkIRect dstRect(srcRect);
        if (srcBounds && i == 1) {
            SkRect domain;
            matrix.mapRect(&domain, SkRect::Make(*srcBounds));
            domain.inset((i < scaleFactorX) ? SK_ScalarHalf / srcTexture->width() : 0.0f,
                (i < scaleFactorY) ? SK_ScalarHalf / srcTexture->height() : 0.0f);
            sk_sp<GrFragmentProcessor> fp(GrTextureDomainEffect::Make(
                srcTexture.get(),
=======

    SkRect srcRect(rect);
    scale_rect(&srcRect, 1.0f / scaleFactorX, 1.0f / scaleFactorY);
    srcRect.roundOut(&srcRect);
    scale_rect(&srcRect, static_cast<float>(scaleFactorX),
                         static_cast<float>(scaleFactorY));

    // setup new clip
    GrClip clip(SkRect::MakeWH(srcRect.width(), srcRect.height()));

    SkASSERT(kBGRA_8888_GrPixelConfig == srcTexture->config() ||
             kRGBA_8888_GrPixelConfig == srcTexture->config() ||
             kAlpha_8_GrPixelConfig == srcTexture->config());

    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = SkScalarFloorToInt(srcRect.width());
    desc.fHeight = SkScalarFloorToInt(srcRect.height());
    desc.fConfig = srcTexture->config();

    GrTexture* dstTexture;
    GrTexture* tempTexture;
    SkAutoTUnref<GrTexture> temp1, temp2;

    temp1.reset(context->textureProvider()->refScratchTexture(
        desc, GrTextureProvider::kApprox_ScratchTexMatch));
    dstTexture = temp1.get();
    if (canClobberSrc) {
        tempTexture = srcTexture;
    } else {
        temp2.reset(context->textureProvider()->refScratchTexture(
            desc, GrTextureProvider::kApprox_ScratchTexMatch));
        tempTexture = temp2.get();
    }

    if (NULL == dstTexture || NULL == tempTexture) {
        return NULL;
    }

    GrDrawContext* drawContext = context->drawContext();
    if (!drawContext) {
        return NULL;
    }

    for (int i = 1; i < scaleFactorX || i < scaleFactorY; i *= 2) {
        GrPaint paint;
        SkMatrix matrix;
        matrix.setIDiv(srcTexture->width(), srcTexture->height());
        SkRect dstRect(srcRect);
        if (cropToRect && i == 1) {
            dstRect.offset(-dstRect.fLeft, -dstRect.fTop);
            SkRect domain;
            matrix.mapRect(&domain, rect);
            domain.inset(i < scaleFactorX ? SK_ScalarHalf / srcTexture->width() : 0.0f,
                         i < scaleFactorY ? SK_ScalarHalf / srcTexture->height() : 0.0f);
            SkAutoTUnref<GrFragmentProcessor> fp(   GrTextureDomainEffect::Create(
                paint.getProcessorDataManager(),
                srcTexture,
>>>>>>> miniblink49
                matrix,
                domain,
                GrTextureDomain::kDecal_Mode,
                GrTextureParams::kBilerp_FilterMode));
<<<<<<< HEAD
            paint.addColorFragmentProcessor(std::move(fp));
            srcRect.offset(-srcOffset);
            srcOffset.set(0, 0);
        } else {
            GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kBilerp_FilterMode);
            paint.addColorTextureProcessor(srcTexture.get(), matrix, params);
        }
        paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
        shrink_irect_by_2(&dstRect, i < scaleFactorX, i < scaleFactorY);

        dstDrawContext->fillRectToRect(clip, paint, SkMatrix::I(),
            SkRect::Make(dstRect), SkRect::Make(srcRect));

        srcDrawContext = dstDrawContext;
        srcRect = dstRect;
        srcTexture = srcDrawContext->asTexture();
        dstDrawContext.swap(tmpDrawContext);
        localSrcBounds = srcRect;
    }

    srcRect = localDstBounds;
    scale_irect_roundout(&srcRect, 1.0f / scaleFactorX, 1.0f / scaleFactorY);
    if (sigmaX > 0.0f) {
        if (scaleFactorX > 1) {
            SkASSERT(srcDrawContext);

            // Clear out a radius to the right of the srcRect to prevent the
            // X convolution from reading garbage.
            clearRect = SkIRect::MakeXYWH(srcRect.fRight, srcRect.fTop,
                radiusX, srcRect.height());
            srcDrawContext->clear(&clearRect, 0x0, false);
        }

        convolve_gaussian(dstDrawContext.get(), clip, srcRect,
            srcTexture.get(), Gr1DKernelEffect::kX_Direction, radiusX, sigmaX,
            srcBounds, srcOffset);
        srcDrawContext = dstDrawContext;
        srcTexture = srcDrawContext->asTexture();
        srcRect.offsetTo(0, 0);
        dstDrawContext.swap(tmpDrawContext);
        localSrcBounds = srcRect;
        srcOffset.set(0, 0);
    }

    if (sigmaY > 0.0f) {
        if (scaleFactorY > 1 || sigmaX > 0.0f) {
            SkASSERT(srcDrawContext);

            // Clear out a radius below the srcRect to prevent the Y
            // convolution from reading garbage.
            clearRect = SkIRect::MakeXYWH(srcRect.fLeft, srcRect.fBottom,
                srcRect.width(), radiusY);
            srcDrawContext->clear(&clearRect, 0x0, false);
        }

        convolve_gaussian(dstDrawContext.get(), clip, srcRect,
            srcTexture.get(), Gr1DKernelEffect::kY_Direction, radiusY, sigmaY,
            srcBounds, srcOffset);

        srcDrawContext = dstDrawContext;
        srcRect.offsetTo(0, 0);
        dstDrawContext.swap(tmpDrawContext);
    }

    SkASSERT(srcDrawContext);
    srcTexture = nullptr; // we don't use this from here on out

    if (scaleFactorX > 1 || scaleFactorY > 1) {
        // Clear one pixel to the right and below, to accommodate bilinear upsampling.
        clearRect = SkIRect::MakeXYWH(srcRect.fLeft, srcRect.fBottom, srcRect.width() + 1, 1);
        srcDrawContext->clear(&clearRect, 0x0, false);
        clearRect = SkIRect::MakeXYWH(srcRect.fRight, srcRect.fTop, 1, srcRect.height());
        srcDrawContext->clear(&clearRect, 0x0, false);

        SkMatrix matrix;
        matrix.setIDiv(srcDrawContext->width(), srcDrawContext->height());

        GrPaint paint;
        paint.setGammaCorrect(gammaCorrect);
        // FIXME:  this should be mitchell, not bilinear.
        GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kBilerp_FilterMode);
        sk_sp<GrTexture> tex(srcDrawContext->asTexture());
        paint.addColorTextureProcessor(tex.get(), matrix, params);
        paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);

        SkIRect dstRect(srcRect);
        scale_irect(&dstRect, scaleFactorX, scaleFactorY);

        dstDrawContext->fillRectToRect(clip, paint, SkMatrix::I(),
            SkRect::Make(dstRect), SkRect::Make(srcRect));

        srcDrawContext = dstDrawContext;
        srcRect = dstRect;
        dstDrawContext.swap(tmpDrawContext);
    }

    return srcDrawContext;
}

}

#endif
=======
            paint.addColorProcessor(fp);
        } else {
            GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kBilerp_FilterMode);
            paint.addColorTextureProcessor(srcTexture, matrix, params);
        }
        scale_rect(&dstRect, i < scaleFactorX ? 0.5f : 1.0f,
                             i < scaleFactorY ? 0.5f : 1.0f);
        drawContext->drawNonAARectToRect(dstTexture->asRenderTarget(), clip, paint, SkMatrix::I(),
                                         dstRect, srcRect);
        srcRect = dstRect;
        srcTexture = dstTexture;
        SkTSwap(dstTexture, tempTexture);
    }

    const SkIRect srcIRect = srcRect.roundOut();

    // For really small blurs(Certainly no wider than 5x5 on desktop gpus) it is faster to just
    // launch a single non separable kernel vs two launches
    if (sigmaX > 0.0f && sigmaY > 0 &&
            (2 * radiusX + 1) * (2 * radiusY + 1) <= MAX_KERNEL_SIZE) {
        // We shouldn't be scaling because this is a small size blur
        SkASSERT((scaleFactorX == scaleFactorY) == 1);
        SkRect dstRect = SkRect::MakeWH(srcRect.width(), srcRect.height());
        convolve_gaussian_2d(drawContext, dstTexture->asRenderTarget(), clip, srcRect, dstRect,
                             srcTexture, radiusX, radiusY, sigmaX, sigmaY, cropToRect, srcIRect);
        srcTexture = dstTexture;
        srcRect = dstRect;
        SkTSwap(dstTexture, tempTexture);

    } else {
        if (sigmaX > 0.0f) {
            if (scaleFactorX > 1) {
                // Clear out a radius to the right of the srcRect to prevent the
                // X convolution from reading garbage.
                clearRect = SkIRect::MakeXYWH(srcIRect.fRight, srcIRect.fTop,
                                              radiusX, srcIRect.height());
                drawContext->clear(srcTexture->asRenderTarget(), &clearRect, 0x0, false);
            }
            SkRect dstRect = SkRect::MakeWH(srcRect.width(), srcRect.height());
            convolve_gaussian(drawContext, dstTexture->asRenderTarget(), clip, srcRect, dstRect,
                              srcTexture, Gr1DKernelEffect::kX_Direction, radiusX, sigmaX,
                              cropToRect);
            srcTexture = dstTexture;
            srcRect = dstRect;
            SkTSwap(dstTexture, tempTexture);
        }

        if (sigmaY > 0.0f) {
            if (scaleFactorY > 1 || sigmaX > 0.0f) {
                // Clear out a radius below the srcRect to prevent the Y
                // convolution from reading garbage.
                clearRect = SkIRect::MakeXYWH(srcIRect.fLeft, srcIRect.fBottom,
                                              srcIRect.width(), radiusY);
                drawContext->clear(srcTexture->asRenderTarget(), &clearRect, 0x0, false);
            }

            SkRect dstRect = SkRect::MakeWH(srcRect.width(), srcRect.height());
            convolve_gaussian(drawContext, dstTexture->asRenderTarget(), clip, srcRect,
                              dstRect, srcTexture, Gr1DKernelEffect::kY_Direction, radiusY, sigmaY,
                              cropToRect);
            srcTexture = dstTexture;
            srcRect = dstRect;
            SkTSwap(dstTexture, tempTexture);
        }
    }

    if (scaleFactorX > 1 || scaleFactorY > 1) {
        // Clear one pixel to the right and below, to accommodate bilinear
        // upsampling.
        clearRect = SkIRect::MakeXYWH(srcIRect.fLeft, srcIRect.fBottom,
                                      srcIRect.width() + 1, 1);
        drawContext->clear(srcTexture->asRenderTarget(), &clearRect, 0x0, false);
        clearRect = SkIRect::MakeXYWH(srcIRect.fRight, srcIRect.fTop,
                                      1, srcIRect.height());
        drawContext->clear(srcTexture->asRenderTarget(), &clearRect, 0x0, false);
        SkMatrix matrix;
        matrix.setIDiv(srcTexture->width(), srcTexture->height());

        GrPaint paint;
        // FIXME:  this should be mitchell, not bilinear.
        GrTextureParams params(SkShader::kClamp_TileMode, GrTextureParams::kBilerp_FilterMode);
        paint.addColorTextureProcessor(srcTexture, matrix, params);

        SkRect dstRect(srcRect);
        scale_rect(&dstRect, (float) scaleFactorX, (float) scaleFactorY);
        drawContext->drawNonAARectToRect(dstTexture->asRenderTarget(), clip, paint,
                                         SkMatrix::I(), dstRect, srcRect);
        srcRect = dstRect;
        srcTexture = dstTexture;
        SkTSwap(dstTexture, tempTexture);
    }
    return SkRef(srcTexture);
}
#endif

}
>>>>>>> miniblink49
