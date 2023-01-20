/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkMaskGamma_DEFINED
#define SkMaskGamma_DEFINED

<<<<<<< HEAD
#include "SkColor.h"
#include "SkColorPriv.h"
#include "SkRefCnt.h"
#include "SkTypes.h"
=======
#include "SkTypes.h"
#include "SkColor.h"
#include "SkColorPriv.h"
#include "SkRefCnt.h"
>>>>>>> miniblink49

/**
 * SkColorSpaceLuminance is used to convert luminances to and from linear and
 * perceptual color spaces.
 *
 * Luma is used to specify a linear luminance value [0.0, 1.0].
 * Luminance is used to specify a luminance value in an arbitrary color space [0.0, 1.0].
 */
class SkColorSpaceLuminance : SkNoncopyable {
public:
    virtual ~SkColorSpaceLuminance() { }

    /** Converts a color component luminance in the color space to a linear luma. */
    virtual SkScalar toLuma(SkScalar gamma, SkScalar luminance) const = 0;
    /** Converts a linear luma to a color component luminance in the color space. */
    virtual SkScalar fromLuma(SkScalar gamma, SkScalar luma) const = 0;

    /** Converts a color to a luminance value. */
<<<<<<< HEAD
    static U8CPU computeLuminance(SkScalar gamma, SkColor c)
    {
=======
    static U8CPU computeLuminance(SkScalar gamma, SkColor c) {
>>>>>>> miniblink49
        const SkColorSpaceLuminance& luminance = Fetch(gamma);
        SkScalar r = luminance.toLuma(gamma, SkIntToScalar(SkColorGetR(c)) / 255);
        SkScalar g = luminance.toLuma(gamma, SkIntToScalar(SkColorGetG(c)) / 255);
        SkScalar b = luminance.toLuma(gamma, SkIntToScalar(SkColorGetB(c)) / 255);
<<<<<<< HEAD
        SkScalar luma = r * SK_LUM_COEFF_R + g * SK_LUM_COEFF_G + b * SK_LUM_COEFF_B;
=======
        SkScalar luma = r * SK_LUM_COEFF_R +
                        g * SK_LUM_COEFF_G +
                        b * SK_LUM_COEFF_B;
>>>>>>> miniblink49
        SkASSERT(luma <= SK_Scalar1);
        return SkScalarRoundToInt(luminance.fromLuma(gamma, luma) * 255);
    }

    /** Retrieves the SkColorSpaceLuminance for the given gamma. */
    static const SkColorSpaceLuminance& Fetch(SkScalar gamma);
};

///@{
/**
 * Scales base <= 2^N-1 to 2^8-1
 * @param N [1, 8] the number of bits used by base.
 * @param base the number to be scaled to [0, 255].
 */
<<<<<<< HEAD
template <U8CPU N>
static inline U8CPU sk_t_scale255(U8CPU base)
{
=======
template<U8CPU N> static inline U8CPU sk_t_scale255(U8CPU base) {
>>>>>>> miniblink49
    base <<= (8 - N);
    U8CPU lum = base;
    for (unsigned int i = N; i < 8; i += N) {
        lum |= base >> i;
    }
    return lum;
}
<<<<<<< HEAD
template <>
/*static*/ inline U8CPU sk_t_scale255<1>(U8CPU base)
{
    return base * 0xFF;
}
template <>
/*static*/ inline U8CPU sk_t_scale255<2>(U8CPU base)
{
    return base * 0x55;
}
template <>
/*static*/ inline U8CPU sk_t_scale255<4>(U8CPU base)
{
    return base * 0x11;
}
template <>
/*static*/ inline U8CPU sk_t_scale255<8>(U8CPU base)
{
=======
template<> /*static*/ inline U8CPU sk_t_scale255<1>(U8CPU base) {
    return base * 0xFF;
}
template<> /*static*/ inline U8CPU sk_t_scale255<2>(U8CPU base) {
    return base * 0x55;
}
template<> /*static*/ inline U8CPU sk_t_scale255<4>(U8CPU base) {
    return base * 0x11;
}
template<> /*static*/ inline U8CPU sk_t_scale255<8>(U8CPU base) {
>>>>>>> miniblink49
    return base;
}
///@}

<<<<<<< HEAD
template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS>
class SkTMaskPreBlend;

void SkTMaskGamma_build_correcting_lut(uint8_t table[256], U8CPU srcI, SkScalar contrast,
    const SkColorSpaceLuminance& srcConvert, SkScalar srcGamma,
    const SkColorSpaceLuminance& dstConvert, SkScalar dstGamma);
=======
template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS> class SkTMaskPreBlend;

void SkTMaskGamma_build_correcting_lut(uint8_t table[256], U8CPU srcI, SkScalar contrast,
                                       const SkColorSpaceLuminance& srcConvert, SkScalar srcGamma,
                                       const SkColorSpaceLuminance& dstConvert, SkScalar dstGamma);
>>>>>>> miniblink49

/**
 * A regular mask contains linear alpha values. A gamma correcting mask
 * contains non-linear alpha values in an attempt to create gamma correct blits
 * in the presence of a gamma incorrect (linear) blend in the blitter.
 *
 * SkMaskGamma creates and maintains tables which convert linear alpha values
 * to gamma correcting alpha values.
 * @param R The number of luminance bits to use [1, 8] from the red channel.
 * @param G The number of luminance bits to use [1, 8] from the green channel.
 * @param B The number of luminance bits to use [1, 8] from the blue channel.
 */
<<<<<<< HEAD
template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS>
class SkTMaskGamma : public SkRefCnt {

public:
    /** Creates a linear SkTMaskGamma. */
    SkTMaskGamma()
        : fIsLinear(true)
    {
    }
=======
template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS> class SkTMaskGamma : public SkRefCnt {
    
public:

    /** Creates a linear SkTMaskGamma. */
    SkTMaskGamma() : fIsLinear(true) { }
>>>>>>> miniblink49

    /**
     * Creates tables to convert linear alpha values to gamma correcting alpha
     * values.
     *
     * @param contrast A value in the range [0.0, 1.0] which indicates the
     *                 amount of artificial contrast to add.
     * @param paint The color space in which the paint color was chosen.
     * @param device The color space of the target device.
     */
<<<<<<< HEAD
    SkTMaskGamma(SkScalar contrast, SkScalar paintGamma, SkScalar deviceGamma)
        : fIsLinear(false)
    {
=======
    SkTMaskGamma(SkScalar contrast, SkScalar paintGamma, SkScalar deviceGamma) : fIsLinear(false) {
>>>>>>> miniblink49
        const SkColorSpaceLuminance& paintConvert = SkColorSpaceLuminance::Fetch(paintGamma);
        const SkColorSpaceLuminance& deviceConvert = SkColorSpaceLuminance::Fetch(deviceGamma);
        for (U8CPU i = 0; i < (1 << MAX_LUM_BITS); ++i) {
            U8CPU lum = sk_t_scale255<MAX_LUM_BITS>(i);
            SkTMaskGamma_build_correcting_lut(fGammaTables[i], lum, contrast,
<<<<<<< HEAD
                paintConvert, paintGamma,
                deviceConvert, deviceGamma);
=======
                                              paintConvert, paintGamma,
                                              deviceConvert, deviceGamma);
>>>>>>> miniblink49
        }
    }

    /** Given a color, returns the closest canonical color. */
<<<<<<< HEAD
    static SkColor CanonicalColor(SkColor color)
    {
        return SkColorSetRGB(
            sk_t_scale255<R_LUM_BITS>(SkColorGetR(color) >> (8 - R_LUM_BITS)),
            sk_t_scale255<G_LUM_BITS>(SkColorGetG(color) >> (8 - G_LUM_BITS)),
            sk_t_scale255<B_LUM_BITS>(SkColorGetB(color) >> (8 - B_LUM_BITS)));
=======
    static SkColor CanonicalColor(SkColor color) {
        return SkColorSetRGB(
                   sk_t_scale255<R_LUM_BITS>(SkColorGetR(color) >> (8 - R_LUM_BITS)),
                   sk_t_scale255<G_LUM_BITS>(SkColorGetG(color) >> (8 - G_LUM_BITS)),
                   sk_t_scale255<B_LUM_BITS>(SkColorGetB(color) >> (8 - B_LUM_BITS)));
>>>>>>> miniblink49
    }

    /** The type of the mask pre-blend which will be returned from preBlend(SkColor). */
    typedef SkTMaskPreBlend<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS> PreBlend;

    /**
     * Provides access to the tables appropriate for converting linear alpha
     * values into gamma correcting alpha values when drawing the given color
     * through the mask. The destination color will be approximated.
     */
    PreBlend preBlend(SkColor color) const;

    /**
     * Get dimensions for the full table set, so it can be allocated as a block.
     */
<<<<<<< HEAD
    void getGammaTableDimensions(int* tableWidth, int* numTables) const
    {
=======
    void getGammaTableDimensions(int* tableWidth, int* numTables) const {
>>>>>>> miniblink49
        *tableWidth = 256;
        *numTables = (1 << MAX_LUM_BITS);
    }

    /**
     * Provides direct access to the full table set, so it can be uploaded
     * into a texture.
     */
<<<<<<< HEAD
    const uint8_t* getGammaTables() const
    {
        return (const uint8_t*)fGammaTables;
    }

private:
    static const int MAX_LUM_BITS = B_LUM_BITS > (R_LUM_BITS > G_LUM_BITS ? R_LUM_BITS : G_LUM_BITS)
        ? B_LUM_BITS
        : (R_LUM_BITS > G_LUM_BITS ? R_LUM_BITS : G_LUM_BITS);
=======
    const uint8_t* getGammaTables() const {
        return (const uint8_t*) fGammaTables;
    }
    
private:
    static const int MAX_LUM_BITS =
          B_LUM_BITS > (R_LUM_BITS > G_LUM_BITS ? R_LUM_BITS : G_LUM_BITS)
        ? B_LUM_BITS : (R_LUM_BITS > G_LUM_BITS ? R_LUM_BITS : G_LUM_BITS);
>>>>>>> miniblink49
    uint8_t fGammaTables[1 << MAX_LUM_BITS][256];
    bool fIsLinear;

    typedef SkRefCnt INHERITED;
};

<<<<<<< HEAD
=======

>>>>>>> miniblink49
/**
 * SkTMaskPreBlend is a tear-off of SkTMaskGamma. It provides the tables to
 * convert a linear alpha value for a given channel to a gamma correcting alpha
 * value for that channel. This class is immutable.
 *
<<<<<<< HEAD
 * If fR, fG, or fB is nullptr, all of them will be. This indicates that no mask
 * pre blend should be applied. SkTMaskPreBlend::isApplicable() is provided as
 * a convenience function to test for the absence of this case.
 */
template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS>
class SkTMaskPreBlend {
private:
    SkTMaskPreBlend(const SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>* parent,
        const uint8_t* r, const uint8_t* g, const uint8_t* b)
        : fParent(SkSafeRef(parent))
        , fR(r)
        , fG(g)
        , fB(b)
    {
    }

    SkAutoTUnref<const SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>> fParent;
    friend class SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>;

public:
    /** Creates a non applicable SkTMaskPreBlend. */
    SkTMaskPreBlend()
        : fParent()
        , fR(nullptr)
        , fG(nullptr)
        , fB(nullptr)
    {
    }
=======
 * If fR, fG, or fB is NULL, all of them will be. This indicates that no mask
 * pre blend should be applied. SkTMaskPreBlend::isApplicable() is provided as
 * a convenience function to test for the absence of this case.
 */
template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS> class SkTMaskPreBlend {
private:
    SkTMaskPreBlend(const SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>* parent,
                    const uint8_t* r, const uint8_t* g, const uint8_t* b)
    : fParent(SkSafeRef(parent)), fR(r), fG(g), fB(b) { }

    SkAutoTUnref<const SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS> > fParent;
    friend class SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>;
public:
    /** Creates a non applicable SkTMaskPreBlend. */
    SkTMaskPreBlend() : fParent(), fR(NULL), fG(NULL), fB(NULL) { }
>>>>>>> miniblink49

    /**
     * This copy contructor exists for correctness, but should never be called
     * when return value optimization is enabled.
     */
    SkTMaskPreBlend(const SkTMaskPreBlend<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>& that)
<<<<<<< HEAD
        : fParent(SkSafeRef(that.fParent.get()))
        , fR(that.fR)
        , fG(that.fG)
        , fB(that.fB)
    {
    }

    ~SkTMaskPreBlend() { }

    /** True if this PreBlend should be applied. When false, fR, fG, and fB are nullptr. */
=======
    : fParent(SkSafeRef(that.fParent.get())), fR(that.fR), fG(that.fG), fB(that.fB) { }

    ~SkTMaskPreBlend() { }

    /** True if this PreBlend should be applied. When false, fR, fG, and fB are NULL. */
>>>>>>> miniblink49
    bool isApplicable() const { return SkToBool(this->fG); }

    const uint8_t* fR;
    const uint8_t* fG;
    const uint8_t* fB;
};

template <int R_LUM_BITS, int G_LUM_BITS, int B_LUM_BITS>
SkTMaskPreBlend<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>
<<<<<<< HEAD
SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>::preBlend(SkColor color) const
{
=======
SkTMaskGamma<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>::preBlend(SkColor color) const {
>>>>>>> miniblink49
    return fIsLinear ? SkTMaskPreBlend<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>()
                     : SkTMaskPreBlend<R_LUM_BITS, G_LUM_BITS, B_LUM_BITS>(this,
                         fGammaTables[SkColorGetR(color) >> (8 - MAX_LUM_BITS)],
                         fGammaTables[SkColorGetG(color) >> (8 - MAX_LUM_BITS)],
                         fGammaTables[SkColorGetB(color) >> (8 - MAX_LUM_BITS)]);
}

///@{
/**
 *  If APPLY_LUT is false, returns component unchanged.
 *  If APPLY_LUT is true, returns lut[component].
 *  @param APPLY_LUT whether or not the look-up table should be applied to component.
 *  @component the initial component.
 *  @lut a look-up table which transforms the component.
 */
<<<<<<< HEAD
template <bool APPLY_LUT>
static inline U8CPU sk_apply_lut_if(U8CPU component, const uint8_t*)
{
    return component;
}
template <>
/*static*/ inline U8CPU sk_apply_lut_if<true>(U8CPU component, const uint8_t* lut)
{
=======
template<bool APPLY_LUT> static inline U8CPU sk_apply_lut_if(U8CPU component, const uint8_t*) {
    return component;
}
template<> /*static*/ inline U8CPU sk_apply_lut_if<true>(U8CPU component, const uint8_t* lut) {
>>>>>>> miniblink49
    return lut[component];
}
///@}

#endif
