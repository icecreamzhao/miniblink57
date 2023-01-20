/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrResourceProvider_DEFINED
#define GrResourceProvider_DEFINED

<<<<<<< HEAD
#include "GrBatchAtlas.h"
#include "GrBuffer.h"
#include "GrPathRange.h"
#include "GrTextureProvider.h"

class GrBatchAtlas;
class GrPath;
class GrRenderTarget;
class GrSingleOwner;
class GrStencilAttachment;
class GrStyle;
=======
#include "GrIndexBuffer.h"
#include "GrTextureProvider.h"
#include "GrPathRange.h"

class GrIndexBuffer;
class GrPath;
class GrStrokeInfo;
class GrVertexBuffer;
>>>>>>> miniblink49
class SkDescriptor;
class SkPath;
class SkTypeface;

/**
 * An extension of the texture provider for arbitrary resource types. This class is intended for
 * use within the Gr code base, not by clients or extensions (e.g. third party GrProcessor
 * derivatives).
<<<<<<< HEAD
 *
 * This currently inherits from GrTextureProvider non-publically to force callers to provider
 * make a flags (pendingIO) decision and not use the GrTP methods that don't take flags. This
 * can be relaxed once https://bug.skia.org/4156 is fixed.
 */
class GrResourceProvider : protected GrTextureProvider {
public:
    GrResourceProvider(GrGpu* gpu, GrResourceCache* cache, GrSingleOwner* owner);

