/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkColorCubeFilter_DEFINED
#define SkColorCubeFilter_DEFINED

<<<<<<< HEAD
#include "../private/SkOnce.h"
#include "../private/SkTemplates.h"
#include "SkColorFilter.h"
#include "SkData.h"
=======
#include "SkColorFilter.h"
#include "SkData.h"
#include "SkMutex.h"
>>>>>>> miniblink49

class SK_API SkColorCubeFilter : public SkColorFilter {
public:
    /** cubeData must containt a 3D data in the form of cube of the size:
     *  cubeDimension * cubeDimension * cubeDimension * sizeof(SkColor)
     *  This cube contains a transform where (x,y,z) maps to the (r,g,b).
<<<<<<< HEAD
     *  The alpha components of the colors must be 0xFF.
     */
    static sk_sp<SkColorFilter> Make(sk_sp<SkData> cubeData, int cubeDimension);

#ifdef SK_SUPPORT_LEGACY_COLORFILTER_PTR
    static SkColorFilter* Create(SkData* cubeData, int cubeDimension);
#endif
=======
     *  The alpha components of the colors are ignored (treated as 0xFF).
     */
    static SkColorFilter* Create(SkData* cubeData, int cubeDimension);
>>>>>>> miniblink49

    void filterSpan(const SkPMColor src[], int count, SkPMColor[]) const override;
    uint32_t getFlags() const override;

#if SK_SUPPORT_GPU
<<<<<<< HEAD
    sk_sp<GrFragmentProcessor> asFragmentProcessor(GrContext*) const override;
=======
   bool asFragmentProcessors(GrContext*, GrProcessorDataManager*,
                             SkTDArray<GrFragmentProcessor*>*) const override;
>>>>>>> miniblink49
#endif

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkColorCubeFilter)

protected:
<<<<<<< HEAD
    SkColorCubeFilter(sk_sp<SkData> cubeData, int cubeDimension);
=======
    SkColorCubeFilter(SkData* cubeData, int cubeDimension);
>>>>>>> miniblink49
    void flatten(SkWriteBuffer&) const override;

private:
    /** The cache is initialized on-demand when getProcessingLuts is called.
     */
    class ColorCubeProcesingCache {
    public:
        ColorCubeProcesingCache(int cubeDimension);

        void getProcessingLuts(const int* (*colorToIndex)[2],
<<<<<<< HEAD
            const SkScalar* (*colorToFactors)[2],
            const SkScalar** colorToScalar);
=======
                               const SkScalar* (*colorToFactors)[2],
                               const SkScalar** colorToScalar);
>>>>>>> miniblink49

        int cubeDimension() const { return fCubeDimension; }

    private:
        // Working pointers. If any of these is NULL,
        // we need to recompute the corresponding cache values.
        int* fColorToIndex[2];
        SkScalar* fColorToFactors[2];
        SkScalar* fColorToScalar;

<<<<<<< HEAD
        SkAutoTMalloc<uint8_t> fLutStorage;
=======
        SkAutoMalloc fLutStorage;
>>>>>>> miniblink49

        const int fCubeDimension;

        // Make sure we only initialize the caches once.
<<<<<<< HEAD
        SkOnce fLutsInitOnce;
=======
        SkMutex fLutsMutex;
        bool fLutsInited;
>>>>>>> miniblink49

        static void initProcessingLuts(ColorCubeProcesingCache* cache);
    };

<<<<<<< HEAD
    sk_sp<SkData> fCubeData;
=======
    SkAutoDataUnref fCubeData;
>>>>>>> miniblink49
    int32_t fUniqueID;

    mutable ColorCubeProcesingCache fCache;

    typedef SkColorFilter INHERITED;
};

#endif
