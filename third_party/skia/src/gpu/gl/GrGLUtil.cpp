/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "GrGLUtil.h"
#include "SkMatrix.h"
#include <stdio.h>

<<<<<<< HEAD
void GrGLClearErr(const GrGLInterface* gl)
{
    while (GR_GL_NO_ERROR != gl->fFunctions.fGetError()) { }
}

namespace {
const char* get_error_string(uint32_t err)
{
=======
void GrGLClearErr(const GrGLInterface* gl) {
    while (GR_GL_NO_ERROR != gl->fFunctions.fGetError()) {}
}

namespace {
const char *get_error_string(uint32_t err) {
>>>>>>> miniblink49
    switch (err) {
    case GR_GL_NO_ERROR:
        return "";
    case GR_GL_INVALID_ENUM:
        return "Invalid Enum";
    case GR_GL_INVALID_VALUE:
        return "Invalid Value";
    case GR_GL_INVALID_OPERATION:
        return "Invalid Operation";
    case GR_GL_OUT_OF_MEMORY:
        return "Out of Memory";
    case GR_GL_CONTEXT_LOST:
        return "Context Lost";
    }
    return "Unknown";
}
}

void GrGLCheckErr(const GrGLInterface* gl,
<<<<<<< HEAD
    const char* location,
    const char* call)
{
=======
                  const char* location,
                  const char* call) {
>>>>>>> miniblink49
    uint32_t err = GR_GL_GET_ERROR(gl);
    if (GR_GL_NO_ERROR != err) {
        SkDebugf("---- glGetError 0x%x(%s)", err, get_error_string(err));
        if (location) {
            SkDebugf(" at\n\t%s", location);
        }
        if (call) {
            SkDebugf("\n\t\t%s", call);
        }
        SkDebugf("\n");
    }
}

///////////////////////////////////////////////////////////////////////////////

#if GR_GL_LOG_CALLS
<<<<<<< HEAD
bool gLogCallsGL = !!(GR_GL_LOG_CALLS_START);
#endif

#if GR_GL_CHECK_ERROR
bool gCheckErrorGL = !!(GR_GL_CHECK_ERROR_START);
=======
    bool gLogCallsGL = !!(GR_GL_LOG_CALLS_START);
#endif

#if GR_GL_CHECK_ERROR
    bool gCheckErrorGL = !!(GR_GL_CHECK_ERROR_START);
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrGLStandard GrGLGetStandardInUseFromString(const char* versionString)
{
    if (nullptr == versionString) {
        SkDebugf("nullptr GL version string.");
=======
GrGLStandard GrGLGetStandardInUseFromString(const char* versionString) {
    if (NULL == versionString) {
        SkDebugf("NULL GL version string.");
>>>>>>> miniblink49
        return kNone_GrGLStandard;
    }

    int major, minor;

    // check for desktop
    int n = sscanf(versionString, "%d.%d", &major, &minor);
    if (2 == n) {
        return kGL_GrGLStandard;
    }

    // check for ES 1
    char profile[2];
<<<<<<< HEAD
    n = sscanf(versionString, "OpenGL ES-%c%c %d.%d", profile, profile + 1, &major, &minor);
=======
    n = sscanf(versionString, "OpenGL ES-%c%c %d.%d", profile, profile+1, &major, &minor);
>>>>>>> miniblink49
    if (4 == n) {
        // we no longer support ES1.
        return kNone_GrGLStandard;
    }

    // check for ES2
    n = sscanf(versionString, "OpenGL ES %d.%d", &major, &minor);
    if (2 == n) {
        return kGLES_GrGLStandard;
    }
    return kNone_GrGLStandard;
}

void GrGLGetDriverInfo(GrGLStandard standard,
<<<<<<< HEAD
    GrGLVendor vendor,
    const char* rendererString,
    const char* versionString,
    GrGLDriver* outDriver,
    GrGLDriverVersion* outVersion)
{
=======
                       GrGLVendor vendor,
                       const char* rendererString,
                       const char* versionString,
                       GrGLDriver* outDriver,
                       GrGLDriverVersion* outVersion) {
>>>>>>> miniblink49
    int major, minor, rev, driverMajor, driverMinor;

    *outDriver = kUnknown_GrGLDriver;
    *outVersion = GR_GL_DRIVER_UNKNOWN_VER;
<<<<<<< HEAD
    // These null checks are for test GL contexts that return nullptr in their
    // glGetString implementation.
    if (!rendererString) {
        rendererString = "";
    }
    if (!versionString) {
        versionString = "";
    }
=======
>>>>>>> miniblink49

    if (0 == strcmp(rendererString, "Chromium")) {
        *outDriver = kChromium_GrGLDriver;
        return;
    }

    if (standard == kGL_GrGLStandard) {
        if (kNVIDIA_GrGLVendor == vendor) {
            *outDriver = kNVIDIA_GrGLDriver;
            int n = sscanf(versionString, "%d.%d.%d NVIDIA %d.%d",
<<<<<<< HEAD
                &major, &minor, &rev, &driverMajor, &driverMinor);
=======
                           &major, &minor, &rev, &driverMajor, &driverMinor);
>>>>>>> miniblink49
            // Some older NVIDIA drivers don't report the driver version.
            if (5 == n) {
                *outVersion = GR_GL_DRIVER_VER(driverMajor, driverMinor);
            }
            return;
        }
<<<<<<< HEAD
        int n = sscanf(versionString, "%d.%d Mesa %d.%d",
            &major, &minor, &driverMajor, &driverMinor);
=======

        int n = sscanf(versionString, "%d.%d Mesa %d.%d",
                       &major, &minor, &driverMajor, &driverMinor);
>>>>>>> miniblink49
        if (4 == n) {
            *outDriver = kMesa_GrGLDriver;
            *outVersion = GR_GL_DRIVER_VER(driverMajor, driverMinor);
            return;
        }
<<<<<<< HEAD
    } else {
        if (kNVIDIA_GrGLVendor == vendor) {
            *outDriver = kNVIDIA_GrGLDriver;
            int n = sscanf(versionString, "OpenGL ES %d.%d NVIDIA %d.%d",
                &major, &minor, &driverMajor, &driverMinor);
=======
    }
    else {
        if (kNVIDIA_GrGLVendor == vendor) {
            *outDriver = kNVIDIA_GrGLDriver;
            int n = sscanf(versionString, "OpenGL ES %d.%d NVIDIA %d.%d",
                           &major, &minor, &driverMajor, &driverMinor);
>>>>>>> miniblink49
            // Some older NVIDIA drivers don't report the driver version.
            if (4 == n) {
                *outVersion = GR_GL_DRIVER_VER(driverMajor, driverMinor);
            }
            return;
        }

        int n = sscanf(versionString, "OpenGL ES %d.%d Mesa %d.%d",
<<<<<<< HEAD
            &major, &minor, &driverMajor, &driverMinor);
=======
                       &major, &minor, &driverMajor, &driverMinor);
>>>>>>> miniblink49
        if (4 == n) {
            *outDriver = kMesa_GrGLDriver;
            *outVersion = GR_GL_DRIVER_VER(driverMajor, driverMinor);
            return;
        }
<<<<<<< HEAD
        if (0 == strncmp("ANGLE", rendererString, 5)) {
            *outDriver = kANGLE_GrGLDriver;
            n = sscanf(versionString, "OpenGL ES %d.%d (ANGLE %d.%d", &major, &minor, &driverMajor,
                &driverMinor);
            if (4 == n) {
                *outVersion = GR_GL_DRIVER_VER(driverMajor, driverMinor);
            }
            return;
        }
=======
>>>>>>> miniblink49
    }

    if (kIntel_GrGLVendor == vendor) {
        // We presume we're on the Intel driver since it hasn't identified itself as Mesa.
        *outDriver = kIntel_GrGLDriver;
    }
}

<<<<<<< HEAD
GrGLVersion GrGLGetVersionFromString(const char* versionString)
{
    if (nullptr == versionString) {
        SkDebugf("nullptr GL version string.");
=======
GrGLVersion GrGLGetVersionFromString(const char* versionString) {
    if (NULL == versionString) {
        SkDebugf("NULL GL version string.");
>>>>>>> miniblink49
        return GR_GL_INVALID_VER;
    }

    int major, minor;

    // check for mesa
    int mesaMajor, mesaMinor;
    int n = sscanf(versionString, "%d.%d Mesa %d.%d", &major, &minor, &mesaMajor, &mesaMinor);
    if (4 == n) {
        return GR_GL_VER(major, minor);
    }

    n = sscanf(versionString, "%d.%d", &major, &minor);
    if (2 == n) {
        return GR_GL_VER(major, minor);
    }

    char profile[2];
<<<<<<< HEAD
    n = sscanf(versionString, "OpenGL ES-%c%c %d.%d", profile, profile + 1,
        &major, &minor);
=======
    n = sscanf(versionString, "OpenGL ES-%c%c %d.%d", profile, profile+1,
               &major, &minor);
>>>>>>> miniblink49
    if (4 == n) {
        return GR_GL_VER(major, minor);
    }

    n = sscanf(versionString, "OpenGL ES %d.%d", &major, &minor);
    if (2 == n) {
        return GR_GL_VER(major, minor);
    }

    return GR_GL_INVALID_VER;
}

<<<<<<< HEAD
GrGLSLVersion GrGLGetGLSLVersionFromString(const char* versionString)
{
    if (nullptr == versionString) {
        SkDebugf("nullptr GLSL version string.");
=======
GrGLSLVersion GrGLGetGLSLVersionFromString(const char* versionString) {
    if (NULL == versionString) {
        SkDebugf("NULL GLSL version string.");
>>>>>>> miniblink49
        return GR_GLSL_INVALID_VER;
    }

    int major, minor;

    int n = sscanf(versionString, "%d.%d", &major, &minor);
    if (2 == n) {
        return GR_GLSL_VER(major, minor);
    }

    n = sscanf(versionString, "OpenGL ES GLSL ES %d.%d", &major, &minor);
    if (2 == n) {
        return GR_GLSL_VER(major, minor);
    }

#ifdef SK_BUILD_FOR_ANDROID
    // android hack until the gpu vender updates their drivers
    n = sscanf(versionString, "OpenGL ES GLSL %d.%d", &major, &minor);
    if (2 == n) {
        return GR_GLSL_VER(major, minor);
    }
#endif

    return GR_GLSL_INVALID_VER;
}

<<<<<<< HEAD
GrGLVendor GrGLGetVendorFromString(const char* vendorString)
{
=======
GrGLVendor GrGLGetVendorFromString(const char* vendorString) {
>>>>>>> miniblink49
    if (vendorString) {
        if (0 == strcmp(vendorString, "ARM")) {
            return kARM_GrGLVendor;
        }
        if (0 == strcmp(vendorString, "Imagination Technologies")) {
            return kImagination_GrGLVendor;
        }
        if (0 == strncmp(vendorString, "Intel ", 6) || 0 == strcmp(vendorString, "Intel")) {
            return kIntel_GrGLVendor;
        }
        if (0 == strcmp(vendorString, "Qualcomm")) {
            return kQualcomm_GrGLVendor;
        }
        if (0 == strcmp(vendorString, "NVIDIA Corporation")) {
            return kNVIDIA_GrGLVendor;
        }
<<<<<<< HEAD
        if (0 == strcmp(vendorString, "ATI Technologies Inc.")) {
            return kATI_GrGLVendor;
        }
=======
>>>>>>> miniblink49
    }
    return kOther_GrGLVendor;
}

<<<<<<< HEAD
GrGLRenderer GrGLGetRendererFromString(const char* rendererString)
{
=======
GrGLRenderer GrGLGetRendererFromString(const char* rendererString) {
>>>>>>> miniblink49
    if (rendererString) {
        if (0 == strcmp(rendererString, "NVIDIA Tegra 3")) {
            return kTegra3_GrGLRenderer;
        } else if (0 == strcmp(rendererString, "NVIDIA Tegra")) {
            return kTegra2_GrGLRenderer;
        }
        int lastDigit;
        int n = sscanf(rendererString, "PowerVR SGX 54%d", &lastDigit);
        if (1 == n && lastDigit >= 0 && lastDigit <= 9) {
            return kPowerVR54x_GrGLRenderer;
        }
<<<<<<< HEAD
        // certain iOS devices also use PowerVR54x GPUs
        static const char kAppleA4Str[] = "Apple A4";
        static const char kAppleA5Str[] = "Apple A5";
        static const char kAppleA6Str[] = "Apple A6";
        if (0 == strncmp(rendererString, kAppleA4Str, SK_ARRAY_COUNT(kAppleA4Str) - 1) || 0 == strncmp(rendererString, kAppleA5Str, SK_ARRAY_COUNT(kAppleA5Str) - 1) || 0 == strncmp(rendererString, kAppleA6Str, SK_ARRAY_COUNT(kAppleA6Str) - 1)) {
            return kPowerVR54x_GrGLRenderer;
        }
        static const char kPowerVRRogueStr[] = "PowerVR Rogue";
        static const char kAppleA7Str[] = "Apple A7";
        static const char kAppleA8Str[] = "Apple A8";
        if (0 == strncmp(rendererString, kPowerVRRogueStr, SK_ARRAY_COUNT(kPowerVRRogueStr) - 1) || 0 == strncmp(rendererString, kAppleA7Str, SK_ARRAY_COUNT(kAppleA7Str) - 1) || 0 == strncmp(rendererString, kAppleA8Str, SK_ARRAY_COUNT(kAppleA8Str) - 1)) {
=======
        static const char kPowerVRRogueStr[] = "PowerVR Rogue";
        if (0 == strncmp(rendererString, kPowerVRRogueStr,
                         SK_ARRAY_COUNT(kPowerVRRogueStr)-1)) {
>>>>>>> miniblink49
            return kPowerVRRogue_GrGLRenderer;
        }
        int adrenoNumber;
        n = sscanf(rendererString, "Adreno (TM) %d", &adrenoNumber);
        if (1 == n) {
            if (adrenoNumber >= 300) {
                if (adrenoNumber < 400) {
                    return kAdreno3xx_GrGLRenderer;
                }
                if (adrenoNumber < 500) {
                    return kAdreno4xx_GrGLRenderer;
                }
            }
        }
<<<<<<< HEAD
        if (strcmp("Mesa Offscreen", rendererString)) {
            return kOSMesa_GrGLRenderer;
        }
=======
>>>>>>> miniblink49
    }
    return kOther_GrGLRenderer;
}

<<<<<<< HEAD
GrGLVersion GrGLGetVersion(const GrGLInterface* gl)
{
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_VERSION));
    return GrGLGetVersionFromString((const char*)v);
}

GrGLSLVersion GrGLGetGLSLVersion(const GrGLInterface* gl)
{
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_SHADING_LANGUAGE_VERSION));
    return GrGLGetGLSLVersionFromString((const char*)v);
}

GrGLVendor GrGLGetVendor(const GrGLInterface* gl)
{
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_VENDOR));
    return GrGLGetVendorFromString((const char*)v);
}

GrGLRenderer GrGLGetRenderer(const GrGLInterface* gl)
{
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_RENDERER));
    return GrGLGetRendererFromString((const char*)v);
}

GrGLenum GrToGLStencilFunc(GrStencilTest test)
{
    static const GrGLenum gTable[kGrStencilTestCount] = {
        GR_GL_ALWAYS, // kAlways
        GR_GL_NEVER, // kNever
        GR_GL_GREATER, // kGreater
        GR_GL_GEQUAL, // kGEqual
        GR_GL_LESS, // kLess
        GR_GL_LEQUAL, // kLEqual
        GR_GL_EQUAL, // kEqual
        GR_GL_NOTEQUAL, // kNotEqual
    };
    GR_STATIC_ASSERT(0 == (int)GrStencilTest::kAlways);
    GR_STATIC_ASSERT(1 == (int)GrStencilTest::kNever);
    GR_STATIC_ASSERT(2 == (int)GrStencilTest::kGreater);
    GR_STATIC_ASSERT(3 == (int)GrStencilTest::kGEqual);
    GR_STATIC_ASSERT(4 == (int)GrStencilTest::kLess);
    GR_STATIC_ASSERT(5 == (int)GrStencilTest::kLEqual);
    GR_STATIC_ASSERT(6 == (int)GrStencilTest::kEqual);
    GR_STATIC_ASSERT(7 == (int)GrStencilTest::kNotEqual);
    SkASSERT(test < (GrStencilTest)kGrStencilTestCount);

    return gTable[(int)test];
=======
GrGLVersion GrGLGetVersion(const GrGLInterface* gl) {
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_VERSION));
    return GrGLGetVersionFromString((const char*) v);
}

GrGLSLVersion GrGLGetGLSLVersion(const GrGLInterface* gl) {
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_SHADING_LANGUAGE_VERSION));
    return GrGLGetGLSLVersionFromString((const char*) v);
}

