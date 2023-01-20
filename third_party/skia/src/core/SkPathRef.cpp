/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPathRef.h"
#include "SkBuffer.h"
#include "SkOnce.h"
#include "SkPath.h"
#include <limits>

//////////////////////////////////////////////////////////////////////////////
SkPathRef::Editor::Editor(SkAutoTUnref<SkPathRef>* pathRef,
    int incReserveVerbs,
    int incReservePoints)
=======
#include "SkBuffer.h"
#include "SkLazyPtr.h"
#include "SkPath.h"
#include "SkPathRef.h"

//////////////////////////////////////////////////////////////////////////////
SkPathRef::Editor::Editor(SkAutoTUnref<SkPathRef>* pathRef,
                          int incReserveVerbs,
                          int incReservePoints)
>>>>>>> miniblink49
{
    if ((*pathRef)->unique()) {
        (*pathRef)->incReserve(incReserveVerbs, incReservePoints);
    } else {
<<<<<<< HEAD
        SkPathRef* copy = new SkPathRef;
=======
        SkPathRef* copy = SkNEW(SkPathRef);
>>>>>>> miniblink49
        copy->copy(**pathRef, incReserveVerbs, incReservePoints);
        pathRef->reset(copy);
    }
    fPathRef = *pathRef;
<<<<<<< HEAD
    fPathRef->callGenIDChangeListeners();
=======
>>>>>>> miniblink49
    fPathRef->fGenerationID = 0;
    SkDEBUGCODE(sk_atomic_inc(&fPathRef->fEditorsAttached);)
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkPathRef::~SkPathRef()
{
    this->callGenIDChangeListeners();
    SkDEBUGCODE(this->validate();)
        sk_free(fPoints);

    SkDEBUGCODE(fPoints = nullptr;)
        SkDEBUGCODE(fVerbs = nullptr;)
            SkDEBUGCODE(fVerbCnt = 0x9999999;)
                SkDEBUGCODE(fPointCnt = 0xAAAAAAA;)
                    SkDEBUGCODE(fPointCnt = 0xBBBBBBB;)
                        SkDEBUGCODE(fGenerationID = 0xEEEEEEEE;)
                            SkDEBUGCODE(fEditorsAttached = 0x7777777;)
}

static SkPathRef* gEmpty = nullptr;

SkPathRef* SkPathRef::CreateEmpty()
{
    static SkOnce once;
    once([] {
        gEmpty = new SkPathRef;
        gEmpty->computeBounds(); // Avoids races later to be the first to do this.
    });
    return SkRef(gEmpty);
}

static void transform_dir_and_start(const SkMatrix& matrix, bool isRRect, bool* isCCW,
    unsigned* start)
{
    int inStart = *start;
    int rm = 0;
    if (isRRect) {
        // Degenerate rrect indices to oval indices and remember the remainder.
        // Ovals have one index per side whereas rrects have two.
        rm = inStart & /*0b1*/ 1;
        inStart /= 2;
    }
    // Is the antidiagonal non-zero (otherwise the diagonal is zero)
    int antiDiag;
    // Is the non-zero value in the top row (either kMScaleX or kMSkewX) negative
    int topNeg;
    // Are the two non-zero diagonal or antidiagonal values the same sign.
    int sameSign;
    if (matrix.get(SkMatrix::kMScaleX) != 0) {
        antiDiag = /*0b00*/ 0;
        if (matrix.get(SkMatrix::kMScaleX) > 0) {
            topNeg = /*0b00*/ 0;
            sameSign = matrix.get(SkMatrix::kMScaleY) > 0 ? /*0b01*/ 1 : /*0b00*/ 0;
        } else {
            topNeg = /*0b10*/ 2;
            sameSign = matrix.get(SkMatrix::kMScaleY) > 0 ? /*0b00*/ 0 : /*0b01*/ 1;
        }
    } else {
        antiDiag = /*0b01*/ 1;
        if (matrix.get(SkMatrix::kMSkewX) > 0) {
            topNeg = /*0b00*/ 0;
            sameSign = matrix.get(SkMatrix::kMSkewY) > 0 ? /*0b01*/ 1 : /*0b00*/ 0;
        } else {
            topNeg = /*0b10*/ 2;
            sameSign = matrix.get(SkMatrix::kMSkewY) > 0 ? /*0b00*/ 0 : /*0b01*/ 1;
        }
    }
    if (sameSign != antiDiag) {
        // This is a rotation (and maybe scale). The direction is unchanged.
        // Trust me on the start computation (or draw yourself some pictures)
        *start = (inStart + 4 - (topNeg | antiDiag)) % 4;
        SkASSERT(*start < 4);
        if (isRRect) {
            *start = 2 * *start + rm;
        }
    } else {
        // This is a mirror (and maybe scale). The direction is reversed.
        *isCCW = !*isCCW;
        // Trust me on the start computation (or draw yourself some pictures)
        *start = (6 + (topNeg | antiDiag) - inStart) % 4;
        SkASSERT(*start < 4);
        if (isRRect) {
            *start = 2 * *start + (rm ? 0 : 1);
        }
    }
}

void SkPathRef::CreateTransformedCopy(SkAutoTUnref<SkPathRef>* dst,
    const SkPathRef& src,
    const SkMatrix& matrix)
{
    SkDEBUGCODE(src.validate();) if (matrix.isIdentity())
    {
=======
// As a template argument, this must have external linkage.
SkPathRef* sk_create_empty_pathref() {
    SkPathRef* empty = SkNEW(SkPathRef);
    empty->computeBounds();   // Avoids races later to be the first to do this.
    return empty;
}

SK_DECLARE_STATIC_LAZY_PTR(SkPathRef, empty, sk_create_empty_pathref);

SkPathRef* SkPathRef::CreateEmpty() {
    return SkRef(empty.get());
}

void SkPathRef::CreateTransformedCopy(SkAutoTUnref<SkPathRef>* dst,
                                      const SkPathRef& src,
                                      const SkMatrix& matrix) {
    SkDEBUGCODE(src.validate();)
    if (matrix.isIdentity()) {
>>>>>>> miniblink49
        if (*dst != &src) {
            src.ref();
            dst->reset(const_cast<SkPathRef*>(&src));
            SkDEBUGCODE((*dst)->validate();)
        }
        return;
    }

    if (!(*dst)->unique()) {
<<<<<<< HEAD
        dst->reset(new SkPathRef);
=======
        dst->reset(SkNEW(SkPathRef));
>>>>>>> miniblink49
    }

    if (*dst != &src) {
        (*dst)->resetToSize(src.fVerbCnt, src.fPointCnt, src.fConicWeights.count());
<<<<<<< HEAD
        sk_careful_memcpy((*dst)->verbsMemWritable(), src.verbsMemBegin(),
            src.fVerbCnt * sizeof(uint8_t));
=======
        memcpy((*dst)->verbsMemWritable(), src.verbsMemBegin(), src.fVerbCnt * sizeof(uint8_t));
>>>>>>> miniblink49
        (*dst)->fConicWeights = src.fConicWeights;
    }

    SkASSERT((*dst)->countPoints() == src.countPoints());
    SkASSERT((*dst)->countVerbs() == src.countVerbs());
    SkASSERT((*dst)->fConicWeights.count() == src.fConicWeights.count());

    // Need to check this here in case (&src == dst)
    bool canXformBounds = !src.fBoundsIsDirty && matrix.rectStaysRect() && src.countPoints() > 1;

    matrix.mapPoints((*dst)->fPoints, src.points(), src.fPointCnt);

    /*
<<<<<<< HEAD
     *  Here we optimize the bounds computation, by noting if the bounds are
     *  already known, and if so, we just transform those as well and mark
     *  them as "known", rather than force the transformed path to have to
     *  recompute them.
     *
     *  Special gotchas if the path is effectively empty (<= 1 point) or
     *  if it is non-finite. In those cases bounds need to stay empty,
     *  regardless of the matrix.
     */
=======
        *  Here we optimize the bounds computation, by noting if the bounds are
        *  already known, and if so, we just transform those as well and mark
        *  them as "known", rather than force the transformed path to have to
        *  recompute them.
        *
        *  Special gotchas if the path is effectively empty (<= 1 point) or
        *  if it is non-finite. In those cases bounds need to stay empty,
        *  regardless of the matrix.
        */
>>>>>>> miniblink49
    if (canXformBounds) {
        (*dst)->fBoundsIsDirty = false;
        if (src.fIsFinite) {
            matrix.mapRect(&(*dst)->fBounds, src.fBounds);
            if (!((*dst)->fIsFinite = (*dst)->fBounds.isFinite())) {
                (*dst)->fBounds.setEmpty();
            }
        } else {
            (*dst)->fIsFinite = false;
            (*dst)->fBounds.setEmpty();
        }
    } else {
        (*dst)->fBoundsIsDirty = true;
    }

    (*dst)->fSegmentMask = src.fSegmentMask;

    // It's an oval only if it stays a rect.
<<<<<<< HEAD
    bool rectStaysRect = matrix.rectStaysRect();
    (*dst)->fIsOval = src.fIsOval && rectStaysRect;
    (*dst)->fIsRRect = src.fIsRRect && rectStaysRect;
    if ((*dst)->fIsOval || (*dst)->fIsRRect) {
        unsigned start = src.fRRectOrOvalStartIdx;
        bool isCCW = SkToBool(src.fRRectOrOvalIsCCW);
        transform_dir_and_start(matrix, (*dst)->fIsRRect, &isCCW, &start);
        (*dst)->fRRectOrOvalIsCCW = isCCW;
        (*dst)->fRRectOrOvalStartIdx = start;
    }
=======
    (*dst)->fIsOval = src.fIsOval && matrix.rectStaysRect();
>>>>>>> miniblink49

    SkDEBUGCODE((*dst)->validate();)
}

<<<<<<< HEAD
SkPathRef* SkPathRef::CreateFromBuffer(SkRBuffer* buffer)
{
    SkPathRef* ref = new SkPathRef;

    int32_t packed;
    if (!buffer->readS32(&packed)) {
        delete ref;
        return nullptr;
    }

    ref->fIsFinite = (packed >> kIsFinite_SerializationShift) & 1;
    uint8_t segmentMask = (packed >> kSegmentMask_SerializationShift) & 0xF;
    bool isOval = (packed >> kIsOval_SerializationShift) & 1;
    bool isRRect = (packed >> kIsRRect_SerializationShift) & 1;
    bool rrectOrOvalIsCCW = (packed >> kRRectOrOvalIsCCW_SerializationShift) & 1;
    unsigned rrectOrOvalStartIdx = (packed >> kRRectOrOvalStartIdx_SerializationShift) & 0x7;

    int32_t verbCount, pointCount, conicCount;
    ptrdiff_t maxPtrDiff = std::numeric_limits<ptrdiff_t>::max();
    if (!buffer->readU32(&(ref->fGenerationID)) || !buffer->readS32(&verbCount) || verbCount < 0 || static_cast<uint32_t>(verbCount) > maxPtrDiff / sizeof(uint8_t) || !buffer->readS32(&pointCount) || pointCount < 0 || static_cast<uint32_t>(pointCount) > maxPtrDiff / sizeof(SkPoint) || sizeof(uint8_t) * verbCount + sizeof(SkPoint) * pointCount > static_cast<size_t>(maxPtrDiff) || !buffer->readS32(&conicCount) || conicCount < 0) {
        delete ref;
        return nullptr;
=======
SkPathRef* SkPathRef::CreateFromBuffer(SkRBuffer* buffer) {
    SkPathRef* ref = SkNEW(SkPathRef);
    bool isOval;
    uint8_t segmentMask;

    int32_t packed;
    if (!buffer->readS32(&packed)) {
        SkDELETE(ref);
        return NULL;
    }

    ref->fIsFinite = (packed >> kIsFinite_SerializationShift) & 1;
    segmentMask = (packed >> kSegmentMask_SerializationShift) & 0xF;
    isOval  = (packed >> kIsOval_SerializationShift) & 1;

    int32_t verbCount, pointCount, conicCount;
    if (!buffer->readU32(&(ref->fGenerationID)) ||
        !buffer->readS32(&verbCount) ||
        !buffer->readS32(&pointCount) ||
        !buffer->readS32(&conicCount)) {
        SkDELETE(ref);
        return NULL;
>>>>>>> miniblink49
    }

    ref->resetToSize(verbCount, pointCount, conicCount);
    SkASSERT(verbCount == ref->countVerbs());
    SkASSERT(pointCount == ref->countPoints());
    SkASSERT(conicCount == ref->fConicWeights.count());

<<<<<<< HEAD
    if (!buffer->read(ref->verbsMemWritable(), verbCount * sizeof(uint8_t)) || !buffer->read(ref->fPoints, pointCount * sizeof(SkPoint)) || !buffer->read(ref->fConicWeights.begin(), conicCount * sizeof(SkScalar)) || !buffer->read(&ref->fBounds, sizeof(SkRect))) {
        delete ref;
        return nullptr;
=======
    if (!buffer->read(ref->verbsMemWritable(), verbCount * sizeof(uint8_t)) ||
        !buffer->read(ref->fPoints, pointCount * sizeof(SkPoint)) ||
        !buffer->read(ref->fConicWeights.begin(), conicCount * sizeof(SkScalar)) ||
        !buffer->read(&ref->fBounds, sizeof(SkRect))) {
        SkDELETE(ref);
        return NULL;
>>>>>>> miniblink49
    }
    ref->fBoundsIsDirty = false;

    // resetToSize clears fSegmentMask and fIsOval
    ref->fSegmentMask = segmentMask;
    ref->fIsOval = isOval;
<<<<<<< HEAD
    ref->fIsRRect = isRRect;
    ref->fRRectOrOvalIsCCW = rrectOrOvalIsCCW;
    ref->fRRectOrOvalStartIdx = rrectOrOvalStartIdx;
    return ref;
}

void SkPathRef::Rewind(SkAutoTUnref<SkPathRef>* pathRef)
{
    if ((*pathRef)->unique()) {
        SkDEBUGCODE((*pathRef)->validate();)(*pathRef)->callGenIDChangeListeners();
        (*pathRef)->fBoundsIsDirty = true; // this also invalidates fIsFinite
=======
    return ref;
}

void SkPathRef::Rewind(SkAutoTUnref<SkPathRef>* pathRef) {
    if ((*pathRef)->unique()) {
        SkDEBUGCODE((*pathRef)->validate();)
        (*pathRef)->fBoundsIsDirty = true;  // this also invalidates fIsFinite
>>>>>>> miniblink49
        (*pathRef)->fVerbCnt = 0;
        (*pathRef)->fPointCnt = 0;
        (*pathRef)->fFreeSpace = (*pathRef)->currSize();
        (*pathRef)->fGenerationID = 0;
        (*pathRef)->fConicWeights.rewind();
        (*pathRef)->fSegmentMask = 0;
        (*pathRef)->fIsOval = false;
<<<<<<< HEAD
        (*pathRef)->fIsRRect = false;
=======
>>>>>>> miniblink49
        SkDEBUGCODE((*pathRef)->validate();)
    } else {
        int oldVCnt = (*pathRef)->countVerbs();
        int oldPCnt = (*pathRef)->countPoints();
<<<<<<< HEAD
        pathRef->reset(new SkPathRef);
=======
        pathRef->reset(SkNEW(SkPathRef));
>>>>>>> miniblink49
        (*pathRef)->resetToSize(0, 0, 0, oldVCnt, oldPCnt);
    }
}

<<<<<<< HEAD
bool SkPathRef::operator==(const SkPathRef& ref) const
{
    SkDEBUGCODE(this->validate();)
        SkDEBUGCODE(ref.validate();)

        // We explicitly check fSegmentMask as a quick-reject. We could skip it,
        // since it is only a cache of info in the fVerbs, but its a fast way to
        // notice a difference
        if (fSegmentMask != ref.fSegmentMask)
    {
=======
bool SkPathRef::operator== (const SkPathRef& ref) const {
    SkDEBUGCODE(this->validate();)
    SkDEBUGCODE(ref.validate();)

    // We explicitly check fSegmentMask as a quick-reject. We could skip it,
    // since it is only a cache of info in the fVerbs, but its a fast way to
    // notice a difference
    if (fSegmentMask != ref.fSegmentMask) {
>>>>>>> miniblink49
        return false;
    }

    bool genIDMatch = fGenerationID && fGenerationID == ref.fGenerationID;
#ifdef SK_RELEASE
    if (genIDMatch) {
        return true;
    }
#endif
<<<<<<< HEAD
    if (fPointCnt != ref.fPointCnt || fVerbCnt != ref.fVerbCnt) {
=======
    if (fPointCnt != ref.fPointCnt ||
        fVerbCnt != ref.fVerbCnt) {
>>>>>>> miniblink49
        SkASSERT(!genIDMatch);
        return false;
    }
    if (0 == ref.fVerbCnt) {
        SkASSERT(0 == ref.fPointCnt);
        return true;
    }
    SkASSERT(this->verbsMemBegin() && ref.verbsMemBegin());
<<<<<<< HEAD
    if (0 != memcmp(this->verbsMemBegin(), ref.verbsMemBegin(), ref.fVerbCnt * sizeof(uint8_t))) {
=======
    if (0 != memcmp(this->verbsMemBegin(),
                    ref.verbsMemBegin(),
                    ref.fVerbCnt * sizeof(uint8_t))) {
>>>>>>> miniblink49
        SkASSERT(!genIDMatch);
        return false;
    }
    SkASSERT(this->points() && ref.points());
<<<<<<< HEAD
    if (0 != memcmp(this->points(), ref.points(), ref.fPointCnt * sizeof(SkPoint))) {
=======
    if (0 != memcmp(this->points(),
                    ref.points(),
                    ref.fPointCnt * sizeof(SkPoint))) {
>>>>>>> miniblink49
        SkASSERT(!genIDMatch);
        return false;
    }
    if (fConicWeights != ref.fConicWeights) {
        SkASSERT(!genIDMatch);
        return false;
    }
<<<<<<< HEAD
    return true;
}

void SkPathRef::writeToBuffer(SkWBuffer* buffer) const
{
    SkDEBUGCODE(this->validate();)
        SkDEBUGCODE(size_t beforePos = buffer->pos();)

        // Call getBounds() to ensure (as a side-effect) that fBounds
        // and fIsFinite are computed.
        const SkRect& bounds
        = this->getBounds();

    int32_t packed = ((fRRectOrOvalStartIdx & 7) << kRRectOrOvalStartIdx_SerializationShift) | ((fRRectOrOvalIsCCW & 1) << kRRectOrOvalIsCCW_SerializationShift) | ((fIsFinite & 1) << kIsFinite_SerializationShift) | ((fIsOval & 1) << kIsOval_SerializationShift) | ((fIsRRect & 1) << kIsRRect_SerializationShift) | (fSegmentMask << kSegmentMask_SerializationShift);
=======
    // We've done the work to determine that these are equal. If either has a zero genID, copy
    // the other's. If both are 0 then genID() will compute the next ID.
    if (0 == fGenerationID) {
        fGenerationID = ref.genID();
    } else if (0 == ref.fGenerationID) {
        ref.fGenerationID = this->genID();
    }
    return true;
}

void SkPathRef::writeToBuffer(SkWBuffer* buffer) const {
    SkDEBUGCODE(this->validate();)
    SkDEBUGCODE(size_t beforePos = buffer->pos();)

    // Call getBounds() to ensure (as a side-effect) that fBounds
    // and fIsFinite are computed.
    const SkRect& bounds = this->getBounds();

    int32_t packed = ((fIsFinite & 1) << kIsFinite_SerializationShift) |
                     ((fIsOval & 1) << kIsOval_SerializationShift) |
                     (fSegmentMask << kSegmentMask_SerializationShift);
>>>>>>> miniblink49
    buffer->write32(packed);

    // TODO: write gen ID here. Problem: We don't know if we're cross process or not from
    // SkWBuffer. Until this is fixed we write 0.
    buffer->write32(0);
    buffer->write32(fVerbCnt);
    buffer->write32(fPointCnt);
    buffer->write32(fConicWeights.count());
    buffer->write(verbsMemBegin(), fVerbCnt * sizeof(uint8_t));
    buffer->write(fPoints, fPointCnt * sizeof(SkPoint));
    buffer->write(fConicWeights.begin(), fConicWeights.bytes());
    buffer->write(&bounds, sizeof(bounds));

<<<<<<< HEAD
    SkASSERT(buffer->pos() - beforePos == (size_t)this->writeSize());
}

uint32_t SkPathRef::writeSize() const
{
    return uint32_t(5 * sizeof(uint32_t) + fVerbCnt * sizeof(uint8_t) + fPointCnt * sizeof(SkPoint) + fConicWeights.bytes() + sizeof(SkRect));
}

void SkPathRef::copy(const SkPathRef& ref,
    int additionalReserveVerbs,
    int additionalReservePoints)
{
    SkDEBUGCODE(this->validate();) this->resetToSize(ref.fVerbCnt, ref.fPointCnt, ref.fConicWeights.count(),
        additionalReserveVerbs, additionalReservePoints);
    sk_careful_memcpy(this->verbsMemWritable(), ref.verbsMemBegin(), ref.fVerbCnt * sizeof(uint8_t));
    sk_careful_memcpy(this->fPoints, ref.fPoints, ref.fPointCnt * sizeof(SkPoint));
    fConicWeights = ref.fConicWeights;
=======
    SkASSERT(buffer->pos() - beforePos == (size_t) this->writeSize());
}

uint32_t SkPathRef::writeSize() const {
    return uint32_t(5 * sizeof(uint32_t) +
                    fVerbCnt * sizeof(uint8_t) +
                    fPointCnt * sizeof(SkPoint) +
                    fConicWeights.bytes() +
                    sizeof(SkRect));
}

void SkPathRef::copy(const SkPathRef& ref,
                     int additionalReserveVerbs,
                     int additionalReservePoints) {
    SkDEBUGCODE(this->validate();)
    this->resetToSize(ref.fVerbCnt, ref.fPointCnt, ref.fConicWeights.count(),
                        additionalReserveVerbs, additionalReservePoints);
    memcpy(this->verbsMemWritable(), ref.verbsMemBegin(), ref.fVerbCnt * sizeof(uint8_t));
    memcpy(this->fPoints, ref.fPoints, ref.fPointCnt * sizeof(SkPoint));
    fConicWeights = ref.fConicWeights;
    // We could call genID() here to force a real ID (instead of 0). However, if we're making
    // a copy then presumably we intend to make a modification immediately afterwards.
    fGenerationID = ref.fGenerationID;
>>>>>>> miniblink49
    fBoundsIsDirty = ref.fBoundsIsDirty;
    if (!fBoundsIsDirty) {
        fBounds = ref.fBounds;
        fIsFinite = ref.fIsFinite;
    }
    fSegmentMask = ref.fSegmentMask;
    fIsOval = ref.fIsOval;
<<<<<<< HEAD
    fIsRRect = ref.fIsRRect;
    fRRectOrOvalIsCCW = ref.fRRectOrOvalIsCCW;
    fRRectOrOvalStartIdx = ref.fRRectOrOvalStartIdx;
    SkDEBUGCODE(this->validate();)
}

void SkPathRef::interpolate(const SkPathRef& ending, SkScalar weight, SkPathRef* out) const
{
    const SkScalar* inValues = &ending.getPoints()->fX;
    SkScalar* outValues = &out->getPoints()->fX;
    int count = out->countPoints() * 2;
    for (int index = 0; index < count; ++index) {
        outValues[index] = outValues[index] * weight + inValues[index] * (1 - weight);
    }
    out->fBoundsIsDirty = true;
    out->fIsOval = false;
    out->fIsRRect = false;
}

SkPoint* SkPathRef::growForRepeatedVerb(int /*SkPath::Verb*/ verb,
    int numVbs,
    SkScalar** weights)
{
=======
    SkDEBUGCODE(this->validate();)
}

SkPoint* SkPathRef::growForRepeatedVerb(int /*SkPath::Verb*/ verb,
                                        int numVbs,
                                        SkScalar** weights) {
>>>>>>> miniblink49
    // This value is just made-up for now. When count is 4, calling memset was much
    // slower than just writing the loop. This seems odd, and hopefully in the
    // future this will appear to have been a fluke...
    static const unsigned int kMIN_COUNT_FOR_MEMSET_TO_BE_FAST = 16;

<<<<<<< HEAD
    SkDEBUGCODE(this->validate();) int pCnt;
    bool dirtyAfterEdit = true;
    switch (verb) {
    case SkPath::kMove_Verb:
        pCnt = numVbs;
        dirtyAfterEdit = false;
        break;
    case SkPath::kLine_Verb:
        fSegmentMask |= SkPath::kLine_SegmentMask;
        pCnt = numVbs;
        break;
    case SkPath::kQuad_Verb:
        fSegmentMask |= SkPath::kQuad_SegmentMask;
        pCnt = 2 * numVbs;
        break;
    case SkPath::kConic_Verb:
        fSegmentMask |= SkPath::kConic_SegmentMask;
        pCnt = 2 * numVbs;
        break;
    case SkPath::kCubic_Verb:
        fSegmentMask |= SkPath::kCubic_SegmentMask;
        pCnt = 3 * numVbs;
        break;
    case SkPath::kClose_Verb:
        SkDEBUGFAIL("growForRepeatedVerb called for kClose_Verb");
        pCnt = 0;
        dirtyAfterEdit = false;
        break;
    case SkPath::kDone_Verb:
        SkDEBUGFAIL("growForRepeatedVerb called for kDone");
        // fall through
    default:
        SkDEBUGFAIL("default should not be reached");
        pCnt = 0;
        dirtyAfterEdit = false;
    }

    size_t space = numVbs * sizeof(uint8_t) + pCnt * sizeof(SkPoint);
=======
    SkDEBUGCODE(this->validate();)
    int pCnt;
    bool dirtyAfterEdit = true;
    switch (verb) {
        case SkPath::kMove_Verb:
            pCnt = numVbs;
            dirtyAfterEdit = false;
            break;
        case SkPath::kLine_Verb:
            fSegmentMask |= SkPath::kLine_SegmentMask;
            pCnt = numVbs;
            break;
        case SkPath::kQuad_Verb:
            fSegmentMask |= SkPath::kQuad_SegmentMask;
            pCnt = 2 * numVbs;
            break;
        case SkPath::kConic_Verb:
            fSegmentMask |= SkPath::kConic_SegmentMask;
            pCnt = 2 * numVbs;
            break;
        case SkPath::kCubic_Verb:
            fSegmentMask |= SkPath::kCubic_SegmentMask;
            pCnt = 3 * numVbs;
            break;
        case SkPath::kClose_Verb:
            SkDEBUGFAIL("growForRepeatedVerb called for kClose_Verb");
            pCnt = 0;
            dirtyAfterEdit = false;
            break;
        case SkPath::kDone_Verb:
            SkDEBUGFAIL("growForRepeatedVerb called for kDone");
            // fall through
        default:
            SkDEBUGFAIL("default should not be reached");
            pCnt = 0;
            dirtyAfterEdit = false;
    }

    size_t space = numVbs * sizeof(uint8_t) + pCnt * sizeof (SkPoint);
>>>>>>> miniblink49
    this->makeSpace(space);

    SkPoint* ret = fPoints + fPointCnt;
    uint8_t* vb = fVerbs - fVerbCnt;

    // cast to unsigned, so if kMIN_COUNT_FOR_MEMSET_TO_BE_FAST is defined to
    // be 0, the compiler will remove the test/branch entirely.
    if ((unsigned)numVbs >= kMIN_COUNT_FOR_MEMSET_TO_BE_FAST) {
        memset(vb - numVbs, verb, numVbs);
    } else {
        for (int i = 0; i < numVbs; ++i) {
            vb[~i] = verb;
        }
    }

    fVerbCnt += numVbs;
    fPointCnt += pCnt;
    fFreeSpace -= space;
<<<<<<< HEAD
    fBoundsIsDirty = true; // this also invalidates fIsFinite
    if (dirtyAfterEdit) {
        fIsOval = false;
        fIsRRect = false;
=======
    fBoundsIsDirty = true;  // this also invalidates fIsFinite
    if (dirtyAfterEdit) {
        fIsOval = false;
>>>>>>> miniblink49
    }

    if (SkPath::kConic_Verb == verb) {
        SkASSERT(weights);
        *weights = fConicWeights.append(numVbs);
    }

<<<<<<< HEAD
    SkDEBUGCODE(this->validate();) return ret;
}

SkPoint* SkPathRef::growForVerb(int /* SkPath::Verb*/ verb, SkScalar weight)
{
    SkDEBUGCODE(this->validate();) int pCnt;
    bool dirtyAfterEdit = true;
    switch (verb) {
    case SkPath::kMove_Verb:
        pCnt = 1;
        dirtyAfterEdit = false;
        break;
    case SkPath::kLine_Verb:
        fSegmentMask |= SkPath::kLine_SegmentMask;
        pCnt = 1;
        break;
    case SkPath::kQuad_Verb:
        fSegmentMask |= SkPath::kQuad_SegmentMask;
        pCnt = 2;
        break;
    case SkPath::kConic_Verb:
        fSegmentMask |= SkPath::kConic_SegmentMask;
        pCnt = 2;
        break;
    case SkPath::kCubic_Verb:
        fSegmentMask |= SkPath::kCubic_SegmentMask;
        pCnt = 3;
        break;
    case SkPath::kClose_Verb:
        pCnt = 0;
        dirtyAfterEdit = false;
        break;
    case SkPath::kDone_Verb:
        SkDEBUGFAIL("growForVerb called for kDone");
        // fall through
    default:
        SkDEBUGFAIL("default is not reached");
        dirtyAfterEdit = false;
        pCnt = 0;
    }
    size_t space = sizeof(uint8_t) + pCnt * sizeof(SkPoint);
=======
    SkDEBUGCODE(this->validate();)
    return ret;
}

SkPoint* SkPathRef::growForVerb(int /* SkPath::Verb*/ verb, SkScalar weight) {
    SkDEBUGCODE(this->validate();)
    int pCnt;
    bool dirtyAfterEdit = true;
    switch (verb) {
        case SkPath::kMove_Verb:
            pCnt = 1;
            dirtyAfterEdit = false;
            break;
        case SkPath::kLine_Verb:
            fSegmentMask |= SkPath::kLine_SegmentMask;
            pCnt = 1;
            break;
        case SkPath::kQuad_Verb:
            fSegmentMask |= SkPath::kQuad_SegmentMask;
            pCnt = 2;
            break;
        case SkPath::kConic_Verb:
            fSegmentMask |= SkPath::kConic_SegmentMask;
            pCnt = 2;
            break;
        case SkPath::kCubic_Verb:
            fSegmentMask |= SkPath::kCubic_SegmentMask;
            pCnt = 3;
            break;
        case SkPath::kClose_Verb:
            pCnt = 0;
            dirtyAfterEdit = false;
            break;
        case SkPath::kDone_Verb:
            SkDEBUGFAIL("growForVerb called for kDone");
            // fall through
        default:
            SkDEBUGFAIL("default is not reached");
            dirtyAfterEdit = false;
            pCnt = 0;
    }
    size_t space = sizeof(uint8_t) + pCnt * sizeof (SkPoint);
>>>>>>> miniblink49
    this->makeSpace(space);
    this->fVerbs[~fVerbCnt] = verb;
    SkPoint* ret = fPoints + fPointCnt;
    fVerbCnt += 1;
    fPointCnt += pCnt;
    fFreeSpace -= space;
<<<<<<< HEAD
    fBoundsIsDirty = true; // this also invalidates fIsFinite
    if (dirtyAfterEdit) {
        fIsOval = false;
        fIsRRect = false;
=======
    fBoundsIsDirty = true;  // this also invalidates fIsFinite
    if (dirtyAfterEdit) {
        fIsOval = false;
>>>>>>> miniblink49
    }

    if (SkPath::kConic_Verb == verb) {
        *fConicWeights.append() = weight;
    }

<<<<<<< HEAD
    SkDEBUGCODE(this->validate();) return ret;
}

uint32_t SkPathRef::genID() const
{
=======
    SkDEBUGCODE(this->validate();)
    return ret;
}

uint32_t SkPathRef::genID() const {
>>>>>>> miniblink49
    SkASSERT(!fEditorsAttached);
    static const uint32_t kMask = (static_cast<int64_t>(1) << SkPath::kPathRefGenIDBitCnt) - 1;
    if (!fGenerationID) {
        if (0 == fPointCnt && 0 == fVerbCnt) {
            fGenerationID = kEmptyGenID;
        } else {
<<<<<<< HEAD
            static int32_t gPathRefGenerationID;
=======
            static int32_t  gPathRefGenerationID;
>>>>>>> miniblink49
            // do a loop in case our global wraps around, as we never want to return a 0 or the
            // empty ID
            do {
                fGenerationID = (sk_atomic_inc(&gPathRefGenerationID) + 1) & kMask;
            } while (fGenerationID <= kEmptyGenID);
        }
    }
    return fGenerationID;
}

<<<<<<< HEAD
void SkPathRef::addGenIDChangeListener(GenIDChangeListener* listener)
{
    if (nullptr == listener || this == gEmpty) {
        delete listener;
        return;
    }
    *fGenIDChangeListeners.append() = listener;
}

// we need to be called *before* the genID gets changed or zerod
void SkPathRef::callGenIDChangeListeners()
{
    for (int i = 0; i < fGenIDChangeListeners.count(); i++) {
        fGenIDChangeListeners[i]->onChange();
    }

    // Listeners get at most one shot, so whether these triggered or not, blow them away.
    fGenIDChangeListeners.deleteAll();
}

SkRRect SkPathRef::getRRect() const
{
    const SkRect& bounds = this->getBounds();
    SkVector radii[4] = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };
    Iter iter(*this);
    SkPoint pts[4];
    uint8_t verb = iter.next(pts);
    SkASSERT(SkPath::kMove_Verb == verb);
    while ((verb = iter.next(pts)) != SkPath::kDone_Verb) {
        if (SkPath::kConic_Verb == verb) {
            SkVector v1_0 = pts[1] - pts[0];
            SkVector v2_1 = pts[2] - pts[1];
            SkVector dxdy;
            if (v1_0.fX) {
                SkASSERT(!v2_1.fX && !v1_0.fY);
                dxdy.set(SkScalarAbs(v1_0.fX), SkScalarAbs(v2_1.fY));
            } else if (!v1_0.fY) {
                SkASSERT(!v2_1.fX || !v2_1.fY);
                dxdy.set(SkScalarAbs(v2_1.fX), SkScalarAbs(v2_1.fY));
            } else {
                SkASSERT(!v2_1.fY);
                dxdy.set(SkScalarAbs(v2_1.fX), SkScalarAbs(v1_0.fY));
            }
            SkRRect::Corner corner = pts[1].fX == bounds.fLeft ? pts[1].fY == bounds.fTop ? SkRRect::kUpperLeft_Corner : SkRRect::kLowerLeft_Corner : pts[1].fY == bounds.fTop ? SkRRect::kUpperRight_Corner : SkRRect::kLowerRight_Corner;
            SkASSERT(!radii[corner].fX && !radii[corner].fY);
            radii[corner] = dxdy;
        } else {
            SkASSERT((verb == SkPath::kLine_Verb
                         && (!(pts[1].fX - pts[0].fX) || !(pts[1].fY - pts[0].fY)))
                || verb == SkPath::kClose_Verb);
        }
    }
    SkRRect rrect;
    rrect.setRectRadii(bounds, radii);
    return rrect;
}

///////////////////////////////////////////////////////////////////////////////

SkPathRef::Iter::Iter()
{
#ifdef SK_DEBUG
    fPts = nullptr;
    fConicWeights = nullptr;
#endif
    // need to init enough to make next() harmlessly return kDone_Verb
    fVerbs = nullptr;
    fVerbStop = nullptr;
}

SkPathRef::Iter::Iter(const SkPathRef& path)
{
    this->setPathRef(path);
}

void SkPathRef::Iter::setPathRef(const SkPathRef& path)
{
    fPts = path.points();
    fVerbs = path.verbs();
    fVerbStop = path.verbsMemBegin();
    fConicWeights = path.conicWeights() - 1; // begin one behind
}

uint8_t SkPathRef::Iter::next(SkPoint pts[4])
{
    SkASSERT(pts);
    if (fVerbs == fVerbStop) {
        return (uint8_t)SkPath::kDone_Verb;
    }

    // fVerbs points one beyond next verb so decrement first.
    unsigned verb = *(--fVerbs);
    const SkPoint* srcPts = fPts;

    switch (verb) {
    case SkPath::kMove_Verb:
        pts[0] = srcPts[0];
        srcPts += 1;
        break;
    case SkPath::kLine_Verb:
        pts[0] = srcPts[-1];
        pts[1] = srcPts[0];
        srcPts += 1;
        break;
    case SkPath::kConic_Verb:
        fConicWeights += 1;
        // fall-through
    case SkPath::kQuad_Verb:
        pts[0] = srcPts[-1];
        pts[1] = srcPts[0];
        pts[2] = srcPts[1];
        srcPts += 2;
        break;
    case SkPath::kCubic_Verb:
        pts[0] = srcPts[-1];
        pts[1] = srcPts[0];
        pts[2] = srcPts[1];
        pts[3] = srcPts[2];
        srcPts += 3;
        break;
    case SkPath::kClose_Verb:
        break;
    case SkPath::kDone_Verb:
        SkASSERT(fVerbs == fVerbStop);
        break;
    }
    fPts = srcPts;
    return (uint8_t)verb;
}

uint8_t SkPathRef::Iter::peek() const
{
    const uint8_t* next = fVerbs - 1;
    return next <= fVerbStop ? (uint8_t)SkPath::kDone_Verb : *next;
}

#ifdef SK_DEBUG
void SkPathRef::validate() const
{
    this->INHERITED::validate();
    SkASSERT(static_cast<ptrdiff_t>(fFreeSpace) >= 0);
    SkASSERT(reinterpret_cast<intptr_t>(fVerbs) - reinterpret_cast<intptr_t>(fPoints) >= 0);
    SkASSERT((nullptr == fPoints) == (nullptr == fVerbs));
    SkASSERT(!(nullptr == fPoints && 0 != fFreeSpace));
    SkASSERT(!(nullptr == fPoints && 0 != fFreeSpace));
    SkASSERT(!(nullptr == fPoints && fPointCnt));
    SkASSERT(!(nullptr == fVerbs && fVerbCnt));
    SkASSERT(this->currSize() == fFreeSpace + sizeof(SkPoint) * fPointCnt + sizeof(uint8_t) * fVerbCnt);

    if (fIsOval || fIsRRect) {
        // Currently we don't allow both of these to be set, even though ovals are round rects.
        SkASSERT(fIsOval != fIsRRect);
        if (fIsOval) {
            SkASSERT(fRRectOrOvalStartIdx < 4);
        } else {
            SkASSERT(fRRectOrOvalStartIdx < 8);
        }
    }
=======
#ifdef SK_DEBUG
void SkPathRef::validate() const {
    this->INHERITED::validate();
    SkASSERT(static_cast<ptrdiff_t>(fFreeSpace) >= 0);
    SkASSERT(reinterpret_cast<intptr_t>(fVerbs) - reinterpret_cast<intptr_t>(fPoints) >= 0);
    SkASSERT((NULL == fPoints) == (NULL == fVerbs));
    SkASSERT(!(NULL == fPoints && 0 != fFreeSpace));
    SkASSERT(!(NULL == fPoints && 0 != fFreeSpace));
    SkASSERT(!(NULL == fPoints && fPointCnt));
    SkASSERT(!(NULL == fVerbs && fVerbCnt));
    SkASSERT(this->currSize() ==
                fFreeSpace + sizeof(SkPoint) * fPointCnt + sizeof(uint8_t) * fVerbCnt);
>>>>>>> miniblink49

    if (!fBoundsIsDirty && !fBounds.isEmpty()) {
        bool isFinite = true;
        for (int i = 0; i < fPointCnt; ++i) {
#ifdef SK_DEBUG
<<<<<<< HEAD
            if (fPoints[i].isFinite() && (fPoints[i].fX < fBounds.fLeft || fPoints[i].fX > fBounds.fRight || fPoints[i].fY < fBounds.fTop || fPoints[i].fY > fBounds.fBottom)) {
                SkDebugf("bounds: %f %f %f %f\n",
                    fBounds.fLeft, fBounds.fTop, fBounds.fRight, fBounds.fBottom);
=======
            if (fPoints[i].isFinite() &&
                (fPoints[i].fX < fBounds.fLeft || fPoints[i].fX > fBounds.fRight ||
                 fPoints[i].fY < fBounds.fTop || fPoints[i].fY > fBounds.fBottom)) {
                SkDebugf("bounds: %f %f %f %f\n",
                         fBounds.fLeft, fBounds.fTop, fBounds.fRight, fBounds.fBottom);
>>>>>>> miniblink49
                for (int j = 0; j < fPointCnt; ++j) {
                    if (i == j) {
                        SkDebugf("*");
                    }
                    SkDebugf("%f %f\n", fPoints[j].fX, fPoints[j].fY);
                }
            }
#endif

<<<<<<< HEAD
            SkASSERT(!fPoints[i].isFinite() || (fPoints[i].fX >= fBounds.fLeft && fPoints[i].fX <= fBounds.fRight && fPoints[i].fY >= fBounds.fTop && fPoints[i].fY <= fBounds.fBottom));
=======
            SkASSERT(!fPoints[i].isFinite() ||
		     (fPoints[i].fX >= fBounds.fLeft && fPoints[i].fX <= fBounds.fRight &&
		      fPoints[i].fY >= fBounds.fTop && fPoints[i].fY <= fBounds.fBottom));
>>>>>>> miniblink49
            if (!fPoints[i].isFinite()) {
                isFinite = false;
            }
        }
        SkASSERT(SkToBool(fIsFinite) == isFinite);
    }

#ifdef SK_DEBUG_PATH
    uint32_t mask = 0;
    for (int i = 0; i < fVerbCnt; ++i) {
        switch (fVerbs[~i]) {
<<<<<<< HEAD
        case SkPath::kMove_Verb:
            break;
        case SkPath::kLine_Verb:
            mask |= SkPath::kLine_SegmentMask;
            break;
        case SkPath::kQuad_Verb:
            mask |= SkPath::kQuad_SegmentMask;
            break;
        case SkPath::kConic_Verb:
            mask |= SkPath::kConic_SegmentMask;
            break;
        case SkPath::kCubic_Verb:
            mask |= SkPath::kCubic_SegmentMask;
            break;
        case SkPath::kClose_Verb:
            break;
        case SkPath::kDone_Verb:
            SkDEBUGFAIL("Done verb shouldn't be recorded.");
            break;
        default:
            SkDEBUGFAIL("Unknown Verb");
            break;
=======
            case SkPath::kMove_Verb:
                break;
            case SkPath::kLine_Verb:
                mask |= SkPath::kLine_SegmentMask;
                break;
            case SkPath::kQuad_Verb:
                mask |= SkPath::kQuad_SegmentMask;
                break;
            case SkPath::kConic_Verb:
                mask |= SkPath::kConic_SegmentMask;
                break;
            case SkPath::kCubic_Verb:
                mask |= SkPath::kCubic_SegmentMask;
                break;
            case SkPath::kClose_Verb:
                break;
            case SkPath::kDone_Verb:
                SkDEBUGFAIL("Done verb shouldn't be recorded.");
                break;
            default:
                SkDEBUGFAIL("Unknown Verb");
                break;
>>>>>>> miniblink49
        }
    }
    SkASSERT(mask == fSegmentMask);
#endif // SK_DEBUG_PATH
}
#endif
