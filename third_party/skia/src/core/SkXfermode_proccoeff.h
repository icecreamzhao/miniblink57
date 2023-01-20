/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkXfermode_proccoeff_DEFINED
#define SkXfermode_proccoeff_DEFINED

<<<<<<< HEAD
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkXfermode.h"

struct ProcCoeff {
    SkXfermodeProc fProc;
    SkXfermodeProc4f fProc4f;
    SkXfermode::Coeff fSC;
    SkXfermode::Coeff fDC;
};

#define CANNOT_USE_COEFF SkXfermode::Coeff(-1)

class SK_API SkProcCoeffXfermode : public SkXfermode {
public:
    SkProcCoeffXfermode(const ProcCoeff& rec, Mode mode)
    {
=======
#include "SkXfermode.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"

struct ProcCoeff {
    SkXfermodeProc      fProc;
    SkXfermode::Coeff   fSC;
    SkXfermode::Coeff   fDC;
};

#define CANNOT_USE_COEFF    SkXfermode::Coeff(-1)

class SK_API SkProcCoeffXfermode : public SkXfermode {
public:
    SkProcCoeffXfermode(const ProcCoeff& rec, Mode mode) {
>>>>>>> miniblink49
        fMode = mode;
        fProc = rec.fProc;
        // these may be valid, or may be CANNOT_USE_COEFF
        fSrcCoeff = rec.fSC;
        fDstCoeff = rec.fDC;
    }

    void xfer32(SkPMColor dst[], const SkPMColor src[], int count,
<<<<<<< HEAD
        const SkAlpha aa[]) const override;
    void xfer16(uint16_t dst[], const SkPMColor src[], int count,
        const SkAlpha aa[]) const override;
    void xferA8(SkAlpha dst[], const SkPMColor src[], int count,
        const SkAlpha aa[]) const override;
=======
                const SkAlpha aa[]) const override;
    void xfer16(uint16_t dst[], const SkPMColor src[], int count,
                const SkAlpha aa[]) const override;
    void xferA8(SkAlpha dst[], const SkPMColor src[], int count,
                const SkAlpha aa[]) const override;
>>>>>>> miniblink49

    bool asMode(Mode* mode) const override;

    bool supportsCoverageAsAlpha() const override;

    bool isOpaque(SkXfermode::SrcColorOpacity opacityType) const override;

#if SK_SUPPORT_GPU
<<<<<<< HEAD
    sk_sp<GrFragmentProcessor> makeFragmentProcessorForImageFilter(
        sk_sp<GrFragmentProcessor>) const override;
    sk_sp<GrXPFactory> asXPFactory() const override;
=======
    bool asFragmentProcessor(GrFragmentProcessor**, GrProcessorDataManager*,
                             GrTexture* background) const override;

    bool asXPFactory(GrXPFactory**) const override;
>>>>>>> miniblink49
#endif

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkProcCoeffXfermode)

protected:
    void flatten(SkWriteBuffer& buffer) const override;

    Mode getMode() const { return fMode; }

    SkXfermodeProc getProc() const { return fProc; }

private:
<<<<<<< HEAD
    SkXfermodeProc fProc;
    Mode fMode;
    Coeff fSrcCoeff, fDstCoeff;
=======
    SkXfermodeProc  fProc;
    Mode            fMode;
    Coeff           fSrcCoeff, fDstCoeff;
>>>>>>> miniblink49

    friend class SkXfermode;

    typedef SkXfermode INHERITED;
};

#endif // #ifndef SkXfermode_proccoeff_DEFINED
