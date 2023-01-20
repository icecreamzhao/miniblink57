/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGLGpu_DEFINED
#define GrGLGpu_DEFINED

#include "GrGLContext.h"
#include "GrGLIRect.h"
<<<<<<< HEAD
=======
#include "GrGLIndexBuffer.h"
>>>>>>> miniblink49
#include "GrGLPathRendering.h"
#include "GrGLProgram.h"
#include "GrGLRenderTarget.h"
#include "GrGLStencilAttachment.h"
#include "GrGLTexture.h"
#include "GrGLVertexArray.h"
<<<<<<< HEAD
#include "GrGpu.h"
#include "GrPipelineBuilder.h"
#include "GrTypes.h"
#include "GrXferProcessor.h"
#include "SkTArray.h"
#include "SkTypes.h"

class GrGLBuffer;
class GrPipeline;
class GrNonInstancedMesh;
class GrSwizzle;

#ifdef SK_DEBUG
#define PROGRAM_CACHE_STATS
#endif

class GrGLGpu final : public GrGpu {
public:
    static GrGpu* Create(GrBackendContext backendContext, const GrContextOptions& options,
        GrContext* context);
    ~GrGLGpu() override;

    void disconnect(DisconnectType) override;
=======
#include "GrGLVertexBuffer.h"
#include "GrGpu.h"
#include "GrPipelineBuilder.h"
#include "GrXferProcessor.h"
#include "SkTypes.h"

class GrPipeline;
class GrNonInstancedVertices;

#ifdef SK_DEVELOPER
#define PROGRAM_CACHE_STATS
#endif

class GrGLGpu : public GrGpu {
public:
    static GrGpu* Create(GrBackendContext backendContext, const GrContextOptions& options,
                         GrContext* context);
    ~GrGLGpu() override;

    void contextAbandoned() override;
>>>>>>> miniblink49

    const GrGLContext& glContext() const { return *fGLContext; }

