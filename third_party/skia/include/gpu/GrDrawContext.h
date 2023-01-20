/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrDrawContext_DEFINED
#define GrDrawContext_DEFINED

<<<<<<< HEAD
#include "../private/GrSingleOwner.h"
#include "GrColor.h"
#include "GrPaint.h"
#include "GrRenderTarget.h"
#include "SkRefCnt.h"
#include "SkRegion.h"
#include "SkSurfaceProps.h"

class GrAtlasTextContext;
class GrAuditTrail;
class GrClip;
class GrContext;
class GrDrawBatch;
class GrDrawContextPriv;
class GrDrawPathBatchBase;
class GrDrawingManager;
class GrDrawTarget;
class GrPaint;
class GrPathProcessor;
class GrPipelineBuilder;
class GrRenderTarget;
class GrStyle;
class GrSurface;
=======
#include "GrColor.h"
#include "SkRefCnt.h"
#include "SkSurfaceProps.h"

class GrBatch;
class GrClip;
class GrContext;
class GrDrawTarget;
class GrPaint;
class GrPathProcessor;
class GrPathRange;
class GrPipelineBuilder;
class GrRenderTarget;
class GrStrokeInfo;
class GrSurface;
class GrTextContext;
>>>>>>> miniblink49
class SkDrawFilter;
struct SkIPoint;
struct SkIRect;
class SkMatrix;
class SkPaint;
class SkPath;
struct SkPoint;
struct SkRect;
class SkRRect;
<<<<<<< HEAD
struct SkRSXform;
=======
>>>>>>> miniblink49
class SkTextBlob;

/*
 * A helper object to orchestrate draws
 */
class SK_API GrDrawContext : public SkRefCnt {
public:
    ~GrDrawContext() override;

<<<<<<< HEAD
    bool copySurface(GrSurface* src, const SkIRect& srcRect, const SkIPoint& dstPoint);

    // TODO: it is odd that we need both the SkPaint in the following 3 methods.
    // We should extract the text parameters from SkPaint and pass them separately
    // akin to GrStyle (GrTextInfo?)
    virtual void drawText(const GrClip&, const GrPaint&, const SkPaint&,
        const SkMatrix& viewMatrix, const char text[], size_t byteLength,
        SkScalar x, SkScalar y, const SkIRect& clipBounds);
    virtual void drawPosText(const GrClip&, const GrPaint&, const SkPaint&,
        const SkMatrix& viewMatrix, const char text[], size_t byteLength,
        const SkScalar pos[], int scalarsPerPosition,
        const SkPoint& offset, const SkIRect& clipBounds);
    virtual void drawTextBlob(const GrClip&, const SkPaint&,
        const SkMatrix& viewMatrix, const SkTextBlob*,
        SkScalar x, SkScalar y,
        SkDrawFilter*, const SkIRect& clipBounds);
=======
    void copySurface(GrRenderTarget* dst, GrSurface* src,
                     const SkIRect& srcRect, const SkIPoint& dstPoint);

    // TODO: it is odd that we need both the SkPaint in the following 3 methods.
    // We should extract the text parameters from SkPaint and pass them separately
    // akin to GrStrokeInfo (GrTextInfo?)
    void drawText(GrRenderTarget*, const GrClip&,  const GrPaint&, const SkPaint&,
                  const SkMatrix& viewMatrix, const char text[], size_t byteLength,
                  SkScalar x, SkScalar y, const SkIRect& clipBounds);
    void drawPosText(GrRenderTarget*, const GrClip&, const GrPaint&, const SkPaint&,
                     const SkMatrix& viewMatrix, const char text[], size_t byteLength,
                     const SkScalar pos[], int scalarsPerPosition,
                     const SkPoint& offset, const SkIRect& clipBounds);
    void drawTextBlob(GrRenderTarget*, const GrClip&, const SkPaint&,
                      const SkMatrix& viewMatrix, const SkTextBlob*,
                      SkScalar x, SkScalar y,
                      SkDrawFilter*, const SkIRect& clipBounds);

