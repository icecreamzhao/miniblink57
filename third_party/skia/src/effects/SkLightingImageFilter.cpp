/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkLightingImageFilter.h"
#include "SkBitmap.h"
#include "SkColorPriv.h"
<<<<<<< HEAD
#include "SkPoint3.h"
#include "SkReadBuffer.h"
#include "SkSpecialImage.h"
#include "SkTypes.h"
#include "SkWriteBuffer.h"
=======
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkTypes.h"
>>>>>>> miniblink49

#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrDrawContext.h"
#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
#include "GrPaint.h"
<<<<<<< HEAD
#include "SkGr.h"
#include "effects/GrSingleTextureEffect.h"
#include "effects/GrTextureDomain.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
=======
#include "effects/GrSingleTextureEffect.h"
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49

class GrGLDiffuseLightingEffect;
class GrGLSpecularLightingEffect;

// For brevity
<<<<<<< HEAD
typedef GrGLSLProgramDataManager::UniformHandle UniformHandle;
=======
typedef GrGLProgramDataManager::UniformHandle UniformHandle;
>>>>>>> miniblink49
#endif

namespace {

const SkScalar gOneThird = SkIntToScalar(1) / 3;
const SkScalar gTwoThirds = SkIntToScalar(2) / 3;
const SkScalar gOneHalf = 0.5f;
const SkScalar gOneQuarter = 0.25f;

#if SK_SUPPORT_GPU
<<<<<<< HEAD
void setUniformPoint3(const GrGLSLProgramDataManager& pdman, UniformHandle uni,
    const SkPoint3& point)
{
    GR_STATIC_ASSERT(sizeof(SkPoint3) == 3 * sizeof(float));
    pdman.set3fv(uni, 1, &point.fX);
}

void setUniformNormal3(const GrGLSLProgramDataManager& pdman, UniformHandle uni,
    const SkPoint3& point)
{
    setUniformPoint3(pdman, uni, point);
=======
void setUniformPoint3(const GrGLProgramDataManager& pdman, UniformHandle uni,
                      const SkPoint3& point) {
    GR_STATIC_ASSERT(sizeof(SkPoint3) == 3 * sizeof(GrGLfloat));
    pdman.set3fv(uni, 1, &point.fX);
}

void setUniformNormal3(const GrGLProgramDataManager& pdman, UniformHandle uni,
                       const SkPoint3& point) {
    setUniformPoint3(pdman, uni, SkPoint3(point.fX, point.fY, point.fZ));
>>>>>>> miniblink49
}
#endif

// Shift matrix components to the left, as we advance pixels to the right.
<<<<<<< HEAD
inline void shiftMatrixLeft(int m[9])
{
=======
inline void shiftMatrixLeft(int m[9]) {
>>>>>>> miniblink49
    m[0] = m[1];
    m[3] = m[4];
    m[6] = m[7];
    m[1] = m[2];
    m[4] = m[5];
    m[7] = m[8];
}

<<<<<<< HEAD
static inline void fast_normalize(SkPoint3* vector)
{
    // add a tiny bit so we don't have to worry about divide-by-zero
    SkScalar magSq = vector->dot(*vector) + SK_ScalarNearlyZero;
    SkScalar scale = sk_float_rsqrt(magSq);
    vector->fX *= scale;
    vector->fY *= scale;
    vector->fZ *= scale;
}

class DiffuseLightingType {
public:
    DiffuseLightingType(SkScalar kd)
        : fKD(kd)
    {
    }
    SkPMColor light(const SkPoint3& normal, const SkPoint3& surfaceTolight,
        const SkPoint3& lightColor) const
    {
        SkScalar colorScale = SkScalarMul(fKD, normal.dot(surfaceTolight));
        colorScale = SkScalarClampMax(colorScale, SK_Scalar1);
        SkPoint3 color = lightColor.makeScale(colorScale);
        return SkPackARGB32(255,
            SkClampMax(SkScalarRoundToInt(color.fX), 255),
            SkClampMax(SkScalarRoundToInt(color.fY), 255),
            SkClampMax(SkScalarRoundToInt(color.fZ), 255));
    }

=======
class DiffuseLightingType {
public:
    DiffuseLightingType(SkScalar kd)
        : fKD(kd) {}
    SkPMColor light(const SkPoint3& normal, const SkPoint3& surfaceTolight,
                    const SkPoint3& lightColor) const {
        SkScalar colorScale = SkScalarMul(fKD, normal.dot(surfaceTolight));
        colorScale = SkScalarClampMax(colorScale, SK_Scalar1);
        SkPoint3 color(lightColor * colorScale);
        return SkPackARGB32(255,
                            SkClampMax(SkScalarRoundToInt(color.fX), 255),
                            SkClampMax(SkScalarRoundToInt(color.fY), 255),
                            SkClampMax(SkScalarRoundToInt(color.fZ), 255));
    }
>>>>>>> miniblink49
private:
    SkScalar fKD;
};

<<<<<<< HEAD
static SkScalar max_component(const SkPoint3& p)
{
    return p.x() > p.y() ? (p.x() > p.z() ? p.x() : p.z()) : (p.y() > p.z() ? p.y() : p.z());
}

class SpecularLightingType {
public:
    SpecularLightingType(SkScalar ks, SkScalar shininess)
        : fKS(ks)
        , fShininess(shininess)
    {
    }
    SkPMColor light(const SkPoint3& normal, const SkPoint3& surfaceTolight,
        const SkPoint3& lightColor) const
    {
        SkPoint3 halfDir(surfaceTolight);
        halfDir.fZ += SK_Scalar1; // eye position is always (0, 0, 1)
        fast_normalize(&halfDir);
        SkScalar colorScale = SkScalarMul(fKS,
            SkScalarPow(normal.dot(halfDir), fShininess));
        colorScale = SkScalarClampMax(colorScale, SK_Scalar1);
        SkPoint3 color = lightColor.makeScale(colorScale);
        return SkPackARGB32(SkClampMax(SkScalarRoundToInt(max_component(color)), 255),
            SkClampMax(SkScalarRoundToInt(color.fX), 255),
            SkClampMax(SkScalarRoundToInt(color.fY), 255),
            SkClampMax(SkScalarRoundToInt(color.fZ), 255));
    }

=======
class SpecularLightingType {
public:
    SpecularLightingType(SkScalar ks, SkScalar shininess)
        : fKS(ks), fShininess(shininess) {}
    SkPMColor light(const SkPoint3& normal, const SkPoint3& surfaceTolight,
                    const SkPoint3& lightColor) const {
        SkPoint3 halfDir(surfaceTolight);
        halfDir.fZ += SK_Scalar1;        // eye position is always (0, 0, 1)
        halfDir.normalize();
        SkScalar colorScale = SkScalarMul(fKS,
            SkScalarPow(normal.dot(halfDir), fShininess));
        colorScale = SkScalarClampMax(colorScale, SK_Scalar1);
        SkPoint3 color(lightColor * colorScale);
        return SkPackARGB32(SkClampMax(SkScalarRoundToInt(color.maxComponent()), 255),
                            SkClampMax(SkScalarRoundToInt(color.fX), 255),
                            SkClampMax(SkScalarRoundToInt(color.fY), 255),
                            SkClampMax(SkScalarRoundToInt(color.fZ), 255));
    }
>>>>>>> miniblink49
private:
    SkScalar fKS;
    SkScalar fShininess;
};

<<<<<<< HEAD
inline SkScalar sobel(int a, int b, int c, int d, int e, int f, SkScalar scale)
{
    return SkScalarMul(SkIntToScalar(-a + b - 2 * c + 2 * d - e + f), scale);
}

inline SkPoint3 pointToNormal(SkScalar x, SkScalar y, SkScalar surfaceScale)
{
    SkPoint3 vector = SkPoint3::Make(SkScalarMul(-x, surfaceScale),
        SkScalarMul(-y, surfaceScale),
        SK_Scalar1);
    fast_normalize(&vector);
    return vector;
}

inline SkPoint3 topLeftNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(0, 0, m[4], m[5], m[7], m[8], gTwoThirds),
        sobel(0, 0, m[4], m[7], m[5], m[8], gTwoThirds),
        surfaceScale);
}

inline SkPoint3 topNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(0, 0, m[3], m[5], m[6], m[8], gOneThird),
        sobel(m[3], m[6], m[4], m[7], m[5], m[8], gOneHalf),
        surfaceScale);
}

inline SkPoint3 topRightNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(0, 0, m[3], m[4], m[6], m[7], gTwoThirds),
        sobel(m[3], m[6], m[4], m[7], 0, 0, gTwoThirds),
        surfaceScale);
}

inline SkPoint3 leftNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(m[1], m[2], m[4], m[5], m[7], m[8], gOneHalf),
        sobel(0, 0, m[1], m[7], m[2], m[8], gOneThird),
        surfaceScale);
}

inline SkPoint3 interiorNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(m[0], m[2], m[3], m[5], m[6], m[8], gOneQuarter),
        sobel(m[0], m[6], m[1], m[7], m[2], m[8], gOneQuarter),
        surfaceScale);
}

inline SkPoint3 rightNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(m[0], m[1], m[3], m[4], m[6], m[7], gOneHalf),
        sobel(m[0], m[6], m[1], m[7], 0, 0, gOneThird),
        surfaceScale);
}

inline SkPoint3 bottomLeftNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(m[1], m[2], m[4], m[5], 0, 0, gTwoThirds),
        sobel(0, 0, m[1], m[4], m[2], m[5], gTwoThirds),
        surfaceScale);
}

inline SkPoint3 bottomNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(m[0], m[2], m[3], m[5], 0, 0, gOneThird),
        sobel(m[0], m[3], m[1], m[4], m[2], m[5], gOneHalf),
        surfaceScale);
}

inline SkPoint3 bottomRightNormal(int m[9], SkScalar surfaceScale)
{
    return pointToNormal(sobel(m[0], m[1], m[3], m[4], 0, 0, gTwoThirds),
        sobel(m[0], m[3], m[1], m[4], 0, 0, gTwoThirds),
        surfaceScale);
}

class UncheckedPixelFetcher {
public:
    static inline uint32_t Fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds)
    {
        return SkGetPackedA32(*src.getAddr32(x, y));
    }
};

// The DecalPixelFetcher is used when the destination crop rect exceeds the input bitmap bounds.
class DecalPixelFetcher {
public:
    static inline uint32_t Fetch(const SkBitmap& src, int x, int y, const SkIRect& bounds)
    {
        if (x < bounds.fLeft || x >= bounds.fRight || y < bounds.fTop || y >= bounds.fBottom) {
            return 0;
        } else {
            return SkGetPackedA32(*src.getAddr32(x, y));
        }
    }
};

template <class LightingType, class LightType, class PixelFetcher>
void lightBitmap(const LightingType& lightingType,
    const SkImageFilterLight* light,
    const SkBitmap& src,
    SkBitmap* dst,
    SkScalar surfaceScale,
    const SkIRect& bounds)
{
=======
inline SkScalar sobel(int a, int b, int c, int d, int e, int f, SkScalar scale) {
    return SkScalarMul(SkIntToScalar(-a + b - 2 * c + 2 * d -e + f), scale);
}

inline SkPoint3 pointToNormal(SkScalar x, SkScalar y, SkScalar surfaceScale) {
    SkPoint3 vector(SkScalarMul(-x, surfaceScale),
                    SkScalarMul(-y, surfaceScale),
                    SK_Scalar1);
    vector.normalize();
    return vector;
}

inline SkPoint3 topLeftNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(0, 0, m[4], m[5], m[7], m[8], gTwoThirds),
                         sobel(0, 0, m[4], m[7], m[5], m[8], gTwoThirds),
                         surfaceScale);
}

inline SkPoint3 topNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(   0,    0, m[3], m[5], m[6], m[8], gOneThird),
                         sobel(m[3], m[6], m[4], m[7], m[5], m[8], gOneHalf),
                         surfaceScale);
}

inline SkPoint3 topRightNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(   0,    0, m[3], m[4], m[6], m[7], gTwoThirds),
                         sobel(m[3], m[6], m[4], m[7],    0,    0, gTwoThirds),
                         surfaceScale);
}

inline SkPoint3 leftNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(m[1], m[2], m[4], m[5], m[7], m[8], gOneHalf),
                         sobel(   0,    0, m[1], m[7], m[2], m[8], gOneThird),
                         surfaceScale);
}


inline SkPoint3 interiorNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(m[0], m[2], m[3], m[5], m[6], m[8], gOneQuarter),
                         sobel(m[0], m[6], m[1], m[7], m[2], m[8], gOneQuarter),
                         surfaceScale);
}

inline SkPoint3 rightNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(m[0], m[1], m[3], m[4], m[6], m[7], gOneHalf),
                         sobel(m[0], m[6], m[1], m[7],    0,    0, gOneThird),
                         surfaceScale);
}

inline SkPoint3 bottomLeftNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(m[1], m[2], m[4], m[5],    0,    0, gTwoThirds),
                         sobel(   0,    0, m[1], m[4], m[2], m[5], gTwoThirds),
                         surfaceScale);
}

inline SkPoint3 bottomNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(m[0], m[2], m[3], m[5],    0,    0, gOneThird),
                         sobel(m[0], m[3], m[1], m[4], m[2], m[5], gOneHalf),
                         surfaceScale);
}

inline SkPoint3 bottomRightNormal(int m[9], SkScalar surfaceScale) {
    return pointToNormal(sobel(m[0], m[1], m[3], m[4], 0,  0, gTwoThirds),
                         sobel(m[0], m[3], m[1], m[4], 0,  0, gTwoThirds),
                         surfaceScale);
}

