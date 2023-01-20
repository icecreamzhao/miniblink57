<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkBlurMaskFilter.h"
#include "SkBlurMask.h"
#include "SkGpuBlurUtils.h"
<<<<<<< HEAD
#include "SkMaskFilter.h"
#include "SkRRect.h"
#include "SkRTConf.h"
#include "SkReadBuffer.h"
#include "SkStringUtils.h"
#include "SkStrokeRec.h"
#include "SkWriteBuffer.h"

#if SK_SUPPORT_GPU
#include "GrCircleBlurFragmentProcessor.h"
#include "GrContext.h"
#include "GrDrawContext.h"
#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
#include "GrTexture.h"
#include "SkDraw.h"
#include "effects/GrSimpleTextureEffect.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLSampler.h"
#include "glsl/GrGLSLUniformHandler.h"
#endif

SkScalar SkBlurMaskFilter::ConvertRadiusToSigma(SkScalar radius)
{
=======
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkMaskFilter.h"
#include "SkRRect.h"
#include "SkRTConf.h"
#include "SkStringUtils.h"
#include "SkStrokeRec.h"

#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrDrawContext.h"
#include "GrTexture.h"
#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
#include "SkGrPixelRef.h"
#include "SkDraw.h"
#include "effects/GrSimpleTextureEffect.h"
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
#endif

SkScalar SkBlurMaskFilter::ConvertRadiusToSigma(SkScalar radius) {
>>>>>>> miniblink49
    return SkBlurMask::ConvertRadiusToSigma(radius);
}

class SkBlurMaskFilterImpl : public SkMaskFilter {
public:
    SkBlurMaskFilterImpl(SkScalar sigma, SkBlurStyle, uint32_t flags);

    // overrides from SkMaskFilter
    SkMask::Format getFormat() const override;
<<<<<<< HEAD
    bool filterMask(SkMask* dst, const SkMask& src, const SkMatrix&,
        SkIPoint* margin) const override;

#if SK_SUPPORT_GPU
    bool canFilterMaskGPU(const SkRRect& devRRect,
        const SkIRect& clipBounds,
        const SkMatrix& ctm,
        SkRect* maskRect) const override;
    bool directFilterMaskGPU(GrTextureProvider* texProvider,
        GrDrawContext* drawContext,
        GrPaint* grp,
        const GrClip&,
        const SkMatrix& viewMatrix,
        const SkStrokeRec& strokeRec,
        const SkPath& path) const override;
    bool directFilterRRectMaskGPU(GrTextureProvider* texProvider,
        GrDrawContext* drawContext,
        GrPaint* grp,
        const GrClip&,
        const SkMatrix& viewMatrix,
        const SkStrokeRec& strokeRec,
        const SkRRect& rrect) const override;
    bool filterMaskGPU(GrTexture* src,
        const SkMatrix& ctm,
        const SkIRect& maskRect,
        GrTexture** result) const override;
=======
    virtual bool filterMask(SkMask* dst, const SkMask& src, const SkMatrix&,
                            SkIPoint* margin) const override;

#if SK_SUPPORT_GPU
    virtual bool canFilterMaskGPU(const SkRect& devBounds,
                                  const SkIRect& clipBounds,
                                  const SkMatrix& ctm,
                                  SkRect* maskRect) const override;
    virtual bool directFilterMaskGPU(GrContext* context,
                                     GrRenderTarget* rt,
                                     GrPaint* grp,
                                     const GrClip&,
                                     const SkMatrix& viewMatrix,
                                     const SkStrokeRec& strokeRec,
                                     const SkPath& path) const override;
    virtual bool directFilterRRectMaskGPU(GrContext* context,
                                          GrRenderTarget* rt,
                                          GrPaint* grp,
                                          const GrClip&,
                                          const SkMatrix& viewMatrix,
                                          const SkStrokeRec& strokeRec,
                                          const SkRRect& rrect) const override;

    virtual bool filterMaskGPU(GrTexture* src,
                               const SkMatrix& ctm,
                               const SkRect& maskRect,
                               GrTexture** result,
                               bool canOverwriteSrc) const override;
>>>>>>> miniblink49
#endif

    void computeFastBounds(const SkRect&, SkRect*) const override;
    bool asABlur(BlurRec*) const override;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkBlurMaskFilterImpl)

protected:
<<<<<<< HEAD
    FilterReturn filterRectsToNine(const SkRect[], int count, const SkMatrix&,
        const SkIRect& clipBounds,
        NinePatch*) const override;

    FilterReturn filterRRectToNine(const SkRRect&, const SkMatrix&,
        const SkIRect& clipBounds,
        NinePatch*) const override;

    bool filterRectMask(SkMask* dstM, const SkRect& r, const SkMatrix& matrix,
        SkIPoint* margin, SkMask::CreateMode createMode) const;
    bool filterRRectMask(SkMask* dstM, const SkRRect& r, const SkMatrix& matrix,
        SkIPoint* margin, SkMask::CreateMode createMode) const;
=======
    virtual FilterReturn filterRectsToNine(const SkRect[], int count, const SkMatrix&,
                                           const SkIRect& clipBounds,
                                           NinePatch*) const override;

    virtual FilterReturn filterRRectToNine(const SkRRect&, const SkMatrix&,
                                           const SkIRect& clipBounds,
                                           NinePatch*) const override;

    bool filterRectMask(SkMask* dstM, const SkRect& r, const SkMatrix& matrix,
                        SkIPoint* margin, SkMask::CreateMode createMode) const;
    bool filterRRectMask(SkMask* dstM, const SkRRect& r, const SkMatrix& matrix,
                        SkIPoint* margin, SkMask::CreateMode createMode) const;
>>>>>>> miniblink49

private:
    // To avoid unseemly allocation requests (esp. for finite platforms like
    // handset) we limit the radius so something manageable. (as opposed to
    // a request like 10,000)
    static const SkScalar kMAX_BLUR_SIGMA;

<<<<<<< HEAD
    SkScalar fSigma;
    SkBlurStyle fBlurStyle;
    uint32_t fBlurFlags;

    SkBlurQuality getQuality() const
    {
        return (fBlurFlags & SkBlurMaskFilter::kHighQuality_BlurFlag) ? kHigh_SkBlurQuality : kLow_SkBlurQuality;
=======
    SkScalar    fSigma;
    SkBlurStyle fBlurStyle;
    uint32_t    fBlurFlags;

    SkBlurQuality getQuality() const {
        return (fBlurFlags & SkBlurMaskFilter::kHighQuality_BlurFlag) ?
                kHigh_SkBlurQuality : kLow_SkBlurQuality;
>>>>>>> miniblink49
    }

    SkBlurMaskFilterImpl(SkReadBuffer&);
    void flatten(SkWriteBuffer&) const override;

<<<<<<< HEAD
    SkScalar computeXformedSigma(const SkMatrix& ctm) const
    {
=======
    SkScalar computeXformedSigma(const SkMatrix& ctm) const {
>>>>>>> miniblink49
        bool ignoreTransform = SkToBool(fBlurFlags & SkBlurMaskFilter::kIgnoreTransform_BlurFlag);

        SkScalar xformedSigma = ignoreTransform ? fSigma : ctm.mapRadius(fSigma);
        return SkMinScalar(xformedSigma, kMAX_BLUR_SIGMA);
    }

    friend class SkBlurMaskFilter;

    typedef SkMaskFilter INHERITED;
};

const SkScalar SkBlurMaskFilterImpl::kMAX_BLUR_SIGMA = SkIntToScalar(128);

<<<<<<< HEAD
sk_sp<SkMaskFilter> SkBlurMaskFilter::Make(SkBlurStyle style, SkScalar sigma, uint32_t flags)
{
    if (!SkScalarIsFinite(sigma) || sigma <= 0) {
        return nullptr;
    }
    if ((unsigned)style > (unsigned)kLastEnum_SkBlurStyle) {
        return nullptr;
    }
    if (flags > SkBlurMaskFilter::kAll_BlurFlag) {
        return nullptr;
    }
    return sk_sp<SkMaskFilter>(new SkBlurMaskFilterImpl(sigma, style, flags));
=======
SkMaskFilter* SkBlurMaskFilter::Create(SkBlurStyle style, SkScalar sigma, uint32_t flags) {
    if (!SkScalarIsFinite(sigma) || sigma <= 0) {
        return NULL;
    }
    if ((unsigned)style > (unsigned)kLastEnum_SkBlurStyle) {
        return NULL;
    }
    if (flags > SkBlurMaskFilter::kAll_BlurFlag) {
        return NULL;
    }
    return SkNEW_ARGS(SkBlurMaskFilterImpl, (sigma, style, flags));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

SkBlurMaskFilterImpl::SkBlurMaskFilterImpl(SkScalar sigma, SkBlurStyle style, uint32_t flags)
    : fSigma(sigma)
    , fBlurStyle(style)
<<<<<<< HEAD
    , fBlurFlags(flags)
{
=======
    , fBlurFlags(flags) {
>>>>>>> miniblink49
    SkASSERT(fSigma > 0);
    SkASSERT((unsigned)style <= kLastEnum_SkBlurStyle);
    SkASSERT(flags <= SkBlurMaskFilter::kAll_BlurFlag);
}

<<<<<<< HEAD
SkMask::Format SkBlurMaskFilterImpl::getFormat() const
{
    return SkMask::kA8_Format;
}

bool SkBlurMaskFilterImpl::asABlur(BlurRec* rec) const
{
=======
SkMask::Format SkBlurMaskFilterImpl::getFormat() const {
    return SkMask::kA8_Format;
}

bool SkBlurMaskFilterImpl::asABlur(BlurRec* rec) const {
>>>>>>> miniblink49
    if (fBlurFlags & SkBlurMaskFilter::kIgnoreTransform_BlurFlag) {
        return false;
    }

    if (rec) {
        rec->fSigma = fSigma;
        rec->fStyle = fBlurStyle;
        rec->fQuality = this->getQuality();
    }
    return true;
}

bool SkBlurMaskFilterImpl::filterMask(SkMask* dst, const SkMask& src,
<<<<<<< HEAD
    const SkMatrix& matrix,
    SkIPoint* margin) const
{
=======
                                      const SkMatrix& matrix,
                                      SkIPoint* margin) const{
>>>>>>> miniblink49
    SkScalar sigma = this->computeXformedSigma(matrix);
    return SkBlurMask::BoxBlur(dst, src, sigma, fBlurStyle, this->getQuality(), margin);
}

bool SkBlurMaskFilterImpl::filterRectMask(SkMask* dst, const SkRect& r,
<<<<<<< HEAD
    const SkMatrix& matrix,
    SkIPoint* margin, SkMask::CreateMode createMode) const
{
    SkScalar sigma = computeXformedSigma(matrix);

    return SkBlurMask::BlurRect(sigma, dst, r, fBlurStyle, margin, createMode);
}

bool SkBlurMaskFilterImpl::filterRRectMask(SkMask* dst, const SkRRect& r,
    const SkMatrix& matrix,
    SkIPoint* margin, SkMask::CreateMode createMode) const
{
    SkScalar sigma = computeXformedSigma(matrix);

    return SkBlurMask::BlurRRect(sigma, dst, r, fBlurStyle, margin, createMode);
=======
                                          const SkMatrix& matrix,
                                          SkIPoint* margin, SkMask::CreateMode createMode) const{
    SkScalar sigma = computeXformedSigma(matrix);

    return SkBlurMask::BlurRect(sigma, dst, r, fBlurStyle,
                                margin, createMode);
}

bool SkBlurMaskFilterImpl::filterRRectMask(SkMask* dst, const SkRRect& r,
                                          const SkMatrix& matrix,
                                          SkIPoint* margin, SkMask::CreateMode createMode) const{
    SkScalar sigma = computeXformedSigma(matrix);

    return SkBlurMask::BlurRRect(sigma, dst, r, fBlurStyle,
                                margin, createMode);
>>>>>>> miniblink49
}

#include "SkCanvas.h"

<<<<<<< HEAD
static bool prepare_to_draw_into_mask(const SkRect& bounds, SkMask* mask)
{
    SkASSERT(mask != nullptr);
=======
static bool prepare_to_draw_into_mask(const SkRect& bounds, SkMask* mask) {
    SkASSERT(mask != NULL);
>>>>>>> miniblink49

    mask->fBounds = bounds.roundOut();
    mask->fRowBytes = SkAlign4(mask->fBounds.width());
    mask->fFormat = SkMask::kA8_Format;
    const size_t size = mask->computeImageSize();
    mask->fImage = SkMask::AllocImage(size);
<<<<<<< HEAD
    if (nullptr == mask->fImage) {
=======
    if (NULL == mask->fImage) {
>>>>>>> miniblink49
        return false;
    }

    // FIXME: use sk_calloc in AllocImage?
    sk_bzero(mask->fImage, size);
    return true;
}

<<<<<<< HEAD
static bool draw_rrect_into_mask(const SkRRect rrect, SkMask* mask)
{
=======
static bool draw_rrect_into_mask(const SkRRect rrect, SkMask* mask) {
>>>>>>> miniblink49
    if (!prepare_to_draw_into_mask(rrect.rect(), mask)) {
        return false;
    }

    // FIXME: This code duplicates code in draw_rects_into_mask, below. Is there a
    // clean way to share more code?
    SkBitmap bitmap;
    bitmap.installMaskPixels(*mask);

    SkCanvas canvas(bitmap);
    canvas.translate(-SkIntToScalar(mask->fBounds.left()),
<<<<<<< HEAD
        -SkIntToScalar(mask->fBounds.top()));
=======
                     -SkIntToScalar(mask->fBounds.top()));
>>>>>>> miniblink49

    SkPaint paint;
    paint.setAntiAlias(true);
    canvas.drawRRect(rrect, paint);
    return true;
}

<<<<<<< HEAD
static bool draw_rects_into_mask(const SkRect rects[], int count, SkMask* mask)
{
=======
static bool draw_rects_into_mask(const SkRect rects[], int count, SkMask* mask) {
>>>>>>> miniblink49
    if (!prepare_to_draw_into_mask(rects[0], mask)) {
        return false;
    }

    SkBitmap bitmap;
    bitmap.installPixels(SkImageInfo::Make(mask->fBounds.width(),
<<<<<<< HEAD
                             mask->fBounds.height(),
                             kAlpha_8_SkColorType,
                             kPremul_SkAlphaType),
        mask->fImage, mask->fRowBytes);

    SkCanvas canvas(bitmap);
    canvas.translate(-SkIntToScalar(mask->fBounds.left()),
        -SkIntToScalar(mask->fBounds.top()));
=======
                                           mask->fBounds.height(),
                                           kAlpha_8_SkColorType,
                                           kPremul_SkAlphaType),
                         mask->fImage, mask->fRowBytes);

    SkCanvas canvas(bitmap);
    canvas.translate(-SkIntToScalar(mask->fBounds.left()),
                     -SkIntToScalar(mask->fBounds.top()));
>>>>>>> miniblink49

    SkPaint paint;
    paint.setAntiAlias(true);

    if (1 == count) {
        canvas.drawRect(rects[0], paint);
    } else {
        // todo: do I need a fast way to do this?
        SkPath path;
        path.addRect(rects[0]);
        path.addRect(rects[1]);
        path.setFillType(SkPath::kEvenOdd_FillType);
        canvas.drawPath(path, paint);
    }
    return true;
}

<<<<<<< HEAD
static bool rect_exceeds(const SkRect& r, SkScalar v)
{
    return r.fLeft < -v || r.fTop < -v || r.fRight > v || r.fBottom > v || r.width() > v || r.height() > v;
=======
static bool rect_exceeds(const SkRect& r, SkScalar v) {
    return r.fLeft < -v || r.fTop < -v || r.fRight > v || r.fBottom > v ||
           r.width() > v || r.height() > v;
>>>>>>> miniblink49
}

#include "SkMaskCache.h"

<<<<<<< HEAD
static SkCachedData* copy_mask_to_cacheddata(SkMask* mask)
{
=======
static SkCachedData* copy_mask_to_cacheddata(SkMask* mask) {
>>>>>>> miniblink49
    const size_t size = mask->computeTotalImageSize();
    SkCachedData* data = SkResourceCache::NewCachedData(size);
    if (data) {
        memcpy(data->writable_data(), mask->fImage, size);
        SkMask::FreeImage(mask->fImage);
        mask->fImage = (uint8_t*)data->data();
    }
    return data;
}

static SkCachedData* find_cached_rrect(SkMask* mask, SkScalar sigma, SkBlurStyle style,
<<<<<<< HEAD
    SkBlurQuality quality, const SkRRect& rrect)
{
=======
                                       SkBlurQuality quality, const SkRRect& rrect) {
>>>>>>> miniblink49
    return SkMaskCache::FindAndRef(sigma, style, quality, rrect, mask);
}

static SkCachedData* add_cached_rrect(SkMask* mask, SkScalar sigma, SkBlurStyle style,
<<<<<<< HEAD
    SkBlurQuality quality, const SkRRect& rrect)
{
=======
                                      SkBlurQuality quality, const SkRRect& rrect) {
>>>>>>> miniblink49
    SkCachedData* cache = copy_mask_to_cacheddata(mask);
    if (cache) {
        SkMaskCache::Add(sigma, style, quality, rrect, *mask, cache);
    }
    return cache;
}

static SkCachedData* find_cached_rects(SkMask* mask, SkScalar sigma, SkBlurStyle style,
<<<<<<< HEAD
    SkBlurQuality quality, const SkRect rects[], int count)
{
=======
                                       SkBlurQuality quality, const SkRect rects[], int count) {
>>>>>>> miniblink49
    return SkMaskCache::FindAndRef(sigma, style, quality, rects, count, mask);
}

static SkCachedData* add_cached_rects(SkMask* mask, SkScalar sigma, SkBlurStyle style,
<<<<<<< HEAD
    SkBlurQuality quality, const SkRect rects[], int count)
{
=======
                                      SkBlurQuality quality, const SkRect rects[], int count) {
>>>>>>> miniblink49
    SkCachedData* cache = copy_mask_to_cacheddata(mask);
    if (cache) {
        SkMaskCache::Add(sigma, style, quality, rects, count, *mask, cache);
    }
    return cache;
}

#ifdef SK_IGNORE_FAST_RRECT_BLUR
<<<<<<< HEAD
SK_CONF_DECLARE(bool, c_analyticBlurRRect, "mask.filter.blur.analyticblurrrect", false, "Use the faster analytic blur approach for ninepatch rects");
#else
SK_CONF_DECLARE(bool, c_analyticBlurRRect, "mask.filter.blur.analyticblurrrect", true, "Use the faster analytic blur approach for ninepatch round rects");
=======
SK_CONF_DECLARE( bool, c_analyticBlurRRect, "mask.filter.blur.analyticblurrrect", false, "Use the faster analytic blur approach for ninepatch rects" );
#else
SK_CONF_DECLARE( bool, c_analyticBlurRRect, "mask.filter.blur.analyticblurrrect", true, "Use the faster analytic blur approach for ninepatch round rects" );
>>>>>>> miniblink49
#endif

SkMaskFilter::FilterReturn
SkBlurMaskFilterImpl::filterRRectToNine(const SkRRect& rrect, const SkMatrix& matrix,
<<<<<<< HEAD
    const SkIRect& clipBounds,
    NinePatch* patch) const
{
    SkASSERT(patch != nullptr);
    switch (rrect.getType()) {
    case SkRRect::kEmpty_Type:
        // Nothing to draw.
        return kFalse_FilterReturn;

    case SkRRect::kRect_Type:
        // We should have caught this earlier.
        SkASSERT(false);
        // Fall through.
    case SkRRect::kOval_Type:
        // The nine patch special case does not handle ovals, and we
        // already have code for rectangles.
        return kUnimplemented_FilterReturn;

    // These three can take advantage of this fast path.
    case SkRRect::kSimple_Type:
    case SkRRect::kNinePatch_Type:
    case SkRRect::kComplex_Type:
        break;
=======
                                        const SkIRect& clipBounds,
                                        NinePatch* patch) const {
    SkASSERT(patch != NULL);
    switch (rrect.getType()) {
        case SkRRect::kEmpty_Type:
            // Nothing to draw.
            return kFalse_FilterReturn;

        case SkRRect::kRect_Type:
            // We should have caught this earlier.
            SkASSERT(false);
            // Fall through.
        case SkRRect::kOval_Type:
            // The nine patch special case does not handle ovals, and we
            // already have code for rectangles.
            return kUnimplemented_FilterReturn;

        // These three can take advantage of this fast path.
        case SkRRect::kSimple_Type:
        case SkRRect::kNinePatch_Type:
        case SkRRect::kComplex_Type:
            break;
>>>>>>> miniblink49
    }

    // TODO: report correct metrics for innerstyle, where we do not grow the
    // total bounds, but we do need an inset the size of our blur-radius
    if (kInner_SkBlurStyle == fBlurStyle) {
        return kUnimplemented_FilterReturn;
    }

    // TODO: take clipBounds into account to limit our coordinates up front
    // for now, just skip too-large src rects (to take the old code path).
    if (rect_exceeds(rrect.rect(), SkIntToScalar(32767))) {
        return kUnimplemented_FilterReturn;
    }

    SkIPoint margin;
<<<<<<< HEAD
    SkMask srcM, dstM;
    srcM.fBounds = rrect.rect().roundOut();
=======
    SkMask  srcM, dstM;
    srcM.fBounds = rrect.rect().roundOut();
    srcM.fImage = NULL;
>>>>>>> miniblink49
    srcM.fFormat = SkMask::kA8_Format;
    srcM.fRowBytes = 0;

    bool filterResult = false;
    if (c_analyticBlurRRect) {
        // special case for fast round rect blur
        // don't actually do the blur the first time, just compute the correct size
        filterResult = this->filterRRectMask(&dstM, rrect, matrix, &margin,
<<<<<<< HEAD
            SkMask::kJustComputeBounds_CreateMode);
=======
                                            SkMask::kJustComputeBounds_CreateMode);
>>>>>>> miniblink49
    }

    if (!filterResult) {
        filterResult = this->filterMask(&dstM, srcM, matrix, &margin);
    }

    if (!filterResult) {
        return kFalse_FilterReturn;
    }

    // Now figure out the appropriate width and height of the smaller round rectangle
    // to stretch. It will take into account the larger radius per side as well as double
    // the margin, to account for inner and outer blur.
    const SkVector& UL = rrect.radii(SkRRect::kUpperLeft_Corner);
    const SkVector& UR = rrect.radii(SkRRect::kUpperRight_Corner);
    const SkVector& LR = rrect.radii(SkRRect::kLowerRight_Corner);
    const SkVector& LL = rrect.radii(SkRRect::kLowerLeft_Corner);

    const SkScalar leftUnstretched = SkTMax(UL.fX, LL.fX) + SkIntToScalar(2 * margin.fX);
    const SkScalar rightUnstretched = SkTMax(UR.fX, LR.fX) + SkIntToScalar(2 * margin.fX);

    // Extra space in the middle to ensure an unchanging piece for stretching. Use 3 to cover
    // any fractional space on either side plus 1 for the part to stretch.
    const SkScalar stretchSize = SkIntToScalar(3);

    const SkScalar totalSmallWidth = leftUnstretched + rightUnstretched + stretchSize;
    if (totalSmallWidth >= rrect.rect().width()) {
        // There is no valid piece to stretch.
        return kUnimplemented_FilterReturn;
    }

    const SkScalar topUnstretched = SkTMax(UL.fY, UR.fY) + SkIntToScalar(2 * margin.fY);
    const SkScalar bottomUnstretched = SkTMax(LL.fY, LR.fY) + SkIntToScalar(2 * margin.fY);

    const SkScalar totalSmallHeight = topUnstretched + bottomUnstretched + stretchSize;
    if (totalSmallHeight >= rrect.rect().height()) {
        // There is no valid piece to stretch.
        return kUnimplemented_FilterReturn;
    }

    SkRect smallR = SkRect::MakeWH(totalSmallWidth, totalSmallHeight);

    SkRRect smallRR;
    SkVector radii[4];
    radii[SkRRect::kUpperLeft_Corner] = UL;
    radii[SkRRect::kUpperRight_Corner] = UR;
    radii[SkRRect::kLowerRight_Corner] = LR;
    radii[SkRRect::kLowerLeft_Corner] = LL;
    smallRR.setRectRadii(smallR, radii);

    const SkScalar sigma = this->computeXformedSigma(matrix);
    SkCachedData* cache = find_cached_rrect(&patch->fMask, sigma, fBlurStyle,
<<<<<<< HEAD
        this->getQuality(), smallRR);
    if (!cache) {
        bool analyticBlurWorked = false;
        if (c_analyticBlurRRect) {
            analyticBlurWorked = this->filterRRectMask(&patch->fMask, smallRR, matrix, &margin,
                SkMask::kComputeBoundsAndRenderImage_CreateMode);
=======
                                            this->getQuality(), smallRR);
    if (!cache) {
        bool analyticBlurWorked = false;
        if (c_analyticBlurRRect) {
            analyticBlurWorked =
                this->filterRRectMask(&patch->fMask, smallRR, matrix, &margin,
                                      SkMask::kComputeBoundsAndRenderImage_CreateMode);
>>>>>>> miniblink49
        }

        if (!analyticBlurWorked) {
            if (!draw_rrect_into_mask(smallRR, &srcM)) {
                return kFalse_FilterReturn;
            }

            SkAutoMaskFreeImage amf(srcM.fImage);

            if (!this->filterMask(&patch->fMask, srcM, matrix, &margin)) {
                return kFalse_FilterReturn;
            }
        }
        cache = add_cached_rrect(&patch->fMask, sigma, fBlurStyle, this->getQuality(), smallRR);
    }

    patch->fMask.fBounds.offsetTo(0, 0);
    patch->fOuterRect = dstM.fBounds;
    patch->fCenter.fX = SkScalarCeilToInt(leftUnstretched) + 1;
    patch->fCenter.fY = SkScalarCeilToInt(topUnstretched) + 1;
<<<<<<< HEAD
    SkASSERT(nullptr == patch->fCache);
    patch->fCache = cache; // transfer ownership to patch
    return kTrue_FilterReturn;
}

SK_CONF_DECLARE(bool, c_analyticBlurNinepatch, "mask.filter.analyticNinePatch", true, "Use the faster analytic blur approach for ninepatch rects");

SkMaskFilter::FilterReturn
SkBlurMaskFilterImpl::filterRectsToNine(const SkRect rects[], int count,
    const SkMatrix& matrix,
    const SkIRect& clipBounds,
    NinePatch* patch) const
{
=======
    SkASSERT(NULL == patch->fCache);
    patch->fCache = cache;  // transfer ownership to patch
    return kTrue_FilterReturn;
}

SK_CONF_DECLARE( bool, c_analyticBlurNinepatch, "mask.filter.analyticNinePatch", true, "Use the faster analytic blur approach for ninepatch rects" );

SkMaskFilter::FilterReturn
SkBlurMaskFilterImpl::filterRectsToNine(const SkRect rects[], int count,
                                        const SkMatrix& matrix,
                                        const SkIRect& clipBounds,
                                        NinePatch* patch) const {
>>>>>>> miniblink49
    if (count < 1 || count > 2) {
        return kUnimplemented_FilterReturn;
    }

    // TODO: report correct metrics for innerstyle, where we do not grow the
    // total bounds, but we do need an inset the size of our blur-radius
    if (kInner_SkBlurStyle == fBlurStyle || kOuter_SkBlurStyle == fBlurStyle) {
        return kUnimplemented_FilterReturn;
    }

    // TODO: take clipBounds into account to limit our coordinates up front
    // for now, just skip too-large src rects (to take the old code path).
    if (rect_exceeds(rects[0], SkIntToScalar(32767))) {
        return kUnimplemented_FilterReturn;
    }

    SkIPoint margin;
<<<<<<< HEAD
    SkMask srcM, dstM;
    srcM.fBounds = rects[0].roundOut();
=======
    SkMask  srcM, dstM;
    srcM.fBounds = rects[0].roundOut();
    srcM.fImage = NULL;
>>>>>>> miniblink49
    srcM.fFormat = SkMask::kA8_Format;
    srcM.fRowBytes = 0;

    bool filterResult = false;
    if (count == 1 && c_analyticBlurNinepatch) {
        // special case for fast rect blur
        // don't actually do the blur the first time, just compute the correct size
        filterResult = this->filterRectMask(&dstM, rects[0], matrix, &margin,
<<<<<<< HEAD
            SkMask::kJustComputeBounds_CreateMode);
=======
                                            SkMask::kJustComputeBounds_CreateMode);
>>>>>>> miniblink49
    } else {
        filterResult = this->filterMask(&dstM, srcM, matrix, &margin);
    }

    if (!filterResult) {
        return kFalse_FilterReturn;
    }

    /*
     *  smallR is the smallest version of 'rect' that will still guarantee that
     *  we get the same blur results on all edges, plus 1 center row/col that is
     *  representative of the extendible/stretchable edges of the ninepatch.
     *  Since our actual edge may be fractional we inset 1 more to be sure we
     *  don't miss any interior blur.
     *  x is an added pixel of blur, and { and } are the (fractional) edge
     *  pixels from the original rect.
     *
     *   x x { x x .... x x } x x
     *
     *  Thus, in this case, we inset by a total of 5 (on each side) beginning
     *  with our outer-rect (dstM.fBounds)
     */
    SkRect smallR[2];
    SkIPoint center;

    // +2 is from +1 for each edge (to account for possible fractional edges
    int smallW = dstM.fBounds.width() - srcM.fBounds.width() + 2;
    int smallH = dstM.fBounds.height() - srcM.fBounds.height() + 2;
    SkIRect innerIR;

    if (1 == count) {
        innerIR = srcM.fBounds;
        center.set(smallW, smallH);
    } else {
        SkASSERT(2 == count);
        rects[1].roundIn(&innerIR);
        center.set(smallW + (innerIR.left() - srcM.fBounds.left()),
<<<<<<< HEAD
            smallH + (innerIR.top() - srcM.fBounds.top()));
=======
                   smallH + (innerIR.top() - srcM.fBounds.top()));
>>>>>>> miniblink49
    }

    // +1 so we get a clean, stretchable, center row/col
    smallW += 1;
    smallH += 1;

    // we want the inset amounts to be integral, so we don't change any
    // fractional phase on the fRight or fBottom of our smallR.
    const SkScalar dx = SkIntToScalar(innerIR.width() - smallW);
    const SkScalar dy = SkIntToScalar(innerIR.height() - smallH);
    if (dx < 0 || dy < 0) {
        // we're too small, relative to our blur, to break into nine-patch,
        // so we ask to have our normal filterMask() be called.
        return kUnimplemented_FilterReturn;
    }

    smallR[0].set(rects[0].left(), rects[0].top(), rects[0].right() - dx, rects[0].bottom() - dy);
    if (smallR[0].width() < 2 || smallR[0].height() < 2) {
        return kUnimplemented_FilterReturn;
    }
    if (2 == count) {
        smallR[1].set(rects[1].left(), rects[1].top(),
<<<<<<< HEAD
            rects[1].right() - dx, rects[1].bottom() - dy);
=======
                      rects[1].right() - dx, rects[1].bottom() - dy);
>>>>>>> miniblink49
        SkASSERT(!smallR[1].isEmpty());
    }

    const SkScalar sigma = this->computeXformedSigma(matrix);
    SkCachedData* cache = find_cached_rects(&patch->fMask, sigma, fBlurStyle,
<<<<<<< HEAD
        this->getQuality(), smallR, count);
=======
                                            this->getQuality(), smallR, count);
>>>>>>> miniblink49
    if (!cache) {
        if (count > 1 || !c_analyticBlurNinepatch) {
            if (!draw_rects_into_mask(smallR, count, &srcM)) {
                return kFalse_FilterReturn;
            }

            SkAutoMaskFreeImage amf(srcM.fImage);

            if (!this->filterMask(&patch->fMask, srcM, matrix, &margin)) {
                return kFalse_FilterReturn;
            }
        } else {
            if (!this->filterRectMask(&patch->fMask, smallR[0], matrix, &margin,
<<<<<<< HEAD
                    SkMask::kComputeBoundsAndRenderImage_CreateMode)) {
=======
                                      SkMask::kComputeBoundsAndRenderImage_CreateMode)) {
>>>>>>> miniblink49
                return kFalse_FilterReturn;
            }
        }
        cache = add_cached_rects(&patch->fMask, sigma, fBlurStyle, this->getQuality(), smallR, count);
    }
    patch->fMask.fBounds.offsetTo(0, 0);
    patch->fOuterRect = dstM.fBounds;
    patch->fCenter = center;
<<<<<<< HEAD
    SkASSERT(nullptr == patch->fCache);
    patch->fCache = cache; // transfer ownership to patch
=======
    SkASSERT(NULL == patch->fCache);
    patch->fCache = cache;  // transfer ownership to patch
>>>>>>> miniblink49
    return kTrue_FilterReturn;
}

void SkBlurMaskFilterImpl::computeFastBounds(const SkRect& src,
<<<<<<< HEAD
    SkRect* dst) const
{
    SkScalar pad = 3.0f * fSigma;

    dst->set(src.fLeft - pad, src.fTop - pad,
        src.fRight + pad, src.fBottom + pad);
}

sk_sp<SkFlattenable> SkBlurMaskFilterImpl::CreateProc(SkReadBuffer& buffer)
{
=======
                                             SkRect* dst) const {
    SkScalar pad = 3.0f * fSigma;

    dst->set(src.fLeft  - pad, src.fTop    - pad,
             src.fRight + pad, src.fBottom + pad);
}

SkFlattenable* SkBlurMaskFilterImpl::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    const SkScalar sigma = buffer.readScalar();
    const unsigned style = buffer.readUInt();
    const unsigned flags = buffer.readUInt();
    if (style <= kLastEnum_SkBlurStyle) {
<<<<<<< HEAD
        return SkBlurMaskFilter::Make((SkBlurStyle)style, sigma, flags);
    }
    return nullptr;
}

void SkBlurMaskFilterImpl::flatten(SkWriteBuffer& buffer) const
{
=======
        return SkBlurMaskFilter::Create((SkBlurStyle)style, sigma, flags);
    }
    return NULL;
}

void SkBlurMaskFilterImpl::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    buffer.writeScalar(fSigma);
    buffer.writeUInt(fBlurStyle);
    buffer.writeUInt(fBlurFlags);
}

#if SK_SUPPORT_GPU

class GrGLRectBlurEffect;

class GrRectBlurEffect : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    ~GrRectBlurEffect() override { }

    const char* name() const override { return "RectBlur"; }

    static sk_sp<GrFragmentProcessor> Make(GrTextureProvider* textureProvider,
        const SkRect& rect, float sigma)
    {
        int doubleProfileSize = SkScalarCeilToInt(12 * sigma);
=======
    virtual ~GrRectBlurEffect();

    const char* name() const override { return "RectBlur"; }

    virtual void getGLProcessorKey(const GrGLSLCaps& caps,
                                   GrProcessorKeyBuilder* b) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

    /**
     * Create a simple filter effect with custom bicubic coefficients.
     */
    static GrFragmentProcessor* Create(GrTextureProvider *textureProvider, const SkRect& rect,
                                       float sigma) {
        GrTexture *blurProfileTexture = NULL;
        int doubleProfileSize = SkScalarCeilToInt(12*sigma);
>>>>>>> miniblink49

        if (doubleProfileSize >= rect.width() || doubleProfileSize >= rect.height()) {
            // if the blur sigma is too large so the gaussian overlaps the whole
            // rect in either direction, fall back to CPU path for now.
<<<<<<< HEAD
            return nullptr;
        }

        SkAutoTUnref<GrTexture> blurProfile(CreateBlurProfileTexture(textureProvider, sigma));
        if (!blurProfile) {
            return nullptr;
        }
        // in OpenGL ES, mediump floats have a minimum range of 2^14. If we have coordinates bigger
        // than that, the shader math will end up with infinities and result in the blur effect not
        // working correctly. To avoid this, we switch into highp when the coordinates are too big.
        // As 2^14 is the minimum range but the actual range can be bigger, we might end up
        // switching to highp sooner than strictly necessary, but most devices that have a bigger
        // range for mediump also have mediump being exactly the same as highp (e.g. all non-OpenGL
        // ES devices), and thus incur no additional penalty for the switch.
        static const SkScalar kMAX_BLUR_COORD = SkIntToScalar(16000);
        GrSLPrecision precision;
        if (SkScalarAbs(rect.top()) > kMAX_BLUR_COORD || SkScalarAbs(rect.left()) > kMAX_BLUR_COORD || SkScalarAbs(rect.bottom()) > kMAX_BLUR_COORD || SkScalarAbs(rect.right()) > kMAX_BLUR_COORD || SkScalarAbs(rect.width()) > kMAX_BLUR_COORD || SkScalarAbs(rect.height()) > kMAX_BLUR_COORD) {
            precision = kHigh_GrSLPrecision;
        } else {
            precision = kDefault_GrSLPrecision;
        }
        return sk_sp<GrFragmentProcessor>(
            new GrRectBlurEffect(rect, sigma, blurProfile, precision));
=======

            return NULL;
        }

        bool createdBlurProfileTexture = CreateBlurProfileTexture(
            textureProvider, sigma, &blurProfileTexture);
        SkAutoTUnref<GrTexture> hunref(blurProfileTexture);
        if (!createdBlurProfileTexture) {
           return NULL;
        }
        return SkNEW_ARGS(GrRectBlurEffect, (rect, sigma, blurProfileTexture));
>>>>>>> miniblink49
    }

    const SkRect& getRect() const { return fRect; }
    float getSigma() const { return fSigma; }
<<<<<<< HEAD
    GrSLPrecision precision() const { return fPrecision; }

private:
    GrRectBlurEffect(const SkRect& rect, float sigma, GrTexture* blurProfile,
        GrSLPrecision fPrecision);

    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const override;

=======

private:
    GrRectBlurEffect(const SkRect& rect, float sigma, GrTexture *blur_profile);
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

<<<<<<< HEAD
    static GrTexture* CreateBlurProfileTexture(GrTextureProvider*, float sigma);

    SkRect fRect;
    float fSigma;
    GrTextureAccess fBlurProfileAccess;
    GrSLPrecision fPrecision;
=======
    static bool CreateBlurProfileTexture(GrTextureProvider*, float sigma,
                                         GrTexture **blurProfileTexture);

    SkRect          fRect;
    float           fSigma;
    GrTextureAccess fBlurProfileAccess;
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef GrFragmentProcessor INHERITED;
};

<<<<<<< HEAD
class GrGLRectBlurEffect : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs&) override;

    static void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder* b);

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