    // drawPaths is thanks to GrStencilAndCoverTextContext
    // TODO: remove
    void drawPaths(GrPipelineBuilder* pipelineBuilder,
                   const GrPathProcessor* pathProc,
                   const GrPathRange* pathRange,
                   const void* indices,
                   int /*GrDrawTarget::PathIndexType*/ indexType,
                   const float transformValues[],
                   int /*GrDrawTarget::PathTransformType*/ transformType,
                   int count,
                   int /*GrPathRendering::FillType*/ fill);
>>>>>>> miniblink49

    /**
     * Provides a perfomance hint that the render target's contents are allowed
     * to become undefined.
     */
<<<<<<< HEAD
    void discard();

    /**
     * Clear the entire or rect of the render target, ignoring any clips.
=======
    void discard(GrRenderTarget*);

    /**
     * Clear the entire or rect of the render target, ignoring any clips.
     * @param target The render target to clear.
>>>>>>> miniblink49
     * @param rect  the rect to clear or the whole thing if rect is NULL.
     * @param color the color to clear to.
     * @param canIgnoreRect allows partial clears to be converted to whole
     *                      clears on platforms for which that is cheap
     */
<<<<<<< HEAD
    void clear(const SkIRect* rect, GrColor color, bool canIgnoreRect);
=======
    void clear(GrRenderTarget*, const SkIRect* rect, GrColor color, bool canIgnoreRect);
>>>>>>> miniblink49

    /**
     *  Draw everywhere (respecting the clip) with the paint.
     */
<<<<<<< HEAD
    void drawPaint(const GrClip&, const GrPaint&, const SkMatrix& viewMatrix);
=======
    void drawPaint(GrRenderTarget*, const GrClip&, const GrPaint&, const SkMatrix& viewMatrix);
>>>>>>> miniblink49

    /**
     *  Draw the rect using a paint.
     *  @param paint        describes how to color pixels.
     *  @param viewMatrix   transformation matrix
<<<<<<< HEAD
     *  @param style        The style to apply. Null means fill. Currently path effects are not
     *                      allowed.
     *  The rects coords are used to access the paint (through texture matrix)
     */
    void drawRect(const GrClip&,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkRect&,
        const GrStyle* style = nullptr);

    /**
     * Maps a rectangle of shader coordinates to a rectangle and fills that rectangle.
=======
     *  @param strokeInfo   the stroke information (width, join, cap), and.
     *                      the dash information (intervals, count, phase).
     *                      If strokeInfo == NULL, then the rect is filled.
     *                      Otherwise, if stroke width == 0, then the stroke
     *                      is always a single pixel thick, else the rect is
     *                      mitered/beveled stroked based on stroke width.
     *  The rects coords are used to access the paint (through texture matrix)
     */
    void drawRect(GrRenderTarget*,
                  const GrClip&,
                  const GrPaint& paint,
                  const SkMatrix& viewMatrix,
                  const SkRect&,
                  const GrStrokeInfo* strokeInfo = NULL);

    /**
     * Maps a rectangle of shader coordinates to a rectangle and draws that rectangle
>>>>>>> miniblink49
     *
     * @param paint         describes how to color pixels.
     * @param viewMatrix    transformation matrix which applies to rectToDraw
     * @param rectToDraw    the rectangle to draw
     * @param localRect     the rectangle of shader coordinates applied to rectToDraw
<<<<<<< HEAD
     */
    void fillRectToRect(const GrClip&,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkRect& rectToDraw,
        const SkRect& localRect);

    /**
     * Fills a rect with a paint and a localMatrix.
     */
    void fillRectWithLocalMatrix(const GrClip& clip,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkRect& rect,
        const SkMatrix& localMatrix);
=======
     * @param localMatrix   an optional matrix to transform the shader coordinates before applying
     *                      to rectToDraw
     */
    void drawNonAARectToRect(GrRenderTarget*,
                             const GrClip&,
                             const GrPaint& paint,
                             const SkMatrix& viewMatrix,
                             const SkRect& rectToDraw,
                             const SkRect& localRect,
                             const SkMatrix* localMatrix = NULL);

