/*
 * Copyright 2014 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrixImageFilter.h"
<<<<<<< HEAD

#include "SkCanvas.h"
#include "SkReadBuffer.h"
#include "SkRect.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkWriteBuffer.h"

SkMatrixImageFilter::SkMatrixImageFilter(const SkMatrix& transform,
    SkFilterQuality filterQuality,
    sk_sp<SkImageFilter> input)
    : INHERITED(&input, 1, nullptr)
    , fTransform(transform)
    , fFilterQuality(filterQuality)
{
}

sk_sp<SkImageFilter> SkMatrixImageFilter::Make(const SkMatrix& transform,
    SkFilterQuality filterQuality,
    sk_sp<SkImageFilter> input)
{
    return sk_sp<SkImageFilter>(new SkMatrixImageFilter(transform,
        filterQuality,
        std::move(input)));
}

sk_sp<SkFlattenable> SkMatrixImageFilter::CreateProc(SkReadBuffer& buffer)
{
=======
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkColorPriv.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkMatrix.h"
#include "SkRect.h"

SkMatrixImageFilter::SkMatrixImageFilter(const SkMatrix& transform,
                                         SkFilterQuality filterQuality,
                                         SkImageFilter* input)
  : INHERITED(1, &input),
    fTransform(transform),
    fFilterQuality(filterQuality) {
}

SkMatrixImageFilter* SkMatrixImageFilter::Create(const SkMatrix& transform,
                                                 SkFilterQuality filterQuality,
                                                 SkImageFilter* input) {
    return SkNEW_ARGS(SkMatrixImageFilter, (transform, filterQuality, input));
}

SkFlattenable* SkMatrixImageFilter::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    SkFilterQuality quality = static_cast<SkFilterQuality>(buffer.readInt());
<<<<<<< HEAD
    return Make(matrix, quality, common.getInput(0));
}

void SkMatrixImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
    return Create(matrix, quality, common.getInput(0));
}

void SkMatrixImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeMatrix(fTransform);
    buffer.writeInt(fFilterQuality);
}

<<<<<<< HEAD
sk_sp<SkSpecialImage> SkMatrixImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{

    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));
    if (!input) {
        return nullptr;
    }

    SkMatrix matrix;
    if (!ctx.ctm().invert(&matrix)) {
        return nullptr;
    }
    matrix.postConcat(fTransform);
    matrix.postConcat(ctx.ctm());

    const SkIRect srcBounds = SkIRect::MakeXYWH(inputOffset.x(), inputOffset.y(),
        input->width(), input->height());
    const SkRect srcRect = SkRect::Make(srcBounds);

    SkRect dstRect;
    matrix.mapRect(&dstRect, srcRect);
    SkIRect dstBounds;
    dstRect.roundOut(&dstBounds);

    const SkImageInfo info = SkImageInfo::MakeN32Premul(dstBounds.width(), dstBounds.height());

    sk_sp<SkSpecialSurface> surf(input->makeSurface(info));
    if (!surf) {
        return nullptr;
    }

    SkCanvas* canvas = surf->getCanvas();
    SkASSERT(canvas);

    canvas->clear(0x0);

    canvas->translate(-SkIntToScalar(dstBounds.x()), -SkIntToScalar(dstBounds.y()));
    canvas->concat(matrix);

    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    paint.setFilterQuality(fFilterQuality);

    input->draw(canvas, srcRect.x(), srcRect.y(), &paint);

    offset->fX = dstBounds.fLeft;
    offset->fY = dstBounds.fTop;
    return surf->makeImageSnapshot();
}

SkRect SkMatrixImageFilter::computeFastBounds(const SkRect& src) const
{
    SkRect bounds = this->getInput(0) ? this->getInput(0)->computeFastBounds(src) : src;
    SkRect dst;
    fTransform.mapRect(&dst, bounds);
    return dst;
}

SkIRect SkMatrixImageFilter::onFilterNodeBounds(const SkIRect& src, const SkMatrix& ctm,
    MapDirection direction) const
{
    SkMatrix matrix;
    if (!ctm.invert(&matrix)) {
        return src;
    }
    if (kForward_MapDirection == direction) {
        matrix.postConcat(fTransform);
    } else {
        SkMatrix transformInverse;
        if (!fTransform.invert(&transformInverse)) {
            return src;
        }
        matrix.postConcat(transformInverse);
    }
    matrix.postConcat(ctm);
    SkRect floatBounds;
    matrix.mapRect(&floatBounds, SkRect::Make(src));
    return floatBounds.roundOut();
}

#ifndef SK_IGNORE_TO_STRING
void SkMatrixImageFilter::toString(SkString* str) const
{
    str->appendf("SkMatrixImageFilter: (");

    str->appendf("transform: (%f %f %f %f %f %f %f %f %f)",
        fTransform[SkMatrix::kMScaleX],
        fTransform[SkMatrix::kMSkewX],
        fTransform[SkMatrix::kMTransX],
        fTransform[SkMatrix::kMSkewY],
        fTransform[SkMatrix::kMScaleY],
        fTransform[SkMatrix::kMTransY],
        fTransform[SkMatrix::kMPersp0],
        fTransform[SkMatrix::kMPersp1],
        fTransform[SkMatrix::kMPersp2]);
=======
SkMatrixImageFilter::~SkMatrixImageFilter() {
}

bool SkMatrixImageFilter::onFilterImage(Proxy* proxy,
                                        const SkBitmap& source,
                                        const Context& ctx,
                                        SkBitmap* result,
                                        SkIPoint* offset) const {
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (getInput(0) && !getInput(0)->filterImage(proxy, source, ctx, &src, &srcOffset)) {
        return false;
    }

    SkRect dstRect;
    SkIRect srcBounds, dstBounds;
    src.getBounds(&srcBounds);
    srcBounds.offset(srcOffset);
    SkRect srcRect = SkRect::Make(srcBounds);
    SkMatrix matrix;
    if (!ctx.ctm().invert(&matrix)) {
        return false;
    }
    matrix.postConcat(fTransform);
    matrix.postConcat(ctx.ctm());
    matrix.mapRect(&dstRect, srcRect);
    dstRect.roundOut(&dstBounds);

    SkAutoTUnref<SkBaseDevice> device(proxy->createDevice(dstBounds.width(), dstBounds.height()));
    if (NULL == device.get()) {
        return false;
    }

    SkCanvas canvas(device.get());
    canvas.translate(-SkIntToScalar(dstBounds.x()), -SkIntToScalar(dstBounds.y()));
    canvas.concat(matrix);
    SkPaint paint;

    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    paint.setFilterQuality(fFilterQuality);
    canvas.drawBitmap(src, srcRect.x(), srcRect.y(), &paint);

    *result = device.get()->accessBitmap(false);
    offset->fX = dstBounds.fLeft;
    offset->fY = dstBounds.fTop;
    return true;
}

void SkMatrixImageFilter::computeFastBounds(const SkRect& src, SkRect* dst) const {
    SkRect bounds = src;
    if (getInput(0)) {
        getInput(0)->computeFastBounds(src, &bounds);
    }
    fTransform.mapRect(dst, bounds);
    dst->join(bounds);   // Work around for skia:3194
}

bool SkMatrixImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix& ctm,
                                         SkIRect* dst) const {
    SkMatrix transformInverse;
    if (!fTransform.invert(&transformInverse)) {
        return false;
    }
    SkMatrix matrix;
    if (!ctm.invert(&matrix)) {
        return false;
    }
    matrix.postConcat(transformInverse);
    matrix.postConcat(ctm);
    SkRect floatBounds;
    matrix.mapRect(&floatBounds, SkRect::Make(src));
    SkIRect bounds = floatBounds.roundOut();
    if (getInput(0) && !getInput(0)->filterBounds(bounds, ctm, &bounds)) {
        return false;
    }

    *dst = bounds;
    return true;
}

#ifndef SK_IGNORE_TO_STRING
void SkMatrixImageFilter::toString(SkString* str) const {
    str->appendf("SkMatrixImageFilter: (");

    str->appendf("transform: (%f %f %f %f %f %f %f %f %f)",
                 fTransform[SkMatrix::kMScaleX],
                 fTransform[SkMatrix::kMSkewX],
                 fTransform[SkMatrix::kMTransX],
                 fTransform[SkMatrix::kMSkewY],
                 fTransform[SkMatrix::kMScaleY],
                 fTransform[SkMatrix::kMTransY],
                 fTransform[SkMatrix::kMPersp0],
                 fTransform[SkMatrix::kMPersp1],
                 fTransform[SkMatrix::kMPersp2]);
>>>>>>> miniblink49

    str->append("<dt>FilterLevel:</dt><dd>");
    static const char* gFilterLevelStrings[] = { "None", "Low", "Medium", "High" };
    str->append(gFilterLevelStrings[fFilterQuality]);
    str->append("</dd>");

    str->appendf(")");
}
#endif