private:
    typedef GrGLSLProgramDataManager::UniformHandle UniformHandle;

    UniformHandle fProxyRectUniform;
    UniformHandle fProfileSizeUniform;

    typedef GrGLSLFragmentProcessor INHERITED;
};

void OutputRectBlurProfileLookup(GrGLSLFPFragmentBuilder* fragBuilder,
    GrGLSLFragmentProcessor::SamplerHandle sampler,
    const char* output,
    const char* profileSize, const char* loc,
    const char* blurred_width,
    const char* sharp_width)
{
    fragBuilder->codeAppendf("float %s;", output);
    fragBuilder->codeAppendf("{");
    fragBuilder->codeAppendf("float coord = ((abs(%s - 0.5 * %s) - 0.5 * %s)) / %s;",
        loc, blurred_width, sharp_width, profileSize);
    fragBuilder->codeAppendf("%s = ", output);
    fragBuilder->appendTextureLookup(sampler, "vec2(coord,0.5)");
    fragBuilder->codeAppend(".a;");
    fragBuilder->codeAppendf("}");
}

void GrGLRectBlurEffect::GenKey(const GrProcessor& proc, const GrGLSLCaps&,
    GrProcessorKeyBuilder* b)
{
    const GrRectBlurEffect& rbe = proc.cast<GrRectBlurEffect>();

    b->add32(rbe.precision());
}

