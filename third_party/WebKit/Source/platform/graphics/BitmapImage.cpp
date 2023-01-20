/*
 * Copyright (C) 2006 Samuel Weinig (sam.weinig@gmail.com)
 * Copyright (C) 2004, 2005, 2006, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/graphics/BitmapImage.h"

#include "platform/PlatformInstrumentation.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/Timer.h"
#include "platform/geometry/FloatRect.h"
#include "platform/graphics/BitmapImageMetrics.h"
#include "platform/graphics/DeferredImageDecoder.h"
#include "platform/graphics/ImageObserver.h"
#include "platform/graphics/StaticBitmapImage.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "wtf/PassRefPtr.h"
#include "wtf/PtrUtil.h"
=======
#include "config.h"
#include "platform/graphics/BitmapImage.h"

#include "platform/PlatformInstrumentation.h"
#include "platform/Timer.h"
#include "platform/TraceEvent.h"
#include "platform/geometry/FloatRect.h"
#include "platform/graphics/DeferredImageDecoder.h"
#include "platform/graphics/ImageObserver.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "wtf/PassRefPtr.h"
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
namespace {

    ColorBehavior defaultColorBehavior()
    {
        // TODO(ccameron): ColorBehavior should be specified by the caller requesting
        // SkImages.
        // https://crbug.com/667420
        if (RuntimeEnabledFeatures::trueColorRenderingEnabled())
            return ColorBehavior::tag();
        return ColorBehavior::transformToGlobalTarget();
    }

} // namespace

PassRefPtr<BitmapImage> BitmapImage::createWithOrientationForTesting(
    const SkBitmap& bitmap,
    ImageOrientation orientation)
{
    if (bitmap.isNull()) {
        return BitmapImage::create();
    }

    RefPtr<BitmapImage> result = adoptRef(new BitmapImage(bitmap));
    result->m_frames[0].m_orientation = orientation;
    if (orientation.usesWidthAsHeight())
        result->m_sizeRespectingOrientation = result->m_size.transposedSize();
=======
PassRefPtr<BitmapImage> BitmapImage::create(const SkBitmap& bitmap, ImageObserver* observer)
{
    if (bitmap.isNull()) {
        return BitmapImage::create(observer);
    }

    return adoptRef(new BitmapImage(bitmap, observer));
}

PassRefPtr<BitmapImage> BitmapImage::createWithOrientationForTesting(const SkBitmap& bitmap, ImageOrientation orientation)
{
    RefPtr<BitmapImage> result = create(bitmap);
    result->m_frames[0].m_orientation = orientation;
    if (orientation.usesWidthAsHeight())
        result->m_sizeRespectingOrientation = IntSize(result->m_size.height(), result->m_size.width());
>>>>>>> miniblink49
    return result.release();
}

BitmapImage::BitmapImage(ImageObserver* observer)
    : Image(observer)
    , m_currentFrame(0)
<<<<<<< HEAD
    , m_cachedFrameIndex(0)
    , m_cachedFrameColorBehavior(defaultColorBehavior())
=======
    , m_frames()
    , m_frameTimer(0)
>>>>>>> miniblink49
    , m_repetitionCount(cAnimationNone)
    , m_repetitionCountStatus(Unknown)
    , m_repetitionsComplete(0)
    , m_desiredFrameStartTime(0)
    , m_frameCount(0)
    , m_animationPolicy(ImageAnimationPolicyAllowed)
<<<<<<< HEAD
=======
    , m_isSolidColor(false)
    , m_checkedForSolidColor(false)
>>>>>>> miniblink49
    , m_animationFinished(false)
    , m_allDataReceived(false)
    , m_haveSize(false)
    , m_sizeAvailable(false)
<<<<<<< HEAD
=======
    , m_hasUniformFrameSize(true)
>>>>>>> miniblink49
    , m_haveFrameCount(false)
{
}

BitmapImage::BitmapImage(const SkBitmap& bitmap, ImageObserver* observer)
    : Image(observer)
    , m_size(bitmap.width(), bitmap.height())
    , m_currentFrame(0)
<<<<<<< HEAD
    , m_cachedFrame(SkImage::MakeFromBitmap(bitmap))
    , m_cachedFrameIndex(0)
    , m_cachedFrameColorBehavior(defaultColorBehavior())
=======
    , m_frames(0)
    , m_frameTimer(0)
>>>>>>> miniblink49
    , m_repetitionCount(cAnimationNone)
    , m_repetitionCountStatus(Unknown)
    , m_repetitionsComplete(0)
    , m_frameCount(1)
    , m_animationPolicy(ImageAnimationPolicyAllowed)
<<<<<<< HEAD
=======
    , m_isSolidColor(false)
    , m_checkedForSolidColor(false)
>>>>>>> miniblink49
    , m_animationFinished(true)
    , m_allDataReceived(true)
    , m_haveSize(true)
    , m_sizeAvailable(true)
    , m_haveFrameCount(true)
{
    // Since we don't have a decoder, we can't figure out the image orientation.
    // Set m_sizeRespectingOrientation to be the same as m_size so it's not 0x0.
    m_sizeRespectingOrientation = m_size;

    m_frames.grow(1);
    m_frames[0].m_hasAlpha = !bitmap.isOpaque();
<<<<<<< HEAD
    m_frames[0].m_haveMetadata = true;
=======
    m_frames[0].m_frame = bitmap;
    m_frames[0].m_haveMetadata = true;

    checkForSolidColor();
>>>>>>> miniblink49
}

BitmapImage::~BitmapImage()
{
    stopAnimation();
}

<<<<<<< HEAD
=======
bool BitmapImage::isBitmapImage() const
{
    return true;
}

>>>>>>> miniblink49
bool BitmapImage::currentFrameHasSingleSecurityOrigin() const
{
    return true;
}

<<<<<<< HEAD
void BitmapImage::destroyDecodedData()
{
    m_cachedFrame.reset();
    for (size_t i = 0; i < m_frames.size(); ++i)
        m_frames[i].clear(true);
    m_source.clearCacheExceptFrame(kNotFound);
    notifyMemoryChanged();
}

PassRefPtr<SharedBuffer> BitmapImage::data()
{
    return m_source.data();
}

void BitmapImage::notifyMemoryChanged()
{
    if (getImageObserver())
        getImageObserver()->decodedSizeChangedTo(this, totalFrameBytes());
}

size_t BitmapImage::totalFrameBytes()
=======
int BitmapImage::totalFrameBytes()
>>>>>>> miniblink49
{
    const size_t numFrames = frameCount();
    size_t totalBytes = 0;
    for (size_t i = 0; i < numFrames; ++i)
        totalBytes += m_source.frameBytesAtIndex(i);
<<<<<<< HEAD
    return totalBytes;
}

sk_sp<SkImage> BitmapImage::decodeAndCacheFrame(
    size_t index,
    const ColorBehavior& colorBehavior)
=======
    return safeCast<int>(totalBytes);
}

void BitmapImage::destroyDecodedData(bool destroyAll)
{
    for (size_t i = 0; i < m_frames.size(); ++i) {
        // The underlying frame isn't actually changing (we're just trying to
        // save the memory for the framebuffer data), so we don't need to clear
        // the metadata.
        m_frames[i].clear(false);
    }

    destroyMetadataAndNotify(m_source.clearCacheExceptFrame(destroyAll ? kNotFound : m_currentFrame));
}

void BitmapImage::destroyDecodedDataIfNecessary()
{
    // Animated images >5MB are considered large enough that we'll only hang on
    // to one frame at a time.
    static const size_t cLargeAnimationCutoff = 5242880;
    size_t allFrameBytes = 0;
    for (size_t i = 0; i < m_frames.size(); ++i)
        allFrameBytes += m_frames[i].m_frameBytes;

    if (allFrameBytes > cLargeAnimationCutoff) {
        destroyDecodedData(false);
    }
}

void BitmapImage::destroyMetadataAndNotify(size_t frameBytesCleared)
{
    m_isSolidColor = false;
    m_checkedForSolidColor = false;

    if (frameBytesCleared && imageObserver())
        imageObserver()->decodedSizeChanged(this, -safeCast<int>(frameBytesCleared));
}

void BitmapImage::cacheFrame(size_t index)
>>>>>>> miniblink49
{
    size_t numFrames = frameCount();
    if (m_frames.size() < numFrames)
        m_frames.grow(numFrames);

<<<<<<< HEAD
    // We are caching frame snapshots.  This is OK even for partially decoded
    // frames, as they are cleared by dataChanged() when new data arrives.
    sk_sp<SkImage> image = m_source.createFrameAtIndex(index, colorBehavior);
    m_cachedFrame = image;
    m_cachedFrameIndex = index;
    m_cachedFrameColorBehavior = colorBehavior;
=======
    int deltaBytes = totalFrameBytes();
    if (m_source.createFrameAtIndex(index, &m_frames[index].m_frame) && numFrames == 1)
        checkForSolidColor();
>>>>>>> miniblink49

    m_frames[index].m_orientation = m_source.orientationAtIndex(index);
    m_frames[index].m_haveMetadata = true;
    m_frames[index].m_isComplete = m_source.frameIsCompleteAtIndex(index);
    if (repetitionCount(false) != cAnimationNone)
        m_frames[index].m_duration = m_source.frameDurationAtIndex(index);
    m_frames[index].m_hasAlpha = m_source.frameHasAlphaAtIndex(index);
    m_frames[index].m_frameBytes = m_source.frameBytesAtIndex(index);

<<<<<<< HEAD
    notifyMemoryChanged();
    return image;
=======
    const IntSize frameSize(index ? m_source.frameSizeAtIndex(index) : m_size);
    if (frameSize != m_size)
        m_hasUniformFrameSize = false;

    // We need to check the total bytes before and after the decode call, not
    // just the current frame size, because some multi-frame images may require
    // decoding multiple frames to decode the current frame.
    deltaBytes = totalFrameBytes() - deltaBytes;
    if (deltaBytes && imageObserver())
        imageObserver()->decodedSizeChanged(this, deltaBytes);
>>>>>>> miniblink49
}

void BitmapImage::updateSize() const
{
    if (!m_sizeAvailable || m_haveSize)
        return;

    m_size = m_source.size();
    m_sizeRespectingOrientation = m_source.size(RespectImageOrientation);
    m_haveSize = true;
}

IntSize BitmapImage::size() const
{
    updateSize();
    return m_size;
}

IntSize BitmapImage::sizeRespectingOrientation() const
{
    updateSize();
    return m_sizeRespectingOrientation;
}

bool BitmapImage::getHotSpot(IntPoint& hotSpot) const
{
    return m_source.getHotSpot(hotSpot);
}

<<<<<<< HEAD
Image::SizeAvailability BitmapImage::setData(PassRefPtr<SharedBuffer> data,
    bool allDataReceived)
{
    if (!data.get())
        return SizeAvailable;

    int length = data->size();
    if (!length)
        return SizeAvailable;

    // If ImageSource::setData() fails, we know that this is a decode error.
    // Report size available so that it gets registered as such in
    // ImageResourceContent.
    if (!m_source.setData(std::move(data), allDataReceived))
        return SizeAvailable;

    return dataChanged(allDataReceived);
}

Image::SizeAvailability BitmapImage::dataChanged(bool allDataReceived)
=======
bool BitmapImage::dataChanged(bool allDataReceived)
>>>>>>> miniblink49
{
    TRACE_EVENT0("blink", "BitmapImage::dataChanged");

    // Clear all partially-decoded frames. For most image formats, there is only
    // one frame, but at least GIF and ICO can have more. With GIFs, the frames
    // come in order and we ask to decode them in order, waiting to request a
    // subsequent frame until the prior one is complete. Given that we clear
    // incomplete frames here, this means there is at most one incomplete frame
    // (even if we use destroyDecodedData() -- since it doesn't reset the
    // metadata), and it is after all the complete frames.
    //
    // With ICOs, on the other hand, we may ask for arbitrary frames at
    // different times (e.g. because we're displaying a higher-resolution image
    // in the content area and using a lower-resolution one for the favicon),
    // and the frames aren't even guaranteed to appear in the file in the same
    // order as in the directory, so an arbitrary number of the frames might be
    // incomplete (if we ask for frames for which we've not yet reached the
    // start of the frame data), and any or none of them might be the particular
    // frame affected by appending new data here. Thus we have to clear all the
    // incomplete frames to be safe.
<<<<<<< HEAD
=======
    size_t frameBytesCleared = 0;
>>>>>>> miniblink49
    for (size_t i = 0; i < m_frames.size(); ++i) {
        // NOTE: Don't call frameIsCompleteAtIndex() here, that will try to
        // decode any uncached (i.e. never-decoded or
        // cleared-on-a-previous-pass) frames!
<<<<<<< HEAD
        if (m_frames[i].m_haveMetadata && !m_frames[i].m_isComplete) {
            m_frames[i].clear(true);
            if (i == m_cachedFrameIndex)
                m_cachedFrame.reset();
        }
    }

    // Feed all the data we've seen so far to the image decoder.
    m_allDataReceived = allDataReceived;

    m_haveFrameCount = false;
    return isSizeAvailable() ? SizeAvailable : SizeUnavailable;
=======
        size_t frameBytes = m_frames[i].m_frameBytes;
        if (m_frames[i].m_haveMetadata && !m_frames[i].m_isComplete)
            frameBytesCleared += (m_frames[i].clear(true) ? frameBytes : 0);
    }
    destroyMetadataAndNotify(frameBytesCleared);

    // Feed all the data we've seen so far to the image decoder.
    m_allDataReceived = allDataReceived;
    ASSERT(data());
    m_source.setData(*data(), allDataReceived);

    m_haveFrameCount = false;
    m_hasUniformFrameSize = true;
    return isSizeAvailable();
>>>>>>> miniblink49
}

bool BitmapImage::hasColorProfile() const
{
    return m_source.hasColorProfile();
}

String BitmapImage::filenameExtension() const
{
    return m_source.filenameExtension();
}

<<<<<<< HEAD
void BitmapImage::draw(
    SkCanvas* canvas,
    const SkPaint& paint,
    const FloatRect& dstRect,
    const FloatRect& srcRect,
    RespectImageOrientationEnum shouldRespectImageOrientation,
    ImageClampingMode clampMode,
    const ColorBehavior& colorBehavior)
{
    TRACE_EVENT0("skia", "BitmapImage::draw");

    sk_sp<SkImage> image = imageForCurrentFrame(colorBehavior);
    if (!image)
        return; // It's too early and we don't have an image yet.

    FloatRect adjustedSrcRect = srcRect;
    adjustedSrcRect.intersect(SkRect::Make(image->bounds()));
=======
bool BitmapImage::isLazyDecodedBitmap()
{
    SkBitmap bitmap;
    if (!bitmapForCurrentFrame(&bitmap))
        return false;
    return DeferredImageDecoder::isLazyDecoded(bitmap);
}

bool BitmapImage::isImmutableBitmap()
{
    SkBitmap bitmap;
    if (!bitmapForCurrentFrame(&bitmap))
        return false;
    return bitmap.isImmutable();
}

void BitmapImage::draw(SkCanvas* canvas, const SkPaint& paint, const FloatRect& dstRect, const FloatRect& srcRect, RespectImageOrientationEnum shouldRespectImageOrientation, ImageClampingMode clampMode)
{
    TRACE_EVENT0("skia", "BitmapImage::draw");

    SkBitmap bitmap;
    if (!bitmapForCurrentFrame(&bitmap))
        return; // It's too early and we don't have an image yet.

    FloatRect adjustedSrcRect = srcRect;
    adjustedSrcRect.intersect(FloatRect(0, 0, bitmap.width(), bitmap.height()));
>>>>>>> miniblink49

    if (adjustedSrcRect.isEmpty() || dstRect.isEmpty())
        return; // Nothing to draw.

    ImageOrientation orientation = DefaultImageOrientation;
    if (shouldRespectImageOrientation == RespectImageOrientation)
        orientation = frameOrientationAtIndex(m_currentFrame);

<<<<<<< HEAD
    SkAutoCanvasRestore autoRestore(canvas, false);
=======
    int initialSaveCount = canvas->getSaveCount();
>>>>>>> miniblink49
    FloatRect adjustedDstRect = dstRect;
    if (orientation != DefaultImageOrientation) {
        canvas->save();

        // ImageOrientation expects the origin to be at (0, 0)
        canvas->translate(adjustedDstRect.x(), adjustedDstRect.y());
        adjustedDstRect.setLocation(FloatPoint());

<<<<<<< HEAD
        canvas->concat(affineTransformToSkMatrix(
            orientation.transformFromDefault(adjustedDstRect.size())));

        if (orientation.usesWidthAsHeight()) {
            // The destination rect will have its width and height already reversed
            // for the orientation of the image, as it was needed for page layout, so
            // we need to reverse it back here.
            adjustedDstRect = FloatRect(adjustedDstRect.x(), adjustedDstRect.y(),
                adjustedDstRect.height(), adjustedDstRect.width());
        }
    }

    canvas->drawImageRect(image.get(), adjustedSrcRect, adjustedDstRect, &paint,
        WebCoreClampingModeToSkiaRectConstraint(clampMode));

    if (image->isLazyGenerated())
        PlatformInstrumentation::didDrawLazyPixelRef(image->uniqueID());
=======
        canvas->concat(affineTransformToSkMatrix(orientation.transformFromDefault(adjustedDstRect.size())));

        if (orientation.usesWidthAsHeight()) {
            // The destination rect will have it's width and height already reversed for the orientation of
            // the image, as it was needed for page layout, so we need to reverse it back here.
            adjustedDstRect = FloatRect(adjustedDstRect.x(), adjustedDstRect.y(), adjustedDstRect.height(), adjustedDstRect.width());
        }
    }

    SkRect skSrcRect = adjustedSrcRect;
    SkCanvas::DrawBitmapRectFlags flags =
        clampMode == ClampImageToSourceRect ? SkCanvas::kNone_DrawBitmapRectFlag : SkCanvas::kBleed_DrawBitmapRectFlag;
    canvas->drawBitmapRectToRect(bitmap, &skSrcRect, adjustedDstRect, &paint, flags);
    canvas->restoreToCount(initialSaveCount);

    if (DeferredImageDecoder::isLazyDecoded(bitmap))
        PlatformInstrumentation::didDrawLazyPixelRef(bitmap.getGenerationID());

    if (ImageObserver* observer = imageObserver())
        observer->didDraw(this);
>>>>>>> miniblink49

    startAnimation();
}

size_t BitmapImage::frameCount()
{
    if (!m_haveFrameCount) {
        m_frameCount = m_source.frameCount();
        // If decoder is not initialized yet, m_source.frameCount() returns 0.
        if (m_frameCount)
            m_haveFrameCount = true;
    }

    return m_frameCount;
}

<<<<<<< HEAD
static inline bool hasVisibleImageSize(IntSize size)
{
    return (size.width() > 1 || size.height() > 1);
}

=======
>>>>>>> miniblink49
bool BitmapImage::isSizeAvailable()
{
    if (m_sizeAvailable)
        return true;

    m_sizeAvailable = m_source.isSizeAvailable();

<<<<<<< HEAD
    if (m_sizeAvailable && hasVisibleImageSize(size())) {
        BitmapImageMetrics::countDecodedImageType(m_source.filenameExtension());
        if (m_source.filenameExtension() == "jpg")
            BitmapImageMetrics::countImageOrientation(
                m_source.orientationAtIndex(0).orientation());
    }

    return m_sizeAvailable;
}

sk_sp<SkImage> BitmapImage::frameAtIndex(size_t index,
    const ColorBehavior& colorBehavior)
{
    if (index >= frameCount())
        return nullptr;

    if (index == m_cachedFrameIndex && m_cachedFrame && m_cachedFrameColorBehavior == colorBehavior)
        return m_cachedFrame;

    return decodeAndCacheFrame(index, colorBehavior);
}

bool BitmapImage::frameIsCompleteAtIndex(size_t index) const
=======
    return m_sizeAvailable;
}

bool BitmapImage::ensureFrameIsCached(size_t index)
{
    if (index >= frameCount())
        return false;

    if (index >= m_frames.size() || m_frames[index].m_frame.isNull())
        cacheFrame(index);

    return true;
}

bool BitmapImage::frameAtIndex(size_t index, SkBitmap* bitmap)
{
    if (!ensureFrameIsCached(index))
        return false;

    *bitmap = m_frames[index].m_frame;
    return true;
}

bool BitmapImage::frameIsCompleteAtIndex(size_t index)
>>>>>>> miniblink49
{
    if (index < m_frames.size() && m_frames[index].m_haveMetadata && m_frames[index].m_isComplete)
        return true;

    return m_source.frameIsCompleteAtIndex(index);
}

<<<<<<< HEAD
float BitmapImage::frameDurationAtIndex(size_t index) const
=======
float BitmapImage::frameDurationAtIndex(size_t index)
>>>>>>> miniblink49
{
    if (index < m_frames.size() && m_frames[index].m_haveMetadata)
        return m_frames[index].m_duration;

    return m_source.frameDurationAtIndex(index);
}

<<<<<<< HEAD
sk_sp<SkImage> BitmapImage::imageForCurrentFrame(
    const ColorBehavior& colorBehavior)
{
    return frameAtIndex(currentFrame(), colorBehavior);
=======
bool BitmapImage::bitmapForCurrentFrame(SkBitmap* bitmap)
{
    return frameAtIndex(currentFrame(), bitmap);
>>>>>>> miniblink49
}

PassRefPtr<Image> BitmapImage::imageForDefaultFrame()
{
<<<<<<< HEAD
    // TODO(ccameron): Determine the appropriate ColorBehavior for this situation.
    // https://crbug.com/667420
    const ColorBehavior& colorBehavior = m_cachedFrameColorBehavior;
    if (frameCount() > 1) {
        sk_sp<SkImage> firstFrame = frameAtIndex(0, colorBehavior);
        if (firstFrame)
            return StaticBitmapImage::create(std::move(firstFrame));
    }
=======
    SkBitmap bitmap;
    if (frameCount() > 1 && frameAtIndex(0, &bitmap))
        return BitmapImage::create(bitmap);
>>>>>>> miniblink49

    return Image::imageForDefaultFrame();
}

bool BitmapImage::frameHasAlphaAtIndex(size_t index)
{
    if (m_frames.size() <= index)
        return true;

<<<<<<< HEAD
    if (m_frames[index].m_haveMetadata && !m_frames[index].m_hasAlpha)
        return false;

    // m_hasAlpha may change after m_haveMetadata is set to true, so always ask
    // ImageSource for the value if the cached value is the default value.
    bool hasAlpha = m_source.frameHasAlphaAtIndex(index);

    if (m_frames[index].m_haveMetadata)
        m_frames[index].m_hasAlpha = hasAlpha;

    return hasAlpha;
}

bool BitmapImage::currentFrameKnownToBeOpaque(MetadataMode metadataMode)
{
    if (metadataMode == PreCacheMetadata) {
        // frameHasAlphaAtIndex() conservatively returns false for uncached frames.
        // To increase the chance of an accurate answer, pre-cache the current frame
        // metadata. Because ColorBehavior does not affect this result, use
        // whatever ColorBehavior was last used (if any).
        frameAtIndex(currentFrame(), m_cachedFrameColorBehavior);
    }
    return !frameHasAlphaAtIndex(currentFrame());
}

bool BitmapImage::currentFrameIsComplete()
{
    return frameIsCompleteAtIndex(currentFrame());
}

bool BitmapImage::currentFrameIsLazyDecoded()
{
    // Because ColorBehavior does not affect this result, use whatever
    // ColorBehavior was last used (if any).
    sk_sp<SkImage> image = frameAtIndex(currentFrame(), m_cachedFrameColorBehavior);
    return image && image->isLazyGenerated();
}

=======
    if (m_frames[index].m_haveMetadata)
        return m_frames[index].m_hasAlpha;

    return m_source.frameHasAlphaAtIndex(index);
}

bool BitmapImage::currentFrameKnownToBeOpaque()
{
    return !frameHasAlphaAtIndex(currentFrame());
}

>>>>>>> miniblink49
ImageOrientation BitmapImage::currentFrameOrientation()
{
    return frameOrientationAtIndex(currentFrame());
}

ImageOrientation BitmapImage::frameOrientationAtIndex(size_t index)
{
    if (m_frames.size() <= index)
        return DefaultImageOrientation;

    if (m_frames[index].m_haveMetadata)
        return m_frames[index].m_orientation;

    return m_source.orientationAtIndex(index);
}

<<<<<<< HEAD
=======
#if ENABLE(ASSERT)
bool BitmapImage::notSolidColor()
{
    return size().width() != 1 || size().height() != 1 || frameCount() > 1;
}
#endif

>>>>>>> miniblink49
int BitmapImage::repetitionCount(bool imageKnownToBeComplete)
{
    if ((m_repetitionCountStatus == Unknown) || ((m_repetitionCountStatus == Uncertain) && imageKnownToBeComplete)) {
        // Snag the repetition count.  If |imageKnownToBeComplete| is false, the
        // repetition count may not be accurate yet for GIFs; in this case the
        // decoder will default to cAnimationLoopOnce, and we'll try and read
        // the count again once the whole image is decoded.
        m_repetitionCount = m_source.repetitionCount();
<<<<<<< HEAD
        m_repetitionCountStatus = (imageKnownToBeComplete || m_repetitionCount == cAnimationNone)
            ? Certain
            : Uncertain;
=======
        m_repetitionCountStatus = (imageKnownToBeComplete || m_repetitionCount == cAnimationNone) ? Certain : Uncertain;
>>>>>>> miniblink49
    }
    return m_repetitionCount;
}

bool BitmapImage::shouldAnimate()
{
<<<<<<< HEAD
    bool animated = repetitionCount(false) != cAnimationNone && !m_animationFinished && getImageObserver();
=======
    bool animated = repetitionCount(false) != cAnimationNone && !m_animationFinished && imageObserver();
>>>>>>> miniblink49
    if (animated && m_animationPolicy == ImageAnimationPolicyNoAnimation)
        animated = false;
    return animated;
}

void BitmapImage::startAnimation(CatchUpAnimation catchUpIfNecessary)
{
    if (m_frameTimer || !shouldAnimate() || frameCount() <= 1)
        return;

    // If we aren't already animating, set now as the animation start time.
    const double time = monotonicallyIncreasingTime();
    if (!m_desiredFrameStartTime)
        m_desiredFrameStartTime = time;

    // Don't advance the animation to an incomplete frame.
    size_t nextFrame = (m_currentFrame + 1) % frameCount();
    if (!m_allDataReceived && !frameIsCompleteAtIndex(nextFrame))
        return;

    // Don't advance past the last frame if we haven't decoded the whole image
    // yet and our repetition count is potentially unset.  The repetition count
    // in a GIF can potentially come after all the rest of the image data, so
    // wait on it.
<<<<<<< HEAD
    if (!m_allDataReceived && (repetitionCount(false) == cAnimationLoopOnce || m_animationPolicy == ImageAnimationPolicyAnimateOnce) && m_currentFrame >= (frameCount() - 1))
=======
    if (!m_allDataReceived
        && (repetitionCount(false) == cAnimationLoopOnce || m_animationPolicy == ImageAnimationPolicyAnimateOnce)
        && m_currentFrame >= (frameCount() - 1))
>>>>>>> miniblink49
        return;

    // Determine time for next frame to start.  By ignoring paint and timer lag
    // in this calculation, we make the animation appear to run at its desired
    // rate regardless of how fast it's being repainted.
    const double currentDuration = frameDurationAtIndex(m_currentFrame);
    m_desiredFrameStartTime += currentDuration;

    // When an animated image is more than five minutes out of date, the
    // user probably doesn't care about resyncing and we could burn a lot of
    // time looping through frames below.  Just reset the timings.
    const double cAnimationResyncCutoff = 5 * 60;
    if ((time - m_desiredFrameStartTime) > cAnimationResyncCutoff)
        m_desiredFrameStartTime = time + currentDuration;

    // The image may load more slowly than it's supposed to animate, so that by
    // the time we reach the end of the first repetition, we're well behind.
    // Clamp the desired frame start time in this case, so that we don't skip
    // frames (or whole iterations) trying to "catch up".  This is a tradeoff:
    // It guarantees users see the whole animation the second time through and
    // don't miss any repetitions, and is closer to what other browsers do; on
    // the other hand, it makes animations "less accurate" for pages that try to
    // sync an image and some other resource (e.g. audio), especially if users
    // switch tabs (and thus stop drawing the animation, which will pause it)
    // during that initial loop, then switch back later.
    if (nextFrame == 0 && m_repetitionsComplete == 0 && m_desiredFrameStartTime < time)
        m_desiredFrameStartTime = time;

    if (catchUpIfNecessary == DoNotCatchUp || time < m_desiredFrameStartTime) {
        // Haven't yet reached time for next frame to start; delay until then.
<<<<<<< HEAD
        m_frameTimer = WTF::wrapUnique(
            new Timer<BitmapImage>(this, &BitmapImage::advanceAnimation));
        m_frameTimer->startOneShot(std::max(m_desiredFrameStartTime - time, 0.),
            BLINK_FROM_HERE);
=======
        m_frameTimer = new Timer<BitmapImage>(this, &BitmapImage::advanceAnimation);
        m_frameTimer->startOneShot(std::max(m_desiredFrameStartTime - time, 0.), FROM_HERE);
>>>>>>> miniblink49
    } else {
        // We've already reached or passed the time for the next frame to start.
        // See if we've also passed the time for frames after that to start, in
        // case we need to skip some frames entirely.  Remember not to advance
        // to an incomplete frame.
<<<<<<< HEAD
        for (size_t frameAfterNext = (nextFrame + 1) % frameCount();
             frameIsCompleteAtIndex(frameAfterNext);
             frameAfterNext = (nextFrame + 1) % frameCount()) {
=======
        for (size_t frameAfterNext = (nextFrame + 1) % frameCount(); frameIsCompleteAtIndex(frameAfterNext); frameAfterNext = (nextFrame + 1) % frameCount()) {
>>>>>>> miniblink49
            // Should we skip the next frame?
            double frameAfterNextStartTime = m_desiredFrameStartTime + frameDurationAtIndex(nextFrame);
            if (time < frameAfterNextStartTime)
                break;

<<<<<<< HEAD
            // Skip the next frame by advancing the animation forward one frame.
            if (!internalAdvanceAnimation(SkipFramesToCatchUp)) {
                DCHECK(m_animationFinished);
                return;
            }
=======
            // Yes; skip over it without notifying our observers.
            if (!internalAdvanceAnimation(true))
                return;
>>>>>>> miniblink49
            m_desiredFrameStartTime = frameAfterNextStartTime;
            nextFrame = frameAfterNext;
        }

<<<<<<< HEAD
        // Post a task to advance the frame immediately. m_desiredFrameStartTime
        // may be in the past, meaning the next time through this function we'll
        // kick off the next advancement sooner than this frame's duration would
        // suggest.
        m_frameTimer = WTF::wrapUnique(new Timer<BitmapImage>(
            this, &BitmapImage::advanceAnimationWithoutCatchUp));
        m_frameTimer->startOneShot(0, BLINK_FROM_HERE);
=======
        // Draw the next frame immediately.  Note that m_desiredFrameStartTime
        // may be in the past, meaning the next time through this function we'll
        // kick off the next advancement sooner than this frame's duration would
        // suggest.
        if (internalAdvanceAnimation(false)) {
            // The image region has been marked dirty, but once we return to our
            // caller, draw() will clear it, and nothing will cause the
            // animation to advance again.  We need to start the timer for the
            // next frame running, or the animation can hang.  (Compare this
            // with when advanceAnimation() is called, and the region is dirtied
            // while draw() is not in the callstack, meaning draw() gets called
            // to update the region and thus startAnimation() is reached again.)
            // NOTE: For large images with slow or heavily-loaded systems,
            // throwing away data as we go (see destroyDecodedData()) means we
            // can spend so much time re-decoding data above that by the time we
            // reach here we're behind again.  If we let startAnimation() run
            // the catch-up code again, we can get long delays without painting
            // as we race the timer, or even infinite recursion.  In this
            // situation the best we can do is to simply change frames as fast
            // as possible, so force startAnimation() to set a zero-delay timer
            // and bail out if we're not caught up.
            startAnimation(DoNotCatchUp);
        }
>>>>>>> miniblink49
    }
}

void BitmapImage::stopAnimation()
{
<<<<<<< HEAD
    // This timer is used to animate all occurrences of this image.  Don't
    // invalidate the timer unless all renderers have stopped drawing.
    m_frameTimer.reset();
=======
    // This timer is used to animate all occurrences of this image.  Don't invalidate
    // the timer unless all renderers have stopped drawing.
    delete m_frameTimer;
    m_frameTimer = 0;
>>>>>>> miniblink49
}

void BitmapImage::resetAnimation()
{
    stopAnimation();
    m_currentFrame = 0;
    m_repetitionsComplete = 0;
    m_desiredFrameStartTime = 0;
    m_animationFinished = false;
<<<<<<< HEAD
    m_cachedFrame.reset();
=======

    // For extremely large animations, when the animation is reset, we just throw everything away.
    destroyDecodedDataIfNecessary();
>>>>>>> miniblink49
}

bool BitmapImage::maybeAnimated()
{
    if (m_animationFinished)
        return false;
    if (frameCount() > 1)
        return true;

    return m_source.repetitionCount() != cAnimationNone;
}

void BitmapImage::advanceTime(double deltaTimeInSeconds)
{
    if (m_desiredFrameStartTime)
        m_desiredFrameStartTime -= deltaTimeInSeconds;
    else
        m_desiredFrameStartTime = monotonicallyIncreasingTime() - deltaTimeInSeconds;
}

<<<<<<< HEAD
void BitmapImage::advanceAnimation(TimerBase*)
{
    internalAdvanceAnimation();
=======
void BitmapImage::advanceAnimation(Timer<BitmapImage>*)
{
    internalAdvanceAnimation(false);
>>>>>>> miniblink49
    // At this point the image region has been marked dirty, and if it's
    // onscreen, we'll soon make a call to draw(), which will call
    // startAnimation() again to keep the animation moving.
}

<<<<<<< HEAD
void BitmapImage::advanceAnimationWithoutCatchUp(TimerBase*)
{
    if (internalAdvanceAnimation())
        startAnimation(DoNotCatchUp);
}

bool BitmapImage::internalAdvanceAnimation(AnimationAdvancement advancement)
=======
bool BitmapImage::internalAdvanceAnimation(bool skippingFrames)
>>>>>>> miniblink49
{
    // Stop the animation.
    stopAnimation();

<<<<<<< HEAD
    // See if anyone is still paying attention to this animation.  If not, we
    // don't advance, and will remain suspended at the current frame until the
    // animation is resumed.
    if (advancement != SkipFramesToCatchUp && getImageObserver()->shouldPauseAnimation(this))
        return false;

    if (m_currentFrame + 1 < frameCount()) {
        m_currentFrame++;
    } else {
        m_repetitionsComplete++;

        // Get the repetition count again. If we weren't able to get a
        // repetition count before, we should have decoded the whole image by
        // now, so it should now be available.
        // We don't need to special-case cAnimationLoopOnce here because it is
        // 0 (see comments on its declaration in ImageAnimation.h).
        if ((repetitionCount(true) != cAnimationLoopInfinite && m_repetitionsComplete > m_repetitionCount) || m_animationPolicy == ImageAnimationPolicyAnimateOnce) {
            m_animationFinished = true;
            m_desiredFrameStartTime = 0;

            // We skipped to the last frame and cannot advance further. The
            // observer will not receive animationAdvanced notifications while
            // skipping but we still need to notify the observer to draw the
            // last frame. Skipping frames occurs while painting so we do not
            // synchronously notify the observer which could cause a layout.
            if (advancement == SkipFramesToCatchUp) {
                m_frameTimer = WTF::wrapUnique(new Timer<BitmapImage>(
                    this, &BitmapImage::notifyObserversOfAnimationAdvance));
                m_frameTimer->startOneShot(0, BLINK_FROM_HERE);
            }

            return false;
        }

        // Loop the animation back to the first frame.
        m_currentFrame = 0;
    }

    // We need to draw this frame if we advanced to it while not skipping.
    if (advancement != SkipFramesToCatchUp)
        getImageObserver()->animationAdvanced(this);

    return true;
}

void BitmapImage::notifyObserversOfAnimationAdvance(TimerBase*)
{
    getImageObserver()->animationAdvanced(this);
=======
    // See if anyone is still paying attention to this animation.  If not, we don't
    // advance and will remain suspended at the current frame until the animation is resumed.
    if (!skippingFrames && imageObserver()->shouldPauseAnimation(this))
        return false;

    ++m_currentFrame;
    bool advancedAnimation = true;
    if (m_currentFrame >= frameCount()) {
        ++m_repetitionsComplete;

        // Get the repetition count again.  If we weren't able to get a
        // repetition count before, we should have decoded the whole image by
        // now, so it should now be available.
        // Note that we don't need to special-case cAnimationLoopOnce here
        // because it is 0 (see comments on its declaration in ImageAnimation.h).
        if ((repetitionCount(true) != cAnimationLoopInfinite && m_repetitionsComplete > m_repetitionCount)
            || (m_animationPolicy == ImageAnimationPolicyAnimateOnce && m_repetitionsComplete > 0)) {
            m_animationFinished = true;
            m_desiredFrameStartTime = 0;
            --m_currentFrame;
            advancedAnimation = false;
        } else
            m_currentFrame = 0;
    }
    destroyDecodedDataIfNecessary();

    // We need to draw this frame if we advanced to it while not skipping, or if
    // while trying to skip frames we hit the last frame and thus had to stop.
    if (skippingFrames != advancedAnimation)
        imageObserver()->animationAdvanced(this);
    return advancedAnimation;
}

void BitmapImage::checkForSolidColor()
{
    m_isSolidColor = false;
    m_checkedForSolidColor = true;

    if (frameCount() > 1)
        return;

    SkBitmap bitmap;
    if (frameAtIndex(0, &bitmap) && size().width() == 1 && size().height() == 1) {
        SkAutoLockPixels lock(bitmap);
        if (!bitmap.getPixels())
            return;

        m_isSolidColor = true;
        m_solidColor = Color(bitmap.getColor(0, 0));
    }
}

bool BitmapImage::mayFillWithSolidColor()
{
    if (!m_checkedForSolidColor && frameCount() > 0) {
        checkForSolidColor();
        ASSERT(m_checkedForSolidColor);
    }

    return m_isSolidColor && !m_currentFrame;
}

Color BitmapImage::solidColor() const
{
    return m_solidColor;
>>>>>>> miniblink49
}

} // namespace blink
