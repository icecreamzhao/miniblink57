/*
 * Copyright (c) 2010, Google Inc. All rights reserved.
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
#include "platform/graphics/gpu/DrawingBuffer.h"

#include "cc/resources/shared_bitmap.h"
#include "gpu/GLES2/gl2extchromium.h"
#include "gpu/command_buffer/client/gles2_interface.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/AcceleratedStaticBitmapImage.h"
#include "platform/graphics/GraphicsLayer.h"
#include "platform/graphics/ImageBuffer.h"
#include "platform/graphics/WebGraphicsContext3DProviderWrapper.h"
#include "platform/graphics/gpu/Extensions3DUtil.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
=======
#include "config.h"
#include "platform/graphics/gpu/DrawingBuffer.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "platform/graphics/GraphicsLayer.h"
#include "platform/graphics/ImageBuffer.h"
#include "platform/graphics/gpu/Extensions3DUtil.h"
>>>>>>> miniblink49
#include "public/platform/Platform.h"
#include "public/platform/WebCompositorSupport.h"
#include "public/platform/WebExternalBitmap.h"
#include "public/platform/WebExternalTextureLayer.h"
<<<<<<< HEAD
#include "skia/ext/texture_handle.h"
#include "third_party/skia/include/gpu/GrContext.h"
#include "third_party/skia/include/gpu/gl/GrGLTypes.h"
#include "wtf/CheckedNumeric.h"
#include "wtf/typed_arrays/ArrayBufferContents.h"
#include <algorithm>
#include <memory>
=======
#include "public/platform/WebGraphicsContext3D.h"
#include "public/platform/WebGraphicsContext3DProvider.h"
#include "wtf/ArrayBufferContents.h"
#include <algorithm>
#ifndef NDEBUG
#include "wtf/RefCountedLeakCounter.h"
#endif
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    const float s_resourceAdjustedRatio = 0.5;

    static bool shouldFailDrawingBufferCreationForTesting = false;

} // namespace

PassRefPtr<DrawingBuffer> DrawingBuffer::create(
    std::unique_ptr<WebGraphicsContext3DProvider> contextProvider,
    Client* client,
    const IntSize& size,
    bool premultipliedAlpha,
    bool wantAlphaChannel,
    bool wantDepthBuffer,
    bool wantStencilBuffer,
    bool wantAntialiasing,
    PreserveDrawingBuffer preserve,
    WebGLVersion webGLVersion,
    ChromiumImageUsage chromiumImageUsage)
{
    ASSERT(contextProvider);
=======
const float s_resourceAdjustedRatio = 0.5;

DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, drawingBufferCounter, ("DrawingBuffer"));

class ScopedTextureUnit0BindingRestorer {
public:
    ScopedTextureUnit0BindingRestorer(WebGraphicsContext3D* context, GLenum activeTextureUnit, Platform3DObject textureUnitZeroId)
        : m_context(context)
        , m_oldActiveTextureUnit(activeTextureUnit)
        , m_oldTextureUnitZeroId(textureUnitZeroId)
    {
        m_context->activeTexture(GL_TEXTURE0);
    }
    ~ScopedTextureUnit0BindingRestorer()
    {
        m_context->bindTexture(GL_TEXTURE_2D, m_oldTextureUnitZeroId);
        m_context->activeTexture(m_oldActiveTextureUnit);
    }

private:
    WebGraphicsContext3D* m_context;
    GLenum m_oldActiveTextureUnit;
    Platform3DObject m_oldTextureUnitZeroId;
};

static bool shouldFailDrawingBufferCreationForTesting = false;

} // namespace

PassRefPtr<DrawingBuffer> DrawingBuffer::create(PassOwnPtr<WebGraphicsContext3D> context, const IntSize& size, PreserveDrawingBuffer preserve, WebGraphicsContext3D::Attributes requestedAttributes)
{
    ASSERT(context);
>>>>>>> miniblink49

    if (shouldFailDrawingBufferCreationForTesting) {
        shouldFailDrawingBufferCreationForTesting = false;
        return nullptr;
    }

<<<<<<< HEAD
    std::unique_ptr<Extensions3DUtil> extensionsUtil = Extensions3DUtil::create(contextProvider->contextGL());
    if (!extensionsUtil->isValid()) {
        // This might be the first time we notice that the GL context is lost.
        return nullptr;
    }
    ASSERT(extensionsUtil->supportsExtension("GL_OES_packed_depth_stencil"));
    extensionsUtil->ensureExtensionEnabled("GL_OES_packed_depth_stencil");
    bool multisampleSupported = wantAntialiasing && (extensionsUtil->supportsExtension("GL_CHROMIUM_framebuffer_multisample") || extensionsUtil->supportsExtension("GL_EXT_multisampled_render_to_texture")) && extensionsUtil->supportsExtension("GL_OES_rgb8_rgba8");
    if (multisampleSupported) {
        extensionsUtil->ensureExtensionEnabled("GL_OES_rgb8_rgba8");
        if (extensionsUtil->supportsExtension(
                "GL_CHROMIUM_framebuffer_multisample"))
            extensionsUtil->ensureExtensionEnabled(
                "GL_CHROMIUM_framebuffer_multisample");
        else
            extensionsUtil->ensureExtensionEnabled(
                "GL_EXT_multisampled_render_to_texture");
    }
=======
    OwnPtr<Extensions3DUtil> extensionsUtil = Extensions3DUtil::create(context.get());
    if (!extensionsUtil->isValid()) {
        // This might be the first time we notice that the WebGraphicsContext3D is lost.
        return nullptr;
    }
    bool multisampleSupported = (extensionsUtil->supportsExtension("GL_CHROMIUM_framebuffer_multisample")
        || extensionsUtil->supportsExtension("GL_EXT_multisampled_render_to_texture"))
        && extensionsUtil->supportsExtension("GL_OES_rgb8_rgba8");
    if (multisampleSupported) {
        extensionsUtil->ensureExtensionEnabled("GL_OES_rgb8_rgba8");
        if (extensionsUtil->supportsExtension("GL_CHROMIUM_framebuffer_multisample"))
            extensionsUtil->ensureExtensionEnabled("GL_CHROMIUM_framebuffer_multisample");
        else
            extensionsUtil->ensureExtensionEnabled("GL_EXT_multisampled_render_to_texture");
    }
    bool packedDepthStencilSupported = extensionsUtil->supportsExtension("GL_OES_packed_depth_stencil");
    if (packedDepthStencilSupported)
        extensionsUtil->ensureExtensionEnabled("GL_OES_packed_depth_stencil");
>>>>>>> miniblink49
    bool discardFramebufferSupported = extensionsUtil->supportsExtension("GL_EXT_discard_framebuffer");
    if (discardFramebufferSupported)
        extensionsUtil->ensureExtensionEnabled("GL_EXT_discard_framebuffer");

<<<<<<< HEAD
    RefPtr<DrawingBuffer> drawingBuffer = adoptRef(new DrawingBuffer(
        std::move(contextProvider), std::move(extensionsUtil), client,
        discardFramebufferSupported, wantAlphaChannel, premultipliedAlpha,
        preserve, webGLVersion, wantDepthBuffer, wantStencilBuffer,
        chromiumImageUsage));
    if (!drawingBuffer->initialize(size, multisampleSupported)) {
=======
    RefPtr<DrawingBuffer> drawingBuffer = adoptRef(new DrawingBuffer(context, extensionsUtil.release(), multisampleSupported, packedDepthStencilSupported, discardFramebufferSupported, preserve, requestedAttributes));
    if (!drawingBuffer->initialize(size)) {
>>>>>>> miniblink49
        drawingBuffer->beginDestruction();
        return PassRefPtr<DrawingBuffer>();
    }
    return drawingBuffer.release();
}

void DrawingBuffer::forceNextDrawingBufferCreationToFail()
{
    shouldFailDrawingBufferCreationForTesting = true;
}

<<<<<<< HEAD
DrawingBuffer::DrawingBuffer(
    std::unique_ptr<WebGraphicsContext3DProvider> contextProvider,
    std::unique_ptr<Extensions3DUtil> extensionsUtil,
    Client* client,
    bool discardFramebufferSupported,
    bool wantAlphaChannel,
    bool premultipliedAlpha,
    PreserveDrawingBuffer preserve,
    WebGLVersion webGLVersion,
    bool wantDepth,
    bool wantStencil,
    ChromiumImageUsage chromiumImageUsage)
    : m_client(client)
    , m_preserveDrawingBuffer(preserve)
    , m_webGLVersion(webGLVersion)
    , m_contextProvider(WTF::wrapUnique(
          new WebGraphicsContext3DProviderWrapper(std::move(contextProvider))))
    , m_gl(this->contextProvider()->contextGL())
    , m_extensionsUtil(std::move(extensionsUtil))
    , m_discardFramebufferSupported(discardFramebufferSupported)
    , m_wantAlphaChannel(wantAlphaChannel)
    , m_premultipliedAlpha(premultipliedAlpha)
    , m_softwareRendering(this->contextProvider()->isSoftwareRendering())
    , m_wantDepth(wantDepth)
    , m_wantStencil(wantStencil)
    , m_chromiumImageUsage(chromiumImageUsage)
{
    // Used by browser tests to detect the use of a DrawingBuffer.
    TRACE_EVENT_INSTANT0("test_gpu", "DrawingBufferCreation",
        TRACE_EVENT_SCOPE_GLOBAL);
=======
DrawingBuffer::DrawingBuffer(PassOwnPtr<WebGraphicsContext3D> context,
    PassOwnPtr<Extensions3DUtil> extensionsUtil,
    bool multisampleExtensionSupported,
    bool packedDepthStencilExtensionSupported,
    bool discardFramebufferSupported,
    PreserveDrawingBuffer preserve,
    WebGraphicsContext3D::Attributes requestedAttributes)
    : m_preserveDrawingBuffer(preserve)
    , m_scissorEnabled(false)
    , m_texture2DBinding(0)
    , m_drawFramebufferBinding(0)
    , m_readFramebufferBinding(0)
    , m_activeTextureUnit(GL_TEXTURE0)
    , m_context(context)
    , m_extensionsUtil(extensionsUtil)
    , m_size(-1, -1)
    , m_requestedAttributes(requestedAttributes)
    , m_multisampleExtensionSupported(multisampleExtensionSupported)
    , m_packedDepthStencilExtensionSupported(packedDepthStencilExtensionSupported)
    , m_discardFramebufferSupported(discardFramebufferSupported)
    , m_fbo(0)
    , m_depthStencilBuffer(0)
    , m_depthBuffer(0)
    , m_stencilBuffer(0)
    , m_multisampleFBO(0)
    , m_multisampleColorBuffer(0)
    , m_contentsChanged(true)
    , m_contentsChangeCommitted(false)
    , m_bufferClearNeeded(false)
    , m_multisampleMode(None)
    , m_internalColorFormat(0)
    , m_colorFormat(0)
    , m_internalRenderbufferFormat(0)
    , m_maxTextureSize(0)
    , m_sampleCount(0)
    , m_packAlignment(4)
    , m_destructionInProgress(false)
    , m_isHidden(false)
    , m_filterQuality(kLow_SkFilterQuality)
{
    // Used by browser tests to detect the use of a DrawingBuffer.
    TRACE_EVENT_INSTANT0("test_gpu", "DrawingBufferCreation", TRACE_EVENT_SCOPE_GLOBAL);
#ifndef NDEBUG
    drawingBufferCounter.increment();
#endif
>>>>>>> miniblink49
}

DrawingBuffer::~DrawingBuffer()
{
<<<<<<< HEAD
    DCHECK(m_destructionInProgress);
    m_layer.reset();
    m_contextProvider.reset();
}

bool DrawingBuffer::markContentsChanged()
{
    if (m_contentsChangeCommitted || !m_contentsChanged) {
        m_contentsChangeCommitted = false;
        m_contentsChanged = true;
        return true;
    }
    return false;
=======
    ASSERT(m_destructionInProgress);
    ASSERT(m_textureMailboxes.isEmpty());
    m_layer.clear();
    m_context.clear();
#ifndef NDEBUG
    drawingBufferCounter.decrement();
#endif
}

void DrawingBuffer::markContentsChanged()
{
    m_contentsChanged = true;
    m_contentsChangeCommitted = false;
>>>>>>> miniblink49
}

bool DrawingBuffer::bufferClearNeeded() const
{
    return m_bufferClearNeeded;
}

void DrawingBuffer::setBufferClearNeeded(bool flag)
{
    if (m_preserveDrawingBuffer == Discard) {
        m_bufferClearNeeded = flag;
    } else {
        ASSERT(!m_bufferClearNeeded);
    }
}

<<<<<<< HEAD
gpu::gles2::GLES2Interface* DrawingBuffer::contextGL()
{
    return m_gl;
}

WebGraphicsContext3DProvider* DrawingBuffer::contextProvider()
{
    return m_contextProvider->contextProvider();
=======
WebGraphicsContext3D* DrawingBuffer::context()
{
    return m_context.get();
>>>>>>> miniblink49
}

void DrawingBuffer::setIsHidden(bool hidden)
{
    if (m_isHidden == hidden)
        return;
    m_isHidden = hidden;
    if (m_isHidden)
<<<<<<< HEAD
        m_recycledColorBufferQueue.clear();
=======
        freeRecycledMailboxes();
>>>>>>> miniblink49
}

void DrawingBuffer::setFilterQuality(SkFilterQuality filterQuality)
{
    if (m_filterQuality != filterQuality) {
        m_filterQuality = filterQuality;
        if (m_layer)
            m_layer->setNearestNeighbor(filterQuality == kNone_SkFilterQuality);
    }
}

<<<<<<< HEAD
bool DrawingBuffer::requiresAlphaChannelToBePreserved()
{
    return m_client->DrawingBufferClientIsBoundForDraw() && defaultBufferRequiresAlphaChannelToBePreserved();
}

bool DrawingBuffer::defaultBufferRequiresAlphaChannelToBePreserved()
{
    if (wantExplicitResolve()) {
        return !m_wantAlphaChannel && getMultisampledRenderbufferFormat() == GL_RGBA8_OES;
    }

    bool rgbEmulation = contextProvider()->getCapabilities().emulate_rgb_buffer_with_rgba || (shouldUseChromiumImage() && contextProvider()->getCapabilities().chromium_image_rgb_emulation);
    return !m_wantAlphaChannel && rgbEmulation;
}

std::unique_ptr<cc::SharedBitmap> DrawingBuffer::createOrRecycleBitmap()
{
    auto it = std::remove_if(
        m_recycledBitmaps.begin(), m_recycledBitmaps.end(),
        [this](const RecycledBitmap& bitmap) { return bitmap.size != m_size; });
    m_recycledBitmaps.shrink(it - m_recycledBitmaps.begin());

    if (!m_recycledBitmaps.isEmpty()) {
        RecycledBitmap recycled = std::move(m_recycledBitmaps.back());
        m_recycledBitmaps.pop_back();
        DCHECK(recycled.size == m_size);
        return std::move(recycled.bitmap);
    }

    return Platform::current()->allocateSharedBitmap(m_size);
}

bool DrawingBuffer::PrepareTextureMailbox(
    cc::TextureMailbox* outMailbox,
    std::unique_ptr<cc::SingleReleaseCallback>* outReleaseCallback)
{
    ScopedStateRestorer scopedStateRestorer(this);
    bool forceGpuResult = false;
    return prepareTextureMailboxInternal(outMailbox, outReleaseCallback,
        forceGpuResult);
}

bool DrawingBuffer::prepareTextureMailboxInternal(
    cc::TextureMailbox* outMailbox,
    std::unique_ptr<cc::SingleReleaseCallback>* outReleaseCallback,
    bool forceGpuResult)
{
    DCHECK(m_stateRestorer);
=======
void DrawingBuffer::freeRecycledMailboxes()
{
    if (m_recycledMailboxQueue.isEmpty())
        return;
    while (!m_recycledMailboxQueue.isEmpty())
        deleteMailbox(m_recycledMailboxQueue.takeLast());
}

bool DrawingBuffer::prepareMailbox(WebExternalTextureMailbox* outMailbox, WebExternalBitmap* bitmap)
{
>>>>>>> miniblink49
    if (m_destructionInProgress) {
        // It can be hit in the following sequence.
        // 1. WebGL draws something.
        // 2. The compositor begins the frame.
        // 3. Javascript makes a context lost using WEBGL_lose_context extension.
        // 4. Here.
        return false;
    }
    ASSERT(!m_isHidden);
    if (!m_contentsChanged)
        return false;

<<<<<<< HEAD
    // If the context is lost, we don't know if we should be producing GPU or
    // software frames, until we get a new context, since the compositor will
    // be trying to get a new context and may change modes.
    if (m_gl->GetGraphicsResetStatusKHR() != GL_NO_ERROR)
        return false;

    TRACE_EVENT0("blink,rail", "DrawingBuffer::prepareMailbox");

    if (m_newMailboxCallback)
        (*m_newMailboxCallback)();

    // Resolve the multisampled buffer into m_backColorBuffer texture.
    if (m_antiAliasingMode != None)
        resolveMultisampleFramebufferInternal();

    if (m_softwareRendering && !forceGpuResult) {
        return finishPrepareTextureMailboxSoftware(outMailbox, outReleaseCallback);
    } else {
        return finishPrepareTextureMailboxGpu(outMailbox, outReleaseCallback);
    }
}

bool DrawingBuffer::finishPrepareTextureMailboxSoftware(
    cc::TextureMailbox* outMailbox,
    std::unique_ptr<cc::SingleReleaseCallback>* outReleaseCallback)
{
    std::unique_ptr<cc::SharedBitmap> bitmap = createOrRecycleBitmap();
    if (!bitmap)
        return false;

    // Read the framebuffer into |bitmap|.
    {
        unsigned char* pixels = bitmap->pixels();
        DCHECK(pixels);
        bool needPremultiply = m_wantAlphaChannel && !m_premultipliedAlpha;
        WebGLImageConversion::AlphaOp op = needPremultiply ? WebGLImageConversion::AlphaDoPremultiply
                                                           : WebGLImageConversion::AlphaDoNothing;
        readBackFramebuffer(pixels, size().width(), size().height(), ReadbackSkia,
            op);
    }

    *outMailbox = cc::TextureMailbox(bitmap.get(), m_size);

    // This holds a ref on the DrawingBuffer that will keep it alive until the
    // mailbox is released (and while the release callback is running). It also
    // owns the SharedBitmap.
    auto func = WTF::bind(&DrawingBuffer::mailboxReleasedSoftware,
        RefPtr<DrawingBuffer>(this),
        WTF::passed(std::move(bitmap)), m_size);
    *outReleaseCallback = cc::SingleReleaseCallback::Create(convertToBaseCallback(std::move(func)));
    return true;
}

bool DrawingBuffer::finishPrepareTextureMailboxGpu(
    cc::TextureMailbox* outMailbox,
    std::unique_ptr<cc::SingleReleaseCallback>* outReleaseCallback)
{
    DCHECK(m_stateRestorer);
    if (m_webGLVersion > WebGL1) {
        m_stateRestorer->setPixelUnpackBufferBindingDirty();
        m_gl->BindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
    }

    // Specify the buffer that we will put in the mailbox.
    RefPtr<ColorBuffer> colorBufferForMailbox;
    if (m_preserveDrawingBuffer == Discard) {
        // If we can discard the backbuffer, send the old backbuffer directly
        // into the mailbox, and allocate (or recycle) a new backbuffer.
        colorBufferForMailbox = m_backColorBuffer;
        m_backColorBuffer = createOrRecycleColorBuffer();
        attachColorBufferToReadFramebuffer();

        // Explicitly specify that m_fbo (which is now bound to the just-allocated
        // m_backColorBuffer) is not initialized, to save GPU memory bandwidth for
        // tile-based GPU architectures.
        if (m_discardFramebufferSupported) {
            const GLenum attachments[3] = { GL_COLOR_ATTACHMENT0, GL_DEPTH_ATTACHMENT,
                GL_STENCIL_ATTACHMENT };
            m_stateRestorer->setFramebufferBindingDirty();
            m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
            m_gl->DiscardFramebufferEXT(GL_FRAMEBUFFER, 3, attachments);
        }
    } else {
        // If we can't discard the backbuffer, create (or recycle) a buffer to put
        // in the mailbox, and copy backbuffer's contents there.
        colorBufferForMailbox = createOrRecycleColorBuffer();
        m_gl->CopySubTextureCHROMIUM(
            m_backColorBuffer->textureId, 0, colorBufferForMailbox->textureId, 0, 0,
            0, 0, 0, m_size.width(), m_size.height(), GL_FALSE, GL_FALSE, GL_FALSE);
    }

    // Put colorBufferForMailbox into its mailbox, and populate its
    // produceSyncToken with that point.
    {
        m_gl->ProduceTextureDirectCHROMIUM(colorBufferForMailbox->textureId,
            colorBufferForMailbox->parameters.target,
            colorBufferForMailbox->mailbox.name);
        const GLuint64 fenceSync = m_gl->InsertFenceSyncCHROMIUM();
#if OS(MACOSX)
        m_gl->DescheduleUntilFinishedCHROMIUM();
#endif
        m_gl->Flush();
        m_gl->GenSyncTokenCHROMIUM(
            fenceSync, colorBufferForMailbox->produceSyncToken.GetData());
    }

    // Populate the output mailbox and callback.
    {
        bool isOverlayCandidate = colorBufferForMailbox->imageId != 0;
        bool secureOutputOnly = false;
        *outMailbox = cc::TextureMailbox(
            colorBufferForMailbox->mailbox, colorBufferForMailbox->produceSyncToken,
            colorBufferForMailbox->parameters.target, gfx::Size(m_size),
            isOverlayCandidate, secureOutputOnly);

        // This holds a ref on the DrawingBuffer that will keep it alive until the
        // mailbox is released (and while the release callback is running).
        auto func = WTF::bind(&DrawingBuffer::mailboxReleasedGpu,
            RefPtr<DrawingBuffer>(this), colorBufferForMailbox);
        *outReleaseCallback = cc::SingleReleaseCallback::Create(
            convertToBaseCallback(std::move(func)));
    }

    // Point |m_frontColorBuffer| to the buffer that we are now presenting.
    m_frontColorBuffer = colorBufferForMailbox;

    m_contentsChanged = false;
    setBufferClearNeeded(true);
    return true;
}

void DrawingBuffer::mailboxReleasedGpu(RefPtr<ColorBuffer> colorBuffer,
    const gpu::SyncToken& syncToken,
    bool lostResource)
{
    // If the mailbox has been returned by the compositor then it is no
    // longer being presented, and so is no longer the front buffer.
    if (colorBuffer == m_frontColorBuffer)
        m_frontColorBuffer = nullptr;

    // Update the SyncToken to ensure that we will wait for it even if we
    // immediately destroy this buffer.
    colorBuffer->receiveSyncToken = syncToken;

    if (m_destructionInProgress || colorBuffer->size != m_size || m_gl->GetGraphicsResetStatusKHR() != GL_NO_ERROR || lostResource || m_isHidden) {
        return;
    }

    // Creation of image backed mailboxes is very expensive, so be less
    // aggressive about pruning them. Pruning is done in FIFO order.
    size_t cacheLimit = 1;
    if (shouldUseChromiumImage())
        cacheLimit = 4;
    while (m_recycledColorBufferQueue.size() >= cacheLimit)
        m_recycledColorBufferQueue.takeLast();

    m_recycledColorBufferQueue.prepend(colorBuffer);
}

void DrawingBuffer::mailboxReleasedSoftware(
    std::unique_ptr<cc::SharedBitmap> bitmap,
    const IntSize& size,
    const gpu::SyncToken& syncToken,
    bool lostResource)
{
    DCHECK(!syncToken.HasData()); // No sync tokens for software resources.
    if (m_destructionInProgress || lostResource || m_isHidden || size != m_size)
        return; // Just delete the bitmap.

    RecycledBitmap recycled = { std::move(bitmap), m_size };
    m_recycledBitmaps.push_back(std::move(recycled));
}

PassRefPtr<StaticBitmapImage> DrawingBuffer::transferToStaticBitmapImage()
{
    ScopedStateRestorer scopedStateRestorer(this);

    // This can be null if the context is lost before the first call to
    // grContext().
    GrContext* grContext = contextProvider()->grContext();

    cc::TextureMailbox textureMailbox;
    std::unique_ptr<cc::SingleReleaseCallback> releaseCallback;
    bool success = false;
    if (grContext) {
        bool forceGpuResult = true;
        success = prepareTextureMailboxInternal(&textureMailbox, &releaseCallback,
            forceGpuResult);
    }
    if (!success) {
        // If we can't get a mailbox, return an transparent black ImageBitmap.
        // The only situation in which this could happen is when two or more calls
        // to transferToImageBitmap are made back-to-back, or when the context gets
        // lost.
        sk_sp<SkSurface> surface = SkSurface::MakeRasterN32Premul(m_size.width(), m_size.height());
        return StaticBitmapImage::create(surface->makeImageSnapshot());
    }

    DCHECK_EQ(m_size.width(), textureMailbox.size_in_pixels().width());
    DCHECK_EQ(m_size.height(), textureMailbox.size_in_pixels().height());

    // Make our own textureId that is a reference on the same texture backing
    // being used as the front buffer (which was returned from
    // PrepareTextureMailbox()). We do not need to wait on the sync token in
    // |textureMailbox| since the mailbox was produced on the same |m_gl| context
    // that we are using here. Similarly, the |releaseCallback| will run on the
    // same context so we don't need to send a sync token for this consume action
    // back to it.
    // TODO(danakj): Instead of using PrepareTextureMailbox(), we could just use
    // the actual texture id and avoid needing to produce/consume a mailbox.
    GLuint textureId = m_gl->CreateAndConsumeTextureCHROMIUM(
        GL_TEXTURE_2D, textureMailbox.name());
    // Return the mailbox but report that the resource is lost to prevent trying
    // to use the backing for future frames. We keep it alive with our own
    // reference to the backing via our |textureId|.
    releaseCallback->Run(gpu::SyncToken(), true /* lostResource */);

    // We reuse the same mailbox name from above since our texture id was consumed
    // from it.
    const auto& skImageMailbox = textureMailbox.mailbox();
    // Use the sync token generated after producing the mailbox. Waiting for this
    // before trying to use the mailbox with some other context will ensure it is
    // valid. We wouldn't need to wait for the consume done in this function
    // because the texture id it generated would only be valid for the
    // DrawingBuffer's context anyways.
    const auto& skImageSyncToken = textureMailbox.sync_token();

    // TODO(xidachen): Create a small pool of recycled textures from
    // ImageBitmapRenderingContext's transferFromImageBitmap, and try to use them
    // in DrawingBuffer.
    return AcceleratedStaticBitmapImage::createFromWebGLContextImage(
        skImageMailbox, skImageSyncToken, textureId,
        m_contextProvider->createWeakPtr(), m_size);
}

