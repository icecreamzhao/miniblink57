<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "GrPathRendererChain.h"

#include "GrCaps.h"
#include "GrContext.h"
<<<<<<< HEAD
#include "GrGpu.h"
#include "gl/GrGLCaps.h"
#include "glsl/GrGLSLCaps.h"

#include "batches/GrAAConvexPathRenderer.h"
#include "batches/GrAADistanceFieldPathRenderer.h"
#include "batches/GrAAHairLinePathRenderer.h"
#include "batches/GrAALinearizingConvexPathRenderer.h"
#include "batches/GrDashLinePathRenderer.h"
#include "batches/GrDefaultPathRenderer.h"
#include "batches/GrMSAAPathRenderer.h"
#include "batches/GrPLSPathRenderer.h"
#include "batches/GrStencilAndCoverPathRenderer.h"
#include "batches/GrTessellatingPathRenderer.h"

GrPathRendererChain::GrPathRendererChain(GrContext* context)
{
    const GrCaps& caps = *context->caps();
    this->addPathRenderer(new GrDashLinePathRenderer)->unref();

    if (GrPathRenderer* pr = GrStencilAndCoverPathRenderer::Create(context->resourceProvider(),
            caps)) {
        this->addPathRenderer(pr)->unref();
    }
    if (caps.sampleShadingSupport()) {
        this->addPathRenderer(new GrMSAAPathRenderer)->unref();
    }
    this->addPathRenderer(new GrTessellatingPathRenderer)->unref();
    this->addPathRenderer(new GrAAHairLinePathRenderer)->unref();
    this->addPathRenderer(new GrAAConvexPathRenderer)->unref();
    this->addPathRenderer(new GrAALinearizingConvexPathRenderer)->unref();
    if (caps.shaderCaps()->plsPathRenderingSupport()) {
        this->addPathRenderer(new GrPLSPathRenderer)->unref();
    }
    this->addPathRenderer(new GrAADistanceFieldPathRenderer)->unref();
    this->addPathRenderer(new GrDefaultPathRenderer(caps.twoSidedStencilSupport(),
                              caps.stencilWrapOpsSupport()))
        ->unref();
}

GrPathRendererChain::~GrPathRendererChain()
{
=======
#include "GrDefaultPathRenderer.h"
#include "GrGpu.h"

GrPathRendererChain::GrPathRendererChain(GrContext* context)
    : fInit(false)
    , fOwner(context) {
}

GrPathRendererChain::~GrPathRendererChain() {
>>>>>>> miniblink49
    for (int i = 0; i < fChain.count(); ++i) {
        fChain[i]->unref();
    }
}

<<<<<<< HEAD
GrPathRenderer* GrPathRendererChain::addPathRenderer(GrPathRenderer* pr)
{
=======
GrPathRenderer* GrPathRendererChain::addPathRenderer(GrPathRenderer* pr) {
>>>>>>> miniblink49
    fChain.push_back() = pr;
    pr->ref();
    return pr;
}

<<<<<<< HEAD
GrPathRenderer* GrPathRendererChain::getPathRenderer(
    const GrPathRenderer::CanDrawPathArgs& args,
    DrawType drawType,
    GrPathRenderer::StencilSupport* stencilSupport)
{
    GR_STATIC_ASSERT(GrPathRenderer::kNoSupport_StencilSupport < GrPathRenderer::kStencilOnly_StencilSupport);
    GR_STATIC_ASSERT(GrPathRenderer::kStencilOnly_StencilSupport < GrPathRenderer::kNoRestriction_StencilSupport);
    GrPathRenderer::StencilSupport minStencilSupport;
    if (kStencilOnly_DrawType == drawType) {
        minStencilSupport = GrPathRenderer::kStencilOnly_StencilSupport;
    } else if (kStencilAndColor_DrawType == drawType || kStencilAndColorAntiAlias_DrawType == drawType) {
=======
GrPathRenderer* GrPathRendererChain::getPathRenderer(const GrDrawTarget* target,
                                                     const GrPipelineBuilder* pipelineBuilder,
                                                     const SkMatrix& viewMatrix,
                                                     const SkPath& path,
                                                     const GrStrokeInfo& stroke,
                                                     DrawType drawType,
                                                     StencilSupport* stencilSupport) {
    if (!fInit) {
        this->init();
    }
    bool antiAlias = (kColorAntiAlias_DrawType == drawType ||
                      kStencilAndColorAntiAlias_DrawType == drawType);

    GR_STATIC_ASSERT(GrPathRenderer::kNoSupport_StencilSupport <
                     GrPathRenderer::kStencilOnly_StencilSupport);
    GR_STATIC_ASSERT(GrPathRenderer::kStencilOnly_StencilSupport <
                     GrPathRenderer::kNoRestriction_StencilSupport);
    GrPathRenderer::StencilSupport minStencilSupport;
    if (kStencilOnly_DrawType == drawType) {
        minStencilSupport = GrPathRenderer::kStencilOnly_StencilSupport;
    } else if (kStencilAndColor_DrawType == drawType ||
               kStencilAndColorAntiAlias_DrawType == drawType) {
>>>>>>> miniblink49
        minStencilSupport = GrPathRenderer::kNoRestriction_StencilSupport;
    } else {
        minStencilSupport = GrPathRenderer::kNoSupport_StencilSupport;
    }
<<<<<<< HEAD
    if (minStencilSupport != GrPathRenderer::kNoSupport_StencilSupport) {
        // We don't support (and shouldn't need) stenciling of non-fill paths.
        if (!args.fShape->style().isSimpleFill()) {
            return nullptr;
        }
    }

    for (int i = 0; i < fChain.count(); ++i) {
        if (fChain[i]->canDrawPath(args)) {
            if (GrPathRenderer::kNoSupport_StencilSupport != minStencilSupport) {
                GrPathRenderer::StencilSupport support = fChain[i]->getStencilSupport(*args.fShape);
=======


    for (int i = 0; i < fChain.count(); ++i) {
        if (fChain[i]->canDrawPath(target, pipelineBuilder, viewMatrix, path, stroke, antiAlias)) {
            if (GrPathRenderer::kNoSupport_StencilSupport != minStencilSupport) {
                GrPathRenderer::StencilSupport support =
                    fChain[i]->getStencilSupport(target, pipelineBuilder, path, stroke);
>>>>>>> miniblink49
                if (support < minStencilSupport) {
                    continue;
                } else if (stencilSupport) {
                    *stencilSupport = support;
                }
            }
            return fChain[i];
        }
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
}

void GrPathRendererChain::init() {
    SkASSERT(!fInit);
    const GrCaps* caps = fOwner->caps();
    bool twoSided = caps->twoSidedStencilSupport();
    bool wrapOp = caps->stencilWrapOpsSupport();
    GrPathRenderer::AddPathRenderers(fOwner, this);
    this->addPathRenderer(SkNEW_ARGS(GrDefaultPathRenderer,
                                     (twoSided, wrapOp)))->unref();
    fInit = true;
>>>>>>> miniblink49
}