    /**
     * Draws a non-AA rect with paint and a localMatrix
     */
    void drawNonAARectWithLocalMatrix(GrRenderTarget* rt,
                                      const GrClip& clip,
                                      const GrPaint& paint,
                                      const SkMatrix& viewMatrix,
                                      const SkRect& rect,
                                      const SkMatrix& localMatrix) {
        this->drawNonAARectToRect(rt, clip, paint, viewMatrix, rect, rect, &localMatrix);
    }
>>>>>>> miniblink49

    /**
     *  Draw a roundrect using a paint.
     *
     *  @param paint        describes how to color pixels.
     *  @param viewMatrix   transformation matrix
     *  @param rrect        the roundrect to draw
<<<<<<< HEAD
     *  @param style        style to apply to the rrect. Currently path effects are not allowed.
     */
    void drawRRect(const GrClip&,
        const GrPaint&,
        const SkMatrix& viewMatrix,
        const SkRRect& rrect,
        const GrStyle& style);
=======
     *  @param strokeInfo   the stroke information (width, join, cap) and
     *                      the dash information (intervals, count, phase).
     */
    void drawRRect(GrRenderTarget*,
                   const GrClip&,
                   const GrPaint&,
                   const SkMatrix& viewMatrix,
                   const SkRRect& rrect,
                   const GrStrokeInfo&);
>>>>>>> miniblink49

    /**
     *  Shortcut for drawing an SkPath consisting of nested rrects using a paint.
     *  Does not support stroking. The result is undefined if outer does not contain
     *  inner.
     *
     *  @param paint        describes how to color pixels.
     *  @param viewMatrix   transformation matrix
     *  @param outer        the outer roundrect
     *  @param inner        the inner roundrect
     */
<<<<<<< HEAD
    void drawDRRect(const GrClip&,
        const GrPaint&,
        const SkMatrix& viewMatrix,
        const SkRRect& outer,
        const SkRRect& inner);
=======
    void drawDRRect(GrRenderTarget*,
                    const GrClip&,
                    const GrPaint&,
                    const SkMatrix& viewMatrix,
                    const SkRRect& outer,
                    const SkRRect& inner);

>>>>>>> miniblink49

    /**
     * Draws a path.
     *
     * @param paint         describes how to color pixels.
     * @param viewMatrix    transformation matrix
     * @param path          the path to draw
<<<<<<< HEAD
     * @param style         style to apply to the path.
     */
    void drawPath(const GrClip&,
        const GrPaint&,
        const SkMatrix& viewMatrix,
        const SkPath&,
        const GrStyle& style);
=======
     * @param strokeInfo    the stroke information (width, join, cap) and
     *                      the dash information (intervals, count, phase).
     */
    void drawPath(GrRenderTarget*,
                  const GrClip&,
                  const GrPaint&,
                  const SkMatrix& viewMatrix,
                  const SkPath&,
                  const GrStrokeInfo&);
>>>>>>> miniblink49

    /**
     * Draws vertices with a paint.
     *
     * @param   paint           describes how to color pixels.
     * @param   viewMatrix      transformation matrix
     * @param   primitiveType   primitives type to draw.
     * @param   vertexCount     number of vertices.
     * @param   positions       array of vertex positions, required.
     * @param   texCoords       optional array of texture coordinates used
     *                          to access the paint.
     * @param   colors          optional array of per-vertex colors, supercedes
     *                          the paint's color field.
     * @param   indices         optional array of indices. If NULL vertices
     *                          are drawn non-indexed.
     * @param   indexCount      if indices is non-null then this is the
     *                          number of indices.
     */
<<<<<<< HEAD
    void drawVertices(const GrClip&,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        GrPrimitiveType primitiveType,
        int vertexCount,
        const SkPoint positions[],
        const SkPoint texs[],
        const GrColor colors[],
        const uint16_t indices[],
        int indexCount);

