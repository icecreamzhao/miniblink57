/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrix.h"
#include "SkOpEdgeBuilder.h"
<<<<<<< HEAD
#include "SkPathOps.h"
#include "SkPathOpsCommon.h"
#include "SkPathPriv.h"

static bool one_contour(const SkPath& path)
{
    SkChunkAlloc allocator(256);
    int verbCount = path.countVerbs();
    uint8_t* verbs = (uint8_t*)allocator.alloc(sizeof(uint8_t) * verbCount,
        SkChunkAlloc::kThrow_AllocFailType);
    (void)path.getVerbs(verbs, verbCount);
=======
#include "SkPathPriv.h"
#include "SkPathOps.h"
#include "SkPathOpsCommon.h"

static bool one_contour(const SkPath& path) {
    SkChunkAlloc allocator(256);
    int verbCount = path.countVerbs();
    uint8_t* verbs = (uint8_t*) allocator.alloc(sizeof(uint8_t) * verbCount,
            SkChunkAlloc::kThrow_AllocFailType);
    (void) path.getVerbs(verbs, verbCount);
>>>>>>> miniblink49
    for (int index = 1; index < verbCount; ++index) {
        if (verbs[index] == SkPath::kMove_Verb) {
            return false;
        }
    }
    return true;
}

<<<<<<< HEAD
bool FixWinding(SkPath* path)
{
=======
void FixWinding(SkPath* path) {
>>>>>>> miniblink49
    SkPath::FillType fillType = path->getFillType();
    if (fillType == SkPath::kInverseEvenOdd_FillType) {
        fillType = SkPath::kInverseWinding_FillType;
    } else if (fillType == SkPath::kEvenOdd_FillType) {
        fillType = SkPath::kWinding_FillType;
    }
    SkPathPriv::FirstDirection dir;
    if (one_contour(*path) && SkPathPriv::CheapComputeFirstDirection(*path, &dir)) {
        if (dir != SkPathPriv::kCCW_FirstDirection) {
            SkPath temp;
            temp.reverseAddPath(*path);
            *path = temp;
        }
        path->setFillType(fillType);
<<<<<<< HEAD
        return true;
    }
    SkChunkAlloc allocator(4096);
    SkOpContourHead contourHead;
    SkOpGlobalState globalState(nullptr, &contourHead SkDEBUGPARAMS(false) SkDEBUGPARAMS(nullptr));
    SkOpEdgeBuilder builder(*path, &contourHead, &allocator, &globalState);
    builder.finish(&allocator);
    if (!contourHead.next()) {
        return false;
    }
=======
        return;
    }
    SkChunkAlloc allocator(4096);
    SkOpContourHead contourHead;
    SkOpGlobalState globalState(NULL, &contourHead);
    SkOpEdgeBuilder builder(*path, &contourHead, &allocator, &globalState);
    builder.finish(&allocator);
    SkASSERT(contourHead.next());
>>>>>>> miniblink49
    contourHead.resetReverse();
    bool writePath = false;
    SkOpSpan* topSpan;
    globalState.setPhase(SkOpGlobalState::kFixWinding);
    while ((topSpan = FindSortableTop(&contourHead))) {
        SkOpSegment* topSegment = topSpan->segment();
        SkOpContour* topContour = topSegment->contour();
        SkASSERT(topContour->isCcw() >= 0);
#if DEBUG_WINDING
<<<<<<< HEAD
        SkDebugf("%s id=%d nested=%d ccw=%d\n", __FUNCTION__,
            topSegment->debugID(), globalState.nested(), topContour->isCcw());
=======
        SkDebugf("%s id=%d nested=%d ccw=%d\n",  __FUNCTION__,
                topSegment->debugID(), globalState.nested(), topContour->isCcw());
>>>>>>> miniblink49
#endif
        if ((globalState.nested() & 1) != SkToBool(topContour->isCcw())) {
            topContour->setReverse();
            writePath = true;
        }
        topContour->markDone();
        globalState.clearNested();
    }
    if (!writePath) {
        path->setFillType(fillType);
<<<<<<< HEAD
        return true;
=======
        return;
>>>>>>> miniblink49
    }
    SkPath empty;
    SkPathWriter woundPath(empty);
    SkOpContour* test = &contourHead;
    do {
        if (test->reversed()) {
            test->toReversePath(&woundPath);
        } else {
            test->toPath(&woundPath);
        }
    } while ((test = test->next()));
    *path = *woundPath.nativePath();
    path->setFillType(fillType);
<<<<<<< HEAD
    return true;
}

void SkOpBuilder::add(const SkPath& path, SkPathOp op)
{
=======
}

void SkOpBuilder::add(const SkPath& path, SkPathOp op) {
>>>>>>> miniblink49
    if (0 == fOps.count() && op != kUnion_SkPathOp) {
        fPathRefs.push_back() = SkPath();
        *fOps.append() = kUnion_SkPathOp;
    }
    fPathRefs.push_back() = path;
    *fOps.append() = op;
}

<<<<<<< HEAD
void SkOpBuilder::reset()
{
=======
void SkOpBuilder::reset() {
>>>>>>> miniblink49
    fPathRefs.reset();
    fOps.reset();
}

/* OPTIMIZATION: Union doesn't need to be all-or-nothing. A run of three or more convex
   paths with union ops could be locally resolved and still improve over doing the
   ops one at a time. */
<<<<<<< HEAD
bool SkOpBuilder::resolve(SkPath* result)
{
=======
bool SkOpBuilder::resolve(SkPath* result) {
>>>>>>> miniblink49
    SkPath original = *result;
    int count = fOps.count();
    bool allUnion = true;
    SkPathPriv::FirstDirection firstDir = SkPathPriv::kUnknown_FirstDirection;
    for (int index = 0; index < count; ++index) {
        SkPath* test = &fPathRefs[index];
        if (kUnion_SkPathOp != fOps[index] || test->isInverseFillType()) {
            allUnion = false;
            break;
        }
        // If all paths are convex, track direction, reversing as needed.
        if (test->isConvex()) {
            SkPathPriv::FirstDirection dir;
            if (!SkPathPriv::CheapComputeFirstDirection(*test, &dir)) {
                allUnion = false;
                break;
            }
            if (firstDir == SkPathPriv::kUnknown_FirstDirection) {
                firstDir = dir;
            } else if (firstDir != dir) {
                SkPath temp;
                temp.reverseAddPath(*test);
                *test = temp;
            }
            continue;
        }
        // If the path is not convex but its bounds do not intersect the others, simplify is enough.
        const SkRect& testBounds = test->getBounds();
        for (int inner = 0; inner < index; ++inner) {
            // OPTIMIZE: check to see if the contour bounds do not intersect other contour bounds?
            if (SkRect::Intersects(fPathRefs[inner].getBounds(), testBounds)) {
                allUnion = false;
                break;
            }
        }
    }
    if (!allUnion) {
        *result = fPathRefs[0];
        for (int index = 1; index < count; ++index) {
            if (!Op(*result, fPathRefs[index], fOps[index], result)) {
                reset();
                *result = original;
                return false;
            }
        }
        reset();
        return true;
    }
    SkPath sum;
    for (int index = 0; index < count; ++index) {
        if (!Simplify(fPathRefs[index], &fPathRefs[index])) {
            reset();
            *result = original;
            return false;
        }
        if (!fPathRefs[index].isEmpty()) {
            // convert the even odd result back to winding form before accumulating it
<<<<<<< HEAD
            if (!FixWinding(&fPathRefs[index])) {
                *result = original;
                return false;
            }
=======
            FixWinding(&fPathRefs[index]);
>>>>>>> miniblink49
            sum.addPath(fPathRefs[index]);
        }
    }
    reset();
    bool success = Simplify(sum, result);
    if (!success) {
        *result = original;
    }
    return success;
}
