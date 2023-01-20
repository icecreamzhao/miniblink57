/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkOffsetImageFilter.h"
<<<<<<< HEAD

#include "SkCanvas.h"
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkReadBuffer.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkWriteBuffer.h"

sk_sp<SkImageFilter> SkOffsetImageFilter::Make(SkScalar dx, SkScalar dy,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (!SkScalarIsFinite(dx) || !SkScalarIsFinite(dy)) {
        return nullptr;
    }

    return sk_sp<SkImageFilter>(new SkOffsetImageFilter(dx, dy, std::move(input), cropRect));
}

sk_sp<SkSpecialImage> SkOffsetImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &srcOffset));
    if (!input) {
        return nullptr;
    }

    SkVector vec;
    ctx.ctm().mapVectors(&vec, &fOffset, 1);

    if (!this->cropRectIsSet()) {
        offset->fX = srcOffset.fX + SkScalarRoundToInt(vec.fX);
        offset->fY = srcOffset.fY + SkScalarRoundToInt(vec.fY);
        return input;
    } else {
        SkIRect bounds;
        SkIRect srcBounds = SkIRect::MakeWH(input->width(), input->height());
        srcBounds.offset(srcOffset);
        if (!this->applyCropRect(ctx, srcBounds, &bounds)) {
            return nullptr;
        }

        SkImageInfo info = SkImageInfo::MakeN32(bounds.width(), bounds.height(),
            kPremul_SkAlphaType);
        sk_sp<SkSpecialSurface> surf(source->makeSurface(info));
        if (!surf) {
            return nullptr;
        }

        SkCanvas* canvas = surf->getCanvas();
        SkASSERT(canvas);

        // TODO: it seems like this clear shouldn't be necessary (see skbug.com/5075)
        canvas->clear(0x0);

        SkPaint paint;
        paint.setXfermodeMode(SkXfermode::kSrc_Mode);
        canvas->translate(SkIntToScalar(srcOffset.fX - bounds.fLeft),
            SkIntToScalar(srcOffset.fY - bounds.fTop));

        input->draw(canvas, vec.x(), vec.y(), &paint);

        offset->fX = bounds.fLeft;
        offset->fY = bounds.fTop;
        return surf->makeImageSnapshot();
    }
}

SkRect SkOffsetImageFilter::computeFastBounds(const SkRect& src) const
{
    SkRect bounds = this->getInput(0) ? this->getInput(0)->computeFastBounds(src) : src;
    bounds.offset(fOffset.fX, fOffset.fY);
    return bounds;
}

SkIRect SkOffsetImageFilter::onFilterNodeBounds(const SkIRect& src, const SkMatrix& ctm,
    MapDirection direction) const
{
    SkVector vec;
    ctm.mapVectors(&vec, &fOffset, 1);
    if (kReverse_MapDirection == direction) {
        vec.negate();
    }

    return src.makeOffset(SkScalarCeilToInt(vec.fX), SkScalarCeilToInt(vec.fY));
}

sk_sp<SkFlattenable> SkOffsetImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkPoint offset;
    buffer.readPoint(&offset);
    return Make(offset.x(), offset.y(), common.getInput(0), &common.cropRect());
}

void SkOffsetImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkMatrix.h"
#include "SkPaint.h"

bool SkOffsetImageFilter::onFilterImage(Proxy* proxy, const SkBitmap& source,
                                        const Context& ctx,
                                        SkBitmap* result,
                                        SkIPoint* offset) const {
    SkImageFilter* input = getInput(0);
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
#ifdef SK_DISABLE_OFFSETIMAGEFILTER_OPTIMIZATION
    if (false) {
#else
    if (!cropRectIsSet()) {
#endif
        if (input && !input->filterImage(proxy, source, ctx, &src, &srcOffset)) {
            return false;
        }

        SkVector vec;
        ctx.ctm().mapVectors(&vec, &fOffset, 1);

        offset->fX = srcOffset.fX + SkScalarRoundToInt(vec.fX);
        offset->fY = srcOffset.fY + SkScalarRoundToInt(vec.fY);
        *result = src;
    } else {
        if (input && !input->filterImage(proxy, source, ctx, &src, &srcOffset)) {
            return false;
        }

        SkIRect bounds;
        if (!this->applyCropRect(ctx, src, srcOffset, &bounds)) {
            return false;
        }

        SkAutoTUnref<SkBaseDevice> device(proxy->createDevice(bounds.width(), bounds.height()));
        if (NULL == device.get()) {
            return false;
        }
        SkCanvas canvas(device);
        SkPaint paint;
        paint.setXfermodeMode(SkXfermode::kSrc_Mode);
        canvas.translate(SkIntToScalar(srcOffset.fX - bounds.fLeft),
                         SkIntToScalar(srcOffset.fY - bounds.fTop));
        SkVector vec;
        ctx.ctm().mapVectors(&vec, &fOffset, 1);
        canvas.drawBitmap(src, vec.x(), vec.y(), &paint);
        *result = device->accessBitmap(false);
        offset->fX = bounds.fLeft;
        offset->fY = bounds.fTop;
    }
    return true;
}

void SkOffsetImageFilter::computeFastBounds(const SkRect& src, SkRect* dst) const {
    if (getInput(0)) {
        getInput(0)->computeFastBounds(src, dst);
    } else {
        *dst = src;
    }
    SkRect copy = *dst;
    dst->offset(fOffset.fX, fOffset.fY);
    dst->join(copy);
}

bool SkOffsetImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix& ctm,
                                         SkIRect* dst) const {
    SkVector vec;
    ctm.mapVectors(&vec, &fOffset, 1);

    SkIRect bounds = src;
    bounds.offset(-SkScalarCeilToInt(vec.fX), -SkScalarCeilToInt(vec.fY));
    bounds.join(src);
    if (getInput(0)) {
        return getInput(0)->filterBounds(bounds, ctm, dst);
    }
    *dst = bounds;
    return true;
}

SkFlattenable* SkOffsetImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkPoint offset;
    buffer.readPoint(&offset);
    return Create(offset.x(), offset.y(), common.getInput(0), &common.cropRect());
}

void SkOffsetImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writePoint(fOffset);
}

<<<<<<< HEAD
SkOffsetImageFilter::SkOffsetImageFilter(SkScalar dx, SkScalar dy,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
    : INHERITED(&input, 1, cropRect)
{
=======
SkOffsetImageFilter::SkOffsetImageFilter(SkScalar dx, SkScalar dy, SkImageFilter* input,
                                         const CropRect* cropRect)
  : INHERITED(1, &input, cropRect) {
>>>>>>> miniblink49
    fOffset.set(dx, dy);
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkOffsetImageFilter::toString(SkString* str) const
{
=======
void SkOffsetImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkOffsetImageFilter: (");
    str->appendf("offset: (%f, %f) ", fOffset.fX, fOffset.fY);
    str->append("input: (");
    if (this->getInput(0)) {
        this->getInput(0)->toString(str);
    }
    str->append("))");
}
#endif
