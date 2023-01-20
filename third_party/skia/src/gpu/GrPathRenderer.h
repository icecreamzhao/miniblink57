<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrPathRenderer_DEFINED
#define GrPathRenderer_DEFINED

<<<<<<< HEAD
#include "GrDrawContext.h"
#include "GrPaint.h"
#include "GrResourceProvider.h"
#include "GrShape.h"
=======
#include "GrDrawTarget.h"
#include "GrPathRendererChain.h"
#include "GrStencil.h"
#include "GrStrokeInfo.h"
>>>>>>> miniblink49

#include "SkDrawProcs.h"
#include "SkTArray.h"

class SkPath;
<<<<<<< HEAD
class GrFixedClip;
=======

>>>>>>> miniblink49
struct GrPoint;

/**
 *  Base class for drawing paths into a GrDrawTarget.
 *
 *  Derived classes can use stages GrPaint::kTotalStages through GrPipelineBuilder::kNumStages-1.
 *  The stages before GrPaint::kTotalStages are reserved for setting up the draw (i.e., textures and
 *  filter masks).
 */
class SK_API GrPathRenderer : public SkRefCnt {
public:
<<<<<<< HEAD
=======
    

    /**
     * This is called to install custom path renderers in every GrContext at create time. The
     * default implementation in GrCreatePathRenderer_none.cpp does not add any additional
     * renderers. Link against another implementation to install your own. The first added is the
     * most preferred path renderer, second is second most preferred, etc.
     *
     * @param context   the context that will use the path renderer
     * @param prChain   the chain to add path renderers to.
     */
    static void AddPathRenderers(GrContext* context, GrPathRendererChain* prChain);


>>>>>>> miniblink49
    GrPathRenderer();

    /**
     * A caller may wish to use a path renderer to draw a path into the stencil buffer. However,
     * the path renderer itself may require use of the stencil buffer. Also a path renderer may
     * use a GrProcessor coverage stage that sets coverage to zero to eliminate pixels that are
     * covered by bounding geometry but outside the path. These exterior pixels would still be
     * rendered into the stencil.
     *
     * A GrPathRenderer can provide three levels of support for stenciling paths:
     * 1) kNoRestriction: This is the most general. The caller sets up the GrPipelineBuilder on the target
     *                    and calls drawPath(). The path is rendered exactly as the draw state
     *                    indicates including support for simultaneous color and stenciling with
     *                    arbitrary stenciling rules. Pixels partially covered by AA paths are
     *                    affected by the stencil settings.
     * 2) kStencilOnly: The path renderer cannot apply arbitrary stencil rules nor shade and stencil
     *                  simultaneously. The path renderer does support the stencilPath() function
     *                  which performs no color writes and writes a non-zero stencil value to pixels
     *                  covered by the path.
     * 3) kNoSupport: This path renderer cannot be used to stencil the path.
     */
<<<<<<< HEAD
    enum StencilSupport {
        kNoSupport_StencilSupport,
        kStencilOnly_StencilSupport,
        kNoRestriction_StencilSupport,
    };

    /**
     * This function is to get the stencil support for a particular path. The path's fill must
     * not be an inverse type. The path will always be filled and not stroked.
     *
     * @param shape   the shape that will be drawn. Must be simple fill styled and non-inverse
     *                filled.
     */
    StencilSupport getStencilSupport(const GrShape& shape) const
    {
        SkDEBUGCODE(SkPath path;)
            SkDEBUGCODE(shape.asPath(&path);)
                SkASSERT(shape.style().isSimpleFill());
        SkASSERT(!path.isInverseFillType());
        return this->onGetStencilSupport(shape);
    }

    /** Args to canDrawPath()
     *
     * fShaderCaps       The shader caps
     * fPipelineBuilder  The pipelineBuilder
     * fViewMatrix       The viewMatrix
     * fShape            The shape to draw
     * fAntiAlias        True if anti-aliasing is required.
     */
    struct CanDrawPathArgs {
        const GrShaderCaps* fShaderCaps;
        const SkMatrix* fViewMatrix;
        const GrShape* fShape;
        bool fAntiAlias;