template <class LightingType, class LightType> void lightBitmap(
        const LightingType& lightingType, const SkLight* light, const SkBitmap& src, SkBitmap* dst,
        SkScalar surfaceScale, const SkIRect& bounds) {
>>>>>>> miniblink49
    SkASSERT(dst->width() == bounds.width() && dst->height() == bounds.height());
    const LightType* l = static_cast<const LightType*>(light);
    int left = bounds.left(), right = bounds.right();
    int bottom = bounds.bottom();
    int y = bounds.top();
<<<<<<< HEAD
    SkIRect srcBounds = src.bounds();
    SkPMColor* dptr = dst->getAddr32(0, 0);
    {
        int x = left;
        int m[9];
        m[4] = PixelFetcher::Fetch(src, x, y, srcBounds);
        m[5] = PixelFetcher::Fetch(src, x + 1, y, srcBounds);
        m[7] = PixelFetcher::Fetch(src, x, y + 1, srcBounds);
        m[8] = PixelFetcher::Fetch(src, x + 1, y + 1, srcBounds);
        SkPoint3 surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(topLeftNormal(m, surfaceScale), surfaceToLight,
            l->lightColor(surfaceToLight));
        for (++x; x < right - 1; ++x) {
            shiftMatrixLeft(m);
            m[5] = PixelFetcher::Fetch(src, x + 1, y, srcBounds);
            m[8] = PixelFetcher::Fetch(src, x + 1, y + 1, srcBounds);
            surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
            *dptr++ = lightingType.light(topNormal(m, surfaceScale), surfaceToLight,
                l->lightColor(surfaceToLight));
=======
    SkPMColor* dptr = dst->getAddr32(0, 0);
    {
        int x = left;
        const SkPMColor* row1 = src.getAddr32(x, y);
        const SkPMColor* row2 = src.getAddr32(x, y + 1);
        int m[9];
        m[4] = SkGetPackedA32(*row1++);
        m[5] = SkGetPackedA32(*row1++);
        m[7] = SkGetPackedA32(*row2++);
        m[8] = SkGetPackedA32(*row2++);
        SkPoint3 surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(topLeftNormal(m, surfaceScale), surfaceToLight,
                                     l->lightColor(surfaceToLight));
        for (++x; x < right - 1; ++x)
        {
            shiftMatrixLeft(m);
            m[5] = SkGetPackedA32(*row1++);
            m[8] = SkGetPackedA32(*row2++);
            surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
            *dptr++ = lightingType.light(topNormal(m, surfaceScale), surfaceToLight,
                                         l->lightColor(surfaceToLight));
>>>>>>> miniblink49
        }
        shiftMatrixLeft(m);
        surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(topRightNormal(m, surfaceScale), surfaceToLight,
<<<<<<< HEAD
            l->lightColor(surfaceToLight));
=======
                                     l->lightColor(surfaceToLight));
>>>>>>> miniblink49
    }

    for (++y; y < bottom - 1; ++y) {
        int x = left;
<<<<<<< HEAD
        int m[9];
        m[1] = PixelFetcher::Fetch(src, x, y - 1, srcBounds);
        m[2] = PixelFetcher::Fetch(src, x + 1, y - 1, srcBounds);
        m[4] = PixelFetcher::Fetch(src, x, y, srcBounds);
        m[5] = PixelFetcher::Fetch(src, x + 1, y, srcBounds);
        m[7] = PixelFetcher::Fetch(src, x, y + 1, srcBounds);
        m[8] = PixelFetcher::Fetch(src, x + 1, y + 1, srcBounds);
        SkPoint3 surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(leftNormal(m, surfaceScale), surfaceToLight,
            l->lightColor(surfaceToLight));
        for (++x; x < right - 1; ++x) {
            shiftMatrixLeft(m);
            m[2] = PixelFetcher::Fetch(src, x + 1, y - 1, srcBounds);
            m[5] = PixelFetcher::Fetch(src, x + 1, y, srcBounds);
            m[8] = PixelFetcher::Fetch(src, x + 1, y + 1, srcBounds);
            surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
            *dptr++ = lightingType.light(interiorNormal(m, surfaceScale), surfaceToLight,
                l->lightColor(surfaceToLight));
=======
        const SkPMColor* row0 = src.getAddr32(x, y - 1);
        const SkPMColor* row1 = src.getAddr32(x, y);
        const SkPMColor* row2 = src.getAddr32(x, y + 1);
        int m[9];
        m[1] = SkGetPackedA32(*row0++);
        m[2] = SkGetPackedA32(*row0++);
        m[4] = SkGetPackedA32(*row1++);
        m[5] = SkGetPackedA32(*row1++);
        m[7] = SkGetPackedA32(*row2++);
        m[8] = SkGetPackedA32(*row2++);
        SkPoint3 surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(leftNormal(m, surfaceScale), surfaceToLight,
                                     l->lightColor(surfaceToLight));
        for (++x; x < right - 1; ++x) {
            shiftMatrixLeft(m);
            m[2] = SkGetPackedA32(*row0++);
            m[5] = SkGetPackedA32(*row1++);
            m[8] = SkGetPackedA32(*row2++);
            surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
            *dptr++ = lightingType.light(interiorNormal(m, surfaceScale), surfaceToLight,
                                         l->lightColor(surfaceToLight));
>>>>>>> miniblink49
        }
        shiftMatrixLeft(m);
        surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(rightNormal(m, surfaceScale), surfaceToLight,
<<<<<<< HEAD
            l->lightColor(surfaceToLight));
=======
                                     l->lightColor(surfaceToLight));
>>>>>>> miniblink49
    }

    {
        int x = left;
<<<<<<< HEAD
        int m[9];
        m[1] = PixelFetcher::Fetch(src, x, bottom - 2, srcBounds);
        m[2] = PixelFetcher::Fetch(src, x + 1, bottom - 2, srcBounds);
        m[4] = PixelFetcher::Fetch(src, x, bottom - 1, srcBounds);
        m[5] = PixelFetcher::Fetch(src, x + 1, bottom - 1, srcBounds);
        SkPoint3 surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(bottomLeftNormal(m, surfaceScale), surfaceToLight,
            l->lightColor(surfaceToLight));
        for (++x; x < right - 1; ++x) {
            shiftMatrixLeft(m);
            m[2] = PixelFetcher::Fetch(src, x + 1, bottom - 2, srcBounds);
            m[5] = PixelFetcher::Fetch(src, x + 1, bottom - 1, srcBounds);
            surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
            *dptr++ = lightingType.light(bottomNormal(m, surfaceScale), surfaceToLight,
                l->lightColor(surfaceToLight));
=======
        const SkPMColor* row0 = src.getAddr32(x, bottom - 2);
        const SkPMColor* row1 = src.getAddr32(x, bottom - 1);
        int m[9];
        m[1] = SkGetPackedA32(*row0++);
        m[2] = SkGetPackedA32(*row0++);
        m[4] = SkGetPackedA32(*row1++);
        m[5] = SkGetPackedA32(*row1++);
        SkPoint3 surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(bottomLeftNormal(m, surfaceScale), surfaceToLight,
                                     l->lightColor(surfaceToLight));
        for (++x; x < right - 1; ++x)
        {
            shiftMatrixLeft(m);
            m[2] = SkGetPackedA32(*row0++);
            m[5] = SkGetPackedA32(*row1++);
            surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
            *dptr++ = lightingType.light(bottomNormal(m, surfaceScale), surfaceToLight,
                                         l->lightColor(surfaceToLight));
>>>>>>> miniblink49
        }
        shiftMatrixLeft(m);
        surfaceToLight = l->surfaceToLight(x, y, m[4], surfaceScale);
        *dptr++ = lightingType.light(bottomRightNormal(m, surfaceScale), surfaceToLight,
<<<<<<< HEAD
            l->lightColor(surfaceToLight));
    }
}

template <class LightingType, class LightType>
void lightBitmap(const LightingType& lightingType,
    const SkImageFilterLight* light,
    const SkBitmap& src,
    SkBitmap* dst,
    SkScalar surfaceScale,
    const SkIRect& bounds)
{
    if (src.bounds().contains(bounds)) {
        lightBitmap<LightingType, LightType, UncheckedPixelFetcher>(
            lightingType, light, src, dst, surfaceScale, bounds);
    } else {
        lightBitmap<LightingType, LightType, DecalPixelFetcher>(
            lightingType, light, src, dst, surfaceScale, bounds);
    }
}

SkPoint3 readPoint3(SkReadBuffer& buffer)
{
=======
                                     l->lightColor(surfaceToLight));
    }
}

SkPoint3 readPoint3(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    SkPoint3 point;
    point.fX = buffer.readScalar();
    point.fY = buffer.readScalar();
    point.fZ = buffer.readScalar();
<<<<<<< HEAD
    buffer.validate(SkScalarIsFinite(point.fX) && SkScalarIsFinite(point.fY) && SkScalarIsFinite(point.fZ));
    return point;
};

void writePoint3(const SkPoint3& point, SkWriteBuffer& buffer)
{
=======
    buffer.validate(SkScalarIsFinite(point.fX) &&
                    SkScalarIsFinite(point.fY) &&
                    SkScalarIsFinite(point.fZ));
    return point;
};

void writePoint3(const SkPoint3& point, SkWriteBuffer& buffer) {
>>>>>>> miniblink49
    buffer.writeScalar(point.fX);
    buffer.writeScalar(point.fY);
    buffer.writeScalar(point.fZ);
};

enum BoundaryMode {
    kTopLeft_BoundaryMode,
    kTop_BoundaryMode,
    kTopRight_BoundaryMode,
    kLeft_BoundaryMode,
    kInterior_BoundaryMode,
    kRight_BoundaryMode,
    kBottomLeft_BoundaryMode,
    kBottom_BoundaryMode,
    kBottomRight_BoundaryMode,

    kBoundaryModeCount,
};

class SkLightingImageFilterInternal : public SkLightingImageFilter {
protected:
<<<<<<< HEAD
    SkLightingImageFilterInternal(sk_sp<SkImageFilterLight> light,
        SkScalar surfaceScale,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect)
        : INHERITED(std::move(light), surfaceScale, std::move(input), cropRect)
    {
    }

#if SK_SUPPORT_GPU
    sk_sp<SkSpecialImage> filterImageGPU(SkSpecialImage* source,
        SkSpecialImage* input,
        const SkIRect& bounds,
        const SkMatrix& matrix) const;
    virtual sk_sp<GrFragmentProcessor> makeFragmentProcessor(GrTexture*,
        const SkMatrix&,
        const SkIRect* srcBounds,
        BoundaryMode boundaryMode) const = 0;
=======
    SkLightingImageFilterInternal(SkLight* light,
                                  SkScalar surfaceScale,
                                  SkImageFilter* input,
                                  const CropRect* cropRect)
      : INHERITED(light, surfaceScale, input, cropRect) {}

#if SK_SUPPORT_GPU
    bool canFilterImageGPU() const override { return true; }
    bool filterImageGPU(Proxy*, const SkBitmap& src, const Context&,
                        SkBitmap* result, SkIPoint* offset) const override;
    virtual GrFragmentProcessor* getFragmentProcessor(GrProcessorDataManager*,
                                                      GrTexture*,
                                                      const SkMatrix&,
                                                      const SkIRect& bounds,
                                                      BoundaryMode boundaryMode) const = 0;
>>>>>>> miniblink49
#endif
private:
#if SK_SUPPORT_GPU
    void drawRect(GrDrawContext* drawContext,
<<<<<<< HEAD
        GrTexture* src,
        const SkMatrix& matrix,
        const GrClip& clip,
        const SkRect& dstRect,
        BoundaryMode boundaryMode,
        const SkIRect* srcBounds,
        const SkIRect& bounds) const;
=======
                  GrTexture* src,
                  GrTexture* dst,
                  const SkMatrix& matrix,
                  const GrClip& clip,
                  const SkRect& dstRect,
                  BoundaryMode boundaryMode,
                  const SkIRect& bounds) const;
>>>>>>> miniblink49
#endif
    typedef SkLightingImageFilter INHERITED;
};

#if SK_SUPPORT_GPU
void SkLightingImageFilterInternal::drawRect(GrDrawContext* drawContext,
<<<<<<< HEAD
    GrTexture* src,
    const SkMatrix& matrix,
    const GrClip& clip,
    const SkRect& dstRect,
    BoundaryMode boundaryMode,
    const SkIRect* srcBounds,
    const SkIRect& bounds) const
{
    SkRect srcRect = dstRect.makeOffset(SkIntToScalar(bounds.x()), SkIntToScalar(bounds.y()));
    GrPaint paint;
    // SRGBTODO: AllowSRGBInputs?
    sk_sp<GrFragmentProcessor> fp(this->makeFragmentProcessor(src, matrix, srcBounds,
        boundaryMode));
    paint.addColorFragmentProcessor(std::move(fp));
    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
    drawContext->fillRectToRect(clip, paint, SkMatrix::I(), dstRect, srcRect);
}

sk_sp<SkSpecialImage> SkLightingImageFilterInternal::filterImageGPU(SkSpecialImage* source,
    SkSpecialImage* input,
    const SkIRect& offsetBounds,
    const SkMatrix& matrix) const
{
    SkASSERT(source->isTextureBacked());

    GrContext* context = source->getContext();

    sk_sp<GrTexture> inputTexture(input->asTextureRef(context));
    SkASSERT(inputTexture);

    sk_sp<GrDrawContext> drawContext(context->newDrawContext(SkBackingFit::kApprox,
        offsetBounds.width(),
        offsetBounds.height(),
        kRGBA_8888_GrPixelConfig));
    if (!drawContext) {
        return nullptr;
    }

    SkIRect dstIRect = SkIRect::MakeWH(offsetBounds.width(), offsetBounds.height());
    SkRect dstRect = SkRect::Make(dstIRect);

    // setup new clip
    GrFixedClip clip(dstIRect);

    const SkIRect inputBounds = SkIRect::MakeWH(input->width(), input->height());
=======
                                             GrTexture* src,
                                             GrTexture* dst,
                                             const SkMatrix& matrix,
                                             const GrClip& clip,
                                             const SkRect& dstRect,
                                             BoundaryMode boundaryMode,
                                             const SkIRect& bounds) const {
    SkRect srcRect = dstRect.makeOffset(SkIntToScalar(bounds.x()), SkIntToScalar(bounds.y()));
    GrPaint paint;
    GrFragmentProcessor* fp = this->getFragmentProcessor(paint.getProcessorDataManager(), src,
                                                         matrix, bounds, boundaryMode);
    paint.addColorProcessor(fp)->unref();
    drawContext->drawNonAARectToRect(dst->asRenderTarget(), clip, paint, SkMatrix::I(),
                                     dstRect, srcRect);
}

bool SkLightingImageFilterInternal::filterImageGPU(Proxy* proxy,
                                                   const SkBitmap& src,
                                                   const Context& ctx,
                                                   SkBitmap* result,
                                                   SkIPoint* offset) const {
    SkBitmap input = src;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (this->getInput(0) &&
        !this->getInput(0)->getInputResultGPU(proxy, src, ctx, &input, &srcOffset)) {
        return false;
    }
    SkIRect bounds;
    if (!this->applyCropRect(ctx, proxy, input, &srcOffset, &bounds, &input)) {
        return false;
    }
    SkRect dstRect = SkRect::MakeWH(SkIntToScalar(bounds.width()),
                                    SkIntToScalar(bounds.height()));
    GrTexture* srcTexture = input.getTexture();
    GrContext* context = srcTexture->getContext();

    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag,
    desc.fWidth = bounds.width();
    desc.fHeight = bounds.height();
    desc.fConfig = kRGBA_8888_GrPixelConfig;

    SkAutoTUnref<GrTexture> dst(context->textureProvider()->refScratchTexture(desc,
        GrTextureProvider::kApprox_ScratchTexMatch));
    if (!dst) {
        return false;
    }

    // setup new clip
    GrClip clip(dstRect);

    offset->fX = bounds.left();
    offset->fY = bounds.top();
    SkMatrix matrix(ctx.ctm());
    matrix.postTranslate(SkIntToScalar(-bounds.left()), SkIntToScalar(-bounds.top()));
    bounds.offset(-srcOffset);
>>>>>>> miniblink49
    SkRect topLeft = SkRect::MakeXYWH(0, 0, 1, 1);
    SkRect top = SkRect::MakeXYWH(1, 0, dstRect.width() - 2, 1);
    SkRect topRight = SkRect::MakeXYWH(dstRect.width() - 1, 0, 1, 1);
    SkRect left = SkRect::MakeXYWH(0, 1, 1, dstRect.height() - 2);
    SkRect interior = dstRect.makeInset(1, 1);
    SkRect right = SkRect::MakeXYWH(dstRect.width() - 1, 1, 1, dstRect.height() - 2);
    SkRect bottomLeft = SkRect::MakeXYWH(0, dstRect.height() - 1, 1, 1);
    SkRect bottom = SkRect::MakeXYWH(1, dstRect.height() - 1, dstRect.width() - 2, 1);
    SkRect bottomRight = SkRect::MakeXYWH(dstRect.width() - 1, dstRect.height() - 1, 1, 1);

<<<<<<< HEAD
    const SkIRect* pSrcBounds = inputBounds.contains(offsetBounds) ? nullptr : &inputBounds;
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, topLeft,
        kTopLeft_BoundaryMode, pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, top, kTop_BoundaryMode,
        pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, topRight,
        kTopRight_BoundaryMode, pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, left, kLeft_BoundaryMode,
        pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, interior,
        kInterior_BoundaryMode, pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, right, kRight_BoundaryMode,
        pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, bottomLeft,
        kBottomLeft_BoundaryMode, pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, bottom,
        kBottom_BoundaryMode, pSrcBounds, offsetBounds);
    this->drawRect(drawContext.get(), inputTexture.get(), matrix, clip, bottomRight,
        kBottomRight_BoundaryMode, pSrcBounds, offsetBounds);

    return SkSpecialImage::MakeFromGpu(SkIRect::MakeWH(offsetBounds.width(), offsetBounds.height()),
        kNeedNewImageUniqueID_SpecialImage,
        drawContext->asTexture());
=======
    GrDrawContext* drawContext = context->drawContext();
    if (!drawContext) {
        return false;
    }

    this->drawRect(drawContext, srcTexture, dst, matrix, clip, topLeft, kTopLeft_BoundaryMode, 
                   bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, top, kTop_BoundaryMode, bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, topRight, kTopRight_BoundaryMode,
                   bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, left, kLeft_BoundaryMode, bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, interior, kInterior_BoundaryMode,
                   bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, right, kRight_BoundaryMode, bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, bottomLeft, kBottomLeft_BoundaryMode,
                   bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, bottom, kBottom_BoundaryMode, bounds);
    this->drawRect(drawContext, srcTexture, dst, matrix, clip, bottomRight,
                   kBottomRight_BoundaryMode, bounds);
    WrapTexture(dst, bounds.width(), bounds.height(), result);
    return true;
>>>>>>> miniblink49
}
#endif

class SkDiffuseLightingImageFilter : public SkLightingImageFilterInternal {
public:
<<<<<<< HEAD
    static sk_sp<SkImageFilter> Make(sk_sp<SkImageFilterLight> light,
        SkScalar surfaceScale,
        SkScalar kd,
        sk_sp<SkImageFilter>,
        const CropRect*);
=======
    static SkImageFilter* Create(SkLight* light, SkScalar surfaceScale, SkScalar kd, SkImageFilter*,
                                 const CropRect*);
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkDiffuseLightingImageFilter)
    SkScalar kd() const { return fKD; }

protected:
<<<<<<< HEAD
    SkDiffuseLightingImageFilter(sk_sp<SkImageFilterLight> light, SkScalar surfaceScale,
        SkScalar kd,
        sk_sp<SkImageFilter> input, const CropRect* cropRect);
    void flatten(SkWriteBuffer& buffer) const override;

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;

#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> makeFragmentProcessor(GrTexture*, const SkMatrix&,
        const SkIRect* bounds,
        BoundaryMode) const override;
=======
    SkDiffuseLightingImageFilter(SkLight* light, SkScalar surfaceScale,
                                 SkScalar kd, SkImageFilter* input, const CropRect* cropRect);
    void flatten(SkWriteBuffer& buffer) const override;
    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override;
#if SK_SUPPORT_GPU
    GrFragmentProcessor* getFragmentProcessor(GrProcessorDataManager*, GrTexture*, const SkMatrix&,
                                              const SkIRect& bounds, BoundaryMode) const override;
>>>>>>> miniblink49
#endif

private:
    friend class SkLightingImageFilter;
<<<<<<< HEAD
    SkScalar fKD;

    typedef SkLightingImageFilterInternal INHERITED;
=======
    typedef SkLightingImageFilterInternal INHERITED;
    SkScalar fKD;
>>>>>>> miniblink49
};

class SkSpecularLightingImageFilter : public SkLightingImageFilterInternal {
public:
<<<<<<< HEAD
    static sk_sp<SkImageFilter> Make(sk_sp<SkImageFilterLight> light,
        SkScalar surfaceScale,
        SkScalar ks, SkScalar shininess,
        sk_sp<SkImageFilter>, const CropRect*);
=======
    static SkImageFilter* Create(SkLight* light, SkScalar surfaceScale,
                                 SkScalar ks, SkScalar shininess, SkImageFilter*, const CropRect*);
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkSpecularLightingImageFilter)

    SkScalar ks() const { return fKS; }
    SkScalar shininess() const { return fShininess; }

protected:
<<<<<<< HEAD
    SkSpecularLightingImageFilter(sk_sp<SkImageFilterLight> light,
        SkScalar surfaceScale, SkScalar ks,
        SkScalar shininess,
        sk_sp<SkImageFilter> input, const CropRect*);
    void flatten(SkWriteBuffer& buffer) const override;

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;

