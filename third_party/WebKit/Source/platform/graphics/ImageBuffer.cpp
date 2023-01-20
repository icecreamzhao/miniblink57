/*
 * Copyright (c) 2008, Google Inc. All rights reserved.
 * Copyright (C) 2009 Dirk Schulze <krit@webkit.org>
 * Copyright (C) 2010 Torch Mobile (Beijing) Co. Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/graphics/ImageBuffer.h"

#include "gpu/command_buffer/client/gles2_interface.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/geometry/IntRect.h"
#include "platform/graphics/ExpensiveCanvasHeuristicParameters.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/ImageBufferClient.h"
#include "platform/graphics/RecordingImageBufferSurface.h"
#include "platform/graphics/StaticBitmapImage.h"
=======
#include "config.h"
#include "platform/graphics/ImageBuffer.h"

//#include "GrContext.h"
#include "platform/MIMETypeRegistry.h"
#include "platform/geometry/IntRect.h"
#include "platform/graphics/BitmapImage.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/GraphicsTypes3D.h"
#include "platform/graphics/ImageBufferClient.h"
>>>>>>> miniblink49
#include "platform/graphics/UnacceleratedImageBufferSurface.h"
#include "platform/graphics/gpu/DrawingBuffer.h"
#include "platform/graphics/gpu/Extensions3DUtil.h"
#include "platform/graphics/skia/SkiaUtils.h"
<<<<<<< HEAD
#include "platform/image-encoders/JPEGImageEncoder.h"
#include "platform/image-encoders/PNGImageEncoder.h"
// #include "platform/image-encoders/WEBPImageEncoder.h"
#include "platform/network/mime/MIMETypeRegistry.h"
#include "public/platform/Platform.h"
#include "public/platform/WebGraphicsContext3DProvider.h"
//#include "skia/ext/texture_handle.h"
#include "third_party/skia/include/core/SkPicture.h"
#include "third_party/skia/include/core/SkSwizzle.h"
#include "third_party/skia/include/gpu/GrContext.h"
//#include "third_party/skia/include/gpu/gl/GrGLTypes.h"
#include "wtf/CheckedNumeric.h"
#include "wtf/MathExtras.h"
#include "wtf/PtrUtil.h"
#include "wtf/Vector.h"
#include "wtf/text/Base64.h"
#include "wtf/text/WTFString.h"
#include "wtf/typed_arrays/ArrayBufferContents.h"
#include <memory>

namespace blink {

std::unique_ptr<ImageBuffer> ImageBuffer::create(
    std::unique_ptr<ImageBufferSurface> surface)
{
    if (!surface->isValid())
        return nullptr;
    return WTF::wrapUnique(new ImageBuffer(std::move(surface)));
}

std::unique_ptr<ImageBuffer> ImageBuffer::create(
    const IntSize& size,
    OpacityMode opacityMode,
    ImageInitializationMode initializationMode,
    sk_sp<SkColorSpace> colorSpace)
{
    std::unique_ptr<ImageBufferSurface> surface(
        WTF::wrapUnique(new UnacceleratedImageBufferSurface(
            size, opacityMode, initializationMode, std::move(colorSpace))));
    if (!surface->isValid())
        return nullptr;
    return WTF::wrapUnique(new ImageBuffer(std::move(surface)));
}

ImageBuffer::ImageBuffer(std::unique_ptr<ImageBufferSurface> surface)
    : m_weakPtrFactory(this)
    , m_snapshotState(InitialSnapshotState)
    , m_surface(std::move(surface))
    , m_client(0)
    , m_gpuMemoryUsage(0)
{
    m_surface->setImageBuffer(this);
    updateGPUMemoryUsage();
}

intptr_t ImageBuffer::s_globalGPUMemoryUsage = 0;
unsigned ImageBuffer::s_globalAcceleratedImageBufferCount = 0;

ImageBuffer::~ImageBuffer()
{
    if (m_gpuMemoryUsage) {
        DCHECK_GT(s_globalAcceleratedImageBufferCount, 0u);
        s_globalAcceleratedImageBufferCount--;
    }
    ImageBuffer::s_globalGPUMemoryUsage -= m_gpuMemoryUsage;
    m_surface->setImageBuffer(nullptr);
}

bool ImageBuffer::canCreateImageBuffer(const IntSize& size)
{
    if (size.isEmpty())
        return false;
    CheckedNumeric<int> area = size.width();
    area *= size.height();
    if (!area.IsValid() || area.ValueOrDie() > kMaxCanvasArea)
        return false;
    if (size.width() > kMaxSkiaDim || size.height() > kMaxSkiaDim)
        return false;
    return true;
=======
#include "platform/image-encoders/skia/JPEGImageEncoder.h"
#include "platform/image-encoders/skia/PNGImageEncoder.h"
#include "platform/image-encoders/gdiplus/GDIPlusImageEncoder.h"
#include "public/platform/Platform.h"
#include "public/platform/WebExternalTextureMailbox.h"
#include "public/platform/WebGraphicsContext3D.h"
#include "public/platform/WebGraphicsContext3DProvider.h"
#include "third_party/skia/include/core/SkPicture.h"
#include "wtf/ArrayBufferContents.h"
#include "wtf/MathExtras.h"
#include "wtf/Vector.h"
#include "wtf/text/Base64.h"
#include "wtf/text/WTFString.h"

namespace blink {

PassOwnPtr<ImageBuffer> ImageBuffer::create(PassOwnPtr<ImageBufferSurface> surface)
{
    if (!surface->isValid())
        return nullptr;
    return adoptPtr(new ImageBuffer(surface));
}

PassOwnPtr<ImageBuffer> ImageBuffer::create(const IntSize& size, OpacityMode opacityMode)
{
    OwnPtr<ImageBufferSurface> surface(adoptPtr(new UnacceleratedImageBufferSurface(size, opacityMode)));
    if (!surface->isValid())
        return nullptr;
    return adoptPtr(new ImageBuffer(surface.release()));
}

ImageBuffer::ImageBuffer(PassOwnPtr<ImageBufferSurface> surface)
    : m_surface(surface)
    , m_client(0)
{
    m_surface->setImageBuffer(this);
}

ImageBuffer::~ImageBuffer()
{
>>>>>>> miniblink49
}

SkCanvas* ImageBuffer::canvas() const
{
<<<<<<< HEAD
    return m_surface->canvas();
}

void ImageBuffer::disableDeferral(DisableDeferralReason reason) const
{
    return m_surface->disableDeferral(reason);
}

bool ImageBuffer::writePixels(const SkImageInfo& info,
    const void* pixels,
    size_t rowBytes,
    int x,
    int y)
{
    return m_surface->writePixels(info, pixels, rowBytes, x, y);
=======
    if (!isSurfaceValid())
        return nullptr;
    return m_surface->canvas();
}

const SkBitmap& ImageBuffer::bitmap() const
{
    return m_surface->bitmap();
>>>>>>> miniblink49
}

bool ImageBuffer::isSurfaceValid() const
{
    return m_surface->isValid();
}

bool ImageBuffer::isDirty()
{
    return m_client ? m_client->isDirty() : false;
}

void ImageBuffer::didFinalizeFrame()
{
    if (m_client)
        m_client->didFinalizeFrame();
}

<<<<<<< HEAD
void ImageBuffer::finalizeFrame(const FloatRect& dirtyRect)
=======
void ImageBuffer::finalizeFrame(const FloatRect &dirtyRect)
>>>>>>> miniblink49
{
    m_surface->finalizeFrame(dirtyRect);
    didFinalizeFrame();
}

bool ImageBuffer::restoreSurface() const
{
    return m_surface->isValid() || m_surface->restore();
}

void ImageBuffer::notifySurfaceInvalid()
{
    if (m_client)
        m_client->notifySurfaceInvalid();
}

<<<<<<< HEAD
void ImageBuffer::resetCanvas(SkCanvas* canvas) const
{
    if (m_client)
        m_client->restoreCanvasMatrixClipStack(canvas);
}

sk_sp<SkImage> ImageBuffer::newSkImageSnapshot(AccelerationHint hint,
    SnapshotReason reason) const
{
    if (m_snapshotState == InitialSnapshotState)
        m_snapshotState = DidAcquireSnapshot;

    if (!isSurfaceValid())
        return nullptr;
    return m_surface->newImageSnapshot(hint, reason);
}

PassRefPtr<Image> ImageBuffer::newImageSnapshot(AccelerationHint hint,
    SnapshotReason reason) const
{
    sk_sp<SkImage> snapshot = newSkImageSnapshot(hint, reason);
    if (!snapshot)
        return nullptr;
    return StaticBitmapImage::create(std::move(snapshot));
}

void ImageBuffer::didDraw(const FloatRect& rect) const
{
    if (m_snapshotState == DidAcquireSnapshot)
        m_snapshotState = DrawnToAfterSnapshot;
    m_surface->didDraw(rect);
=======
void ImageBuffer::resetCanvas(SkCanvas* canvas)
{
    if (m_client)
        m_client->restoreCanvasMatrixClipStack();
}

PassRefPtr<SkImage> ImageBuffer::newImageSnapshot() const
{
    return m_surface->newImageSnapshot();
}

static SkBitmap deepSkBitmapCopy(const SkBitmap& bitmap)
{
    SkBitmap tmp;
    if (!bitmap.deepCopyTo(&tmp))
        bitmap.copyTo(&tmp, bitmap.colorType());

    return tmp;
}

PassRefPtr<Image> ImageBuffer::copyImage(BackingStoreCopy copyBehavior, ScaleBehavior) const
{
    if (!isSurfaceValid())
        return BitmapImage::create(SkBitmap());

    const SkBitmap& bitmap = m_surface->bitmap();
    return BitmapImage::create(copyBehavior == CopyBackingStore ? deepSkBitmapCopy(bitmap) : bitmap);
}

BackingStoreCopy ImageBuffer::fastCopyImageMode()
{
    return DontCopyBackingStore;
>>>>>>> miniblink49
}

WebLayer* ImageBuffer::platformLayer() const
{
    return m_surface->layer();
}

<<<<<<< HEAD
bool ImageBuffer::copyToPlatformTexture(SnapshotReason reason,
    gpu::gles2::GLES2Interface* gl,
    GLuint texture,
    GLenum internalFormat,
    GLenum destType,
    GLint level,
    bool premultiplyAlpha,
    bool flipY,
    const IntPoint& destPoint,
    const IntRect& sourceSubRectangle)
{
    //   if (!Extensions3DUtil::canUseCopyTextureCHROMIUM(
    //           GL_TEXTURE_2D, internalFormat, destType, level))
    //     return false;
    //
    //   if (!isSurfaceValid())
    //     return false;
    //
    //   sk_sp<const SkImage> textureImage =
    //       m_surface->newImageSnapshot(PreferAcceleration, reason);
    //   if (!textureImage)
    //     return false;
    //
    //   if (!m_surface->isAccelerated())
    //     return false;
    //
    //   DCHECK(textureImage->isTextureBacked());  // The isAccelerated() check above
    //                                             // should guarantee this.
    //   // Get the texture ID, flushing pending operations if needed.
    //   const GrGLTextureInfo* textureInfo = skia::GrBackendObjectToGrGLTextureInfo(
    //       textureImage->getTextureHandle(true));
    //   if (!textureInfo || !textureInfo->fID)
    //     return false;
    //
    //   std::unique_ptr<WebGraphicsContext3DProvider> provider = WTF::wrapUnique(
    //       Platform::current()->createSharedOffscreenGraphicsContext3DProvider());
    //   if (!provider || !provider->grContext())
    //     return false;
    //   gpu::gles2::GLES2Interface* sharedGL = provider->contextGL();
    //
    //   gpu::Mailbox mailbox;
    //
    //   // Contexts may be in a different share group. We must transfer the texture
    //   // through a mailbox first.
    //   sharedGL->GenMailboxCHROMIUM(mailbox.name);
    //   sharedGL->ProduceTextureDirectCHROMIUM(textureInfo->fID, textureInfo->fTarget,
    //                                          mailbox.name);
    //   const GLuint64 sharedFenceSync = sharedGL->InsertFenceSyncCHROMIUM();
    //   sharedGL->Flush();
    //
    //   gpu::SyncToken produceSyncToken;
    //   sharedGL->GenSyncTokenCHROMIUM(sharedFenceSync, produceSyncToken.GetData());
    //   gl->WaitSyncTokenCHROMIUM(produceSyncToken.GetConstData());
    //
    //   GLuint sourceTexture =
    //       gl->CreateAndConsumeTextureCHROMIUM(textureInfo->fTarget, mailbox.name);
    //
    //   // The canvas is stored in a premultiplied format, so unpremultiply if
    //   // necessary. The canvas is also stored in an inverted position, so the flip
    //   // semantics are reversed.
    //   // It is expected that callers of this method have already allocated
    //   // the platform texture with the appropriate size.
    //   gl->CopySubTextureCHROMIUM(sourceTexture, 0, texture, 0, destPoint.x(),
    //                              destPoint.y(), sourceSubRectangle.x(),
    //                              sourceSubRectangle.y(), sourceSubRectangle.width(),
    //                              sourceSubRectangle.height(),
    //                              flipY ? GL_FALSE : GL_TRUE, GL_FALSE,
    //                              premultiplyAlpha ? GL_FALSE : GL_TRUE);
    //
    //   gl->DeleteTextures(1, &sourceTexture);
    //
    //   const GLuint64 contextFenceSync = gl->InsertFenceSyncCHROMIUM();
    //
    //   gl->Flush();
    //
    //   gpu::SyncToken copySyncToken;
    //   gl->GenSyncTokenCHROMIUM(contextFenceSync, copySyncToken.GetData());
    //   sharedGL->WaitSyncTokenCHROMIUM(copySyncToken.GetConstData());
    //   // This disassociates the texture from the mailbox to avoid leaking the
    //   // mapping between the two.
    //   sharedGL->ProduceTextureDirectCHROMIUM(0, textureInfo->fTarget, mailbox.name);
    //
    //   // Undo grContext texture binding changes introduced in this function.
    //   GrContext* grContext = provider->grContext();
    //   CHECK(grContext);  // We already check / early-out above if null.
    //   grContext->resetContext(kTextureBinding_GrGLBackendState);
    DebugBreak();
    return true;
}

bool ImageBuffer::copyRenderingResultsFromDrawingBuffer(
    DrawingBuffer* drawingBuffer,
    SourceDrawingBuffer sourceBuffer)
{
    if (!drawingBuffer || !m_surface->isAccelerated())
        return false;
    std::unique_ptr<WebGraphicsContext3DProvider> provider = WTF::wrapUnique(
        Platform::current()->createSharedOffscreenGraphicsContext3DProvider());
    if (!provider)
        return false;
    gpu::gles2::GLES2Interface* gl = provider->contextGL();
    GLuint textureId = m_surface->getBackingTextureHandleForOverwrite();
    if (!textureId)
        return false;

    gl->Flush();

    //   return drawingBuffer->copyToPlatformTexture(
    //       gl, textureId, GL_RGBA, GL_UNSIGNED_BYTE, 0, true, false, IntPoint(0, 0),
    //       IntRect(IntPoint(0, 0), drawingBuffer->size()), sourceBuffer);
    DebugBreak();
    return nullptr;
}

void ImageBuffer::draw(GraphicsContext& context,
    const FloatRect& destRect,
    const FloatRect* srcPtr,
    SkBlendMode op)
=======
bool ImageBuffer::copyToPlatformTexture(WebGraphicsContext3D* context, Platform3DObject texture, GLenum internalFormat, GLenum destType, GLint level, bool premultiplyAlpha, bool flipY)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (!m_surface->isAccelerated() || !isSurfaceValid())
        return false;

    if (!Extensions3DUtil::canUseCopyTextureCHROMIUM(GL_TEXTURE_2D, internalFormat, destType, level))
        return false;

    RefPtr<const SkImage> textureImage = m_surface->newImageSnapshot();
    if (!textureImage)
        return false;

    ASSERT(textureImage->isTextureBacked()); // isAccelerated() check above should guarantee this
    // Get the texture ID, flushing pending operations if needed.
    Platform3DObject textureId = textureImage->getTextureHandle(true);
    if (!textureId)
        return false;

    OwnPtr<WebGraphicsContext3DProvider> provider = adoptPtr(Platform::current()->createSharedOffscreenGraphicsContext3DProvider());
    if (!provider)
        return false;
    WebGraphicsContext3D* sharedContext = provider->context3d();
    if (!sharedContext)
        return false;

    OwnPtr<WebExternalTextureMailbox> mailbox = adoptPtr(new WebExternalTextureMailbox);

    // Contexts may be in a different share group. We must transfer the texture through a mailbox first
    sharedContext->genMailboxCHROMIUM(mailbox->name);
    sharedContext->produceTextureDirectCHROMIUM(textureId, GL_TEXTURE_2D, mailbox->name);
    sharedContext->flush();

    mailbox->syncPoint = sharedContext->insertSyncPoint();

    context->waitSyncPoint(mailbox->syncPoint);
    Platform3DObject sourceTexture = context->createAndConsumeTextureCHROMIUM(GL_TEXTURE_2D, mailbox->name);

    // The canvas is stored in a premultiplied format, so unpremultiply if necessary.
    // The canvas is stored in an inverted position, so the flip semantics are reversed.
    context->copyTextureCHROMIUM(GL_TEXTURE_2D, sourceTexture, texture, internalFormat, destType, flipY ? GL_FALSE : GL_TRUE, GL_FALSE, premultiplyAlpha ? GL_FALSE : GL_TRUE);

    context->deleteTexture(sourceTexture);

    context->flush();
    sharedContext->waitSyncPoint(context->insertSyncPoint());

    // Undo grContext texture binding changes introduced in this function
    provider->grContext()->resetContext(kTextureBinding_GrGLBackendState);
#endif // MINIBLINK_NOT_IMPLEMENTED
	notImplemented();
    return true;
}

bool ImageBuffer::copyRenderingResultsFromDrawingBuffer(DrawingBuffer* drawingBuffer, SourceDrawingBuffer sourceBuffer)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (!drawingBuffer || !m_surface->isAccelerated())
        return false;
    OwnPtr<WebGraphicsContext3DProvider> provider = adoptPtr(Platform::current()->createSharedOffscreenGraphicsContext3DProvider());
    if (!provider)
        return false;
    WebGraphicsContext3D* context3D = provider->context3d();
    if (!context3D)
        return false;
    Platform3DObject textureId = m_surface->getBackingTextureHandleForOverwrite();
    if (!textureId)
        return false;

    context3D->flush();

    return drawingBuffer->copyToPlatformTexture(context3D, textureId, GL_RGBA,
        GL_UNSIGNED_BYTE, 0, true, false, sourceBuffer);
#endif // MINIBLINK_NOT_IMPLEMENTED
	notImplemented();
	return false;
}

void ImageBuffer::draw(GraphicsContext* context, const FloatRect& destRect, const FloatRect* srcPtr, SkXfermode::Mode op)
>>>>>>> miniblink49
{
    if (!isSurfaceValid())
        return;

<<<<<<< HEAD
    FloatRect srcRect = srcPtr ? *srcPtr : FloatRect(FloatPoint(), FloatSize(size()));
    m_surface->draw(context, destRect, srcRect, op);
}

void ImageBuffer::flush(FlushReason reason)
{
    if (m_surface->canvas()) {
        m_surface->flush(reason);
    }
}

void ImageBuffer::flushGpu(FlushReason reason)
{
    if (m_surface->canvas()) {
        m_surface->flushGpu(reason);
    }
}

bool ImageBuffer::getImageData(Multiply multiplied,
    const IntRect& rect,
    WTF::ArrayBufferContents& contents) const
{
    CheckedNumeric<int> dataSize = 4;
    dataSize *= rect.width();
    dataSize *= rect.height();
    if (!dataSize.IsValid())
        return false;

    if (!isSurfaceValid()) {
        size_t allocSizeInBytes = rect.width() * rect.height() * 4;
        void* data;
        WTF::ArrayBufferContents::allocateMemoryOrNull(
            allocSizeInBytes, WTF::ArrayBufferContents::ZeroInitialize, data);
        if (!data)
            return false;
        WTF::ArrayBufferContents result(data, allocSizeInBytes,
            WTF::ArrayBufferContents::NotShared);
=======
    FloatRect srcRect = srcPtr ? *srcPtr : FloatRect(FloatPoint(), size());
    m_surface->draw(context, destRect, srcRect, op);
}

void ImageBuffer::flush()
{
    if (m_surface->canvas()) {
        m_surface->canvas()->flush();
    }
}

bool ImageBuffer::getImageData(Multiply multiplied, const IntRect& rect, WTF::ArrayBufferContents& contents) const
{
    Checked<int, RecordOverflow> dataSize = 4;
    dataSize *= rect.width();
    dataSize *= rect.height();
    if (dataSize.hasOverflowed())
        return false;

    if (!isSurfaceValid()) {
        WTF::ArrayBufferContents result(rect.width() * rect.height(), 4, WTF::ArrayBufferContents::NotShared, WTF::ArrayBufferContents::ZeroInitialize);
>>>>>>> miniblink49
        result.transfer(contents);
        return true;
    }

<<<<<<< HEAD
    DCHECK(canvas());

    if (ExpensiveCanvasHeuristicParameters::GetImageDataForcesNoAcceleration && !RuntimeEnabledFeatures::canvas2dFixedRenderingModeEnabled()) {
        const_cast<ImageBuffer*>(this)->disableAcceleration();
    }

    sk_sp<SkImage> snapshot = m_surface->newImageSnapshot(
        PreferNoAcceleration, SnapshotReasonGetImageData);
    if (!snapshot)
        return false;

    const bool mayHaveStrayArea = m_surface->isAccelerated() // GPU readback may fail silently
        || rect.x() < 0 || rect.y() < 0 || rect.maxX() > m_surface->size().width() || rect.maxY() > m_surface->size().height();
    size_t allocSizeInBytes = rect.width() * rect.height() * 4;
    void* data;
    WTF::ArrayBufferContents::InitializationPolicy initializationPolicy = mayHaveStrayArea ? WTF::ArrayBufferContents::ZeroInitialize
                                                                                           : WTF::ArrayBufferContents::DontInitialize;
    WTF::ArrayBufferContents::allocateMemoryOrNull(allocSizeInBytes,
        initializationPolicy, data);
    if (!data)
        return false;
    WTF::ArrayBufferContents result(data, allocSizeInBytes,
        WTF::ArrayBufferContents::NotShared);

    // Skia does not support unpremultiplied read with an F16 to 8888 conversion
    bool useF16Workaround = m_surface->colorType() == kRGBA_F16_SkColorType;

    SkAlphaType alphaType = (multiplied == Premultiplied || useF16Workaround)
        ? kPremul_SkAlphaType
        : kUnpremul_SkAlphaType;
    // The workaround path use a canvas draw under the hood, which can only
    // use N32 at this time.
    SkColorType colorType = useF16Workaround ? kN32_SkColorType : kRGBA_8888_SkColorType;
    SkImageInfo info = SkImageInfo::Make(rect.width(), rect.height(), colorType, alphaType,
        SkColorSpace::MakeNamed(SkColorSpace::kSRGB_Named));

    snapshot->readPixels(info, result.data(), 4 * rect.width(), rect.x(),
        rect.y());

    if (useF16Workaround) {
        uint32_t* pixel = (uint32_t*)result.data();
        size_t pixelCount = allocSizeInBytes / sizeof(uint32_t);
        // TODO(skbug.com/5853): make readPixels support RGBA output so that we no
        // longer
        // have to do this.
        if (kN32_SkColorType == kBGRA_8888_SkColorType) {
            // Convert BGRA to RGBA if necessary on this platform.
            SkSwapRB(pixel, pixel, pixelCount);
        }
        // TODO(skbug.com/5853): We should really be doing the unpremultiply in
        // linear space
        // and skia should provide that service.
        if (multiplied == Unmultiplied) {
            for (; pixelCount; --pixelCount) {
                *pixel = SkUnPreMultiply::UnPreMultiplyPreservingByteOrder(*pixel);
                ++pixel;
            }
        }
    }

=======
    const bool hasStrayArea =
        rect.x() < 0
        || rect.y() < 0
        || rect.maxX() > m_surface->size().width()
        || rect.maxY() > m_surface->size().height();
    WTF::ArrayBufferContents result(
        rect.width() * rect.height(), 4,
        WTF::ArrayBufferContents::NotShared,
        hasStrayArea
        ? WTF::ArrayBufferContents::ZeroInitialize
        : WTF::ArrayBufferContents::DontInitialize);

    SkAlphaType alphaType = (multiplied == Premultiplied) ? kPremul_SkAlphaType : kUnpremul_SkAlphaType;
    SkImageInfo info = SkImageInfo::Make(rect.width(), rect.height(), kRGBA_8888_SkColorType, alphaType);

    m_surface->willAccessPixels();
    ASSERT(canvas());
    canvas()->readPixels(info, result.data(), 4 * rect.width(), rect.x(), rect.y());
>>>>>>> miniblink49
    result.transfer(contents);
    return true;
}

<<<<<<< HEAD
void ImageBuffer::putByteArray(Multiply multiplied,
    const unsigned char* source,
    const IntSize& sourceSize,
    const IntRect& sourceRect,
    const IntPoint& destPoint)
=======
void ImageBuffer::putByteArray(Multiply multiplied, const unsigned char* source, const IntSize& sourceSize, const IntRect& sourceRect, const IntPoint& destPoint)
>>>>>>> miniblink49
{
    if (!isSurfaceValid())
        return;

<<<<<<< HEAD
    DCHECK_GT(sourceRect.width(), 0);
    DCHECK_GT(sourceRect.height(), 0);

    int originX = sourceRect.x();
    int destX = destPoint.x() + sourceRect.x();
    DCHECK_GE(destX, 0);
    DCHECK_LT(destX, m_surface->size().width());
    DCHECK_GE(originX, 0);
    DCHECK_LT(originX, sourceRect.maxX());

    int originY = sourceRect.y();
    int destY = destPoint.y() + sourceRect.y();
    DCHECK_GE(destY, 0);
    DCHECK_LT(destY, m_surface->size().height());
    DCHECK_GE(originY, 0);
    DCHECK_LT(originY, sourceRect.maxY());

    const size_t srcBytesPerRow = 4 * sourceSize.width();
    const void* srcAddr = source + originY * srcBytesPerRow + originX * 4;
    SkAlphaType alphaType = (multiplied == Premultiplied) ? kPremul_SkAlphaType
                                                          : kUnpremul_SkAlphaType;
    SkImageInfo info = SkImageInfo::Make(
        sourceRect.width(), sourceRect.height(), kRGBA_8888_SkColorType,
        alphaType, SkColorSpace::MakeNamed(SkColorSpace::kSRGB_Named));

    m_surface->writePixels(info, srcAddr, srcBytesPerRow, destX, destY);
}

void ImageBuffer::updateGPUMemoryUsage() const
{
    if (this->isAccelerated()) {
        // If image buffer is accelerated, we should keep track of GPU memory usage.
        int gpuBufferCount = 2;
        CheckedNumeric<intptr_t> checkedGPUUsage = 4 * gpuBufferCount;
        checkedGPUUsage *= this->size().width();
        checkedGPUUsage *= this->size().height();
        intptr_t gpuMemoryUsage = checkedGPUUsage.ValueOrDefault(std::numeric_limits<intptr_t>::max());

        if (!m_gpuMemoryUsage) // was not accelerated before
            s_globalAcceleratedImageBufferCount++;

        s_globalGPUMemoryUsage += (gpuMemoryUsage - m_gpuMemoryUsage);
        m_gpuMemoryUsage = gpuMemoryUsage;
    } else if (m_gpuMemoryUsage) {
        // In case of switching from accelerated to non-accelerated mode,
        // the GPU memory usage needs to be updated too.
        DCHECK_GT(s_globalAcceleratedImageBufferCount, 0u);
        s_globalAcceleratedImageBufferCount--;
        s_globalGPUMemoryUsage -= m_gpuMemoryUsage;
        m_gpuMemoryUsage = 0;

        if (m_client)
            m_client->didDisableAcceleration();
    }
}

namespace {

    class UnacceleratedSurfaceFactory
        : public RecordingImageBufferFallbackSurfaceFactory {
    public:
        virtual std::unique_ptr<ImageBufferSurface> createSurface(
            const IntSize& size,
            OpacityMode opacityMode,
            sk_sp<SkColorSpace> colorSpace,
            SkColorType colorType)
        {
            return WTF::wrapUnique(new UnacceleratedImageBufferSurface(
                size, opacityMode, InitializeImagePixels, std::move(colorSpace),
                colorType));
        }

        virtual ~UnacceleratedSurfaceFactory() { }
    };

} // namespace

void ImageBuffer::disableAcceleration()
{
    if (!isAccelerated())
        return;

    // Create and configure a recording (unaccelerated) surface.
    std::unique_ptr<RecordingImageBufferFallbackSurfaceFactory> surfaceFactory = WTF::makeUnique<UnacceleratedSurfaceFactory>();
    std::unique_ptr<ImageBufferSurface> surface = WTF::wrapUnique(new RecordingImageBufferSurface(
        m_surface->size(), std::move(surfaceFactory),
        m_surface->getOpacityMode(), m_surface->colorSpace()));
    setSurface(std::move(surface));
}

void ImageBuffer::setSurface(std::unique_ptr<ImageBufferSurface> surface)
{
    //   sk_sp<SkImage> image =
    //       m_surface->newImageSnapshot(PreferNoAcceleration, SnapshotReasonPaint);
    //
    //   if (surface->isRecording()) {
    //     // Using a GPU-backed image with RecordingImageBufferSurface
    //     // will fail at playback time.
    //     image = image->makeNonTextureImage();
    //   }
    //
    //   surface->canvas()->drawImage(image.get(), 0, 0);
    //   surface->setImageBuffer(this);
    //   if (m_client)
    //     m_client->restoreCanvasMatrixClipStack(surface->canvas());
    //   m_surface = std::move(surface);
    //
    //   updateGPUMemoryUsage();
    DebugBreak();
}

bool ImageDataBuffer::encodeImage(const String& mimeType, const double& quality, Vector<unsigned char>* encodedImage) const
{
    if (mimeType == "image/jpeg") {
        if (!JPEGImageEncoder::encode(*this, quality, encodedImage))
            return false;
    } else if (mimeType == "image/webp") {
//         int compressionQuality = WEBPImageEncoder::DefaultCompressionQuality;
//         if (quality >= 0.0 && quality <= 1.0)
//             compressionQuality = static_cast<int>(quality * 100 + 0.5);
//         if (!WEBPImageEncoder::encode(*this, compressionQuality, encodedImage))
//             return false;
        return false;
    } else {
        if (!PNGImageEncoder::encode(*this, encodedImage))
            return false;
        DCHECK_EQ(mimeType, "image/png");
    }
    return true;
}

String ImageDataBuffer::toDataURL(const String& mimeType,
    const double& quality) const
{
    DCHECK(MIMETypeRegistry::isSupportedImageMIMETypeForEncoding(mimeType));

    Vector<unsigned char> result;
    if (!encodeImage(mimeType, quality, &result))
        return "data:,";

    return "data:" + mimeType + ";base64," + base64Encode(result);
=======
    ASSERT(sourceRect.width() > 0);
    ASSERT(sourceRect.height() > 0);

    int originX = sourceRect.x();
    int destX = destPoint.x() + sourceRect.x();
    ASSERT(destX >= 0);
    ASSERT(destX < m_surface->size().width());
    ASSERT(originX >= 0);
    ASSERT(originX < sourceRect.maxX());

    int originY = sourceRect.y();
    int destY = destPoint.y() + sourceRect.y();
    ASSERT(destY >= 0);
    ASSERT(destY < m_surface->size().height());
    ASSERT(originY >= 0);
    ASSERT(originY < sourceRect.maxY());

    const size_t srcBytesPerRow = 4 * sourceSize.width();
    const void* srcAddr = source + originY * srcBytesPerRow + originX * 4;
    SkAlphaType alphaType = (multiplied == Premultiplied) ? kPremul_SkAlphaType : kUnpremul_SkAlphaType;
    SkImageInfo info = SkImageInfo::Make(sourceRect.width(), sourceRect.height(), kRGBA_8888_SkColorType, alphaType);

    m_surface->willAccessPixels();

    canvas()->writePixels(info, srcAddr, srcBytesPerRow, destX, destY);
}

template <typename T>
static bool encodeImage(T& source, const String& mimeType, const double* quality, Vector<char>* output)
{
    Vector<unsigned char>* encodedImage = reinterpret_cast<Vector<unsigned char>*>(output);
#if 1 // def MINIBLINK_NOT_IMPLEMENTED
    if (mimeType == "image/jpeg") {
        int compressionQuality = JPEGImageEncoder::DefaultCompressionQuality;
        if (quality && *quality >= 0.0 && *quality <= 1.0)
            compressionQuality = static_cast<int>(*quality * 100 + 0.5);
        if (!JPEGImageEncoder::encode(source, compressionQuality, encodedImage))
            return false;

    } else if (mimeType == "image/webp") {
//         int compressionQuality = WEBPImageEncoder::DefaultCompressionQuality;
//         if (quality && *quality >= 0.0 && *quality <= 1.0)
//             compressionQuality = static_cast<int>(*quality * 100 + 0.5);
//         if (!WEBPImageEncoder::encode(source, compressionQuality, encodedImage))
            return false;
    } else {
        if (!PNGImageEncoder::encode(source, encodedImage))
            return false;
        ASSERT(mimeType == "image/png");
    }
#else // MINIBLINK_NOT_IMPLEMENTED
    if (mimeType == "image/jpeg") {
        return GDIPlusImageEncoder::encode(source, GDIPlusImageEncoder::JPG, encodedImage);
    } else if (mimeType == "image/png") {
        return GDIPlusImageEncoder::encode(source, GDIPlusImageEncoder::PNG, encodedImage);
    } else
        return false;
#endif // MINIBLINK_NOT_IMPLEMENTED

    return true;
}

String ImageBuffer::toDataURL(const String& mimeType, const double* quality) const
{
    ASSERT(MIMETypeRegistry::isSupportedImageMIMETypeForEncoding(mimeType));

    Vector<char> encodedImage;
    if (!isSurfaceValid() || !encodeImage(m_surface->bitmap(), mimeType, quality, &encodedImage))
        return "data:,";

    return "data:" + mimeType + ";base64," + base64Encode(encodedImage);
}

String ImageDataBuffer::toDataURL(const String& mimeType, const double* quality) const
{
    ASSERT(MIMETypeRegistry::isSupportedImageMIMETypeForEncoding(mimeType));

    Vector<char> encodedImage;
    if (!encodeImage(*this, mimeType, quality, &encodedImage))
        return "data:,";

    return "data:" + mimeType + ";base64," + base64Encode(encodedImage);
>>>>>>> miniblink49
}

} // namespace blink