    /**
     * Draws textured sprites from an atlas with a paint.
     *
     * @param   paint           describes how to color pixels.
     * @param   viewMatrix      transformation matrix
     * @param   spriteCount     number of sprites.
     * @param   xform           array of compressed transformation data, required.
     * @param   texRect         array of texture rectangles used to access the paint.
     * @param   colors          optional array of per-sprite colors, supercedes
     *                          the paint's color field.
     */
    void drawAtlas(const GrClip&,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        int spriteCount,
        const SkRSXform xform[],
        const SkRect texRect[],
        const SkColor colors[]);
=======
    void drawVertices(GrRenderTarget*,
                      const GrClip&,
                      const GrPaint& paint,
                      const SkMatrix& viewMatrix,
                      GrPrimitiveType primitiveType,
                      int vertexCount,
                      const SkPoint positions[],
                      const SkPoint texs[],
                      const GrColor colors[],
                      const uint16_t indices[],
                      int indexCount);
>>>>>>> miniblink49

    /**
     * Draws an oval.
     *
     * @param paint         describes how to color pixels.
     * @param viewMatrix    transformation matrix
     * @param oval          the bounding rect of the oval.
<<<<<<< HEAD
     * @param style         style to apply to the oval. Currently path effects are not allowed.
     */
    void drawOval(const GrClip&,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkRect& oval,
        const GrStyle& style);

    /**
     *  Draw the image stretched differentially to fit into dst.
     *  center is a rect within the image, and logically divides the image
     *  into 9 sections (3x3). For example, if the middle pixel of a [5x5]
     *  image is the "center", then the center-rect should be [2, 2, 3, 3].
     *
     *  If the dst is >= the image size, then...
     *  - The 4 corners are not stretched at all.
     *  - The sides are stretched in only one axis.
     *  - The center is stretched in both axes.
     * Else, for each axis where dst < image,
     *  - The corners shrink proportionally
     *  - The sides (along the shrink axis) and center are not drawn
     */
    void drawImageNine(const GrClip&,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        int imageWidth,
        int imageHeight,
        const SkIRect& center,
        const SkRect& dst);

    bool isStencilBufferMultisampled() const
    {
        return fRenderTarget->isStencilBufferMultisampled();
    }
    bool isUnifiedMultisampled() const { return fRenderTarget->isUnifiedMultisampled(); }
    bool hasMixedSamples() const { return fRenderTarget->hasMixedSamples(); }

    bool mustUseHWAA(const GrPaint& paint) const
    {
        return paint.isAntiAlias() && fRenderTarget->isUnifiedMultisampled();
    }

    const GrSurfaceDesc& desc() const { return fRenderTarget->desc(); }
    int width() const { return fRenderTarget->width(); }
    int height() const { return fRenderTarget->height(); }
    GrPixelConfig config() const { return fRenderTarget->config(); }
    int numColorSamples() const { return fRenderTarget->numColorSamples(); }
    bool isGammaCorrect() const { return fSurfaceProps.isGammaCorrect(); }
    const SkSurfaceProps& surfaceProps() const { return fSurfaceProps; }

    bool wasAbandoned() const;

    GrRenderTarget* accessRenderTarget() { return fRenderTarget.get(); }

    sk_sp<GrRenderTarget> renderTarget() { return fRenderTarget; }

    sk_sp<GrTexture> asTexture() { return sk_ref_sp(fRenderTarget->asTexture()); }

    // Provides access to functions that aren't part of the public API.
    GrDrawContextPriv drawContextPriv();
    const GrDrawContextPriv drawContextPriv() const;

    GrAuditTrail* auditTrail() { return fAuditTrail; }

protected:
    GrDrawContext(GrContext*, GrDrawingManager*, sk_sp<GrRenderTarget>,
        const SkSurfaceProps* surfaceProps, GrAuditTrail*, GrSingleOwner*);

    GrDrawingManager* drawingManager() { return fDrawingManager; }

    SkDEBUGCODE(GrSingleOwner* singleOwner() { return fSingleOwner; })
        SkDEBUGCODE(void validate() const;)