    const GrGLInterface* glInterface() const { return fGLContext->interface(); }
    const GrGLContextInfo& ctxInfo() const { return *fGLContext; }
    GrGLStandard glStandard() const { return fGLContext->standard(); }
    GrGLVersion glVersion() const { return fGLContext->version(); }
    GrGLSLGeneration glslGeneration() const { return fGLContext->glslGeneration(); }
    const GrGLCaps& glCaps() const { return *fGLContext->caps(); }

<<<<<<< HEAD
    GrGLPathRendering* glPathRendering()
    {
=======
    GrGLPathRendering* glPathRendering() {
>>>>>>> miniblink49
        SkASSERT(glCaps().shaderCaps()->pathRenderingSupport());
        return static_cast<GrGLPathRendering*>(pathRendering());
    }

<<<<<<< HEAD
    void discard(GrRenderTarget*);

    // Used by GrGLProgram to configure OpenGL state.
    void bindTexture(int unitIdx, const GrTextureParams& params, bool allowSRGBInputs,
        GrGLTexture* texture);

    void bindTexelBuffer(int unitIdx, GrPixelConfig, GrGLBuffer*);

    void generateMipmaps(const GrTextureParams& params, bool allowSRGBInputs, GrGLTexture* texture);

    bool onGetReadPixelsInfo(GrSurface* srcSurface, int readWidth, int readHeight, size_t rowBytes,
        GrPixelConfig readConfig, DrawPreference*,
        ReadPixelTempDrawInfo*) override;

    bool onGetWritePixelsInfo(GrSurface* dstSurface, int width, int height,
        GrPixelConfig srcConfig, DrawPreference*,
        WritePixelTempDrawInfo*) override;

    bool initCopySurfaceDstDesc(const GrSurface* src, GrSurfaceDesc* desc) const override;

    // These functions should be used to bind GL objects. They track the GL state and skip redundant
    // bindings. Making the equivalent glBind calls directly will confuse the state tracking.
    void bindVertexArray(GrGLuint id)
    {
        fHWVertexArrayState.setVertexArrayID(this, id);
=======
    void discard(GrRenderTarget*) override;

    // Used by GrGLProgram to configure OpenGL state.
    void bindTexture(int unitIdx, const GrTextureParams& params, GrGLTexture* texture);

    // GrGpu overrides
    GrPixelConfig preferredReadPixelsConfig(GrPixelConfig readConfig,
                                            GrPixelConfig surfaceConfig) const override;
    GrPixelConfig preferredWritePixelsConfig(GrPixelConfig writeConfig,
                                             GrPixelConfig surfaceConfig) const override;
    bool canWriteTexturePixels(const GrTexture*, GrPixelConfig srcConfig) const override;
    bool readPixelsWillPayForYFlip(GrRenderTarget* renderTarget,
                                   int left, int top,
                                   int width, int height,
                                   GrPixelConfig config,
                                   size_t rowBytes) const override;
    bool fullReadPixelsIsFasterThanPartial() const override;

    bool initCopySurfaceDstDesc(const GrSurface* src, GrSurfaceDesc* desc) override;

    // These functions should be used to bind GL objects. They track the GL state and skip redundant
    // bindings. Making the equivalent glBind calls directly will confuse the state tracking.
    void bindVertexArray(GrGLuint id) {
        fHWGeometryState.setVertexArrayID(this, id);
    }
    void bindIndexBufferAndDefaultVertexArray(GrGLuint id) {
        fHWGeometryState.setIndexBufferIDOnDefaultVertexArray(this, id);
    }
    void bindVertexBuffer(GrGLuint id) {
        fHWGeometryState.setVertexBufferID(this, id);
>>>>>>> miniblink49
    }

    // These callbacks update state tracking when GL objects are deleted. They are called from
    // GrGLResource onRelease functions.
<<<<<<< HEAD
    void notifyVertexArrayDelete(GrGLuint id)
    {
        fHWVertexArrayState.notifyVertexArrayDelete(id);
    }

    // Binds a buffer to the GL target corresponding to 'type', updates internal state tracking, and
    // returns the GL target the buffer was bound to.
    // When 'type' is kIndex_GrBufferType, this function will also implicitly bind the default VAO.
    // If the caller wishes to bind an index buffer to a specific VAO, it can call glBind directly.
    GrGLenum bindBuffer(GrBufferType type, const GrGLBuffer*);

    // Called by GrGLBuffer after its buffer object has been destroyed.
    void notifyBufferReleased(const GrGLBuffer*);

    // The GrGLGpuCommandBuffer does not buffer up draws before submitting them to the gpu.
    // Thus this is the implementation of the draw call for the corresponding passthrough function
    // on GrGLGpuCommandBuffer.
    void draw(const GrPipeline&,
        const GrPrimitiveProcessor&,
        const GrMesh*,
        int meshCount);

    // The GrGLGpuCommandBuffer does not buffer up draws before submitting them to the gpu.
    // Thus this is the implementation of the clear call for the corresponding passthrough function
    // on GrGLGpuCommandBuffer.
    void clear(const SkIRect& rect, GrColor color, GrRenderTarget* renderTarget);

    // The GrGLGpuCommandBuffer does not buffer up draws before submitting them to the gpu.
    // Thus this is the implementation of the clearStencil call for the corresponding passthrough
    // function on GrGLGpuCommandBuffer.
    void clearStencilClip(const SkIRect& rect, bool insideClip, GrRenderTarget* renderTarget);

    const GrGLContext* glContextForTesting() const override
    {
        return &this->glContext();
    }

    void clearStencil(GrRenderTarget*) override;

    GrGpuCommandBuffer* createCommandBuffer(
        GrRenderTarget* target,
        const GrGpuCommandBuffer::LoadAndStoreInfo& colorInfo,
        const GrGpuCommandBuffer::LoadAndStoreInfo& stencilInfo) override;

    void invalidateBoundRenderTarget()
    {
        fHWBoundRenderTargetUniqueID = SK_InvalidUniqueID;
    }

    GrStencilAttachment* createStencilAttachmentForRenderTarget(const GrRenderTarget* rt,
        int width,
        int height) override;

    GrBackendObject createTestingOnlyBackendTexture(void* pixels, int w, int h,
        GrPixelConfig config,
        bool isRenderTarget = false) override;
    bool isTestingOnlyBackendTexture(GrBackendObject) const override;
    void deleteTestingOnlyBackendTexture(GrBackendObject, bool abandonTexture) override;

    void resetShaderCacheForTesting() const override;

    void drawDebugWireRect(GrRenderTarget*, const SkIRect&, GrColor) override;

    void finishDrawTarget() override;

=======
    void notifyVertexArrayDelete(GrGLuint id) {
        fHWGeometryState.notifyVertexArrayDelete(id);
    }
    void notifyVertexBufferDelete(GrGLuint id) {
        fHWGeometryState.notifyVertexBufferDelete(id);
    }
    void notifyIndexBufferDelete(GrGLuint id) {
        fHWGeometryState.notifyIndexBufferDelete(id);
    }

    void xferBarrier(GrRenderTarget*, GrXferBarrierType) override;

    void buildProgramDesc(GrProgramDesc*,
                          const GrPrimitiveProcessor&,
                          const GrPipeline&,
                          const GrBatchTracker&) const override;

    const GrGLContext* glContextForTesting() const override {
        return &this->glContext();
    }

>>>>>>> miniblink49
private:
    GrGLGpu(GrGLContext* ctx, GrContext* context);

    // GrGpu overrides
    void onResetContext(uint32_t resetBits) override;

<<<<<<< HEAD
    void xferBarrier(GrRenderTarget*, GrXferBarrierType) override;

    GrTexture* onCreateTexture(const GrSurfaceDesc& desc, SkBudgeted budgeted,
        const SkTArray<GrMipLevel>& texels) override;
    GrTexture* onCreateCompressedTexture(const GrSurfaceDesc& desc,
        SkBudgeted budgeted,
        const SkTArray<GrMipLevel>& texels) override;

    GrBuffer* onCreateBuffer(size_t size, GrBufferType intendedType, GrAccessPattern,
        const void* data) override;
    GrTexture* onWrapBackendTexture(const GrBackendTextureDesc&, GrWrapOwnership) override;
    GrRenderTarget* onWrapBackendRenderTarget(const GrBackendRenderTargetDesc&,
        GrWrapOwnership) override;
    GrRenderTarget* onWrapBackendTextureAsRenderTarget(const GrBackendTextureDesc&) override;
    // Given a GrPixelConfig return the index into the stencil format array on GrGLCaps to a
    // compatible stencil format, or negative if there is no compatible stencil format.
    int getCompatibleStencilIndex(GrPixelConfig config);

    // Returns whether the texture is successfully created. On success, the
    // result is stored in |info|.
    // The texture is populated with |texels|, if it exists.
    // The texture parameters are cached in |initialTexParams|.
    bool createTextureImpl(const GrSurfaceDesc& desc, GrGLTextureInfo* info,
        bool renderTarget, GrGLTexture::TexParams* initialTexParams,
        const SkTArray<GrMipLevel>& texels);

    bool onMakeCopyForTextureParams(GrTexture*, const GrTextureParams&,
        GrTextureProducer::CopyParams*) const override;

    // Checks whether glReadPixels can be called to get pixel values in readConfig from the
    // render target.
    bool readPixelsSupported(GrRenderTarget* target, GrPixelConfig readConfig);

    // Checks whether glReadPixels can be called to get pixel values in readConfig from a
    // render target that has renderTargetConfig. This may have to create a temporary
    // render target and thus is less preferable than the variant that takes a render target.
    bool readPixelsSupported(GrPixelConfig renderTargetConfig, GrPixelConfig readConfig);

    // Checks whether glReadPixels can be called to get pixel values in readConfig from a
    // render target that has the same config as surfaceForConfig. Calls one of the the two
    // variations above, depending on whether the surface is a render target or not.
    bool readPixelsSupported(GrSurface* surfaceForConfig, GrPixelConfig readConfig);

    bool onReadPixels(GrSurface*,
        int left, int top,
        int width, int height,
        GrPixelConfig,
        void* buffer,
        size_t rowBytes) override;

    bool onWritePixels(GrSurface*,
        int left, int top, int width, int height,
        GrPixelConfig config,
        const SkTArray<GrMipLevel>& texels) override;

    bool onTransferPixels(GrSurface*,
        int left, int top, int width, int height,
        GrPixelConfig config, GrBuffer* transferBuffer,
        size_t offset, size_t rowBytes) override;

    void onResolveRenderTarget(GrRenderTarget* target) override;

    bool onCopySurface(GrSurface* dst,
        GrSurface* src,
        const SkIRect& srcRect,
        const SkIPoint& dstPoint) override;

    void onGetMultisampleSpecs(GrRenderTarget*,
        const GrStencilSettings&,
        int* effectiveSampleCnt,
        SkAutoTDeleteArray<SkPoint>* sampleLocations) override;
=======
    GrTexture* onCreateTexture(const GrSurfaceDesc& desc, GrGpuResource::LifeCycle lifeCycle,
                               const void* srcData, size_t rowBytes) override;
    GrTexture* onCreateCompressedTexture(const GrSurfaceDesc& desc,
                                         GrGpuResource::LifeCycle lifeCycle,
                                         const void* srcData) override;
    GrVertexBuffer* onCreateVertexBuffer(size_t size, bool dynamic) override;
    GrIndexBuffer* onCreateIndexBuffer(size_t size, bool dynamic) override;
    GrTexture* onWrapBackendTexture(const GrBackendTextureDesc&, GrWrapOwnership) override;
    GrRenderTarget* onWrapBackendRenderTarget(const GrBackendRenderTargetDesc&,
                                              GrWrapOwnership) override;
    bool createStencilAttachmentForRenderTarget(GrRenderTarget* rt, int width, int height) override;
    bool attachStencilAttachmentToRenderTarget(GrStencilAttachment* sb,
                                               GrRenderTarget* rt) override;

    void onClear(GrRenderTarget*, const SkIRect* rect, GrColor color,
                 bool canIgnoreRect) override;

    void onClearStencilClip(GrRenderTarget*, const SkIRect& rect, bool insideClip) override;

    bool onReadPixels(GrRenderTarget* target,
                      int left, int top,
                      int width, int height,
                      GrPixelConfig,
                      void* buffer,
                      size_t rowBytes) override;

    bool onWriteTexturePixels(GrTexture* texture,
                              int left, int top, int width, int height,
                              GrPixelConfig config, const void* buffer,
                              size_t rowBytes) override;

    void onResolveRenderTarget(GrRenderTarget* target) override;

    void onDraw(const DrawArgs&, const GrNonInstancedVertices&) override;

    bool onCopySurface(GrSurface* dst,
                       GrSurface* src,
                       const SkIRect& srcRect,
                       const SkIPoint& dstPoint) override;

    void clearStencil(GrRenderTarget*) override;

    // GrDrawTarget overrides
    void didAddGpuTraceMarker() override;
    void didRemoveGpuTraceMarker() override;
>>>>>>> miniblink49

    // binds texture unit in GL
    void setTextureUnit(int unitIdx);

<<<<<<< HEAD
    void setTextureSwizzle(int unitIdx, GrGLenum target, const GrGLenum swizzle[]);

    // Flushes state from GrPipeline to GL. Returns false if the state couldn't be set.
    bool flushGLState(const GrPipeline& pipeline, const GrPrimitiveProcessor& primProc);
=======
    // Flushes state from GrPipeline to GL. Returns false if the state couldn't be set.
    bool flushGLState(const DrawArgs&);
>>>>>>> miniblink49

    // Sets up vertex attribute pointers and strides. On return indexOffsetInBytes gives the offset
    // an into the index buffer. It does not account for vertices.startIndex() but rather the start
    // index is relative to the returned offset.
    void setupGeometry(const GrPrimitiveProcessor&,
<<<<<<< HEAD
        const GrNonInstancedMesh& mesh,
        size_t* indexOffsetInBytes);

    void flushBlend(const GrXferProcessor::BlendInfo& blendInfo, const GrSwizzle&);

    bool hasExtension(const char* ext) const { return fGLContext->hasExtension(ext); }

    bool copySurfaceAsDraw(GrSurface* dst,
        GrSurface* src,
        const SkIRect& srcRect,
        const SkIPoint& dstPoint);
    void copySurfaceAsCopyTexSubImage(GrSurface* dst,
        GrSurface* src,
        const SkIRect& srcRect,
        const SkIPoint& dstPoint);
    bool copySurfaceAsBlitFramebuffer(GrSurface* dst,
        GrSurface* src,
        const SkIRect& srcRect,
        const SkIPoint& dstPoint);
    bool generateMipmap(GrGLTexture* texture, bool gammaCorrect);

    void stampPLSSetupRect(const SkRect& bounds);

    void setupPixelLocalStorage(const GrPipeline&, const GrPrimitiveProcessor&);
=======
                       const GrNonInstancedVertices& vertices,
                       size_t* indexOffsetInBytes);

    // Subclasses should call this to flush the blend state.
    void flushBlend(const GrXferProcessor::BlendInfo& blendInfo);

    bool hasExtension(const char* ext) const { return fGLContext->hasExtension(ext); }

    void copySurfaceAsDraw(GrSurface* dst,
                           GrSurface* src,
                           const SkIRect& srcRect,
                           const SkIPoint& dstPoint);
    void copySurfaceAsCopyTexSubImage(GrSurface* dst,
                                      GrSurface* src,
                                      const SkIRect& srcRect,
                                      const SkIPoint& dstPoint);
    bool copySurfaceAsBlitFramebuffer(GrSurface* dst,
                                      GrSurface* src,
                                      const SkIRect& srcRect,
                                      const SkIPoint& dstPoint);
>>>>>>> miniblink49

    static bool BlendCoeffReferencesConstant(GrBlendCoeff coeff);

    class ProgramCache : public ::SkNoncopyable {
    public:
        ProgramCache(GrGLGpu* gpu);
        ~ProgramCache();

        void abandon();
<<<<<<< HEAD
        GrGLProgram* refProgram(const GrGLGpu* gpu, const GrPipeline&, const GrPrimitiveProcessor&);
=======
        GrGLProgram* refProgram(const DrawArgs&);
>>>>>>> miniblink49

    private:
        enum {
            // We may actually have kMaxEntries+1 shaders in the GL context because we create a new
            // shader before evicting from the cache.
            kMaxEntries = 128,
            kHashBits = 6,
        };

        struct Entry;

        struct ProgDescLess;

        // binary search for entry matching desc. returns index into fEntries that matches desc or ~
        // of the index of where it should be inserted.
        int search(const GrProgramDesc& desc) const;

        // sorted array of all the entries
<<<<<<< HEAD
        Entry* fEntries[kMaxEntries];
        // hash table based on lowest kHashBits bits of the program key. Used to avoid binary
        // searching fEntries.
        Entry* fHashTable[1 << kHashBits];

        int fCount;
        unsigned int fCurrLRUStamp;
        GrGLGpu* fGpu;
#ifdef PROGRAM_CACHE_STATS
        int fTotalRequests;
        int fCacheMisses;
        int fHashMisses; // cache hit but hash table missed
#endif
    };

=======
        Entry*                      fEntries[kMaxEntries];
        // hash table based on lowest kHashBits bits of the program key. Used to avoid binary
        // searching fEntries.
        Entry*                      fHashTable[1 << kHashBits];

        int                         fCount;
        unsigned int                fCurrLRUStamp;
        GrGLGpu*                    fGpu;
#ifdef PROGRAM_CACHE_STATS
        int                         fTotalRequests;
        int                         fCacheMisses;
        int                         fHashMisses; // cache hit but hash table missed
#endif
    };