DrawingBuffer::ColorBufferParameters
DrawingBuffer::gpuMemoryBufferColorBufferParameters()
{
#if OS(MACOSX)
    // A CHROMIUM_image backed texture requires a specialized set of parameters
    // on OSX.
    ColorBufferParameters parameters;
    parameters.target = GC3D_TEXTURE_RECTANGLE_ARB;

    if (m_wantAlphaChannel) {
        parameters.creationInternalColorFormat = GL_RGBA;
        parameters.internalColorFormat = GL_RGBA;
    } else if (contextProvider()
                   ->getCapabilities()
                   .chromium_image_rgb_emulation) {
        parameters.creationInternalColorFormat = GL_RGB;
        parameters.internalColorFormat = GL_RGBA;
    } else {
        GLenum format = defaultBufferRequiresAlphaChannelToBePreserved() ? GL_RGBA : GL_RGB;
        parameters.creationInternalColorFormat = format;
        parameters.internalColorFormat = format;
    }

    // Unused when CHROMIUM_image is being used.
    parameters.colorFormat = 0;
    return parameters;
#else
    return textureColorBufferParameters();
#endif
}

DrawingBuffer::ColorBufferParameters
DrawingBuffer::textureColorBufferParameters()
{
    ColorBufferParameters parameters;
    parameters.target = GL_TEXTURE_2D;
    if (m_wantAlphaChannel) {
        parameters.internalColorFormat = GL_RGBA;
        parameters.creationInternalColorFormat = GL_RGBA;
        parameters.colorFormat = GL_RGBA;
    } else if (contextProvider()
                   ->getCapabilities()
                   .emulate_rgb_buffer_with_rgba) {
        parameters.internalColorFormat = GL_RGBA;
        parameters.creationInternalColorFormat = GL_RGBA;
        parameters.colorFormat = GL_RGBA;
    } else {
        GLenum format = defaultBufferRequiresAlphaChannelToBePreserved() ? GL_RGBA : GL_RGB;
        parameters.creationInternalColorFormat = format;
        parameters.internalColorFormat = format;
        parameters.colorFormat = format;
    }
    return parameters;
}