void GrGLRectBlurEffect::emitCode(EmitArgs& args)
{
    const GrRectBlurEffect& rbe = args.fFp.cast<GrRectBlurEffect>();

    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

    const char* rectName;
    const char* profileSizeName;

    SkString precisionString;
    if (args.fGLSLCaps->usesPrecisionModifiers()) {
        precisionString.printf("%s ", GrGLSLPrecisionString(rbe.precision()));
    }
    fProxyRectUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec4f_GrSLType,
        rbe.precision(),
        "proxyRect",
        &rectName);
    fProfileSizeUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType,
        kDefault_GrSLPrecision,
        "profileSize",
        &profileSizeName);

    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    const char* fragmentPos = fragBuilder->fragmentPosition();

    if (args.fInputColor) {
        fragBuilder->codeAppendf("vec4 src=%s;", args.fInputColor);
    } else {
        fragBuilder->codeAppendf("vec4 src=vec4(1);");
    }

    fragBuilder->codeAppendf("%s vec2 translatedPos = %s.xy - %s.xy;", precisionString.c_str(),
        fragmentPos, rectName);
    fragBuilder->codeAppendf("%s float width = %s.z - %s.x;", precisionString.c_str(), rectName,
        rectName);
    fragBuilder->codeAppendf("%s float height = %s.w - %s.y;", precisionString.c_str(), rectName,
        rectName);

    fragBuilder->codeAppendf("%s vec2 smallDims = vec2(width - %s, height - %s);",
        precisionString.c_str(), profileSizeName, profileSizeName);
    fragBuilder->codeAppendf("%s float center = 2.0 * floor(%s/2.0 + .25) - 1.0;",
        precisionString.c_str(), profileSizeName);
    fragBuilder->codeAppendf("%s vec2 wh = smallDims - vec2(center,center);",
        precisionString.c_str());

    OutputRectBlurProfileLookup(fragBuilder, args.fTexSamplers[0], "horiz_lookup", profileSizeName,
        "translatedPos.x", "width", "wh.x");
    OutputRectBlurProfileLookup(fragBuilder, args.fTexSamplers[0], "vert_lookup", profileSizeName,
        "translatedPos.y", "height", "wh.y");

    fragBuilder->codeAppendf("float final = horiz_lookup * vert_lookup;");
    fragBuilder->codeAppendf("%s = src * final;", args.fOutputColor);
}

void GrGLRectBlurEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& proc)
{
=======
class GrGLRectBlurEffect : public GrGLFragmentProcessor {
public:
    GrGLRectBlurEffect(const GrProcessor&) {}
    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

private:
    typedef GrGLProgramDataManager::UniformHandle UniformHandle;

    UniformHandle       fProxyRectUniform;
    UniformHandle       fProfileSizeUniform;

    typedef GrGLFragmentProcessor INHERITED;
};

void OutputRectBlurProfileLookup(GrGLFragmentBuilder* fsBuilder,
                                 const GrGLShaderBuilder::TextureSampler& sampler,
                                 const char *output,
                                 const char *profileSize, const char *loc,
                                 const char *blurred_width,
                                 const char *sharp_width) {
    fsBuilder->codeAppendf("\tfloat %s;\n", output);
    fsBuilder->codeAppendf("\t\t{\n");
    fsBuilder->codeAppendf("\t\t\tfloat coord = (0.5 * (abs(2.0*%s - %s) - %s))/%s;\n",
                           loc, blurred_width, sharp_width, profileSize);
    fsBuilder->codeAppendf("\t\t\t%s = ", output);
    fsBuilder->appendTextureLookup(sampler, "vec2(coord,0.5)");
    fsBuilder->codeAppend(".a;\n");
    fsBuilder->codeAppendf("\t\t}\n");
}

void GrGLRectBlurEffect::emitCode(GrGLFPBuilder* builder,
                                 const GrFragmentProcessor&,
                                 const char* outputColor,
                                 const char* inputColor,
                                 const TransformedCoordsArray& coords,
                                 const TextureSamplerArray& samplers) {

    const char *rectName;
    const char *profileSizeName;

    fProxyRectUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                            kVec4f_GrSLType,
                                            kDefault_GrSLPrecision,
                                            "proxyRect",
                                            &rectName);
    fProfileSizeUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                            kFloat_GrSLType,
                                            kDefault_GrSLPrecision,
                                            "profileSize",
                                            &profileSizeName);

    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    const char *fragmentPos = fsBuilder->fragmentPosition();

    if (inputColor) {
        fsBuilder->codeAppendf("\tvec4 src=%s;\n", inputColor);
    } else {
        fsBuilder->codeAppendf("\tvec4 src=vec4(1)\n;");
    }

    fsBuilder->codeAppendf("\tvec2 translatedPos = %s.xy - %s.xy;\n", fragmentPos, rectName );
    fsBuilder->codeAppendf("\tfloat width = %s.z - %s.x;\n", rectName, rectName);
    fsBuilder->codeAppendf("\tfloat height = %s.w - %s.y;\n", rectName, rectName);

    fsBuilder->codeAppendf("\tvec2 smallDims = vec2(width - %s, height-%s);\n", profileSizeName, profileSizeName);
    fsBuilder->codeAppendf("\tfloat center = 2.0 * floor(%s/2.0 + .25) - 1.0;\n", profileSizeName);
    fsBuilder->codeAppendf("\tvec2 wh = smallDims - vec2(center,center);\n");

    OutputRectBlurProfileLookup(fsBuilder, samplers[0], "horiz_lookup", profileSizeName, "translatedPos.x", "width", "wh.x");
    OutputRectBlurProfileLookup(fsBuilder, samplers[0], "vert_lookup", profileSizeName, "translatedPos.y", "height", "wh.y");

    fsBuilder->codeAppendf("\tfloat final = horiz_lookup * vert_lookup;\n");
    fsBuilder->codeAppendf("\t%s = src * final;\n", outputColor );
}

