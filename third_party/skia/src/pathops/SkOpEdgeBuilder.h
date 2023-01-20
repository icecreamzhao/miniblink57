/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkOpEdgeBuilder_DEFINED
#define SkOpEdgeBuilder_DEFINED

#include "SkOpContour.h"
#include "SkPathWriter.h"

class SkOpEdgeBuilder {
public:
    SkOpEdgeBuilder(const SkPathWriter& path, SkOpContour* contours2, SkChunkAlloc* allocator,
<<<<<<< HEAD
        SkOpGlobalState* globalState)
        : fAllocator(allocator) // FIXME: replace with const, tune this
        , fGlobalState(globalState)
        , fPath(path.nativePath())
        , fContoursHead(contours2)
        , fAllowOpenContours(true)
    {
=======
            SkOpGlobalState* globalState)
        : fAllocator(allocator)  // FIXME: replace with const, tune this
        , fGlobalState(globalState)
        , fPath(path.nativePath())
        , fContoursHead(contours2)
        , fAllowOpenContours(true) {
>>>>>>> miniblink49
        init();
    }

    SkOpEdgeBuilder(const SkPath& path, SkOpContour* contours2, SkChunkAlloc* allocator,
<<<<<<< HEAD
        SkOpGlobalState* globalState)
=======
            SkOpGlobalState* globalState)
>>>>>>> miniblink49
        : fAllocator(allocator)
        , fGlobalState(globalState)
        , fPath(&path)
        , fContoursHead(contours2)
<<<<<<< HEAD
        , fAllowOpenContours(false)
    {
=======
        , fAllowOpenContours(false) {
>>>>>>> miniblink49
        init();
    }

    void addOperand(const SkPath& path);

<<<<<<< HEAD
    void complete()
    {
        if (fCurrentContour && fCurrentContour->count()) {
            fCurrentContour->complete();
            fCurrentContour = nullptr;
=======
    void complete() {
        if (fCurrentContour && fCurrentContour->count()) {
            fCurrentContour->complete();
            fCurrentContour = NULL;
>>>>>>> miniblink49
        }
    }

    int count() const;
<<<<<<< HEAD
    bool finish(SkChunkAlloc*);

    const SkOpContour* head() const
    {
=======
    bool finish(SkChunkAlloc* );

    const SkOpContour* head() const {
>>>>>>> miniblink49
        return fContoursHead;
    }

    void init();
    bool unparseable() const { return fUnparseable; }
    SkPathOpsMask xorMask() const { return fXorMask[fOperand]; }

private:
    void closeContour(const SkPoint& curveEnd, const SkPoint& curveStart);
    bool close();
    int preFetch();
<<<<<<< HEAD
    bool walk(SkChunkAlloc*);
=======
    bool walk(SkChunkAlloc* );
>>>>>>> miniblink49

    SkChunkAlloc* fAllocator;
    SkOpGlobalState* fGlobalState;
    const SkPath* fPath;
    SkTDArray<SkPoint> fPathPts;
    SkTDArray<SkScalar> fWeights;
    SkTDArray<uint8_t> fPathVerbs;
    SkOpContour* fCurrentContour;
    SkOpContour* fContoursHead;
    SkPathOpsMask fXorMask[2];
    int fSecondHalf;
    bool fOperand;
    bool fAllowOpenContours;
    bool fUnparseable;
};

#endif