#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> makeFragmentProcessor(GrTexture*, const SkMatrix&,
        const SkIRect* bounds,
        BoundaryMode) const override;
=======
    SkSpecularLightingImageFilter(SkLight* light, SkScalar surfaceScale, SkScalar ks,
                                  SkScalar shininess, SkImageFilter* input, const CropRect*);
    void flatten(SkWriteBuffer& buffer) const override;
    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override;
#if SK_SUPPORT_GPU
    GrFragmentProcessor* getFragmentProcessor(GrProcessorDataManager*, GrTexture*, const SkMatrix&,
                                              const SkIRect& bounds, BoundaryMode) const override;
>>>>>>> miniblink49
#endif

private:
    SkScalar fKS;
    SkScalar fShininess;
    friend class SkLightingImageFilter;
    typedef SkLightingImageFilterInternal INHERITED;
};

#if SK_SUPPORT_GPU

class GrLightingEffect : public GrSingleTextureEffect {
public:
<<<<<<< HEAD
    GrLightingEffect(GrTexture* texture, const SkImageFilterLight* light, SkScalar surfaceScale,
        const SkMatrix& matrix, BoundaryMode boundaryMode, const SkIRect* srcBounds);
    ~GrLightingEffect() override;

    const SkImageFilterLight* light() const { return fLight; }
    SkScalar surfaceScale() const { return fSurfaceScale; }
    const SkMatrix& filterMatrix() const { return fFilterMatrix; }
    BoundaryMode boundaryMode() const { return fBoundaryMode; }
    const GrTextureDomain& domain() const { return fDomain; }
=======
    GrLightingEffect(GrProcessorDataManager*, GrTexture* texture, const SkLight* light,
                     SkScalar surfaceScale, const SkMatrix& matrix, BoundaryMode boundaryMode);
    virtual ~GrLightingEffect();

    const SkLight* light() const { return fLight; }
    SkScalar surfaceScale() const { return fSurfaceScale; }
    const SkMatrix& filterMatrix() const { return fFilterMatrix; }
    BoundaryMode boundaryMode() const { return fBoundaryMode; }
>>>>>>> miniblink49

protected:
    bool onIsEqual(const GrFragmentProcessor&) const override;

<<<<<<< HEAD
    void onComputeInvariantOutput(GrInvariantOutput* inout) const override
    {
=======
    void onComputeInvariantOutput(GrInvariantOutput* inout) const override {
>>>>>>> miniblink49
        // lighting shaders are complicated. We just throw up our hands.
        inout->mulByUnknownFourComponents();
    }

private:
<<<<<<< HEAD
    const SkImageFilterLight* fLight;
    SkScalar fSurfaceScale;
    SkMatrix fFilterMatrix;
    BoundaryMode fBoundaryMode;
    GrTextureDomain fDomain;

    typedef GrSingleTextureEffect INHERITED;
=======
    typedef GrSingleTextureEffect INHERITED;
    const SkLight* fLight;
    SkScalar fSurfaceScale;
    SkMatrix fFilterMatrix;
    BoundaryMode fBoundaryMode;
>>>>>>> miniblink49
};

class GrDiffuseLightingEffect : public GrLightingEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* texture,
        const SkImageFilterLight* light,
        SkScalar surfaceScale,
        const SkMatrix& matrix,
        SkScalar kd,
        BoundaryMode boundaryMode,
        const SkIRect* srcBounds)
    {
        return sk_sp<GrFragmentProcessor>(
            new GrDiffuseLightingEffect(texture, light, surfaceScale, matrix, kd, boundaryMode,
                srcBounds));
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager,
                                       GrTexture* texture,
                                       const SkLight* light,
                                       SkScalar surfaceScale,
                                       const SkMatrix& matrix,
                                       SkScalar kd,
                                       BoundaryMode boundaryMode) {
        return SkNEW_ARGS(GrDiffuseLightingEffect, (procDataManager,
                                                    texture,
                                                    light,
                                                    surfaceScale,
                                                    matrix,
                                                    kd,
                                                    boundaryMode));
>>>>>>> miniblink49
    }

    const char* name() const override { return "DiffuseLighting"; }

<<<<<<< HEAD
    SkScalar kd() const { return fKD; }

private:
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor&) const override;

    GrDiffuseLightingEffect(GrTexture* texture,
        const SkImageFilterLight* light,
        SkScalar surfaceScale,
        const SkMatrix& matrix,
        SkScalar kd,
        BoundaryMode boundaryMode,
        const SkIRect* srcBounds);
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

    SkScalar kd() const { return fKD; }

private:
    bool onIsEqual(const GrFragmentProcessor&) const override;

    GrDiffuseLightingEffect(GrProcessorDataManager*,
                            GrTexture* texture,
                            const SkLight* light,
                            SkScalar surfaceScale,
                            const SkMatrix& matrix,
                            SkScalar kd,
                            BoundaryMode boundaryMode);
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;
    typedef GrLightingEffect INHERITED;
    SkScalar fKD;
};

class GrSpecularLightingEffect : public GrLightingEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* texture,
        const SkImageFilterLight* light,
        SkScalar surfaceScale,
        const SkMatrix& matrix,
        SkScalar ks,
        SkScalar shininess,
        BoundaryMode boundaryMode,
        const SkIRect* srcBounds)
    {
        return sk_sp<GrFragmentProcessor>(
            new GrSpecularLightingEffect(texture, light, surfaceScale, matrix, ks, shininess,
                boundaryMode, srcBounds));
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager,
                                       GrTexture* texture,
                                       const SkLight* light,
                                       SkScalar surfaceScale,
                                       const SkMatrix& matrix,
                                       SkScalar ks,
                                       SkScalar shininess,
                                       BoundaryMode boundaryMode) {
        return SkNEW_ARGS(GrSpecularLightingEffect, (procDataManager,
                                                     texture,
                                                     light,
                                                     surfaceScale,
                                                     matrix,
                                                     ks,
                                                     shininess,
                                                     boundaryMode));
>>>>>>> miniblink49
    }

    const char* name() const override { return "SpecularLighting"; }

<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;
>>>>>>> miniblink49

    SkScalar ks() const { return fKS; }
    SkScalar shininess() const { return fShininess; }

private:
<<<<<<< HEAD
    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor&) const override;

    GrSpecularLightingEffect(GrTexture* texture,
        const SkImageFilterLight* light,
        SkScalar surfaceScale,
        const SkMatrix& matrix,
        SkScalar ks,
        SkScalar shininess,
        BoundaryMode boundaryMode,
        const SkIRect* srcBounds);
=======
    bool onIsEqual(const GrFragmentProcessor&) const override;

    GrSpecularLightingEffect(GrProcessorDataManager*,
                             GrTexture* texture,
                             const SkLight* light,
                             SkScalar surfaceScale,
                             const SkMatrix& matrix,
                             SkScalar ks,
                             SkScalar shininess,
                             BoundaryMode boundaryMode);
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;
    typedef GrLightingEffect INHERITED;
    SkScalar fKS;
    SkScalar fShininess;
};

///////////////////////////////////////////////////////////////////////////////

class GrGLLight {
public:
<<<<<<< HEAD
    virtual ~GrGLLight() { }
=======
    virtual ~GrGLLight() {}
>>>>>>> miniblink49

    /**
     * This is called by GrGLLightingEffect::emitCode() before either of the two virtual functions
     * below. It adds a vec3f uniform visible in the FS that represents the constant light color.
     */
<<<<<<< HEAD
    void emitLightColorUniform(GrGLSLUniformHandler*);
=======
    void emitLightColorUniform(GrGLFPBuilder*);
>>>>>>> miniblink49

    /**
     * These two functions are called from GrGLLightingEffect's emitCode() function.
     * emitSurfaceToLight places an expression in param out that is the vector from the surface to
     * the light. The expression will be used in the FS. emitLightColor writes an expression into
     * the FS that is the color of the light. Either function may add functions and/or uniforms to
     * the FS. The default of emitLightColor appends the name of the constant light color uniform
     * and so this function only needs to be overridden if the light color varies spatially.
     */
<<<<<<< HEAD
    virtual void emitSurfaceToLight(GrGLSLUniformHandler*,
        GrGLSLFPFragmentBuilder*,
        const char* z)
        = 0;
    virtual void emitLightColor(GrGLSLUniformHandler*,
        GrGLSLFPFragmentBuilder*,
        const char* surfaceToLight);

    // This is called from GrGLLightingEffect's setData(). Subclasses of GrGLLight must call
    // INHERITED::setData().
    virtual void setData(const GrGLSLProgramDataManager&, const SkImageFilterLight* light) const;
=======
    virtual void emitSurfaceToLight(GrGLFPBuilder*, const char* z) = 0;
    virtual void emitLightColor(GrGLFPBuilder*, const char *surfaceToLight);

    // This is called from GrGLLightingEffect's setData(). Subclasses of GrGLLight must call
    // INHERITED::setData().
    virtual void setData(const GrGLProgramDataManager&,
                         const SkLight* light) const;
>>>>>>> miniblink49

protected:
    /**
     * Gets the constant light color uniform. Subclasses can use this in their emitLightColor
     * function.
     */
    UniformHandle lightColorUni() const { return fColorUni; }

private:
    UniformHandle fColorUni;

