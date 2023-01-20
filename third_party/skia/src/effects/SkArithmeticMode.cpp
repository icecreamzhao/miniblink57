/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkArithmeticMode.h"
#include "SkColorPriv.h"
<<<<<<< HEAD
#include "SkNx.h"
#include "SkReadBuffer.h"
#include "SkString.h"
#include "SkUnPreMultiply.h"
#include "SkWriteBuffer.h"
=======
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkString.h"
#include "SkUnPreMultiply.h"
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
#include "SkArithmeticMode_gpu.h"
#endif

<<<<<<< HEAD
class SkArithmeticMode_scalar : public SkXfermode {
public:
    SkArithmeticMode_scalar(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4,
        bool enforcePMColor)
    {
=======
static const bool gUseUnpremul = false;

class SkArithmeticMode_scalar : public SkXfermode {
public:
    static SkArithmeticMode_scalar* Create(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4,
                                           bool enforcePMColor) {
        return SkNEW_ARGS(SkArithmeticMode_scalar, (k1, k2, k3, k4, enforcePMColor));
    }

    virtual void xfer32(SkPMColor dst[], const SkPMColor src[], int count,
                        const SkAlpha aa[]) const override;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkArithmeticMode_scalar)

#if SK_SUPPORT_GPU
    bool asFragmentProcessor(GrFragmentProcessor**, GrProcessorDataManager*,
                             GrTexture* background) const override;

    bool asXPFactory(GrXPFactory**) const override;
#endif

private:
    SkArithmeticMode_scalar(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor) {
>>>>>>> miniblink49
        fK[0] = k1;
        fK[1] = k2;
        fK[2] = k3;
        fK[3] = k4;
        fEnforcePMColor = enforcePMColor;
    }

<<<<<<< HEAD
    void xfer32(SkPMColor[], const SkPMColor[], int count, const SkAlpha[]) const override;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkArithmeticMode_scalar)

#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> makeFragmentProcessorForImageFilter(
        sk_sp<GrFragmentProcessor> dst) const override;
    sk_sp<GrXPFactory> asXPFactory() const override;
#endif

private:
    void flatten(SkWriteBuffer& buffer) const override
    {
=======
    void flatten(SkWriteBuffer& buffer) const override {
>>>>>>> miniblink49
        buffer.writeScalar(fK[0]);
        buffer.writeScalar(fK[1]);
        buffer.writeScalar(fK[2]);
        buffer.writeScalar(fK[3]);
        buffer.writeBool(fEnforcePMColor);
    }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
    SkScalar fK[4];
    bool fEnforcePMColor;

    friend class SkArithmeticMode;

    typedef SkXfermode INHERITED;
};

<<<<<<< HEAD
sk_sp<SkFlattenable> SkArithmeticMode_scalar::CreateProc(SkReadBuffer& buffer)
{
=======
SkFlattenable* SkArithmeticMode_scalar::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    const SkScalar k1 = buffer.readScalar();
    const SkScalar k2 = buffer.readScalar();
    const SkScalar k3 = buffer.readScalar();
    const SkScalar k4 = buffer.readScalar();
    const bool enforcePMColor = buffer.readBool();
<<<<<<< HEAD
    return SkArithmeticMode::Make(k1, k2, k3, k4, enforcePMColor);
}

