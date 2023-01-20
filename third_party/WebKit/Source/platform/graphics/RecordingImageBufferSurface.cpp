// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/graphics/RecordingImageBufferSurface.h"

#include "platform/Histogram.h"
#include "platform/graphics/CanvasMetrics.h"
#include "platform/graphics/ExpensiveCanvasHeuristicParameters.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/ImageBuffer.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkPictureRecorder.h"
#include "wtf/PassRefPtr.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

RecordingImageBufferSurface::RecordingImageBufferSurface(
    const IntSize& size,
    std::unique_ptr<RecordingImageBufferFallbackSurfaceFactory> fallbackFactory,
    OpacityMode opacityMode,
    sk_sp<SkColorSpace> colorSpace,
    SkColorType colorType)
    : ImageBufferSurface(size, opacityMode, std::move(colorSpace), colorType)
=======
#include "config.h"

#include "platform/graphics/RecordingImageBufferSurface.h"

#include "platform/graphics/ExpensiveCanvasHeuristicParameters.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/ImageBuffer.h"
#include "public/platform/Platform.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkPictureRecorder.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/PassRefPtr.h"

namespace blink {

RecordingImageBufferSurface::RecordingImageBufferSurface(const IntSize& size, PassOwnPtr<RecordingImageBufferFallbackSurfaceFactory> fallbackFactory, OpacityMode opacityMode)
    : ImageBufferSurface(size, opacityMode)
>>>>>>> miniblink49
    , m_imageBuffer(0)
    , m_currentFramePixelCount(0)
    , m_previousFramePixelCount(0)
    , m_frameWasCleared(true)
    , m_didRecordDrawCommandsInCurrentFrame(false)
    , m_currentFrameHasExpensiveOp(false)
    , m_previousFrameHasExpensiveOp(false)
<<<<<<< HEAD
    , m_fallbackFactory(std::move(fallbackFactory))
=======
    , m_fallbackFactory(fallbackFactory)
>>>>>>> miniblink49
{
    initializeCurrentFrame();
}

<<<<<<< HEAD
RecordingImageBufferSurface::~RecordingImageBufferSurface() { }

void RecordingImageBufferSurface::initializeCurrentFrame()
{
    static SkRTreeFactory rTreeFactory;
    m_currentFrame = WTF::wrapUnique(new SkPictureRecorder);
    SkCanvas* canvas = m_currentFrame->beginRecording(
        size().width(), size().height(), &rTreeFactory);
    // Always save an initial frame, to support resetting the top level matrix
    // and clip.
    canvas->save();

    if (m_imageBuffer) {
        m_imageBuffer->resetCanvas(canvas);
=======
RecordingImageBufferSurface::~RecordingImageBufferSurface()
{ }

bool RecordingImageBufferSurface::initializeCurrentFrame()
{
    static SkRTreeFactory rTreeFactory;
    m_currentFrame = adoptPtr(new SkPictureRecorder);
    m_currentFrame->beginRecording(size().width(), size().height(), &rTreeFactory);
    if (m_imageBuffer) {
        m_imageBuffer->resetCanvas(m_currentFrame->getRecordingCanvas());
>>>>>>> miniblink49
    }
    m_didRecordDrawCommandsInCurrentFrame = false;
    m_currentFrameHasExpensiveOp = false;
    m_currentFramePixelCount = 0;
<<<<<<< HEAD
=======
    return true;
>>>>>>> miniblink49
}

void RecordingImageBufferSurface::setImageBuffer(ImageBuffer* imageBuffer)
{
    m_imageBuffer = imageBuffer;
    if (m_currentFrame && m_imageBuffer) {
        m_imageBuffer->resetCanvas(m_currentFrame->getRecordingCanvas());
    }
    if (m_fallbackSurface) {
        m_fallbackSurface->setImageBuffer(imageBuffer);
    }
}

<<<<<<< HEAD
bool RecordingImageBufferSurface::writePixels(const SkImageInfo& origInfo,
    const void* pixels,
    size_t rowBytes,
    int x,
    int y)
{
    if (!m_fallbackSurface) {
        if (x <= 0 && y <= 0 && x + origInfo.width() >= size().width() && y + origInfo.height() >= size().height()) {
            willOverwriteCanvas();
        }
        fallBackToRasterCanvas(FallbackReasonWritePixels);
    }
    return m_fallbackSurface->writePixels(origInfo, pixels, rowBytes, x, y);
}

void RecordingImageBufferSurface::fallBackToRasterCanvas(
    FallbackReason reason)
{
    ASSERT(m_fallbackFactory);
    CHECK(reason != FallbackReasonUnknown);

=======
void RecordingImageBufferSurface::willAccessPixels()
{
    if (m_fallbackSurface)
        m_fallbackSurface->willAccessPixels();
    else
        fallBackToRasterCanvas();
}

void RecordingImageBufferSurface::fallBackToRasterCanvas()
{
>>>>>>> miniblink49
    if (m_fallbackSurface) {
        ASSERT(!m_currentFrame);
        return;
    }

<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(
        EnumerationHistogram, canvasFallbackHistogram,
        new EnumerationHistogram("Canvas.DisplayListFallbackReason",
            FallbackReasonCount));
    canvasFallbackHistogram.count(reason);

    m_fallbackSurface = m_fallbackFactory->createSurface(
        size(), getOpacityMode(), colorSpace(), colorType());
=======
    m_fallbackSurface = m_fallbackFactory->createSurface(size(), opacityMode());
>>>>>>> miniblink49
    m_fallbackSurface->setImageBuffer(m_imageBuffer);

    if (m_previousFrame) {
        m_previousFrame->playback(m_fallbackSurface->canvas());
<<<<<<< HEAD
        m_previousFrame.reset();
    }

    if (m_currentFrame) {
        m_currentFrame->finishRecordingAsPicture()->playback(
            m_fallbackSurface->canvas());
        m_currentFrame.reset();
=======
        m_previousFrame.clear();
    }

    if (m_currentFrame) {
        RefPtr<SkPicture> currentPicture = adoptRef(m_currentFrame->endRecording());
        currentPicture->playback(m_fallbackSurface->canvas());
        m_currentFrame.clear();
>>>>>>> miniblink49
    }

    if (m_imageBuffer) {
        m_imageBuffer->resetCanvas(m_fallbackSurface->canvas());
    }

<<<<<<< HEAD
    CanvasMetrics::countCanvasContextUsage(
        CanvasMetrics::DisplayList2DCanvasFallbackToRaster);
}

static RecordingImageBufferSurface::FallbackReason
snapshotReasonToFallbackReason(SnapshotReason reason)
{
    switch (reason) {
    case SnapshotReasonUnknown:
        return RecordingImageBufferSurface::FallbackReasonUnknown;
    case SnapshotReasonGetImageData:
        return RecordingImageBufferSurface::FallbackReasonSnapshotForGetImageData;
    case SnapshotReasonPaint:
        return RecordingImageBufferSurface::FallbackReasonSnapshotForPaint;
    case SnapshotReasonToDataURL:
        return RecordingImageBufferSurface::FallbackReasonSnapshotForToDataURL;
    case SnapshotReasonToBlob:
        return RecordingImageBufferSurface::FallbackReasonSnapshotForToBlob;
    case SnapshotReasonCanvasListenerCapture:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForCanvasListenerCapture;
    case SnapshotReasonDrawImage:
        return RecordingImageBufferSurface::FallbackReasonSnapshotForDrawImage;
    case SnapshotReasonCreatePattern:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForCreatePattern;
    case SnapshotReasonTransferToImageBitmap:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForTransferToImageBitmap;
    case SnapshotReasonUnitTests:
        return RecordingImageBufferSurface::FallbackReasonSnapshotForUnitTests;
    case SnapshotReasonGetCopiedImage:
        return RecordingImageBufferSurface::FallbackReasonSnapshotGetCopiedImage;
    case SnapshotReasonWebGLDrawImageIntoBuffer:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotWebGLDrawImageIntoBuffer;
    case SnapshotReasonWebGLTexImage2D:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForWebGLTexImage2D;
    case SnapshotReasonWebGLTexSubImage2D:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForWebGLTexSubImage2D;
    case SnapshotReasonWebGLTexImage3D:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForWebGLTexImage3D;
    case SnapshotReasonWebGLTexSubImage3D:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForWebGLTexSubImage3D;
    case SnapshotReasonCopyToClipboard:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForCopyToClipboard;
    case SnapshotReasonCreateImageBitmap:
        return RecordingImageBufferSurface::
            FallbackReasonSnapshotForCreateImageBitmap;
    }
    NOTREACHED();
    return RecordingImageBufferSurface::FallbackReasonUnknown;
}

sk_sp<SkImage> RecordingImageBufferSurface::newImageSnapshot(
    AccelerationHint hint,
    SnapshotReason reason)
{
    if (!m_fallbackSurface)
        fallBackToRasterCanvas(snapshotReasonToFallbackReason(reason));
    return m_fallbackSurface->newImageSnapshot(hint, reason);
}

SkCanvas* RecordingImageBufferSurface::canvas()
=======
}

PassRefPtr<SkImage> RecordingImageBufferSurface::newImageSnapshot() const
{
    if (!m_fallbackSurface)
        const_cast<RecordingImageBufferSurface*>(this)->fallBackToRasterCanvas();
    return m_fallbackSurface->newImageSnapshot();
}

SkCanvas* RecordingImageBufferSurface::canvas() const
>>>>>>> miniblink49
{
    if (m_fallbackSurface)
        return m_fallbackSurface->canvas();

    ASSERT(m_currentFrame->getRecordingCanvas());
    return m_currentFrame->getRecordingCanvas();
}

<<<<<<< HEAD
static RecordingImageBufferSurface::FallbackReason
disableDeferralReasonToFallbackReason(DisableDeferralReason reason)
{
    switch (reason) {
    case DisableDeferralReasonUnknown:
        return RecordingImageBufferSurface::FallbackReasonUnknown;
    case DisableDeferralReasonExpensiveOverdrawHeuristic:
        return RecordingImageBufferSurface::
            FallbackReasonExpensiveOverdrawHeuristic;
    case DisableDeferralReasonUsingTextureBackedPattern:
        return RecordingImageBufferSurface::FallbackReasonTextureBackedPattern;
    case DisableDeferralReasonDrawImageOfVideo:
        return RecordingImageBufferSurface::FallbackReasonDrawImageOfVideo;
    case DisableDeferralReasonDrawImageOfAnimated2dCanvas:
        return RecordingImageBufferSurface::
            FallbackReasonDrawImageOfAnimated2dCanvas;
    case DisableDeferralReasonSubPixelTextAntiAliasingSupport:
        return RecordingImageBufferSurface::
            FallbackReasonSubPixelTextAntiAliasingSupport;
    case DisableDeferralDrawImageWithTextureBackedSourceImage:
        return RecordingImageBufferSurface::
            FallbackReasonDrawImageWithTextureBackedSourceImage;
    case DisableDeferralReasonCount:
        ASSERT_NOT_REACHED();
        break;
    }
    ASSERT_NOT_REACHED();
    return RecordingImageBufferSurface::FallbackReasonUnknown;
}

void RecordingImageBufferSurface::disableDeferral(
    DisableDeferralReason reason)
{
    if (!m_fallbackSurface)
        fallBackToRasterCanvas(disableDeferralReasonToFallbackReason(reason));
}

sk_sp<SkPicture> RecordingImageBufferSurface::getPicture()
=======
PassRefPtr<SkPicture> RecordingImageBufferSurface::getPicture()
>>>>>>> miniblink49
{
    if (m_fallbackSurface)
        return nullptr;

<<<<<<< HEAD
    FallbackReason fallbackReason = FallbackReasonUnknown;
    bool canUsePicture = finalizeFrameInternal(&fallbackReason);
    m_imageBuffer->didFinalizeFrame();

    ASSERT(canUsePicture || m_fallbackFactory);

=======
    bool canUsePicture = finalizeFrameInternal();
    m_imageBuffer->didFinalizeFrame();

>>>>>>> miniblink49
    if (canUsePicture) {
        return m_previousFrame;
    }

    if (!m_fallbackSurface)
<<<<<<< HEAD
        fallBackToRasterCanvas(fallbackReason);
    return nullptr;
}

void RecordingImageBufferSurface::finalizeFrame(const FloatRect& dirtyRect)
=======
        fallBackToRasterCanvas();
    return nullptr;
}

void RecordingImageBufferSurface::finalizeFrame(const FloatRect &dirtyRect)
>>>>>>> miniblink49
{
    if (m_fallbackSurface) {
        m_fallbackSurface->finalizeFrame(dirtyRect);
        return;
    }

<<<<<<< HEAD
    FallbackReason fallbackReason = FallbackReasonUnknown;
    if (!finalizeFrameInternal(&fallbackReason))
        fallBackToRasterCanvas(fallbackReason);
}

static RecordingImageBufferSurface::FallbackReason flushReasonToFallbackReason(
    FlushReason reason)
{
    switch (reason) {
    case FlushReasonUnknown:
        return RecordingImageBufferSurface::FallbackReasonUnknown;
    case FlushReasonInitialClear:
        return RecordingImageBufferSurface::FallbackReasonFlushInitialClear;
    case FlushReasonDrawImageOfWebGL:
        return RecordingImageBufferSurface::
            FallbackReasonFlushForDrawImageOfWebGL;
    }
    ASSERT_NOT_REACHED();
    return RecordingImageBufferSurface::FallbackReasonUnknown;
}

void RecordingImageBufferSurface::flush(FlushReason reason)
{
    if (!m_fallbackSurface)
        fallBackToRasterCanvas(flushReasonToFallbackReason(reason));
    m_fallbackSurface->flush(reason);
=======
    if (!finalizeFrameInternal())
        fallBackToRasterCanvas();
>>>>>>> miniblink49
}

void RecordingImageBufferSurface::willOverwriteCanvas()
{
    m_frameWasCleared = true;
<<<<<<< HEAD
    m_previousFrame.reset();
=======
    m_previousFrame.clear();
>>>>>>> miniblink49
    m_previousFrameHasExpensiveOp = false;
    m_previousFramePixelCount = 0;
    if (m_didRecordDrawCommandsInCurrentFrame) {
        // Discard previous draw commands
<<<<<<< HEAD
        m_currentFrame->finishRecordingAsPicture();
=======
        adoptRef(m_currentFrame->endRecording());
>>>>>>> miniblink49
        initializeCurrentFrame();
    }
}

void RecordingImageBufferSurface::didDraw(const FloatRect& rect)
{
    m_didRecordDrawCommandsInCurrentFrame = true;
    IntRect pixelBounds = enclosingIntRect(rect);
    m_currentFramePixelCount += pixelBounds.width() * pixelBounds.height();
}

<<<<<<< HEAD
bool RecordingImageBufferSurface::finalizeFrameInternal(
    FallbackReason* fallbackReason)
{
    CHECK(!m_fallbackSurface);
    CHECK(m_currentFrame);
    ASSERT(m_currentFrame->getRecordingCanvas());
    ASSERT(fallbackReason);
    ASSERT(*fallbackReason == FallbackReasonUnknown);
=======
bool RecordingImageBufferSurface::finalizeFrameInternal()
{
    ASSERT(!m_fallbackSurface);
    ASSERT(m_currentFrame);
    ASSERT(m_currentFrame->getRecordingCanvas());
>>>>>>> miniblink49

    if (!m_imageBuffer->isDirty()) {
        if (!m_previousFrame) {
            // Create an initial blank frame
<<<<<<< HEAD
            m_previousFrame = m_currentFrame->finishRecordingAsPicture();
            initializeCurrentFrame();
        }
        CHECK(m_currentFrame);
        return true;
    }

    if (!m_frameWasCleared) {
        *fallbackReason = FallbackReasonCanvasNotClearedBetweenFrames;
        return false;
    }

    if (m_fallbackFactory && m_currentFrame->getRecordingCanvas()->getSaveCount() - 1 > ExpensiveCanvasHeuristicParameters::ExpensiveRecordingStackDepth) {
        // (getSaveCount() decremented to account  for the intial recording canvas
        // save frame.)
        *fallbackReason = FallbackReasonRunawayStateStack;
        return false;
    }

    m_previousFrame = m_currentFrame->finishRecordingAsPicture();
    m_previousFrameHasExpensiveOp = m_currentFrameHasExpensiveOp;
    m_previousFramePixelCount = m_currentFramePixelCount;
    initializeCurrentFrame();
=======
            m_previousFrame = adoptRef(m_currentFrame->endRecording());
            initializeCurrentFrame();
        }
        return m_currentFrame;
    }

    if (!m_frameWasCleared || m_currentFrame->getRecordingCanvas()->getSaveCount() > ExpensiveCanvasHeuristicParameters::ExpensiveRecordingStackDepth) {
        return false;
    }

    m_previousFrame = adoptRef(m_currentFrame->endRecording());
    m_previousFrameHasExpensiveOp = m_currentFrameHasExpensiveOp;
    m_previousFramePixelCount = m_currentFramePixelCount;
    if (!initializeCurrentFrame())
        return false;
>>>>>>> miniblink49

    m_frameWasCleared = false;
    return true;
}

<<<<<<< HEAD
void RecordingImageBufferSurface::draw(GraphicsContext& context,
    const FloatRect& destRect,
    const FloatRect& srcRect,
    SkBlendMode op)
=======
void RecordingImageBufferSurface::willDrawVideo()
{
    // Video draws need to be synchronous
    if (!m_fallbackSurface)
        fallBackToRasterCanvas();
}

void RecordingImageBufferSurface::draw(GraphicsContext* context, const FloatRect& destRect, const FloatRect& srcRect, SkXfermode::Mode op)
>>>>>>> miniblink49
{
    if (m_fallbackSurface) {
        m_fallbackSurface->draw(context, destRect, srcRect, op);
        return;
    }

<<<<<<< HEAD
    sk_sp<SkPicture> picture = getPicture();
    if (picture) {
        context.compositePicture(std::move(picture), destRect, srcRect, op);
=======
    RefPtr<SkPicture> picture = getPicture();
    if (picture) {
        context->compositePicture(picture.get(), destRect, srcRect, op);
>>>>>>> miniblink49
    } else {
        ImageBufferSurface::draw(context, destRect, srcRect, op);
    }
}

bool RecordingImageBufferSurface::isExpensiveToPaint()
{
    if (m_fallbackSurface)
        return m_fallbackSurface->isExpensiveToPaint();

    if (m_didRecordDrawCommandsInCurrentFrame) {
        if (m_currentFrameHasExpensiveOp)
            return true;

        if (m_currentFramePixelCount >= (size().width() * size().height() * ExpensiveCanvasHeuristicParameters::ExpensiveOverdrawThreshold))
            return true;

        if (m_frameWasCleared)
            return false; // early exit because previous frame is overdrawn
    }

    if (m_previousFrame) {
        if (m_previousFrameHasExpensiveOp)
            return true;

        if (m_previousFramePixelCount >= (size().width() * size().height() * ExpensiveCanvasHeuristicParameters::ExpensiveOverdrawThreshold))
            return true;
    }

    return false;
}

// Fallback passthroughs

<<<<<<< HEAD
=======
const SkBitmap& RecordingImageBufferSurface::bitmap()
{
    if (m_fallbackSurface)
        return m_fallbackSurface->bitmap();
    return ImageBufferSurface::bitmap();
}

>>>>>>> miniblink49
bool RecordingImageBufferSurface::restore()
{
    if (m_fallbackSurface)
        return m_fallbackSurface->restore();
    return ImageBufferSurface::restore();
}

WebLayer* RecordingImageBufferSurface::layer() const
{
    if (m_fallbackSurface)
        return m_fallbackSurface->layer();
    return ImageBufferSurface::layer();
}

bool RecordingImageBufferSurface::isAccelerated() const
{
    if (m_fallbackSurface)
        return m_fallbackSurface->isAccelerated();
    return ImageBufferSurface::isAccelerated();
}

void RecordingImageBufferSurface::setIsHidden(bool hidden)
{
    if (m_fallbackSurface)
        m_fallbackSurface->setIsHidden(hidden);
    else
        ImageBufferSurface::setIsHidden(hidden);
}

} // namespace blink
