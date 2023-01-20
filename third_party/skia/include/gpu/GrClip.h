/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrClip_DEFINED
#define GrClip_DEFINED

<<<<<<< HEAD
#include "GrFragmentProcessor.h"
#include "GrTypesPriv.h"
#include "SkClipStack.h"

class GrDrawContext;
class GrPipelineBuilder;

/**
 * Produced by GrClip. It provides a set of modifications to the drawing state that are used to
 * create the final GrPipeline for a GrBatch.
 */
class GrAppliedClip : public SkNoncopyable {
public:
    GrAppliedClip()
        : fHasStencilClip(false)
    {
    }
    GrFragmentProcessor* getClipCoverageFragmentProcessor() const
    {
        return fClipCoverageFP.get();
    }
    const GrScissorState& scissorState() const { return fScissorState; }
    bool hasStencilClip() const { return fHasStencilClip; }

    void makeStencil(bool hasStencil)
    {
        fClipCoverageFP = nullptr;
        fScissorState.setDisabled();
        fHasStencilClip = hasStencil;
    }

    void makeScissoredStencil(bool hasStencil, const SkIRect& scissor)
    {
        fClipCoverageFP = nullptr;
        fScissorState.set(scissor);
        fHasStencilClip = hasStencil;
    }

    void makeFPBased(sk_sp<GrFragmentProcessor> fp)
    {
        fClipCoverageFP = fp;
        fScissorState.setDisabled();
        fHasStencilClip = false;
    }

    void makeScissoredFPBased(sk_sp<GrFragmentProcessor> fp, SkIRect& scissor)
    {
        fClipCoverageFP = fp;
        fScissorState.set(scissor);
        fHasStencilClip = false;
    }

private:
    sk_sp<GrFragmentProcessor> fClipCoverageFP;
    GrScissorState fScissorState;
    bool fHasStencilClip;

    typedef SkNoncopyable INHERITED;
};

/**
 * GrClip is an abstract base class for applying a clip. It constructs a clip mask if necessary, and
 * fills out a GrAppliedClip instructing the caller on how to set up the draw state.
 */
class GrClip {
public:
    virtual bool quickContains(const SkRect&) const = 0;
    virtual void getConservativeBounds(int width, int height, SkIRect* devResult,
        bool* isIntersectionOfRects = nullptr) const = 0;
    virtual bool apply(GrContext*, const GrPipelineBuilder&, GrDrawContext*,
        const SkRect* devBounds, GrAppliedClip*) const = 0;

    virtual ~GrClip() { }
};

/**
 * Specialized implementation for no clip.
 */
class GrNoClip final : public GrClip {
private:
    bool quickContains(const SkRect&) const final { return true; }
    void getConservativeBounds(int width, int height, SkIRect* devResult,
        bool* isIntersectionOfRects) const final;
    bool apply(GrContext*, const GrPipelineBuilder&, GrDrawContext*,
        const SkRect*, GrAppliedClip*) const final { return true; }
};

/**
 * GrFixedClip is a clip that can be represented by fixed-function hardware. It never modifies the
 * stencil buffer itself, but can be configured to use whatever clip is already there.
 */
class GrFixedClip final : public GrClip {
public:
    GrFixedClip()
        : fHasStencilClip(false)
    {
    }
    GrFixedClip(const SkIRect& scissorRect)
        : fScissorState(scissorRect)
        , fHasStencilClip(false)
    {
    }

    void reset()
    {
        fScissorState.setDisabled();
        fHasStencilClip = false;
    }

    void reset(const SkIRect& scissorRect)
    {
        fScissorState.set(scissorRect);
        fHasStencilClip = false;
    }

    void enableStencilClip(bool enable) { fHasStencilClip = enable; }

    const GrScissorState& scissorState() const { return fScissorState; }
    bool hasStencilClip() const { return fHasStencilClip; }

    bool quickContains(const SkRect&) const final;
    void getConservativeBounds(int width, int height, SkIRect* devResult,
        bool* isIntersectionOfRects) const final;

private:
    bool apply(GrContext*, const GrPipelineBuilder&, GrDrawContext*,
        const SkRect* devBounds, GrAppliedClip* out) const final;

    GrScissorState fScissorState;
    bool fHasStencilClip;
};

/**
 * GrClipStackClip can apply a generic SkClipStack to the draw state. It may generate clip masks or
 * write to the stencil buffer during apply().
 */
class GrClipStackClip final : public GrClip {
public:
    GrClipStackClip(const SkClipStack* stack = nullptr, const SkIPoint* origin = nullptr)
    {
        this->reset(stack, origin);
    }

    void reset(const SkClipStack* stack = nullptr, const SkIPoint* origin = nullptr)
    {
        fOrigin = origin ? *origin : SkIPoint::Make(0, 0);
        fStack.reset(SkSafeRef(stack));
    }

    const SkIPoint& origin() const { return fOrigin; }
    const SkClipStack* clipStack() const { return fStack; }

    bool quickContains(const SkRect&) const final;
    void getConservativeBounds(int width, int height, SkIRect* devResult,
        bool* isIntersectionOfRects) const final;
    bool apply(GrContext*, const GrPipelineBuilder&, GrDrawContext*,
        const SkRect* devBounds, GrAppliedClip*) const final;

private:
    SkIPoint fOrigin;
    SkAutoTUnref<const SkClipStack> fStack;
=======
#include "SkClipStack.h"
#include "GrSurface.h"

struct SkIRect;

/**
 * GrClip encapsulates the information required to construct the clip
 * masks. 'A GrClip is either wide open, just an IRect, just a Rect, or a full clipstack.
 * If the clip is a clipstack than the origin is used to translate the stack with
 * respect to device coordinates. This allows us to use a clip stack that is
 * specified for a root device with a layer device that is restricted to a subset
 * of the original canvas. For other clip types the origin will always be (0,0).
 *
 * NOTE: GrClip *must* point to a const clipstack
 */
class GrClip : SkNoncopyable {
public:
    GrClip() : fClipType(kWideOpen_ClipType) {
        fOrigin.setZero();
    }

