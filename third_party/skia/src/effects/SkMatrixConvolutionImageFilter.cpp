/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrixConvolutionImageFilter.h"
#include "SkBitmap.h"
#include "SkColorPriv.h"
#include "SkReadBuffer.h"
<<<<<<< HEAD
#include "SkRect.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkUnPreMultiply.h"
#include "SkWriteBuffer.h"

#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrDrawContext.h"
=======
#include "SkWriteBuffer.h"
#include "SkRect.h"
#include "SkUnPreMultiply.h"

#if SK_SUPPORT_GPU
>>>>>>> miniblink49
#include "effects/GrMatrixConvolutionEffect.h"
#endif

// We need to be able to read at most SK_MaxS32 bytes, so divide that
// by the size of a scalar to know how many scalars we can read.
static const int32_t gMaxKernelSize = SK_MaxS32 / sizeof(SkScalar);

<<<<<<< HEAD
SkMatrixConvolutionImageFilter::SkMatrixConvolutionImageFilter(const SkISize& kernelSize,
=======
SkMatrixConvolutionImageFilter::SkMatrixConvolutionImageFilter(
    const SkISize& kernelSize,
>>>>>>> miniblink49
    const SkScalar* kernel,
    SkScalar gain,
    SkScalar bias,
    const SkIPoint& kernelOffset,
    TileMode tileMode,
    bool convolveAlpha,
<<<<<<< HEAD
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
    : INHERITED(&input, 1, cropRect)
    , fKernelSize(kernelSize)
    , fGain(gain)
    , fBias(bias)
    , fKernelOffset(kernelOffset)
    , fTileMode(tileMode)
    , fConvolveAlpha(convolveAlpha)
{
    size_t size = (size_t)sk_64_mul(fKernelSize.width(), fKernelSize.height());
    fKernel = new SkScalar[size];
=======
    SkImageFilter* input,
    const CropRect* cropRect)
  : INHERITED(1, &input, cropRect),
    fKernelSize(kernelSize),
    fGain(gain),
    fBias(bias),
    fKernelOffset(kernelOffset),
    fTileMode(tileMode),
    fConvolveAlpha(convolveAlpha) {
    size_t size = (size_t) sk_64_mul(fKernelSize.width(), fKernelSize.height());
    fKernel = SkNEW_ARRAY(SkScalar, size);
>>>>>>> miniblink49
    memcpy(fKernel, kernel, size * sizeof(SkScalar));
    SkASSERT(kernelSize.fWidth >= 1 && kernelSize.fHeight >= 1);
    SkASSERT(kernelOffset.fX >= 0 && kernelOffset.fX < kernelSize.fWidth);
    SkASSERT(kernelOffset.fY >= 0 && kernelOffset.fY < kernelSize.fHeight);
}

<<<<<<< HEAD
sk_sp<SkImageFilter> SkMatrixConvolutionImageFilter::Make(const SkISize& kernelSize,
=======
SkMatrixConvolutionImageFilter* SkMatrixConvolutionImageFilter::Create(
    const SkISize& kernelSize,
>>>>>>> miniblink49
    const SkScalar* kernel,
    SkScalar gain,
    SkScalar bias,
    const SkIPoint& kernelOffset,
    TileMode tileMode,
    bool convolveAlpha,
<<<<<<< HEAD
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (kernelSize.width() < 1 || kernelSize.height() < 1) {
        return nullptr;
    }
    if (gMaxKernelSize / kernelSize.fWidth < kernelSize.fHeight) {
        return nullptr;
    }
    if (!kernel) {
        return nullptr;
    }
    if ((kernelOffset.fX < 0) || (kernelOffset.fX >= kernelSize.fWidth) || (kernelOffset.fY < 0) || (kernelOffset.fY >= kernelSize.fHeight)) {
        return nullptr;
    }
    return sk_sp<SkImageFilter>(new SkMatrixConvolutionImageFilter(kernelSize, kernel, gain,
        bias, kernelOffset,
        tileMode, convolveAlpha,
        std::move(input), cropRect));
}

sk_sp<SkFlattenable> SkMatrixConvolutionImageFilter::CreateProc(SkReadBuffer& buffer)
{
=======
    SkImageFilter* input,
    const CropRect* cropRect) {
    if (kernelSize.width() < 1 || kernelSize.height() < 1) {
        return NULL;
    }
    if (gMaxKernelSize / kernelSize.fWidth < kernelSize.fHeight) {
        return NULL;
    }
    if (!kernel) {
        return NULL;
    }
    if ((kernelOffset.fX < 0) || (kernelOffset.fX >= kernelSize.fWidth) ||
        (kernelOffset.fY < 0) || (kernelOffset.fY >= kernelSize.fHeight)) {
        return NULL;
    }
    return SkNEW_ARGS(SkMatrixConvolutionImageFilter, (kernelSize, kernel, gain, bias,
                                                       kernelOffset, tileMode, convolveAlpha,
                                                       input, cropRect));
}

SkFlattenable* SkMatrixConvolutionImageFilter::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkISize kernelSize;
    kernelSize.fWidth = buffer.readInt();
    kernelSize.fHeight = buffer.readInt();
    const int count = buffer.getArrayCount();

    const int64_t kernelArea = sk_64_mul(kernelSize.width(), kernelSize.height());
    if (!buffer.validate(kernelArea == count)) {
<<<<<<< HEAD
        return nullptr;
    }
    SkAutoSTArray<16, SkScalar> kernel(count);
    if (!buffer.readScalarArray(kernel.get(), count)) {
        return nullptr;
=======
        return NULL;
    }
    SkAutoSTArray<16, SkScalar> kernel(count);
    if (!buffer.readScalarArray(kernel.get(), count)) {
        return NULL;
>>>>>>> miniblink49
    }
    SkScalar gain = buffer.readScalar();
    SkScalar bias = buffer.readScalar();
    SkIPoint kernelOffset;
    kernelOffset.fX = buffer.readInt();
    kernelOffset.fY = buffer.readInt();
    TileMode tileMode = (TileMode)buffer.readInt();
    bool convolveAlpha = buffer.readBool();
<<<<<<< HEAD
    return Make(kernelSize, kernel.get(), gain, bias, kernelOffset, tileMode,
        convolveAlpha, common.getInput(0), &common.cropRect());
}

void SkMatrixConvolutionImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
    return Create(kernelSize, kernel.get(), gain, bias, kernelOffset, tileMode, convolveAlpha,
                  common.getInput(0), &common.cropRect());
}

void SkMatrixConvolutionImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeInt(fKernelSize.fWidth);
    buffer.writeInt(fKernelSize.fHeight);
    buffer.writeScalarArray(fKernel, fKernelSize.fWidth * fKernelSize.fHeight);
    buffer.writeScalar(fGain);
    buffer.writeScalar(fBias);
    buffer.writeInt(fKernelOffset.fX);
    buffer.writeInt(fKernelOffset.fY);
<<<<<<< HEAD
    buffer.writeInt((int)fTileMode);
    buffer.writeBool(fConvolveAlpha);
}