    void flushDither(bool dither);
>>>>>>> miniblink49
    void flushColorWrite(bool writeColor);
    void flushDrawFace(GrPipelineBuilder::DrawFace face);

    // flushes the scissor. see the note on flushBoundTextureAndParams about
    // flushing the scissor after that function is called.
    void flushScissor(const GrScissorState&,
<<<<<<< HEAD
        const GrGLIRect& rtViewport,
        GrSurfaceOrigin rtOrigin);
=======
                      const GrGLIRect& rtViewport,
                      GrSurfaceOrigin rtOrigin);
>>>>>>> miniblink49

    // disables the scissor
    void disableScissor();

    void initFSAASupport();

    // determines valid stencil formats
    void initStencilFormats();

    // sets a texture unit to use for texture operations other than binding a texture to a program.
    // ensures that such operations don't negatively interact with tracking bound textures.
    void setScratchTextureUnit();

<<<<<<< HEAD
    // bounds is region that may be modified.
    // nullptr means whole target. Can be an empty rect.
    void flushRenderTarget(GrGLRenderTarget*, const SkIRect* bounds, bool disableSRGB = false);

    // Need not be called if flushRenderTarget is used.
    void flushViewport(const GrGLIRect&);

    void flushStencil(const GrStencilSettings&);

    // rt is used only if useHWAA is true.
    void flushHWAAState(GrRenderTarget* rt, bool useHWAA, bool stencilEnabled);

