/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMergeImageFilter.h"
<<<<<<< HEAD

#include "SkCanvas.h"
#include "SkReadBuffer.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkValidationUtils.h"
#include "SkWriteBuffer.h"

sk_sp<SkImageFilter> SkMergeImageFilter::Make(sk_sp<SkImageFilter> first,
    sk_sp<SkImageFilter> second,
    SkXfermode::Mode mode,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilter> inputs[2] = { first, second };
    SkXfermode::Mode modes[2] = { mode, mode };
    return sk_sp<SkImageFilter>(new SkMergeImageFilter(inputs, 2, modes, cropRect));
}

sk_sp<SkImageFilter> SkMergeImageFilter::Make(sk_sp<SkImageFilter> filters[],
    int count,
    const SkXfermode::Mode modes[],
    const CropRect* cropRect)
{
    return sk_sp<SkImageFilter>(new SkMergeImageFilter(filters, count, modes, cropRect));
}

///////////////////////////////////////////////////////////////////////////////

void SkMergeImageFilter::initAllocModes()
{
    int inputCount = this->countInputs();
=======
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkValidationUtils.h"

///////////////////////////////////////////////////////////////////////////////

void SkMergeImageFilter::initAllocModes() {
    int inputCount = countInputs();
>>>>>>> miniblink49
    if (inputCount) {
        size_t size = sizeof(uint8_t) * inputCount;
        if (size <= sizeof(fStorage)) {
            fModes = SkTCast<uint8_t*>(fStorage);
        } else {
            fModes = SkTCast<uint8_t*>(sk_malloc_throw(size));
        }
    } else {
<<<<<<< HEAD
        fModes = nullptr;
    }
}

void SkMergeImageFilter::initModes(const SkXfermode::Mode modes[])
{
    if (modes) {
        this->initAllocModes();
        int inputCount = this->countInputs();
=======
        fModes = NULL;
    }
}

void SkMergeImageFilter::initModes(const SkXfermode::Mode modes[]) {
    if (modes) {
        this->initAllocModes();
        int inputCount = countInputs();
>>>>>>> miniblink49
        for (int i = 0; i < inputCount; ++i) {
            fModes[i] = SkToU8(modes[i]);
        }
    } else {
<<<<<<< HEAD
        fModes = nullptr;
    }
}

SkMergeImageFilter::SkMergeImageFilter(sk_sp<SkImageFilter> filters[], int count,
    const SkXfermode::Mode modes[],
    const CropRect* cropRect)
    : INHERITED(filters, count, cropRect)
{
=======
        fModes = NULL;
    }
}

SkMergeImageFilter::SkMergeImageFilter(SkImageFilter* filters[], int count,
                                       const SkXfermode::Mode modes[],
                                       const CropRect* cropRect)
  : INHERITED(count, filters, cropRect) {
>>>>>>> miniblink49
    SkASSERT(count >= 0);
    this->initModes(modes);
}