    GrClip(const SkIRect& rect) : fClipType(kIRect_ClipType) {
        fOrigin.setZero();
        fClip.fIRect = rect;
    }

    GrClip(const SkRect& rect) : fClipType(kIRect_ClipType) {
        fOrigin.setZero();
        fClip.fIRect.fLeft   = SkScalarRoundToInt(rect.fLeft);
        fClip.fIRect.fTop    = SkScalarRoundToInt(rect.fTop);
        fClip.fIRect.fRight  = SkScalarRoundToInt(rect.fRight);
        fClip.fIRect.fBottom = SkScalarRoundToInt(rect.fBottom);
    }

    ~GrClip() { this->reset(); }

    const GrClip& operator=(const GrClip& other) {
        this->reset();
        fClipType = other.fClipType;
        switch (other.fClipType) {
            case kWideOpen_ClipType:
                fOrigin.setZero();
                break;
            case kClipStack_ClipType:
                fClip.fStack = SkRef(other.clipStack());
                fOrigin = other.origin();
                break;
            case kIRect_ClipType:
                fClip.fIRect = other.irect();
                fOrigin.setZero();
                break;
        }
        return *this;
    }

    bool operator==(const GrClip& other) const {
        if (this->clipType() != other.clipType()) {
            return false;
        }

        switch (fClipType) {
            case kWideOpen_ClipType:
                return true;
            case kClipStack_ClipType:
                if (this->origin() != other.origin()) {
                    return false;
                }

                if (this->clipStack() && other.clipStack()) {
                    return *this->clipStack() == *other.clipStack();
                } else {
                    return this->clipStack() == other.clipStack();
                }
                break;
            case kIRect_ClipType:
                return this->irect() == other.irect();
                break;
        }
    }

    bool operator!=(const GrClip& other) const {
        return !(*this == other);
    }

    const SkClipStack* clipStack() const {
        SkASSERT(kClipStack_ClipType == fClipType);
        return fClip.fStack;
    }

    void setClipStack(const SkClipStack* clipStack, const SkIPoint* origin = NULL) {
        this->reset();
        if (clipStack->isWideOpen()) {
            fClipType = kWideOpen_ClipType;
            fOrigin.setZero();
        } else {
            fClipType = kClipStack_ClipType;
            fClip.fStack = SkRef(clipStack);
            if (origin) {
                fOrigin = *origin;
            } else {
                fOrigin.setZero();
            }
        }
    }

    const SkIRect& irect() const {
        SkASSERT(kIRect_ClipType == fClipType);
        return fClip.fIRect;
    }

    void reset() {
        if (kClipStack_ClipType == fClipType) {
            fClip.fStack->unref();
            fClip.fStack = NULL;
        }
        fClipType = kWideOpen_ClipType;
        fOrigin.setZero();
    }

    // We support this for all cliptypes to simplify the logic a bit in clip mask manager.
    // non clipstack clip types MUST have a (0,0) origin
    const SkIPoint& origin() const {
        SkASSERT(fClipType == kClipStack_ClipType || (fOrigin.fX == 0 && fOrigin.fY == 0));
        return fOrigin;
    }

    bool isWideOpen(const SkRect& rect) const {
        return (kWideOpen_ClipType == fClipType) ||
               (kClipStack_ClipType == fClipType && this->clipStack()->isWideOpen()) ||
               (kIRect_ClipType == fClipType && this->irect().contains(rect));
    }

    bool isWideOpen(const SkIRect& rect) const {
        return (kWideOpen_ClipType == fClipType) ||
               (kClipStack_ClipType == fClipType && this->clipStack()->isWideOpen()) ||
               (kIRect_ClipType == fClipType && this->irect().contains(rect));
    }

    bool isWideOpen() const {
        return (kWideOpen_ClipType == fClipType) ||
               (kClipStack_ClipType == fClipType && this->clipStack()->isWideOpen());
    }

    bool quickContains(const SkRect& rect) const {
        return (kWideOpen_ClipType == fClipType) ||
               (kClipStack_ClipType == fClipType && this->clipStack()->quickContains(rect)) ||
               (kIRect_ClipType == fClipType && this->irect().contains(rect));
    }

    void getConservativeBounds(const GrSurface* surface,
                               SkIRect* devResult,
                               bool* isIntersectionOfRects = NULL) const {
        this->getConservativeBounds(surface->width(), surface->height(),
                                    devResult, isIntersectionOfRects);
    }

    void getConservativeBounds(int width, int height,
                               SkIRect* devResult,
                               bool* isIntersectionOfRects = NULL) const;

    static const GrClip& WideOpen();

    enum ClipType {
        kClipStack_ClipType,
        kWideOpen_ClipType,
        kIRect_ClipType,
    };

    ClipType clipType() const { return fClipType; }

private:
    union Clip {
        const SkClipStack* fStack;
        SkIRect fIRect;
    } fClip;

    SkIPoint fOrigin;
    ClipType fClipType;
>>>>>>> miniblink49
};

#endif