PassRefPtr<DrawingBuffer::ColorBuffer>
DrawingBuffer::createOrRecycleColorBuffer()
{
    DCHECK(m_stateRestorer);
    if (!m_recycledColorBufferQueue.isEmpty()) {
        RefPtr<ColorBuffer> recycled = m_recycledColorBufferQueue.takeLast();
        if (recycled->receiveSyncToken.HasData())
            m_gl->WaitSyncTokenCHROMIUM(recycled->receiveSyncToken.GetData());
        DCHECK(recycled->size == m_size);
        return recycled;
    }
    return createColorBuffer(m_size);
}

DrawingBuffer::ColorBuffer::ColorBuffer(DrawingBuffer* drawingBuffer,
    const ColorBufferParameters& parameters,
    const IntSize& size,
    GLuint textureId,
    GLuint imageId)
    : drawingBuffer(drawingBuffer)
    , parameters(parameters)
    , size(size)
    , textureId(textureId)
    , imageId(imageId)
{
    drawingBuffer->contextGL()->GenMailboxCHROMIUM(mailbox.name);
}

DrawingBuffer::ColorBuffer::~ColorBuffer()
{
    gpu::gles2::GLES2Interface* gl = drawingBuffer->m_gl;
    if (receiveSyncToken.HasData())
        gl->WaitSyncTokenCHROMIUM(receiveSyncToken.GetConstData());
    if (imageId) {
        gl->BindTexture(parameters.target, textureId);
        gl->ReleaseTexImage2DCHROMIUM(parameters.target, imageId);
        gl->DestroyImageCHROMIUM(imageId);
        switch (parameters.target) {
        case GL_TEXTURE_2D:
            // Restore the texture binding for GL_TEXTURE_2D, since the client will
            // expect the previous state.
            if (drawingBuffer->m_client)
                drawingBuffer->m_client->DrawingBufferClientRestoreTexture2DBinding();
            break;
        case GC3D_TEXTURE_RECTANGLE_ARB:
            // Rectangle textures aren't exposed to WebGL, so don't bother
            // restoring this state (there is no meaningful way to restore it).
            break;
        default:
            NOTREACHED();
            break;
        }
    }
    gl->DeleteTextures(1, &textureId);
}