        // These next two are only used by GrStencilAndCoverPathRenderer
        bool fHasUserStencilSettings;
        bool fIsStencilBufferMSAA;

#ifdef SK_DEBUG
        void validate() const
        {
            SkASSERT(fShaderCaps);
            SkASSERT(fViewMatrix);
            SkASSERT(fShape);
        }
#endif
    };

=======
    typedef GrPathRendererChain::StencilSupport StencilSupport;
    static const StencilSupport kNoSupport_StencilSupport =
        GrPathRendererChain::kNoSupport_StencilSupport;
    static const StencilSupport kStencilOnly_StencilSupport =
        GrPathRendererChain::kStencilOnly_StencilSupport;
    static const StencilSupport kNoRestriction_StencilSupport =
        GrPathRendererChain::kNoRestriction_StencilSupport;

    /**
     * This function is to get the stencil support for a particular path. The path's fill must
     * not be an inverse type.
     *
     * @param target    target that the path will be rendered to
     * @param path      the path that will be drawn
     * @param stroke    the stroke information (width, join, cap).
     */
    StencilSupport getStencilSupport(const GrDrawTarget* target,
                                     const GrPipelineBuilder* pipelineBuilder,
                                     const SkPath& path,
                                     const GrStrokeInfo& stroke) const {
        SkASSERT(!path.isInverseFillType());
        return this->onGetStencilSupport(target, pipelineBuilder, path, stroke);
    }

>>>>>>> miniblink49
    /**
     * Returns true if this path renderer is able to render the path. Returning false allows the
     * caller to fallback to another path renderer This function is called when searching for a path
     * renderer capable of rendering a path.
     *
<<<<<<< HEAD
     * @return  true if the path can be drawn by this object, false otherwise.
     */
    bool canDrawPath(const CanDrawPathArgs& args) const
    {
        SkDEBUGCODE(args.validate();) return this->onCanDrawPath(args);
    }

    /**
     * Args to drawPath()
     *
     * fTarget                The target that the path will be rendered to
     * fResourceProvider      The resource provider for creating gpu resources to render the path
     * fPipelineBuilder       The pipelineBuilder
     * fClip                  The clip
     * fColor                 Color to render with
     * fViewMatrix            The viewMatrix
     * fShape                 The shape to draw
     * fAntiAlias             true if anti-aliasing is required.
     * fGammaCorrect          true if gamma-correct rendering is to be used.
     */
    struct DrawPathArgs {
        GrResourceProvider* fResourceProvider;
        const GrPaint* fPaint;
        const GrUserStencilSettings* fUserStencilSettings;

        GrDrawContext* fDrawContext;
        const GrClip* fClip;
        GrColor fColor;
        const SkMatrix* fViewMatrix;
        const GrShape* fShape;
        bool fAntiAlias;
        bool fGammaCorrect;
#ifdef SK_DEBUG
        void validate() const
        {
            SkASSERT(fResourceProvider);
            SkASSERT(fPaint);
            SkASSERT(fUserStencilSettings);
            SkASSERT(fDrawContext);
            SkASSERT(fClip);
            SkASSERT(fViewMatrix);
            SkASSERT(fShape);
        }
#endif
    };

    /**
     * Draws the path into the draw target. If getStencilSupport() would return kNoRestriction then
     * the subclass must respect the stencil settings of the GrPipelineBuilder.
     */
    bool drawPath(const DrawPathArgs& args)
    {
        SkDEBUGCODE(args.validate();)
#ifdef SK_DEBUG
            CanDrawPathArgs canArgs;
        canArgs.fShaderCaps = args.fResourceProvider->caps()->shaderCaps();
        canArgs.fViewMatrix = args.fViewMatrix;
        canArgs.fShape = args.fShape;
        canArgs.fAntiAlias = args.fAntiAlias;

        canArgs.fHasUserStencilSettings = !args.fUserStencilSettings->isUnused();
        canArgs.fIsStencilBufferMSAA = args.fDrawContext->isStencilBufferMultisampled();
        SkASSERT(this->canDrawPath(canArgs));
        if (!args.fUserStencilSettings->isUnused()) {
            SkPath path;
            args.fShape->asPath(&path);
            SkASSERT(args.fShape->style().isSimpleFill());
            SkASSERT(kNoRestriction_StencilSupport == this->getStencilSupport(*args.fShape));
        }
#endif
        return this->onDrawPath(args);
    }

