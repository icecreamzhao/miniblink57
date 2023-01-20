/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef GrGLContext_DEFINED
#define GrGLContext_DEFINED

#include "GrGLCaps.h"
#include "GrGLUtil.h"
#include "gl/GrGLExtensions.h"
#include "gl/GrGLInterface.h"
=======

#ifndef GrGLContext_DEFINED
#define GrGLContext_DEFINED

#include "gl/GrGLExtensions.h"
#include "gl/GrGLInterface.h"
#include "GrGLCaps.h"
#include "GrGLUtil.h"
>>>>>>> miniblink49

struct GrContextOptions;

/**
 * Encapsulates information about an OpenGL context including the OpenGL
 * version, the GrGLStandard type of the context, and GLSL version.
 */
class GrGLContextInfo : public SkRefCnt {
public:
    GrGLStandard standard() const { return fInterface->fStandard; }
    GrGLVersion version() const { return fGLVersion; }
    GrGLSLGeneration glslGeneration() const { return fGLSLGeneration; }
    GrGLVendor vendor() const { return fVendor; }
    GrGLRenderer renderer() const { return fRenderer; }
    /** What driver is running our GL implementation? This is not necessarily related to the vendor.
        (e.g. Intel GPU being driven by Mesa) */
    GrGLDriver driver() const { return fDriver; }
    GrGLDriverVersion driverVersion() const { return fDriverVersion; }
    const GrGLCaps* caps() const { return fGLCaps.get(); }
    GrGLCaps* caps() { return fGLCaps; }
<<<<<<< HEAD
    bool hasExtension(const char* ext) const
    {
=======
    bool hasExtension(const char* ext) const {
>>>>>>> miniblink49
        return fInterface->hasExtension(ext);
    }

    const GrGLExtensions& extensions() const { return fInterface->fExtensions; }

protected:
    struct ConstructorArgs {
<<<<<<< HEAD
        const GrGLInterface* fInterface;
        GrGLVersion fGLVersion;
        GrGLSLGeneration fGLSLGeneration;
        GrGLVendor fVendor;
        GrGLRenderer fRenderer;
        GrGLDriver fDriver;
        GrGLDriverVersion fDriverVersion;
        const GrContextOptions* fContextOptions;
=======
        const GrGLInterface*                fInterface;
        GrGLVersion                         fGLVersion;
        GrGLSLGeneration                    fGLSLGeneration;
        GrGLVendor                          fVendor;
        GrGLRenderer                        fRenderer;
        GrGLDriver                          fDriver;
        GrGLDriverVersion                   fDriverVersion;
        const  GrContextOptions*            fContextOptions;
>>>>>>> miniblink49
    };

    GrGLContextInfo(const ConstructorArgs& args);

<<<<<<< HEAD
    SkAutoTUnref<const GrGLInterface> fInterface;
    GrGLVersion fGLVersion;
    GrGLSLGeneration fGLSLGeneration;
    GrGLVendor fVendor;
    GrGLRenderer fRenderer;
    GrGLDriver fDriver;
    GrGLDriverVersion fDriverVersion;
    SkAutoTUnref<GrGLCaps> fGLCaps;
=======
    SkAutoTUnref<const GrGLInterface>   fInterface;
    GrGLVersion                         fGLVersion;
    GrGLSLGeneration                    fGLSLGeneration;
    GrGLVendor                          fVendor;
    GrGLRenderer                        fRenderer;
    GrGLDriver                          fDriver;
    GrGLDriverVersion                   fDriverVersion;
    SkAutoTUnref<GrGLCaps>              fGLCaps;
>>>>>>> miniblink49
};

/**
 * Extension of GrGLContextInfo that also provides access to GrGLInterface.
 */
class GrGLContext : public GrGLContextInfo {
public:
    /**
     * Creates a GrGLContext from a GrGLInterface and the currently
     * bound OpenGL context accessible by the GrGLInterface.
     */
    static GrGLContext* Create(const GrGLInterface* interface, const GrContextOptions& options);

    const GrGLInterface* interface() const { return fInterface; }

private:
<<<<<<< HEAD
    GrGLContext(const ConstructorArgs& args)
        : INHERITED(args)
    {
    }
=======
    GrGLContext(const ConstructorArgs& args) : INHERITED(args) {}
>>>>>>> miniblink49

    typedef GrGLContextInfo INHERITED;
};

#endif
