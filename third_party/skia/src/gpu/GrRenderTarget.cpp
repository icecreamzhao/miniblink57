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
#include "GrRenderTarget.h"

#include "GrContext.h"
#include "GrDrawContext.h"
<<<<<<< HEAD
#include "GrDrawTarget.h"
=======
>>>>>>> miniblink49
#include "GrGpu.h"
#include "GrRenderTargetPriv.h"
#include "GrStencilAttachment.h"

<<<<<<< HEAD
GrRenderTarget::~GrRenderTarget()
{
    if (fLastDrawTarget) {
        fLastDrawTarget->clearRT();
    }
    SkSafeUnref(fLastDrawTarget);
}

void GrRenderTarget::discard()
{
    // go through context so that all necessary flushing occurs
    GrContext* context = this->getContext();
    if (!context) {
        return;
    }

    sk_sp<GrDrawContext> drawContext(context->drawContext(sk_ref_sp(this)));
=======
void GrRenderTarget::discard() {
    // go through context so that all necessary flushing occurs
    GrContext* context = this->getContext();
    GrDrawContext* drawContext = context ? context->drawContext() : NULL;
>>>>>>> miniblink49
    if (!drawContext) {
        return;
    }

<<<<<<< HEAD
    drawContext->discard();
}

void GrRenderTarget::flagAsNeedingResolve(const SkIRect* rect)
{
=======
    drawContext->discard(this);
}

void GrRenderTarget::flagAsNeedingResolve(const SkIRect* rect) {
>>>>>>> miniblink49
    if (kCanResolve_ResolveType == getResolveType()) {
        if (rect) {
            fResolveRect.join(*rect);
            if (!fResolveRect.intersect(0, 0, this->width(), this->height())) {
                fResolveRect.setEmpty();
            }
        } else {
            fResolveRect.setLTRB(0, 0, this->width(), this->height());
        }
    }
}

<<<<<<< HEAD
void GrRenderTarget::overrideResolveRect(const SkIRect rect)
{
=======
void GrRenderTarget::overrideResolveRect(const SkIRect rect) {
>>>>>>> miniblink49
    fResolveRect = rect;
    if (fResolveRect.isEmpty()) {
        fResolveRect.setLargestInverted();
    } else {
        if (!fResolveRect.intersect(0, 0, this->width(), this->height())) {
            fResolveRect.setLargestInverted();
        }
    }
}

<<<<<<< HEAD
void GrRenderTarget::onRelease()
{
    SkSafeSetNull(fStencilAttachment);
=======
void GrRenderTarget::onRelease() {
    this->renderTargetPriv().didAttachStencilAttachment(NULL);
>>>>>>> miniblink49

    INHERITED::onRelease();
}

<<<<<<< HEAD
void GrRenderTarget::onAbandon()
{
    SkSafeSetNull(fStencilAttachment);

    // The contents of this renderTarget are gone/invalid. It isn't useful to point back
    // the creating drawTarget.
    this->setLastDrawTarget(nullptr);
=======
void GrRenderTarget::onAbandon() {
    this->renderTargetPriv().didAttachStencilAttachment(NULL);
>>>>>>> miniblink49

    INHERITED::onAbandon();
}

<<<<<<< HEAD
void GrRenderTarget::setLastDrawTarget(GrDrawTarget* dt)
{
    if (fLastDrawTarget) {
        // The non-MDB world never closes so we can't check this condition
#ifdef ENABLE_MDB
        SkASSERT(fLastDrawTarget->isClosed());
#endif
        fLastDrawTarget->clearRT();
    }

    SkRefCnt_SafeAssign(fLastDrawTarget, dt);
}

///////////////////////////////////////////////////////////////////////////////

bool GrRenderTargetPriv::attachStencilAttachment(GrStencilAttachment* stencil)
{
    if (!stencil && !fRenderTarget->fStencilAttachment) {
        // No need to do any work since we currently don't have a stencil attachment and
        // we're not acctually adding one.
        return true;
    }
    fRenderTarget->fStencilAttachment = stencil;
    if (!fRenderTarget->completeStencilAttachment()) {
        SkSafeSetNull(fRenderTarget->fStencilAttachment);
        return false;
    }
    return true;
}

int GrRenderTargetPriv::numStencilBits() const
{
    return fRenderTarget->fStencilAttachment ? fRenderTarget->fStencilAttachment->bits() : 0;
}

const GrGpu::MultisampleSpecs&
GrRenderTargetPriv::getMultisampleSpecs(const GrStencilSettings& stencil) const
{
    return fRenderTarget->getGpu()->getMultisampleSpecs(fRenderTarget, stencil);
}

GrRenderTarget::SampleConfig GrRenderTarget::ComputeSampleConfig(const GrCaps& caps,
    int sampleCnt)
{
    return (caps.usesMixedSamples() && sampleCnt > 0)
        ? GrRenderTarget::kStencil_SampleConfig
        : GrRenderTarget::kUnified_SampleConfig;
=======
///////////////////////////////////////////////////////////////////////////////

void GrRenderTargetPriv::didAttachStencilAttachment(GrStencilAttachment* stencilAttachment) {
    SkRefCnt_SafeAssign(fRenderTarget->fStencilAttachment, stencilAttachment);
}

GrStencilAttachment* GrRenderTargetPriv::attachStencilAttachment() const {
    if (fRenderTarget->fStencilAttachment) {
        return fRenderTarget->fStencilAttachment;
    }
    if (!fRenderTarget->wasDestroyed() && fRenderTarget->canAttemptStencilAttachment()) {
        fRenderTarget->getGpu()->attachStencilAttachmentToRenderTarget(fRenderTarget);
    }
    return fRenderTarget->fStencilAttachment;
>>>>>>> miniblink49
}
