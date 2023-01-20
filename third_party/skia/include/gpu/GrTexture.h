
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrTexture_DEFINED
#define GrTexture_DEFINED

#include "GrSurface.h"
#include "SkPoint.h"
#include "SkRefCnt.h"

class GrTextureParams;
class GrTexturePriv;

class GrTexture : virtual public GrSurface {
public:
    GrTexture* asTexture() override { return this; }
    const GrTexture* asTexture() const override { return this; }
<<<<<<< HEAD
    GrSLType samplerType() const { return fSamplerType; }
=======
>>>>>>> miniblink49

    /**
     *  Return the native ID or handle to the texture, depending on the
     *  platform. e.g. on OpenGL, return the texture ID.
     */
    virtual GrBackendObject getTextureHandle() const = 0;

    /**
     * This function indicates that the texture parameters (wrap mode, filtering, ...) have been
     * changed externally to Skia.
     */
    virtual void textureParamsModified() = 0;

#ifdef SK_DEBUG
<<<<<<< HEAD
    void validate() const
    {
=======
    void validate() const {
>>>>>>> miniblink49
        this->INHERITED::validate();
        this->validateDesc();
    }
#endif

    /** Access methods that are only to be used within Skia code. */
    inline GrTexturePriv texturePriv();
    inline const GrTexturePriv texturePriv() const;

protected:
<<<<<<< HEAD
    GrTexture(GrGpu*, const GrSurfaceDesc&, GrSLType, bool wasMipMapDataProvided);
=======
    GrTexture(GrGpu*, LifeCycle, const GrSurfaceDesc&);
>>>>>>> miniblink49

    void validateDesc() const;

private:
<<<<<<< HEAD
    void computeScratchKey(GrScratchKey*) const override;
=======
>>>>>>> miniblink49
    size_t onGpuMemorySize() const override;
    void dirtyMipMaps(bool mipMapsDirty);

    enum MipMapsStatus {
        kNotAllocated_MipMapsStatus,
        kAllocated_MipMapsStatus,
        kValid_MipMapsStatus
    };

<<<<<<< HEAD
    GrSLType fSamplerType;
    MipMapsStatus fMipMapsStatus;
    int fMaxMipMapLevel;
    SkSourceGammaTreatment fGammaTreatment;
=======
    MipMapsStatus   fMipMapsStatus;
    // These two shift a fixed-point value into normalized coordinates	
    // for this texture if the texture is power of two sized.
    int             fShiftFixedX;
    int             fShiftFixedY;
>>>>>>> miniblink49

    friend class GrTexturePriv;

    typedef GrSurface INHERITED;
};

#endif