bool DrawingBuffer::initialize(const IntSize& size, bool useMultisampling)
{
    ScopedStateRestorer scopedStateRestorer(this);

    if (m_gl->GetGraphicsResetStatusKHR() != GL_NO_ERROR) {
=======
    // Resolve the multisampled buffer into m_colorBuffer texture.
    if (m_multisampleMode != None)
        commit();

    if (bitmap) {
        bitmap->setSize(size());

        unsigned char* pixels = bitmap->pixels();
        bool needPremultiply = m_actualAttributes.alpha && !m_actualAttributes.premultipliedAlpha;
        WebGLImageConversion::AlphaOp op = needPremultiply ? WebGLImageConversion::AlphaDoPremultiply : WebGLImageConversion::AlphaDoNothing;
        if (pixels)
            readBackFramebuffer(pixels, size().width(), size().height(), ReadbackSkia, op);
    }

    // We must restore the texture binding since creating new textures,
    // consuming and producing mailboxes changes it.
    ScopedTextureUnit0BindingRestorer restorer(m_context.get(), m_activeTextureUnit, m_texture2DBinding);

    // First try to recycle an old buffer.
    RefPtr<MailboxInfo> frontColorBufferMailbox = recycledMailbox();

    // No buffer available to recycle, create a new one.
    if (!frontColorBufferMailbox) {
        TextureInfo newTexture;
        newTexture.textureId = createColorTexture();
        allocateTextureMemory(&newTexture, m_size);
        // Bad things happened, abandon ship.
        if (!newTexture.textureId)
            return false;

        frontColorBufferMailbox = createNewMailbox(newTexture);
    }

    if (m_preserveDrawingBuffer == Discard) {
        std::swap(frontColorBufferMailbox->textureInfo, m_colorBuffer);
        // It appears safe to overwrite the context's framebuffer binding in the Discard case since there will always be a
        // WebGLRenderingContext::clearIfComposited() call made before the next draw call which restores the framebuffer binding.
        // If this stops being true at some point, we should track the current framebuffer binding in the DrawingBuffer and restore
        // it after attaching the new back buffer here.
        m_context->bindFramebuffer(GL_FRAMEBUFFER, m_fbo);
        if (m_multisampleMode == ImplicitResolve)
            m_context->framebufferTexture2DMultisampleEXT(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colorBuffer.textureId, 0, m_sampleCount);
        else
            m_context->framebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colorBuffer.textureId, 0);

        if (m_discardFramebufferSupported) {
            // Explicitly discard framebuffer to save GPU memory bandwidth for tile-based GPU arch.
            const WGC3Denum attachments[3] = { GL_COLOR_ATTACHMENT0, GL_DEPTH_ATTACHMENT, GL_STENCIL_ATTACHMENT};
            m_context->discardFramebufferEXT(GL_FRAMEBUFFER, 3, attachments);
        }
    } else {
        m_context->copyTextureCHROMIUM(GL_TEXTURE_2D, m_colorBuffer.textureId, frontColorBufferMailbox->textureInfo.textureId, GL_RGBA, GL_UNSIGNED_BYTE, GL_FALSE, GL_FALSE, GL_FALSE);
    }

    restoreFramebufferBindings();
    m_contentsChanged = false;

    m_context->produceTextureDirectCHROMIUM(frontColorBufferMailbox->textureInfo.textureId, GL_TEXTURE_2D, frontColorBufferMailbox->mailbox.name);
    m_context->flush();
    frontColorBufferMailbox->mailbox.syncPoint = m_context->insertSyncPoint();
    frontColorBufferMailbox->mailbox.allowOverlay = frontColorBufferMailbox->textureInfo.imageId != 0;
    setBufferClearNeeded(true);

    // set m_parentDrawingBuffer to make sure 'this' stays alive as long as it has live mailboxes
    ASSERT(!frontColorBufferMailbox->m_parentDrawingBuffer);
    frontColorBufferMailbox->m_parentDrawingBuffer = this;
    *outMailbox = frontColorBufferMailbox->mailbox;
    m_frontColorBuffer = { frontColorBufferMailbox->textureInfo, frontColorBufferMailbox->mailbox };
    return true;
}

void DrawingBuffer::mailboxReleased(const WebExternalTextureMailbox& mailbox, bool lostResource)
{
    if (m_destructionInProgress || m_context->isContextLost() || lostResource || m_isHidden) {
        mailboxReleasedWithoutRecycling(mailbox);
        return;
    }

    for (size_t i = 0; i < m_textureMailboxes.size(); i++) {
        RefPtr<MailboxInfo> mailboxInfo = m_textureMailboxes[i];
        if (nameEquals(mailboxInfo->mailbox, mailbox)) {
            mailboxInfo->mailbox.syncPoint = mailbox.syncPoint;
            ASSERT(mailboxInfo->m_parentDrawingBuffer.get() == this);
            mailboxInfo->m_parentDrawingBuffer.clear();
            m_recycledMailboxQueue.prepend(mailboxInfo->mailbox);
            return;
        }
    }
    ASSERT_NOT_REACHED();
}

void DrawingBuffer::mailboxReleasedWithoutRecycling(const WebExternalTextureMailbox& mailbox)
{
    ASSERT(m_textureMailboxes.size());
    // Ensure not to call the destructor until deleteMailbox() is completed.
    RefPtr<DrawingBuffer> self = this;
    deleteMailbox(mailbox);
}

PassRefPtr<DrawingBuffer::MailboxInfo> DrawingBuffer::recycledMailbox()
{
    if (m_recycledMailboxQueue.isEmpty())
        return PassRefPtr<MailboxInfo>();

    WebExternalTextureMailbox mailbox;
    while (!m_recycledMailboxQueue.isEmpty()) {
        mailbox = m_recycledMailboxQueue.takeLast();
        // Never have more than one mailbox in the released state.
        if (!m_recycledMailboxQueue.isEmpty())
            deleteMailbox(mailbox);
    }

    RefPtr<MailboxInfo> mailboxInfo;
    for (size_t i = 0; i < m_textureMailboxes.size(); i++) {
        if (nameEquals(m_textureMailboxes[i]->mailbox, mailbox)) {
            mailboxInfo = m_textureMailboxes[i];
            break;
        }
    }
    ASSERT(mailboxInfo);

    if (mailboxInfo->mailbox.syncPoint) {
        m_context->waitSyncPoint(mailboxInfo->mailbox.syncPoint);
        mailboxInfo->mailbox.syncPoint = 0;
    }

    if (mailboxInfo->size != m_size) {
        m_context->bindTexture(GL_TEXTURE_2D, mailboxInfo->textureInfo.textureId);
        allocateTextureMemory(&mailboxInfo->textureInfo, m_size);
        mailboxInfo->size = m_size;
    }

    return mailboxInfo.release();
}

PassRefPtr<DrawingBuffer::MailboxInfo> DrawingBuffer::createNewMailbox(const TextureInfo& info)
{
    RefPtr<MailboxInfo> returnMailbox = adoptRef(new MailboxInfo());
    m_context->genMailboxCHROMIUM(returnMailbox->mailbox.name);
    returnMailbox->textureInfo = info;
    returnMailbox->size = m_size;
    m_textureMailboxes.append(returnMailbox);
    return returnMailbox.release();
}

void DrawingBuffer::deleteMailbox(const WebExternalTextureMailbox& mailbox)
{
    for (size_t i = 0; i < m_textureMailboxes.size(); i++) {
        if (nameEquals(m_textureMailboxes[i]->mailbox, mailbox)) {
            if (mailbox.syncPoint)
                m_context->waitSyncPoint(mailbox.syncPoint);

            deleteChromiumImageForTexture(&m_textureMailboxes[i]->textureInfo);

            m_context->deleteTexture(m_textureMailboxes[i]->textureInfo.textureId);
            m_textureMailboxes.remove(i);
            return;
        }
    }
    ASSERT_NOT_REACHED();
}

bool DrawingBuffer::initialize(const IntSize& size)
{
    if (m_context->isContextLost()) {
>>>>>>> miniblink49
        // Need to try to restore the context again later.
        return false;
    }

<<<<<<< HEAD
    m_gl->GetIntegerv(GL_MAX_TEXTURE_SIZE, &m_maxTextureSize);

    int maxSampleCount = 0;
    m_antiAliasingMode = None;
    if (useMultisampling) {
        m_gl->GetIntegerv(GL_MAX_SAMPLES_ANGLE, &maxSampleCount);
        m_antiAliasingMode = MSAAExplicitResolve;
        if (m_extensionsUtil->supportsExtension(
                "GL_EXT_multisampled_render_to_texture")) {
            m_antiAliasingMode = MSAAImplicitResolve;
        } else if (m_extensionsUtil->supportsExtension(
                       "GL_CHROMIUM_screen_space_antialiasing")) {
            m_antiAliasingMode = ScreenSpaceAntialiasing;
        }
    }
    // TODO(dshwang): Enable storage textures on all platforms. crbug.com/557848
    // The Linux ATI bot fails
    // WebglConformance.conformance_textures_misc_tex_image_webgl, so use storage
    // textures only if ScreenSpaceAntialiasing is enabled, because
    // ScreenSpaceAntialiasing is much faster with storage textures.
    m_storageTextureSupported = (m_webGLVersion > WebGL1 || m_extensionsUtil->supportsExtension("GL_EXT_texture_storage")) && m_antiAliasingMode == ScreenSpaceAntialiasing;
    m_sampleCount = std::min(4, maxSampleCount);

    m_stateRestorer->setFramebufferBindingDirty();
    m_gl->GenFramebuffers(1, &m_fbo);
    m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    if (wantExplicitResolve()) {
        m_gl->GenFramebuffers(1, &m_multisampleFBO);
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_multisampleFBO);
        m_gl->GenRenderbuffers(1, &m_multisampleRenderbuffer);
    }
    if (!resizeFramebufferInternal(size))
        return false;

    if (m_depthStencilBuffer) {
        DCHECK(wantDepthOrStencil());
        m_hasImplicitStencilBuffer = !m_wantStencil;
    }

    if (m_gl->GetGraphicsResetStatusKHR() != GL_NO_ERROR) {
        // It's possible that the drawing buffer allocation provokes a context loss,
        // so check again just in case. http://crbug.com/512302
=======
    if (m_requestedAttributes.alpha) {
        m_internalColorFormat = GL_RGBA;
        m_colorFormat = GL_RGBA;
        m_internalRenderbufferFormat = GL_RGBA8_OES;
    } else {
        m_internalColorFormat = GL_RGB;
        m_colorFormat = GL_RGB;
        m_internalRenderbufferFormat = GL_RGB8_OES;
    }

    m_context->getIntegerv(GL_MAX_TEXTURE_SIZE, &m_maxTextureSize);

    int maxSampleCount = 0;
    m_multisampleMode = None;
    if (m_requestedAttributes.antialias && m_multisampleExtensionSupported) {
        m_context->getIntegerv(GL_MAX_SAMPLES_ANGLE, &maxSampleCount);
        m_multisampleMode = ExplicitResolve;
        if (m_extensionsUtil->supportsExtension("GL_EXT_multisampled_render_to_texture"))
            m_multisampleMode = ImplicitResolve;
    }
    m_sampleCount = std::min(4, maxSampleCount);

    m_fbo = m_context->createFramebuffer();

    m_context->bindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    m_colorBuffer.textureId = createColorTexture();
    if (m_multisampleMode == ImplicitResolve)
        m_context->framebufferTexture2DMultisampleEXT(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colorBuffer.textureId, 0, m_sampleCount);
    else
        m_context->framebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colorBuffer.textureId, 0);
    createSecondaryBuffers();
    // We first try to initialize everything with the requested attributes.
    if (!reset(size))
        return false;
    // If that succeeds, we then see what we actually got and update our actual attributes to reflect that.
    m_actualAttributes = m_requestedAttributes;
    if (m_requestedAttributes.alpha) {
        WGC3Dint alphaBits = 0;
        m_context->getIntegerv(GL_ALPHA_BITS, &alphaBits);
        m_actualAttributes.alpha = alphaBits > 0;
    }
    if (m_requestedAttributes.depth) {
        WGC3Dint depthBits = 0;
        m_context->getIntegerv(GL_DEPTH_BITS, &depthBits);
        m_actualAttributes.depth = depthBits > 0;
    }
    if (m_requestedAttributes.stencil) {
        WGC3Dint stencilBits = 0;
        m_context->getIntegerv(GL_STENCIL_BITS, &stencilBits);
        m_actualAttributes.stencil = stencilBits > 0;
    }
    m_actualAttributes.antialias = multisample();

    if (m_context->isContextLost()) {
        // It's possible that the drawing buffer allocation provokes a context loss, so check again just in case. http://crbug.com/512302
>>>>>>> miniblink49
        return false;
    }

    return true;
}

