/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTileImageFilter.h"
<<<<<<< HEAD

#include "SkCanvas.h"
#include "SkImage.h"
#include "SkMatrix.h"
#include "SkOffsetImageFilter.h"
#include "SkPaint.h"
#include "SkReadBuffer.h"
#include "SkShader.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkSurface.h"
#include "SkValidationUtils.h"
#include "SkWriteBuffer.h"

sk_sp<SkImageFilter> SkTileImageFilter::Make(const SkRect& srcRect, const SkRect& dstRect,
    sk_sp<SkImageFilter> input)
{
    if (!SkIsValidRect(srcRect) || !SkIsValidRect(dstRect)) {
        return nullptr;
    }
    if (srcRect.width() == dstRect.width() && srcRect.height() == dstRect.height()) {
        SkRect ir = dstRect;
        if (!ir.intersect(srcRect)) {
            return input;
        }
        CropRect cropRect(ir);
        return SkOffsetImageFilter::Make(dstRect.x() - srcRect.x(),
            dstRect.y() - srcRect.y(),
            std::move(input),
            &cropRect);
    }
    return sk_sp<SkImageFilter>(new SkTileImageFilter(srcRect, dstRect, std::move(input)));
}

sk_sp<SkSpecialImage> SkTileImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));
    if (!input) {
        return nullptr;
=======
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkShader.h"
#include "SkValidationUtils.h"

SkTileImageFilter* SkTileImageFilter::Create(const SkRect& srcRect, const SkRect& dstRect,
                                             SkImageFilter* input) {
    if (!SkIsValidRect(srcRect) || !SkIsValidRect(dstRect)) {
        return NULL;
    }
    return SkNEW_ARGS(SkTileImageFilter, (srcRect, dstRect, input));
}

bool SkTileImageFilter::onFilterImage(Proxy* proxy, const SkBitmap& src,
                                      const Context& ctx,
                                      SkBitmap* dst, SkIPoint* offset) const {
    SkBitmap source = src;
    SkImageFilter* input = getInput(0);
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (input && !input->filterImage(proxy, src, ctx, &source, &srcOffset)) {
        return false;
>>>>>>> miniblink49
    }

    SkRect dstRect;
    ctx.ctm().mapRect(&dstRect, fDstRect);
<<<<<<< HEAD
    if (!dstRect.intersect(SkRect::Make(ctx.clipBounds()))) {
        return nullptr;
    }

    const SkIRect dstIRect = dstRect.roundOut();
    int dstWidth = dstIRect.width();
    int dstHeight = dstIRect.height();
    if (!fSrcRect.width() || !fSrcRect.height() || !dstWidth || !dstHeight) {
        return nullptr;
=======
    const SkIRect dstIRect = dstRect.roundOut();
    int w = dstIRect.width();
    int h = dstIRect.height();
    if (!fSrcRect.width() || !fSrcRect.height() || !w || !h) {
        return false;
>>>>>>> miniblink49
    }

    SkRect srcRect;
    ctx.ctm().mapRect(&srcRect, fSrcRect);
    SkIRect srcIRect;
    srcRect.roundOut(&srcIRect);
<<<<<<< HEAD
    srcIRect.offset(-inputOffset);
    const SkIRect inputBounds = SkIRect::MakeWH(input->width(), input->height());

    if (!SkIRect::Intersects(srcIRect, inputBounds)) {
        return nullptr;
    }

    // We create an SkImage here b.c. it needs to be a tight fit for the tiling
    sk_sp<SkImage> subset;
    if (inputBounds.contains(srcIRect)) {
        subset = input->makeTightSubset(srcIRect);
        if (!subset) {
            return nullptr;
        }
    } else {
        const SkImageInfo info = SkImageInfo::MakeN32(srcIRect.width(), srcIRect.height(),
            kPremul_SkAlphaType);
        sk_sp<SkSurface> surf(input->makeTightSurface(info));
        if (!surf) {
            return nullptr;
        }

        SkCanvas* canvas = surf->getCanvas();
        SkASSERT(canvas);

        SkPaint paint;
        paint.setXfermodeMode(SkXfermode::kSrc_Mode);

        input->draw(canvas,
            SkIntToScalar(inputOffset.x()), SkIntToScalar(inputOffset.y()),
            &paint);

        subset = surf->makeImageSnapshot();
    }
    SkASSERT(subset->width() == srcIRect.width());
    SkASSERT(subset->height() == srcIRect.height());

    const SkImageInfo info = SkImageInfo::MakeN32(dstWidth, dstHeight, kPremul_SkAlphaType);

    sk_sp<SkSpecialSurface> surf(source->makeSurface(info));
    if (!surf) {
        return nullptr;
    }

    SkCanvas* canvas = surf->getCanvas();
    SkASSERT(canvas);

    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    paint.setShader(subset->makeShader(SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode));
    canvas->translate(-dstRect.fLeft, -dstRect.fTop);
    canvas->drawRect(dstRect, paint);
    offset->fX = dstIRect.fLeft;
    offset->fY = dstIRect.fTop;
    return surf->makeImageSnapshot();
}

SkIRect SkTileImageFilter::onFilterNodeBounds(const SkIRect& src, const SkMatrix& ctm,
    MapDirection direction) const
{
    SkRect rect = kReverse_MapDirection == direction ? fSrcRect : fDstRect;
    ctm.mapRect(&rect);
    return rect.roundOut();
}

SkIRect SkTileImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix&, MapDirection) const
{
    // Don't recurse into inputs.
    return src;
}

SkRect SkTileImageFilter::computeFastBounds(const SkRect& src) const
{
    return fDstRect;
}

sk_sp<SkFlattenable> SkTileImageFilter::CreateProc(SkReadBuffer& buffer)
{
=======
    srcIRect.offset(-srcOffset);
    SkBitmap subset;
    SkIRect bounds;
    source.getBounds(&bounds);

    if (!srcIRect.intersect(bounds)) {
        offset->fX = offset->fY = 0;
        return true;
    } else if (!source.extractSubset(&subset, srcIRect)) {
        return false;
    }

    SkAutoTUnref<SkBaseDevice> device(proxy->createDevice(w, h));
    if (NULL == device.get()) {
        return false;
    }
    SkCanvas canvas(device);
    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);

    SkMatrix shaderMatrix;
    shaderMatrix.setTranslate(SkIntToScalar(srcOffset.fX),
                              SkIntToScalar(srcOffset.fY));
    SkAutoTUnref<SkShader> shader(SkShader::CreateBitmapShader(subset,
                                  SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode,
                                  &shaderMatrix));
    paint.setShader(shader);
    canvas.translate(-dstRect.fLeft, -dstRect.fTop);
    canvas.drawRect(dstRect, paint);
    *dst = device->accessBitmap(false);
    offset->fX = dstIRect.fLeft;
    offset->fY = dstIRect.fTop;
    return true;
}