    void flushMinSampleShading(float minSampleShading);

    void flushFramebufferSRGB(bool enable);

    // helper for onCreateTexture and writeTexturePixels
    enum UploadType {
        kNewTexture_UploadType, // we are creating a new texture
        kWrite_UploadType, // we are using TexSubImage2D to copy data to an existing texture
        kTransfer_UploadType, // we are using a transfer buffer to copy data
    };
    bool uploadTexData(const GrSurfaceDesc& desc,
        GrGLenum target,
        UploadType uploadType,
        int left, int top, int width, int height,
        GrPixelConfig dataConfig,
        const SkTArray<GrMipLevel>& texels);
=======
    // bounds is region that may be modified and therefore has to be resolved.
    // NULL means whole target. Can be an empty rect.
    void flushRenderTarget(GrGLRenderTarget*, const SkIRect* bounds);

    void flushStencil(const GrStencilSettings&);
    void flushHWAAState(GrRenderTarget* rt, bool useHWAA);

    bool configToGLFormats(GrPixelConfig config,
                           bool getSizedInternal,
                           GrGLenum* internalFormat,
                           GrGLenum* externalFormat,
                           GrGLenum* externalType);
    // helper for onCreateTexture and writeTexturePixels
    bool uploadTexData(const GrSurfaceDesc& desc,
                       bool isNewTexture,
                       int left, int top, int width, int height,
                       GrPixelConfig dataConfig,
                       const void* data,
                       size_t rowBytes);
>>>>>>> miniblink49

