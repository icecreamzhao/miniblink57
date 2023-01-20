<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrSoftwarePathRenderer.h"
<<<<<<< HEAD
#include "GrAuditTrail.h"
#include "GrClip.h"
#include "GrSWMaskHelper.h"
#include "GrTextureProvider.h"
#include "batches/GrRectBatchFactory.h"

////////////////////////////////////////////////////////////////////////////////
bool GrSoftwarePathRenderer::onCanDrawPath(const CanDrawPathArgs& args) const
{
    // Pass on any style that applies. The caller will apply the style if a suitable renderer is
    // not found and try again with the new GrShape.
    return !args.fShape->style().applies() && SkToBool(fTexProvider);
=======
#include "GrContext.h"
#include "GrSWMaskHelper.h"
#include "GrVertexBuffer.h"

////////////////////////////////////////////////////////////////////////////////
bool GrSoftwarePathRenderer::canDrawPath(const GrDrawTarget*,
                                         const GrPipelineBuilder*,
                                         const SkMatrix& viewMatrix,
                                         const SkPath&,
                                         const GrStrokeInfo& stroke,
                                         bool antiAlias) const {
    if (NULL == fContext) {
        return false;
    }
    if (stroke.isDashed()) {
        return false;
    }
    return true;
}

GrPathRenderer::StencilSupport
GrSoftwarePathRenderer::onGetStencilSupport(const GrDrawTarget*,
                                            const GrPipelineBuilder*,
                                            const SkPath&,
                                            const GrStrokeInfo&) const {
    return GrPathRenderer::kNoSupport_StencilSupport;
>>>>>>> miniblink49
}

namespace {

////////////////////////////////////////////////////////////////////////////////
// gets device coord bounds of path (not considering the fill) and clip. The
// path bounds will be a subset of the clip bounds. returns false if
// path bounds would be empty.
<<<<<<< HEAD
bool get_shape_and_clip_bounds(int width, int height,
    const GrClip& clip,
    const GrShape& shape,
    const SkMatrix& matrix,
    SkIRect* devShapeBounds,
    SkIRect* devClipBounds)
{
    // compute bounds as intersection of rt size, clip, and path
    clip.getConservativeBounds(width, height, devClipBounds);

    if (devClipBounds->isEmpty()) {
        *devShapeBounds = SkIRect::MakeWH(width, height);
        return false;
    }
    SkRect shapeBounds = shape.styledBounds();
    if (!shapeBounds.isEmpty()) {
        SkRect shapeSBounds;
        matrix.mapRect(&shapeSBounds, shapeBounds);
        SkIRect shapeIBounds;
        shapeSBounds.roundOut(&shapeIBounds);
        *devShapeBounds = *devClipBounds;
        if (!devShapeBounds->intersect(shapeIBounds)) {
            // set the correct path bounds, as this would be used later.
            *devShapeBounds = shapeIBounds;
            return false;
        }
    } else {
        *devShapeBounds = SkIRect::EmptyIRect();
=======
bool get_path_and_clip_bounds(const GrDrawTarget* target,
                              const GrPipelineBuilder* pipelineBuilder,
                              const SkPath& path,
                              const SkMatrix& matrix,
                              SkIRect* devPathBounds,
                              SkIRect* devClipBounds) {
    // compute bounds as intersection of rt size, clip, and path
    const GrRenderTarget* rt = pipelineBuilder->getRenderTarget();
    if (NULL == rt) {
        return false;
    }

    pipelineBuilder->clip().getConservativeBounds(rt, devClipBounds);

    if (devClipBounds->isEmpty()) {
        *devPathBounds = SkIRect::MakeWH(rt->width(), rt->height());
        return false;
    }

    if (!path.getBounds().isEmpty()) {
        SkRect pathSBounds;
        matrix.mapRect(&pathSBounds, path.getBounds());
        SkIRect pathIBounds;
        pathSBounds.roundOut(&pathIBounds);
        *devPathBounds = *devClipBounds;
        if (!devPathBounds->intersect(pathIBounds)) {
            // set the correct path bounds, as this would be used later.
            *devPathBounds = pathIBounds;
            return false;
        }
    } else {
        *devPathBounds = SkIRect::EmptyIRect();
>>>>>>> miniblink49
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD

}

void GrSoftwarePathRenderer::DrawNonAARect(GrDrawContext* drawContext,
    const GrPaint* paint,
    const GrUserStencilSettings* userStencilSettings,
    const GrClip& clip,
    GrColor color,
    const SkMatrix& viewMatrix,
    const SkRect& rect,
    const SkMatrix& localMatrix)
{
    SkAutoTUnref<GrDrawBatch> batch(GrRectBatchFactory::CreateNonAAFill(color, viewMatrix, rect,
        nullptr, &localMatrix));

    GrPipelineBuilder pipelineBuilder(*paint, drawContext->mustUseHWAA(*paint));
    pipelineBuilder.setUserStencil(userStencilSettings);

    drawContext->drawBatch(pipelineBuilder, clip, batch);
}

void GrSoftwarePathRenderer::DrawAroundInvPath(GrDrawContext* drawContext,
    const GrPaint* paint,
    const GrUserStencilSettings* userStencilSettings,
    const GrClip& clip,
    GrColor color,
    const SkMatrix& viewMatrix,
    const SkIRect& devClipBounds,
    const SkIRect& devPathBounds)
{
=======
void draw_around_inv_path(GrDrawTarget* target,
                          GrPipelineBuilder* pipelineBuilder,
                          GrColor color,
                          const SkMatrix& viewMatrix,
                          const SkIRect& devClipBounds,
                          const SkIRect& devPathBounds) {
>>>>>>> miniblink49
    SkMatrix invert;
    if (!viewMatrix.invert(&invert)) {
        return;
    }

    SkRect rect;
    if (devClipBounds.fTop < devPathBounds.fTop) {
        rect.iset(devClipBounds.fLeft, devClipBounds.fTop,
<<<<<<< HEAD
            devClipBounds.fRight, devPathBounds.fTop);
        DrawNonAARect(drawContext, paint, userStencilSettings, clip, color,
            SkMatrix::I(), rect, invert);
    }
    if (devClipBounds.fLeft < devPathBounds.fLeft) {
        rect.iset(devClipBounds.fLeft, devPathBounds.fTop,
            devPathBounds.fLeft, devPathBounds.fBottom);
        DrawNonAARect(drawContext, paint, userStencilSettings, clip, color,
            SkMatrix::I(), rect, invert);
    }
    if (devClipBounds.fRight > devPathBounds.fRight) {
        rect.iset(devPathBounds.fRight, devPathBounds.fTop,
            devClipBounds.fRight, devPathBounds.fBottom);
        DrawNonAARect(drawContext, paint, userStencilSettings, clip, color,
            SkMatrix::I(), rect, invert);
    }
    if (devClipBounds.fBottom > devPathBounds.fBottom) {
        rect.iset(devClipBounds.fLeft, devPathBounds.fBottom,
            devClipBounds.fRight, devClipBounds.fBottom);
        DrawNonAARect(drawContext, paint, userStencilSettings, clip, color,
            SkMatrix::I(), rect, invert);
    }
}

////////////////////////////////////////////////////////////////////////////////
// return true on success; false on failure
bool GrSoftwarePathRenderer::onDrawPath(const DrawPathArgs& args)
{
    GR_AUDIT_TRAIL_AUTO_FRAME(args.fDrawContext->auditTrail(),
        "GrSoftwarePathRenderer::onDrawPath");
    if (!fTexProvider) {
        return false;
    }

    // We really need to know if the shape will be inverse filled or not
    bool inverseFilled = false;
    SkTLazy<GrShape> tmpShape;
    SkASSERT(!args.fShape->style().applies())
        inverseFilled
        = args.fShape->inverseFilled();

    SkIRect devShapeBounds, devClipBounds;
    if (!get_shape_and_clip_bounds(args.fDrawContext->width(), args.fDrawContext->height(),
            *args.fClip, *args.fShape,
            *args.fViewMatrix, &devShapeBounds, &devClipBounds)) {
        if (inverseFilled) {
            DrawAroundInvPath(args.fDrawContext, args.fPaint, args.fUserStencilSettings,
                *args.fClip, args.fColor,
                *args.fViewMatrix, devClipBounds, devShapeBounds);
=======
                  devClipBounds.fRight, devPathBounds.fTop);
        target->drawBWRect(pipelineBuilder, color, SkMatrix::I(), rect, NULL, &invert);
    }
    if (devClipBounds.fLeft < devPathBounds.fLeft) {
        rect.iset(devClipBounds.fLeft, devPathBounds.fTop,
                  devPathBounds.fLeft, devPathBounds.fBottom);
        target->drawBWRect(pipelineBuilder, color, SkMatrix::I(), rect, NULL, &invert);
    }
    if (devClipBounds.fRight > devPathBounds.fRight) {
        rect.iset(devPathBounds.fRight, devPathBounds.fTop,
                  devClipBounds.fRight, devPathBounds.fBottom);
        target->drawBWRect(pipelineBuilder, color, SkMatrix::I(), rect, NULL, &invert);
    }
    if (devClipBounds.fBottom > devPathBounds.fBottom) {
        rect.iset(devClipBounds.fLeft, devPathBounds.fBottom,
                  devClipBounds.fRight, devClipBounds.fBottom);
        target->drawBWRect(pipelineBuilder, color, SkMatrix::I(), rect, NULL, &invert);
    }
}

}

////////////////////////////////////////////////////////////////////////////////
// return true on success; false on failure
bool GrSoftwarePathRenderer::onDrawPath(GrDrawTarget* target,
                                        GrPipelineBuilder* pipelineBuilder,
                                        GrColor color,
                                        const SkMatrix& viewMatrix,
                                        const SkPath& path,
                                        const GrStrokeInfo& stroke,
                                        bool antiAlias) {
    if (NULL == fContext) {
        return false;
    }

    SkIRect devPathBounds, devClipBounds;
    if (!get_path_and_clip_bounds(target, pipelineBuilder, path, viewMatrix, &devPathBounds,
                                  &devClipBounds)) {
        if (path.isInverseFillType()) {
            draw_around_inv_path(target, pipelineBuilder, color, viewMatrix, devClipBounds,
                                 devPathBounds);
>>>>>>> miniblink49
        }
        return true;
    }

    SkAutoTUnref<GrTexture> texture(
<<<<<<< HEAD
        GrSWMaskHelper::DrawShapeMaskToTexture(fTexProvider, *args.fShape, devShapeBounds,
            args.fAntiAlias, args.fViewMatrix));
    if (nullptr == texture) {
        return false;
    }

    GrSWMaskHelper::DrawToTargetWithShapeMask(texture, args.fDrawContext, args.fPaint,
        args.fUserStencilSettings,
        *args.fClip, args.fColor, *args.fViewMatrix,
        devShapeBounds);

    if (inverseFilled) {
        DrawAroundInvPath(args.fDrawContext, args.fPaint, args.fUserStencilSettings,
            *args.fClip, args.fColor,
            *args.fViewMatrix, devClipBounds, devShapeBounds);
=======
            GrSWMaskHelper::DrawPathMaskToTexture(fContext, path, stroke,
                                                  devPathBounds,
                                                  antiAlias, &viewMatrix));
    if (NULL == texture) {
        return false;
    }

    GrSWMaskHelper::DrawToTargetWithPathMask(texture, target, pipelineBuilder, color, viewMatrix,
                                             devPathBounds);

    if (path.isInverseFillType()) {
        draw_around_inv_path(target, pipelineBuilder, color, viewMatrix, devClipBounds,
                             devPathBounds);
>>>>>>> miniblink49
    }

    return true;
}