    /* Args to stencilPath().
     *
     * fResourceProvider      The resource provider for creating gpu resources to render the path
     * fDrawContext           The target of the draws
     * fViewMatrix            Matrix applied to the path.
     * fPath                  The path to draw.
     * fIsAA                  Is the path to be drawn AA (only set when MSAA is available)
     */
    struct StencilPathArgs {
        GrResourceProvider* fResourceProvider;
        GrDrawContext* fDrawContext;
        const GrFixedClip* fClip;
        const SkMatrix* fViewMatrix;
        bool fIsAA;
        const GrShape* fShape;

#ifdef SK_DEBUG
        void validate() const
        {
            SkASSERT(fResourceProvider);
            SkASSERT(fDrawContext);
            SkASSERT(fViewMatrix);
            SkASSERT(fShape);
            SkASSERT(fShape->style().isSimpleFill())
                SkPath path;
            fShape->asPath(&path);
            SkASSERT(!path.isInverseFillType());
        }
#endif
    };
=======
     * @param target           The target that the path will be rendered to
     * @param pipelineBuilder  The pipelineBuilder
     * @param viewMatrix       The viewMatrix
     * @param path             The path to draw
     * @param stroke           The stroke information (width, join, cap)
     * @param antiAlias        True if anti-aliasing is required.
     *
     * @return  true if the path can be drawn by this object, false otherwise.
     */
    virtual bool canDrawPath(const GrDrawTarget* target,
                             const GrPipelineBuilder* pipelineBuilder,
                             const SkMatrix& viewMatrix,
                             const SkPath& path,
                             const GrStrokeInfo& rec,
                             bool antiAlias) const = 0;
    /**
     * Draws the path into the draw target. If getStencilSupport() would return kNoRestriction then
     * the subclass must respect the stencil settings of the target's draw state.
     *
     * @param target                The target that the path will be rendered to
     * @param pipelineBuilder       The pipelineBuilder
     * @param viewMatrix            The viewMatrix
     * @param path                  the path to draw.
     * @param stroke                the stroke information (width, join, cap)
     * @param antiAlias             true if anti-aliasing is required.
     */
    bool drawPath(GrDrawTarget* target,
                  GrPipelineBuilder* ds,
                  GrColor color,
                  const SkMatrix& viewMatrix,
                  const SkPath& path,
                  const GrStrokeInfo& stroke,
                  bool antiAlias) {
        SkASSERT(!path.isEmpty());
        SkASSERT(this->canDrawPath(target, ds, viewMatrix, path, stroke, antiAlias));
        SkASSERT(ds->getStencil().isDisabled() ||
                 kNoRestriction_StencilSupport == this->getStencilSupport(target, ds, path,
                                                                          stroke));
        return this->onDrawPath(target, ds, color, viewMatrix, path, stroke, antiAlias);
    }
>>>>>>> miniblink49