    // helper for onCreateCompressedTexture. If width and height are
    // set to -1, then this function will use desc.fWidth and desc.fHeight
    // for the size of the data. The isNewTexture flag should be set to true
    // whenever a new texture needs to be created. Otherwise, we assume that
    // the texture is already in GPU memory and that it's going to be updated
    // with new data.
    bool uploadCompressedTexData(const GrSurfaceDesc& desc,
<<<<<<< HEAD
        GrGLenum target,
        const SkTArray<GrMipLevel>& texels,
        UploadType uploadType = kNewTexture_UploadType,
        int left = 0, int top = 0,
        int width = -1, int height = -1);

    bool createRenderTargetObjects(const GrSurfaceDesc&, const GrGLTextureInfo& texInfo,
        GrGLRenderTarget::IDDesc*);
=======
                                 const void* data,
                                 bool isNewTexture = true,
                                 int left = 0, int top = 0,
                                 int width = -1, int height = -1);

    bool createRenderTargetObjects(const GrSurfaceDesc&, GrGpuResource::LifeCycle lifeCycle,
                                   GrGLuint texID, GrGLRenderTarget::IDDesc*);
>>>>>>> miniblink49

    enum TempFBOTarget {
        kSrc_TempFBOTarget,
        kDst_TempFBOTarget
    };

<<<<<<< HEAD
    // Binds a surface as a FBO for a copy operation. If the surface already owns an FBO ID then
    // that ID is bound. If not the surface is temporarily bound to a FBO and that FBO is bound.
    // This must be paired with a call to unbindSurfaceFBOForCopy().
    void bindSurfaceFBOForCopy(GrSurface* surface, GrGLenum fboTarget, GrGLIRect* viewport,
        TempFBOTarget tempFBOTarget);

    // Must be called if bindSurfaceFBOForCopy was used to bind a surface for copying.
    void unbindTextureFBOForCopy(GrGLenum fboTarget, GrSurface* surface);

    SkAutoTUnref<GrGLContext> fGLContext;

    bool createCopyProgram(int progIdx);
    bool createMipmapProgram(int progIdx);
    bool createWireRectProgram();
    bool createPLSSetupProgram();

    // GL program-related state
    ProgramCache* fProgramCache;