<<<<<<< HEAD
bool DrawingBuffer::copyToPlatformTexture(gpu::gles2::GLES2Interface* gl,
    GLuint texture,
    GLenum internalFormat,
    GLenum destType,
    GLint level,
    bool premultiplyAlpha,
    bool flipY,
    const IntPoint& destTextureOffset,
    const IntRect& sourceSubRectangle,
    SourceDrawingBuffer sourceBuffer)
{
    ScopedStateRestorer scopedStateRestorer(this);

    if (m_contentsChanged) {
        if (m_antiAliasingMode != None)
            resolveMultisampleFramebufferInternal();
        m_gl->Flush();
    }

    // Assume that the destination target is GL_TEXTURE_2D.
    if (!Extensions3DUtil::canUseCopyTextureCHROMIUM(
            GL_TEXTURE_2D, internalFormat, destType, level))
        return false;

    // Contexts may be in a different share group. We must transfer the texture
    // through a mailbox first.
    GLenum target = 0;
    gpu::Mailbox mailbox;
    gpu::SyncToken produceSyncToken;
    if (sourceBuffer == FrontBuffer && m_frontColorBuffer) {
        target = m_frontColorBuffer->parameters.target;
        mailbox = m_frontColorBuffer->mailbox;
        produceSyncToken = m_frontColorBuffer->produceSyncToken;
    } else {
        target = m_backColorBuffer->parameters.target;
        m_gl->GenMailboxCHROMIUM(mailbox.name);
        m_gl->ProduceTextureDirectCHROMIUM(m_backColorBuffer->textureId, target,
            mailbox.name);
        const GLuint64 fenceSync = m_gl->InsertFenceSyncCHROMIUM();
        m_gl->Flush();
        m_gl->GenSyncTokenCHROMIUM(fenceSync, produceSyncToken.GetData());
    }

    if (!produceSyncToken.HasData()) {
        // This should only happen if the context has been lost.
        return false;
    }

    gl->WaitSyncTokenCHROMIUM(produceSyncToken.GetConstData());
    GLuint sourceTexture = gl->CreateAndConsumeTextureCHROMIUM(target, mailbox.name);

    GLboolean unpackPremultiplyAlphaNeeded = GL_FALSE;
    GLboolean unpackUnpremultiplyAlphaNeeded = GL_FALSE;
    if (m_wantAlphaChannel && m_premultipliedAlpha && !premultiplyAlpha)
        unpackUnpremultiplyAlphaNeeded = GL_TRUE;
    else if (m_wantAlphaChannel && !m_premultipliedAlpha && premultiplyAlpha)
        unpackPremultiplyAlphaNeeded = GL_TRUE;

    gl->CopySubTextureCHROMIUM(
        sourceTexture, 0, texture, 0, destTextureOffset.x(),
        destTextureOffset.y(), sourceSubRectangle.x(), sourceSubRectangle.y(),
        sourceSubRectangle.width(), sourceSubRectangle.height(), flipY,
        unpackPremultiplyAlphaNeeded, unpackUnpremultiplyAlphaNeeded);

    gl->DeleteTextures(1, &sourceTexture);

    const GLuint64 fenceSync = gl->InsertFenceSyncCHROMIUM();

    gl->Flush();
    gpu::SyncToken syncToken;
    gl->GenSyncTokenCHROMIUM(fenceSync, syncToken.GetData());
    m_gl->WaitSyncTokenCHROMIUM(syncToken.GetData());
=======
bool DrawingBuffer::copyToPlatformTexture(WebGraphicsContext3D* context, Platform3DObject texture, GLenum internalFormat,
    GLenum destType, GLint level, bool premultiplyAlpha, bool flipY, SourceDrawingBuffer sourceBuffer)
{
    if (m_contentsChanged) {
        if (m_multisampleMode != None) {
            commit();
            restoreFramebufferBindings();
        }
        m_context->flush();
    }

    if (!Extensions3DUtil::canUseCopyTextureCHROMIUM(GL_TEXTURE_2D, internalFormat, destType, level))
        return false;

    // Contexts may be in a different share group. We must transfer the texture through a mailbox first
    WebExternalTextureMailbox mailbox;
    GLint textureId = 0;
    if (sourceBuffer == FrontBuffer && m_frontColorBuffer.texInfo.textureId) {
        textureId = m_frontColorBuffer.texInfo.textureId;
        mailbox = m_frontColorBuffer.mailbox;
    } else {
        textureId = m_colorBuffer.textureId;
        m_context->genMailboxCHROMIUM(mailbox.name);
        m_context->produceTextureDirectCHROMIUM(textureId, GL_TEXTURE_2D, mailbox.name);
        m_context->flush();
        mailbox.syncPoint = m_context->insertSyncPoint();
    }

    context->waitSyncPoint(mailbox.syncPoint);
    Platform3DObject sourceTexture = context->createAndConsumeTextureCHROMIUM(GL_TEXTURE_2D, mailbox.name);

    GLboolean unpackPremultiplyAlphaNeeded = GL_FALSE;
    GLboolean unpackUnpremultiplyAlphaNeeded = GL_FALSE;
    if (m_actualAttributes.alpha && m_actualAttributes.premultipliedAlpha && !premultiplyAlpha)
        unpackUnpremultiplyAlphaNeeded = GL_TRUE;
    else if (m_actualAttributes.alpha && !m_actualAttributes.premultipliedAlpha && premultiplyAlpha)
        unpackPremultiplyAlphaNeeded = GL_TRUE;

    context->copyTextureCHROMIUM(GL_TEXTURE_2D, sourceTexture, texture, internalFormat, destType, flipY, unpackPremultiplyAlphaNeeded, unpackUnpremultiplyAlphaNeeded);

    context->deleteTexture(sourceTexture);

    context->flush();
    m_context->waitSyncPoint(context->insertSyncPoint());
>>>>>>> miniblink49

    return true;
}

<<<<<<< HEAD
WebLayer* DrawingBuffer::platformLayer()
{
    if (!m_layer) {
        m_layer = Platform::current()->compositorSupport()->createExternalTextureLayer(
            this);

        m_layer->setOpaque(!m_wantAlphaChannel);
        m_layer->setBlendBackgroundColor(m_wantAlphaChannel);
        m_layer->setPremultipliedAlpha(m_premultipliedAlpha);
=======
Platform3DObject DrawingBuffer::framebuffer() const
{
    return m_fbo;
}

WebLayer* DrawingBuffer::platformLayer()
{
    if (!m_layer) {
        m_layer = adoptPtr(Platform::current()->compositorSupport()->createExternalTextureLayer(this));

        m_layer->setOpaque(!m_actualAttributes.alpha);
        m_layer->setBlendBackgroundColor(m_actualAttributes.alpha);
        m_layer->setPremultipliedAlpha(m_actualAttributes.premultipliedAlpha);
>>>>>>> miniblink49
        m_layer->setNearestNeighbor(m_filterQuality == kNone_SkFilterQuality);
        GraphicsLayer::registerContentsLayer(m_layer->layer());
    }

    return m_layer->layer();
}

void DrawingBuffer::clearPlatformLayer()
{
    if (m_layer)
        m_layer->clearTexture();

<<<<<<< HEAD
    m_gl->Flush();
=======
    m_context->flush();
>>>>>>> miniblink49
}

void DrawingBuffer::beginDestruction()
{
    ASSERT(!m_destructionInProgress);
    m_destructionInProgress = true;

    clearPlatformLayer();
<<<<<<< HEAD
    m_recycledColorBufferQueue.clear();

    if (m_multisampleFBO)
        m_gl->DeleteFramebuffers(1, &m_multisampleFBO);

    if (m_fbo)
        m_gl->DeleteFramebuffers(1, &m_fbo);

    if (m_multisampleRenderbuffer)
        m_gl->DeleteRenderbuffers(1, &m_multisampleRenderbuffer);

    if (m_depthStencilBuffer)
        m_gl->DeleteRenderbuffers(1, &m_depthStencilBuffer);

    m_size = IntSize();

    m_backColorBuffer = nullptr;
    m_frontColorBuffer = nullptr;
    m_multisampleRenderbuffer = 0;
    m_depthStencilBuffer = 0;
=======

    while (!m_recycledMailboxQueue.isEmpty())
        deleteMailbox(m_recycledMailboxQueue.takeLast());

    if (m_multisampleFBO)
        m_context->deleteFramebuffer(m_multisampleFBO);

    if (m_fbo)
        m_context->deleteFramebuffer(m_fbo);

    if (m_multisampleColorBuffer)
        m_context->deleteRenderbuffer(m_multisampleColorBuffer);

    if (m_depthStencilBuffer)
        m_context->deleteRenderbuffer(m_depthStencilBuffer);

    if (m_depthBuffer)
        m_context->deleteRenderbuffer(m_depthBuffer);

    if (m_stencilBuffer)
        m_context->deleteRenderbuffer(m_stencilBuffer);

    if (m_colorBuffer.textureId) {
        deleteChromiumImageForTexture(&m_colorBuffer);
        m_context->deleteTexture(m_colorBuffer.textureId);
    }

    setSize(IntSize());

    m_colorBuffer = TextureInfo();
    m_frontColorBuffer = FrontBufferInfo();
    m_multisampleColorBuffer = 0;
    m_depthStencilBuffer = 0;
    m_depthBuffer = 0;
    m_stencilBuffer = 0;
>>>>>>> miniblink49
    m_multisampleFBO = 0;
    m_fbo = 0;

    if (m_layer)
        GraphicsLayer::unregisterContentsLayer(m_layer->layer());
<<<<<<< HEAD

    m_client = nullptr;
}

bool DrawingBuffer::resizeDefaultFramebuffer(const IntSize& size)
{
    DCHECK(m_stateRestorer);
    // Recreate m_backColorBuffer.
    m_backColorBuffer = createColorBuffer(size);

    attachColorBufferToReadFramebuffer();

    if (wantExplicitResolve()) {
        m_stateRestorer->setFramebufferBindingDirty();
        m_stateRestorer->setRenderbufferBindingDirty();
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_multisampleFBO);
        m_gl->BindRenderbuffer(GL_RENDERBUFFER, m_multisampleRenderbuffer);
        m_gl->RenderbufferStorageMultisampleCHROMIUM(
            GL_RENDERBUFFER, m_sampleCount, getMultisampledRenderbufferFormat(),
            size.width(), size.height());

        if (m_gl->GetError() == GL_OUT_OF_MEMORY)
            return false;

        m_gl->FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
            GL_RENDERBUFFER, m_multisampleRenderbuffer);
    }

    if (wantDepthOrStencil()) {
        m_stateRestorer->setFramebufferBindingDirty();
        m_stateRestorer->setRenderbufferBindingDirty();
        m_gl->BindFramebuffer(GL_FRAMEBUFFER,
            m_multisampleFBO ? m_multisampleFBO : m_fbo);
        if (!m_depthStencilBuffer)
            m_gl->GenRenderbuffers(1, &m_depthStencilBuffer);
        m_gl->BindRenderbuffer(GL_RENDERBUFFER, m_depthStencilBuffer);
        if (m_antiAliasingMode == MSAAImplicitResolve) {
            m_gl->RenderbufferStorageMultisampleEXT(GL_RENDERBUFFER, m_sampleCount,
                GL_DEPTH24_STENCIL8_OES,
                size.width(), size.height());
        } else if (m_antiAliasingMode == MSAAExplicitResolve) {
            m_gl->RenderbufferStorageMultisampleCHROMIUM(
                GL_RENDERBUFFER, m_sampleCount, GL_DEPTH24_STENCIL8_OES, size.width(),
                size.height());
        } else {
            m_gl->RenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES,
                size.width(), size.height());
        }
        // For ES 2.0 contexts DEPTH_STENCIL is not available natively, so we
        // emulate
        // it at the command buffer level for WebGL contexts.
        m_gl->FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
            GL_RENDERBUFFER, m_depthStencilBuffer);
        m_gl->BindRenderbuffer(GL_RENDERBUFFER, 0);
    }

    if (wantExplicitResolve()) {
        m_stateRestorer->setFramebufferBindingDirty();
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_multisampleFBO);
        if (m_gl->CheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            return false;
    }

    m_stateRestorer->setFramebufferBindingDirty();
    m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    return m_gl->CheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
}