void GrGLRectBlurEffect::setData(const GrGLProgramDataManager& pdman,
                                 const GrProcessor& proc) {
>>>>>>> miniblink49
    const GrRectBlurEffect& rbe = proc.cast<GrRectBlurEffect>();
    SkRect rect = rbe.getRect();

    pdman.set4f(fProxyRectUniform, rect.fLeft, rect.fTop, rect.fRight, rect.fBottom);
<<<<<<< HEAD
    pdman.set1f(fProfileSizeUniform, SkScalarCeilToScalar(6 * rbe.getSigma()));
}

GrTexture* GrRectBlurEffect::CreateBlurProfileTexture(GrTextureProvider* textureProvider,
    float sigma)
{
    GrSurfaceDesc texDesc;

    unsigned int profileSize = SkScalarCeilToInt(6 * sigma);
=======
    pdman.set1f(fProfileSizeUniform, SkScalarCeilToScalar(6*rbe.getSigma()));
}

bool GrRectBlurEffect::CreateBlurProfileTexture(GrTextureProvider* textureProvider, float sigma,
                                                GrTexture **blurProfileTexture) {
    GrSurfaceDesc texDesc;

    unsigned int profileSize = SkScalarCeilToInt(6*sigma);
>>>>>>> miniblink49

    texDesc.fWidth = profileSize;
    texDesc.fHeight = 1;
    texDesc.fConfig = kAlpha_8_GrPixelConfig;
<<<<<<< HEAD
    texDesc.fIsMipMapped = false;
=======
>>>>>>> miniblink49

    static const GrUniqueKey::Domain kDomain = GrUniqueKey::GenerateDomain();
    GrUniqueKey key;
    GrUniqueKey::Builder builder(&key, kDomain, 1);
    builder[0] = profileSize;
    builder.finish();

<<<<<<< HEAD
    GrTexture* blurProfile = textureProvider->findAndRefTextureByUniqueKey(key);

    if (!blurProfile) {
        SkAutoTDeleteArray<uint8_t> profile(SkBlurMask::ComputeBlurProfile(sigma));

        blurProfile = textureProvider->createTexture(texDesc, SkBudgeted::kYes, profile.get(), 0);
        if (blurProfile) {
            textureProvider->assignUniqueKeyToTexture(key, blurProfile);
        }
    }

    return blurProfile;
}

GrRectBlurEffect::GrRectBlurEffect(const SkRect& rect, float sigma, GrTexture* blurProfile,
    GrSLPrecision precision)
    : fRect(rect)
    , fSigma(sigma)
    , fBlurProfileAccess(blurProfile)
    , fPrecision(precision)
{
=======
    uint8_t *profile = NULL;
    SkAutoTDeleteArray<uint8_t> ada(NULL);

    *blurProfileTexture = textureProvider->findAndRefTextureByUniqueKey(key);

    if (NULL == *blurProfileTexture) {

        SkBlurMask::ComputeBlurProfile(sigma, &profile);
        ada.reset(profile);

        *blurProfileTexture = textureProvider->createTexture(texDesc, true, profile, 0);

        if (NULL == *blurProfileTexture) {
            return false;
        }
        textureProvider->assignUniqueKeyToTexture(key, *blurProfileTexture);
    }

    return true;
}

GrRectBlurEffect::GrRectBlurEffect(const SkRect& rect, float sigma,
                                   GrTexture *blur_profile)
  : fRect(rect),
    fSigma(sigma),
    fBlurProfileAccess(blur_profile) {
>>>>>>> miniblink49
    this->initClassID<GrRectBlurEffect>();
    this->addTextureAccess(&fBlurProfileAccess);
    this->setWillReadFragmentPosition();
}

<<<<<<< HEAD
void GrRectBlurEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLRectBlurEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrRectBlurEffect::onCreateGLSLInstance() const
{
    return new GrGLRectBlurEffect;
}

