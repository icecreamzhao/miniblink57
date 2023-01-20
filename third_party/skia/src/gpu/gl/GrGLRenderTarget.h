/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef GrGLRenderTarget_DEFINED
#define GrGLRenderTarget_DEFINED

#include "GrGLIRect.h"
#include "GrRenderTarget.h"
#include "SkScalar.h"

class GrGLGpu;
<<<<<<< HEAD
class GrGLStencilAttachment;
=======
>>>>>>> miniblink49

class GrGLRenderTarget : public GrRenderTarget {
public:
    // set fTexFBOID to this value to indicate that it is multisampled but
    // Gr doesn't know how to resolve it.
    enum { kUnresolvableFBOID = 0 };

    struct IDDesc {
<<<<<<< HEAD
        GrGLuint fRTFBOID;
        GrBackendObjectOwnership fRTFBOOwnership;
        GrGLuint fTexFBOID;
        GrGLuint fMSColorRenderbufferID;
        GrRenderTarget::SampleConfig fSampleConfig;
    };

    static GrGLRenderTarget* CreateWrapped(GrGLGpu*,
        const GrSurfaceDesc&,
        const IDDesc&,
        int stencilBits);
=======
        GrGLuint                     fRTFBOID;
        GrGLuint                     fTexFBOID;
        GrGLuint                     fMSColorRenderbufferID;
        GrGpuResource::LifeCycle     fLifeCycle;
        GrRenderTarget::SampleConfig fSampleConfig;
    };

    GrGLRenderTarget(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&);
>>>>>>> miniblink49

    void setViewport(const GrGLIRect& rect) { fViewport = rect; }
    const GrGLIRect& getViewport() const { return fViewport; }

    // The following two functions return the same ID when a
    // texture/render target is multisampled, and different IDs when
    // it is.
    // FBO ID used to render into
    GrGLuint renderFBOID() const { return fRTFBOID; }
    // FBO ID that has texture ID attached.
    GrGLuint textureFBOID() const { return fTexFBOID; }

    // override of GrRenderTarget
<<<<<<< HEAD
    ResolveType getResolveType() const override
    {
        if (!this->isUnifiedMultisampled() || fRTFBOID == fTexFBOID) {
=======
    ResolveType getResolveType() const override {
        if (!this->isUnifiedMultisampled() ||
            fRTFBOID == fTexFBOID) {
>>>>>>> miniblink49
            // catches FBO 0 and non MSAA case
            return kAutoResolves_ResolveType;
        } else if (kUnresolvableFBOID == fTexFBOID) {
            return kCantResolve_ResolveType;
        } else {
            return kCanResolve_ResolveType;
        }
    }

    GrBackendObject getRenderTargetHandle() const override { return fRTFBOID; }

<<<<<<< HEAD
    bool canAttemptStencilAttachment() const override;

    // GrGLRenderTarget overrides dumpMemoryStatistics so it can log its texture and renderbuffer
    // components seperately.
    void dumpMemoryStatistics(SkTraceMemoryDump* traceMemoryDump) const override;

protected:
    // Constructor for subclasses.
    GrGLRenderTarget(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&);
=======
    /** When we don't own the FBO ID we don't attempt to modify its attachments. */
    bool canAttemptStencilAttachment() const override {
        return kCached_LifeCycle == fRTLifecycle || kUncached_LifeCycle == fRTLifecycle;
    }

protected:
    // The public constructor registers this object with the cache. However, only the most derived
    // class should register with the cache. This constructor does not do the registration and
    // rather moves that burden onto the derived class.
    enum Derived { kDerived };
    GrGLRenderTarget(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&, Derived);
>>>>>>> miniblink49

    void init(const GrSurfaceDesc&, const IDDesc&);

    void onAbandon() override;
    void onRelease() override;

    // In protected because subclass GrGLTextureRenderTarget calls this version.
    size_t onGpuMemorySize() const override;

private:
<<<<<<< HEAD
    // Constructor for instances wrapping backend objects.
    GrGLRenderTarget(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&, GrGLStencilAttachment*);

    GrGLGpu* getGLGpu() const;
    bool completeStencilAttachment() override;

    // The total size of the resource (including all pixels) for a single sample.
    size_t totalBytesPerSample() const;
    int msaaSamples() const;
    // The number total number of samples, including both MSAA and resolve texture samples.
    int totalSamples() const;

    GrGLuint fRTFBOID;
    GrGLuint fTexFBOID;
    GrGLuint fMSColorRenderbufferID;

    GrBackendObjectOwnership fRTFBOOwnership;
=======
    GrGLuint    fRTFBOID;
    GrGLuint    fTexFBOID;
    GrGLuint    fMSColorRenderbufferID;

    // We track this separately from GrGpuResource because this may be both a texture and a render
    // target, and the texture may be wrapped while the render target is not.
    LifeCycle   fRTLifecycle;
>>>>>>> miniblink49

    // when we switch to this render target we want to set the viewport to
    // only render to content area (as opposed to the whole allocation) and
    // we want the rendering to be at top left (GL has origin in bottom left)
<<<<<<< HEAD
    GrGLIRect fViewport;

    // onGpuMemorySize() needs to know the VRAM footprint of the FBO(s). However, abandon and
    // release zero out the IDs and the cache needs to know the size even after those actions.
    size_t fGpuMemorySize;
=======
    GrGLIRect   fViewport;

    // onGpuMemorySize() needs to know the VRAM footprint of the FBO(s). However, abandon and
    // release zero out the IDs and the cache needs to know the size even after those actions.
    size_t      fGpuMemorySize;
>>>>>>> miniblink49

    typedef GrRenderTarget INHERITED;
};

#endif
