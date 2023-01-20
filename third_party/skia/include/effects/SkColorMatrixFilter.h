/*
 * Copyright 2007 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkColorMatrixFilter_DEFINED
#define SkColorMatrixFilter_DEFINED

#include "SkColorFilter.h"
#include "SkColorMatrix.h"

class SK_API SkColorMatrixFilter : public SkColorFilter {
public:
<<<<<<< HEAD
    /**
     *  Create a colorfilter that multiplies the RGB channels by one color, and
     *  then adds a second color, pinning the result for each component to
     *  [0..255]. The alpha components of the mul and add arguments
     *  are ignored.
     */
    static sk_sp<SkColorFilter> MakeLightingFilter(SkColor mul, SkColor add);

#ifdef SK_SUPPORT_LEGACY_COLORFILTER_PTR
    static SkColorFilter* Create(const SkColorMatrix& cm)
    {
        return SkColorFilter::MakeMatrixFilterRowMajor255(cm.fMat).release();
    }
    static SkColorFilter* Create(const SkScalar array[20])
    {
        return SkColorFilter::MakeMatrixFilterRowMajor255(array).release();
    }
    static SkColorFilter* CreateLightingFilter(SkColor mul, SkColor add)
    {
        return MakeLightingFilter(mul, add).release();
    }
#endif
=======
    static SkColorMatrixFilter* Create(const SkColorMatrix& cm) {
        return SkNEW_ARGS(SkColorMatrixFilter, (cm));
    }
    static SkColorMatrixFilter* Create(const SkScalar array[20]) {
        return SkNEW_ARGS(SkColorMatrixFilter, (array));
    }

    void filterSpan(const SkPMColor src[], int count, SkPMColor[]) const override;
    uint32_t getFlags() const override;
    bool asColorMatrix(SkScalar matrix[20]) const override;
    SkColorFilter* newComposed(const SkColorFilter*) const override;

#if SK_SUPPORT_GPU
    bool asFragmentProcessors(GrContext*, GrProcessorDataManager*,
                              SkTDArray<GrFragmentProcessor*>*) const override;
#endif

    struct State {
        int32_t fArray[20];
        int     fShift;
    };

    SK_TO_STRING_OVERRIDE()

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkColorMatrixFilter)

protected:
    explicit SkColorMatrixFilter(const SkColorMatrix&);
    explicit SkColorMatrixFilter(const SkScalar array[20]);
    void flatten(SkWriteBuffer&) const override;

private:
    SkColorMatrix   fMatrix;
    float           fTranspose[SkColorMatrix::kCount]; // for Sk4s

    typedef void (*Proc)(const State&, unsigned r, unsigned g, unsigned b,
                         unsigned a, int32_t result[4]);

    Proc        fProc;
    State       fState;
    uint32_t    fFlags;

    void initState(const SkScalar array[20]);

    typedef SkColorFilter INHERITED;
>>>>>>> miniblink49
};

#endif