bool GrRectBlurEffect::onIsEqual(const GrFragmentProcessor& sBase) const
{
=======
GrRectBlurEffect::~GrRectBlurEffect() {
}

void GrRectBlurEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                         GrProcessorKeyBuilder* b) const {
    GrGLRectBlurEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrRectBlurEffect::createGLInstance() const {
    return SkNEW_ARGS(GrGLRectBlurEffect, (*this));
}

bool GrRectBlurEffect::onIsEqual(const GrFragmentProcessor& sBase) const {
>>>>>>> miniblink49
    const GrRectBlurEffect& s = sBase.cast<GrRectBlurEffect>();
    return this->getSigma() == s.getSigma() && this->getRect() == s.getRect();
}

<<<<<<< HEAD
void GrRectBlurEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
void GrRectBlurEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    inout->mulByUnknownSingleComponent();
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrRectBlurEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrRectBlurEffect::TestCreate(GrProcessorTestData* d)
{
    float sigma = d->fRandom->nextRangeF(3, 8);
    float width = d->fRandom->nextRangeF(200, 300);
    float height = d->fRandom->nextRangeF(200, 300);
    return GrRectBlurEffect::Make(d->fContext->textureProvider(), SkRect::MakeWH(width, height),
        sigma);
}

bool SkBlurMaskFilterImpl::directFilterMaskGPU(GrTextureProvider* texProvider,
    GrDrawContext* drawContext,
    GrPaint* grp,
    const GrClip& clip,
    const SkMatrix& viewMatrix,
    const SkStrokeRec& strokeRec,
    const SkPath& path) const
{
    SkASSERT(drawContext);

=======
GrFragmentProcessor* GrRectBlurEffect::TestCreate(GrProcessorTestData* d) {
    float sigma = d->fRandom->nextRangeF(3,8);
    float width = d->fRandom->nextRangeF(200,300);
    float height = d->fRandom->nextRangeF(200,300);
    return GrRectBlurEffect::Create(d->fContext->textureProvider(), SkRect::MakeWH(width, height),
                                    sigma);
}


bool SkBlurMaskFilterImpl::directFilterMaskGPU(GrContext* context,
                                               GrRenderTarget* rt,
                                               GrPaint* grp,
                                               const GrClip& clip,
                                               const SkMatrix& viewMatrix,
                                               const SkStrokeRec& strokeRec,
                                               const SkPath& path) const {
>>>>>>> miniblink49
    if (fBlurStyle != kNormal_SkBlurStyle) {
        return false;
    }

<<<<<<< HEAD
    // TODO: we could handle blurred stroked circles
=======
    SkRect rect;
    if (!path.isRect(&rect)) {
        return false;
    }

>>>>>>> miniblink49
    if (!strokeRec.isFillStyle()) {
        return false;
    }

<<<<<<< HEAD
    SkScalar xformedSigma = this->computeXformedSigma(viewMatrix);

    sk_sp<GrFragmentProcessor> fp;

    SkRect rect;
    if (path.isRect(&rect)) {
        int pad = SkScalarCeilToInt(6 * xformedSigma) / 2;
        rect.outset(SkIntToScalar(pad), SkIntToScalar(pad));

        fp = GrRectBlurEffect::Make(texProvider, rect, xformedSigma);
    } else if (path.isOval(&rect) && SkScalarNearlyEqual(rect.width(), rect.height())) {
        fp = GrCircleBlurFragmentProcessor::Make(texProvider, rect, xformedSigma);

        // expand the rect for the coverage geometry
        int pad = SkScalarCeilToInt(6 * xformedSigma) / 2;
        rect.outset(SkIntToScalar(pad), SkIntToScalar(pad));
    } else {
        return false;
    }

=======
    SkMatrix ctm = viewMatrix;
    SkScalar xformedSigma = this->computeXformedSigma(ctm);

    int pad=SkScalarCeilToInt(6*xformedSigma)/2;
    rect.outset(SkIntToScalar(pad), SkIntToScalar(pad));

    SkAutoTUnref<GrFragmentProcessor> fp(GrRectBlurEffect::Create(
        context->textureProvider(), rect, xformedSigma));
>>>>>>> miniblink49
    if (!fp) {
        return false;
    }

<<<<<<< HEAD
    grp->addCoverageFragmentProcessor(std::move(fp));
=======
    grp->addCoverageProcessor(fp);
>>>>>>> miniblink49

    SkMatrix inverse;
    if (!viewMatrix.invert(&inverse)) {
        return false;
    }

<<<<<<< HEAD
    drawContext->fillRectWithLocalMatrix(clip, *grp, SkMatrix::I(), rect, inverse);
    return true;
}

//////////////////////////////////////////////////////////////////////////////

class GrRRectBlurEffect : public GrFragmentProcessor {
public:
    static sk_sp<GrFragmentProcessor> Make(GrTextureProvider*, float sigma, const SkRRect&);
=======
    GrDrawContext* drawContext = context->drawContext();
    if (drawContext) {
        drawContext->drawNonAARectWithLocalMatrix(rt, clip, *grp, SkMatrix::I(), rect, inverse);
        return true;
    }

    return false;
}

class GrRRectBlurEffect : public GrFragmentProcessor {
public:

    static GrFragmentProcessor* Create(GrContext* context, float sigma, const SkRRect&);
>>>>>>> miniblink49

    virtual ~GrRRectBlurEffect() {};
    const char* name() const override { return "GrRRectBlur"; }

    const SkRRect& getRRect() const { return fRRect; }
    float getSigma() const { return fSigma; }

<<<<<<< HEAD
private:
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    GrRRectBlurEffect(float sigma, const SkRRect&, GrTexture* profileTexture);

    virtual void onGetGLSLProcessorKey(const GrGLSLCaps& caps,
        GrProcessorKeyBuilder* b) const override;

=======
    virtual void getGLProcessorKey(const GrGLSLCaps& caps,
                                   GrProcessorKeyBuilder* b) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

private:
    GrRRectBlurEffect(float sigma, const SkRRect&, GrTexture* profileTexture);

>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor& other) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

<<<<<<< HEAD
    SkRRect fRRect;
    float fSigma;
    GrTextureAccess fNinePatchAccess;
=======
    SkRRect             fRRect;
    float               fSigma;
    GrTextureAccess     fNinePatchAccess;
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef GrFragmentProcessor INHERITED;
};

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrRRectBlurEffect::Make(GrTextureProvider* texProvider, float sigma,
    const SkRRect& rrect)
{
    if (rrect.isCircle()) {
        return GrCircleBlurFragmentProcessor::Make(texProvider, rrect.rect(), sigma);
    }

    if (!rrect.isSimpleCircular()) {
        return nullptr;
=======

GrFragmentProcessor* GrRRectBlurEffect::Create(GrContext* context, float sigma,
                                               const SkRRect& rrect) {
    if (!rrect.isSimpleCircular()) {
        return NULL;
>>>>>>> miniblink49
    }

    // Make sure we can successfully ninepatch this rrect -- the blur sigma has to be
    // sufficiently small relative to both the size of the corner radius and the
    // width (and height) of the rrect.

<<<<<<< HEAD
    unsigned int blurRadius = 3 * SkScalarCeilToInt(sigma - 1 / 6.0f);
    unsigned int cornerRadius = SkScalarCeilToInt(rrect.getSimpleRadii().x());
    if (cornerRadius + blurRadius > rrect.width() / 2 || cornerRadius + blurRadius > rrect.height() / 2) {
        return nullptr;
=======
    unsigned int blurRadius = 3*SkScalarCeilToInt(sigma-1/6.0f);
    unsigned int cornerRadius = SkScalarCeilToInt(rrect.getSimpleRadii().x());
    if (cornerRadius + blurRadius > rrect.width()/2 ||
        cornerRadius + blurRadius > rrect.height()/2) {
        return NULL;
>>>>>>> miniblink49
    }

    static const GrUniqueKey::Domain kDomain = GrUniqueKey::GenerateDomain();
    GrUniqueKey key;
    GrUniqueKey::Builder builder(&key, kDomain, 2);
    builder[0] = blurRadius;
    builder[1] = cornerRadius;
    builder.finish();

<<<<<<< HEAD
    SkAutoTUnref<GrTexture> blurNinePatchTexture(texProvider->findAndRefTextureByUniqueKey(key));
=======
    SkAutoTUnref<GrTexture> blurNinePatchTexture(
        context->textureProvider()->findAndRefTextureByUniqueKey(key));
>>>>>>> miniblink49

    if (!blurNinePatchTexture) {
        SkMask mask;

<<<<<<< HEAD
        unsigned int smallRectSide = 2 * (blurRadius + cornerRadius) + 1;
=======
        unsigned int smallRectSide = 2*(blurRadius + cornerRadius) + 1;
>>>>>>> miniblink49

        mask.fBounds = SkIRect::MakeWH(smallRectSide, smallRectSide);
        mask.fFormat = SkMask::kA8_Format;
        mask.fRowBytes = mask.fBounds.width();
        mask.fImage = SkMask::AllocImage(mask.computeTotalImageSize());
        SkAutoMaskFreeImage amfi(mask.fImage);

        memset(mask.fImage, 0, mask.computeTotalImageSize());

        SkRect smallRect;
        smallRect.setWH(SkIntToScalar(smallRectSide), SkIntToScalar(smallRectSide));

        SkRRect smallRRect;
        smallRRect.setRectXY(smallRect, SkIntToScalar(cornerRadius), SkIntToScalar(cornerRadius));

        SkPath path;
<<<<<<< HEAD
        path.addRRect(smallRRect);

        SkDraw::DrawToMask(path, &mask.fBounds, nullptr, nullptr, &mask,
            SkMask::kJustRenderImage_CreateMode, SkStrokeRec::kFill_InitStyle);

        SkMask blurredMask;
        if (!SkBlurMask::BoxBlur(&blurredMask, mask, sigma, kNormal_SkBlurStyle,
                kHigh_SkBlurQuality, nullptr, true)) {
            return nullptr;
        }

        unsigned int texSide = smallRectSide + 2 * blurRadius;
=======
        path.addRRect( smallRRect );

        SkDraw::DrawToMask(path, &mask.fBounds, NULL, NULL, &mask,
                           SkMask::kJustRenderImage_CreateMode, SkPaint::kFill_Style);

        SkMask blurredMask;
        SkBlurMask::BoxBlur(&blurredMask, mask, sigma, kNormal_SkBlurStyle, kHigh_SkBlurQuality,
                            NULL, true );

        unsigned int texSide = smallRectSide + 2*blurRadius;
>>>>>>> miniblink49
        GrSurfaceDesc texDesc;
        texDesc.fWidth = texSide;
        texDesc.fHeight = texSide;
        texDesc.fConfig = kAlpha_8_GrPixelConfig;
<<<<<<< HEAD
        texDesc.fIsMipMapped = false;

        blurNinePatchTexture.reset(
            texProvider->createTexture(texDesc, SkBudgeted::kYes, blurredMask.fImage, 0));
        SkMask::FreeImage(blurredMask.fImage);
        if (!blurNinePatchTexture) {
            return nullptr;
        }
        texProvider->assignUniqueKeyToTexture(key, blurNinePatchTexture);
    }
    return sk_sp<GrFragmentProcessor>(new GrRRectBlurEffect(sigma, rrect, blurNinePatchTexture));
}

void GrRRectBlurEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
    inout->mulByUnknownSingleComponent();
}

GrRRectBlurEffect::GrRRectBlurEffect(float sigma, const SkRRect& rrect, GrTexture* ninePatchTexture)
    : fRRect(rrect)
    , fSigma(sigma)
    , fNinePatchAccess(ninePatchTexture)
{
=======

        blurNinePatchTexture.reset(
            context->textureProvider()->createTexture(texDesc, true, blurredMask.fImage, 0));
        SkMask::FreeImage(blurredMask.fImage);
        if (!blurNinePatchTexture) {
            return NULL;
        }
        context->textureProvider()->assignUniqueKeyToTexture(key, blurNinePatchTexture);
    }
    return SkNEW_ARGS(GrRRectBlurEffect, (sigma, rrect, blurNinePatchTexture));
}

void GrRRectBlurEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
    inout->mulByUnknownSingleComponent();
}

GrRRectBlurEffect::GrRRectBlurEffect(float sigma, const SkRRect& rrect, GrTexture *ninePatchTexture)
    : fRRect(rrect),
      fSigma(sigma),
      fNinePatchAccess(ninePatchTexture) {
>>>>>>> miniblink49
    this->initClassID<GrRRectBlurEffect>();
    this->addTextureAccess(&fNinePatchAccess);
    this->setWillReadFragmentPosition();
}

<<<<<<< HEAD
bool GrRRectBlurEffect::onIsEqual(const GrFragmentProcessor& other) const
{
    const GrRRectBlurEffect& rrbe = other.cast<GrRRectBlurEffect>();
    return fRRect.getSimpleRadii().fX == rrbe.fRRect.getSimpleRadii().fX && fSigma == rrbe.fSigma && fRRect.rect() == rrbe.fRRect.rect();
=======
bool GrRRectBlurEffect::onIsEqual(const GrFragmentProcessor& other) const {
    const GrRRectBlurEffect& rrbe = other.cast<GrRRectBlurEffect>();
    return fRRect.getSimpleRadii().fX == rrbe.fRRect.getSimpleRadii().fX && fSigma == rrbe.fSigma;
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrRRectBlurEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrRRectBlurEffect::TestCreate(GrProcessorTestData* d)
{
    SkScalar w = d->fRandom->nextRangeScalar(100.f, 1000.f);
    SkScalar h = d->fRandom->nextRangeScalar(100.f, 1000.f);
    SkScalar r = d->fRandom->nextRangeF(1.f, 9.f);
    SkScalar sigma = d->fRandom->nextRangeF(1.f, 10.f);
    SkRRect rrect;
    rrect.setRectXY(SkRect::MakeWH(w, h), r, r);
    return GrRRectBlurEffect::Make(d->fContext->textureProvider(), sigma, rrect);
=======
GrFragmentProcessor* GrRRectBlurEffect::TestCreate(GrProcessorTestData* d) {
    SkScalar w = d->fRandom->nextRangeScalar(100.f, 1000.f);
    SkScalar h = d->fRandom->nextRangeScalar(100.f, 1000.f);
    SkScalar r = d->fRandom->nextRangeF(1.f, 9.f);
    SkScalar sigma = d->fRandom->nextRangeF(1.f,10.f);
    SkRRect rrect;
    rrect.setRectXY(SkRect::MakeWH(w, h), r, r);
    return GrRRectBlurEffect::Create(d->fContext, sigma, rrect);
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLRRectBlurEffect : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs&) override;

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLSLProgramDataManager::UniformHandle fProxyRectUniform;
    GrGLSLProgramDataManager::UniformHandle fCornerRadiusUniform;
    GrGLSLProgramDataManager::UniformHandle fBlurRadiusUniform;
    typedef GrGLSLFragmentProcessor INHERITED;
};

void GrGLRRectBlurEffect::emitCode(EmitArgs& args)
{
    const char* rectName;
    const char* cornerRadiusName;
    const char* blurRadiusName;

    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    // The proxy rect has left, top, right, and bottom edges correspond to
    // components x, y, z, and w, respectively.

    fProxyRectUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec4f_GrSLType,
        kDefault_GrSLPrecision,
        "proxyRect",
        &rectName);
    fCornerRadiusUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType,
        kDefault_GrSLPrecision,
        "cornerRadius",
        &cornerRadiusName);
    fBlurRadiusUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType,
        kDefault_GrSLPrecision,
        "blurRadius",
        &blurRadiusName);

    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    const char* fragmentPos = fragBuilder->fragmentPosition();

    // warp the fragment position to the appropriate part of the 9patch blur texture

    fragBuilder->codeAppendf("vec2 rectCenter = (%s.xy + %s.zw)/2.0;", rectName, rectName);
    fragBuilder->codeAppendf("vec2 translatedFragPos = %s.xy - %s.xy;", fragmentPos, rectName);
    fragBuilder->codeAppendf("float threshold = %s + 2.0*%s;", cornerRadiusName, blurRadiusName);
    fragBuilder->codeAppendf("vec2 middle = %s.zw - %s.xy - 2.0*threshold;", rectName, rectName);

    fragBuilder->codeAppendf(
        "if (translatedFragPos.x >= threshold && translatedFragPos.x < (middle.x+threshold)) {");
    fragBuilder->codeAppendf("translatedFragPos.x = threshold;\n");
    fragBuilder->codeAppendf("} else if (translatedFragPos.x >= (middle.x + threshold)) {");
    fragBuilder->codeAppendf("translatedFragPos.x -= middle.x - 1.0;");
    fragBuilder->codeAppendf("}");

    fragBuilder->codeAppendf(
        "if (translatedFragPos.y > threshold && translatedFragPos.y < (middle.y+threshold)) {");
    fragBuilder->codeAppendf("translatedFragPos.y = threshold;");
    fragBuilder->codeAppendf("} else if (translatedFragPos.y >= (middle.y + threshold)) {");
    fragBuilder->codeAppendf("translatedFragPos.y -= middle.y - 1.0;");
    fragBuilder->codeAppendf("}");

    fragBuilder->codeAppendf("vec2 proxyDims = vec2(2.0*threshold+1.0);");
    fragBuilder->codeAppendf("vec2 texCoord = translatedFragPos / proxyDims;");

    fragBuilder->codeAppendf("%s = ", args.fOutputColor);
    fragBuilder->appendTextureLookupAndModulate(args.fInputColor, args.fTexSamplers[0], "texCoord");
    fragBuilder->codeAppend(";");
}

void GrGLRRectBlurEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& proc)
{
    const GrRRectBlurEffect& brre = proc.cast<GrRRectBlurEffect>();
    const SkRRect& rrect = brre.getRRect();

    float blurRadius = 3.f * SkScalarCeilToScalar(brre.getSigma() - 1 / 6.0f);
=======
class GrGLRRectBlurEffect : public GrGLFragmentProcessor {
public:
    GrGLRRectBlurEffect(const GrProcessor&) {}

    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLProgramDataManager::UniformHandle fProxyRectUniform;
    GrGLProgramDataManager::UniformHandle fCornerRadiusUniform;
    GrGLProgramDataManager::UniformHandle fBlurRadiusUniform;
    typedef GrGLFragmentProcessor INHERITED;
};

void GrGLRRectBlurEffect::emitCode(GrGLFPBuilder* builder,
                                   const GrFragmentProcessor&,
                                   const char* outputColor,
                                   const char* inputColor,
                                   const TransformedCoordsArray&,
                                   const TextureSamplerArray& samplers) {
    const char *rectName;
    const char *cornerRadiusName;
    const char *blurRadiusName;

    // The proxy rect has left, top, right, and bottom edges correspond to
    // components x, y, z, and w, respectively.

    fProxyRectUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                            kVec4f_GrSLType,
                                            kDefault_GrSLPrecision,
                                            "proxyRect",
                                            &rectName);
    fCornerRadiusUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                               kFloat_GrSLType,
                                               kDefault_GrSLPrecision,
                                               "cornerRadius",
                                               &cornerRadiusName);
    fBlurRadiusUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                             kFloat_GrSLType,
                                              kDefault_GrSLPrecision,
                                              "blurRadius",
                                              &blurRadiusName);

    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    const char* fragmentPos = fsBuilder->fragmentPosition();

    // warp the fragment position to the appropriate part of the 9patch blur texture

    fsBuilder->codeAppendf("\t\tvec2 rectCenter = (%s.xy + %s.zw)/2.0;\n", rectName, rectName);
    fsBuilder->codeAppendf("\t\tvec2 translatedFragPos = %s.xy - %s.xy;\n", fragmentPos, rectName);
    fsBuilder->codeAppendf("\t\tfloat threshold = %s + 2.0*%s;\n", cornerRadiusName, blurRadiusName );
    fsBuilder->codeAppendf("\t\tvec2 middle = %s.zw - %s.xy - 2.0*threshold;\n", rectName, rectName );

    fsBuilder->codeAppendf("\t\tif (translatedFragPos.x >= threshold && translatedFragPos.x < (middle.x+threshold)) {\n" );
    fsBuilder->codeAppendf("\t\t\ttranslatedFragPos.x = threshold;\n");
    fsBuilder->codeAppendf("\t\t} else if (translatedFragPos.x >= (middle.x + threshold)) {\n");
    fsBuilder->codeAppendf("\t\t\ttranslatedFragPos.x -= middle.x - 1.0;\n");
    fsBuilder->codeAppendf("\t\t}\n");

    fsBuilder->codeAppendf("\t\tif (translatedFragPos.y > threshold && translatedFragPos.y < (middle.y+threshold)) {\n" );
    fsBuilder->codeAppendf("\t\t\ttranslatedFragPos.y = threshold;\n");
    fsBuilder->codeAppendf("\t\t} else if (translatedFragPos.y >= (middle.y + threshold)) {\n");
    fsBuilder->codeAppendf("\t\t\ttranslatedFragPos.y -= middle.y - 1.0;\n");
    fsBuilder->codeAppendf("\t\t}\n");

    fsBuilder->codeAppendf("\t\tvec2 proxyDims = vec2(2.0*threshold+1.0);\n");
    fsBuilder->codeAppendf("\t\tvec2 texCoord = translatedFragPos / proxyDims;\n");

    fsBuilder->codeAppendf("\t%s = ", outputColor);
    fsBuilder->appendTextureLookupAndModulate(inputColor, samplers[0], "texCoord");
    fsBuilder->codeAppend(";\n");
}

void GrGLRRectBlurEffect::setData(const GrGLProgramDataManager& pdman,
                                  const GrProcessor& proc) {
    const GrRRectBlurEffect& brre = proc.cast<GrRRectBlurEffect>();
    SkRRect rrect = brre.getRRect();

    float blurRadius = 3.f*SkScalarCeilToScalar(brre.getSigma()-1/6.0f);
>>>>>>> miniblink49
    pdman.set1f(fBlurRadiusUniform, blurRadius);

    SkRect rect = rrect.getBounds();
    rect.outset(blurRadius, blurRadius);
    pdman.set4f(fProxyRectUniform, rect.fLeft, rect.fTop, rect.fRight, rect.fBottom);

    SkScalar radius = 0;
    SkASSERT(rrect.isSimpleCircular() || rrect.isRect());
    radius = rrect.getSimpleRadii().fX;
    pdman.set1f(fCornerRadiusUniform, radius);
}

<<<<<<< HEAD
void GrRRectBlurEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLRRectBlurEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrRRectBlurEffect::onCreateGLSLInstance() const
{
    return new GrGLRRectBlurEffect;
}