SkMatrixConvolutionImageFilter::~SkMatrixConvolutionImageFilter()
{
=======
    buffer.writeInt((int) fTileMode);
    buffer.writeBool(fConvolveAlpha);
}

SkMatrixConvolutionImageFilter::~SkMatrixConvolutionImageFilter() {
>>>>>>> miniblink49
    delete[] fKernel;
}

class UncheckedPixelFetcher {
public:
<<<<<<< HEAD
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds)
    {
=======
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds) {
>>>>>>> miniblink49
        return *src.getAddr32(x, y);
    }
};

class ClampPixelFetcher {
public:
<<<<<<< HEAD
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds)
    {
        x = SkTPin(x, bounds.fLeft, bounds.fRight - 1);
        y = SkTPin(y, bounds.fTop, bounds.fBottom - 1);
=======
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds) {
        x = SkPin32(x, bounds.fLeft, bounds.fRight - 1);
        y = SkPin32(y, bounds.fTop, bounds.fBottom - 1);
>>>>>>> miniblink49
        return *src.getAddr32(x, y);
    }
};

class RepeatPixelFetcher {
public:
<<<<<<< HEAD
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds)
    {
=======
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds) {
>>>>>>> miniblink49
        x = (x - bounds.left()) % bounds.width() + bounds.left();
        y = (y - bounds.top()) % bounds.height() + bounds.top();
        if (x < bounds.left()) {
            x += bounds.width();
        }
        if (y < bounds.top()) {
            y += bounds.height();
        }
        return *src.getAddr32(x, y);
    }
};

