<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrSoftwarePathRenderer_DEFINED
#define GrSoftwarePathRenderer_DEFINED

#include "GrPathRenderer.h"

<<<<<<< HEAD
class GrTextureProvider;
=======
class GrContext;
>>>>>>> miniblink49

/**
 * This class uses the software side to render a path to an SkBitmap and
 * then uploads the result to the gpu
 */
class GrSoftwarePathRenderer : public GrPathRenderer {
public:
<<<<<<< HEAD
    GrSoftwarePathRenderer(GrTextureProvider* texProvider)
        : fTexProvider(texProvider)
    {
    }

private:
    static void DrawNonAARect(GrDrawContext* drawContext,
        const GrPaint* paint,
        const GrUserStencilSettings* userStencilSettings,
        const GrClip& clip,
        GrColor color,
        const SkMatrix& viewMatrix,
        const SkRect& rect,
        const SkMatrix& localMatrix);
    static void DrawAroundInvPath(GrDrawContext* drawContext,
        const GrPaint* paint,
        const GrUserStencilSettings* userStencilSettings,
        const GrClip& clip,
        GrColor color,
        const SkMatrix& viewMatrix,
        const SkIRect& devClipBounds,
        const SkIRect& devPathBounds);

    StencilSupport onGetStencilSupport(const GrShape&) const override
    {
        return GrPathRenderer::kNoSupport_StencilSupport;
    }

    bool onCanDrawPath(const CanDrawPathArgs&) const override;

    bool onDrawPath(const DrawPathArgs&) override;

private:
    GrTextureProvider* fTexProvider;
=======
    GrSoftwarePathRenderer(GrContext* context)
        : fContext(context) {
    }

    virtual bool canDrawPath(const GrDrawTarget*,
                             const GrPipelineBuilder*,
                             const SkMatrix& viewMatrix,
                             const SkPath&,
                             const GrStrokeInfo&,
                             bool antiAlias) const override;
protected:
    virtual StencilSupport onGetStencilSupport(const GrDrawTarget*,
                                               const GrPipelineBuilder*,
                                               const SkPath&,
                                               const GrStrokeInfo&) const override;

    virtual bool onDrawPath(GrDrawTarget*,
                            GrPipelineBuilder*,
                            GrColor,
                            const SkMatrix& viewMatrix,
                            const SkPath&,
                            const GrStrokeInfo&,
                            bool antiAlias) override;

private:
    GrContext*     fContext;
>>>>>>> miniblink49

    typedef GrPathRenderer INHERITED;
};

#endif
