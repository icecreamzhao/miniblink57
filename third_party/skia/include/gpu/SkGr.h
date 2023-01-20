<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkGr_DEFINED
#define SkGr_DEFINED

#include "GrColor.h"
#include "GrTextureAccess.h"
#include "SkColor.h"
#include "SkColorPriv.h"
#include "SkFilterQuality.h"
#include "SkImageInfo.h"

class GrCaps;
class GrContext;
class GrTexture;
class GrTextureParams;
class SkBitmap;
=======


#ifndef SkGr_DEFINED
#define SkGr_DEFINED

#include <stddef.h>

// Gr headers
#include "GrTypes.h"
#include "GrContext.h"

// skia headers
#include "SkBitmap.h"
#include "SkPath.h"
#include "SkPoint.h"
#include "SkRegion.h"
#include "SkClipStack.h"
>>>>>>> miniblink49

////////////////////////////////////////////////////////////////////////////////
// Sk to Gr Type conversions

<<<<<<< HEAD
static inline GrColor SkColorToPremulGrColor(SkColor c)
{
=======
GR_STATIC_ASSERT((int)kZero_GrBlendCoeff == (int)SkXfermode::kZero_Coeff);
GR_STATIC_ASSERT((int)kOne_GrBlendCoeff  == (int)SkXfermode::kOne_Coeff);
GR_STATIC_ASSERT((int)kSC_GrBlendCoeff   == (int)SkXfermode::kSC_Coeff);
GR_STATIC_ASSERT((int)kISC_GrBlendCoeff  == (int)SkXfermode::kISC_Coeff);
GR_STATIC_ASSERT((int)kDC_GrBlendCoeff   == (int)SkXfermode::kDC_Coeff);
GR_STATIC_ASSERT((int)kIDC_GrBlendCoeff  == (int)SkXfermode::kIDC_Coeff);
GR_STATIC_ASSERT((int)kSA_GrBlendCoeff   == (int)SkXfermode::kSA_Coeff);
GR_STATIC_ASSERT((int)kISA_GrBlendCoeff  == (int)SkXfermode::kISA_Coeff);
GR_STATIC_ASSERT((int)kDA_GrBlendCoeff   == (int)SkXfermode::kDA_Coeff);
GR_STATIC_ASSERT((int)kIDA_GrBlendCoeff  == (int)SkXfermode::kIDA_Coeff);

#define sk_blend_to_grblend(X) ((GrBlendCoeff)(X))

///////////////////////////////////////////////////////////////////////////////

#include "SkColorPriv.h"

GrPixelConfig SkImageInfo2GrPixelConfig(SkColorType, SkAlphaType, SkColorProfileType);

static inline GrPixelConfig SkImageInfo2GrPixelConfig(const SkImageInfo& info) {
    return SkImageInfo2GrPixelConfig(info.colorType(), info.alphaType(), info.profileType());
}

bool GrPixelConfig2ColorAndProfileType(GrPixelConfig, SkColorType*, SkColorProfileType*);

static inline GrColor SkColor2GrColor(SkColor c) {
>>>>>>> miniblink49
    SkPMColor pm = SkPreMultiplyColor(c);
    unsigned r = SkGetPackedR32(pm);
    unsigned g = SkGetPackedG32(pm);
    unsigned b = SkGetPackedB32(pm);
    unsigned a = SkGetPackedA32(pm);
    return GrColorPackRGBA(r, g, b, a);
}

<<<<<<< HEAD
static inline GrColor SkColorToUnpremulGrColor(SkColor c)
{
    unsigned r = SkColorGetR(c);
    unsigned g = SkColorGetG(c);
    unsigned b = SkColorGetB(c);
    unsigned a = SkColorGetA(c);
    return GrColorPackRGBA(r, g, b, a);
}

static inline GrColor SkColorToOpaqueGrColor(SkColor c)
{
    unsigned r = SkColorGetR(c);
    unsigned g = SkColorGetG(c);
    unsigned b = SkColorGetB(c);
    return GrColorPackRGBA(r, g, b, 0xFF);
}

/** Replicates the SkColor's alpha to all four channels of the GrColor. */
static inline GrColor SkColorAlphaToGrColor(SkColor c)
{
=======
static inline GrColor SkColor2GrColorJustAlpha(SkColor c) {
>>>>>>> miniblink49
    U8CPU a = SkColorGetA(c);
    return GrColorPackRGBA(a, a, a, a);
}

<<<<<<< HEAD
static inline SkPMColor GrColorToSkPMColor(GrColor c)
{
    GrColorIsPMAssert(c);
    return SkPackARGB32(GrColorUnpackA(c), GrColorUnpackR(c), GrColorUnpackG(c), GrColorUnpackB(c));
}

static inline GrColor SkPMColorToGrColor(SkPMColor c)
{
    return GrColorPackRGBA(SkGetPackedR32(c), SkGetPackedG32(c), SkGetPackedB32(c),
        SkGetPackedA32(c));
}

////////////////////////////////////////////////////////////////////////////////
/** Returns a texture representing the bitmap that is compatible with the GrTextureParams. The
    texture is inserted into the cache (unless the bitmap is marked volatile) and can be
    retrieved again via this function. */
GrTexture* GrRefCachedBitmapTexture(GrContext*, const SkBitmap&, const GrTextureParams&,
    SkSourceGammaTreatment);

// TODO: Move SkImageInfo2GrPixelConfig to SkGrPriv.h (requires cleanup to SkWindow its subclasses).
GrPixelConfig SkImageInfo2GrPixelConfig(SkColorType, SkAlphaType, const SkColorSpace*,
    const GrCaps&);

static inline GrPixelConfig SkImageInfo2GrPixelConfig(const SkImageInfo& info, const GrCaps& caps)
{
    return SkImageInfo2GrPixelConfig(info.colorType(), info.alphaType(), info.colorSpace(), caps);
}

GrTextureParams::FilterMode GrSkFilterQualityToGrFilterMode(SkFilterQuality paintFilterQuality,
    const SkMatrix& viewM,
    const SkMatrix& localM,
    bool* doBicubic);

////////////////////////////////////////////////////////////////////////////////
=======
////////////////////////////////////////////////////////////////////////////////

bool GrIsBitmapInCache(const GrContext*, const SkBitmap&, const GrTextureParams*);

GrTexture* GrRefCachedBitmapTexture(GrContext*, const SkBitmap&, const GrTextureParams*);

////////////////////////////////////////////////////////////////////////////////

// Converts a SkPaint to a GrPaint, ignoring the SkPaint's shader.
// Sets the color of GrPaint to the value of the parameter paintColor
// Callers may subsequently modify the GrPaint. Setting constantColor indicates
// that the final paint will draw the same color at every pixel. This allows
// an optimization where the color filter can be applied to the SkPaint's
// color once while converting to GrPaint and then ignored. TODO: Remove this
// bool and use the invariant info to automatically apply the color filter.
bool SkPaint2GrPaintNoShader(GrContext* context, GrRenderTarget*, const SkPaint& skPaint,
                             GrColor paintColor, bool constantColor, GrPaint* grPaint);

// This function is similar to skPaint2GrPaintNoShader but also converts
// skPaint's shader to a GrFragmentProcessor if possible.
// constantColor has the same meaning as in skPaint2GrPaintNoShader.
bool SkPaint2GrPaint(GrContext* context, GrRenderTarget*, const SkPaint& skPaint,
                     const SkMatrix& viewM, bool constantColor, GrPaint* grPaint);

>>>>>>> miniblink49

SkImageInfo GrMakeInfoFromTexture(GrTexture* tex, int w, int h, bool isOpaque);

// Using the dreaded SkGrPixelRef ...
<<<<<<< HEAD
SK_API void GrWrapTextureInBitmap(GrTexture* src, int w, int h, bool isOpaque,
    SkBitmap* dst);
=======
void GrWrapTextureInBitmap(GrTexture* src, int w, int h, bool isOpaque, SkBitmap* dst);

////////////////////////////////////////////////////////////////////////////////
// Classes

class SkGlyphCache;

////////////////////////////////////////////////////////////////////////////////
>>>>>>> miniblink49

#endif