class ClampToBlackPixelFetcher {
public:
<<<<<<< HEAD
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds)
    {
=======
    static inline SkPMColor fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds) {
>>>>>>> miniblink49
        if (x < bounds.fLeft || x >= bounds.fRight || y < bounds.fTop || y >= bounds.fBottom) {
            return 0;
        } else {
            return *src.getAddr32(x, y);
        }
    }
};

<<<<<<< HEAD
template <class PixelFetcher, bool convolveAlpha>
void SkMatrixConvolutionImageFilter::filterPixels(const SkBitmap& src,
    SkBitmap* result,
    const SkIRect& r,
    const SkIRect& bounds) const
{
=======
template<class PixelFetcher, bool convolveAlpha>
void SkMatrixConvolutionImageFilter::filterPixels(const SkBitmap& src,
                                                  SkBitmap* result,
                                                  const SkIRect& r,
                                                  const SkIRect& bounds) const {
>>>>>>> miniblink49
    SkIRect rect(r);
    if (!rect.intersect(bounds)) {
        return;
    }
    for (int y = rect.fTop; y < rect.fBottom; ++y) {
        SkPMColor* dptr = result->getAddr32(rect.fLeft - bounds.fLeft, y - bounds.fTop);
        for (int x = rect.fLeft; x < rect.fRight; ++x) {
            SkScalar sumA = 0, sumR = 0, sumG = 0, sumB = 0;
            for (int cy = 0; cy < fKernelSize.fHeight; cy++) {
                for (int cx = 0; cx < fKernelSize.fWidth; cx++) {
                    SkPMColor s = PixelFetcher::fetch(src,
<<<<<<< HEAD
                        x + cx - fKernelOffset.fX,
                        y + cy - fKernelOffset.fY,
                        bounds);
=======
                                                      x + cx - fKernelOffset.fX,
                                                      y + cy - fKernelOffset.fY,
                                                      bounds);
>>>>>>> miniblink49
                    SkScalar k = fKernel[cy * fKernelSize.fWidth + cx];
                    if (convolveAlpha) {
                        sumA += SkScalarMul(SkIntToScalar(SkGetPackedA32(s)), k);
                    }
                    sumR += SkScalarMul(SkIntToScalar(SkGetPackedR32(s)), k);
                    sumG += SkScalarMul(SkIntToScalar(SkGetPackedG32(s)), k);
                    sumB += SkScalarMul(SkIntToScalar(SkGetPackedB32(s)), k);
                }
            }
            int a = convolveAlpha
<<<<<<< HEAD
                ? SkClampMax(SkScalarFloorToInt(SkScalarMul(sumA, fGain) + fBias), 255)
                : 255;
=======
                  ? SkClampMax(SkScalarFloorToInt(SkScalarMul(sumA, fGain) + fBias), 255)
                  : 255;
>>>>>>> miniblink49
            int r = SkClampMax(SkScalarFloorToInt(SkScalarMul(sumR, fGain) + fBias), a);
            int g = SkClampMax(SkScalarFloorToInt(SkScalarMul(sumG, fGain) + fBias), a);
            int b = SkClampMax(SkScalarFloorToInt(SkScalarMul(sumB, fGain) + fBias), a);
            if (!convolveAlpha) {
                a = SkGetPackedA32(PixelFetcher::fetch(src, x, y, bounds));
                *dptr++ = SkPreMultiplyARGB(a, r, g, b);
            } else {
                *dptr++ = SkPackARGB32(a, r, g, b);
            }
        }
    }
}

