/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkComposeImageFilter.h"

#include "SkReadBuffer.h"
#include "SkSpecialImage.h"
#include "SkWriteBuffer.h"

sk_sp<SkImageFilter> SkComposeImageFilter::Make(sk_sp<SkImageFilter> outer,
    sk_sp<SkImageFilter> inner)
{
    if (!outer) {
        return inner;
    }
    if (!inner) {
        return outer;
    }
    sk_sp<SkImageFilter> inputs[2] = { std::move(outer), std::move(inner) };
    return sk_sp<SkImageFilter>(new SkComposeImageFilter(inputs));
}

SkRect SkComposeImageFilter::computeFastBounds(const SkRect& src) const
{
    SkImageFilter* outer = this->getInput(0);
    SkImageFilter* inner = this->getInput(1);

    return outer->computeFastBounds(inner->computeFastBounds(src));
}

sk_sp<SkSpecialImage> SkComposeImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    // The bounds passed to the inner filter must be filtered by the outer
    // filter, so that the inner filter produces the pixels that the outer
    // filter requires as input. This matters if the outer filter moves pixels.
    SkIRect innerClipBounds;
    innerClipBounds = this->getInput(0)->filterBounds(ctx.clipBounds(), ctx.ctm());
    Context innerContext(ctx.ctm(), innerClipBounds, ctx.cache());
    SkIPoint innerOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> inner(this->filterInput(1, source, innerContext, &innerOffset));
    if (!inner) {
        return nullptr;
    }

    SkMatrix outerMatrix(ctx.ctm());
    outerMatrix.postTranslate(SkIntToScalar(-innerOffset.x()), SkIntToScalar(-innerOffset.y()));
    SkIRect clipBounds = ctx.clipBounds();
    clipBounds.offset(-innerOffset.x(), -innerOffset.y());
    Context outerContext(outerMatrix, clipBounds, ctx.cache());

    SkIPoint outerOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> outer(this->filterInput(0, inner.get(), outerContext, &outerOffset));
    if (!outer) {
        return nullptr;
    }

    *offset = innerOffset + outerOffset;
    return outer;
}

SkIRect SkComposeImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix& ctm,
    MapDirection direction) const
{
    SkImageFilter* outer = this->getInput(0);
    SkImageFilter* inner = this->getInput(1);

    return outer->filterBounds(inner->filterBounds(src, ctm, direction), ctm, direction);
}

sk_sp<SkFlattenable> SkComposeImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 2);
    return SkComposeImageFilter::Make(common.getInput(0), common.getInput(1));
}

#ifndef SK_IGNORE_TO_STRING
void SkComposeImageFilter::toString(SkString* str) const
{
=======
#include "SkBitmap.h"
#include "SkComposeImageFilter.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"

SkComposeImageFilter::~SkComposeImageFilter() {
}

void SkComposeImageFilter::computeFastBounds(const SkRect& src, SkRect* dst) const {
    SkImageFilter* outer = getInput(0);
    SkImageFilter* inner = getInput(1);

    SkRect tmp;
    inner->computeFastBounds(src, &tmp);
    outer->computeFastBounds(tmp, dst);
}

bool SkComposeImageFilter::onFilterImage(Proxy* proxy,
                                         const SkBitmap& src,
                                         const Context& ctx,
                                         SkBitmap* result,
                                         SkIPoint* offset) const {
    SkImageFilter* outer = getInput(0);
    SkImageFilter* inner = getInput(1);

    SkBitmap tmp;
    SkIPoint innerOffset = SkIPoint::Make(0, 0);
    SkIPoint outerOffset = SkIPoint::Make(0, 0);
    if (!inner->filterImage(proxy, src, ctx, &tmp, &innerOffset))
        return false;

    SkMatrix outerMatrix(ctx.ctm());
    outerMatrix.postTranslate(SkIntToScalar(-innerOffset.x()), SkIntToScalar(-innerOffset.y()));
    Context outerContext(outerMatrix, ctx.clipBounds(), ctx.cache());
    if (!outer->filterImage(proxy, tmp, outerContext, result, &outerOffset)) {
        return false;
    }

    *offset = innerOffset + outerOffset;
    return true;
}

bool SkComposeImageFilter::onFilterBounds(const SkIRect& src,
                                          const SkMatrix& ctm,
                                          SkIRect* dst) const {
    SkImageFilter* outer = getInput(0);
    SkImageFilter* inner = getInput(1);

    SkIRect tmp;
    return inner->filterBounds(src, ctm, &tmp) && outer->filterBounds(tmp, ctm, dst);
}

SkFlattenable* SkComposeImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 2);
    return SkComposeImageFilter::Create(common.getInput(0), common.getInput(1));
}

#ifndef SK_IGNORE_TO_STRING
void SkComposeImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    SkImageFilter* outer = getInput(0);
    SkImageFilter* inner = getInput(1);

    str->appendf("SkComposeImageFilter: (");

    str->appendf("outer: ");
    outer->toString(str);

    str->appendf("inner: ");
    inner->toString(str);

    str->appendf(")");
}
#endif