GrGLVendor GrGLGetVendor(const GrGLInterface* gl) {
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_VENDOR));
    return GrGLGetVendorFromString((const char*) v);
}

GrGLRenderer GrGLGetRenderer(const GrGLInterface* gl) {
    const GrGLubyte* v;
    GR_GL_CALL_RET(gl, v, GetString(GR_GL_RENDERER));
    return GrGLGetRendererFromString((const char*) v);
}

template<> void GrGLGetMatrix<3>(GrGLfloat* dest, const SkMatrix& src) {
    // Col 0
    dest[0] = SkScalarToFloat(src[SkMatrix::kMScaleX]);
    dest[1] = SkScalarToFloat(src[SkMatrix::kMSkewY]);
    dest[2] = SkScalarToFloat(src[SkMatrix::kMPersp0]);

    // Col 1
    dest[3] = SkScalarToFloat(src[SkMatrix::kMSkewX]);
    dest[4] = SkScalarToFloat(src[SkMatrix::kMScaleY]);
    dest[5] = SkScalarToFloat(src[SkMatrix::kMPersp1]);

    // Col 2
    dest[6] = SkScalarToFloat(src[SkMatrix::kMTransX]);
    dest[7] = SkScalarToFloat(src[SkMatrix::kMTransY]);
    dest[8] = SkScalarToFloat(src[SkMatrix::kMPersp2]);
}