<<<<<<< HEAD
template <class PixelFetcher>
void SkMatrixConvolutionImageFilter::filterPixels(const SkBitmap& src,
    SkBitmap* result,
    const SkIRect& rect,
    const SkIRect& bounds) const
{
=======
template<class PixelFetcher>
void SkMatrixConvolutionImageFilter::filterPixels(const SkBitmap& src,
                                                  SkBitmap* result,
                                                  const SkIRect& rect,
                                                  const SkIRect& bounds) const {
>>>>>>> miniblink49
    if (fConvolveAlpha) {
        filterPixels<PixelFetcher, true>(src, result, rect, bounds);
    } else {
        filterPixels<PixelFetcher, false>(src, result, rect, bounds);
    }
}

void SkMatrixConvolutionImageFilter::filterInteriorPixels(const SkBitmap& src,
<<<<<<< HEAD
    SkBitmap* result,
    const SkIRect& rect,
    const SkIRect& bounds) const
{
=======
                                                          SkBitmap* result,
                                                          const SkIRect& rect,
                                                          const SkIRect& bounds) const {
>>>>>>> miniblink49
    filterPixels<UncheckedPixelFetcher>(src, result, rect, bounds);
}

void SkMatrixConvolutionImageFilter::filterBorderPixels(const SkBitmap& src,
<<<<<<< HEAD
    SkBitmap* result,
    const SkIRect& rect,
    const SkIRect& bounds) const
{
    switch (fTileMode) {
    case kClamp_TileMode:
        filterPixels<ClampPixelFetcher>(src, result, rect, bounds);
        break;
    case kRepeat_TileMode:
        filterPixels<RepeatPixelFetcher>(src, result, rect, bounds);
        break;
    case kClampToBlack_TileMode:
        filterPixels<ClampToBlackPixelFetcher>(src, result, rect, bounds);
        break;
=======
                                                        SkBitmap* result,
                                                        const SkIRect& rect,
                                                        const SkIRect& bounds) const {
    switch (fTileMode) {
        case kClamp_TileMode:
            filterPixels<ClampPixelFetcher>(src, result, rect, bounds);
            break;
        case kRepeat_TileMode:
            filterPixels<RepeatPixelFetcher>(src, result, rect, bounds);
            break;
        case kClampToBlack_TileMode:
            filterPixels<ClampToBlackPixelFetcher>(src, result, rect, bounds);
            break;
>>>>>>> miniblink49
    }
}

// FIXME:  This should be refactored to SkImageFilterUtils for
// use by other filters.  For now, we assume the input is always
// premultiplied and unpremultiply it
<<<<<<< HEAD
static SkBitmap unpremultiply_bitmap(const SkBitmap& src)
=======
static SkBitmap unpremultiplyBitmap(const SkBitmap& src)
>>>>>>> miniblink49
{
    SkAutoLockPixels alp(src);
    if (!src.getPixels()) {
        return SkBitmap();
    }
<<<<<<< HEAD

    const SkImageInfo info = SkImageInfo::MakeN32(src.width(), src.height(), src.alphaType());
    SkBitmap result;
    if (!result.tryAllocPixels(info)) {
        return SkBitmap();
    }
    SkAutoLockPixels resultLock(result);
=======
    SkBitmap result;
    if (!result.tryAllocPixels(src.info())) {
        return SkBitmap();
    }
>>>>>>> miniblink49
    for (int y = 0; y < src.height(); ++y) {
        const uint32_t* srcRow = src.getAddr32(0, y);
        uint32_t* dstRow = result.getAddr32(0, y);
        for (int x = 0; x < src.width(); ++x) {
            dstRow[x] = SkUnPreMultiply::PMColorToColor(srcRow[x]);
        }
    }
    return result;
}

<<<<<<< HEAD
#if SK_SUPPORT_GPU

static GrTextureDomain::Mode convert_tilemodes(SkMatrixConvolutionImageFilter::TileMode tileMode)
{
    switch (tileMode) {
    case SkMatrixConvolutionImageFilter::kClamp_TileMode:
        return GrTextureDomain::kClamp_Mode;
    case SkMatrixConvolutionImageFilter::kRepeat_TileMode:
        return GrTextureDomain::kRepeat_Mode;
    case SkMatrixConvolutionImageFilter::kClampToBlack_TileMode:
        return GrTextureDomain::kDecal_Mode;
    default:
        SkASSERT(false);
=======
bool SkMatrixConvolutionImageFilter::onFilterImage(Proxy* proxy,
                                                   const SkBitmap& source,
                                                   const Context& ctx,
                                                   SkBitmap* result,
                                                   SkIPoint* offset) const {
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (getInput(0) && !getInput(0)->filterImage(proxy, source, ctx, &src, &srcOffset)) {
        return false;
    }

    if (src.colorType() != kN32_SkColorType) {
        return false;
    }

    SkIRect bounds;
    if (!this->applyCropRect(ctx, proxy, src, &srcOffset, &bounds, &src)) {
        return false;
    }

    if (!fConvolveAlpha && !src.isOpaque()) {
        src = unpremultiplyBitmap(src);
    }

    SkAutoLockPixels alp(src);
    if (!src.getPixels()) {
        return false;
    }

    if (!result->tryAllocPixels(src.info().makeWH(bounds.width(), bounds.height()))) {
        return false;
    }

    offset->fX = bounds.fLeft;
    offset->fY = bounds.fTop;
    bounds.offset(-srcOffset);
    SkIRect interior = SkIRect::MakeXYWH(bounds.left() + fKernelOffset.fX,
                                         bounds.top() + fKernelOffset.fY,
                                         bounds.width() - fKernelSize.fWidth + 1,
                                         bounds.height() - fKernelSize.fHeight + 1);
    SkIRect top = SkIRect::MakeLTRB(bounds.left(), bounds.top(), bounds.right(), interior.top());
    SkIRect bottom = SkIRect::MakeLTRB(bounds.left(), interior.bottom(),
                                       bounds.right(), bounds.bottom());
    SkIRect left = SkIRect::MakeLTRB(bounds.left(), interior.top(),
                                     interior.left(), interior.bottom());
    SkIRect right = SkIRect::MakeLTRB(interior.right(), interior.top(),
                                      bounds.right(), interior.bottom());
    filterBorderPixels(src, result, top, bounds);
    filterBorderPixels(src, result, left, bounds);
    filterInteriorPixels(src, result, interior, bounds);
    filterBorderPixels(src, result, right, bounds);
    filterBorderPixels(src, result, bottom, bounds);
    return true;
}

bool SkMatrixConvolutionImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix& ctm,
                                                    SkIRect* dst) const {
    SkIRect bounds = src;
    bounds.fRight += fKernelSize.width() - 1;
    bounds.fBottom += fKernelSize.height() - 1;
    bounds.offset(-fKernelOffset);
    if (getInput(0) && !getInput(0)->filterBounds(bounds, ctm, &bounds)) {
        return false;
    }
    *dst = bounds;
    return true;
}

#if SK_SUPPORT_GPU

static GrTextureDomain::Mode convert_tilemodes(
        SkMatrixConvolutionImageFilter::TileMode tileMode) {
    switch (tileMode) {
        case SkMatrixConvolutionImageFilter::kClamp_TileMode:
            return GrTextureDomain::kClamp_Mode;
        case SkMatrixConvolutionImageFilter::kRepeat_TileMode:
            return GrTextureDomain::kRepeat_Mode;
        case SkMatrixConvolutionImageFilter::kClampToBlack_TileMode:
            return GrTextureDomain::kDecal_Mode;
        default:
            SkASSERT(false);
>>>>>>> miniblink49
    }
    return GrTextureDomain::kIgnore_Mode;
}

<<<<<<< HEAD
#endif

sk_sp<SkSpecialImage> SkMatrixConvolutionImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));
    if (!input) {
        return nullptr;
    }

    SkIRect bounds;
    input = this->applyCropRect(this->mapContext(ctx), input.get(), &inputOffset, &bounds);
    if (!input) {
        return nullptr;
    }

#if SK_SUPPORT_GPU
    // Note: if the kernel is too big, the GPU path falls back to SW
    if (source->isTextureBacked() && fKernelSize.width() * fKernelSize.height() <= MAX_KERNEL_SIZE) {
        GrContext* context = source->getContext();

        sk_sp<GrTexture> inputTexture(input->asTextureRef(context));
        SkASSERT(inputTexture);

        offset->fX = bounds.left();
        offset->fY = bounds.top();
        bounds.offset(-inputOffset);

        // SRGBTODO: handle sRGB here
        sk_sp<GrFragmentProcessor> fp(GrMatrixConvolutionEffect::Make(inputTexture.get(),
            bounds,
            fKernelSize,
            fKernel,
            fGain,
            fBias,
            fKernelOffset,
            convert_tilemodes(fTileMode),
            fConvolveAlpha));
        if (!fp) {
            return nullptr;
        }

        return DrawWithFP(context, std::move(fp), bounds);
    }
#endif

    SkBitmap inputBM;

    if (!input->getROPixels(&inputBM)) {
        return nullptr;
    }

    if (inputBM.colorType() != kN32_SkColorType) {
        return nullptr;
    }

    if (!fConvolveAlpha && !inputBM.isOpaque()) {
        inputBM = unpremultiply_bitmap(inputBM);
    }

    SkAutoLockPixels alp(inputBM);
    if (!inputBM.getPixels()) {
        return nullptr;
    }

    const SkImageInfo info = SkImageInfo::MakeN32(bounds.width(), bounds.height(),
        inputBM.alphaType());

    SkBitmap dst;
    if (!dst.tryAllocPixels(info)) {
        return nullptr;
    }

    SkAutoLockPixels dstLock(dst);

    offset->fX = bounds.fLeft;
    offset->fY = bounds.fTop;
    bounds.offset(-inputOffset);
    SkIRect interior = SkIRect::MakeXYWH(bounds.left() + fKernelOffset.fX,
        bounds.top() + fKernelOffset.fY,
        bounds.width() - fKernelSize.fWidth + 1,
        bounds.height() - fKernelSize.fHeight + 1);
    SkIRect top = SkIRect::MakeLTRB(bounds.left(), bounds.top(), bounds.right(), interior.top());
    SkIRect bottom = SkIRect::MakeLTRB(bounds.left(), interior.bottom(),
        bounds.right(), bounds.bottom());
    SkIRect left = SkIRect::MakeLTRB(bounds.left(), interior.top(),
        interior.left(), interior.bottom());
    SkIRect right = SkIRect::MakeLTRB(interior.right(), interior.top(),
        bounds.right(), interior.bottom());
    this->filterBorderPixels(inputBM, &dst, top, bounds);
    this->filterBorderPixels(inputBM, &dst, left, bounds);
    this->filterInteriorPixels(inputBM, &dst, interior, bounds);
    this->filterBorderPixels(inputBM, &dst, right, bounds);
    this->filterBorderPixels(inputBM, &dst, bottom, bounds);
    return SkSpecialImage::MakeFromRaster(SkIRect::MakeWH(bounds.width(), bounds.height()),
        dst);
}

