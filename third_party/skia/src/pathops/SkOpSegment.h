/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkOpSegment_DEFINE
#define SkOpSegment_DEFINE

#include "SkOpAngle.h"
#include "SkOpSpan.h"
#include "SkOpTAllocator.h"
#include "SkPathOpsBounds.h"
#include "SkPathOpsCubic.h"
#include "SkPathOpsCurve.h"

struct SkDCurve;
class SkOpCoincidence;
class SkOpContour;
enum class SkOpRayDir;
struct SkOpRayHit;
class SkPathWriter;

class SkOpSegment {
public:
    enum AllowAlias {
        kAllowAlias,
        kNoAlias
    };

<<<<<<< HEAD
    bool operator<(const SkOpSegment& rh) const
    {
=======
    bool operator<(const SkOpSegment& rh) const {
>>>>>>> miniblink49
        return fBounds.fTop < rh.fBounds.fTop;
    }

    SkOpAngle* activeAngle(SkOpSpanBase* start, SkOpSpanBase** startPtr, SkOpSpanBase** endPtr,
<<<<<<< HEAD
        bool* done);
    SkOpAngle* activeAngleInner(SkOpSpanBase* start, SkOpSpanBase** startPtr,
        SkOpSpanBase** endPtr, bool* done);
    SkOpAngle* activeAngleOther(SkOpSpanBase* start, SkOpSpanBase** startPtr,
        SkOpSpanBase** endPtr, bool* done);
    bool activeOp(SkOpSpanBase* start, SkOpSpanBase* end, int xorMiMask, int xorSuMask,
        SkPathOp op);
    bool activeOp(int xorMiMask, int xorSuMask, SkOpSpanBase* start, SkOpSpanBase* end, SkPathOp op,
        int* sumMiWinding, int* sumSuWinding);
=======
                            bool* done);
    SkOpAngle* activeAngleInner(SkOpSpanBase* start, SkOpSpanBase** startPtr,
                                       SkOpSpanBase** endPtr, bool* done);
    SkOpAngle* activeAngleOther(SkOpSpanBase* start, SkOpSpanBase** startPtr,
                                       SkOpSpanBase** endPtr, bool* done);
    bool activeOp(SkOpSpanBase* start, SkOpSpanBase* end, int xorMiMask, int xorSuMask,
                  SkPathOp op);
    bool activeOp(int xorMiMask, int xorSuMask, SkOpSpanBase* start, SkOpSpanBase* end, SkPathOp op,
                  int* sumMiWinding, int* sumSuWinding);
>>>>>>> miniblink49

