/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef GrGLTexture_DEFINED
#define GrGLTexture_DEFINED

#include "GrGLUtil.h"
#include "GrGpu.h"
#include "GrTexture.h"
=======

#ifndef GrGLTexture_DEFINED
#define GrGLTexture_DEFINED

#include "GrGpu.h"
#include "GrTexture.h"
#include "GrGLUtil.h"
>>>>>>> miniblink49

class GrGLGpu;

class GrGLTexture : public GrTexture {
<<<<<<< HEAD
=======

>>>>>>> miniblink49
public:
    struct TexParams {
        GrGLenum fMinFilter;
        GrGLenum fMagFilter;
        GrGLenum fWrapS;
        GrGLenum fWrapT;
<<<<<<< HEAD
        GrGLenum fMaxMipMapLevel;
        GrGLenum fSwizzleRGBA[4];
        GrGLenum fSRGBDecode;
=======
        GrGLenum fSwizzleRGBA[4];
>>>>>>> miniblink49
        void invalidate() { memset(this, 0xff, sizeof(TexParams)); }
    };

    struct IDDesc {
<<<<<<< HEAD
        GrGLTextureInfo fInfo;
        GrBackendObjectOwnership fOwnership;
    };
    GrGLTexture(GrGLGpu*, SkBudgeted, const GrSurfaceDesc&, const IDDesc&);
    GrGLTexture(GrGLGpu*, SkBudgeted, const GrSurfaceDesc&, const IDDesc&,
        bool wasMipMapDataProvided);
=======
        GrGLuint                    fTextureID;
        GrGpuResource::LifeCycle    fLifeCycle;
    };

    GrGLTexture(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&);
>>>>>>> miniblink49

    GrBackendObject getTextureHandle() const override;

    void textureParamsModified() override { fTexParams.invalidate(); }

    // These functions are used to track the texture parameters associated with the texture.
<<<<<<< HEAD
    const TexParams& getCachedTexParams(GrGpu::ResetTimestamp* timestamp) const
    {
=======
    const TexParams& getCachedTexParams(GrGpu::ResetTimestamp* timestamp) const {
>>>>>>> miniblink49
        *timestamp = fTexParamsTimestamp;
        return fTexParams;
    }

    void setCachedTexParams(const TexParams& texParams,
<<<<<<< HEAD
        GrGpu::ResetTimestamp timestamp)
    {
=======
                            GrGpu::ResetTimestamp timestamp) {
>>>>>>> miniblink49
        fTexParams = texParams;
        fTexParamsTimestamp = timestamp;
    }

<<<<<<< HEAD
    GrGLuint textureID() const { return fInfo.fID; }

    GrGLenum target() const { return fInfo.fTarget; }

    static GrGLTexture* CreateWrapped(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&);

protected:
    // Constructor for subclasses.
    GrGLTexture(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&);

    enum Wrapped { kWrapped };
    // Constructor for instances wrapping backend objects.
    GrGLTexture(GrGLGpu*, Wrapped, const GrSurfaceDesc&, const IDDesc&);
=======
    GrGLuint textureID() const { return fTextureID; }

protected:
    // The public constructor registers this object with the cache. However, only the most derived
    // class should register with the cache. This constructor does not do the registration and
    // rather moves that burden onto the derived class.
    enum Derived { kDerived };
    GrGLTexture(GrGLGpu*, const GrSurfaceDesc&, const IDDesc&, Derived);
>>>>>>> miniblink49

    void init(const GrSurfaceDesc&, const IDDesc&);

    void onAbandon() override;
    void onRelease() override;
<<<<<<< HEAD
    void setMemoryBacking(SkTraceMemoryDump* traceMemoryDump,
        const SkString& dumpName) const override;

private:
    TexParams fTexParams;
    GrGpu::ResetTimestamp fTexParamsTimestamp;
    // Holds the texture target and ID. A pointer to this may be shared to external clients for
    // direct interaction with the GL object.
    GrGLTextureInfo fInfo;
    GrBackendObjectOwnership fTextureIDOwnership;
=======

private:
    TexParams                       fTexParams;
    GrGpu::ResetTimestamp           fTexParamsTimestamp;
    GrGLuint                        fTextureID;

    // We track this separately from GrGpuResource because this may be both a texture and a render
    // target, and the texture may be wrapped while the render target is not.
    LifeCycle                       fTextureIDLifecycle;
>>>>>>> miniblink49

    typedef GrTexture INHERITED;
};

#endif
