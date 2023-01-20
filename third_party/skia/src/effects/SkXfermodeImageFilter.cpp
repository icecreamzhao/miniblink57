/*
 * Copyright 2013 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkXfermodeImageFilter.h"
<<<<<<< HEAD

#include "SkCanvas.h"
#include "SkColorPriv.h"
#include "SkReadBuffer.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
=======
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkColorPriv.h"
#include "SkReadBuffer.h"
>>>>>>> miniblink49
#include "SkWriteBuffer.h"
#include "SkXfermode.h"
#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrDrawContext.h"
<<<<<<< HEAD
#include "SkGr.h"
#include "effects/GrConstColorProcessor.h"
#include "effects/GrSimpleTextureEffect.h"
#include "effects/GrTextureDomain.h"
=======
#include "effects/GrTextureDomain.h"
#include "SkGr.h"
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkImageFilter> SkXfermodeImageFilter::Make(sk_sp<SkXfermode> mode,
    sk_sp<SkImageFilter> background,
    sk_sp<SkImageFilter> foreground,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilter> inputs[2] = { std::move(background), std::move(foreground) };
    return sk_sp<SkImageFilter>(new SkXfermodeImageFilter(mode, inputs, cropRect));
}

sk_sp<SkImageFilter> SkXfermodeImageFilter::Make(SkBlendMode mode, sk_sp<SkImageFilter> background,
    sk_sp<SkImageFilter> foreground, const CropRect* cropRect)
{
    return Make(SkXfermode::Make(SkXfermode::SkBlendModeToSkXfermodeMode(mode)), std::move(background), std::move(foreground), cropRect);
}

SkXfermodeImageFilter::SkXfermodeImageFilter(sk_sp<SkXfermode> mode,
    sk_sp<SkImageFilter> inputs[2],
    const CropRect* cropRect)
    : INHERITED(inputs, 2, cropRect)
    , fMode(std::move(mode))
{
}

sk_sp<SkFlattenable> SkXfermodeImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 2);
    sk_sp<SkXfermode> mode(buffer.readXfermode());
    return Make(std::move(mode), common.getInput(0), common.getInput(1), &common.cropRect());
}

void SkXfermodeImageFilter::flatten(SkWriteBuffer& buffer) const
{
    this->INHERITED::flatten(buffer);
    buffer.writeFlattenable(fMode.get());
}

sk_sp<SkSpecialImage> SkXfermodeImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint backgroundOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> background(this->filterInput(0, source, ctx, &backgroundOffset));

    SkIPoint foregroundOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> foreground(this->filterInput(1, source, ctx, &foregroundOffset));

    SkIRect foregroundBounds = SkIRect::EmptyIRect();
    if (foreground) {
        foregroundBounds = SkIRect::MakeXYWH(foregroundOffset.x(), foregroundOffset.y(),
            foreground->width(), foreground->height());
    }

    SkIRect srcBounds = SkIRect::EmptyIRect();
    if (background) {
        srcBounds = SkIRect::MakeXYWH(backgroundOffset.x(), backgroundOffset.y(),
            background->width(), background->height());
    }

    srcBounds.join(foregroundBounds);
    if (srcBounds.isEmpty()) {
        return nullptr;
    }

    SkIRect bounds;
    if (!this->applyCropRect(ctx, srcBounds, &bounds)) {
        return nullptr;
    }

    offset->fX = bounds.left();
    offset->fY = bounds.top();

#if SK_SUPPORT_GPU
    if (source->isTextureBacked()) {
        return this->filterImageGPU(source,
            background, backgroundOffset,
            foreground, foregroundOffset,
            bounds);
    }
#endif

    const SkImageInfo info = SkImageInfo::MakeN32(bounds.width(), bounds.height(),
        kPremul_SkAlphaType);
    sk_sp<SkSpecialSurface> surf(source->makeSurface(info));
    if (!surf) {
        return nullptr;
    }

    SkCanvas* canvas = surf->getCanvas();
    SkASSERT(canvas);

    canvas->clear(0x0); // can't count on background to fully clear the background

    canvas->translate(SkIntToScalar(-bounds.left()), SkIntToScalar(-bounds.top()));

    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);

    if (background) {
        background->draw(canvas,
            SkIntToScalar(backgroundOffset.fX), SkIntToScalar(backgroundOffset.fY),
            &paint);
    }

    paint.setXfermode(fMode);

    if (foreground) {
        foreground->draw(canvas,
            SkIntToScalar(foregroundOffset.fX), SkIntToScalar(foregroundOffset.fY),
            &paint);
    }

    canvas->clipRect(SkRect::Make(foregroundBounds), SkRegion::kDifference_Op);
    paint.setColor(SK_ColorTRANSPARENT);
    canvas->drawPaint(paint);

    return surf->makeImageSnapshot();
}

#ifndef SK_IGNORE_TO_STRING
void SkXfermodeImageFilter::toString(SkString* str) const
{
=======
SkXfermodeImageFilter::SkXfermodeImageFilter(SkXfermode* mode,
                                             SkImageFilter* inputs[2],
                                             const CropRect* cropRect)
  : INHERITED(2, inputs, cropRect), fMode(mode) {
    SkSafeRef(fMode);
}

SkXfermodeImageFilter::~SkXfermodeImageFilter() {
    SkSafeUnref(fMode);
}

SkFlattenable* SkXfermodeImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 2);
    SkAutoTUnref<SkXfermode> mode(buffer.readXfermode());
    return Create(mode, common.getInput(0), common.getInput(1), &common.cropRect());
}

void SkXfermodeImageFilter::flatten(SkWriteBuffer& buffer) const {
    this->INHERITED::flatten(buffer);
    buffer.writeFlattenable(fMode);
}

bool SkXfermodeImageFilter::onFilterImage(Proxy* proxy,
                                            const SkBitmap& src,
                                            const Context& ctx,
                                            SkBitmap* dst,
                                            SkIPoint* offset) const {
    SkBitmap background = src, foreground = src;
    SkImageFilter* backgroundInput = getInput(0);
    SkImageFilter* foregroundInput = getInput(1);
    SkIPoint backgroundOffset = SkIPoint::Make(0, 0);
    if (backgroundInput &&
        !backgroundInput->filterImage(proxy, src, ctx, &background, &backgroundOffset)) {
        background.reset();
    }
    SkIPoint foregroundOffset = SkIPoint::Make(0, 0);
    if (foregroundInput &&
        !foregroundInput->filterImage(proxy, src, ctx, &foreground, &foregroundOffset)) {
        foreground.reset();
    }

    SkIRect bounds, foregroundBounds;
    if (!applyCropRect(ctx, foreground, foregroundOffset, &foregroundBounds)) {
        foregroundBounds.setEmpty();
        foreground.reset();
    }
    if (!applyCropRect(ctx, background, backgroundOffset, &bounds)) {
        bounds.setEmpty();
        background.reset();
    }
    bounds.join(foregroundBounds);
    if (bounds.isEmpty()) {
        return false;
    }

    SkAutoTUnref<SkBaseDevice> device(proxy->createDevice(bounds.width(), bounds.height()));
    if (NULL == device.get()) {
        return false;
    }
    SkCanvas canvas(device);
    canvas.translate(SkIntToScalar(-bounds.left()), SkIntToScalar(-bounds.top()));
    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    canvas.drawBitmap(background, SkIntToScalar(backgroundOffset.fX),
                      SkIntToScalar(backgroundOffset.fY), &paint);
    paint.setXfermode(fMode);
    canvas.drawBitmap(foreground, SkIntToScalar(foregroundOffset.fX),
                      SkIntToScalar(foregroundOffset.fY), &paint);
    canvas.clipRect(SkRect::Make(foregroundBounds), SkRegion::kDifference_Op);
    paint.setColor(SK_ColorTRANSPARENT);
    canvas.drawPaint(paint);
    *dst = device->accessBitmap(false);
    offset->fX = bounds.left();
    offset->fY = bounds.top();
    return true;
}

#ifndef SK_IGNORE_TO_STRING
void SkXfermodeImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkXfermodeImageFilter: (");
    str->appendf("xfermode: (");
    if (fMode) {
        fMode->toString(str);
    }
    str->append(")");
    if (this->getInput(0)) {
        str->appendf("foreground: (");
        this->getInput(0)->toString(str);
        str->appendf(")");
    }
    if (this->getInput(1)) {
        str->appendf("background: (");
        this->getInput(1)->toString(str);
        str->appendf(")");
    }
    str->append(")");
}
#endif

#if SK_SUPPORT_GPU

<<<<<<< HEAD
#include "SkXfermode_proccoeff.h"

sk_sp<SkSpecialImage> SkXfermodeImageFilter::filterImageGPU(SkSpecialImage* source,
    sk_sp<SkSpecialImage> background,
    const SkIPoint& backgroundOffset,
    sk_sp<SkSpecialImage> foreground,
    const SkIPoint& foregroundOffset,
    const SkIRect& bounds) const
{
    SkASSERT(source->isTextureBacked());

    GrContext* context = source->getContext();

    sk_sp<GrTexture> backgroundTex, foregroundTex;

    if (background) {
        backgroundTex = background->asTextureRef(context);
    }

    if (foreground) {
        foregroundTex = foreground->asTextureRef(context);
    }

    GrPaint paint;
    // SRGBTODO: AllowSRGBInputs?
    sk_sp<GrFragmentProcessor> bgFP;

    if (backgroundTex) {
        SkMatrix backgroundMatrix;
        backgroundMatrix.setIDiv(backgroundTex->width(), backgroundTex->height());
        backgroundMatrix.preTranslate(SkIntToScalar(-backgroundOffset.fX),
            SkIntToScalar(-backgroundOffset.fY));
        bgFP = GrTextureDomainEffect::Make(
            backgroundTex.get(), backgroundMatrix,
            GrTextureDomain::MakeTexelDomain(backgroundTex.get(),
                background->subset()),
            GrTextureDomain::kDecal_Mode,
            GrTextureParams::kNone_FilterMode);
    } else {
        bgFP = GrConstColorProcessor::Make(GrColor_TRANSPARENT_BLACK,
            GrConstColorProcessor::kIgnore_InputMode);
    }

    if (foregroundTex) {
        SkMatrix foregroundMatrix;
        foregroundMatrix.setIDiv(foregroundTex->width(), foregroundTex->height());
        foregroundMatrix.preTranslate(SkIntToScalar(-foregroundOffset.fX),
            SkIntToScalar(-foregroundOffset.fY));

        sk_sp<GrFragmentProcessor> foregroundFP;

        foregroundFP = GrTextureDomainEffect::Make(
            foregroundTex.get(), foregroundMatrix,
            GrTextureDomain::MakeTexelDomain(foregroundTex.get(),
                foreground->subset()),
            GrTextureDomain::kDecal_Mode,
            GrTextureParams::kNone_FilterMode);

        paint.addColorFragmentProcessor(std::move(foregroundFP));

        // A null fMode is interpreted to mean kSrcOver_Mode (to match raster).
        SkAutoTUnref<SkXfermode> mode(SkSafeRef(fMode.get()));
        if (!mode) {
            // It would be awesome to use SkXfermode::Create here but it knows better
            // than us and won't return a kSrcOver_Mode SkXfermode. That means we
            // have to get one the hard way.
            struct ProcCoeff rec;
            rec.fProc = SkXfermode::GetProc(SkXfermode::kSrcOver_Mode);
            SkXfermode::ModeAsCoeff(SkXfermode::kSrcOver_Mode, &rec.fSC, &rec.fDC);

            mode.reset(new SkProcCoeffXfermode(rec, SkXfermode::kSrcOver_Mode));
        }

        sk_sp<GrFragmentProcessor> xferFP(
            mode->makeFragmentProcessorForImageFilter(std::move(bgFP)));

        // A null 'xferFP' here means kSrc_Mode was used in which case we can just proceed
        if (xferFP) {
            paint.addColorFragmentProcessor(std::move(xferFP));
        }
    } else {
        paint.addColorFragmentProcessor(std::move(bgFP));
    }

    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);

    sk_sp<GrDrawContext> drawContext(context->newDrawContext(SkBackingFit::kApprox,
        bounds.width(), bounds.height(),
        kSkia8888_GrPixelConfig));
    if (!drawContext) {
        return nullptr;
    }

    SkMatrix matrix;
    matrix.setTranslate(SkIntToScalar(-bounds.left()), SkIntToScalar(-bounds.top()));
    drawContext->drawRect(GrNoClip(), paint, matrix, SkRect::Make(bounds));

    return SkSpecialImage::MakeFromGpu(SkIRect::MakeWH(bounds.width(), bounds.height()),
        kNeedNewImageUniqueID_SpecialImage,
        drawContext->asTexture());
}

#endif
=======
bool SkXfermodeImageFilter::canFilterImageGPU() const {
    return fMode && fMode->asFragmentProcessor(NULL, NULL, NULL) && !cropRectIsSet();
}

bool SkXfermodeImageFilter::filterImageGPU(Proxy* proxy,
                                           const SkBitmap& src,
                                           const Context& ctx,
                                           SkBitmap* result,
                                           SkIPoint* offset) const {
    SkBitmap background = src;
    SkIPoint backgroundOffset = SkIPoint::Make(0, 0);
    if (getInput(0) && !getInput(0)->getInputResultGPU(proxy, src, ctx, &background,
                                                       &backgroundOffset)) {
        return onFilterImage(proxy, src, ctx, result, offset);
    }
    GrTexture* backgroundTex = background.getTexture();

    if (NULL == backgroundTex) {
        SkASSERT(false);
        return false;
    }

    SkBitmap foreground = src;
    SkIPoint foregroundOffset = SkIPoint::Make(0, 0);
    if (getInput(1) && !getInput(1)->getInputResultGPU(proxy, src, ctx, &foreground,
                                                       &foregroundOffset)) {
        return onFilterImage(proxy, src, ctx, result, offset);
    }
    GrTexture* foregroundTex = foreground.getTexture();
    GrContext* context = foregroundTex->getContext();

    GrFragmentProcessor* xferProcessor = NULL;

    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = src.width();
    desc.fHeight = src.height();
    desc.fConfig = kSkia8888_GrPixelConfig;
    SkAutoTUnref<GrTexture> dst(context->textureProvider()->refScratchTexture(
        desc, GrTextureProvider::kApprox_ScratchTexMatch));
    if (!dst) {
        return false;
    }

    GrPaint paint;
    if (!fMode || !fMode->asFragmentProcessor(&xferProcessor, paint.getProcessorDataManager(),
                                              backgroundTex)) {
        // canFilterImageGPU() should've taken care of this
        SkASSERT(false);
        return false;
    }

    SkMatrix foregroundMatrix = GrCoordTransform::MakeDivByTextureWHMatrix(foregroundTex);
    foregroundMatrix.preTranslate(SkIntToScalar(backgroundOffset.fX-foregroundOffset.fX),
                                  SkIntToScalar(backgroundOffset.fY-foregroundOffset.fY));


    SkRect srcRect;
    src.getBounds(&srcRect);

    SkAutoTUnref<GrFragmentProcessor> foregroundDomain(GrTextureDomainEffect::Create(
        paint.getProcessorDataManager(),
        foregroundTex, foregroundMatrix,
        GrTextureDomain::MakeTexelDomain(foregroundTex, foreground.bounds()),
        GrTextureDomain::kDecal_Mode,
        GrTextureParams::kNone_FilterMode)
    );

    paint.addColorProcessor(foregroundDomain.get());
    paint.addColorProcessor(xferProcessor)->unref();

    GrDrawContext* drawContext = context->drawContext();
    if (!drawContext) {
        return false;
    }

    drawContext->drawRect(dst->asRenderTarget(), GrClip::WideOpen(), paint, 
                          SkMatrix::I(), srcRect);

    offset->fX = backgroundOffset.fX;
    offset->fY = backgroundOffset.fY;
    WrapTexture(dst, src.width(), src.height(), result);
    return true;
}

#endif

>>>>>>> miniblink49
