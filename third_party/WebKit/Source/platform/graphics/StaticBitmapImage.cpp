// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/graphics/StaticBitmapImage.h"

#include "platform/graphics/AcceleratedStaticBitmapImage.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/ImageObserver.h"
#include "platform/graphics/UnacceleratedStaticBitmapImage.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkImage.h"
#include "third_party/skia/include/core/SkPaint.h"

namespace blink {

PassRefPtr<StaticBitmapImage> StaticBitmapImage::create(sk_sp<SkImage> image)
{
    if (!image)
        return nullptr;
    if (image->isTextureBacked()) {
        //return AcceleratedStaticBitmapImage::createFromSharedContextImage(std::move(image));
        DebugBreak();
    }
    return UnacceleratedStaticBitmapImage::create(std::move(image));
}

void StaticBitmapImage::drawHelper(SkCanvas* canvas,
    const SkPaint& paint,
    const FloatRect& dstRect,
    const FloatRect& srcRect,
    ImageClampingMode clampMode,
    sk_sp<SkImage> image)
{
    FloatRect adjustedSrcRect = srcRect;
    adjustedSrcRect.intersect(SkRect::Make(image->bounds()));

    if (dstRect.isEmpty() || adjustedSrcRect.isEmpty())
        return; // Nothing to draw.

    canvas->drawImageRect(image.get(), adjustedSrcRect, dstRect, &paint, WebCoreClampingModeToSkiaRectConstraint(clampMode));
=======
#include "config.h"
#include "platform/graphics/StaticBitmapImage.h"

#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/ImageObserver.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkImage.h"
#include "third_party/skia/include/core/SkPaint.h"
#include "third_party/skia/include/core/SkShader.h"

namespace blink {

PassRefPtr<Image> StaticBitmapImage::create(PassRefPtr<SkImage> image)
{
    return adoptRef(new StaticBitmapImage(image));
}

StaticBitmapImage::StaticBitmapImage(PassRefPtr<SkImage> image) : m_image(image)
{
    ASSERT(m_image);
}

StaticBitmapImage::~StaticBitmapImage() { }

IntSize StaticBitmapImage::size() const
{
    return IntSize(m_image->width(), m_image->height());
}

bool StaticBitmapImage::currentFrameKnownToBeOpaque()
{
    return m_image->isOpaque();
}

void StaticBitmapImage::draw(SkCanvas* canvas, const SkPaint& paint, const FloatRect& dstRect, const FloatRect& srcRect, RespectImageOrientationEnum, ImageClampingMode)
{
    ASSERT(dstRect.width() >= 0 && dstRect.height() >= 0);
    ASSERT(srcRect.width() >= 0 && srcRect.height() >= 0);

    FloatRect adjustedSrcRect = srcRect;
    adjustedSrcRect.intersect(FloatRect(0, 0, m_image->width(), m_image->height()));

    if (adjustedSrcRect.isEmpty() || dstRect.isEmpty())
        return; // Nothing to draw.

    ASSERT(adjustedSrcRect.width() <= m_image->width() && adjustedSrcRect.height() <= m_image->height());

    SkRect srcSkRect = adjustedSrcRect;
    // TODO: Add support for ImageClampingMode
    canvas->drawImageRect(m_image.get(), &srcSkRect, dstRect, &paint);

    if (ImageObserver* observer = imageObserver())
        observer->didDraw(this);
>>>>>>> miniblink49
}

} // namespace blink