            private : friend class GrAtlasTextBlob; // for access to drawBatch
    friend class GrStencilAndCoverTextContext; // for access to drawBatch

    friend class GrDrawingManager; // for ctor
    friend class GrDrawContextPriv;
    friend class GrTestTarget; // for access to getDrawTarget
    friend class GrSWMaskHelper; // for access to drawBatch
    friend class GrClipMaskManager; // for access to drawBatch

    // All the path renderers currently make their own batches
    friend class GrSoftwarePathRenderer; // for access to drawBatch
    friend class GrAAConvexPathRenderer; // for access to drawBatch
    friend class GrDashLinePathRenderer; // for access to drawBatch
    friend class GrAAHairLinePathRenderer; // for access to drawBatch
    friend class GrAALinearizingConvexPathRenderer; // for access to drawBatch
    friend class GrAADistanceFieldPathRenderer; // for access to drawBatch
    friend class GrDefaultPathRenderer; // for access to drawBatch
    friend class GrPLSPathRenderer; // for access to drawBatch
    friend class GrMSAAPathRenderer; // for access to drawBatch
    friend class GrStencilAndCoverPathRenderer; // for access to drawBatch
    friend class GrTessellatingPathRenderer; // for access to drawBatch

    bool drawFilledDRRect(const GrClip& clip,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkRRect& origOuter,
        const SkRRect& origInner);

    GrDrawBatch* getFillRectBatch(const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkRect& rect,
        bool* useHWAA);

    void internalDrawPath(const GrClip& clip,
        const GrPaint& paint,
        const SkMatrix& viewMatrix,
        const SkPath& path,
        const GrStyle& style);

    // This entry point allows the GrTextContext-derived classes to add their batches to
    // the drawTarget.
    void drawBatch(const GrPipelineBuilder& pipelineBuilder, const GrClip&, GrDrawBatch* batch);

    GrDrawTarget* getDrawTarget();

    GrDrawingManager* fDrawingManager;
    sk_sp<GrRenderTarget> fRenderTarget;

    // In MDB-mode the drawTarget can be closed by some other drawContext that has picked
    // it up. For this reason, the drawTarget should only ever be accessed via 'getDrawTarget'.
    GrDrawTarget* fDrawTarget;
    SkAutoTDelete<GrAtlasTextContext> fAtlasTextContext;
    GrContext* fContext;

    SkSurfaceProps fSurfaceProps;
    GrAuditTrail* fAuditTrail;

    // In debug builds we guard against improper thread handling
    SkDEBUGCODE(mutable GrSingleOwner* fSingleOwner;)
=======
     * @param strokeInfo    the stroke information (width, join, cap) and
     *                      the dash information (intervals, count, phase).
     */
    void drawOval(GrRenderTarget*,
                  const GrClip&,
                  const GrPaint& paint,
                  const SkMatrix& viewMatrix,
                  const SkRect& oval,
                  const GrStrokeInfo& strokeInfo);


private:
    friend class GrAtlasTextContext; // for access to drawBatch
    friend class GrContext; // for ctor

    GrDrawContext(GrContext*, GrDrawTarget*, const SkSurfaceProps&);

    GrTextContext* createTextContext(GrRenderTarget*, const SkSurfaceProps&);

    // Checks if the context has been abandoned and if the rendertarget is owned by this context
    bool prepareToDraw(GrRenderTarget* rt);

    void internalDrawPath(GrDrawTarget*,
                          GrPipelineBuilder*,
                          const SkMatrix& viewMatrix,
                          GrColor,
                          bool useAA,
                          const SkPath&,
                          const GrStrokeInfo&);

    // This entry point allows the GrTextContext-derived classes to add their batches to
    // the drawTarget.
    void drawBatch(GrPipelineBuilder* pipelineBuilder, GrBatch* batch);

    GrContext*          fContext;     // owning context -> no ref
    GrDrawTarget*       fDrawTarget;
    GrTextContext*      fTextContext; // lazily created

    SkSurfaceProps      fSurfaceProps;
>>>>>>> miniblink49
};

#endif