void DrawingBuffer::clearFramebuffers(GLbitfield clearMask)
{
    ScopedStateRestorer scopedStateRestorer(this);
    clearFramebuffersInternal(clearMask);
}

void DrawingBuffer::clearFramebuffersInternal(GLbitfield clearMask)
{
    DCHECK(m_stateRestorer);
    m_stateRestorer->setFramebufferBindingDirty();
    // We will clear the multisample FBO, but we also need to clear the
    // non-multisampled buffer.
    if (m_multisampleFBO) {
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
        m_gl->Clear(GL_COLOR_BUFFER_BIT);
    }

    m_gl->BindFramebuffer(GL_FRAMEBUFFER,
        m_multisampleFBO ? m_multisampleFBO : m_fbo);
    m_gl->Clear(clearMask);
}

IntSize DrawingBuffer::adjustSize(const IntSize& desiredSize,
    const IntSize& curSize,
    int maxTextureSize)
{
    IntSize adjustedSize = desiredSize;

    // Clamp if the desired size is greater than the maximum texture size for the
    // device.
=======
}

unsigned DrawingBuffer::createColorTexture()
{
    unsigned offscreenColorTexture = m_context->createTexture();
    if (!offscreenColorTexture)
        return 0;

    m_context->bindTexture(GL_TEXTURE_2D, offscreenColorTexture);
    m_context->texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    m_context->texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    m_context->texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    m_context->texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    return offscreenColorTexture;
}

void DrawingBuffer::createSecondaryBuffers()
{
    // create a multisample FBO
    if (m_multisampleMode == ExplicitResolve) {
        m_multisampleFBO = m_context->createFramebuffer();
        m_context->bindFramebuffer(GL_FRAMEBUFFER, m_multisampleFBO);
        m_multisampleColorBuffer = m_context->createRenderbuffer();
    }
}

bool DrawingBuffer::resizeFramebuffer(const IntSize& size)
{
    // resize regular FBO
    m_context->bindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    m_context->bindTexture(GL_TEXTURE_2D, m_colorBuffer.textureId);

    allocateTextureMemory(&m_colorBuffer, size);

    if (m_multisampleMode == ImplicitResolve)
        m_context->framebufferTexture2DMultisampleEXT(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colorBuffer.textureId, 0, m_sampleCount);
    else
        m_context->framebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colorBuffer.textureId, 0);

    m_context->bindTexture(GL_TEXTURE_2D, 0);

    if (m_multisampleMode != ExplicitResolve)
        resizeDepthStencil(size);
    if (m_context->checkFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        return false;

    return true;
}

bool DrawingBuffer::resizeMultisampleFramebuffer(const IntSize& size)
{
    if (m_multisampleMode == ExplicitResolve) {
        m_context->bindFramebuffer(GL_FRAMEBUFFER, m_multisampleFBO);

        m_context->bindRenderbuffer(GL_RENDERBUFFER, m_multisampleColorBuffer);
        m_context->renderbufferStorageMultisampleCHROMIUM(GL_RENDERBUFFER, m_sampleCount, m_internalRenderbufferFormat, size.width(), size.height());

        if (m_context->getError() == GL_OUT_OF_MEMORY)
            return false;

        m_context->framebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_multisampleColorBuffer);
        resizeDepthStencil(size);
        if (m_context->checkFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            return false;
    }

    return true;
}

void DrawingBuffer::resizeDepthStencil(const IntSize& size)
{
    if (!m_requestedAttributes.depth && !m_requestedAttributes.stencil)
        return;

    if (m_packedDepthStencilExtensionSupported) {
        if (!m_depthStencilBuffer)
            m_depthStencilBuffer = m_context->createRenderbuffer();
        m_context->bindRenderbuffer(GL_RENDERBUFFER, m_depthStencilBuffer);
        if (m_multisampleMode == ImplicitResolve)
            m_context->renderbufferStorageMultisampleEXT(GL_RENDERBUFFER, m_sampleCount, GL_DEPTH24_STENCIL8_OES, size.width(), size.height());
        else if (m_multisampleMode == ExplicitResolve)
            m_context->renderbufferStorageMultisampleCHROMIUM(GL_RENDERBUFFER, m_sampleCount, GL_DEPTH24_STENCIL8_OES, size.width(), size.height());
        else
            m_context->renderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, size.width(), size.height());
        m_context->framebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_depthStencilBuffer);
        m_context->framebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthStencilBuffer);
    } else {
        if (m_requestedAttributes.depth) {
            if (!m_depthBuffer)
                m_depthBuffer = m_context->createRenderbuffer();
            m_context->bindRenderbuffer(GL_RENDERBUFFER, m_depthBuffer);
            if (m_multisampleMode == ImplicitResolve)
                m_context->renderbufferStorageMultisampleEXT(GL_RENDERBUFFER, m_sampleCount, GL_DEPTH_COMPONENT16, size.width(), size.height());
            else if (m_multisampleMode == ExplicitResolve)
                m_context->renderbufferStorageMultisampleCHROMIUM(GL_RENDERBUFFER, m_sampleCount, GL_DEPTH_COMPONENT16, size.width(), size.height());
            else
                m_context->renderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, size.width(), size.height());
            m_context->framebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer);
        }
        if (m_requestedAttributes.stencil) {
            if (!m_stencilBuffer)
                m_stencilBuffer = m_context->createRenderbuffer();
            m_context->bindRenderbuffer(GL_RENDERBUFFER, m_stencilBuffer);
            if (m_multisampleMode == ImplicitResolve)
                m_context->renderbufferStorageMultisampleEXT(GL_RENDERBUFFER, m_sampleCount, GL_STENCIL_INDEX8, size.width(), size.height());
            else if (m_multisampleMode == ExplicitResolve)
                m_context->renderbufferStorageMultisampleCHROMIUM(GL_RENDERBUFFER, m_sampleCount, GL_STENCIL_INDEX8, size.width(), size.height());
            else
                m_context->renderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, size.width(), size.height());
            m_context->framebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_stencilBuffer);
        }
    }
    m_context->bindRenderbuffer(GL_RENDERBUFFER, 0);
}



void DrawingBuffer::clearFramebuffers(GLbitfield clearMask)
{
    // We will clear the multisample FBO, but we also need to clear the non-multisampled buffer.
    if (m_multisampleFBO) {
        m_context->bindFramebuffer(GL_FRAMEBUFFER, m_fbo);
        m_context->clear(GL_COLOR_BUFFER_BIT);
    }

    m_context->bindFramebuffer(GL_FRAMEBUFFER, m_multisampleFBO ? m_multisampleFBO : m_fbo);
    m_context->clear(clearMask);
}

void DrawingBuffer::setSize(const IntSize& size)
{
    if (m_size == size)
        return;

    m_size = size;
}

IntSize DrawingBuffer::adjustSize(const IntSize& desiredSize, const IntSize& curSize, int maxTextureSize)
{
    IntSize adjustedSize = desiredSize;

    // Clamp if the desired size is greater than the maximum texture size for the device.
>>>>>>> miniblink49
    if (adjustedSize.height() > maxTextureSize)
        adjustedSize.setHeight(maxTextureSize);

    if (adjustedSize.width() > maxTextureSize)
        adjustedSize.setWidth(maxTextureSize);

    return adjustedSize;
}

<<<<<<< HEAD
bool DrawingBuffer::resize(const IntSize& newSize)
{
    ScopedStateRestorer scopedStateRestorer(this);
    return resizeFramebufferInternal(newSize);
}

