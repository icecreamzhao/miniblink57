// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef RecordingImageBufferSurface_h
#define RecordingImageBufferSurface_h

#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/ImageBufferSurface.h"
#include "public/platform/WebThread.h"
<<<<<<< HEAD
#include "third_party/skia/include/core/SkRefCnt.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
#include <memory>

class SkCanvas;
=======
#include "third_party/skia/include/core/SkCanvas.h"
#include "wtf/LinkedStack.h"
#include "wtf/OwnPtr.h"
#include "wtf/RefPtr.h"

>>>>>>> miniblink49
class SkPicture;
class SkPictureRecorder;

namespace blink {

class ImageBuffer;
class RecordingImageBufferSurfaceTest;

class RecordingImageBufferFallbackSurfaceFactory {
<<<<<<< HEAD
    USING_FAST_MALLOC(RecordingImageBufferFallbackSurfaceFactory);
    WTF_MAKE_NONCOPYABLE(RecordingImageBufferFallbackSurfaceFactory);

public:
    virtual std::unique_ptr<ImageBufferSurface> createSurface(const IntSize&,
        OpacityMode,
        sk_sp<SkColorSpace>,
        SkColorType)
        = 0;
    virtual ~RecordingImageBufferFallbackSurfaceFactory() { }

protected:
    RecordingImageBufferFallbackSurfaceFactory() { }
};

class PLATFORM_EXPORT RecordingImageBufferSurface : public ImageBufferSurface {
    WTF_MAKE_NONCOPYABLE(RecordingImageBufferSurface);
    USING_FAST_MALLOC(RecordingImageBufferSurface);

public:
    // If the fallbackFactory is null the buffer surface should only be used
    // for one frame and should not be used for any operations which need a
    // raster surface, (i.e. writePixels).
    // Only #getPicture should be used to access the resulting frame.
    RecordingImageBufferSurface(
        const IntSize&,
        std::unique_ptr<RecordingImageBufferFallbackSurfaceFactory>
            fallbackFactory
        = nullptr,
        OpacityMode = NonOpaque,
        sk_sp<SkColorSpace> = nullptr,
        SkColorType = kN32_SkColorType);
    ~RecordingImageBufferSurface() override;

    // Implementation of ImageBufferSurface interfaces
    SkCanvas* canvas() override;
    void disableDeferral(DisableDeferralReason) override;
    sk_sp<SkPicture> getPicture() override;
    void flush(FlushReason) override;
    void didDraw(const FloatRect&) override;
    bool isValid() const override { return true; }
    bool isRecording() const override { return !m_fallbackSurface; }
    bool writePixels(const SkImageInfo& origInfo,
        const void* pixels,
        size_t rowBytes,
        int x,
        int y) override;
    void willOverwriteCanvas() override;
    virtual void finalizeFrame(const FloatRect&);
    void setImageBuffer(ImageBuffer*) override;
    sk_sp<SkImage> newImageSnapshot(AccelerationHint, SnapshotReason) override;
    void draw(GraphicsContext&,
        const FloatRect& destRect,
        const FloatRect& srcRect,
        SkBlendMode) override;
=======
public:
    virtual PassOwnPtr<ImageBufferSurface> createSurface(const IntSize&, OpacityMode) = 0;
    virtual ~RecordingImageBufferFallbackSurfaceFactory() { }
};

class PLATFORM_EXPORT RecordingImageBufferSurface : public ImageBufferSurface {
    WTF_MAKE_NONCOPYABLE(RecordingImageBufferSurface); WTF_MAKE_FAST_ALLOCATED(RecordingImageBufferSurface);
public:
    RecordingImageBufferSurface(const IntSize&, PassOwnPtr<RecordingImageBufferFallbackSurfaceFactory> fallbackFactory, OpacityMode = NonOpaque);
    ~RecordingImageBufferSurface() override;

    // Implementation of ImageBufferSurface interfaces
    SkCanvas* canvas() const override;
    PassRefPtr<SkPicture> getPicture() override;
    void willDrawVideo() override;
    void didDraw(const FloatRect&) override;
    bool isValid() const override { return true; }
    bool isRecording() const override { return !m_fallbackSurface; }
    void willAccessPixels() override;
    void willOverwriteCanvas() override;
    virtual void finalizeFrame(const FloatRect&);
    void setImageBuffer(ImageBuffer*) override;
    PassRefPtr<SkImage> newImageSnapshot() const override;
    void draw(GraphicsContext*, const FloatRect& destRect, const FloatRect& srcRect, SkXfermode::Mode) override;
>>>>>>> miniblink49
    bool isExpensiveToPaint() override;
    void setHasExpensiveOp() override { m_currentFrameHasExpensiveOp = true; }