    template <typename T>
    T* findAndRefTByUniqueKey(const GrUniqueKey& key)
    {
=======
 */
class GrResourceProvider : public GrTextureProvider {
public:

    GrResourceProvider(GrGpu* gpu, GrResourceCache* cache);

    template <typename T> T* findAndRefTByUniqueKey(const GrUniqueKey& key) {
>>>>>>> miniblink49
        return static_cast<T*>(this->findAndRefResourceByUniqueKey(key));
    }

    /**
     * Either finds and refs, or creates an index buffer for instanced drawing with a specific
     * pattern if the index buffer is not found. If the return is non-null, the caller owns
<<<<<<< HEAD
     * a ref on the returned GrBuffer.
=======
     * a ref on the returned GrIndexBuffer.
>>>>>>> miniblink49
     *
     * @param pattern     the pattern of indices to repeat
     * @param patternSize size in bytes of the pattern
     * @param reps        number of times to repeat the pattern
     * @param vertCount   number of vertices the pattern references
     * @param key         Key to be assigned to the index buffer.
     *
<<<<<<< HEAD
     * @return The index buffer if successful, otherwise nullptr.
     */
    const GrBuffer* findOrCreateInstancedIndexBuffer(const uint16_t* pattern,
        int patternSize,
        int reps,
        int vertCount,
        const GrUniqueKey& key)
    {
        if (GrBuffer* buffer = this->findAndRefTByUniqueKey<GrBuffer>(key)) {
=======
     * @return The index buffer if successful, otherwise NULL.
     */
    const GrIndexBuffer* refOrCreateInstancedIndexBuffer(const uint16_t* pattern,
                                                         int patternSize,
                                                         int reps,
                                                         int vertCount,
                                                         const GrUniqueKey& key) {
        if (GrIndexBuffer* buffer = this->findAndRefTByUniqueKey<GrIndexBuffer>(key)) {
>>>>>>> miniblink49
            return buffer;
        }
        return this->createInstancedIndexBuffer(pattern, patternSize, reps, vertCount, key);
    }

    /**
     * Returns an index buffer that can be used to render quads.
     * Six indices per quad: 0, 1, 2, 0, 2, 3, etc.
<<<<<<< HEAD
     * The max number of quads is the buffer's index capacity divided by 6.
     * Draw with kTriangles_GrPrimitiveType
     * @ return the quad index buffer
     */
    const GrBuffer* refQuadIndexBuffer()
    {
        if (GrBuffer* buffer = this->findAndRefTByUniqueKey<GrBuffer>(fQuadIndexBufferKey)) {
=======
     * The max number of quads can be queried using GrIndexBuffer::maxQuads().
     * Draw with kTriangles_GrPrimitiveType
     * @ return the quad index buffer
     */
    const GrIndexBuffer* refQuadIndexBuffer() {
        if (GrIndexBuffer* buffer =
            this->findAndRefTByUniqueKey<GrIndexBuffer>(fQuadIndexBufferKey)) {
>>>>>>> miniblink49
            return buffer;
        }
        return this->createQuadIndexBuffer();
    }

    /**
     * Factories for GrPath and GrPathRange objects. It's an error to call these if path rendering
     * is not supported.
     */
<<<<<<< HEAD
    GrPath* createPath(const SkPath&, const GrStyle&);
    GrPathRange* createPathRange(GrPathRange::PathGenerator*, const GrStyle&);
    GrPathRange* createGlyphs(const SkTypeface*, const SkScalerContextEffects&,
        const SkDescriptor*, const GrStyle&);

    using GrTextureProvider::abandon;
    using GrTextureProvider::assignUniqueKeyToResource;
    using GrTextureProvider::findAndRefResourceByUniqueKey;
    using GrTextureProvider::findAndRefTextureByUniqueKey;

    enum Flags {
        /** If the caller intends to do direct reads/writes to/from the CPU then this flag must be
         *  set when accessing resources during a GrDrawTarget flush. This includes the execution of
         *  GrBatch objects. The reason is that these memory operations are done immediately and
         *  will occur out of order WRT the operations being flushed.
         *  Make this automatic: https://bug.skia.org/4156
         */
        kNoPendingIO_Flag = kNoPendingIO_ScratchTextureFlag,
    };

    /**
     * Returns a buffer.
     *
     * @param size            minimum size of buffer to return.
     * @param intendedType    hint to the graphics subsystem about what the buffer will be used for.
     * @param GrAccessPattern hint to the graphics subsystem about how the data will be accessed.
     * @param flags           see Flags enum.
     * @param data            optional data with which to initialize the buffer.
     *
     * @return the buffer if successful, otherwise nullptr.
     */
    GrBuffer* createBuffer(size_t size, GrBufferType intendedType, GrAccessPattern, uint32_t flags,
        const void* data = nullptr);

    GrTexture* createApproxTexture(const GrSurfaceDesc& desc, uint32_t flags)
    {
        SkASSERT(0 == flags || kNoPendingIO_Flag == flags);
        return this->internalCreateApproxTexture(desc, flags);
    }

    /**  Returns a GrBatchAtlas. This function can be called anywhere, but the returned atlas should
     *   only be used inside of GrBatch::generateGeometry
     *   @param GrPixelConfig    The pixel config which this atlas will store
     *   @param width            width in pixels of the atlas
     *   @param height           height in pixels of the atlas
     *   @param numPlotsX        The number of plots the atlas should be broken up into in the X
     *                           direction
     *   @param numPlotsY        The number of plots the atlas should be broken up into in the Y
     *                           direction
     *   @param func             An eviction function which will be called whenever the atlas has to
     *                           evict data
     *   @param data             User supplied data which will be passed into func whenver an
     *                           eviction occurs
     *
     *   @return                 An initialized GrBatchAtlas, or nullptr if creation fails
     */
    GrBatchAtlas* createAtlas(GrPixelConfig, int width, int height, int numPlotsX, int numPlotsY,
        GrBatchAtlas::EvictionFunc func, void* data);

    /**
     * If passed in render target already has a stencil buffer, return it. Otherwise attempt to
     * attach one.
     */
    GrStencilAttachment* attachStencilAttachment(GrRenderTarget* rt);

    const GrCaps* caps() { return this->gpu()->caps(); }

    /**
      * Wraps an existing texture with a GrRenderTarget object. This is useful when the provided
      * texture has a format that cannot be textured from by Skia, but we want to raster to it.
      *
      * The texture is wrapped as borrowed. The texture object will not be freed once the
      * render target is destroyed.
      *
      * @return GrRenderTarget object or NULL on failure.
      */
    GrRenderTarget* wrapBackendTextureAsRenderTarget(const GrBackendTextureDesc& desc);

private:
    const GrBuffer* createInstancedIndexBuffer(const uint16_t* pattern,
        int patternSize,
        int reps,
        int vertCount,
        const GrUniqueKey& key);

    const GrBuffer* createQuadIndexBuffer();
=======
    GrPath* createPath(const SkPath&, const GrStrokeInfo&);
    GrPathRange* createPathRange(GrPathRange::PathGenerator*, const GrStrokeInfo&);
    GrPathRange* createGlyphs(const SkTypeface*, const SkDescriptor*, const GrStrokeInfo&);


    using GrTextureProvider::assignUniqueKeyToResource;
    using GrTextureProvider::findAndRefResourceByUniqueKey;
    using GrTextureProvider::abandon;

    GrIndexBuffer* getIndexBuffer(size_t size, bool dynamic, bool calledDuringFlush);
    GrVertexBuffer* getVertexBuffer(size_t size, bool dynamic, bool calledDuringFlush);

private:
    const GrIndexBuffer* createInstancedIndexBuffer(const uint16_t* pattern,
                                                    int patternSize,
                                                    int reps,
                                                    int vertCount,
                                                    const GrUniqueKey& key);

    const GrIndexBuffer* createQuadIndexBuffer();
>>>>>>> miniblink49

    GrUniqueKey fQuadIndexBufferKey;

    typedef GrTextureProvider INHERITED;
};

#endif