SkIRect SkMatrixConvolutionImageFilter::onFilterNodeBounds(const SkIRect& src, const SkMatrix& ctm,
    MapDirection direction) const
{
    SkIRect dst = src;
    int w = fKernelSize.width() - 1, h = fKernelSize.height() - 1;
    dst.fRight += w;
    dst.fBottom += h;
    if (kReverse_MapDirection == direction) {
        dst.offset(-fKernelOffset);
    } else {
        dst.offset(fKernelOffset - SkIPoint::Make(w, h));
    }
    return dst;
}

bool SkMatrixConvolutionImageFilter::affectsTransparentBlack() const
{
    // Because the kernel is applied in device-space, we have no idea what
    // pixels it will affect in object-space.
    return true;
}

#ifndef SK_IGNORE_TO_STRING
void SkMatrixConvolutionImageFilter::toString(SkString* str) const
{
=======
bool SkMatrixConvolutionImageFilter::asFragmentProcessor(GrFragmentProcessor** fp,
                                                         GrProcessorDataManager* procDataManager,
                                                         GrTexture* texture,
                                                         const SkMatrix&,
                                                         const SkIRect& bounds) const {
    if (!fp) {
        return fKernelSize.width() * fKernelSize.height() <= MAX_KERNEL_SIZE;
    }
    SkASSERT(fKernelSize.width() * fKernelSize.height() <= MAX_KERNEL_SIZE);
    *fp = GrMatrixConvolutionEffect::Create(procDataManager,
                                            texture,
                                            bounds,
                                            fKernelSize,
                                            fKernel,
                                            fGain,
                                            fBias,
                                            fKernelOffset,
                                            convert_tilemodes(fTileMode),
                                            fConvolveAlpha);
    return true;
}
#endif

#ifndef SK_IGNORE_TO_STRING
void SkMatrixConvolutionImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkMatrixConvolutionImageFilter: (");
    str->appendf("size: (%d,%d) kernel: (", fKernelSize.width(), fKernelSize.height());
    for (int y = 0; y < fKernelSize.height(); y++) {
        for (int x = 0; x < fKernelSize.width(); x++) {
            str->appendf("%f ", fKernel[y * fKernelSize.width() + x]);
        }
    }
    str->appendf(")");
    str->appendf("gain: %f bias: %f ", fGain, fBias);
    str->appendf("offset: (%d, %d) ", fKernelOffset.fX, fKernelOffset.fY);
    str->appendf("convolveAlpha: %s", fConvolveAlpha ? "true" : "false");
    str->append(")");
}
#endif