<<<<<<< HEAD
SkMergeImageFilter::~SkMergeImageFilter()
{
=======
SkMergeImageFilter::~SkMergeImageFilter() {
>>>>>>> miniblink49

    if (fModes != SkTCast<uint8_t*>(fStorage)) {
        sk_free(fModes);
    }
}

<<<<<<< HEAD
sk_sp<SkSpecialImage> SkMergeImageFilter::onFilterImage(SkSpecialImage* source, const Context& ctx,
    SkIPoint* offset) const
{
    int inputCount = this->countInputs();
    if (inputCount < 1) {
        return nullptr;
    }

    SkIRect bounds;
    bounds.setEmpty();

    SkAutoTDeleteArray<sk_sp<SkSpecialImage>> inputs(new sk_sp<SkSpecialImage>[inputCount]);
    SkAutoTDeleteArray<SkIPoint> offsets(new SkIPoint[inputCount]);

    // Filter all of the inputs.
    for (int i = 0; i < inputCount; ++i) {
        offsets[i].setZero();
        inputs[i] = this->filterInput(i, source, ctx, &offsets[i]);
        if (!inputs[i]) {
            continue;
        }
        const SkIRect inputBounds = SkIRect::MakeXYWH(offsets[i].fX, offsets[i].fY,
            inputs[i]->width(), inputs[i]->height());
        bounds.join(inputBounds);
    }
    if (bounds.isEmpty()) {
        return nullptr;
    }

    // Apply the crop rect to the union of the inputs' bounds.
    // Note that the crop rect can only reduce the bounds, since this
    // filter does not affect transparent black.
    bool embiggen = false;
    this->getCropRect().applyTo(bounds, ctx.ctm(), embiggen, &bounds);
    if (!bounds.intersect(ctx.clipBounds())) {
        return nullptr;
=======
bool SkMergeImageFilter::onFilterImage(Proxy* proxy, const SkBitmap& src,
                                       const Context& ctx,
                                       SkBitmap* result, SkIPoint* offset) const {
    if (countInputs() < 1) {
        return false;
    }

    SkIRect bounds;
    if (!this->applyCropRect(ctx, src, SkIPoint::Make(0, 0), &bounds)) {
        return false;
>>>>>>> miniblink49
    }

    const int x0 = bounds.left();
    const int y0 = bounds.top();

<<<<<<< HEAD
    SkImageInfo info = SkImageInfo::MakeN32(bounds.width(), bounds.height(),
        kPremul_SkAlphaType);

    sk_sp<SkSpecialSurface> surf(source->makeSurface(info));
    if (!surf) {
        return nullptr;
    }

    SkCanvas* canvas = surf->getCanvas();
    SkASSERT(canvas);

    canvas->clear(0x0);

    // Composite all of the filter inputs.
    for (int i = 0; i < inputCount; ++i) {
        if (!inputs[i]) {
            continue;
        }

        SkPaint paint;
        if (fModes) {
            paint.setXfermodeMode((SkXfermode::Mode)fModes[i]);
        }

        inputs[i]->draw(canvas,
            SkIntToScalar(offsets[i].x() - x0), SkIntToScalar(offsets[i].y() - y0),
            &paint);
    }

    offset->fX = bounds.left();
    offset->fY = bounds.top();
    return surf->makeImageSnapshot();
}

sk_sp<SkFlattenable> SkMergeImageFilter::CreateProc(SkReadBuffer& buffer)
{
    Common common;
    if (!common.unflatten(buffer, -1)) {
        return nullptr;
=======
    SkAutoTUnref<SkBaseDevice> dst(proxy->createDevice(bounds.width(), bounds.height()));
    if (NULL == dst) {
        return false;
    }
    SkCanvas canvas(dst);
    SkPaint paint;

    bool didProduceResult = false;
    int inputCount = countInputs();
    for (int i = 0; i < inputCount; ++i) {
        SkBitmap tmp;
        const SkBitmap* srcPtr;
        SkIPoint pos = SkIPoint::Make(0, 0);
        SkImageFilter* filter = getInput(i);
        if (filter) {
            if (!filter->filterImage(proxy, src, ctx, &tmp, &pos)) {
                continue;
            }
            srcPtr = &tmp;
        } else {
            srcPtr = &src;
        }

        if (fModes) {
            paint.setXfermodeMode((SkXfermode::Mode)fModes[i]);
        } else {
            paint.setXfermode(NULL);
        }
        canvas.drawSprite(*srcPtr, pos.x() - x0, pos.y() - y0, &paint);
        didProduceResult = true;
    }

    if (!didProduceResult)
        return false;

    offset->fX = bounds.left();
    offset->fY = bounds.top();
    *result = dst->accessBitmap(false);
    return true;
}

SkFlattenable* SkMergeImageFilter::CreateProc(SkReadBuffer& buffer) {
    Common common;
    if (!common.unflatten(buffer, -1)) {
        return NULL;
>>>>>>> miniblink49
    }

    const int count = common.inputCount();
    bool hasModes = buffer.readBool();
    if (hasModes) {
        SkAutoSTArray<4, SkXfermode::Mode> modes(count);
        SkAutoSTArray<4, uint8_t> modes8(count);
        if (!buffer.readByteArray(modes8.get(), count)) {
<<<<<<< HEAD
            return nullptr;
=======
            return NULL;
>>>>>>> miniblink49
        }
        for (int i = 0; i < count; ++i) {
            modes[i] = (SkXfermode::Mode)modes8[i];
            buffer.validate(SkIsValidMode(modes[i]));
        }
        if (!buffer.isValid()) {
<<<<<<< HEAD
            return nullptr;
        }
        return Make(common.inputs(), count, modes.get(), &common.cropRect());
    }
    return Make(common.inputs(), count, nullptr, &common.cropRect());
}

void SkMergeImageFilter::flatten(SkWriteBuffer& buffer) const
{
    this->INHERITED::flatten(buffer);
    buffer.writeBool(fModes != nullptr);
    if (fModes) {
        buffer.writeByteArray(fModes, this->countInputs() * sizeof(fModes[0]));
=======
            return NULL;
        }
        return Create(common.inputs(), count, modes.get(), &common.cropRect());
    }
    return Create(common.inputs(), count, NULL, &common.cropRect());
}

void SkMergeImageFilter::flatten(SkWriteBuffer& buffer) const {
    this->INHERITED::flatten(buffer);
    buffer.writeBool(fModes != NULL);
    if (fModes) {
        buffer.writeByteArray(fModes, countInputs() * sizeof(fModes[0]));
>>>>>>> miniblink49
    }
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkMergeImageFilter::toString(SkString* str) const
{
    str->appendf("SkMergeImageFilter: (");

=======
void SkMergeImageFilter::toString(SkString* str) const {
    str->appendf("SkMergeImageFilter: (");
    
>>>>>>> miniblink49
    for (int i = 0; i < this->countInputs(); ++i) {
        SkImageFilter* filter = this->getInput(i);
        str->appendf("%d: (", i);
        filter->toString(str);
        str->appendf(")");
    }

    str->append(")");
}
#endif