bool SkTileImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix& ctm,
                                       SkIRect* dst) const {
    SkRect srcRect;
    ctm.mapRect(&srcRect, fSrcRect);
    SkIRect srcIRect;
    srcRect.roundOut(&srcIRect);
    srcIRect.join(src);
    *dst = srcIRect;
    return true;
}

void SkTileImageFilter::computeFastBounds(const SkRect& src, SkRect* dst) const {
    // This is a workaround for skia:3194.
    *dst = src;
    dst->join(fDstRect);
}

SkFlattenable* SkTileImageFilter::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkRect src, dst;
    buffer.readRect(&src);
    buffer.readRect(&dst);
<<<<<<< HEAD
    return Make(src, dst, common.getInput(0));
}

void SkTileImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
    return Create(src, dst, common.getInput(0));
}

void SkTileImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeRect(fSrcRect);
    buffer.writeRect(fDstRect);
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkTileImageFilter::toString(SkString* str) const
{
    str->appendf("SkTileImageFilter: (");
    str->appendf("src: %.2f %.2f %.2f %.2f",
        fSrcRect.fLeft, fSrcRect.fTop, fSrcRect.fRight, fSrcRect.fBottom);
    str->appendf(" dst: %.2f %.2f %.2f %.2f",
        fDstRect.fLeft, fDstRect.fTop, fDstRect.fRight, fDstRect.fBottom);
=======
void SkTileImageFilter::toString(SkString* str) const {
    str->appendf("SkTileImageFilter: (");
    str->appendf("src: %.2f %.2f %.2f %.2f",
                 fSrcRect.fLeft, fSrcRect.fTop, fSrcRect.fRight, fSrcRect.fBottom);
    str->appendf(" dst: %.2f %.2f %.2f %.2f",
                 fDstRect.fLeft, fDstRect.fTop, fDstRect.fRight, fDstRect.fBottom);
>>>>>>> miniblink49
    if (this->getInput(0)) {
        str->appendf("input: (");
        this->getInput(0)->toString(str);
        str->appendf(")");
    }
    str->append(")");
}
#endif