bool DrawingBuffer::resizeFramebufferInternal(const IntSize& newSize)
{
    DCHECK(m_stateRestorer);
    DCHECK(!newSize.isEmpty());
=======
bool DrawingBuffer::reset(const IntSize& newSize)
{
    ASSERT(!newSize.isEmpty());
>>>>>>> miniblink49
    IntSize adjustedSize = adjustSize(newSize, m_size, m_maxTextureSize);
    if (adjustedSize.isEmpty())
        return false;

    if (adjustedSize != m_size) {
        do {
<<<<<<< HEAD
            if (!resizeDefaultFramebuffer(adjustedSize)) {
=======
            // resize multisample FBO
            if (!resizeMultisampleFramebuffer(adjustedSize) || !resizeFramebuffer(adjustedSize)) {
>>>>>>> miniblink49
                adjustedSize.scale(s_resourceAdjustedRatio);
                continue;
            }
            break;
        } while (!adjustedSize.isEmpty());

<<<<<<< HEAD
        m_size = adjustedSize;
        // Free all mailboxes, because they are now of the wrong size. Only the
        // first call in this loop has any effect.
        m_recycledColorBufferQueue.clear();
        m_recycledBitmaps.clear();
=======
        setSize(adjustedSize);
>>>>>>> miniblink49

        if (adjustedSize.isEmpty())
            return false;
    }

<<<<<<< HEAD
    m_stateRestorer->setClearStateDirty();
    m_gl->Disable(GL_SCISSOR_TEST);
    m_gl->ClearColor(0, 0, 0,
        defaultBufferRequiresAlphaChannelToBePreserved() ? 1 : 0);
    m_gl->ColorMask(true, true, true, true);

    GLbitfield clearMask = GL_COLOR_BUFFER_BIT;
    if (!!m_depthStencilBuffer) {
        m_gl->ClearDepthf(1.0f);
        clearMask |= GL_DEPTH_BUFFER_BIT;
        m_gl->DepthMask(true);
    }
    if (!!m_depthStencilBuffer) {
        m_gl->ClearStencil(0);
        clearMask |= GL_STENCIL_BUFFER_BIT;
        m_gl->StencilMaskSeparate(GL_FRONT, 0xFFFFFFFF);
    }

    clearFramebuffersInternal(clearMask);
    return true;
}

void DrawingBuffer::resolveAndBindForReadAndDraw()
{
    {
        ScopedStateRestorer scopedStateRestorer(this);
        resolveMultisampleFramebufferInternal();
    }
    m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void DrawingBuffer::resolveMultisampleFramebufferInternal()
{
    DCHECK(m_stateRestorer);
    m_stateRestorer->setFramebufferBindingDirty();
    if (wantExplicitResolve() && !m_contentsChangeCommitted) {
        m_stateRestorer->setClearStateDirty();
        m_gl->BindFramebuffer(GL_READ_FRAMEBUFFER_ANGLE, m_multisampleFBO);
        m_gl->BindFramebuffer(GL_DRAW_FRAMEBUFFER_ANGLE, m_fbo);
        m_gl->Disable(GL_SCISSOR_TEST);
=======
    m_context->disable(GL_SCISSOR_TEST);
    m_context->clearColor(0, 0, 0, 0);
    m_context->colorMask(true, true, true, true);

    GLbitfield clearMask = GL_COLOR_BUFFER_BIT;
    if (m_actualAttributes.depth) {
        m_context->clearDepth(1.0f);
        clearMask |= GL_DEPTH_BUFFER_BIT;
        m_context->depthMask(true);
    }
    if (m_actualAttributes.stencil) {
        m_context->clearStencil(0);
        clearMask |= GL_STENCIL_BUFFER_BIT;
        m_context->stencilMaskSeparate(GL_FRONT, 0xFFFFFFFF);
    }

    clearFramebuffers(clearMask);
    return true;
}

void DrawingBuffer::commit()
{
    if (m_multisampleFBO && !m_contentsChangeCommitted) {
        m_context->bindFramebuffer(GL_READ_FRAMEBUFFER_ANGLE, m_multisampleFBO);
        m_context->bindFramebuffer(GL_DRAW_FRAMEBUFFER_ANGLE, m_fbo);

        if (m_scissorEnabled)
            m_context->disable(GL_SCISSOR_TEST);
>>>>>>> miniblink49

        int width = m_size.width();
        int height = m_size.height();
        // Use NEAREST, because there is no scale performed during the blit.
<<<<<<< HEAD
        GLuint filter = GL_NEAREST;

        m_gl->BlitFramebufferCHROMIUM(0, 0, width, height, 0, 0, width, height,
            GL_COLOR_BUFFER_BIT, filter);

        // On old AMD GPUs on OS X, glColorMask doesn't work correctly for
        // multisampled renderbuffers and the alpha channel can be overwritten.
        // Clear the alpha channel of |m_fbo|.
        if (defaultBufferRequiresAlphaChannelToBePreserved() && contextProvider()->getCapabilities().disable_multisampling_color_mask_usage) {
            m_gl->ClearColor(0, 0, 0, 1);
            m_gl->ColorMask(false, false, false, true);
            m_gl->Clear(GL_COLOR_BUFFER_BIT);
        }
    }

    m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    if (m_antiAliasingMode == ScreenSpaceAntialiasing)
        m_gl->ApplyScreenSpaceAntialiasingCHROMIUM();
=======
        m_context->blitFramebufferCHROMIUM(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_NEAREST);

        if (m_scissorEnabled)
            m_context->enable(GL_SCISSOR_TEST);
    }

    m_context->bindFramebuffer(GL_FRAMEBUFFER, m_fbo);
>>>>>>> miniblink49
    m_contentsChangeCommitted = true;
}

void DrawingBuffer::restoreFramebufferBindings()
{
<<<<<<< HEAD
    m_client->DrawingBufferClientRestoreFramebufferBinding();
}

void DrawingBuffer::restoreAllState()
{
    m_client->DrawingBufferClientRestoreScissorTest();
    m_client->DrawingBufferClientRestoreMaskAndClearValues();
    m_client->DrawingBufferClientRestorePixelPackAlignment();
    m_client->DrawingBufferClientRestoreTexture2DBinding();
    m_client->DrawingBufferClientRestoreRenderbufferBinding();
    m_client->DrawingBufferClientRestoreFramebufferBinding();
    m_client->DrawingBufferClientRestorePixelUnpackBufferBinding();
=======
    if (m_drawFramebufferBinding && m_readFramebufferBinding) {
        if (m_drawFramebufferBinding == m_readFramebufferBinding) {
            m_context->bindFramebuffer(GL_FRAMEBUFFER, m_readFramebufferBinding);
        } else {
            m_context->bindFramebuffer(GL_READ_FRAMEBUFFER, m_readFramebufferBinding);
            m_context->bindFramebuffer(GL_DRAW_FRAMEBUFFER, m_drawFramebufferBinding);
        }
        return;
    }
    if (!m_drawFramebufferBinding && !m_readFramebufferBinding) {
        bind(GL_FRAMEBUFFER);
        return;
    }
    if (!m_drawFramebufferBinding) {
        bind(GL_DRAW_FRAMEBUFFER);
        m_context->bindFramebuffer(GL_READ_FRAMEBUFFER, m_readFramebufferBinding);
    } else {
        bind(GL_READ_FRAMEBUFFER);
        m_context->bindFramebuffer(GL_DRAW_FRAMEBUFFER, m_drawFramebufferBinding);
    }
>>>>>>> miniblink49
}

bool DrawingBuffer::multisample() const
{
<<<<<<< HEAD
    return m_antiAliasingMode != None;
=======
    return m_multisampleMode != None;
>>>>>>> miniblink49
}

void DrawingBuffer::bind(GLenum target)
{
<<<<<<< HEAD
    m_gl->BindFramebuffer(target,
        wantExplicitResolve() ? m_multisampleFBO : m_fbo);
}

bool DrawingBuffer::paintRenderingResultsToImageData(
    int& width,
    int& height,
    SourceDrawingBuffer sourceBuffer,
    WTF::ArrayBufferContents& contents)
{
    ScopedStateRestorer scopedStateRestorer(this);

    ASSERT(!m_premultipliedAlpha);
    width = size().width();
    height = size().height();

    CheckedNumeric<int> dataSize = 4;
    dataSize *= width;
    dataSize *= height;
    if (!dataSize.IsValid())
        return false;

    WTF::ArrayBufferContents pixels(width * height, 4,
        WTF::ArrayBufferContents::NotShared,
        WTF::ArrayBufferContents::DontInitialize);

    GLuint fbo = 0;
    m_stateRestorer->setFramebufferBindingDirty();
    if (sourceBuffer == FrontBuffer && m_frontColorBuffer) {
        m_gl->GenFramebuffers(1, &fbo);
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, fbo);
        m_gl->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
            m_frontColorBuffer->parameters.target,
            m_frontColorBuffer->textureId, 0);
    } else {
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    }

    readBackFramebuffer(static_cast<unsigned char*>(pixels.data()), width, height,
        ReadbackRGBA, WebGLImageConversion::AlphaDoNothing);
    flipVertically(static_cast<uint8_t*>(pixels.data()), width, height);

    if (fbo) {
        m_gl->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
            m_frontColorBuffer->parameters.target, 0, 0);
        m_gl->DeleteFramebuffers(1, &fbo);
    }

=======
    if (target != GL_READ_FRAMEBUFFER)
        m_context->bindFramebuffer(target, m_multisampleFBO ? m_multisampleFBO : m_fbo);
    else
        m_context->bindFramebuffer(target, m_fbo);
}

void DrawingBuffer::setPackAlignment(GLint param)
{
    m_packAlignment = param;
}

void DrawingBuffer::paintRenderingResultsToCanvas(ImageBuffer* imageBuffer)
{
    paintFramebufferToCanvas(framebuffer(), size().width(), size().height(), !m_actualAttributes.premultipliedAlpha, imageBuffer);
}

bool DrawingBuffer::paintRenderingResultsToImageData(int& width, int& height, SourceDrawingBuffer sourceBuffer, WTF::ArrayBufferContents& contents)
{
    ASSERT(!m_actualAttributes.premultipliedAlpha);
    width = size().width();
    height = size().height();

    Checked<int, RecordOverflow> dataSize = 4;
    dataSize *= width;
    dataSize *= height;
    if (dataSize.hasOverflowed())
        return false;

    WTF::ArrayBufferContents pixels(width * height, 4, WTF::ArrayBufferContents::NotShared, WTF::ArrayBufferContents::DontInitialize);

    GLint fbo = 0;
    if (sourceBuffer == FrontBuffer && m_frontColorBuffer.texInfo.textureId) {
        fbo = m_context->createFramebuffer();
        m_context->bindFramebuffer(GL_FRAMEBUFFER, fbo);
        m_context->framebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_frontColorBuffer.texInfo.textureId, 0);
    } else {
        m_context->bindFramebuffer(GL_FRAMEBUFFER, framebuffer());
    }

    readBackFramebuffer(static_cast<unsigned char*>(pixels.data()), width, height, ReadbackRGBA, WebGLImageConversion::AlphaDoNothing);
    flipVertically(static_cast<uint8_t*>(pixels.data()), width, height);

    if (fbo) {
        m_context->framebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, 0, 0);
        m_context->deleteFramebuffer(fbo);
    }

    restoreFramebufferBindings();

>>>>>>> miniblink49
    pixels.transfer(contents);
    return true;
}