    bool activeWinding(SkOpSpanBase* start, SkOpSpanBase* end);
    bool activeWinding(SkOpSpanBase* start, SkOpSpanBase* end, int* sumWinding);
    void addAlignIntersection(SkOpPtT& endPtT, SkPoint& oldPt,
        SkOpContourHead* contourList, SkChunkAlloc* allocator);

<<<<<<< HEAD
    void addAlignIntersections(SkOpContourHead* contourList, SkChunkAlloc* allocator)
    {
=======
    void addAlignIntersections(SkOpContourHead* contourList, SkChunkAlloc* allocator) {
>>>>>>> miniblink49
        this->addAlignIntersection(*fHead.ptT(), fOriginal[0], contourList, allocator);
        this->addAlignIntersection(*fTail.ptT(), fOriginal[1], contourList, allocator);
    }

<<<<<<< HEAD
    SkOpSegment* addConic(SkPoint pts[3], SkScalar weight, SkOpContour* parent)
    {
=======
    SkOpSegment* addConic(SkPoint pts[3], SkScalar weight, SkOpContour* parent) {
>>>>>>> miniblink49
        init(pts, weight, parent, SkPath::kConic_Verb);
        SkDCurve curve;
        curve.fConic.set(pts, weight);
        curve.setConicBounds(pts, weight, 0, 1, &fBounds);
        return this;
    }

<<<<<<< HEAD
    SkOpSegment* addCubic(SkPoint pts[4], SkOpContour* parent)
    {
=======
    SkOpSegment* addCubic(SkPoint pts[4], SkOpContour* parent) {
>>>>>>> miniblink49
        init(pts, 1, parent, SkPath::kCubic_Verb);
        SkDCurve curve;
        curve.fCubic.set(pts);
        curve.setCubicBounds(pts, 1, 0, 1, &fBounds);
        return this;
    }

<<<<<<< HEAD
    bool addCurveTo(const SkOpSpanBase* start, const SkOpSpanBase* end, SkPathWriter* path) const;

    SkOpAngle* addEndSpan(SkChunkAlloc* allocator)
    {
=======
    void addCurveTo(const SkOpSpanBase* start, const SkOpSpanBase* end, SkPathWriter* path,
                    bool active) const;

    SkOpAngle* addEndSpan(SkChunkAlloc* allocator) {
>>>>>>> miniblink49
        SkOpAngle* angle = SkOpTAllocator<SkOpAngle>::Allocate(allocator);
        angle->set(&fTail, fTail.prev());
        fTail.setFromAngle(angle);
        return angle;
    }

<<<<<<< HEAD
    SkOpSegment* addLine(SkPoint pts[2], SkOpContour* parent)
    {
=======
    SkOpSegment* addLine(SkPoint pts[2], SkOpContour* parent) {
>>>>>>> miniblink49
        init(pts, 1, parent, SkPath::kLine_Verb);
        fBounds.set(pts, 2);
        return this;
    }

<<<<<<< HEAD
    SkOpPtT* addMissing(double t, SkOpSegment* opp, SkChunkAlloc*);

    SkOpAngle* addStartSpan(SkChunkAlloc* allocator)
    {
=======
    SkOpPtT* addMissing(double t, SkOpSegment* opp, SkChunkAlloc* );

    SkOpAngle* addStartSpan(SkChunkAlloc* allocator) {
>>>>>>> miniblink49
        SkOpAngle* angle = SkOpTAllocator<SkOpAngle>::Allocate(allocator);
        angle->set(&fHead, fHead.next());
        fHead.setToAngle(angle);
        return angle;
    }

<<<<<<< HEAD
    SkOpSegment* addQuad(SkPoint pts[3], SkOpContour* parent)
    {
=======
    SkOpSegment* addQuad(SkPoint pts[3], SkOpContour* parent) {
>>>>>>> miniblink49
        init(pts, 1, parent, SkPath::kQuad_Verb);
        SkDCurve curve;
        curve.fQuad.set(pts);
        curve.setQuadBounds(pts, 1, 0, 1, &fBounds);
        return this;
    }

<<<<<<< HEAD
    SkOpPtT* addT(double t, AllowAlias, SkChunkAlloc*);

    void align();

    const SkPathOpsBounds& bounds() const
    {
        return fBounds;
    }

    void bumpCount()
    {
=======
    SkOpPtT* addT(double t, AllowAlias , SkChunkAlloc* );

    void align();

    const SkPathOpsBounds& bounds() const {
        return fBounds;
    }

    void bumpCount() {
>>>>>>> miniblink49
        ++fCount;
    }

    void calcAngles(SkChunkAlloc*);
<<<<<<< HEAD
    bool collapsed() const;
    static void ComputeOneSum(const SkOpAngle* baseAngle, SkOpAngle* nextAngle,
        SkOpAngle::IncludeType);
    static void ComputeOneSumReverse(SkOpAngle* baseAngle, SkOpAngle* nextAngle,
        SkOpAngle::IncludeType);
    int computeSum(SkOpSpanBase* start, SkOpSpanBase* end, SkOpAngle::IncludeType includeType);

    SkOpContour* contour() const
    {
        return fContour;
    }

    int count() const
    {
=======
    void checkAngleCoin(SkOpCoincidence* coincidences, SkChunkAlloc* allocator);
    void checkNearCoincidence(SkOpAngle* );
    bool collapsed() const;
    static void ComputeOneSum(const SkOpAngle* baseAngle, SkOpAngle* nextAngle,
                              SkOpAngle::IncludeType );
    static void ComputeOneSumReverse(SkOpAngle* baseAngle, SkOpAngle* nextAngle,
                                     SkOpAngle::IncludeType );
    int computeSum(SkOpSpanBase* start, SkOpSpanBase* end, SkOpAngle::IncludeType includeType);

    SkOpContour* contour() const {
        return fContour;
    }

    int count() const {
>>>>>>> miniblink49
        return fCount;
    }

    void debugAddAngle(double startT, double endT, SkChunkAlloc*);
<<<<<<< HEAD
    void debugAddAlignIntersection(const char* id, SkPathOpsDebug::GlitchLog* glitches,
        const SkOpPtT& endPtT, const SkPoint& oldPt,
        const SkOpContourHead*) const;

    void debugAddAlignIntersections(const char* id, SkPathOpsDebug::GlitchLog* glitches,
        SkOpContourHead* contourList) const
    {
        this->debugAddAlignIntersection(id, glitches, *fHead.ptT(), fOriginal[0], contourList);
        this->debugAddAlignIntersection(id, glitches, *fTail.ptT(), fOriginal[1], contourList);
    }

    bool debugAddMissing(double t, const SkOpSegment* opp) const;
    void debugAlign(const char* id, SkPathOpsDebug::GlitchLog* glitches) const;
    const SkOpAngle* debugAngle(int id) const;
#if DEBUG_ANGLE
    void debugCheckAngleCoin() const;
#endif
    void debugCheckHealth(const char* id, SkPathOpsDebug::GlitchLog*) const;
    SkOpContour* debugContour(int id);
    void debugFindCollapsed(const char* id, SkPathOpsDebug::GlitchLog* glitches) const;

    int debugID() const
    {
=======
    const SkOpAngle* debugAngle(int id) const;
    SkOpContour* debugContour(int id);

    int debugID() const {
>>>>>>> miniblink49
        return SkDEBUGRELEASE(fID, -1);
    }

    SkOpAngle* debugLastAngle();
<<<<<<< HEAD
    void debugMissingCoincidence(const char* id, SkPathOpsDebug::GlitchLog* glitches,
        const SkOpCoincidence* coincidences) const;
    void debugMoveMultiples(const char* id, SkPathOpsDebug::GlitchLog* glitches) const;
    void debugMoveNearby(const char* id, SkPathOpsDebug::GlitchLog* glitches) const;
=======
>>>>>>> miniblink49
    const SkOpPtT* debugPtT(int id) const;
    void debugReset();
    const SkOpSegment* debugSegment(int id) const;

#if DEBUG_ACTIVE_SPANS
    void debugShowActiveSpans() const;
#endif
#if DEBUG_MARK_DONE
    void debugShowNewWinding(const char* fun, const SkOpSpan* span, int winding);
    void debugShowNewWinding(const char* fun, const SkOpSpan* span, int winding, int oppWinding);
#endif

    const SkOpSpanBase* debugSpan(int id) const;
    void debugValidate() const;
<<<<<<< HEAD
    void release(const SkOpSpan*);
    double distSq(double t, const SkOpAngle* opp) const;

    bool done() const
    {
=======
    void detach(const SkOpSpan* );
    double distSq(double t, SkOpAngle* opp);

    bool done() const {
>>>>>>> miniblink49
        SkASSERT(fDoneCount <= fCount);
        return fDoneCount == fCount;
    }

<<<<<<< HEAD
    bool done(const SkOpAngle* angle) const
    {
        return angle->start()->starter(angle->end())->done();
    }

    SkDPoint dPtAtT(double mid) const
    {
        return (*CurveDPointAtT[fVerb])(fPts, fWeight, mid);
    }

    SkDVector dSlopeAtT(double mid) const
    {
=======
    bool done(const SkOpAngle* angle) const {
        return angle->start()->starter(angle->end())->done();
    }

    SkDPoint dPtAtT(double mid) const {
        return (*CurveDPointAtT[fVerb])(fPts, fWeight, mid);
    }

    SkDVector dSlopeAtT(double mid) const {
>>>>>>> miniblink49
        return (*CurveDSlopeAtT[fVerb])(fPts, fWeight, mid);
    }

    void dump() const;
    void dumpAll() const;
    void dumpAngles() const;
    void dumpCoin() const;
<<<<<<< HEAD
    void dumpPts(const char* prefix = "seg") const;
    void dumpPtsInner(const char* prefix = "seg") const;

    void findCollapsed();
    SkOpSegment* findNextOp(SkTDArray<SkOpSpanBase*>* chase, SkOpSpanBase** nextStart,
        SkOpSpanBase** nextEnd, bool* unsortable, SkPathOp op,
        int xorMiMask, int xorSuMask);
    SkOpSegment* findNextWinding(SkTDArray<SkOpSpanBase*>* chase, SkOpSpanBase** nextStart,
        SkOpSpanBase** nextEnd, bool* unsortable);
    SkOpSegment* findNextXor(SkOpSpanBase** nextStart, SkOpSpanBase** nextEnd, bool* unsortable);
    SkOpSpan* findSortableTop(SkOpContour*);
    SkOpGlobalState* globalState() const;

    const SkOpSpan* head() const
    {
        return &fHead;
    }

    SkOpSpan* head()
    {
=======
    void dumpPts() const;
    void dumpPtsInner() const;

    SkOpSegment* findNextOp(SkTDArray<SkOpSpanBase*>* chase, SkOpSpanBase** nextStart,
                             SkOpSpanBase** nextEnd, bool* unsortable, SkPathOp op,
                             int xorMiMask, int xorSuMask);
    SkOpSegment* findNextWinding(SkTDArray<SkOpSpanBase*>* chase, SkOpSpanBase** nextStart,
                                  SkOpSpanBase** nextEnd, bool* unsortable);
    SkOpSegment* findNextXor(SkOpSpanBase** nextStart, SkOpSpanBase** nextEnd, bool* unsortable);
    SkOpSpan* findSortableTop(SkOpContour* );
    SkOpGlobalState* globalState() const;

    const SkOpSpan* head() const {
        return &fHead;
    }

    SkOpSpan* head() {
>>>>>>> miniblink49
        return &fHead;
    }

    void init(SkPoint pts[], SkScalar weight, SkOpContour* parent, SkPath::Verb verb);

<<<<<<< HEAD
    SkOpSpan* insert(SkOpSpan* prev, SkChunkAlloc* allocator)
    {
=======
    SkOpSpan* insert(SkOpSpan* prev, SkChunkAlloc* allocator) {
>>>>>>> miniblink49
        SkOpSpan* result = SkOpTAllocator<SkOpSpan>::Allocate(allocator);
        SkOpSpanBase* next = prev->next();
        result->setPrev(prev);
        prev->setNext(result);
        SkDEBUGCODE(result->ptT()->fT = 0);
        result->setNext(next);
        if (next) {
            next->setPrev(result);
        }
        return result;
    }

    bool isClose(double t, const SkOpSegment* opp) const;

<<<<<<< HEAD
    bool isHorizontal() const
    {
        return fBounds.fTop == fBounds.fBottom;
    }

    SkOpSegment* isSimple(SkOpSpanBase** end, int* step)
    {
        return nextChase(end, step, nullptr, nullptr);
    }

    bool isVertical() const
    {
        return fBounds.fLeft == fBounds.fRight;
    }

    bool isVertical(SkOpSpanBase* start, SkOpSpanBase* end) const
    {
=======
    bool isHorizontal() const {
        return fBounds.fTop == fBounds.fBottom;
    }

    SkOpSegment* isSimple(SkOpSpanBase** end, int* step) {
        return nextChase(end, step, NULL, NULL);
    }

    bool isVertical() const {
        return fBounds.fLeft == fBounds.fRight;
    }

    bool isVertical(SkOpSpanBase* start, SkOpSpanBase* end) const {
>>>>>>> miniblink49
        return (*CurveIsVertical[fVerb])(fPts, fWeight, start->t(), end->t());
    }

    bool isXor() const;

<<<<<<< HEAD
    const SkPoint& lastPt() const
    {
=======
    const SkPoint& lastPt() const {
>>>>>>> miniblink49
        return fPts[SkPathOpsVerbToPoints(fVerb)];
    }

    void markAllDone();
    SkOpSpanBase* markAndChaseDone(SkOpSpanBase* start, SkOpSpanBase* end);
    bool markAndChaseWinding(SkOpSpanBase* start, SkOpSpanBase* end, int winding,
<<<<<<< HEAD
        SkOpSpanBase** lastPtr);
    bool markAndChaseWinding(SkOpSpanBase* start, SkOpSpanBase* end, int winding,
        int oppWinding, SkOpSpanBase** lastPtr);
    SkOpSpanBase* markAngle(int maxWinding, int sumWinding, const SkOpAngle* angle);
    SkOpSpanBase* markAngle(int maxWinding, int sumWinding, int oppMaxWinding, int oppSumWinding,
        const SkOpAngle* angle);
    void markDone(SkOpSpan*);
    bool markWinding(SkOpSpan*, int winding);
    bool markWinding(SkOpSpan*, int winding, int oppWinding);
    bool match(const SkOpPtT* span, const SkOpSegment* parent, double t, const SkPoint& pt) const;
    bool missingCoincidence(SkOpCoincidence* coincidences, SkChunkAlloc* allocator);
    bool moveMultiples();
    void moveNearby();

    SkOpSegment* next() const
    {
        return fNext;
    }

    SkOpSegment* nextChase(SkOpSpanBase**, int* step, SkOpSpan**, SkOpSpanBase** last) const;
    bool operand() const;

    static int OppSign(const SkOpSpanBase* start, const SkOpSpanBase* end)
    {
        int result = start->t() < end->t() ? -start->upCast()->oppValue()
                                           : end->upCast()->oppValue();
=======
            SkOpSpanBase** lastPtr);
    bool markAndChaseWinding(SkOpSpanBase* start, SkOpSpanBase* end, int winding,
            int oppWinding, SkOpSpanBase** lastPtr);
    SkOpSpanBase* markAngle(int maxWinding, int sumWinding, const SkOpAngle* angle);
    SkOpSpanBase* markAngle(int maxWinding, int sumWinding, int oppMaxWinding, int oppSumWinding,
                         const SkOpAngle* angle);
    void markDone(SkOpSpan* );
    bool markWinding(SkOpSpan* , int winding);
    bool markWinding(SkOpSpan* , int winding, int oppWinding);
    bool match(const SkOpPtT* span, const SkOpSegment* parent, double t, const SkPoint& pt) const;
    bool missingCoincidence(SkOpCoincidence* coincidences, SkChunkAlloc* allocator);
    void moveMultiples();
    void moveNearby();

    SkOpSegment* next() const {
        return fNext;
    }

    SkOpSegment* nextChase(SkOpSpanBase** , int* step, SkOpSpan** , SkOpSpanBase** last) const;
    bool operand() const;

    static int OppSign(const SkOpSpanBase* start, const SkOpSpanBase* end) {
        int result = start->t() < end->t() ? -start->upCast()->oppValue()
                : end->upCast()->oppValue();
>>>>>>> miniblink49
        return result;
    }

    bool oppXor() const;

<<<<<<< HEAD
    const SkOpSegment* prev() const
    {
        return fPrev;
    }

    SkPoint ptAtT(double mid) const
    {
        return (*CurvePointAtT[fVerb])(fPts, fWeight, mid);
    }

    const SkPoint* pts() const
    {
        return fPts;
    }

    bool ptsDisjoint(const SkOpPtT& span, const SkOpPtT& test) const
    {
        return ptsDisjoint(span.fT, span.fPt, test.fT, test.fPt);
    }

    bool ptsDisjoint(const SkOpPtT& span, double t, const SkPoint& pt) const
    {
=======
    const SkOpSegment* prev() const {
        return fPrev;
    }

    SkPoint ptAtT(double mid) const {
        return (*CurvePointAtT[fVerb])(fPts, fWeight, mid);
    }

    const SkPoint* pts() const {
        return fPts;
    }

    bool ptsDisjoint(const SkOpPtT& span, const SkOpPtT& test) const {
        return ptsDisjoint(span.fT, span.fPt, test.fT, test.fPt);
    }

    bool ptsDisjoint(const SkOpPtT& span, double t, const SkPoint& pt) const {
>>>>>>> miniblink49
        return ptsDisjoint(span.fT, span.fPt, t, pt);
    }

    bool ptsDisjoint(double t1, const SkPoint& pt1, double t2, const SkPoint& pt2) const;

    void rayCheck(const SkOpRayHit& base, SkOpRayDir dir, SkOpRayHit** hits,
<<<<<<< HEAD
        SkChunkAlloc* allocator);

    void resetVisited()
    {
        fVisited = false;
    }

    void setContour(SkOpContour* contour)
    {
        fContour = contour;
    }

    void setNext(SkOpSegment* next)
    {
        fNext = next;
    }

    void setPrev(SkOpSegment* prev)
    {
        fPrev = prev;
    }

    void setVisited()
    {
        fVisited = true;
    }

    void setUpWinding(SkOpSpanBase* start, SkOpSpanBase* end, int* maxWinding, int* sumWinding)
    {
        int deltaSum = SpanSign(start, end);
        *maxWinding = *sumWinding;
        if (*sumWinding == SK_MinS32) {
            return;
        }
=======
                  SkChunkAlloc* allocator);

    void resetVisited() {
        fVisited = false;
    }

    void setContour(SkOpContour* contour) {
        fContour = contour;
    }

    void setCubicType(SkDCubic::CubicType cubicType) {
        fCubicType = cubicType;
    }

    void setNext(SkOpSegment* next) {
        fNext = next;
    }

    void setPrev(SkOpSegment* prev) {
        fPrev = prev;
    }

    void setVisited() {
        fVisited = true;
    }

    void setUpWinding(SkOpSpanBase* start, SkOpSpanBase* end, int* maxWinding, int* sumWinding) {
        int deltaSum = SpanSign(start, end);
        *maxWinding = *sumWinding;
>>>>>>> miniblink49
        *sumWinding -= deltaSum;
    }

    void setUpWindings(SkOpSpanBase* start, SkOpSpanBase* end, int* sumMiWinding,
<<<<<<< HEAD
        int* maxWinding, int* sumWinding);
    void setUpWindings(SkOpSpanBase* start, SkOpSpanBase* end, int* sumMiWinding, int* sumSuWinding,
        int* maxWinding, int* sumWinding, int* oppMaxWinding, int* oppSumWinding);
    void sortAngles();

    static int SpanSign(const SkOpSpanBase* start, const SkOpSpanBase* end)
    {
        int result = start->t() < end->t() ? -start->upCast()->windValue()
                                           : end->upCast()->windValue();
        return result;
    }

    SkOpAngle* spanToAngle(SkOpSpanBase* start, SkOpSpanBase* end)
    {
=======
                       int* maxWinding, int* sumWinding);
    void setUpWindings(SkOpSpanBase* start, SkOpSpanBase* end, int* sumMiWinding, int* sumSuWinding,
                       int* maxWinding, int* sumWinding, int* oppMaxWinding, int* oppSumWinding);
    void sortAngles();

    static int SpanSign(const SkOpSpanBase* start, const SkOpSpanBase* end) {
        int result = start->t() < end->t() ? -start->upCast()->windValue()
                : end->upCast()->windValue();
        return result;
    }

    SkOpAngle* spanToAngle(SkOpSpanBase* start, SkOpSpanBase* end) {
>>>>>>> miniblink49
        SkASSERT(start != end);
        return start->t() < end->t() ? start->upCast()->toAngle() : start->fromAngle();
    }

    bool subDivide(const SkOpSpanBase* start, const SkOpSpanBase* end, SkDCurve* result) const;
    bool subDivide(const SkOpSpanBase* start, const SkOpSpanBase* end, SkOpCurve* result) const;

<<<<<<< HEAD
    const SkOpSpanBase* tail() const
    {
        return &fTail;
    }

    SkOpSpanBase* tail()
    {
=======
    const SkOpSpanBase* tail() const {
        return &fTail;
    }

    SkOpSpanBase* tail() {
>>>>>>> miniblink49
        return &fTail;
    }

    bool testForCoincidence(const SkOpPtT* priorPtT, const SkOpPtT* ptT, const SkOpSpanBase* prior,
<<<<<<< HEAD
        const SkOpSpanBase* spanBase, const SkOpSegment* opp, SkScalar flatnessLimit) const;
=======
            const SkOpSpanBase* spanBase, const SkOpSegment* opp, SkScalar flatnessLimit) const;
>>>>>>> miniblink49

    void undoneSpan(SkOpSpanBase** start, SkOpSpanBase** end);
    int updateOppWinding(const SkOpSpanBase* start, const SkOpSpanBase* end) const;
    int updateOppWinding(const SkOpAngle* angle) const;
    int updateOppWindingReverse(const SkOpAngle* angle) const;
    int updateWinding(SkOpSpanBase* start, SkOpSpanBase* end);
    int updateWinding(SkOpAngle* angle);
    int updateWindingReverse(const SkOpAngle* angle);

    static bool UseInnerWinding(int outerWinding, int innerWinding);

<<<<<<< HEAD
    SkPath::Verb verb() const
    {
=======
    SkPath::Verb verb() const {
>>>>>>> miniblink49
        return fVerb;
    }

    // look for two different spans that point to the same opposite segment
<<<<<<< HEAD
    bool visited()
    {
=======
    bool visited() {
>>>>>>> miniblink49
        if (!fVisited) {
            fVisited = true;
            return false;
        }
        return true;
    }

<<<<<<< HEAD
    SkScalar weight() const
    {
=======
    SkScalar weight() const {
>>>>>>> miniblink49
        return fWeight;
    }

    SkOpSpan* windingSpanAtT(double tHit);
    int windSum(const SkOpAngle* angle) const;

<<<<<<< HEAD
    SkPoint* writablePt(bool end)
    {
=======
    SkPoint* writablePt(bool end) {
>>>>>>> miniblink49
        return &fPts[end ? SkPathOpsVerbToPoints(fVerb) : 0];
    }

private:
<<<<<<< HEAD
    SkOpSpan fHead; // the head span always has its t set to zero
    SkOpSpanBase fTail; // the tail span always has its t set to one
    SkOpContour* fContour;
    SkOpSegment* fNext; // forward-only linked list used by contour to walk the segments
    const SkOpSegment* fPrev;
    SkPoint fOriginal[2]; // if aligned, the original unaligned points are here
    SkPoint* fPts; // pointer into array of points owned by edge builder that may be tweaked
    SkPathOpsBounds fBounds; // tight bounds
    SkScalar fWeight;
    int fCount; // number of spans (one for a non-intersecting segment)
    int fDoneCount; // number of processed spans (zero initially)
    SkPath::Verb fVerb;
    bool fVisited; // used by missing coincidence check
=======
    SkOpSpan fHead;  // the head span always has its t set to zero
    SkOpSpanBase fTail;  // the tail span always has its t set to one
    SkOpContour* fContour;
    SkOpSegment* fNext;  // forward-only linked list used by contour to walk the segments
    const SkOpSegment* fPrev;
    SkPoint fOriginal[2];  // if aligned, the original unaligned points are here
    SkPoint* fPts;  // pointer into array of points owned by edge builder that may be tweaked
    SkPathOpsBounds fBounds;  // tight bounds
    SkScalar fWeight;
    int fCount;  // number of spans (one for a non-intersecting segment)
    int fDoneCount;  // number of processed spans (zero initially)
    SkPath::Verb fVerb;
    SkDCubic::CubicType fCubicType;
    bool fTopsFound;
    bool fVisited;  // used by missing coincidence check
>>>>>>> miniblink49
    SkDEBUGCODE(int fID);
};

#endif