void SkArithmeticMode_scalar::xfer32(SkPMColor dst[], const SkPMColor src[],
    int count, const SkAlpha aaCoverage[]) const
{
    const Sk4f k1 = fK[0] * (1 / 255.0f),
               k2 = fK[1],
               k3 = fK[2],
               k4 = fK[3] * 255.0f + 0.5f;

    auto pin = [](float min, const Sk4f& val, float max) {
        return Sk4f::Max(min, Sk4f::Min(val, max));
    };

    for (int i = 0; i < count; i++) {
        if (aaCoverage && aaCoverage[i] == 0) {
            continue;
        }

        Sk4f s = SkNx_cast<float>(Sk4b::Load(src + i)),
             d = SkNx_cast<float>(Sk4b::Load(dst + i)),
             r = pin(0, k1 * s * d + k2 * s + k3 * d + k4, 255);

        if (fEnforcePMColor) {
            Sk4f a = SkNx_shuffle<3, 3, 3, 3>(r);
            r = Sk4f::Min(a, r);
        }

        if (aaCoverage && aaCoverage[i] != 255) {
            Sk4f c = aaCoverage[i] * (1 / 255.0f);
            r = d + (r - d) * c;
        }

        SkNx_cast<uint8_t>(r).store(dst + i);
=======
    return Create(k1, k2, k3, k4, enforcePMColor);
}

static int pinToByte(int value) {
    if (value < 0) {
        value = 0;
    } else if (value > 255) {
        value = 255;
    }
    return value;
}

static int arith(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4,
                 int src, int dst) {
    SkScalar result = SkScalarMul(k1, src * dst) +
                      SkScalarMul(k2, src) +
                      SkScalarMul(k3, dst) +
                      k4;
    int res = SkScalarRoundToInt(result);
    return pinToByte(res);
}

static int blend(int src, int dst, int scale) {
    return dst + ((src - dst) * scale >> 8);
}

static bool needsUnpremul(int alpha) {
    return 0 != alpha && 0xFF != alpha;
}

void SkArithmeticMode_scalar::xfer32(SkPMColor dst[], const SkPMColor src[],
                                 int count, const SkAlpha aaCoverage[]) const {
    SkScalar k1 = fK[0] / 255;
    SkScalar k2 = fK[1];
    SkScalar k3 = fK[2];
    SkScalar k4 = fK[3] * 255;

    for (int i = 0; i < count; ++i) {
        if ((NULL == aaCoverage) || aaCoverage[i]) {
            SkPMColor sc = src[i];
            SkPMColor dc = dst[i];

            int a, r, g, b;

            if (gUseUnpremul) {
                int sa = SkGetPackedA32(sc);
                int da = SkGetPackedA32(dc);

                int srcNeedsUnpremul = needsUnpremul(sa);
                int dstNeedsUnpremul = needsUnpremul(da);

                if (!srcNeedsUnpremul && !dstNeedsUnpremul) {
                    a = arith(k1, k2, k3, k4, sa, da);
                    r = arith(k1, k2, k3, k4, SkGetPackedR32(sc), SkGetPackedR32(dc));
                    g = arith(k1, k2, k3, k4, SkGetPackedG32(sc), SkGetPackedG32(dc));
                    b = arith(k1, k2, k3, k4, SkGetPackedB32(sc), SkGetPackedB32(dc));
                } else {
                    int sr = SkGetPackedR32(sc);
                    int sg = SkGetPackedG32(sc);
                    int sb = SkGetPackedB32(sc);
                    if (srcNeedsUnpremul) {
                        SkUnPreMultiply::Scale scale = SkUnPreMultiply::GetScale(sa);
                        sr = SkUnPreMultiply::ApplyScale(scale, sr);
                        sg = SkUnPreMultiply::ApplyScale(scale, sg);
                        sb = SkUnPreMultiply::ApplyScale(scale, sb);
                    }

                    int dr = SkGetPackedR32(dc);
                    int dg = SkGetPackedG32(dc);
                    int db = SkGetPackedB32(dc);
                    if (dstNeedsUnpremul) {
                        SkUnPreMultiply::Scale scale = SkUnPreMultiply::GetScale(da);
                        dr = SkUnPreMultiply::ApplyScale(scale, dr);
                        dg = SkUnPreMultiply::ApplyScale(scale, dg);
                        db = SkUnPreMultiply::ApplyScale(scale, db);
                    }

                    a = arith(k1, k2, k3, k4, sa, da);
                    r = arith(k1, k2, k3, k4, sr, dr);
                    g = arith(k1, k2, k3, k4, sg, dg);
                    b = arith(k1, k2, k3, k4, sb, db);
                }
            } else {
                a = arith(k1, k2, k3, k4, SkGetPackedA32(sc), SkGetPackedA32(dc));
                r = arith(k1, k2, k3, k4, SkGetPackedR32(sc), SkGetPackedR32(dc));
                g = arith(k1, k2, k3, k4, SkGetPackedG32(sc), SkGetPackedG32(dc));
                b = arith(k1, k2, k3, k4, SkGetPackedB32(sc), SkGetPackedB32(dc));
                if (fEnforcePMColor) {
                    r = SkMin32(r, a);
                    g = SkMin32(g, a);
                    b = SkMin32(b, a);
                }
            }

            // apply antialias coverage if necessary
            if (aaCoverage && 0xFF != aaCoverage[i]) {
                int scale = aaCoverage[i] + (aaCoverage[i] >> 7);
                a = blend(a, SkGetPackedA32(sc), scale);
                r = blend(r, SkGetPackedR32(sc), scale);
                g = blend(g, SkGetPackedG32(sc), scale);
                b = blend(b, SkGetPackedB32(sc), scale);
            }

            // turn the result back into premul
            if (gUseUnpremul && (0xFF != a)) {
                int scale = a + (a >> 7);
                r = SkAlphaMul(r, scale);
                g = SkAlphaMul(g, scale);
                b = SkAlphaMul(b, scale);
            }
            dst[i] = fEnforcePMColor ? SkPackARGB32(a, r, g, b) : SkPackARGB32NoCheck(a, r, g, b);
        }
>>>>>>> miniblink49
    }
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkArithmeticMode_scalar::toString(SkString* str) const
{
=======
void SkArithmeticMode_scalar::toString(SkString* str) const {
>>>>>>> miniblink49
    str->append("SkArithmeticMode_scalar: ");
    for (int i = 0; i < 4; ++i) {
        str->appendScalar(fK[i]);
        str->append(" ");
    }
    str->appendS32(fEnforcePMColor ? 1 : 0);
}
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkXfermode> SkArithmeticMode::Make(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4,
    bool enforcePMColor)
{
    if (SkScalarNearlyZero(k1) && SkScalarNearlyEqual(k2, SK_Scalar1) && SkScalarNearlyZero(k3) && SkScalarNearlyZero(k4)) {
        return SkXfermode::Make(SkXfermode::kSrc_Mode);
    } else if (SkScalarNearlyZero(k1) && SkScalarNearlyZero(k2) && SkScalarNearlyEqual(k3, SK_Scalar1) && SkScalarNearlyZero(k4)) {
        return SkXfermode::Make(SkXfermode::kDst_Mode);
    }
    return sk_make_sp<SkArithmeticMode_scalar>(k1, k2, k3, k4, enforcePMColor);
}

//////////////////////////////////////////////////////////////////////////////

#if SK_SUPPORT_GPU
sk_sp<GrFragmentProcessor> SkArithmeticMode_scalar::makeFragmentProcessorForImageFilter(
    sk_sp<GrFragmentProcessor> dst) const
{
    return GrArithmeticFP::Make(SkScalarToFloat(fK[0]),
        SkScalarToFloat(fK[1]),
        SkScalarToFloat(fK[2]),
        SkScalarToFloat(fK[3]),
        fEnforcePMColor,
        std::move(dst));
}

sk_sp<GrXPFactory> SkArithmeticMode_scalar::asXPFactory() const
{
    return GrArithmeticXPFactory::Make(SkScalarToFloat(fK[0]),
        SkScalarToFloat(fK[1]),
        SkScalarToFloat(fK[2]),
        SkScalarToFloat(fK[3]),
        fEnforcePMColor);
=======
static bool fitsInBits(SkScalar x, int bits) {
    return SkScalarAbs(x) < (1 << (bits - 1));
}

#if 0 // UNUSED
static int32_t toDot8(SkScalar x) {
    return (int32_t)(x * 256);
}
#endif

SkXfermode* SkArithmeticMode::Create(SkScalar k1, SkScalar k2,
                                     SkScalar k3, SkScalar k4,
                                     bool enforcePMColor) {
    if (fitsInBits(k1, 8) && fitsInBits(k2, 16) &&
        fitsInBits(k2, 16) && fitsInBits(k2, 24)) {

#if 0 // UNUSED
        int32_t i1 = toDot8(k1);
        int32_t i2 = toDot8(k2);
        int32_t i3 = toDot8(k3);
        int32_t i4 = toDot8(k4);
        if (i1) {
            return SkNEW_ARGS(SkArithmeticMode_quad, (i1, i2, i3, i4));
        }
        if (0 == i2) {
            return SkNEW_ARGS(SkArithmeticMode_dst, (i3, i4));
        }
        if (0 == i3) {
            return SkNEW_ARGS(SkArithmeticMode_src, (i2, i4));
        }
        return SkNEW_ARGS(SkArithmeticMode_linear, (i2, i3, i4));
#endif
    }
    return SkArithmeticMode_scalar::Create(k1, k2, k3, k4, enforcePMColor);
}


//////////////////////////////////////////////////////////////////////////////

#if SK_SUPPORT_GPU
bool SkArithmeticMode_scalar::asFragmentProcessor(GrFragmentProcessor** fp,
                                                  GrProcessorDataManager* procDataManager,
                                                  GrTexture* background) const {
    if (fp) {
        *fp = GrArithmeticFP::Create(procDataManager,
                                     SkScalarToFloat(fK[0]),
                                     SkScalarToFloat(fK[1]),
                                     SkScalarToFloat(fK[2]),
                                     SkScalarToFloat(fK[3]),
                                     fEnforcePMColor,
                                     background);
    }
    return true;
}

bool SkArithmeticMode_scalar::asXPFactory(GrXPFactory** xpf) const {
    if (xpf) {
        *xpf = GrArithmeticXPFactory::Create(SkScalarToFloat(fK[0]),
                                             SkScalarToFloat(fK[1]),
                                             SkScalarToFloat(fK[2]),
                                             SkScalarToFloat(fK[3]),
                                             fEnforcePMColor);
    }
    return true;
>>>>>>> miniblink49
}

#endif

SK_DEFINE_FLATTENABLE_REGISTRAR_GROUP_START(SkArithmeticMode)
<<<<<<< HEAD
SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkArithmeticMode_scalar)
=======
    SK_DEFINE_FLATTENABLE_REGISTRAR_ENTRY(SkArithmeticMode_scalar)
>>>>>>> miniblink49
SK_DEFINE_FLATTENABLE_REGISTRAR_GROUP_END