template<> void GrGLGetMatrix<4>(GrGLfloat* dest, const SkMatrix& src) {
    // Col 0
    dest[0]  = SkScalarToFloat(src[SkMatrix::kMScaleX]);
    dest[1]  = SkScalarToFloat(src[SkMatrix::kMSkewY]);
    dest[2]  = 0;
    dest[3]  = SkScalarToFloat(src[SkMatrix::kMPersp0]);

    // Col 1
    dest[4]  = SkScalarToFloat(src[SkMatrix::kMSkewX]);
    dest[5]  = SkScalarToFloat(src[SkMatrix::kMScaleY]);
    dest[6]  = 0;
    dest[7]  = SkScalarToFloat(src[SkMatrix::kMPersp1]);

    // Col 2
    dest[8]  = 0;
    dest[9]  = 0;
    dest[10] = 1;
    dest[11] = 0;

    // Col 3
    dest[12] = SkScalarToFloat(src[SkMatrix::kMTransX]);
    dest[13] = SkScalarToFloat(src[SkMatrix::kMTransY]);
    dest[14] = 0;
    dest[15] = SkScalarToFloat(src[SkMatrix::kMPersp2]);
}

GrGLenum GrToGLStencilFunc(GrStencilFunc basicFunc) {
    static const GrGLenum gTable[] = {
        GR_GL_ALWAYS,           // kAlways_StencilFunc
        GR_GL_NEVER,            // kNever_StencilFunc
        GR_GL_GREATER,          // kGreater_StencilFunc
        GR_GL_GEQUAL,           // kGEqual_StencilFunc
        GR_GL_LESS,             // kLess_StencilFunc
        GR_GL_LEQUAL,           // kLEqual_StencilFunc,
        GR_GL_EQUAL,            // kEqual_StencilFunc,
        GR_GL_NOTEQUAL,         // kNotEqual_StencilFunc,
    };
    GR_STATIC_ASSERT(SK_ARRAY_COUNT(gTable) == kBasicStencilFuncCount);
    GR_STATIC_ASSERT(0 == kAlways_StencilFunc);
    GR_STATIC_ASSERT(1 == kNever_StencilFunc);
    GR_STATIC_ASSERT(2 == kGreater_StencilFunc);
    GR_STATIC_ASSERT(3 == kGEqual_StencilFunc);
    GR_STATIC_ASSERT(4 == kLess_StencilFunc);
    GR_STATIC_ASSERT(5 == kLEqual_StencilFunc);
    GR_STATIC_ASSERT(6 == kEqual_StencilFunc);
    GR_STATIC_ASSERT(7 == kNotEqual_StencilFunc);
    SkASSERT((unsigned) basicFunc < kBasicStencilFuncCount);

    return gTable[basicFunc];
>>>>>>> miniblink49
}