<<<<<<< HEAD
void DrawingBuffer::readBackFramebuffer(unsigned char* pixels,
    int width,
    int height,
    ReadbackOrder readbackOrder,
    WebGLImageConversion::AlphaOp op)
{
    DCHECK(m_stateRestorer);
    m_stateRestorer->setPixelPackAlignmentDirty();
    m_gl->PixelStorei(GL_PACK_ALIGNMENT, 1);
    m_gl->ReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
=======
void DrawingBuffer::paintFramebufferToCanvas(int framebuffer, int width, int height, bool premultiplyAlpha, ImageBuffer* imageBuffer)
{
    unsigned char* pixels = 0;

    const SkBitmap& canvasBitmap = imageBuffer->bitmap();
    const SkBitmap* readbackBitmap = 0;
    ASSERT(canvasBitmap.colorType() == kN32_SkColorType);
    if (canvasBitmap.width() == width && canvasBitmap.height() == height) {
        // This is the fastest and most common case. We read back
        // directly into the canvas's backing store.
        readbackBitmap = &canvasBitmap;
        m_resizingBitmap.reset();
    } else {
        // We need to allocate a temporary bitmap for reading back the
        // pixel data. We will then use Skia to rescale this bitmap to
        // the size of the canvas's backing store.
        if (m_resizingBitmap.width() != width || m_resizingBitmap.height() != height) {
            if (!m_resizingBitmap.tryAllocN32Pixels(width, height))
                return;
        }
        readbackBitmap = &m_resizingBitmap;
    }

    // Read back the frame buffer.
    SkAutoLockPixels bitmapLock(*readbackBitmap);
    pixels = static_cast<unsigned char*>(readbackBitmap->getPixels());

    m_context->bindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    readBackFramebuffer(pixels, width, height, ReadbackSkia, premultiplyAlpha ? WebGLImageConversion::AlphaDoPremultiply : WebGLImageConversion::AlphaDoNothing);
    flipVertically(pixels, width, height);

    readbackBitmap->notifyPixelsChanged();
    if (m_resizingBitmap.readyToDraw()) {
        // We need to draw the resizing bitmap into the canvas's backing store.
        SkCanvas canvas(canvasBitmap);
        SkRect dst;
        dst.set(SkIntToScalar(0), SkIntToScalar(0), SkIntToScalar(canvasBitmap.width()), SkIntToScalar(canvasBitmap.height()));
        canvas.drawBitmapRect(m_resizingBitmap, 0, dst);
    }
}

void DrawingBuffer::readBackFramebuffer(unsigned char* pixels, int width, int height, ReadbackOrder readbackOrder, WebGLImageConversion::AlphaOp op)
{
    if (m_packAlignment > 4)
        m_context->pixelStorei(GL_PACK_ALIGNMENT, 1);
    m_context->readPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    if (m_packAlignment > 4)
        m_context->pixelStorei(GL_PACK_ALIGNMENT, m_packAlignment);
>>>>>>> miniblink49

    size_t bufferSize = 4 * width * height;

    if (readbackOrder == ReadbackSkia) {
#if (SK_R32_SHIFT == 16) && !SK_B32_SHIFT
        // Swizzle red and blue channels to match SkBitmap's byte ordering.
        // TODO(kbr): expose GL_BGRA as extension.
        for (size_t i = 0; i < bufferSize; i += 4) {
            std::swap(pixels[i], pixels[i + 2]);
        }
#endif
    }

    if (op == WebGLImageConversion::AlphaDoPremultiply) {
        for (size_t i = 0; i < bufferSize; i += 4) {
            pixels[i + 0] = std::min(255, pixels[i + 0] * pixels[i + 3] / 255);
            pixels[i + 1] = std::min(255, pixels[i + 1] * pixels[i + 3] / 255);
            pixels[i + 2] = std::min(255, pixels[i + 2] * pixels[i + 3] / 255);
        }
    } else if (op != WebGLImageConversion::AlphaDoNothing) {
        ASSERT_NOT_REACHED();
    }
}

<<<<<<< HEAD
void DrawingBuffer::flipVertically(uint8_t* framebuffer,
    int width,
    int height)
{
    std::vector<uint8_t> scanline(width * 4);
    unsigned rowBytes = width * 4;
    unsigned count = height / 2;
    for (unsigned i = 0; i < count; i++) {
        uint8_t* rowA = framebuffer + i * rowBytes;
        uint8_t* rowB = framebuffer + (height - i - 1) * rowBytes;
        memcpy(scanline.data(), rowB, rowBytes);
        memcpy(rowB, rowA, rowBytes);
        memcpy(rowA, scanline.data(), rowBytes);
    }
}

RefPtr<DrawingBuffer::ColorBuffer> DrawingBuffer::createColorBuffer(
    const IntSize& size)
{
    DCHECK(m_stateRestorer);
    m_stateRestorer->setFramebufferBindingDirty();
    m_stateRestorer->setTextureBindingDirty();

    // Select the Parameters for the texture object. Allocate the backing
    // GpuMemoryBuffer and GLImage, if one is going to be used.
    ColorBufferParameters parameters;
    GLuint imageId = 0;
    if (shouldUseChromiumImage()) {
        parameters = gpuMemoryBufferColorBufferParameters();
        imageId = m_gl->CreateGpuMemoryBufferImageCHROMIUM(
            size.width(), size.height(), parameters.creationInternalColorFormat,
            GC3D_SCANOUT_CHROMIUM);
    } else {
        parameters = textureColorBufferParameters();
    }

    // Allocate the texture for this object.
    GLuint textureId = 0;
    {
        m_gl->GenTextures(1, &textureId);
        m_gl->BindTexture(parameters.target, textureId);
        m_gl->TexParameteri(parameters.target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        m_gl->TexParameteri(parameters.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        m_gl->TexParameteri(parameters.target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        m_gl->TexParameteri(parameters.target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    // If this is GpuMemoryBuffer-backed, then bind the texture to the
    // GpuMemoryBuffer's GLImage. Otherwise, allocate ordinary texture storage.
    if (imageId) {
        m_gl->BindTexImage2DCHROMIUM(parameters.target, imageId);
    } else {
        if (m_storageTextureSupported) {
            GLenum internalStorageFormat = GL_NONE;
            if (parameters.creationInternalColorFormat == GL_RGB) {
                internalStorageFormat = GL_RGB8;
            } else if (parameters.creationInternalColorFormat == GL_RGBA) {
                internalStorageFormat = GL_RGBA8;
            } else {
                NOTREACHED();
            }
            m_gl->TexStorage2DEXT(GL_TEXTURE_2D, 1, internalStorageFormat,
                size.width(), size.height());
        } else {
            m_gl->TexImage2D(parameters.target, 0,
                parameters.creationInternalColorFormat, size.width(),
                size.height(), 0, parameters.colorFormat,
                GL_UNSIGNED_BYTE, 0);
        }
    }

    // Clear the alpha channel if this is RGB emulated.
    if (imageId && !m_wantAlphaChannel && contextProvider()->getCapabilities().chromium_image_rgb_emulation) {
        GLuint fbo = 0;

        m_stateRestorer->setClearStateDirty();
        m_gl->GenFramebuffers(1, &fbo);
        m_gl->BindFramebuffer(GL_FRAMEBUFFER, fbo);
        m_gl->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
            parameters.target, textureId, 0);
        m_gl->ClearColor(0, 0, 0, 1);
        m_gl->ColorMask(false, false, false, true);
        m_gl->Clear(GL_COLOR_BUFFER_BIT);
        m_gl->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
            parameters.target, 0, 0);
        m_gl->DeleteFramebuffers(1, &fbo);
    }

    return adoptRef(new ColorBuffer(this, parameters, size, textureId, imageId));
}

void DrawingBuffer::attachColorBufferToReadFramebuffer()
{
    DCHECK(m_stateRestorer);
    m_stateRestorer->setFramebufferBindingDirty();
    m_stateRestorer->setTextureBindingDirty();

    m_gl->BindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    GLenum target = m_backColorBuffer->parameters.target;
    GLenum id = m_backColorBuffer->textureId;

    m_gl->BindTexture(target, id);

    if (m_antiAliasingMode == MSAAImplicitResolve)
        m_gl->FramebufferTexture2DMultisampleEXT(
            GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, target, id, 0, m_sampleCount);
    else
        m_gl->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, target, id,
            0);
}

bool DrawingBuffer::wantExplicitResolve()
{
    return m_antiAliasingMode == MSAAExplicitResolve;
}

bool DrawingBuffer::wantDepthOrStencil()
{
    return m_wantDepth || m_wantStencil;
}

GLenum DrawingBuffer::getMultisampledRenderbufferFormat()
{
    DCHECK(wantExplicitResolve());
    if (m_wantAlphaChannel)
        return GL_RGBA8_OES;
    if (shouldUseChromiumImage() && contextProvider()->getCapabilities().chromium_image_rgb_emulation)
        return GL_RGBA8_OES;
    if (contextProvider()
            ->getCapabilities()
            .disable_webgl_rgb_multisampling_usage)
        return GL_RGBA8_OES;
    return GL_RGB8_OES;
}

DrawingBuffer::ScopedStateRestorer::ScopedStateRestorer(
    DrawingBuffer* drawingBuffer)
    : m_drawingBuffer(drawingBuffer)
{
    // If this is a nested restorer, save the previous restorer.
    m_previousStateRestorer = drawingBuffer->m_stateRestorer;
    m_drawingBuffer->m_stateRestorer = this;
}

DrawingBuffer::ScopedStateRestorer::~ScopedStateRestorer()
{
    DCHECK_EQ(m_drawingBuffer->m_stateRestorer, this);
    m_drawingBuffer->m_stateRestorer = m_previousStateRestorer;
    Client* client = m_drawingBuffer->m_client;
    if (!client)
        return;

    if (m_clearStateDirty) {
        client->DrawingBufferClientRestoreScissorTest();
        client->DrawingBufferClientRestoreMaskAndClearValues();
    }
    if (m_pixelPackAlignmentDirty)
        client->DrawingBufferClientRestorePixelPackAlignment();
    if (m_textureBindingDirty)
        client->DrawingBufferClientRestoreTexture2DBinding();
    if (m_renderbufferBindingDirty)
        client->DrawingBufferClientRestoreRenderbufferBinding();
    if (m_framebufferBindingDirty)
        client->DrawingBufferClientRestoreFramebufferBinding();
    if (m_pixelUnpackBufferBindingDirty)
        client->DrawingBufferClientRestorePixelUnpackBufferBinding();
}

bool DrawingBuffer::shouldUseChromiumImage()
{
    return RuntimeEnabledFeatures::webGLImageChromiumEnabled() && m_chromiumImageUsage == AllowChromiumImage;
=======
void DrawingBuffer::flipVertically(uint8_t* framebuffer, int width, int height)
{
    m_scanline.resize(width * 4);
    uint8* scanline = &m_scanline[0];
    unsigned rowBytes = width * 4;
    unsigned count = height / 2;
    for (unsigned i = 0; i < count; i++) {
        uint8* rowA = framebuffer + i * rowBytes;
        uint8* rowB = framebuffer + (height - i - 1) * rowBytes;
        memcpy(scanline, rowB, rowBytes);
        memcpy(rowB, rowA, rowBytes);
        memcpy(rowA, scanline, rowBytes);
    }
}

void DrawingBuffer::texImage2DResourceSafe(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLint unpackAlignment)
{
    ASSERT(unpackAlignment == 1 || unpackAlignment == 2 || unpackAlignment == 4 || unpackAlignment == 8);
    m_context->texImage2D(target, level, internalformat, width, height, border, format, type, 0);
}

void DrawingBuffer::allocateTextureMemory(TextureInfo* info, const IntSize& size)
{
    if (RuntimeEnabledFeatures::webGLImageChromiumEnabled()) {
        deleteChromiumImageForTexture(info);

        info->imageId = m_context->createGpuMemoryBufferImageCHROMIUM(size.width(), size.height(), GL_RGBA, GC3D_SCANOUT_CHROMIUM);
        if (info->imageId) {
            m_context->bindTexImage2DCHROMIUM(GL_TEXTURE_2D, info->imageId);
            return;
        }
    }

    texImage2DResourceSafe(GL_TEXTURE_2D, 0, m_internalColorFormat, size.width(), size.height(), 0, m_colorFormat, GL_UNSIGNED_BYTE);
}

void DrawingBuffer::deleteChromiumImageForTexture(TextureInfo* info)
{
    if (info->imageId) {
        m_context->releaseTexImage2DCHROMIUM(GL_TEXTURE_2D, info->imageId);
        m_context->destroyImageCHROMIUM(info->imageId);
        info->imageId = 0;
    }
>>>>>>> miniblink49
}

} // namespace blink