=======
    GrGLuint bindSurfaceAsFBO(GrSurface* surface, GrGLenum fboTarget, GrGLIRect* viewport,
                              TempFBOTarget tempFBOTarget);

    void unbindTextureFromFBO(GrGLenum fboTarget);

    SkAutoTUnref<GrGLContext>  fGLContext;

    void createCopyProgram();

    // GL program-related state
    ProgramCache*               fProgramCache;
>>>>>>> miniblink49

    ///////////////////////////////////////////////////////////////////////////
    ///@name Caching of GL State
    ///@{
<<<<<<< HEAD
    int fHWActiveTextureUnitIdx;
    GrGLuint fHWProgramID;
=======
    int                         fHWActiveTextureUnitIdx;
    GrGLuint                    fHWProgramID;
>>>>>>> miniblink49

    enum TriState {
        kNo_TriState,
        kYes_TriState,
        kUnknown_TriState
    };

<<<<<<< HEAD
    GrGLuint fTempSrcFBOID;
    GrGLuint fTempDstFBOID;

    GrGLuint fStencilClearFBOID;

    // last scissor / viewport scissor state seen by the GL.
    struct {
        TriState fEnabled;
        GrGLIRect fRect;
        void invalidate()
        {
=======
    GrGLuint                    fTempSrcFBOID;
    GrGLuint                    fTempDstFBOID;

    GrGLuint                    fStencilClearFBOID;

    // last scissor / viewport scissor state seen by the GL.
    struct {
        TriState    fEnabled;
        GrGLIRect   fRect;
        void invalidate() {
>>>>>>> miniblink49
            fEnabled = kUnknown_TriState;
            fRect.invalidate();
        }
    } fHWScissorSettings;

<<<<<<< HEAD
    GrGLIRect fHWViewport;

    /**
     * Tracks vertex attrib array state.
     */
    class HWVertexArrayState {
    public:
        HWVertexArrayState()
            : fCoreProfileVertexArray(nullptr)
        {
            this->invalidate();
        }

        ~HWVertexArrayState() { delete fCoreProfileVertexArray; }

        void invalidate()
        {
            fBoundVertexArrayIDIsValid = false;
            fDefaultVertexArrayAttribState.invalidate();
            if (fCoreProfileVertexArray) {
                fCoreProfileVertexArray->invalidateCachedState();
            }
        }

        void notifyVertexArrayDelete(GrGLuint id)
        {
=======
    GrGLIRect                   fHWViewport;

    /**
     * Tracks bound vertex and index buffers and vertex attrib array state.
     */
    class HWGeometryState {
    public:
        HWGeometryState() { fVBOVertexArray = NULL; this->invalidate(); }

        ~HWGeometryState() { SkDELETE(fVBOVertexArray); }

        void invalidate() {
            fBoundVertexArrayIDIsValid = false;
            fBoundVertexBufferIDIsValid = false;
            fDefaultVertexArrayBoundIndexBufferID = false;
            fDefaultVertexArrayBoundIndexBufferIDIsValid = false;
            fDefaultVertexArrayAttribState.invalidate();
            if (fVBOVertexArray) {
                fVBOVertexArray->invalidateCachedState();
            }
        }

        void notifyVertexArrayDelete(GrGLuint id) {
>>>>>>> miniblink49
            if (fBoundVertexArrayIDIsValid && fBoundVertexArrayID == id) {
                // Does implicit bind to 0
                fBoundVertexArrayID = 0;
            }
        }

<<<<<<< HEAD
        void setVertexArrayID(GrGLGpu* gpu, GrGLuint arrayID)
        {
=======
        void setVertexArrayID(GrGLGpu* gpu, GrGLuint arrayID) {
>>>>>>> miniblink49
            if (!gpu->glCaps().vertexArrayObjectSupport()) {
                SkASSERT(0 == arrayID);
                return;
            }
            if (!fBoundVertexArrayIDIsValid || arrayID != fBoundVertexArrayID) {
                GR_GL_CALL(gpu->glInterface(), BindVertexArray(arrayID));
                fBoundVertexArrayIDIsValid = true;
                fBoundVertexArrayID = arrayID;
            }
        }

<<<<<<< HEAD
        /**
         * Binds the vertex array that should be used for internal draws, and returns its attrib
         * state. This binds the default VAO (ID=zero) unless we are on a core profile, in which
         * case we use a dummy array instead.
         *
         * If an index buffer is privided, it will be bound to the vertex array. Otherwise the
         * index buffer binding will be left unchanged.
         *
         * The returned GrGLAttribArrayState should be used to set vertex attribute arrays.
         */
        GrGLAttribArrayState* bindInternalVertexArray(GrGLGpu*, const GrGLBuffer* ibuff = nullptr);

    private:
        GrGLuint fBoundVertexArrayID;
        bool fBoundVertexArrayIDIsValid;

        // We return a non-const pointer to this from bindArrayAndBuffersToDraw when vertex array 0
        // is bound. However, this class is internal to GrGLGpu and this object never leaks out of
        // GrGLGpu.
        GrGLAttribArrayState fDefaultVertexArrayAttribState;

        // This is used when we're using a core profile.
        GrGLVertexArray* fCoreProfileVertexArray;
    } fHWVertexArrayState;

    struct {
        GrGLenum fGLTarget;
        uint32_t fBoundBufferUniqueID;
        bool fBufferZeroKnownBound;

        void invalidate()
        {
            fBoundBufferUniqueID = SK_InvalidUniqueID;
            fBufferZeroKnownBound = false;
        }
    } fHWBufferState[kGrBufferTypeCount];

    struct {
        GrBlendEquation fEquation;
        GrBlendCoeff fSrcCoeff;
        GrBlendCoeff fDstCoeff;
        GrColor fConstColor;
        bool fConstColorValid;
        TriState fEnabled;

        void invalidate()
        {
=======
        void notifyVertexBufferDelete(GrGLuint id) {
            if (fBoundVertexBufferIDIsValid && id == fBoundVertexBufferID) {
                fBoundVertexBufferID = 0;
            }
            if (fVBOVertexArray) {
                fVBOVertexArray->notifyVertexBufferDelete(id);
            }
            fDefaultVertexArrayAttribState.notifyVertexBufferDelete(id);
        }

        void notifyIndexBufferDelete(GrGLuint id) {
            if (fDefaultVertexArrayBoundIndexBufferIDIsValid &&
                id == fDefaultVertexArrayBoundIndexBufferID) {
                fDefaultVertexArrayBoundIndexBufferID = 0;
            }
            if (fVBOVertexArray) {
                fVBOVertexArray->notifyIndexBufferDelete(id);
            }
        }

        void setVertexBufferID(GrGLGpu* gpu, GrGLuint id) {
            if (!fBoundVertexBufferIDIsValid || id != fBoundVertexBufferID) {
                GR_GL_CALL(gpu->glInterface(), BindBuffer(GR_GL_ARRAY_BUFFER, id));
                fBoundVertexBufferIDIsValid = true;
                fBoundVertexBufferID = id;
            }
        }

        /**
         * Binds the default vertex array and binds the index buffer. This is used when binding
         * an index buffer in order to update it.
         */
        void setIndexBufferIDOnDefaultVertexArray(GrGLGpu* gpu, GrGLuint id) {
            this->setVertexArrayID(gpu, 0);
            if (!fDefaultVertexArrayBoundIndexBufferIDIsValid ||
                id != fDefaultVertexArrayBoundIndexBufferID) {
                GR_GL_CALL(gpu->glInterface(), BindBuffer(GR_GL_ELEMENT_ARRAY_BUFFER, id));
                fDefaultVertexArrayBoundIndexBufferIDIsValid = true;
                fDefaultVertexArrayBoundIndexBufferID = id;
            }
        }

        /**
         * Binds the vertex array object that should be used to render from the vertex buffer.
         * The vertex array is bound and its attrib array state object is returned. The vertex
         * buffer is bound. The index buffer (if non-NULL) is bound to the vertex array. The
         * returned GrGLAttribArrayState should be used to set vertex attribute arrays.
         */
        GrGLAttribArrayState* bindArrayAndBuffersToDraw(GrGLGpu* gpu,
                                                        const GrGLVertexBuffer* vbuffer,
                                                        const GrGLIndexBuffer* ibuffer);

        /** Variants of the above that takes GL buffer IDs. Note that 0 does not imply that a 
            buffer won't be bound. The "default buffer" will be bound, which is used for client-side
            array rendering. */
        GrGLAttribArrayState* bindArrayAndBufferToDraw(GrGLGpu* gpu, GrGLuint vbufferID);
        GrGLAttribArrayState* bindArrayAndBuffersToDraw(GrGLGpu* gpu,
                                                        GrGLuint vbufferID,
                                                        GrGLuint ibufferID);

    private:
        GrGLAttribArrayState* internalBind(GrGLGpu* gpu, GrGLuint vbufferID, GrGLuint* ibufferID);

        GrGLuint                fBoundVertexArrayID;
        GrGLuint                fBoundVertexBufferID;
        bool                    fBoundVertexArrayIDIsValid;
        bool                    fBoundVertexBufferIDIsValid;

        GrGLuint                fDefaultVertexArrayBoundIndexBufferID;
        bool                    fDefaultVertexArrayBoundIndexBufferIDIsValid;
        // We return a non-const pointer to this from bindArrayAndBuffersToDraw when vertex array 0
        // is bound. However, this class is internal to GrGLGpu and this object never leaks out of
        // GrGLGpu.
        GrGLAttribArrayState    fDefaultVertexArrayAttribState;

        // This is used when we're using a core profile and the vertices are in a VBO.
        GrGLVertexArray*        fVBOVertexArray;
    } fHWGeometryState;

    struct {
        GrBlendEquation fEquation;
        GrBlendCoeff    fSrcCoeff;
        GrBlendCoeff    fDstCoeff;
        GrColor         fConstColor;
        bool            fConstColorValid;
        TriState        fEnabled;

        void invalidate() {
>>>>>>> miniblink49
            fEquation = static_cast<GrBlendEquation>(-1);
            fSrcCoeff = static_cast<GrBlendCoeff>(-1);
            fDstCoeff = static_cast<GrBlendCoeff>(-1);
            fConstColorValid = false;
            fEnabled = kUnknown_TriState;
        }
    } fHWBlendState;

<<<<<<< HEAD
    TriState fMSAAEnabled;

    GrStencilSettings fHWStencilSettings;
    TriState fHWStencilTestEnabled;

    GrPipelineBuilder::DrawFace fHWDrawFace;
    TriState fHWWriteToColor;
    uint32_t fHWBoundRenderTargetUniqueID;
    TriState fHWSRGBFramebuffer;
    SkTArray<uint32_t, true> fHWBoundTextureUniqueIDs;

    struct BufferTexture {
        BufferTexture()
            : fTextureID(0)
            , fKnownBound(false)
            , fAttachedBufferUniqueID(SK_InvalidUniqueID)
            , fSwizzle(GrSwizzle::RGBA())
        {
        }

        GrGLuint fTextureID;
        bool fKnownBound;
        GrPixelConfig fTexelConfig;
        uint32_t fAttachedBufferUniqueID;
        GrSwizzle fSwizzle;
    };

    SkTArray<BufferTexture, true> fHWBufferTextures;
    int fHWMaxUsedBufferTextureUnit;

    // EXT_raster_multisample.
    TriState fHWRasterMultisampleEnabled;
    int fHWNumRasterSamples;
    ///@}

    /** IDs for copy surface program. */
    struct {
        GrGLuint fProgram;
        GrGLint fTextureUniform;
        GrGLint fTexCoordXformUniform;
        GrGLint fPosXformUniform;
    } fCopyPrograms[3];
    SkAutoTUnref<GrGLBuffer> fCopyProgramArrayBuffer;

    /** IDs for texture mipmap program. (4 filter configurations) */
    struct {
        GrGLuint fProgram;
        GrGLint fTextureUniform;
        GrGLint fTexCoordXformUniform;
    } fMipmapPrograms[4];
    SkAutoTUnref<GrGLBuffer> fMipmapProgramArrayBuffer;

    struct {
        GrGLuint fProgram;
        GrGLint fColorUniform;
        GrGLint fRectUniform;
    } fWireRectProgram;
    SkAutoTUnref<GrGLBuffer> fWireRectArrayBuffer;

    static int TextureTargetToCopyProgramIdx(GrGLenum target)
    {
        switch (target) {
        case GR_GL_TEXTURE_2D:
            return 0;
        case GR_GL_TEXTURE_EXTERNAL:
            return 1;
        case GR_GL_TEXTURE_RECTANGLE:
            return 2;
        default:
            SkFAIL("Unexpected texture target type.");
            return 0;
        }
    }

    static int TextureSizeToMipmapProgramIdx(int width, int height)
    {
        const bool wide = (width > 1) && SkToBool(width & 0x1);
        const bool tall = (height > 1) && SkToBool(height & 0x1);
        return (wide ? 0x2 : 0x0) | (tall ? 0x1 : 0x0);
    }

    struct {
        GrGLuint fProgram;
        GrGLint fPosXformUniform;
        SkAutoTUnref<GrGLBuffer> fArrayBuffer;
    } fPLSSetupProgram;

    bool fHWPLSEnabled;
    bool fPLSHasBeenUsed;

    float fHWMinSampleShading;
=======
    /** IDs for copy surface program. */
    struct {
        GrGLuint    fProgram;
        GrGLint     fTextureUniform;
        GrGLint     fTexCoordXformUniform;
        GrGLint     fPosXformUniform;
        GrGLuint    fArrayBuffer;
    } fCopyProgram;

    TriState fMSAAEnabled;

    GrStencilSettings           fHWStencilSettings;
    TriState                    fHWStencilTestEnabled;


    GrPipelineBuilder::DrawFace fHWDrawFace;
    TriState                    fHWWriteToColor;
    TriState                    fHWDitherEnabled;
    uint32_t                    fHWBoundRenderTargetUniqueID;
    SkTArray<uint32_t, true>    fHWBoundTextureUniqueIDs;

    ///@}

    // we record what stencil format worked last time to hopefully exit early
    // from our loop that tries stencil formats and calls check fb status.
    int fLastSuccessfulStencilFmtIdx;
>>>>>>> miniblink49

    typedef GrGpu INHERITED;
    friend class GrGLPathRendering; // For accessing setTextureUnit.
};

#endif