bool SkBlurMaskFilterImpl::directFilterRRectMaskGPU(GrTextureProvider* texProvider,
    GrDrawContext* drawContext,
    GrPaint* grp,
    const GrClip& clip,
    const SkMatrix& viewMatrix,
    const SkStrokeRec& strokeRec,
    const SkRRect& rrect) const
{
    SkASSERT(drawContext);

=======
void GrRRectBlurEffect::getGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const {
    GrGLRRectBlurEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrRRectBlurEffect::createGLInstance() const {
    return SkNEW_ARGS(GrGLRRectBlurEffect, (*this));
}

bool SkBlurMaskFilterImpl::directFilterRRectMaskGPU(GrContext* context,
                                                    GrRenderTarget* rt,
                                                    GrPaint* grp,
                                                    const GrClip& clip,
                                                    const SkMatrix& viewMatrix,
                                                    const SkStrokeRec& strokeRec,
                                                    const SkRRect& rrect) const {
>>>>>>> miniblink49
    if (fBlurStyle != kNormal_SkBlurStyle) {
        return false;
    }

    if (!strokeRec.isFillStyle()) {
        return false;
    }

<<<<<<< HEAD
    SkScalar xformedSigma = this->computeXformedSigma(viewMatrix);
    float extra = 3.f * SkScalarCeilToScalar(xformedSigma - 1 / 6.0f);

    SkRect proxyRect = rrect.rect();
    proxyRect.outset(extra, extra);

    sk_sp<GrFragmentProcessor> fp(GrRRectBlurEffect::Make(texProvider, xformedSigma, rrect));
=======
    SkRect proxy_rect = rrect.rect();
    SkMatrix ctm = viewMatrix;
    SkScalar xformedSigma = this->computeXformedSigma(ctm);
    float extra=3.f*SkScalarCeilToScalar(xformedSigma-1/6.0f);
    proxy_rect.outset(extra, extra);

    SkAutoTUnref<GrFragmentProcessor> fp(GrRRectBlurEffect::Create(context, xformedSigma, rrect));
>>>>>>> miniblink49
    if (!fp) {
        return false;
    }

<<<<<<< HEAD
    grp->addCoverageFragmentProcessor(std::move(fp));
=======
    grp->addCoverageProcessor(fp);
>>>>>>> miniblink49

    SkMatrix inverse;
    if (!viewMatrix.invert(&inverse)) {
        return false;
    }

<<<<<<< HEAD
    drawContext->fillRectWithLocalMatrix(clip, *grp, SkMatrix::I(), proxyRect, inverse);
    return true;
}

bool SkBlurMaskFilterImpl::canFilterMaskGPU(const SkRRect& devRRect,
    const SkIRect& clipBounds,
    const SkMatrix& ctm,
    SkRect* maskRect) const
{
=======
    GrDrawContext* drawContext = context->drawContext();
    if (drawContext) {
        drawContext->drawNonAARectWithLocalMatrix(rt, clip, *grp, SkMatrix::I(),
                                                  proxy_rect, inverse);
        return true;
    }

    return false;
}

bool SkBlurMaskFilterImpl::canFilterMaskGPU(const SkRect& srcBounds,
                                            const SkIRect& clipBounds,
                                            const SkMatrix& ctm,
                                            SkRect* maskRect) const {
>>>>>>> miniblink49
    SkScalar xformedSigma = this->computeXformedSigma(ctm);
    if (xformedSigma <= 0) {
        return false;
    }

<<<<<<< HEAD
    // We always do circles on the GPU
    if (!devRRect.isCircle()) {
        static const SkScalar kMIN_GPU_BLUR_SIZE = SkIntToScalar(64);
        static const SkScalar kMIN_GPU_BLUR_SIGMA = SkIntToScalar(32);

        if (devRRect.width() <= kMIN_GPU_BLUR_SIZE && devRRect.height() <= kMIN_GPU_BLUR_SIZE && xformedSigma <= kMIN_GPU_BLUR_SIGMA) {
            // We prefer to blur small rects with small radii on the CPU.
            return false;
        }
    }

    if (nullptr == maskRect) {
=======
    static const SkScalar kMIN_GPU_BLUR_SIZE  = SkIntToScalar(64);
    static const SkScalar kMIN_GPU_BLUR_SIGMA = SkIntToScalar(32);

    if (srcBounds.width() <= kMIN_GPU_BLUR_SIZE &&
        srcBounds.height() <= kMIN_GPU_BLUR_SIZE &&
        xformedSigma <= kMIN_GPU_BLUR_SIGMA) {
        // We prefer to blur small rect with small radius via CPU.
        return false;
    }

    if (NULL == maskRect) {
>>>>>>> miniblink49
        // don't need to compute maskRect
        return true;
    }

    float sigma3 = 3 * SkScalarToFloat(xformedSigma);

    SkRect clipRect = SkRect::Make(clipBounds);
<<<<<<< HEAD
    SkRect srcRect(devRRect.rect());
=======
    SkRect srcRect(srcBounds);
>>>>>>> miniblink49

    // Outset srcRect and clipRect by 3 * sigma, to compute affected blur area.
    srcRect.outset(sigma3, sigma3);
    clipRect.outset(sigma3, sigma3);
    if (!srcRect.intersect(clipRect)) {
        srcRect.setEmpty();
    }
    *maskRect = srcRect;
    return true;
}

bool SkBlurMaskFilterImpl::filterMaskGPU(GrTexture* src,
<<<<<<< HEAD
    const SkMatrix& ctm,
    const SkIRect& maskRect,
    GrTexture** result) const
{
    // 'maskRect' isn't snapped to the UL corner but the mask in 'src' is.
    const SkIRect clipRect = SkIRect::MakeWH(maskRect.width(), maskRect.height());
=======
                                         const SkMatrix& ctm,
                                         const SkRect& maskRect,
                                         GrTexture** result,
                                         bool canOverwriteSrc) const {
    SkRect clipRect = SkRect::MakeWH(maskRect.width(), maskRect.height());
>>>>>>> miniblink49

    GrContext* context = src->getContext();

    SkScalar xformedSigma = this->computeXformedSigma(ctm);
    SkASSERT(xformedSigma > 0);

    // If we're doing a normal blur, we can clobber the pathTexture in the
    // gaussianBlur.  Otherwise, we need to save it for later compositing.
<<<<<<< HEAD
    static const bool kIsGammaCorrect = false;
    bool isNormalBlur = (kNormal_SkBlurStyle == fBlurStyle);
    sk_sp<GrDrawContext> drawContext(SkGpuBlurUtils::GaussianBlur(context, src,
        kIsGammaCorrect,
        clipRect, nullptr,
        xformedSigma, xformedSigma));
    if (!drawContext) {
=======
    bool isNormalBlur = (kNormal_SkBlurStyle == fBlurStyle);
    *result = SkGpuBlurUtils::GaussianBlur(context, src, isNormalBlur && canOverwriteSrc,
                                           clipRect, false, xformedSigma, xformedSigma);
    if (NULL == *result) {
>>>>>>> miniblink49
        return false;
    }

    if (!isNormalBlur) {
        GrPaint paint;
        SkMatrix matrix;
        matrix.setIDiv(src->width(), src->height());
        // Blend pathTexture over blurTexture.
<<<<<<< HEAD
        paint.addCoverageFragmentProcessor(GrSimpleTextureEffect::Make(src, matrix));
=======
        paint.addCoverageProcessor(GrSimpleTextureEffect::Create(paint.getProcessorDataManager(),
                                                                 src, matrix))->unref();
>>>>>>> miniblink49
        if (kInner_SkBlurStyle == fBlurStyle) {
            // inner:  dst = dst * src
            paint.setCoverageSetOpXPFactory(SkRegion::kIntersect_Op);
        } else if (kSolid_SkBlurStyle == fBlurStyle) {
            // solid:  dst = src + dst - src * dst
            //             = src + (1 - src) * dst
            paint.setCoverageSetOpXPFactory(SkRegion::kUnion_Op);
        } else if (kOuter_SkBlurStyle == fBlurStyle) {
            // outer:  dst = dst * (1 - src)
            //             = 0 * src + (1 - src) * dst
            paint.setCoverageSetOpXPFactory(SkRegion::kDifference_Op);
<<<<<<< HEAD
        } else {
            paint.setCoverageSetOpXPFactory(SkRegion::kReplace_Op);
        }

        drawContext->drawRect(GrNoClip(), paint, SkMatrix::I(), SkRect::Make(clipRect));
    }

    *result = drawContext->asTexture().release();
=======
        }

        GrDrawContext* drawContext = context->drawContext();
        if (!drawContext) {
            return false;
        }

        drawContext->drawRect((*result)->asRenderTarget(), GrClip::WideOpen(),
                              paint, SkMatrix::I(), clipRect);
    }

>>>>>>> miniblink49
    return true;
}

#endif // SK_SUPPORT_GPU

<<<<<<< HEAD
#ifndef SK_IGNORE_TO_STRING
void SkBlurMaskFilterImpl::toString(SkString* str) const
{
=======

#ifndef SK_IGNORE_TO_STRING
void SkBlurMaskFilterImpl::toString(SkString* str) const {
>>>>>>> miniblink49
    str->append("SkBlurMaskFilterImpl: (");

    str->append("sigma: ");
    str->appendScalar(fSigma);
    str->append(" ");

    static const char* gStyleName[kLastEnum_SkBlurStyle + 1] = {
        "normal", "solid", "outer", "inner"
    };

    str->appendf("style: %s ", gStyleName[fBlurStyle]);
    str->append("flags: (");
    if (fBlurFlags) {
        bool needSeparator = false;
        SkAddFlagToString(str,
<<<<<<< HEAD
            SkToBool(fBlurFlags & SkBlurMaskFilter::kIgnoreTransform_BlurFlag),
            "IgnoreXform", &needSeparator);
        SkAddFlagToString(str,
            SkToBool(fBlurFlags & SkBlurMaskFilter::kHighQuality_BlurFlag),
            "HighQuality", &needSeparator);
=======
                          SkToBool(fBlurFlags & SkBlurMaskFilter::kIgnoreTransform_BlurFlag),
                          "IgnoreXform", &needSeparator);
        SkAddFlagToString(str,
                          SkToBool(fBlurFlags & SkBlurMaskFilter::kHighQuality_BlurFlag),
                          "HighQuality", &needSeparator);
>>>>>>> miniblink49
    } else {
        str->append("None");
    }
    str->append("))");
}
#endif

SK_DEFINE_FLATTENABLE_REGISTRAR_GROUP_START(SkBlurMaskFilter)
<<<<<<< HEAD
SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkBlurMaskFilterImpl)
=======
    SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkBlurMaskFilterImpl)
>>>>>>> miniblink49
SK_DEFINE_FLATTENABLE_REGISTRAR_GROUP_END