    /**
     * Draws the path to the stencil buffer. Assume the writable stencil bits are already
     * initialized to zero. The pixels inside the path will have non-zero stencil values afterwards.
<<<<<<< HEAD
     */
    void stencilPath(const StencilPathArgs& args)
    {
        SkDEBUGCODE(args.validate();)
            SkASSERT(kNoSupport_StencilSupport != this->getStencilSupport(*args.fShape));
        this->onStencilPath(args);
=======
     *
     * @param path                  the path to draw.
     * @param stroke                the stroke information (width, join, cap)
     * @param target                target that the path will be rendered to
     */
    void stencilPath(GrDrawTarget* target,
                     GrPipelineBuilder* ds,
                     const SkMatrix& viewMatrix,
                     const SkPath& path,
                     const GrStrokeInfo& stroke) {
        SkASSERT(!path.isEmpty());
        SkASSERT(kNoSupport_StencilSupport != this->getStencilSupport(target, ds, path, stroke));
        this->onStencilPath(target, ds, viewMatrix, path, stroke);
>>>>>>> miniblink49
    }

    // Helper for determining if we can treat a thin stroke as a hairline w/ coverage.
    // If we can, we draw lots faster (raster device does this same test).
<<<<<<< HEAD
    static bool IsStrokeHairlineOrEquivalent(const GrStyle& style, const SkMatrix& matrix,
        SkScalar* outCoverage)
    {
        if (style.pathEffect()) {
            return false;
        }
        const SkStrokeRec& stroke = style.strokeRec();
=======
    static bool IsStrokeHairlineOrEquivalent(const GrStrokeInfo& stroke, const SkMatrix& matrix,
                                             SkScalar* outCoverage) {
        if (stroke.isDashed()) {
            return false;
        }
>>>>>>> miniblink49
        if (stroke.isHairlineStyle()) {
            if (outCoverage) {
                *outCoverage = SK_Scalar1;
            }
            return true;
        }
<<<<<<< HEAD
        return stroke.getStyle() == SkStrokeRec::kStroke_Style && SkDrawTreatAAStrokeAsHairline(stroke.getWidth(), matrix, outCoverage);
    }

protected:
    // Helper for getting the device bounds of a path. Inverse filled paths will have bounds set
    // by devSize. Non-inverse path bounds will not necessarily be clipped to devSize.
    static void GetPathDevBounds(const SkPath& path,
        int devW,
        int devH,
        const SkMatrix& matrix,
        SkRect* bounds);

private:
    /**
     * Subclass overrides if it has any limitations of stenciling support.
     */
    virtual StencilSupport onGetStencilSupport(const GrShape&) const
    {
=======
        return stroke.getStyle() == SkStrokeRec::kStroke_Style &&
            SkDrawTreatAAStrokeAsHairline(stroke.getWidth(), matrix, outCoverage);
    }

protected:
    /**
     * Subclass overrides if it has any limitations of stenciling support.
     */
    virtual StencilSupport onGetStencilSupport(const GrDrawTarget*,
                                               const GrPipelineBuilder*,
                                               const SkPath&,
                                               const GrStrokeInfo&) const {
>>>>>>> miniblink49
        return kNoRestriction_StencilSupport;
    }

    /**
     * Subclass implementation of drawPath()
     */
<<<<<<< HEAD
    virtual bool onDrawPath(const DrawPathArgs& args) = 0;

    /**
     * Subclass implementation of canDrawPath()
     */
    virtual bool onCanDrawPath(const CanDrawPathArgs& args) const = 0;
=======
    virtual bool onDrawPath(GrDrawTarget*,
                            GrPipelineBuilder*,
                            GrColor,
                            const SkMatrix& viewMatrix,
                            const SkPath&,
                            const GrStrokeInfo&,
                            bool antiAlias) = 0;
>>>>>>> miniblink49

    /**
     * Subclass implementation of stencilPath(). Subclass must override iff it ever returns
     * kStencilOnly in onGetStencilSupport().
     */
<<<<<<< HEAD
    virtual void onStencilPath(const StencilPathArgs& args)
    {
        static constexpr GrUserStencilSettings kIncrementStencil(
            GrUserStencilSettings::StaticInit<
                0xffff,
                GrUserStencilTest::kAlways,
                0xffff,
                GrUserStencilOp::kReplace,
                GrUserStencilOp::kReplace,
                0xffff>());

        GrPaint paint;

        DrawPathArgs drawArgs;
        drawArgs.fResourceProvider = args.fResourceProvider;
        drawArgs.fPaint = &paint;
        drawArgs.fUserStencilSettings = &kIncrementStencil;
        drawArgs.fDrawContext = args.fDrawContext;
        drawArgs.fColor = GrColor_WHITE;
        drawArgs.fViewMatrix = args.fViewMatrix;
        drawArgs.fShape = args.fShape;
        drawArgs.fAntiAlias = false; // In this case the MSAA handles the AA so we want to draw BW
        drawArgs.fGammaCorrect = false;
        this->drawPath(drawArgs);
    }

=======
    virtual void onStencilPath(GrDrawTarget* target,
                               GrPipelineBuilder* pipelineBuilder,
                               const SkMatrix& viewMatrix,
                               const SkPath& path,
                               const GrStrokeInfo& stroke) {
        GR_STATIC_CONST_SAME_STENCIL(kIncrementStencil,
                                     kReplace_StencilOp,
                                     kReplace_StencilOp,
                                     kAlways_StencilFunc,
                                     0xffff,
                                     0xffff,
                                     0xffff);
        pipelineBuilder->setStencil(kIncrementStencil);
        pipelineBuilder->setDisableColorXPFactory();
        this->drawPath(target, pipelineBuilder, GrColor_WHITE, viewMatrix, path, stroke, false);
    }

    // Helper for getting the device bounds of a path. Inverse filled paths will have bounds set
    // by devSize. Non-inverse path bounds will not necessarily be clipped to devSize.
    static void GetPathDevBounds(const SkPath& path,
                                 int devW,
                                 int devH,
                                 const SkMatrix& matrix,
                                 SkRect* bounds);

    // Helper version that gets the dev width and height from a GrSurface.
    static void GetPathDevBounds(const SkPath& path,
                                 const GrSurface* device,
                                 const SkMatrix& matrix,
                                 SkRect* bounds) {
        GetPathDevBounds(path, device->width(), device->height(), matrix, bounds);
    }

private:

>>>>>>> miniblink49
    typedef SkRefCnt INHERITED;
};

#endif
