/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkColorFilterImageFilter.h"
<<<<<<< HEAD

#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkReadBuffer.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkWriteBuffer.h"

sk_sp<SkImageFilter> SkColorFilterImageFilter::Make(sk_sp<SkColorFilter> cf,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (!cf) {
        return nullptr;
=======
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColorMatrixFilter.h"
#include "SkDevice.h"
#include "SkColorFilter.h"
#include "SkReadBuffer.h"
#include "SkTableColorFilter.h"
#include "SkWriteBuffer.h"

SkColorFilterImageFilter* SkColorFilterImageFilter::Create(SkColorFilter* cf,
        SkImageFilter* input, const CropRect* cropRect) {
    if (NULL == cf) {
        return NULL;
>>>>>>> miniblink49
    }

    SkColorFilter* inputCF;
    if (input && input->isColorFilterNode(&inputCF)) {
        // This is an optimization, as it collapses the hierarchy by just combining the two
        // colorfilters into a single one, which the new imagefilter will wrap.
<<<<<<< HEAD
        sk_sp<SkColorFilter> newCF(SkColorFilter::MakeComposeFilter(cf, // can't move bc of fallthru
            sk_sp<SkColorFilter>(inputCF)));
        if (newCF) {
            return sk_sp<SkImageFilter>(new SkColorFilterImageFilter(std::move(newCF),
                sk_ref_sp(input->getInput(0)),
                cropRect));
        }
    }

    return sk_sp<SkImageFilter>(new SkColorFilterImageFilter(std::move(cf),
        std::move(input),
        cropRect));
}

SkColorFilterImageFilter::SkColorFilterImageFilter(sk_sp<SkColorFilter> cf,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
    : INHERITED(&input, 1, cropRect)
    , fColorFilter(std::move(cf))
{
}

sk_sp<SkFlattenable> SkColorFilterImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    sk_sp<SkColorFilter> cf(buffer.readColorFilter());
    return Make(std::move(cf), common.getInput(0), &common.cropRect());
}

void SkColorFilterImageFilter::flatten(SkWriteBuffer& buffer) const
{
    this->INHERITED::flatten(buffer);
    buffer.writeFlattenable(fColorFilter.get());
}

sk_sp<SkSpecialImage> SkColorFilterImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));

    SkIRect inputBounds;
    if (fColorFilter->affectsTransparentBlack()) {
        // If the color filter affects transparent black, the bounds are the entire clip.
        inputBounds = ctx.clipBounds();
    } else if (!input) {
        return nullptr;
    } else {
        inputBounds = SkIRect::MakeXYWH(inputOffset.x(), inputOffset.y(),
            input->width(), input->height());
    }

    SkIRect bounds;
    if (!this->applyCropRect(ctx, inputBounds, &bounds)) {
        return nullptr;
    }

    SkImageInfo info = SkImageInfo::MakeN32(bounds.width(), bounds.height(), kPremul_SkAlphaType);
    sk_sp<SkSpecialSurface> surf(source->makeSurface(info));
    if (!surf) {
        return nullptr;
    }

    SkCanvas* canvas = surf->getCanvas();
    SkASSERT(canvas);

=======
        SkAutoUnref autoUnref(inputCF);
        SkAutoTUnref<SkColorFilter> newCF(SkColorFilter::CreateComposeFilter(cf, inputCF));
        if (newCF) {
            return SkNEW_ARGS(SkColorFilterImageFilter, (newCF, input->getInput(0), cropRect));
        }
    }

    return SkNEW_ARGS(SkColorFilterImageFilter, (cf, input, cropRect));
}

SkColorFilterImageFilter::SkColorFilterImageFilter(SkColorFilter* cf,
        SkImageFilter* input, const CropRect* cropRect)
    : INHERITED(1, &input, cropRect), fColorFilter(SkRef(cf)) {
}

SkFlattenable* SkColorFilterImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkAutoTUnref<SkColorFilter> cf(buffer.readColorFilter());
    return Create(cf, common.getInput(0), &common.cropRect());
}

void SkColorFilterImageFilter::flatten(SkWriteBuffer& buffer) const {
    this->INHERITED::flatten(buffer);
    buffer.writeFlattenable(fColorFilter);
}

SkColorFilterImageFilter::~SkColorFilterImageFilter() {
    fColorFilter->unref();
}

bool SkColorFilterImageFilter::onFilterImage(Proxy* proxy, const SkBitmap& source,
                                             const Context& ctx,
                                             SkBitmap* result,
                                             SkIPoint* offset) const {
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (getInput(0) && !getInput(0)->filterImage(proxy, source, ctx, &src, &srcOffset)) {
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
    SkCanvas canvas(device.get());
>>>>>>> miniblink49
    SkPaint paint;

    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    paint.setColorFilter(fColorFilter);
<<<<<<< HEAD

    // TODO: it may not be necessary to clear or drawPaint inside the input bounds
    // (see skbug.com/5075)
    if (fColorFilter->affectsTransparentBlack()) {
        // The subsequent input->draw() call may not fill the entire canvas. For filters which
        // affect transparent black, ensure that the filter is applied everywhere.
        paint.setColor(SK_ColorTRANSPARENT);
        canvas->drawPaint(paint);
        paint.setColor(SK_ColorBLACK);
    } else {
        canvas->clear(0x0);
    }

    if (input) {
        input->draw(canvas,
            SkIntToScalar(inputOffset.fX - bounds.fLeft),
            SkIntToScalar(inputOffset.fY - bounds.fTop),
            &paint);
    }

    offset->fX = bounds.fLeft;
    offset->fY = bounds.fTop;
    return surf->makeImageSnapshot();
}

bool SkColorFilterImageFilter::onIsColorFilterNode(SkColorFilter** filter) const
{
    SkASSERT(1 == this->countInputs());
    if (!this->cropRectIsSet()) {
        if (filter) {
            *filter = SkRef(fColorFilter.get());
=======
    canvas.drawSprite(src, srcOffset.fX - bounds.fLeft, srcOffset.fY - bounds.fTop, &paint);

    *result = device.get()->accessBitmap(false);
    offset->fX = bounds.fLeft;
    offset->fY = bounds.fTop;
    return true;
}

bool SkColorFilterImageFilter::onIsColorFilterNode(SkColorFilter** filter) const {
    SkASSERT(1 == this->countInputs());
    if (!this->cropRectIsSet()) {
        if (filter) {
            *filter = SkRef(fColorFilter);
>>>>>>> miniblink49
        }
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool SkColorFilterImageFilter::affectsTransparentBlack() const
{
    return fColorFilter->affectsTransparentBlack();
}

#ifndef SK_IGNORE_TO_STRING
void SkColorFilterImageFilter::toString(SkString* str) const
{
=======
#ifndef SK_IGNORE_TO_STRING
void SkColorFilterImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkColorFilterImageFilter: (");

    str->appendf("input: (");

    if (this->getInput(0)) {
        this->getInput(0)->toString(str);
    }

    str->appendf(") color filter: ");
    fColorFilter->toString(str);

    str->append(")");
}
#endif