    typedef SkRefCnt INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

class GrGLDistantLight : public GrGLLight {
public:
<<<<<<< HEAD
    virtual ~GrGLDistantLight() { }
    void setData(const GrGLSLProgramDataManager&, const SkImageFilterLight* light) const override;
    void emitSurfaceToLight(GrGLSLUniformHandler*, GrGLSLFPFragmentBuilder*, const char* z) override;
=======
    virtual ~GrGLDistantLight() {}
    void setData(const GrGLProgramDataManager&, const SkLight* light) const override;
    void emitSurfaceToLight(GrGLFPBuilder*, const char* z) override;
>>>>>>> miniblink49

private:
    typedef GrGLLight INHERITED;
    UniformHandle fDirectionUni;
};

///////////////////////////////////////////////////////////////////////////////

class GrGLPointLight : public GrGLLight {
public:
<<<<<<< HEAD
    virtual ~GrGLPointLight() { }
    void setData(const GrGLSLProgramDataManager&, const SkImageFilterLight* light) const override;
    void emitSurfaceToLight(GrGLSLUniformHandler*, GrGLSLFPFragmentBuilder*, const char* z) override;
=======
    virtual ~GrGLPointLight() {}
    void setData(const GrGLProgramDataManager&, const SkLight* light) const override;
    void emitSurfaceToLight(GrGLFPBuilder*, const char* z) override;
>>>>>>> miniblink49

private:
    typedef GrGLLight INHERITED;
    UniformHandle fLocationUni;
};

///////////////////////////////////////////////////////////////////////////////

class GrGLSpotLight : public GrGLLight {
public:
<<<<<<< HEAD
    virtual ~GrGLSpotLight() { }
    void setData(const GrGLSLProgramDataManager&, const SkImageFilterLight* light) const override;
    void emitSurfaceToLight(GrGLSLUniformHandler*, GrGLSLFPFragmentBuilder*, const char* z) override;
    void emitLightColor(GrGLSLUniformHandler*,
        GrGLSLFPFragmentBuilder*,
        const char* surfaceToLight) override;
=======
    virtual ~GrGLSpotLight() {}
    void setData(const GrGLProgramDataManager&, const SkLight* light) const override;
    void emitSurfaceToLight(GrGLFPBuilder*, const char* z) override;
    void emitLightColor(GrGLFPBuilder*, const char *surfaceToLight) override;
>>>>>>> miniblink49

private:
    typedef GrGLLight INHERITED;

<<<<<<< HEAD
    SkString fLightColorFunc;
    UniformHandle fLocationUni;
    UniformHandle fExponentUni;
    UniformHandle fCosOuterConeAngleUni;
    UniformHandle fCosInnerConeAngleUni;
    UniformHandle fConeScaleUni;
    UniformHandle fSUni;
=======
    SkString        fLightColorFunc;
    UniformHandle   fLocationUni;
    UniformHandle   fExponentUni;
    UniformHandle   fCosOuterConeAngleUni;
    UniformHandle   fCosInnerConeAngleUni;
    UniformHandle   fConeScaleUni;
    UniformHandle   fSUni;
>>>>>>> miniblink49
};
#else

class GrGLLight;

#endif

};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class SkImageFilterLight : public SkRefCnt {
public:
=======
class SkLight : public SkRefCnt {
public:
    

>>>>>>> miniblink49
    enum LightType {
        kDistant_LightType,
        kPoint_LightType,
        kSpot_LightType,
    };
    virtual LightType type() const = 0;
    const SkPoint3& color() const { return fColor; }
    virtual GrGLLight* createGLLight() const = 0;
<<<<<<< HEAD
    virtual bool isEqual(const SkImageFilterLight& other) const
    {
=======
    virtual bool isEqual(const SkLight& other) const {
>>>>>>> miniblink49
        return fColor == other.fColor;
    }
    // Called to know whether the generated GrGLLight will require access to the fragment position.
    virtual bool requiresFragmentPosition() const = 0;
<<<<<<< HEAD
    virtual SkImageFilterLight* transform(const SkMatrix& matrix) const = 0;

    // Defined below SkLight's subclasses.
    void flattenLight(SkWriteBuffer& buffer) const;
    static SkImageFilterLight* UnflattenLight(SkReadBuffer& buffer);

protected:
    SkImageFilterLight(SkColor color)
    {
        fColor = SkPoint3::Make(SkIntToScalar(SkColorGetR(color)),
            SkIntToScalar(SkColorGetG(color)),
            SkIntToScalar(SkColorGetB(color)));
    }
    SkImageFilterLight(const SkPoint3& color)
        : fColor(color)
    {
    }
    SkImageFilterLight(SkReadBuffer& buffer)
    {
=======
    virtual SkLight* transform(const SkMatrix& matrix) const = 0;

    // Defined below SkLight's subclasses.
    void flattenLight(SkWriteBuffer& buffer) const;
    static SkLight* UnflattenLight(SkReadBuffer& buffer);

protected:
    SkLight(SkColor color)
      : fColor(SkIntToScalar(SkColorGetR(color)),
               SkIntToScalar(SkColorGetG(color)),
               SkIntToScalar(SkColorGetB(color))) {}
    SkLight(const SkPoint3& color)
      : fColor(color) {}
    SkLight(SkReadBuffer& buffer) {
>>>>>>> miniblink49
        fColor = readPoint3(buffer);
    }

    virtual void onFlattenLight(SkWriteBuffer& buffer) const = 0;

<<<<<<< HEAD
=======

>>>>>>> miniblink49
private:
    typedef SkRefCnt INHERITED;
    SkPoint3 fColor;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class SkDistantLight : public SkImageFilterLight {
public:
    SkDistantLight(const SkPoint3& direction, SkColor color)
        : INHERITED(color)
        , fDirection(direction)
    {
    }

    SkPoint3 surfaceToLight(int x, int y, int z, SkScalar surfaceScale) const
    {
        return fDirection;
    };
    const SkPoint3& lightColor(const SkPoint3&) const { return this->color(); }
    LightType type() const override { return kDistant_LightType; }
    const SkPoint3& direction() const { return fDirection; }
    GrGLLight* createGLLight() const override
    {
#if SK_SUPPORT_GPU
        return new GrGLDistantLight;
#else
        SkDEBUGFAIL("Should not call in GPU-less build");
        return nullptr;
=======
class SkDistantLight : public SkLight {
public:
    SkDistantLight(const SkPoint3& direction, SkColor color)
      : INHERITED(color), fDirection(direction) {
    }

    SkPoint3 surfaceToLight(int x, int y, int z, SkScalar surfaceScale) const {
        return fDirection;
    };
    SkPoint3 lightColor(const SkPoint3&) const { return color(); }
    LightType type() const override { return kDistant_LightType; }
    const SkPoint3& direction() const { return fDirection; }
    GrGLLight* createGLLight() const override {
#if SK_SUPPORT_GPU
        return SkNEW(GrGLDistantLight);
#else
        SkDEBUGFAIL("Should not call in GPU-less build");
        return NULL;
>>>>>>> miniblink49
#endif
    }
    bool requiresFragmentPosition() const override { return false; }

<<<<<<< HEAD
    bool isEqual(const SkImageFilterLight& other) const override
    {
=======
    bool isEqual(const SkLight& other) const override {
>>>>>>> miniblink49
        if (other.type() != kDistant_LightType) {
            return false;
        }

        const SkDistantLight& o = static_cast<const SkDistantLight&>(other);
<<<<<<< HEAD
        return INHERITED::isEqual(other) && fDirection == o.fDirection;
    }

    SkDistantLight(SkReadBuffer& buffer)
        : INHERITED(buffer)
    {
=======
        return INHERITED::isEqual(other) &&
               fDirection == o.fDirection;
    }

    SkDistantLight(SkReadBuffer& buffer) : INHERITED(buffer) {
>>>>>>> miniblink49
        fDirection = readPoint3(buffer);
    }

protected:
    SkDistantLight(const SkPoint3& direction, const SkPoint3& color)
<<<<<<< HEAD
        : INHERITED(color)
        , fDirection(direction)
    {
    }
    SkImageFilterLight* transform(const SkMatrix& matrix) const override
    {
        return new SkDistantLight(direction(), color());
    }
    void onFlattenLight(SkWriteBuffer& buffer) const override
    {
=======
      : INHERITED(color), fDirection(direction) {
    }
    SkLight* transform(const SkMatrix& matrix) const override {
        return new SkDistantLight(direction(), color());
    }
    void onFlattenLight(SkWriteBuffer& buffer) const override {
>>>>>>> miniblink49
        writePoint3(fDirection, buffer);
    }

private:
<<<<<<< HEAD
    SkPoint3 fDirection;

    typedef SkImageFilterLight INHERITED;
=======
    typedef SkLight INHERITED;
    SkPoint3 fDirection;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class SkPointLight : public SkImageFilterLight {
public:
    SkPointLight(const SkPoint3& location, SkColor color)
        : INHERITED(color)
        , fLocation(location)
    {
    }

    SkPoint3 surfaceToLight(int x, int y, int z, SkScalar surfaceScale) const
    {
        SkPoint3 direction = SkPoint3::Make(fLocation.fX - SkIntToScalar(x),
            fLocation.fY - SkIntToScalar(y),
            fLocation.fZ - SkScalarMul(SkIntToScalar(z), surfaceScale));
        fast_normalize(&direction);
        return direction;
    };
    const SkPoint3& lightColor(const SkPoint3&) const { return this->color(); }
    LightType type() const override { return kPoint_LightType; }
    const SkPoint3& location() const { return fLocation; }
    GrGLLight* createGLLight() const override
    {
#if SK_SUPPORT_GPU
        return new GrGLPointLight;
#else
        SkDEBUGFAIL("Should not call in GPU-less build");
        return nullptr;
#endif
    }
    bool requiresFragmentPosition() const override { return true; }
    bool isEqual(const SkImageFilterLight& other) const override
    {
=======
class SkPointLight : public SkLight {
public:
    SkPointLight(const SkPoint3& location, SkColor color)
     : INHERITED(color), fLocation(location) {}

    SkPoint3 surfaceToLight(int x, int y, int z, SkScalar surfaceScale) const {
        SkPoint3 direction(fLocation.fX - SkIntToScalar(x),
                           fLocation.fY - SkIntToScalar(y),
                           fLocation.fZ - SkScalarMul(SkIntToScalar(z), surfaceScale));
        direction.normalize();
        return direction;
    };
    SkPoint3 lightColor(const SkPoint3&) const { return color(); }
    LightType type() const override { return kPoint_LightType; }
    const SkPoint3& location() const { return fLocation; }
    GrGLLight* createGLLight() const override {
#if SK_SUPPORT_GPU
        return SkNEW(GrGLPointLight);
#else
        SkDEBUGFAIL("Should not call in GPU-less build");
        return NULL;
#endif
    }
    bool requiresFragmentPosition() const override { return true; }
    bool isEqual(const SkLight& other) const override {
>>>>>>> miniblink49
        if (other.type() != kPoint_LightType) {
            return false;
        }
        const SkPointLight& o = static_cast<const SkPointLight&>(other);
<<<<<<< HEAD
        return INHERITED::isEqual(other) && fLocation == o.fLocation;
    }
    SkImageFilterLight* transform(const SkMatrix& matrix) const override
    {
=======
        return INHERITED::isEqual(other) &&
               fLocation == o.fLocation;
    }
    SkLight* transform(const SkMatrix& matrix) const override {
>>>>>>> miniblink49
        SkPoint location2 = SkPoint::Make(fLocation.fX, fLocation.fY);
        matrix.mapPoints(&location2, 1);
        // Use X scale and Y scale on Z and average the result
        SkPoint locationZ = SkPoint::Make(fLocation.fZ, fLocation.fZ);
        matrix.mapVectors(&locationZ, 1);
<<<<<<< HEAD
        SkPoint3 location = SkPoint3::Make(location2.fX,
            location2.fY,
            SkScalarAve(locationZ.fX, locationZ.fY));
        return new SkPointLight(location, color());
    }

    SkPointLight(SkReadBuffer& buffer)
        : INHERITED(buffer)
    {
=======
        SkPoint3 location(location2.fX, location2.fY, SkScalarAve(locationZ.fX, locationZ.fY));
        return new SkPointLight(location, color());
    }

    SkPointLight(SkReadBuffer& buffer) : INHERITED(buffer) {
>>>>>>> miniblink49
        fLocation = readPoint3(buffer);
    }

protected:
    SkPointLight(const SkPoint3& location, const SkPoint3& color)
<<<<<<< HEAD
        : INHERITED(color)
        , fLocation(location)
    {
    }
    void onFlattenLight(SkWriteBuffer& buffer) const override
    {
=======
     : INHERITED(color), fLocation(location) {}
    void onFlattenLight(SkWriteBuffer& buffer) const override {
>>>>>>> miniblink49
        writePoint3(fLocation, buffer);
    }

private:
<<<<<<< HEAD
    SkPoint3 fLocation;

    typedef SkImageFilterLight INHERITED;
=======
    typedef SkLight INHERITED;
    SkPoint3 fLocation;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class SkSpotLight : public SkImageFilterLight {
public:
    SkSpotLight(const SkPoint3& location,
        const SkPoint3& target,
        SkScalar specularExponent,
        SkScalar cutoffAngle,
        SkColor color)
        : INHERITED(color)
        , fLocation(location)
        , fTarget(target)
        , fSpecularExponent(SkScalarPin(specularExponent, kSpecularExponentMin, kSpecularExponentMax))
    {
        fS = target - location;
        fast_normalize(&fS);
        fCosOuterConeAngle = SkScalarCos(SkDegreesToRadians(cutoffAngle));
        const SkScalar antiAliasThreshold = 0.016f;
        fCosInnerConeAngle = fCosOuterConeAngle + antiAliasThreshold;
        fConeScale = SkScalarInvert(antiAliasThreshold);
    }

    SkImageFilterLight* transform(const SkMatrix& matrix) const override
    {
=======
class SkSpotLight : public SkLight {
public:
    SkSpotLight(const SkPoint3& location,
                const SkPoint3& target,
                SkScalar specularExponent,
                SkScalar cutoffAngle,
                SkColor color)
     : INHERITED(color),
       fLocation(location),
       fTarget(target),
       fSpecularExponent(SkScalarPin(specularExponent, kSpecularExponentMin, kSpecularExponentMax))
    {
       fS = target - location;
       fS.normalize();
       fCosOuterConeAngle = SkScalarCos(SkDegreesToRadians(cutoffAngle));
       const SkScalar antiAliasThreshold = 0.016f;
       fCosInnerConeAngle = fCosOuterConeAngle + antiAliasThreshold;
       fConeScale = SkScalarInvert(antiAliasThreshold);
    }

    SkLight* transform(const SkMatrix& matrix) const override {
>>>>>>> miniblink49
        SkPoint location2 = SkPoint::Make(fLocation.fX, fLocation.fY);
        matrix.mapPoints(&location2, 1);
        // Use X scale and Y scale on Z and average the result
        SkPoint locationZ = SkPoint::Make(fLocation.fZ, fLocation.fZ);
        matrix.mapVectors(&locationZ, 1);
<<<<<<< HEAD
        SkPoint3 location = SkPoint3::Make(location2.fX, location2.fY,
            SkScalarAve(locationZ.fX, locationZ.fY));
=======
        SkPoint3 location(location2.fX, location2.fY, SkScalarAve(locationZ.fX, locationZ.fY));
>>>>>>> miniblink49
        SkPoint target2 = SkPoint::Make(fTarget.fX, fTarget.fY);
        matrix.mapPoints(&target2, 1);
        SkPoint targetZ = SkPoint::Make(fTarget.fZ, fTarget.fZ);
        matrix.mapVectors(&targetZ, 1);
<<<<<<< HEAD
        SkPoint3 target = SkPoint3::Make(target2.fX, target2.fY,
            SkScalarAve(targetZ.fX, targetZ.fY));
        SkPoint3 s = target - location;
        fast_normalize(&s);
        return new SkSpotLight(location,
            target,
            fSpecularExponent,
            fCosOuterConeAngle,
            fCosInnerConeAngle,
            fConeScale,
            s,
            color());
    }

    SkPoint3 surfaceToLight(int x, int y, int z, SkScalar surfaceScale) const
    {
        SkPoint3 direction = SkPoint3::Make(fLocation.fX - SkIntToScalar(x),
            fLocation.fY - SkIntToScalar(y),
            fLocation.fZ - SkScalarMul(SkIntToScalar(z), surfaceScale));
        fast_normalize(&direction);
        return direction;
    };
    SkPoint3 lightColor(const SkPoint3& surfaceToLight) const
    {
        SkScalar cosAngle = -surfaceToLight.dot(fS);
        SkScalar scale = 0;
        if (cosAngle >= fCosOuterConeAngle) {
            scale = SkScalarPow(cosAngle, fSpecularExponent);
            if (cosAngle < fCosInnerConeAngle) {
                scale = SkScalarMul(scale, cosAngle - fCosOuterConeAngle);
                scale *= fConeScale;
            }
        }
        return this->color().makeScale(scale);
    }
    GrGLLight* createGLLight() const override
    {
#if SK_SUPPORT_GPU
        return new GrGLSpotLight;
#else
        SkDEBUGFAIL("Should not call in GPU-less build");
        return nullptr;
=======
        SkPoint3 target(target2.fX, target2.fY, SkScalarAve(targetZ.fX, targetZ.fY));
        SkPoint3 s = target - location;
        s.normalize();
        return new SkSpotLight(location,
                               target,
                               fSpecularExponent,
                               fCosOuterConeAngle,
                               fCosInnerConeAngle,
                               fConeScale,
                               s,
                               color());
    }

    SkPoint3 surfaceToLight(int x, int y, int z, SkScalar surfaceScale) const {
        SkPoint3 direction(fLocation.fX - SkIntToScalar(x),
                           fLocation.fY - SkIntToScalar(y),
                           fLocation.fZ - SkScalarMul(SkIntToScalar(z), surfaceScale));
        direction.normalize();
        return direction;
    };
    SkPoint3 lightColor(const SkPoint3& surfaceToLight) const {
        SkScalar cosAngle = -surfaceToLight.dot(fS);
        if (cosAngle < fCosOuterConeAngle) {
            return SkPoint3(0, 0, 0);
        }
        SkScalar scale = SkScalarPow(cosAngle, fSpecularExponent);
        if (cosAngle < fCosInnerConeAngle) {
            scale = SkScalarMul(scale, cosAngle - fCosOuterConeAngle);
            return color() * SkScalarMul(scale, fConeScale);
        }
        return color() * scale;
    }
    GrGLLight* createGLLight() const override {
#if SK_SUPPORT_GPU
        return SkNEW(GrGLSpotLight);
#else
        SkDEBUGFAIL("Should not call in GPU-less build");
        return NULL;
>>>>>>> miniblink49
#endif
    }
    bool requiresFragmentPosition() const override { return true; }
    LightType type() const override { return kSpot_LightType; }
    const SkPoint3& location() const { return fLocation; }
    const SkPoint3& target() const { return fTarget; }
    SkScalar specularExponent() const { return fSpecularExponent; }
    SkScalar cosInnerConeAngle() const { return fCosInnerConeAngle; }
    SkScalar cosOuterConeAngle() const { return fCosOuterConeAngle; }
    SkScalar coneScale() const { return fConeScale; }
    const SkPoint3& s() const { return fS; }

<<<<<<< HEAD
    SkSpotLight(SkReadBuffer& buffer)
        : INHERITED(buffer)
    {
=======
    SkSpotLight(SkReadBuffer& buffer) : INHERITED(buffer) {
>>>>>>> miniblink49
        fLocation = readPoint3(buffer);
        fTarget = readPoint3(buffer);
        fSpecularExponent = buffer.readScalar();
        fCosOuterConeAngle = buffer.readScalar();
        fCosInnerConeAngle = buffer.readScalar();
        fConeScale = buffer.readScalar();
        fS = readPoint3(buffer);
<<<<<<< HEAD
        buffer.validate(SkScalarIsFinite(fSpecularExponent) && SkScalarIsFinite(fCosOuterConeAngle) && SkScalarIsFinite(fCosInnerConeAngle) && SkScalarIsFinite(fConeScale));
    }

protected:
    SkSpotLight(const SkPoint3& location,
        const SkPoint3& target,
        SkScalar specularExponent,
        SkScalar cosOuterConeAngle,
        SkScalar cosInnerConeAngle,
        SkScalar coneScale,
        const SkPoint3& s,
        const SkPoint3& color)
        : INHERITED(color)
        , fLocation(location)
        , fTarget(target)
        , fSpecularExponent(specularExponent)
        , fCosOuterConeAngle(cosOuterConeAngle)
        , fCosInnerConeAngle(cosInnerConeAngle)
        , fConeScale(coneScale)
        , fS(s)
    {
    }
    void onFlattenLight(SkWriteBuffer& buffer) const override
    {
=======
        buffer.validate(SkScalarIsFinite(fSpecularExponent) &&
                        SkScalarIsFinite(fCosOuterConeAngle) &&
                        SkScalarIsFinite(fCosInnerConeAngle) &&
                        SkScalarIsFinite(fConeScale));
    }
protected:
    SkSpotLight(const SkPoint3& location,
                const SkPoint3& target,
                SkScalar specularExponent,
                SkScalar cosOuterConeAngle,
                SkScalar cosInnerConeAngle,
                SkScalar coneScale,
                const SkPoint3& s,
                const SkPoint3& color)
     : INHERITED(color),
       fLocation(location),
       fTarget(target),
       fSpecularExponent(specularExponent),
       fCosOuterConeAngle(cosOuterConeAngle),
       fCosInnerConeAngle(cosInnerConeAngle),
       fConeScale(coneScale),
       fS(s)
    {
    }
    void onFlattenLight(SkWriteBuffer& buffer) const override {
>>>>>>> miniblink49
        writePoint3(fLocation, buffer);
        writePoint3(fTarget, buffer);
        buffer.writeScalar(fSpecularExponent);
        buffer.writeScalar(fCosOuterConeAngle);
        buffer.writeScalar(fCosInnerConeAngle);
        buffer.writeScalar(fConeScale);
        writePoint3(fS, buffer);
    }

<<<<<<< HEAD
    bool isEqual(const SkImageFilterLight& other) const override
    {
=======
    bool isEqual(const SkLight& other) const override {
>>>>>>> miniblink49
        if (other.type() != kSpot_LightType) {
            return false;
        }

        const SkSpotLight& o = static_cast<const SkSpotLight&>(other);
<<<<<<< HEAD
        return INHERITED::isEqual(other) && fLocation == o.fLocation && fTarget == o.fTarget && fSpecularExponent == o.fSpecularExponent && fCosOuterConeAngle == o.fCosOuterConeAngle;
=======
        return INHERITED::isEqual(other) &&
               fLocation == o.fLocation &&
               fTarget == o.fTarget &&
               fSpecularExponent == o.fSpecularExponent &&
               fCosOuterConeAngle == o.fCosOuterConeAngle;
>>>>>>> miniblink49
    }

private:
    static const SkScalar kSpecularExponentMin;
    static const SkScalar kSpecularExponentMax;

<<<<<<< HEAD
=======
    typedef SkLight INHERITED;
>>>>>>> miniblink49
    SkPoint3 fLocation;
    SkPoint3 fTarget;
    SkScalar fSpecularExponent;
    SkScalar fCosOuterConeAngle;
    SkScalar fCosInnerConeAngle;
    SkScalar fConeScale;
    SkPoint3 fS;
<<<<<<< HEAD

    typedef SkImageFilterLight INHERITED;
=======
>>>>>>> miniblink49
};

// According to the spec, the specular term should be in the range [1, 128] :
// http://www.w3.org/TR/SVG/filters.html#feSpecularLightingSpecularExponentAttribute
const SkScalar SkSpotLight::kSpecularExponentMin = 1.0f;
const SkScalar SkSpotLight::kSpecularExponentMax = 128.0f;

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkImageFilterLight::flattenLight(SkWriteBuffer& buffer) const
{
=======
void SkLight::flattenLight(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    // Write type first, then baseclass, then subclass.
    buffer.writeInt(this->type());
    writePoint3(fColor, buffer);
    this->onFlattenLight(buffer);
}

<<<<<<< HEAD
/*static*/ SkImageFilterLight* SkImageFilterLight::UnflattenLight(SkReadBuffer& buffer)
{
    // Read type first.
    const SkImageFilterLight::LightType type = (SkImageFilterLight::LightType)buffer.readInt();
    switch (type) {
    // Each of these constructors must first call SkLight's, so we'll read the baseclass
    // then subclass, same order as flattenLight.
    case SkImageFilterLight::kDistant_LightType:
        return new SkDistantLight(buffer);
    case SkImageFilterLight::kPoint_LightType:
        return new SkPointLight(buffer);
    case SkImageFilterLight::kSpot_LightType:
        return new SkSpotLight(buffer);
    default:
        SkDEBUGFAIL("Unknown LightType.");
        buffer.validate(false);
        return nullptr;
=======
/*static*/ SkLight* SkLight::UnflattenLight(SkReadBuffer& buffer) {
    // Read type first.
    const SkLight::LightType type = (SkLight::LightType)buffer.readInt();
    switch (type) {
        // Each of these constructors must first call SkLight's, so we'll read the baseclass
        // then subclass, same order as flattenLight.
        case SkLight::kDistant_LightType: return SkNEW_ARGS(SkDistantLight, (buffer));
        case SkLight::kPoint_LightType:   return SkNEW_ARGS(SkPointLight, (buffer));
        case SkLight::kSpot_LightType:    return SkNEW_ARGS(SkSpotLight, (buffer));
        default:
            SkDEBUGFAIL("Unknown LightType.");
            buffer.validate(false);
            return NULL;
>>>>>>> miniblink49
    }
}
///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkLightingImageFilter::SkLightingImageFilter(sk_sp<SkImageFilterLight> light,
    SkScalar surfaceScale,
    sk_sp<SkImageFilter> input, const CropRect* cropRect)
    : INHERITED(&input, 1, cropRect)
    , fLight(std::move(light))
    , fSurfaceScale(surfaceScale / 255)
{
}

SkLightingImageFilter::~SkLightingImageFilter() { }

sk_sp<SkImageFilter> SkLightingImageFilter::MakeDistantLitDiffuse(const SkPoint3& direction,
    SkColor lightColor,
    SkScalar surfaceScale,
    SkScalar kd,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilterLight> light(new SkDistantLight(direction, lightColor));
    return SkDiffuseLightingImageFilter::Make(std::move(light), surfaceScale, kd,
        std::move(input), cropRect);
}

sk_sp<SkImageFilter> SkLightingImageFilter::MakePointLitDiffuse(const SkPoint3& location,
    SkColor lightColor,
    SkScalar surfaceScale,
    SkScalar kd,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilterLight> light(new SkPointLight(location, lightColor));
    return SkDiffuseLightingImageFilter::Make(std::move(light), surfaceScale, kd,
        std::move(input), cropRect);
}

sk_sp<SkImageFilter> SkLightingImageFilter::MakeSpotLitDiffuse(const SkPoint3& location,
    const SkPoint3& target,
    SkScalar specularExponent,
    SkScalar cutoffAngle,
    SkColor lightColor,
    SkScalar surfaceScale,
    SkScalar kd,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilterLight> light(
        new SkSpotLight(location, target, specularExponent, cutoffAngle, lightColor));
    return SkDiffuseLightingImageFilter::Make(std::move(light), surfaceScale, kd,
        std::move(input), cropRect);
}

sk_sp<SkImageFilter> SkLightingImageFilter::MakeDistantLitSpecular(const SkPoint3& direction,
    SkColor lightColor,
    SkScalar surfaceScale,
    SkScalar ks,
    SkScalar shine,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilterLight> light(new SkDistantLight(direction, lightColor));
    return SkSpecularLightingImageFilter::Make(std::move(light), surfaceScale, ks, shine,
        std::move(input), cropRect);
}

sk_sp<SkImageFilter> SkLightingImageFilter::MakePointLitSpecular(const SkPoint3& location,
    SkColor lightColor,
    SkScalar surfaceScale,
    SkScalar ks,
    SkScalar shine,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilterLight> light(new SkPointLight(location, lightColor));
    return SkSpecularLightingImageFilter::Make(std::move(light), surfaceScale, ks, shine,
        std::move(input), cropRect);
}

sk_sp<SkImageFilter> SkLightingImageFilter::MakeSpotLitSpecular(const SkPoint3& location,
    const SkPoint3& target,
    SkScalar specularExponent,
    SkScalar cutoffAngle,
    SkColor lightColor,
    SkScalar surfaceScale,
    SkScalar ks,
    SkScalar shine,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    sk_sp<SkImageFilterLight> light(
        new SkSpotLight(location, target, specularExponent, cutoffAngle, lightColor));
    return SkSpecularLightingImageFilter::Make(std::move(light), surfaceScale, ks, shine,
        std::move(input), cropRect);
}

void SkLightingImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
SkLightingImageFilter::SkLightingImageFilter(SkLight* light, SkScalar surfaceScale,
                                             SkImageFilter* input, const CropRect* cropRect)
  : INHERITED(1, &input, cropRect)
  , fLight(SkRef(light))
  , fSurfaceScale(surfaceScale / 255)
{}

SkImageFilter* SkLightingImageFilter::CreateDistantLitDiffuse(const SkPoint3& direction,
                                                              SkColor lightColor,
                                                              SkScalar surfaceScale,
                                                              SkScalar kd,
                                                              SkImageFilter* input,
                                                              const CropRect* cropRect) {
    SkAutoTUnref<SkLight> light(SkNEW_ARGS(SkDistantLight, (direction, lightColor)));
    return SkDiffuseLightingImageFilter::Create(light, surfaceScale, kd, input, cropRect);
}

SkImageFilter* SkLightingImageFilter::CreatePointLitDiffuse(const SkPoint3& location,
                                                            SkColor lightColor,
                                                            SkScalar surfaceScale,
                                                            SkScalar kd,
                                                            SkImageFilter* input,
                                                            const CropRect* cropRect) {
    SkAutoTUnref<SkLight> light(SkNEW_ARGS(SkPointLight, (location, lightColor)));
    return SkDiffuseLightingImageFilter::Create(light, surfaceScale, kd, input, cropRect);
}

SkImageFilter* SkLightingImageFilter::CreateSpotLitDiffuse(const SkPoint3& location,
                                                           const SkPoint3& target,
                                                           SkScalar specularExponent,
                                                           SkScalar cutoffAngle,
                                                           SkColor lightColor,
                                                           SkScalar surfaceScale,
                                                           SkScalar kd,
                                                           SkImageFilter* input,
                                                           const CropRect* cropRect) {
    SkAutoTUnref<SkLight> light(SkNEW_ARGS(SkSpotLight, (location, target, specularExponent,
                                                         cutoffAngle, lightColor)));
    return SkDiffuseLightingImageFilter::Create(light, surfaceScale, kd, input, cropRect);
}

SkImageFilter* SkLightingImageFilter::CreateDistantLitSpecular(const SkPoint3& direction,
                                                               SkColor lightColor,
                                                               SkScalar surfaceScale,
                                                               SkScalar ks,
                                                               SkScalar shine,
                                                               SkImageFilter* input,
                                                               const CropRect* cropRect) {
    SkAutoTUnref<SkLight> light(SkNEW_ARGS(SkDistantLight, (direction, lightColor)));
    return SkSpecularLightingImageFilter::Create(light, surfaceScale, ks, shine, input, cropRect);
}

SkImageFilter* SkLightingImageFilter::CreatePointLitSpecular(const SkPoint3& location,
                                                             SkColor lightColor,
                                                             SkScalar surfaceScale,
                                                             SkScalar ks,
                                                             SkScalar shine,
                                                             SkImageFilter* input,
                                                             const CropRect* cropRect) {
    SkAutoTUnref<SkLight> light(SkNEW_ARGS(SkPointLight, (location, lightColor)));
    return SkSpecularLightingImageFilter::Create(light, surfaceScale, ks, shine, input, cropRect);
}

SkImageFilter* SkLightingImageFilter::CreateSpotLitSpecular(const SkPoint3& location,
                                                            const SkPoint3& target,
                                                            SkScalar specularExponent,
                                                            SkScalar cutoffAngle,
                                                            SkColor lightColor,
                                                            SkScalar surfaceScale,
                                                            SkScalar ks,
                                                            SkScalar shine,
                                                            SkImageFilter* input,
                                                            const CropRect* cropRect) {
    SkAutoTUnref<SkLight> light(SkNEW_ARGS(SkSpotLight, (location, target, specularExponent,
                                                         cutoffAngle, lightColor)));
    return SkSpecularLightingImageFilter::Create(light, surfaceScale, ks, shine, input, cropRect);
}

SkLightingImageFilter::~SkLightingImageFilter() {}

void SkLightingImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    fLight->flattenLight(buffer);
    buffer.writeScalar(fSurfaceScale * 255);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkImageFilter> SkDiffuseLightingImageFilter::Make(sk_sp<SkImageFilterLight> light,
    SkScalar surfaceScale,
    SkScalar kd,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (!light) {
        return nullptr;
    }
    if (!SkScalarIsFinite(surfaceScale) || !SkScalarIsFinite(kd)) {
        return nullptr;
=======
SkImageFilter* SkDiffuseLightingImageFilter::Create(SkLight* light, SkScalar surfaceScale,
                                    SkScalar kd, SkImageFilter* input, const CropRect* cropRect) {
    if (NULL == light) {
        return NULL;
    }
    if (!SkScalarIsFinite(surfaceScale) || !SkScalarIsFinite(kd)) {
        return NULL;
>>>>>>> miniblink49
    }
    // According to the spec, kd can be any non-negative number :
    // http://www.w3.org/TR/SVG/filters.html#feDiffuseLightingElement
    if (kd < 0) {
<<<<<<< HEAD
        return nullptr;
    }
    return sk_sp<SkImageFilter>(new SkDiffuseLightingImageFilter(std::move(light), surfaceScale,
        kd, std::move(input), cropRect));
}

SkDiffuseLightingImageFilter::SkDiffuseLightingImageFilter(sk_sp<SkImageFilterLight> light,
    SkScalar surfaceScale,
    SkScalar kd,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
    : INHERITED(std::move(light), surfaceScale, std::move(input), cropRect)
    , fKD(kd)
{
}

sk_sp<SkFlattenable> SkDiffuseLightingImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    sk_sp<SkImageFilterLight> light(SkImageFilterLight::UnflattenLight(buffer));
    SkScalar surfaceScale = buffer.readScalar();
    SkScalar kd = buffer.readScalar();
    return Make(std::move(light), surfaceScale, kd, common.getInput(0), &common.cropRect());
}

void SkDiffuseLightingImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
        return NULL;
    }
    return SkNEW_ARGS(SkDiffuseLightingImageFilter, (light, surfaceScale, kd, input, cropRect));
}

SkDiffuseLightingImageFilter::SkDiffuseLightingImageFilter(SkLight* light,
                                                           SkScalar surfaceScale,
                                                           SkScalar kd,
                                                           SkImageFilter* input,
                                                           const CropRect* cropRect)
  : INHERITED(light, surfaceScale, input, cropRect),
    fKD(kd)
{
}

SkFlattenable* SkDiffuseLightingImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkAutoTUnref<SkLight> light(SkLight::UnflattenLight(buffer));
    SkScalar surfaceScale = buffer.readScalar();
    SkScalar kd = buffer.readScalar();
    return Create(light, surfaceScale, kd, common.getInput(0), &common.cropRect());
}

void SkDiffuseLightingImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeScalar(fKD);
}

<<<<<<< HEAD
sk_sp<SkSpecialImage> SkDiffuseLightingImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));
    if (!input) {
        return nullptr;
    }

    const SkIRect inputBounds = SkIRect::MakeXYWH(inputOffset.x(), inputOffset.y(),
        input->width(), input->height());
    SkIRect bounds;
    if (!this->applyCropRect(ctx, inputBounds, &bounds)) {
        return nullptr;
    }

    offset->fX = bounds.left();
    offset->fY = bounds.top();
    bounds.offset(-inputOffset);

#if SK_SUPPORT_GPU
    if (source->isTextureBacked()) {
        SkMatrix matrix(ctx.ctm());
        matrix.postTranslate(SkIntToScalar(-offset->fX), SkIntToScalar(-offset->fY));

        return this->filterImageGPU(source, input.get(), bounds, matrix);
    }
#endif

    if (bounds.width() < 2 || bounds.height() < 2) {
        return nullptr;
    }

    SkBitmap inputBM;

    if (!input->getROPixels(&inputBM)) {
        return nullptr;
    }

    if (inputBM.colorType() != kN32_SkColorType) {
        return nullptr;
    }

    SkAutoLockPixels alp(inputBM);
    if (!inputBM.getPixels()) {
        return nullptr;
    }

    const SkImageInfo info = SkImageInfo::MakeN32Premul(bounds.width(), bounds.height());

    SkBitmap dst;
    if (!dst.tryAllocPixels(info)) {
        return nullptr;
    }

    SkAutoLockPixels dstLock(dst);

    SkMatrix matrix(ctx.ctm());
    matrix.postTranslate(SkIntToScalar(-inputOffset.x()), SkIntToScalar(-inputOffset.y()));

    sk_sp<SkImageFilterLight> transformedLight(light()->transform(matrix));

    DiffuseLightingType lightingType(fKD);
    switch (transformedLight->type()) {
    case SkImageFilterLight::kDistant_LightType:
        lightBitmap<DiffuseLightingType, SkDistantLight>(lightingType,
            transformedLight.get(),
            inputBM,
            &dst,
            surfaceScale(),
            bounds);
        break;
    case SkImageFilterLight::kPoint_LightType:
        lightBitmap<DiffuseLightingType, SkPointLight>(lightingType,
            transformedLight.get(),
            inputBM,
            &dst,
            surfaceScale(),
            bounds);
        break;
    case SkImageFilterLight::kSpot_LightType:
        lightBitmap<DiffuseLightingType, SkSpotLight>(lightingType,
            transformedLight.get(),
            inputBM,
            &dst,
            surfaceScale(),
            bounds);
        break;
    }

    return SkSpecialImage::MakeFromRaster(SkIRect::MakeWH(bounds.width(), bounds.height()),
        dst);
}

#ifndef SK_IGNORE_TO_STRING
void SkDiffuseLightingImageFilter::toString(SkString* str) const
{
=======
bool SkDiffuseLightingImageFilter::onFilterImage(Proxy* proxy,
                                                 const SkBitmap& source,
                                                 const Context& ctx,
                                                 SkBitmap* dst,
                                                 SkIPoint* offset) const {
    SkImageFilter* input = getInput(0);
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (input && !input->filterImage(proxy, source, ctx, &src, &srcOffset)) {
        return false;
    }

    if (src.colorType() != kN32_SkColorType) {
        return false;
    }
    SkIRect bounds;
    if (!this->applyCropRect(ctx, proxy, src, &srcOffset, &bounds, &src)) {
        return false;
    }

    if (bounds.width() < 2 || bounds.height() < 2) {
        return false;
    }

    SkAutoLockPixels alp(src);
    if (!src.getPixels()) {
        return false;
    }

    if (!dst->tryAllocPixels(src.info().makeWH(bounds.width(), bounds.height()))) {
        return false;
    }

    SkAutoTUnref<SkLight> transformedLight(light()->transform(ctx.ctm()));

    DiffuseLightingType lightingType(fKD);
    offset->fX = bounds.left();
    offset->fY = bounds.top();
    bounds.offset(-srcOffset);
    switch (transformedLight->type()) {
        case SkLight::kDistant_LightType:
            lightBitmap<DiffuseLightingType, SkDistantLight>(lightingType,
                                                             transformedLight,
                                                             src,
                                                             dst,
                                                             surfaceScale(),
                                                             bounds);
            break;
        case SkLight::kPoint_LightType:
            lightBitmap<DiffuseLightingType, SkPointLight>(lightingType,
                                                           transformedLight,
                                                           src,
                                                           dst,
                                                           surfaceScale(),
                                                           bounds);
            break;
        case SkLight::kSpot_LightType:
            lightBitmap<DiffuseLightingType, SkSpotLight>(lightingType,
                                                          transformedLight,
                                                          src,
                                                          dst,
                                                          surfaceScale(),
                                                          bounds);
            break;
    }

    return true;
}

#ifndef SK_IGNORE_TO_STRING
void SkDiffuseLightingImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkDiffuseLightingImageFilter: (");
    str->appendf("kD: %f\n", fKD);
    str->append(")");
}
#endif

#if SK_SUPPORT_GPU
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> SkDiffuseLightingImageFilter::makeFragmentProcessor(
    GrTexture* texture,
    const SkMatrix& matrix,
    const SkIRect* srcBounds,
    BoundaryMode boundaryMode) const
{
    SkScalar scale = SkScalarMul(this->surfaceScale(), SkIntToScalar(255));
    return GrDiffuseLightingEffect::Make(texture, this->light(), scale, matrix, this->kd(),
        boundaryMode, srcBounds);
=======
GrFragmentProcessor* SkDiffuseLightingImageFilter::getFragmentProcessor(
                                                   GrProcessorDataManager* procDataManager,
                                                   GrTexture* texture,
                                                   const SkMatrix& matrix,
                                                   const SkIRect&,
                                                   BoundaryMode boundaryMode
) const {
    SkScalar scale = SkScalarMul(this->surfaceScale(), SkIntToScalar(255));
    return GrDiffuseLightingEffect::Create(procDataManager, texture, this->light(), scale, matrix,
                                           this->kd(), boundaryMode);
>>>>>>> miniblink49
}
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkImageFilter> SkSpecularLightingImageFilter::Make(sk_sp<SkImageFilterLight> light,
    SkScalar surfaceScale,
    SkScalar ks,
    SkScalar shininess,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (!light) {
        return nullptr;
    }
    if (!SkScalarIsFinite(surfaceScale) || !SkScalarIsFinite(ks) || !SkScalarIsFinite(shininess)) {
        return nullptr;
=======
SkImageFilter* SkSpecularLightingImageFilter::Create(SkLight* light, SkScalar surfaceScale,
                SkScalar ks, SkScalar shininess, SkImageFilter* input, const CropRect* cropRect) {
    if (NULL == light) {
        return NULL;
    }
    if (!SkScalarIsFinite(surfaceScale) || !SkScalarIsFinite(ks) || !SkScalarIsFinite(shininess)) {
        return NULL;
>>>>>>> miniblink49
    }
    // According to the spec, ks can be any non-negative number :
    // http://www.w3.org/TR/SVG/filters.html#feSpecularLightingElement
    if (ks < 0) {
<<<<<<< HEAD
        return nullptr;
    }
    return sk_sp<SkImageFilter>(new SkSpecularLightingImageFilter(std::move(light), surfaceScale,
        ks, shininess,
        std::move(input), cropRect));
}

SkSpecularLightingImageFilter::SkSpecularLightingImageFilter(sk_sp<SkImageFilterLight> light,
    SkScalar surfaceScale,
    SkScalar ks,
    SkScalar shininess,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
    : INHERITED(std::move(light), surfaceScale, std::move(input), cropRect)
    , fKS(ks)
    , fShininess(shininess)
{
}

sk_sp<SkFlattenable> SkSpecularLightingImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    sk_sp<SkImageFilterLight> light(SkImageFilterLight::UnflattenLight(buffer));
    SkScalar surfaceScale = buffer.readScalar();
    SkScalar ks = buffer.readScalar();
    SkScalar shine = buffer.readScalar();
    return Make(std::move(light), surfaceScale, ks, shine, common.getInput(0),
        &common.cropRect());
}

void SkSpecularLightingImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
        return NULL;
    }
    return SkNEW_ARGS(SkSpecularLightingImageFilter,
                      (light, surfaceScale, ks, shininess, input, cropRect));
}

SkSpecularLightingImageFilter::SkSpecularLightingImageFilter(SkLight* light,
                                                             SkScalar surfaceScale,
                                                             SkScalar ks,
                                                             SkScalar shininess,
                                                             SkImageFilter* input,
                                                             const CropRect* cropRect)
  : INHERITED(light, surfaceScale, input, cropRect),
    fKS(ks),
    fShininess(shininess)
{
}

SkFlattenable* SkSpecularLightingImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    SkAutoTUnref<SkLight> light(SkLight::UnflattenLight(buffer));
    SkScalar surfaceScale = buffer.readScalar();
    SkScalar ks = buffer.readScalar();
    SkScalar shine = buffer.readScalar();
    return Create(light, surfaceScale, ks, shine, common.getInput(0), &common.cropRect());
}

void SkSpecularLightingImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeScalar(fKS);
    buffer.writeScalar(fShininess);
}

<<<<<<< HEAD
sk_sp<SkSpecialImage> SkSpecularLightingImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));
    if (!input) {
        return nullptr;
    }

    const SkIRect inputBounds = SkIRect::MakeXYWH(inputOffset.x(), inputOffset.y(),
        input->width(), input->height());
    SkIRect bounds;
    if (!this->applyCropRect(ctx, inputBounds, &bounds)) {
        return nullptr;
    }

    offset->fX = bounds.left();
    offset->fY = bounds.top();
    bounds.offset(-inputOffset);

#if SK_SUPPORT_GPU
    if (source->isTextureBacked()) {
        SkMatrix matrix(ctx.ctm());
        matrix.postTranslate(SkIntToScalar(-offset->fX), SkIntToScalar(-offset->fY));

        return this->filterImageGPU(source, input.get(), bounds, matrix);
    }
#endif

    if (bounds.width() < 2 || bounds.height() < 2) {
        return nullptr;
    }

    SkBitmap inputBM;

    if (!input->getROPixels(&inputBM)) {
        return nullptr;
    }

    if (inputBM.colorType() != kN32_SkColorType) {
        return nullptr;
    }

    SkAutoLockPixels alp(inputBM);
    if (!inputBM.getPixels()) {
        return nullptr;
    }

    const SkImageInfo info = SkImageInfo::MakeN32Premul(bounds.width(), bounds.height());

    SkBitmap dst;
    if (!dst.tryAllocPixels(info)) {
        return nullptr;
    }

    SkAutoLockPixels dstLock(dst);

    SpecularLightingType lightingType(fKS, fShininess);

    SkMatrix matrix(ctx.ctm());
    matrix.postTranslate(SkIntToScalar(-inputOffset.x()), SkIntToScalar(-inputOffset.y()));

    sk_sp<SkImageFilterLight> transformedLight(light()->transform(matrix));

    switch (transformedLight->type()) {
    case SkImageFilterLight::kDistant_LightType:
        lightBitmap<SpecularLightingType, SkDistantLight>(lightingType,
            transformedLight.get(),
            inputBM,
            &dst,
            surfaceScale(),
            bounds);
        break;
    case SkImageFilterLight::kPoint_LightType:
        lightBitmap<SpecularLightingType, SkPointLight>(lightingType,
            transformedLight.get(),
            inputBM,
            &dst,
            surfaceScale(),
            bounds);
        break;
    case SkImageFilterLight::kSpot_LightType:
        lightBitmap<SpecularLightingType, SkSpotLight>(lightingType,
            transformedLight.get(),
            inputBM,
            &dst,
            surfaceScale(),
            bounds);
        break;
    }

    return SkSpecialImage::MakeFromRaster(SkIRect::MakeWH(bounds.width(), bounds.height()), dst);
}

#ifndef SK_IGNORE_TO_STRING
void SkSpecularLightingImageFilter::toString(SkString* str) const
{
=======
bool SkSpecularLightingImageFilter::onFilterImage(Proxy* proxy,
                                                  const SkBitmap& source,
                                                  const Context& ctx,
                                                  SkBitmap* dst,
                                                  SkIPoint* offset) const {
    SkImageFilter* input = getInput(0);
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (input && !input->filterImage(proxy, source, ctx, &src, &srcOffset)) {
        return false;
    }

    if (src.colorType() != kN32_SkColorType) {
        return false;
    }

    SkIRect bounds;
    if (!this->applyCropRect(ctx, proxy, src, &srcOffset, &bounds, &src)) {
        return false;
    }

    if (bounds.width() < 2 || bounds.height() < 2) {
        return false;
    }

    SkAutoLockPixels alp(src);
    if (!src.getPixels()) {
        return false;
    }

    if (!dst->tryAllocPixels(src.info().makeWH(bounds.width(), bounds.height()))) {
        return false;
    }

    SpecularLightingType lightingType(fKS, fShininess);
    offset->fX = bounds.left();
    offset->fY = bounds.top();
    bounds.offset(-srcOffset);
    SkAutoTUnref<SkLight> transformedLight(light()->transform(ctx.ctm()));
    switch (transformedLight->type()) {
        case SkLight::kDistant_LightType:
            lightBitmap<SpecularLightingType, SkDistantLight>(lightingType,
                                                              transformedLight,
                                                              src,
                                                              dst,
                                                              surfaceScale(),
                                                              bounds);
            break;
        case SkLight::kPoint_LightType:
            lightBitmap<SpecularLightingType, SkPointLight>(lightingType,
                                                            transformedLight,
                                                            src,
                                                            dst,
                                                            surfaceScale(),
                                                            bounds);
            break;
        case SkLight::kSpot_LightType:
            lightBitmap<SpecularLightingType, SkSpotLight>(lightingType,
                                                           transformedLight,
                                                           src,
                                                           dst,
                                                           surfaceScale(),
                                                           bounds);
            break;
    }
    return true;
}

#ifndef SK_IGNORE_TO_STRING
void SkSpecularLightingImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkSpecularLightingImageFilter: (");
    str->appendf("kS: %f shininess: %f", fKS, fShininess);
    str->append(")");
}
#endif

#if SK_SUPPORT_GPU
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> SkSpecularLightingImageFilter::makeFragmentProcessor(
    GrTexture* texture,
    const SkMatrix& matrix,
    const SkIRect* srcBounds,
    BoundaryMode boundaryMode) const
{
    SkScalar scale = SkScalarMul(this->surfaceScale(), SkIntToScalar(255));
    return GrSpecularLightingEffect::Make(texture, this->light(), scale, matrix, this->ks(),
        this->shininess(), boundaryMode, srcBounds);
=======
GrFragmentProcessor* SkSpecularLightingImageFilter::getFragmentProcessor(
                                                    GrProcessorDataManager* procDataManager,
                                                    GrTexture* texture,
                                                    const SkMatrix& matrix,
                                                    const SkIRect&,
                                                    BoundaryMode boundaryMode) const {
    SkScalar scale = SkScalarMul(this->surfaceScale(), SkIntToScalar(255));
    return GrSpecularLightingEffect::Create(procDataManager, texture, this->light(), scale, matrix,
                                            this->ks(), this->shininess(), boundaryMode);
>>>>>>> miniblink49
}
#endif

///////////////////////////////////////////////////////////////////////////////

#if SK_SUPPORT_GPU

namespace {
<<<<<<< HEAD
SkPoint3 random_point3(SkRandom* random)
{
    return SkPoint3::Make(SkScalarToFloat(random->nextSScalar1()),
        SkScalarToFloat(random->nextSScalar1()),
        SkScalarToFloat(random->nextSScalar1()));
}

SkImageFilterLight* create_random_light(SkRandom* random)
{
    int type = random->nextULessThan(3);
    switch (type) {
    case 0: {
        return new SkDistantLight(random_point3(random), random->nextU());
    }
    case 1: {
        return new SkPointLight(random_point3(random), random->nextU());
    }
    case 2: {
        return new SkSpotLight(random_point3(random), random_point3(random),
            random->nextUScalar1(), random->nextUScalar1(), random->nextU());
    }
    default:
        SkFAIL("Unexpected value.");
        return nullptr;
=======
SkPoint3 random_point3(SkRandom* random) {
    return SkPoint3(SkScalarToFloat(random->nextSScalar1()),
                    SkScalarToFloat(random->nextSScalar1()),
                    SkScalarToFloat(random->nextSScalar1()));
}

SkLight* create_random_light(SkRandom* random) {
    int type = random->nextULessThan(3);
    switch (type) {
        case 0: {
            return SkNEW_ARGS(SkDistantLight, (random_point3(random), random->nextU()));
        }
        case 1: {
            return SkNEW_ARGS(SkPointLight, (random_point3(random), random->nextU()));
        }
        case 2: {
            return SkNEW_ARGS(SkSpotLight, (random_point3(random),
                                            random_point3(random),
                                            random->nextUScalar1(),
                                            random->nextUScalar1(),
                                            random->nextU()));
        }
        default:
            SkFAIL("Unexpected value.");
            return NULL;
>>>>>>> miniblink49
    }
}

SkString emitNormalFunc(BoundaryMode mode,
<<<<<<< HEAD
    const char* pointToNormalName,
    const char* sobelFuncName)
{
=======
                        const char* pointToNormalName,
                        const char* sobelFuncName) {
>>>>>>> miniblink49
    SkString result;
    switch (mode) {
    case kTopLeft_BoundaryMode:
        result.printf("\treturn %s(%s(0.0, 0.0, m[4], m[5], m[7], m[8], %g),\n"
                      "\t          %s(0.0, 0.0, m[4], m[7], m[5], m[8], %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gTwoThirds,
            sobelFuncName, gTwoThirds);
=======
                      pointToNormalName, sobelFuncName, gTwoThirds,
                                         sobelFuncName, gTwoThirds);
>>>>>>> miniblink49
        break;
    case kTop_BoundaryMode:
        result.printf("\treturn %s(%s(0.0, 0.0, m[3], m[5], m[6], m[8], %g),\n"
                      "\t          %s(0.0, 0.0, m[4], m[7], m[5], m[8], %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gOneThird,
            sobelFuncName, gOneHalf);
=======
                      pointToNormalName, sobelFuncName, gOneThird,
                                         sobelFuncName, gOneHalf);
>>>>>>> miniblink49
        break;
    case kTopRight_BoundaryMode:
        result.printf("\treturn %s(%s( 0.0,  0.0, m[3], m[4], m[6], m[7], %g),\n"
                      "\t          %s(m[3], m[6], m[4], m[7],  0.0,  0.0, %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gTwoThirds,
            sobelFuncName, gTwoThirds);
=======
                      pointToNormalName, sobelFuncName, gTwoThirds,
                                         sobelFuncName, gTwoThirds);
>>>>>>> miniblink49
        break;
    case kLeft_BoundaryMode:
        result.printf("\treturn %s(%s(m[1], m[2], m[4], m[5], m[7], m[8], %g),\n"
                      "\t          %s( 0.0,  0.0, m[1], m[7], m[2], m[8], %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gOneHalf,
            sobelFuncName, gOneThird);
=======
                      pointToNormalName, sobelFuncName, gOneHalf,
                                         sobelFuncName, gOneThird);
>>>>>>> miniblink49
        break;
    case kInterior_BoundaryMode:
        result.printf("\treturn %s(%s(m[0], m[2], m[3], m[5], m[6], m[8], %g),\n"
                      "\t          %s(m[0], m[6], m[1], m[7], m[2], m[8], %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gOneQuarter,
            sobelFuncName, gOneQuarter);
=======
                      pointToNormalName, sobelFuncName, gOneQuarter,
                                         sobelFuncName, gOneQuarter);
>>>>>>> miniblink49
        break;
    case kRight_BoundaryMode:
        result.printf("\treturn %s(%s(m[0], m[1], m[3], m[4], m[6], m[7], %g),\n"
                      "\t          %s(m[0], m[6], m[1], m[7],  0.0,  0.0, %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gOneHalf,
            sobelFuncName, gOneThird);
=======
                      pointToNormalName, sobelFuncName, gOneHalf,
                                         sobelFuncName, gOneThird);
>>>>>>> miniblink49
        break;
    case kBottomLeft_BoundaryMode:
        result.printf("\treturn %s(%s(m[1], m[2], m[4], m[5],  0.0,  0.0, %g),\n"
                      "\t          %s( 0.0,  0.0, m[1], m[4], m[2], m[5], %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gTwoThirds,
            sobelFuncName, gTwoThirds);
=======
                      pointToNormalName, sobelFuncName, gTwoThirds,
                                         sobelFuncName, gTwoThirds);
>>>>>>> miniblink49
        break;
    case kBottom_BoundaryMode:
        result.printf("\treturn %s(%s(m[0], m[2], m[3], m[5],  0.0,  0.0, %g),\n"
                      "\t          %s(m[0], m[3], m[1], m[4], m[2], m[5], %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gOneThird,
            sobelFuncName, gOneHalf);
=======
                      pointToNormalName, sobelFuncName, gOneThird,
                                         sobelFuncName, gOneHalf);
>>>>>>> miniblink49
        break;
    case kBottomRight_BoundaryMode:
        result.printf("\treturn %s(%s(m[0], m[1], m[3], m[4],  0.0,  0.0, %g),\n"
                      "\t          %s(m[0], m[3], m[1], m[4],  0.0,  0.0, %g),\n"
                      "\t          surfaceScale);\n",
<<<<<<< HEAD
            pointToNormalName, sobelFuncName, gTwoThirds,
            sobelFuncName, gTwoThirds);
=======
                      pointToNormalName, sobelFuncName, gTwoThirds,
                                         sobelFuncName, gTwoThirds);
>>>>>>> miniblink49
        break;
    default:
        SkASSERT(false);
        break;
    }
    return result;
}

}

<<<<<<< HEAD
class GrGLLightingEffect : public GrGLSLFragmentProcessor {
public:
    GrGLLightingEffect()
        : fLight(nullptr)
    {
    }
    virtual ~GrGLLightingEffect() { delete fLight; }

    void emitCode(EmitArgs&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder* b);

protected:
    /**
     * Subclasses of GrGLLightingEffect must call INHERITED::onSetData();
     */
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

    virtual void emitLightFunc(GrGLSLUniformHandler*,
        GrGLSLFPFragmentBuilder*,
        SkString* funcName)
        = 0;

private:
    typedef GrGLSLFragmentProcessor INHERITED;

    UniformHandle fImageIncrementUni;
    UniformHandle fSurfaceScaleUni;
    GrTextureDomain::GLDomain fDomain;
    GrGLLight* fLight;
=======
class GrGLLightingEffect  : public GrGLFragmentProcessor {
public:
    GrGLLightingEffect(const GrProcessor&);
    virtual ~GrGLLightingEffect();

    void emitCode(GrGLFPBuilder*,
                  const GrFragmentProcessor&,
                  const char* outputColor,
                  const char* inputColor,
                  const TransformedCoordsArray&,
                  const TextureSamplerArray&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder* b);

    /**
     * Subclasses of GrGLLightingEffect must call INHERITED::setData();
     */
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

protected:
    virtual void emitLightFunc(GrGLFPBuilder*, SkString* funcName) = 0;

private:
    typedef GrGLFragmentProcessor INHERITED;

    UniformHandle       fImageIncrementUni;
    UniformHandle       fSurfaceScaleUni;
    GrGLLight*          fLight;
    BoundaryMode        fBoundaryMode;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLDiffuseLightingEffect : public GrGLLightingEffect {
public:
    void emitLightFunc(GrGLSLUniformHandler*, GrGLSLFPFragmentBuilder*, SkString* funcName) override;

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;
=======
class GrGLDiffuseLightingEffect  : public GrGLLightingEffect {
public:
    GrGLDiffuseLightingEffect(const GrProcessor&);
    void emitLightFunc(GrGLFPBuilder*, SkString* funcName) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

private:
    typedef GrGLLightingEffect INHERITED;

<<<<<<< HEAD
    UniformHandle fKDUni;
=======
    UniformHandle   fKDUni;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLSpecularLightingEffect : public GrGLLightingEffect {
public:
    void emitLightFunc(GrGLSLUniformHandler*, GrGLSLFPFragmentBuilder*, SkString* funcName) override;

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;
=======
class GrGLSpecularLightingEffect  : public GrGLLightingEffect {
public:
    GrGLSpecularLightingEffect(const GrProcessor&);
    void emitLightFunc(GrGLFPBuilder*, SkString* funcName) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

private:
    typedef GrGLLightingEffect INHERITED;

<<<<<<< HEAD
    UniformHandle fKSUni;
    UniformHandle fShininessUni;
=======
    UniformHandle   fKSUni;
    UniformHandle   fShininessUni;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
namespace {

GrTextureDomain create_domain(GrTexture* texture, const SkIRect* srcBounds,
    GrTextureDomain::Mode mode)
{
    if (srcBounds) {
        SkRect texelDomain = GrTextureDomain::MakeTexelDomainForMode(texture, *srcBounds, mode);
        return GrTextureDomain(texelDomain, mode);
    } else {
        return GrTextureDomain(SkRect::MakeEmpty(), GrTextureDomain::kIgnore_Mode);
    }
}

};

GrLightingEffect::GrLightingEffect(GrTexture* texture,
    const SkImageFilterLight* light,
    SkScalar surfaceScale,
    const SkMatrix& matrix,
    BoundaryMode boundaryMode,
    const SkIRect* srcBounds)
    : INHERITED(texture, GrCoordTransform::MakeDivByTextureWHMatrix(texture))
    , fLight(light)
    , fSurfaceScale(surfaceScale)
    , fFilterMatrix(matrix)
    , fBoundaryMode(boundaryMode)
    , fDomain(create_domain(texture, srcBounds, GrTextureDomain::kDecal_Mode))
{
=======
GrLightingEffect::GrLightingEffect(GrProcessorDataManager* procDataManager,
                                   GrTexture* texture,
                                   const SkLight* light,
                                   SkScalar surfaceScale,
                                   const SkMatrix& matrix,
                                   BoundaryMode boundaryMode)
    : INHERITED(procDataManager, texture, GrCoordTransform::MakeDivByTextureWHMatrix(texture))
    , fLight(light)
    , fSurfaceScale(surfaceScale)
    , fFilterMatrix(matrix)
    , fBoundaryMode(boundaryMode) {
>>>>>>> miniblink49
    fLight->ref();
    if (light->requiresFragmentPosition()) {
        this->setWillReadFragmentPosition();
    }
}

<<<<<<< HEAD
GrLightingEffect::~GrLightingEffect()
{
    fLight->unref();
}

bool GrLightingEffect::onIsEqual(const GrFragmentProcessor& sBase) const
{
    const GrLightingEffect& s = sBase.cast<GrLightingEffect>();
    return fLight->isEqual(*s.fLight) && fSurfaceScale == s.fSurfaceScale && fBoundaryMode == s.fBoundaryMode;
=======
GrLightingEffect::~GrLightingEffect() {
    fLight->unref();
}

bool GrLightingEffect::onIsEqual(const GrFragmentProcessor& sBase) const {
    const GrLightingEffect& s = sBase.cast<GrLightingEffect>();
    return fLight->isEqual(*s.fLight) &&
           fSurfaceScale == s.fSurfaceScale &&
           fBoundaryMode == s.fBoundaryMode;
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrDiffuseLightingEffect::GrDiffuseLightingEffect(GrTexture* texture,
    const SkImageFilterLight* light,
    SkScalar surfaceScale,
    const SkMatrix& matrix,
    SkScalar kd,
    BoundaryMode boundaryMode,
    const SkIRect* srcBounds)
    : INHERITED(texture, light, surfaceScale, matrix, boundaryMode, srcBounds)
    , fKD(kd)
{
    this->initClassID<GrDiffuseLightingEffect>();
}

bool GrDiffuseLightingEffect::onIsEqual(const GrFragmentProcessor& sBase) const
{
    const GrDiffuseLightingEffect& s = sBase.cast<GrDiffuseLightingEffect>();
    return INHERITED::onIsEqual(sBase) && this->kd() == s.kd();
}

void GrDiffuseLightingEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLDiffuseLightingEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrDiffuseLightingEffect::onCreateGLSLInstance() const
{
    return new GrGLDiffuseLightingEffect;
=======
GrDiffuseLightingEffect::GrDiffuseLightingEffect(GrProcessorDataManager* procDataManager,
                                                 GrTexture* texture,
                                                 const SkLight* light,
                                                 SkScalar surfaceScale,
                                                 const SkMatrix& matrix,
                                                 SkScalar kd,
                                                 BoundaryMode boundaryMode)
    : INHERITED(procDataManager, texture, light, surfaceScale, matrix, boundaryMode), fKD(kd) {
    this->initClassID<GrDiffuseLightingEffect>();
}

bool GrDiffuseLightingEffect::onIsEqual(const GrFragmentProcessor& sBase) const {
    const GrDiffuseLightingEffect& s = sBase.cast<GrDiffuseLightingEffect>();
    return INHERITED::onIsEqual(sBase) &&
            this->kd() == s.kd();
}

void GrDiffuseLightingEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                                GrProcessorKeyBuilder* b) const {
    GrGLDiffuseLightingEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrDiffuseLightingEffect::createGLInstance() const {
    return SkNEW_ARGS(GrGLDiffuseLightingEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrDiffuseLightingEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrDiffuseLightingEffect::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
    GrTexture* tex = d->fTextures[texIdx];
    SkScalar surfaceScale = d->fRandom->nextSScalar1();
    SkScalar kd = d->fRandom->nextUScalar1();
    SkAutoTUnref<SkImageFilterLight> light(create_random_light(d->fRandom));
=======
GrFragmentProcessor* GrDiffuseLightingEffect::TestCreate(GrProcessorTestData* d) {
    SkScalar surfaceScale = d->fRandom->nextSScalar1();
    SkScalar kd = d->fRandom->nextUScalar1();
    SkAutoTUnref<SkLight> light(create_random_light(d->fRandom));
>>>>>>> miniblink49
    SkMatrix matrix;
    for (int i = 0; i < 9; i++) {
        matrix[i] = d->fRandom->nextUScalar1();
    }
<<<<<<< HEAD
    SkIRect srcBounds = SkIRect::MakeXYWH(d->fRandom->nextRangeU(0, tex->width()),
        d->fRandom->nextRangeU(0, tex->height()),
        d->fRandom->nextRangeU(0, tex->width()),
        d->fRandom->nextRangeU(0, tex->height()));
    BoundaryMode mode = static_cast<BoundaryMode>(d->fRandom->nextU() % kBoundaryModeCount);
    return GrDiffuseLightingEffect::Make(tex, light, surfaceScale, matrix, kd, mode, &srcBounds);
}

///////////////////////////////////////////////////////////////////////////////

void GrGLLightingEffect::emitCode(EmitArgs& args)
{
    const GrLightingEffect& le = args.fFp.cast<GrLightingEffect>();
    if (!fLight) {
        fLight = le.light()->createGLLight();
    }

    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    fImageIncrementUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec2f_GrSLType, kDefault_GrSLPrecision,
        "ImageIncrement");
    fSurfaceScaleUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "SurfaceScale");
    fLight->emitLightColorUniform(uniformHandler);
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString lightFunc;
    this->emitLightFunc(uniformHandler, fragBuilder, &lightFunc);
    static const GrGLSLShaderVar gSobelArgs[] = {
        GrGLSLShaderVar("a", kFloat_GrSLType),
        GrGLSLShaderVar("b", kFloat_GrSLType),
        GrGLSLShaderVar("c", kFloat_GrSLType),
        GrGLSLShaderVar("d", kFloat_GrSLType),
        GrGLSLShaderVar("e", kFloat_GrSLType),
        GrGLSLShaderVar("f", kFloat_GrSLType),
        GrGLSLShaderVar("scale", kFloat_GrSLType),
    };
    SkString sobelFuncName;
    SkString coords2D = fragBuilder->ensureFSCoords2D(args.fCoords, 0);

    fragBuilder->emitFunction(kFloat_GrSLType,
        "sobel",
        SK_ARRAY_COUNT(gSobelArgs),
        gSobelArgs,
        "\treturn (-a + b - 2.0 * c + 2.0 * d -e + f) * scale;\n",
        &sobelFuncName);
    static const GrGLSLShaderVar gPointToNormalArgs[] = {
        GrGLSLShaderVar("x", kFloat_GrSLType),
        GrGLSLShaderVar("y", kFloat_GrSLType),
        GrGLSLShaderVar("scale", kFloat_GrSLType),
    };
    SkString pointToNormalName;
    fragBuilder->emitFunction(kVec3f_GrSLType,
        "pointToNormal",
        SK_ARRAY_COUNT(gPointToNormalArgs),
        gPointToNormalArgs,
        "\treturn normalize(vec3(-x * scale, -y * scale, 1));\n",
        &pointToNormalName);

    static const GrGLSLShaderVar gInteriorNormalArgs[] = {
        GrGLSLShaderVar("m", kFloat_GrSLType, 9),
        GrGLSLShaderVar("surfaceScale", kFloat_GrSLType),
    };
    SkString normalBody = emitNormalFunc(le.boundaryMode(),
        pointToNormalName.c_str(),
        sobelFuncName.c_str());
    SkString normalName;
    fragBuilder->emitFunction(kVec3f_GrSLType,
        "normal",
        SK_ARRAY_COUNT(gInteriorNormalArgs),
        gInteriorNormalArgs,
        normalBody.c_str(),
        &normalName);

    fragBuilder->codeAppendf("\t\tvec2 coord = %s;\n", coords2D.c_str());
    fragBuilder->codeAppend("\t\tfloat m[9];\n");

    const char* imgInc = uniformHandler->getUniformCStr(fImageIncrementUni);
    const char* surfScale = uniformHandler->getUniformCStr(fSurfaceScaleUni);
=======
    BoundaryMode mode = static_cast<BoundaryMode>(d->fRandom->nextU() % kBoundaryModeCount);
    return GrDiffuseLightingEffect::Create(d->fProcDataManager,
                                           d->fTextures[GrProcessorUnitTest::kAlphaTextureIdx],
                                           light, surfaceScale, matrix, kd, mode);
}


///////////////////////////////////////////////////////////////////////////////

GrGLLightingEffect::GrGLLightingEffect(const GrProcessor& fp) {
    const GrLightingEffect& m = fp.cast<GrLightingEffect>();
    fLight = m.light()->createGLLight();
    fBoundaryMode = m.boundaryMode();
}

GrGLLightingEffect::~GrGLLightingEffect() {
    delete fLight;
}

void GrGLLightingEffect::emitCode(GrGLFPBuilder* builder,
                                  const GrFragmentProcessor&,
                                  const char* outputColor,
                                  const char* inputColor,
                                  const TransformedCoordsArray& coords,
                                  const TextureSamplerArray& samplers) {
    fImageIncrementUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                              kVec2f_GrSLType, kDefault_GrSLPrecision,
                                             "ImageIncrement");
    fSurfaceScaleUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                           kFloat_GrSLType, kDefault_GrSLPrecision,
                                           "SurfaceScale");
    fLight->emitLightColorUniform(builder);
    SkString lightFunc;
    this->emitLightFunc(builder, &lightFunc);
    static const GrGLShaderVar gSobelArgs[] =  {
        GrGLShaderVar("a", kFloat_GrSLType),
        GrGLShaderVar("b", kFloat_GrSLType),
        GrGLShaderVar("c", kFloat_GrSLType),
        GrGLShaderVar("d", kFloat_GrSLType),
        GrGLShaderVar("e", kFloat_GrSLType),
        GrGLShaderVar("f", kFloat_GrSLType),
        GrGLShaderVar("scale", kFloat_GrSLType),
    };
    SkString sobelFuncName;
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2D = fsBuilder->ensureFSCoords2D(coords, 0);

    fsBuilder->emitFunction(kFloat_GrSLType,
                            "sobel",
                            SK_ARRAY_COUNT(gSobelArgs),
                            gSobelArgs,
                            "\treturn (-a + b - 2.0 * c + 2.0 * d -e + f) * scale;\n",
                            &sobelFuncName);
    static const GrGLShaderVar gPointToNormalArgs[] =  {
        GrGLShaderVar("x", kFloat_GrSLType),
        GrGLShaderVar("y", kFloat_GrSLType),
        GrGLShaderVar("scale", kFloat_GrSLType),
    };
    SkString pointToNormalName;
    fsBuilder->emitFunction(kVec3f_GrSLType,
                            "pointToNormal",
                            SK_ARRAY_COUNT(gPointToNormalArgs),
                            gPointToNormalArgs,
                            "\treturn normalize(vec3(-x * scale, -y * scale, 1));\n",
                            &pointToNormalName);

    static const GrGLShaderVar gInteriorNormalArgs[] =  {
        GrGLShaderVar("m", kFloat_GrSLType, 9),
        GrGLShaderVar("surfaceScale", kFloat_GrSLType),
    };
    SkString normalBody = emitNormalFunc(fBoundaryMode,
                                         pointToNormalName.c_str(),
                                         sobelFuncName.c_str());
    SkString normalName;
    fsBuilder->emitFunction(kVec3f_GrSLType,
                            "normal",
                            SK_ARRAY_COUNT(gInteriorNormalArgs),
                            gInteriorNormalArgs,
                            normalBody.c_str(),
                            &normalName);

    fsBuilder->codeAppendf("\t\tvec2 coord = %s;\n", coords2D.c_str());
    fsBuilder->codeAppend("\t\tfloat m[9];\n");

    const char* imgInc = builder->getUniformCStr(fImageIncrementUni);
    const char* surfScale = builder->getUniformCStr(fSurfaceScaleUni);
>>>>>>> miniblink49

    int index = 0;
    for (int dy = 1; dy >= -1; dy--) {
        for (int dx = -1; dx <= 1; dx++) {
            SkString texCoords;
            texCoords.appendf("coord + vec2(%d, %d) * %s", dx, dy, imgInc);
<<<<<<< HEAD
            SkString temp;
            temp.appendf("temp%d", index);
            fragBuilder->codeAppendf("vec4 %s;", temp.c_str());
            fDomain.sampleTexture(fragBuilder,
                args.fUniformHandler,
                args.fGLSLCaps,
                le.domain(),
                temp.c_str(),
                texCoords,
                args.fTexSamplers[0]);
            fragBuilder->codeAppendf("m[%d] = %s.a;", index, temp.c_str());
            index++;
        }
    }
    fragBuilder->codeAppend("\t\tvec3 surfaceToLight = ");
    SkString arg;
    arg.appendf("%s * m[4]", surfScale);
    fLight->emitSurfaceToLight(uniformHandler, fragBuilder, arg.c_str());
    fragBuilder->codeAppend(";\n");
    fragBuilder->codeAppendf("\t\t%s = %s(%s(m, %s), surfaceToLight, ",
        args.fOutputColor, lightFunc.c_str(), normalName.c_str(), surfScale);
    fLight->emitLightColor(uniformHandler, fragBuilder, "surfaceToLight");
    fragBuilder->codeAppend(");\n");
    SkString modulate;
    GrGLSLMulVarBy4f(&modulate, args.fOutputColor, args.fInputColor);
    fragBuilder->codeAppend(modulate.c_str());
}

void GrGLLightingEffect::GenKey(const GrProcessor& proc,
    const GrGLSLCaps& caps, GrProcessorKeyBuilder* b)
{
    const GrLightingEffect& lighting = proc.cast<GrLightingEffect>();
    b->add32(lighting.boundaryMode() << 2 | lighting.light()->type());
    b->add32(GrTextureDomain::GLDomain::DomainKey(lighting.domain()));
}

void GrGLLightingEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& proc)
{
    const GrLightingEffect& lighting = proc.cast<GrLightingEffect>();
    if (!fLight) {
        fLight = lighting.light()->createGLLight();
    }

=======
            fsBuilder->codeAppendf("\t\tm[%d] = ", index++);
            fsBuilder->appendTextureLookup(samplers[0], texCoords.c_str());
            fsBuilder->codeAppend(".a;\n");
        }
    }
    fsBuilder->codeAppend("\t\tvec3 surfaceToLight = ");
    SkString arg;
    arg.appendf("%s * m[4]", surfScale);
    fLight->emitSurfaceToLight(builder, arg.c_str());
    fsBuilder->codeAppend(";\n");
    fsBuilder->codeAppendf("\t\t%s = %s(%s(m, %s), surfaceToLight, ",
                           outputColor, lightFunc.c_str(), normalName.c_str(), surfScale);
    fLight->emitLightColor(builder, "surfaceToLight");
    fsBuilder->codeAppend(");\n");
    SkString modulate;
    GrGLSLMulVarBy4f(&modulate, outputColor, inputColor);
    fsBuilder->codeAppend(modulate.c_str());
}

void GrGLLightingEffect::GenKey(const GrProcessor& proc,
                                const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) {
    const GrLightingEffect& lighting = proc.cast<GrLightingEffect>();
    b->add32(lighting.boundaryMode() << 2 | lighting.light()->type());
}

void GrGLLightingEffect::setData(const GrGLProgramDataManager& pdman,
                                 const GrProcessor& proc) {
    const GrLightingEffect& lighting = proc.cast<GrLightingEffect>();
>>>>>>> miniblink49
    GrTexture* texture = lighting.texture(0);
    float ySign = texture->origin() == kTopLeft_GrSurfaceOrigin ? -1.0f : 1.0f;
    pdman.set2f(fImageIncrementUni, 1.0f / texture->width(), ySign / texture->height());
    pdman.set1f(fSurfaceScaleUni, lighting.surfaceScale());
<<<<<<< HEAD
    SkAutoTUnref<SkImageFilterLight> transformedLight(
        lighting.light()->transform(lighting.filterMatrix()));
    fDomain.setData(pdman, lighting.domain(), texture->origin());
=======
    SkAutoTUnref<SkLight> transformedLight(lighting.light()->transform(lighting.filterMatrix()));
>>>>>>> miniblink49
    fLight->setData(pdman, transformedLight);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrGLDiffuseLightingEffect::emitLightFunc(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    SkString* funcName)
{
    const char* kd;
    fKDUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "KD", &kd);

    static const GrGLSLShaderVar gLightArgs[] = {
        GrGLSLShaderVar("normal", kVec3f_GrSLType),
        GrGLSLShaderVar("surfaceToLight", kVec3f_GrSLType),
        GrGLSLShaderVar("lightColor", kVec3f_GrSLType)
=======
GrGLDiffuseLightingEffect::GrGLDiffuseLightingEffect(const GrProcessor& proc)
    : INHERITED(proc) {
}

void GrGLDiffuseLightingEffect::emitLightFunc(GrGLFPBuilder* builder, SkString* funcName) {
    const char* kd;
    fKDUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                 kFloat_GrSLType, kDefault_GrSLPrecision,
                                 "KD", &kd);

    static const GrGLShaderVar gLightArgs[] = {
        GrGLShaderVar("normal", kVec3f_GrSLType),
        GrGLShaderVar("surfaceToLight", kVec3f_GrSLType),
        GrGLShaderVar("lightColor", kVec3f_GrSLType)
>>>>>>> miniblink49
    };
    SkString lightBody;
    lightBody.appendf("\tfloat colorScale = %s * dot(normal, surfaceToLight);\n", kd);
    lightBody.appendf("\treturn vec4(lightColor * clamp(colorScale, 0.0, 1.0), 1.0);\n");
<<<<<<< HEAD
    fragBuilder->emitFunction(kVec4f_GrSLType,
        "light",
        SK_ARRAY_COUNT(gLightArgs),
        gLightArgs,
        lightBody.c_str(),
        funcName);
}

void GrGLDiffuseLightingEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& proc)
{
    INHERITED::onSetData(pdman, proc);
=======
    builder->getFragmentShaderBuilder()->emitFunction(kVec4f_GrSLType,
                                                      "light",
                                                      SK_ARRAY_COUNT(gLightArgs),
                                                      gLightArgs,
                                                      lightBody.c_str(),
                                                      funcName);
}

void GrGLDiffuseLightingEffect::setData(const GrGLProgramDataManager& pdman,
                                        const GrProcessor& proc) {
    INHERITED::setData(pdman, proc);
>>>>>>> miniblink49
    const GrDiffuseLightingEffect& diffuse = proc.cast<GrDiffuseLightingEffect>();
    pdman.set1f(fKDUni, diffuse.kd());
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrSpecularLightingEffect::GrSpecularLightingEffect(GrTexture* texture,
    const SkImageFilterLight* light,
    SkScalar surfaceScale,
    const SkMatrix& matrix,
    SkScalar ks,
    SkScalar shininess,
    BoundaryMode boundaryMode,
    const SkIRect* srcBounds)
    : INHERITED(texture, light, surfaceScale, matrix, boundaryMode, srcBounds)
    , fKS(ks)
    , fShininess(shininess)
{
    this->initClassID<GrSpecularLightingEffect>();
}

bool GrSpecularLightingEffect::onIsEqual(const GrFragmentProcessor& sBase) const
{
    const GrSpecularLightingEffect& s = sBase.cast<GrSpecularLightingEffect>();
    return INHERITED::onIsEqual(sBase) && this->ks() == s.ks() && this->shininess() == s.shininess();
}

void GrSpecularLightingEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLSpecularLightingEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrSpecularLightingEffect::onCreateGLSLInstance() const
{
    return new GrGLSpecularLightingEffect;
=======
GrSpecularLightingEffect::GrSpecularLightingEffect(GrProcessorDataManager* procDataManager,
                                                   GrTexture* texture,
                                                   const SkLight* light,
                                                   SkScalar surfaceScale,
                                                   const SkMatrix& matrix,
                                                   SkScalar ks,
                                                   SkScalar shininess,
                                                   BoundaryMode boundaryMode)
    : INHERITED(procDataManager, texture, light, surfaceScale, matrix, boundaryMode),
      fKS(ks),
      fShininess(shininess) {
    this->initClassID<GrSpecularLightingEffect>();
}

bool GrSpecularLightingEffect::onIsEqual(const GrFragmentProcessor& sBase) const {
    const GrSpecularLightingEffect& s = sBase.cast<GrSpecularLightingEffect>();
    return INHERITED::onIsEqual(sBase) &&
           this->ks() == s.ks() &&
           this->shininess() == s.shininess();
}

void GrSpecularLightingEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                                GrProcessorKeyBuilder* b) const {
    GrGLSpecularLightingEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrSpecularLightingEffect::createGLInstance() const {
    return SkNEW_ARGS(GrGLSpecularLightingEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrSpecularLightingEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrSpecularLightingEffect::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
    GrTexture* tex = d->fTextures[texIdx];
    SkScalar surfaceScale = d->fRandom->nextSScalar1();
    SkScalar ks = d->fRandom->nextUScalar1();
    SkScalar shininess = d->fRandom->nextUScalar1();
    SkAutoTUnref<SkImageFilterLight> light(create_random_light(d->fRandom));
=======
GrFragmentProcessor* GrSpecularLightingEffect::TestCreate(GrProcessorTestData* d) {
    SkScalar surfaceScale = d->fRandom->nextSScalar1();
    SkScalar ks = d->fRandom->nextUScalar1();
    SkScalar shininess = d->fRandom->nextUScalar1();
    SkAutoTUnref<SkLight> light(create_random_light(d->fRandom));
>>>>>>> miniblink49
    SkMatrix matrix;
    for (int i = 0; i < 9; i++) {
        matrix[i] = d->fRandom->nextUScalar1();
    }
    BoundaryMode mode = static_cast<BoundaryMode>(d->fRandom->nextU() % kBoundaryModeCount);
<<<<<<< HEAD
    SkIRect srcBounds = SkIRect::MakeXYWH(d->fRandom->nextRangeU(0, tex->width()),
        d->fRandom->nextRangeU(0, tex->height()),
        d->fRandom->nextRangeU(0, tex->width()),
        d->fRandom->nextRangeU(0, tex->height()));
    return GrSpecularLightingEffect::Make(d->fTextures[GrProcessorUnitTest::kAlphaTextureIdx],
        light, surfaceScale, matrix, ks, shininess, mode,
        &srcBounds);
=======
    return GrSpecularLightingEffect::Create(d->fProcDataManager,
                                            d->fTextures[GrProcessorUnitTest::kAlphaTextureIdx],
                                            light, surfaceScale, matrix, ks, shininess, mode);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrGLSpecularLightingEffect::emitLightFunc(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    SkString* funcName)
{
    const char* ks;
    const char* shininess;

    fKSUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision, "KS", &ks);
    fShininessUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType,
        kDefault_GrSLPrecision,
        "Shininess",
        &shininess);

    static const GrGLSLShaderVar gLightArgs[] = {
        GrGLSLShaderVar("normal", kVec3f_GrSLType),
        GrGLSLShaderVar("surfaceToLight", kVec3f_GrSLType),
        GrGLSLShaderVar("lightColor", kVec3f_GrSLType)
=======
GrGLSpecularLightingEffect::GrGLSpecularLightingEffect(const GrProcessor& proc)
    : INHERITED(proc) {
}

void GrGLSpecularLightingEffect::emitLightFunc(GrGLFPBuilder* builder, SkString* funcName) {
    const char* ks;
    const char* shininess;

    fKSUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                 kFloat_GrSLType, kDefault_GrSLPrecision, "KS", &ks);
    fShininessUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                        kFloat_GrSLType,
                                        kDefault_GrSLPrecision,
                                        "Shininess",
                                        &shininess);

    static const GrGLShaderVar gLightArgs[] = {
        GrGLShaderVar("normal", kVec3f_GrSLType),
        GrGLShaderVar("surfaceToLight", kVec3f_GrSLType),
        GrGLShaderVar("lightColor", kVec3f_GrSLType)
>>>>>>> miniblink49
    };
    SkString lightBody;
    lightBody.appendf("\tvec3 halfDir = vec3(normalize(surfaceToLight + vec3(0, 0, 1)));\n");
    lightBody.appendf("\tfloat colorScale = %s * pow(dot(normal, halfDir), %s);\n", ks, shininess);
    lightBody.appendf("\tvec3 color = lightColor * clamp(colorScale, 0.0, 1.0);\n");
    lightBody.appendf("\treturn vec4(color, max(max(color.r, color.g), color.b));\n");
<<<<<<< HEAD
    fragBuilder->emitFunction(kVec4f_GrSLType,
        "light",
        SK_ARRAY_COUNT(gLightArgs),
        gLightArgs,
        lightBody.c_str(),
        funcName);
}

void GrGLSpecularLightingEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& effect)
{
    INHERITED::onSetData(pdman, effect);
=======
    builder->getFragmentShaderBuilder()->emitFunction(kVec4f_GrSLType,
                                                      "light",
                                                      SK_ARRAY_COUNT(gLightArgs),
                                                      gLightArgs,
                                                      lightBody.c_str(),
                                                      funcName);
}

void GrGLSpecularLightingEffect::setData(const GrGLProgramDataManager& pdman,
                                         const GrProcessor& effect) {
    INHERITED::setData(pdman, effect);
>>>>>>> miniblink49
    const GrSpecularLightingEffect& spec = effect.cast<GrSpecularLightingEffect>();
    pdman.set1f(fKSUni, spec.ks());
    pdman.set1f(fShininessUni, spec.shininess());
}

///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
void GrGLLight::emitLightColorUniform(GrGLSLUniformHandler* uniformHandler)
{
    fColorUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision,
        "LightColor");
}

void GrGLLight::emitLightColor(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    const char* surfaceToLight)
{
    fragBuilder->codeAppend(uniformHandler->getUniformCStr(this->lightColorUni()));
}

void GrGLLight::setData(const GrGLSLProgramDataManager& pdman,
    const SkImageFilterLight* light) const
{
    setUniformPoint3(pdman, fColorUni,
        light->color().makeScale(SkScalarInvert(SkIntToScalar(255))));
=======
void GrGLLight::emitLightColorUniform(GrGLFPBuilder* builder) {
    fColorUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                    kVec3f_GrSLType, kDefault_GrSLPrecision,
                                    "LightColor");
}

void GrGLLight::emitLightColor(GrGLFPBuilder* builder,
                               const char *surfaceToLight) {
    builder->getFragmentShaderBuilder()->codeAppend(builder->getUniformCStr(this->lightColorUni()));
}

void GrGLLight::setData(const GrGLProgramDataManager& pdman,
                        const SkLight* light) const {
    setUniformPoint3(pdman, fColorUni, light->color() * SkScalarInvert(SkIntToScalar(255)));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrGLDistantLight::setData(const GrGLSLProgramDataManager& pdman,
    const SkImageFilterLight* light) const
{
    INHERITED::setData(pdman, light);
    SkASSERT(light->type() == SkImageFilterLight::kDistant_LightType);
=======
void GrGLDistantLight::setData(const GrGLProgramDataManager& pdman,
                               const SkLight* light) const {
    INHERITED::setData(pdman, light);
    SkASSERT(light->type() == SkLight::kDistant_LightType);
>>>>>>> miniblink49
    const SkDistantLight* distantLight = static_cast<const SkDistantLight*>(light);
    setUniformNormal3(pdman, fDirectionUni, distantLight->direction());
}

<<<<<<< HEAD
void GrGLDistantLight::emitSurfaceToLight(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    const char* z)
{
    const char* dir;
    fDirectionUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision,
        "LightDirection", &dir);
    fragBuilder->codeAppend(dir);
=======
void GrGLDistantLight::emitSurfaceToLight(GrGLFPBuilder* builder, const char* z) {
    const char* dir;
    fDirectionUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                        kVec3f_GrSLType, kDefault_GrSLPrecision,
                                        "LightDirection", &dir);
    builder->getFragmentShaderBuilder()->codeAppend(dir);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrGLPointLight::setData(const GrGLSLProgramDataManager& pdman,
    const SkImageFilterLight* light) const
{
    INHERITED::setData(pdman, light);
    SkASSERT(light->type() == SkImageFilterLight::kPoint_LightType);
=======
void GrGLPointLight::setData(const GrGLProgramDataManager& pdman,
                             const SkLight* light) const {
    INHERITED::setData(pdman, light);
    SkASSERT(light->type() == SkLight::kPoint_LightType);
>>>>>>> miniblink49
    const SkPointLight* pointLight = static_cast<const SkPointLight*>(light);
    setUniformPoint3(pdman, fLocationUni, pointLight->location());
}

<<<<<<< HEAD
void GrGLPointLight::emitSurfaceToLight(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    const char* z)
{
    const char* loc;
    fLocationUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision,
        "LightLocation", &loc);
    fragBuilder->codeAppendf("normalize(%s - vec3(%s.xy, %s))",
        loc, fragBuilder->fragmentPosition(), z);
=======
void GrGLPointLight::emitSurfaceToLight(GrGLFPBuilder* builder, const char* z) {
    const char* loc;
    fLocationUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                       kVec3f_GrSLType, kDefault_GrSLPrecision,
                                       "LightLocation", &loc);
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    fsBuilder->codeAppendf("normalize(%s - vec3(%s.xy, %s))",
            loc, fsBuilder->fragmentPosition(), z);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrGLSpotLight::setData(const GrGLSLProgramDataManager& pdman,
    const SkImageFilterLight* light) const
{
    INHERITED::setData(pdman, light);
    SkASSERT(light->type() == SkImageFilterLight::kSpot_LightType);
    const SkSpotLight* spotLight = static_cast<const SkSpotLight*>(light);
=======
void GrGLSpotLight::setData(const GrGLProgramDataManager& pdman,
                            const SkLight* light) const {
    INHERITED::setData(pdman, light);
    SkASSERT(light->type() == SkLight::kSpot_LightType);
    const SkSpotLight* spotLight = static_cast<const SkSpotLight *>(light);
>>>>>>> miniblink49
    setUniformPoint3(pdman, fLocationUni, spotLight->location());
    pdman.set1f(fExponentUni, spotLight->specularExponent());
    pdman.set1f(fCosInnerConeAngleUni, spotLight->cosInnerConeAngle());
    pdman.set1f(fCosOuterConeAngleUni, spotLight->cosOuterConeAngle());
    pdman.set1f(fConeScaleUni, spotLight->coneScale());
    setUniformNormal3(pdman, fSUni, spotLight->s());
}

<<<<<<< HEAD
void GrGLSpotLight::emitSurfaceToLight(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    const char* z)
{
    const char* location;
    fLocationUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision,
        "LightLocation", &location);

    fragBuilder->codeAppendf("normalize(%s - vec3(%s.xy, %s))",
        location, fragBuilder->fragmentPosition(), z);
}

void GrGLSpotLight::emitLightColor(GrGLSLUniformHandler* uniformHandler,
    GrGLSLFPFragmentBuilder* fragBuilder,
    const char* surfaceToLight)
{

    const char* color = uniformHandler->getUniformCStr(this->lightColorUni()); // created by parent class.
=======
void GrGLSpotLight::emitSurfaceToLight(GrGLFPBuilder* builder, const char* z) {
    const char* location;
    fLocationUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                       kVec3f_GrSLType, kDefault_GrSLPrecision,
                                       "LightLocation", &location);

    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    fsBuilder->codeAppendf("normalize(%s - vec3(%s.xy, %s))",
            location, fsBuilder->fragmentPosition(), z);
}

void GrGLSpotLight::emitLightColor(GrGLFPBuilder* builder,
                                   const char *surfaceToLight) {

    const char* color = builder->getUniformCStr(this->lightColorUni()); // created by parent class.
>>>>>>> miniblink49

    const char* exponent;
    const char* cosInner;
    const char* cosOuter;
    const char* coneScale;
    const char* s;
<<<<<<< HEAD
    fExponentUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "Exponent", &exponent);
    fCosInnerConeAngleUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "CosInnerConeAngle", &cosInner);
    fCosOuterConeAngleUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "CosOuterConeAngle", &cosOuter);
    fConeScaleUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "ConeScale", &coneScale);
    fSUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision, "S", &s);

    static const GrGLSLShaderVar gLightColorArgs[] = {
        GrGLSLShaderVar("surfaceToLight", kVec3f_GrSLType)
=======
    fExponentUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                       kFloat_GrSLType, kDefault_GrSLPrecision,
                                       "Exponent", &exponent);
    fCosInnerConeAngleUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                                kFloat_GrSLType, kDefault_GrSLPrecision,
                                                "CosInnerConeAngle", &cosInner);
    fCosOuterConeAngleUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                                kFloat_GrSLType, kDefault_GrSLPrecision,
                                                "CosOuterConeAngle", &cosOuter);
    fConeScaleUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                        kFloat_GrSLType, kDefault_GrSLPrecision,
                                        "ConeScale", &coneScale);
    fSUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                kVec3f_GrSLType, kDefault_GrSLPrecision, "S", &s);

    static const GrGLShaderVar gLightColorArgs[] = {
        GrGLShaderVar("surfaceToLight", kVec3f_GrSLType)
>>>>>>> miniblink49
    };
    SkString lightColorBody;
    lightColorBody.appendf("\tfloat cosAngle = -dot(surfaceToLight, %s);\n", s);
    lightColorBody.appendf("\tif (cosAngle < %s) {\n", cosOuter);
    lightColorBody.appendf("\t\treturn vec3(0);\n");
    lightColorBody.appendf("\t}\n");
    lightColorBody.appendf("\tfloat scale = pow(cosAngle, %s);\n", exponent);
    lightColorBody.appendf("\tif (cosAngle < %s) {\n", cosInner);
    lightColorBody.appendf("\t\treturn %s * scale * (cosAngle - %s) * %s;\n",
<<<<<<< HEAD
        color, cosOuter, coneScale);
    lightColorBody.appendf("\t}\n");
    lightColorBody.appendf("\treturn %s;\n", color);
    fragBuilder->emitFunction(kVec3f_GrSLType,
        "lightColor",
        SK_ARRAY_COUNT(gLightColorArgs),
        gLightColorArgs,
        lightColorBody.c_str(),
        &fLightColorFunc);

    fragBuilder->codeAppendf("%s(%s)", fLightColorFunc.c_str(), surfaceToLight);
=======
                           color, cosOuter, coneScale);
    lightColorBody.appendf("\t}\n");
    lightColorBody.appendf("\treturn %s;\n", color);
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    fsBuilder->emitFunction(kVec3f_GrSLType,
                            "lightColor",
                            SK_ARRAY_COUNT(gLightColorArgs),
                            gLightColorArgs,
                            lightColorBody.c_str(),
                            &fLightColorFunc);

    fsBuilder->codeAppendf("%s(%s)", fLightColorFunc.c_str(), surfaceToLight);
>>>>>>> miniblink49
}

#endif

SK_DEFINE_FLATTENABLE_REGISTRAR_GROUP_START(SkLightingImageFilter)
<<<<<<< HEAD
SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkDiffuseLightingImageFilter)
SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkSpecularLightingImageFilter)
=======
    SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkDiffuseLightingImageFilter)
    SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkSpecularLightingImageFilter)
>>>>>>> miniblink49
SK_DEFINE_FLATTENABLE_REGISTRAR_GROUP_END