    // Passthroughs to fallback surface
<<<<<<< HEAD
=======
    const SkBitmap& bitmap() override;
>>>>>>> miniblink49
    bool restore() override;
    WebLayer* layer() const override;
    bool isAccelerated() const override;
    void setIsHidden(bool) override;

<<<<<<< HEAD
    // This enum is used in a UMA histogram.
    enum FallbackReason {
        FallbackReasonUnknown = 0, // This value should never appear in production histograms
        FallbackReasonCanvasNotClearedBetweenFrames = 1,
        FallbackReasonRunawayStateStack = 2,
        FallbackReasonWritePixels = 3,
        FallbackReasonFlushInitialClear = 4,
        FallbackReasonFlushForDrawImageOfWebGL = 5,
        FallbackReasonSnapshotForGetImageData = 6,
        FallbackReasonSnapshotForPaint = 8,
        FallbackReasonSnapshotForToDataURL = 9,
        FallbackReasonSnapshotForToBlob = 10,
        FallbackReasonSnapshotForCanvasListenerCapture = 11,
        FallbackReasonSnapshotForDrawImage = 12,
        FallbackReasonSnapshotForCreatePattern = 13,
        FallbackReasonExpensiveOverdrawHeuristic = 14,
        FallbackReasonTextureBackedPattern = 15,
        FallbackReasonDrawImageOfVideo = 16,
        FallbackReasonDrawImageOfAnimated2dCanvas = 17,
        FallbackReasonSubPixelTextAntiAliasingSupport = 18,
        FallbackReasonDrawImageWithTextureBackedSourceImage = 19,
        FallbackReasonSnapshotForTransferToImageBitmap = 20,
        FallbackReasonSnapshotForUnitTests = 21, // This value should never appear in production histograms
        FallbackReasonSnapshotGetCopiedImage = 22,
        FallbackReasonSnapshotWebGLDrawImageIntoBuffer = 23,
        FallbackReasonSnapshotForWebGLTexImage2D = 24,
        FallbackReasonSnapshotForWebGLTexSubImage2D = 25,
        FallbackReasonSnapshotForWebGLTexImage3D = 26,
        FallbackReasonSnapshotForWebGLTexSubImage3D = 27,
        FallbackReasonSnapshotForCopyToClipboard = 28,
        FallbackReasonSnapshotForCreateImageBitmap = 29,
        FallbackReasonCount,
    };

private:
    friend class RecordingImageBufferSurfaceTest; // for unit testing
    void fallBackToRasterCanvas(FallbackReason);
    void initializeCurrentFrame();
    bool finalizeFrameInternal(FallbackReason*);
    int approximateOpCount();

    std::unique_ptr<SkPictureRecorder> m_currentFrame;
    sk_sp<SkPicture> m_previousFrame;
    std::unique_ptr<ImageBufferSurface> m_fallbackSurface;
=======
private:
    friend class RecordingImageBufferSurfaceTest; // for unit testing
    void fallBackToRasterCanvas();
    bool initializeCurrentFrame();
    bool finalizeFrameInternal();
    int approximateOpCount();

    OwnPtr<SkPictureRecorder> m_currentFrame;
    RefPtr<SkPicture> m_previousFrame;
    OwnPtr<ImageBufferSurface> m_fallbackSurface;
>>>>>>> miniblink49
    ImageBuffer* m_imageBuffer;
    int m_initialSaveCount;
    int m_currentFramePixelCount;
    int m_previousFramePixelCount;
    bool m_frameWasCleared;
    bool m_didRecordDrawCommandsInCurrentFrame;
    bool m_currentFrameHasExpensiveOp;
    bool m_previousFrameHasExpensiveOp;
<<<<<<< HEAD
    std::unique_ptr<RecordingImageBufferFallbackSurfaceFactory> m_fallbackFactory;
=======
    OwnPtr<RecordingImageBufferFallbackSurfaceFactory> m_fallbackFactory;
>>>>>>> miniblink49
};

} // namespace blink

#endif
