/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#ifndef SkPathOpsTSect_DEFINED
#define SkPathOpsTSect_DEFINED

#include "SkChunkAlloc.h"
#include "SkIntersections.h"
#include "SkPathOpsBounds.h"
#include "SkPathOpsRect.h"
#include "SkTSort.h"

#ifdef SK_DEBUG
typedef uint8_t SkOpDebugBool;
#else
typedef bool SkOpDebugBool;
#endif

/* TCurve and OppCurve are one of { SkDQuadratic, SkDConic, SkDCubic } */
template <typename TCurve, typename OppCurve>
class SkTCoincident {
public:
    SkTCoincident()
    {
        this->init();
    }

    void debugInit()
    {
#ifdef SK_DEBUG
        this->fPerpPt.fX = this->fPerpPt.fY = SK_ScalarNaN;
        this->fPerpT = SK_ScalarNaN;
        this->fCoincident = 0xFF;
#endif
    }

    char dumpIsCoincidentStr() const;
    void dump() const;

    bool isCoincident() const
    {
        SkASSERT(!!fCoincident == fCoincident);
        return SkToBool(fCoincident);
    }

    void init()
    {
=======

#include "SkChunkAlloc.h"
#include "SkPathOpsBounds.h"
#include "SkPathOpsRect.h"
#include "SkIntersections.h"
#include "SkTSort.h"

/* TCurve and OppCurve are one of { SkDQuadratic, SkDConic, SkDCubic } */
template<typename TCurve, typename OppCurve>
class SkTCoincident {
public:
    SkTCoincident() {
        this->init();
    }

    void dump() const;

    bool isCoincident() const {
        return fCoincident;
    }

    void init() {
>>>>>>> miniblink49
        fPerpT = -1;
        fCoincident = false;
        fPerpPt.fX = fPerpPt.fY = SK_ScalarNaN;
    }

<<<<<<< HEAD
    void markCoincident()
    {
=======
    void markCoincident() {
>>>>>>> miniblink49
        if (!fCoincident) {
            fPerpT = -1;
        }
        fCoincident = true;
    }

<<<<<<< HEAD
    const SkDPoint& perpPt() const
    {
        return fPerpPt;
    }

    double perpT() const
    {
        return fPerpT;
    }

    void setPerp(const TCurve& c1, double t, const SkDPoint& cPt, const OppCurve&);

private:
    SkDPoint fPerpPt;
    double fPerpT; // perpendicular intersection on opposite curve
    SkOpDebugBool fCoincident;
};

template <typename TCurve, typename OppCurve>
class SkTSect;
template <typename TCurve, typename OppCurve>
class SkTSpan;

template <typename TCurve, typename OppCurve>
=======
    const SkDPoint& perpPt() const {
        return fPerpPt;
    }

    double perpT() const {
        return fPerpT;
    }

    void setPerp(const TCurve& c1, double t, const SkDPoint& cPt, const OppCurve& );

private:
    SkDPoint fPerpPt;
    double fPerpT;  // perpendicular intersection on opposite curve
    bool fCoincident;
};

template<typename TCurve, typename OppCurve> class SkTSect;
template<typename TCurve, typename OppCurve> class SkTSpan;

template<typename TCurve, typename OppCurve>
>>>>>>> miniblink49
struct SkTSpanBounded {
    SkTSpan<TCurve, OppCurve>* fBounded;
    SkTSpanBounded* fNext;
};

/* Curve is either TCurve or SkDCubic */
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
class SkTSpan {
public:
    void addBounded(SkTSpan<OppCurve, TCurve>*, SkChunkAlloc*);
    double closestBoundedT(const SkDPoint& pt) const;
    bool contains(double t) const;

    void debugInit()
    {
=======
template<typename TCurve, typename OppCurve>
class SkTSpan {
public:
    void addBounded(SkTSpan<OppCurve, TCurve>* , SkChunkAlloc* );
    double closestBoundedT(const SkDPoint& pt) const;
    bool contains(double t) const;

    void debugInit() {
>>>>>>> miniblink49
        TCurve dummy;
        dummy.debugInit();
        init(dummy);
        initBounds(dummy);
        fCoinStart.init();
        fCoinEnd.init();
    }

    const SkTSect<OppCurve, TCurve>* debugOpp() const;
<<<<<<< HEAD
    const SkTSpan* debugSpan(int) const;
=======
    const SkTSpan* debugSpan(int ) const;
>>>>>>> miniblink49
    const SkTSpan* debugT(double t) const;
#ifdef SK_DEBUG
    bool debugIsBefore(const SkTSpan* span) const;
#endif
    void dump() const;
<<<<<<< HEAD
    void dumpAll() const;
=======
>>>>>>> miniblink49
    void dumpBounded(int id) const;
    void dumpBounds() const;
    void dumpCoin() const;

<<<<<<< HEAD
    double endT() const
    {
=======
    double endT() const {
>>>>>>> miniblink49
        return fEndT;
    }

    SkTSpan<OppCurve, TCurve>* findOppSpan(const SkTSpan<OppCurve, TCurve>* opp) const;

<<<<<<< HEAD
    SkTSpan<OppCurve, TCurve>* findOppT(double t) const
    {
=======
    SkTSpan<OppCurve, TCurve>* findOppT(double t) const {
>>>>>>> miniblink49
        SkTSpan<OppCurve, TCurve>* result = oppT(t);
        SkASSERT(result);
        return result;
    }

<<<<<<< HEAD
    bool hasOppT(double t) const
    {
=======
    bool hasOppT(double t) const {
>>>>>>> miniblink49
        return SkToBool(oppT(t));
    }

    int hullsIntersect(SkTSpan<OppCurve, TCurve>* span, bool* start, bool* oppStart);
<<<<<<< HEAD
    void init(const TCurve&);
    void initBounds(const TCurve&);

    bool isBounded() const
    {
        return fBounded != nullptr;
    }

    bool linearsIntersect(SkTSpan<OppCurve, TCurve>* span);
    double linearT(const SkDPoint&) const;

    void markCoincident()
    {
=======
    void init(const TCurve& );
    void initBounds(const TCurve& );

    bool isBounded() const {
        return fBounded != NULL;
    }

    bool linearsIntersect(SkTSpan<OppCurve, TCurve>* span);
    double linearT(const SkDPoint& ) const;

    void markCoincident() {
>>>>>>> miniblink49
        fCoinStart.markCoincident();
        fCoinEnd.markCoincident();
    }

<<<<<<< HEAD
    const SkTSpan* next() const
    {
=======
    const SkTSpan* next() const {
>>>>>>> miniblink49
        return fNext;
    }

    bool onlyEndPointsInCommon(const SkTSpan<OppCurve, TCurve>* opp, bool* start,
<<<<<<< HEAD
        bool* oppStart, bool* ptsInCommon);

    const TCurve& part() const
    {
=======
            bool* oppStart, bool* ptsInCommon);

    const TCurve& part() const {
>>>>>>> miniblink49
        return fPart;
    }

    bool removeAllBounded();
    bool removeBounded(const SkTSpan<OppCurve, TCurve>* opp);

<<<<<<< HEAD
    void reset()
    {
        fBounded = nullptr;
    }

    void resetBounds(const TCurve& curve)
    {
=======
    void reset() {
        fBounded = NULL;
    }

    void resetBounds(const TCurve& curve) {
>>>>>>> miniblink49
        fIsLinear = fIsLine = false;
        initBounds(curve);
    }

<<<<<<< HEAD
    bool split(SkTSpan* work, SkChunkAlloc* heap)
    {
=======
    bool split(SkTSpan* work, SkChunkAlloc* heap) {
>>>>>>> miniblink49
        return splitAt(work, (work->fStartT + work->fEndT) * 0.5, heap);
    }

    bool splitAt(SkTSpan* work, double t, SkChunkAlloc* heap);

<<<<<<< HEAD
    double startT() const
    {
=======
    double startT() const {
>>>>>>> miniblink49
        return fStartT;
    }

private:
<<<<<<< HEAD
    // implementation is for testing only
    int debugID() const
    {
=======

    // implementation is for testing only
    int debugID() const {
>>>>>>> miniblink49
        return PATH_OPS_DEBUG_T_SECT_RELEASE(fID, -1);
    }

    void dumpID() const;

    int hullCheck(const SkTSpan<OppCurve, TCurve>* opp, bool* start, bool* oppStart);
<<<<<<< HEAD
    int linearIntersects(const OppCurve&) const;
=======
    int linearIntersects(const OppCurve& ) const;
>>>>>>> miniblink49
    SkTSpan<OppCurve, TCurve>* oppT(double t) const;

    void validate() const;
    void validateBounded() const;
    void validatePerpT(double oppT) const;
<<<<<<< HEAD
    void validatePerpPt(double t, const SkDPoint&) const;
=======
    void validatePerpPt(double t, const SkDPoint& ) const;
>>>>>>> miniblink49

    TCurve fPart;
    SkTCoincident<TCurve, OppCurve> fCoinStart;
    SkTCoincident<TCurve, OppCurve> fCoinEnd;
    SkTSpanBounded<OppCurve, TCurve>* fBounded;
    SkTSpan* fPrev;
    SkTSpan* fNext;
    SkDRect fBounds;
    double fStartT;
    double fEndT;
    double fBoundsMax;
<<<<<<< HEAD
    SkOpDebugBool fCollapsed;
    SkOpDebugBool fHasPerp;
    SkOpDebugBool fIsLinear;
    SkOpDebugBool fIsLine;
    SkOpDebugBool fDeleted;
=======
    bool fCollapsed;
    bool fHasPerp;
    bool fIsLinear;
    bool fIsLine;
    bool fDeleted;
>>>>>>> miniblink49
    SkDEBUGCODE_(SkTSect<TCurve, OppCurve>* fDebugSect);
    PATH_OPS_DEBUG_T_SECT_CODE(int fID);
    friend class SkTSect<TCurve, OppCurve>;
    friend class SkTSect<OppCurve, TCurve>;
    friend class SkTSpan<OppCurve, TCurve>;
};

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
class SkTSect {
public:
    SkTSect(const TCurve& c PATH_OPS_DEBUG_T_SECT_PARAMS(int id));
    static void BinarySearch(SkTSect* sect1, SkTSect<OppCurve, TCurve>* sect2,
        SkIntersections* intersections);

    // for testing only
    bool debugHasBounded(const SkTSpan<OppCurve, TCurve>*) const;

    const SkTSect<OppCurve, TCurve>* debugOpp() const
    {
        return SkDEBUGRELEASE(fOppSect, nullptr);
=======
template<typename TCurve, typename OppCurve>
class SkTSect {
public:
    SkTSect(const TCurve& c  PATH_OPS_DEBUG_T_SECT_PARAMS(int id));
    static void BinarySearch(SkTSect* sect1, SkTSect<OppCurve, TCurve>* sect2,
            SkIntersections* intersections);

    // for testing only
    bool debugHasBounded(const SkTSpan<OppCurve, TCurve>* ) const;

    const SkTSect<OppCurve, TCurve>* debugOpp() const {
        return SkDEBUGRELEASE(fOppSect, NULL);
>>>>>>> miniblink49
    }

    const SkTSpan<TCurve, OppCurve>* debugSpan(int id) const;
    const SkTSpan<TCurve, OppCurve>* debugT(double t) const;
    void dump() const;
<<<<<<< HEAD
    void dumpBoth(SkTSect<OppCurve, TCurve>*) const;
=======
    void dumpBoth(SkTSect<OppCurve, TCurve>* ) const;
>>>>>>> miniblink49
    void dumpBounded(int id) const;
    void dumpBounds() const;
    void dumpCoin() const;
    void dumpCoinCurves() const;
    void dumpCurves() const;

private:
    enum {
        kZeroS1Set = 1,
        kOneS1Set = 2,
        kZeroS2Set = 4,
        kOneS2Set = 8
    };

    SkTSpan<TCurve, OppCurve>* addFollowing(SkTSpan<TCurve, OppCurve>* prior);
    void addForPerp(SkTSpan<OppCurve, TCurve>* span, double t);
    SkTSpan<TCurve, OppCurve>* addOne();
<<<<<<< HEAD

    SkTSpan<TCurve, OppCurve>* addSplitAt(SkTSpan<TCurve, OppCurve>* span, double t)
    {
=======
    
    SkTSpan<TCurve, OppCurve>* addSplitAt(SkTSpan<TCurve, OppCurve>* span, double t) {
>>>>>>> miniblink49
        SkTSpan<TCurve, OppCurve>* result = this->addOne();
        result->splitAt(span, t, &fHeap);
        result->initBounds(fCurve);
        span->initBounds(fCurve);
        return result;
    }

<<<<<<< HEAD
    bool binarySearchCoin(SkTSect<OppCurve, TCurve>*, double tStart, double tStep, double* t,
        double* oppT);
    SkTSpan<TCurve, OppCurve>* boundsMax() const;
    void coincidentCheck(SkTSect<OppCurve, TCurve>* sect2);
    void coincidentForce(SkTSect<OppCurve, TCurve>* sect2, double start1s, double start1e);
    bool coincidentHasT(double t);
    int collapsed() const;
    void computePerpendiculars(SkTSect<OppCurve, TCurve>* sect2, SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>* last);
    int countConsecutiveSpans(SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>** last) const;

    int debugID() const
    {
=======
    bool binarySearchCoin(SkTSect<OppCurve, TCurve>* , double tStart, double tStep, double* t,
                          double* oppT);
    SkTSpan<TCurve, OppCurve>* boundsMax() const;
    void coincidentCheck(SkTSect<OppCurve, TCurve>* sect2);
    bool coincidentHasT(double t);
    int collapsed() const;
    void computePerpendiculars(SkTSect<OppCurve, TCurve>* sect2, SkTSpan<TCurve, OppCurve>* first,
                               SkTSpan<TCurve, OppCurve>* last);
    int countConsecutiveSpans(SkTSpan<TCurve, OppCurve>* first,
                              SkTSpan<TCurve, OppCurve>** last) const;

    int debugID() const {
>>>>>>> miniblink49
        return PATH_OPS_DEBUG_T_SECT_RELEASE(fID, -1);
    }

    void deleteEmptySpans();
<<<<<<< HEAD
    void dumpCommon(const SkTSpan<TCurve, OppCurve>*) const;
    void dumpCommonCurves(const SkTSpan<TCurve, OppCurve>*) const;
    static int EndsEqual(const SkTSect* sect1, const SkTSect<OppCurve, TCurve>* sect2,
        SkIntersections*);
    SkTSpan<TCurve, OppCurve>* extractCoincident(SkTSect<OppCurve, TCurve>* sect2,
        SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>* last);
    SkTSpan<TCurve, OppCurve>* findCoincidentRun(SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>** lastPtr);
    int intersects(SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp,
        SkTSpan<OppCurve, TCurve>* oppSpan, int* oppResult);
    bool isParallel(const SkDLine& thisLine, const SkTSect<OppCurve, TCurve>* opp) const;
    int linesIntersect(SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp,
        SkTSpan<OppCurve, TCurve>* oppSpan, SkIntersections*);
    void markSpanGone(SkTSpan<TCurve, OppCurve>* span);
    bool matchedDirection(double t, const SkTSect<OppCurve, TCurve>* sect2, double t2) const;
    void matchedDirCheck(double t, const SkTSect<OppCurve, TCurve>* sect2, double t2,
        bool* calcMatched, bool* oppMatched) const;
    void mergeCoincidence(SkTSect<OppCurve, TCurve>* sect2);
    SkTSpan<TCurve, OppCurve>* prev(SkTSpan<TCurve, OppCurve>*) const;
=======
    void dumpCommon(const SkTSpan<TCurve, OppCurve>* ) const;
    void dumpCommonCurves(const SkTSpan<TCurve, OppCurve>* ) const;
    static int EndsEqual(const SkTSect* sect1, const SkTSect<OppCurve, TCurve>* sect2,
                         SkIntersections* );
    SkTSpan<TCurve, OppCurve>* extractCoincident(SkTSect<OppCurve, TCurve>* sect2,
                                                  SkTSpan<TCurve, OppCurve>* first,
                                                  SkTSpan<TCurve, OppCurve>* last);
    SkTSpan<TCurve, OppCurve>* findCoincidentRun(SkTSpan<TCurve, OppCurve>* first,
                                                  SkTSpan<TCurve, OppCurve>** lastPtr);
    int intersects(SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp,
                   SkTSpan<OppCurve, TCurve>* oppSpan, int* oppResult);
    int linesIntersect(SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp,
                       SkTSpan<OppCurve, TCurve>* oppSpan, SkIntersections* );
    void markSpanGone(SkTSpan<TCurve, OppCurve>* span);
    bool matchedDirection(double t, const SkTSect<OppCurve, TCurve>* sect2, double t2) const;
    void matchedDirCheck(double t, const SkTSect<OppCurve, TCurve>* sect2, double t2,
                         bool* calcMatched, bool* oppMatched) const;
    void mergeCoincidence(SkTSect<OppCurve, TCurve>* sect2);
    SkTSpan<TCurve, OppCurve>* prev(SkTSpan<TCurve, OppCurve>* ) const;
>>>>>>> miniblink49
    void removeByPerpendicular(SkTSect<OppCurve, TCurve>* opp);
    void recoverCollapsed();
    void removeCoincident(SkTSpan<TCurve, OppCurve>* span, bool isBetween);
    void removeAllBut(const SkTSpan<OppCurve, TCurve>* keep, SkTSpan<TCurve, OppCurve>* span,
<<<<<<< HEAD
        SkTSect<OppCurve, TCurve>* opp);
=======
                      SkTSect<OppCurve, TCurve>* opp);
>>>>>>> miniblink49
    void removeSpan(SkTSpan<TCurve, OppCurve>* span);
    void removeSpanRange(SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>* last);
    void removeSpans(SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp);
    SkTSpan<TCurve, OppCurve>* spanAtT(double t, SkTSpan<TCurve, OppCurve>** priorSpan);
    SkTSpan<TCurve, OppCurve>* tail();
    void trim(SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp);
    void unlinkSpan(SkTSpan<TCurve, OppCurve>* span);
    bool updateBounded(SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>* last,
<<<<<<< HEAD
        SkTSpan<OppCurve, TCurve>* oppFirst);
=======
                       SkTSpan<OppCurve, TCurve>* oppFirst);
>>>>>>> miniblink49
    void validate() const;
    void validateBounded() const;

    const TCurve& fCurve;
    SkChunkAlloc fHeap;
    SkTSpan<TCurve, OppCurve>* fHead;
    SkTSpan<TCurve, OppCurve>* fCoincident;
    SkTSpan<TCurve, OppCurve>* fDeleted;
    int fActiveCount;
    SkDEBUGCODE_(SkTSect<OppCurve, TCurve>* fOppSect);
    PATH_OPS_DEBUG_T_SECT_CODE(int fID);
    PATH_OPS_DEBUG_T_SECT_CODE(int fDebugCount);
#if DEBUG_T_SECT
    int fDebugAllocatedCount;
#endif
    friend class SkTSpan<TCurve, OppCurve>;
    friend class SkTSpan<OppCurve, TCurve>;
    friend class SkTSect<OppCurve, TCurve>;
};

#define COINCIDENT_SPAN_COUNT 9

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTCoincident<TCurve, OppCurve>::setPerp(const TCurve& c1, double t,
    const SkDPoint& cPt, const OppCurve& c2)
{
    SkDVector dxdy = c1.dxdyAtT(t);
    SkDLine perp = { { cPt, { cPt.fX + dxdy.fY, cPt.fY - dxdy.fX } } };
=======
template<typename TCurve, typename OppCurve>
void SkTCoincident<TCurve, OppCurve>::setPerp(const TCurve& c1, double t,
        const SkDPoint& cPt, const OppCurve& c2) {
    SkDVector dxdy = c1.dxdyAtT(t);
    SkDLine perp = {{ cPt, {cPt.fX + dxdy.fY, cPt.fY - dxdy.fX} }};
>>>>>>> miniblink49
    SkIntersections i;
    int used = i.intersectRay(c2, perp);
    // only keep closest
    if (used == 0 || used == 3) {
        this->init();
        return;
<<<<<<< HEAD
    }
=======
    } 
>>>>>>> miniblink49
    fPerpT = i[0][0];
    fPerpPt = i.pt(0);
    SkASSERT(used <= 2);
    if (used == 2) {
        double distSq = (fPerpPt - cPt).lengthSquared();
        double dist2Sq = (i.pt(1) - cPt).lengthSquared();
        if (dist2Sq < distSq) {
            fPerpT = i[0][1];
            fPerpPt = i.pt(1);
        }
    }
#if DEBUG_T_SECT
    SkDebugf("setPerp t=%1.9g cPt=(%1.9g,%1.9g) %s oppT=%1.9g fPerpPt=(%1.9g,%1.9g)\n",
<<<<<<< HEAD
        t, cPt.fX, cPt.fY,
        cPt.approximatelyEqual(fPerpPt) ? "==" : "!=", fPerpT, fPerpPt.fX, fPerpPt.fY);
=======
            t, cPt.fX, cPt.fY,
            cPt.approximatelyEqual(fPerpPt) ? "==" : "!=", fPerpT, fPerpPt.fX, fPerpPt.fY);
>>>>>>> miniblink49
#endif
    fCoincident = cPt.approximatelyEqual(fPerpPt);
#if DEBUG_T_SECT
    if (fCoincident) {
<<<<<<< HEAD
        SkDebugf(""); // allow setting breakpoint
=======
        SkDebugf("");  // allow setting breakpoint
>>>>>>> miniblink49
    }
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::addBounded(SkTSpan<OppCurve, TCurve>* span, SkChunkAlloc* heap)
{
    SkTSpanBounded<OppCurve, TCurve>* bounded = new (heap->allocThrow(
        sizeof(SkTSpanBounded<OppCurve, TCurve>)))(SkTSpanBounded<OppCurve, TCurve>);
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::addBounded(SkTSpan<OppCurve, TCurve>* span, SkChunkAlloc* heap) {
    SkTSpanBounded<OppCurve, TCurve>* bounded = SkNEW_PLACEMENT(heap->allocThrow(
            sizeof(SkTSpanBounded<OppCurve, TCurve>)), (SkTSpanBounded<OppCurve, TCurve>));
>>>>>>> miniblink49
    bounded->fBounded = span;
    bounded->fNext = fBounded;
    fBounded = bounded;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::addFollowing(
    SkTSpan<TCurve, OppCurve>* prior)
{
=======
template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::addFollowing(
        SkTSpan<TCurve, OppCurve>* prior) {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* result = this->addOne();
    result->fStartT = prior ? prior->fEndT : 0;
    SkTSpan<TCurve, OppCurve>* next = prior ? prior->fNext : fHead;
    result->fEndT = next ? next->fStartT : 1;
    result->fPrev = prior;
    result->fNext = next;
    if (prior) {
        prior->fNext = result;
    } else {
        fHead = result;
    }
    if (next) {
        next->fPrev = result;
    }
    result->resetBounds(fCurve);
    return result;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::addForPerp(SkTSpan<OppCurve, TCurve>* span, double t)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::addForPerp(SkTSpan<OppCurve, TCurve>* span, double t) {
>>>>>>> miniblink49
    if (!span->hasOppT(t)) {
        SkTSpan<TCurve, OppCurve>* priorSpan;
        SkTSpan<TCurve, OppCurve>* opp = this->spanAtT(t, &priorSpan);
        if (!opp) {
            opp = this->addFollowing(priorSpan);
#if DEBUG_PERP
<<<<<<< HEAD
            SkDebugf("%s priorSpan=%d t=%1.9g opp=%d\n", __FUNCTION__, priorSpan ? priorSpan->debugID() : -1, t, opp->debugID());
#endif
        }
#if DEBUG_PERP
        opp->dump();
        SkDebugf("\n");
        SkDebugf("%s addBounded span=%d opp=%d\n", __FUNCTION__, priorSpan ? priorSpan->debugID() : -1, opp->debugID());
=======
            SkDebugf("%s priorSpan=%d t=%1.9g opp=%d\n", __FUNCTION__, priorSpan->debugID(), t,
                    opp->debugID());
#endif
        }
#if DEBUG_PERP
        opp->dump(); SkDebugf("\n");
        SkDebugf("%s addBounded span=%d opp=%d\n", __FUNCTION__, priorSpan->debugID(),
                opp->debugID());
>>>>>>> miniblink49
#endif
        opp->addBounded(span, &fHeap);
        span->addBounded(opp, &fHeap);
    }
    this->validate();
#if DEBUG_T_SECT
    span->validatePerpT(t);
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
double SkTSpan<TCurve, OppCurve>::closestBoundedT(const SkDPoint& pt) const
{
    double result = -1;
    double closest = DBL_MAX;
=======
template<typename TCurve, typename OppCurve>
double SkTSpan<TCurve, OppCurve>::closestBoundedT(const SkDPoint& pt) const {
    double result = -1;
    double closest = FLT_MAX;
>>>>>>> miniblink49
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = fBounded;
    while (testBounded) {
        const SkTSpan<OppCurve, TCurve>* test = testBounded->fBounded;
        double startDist = test->fPart[0].distanceSquared(pt);
        if (closest > startDist) {
            closest = startDist;
            result = test->fStartT;
        }
        double endDist = test->fPart[OppCurve::kPointLast].distanceSquared(pt);
        if (closest > endDist) {
            closest = endDist;
            result = test->fEndT;
        }
        testBounded = testBounded->fNext;
    }
    SkASSERT(between(0, result, 1));
    return result;
}

#ifdef SK_DEBUG
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::debugIsBefore(const SkTSpan* span) const
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::debugIsBefore(const SkTSpan* span) const {
>>>>>>> miniblink49
    const SkTSpan* work = this;
    do {
        if (span == work) {
            return true;
        }
    } while ((work = work->fNext));
    return false;
}
#endif

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::contains(double t) const
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::contains(double t) const {
>>>>>>> miniblink49
    const SkTSpan* work = this;
    do {
        if (between(work->fStartT, t, work->fEndT)) {
            return true;
        }
    } while ((work = work->fNext));
    return false;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
const SkTSect<OppCurve, TCurve>* SkTSpan<TCurve, OppCurve>::debugOpp() const
{
    return SkDEBUGRELEASE(fDebugSect->debugOpp(), nullptr);
}

template <typename TCurve, typename OppCurve>
SkTSpan<OppCurve, TCurve>* SkTSpan<TCurve, OppCurve>::findOppSpan(
    const SkTSpan<OppCurve, TCurve>* opp) const
{
=======
template<typename TCurve, typename OppCurve>
const SkTSect<OppCurve, TCurve>* SkTSpan<TCurve, OppCurve>::debugOpp() const {
    return SkDEBUGRELEASE(fDebugSect->debugOpp(), NULL);
}

template<typename TCurve, typename OppCurve>
SkTSpan<OppCurve, TCurve>* SkTSpan<TCurve, OppCurve>::findOppSpan(
        const SkTSpan<OppCurve, TCurve>* opp) const {
>>>>>>> miniblink49
    SkTSpanBounded<OppCurve, TCurve>* bounded = fBounded;
    while (bounded) {
        SkTSpan<OppCurve, TCurve>* test = bounded->fBounded;
        if (opp == test) {
            return test;
        }
        bounded = bounded->fNext;
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

// returns 0 if no hull intersection
//         1 if hulls intersect
//         2 if hulls only share a common endpoint
//        -1 if linear and further checking is required
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
int SkTSpan<TCurve, OppCurve>::hullCheck(const SkTSpan<OppCurve, TCurve>* opp,
    bool* start, bool* oppStart)
{
=======
template<typename TCurve, typename OppCurve>
int SkTSpan<TCurve, OppCurve>::hullCheck(const SkTSpan<OppCurve, TCurve>* opp,
        bool* start, bool* oppStart) {
>>>>>>> miniblink49
    if (fIsLinear) {
        return -1;
    }
    bool ptsInCommon;
    if (onlyEndPointsInCommon(opp, start, oppStart, &ptsInCommon)) {
        SkASSERT(ptsInCommon);
        return 2;
    }
    bool linear;
    if (fPart.hullIntersects(opp->fPart, &linear)) {
<<<<<<< HEAD
        if (!linear) { // check set true if linear
=======
        if (!linear) {  // check set true if linear
>>>>>>> miniblink49
            return 1;
        }
        fIsLinear = true;
        fIsLine = fPart.controlsInside();
<<<<<<< HEAD
        return ptsInCommon ? 1 : -1;
    } else { // hull is not linear; check set true if intersected at the end points
        return ((int)ptsInCommon) << 1; // 0 or 2
=======
        return ptsInCommon ? 2 : -1;
    } else {  // hull is not linear; check set true if intersected at the end points
        return ((int) ptsInCommon) << 1;  // 0 or 2
>>>>>>> miniblink49
    }
    return 0;
}

// OPTIMIZE ? If at_most_end_pts_in_common detects that one quad is near linear,
// use line intersection to guess a better split than 0.5
// OPTIMIZE Once at_most_end_pts_in_common detects linear, mark span so all future splits are linear
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
int SkTSpan<TCurve, OppCurve>::hullsIntersect(SkTSpan<OppCurve, TCurve>* opp,
    bool* start, bool* oppStart)
{
=======
template<typename TCurve, typename OppCurve>
int SkTSpan<TCurve, OppCurve>::hullsIntersect(SkTSpan<OppCurve, TCurve>* opp,
        bool* start, bool* oppStart) {
>>>>>>> miniblink49
    if (!fBounds.intersects(opp->fBounds)) {
        return 0;
    }
    int hullSect = this->hullCheck(opp, start, oppStart);
    if (hullSect >= 0) {
        return hullSect;
    }
    hullSect = opp->hullCheck(this, oppStart, start);
    if (hullSect >= 0) {
        return hullSect;
    }
    return -1;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::init(const TCurve& c)
{
    fPrev = fNext = nullptr;
    fStartT = 0;
    fEndT = 1;
    fBounded = nullptr;
    resetBounds(c);
}

template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::initBounds(const TCurve& c)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::init(const TCurve& c) {
    fPrev = fNext = NULL;
    fStartT = 0;
    fEndT = 1;
    fBounded = NULL;
    resetBounds(c);
}

template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::initBounds(const TCurve& c) {
>>>>>>> miniblink49
    fPart = c.subDivide(fStartT, fEndT);
    fBounds.setBounds(fPart);
    fCoinStart.init();
    fCoinEnd.init();
    fBoundsMax = SkTMax(fBounds.width(), fBounds.height());
    fCollapsed = fPart.collapsed();
    fHasPerp = false;
    fDeleted = false;
#if DEBUG_T_SECT
    if (fCollapsed) {
<<<<<<< HEAD
        SkDebugf(""); // for convenient breakpoints
=======
        SkDebugf("");  // for convenient breakpoints
>>>>>>> miniblink49
    }
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::linearsIntersect(SkTSpan<OppCurve, TCurve>* span)
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::linearsIntersect(SkTSpan<OppCurve, TCurve>* span) {
>>>>>>> miniblink49
    int result = this->linearIntersects(span->fPart);
    if (result <= 1) {
        return SkToBool(result);
    }
    SkASSERT(span->fIsLinear);
    result = span->linearIntersects(this->fPart);
<<<<<<< HEAD
    //    SkASSERT(result <= 1);
    return SkToBool(result);
}

template <typename TCurve, typename OppCurve>
double SkTSpan<TCurve, OppCurve>::linearT(const SkDPoint& pt) const
{
    SkDVector len = fPart[TCurve::kPointLast] - fPart[0];
    return fabs(len.fX) > fabs(len.fY)
        ? (pt.fX - fPart[0].fX) / len.fX
        : (pt.fY - fPart[0].fY) / len.fY;
}

template <typename TCurve, typename OppCurve>
int SkTSpan<TCurve, OppCurve>::linearIntersects(const OppCurve& q2) const
{
    // looks like q1 is near-linear
    int start = 0, end = TCurve::kPointLast; // the outside points are usually the extremes
    if (!fPart.controlsInside()) {
        double dist = 0; // if there's any question, compute distance to find best outsiders
=======
//    SkASSERT(result <= 1);
    return SkToBool(result);
}

template<typename TCurve, typename OppCurve>
double SkTSpan<TCurve, OppCurve>::linearT(const SkDPoint& pt) const {
    SkDVector len = fPart[TCurve::kPointLast] - fPart[0];
    return fabs(len.fX) > fabs(len.fY)
            ? (pt.fX - fPart[0].fX) / len.fX
            : (pt.fY - fPart[0].fY) / len.fY;
}

template<typename TCurve, typename OppCurve>
int SkTSpan<TCurve, OppCurve>::linearIntersects(const OppCurve& q2) const {
    // looks like q1 is near-linear
    int start = 0, end = TCurve::kPointLast;  // the outside points are usually the extremes
    if (!fPart.controlsInside()) {
        double dist = 0;  // if there's any question, compute distance to find best outsiders
>>>>>>> miniblink49
        for (int outer = 0; outer < TCurve::kPointCount - 1; ++outer) {
            for (int inner = outer + 1; inner < TCurve::kPointCount; ++inner) {
                double test = (fPart[outer] - fPart[inner]).lengthSquared();
                if (dist > test) {
                    continue;
                }
                dist = test;
                start = outer;
                end = inner;
            }
        }
    }
    // see if q2 is on one side of the line formed by the extreme points
    double origX = fPart[start].fX;
    double origY = fPart[start].fY;
    double adj = fPart[end].fX - origX;
    double opp = fPart[end].fY - origY;
    double maxPart = SkTMax(fabs(adj), fabs(opp));
<<<<<<< HEAD
    double sign = 0; // initialization to shut up warning in release build
=======
    double sign = 0;  // initialization to shut up warning in release build
>>>>>>> miniblink49
    for (int n = 0; n < OppCurve::kPointCount; ++n) {
        double dx = q2[n].fY - origY;
        double dy = q2[n].fX - origX;
        double maxVal = SkTMax(maxPart, SkTMax(fabs(dx), fabs(dy)));
        double test = (q2[n].fY - origY) * adj - (q2[n].fX - origX) * opp;
        if (precisely_zero_when_compared_to(test, maxVal)) {
            return 1;
        }
        if (approximately_zero_when_compared_to(test, maxVal)) {
            return 3;
        }
        if (n == 0) {
            sign = test;
            continue;
        }
        if (test * sign < 0) {
            return 1;
        }
    }
    return 0;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::onlyEndPointsInCommon(const SkTSpan<OppCurve, TCurve>* opp,
    bool* start, bool* oppStart, bool* ptsInCommon)
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::onlyEndPointsInCommon(const SkTSpan<OppCurve, TCurve>* opp,
        bool* start, bool* oppStart, bool* ptsInCommon) {
>>>>>>> miniblink49
    if (opp->fPart[0] == fPart[0]) {
        *start = *oppStart = true;
    } else if (opp->fPart[0] == fPart[TCurve::kPointLast]) {
        *start = false;
        *oppStart = true;
    } else if (opp->fPart[OppCurve::kPointLast] == fPart[0]) {
        *start = true;
        *oppStart = false;
    } else if (opp->fPart[OppCurve::kPointLast] == fPart[TCurve::kPointLast]) {
        *start = *oppStart = false;
    } else {
        *ptsInCommon = false;
        return false;
    }
    *ptsInCommon = true;
<<<<<<< HEAD
    const SkDPoint *otherPts[TCurve::kPointCount - 1], *oppOtherPts[OppCurve::kPointCount - 1];
=======
    const SkDPoint* otherPts[TCurve::kPointCount - 1], * oppOtherPts[OppCurve::kPointCount - 1];
>>>>>>> miniblink49
    int baseIndex = *start ? 0 : TCurve::kPointLast;
    fPart.otherPts(baseIndex, otherPts);
    opp->fPart.otherPts(*oppStart ? 0 : OppCurve::kPointLast, oppOtherPts);
    const SkDPoint& base = fPart[baseIndex];
<<<<<<< HEAD
    for (int o1 = 0; o1 < (int)SK_ARRAY_COUNT(otherPts); ++o1) {
        SkDVector v1 = *otherPts[o1] - base;
        for (int o2 = 0; o2 < (int)SK_ARRAY_COUNT(oppOtherPts); ++o2) {
=======
    for (int o1 = 0; o1 < (int) SK_ARRAY_COUNT(otherPts); ++o1) {
        SkDVector v1 = *otherPts[o1] - base;
        for (int o2 = 0; o2 < (int) SK_ARRAY_COUNT(oppOtherPts); ++o2) {
>>>>>>> miniblink49
            SkDVector v2 = *oppOtherPts[o2] - base;
            if (v2.dot(v1) >= 0) {
                return false;
            }
        }
    }
    return true;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<OppCurve, TCurve>* SkTSpan<TCurve, OppCurve>::oppT(double t) const
{
=======
template<typename TCurve, typename OppCurve>
SkTSpan<OppCurve, TCurve>* SkTSpan<TCurve, OppCurve>::oppT(double t) const {
>>>>>>> miniblink49
    SkTSpanBounded<OppCurve, TCurve>* bounded = fBounded;
    while (bounded) {
        SkTSpan<OppCurve, TCurve>* test = bounded->fBounded;
        if (between(test->fStartT, t, test->fEndT)) {
            return test;
        }
        bounded = bounded->fNext;
    }
<<<<<<< HEAD
    return nullptr;
}

template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::removeAllBounded()
{
=======
    return NULL;
}

template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::removeAllBounded() {
>>>>>>> miniblink49
    bool deleteSpan = false;
    SkTSpanBounded<OppCurve, TCurve>* bounded = fBounded;
    while (bounded) {
        SkTSpan<OppCurve, TCurve>* opp = bounded->fBounded;
        deleteSpan |= opp->removeBounded(this);
        bounded = bounded->fNext;
    }
    return deleteSpan;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::removeBounded(const SkTSpan<OppCurve, TCurve>* opp)
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::removeBounded(const SkTSpan<OppCurve, TCurve>* opp) {
>>>>>>> miniblink49
    if (fHasPerp) {
        bool foundStart = false;
        bool foundEnd = false;
        SkTSpanBounded<OppCurve, TCurve>* bounded = fBounded;
        while (bounded) {
            SkTSpan<OppCurve, TCurve>* test = bounded->fBounded;
            if (opp != test) {
                foundStart |= between(test->fStartT, fCoinStart.perpT(), test->fEndT);
                foundEnd |= between(test->fStartT, fCoinEnd.perpT(), test->fEndT);
            }
            bounded = bounded->fNext;
        }
        if (!foundStart || !foundEnd) {
            fHasPerp = false;
            fCoinStart.init();
            fCoinEnd.init();
        }
    }
    SkTSpanBounded<OppCurve, TCurve>* bounded = fBounded;
<<<<<<< HEAD
    SkTSpanBounded<OppCurve, TCurve>* prev = nullptr;
=======
    SkTSpanBounded<OppCurve, TCurve>* prev = NULL;
>>>>>>> miniblink49
    while (bounded) {
        SkTSpanBounded<OppCurve, TCurve>* boundedNext = bounded->fNext;
        if (opp == bounded->fBounded) {
            if (prev) {
                prev->fNext = boundedNext;
                return false;
            } else {
                fBounded = boundedNext;
<<<<<<< HEAD
                return fBounded == nullptr;
=======
                return fBounded == NULL;
>>>>>>> miniblink49
            }
        }
        prev = bounded;
        bounded = boundedNext;
    }
    SkASSERT(0);
    return false;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::splitAt(SkTSpan* work, double t, SkChunkAlloc* heap)
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSpan<TCurve, OppCurve>::splitAt(SkTSpan* work, double t, SkChunkAlloc* heap) {
>>>>>>> miniblink49
    fStartT = t;
    fEndT = work->fEndT;
    if (fStartT == fEndT) {
        fCollapsed = true;
        return false;
    }
    work->fEndT = t;
    if (work->fStartT == work->fEndT) {
        work->fCollapsed = true;
        return false;
    }
    fPrev = work;
    fNext = work->fNext;
    fIsLinear = work->fIsLinear;
    fIsLine = work->fIsLine;

    work->fNext = this;
    if (fNext) {
        fNext->fPrev = this;
    }
    SkTSpanBounded<OppCurve, TCurve>* bounded = work->fBounded;
<<<<<<< HEAD
    fBounded = nullptr;
=======
    fBounded = NULL;
>>>>>>> miniblink49
    while (bounded) {
        this->addBounded(bounded->fBounded, heap);
        bounded = bounded->fNext;
    }
    bounded = fBounded;
    while (bounded) {
        bounded->fBounded->addBounded(this, heap);
        bounded = bounded->fNext;
    }
    return true;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validate() const
{
#if DEBUG_T_SECT
    SkASSERT(fNext == nullptr || fNext != fPrev);
    SkASSERT(fNext == nullptr || this == fNext->fPrev);
    SkASSERT(fPrev == nullptr || this == fPrev->fNext);
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validate() const {
#if DEBUG_T_SECT
    SkASSERT(fNext == NULL || fNext != fPrev);
    SkASSERT(fNext == NULL || this == fNext->fPrev);
    SkASSERT(fPrev == NULL || this == fPrev->fNext);
>>>>>>> miniblink49
    SkASSERT(fBounds.width() || fBounds.height() || fCollapsed);
    SkASSERT(fBoundsMax == SkTMax(fBounds.width(), fBounds.height()));
    SkASSERT(0 <= fStartT);
    SkASSERT(fEndT <= 1);
    SkASSERT(fStartT <= fEndT);
    SkASSERT(fBounded);
    this->validateBounded();
    if (fHasPerp) {
        if (fCoinStart.isCoincident()) {
            validatePerpT(fCoinStart.perpT());
            validatePerpPt(fCoinStart.perpT(), fCoinStart.perpPt());
        }
        if (fCoinEnd.isCoincident()) {
            validatePerpT(fCoinEnd.perpT());
            validatePerpPt(fCoinEnd.perpT(), fCoinEnd.perpPt());
        }
    }
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validateBounded() const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validateBounded() const {
>>>>>>> miniblink49
#if DEBUG_VALIDATE
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = fBounded;
    while (testBounded) {
        SkDEBUGCODE_(const SkTSpan<OppCurve, TCurve>* overlap = testBounded->fBounded);
        SkASSERT(!overlap->fDeleted);
        SkASSERT(((this->debugID() ^ overlap->debugID()) & 1) == 1);
        SkASSERT(overlap->findOppSpan(this));
        testBounded = testBounded->fNext;
    }
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validatePerpT(double oppT) const
{
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = fBounded;
    while (testBounded) {
        const SkTSpan<OppCurve, TCurve>* overlap = testBounded->fBounded;
        if (precisely_between(overlap->fStartT, oppT, overlap->fEndT)) {
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validatePerpT(double oppT) const {
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = fBounded;
    while (testBounded) {
        const SkTSpan<OppCurve, TCurve>* overlap = testBounded->fBounded;
        if (between(overlap->fStartT, oppT, overlap->fEndT)) {
>>>>>>> miniblink49
            return;
        }
        testBounded = testBounded->fNext;
    }
    SkASSERT(0);
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validatePerpPt(double t, const SkDPoint& pt) const
{
    SkASSERT(fDebugSect->fOppSect->fCurve.ptAtT(t) == pt);
}

template <typename TCurve, typename OppCurve>
SkTSect<TCurve, OppCurve>::SkTSect(const TCurve& c PATH_OPS_DEBUG_T_SECT_PARAMS(int id))
    : fCurve(c)
    , fHeap(sizeof(SkTSpan<TCurve, OppCurve>) * 4)
    , fCoincident(nullptr)
    , fDeleted(nullptr)
    , fActiveCount(0)
          PATH_OPS_DEBUG_T_SECT_PARAMS(fID(id))
              PATH_OPS_DEBUG_T_SECT_PARAMS(fDebugCount(0))
                  PATH_OPS_DEBUG_T_SECT_PARAMS(fDebugAllocatedCount(0))
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::validatePerpPt(double t, const SkDPoint& pt) const {
    SkASSERT(fDebugSect->fOppSect->fCurve.ptAtT(t) == pt);
}


template<typename TCurve, typename OppCurve>
SkTSect<TCurve, OppCurve>::SkTSect(const TCurve& c PATH_OPS_DEBUG_T_SECT_PARAMS(int id))
    : fCurve(c)
    , fHeap(sizeof(SkTSpan<TCurve, OppCurve>) * 4)
    , fCoincident(NULL)
    , fDeleted(NULL)
    , fActiveCount(0)
    PATH_OPS_DEBUG_T_SECT_PARAMS(fID(id))
    PATH_OPS_DEBUG_T_SECT_PARAMS(fDebugCount(0))
    PATH_OPS_DEBUG_T_SECT_PARAMS(fDebugAllocatedCount(0))
>>>>>>> miniblink49
{
    fHead = addOne();
    fHead->init(c);
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::addOne()
{
    SkTSpan<TCurve, OppCurve>* result;
    if (fDeleted) {
        result = fDeleted;
        fDeleted = result->fNext;
    } else {
        result = new (fHeap.allocThrow(sizeof(SkTSpan<TCurve, OppCurve>)))(
            SkTSpan<TCurve, OppCurve>);
=======
template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::addOne() {
    SkTSpan<TCurve, OppCurve>* result;
    if (fDeleted) {
        result = fDeleted;
        result->reset();
        fDeleted = result->fNext;
    } else {
        result = SkNEW_PLACEMENT(fHeap.allocThrow(sizeof(SkTSpan<TCurve, OppCurve>)),
                (SkTSpan<TCurve, OppCurve>));
        result->fBounded = NULL;
>>>>>>> miniblink49
#if DEBUG_T_SECT
        ++fDebugAllocatedCount;
#endif
    }
<<<<<<< HEAD
    result->reset();
    result->fHasPerp = false;
    result->fDeleted = false;
    ++fActiveCount;
    PATH_OPS_DEBUG_T_SECT_CODE(result->fID = fDebugCount++ * 2 + fID);
    SkDEBUGCODE(result->fDebugSect = this);
#ifdef SK_DEBUG
    result->fPart.debugInit();
    result->fCoinStart.debugInit();
    result->fCoinEnd.debugInit();
    result->fPrev = result->fNext = nullptr;
    result->fBounds.debugInit();
    result->fStartT = result->fEndT = result->fBoundsMax = SK_ScalarNaN;
    result->fCollapsed = result->fIsLinear = result->fIsLine = 0xFF;
#endif
    return result;
}

template <typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::binarySearchCoin(SkTSect<OppCurve, TCurve>* sect2, double tStart,
    double tStep, double* resultT, double* oppT)
{
=======
    result->fHasPerp = false;
    result->fDeleted = false;
    ++fActiveCount; 
    PATH_OPS_DEBUG_T_SECT_CODE(result->fID = fDebugCount++ * 2 + fID);
    SkDEBUGCODE(result->fDebugSect = this);
    return result;
}

template<typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::binarySearchCoin(SkTSect<OppCurve, TCurve>* sect2, double tStart,
        double tStep, double* resultT, double* oppT) {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve> work;
    double result = work.fStartT = work.fEndT = tStart;
    SkDEBUGCODE(work.fDebugSect = this);
    SkDPoint last = fCurve.ptAtT(tStart);
    SkDPoint oppPt;
    bool flip = false;
    SkDEBUGCODE(bool down = tStep < 0);
    const OppCurve& opp = sect2->fCurve;
    do {
        tStep *= 0.5;
        work.fStartT += tStep;
        if (flip) {
            tStep = -tStep;
            flip = false;
        }
        work.initBounds(fCurve);
        if (work.fCollapsed) {
            return false;
        }
        if (last.approximatelyEqual(work.fPart[0])) {
            break;
        }
        last = work.fPart[0];
        work.fCoinStart.setPerp(fCurve, work.fStartT, last, opp);
        if (work.fCoinStart.isCoincident()) {
#if DEBUG_T_SECT
            work.validatePerpPt(work.fCoinStart.perpT(), work.fCoinStart.perpPt());
#endif
            double oppTTest = work.fCoinStart.perpT();
            if (sect2->fHead->contains(oppTTest)) {
                *oppT = oppTTest;
                oppPt = work.fCoinStart.perpPt();
                SkASSERT(down ? result > work.fStartT : result < work.fStartT);
                result = work.fStartT;
                continue;
            }
        }
        tStep = -tStep;
        flip = true;
    } while (true);
    if (last.approximatelyEqual(fCurve[0])) {
        result = 0;
    } else if (last.approximatelyEqual(fCurve[TCurve::kPointLast])) {
        result = 1;
    }
    if (oppPt.approximatelyEqual(opp[0])) {
        *oppT = 0;
    } else if (oppPt.approximatelyEqual(opp[OppCurve::kPointLast])) {
        *oppT = 1;
    }
    *resultT = result;
    return true;
}

// OPTIMIZE ? keep a sorted list of sizes in the form of a doubly-linked list in quad span
//            so that each quad sect has a pointer to the largest, and can update it as spans
//            are split
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::boundsMax() const
{
=======
template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::boundsMax() const {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* test = fHead;
    SkTSpan<TCurve, OppCurve>* largest = fHead;
    bool lCollapsed = largest->fCollapsed;
    while ((test = test->fNext)) {
        bool tCollapsed = test->fCollapsed;
<<<<<<< HEAD
        if ((lCollapsed && !tCollapsed) || (lCollapsed == tCollapsed && largest->fBoundsMax < test->fBoundsMax)) {
=======
        if ((lCollapsed && !tCollapsed) || (lCollapsed == tCollapsed &&
                largest->fBoundsMax < test->fBoundsMax)) {
>>>>>>> miniblink49
            largest = test;
            lCollapsed = test->fCollapsed;
        }
    }
    return largest;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::coincidentCheck(SkTSect<OppCurve, TCurve>* sect2)
{
    SkTSpan<TCurve, OppCurve>* first = fHead;
    SkTSpan<TCurve, OppCurve>*last, *next;
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::coincidentCheck(SkTSect<OppCurve, TCurve>* sect2) {
    SkTSpan<TCurve, OppCurve>* first = fHead;
    SkTSpan<TCurve, OppCurve>* last, * next;
>>>>>>> miniblink49
    do {
        int consecutive = this->countConsecutiveSpans(first, &last);
        next = last->fNext;
        if (consecutive < COINCIDENT_SPAN_COUNT) {
            continue;
        }
        this->validate();
        sect2->validate();
        this->computePerpendiculars(sect2, first, last);
        this->validate();
        sect2->validate();
        // check to see if a range of points are on the curve
        SkTSpan<TCurve, OppCurve>* coinStart = first;
        do {
            coinStart = this->extractCoincident(sect2, coinStart, last);
        } while (coinStart && !last->fDeleted);
    } while ((first = next));
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::coincidentForce(SkTSect<OppCurve, TCurve>* sect2,
    double start1s, double start1e)
{
    SkTSpan<TCurve, OppCurve>* first = fHead;
    SkTSpan<TCurve, OppCurve>* last = this->tail();
    SkTSpan<OppCurve, TCurve>* oppFirst = sect2->fHead;
    SkTSpan<OppCurve, TCurve>* oppLast = sect2->tail();
    bool deleteEmptySpans = this->updateBounded(first, last, oppFirst);
    deleteEmptySpans |= sect2->updateBounded(oppFirst, oppLast, first);
    this->removeSpanRange(first, last);
    sect2->removeSpanRange(oppFirst, oppLast);
    first->fStartT = start1s;
    first->fEndT = start1e;
    first->resetBounds(fCurve);
    first->fCoinStart.setPerp(fCurve, start1s, fCurve[0], sect2->fCurve);
    first->fCoinEnd.setPerp(fCurve, start1e, fCurve[TCurve::kPointLast], sect2->fCurve);
    bool oppMatched = first->fCoinStart.perpT() < first->fCoinEnd.perpT();
    double oppStartT = first->fCoinStart.perpT() == -1 ? 0 : SkTMax(0., first->fCoinStart.perpT());
    double oppEndT = first->fCoinEnd.perpT() == -1 ? 1 : SkTMin(1., first->fCoinEnd.perpT());
    if (!oppMatched) {
        SkTSwap(oppStartT, oppEndT);
    }
    oppFirst->fStartT = oppStartT;
    oppFirst->fEndT = oppEndT;
    oppFirst->resetBounds(sect2->fCurve);
    this->removeCoincident(first, false);
    sect2->removeCoincident(oppFirst, true);
    if (deleteEmptySpans) {
        this->deleteEmptySpans();
        sect2->deleteEmptySpans();
    }
}

template <typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::coincidentHasT(double t)
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::coincidentHasT(double t) {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* test = fCoincident;
    while (test) {
        if (between(test->fStartT, t, test->fEndT)) {
            return true;
        }
        test = test->fNext;
    }
    return false;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::collapsed() const
{
=======
template<typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::collapsed() const {
>>>>>>> miniblink49
    int result = 0;
    const SkTSpan<TCurve, OppCurve>* test = fHead;
    while (test) {
        if (test->fCollapsed) {
            ++result;
        }
        test = test->next();
    }
    return result;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::computePerpendiculars(SkTSect<OppCurve, TCurve>* sect2,
    SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>* last)
{
    const OppCurve& opp = sect2->fCurve;
    SkTSpan<TCurve, OppCurve>* work = first;
    SkTSpan<TCurve, OppCurve>* prior = nullptr;
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::computePerpendiculars(SkTSect<OppCurve, TCurve>* sect2,
        SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>* last) {
    const OppCurve& opp = sect2->fCurve;
    SkTSpan<TCurve, OppCurve>* work = first;
    SkTSpan<TCurve, OppCurve>* prior = NULL;
>>>>>>> miniblink49
    do {
        if (!work->fHasPerp && !work->fCollapsed) {
            if (prior) {
                work->fCoinStart = prior->fCoinEnd;
            } else {
                work->fCoinStart.setPerp(fCurve, work->fStartT, work->fPart[0], opp);
            }
            if (work->fCoinStart.isCoincident()) {
                double perpT = work->fCoinStart.perpT();
                if (sect2->coincidentHasT(perpT)) {
                    work->fCoinStart.init();
                } else {
                    sect2->addForPerp(work, perpT);
                }
            }
            work->fCoinEnd.setPerp(fCurve, work->fEndT, work->fPart[TCurve::kPointLast], opp);
            if (work->fCoinEnd.isCoincident()) {
                double perpT = work->fCoinEnd.perpT();
                if (sect2->coincidentHasT(perpT)) {
                    work->fCoinEnd.init();
                } else {
                    sect2->addForPerp(work, perpT);
                }
            }
            work->fHasPerp = true;
        }
        if (work == last) {
            break;
        }
        prior = work;
        work = work->fNext;
        SkASSERT(work);
    } while (true);
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::countConsecutiveSpans(SkTSpan<TCurve, OppCurve>* first,
    SkTSpan<TCurve, OppCurve>** lastPtr) const
{
=======
template<typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::countConsecutiveSpans(SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>** lastPtr) const {
>>>>>>> miniblink49
    int consecutive = 1;
    SkTSpan<TCurve, OppCurve>* last = first;
    do {
        SkTSpan<TCurve, OppCurve>* next = last->fNext;
        if (!next) {
            break;
        }
        if (next->fStartT > last->fEndT) {
            break;
        }
        ++consecutive;
        last = next;
    } while (true);
    *lastPtr = last;
    return consecutive;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::debugHasBounded(const SkTSpan<OppCurve, TCurve>* span) const
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::debugHasBounded(const SkTSpan<OppCurve, TCurve>* span) const {
>>>>>>> miniblink49
    const SkTSpan<TCurve, OppCurve>* test = fHead;
    if (!test) {
        return false;
    }
    do {
        if (test->findOppSpan(span)) {
            return true;
        }
    } while ((test = test->next()));
    return false;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::deleteEmptySpans()
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::deleteEmptySpans() {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* test;
    SkTSpan<TCurve, OppCurve>* next = fHead;
    while ((test = next)) {
        next = test->fNext;
        if (!test->fBounded) {
            this->removeSpan(test);
        }
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::extractCoincident(
    SkTSect<OppCurve, TCurve>* sect2,
    SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>* last)
{
    first = findCoincidentRun(first, &last);
    if (!first) {
        return nullptr;
=======
template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::extractCoincident(
        SkTSect<OppCurve, TCurve>* sect2,
        SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>* last) {
    first = findCoincidentRun(first, &last);
    if (!first) {
        return NULL;
>>>>>>> miniblink49
    }
    // march outwards to find limit of coincidence from here to previous and next spans
    double startT = first->fStartT;
    double oppStartT SK_INIT_TO_AVOID_WARNING;
    double oppEndT SK_INIT_TO_AVOID_WARNING;
    SkTSpan<TCurve, OppCurve>* prev = first->fPrev;
    SkASSERT(first->fCoinStart.isCoincident());
    SkTSpan<OppCurve, TCurve>* oppFirst = first->findOppT(first->fCoinStart.perpT());
    SkASSERT(last->fCoinEnd.isCoincident());
    bool oppMatched = first->fCoinStart.perpT() < first->fCoinEnd.perpT();
    double coinStart;
    SkDEBUGCODE(double coinEnd);
    SkTSpan<OppCurve, TCurve>* cutFirst;
    if (prev && prev->fEndT == startT
<<<<<<< HEAD
        && this->binarySearchCoin(sect2, startT, prev->fStartT - startT, &coinStart,
            &oppStartT)
        && prev->fStartT < coinStart && coinStart < startT
        && (cutFirst = prev->oppT(oppStartT))) {
=======
            && this->binarySearchCoin(sect2, startT, prev->fStartT - startT, &coinStart,
                                      &oppStartT)
            && prev->fStartT < coinStart && coinStart < startT
            && (cutFirst = prev->oppT(oppStartT))) {
>>>>>>> miniblink49
        oppFirst = cutFirst;
        first = this->addSplitAt(prev, coinStart);
        first->markCoincident();
        prev->fCoinEnd.markCoincident();
        if (oppFirst->fStartT < oppStartT && oppStartT < oppFirst->fEndT) {
            SkTSpan<OppCurve, TCurve>* oppHalf = sect2->addSplitAt(oppFirst, oppStartT);
            if (oppMatched) {
                oppFirst->fCoinEnd.markCoincident();
                oppHalf->markCoincident();
                oppFirst = oppHalf;
            } else {
                oppFirst->markCoincident();
                oppHalf->fCoinStart.markCoincident();
            }
        }
    } else {
        SkDEBUGCODE(coinStart = first->fStartT);
        SkDEBUGCODE(oppStartT = oppMatched ? oppFirst->fStartT : oppFirst->fEndT);
    }
    // FIXME: incomplete : if we're not at the end, find end of coin
    SkTSpan<OppCurve, TCurve>* oppLast;
    SkASSERT(last->fCoinEnd.isCoincident());
    oppLast = last->findOppT(last->fCoinEnd.perpT());
    SkDEBUGCODE(coinEnd = last->fEndT);
    SkDEBUGCODE(oppEndT = oppMatched ? oppLast->fEndT : oppLast->fStartT);
    if (!oppMatched) {
        SkTSwap(oppFirst, oppLast);
        SkTSwap(oppStartT, oppEndT);
    }
    SkASSERT(oppStartT < oppEndT);
    SkASSERT(coinStart == first->fStartT);
    SkASSERT(coinEnd == last->fEndT);
    SkASSERT(oppStartT == oppFirst->fStartT);
    SkASSERT(oppEndT == oppLast->fEndT);
    // reduce coincident runs to single entries
    this->validate();
    sect2->validate();
    bool deleteEmptySpans = this->updateBounded(first, last, oppFirst);
    deleteEmptySpans |= sect2->updateBounded(oppFirst, oppLast, first);
    this->removeSpanRange(first, last);
    sect2->removeSpanRange(oppFirst, oppLast);
    first->fEndT = last->fEndT;
    first->resetBounds(this->fCurve);
    first->fCoinStart.setPerp(fCurve, first->fStartT, first->fPart[0], sect2->fCurve);
    first->fCoinEnd.setPerp(fCurve, first->fEndT, first->fPart[TCurve::kPointLast], sect2->fCurve);
    oppStartT = first->fCoinStart.perpT();
    oppEndT = first->fCoinEnd.perpT();
    if (between(0, oppStartT, 1) && between(0, oppEndT, 1)) {
        if (!oppMatched) {
            SkTSwap(oppStartT, oppEndT);
        }
        oppFirst->fStartT = oppStartT;
        oppFirst->fEndT = oppEndT;
        oppFirst->resetBounds(sect2->fCurve);
    }
    this->validateBounded();
    sect2->validateBounded();
    last = first->fNext;
    this->removeCoincident(first, false);
    sect2->removeCoincident(oppFirst, true);
    if (deleteEmptySpans) {
        this->deleteEmptySpans();
        sect2->deleteEmptySpans();
    }
    this->validate();
    sect2->validate();
<<<<<<< HEAD
    return last && !last->fDeleted ? last : nullptr;
}

template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::findCoincidentRun(
    SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>** lastPtr)
{
    SkTSpan<TCurve, OppCurve>* work = first;
    SkTSpan<TCurve, OppCurve>* lastCandidate = nullptr;
    first = nullptr;
=======
    return last && !last->fDeleted ? last : NULL;
}

template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::findCoincidentRun(
        SkTSpan<TCurve, OppCurve>* first, SkTSpan<TCurve, OppCurve>** lastPtr) {
    SkTSpan<TCurve, OppCurve>* work = first;
    SkTSpan<TCurve, OppCurve>* lastCandidate = NULL;
    first = NULL;
>>>>>>> miniblink49
    // find the first fully coincident span
    do {
        if (work->fCoinStart.isCoincident()) {
#if DEBUG_T_SECT
            work->validatePerpT(work->fCoinStart.perpT());
            work->validatePerpPt(work->fCoinStart.perpT(), work->fCoinStart.perpPt());
#endif
            SkASSERT(work->hasOppT(work->fCoinStart.perpT()));
            if (!work->fCoinEnd.isCoincident()) {
                break;
            }
            lastCandidate = work;
            if (!first) {
                first = work;
            }
        } else if (first && work->fCollapsed) {
            *lastPtr = lastCandidate;
            return first;
        } else {
<<<<<<< HEAD
            lastCandidate = nullptr;
=======
            lastCandidate = NULL;
>>>>>>> miniblink49
            SkASSERT(!first);
        }
        if (work == *lastPtr) {
            return first;
        }
        work = work->fNext;
        SkASSERT(work);
    } while (true);
    if (lastCandidate) {
        *lastPtr = lastCandidate;
    }
    return first;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::intersects(SkTSpan<TCurve, OppCurve>* span,
    SkTSect<OppCurve, TCurve>* opp,
    SkTSpan<OppCurve, TCurve>* oppSpan, int* oppResult)
{
    bool spanStart, oppStart;
    int hullResult = span->hullsIntersect(oppSpan, &spanStart, &oppStart);
    if (hullResult >= 0) {
        if (hullResult == 2) { // hulls have one point in common
=======
template<typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::intersects(SkTSpan<TCurve, OppCurve>* span,
        SkTSect<OppCurve, TCurve>* opp,
        SkTSpan<OppCurve, TCurve>* oppSpan, int* oppResult) {
    bool spanStart, oppStart;
    int hullResult = span->hullsIntersect(oppSpan, &spanStart, &oppStart);
    if (hullResult >= 0) {
        if (hullResult == 2) {  // hulls have one point in common
>>>>>>> miniblink49
            if (!span->fBounded || !span->fBounded->fNext) {
                SkASSERT(!span->fBounded || span->fBounded->fBounded == oppSpan);
                if (spanStart) {
                    span->fEndT = span->fStartT;
                } else {
                    span->fStartT = span->fEndT;
                }
            } else {
                hullResult = 1;
            }
            if (!oppSpan->fBounded || !oppSpan->fBounded->fNext) {
                SkASSERT(!oppSpan->fBounded || oppSpan->fBounded->fBounded == span);
                if (oppStart) {
                    oppSpan->fEndT = oppSpan->fStartT;
                } else {
                    oppSpan->fStartT = oppSpan->fEndT;
                }
                *oppResult = 2;
            } else {
                *oppResult = 1;
            }
        } else {
            *oppResult = 1;
        }
        return hullResult;
    }
    if (span->fIsLine && oppSpan->fIsLine) {
        SkIntersections i;
        int sects = this->linesIntersect(span, opp, oppSpan, &i);
<<<<<<< HEAD
        if (sects == 2) {
            return *oppResult = 1;
        }
=======
>>>>>>> miniblink49
        if (!sects) {
            return -1;
        }
        span->fStartT = span->fEndT = i[0][0];
        oppSpan->fStartT = oppSpan->fEndT = i[1][0];
        return *oppResult = 2;
    }
    if (span->fIsLinear || oppSpan->fIsLinear) {
<<<<<<< HEAD
        return *oppResult = (int)span->linearsIntersect(oppSpan);
=======
        return *oppResult = (int) span->linearsIntersect(oppSpan);
>>>>>>> miniblink49
    }
    return *oppResult = 1;
}

<<<<<<< HEAD
template <typename TCurve>
static bool is_parallel(const SkDLine& thisLine, const TCurve& opp)
{
    if (!opp.IsConic()) {
        return false; // FIXME : breaks a lot of stuff now
    }
    int finds = 0;
    SkDLine thisPerp;
    thisPerp.fPts[0].fX = thisLine.fPts[1].fX + (thisLine.fPts[1].fY - thisLine.fPts[0].fY);
    thisPerp.fPts[0].fY = thisLine.fPts[1].fY + (thisLine.fPts[0].fX - thisLine.fPts[1].fX);
    thisPerp.fPts[1] = thisLine.fPts[1];
    SkIntersections perpRayI;
    perpRayI.intersectRay(opp, thisPerp);
    for (int pIndex = 0; pIndex < perpRayI.used(); ++pIndex) {
        finds += perpRayI.pt(pIndex).approximatelyEqual(thisPerp.fPts[1]);
    }
    thisPerp.fPts[1].fX = thisLine.fPts[0].fX + (thisLine.fPts[1].fY - thisLine.fPts[0].fY);
    thisPerp.fPts[1].fY = thisLine.fPts[0].fY + (thisLine.fPts[0].fX - thisLine.fPts[1].fX);
    thisPerp.fPts[0] = thisLine.fPts[0];
    perpRayI.intersectRay(opp, thisPerp);
    for (int pIndex = 0; pIndex < perpRayI.used(); ++pIndex) {
        finds += perpRayI.pt(pIndex).approximatelyEqual(thisPerp.fPts[0]);
    }
    return finds >= 2;
}

// while the intersection points are sufficiently far apart:
// construct the tangent lines from the intersections
// find the point where the tangent line intersects the opposite curve
template <typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::linesIntersect(SkTSpan<TCurve, OppCurve>* span,
    SkTSect<OppCurve, TCurve>* opp,
    SkTSpan<OppCurve, TCurve>* oppSpan, SkIntersections* i)
{
    SkIntersections thisRayI, oppRayI;
    SkDLine thisLine = { { span->fPart[0], span->fPart[TCurve::kPointLast] } };
    SkDLine oppLine = { { oppSpan->fPart[0], oppSpan->fPart[OppCurve::kPointLast] } };
=======
// while the intersection points are sufficiently far apart:
// construct the tangent lines from the intersections
// find the point where the tangent line intersects the opposite curve
template<typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::linesIntersect(SkTSpan<TCurve, OppCurve>* span,
        SkTSect<OppCurve, TCurve>* opp,
        SkTSpan<OppCurve, TCurve>* oppSpan, SkIntersections* i) {
    SkIntersections thisRayI, oppRayI;
    SkDLine thisLine = {{ span->fPart[0], span->fPart[TCurve::kPointLast] }};
    SkDLine oppLine = {{ oppSpan->fPart[0], oppSpan->fPart[OppCurve::kPointLast] }};
>>>>>>> miniblink49
    int loopCount = 0;
    double bestDistSq = DBL_MAX;
    if (!thisRayI.intersectRay(opp->fCurve, thisLine)) {
        return 0;
    }
    if (!oppRayI.intersectRay(this->fCurve, oppLine)) {
        return 0;
    }
<<<<<<< HEAD
    // if the ends of each line intersect the opposite curve, the lines are coincident
    if (thisRayI.used() > 1) {
        int ptMatches = 0;
        for (int tIndex = 0; tIndex < thisRayI.used(); ++tIndex) {
            for (int lIndex = 0; lIndex < (int)SK_ARRAY_COUNT(thisLine.fPts); ++lIndex) {
                ptMatches += thisRayI.pt(tIndex).approximatelyEqual(thisLine.fPts[lIndex]);
            }
        }
        if (ptMatches == 2 || is_parallel(thisLine, opp->fCurve)) {
            return 2;
        }
    }
    if (oppRayI.used() > 1) {
        int ptMatches = 0;
        for (int oIndex = 0; oIndex < oppRayI.used(); ++oIndex) {
            for (int lIndex = 0; lIndex < (int)SK_ARRAY_COUNT(thisLine.fPts); ++lIndex) {
                ptMatches += oppRayI.pt(oIndex).approximatelyEqual(oppLine.fPts[lIndex]);
            }
        }
        if (ptMatches == 2 || is_parallel(oppLine, this->fCurve)) {
            return 2;
        }
    }
=======
>>>>>>> miniblink49
    do {
        // pick the closest pair of points
        double closest = DBL_MAX;
        int closeIndex SK_INIT_TO_AVOID_WARNING;
        int oppCloseIndex SK_INIT_TO_AVOID_WARNING;
        for (int index = 0; index < oppRayI.used(); ++index) {
            if (!roughly_between(span->fStartT, oppRayI[0][index], span->fEndT)) {
                continue;
            }
            for (int oIndex = 0; oIndex < thisRayI.used(); ++oIndex) {
                if (!roughly_between(oppSpan->fStartT, thisRayI[0][oIndex], oppSpan->fEndT)) {
                    continue;
                }
                double distSq = thisRayI.pt(index).distanceSquared(oppRayI.pt(oIndex));
                if (closest > distSq) {
                    closest = distSq;
                    closeIndex = index;
                    oppCloseIndex = oIndex;
                }
            }
        }
        if (closest == DBL_MAX) {
            break;
        }
        const SkDPoint& oppIPt = thisRayI.pt(oppCloseIndex);
        const SkDPoint& iPt = oppRayI.pt(closeIndex);
        if (between(span->fStartT, oppRayI[0][closeIndex], span->fEndT)
<<<<<<< HEAD
            && between(oppSpan->fStartT, thisRayI[0][oppCloseIndex], oppSpan->fEndT)
            && oppIPt.approximatelyEqual(iPt)) {
=======
                && between(oppSpan->fStartT, thisRayI[0][oppCloseIndex], oppSpan->fEndT)
                && oppIPt.approximatelyEqual(iPt)) {
>>>>>>> miniblink49
            i->merge(oppRayI, closeIndex, thisRayI, oppCloseIndex);
            return i->used();
        }
        double distSq = oppIPt.distanceSquared(iPt);
        if (bestDistSq < distSq || ++loopCount > 5) {
            return 0;
        }
        bestDistSq = distSq;
        double oppStart = oppRayI[0][closeIndex];
        thisLine[0] = fCurve.ptAtT(oppStart);
        thisLine[1] = thisLine[0] + fCurve.dxdyAtT(oppStart);
        if (!thisRayI.intersectRay(opp->fCurve, thisLine)) {
            break;
        }
        double start = thisRayI[0][oppCloseIndex];
        oppLine[0] = opp->fCurve.ptAtT(start);
        oppLine[1] = oppLine[0] + opp->fCurve.dxdyAtT(start);
        if (!oppRayI.intersectRay(this->fCurve, oppLine)) {
            break;
        }
    } while (true);
    // convergence may fail if the curves are nearly coincident
    SkTCoincident<OppCurve, TCurve> oCoinS, oCoinE;
    oCoinS.setPerp(opp->fCurve, oppSpan->fStartT, oppSpan->fPart[0], fCurve);
    oCoinE.setPerp(opp->fCurve, oppSpan->fEndT, oppSpan->fPart[OppCurve::kPointLast], fCurve);
    double tStart = oCoinS.perpT();
    double tEnd = oCoinE.perpT();
    bool swap = tStart > tEnd;
    if (swap) {
        SkTSwap(tStart, tEnd);
    }
    tStart = SkTMax(tStart, span->fStartT);
    tEnd = SkTMin(tEnd, span->fEndT);
    if (tStart > tEnd) {
        return 0;
    }
    SkDVector perpS, perpE;
    if (tStart == span->fStartT) {
        SkTCoincident<TCurve, OppCurve> coinS;
        coinS.setPerp(fCurve, span->fStartT, span->fPart[0], opp->fCurve);
        perpS = span->fPart[0] - coinS.perpPt();
    } else if (swap) {
        perpS = oCoinE.perpPt() - oppSpan->fPart[OppCurve::kPointLast];
    } else {
        perpS = oCoinS.perpPt() - oppSpan->fPart[0];
    }
    if (tEnd == span->fEndT) {
        SkTCoincident<TCurve, OppCurve> coinE;
        coinE.setPerp(fCurve, span->fEndT, span->fPart[TCurve::kPointLast], opp->fCurve);
        perpE = span->fPart[TCurve::kPointLast] - coinE.perpPt();
    } else if (swap) {
        perpE = oCoinS.perpPt() - oppSpan->fPart[0];
    } else {
        perpE = oCoinE.perpPt() - oppSpan->fPart[OppCurve::kPointLast];
    }
    if (perpS.dot(perpE) >= 0) {
        return 0;
    }
    SkTCoincident<TCurve, OppCurve> coinW;
    double workT = tStart;
    double tStep = tEnd - tStart;
    SkDPoint workPt;
    do {
        tStep *= 0.5;
        if (precisely_zero(tStep)) {
            return 0;
        }
        workT += tStep;
        workPt = fCurve.ptAtT(workT);
        coinW.setPerp(fCurve, workT, workPt, opp->fCurve);
<<<<<<< HEAD
        if (coinW.perpT() < 0) {
            continue;
        }
=======
>>>>>>> miniblink49
        SkDVector perpW = workPt - coinW.perpPt();
        if ((perpS.dot(perpW) >= 0) == (tStep < 0)) {
            tStep = -tStep;
        }
<<<<<<< HEAD
        if (workPt.approximatelyEqual(coinW.perpPt())) {
            break;
        }
    } while (true);
=======
    } while (!workPt.approximatelyEqual(coinW.perpPt()));
>>>>>>> miniblink49
    double oppTTest = coinW.perpT();
    if (!opp->fHead->contains(oppTTest)) {
        return 0;
    }
    i->setMax(1);
    i->insert(workT, oppTTest, workPt);
    return 1;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::markSpanGone(SkTSpan<TCurve, OppCurve>* span)
{
=======

template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::markSpanGone(SkTSpan<TCurve, OppCurve>* span) {
>>>>>>> miniblink49
    --fActiveCount;
    span->fNext = fDeleted;
    fDeleted = span;
    SkASSERT(!span->fDeleted);
    span->fDeleted = true;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::matchedDirection(double t, const SkTSect<OppCurve, TCurve>* sect2,
    double t2) const
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::matchedDirection(double t, const SkTSect<OppCurve, TCurve>* sect2,
        double t2) const {
>>>>>>> miniblink49
    SkDVector dxdy = this->fCurve.dxdyAtT(t);
    SkDVector dxdy2 = sect2->fCurve.dxdyAtT(t2);
    return dxdy.dot(dxdy2) >= 0;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::matchedDirCheck(double t, const SkTSect<OppCurve, TCurve>* sect2,
    double t2, bool* calcMatched, bool* oppMatched) const
{
    if (*calcMatched) {
        SkASSERT(*oppMatched == this->matchedDirection(t, sect2, t2));
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::matchedDirCheck(double t, const SkTSect<OppCurve, TCurve>* sect2,
        double t2, bool* calcMatched, bool* oppMatched) const {
    if (*calcMatched) {
        SkASSERT(*oppMatched == this->matchedDirection(t, sect2, t2)); 
>>>>>>> miniblink49
    } else {
        *oppMatched = this->matchedDirection(t, sect2, t2);
        *calcMatched = true;
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::mergeCoincidence(SkTSect<OppCurve, TCurve>* sect2)
{
    double smallLimit = 0;
    do {
        // find the smallest unprocessed span
        SkTSpan<TCurve, OppCurve>* smaller = nullptr;
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::mergeCoincidence(SkTSect<OppCurve, TCurve>* sect2) {
    double smallLimit = 0;
    do {
        // find the smallest unprocessed span
        SkTSpan<TCurve, OppCurve>* smaller = NULL;
>>>>>>> miniblink49
        SkTSpan<TCurve, OppCurve>* test = fCoincident;
        do {
            if (test->fStartT < smallLimit) {
                continue;
            }
            if (smaller && smaller->fEndT < test->fStartT) {
                continue;
            }
            smaller = test;
        } while ((test = test->fNext));
        if (!smaller) {
            return;
        }
        smallLimit = smaller->fEndT;
        // find next larger span
<<<<<<< HEAD
        SkTSpan<TCurve, OppCurve>* prior = nullptr;
        SkTSpan<TCurve, OppCurve>* larger = nullptr;
        SkTSpan<TCurve, OppCurve>* largerPrior = nullptr;
=======
        SkTSpan<TCurve, OppCurve>* prior = NULL;
        SkTSpan<TCurve, OppCurve>* larger = NULL;
        SkTSpan<TCurve, OppCurve>* largerPrior = NULL;
>>>>>>> miniblink49
        test = fCoincident;
        do {
            if (test->fStartT < smaller->fEndT) {
                continue;
            }
            SkASSERT(test->fStartT != smaller->fEndT);
            if (larger && larger->fStartT < test->fStartT) {
                continue;
            }
            largerPrior = prior;
            larger = test;
        } while ((prior = test), (test = test->fNext));
        if (!larger) {
            continue;
        }
        // check middle t value to see if it is coincident as well
        double midT = (smaller->fEndT + larger->fStartT) / 2;
        SkDPoint midPt = fCurve.ptAtT(midT);
        SkTCoincident<TCurve, OppCurve> coin;
        coin.setPerp(fCurve, midT, midPt, sect2->fCurve);
        if (coin.isCoincident()) {
            smaller->fEndT = larger->fEndT;
            smaller->fCoinEnd = larger->fCoinEnd;
            if (largerPrior) {
                largerPrior->fNext = larger->fNext;
            } else {
                fCoincident = larger->fNext;
            }
        }
    } while (true);
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::prev(
    SkTSpan<TCurve, OppCurve>* span) const
{
    SkTSpan<TCurve, OppCurve>* result = nullptr;
=======
template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::prev(
        SkTSpan<TCurve, OppCurve>* span) const {
    SkTSpan<TCurve, OppCurve>* result = NULL;
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* test = fHead;
    while (span != test) {
        result = test;
        test = test->fNext;
        SkASSERT(test);
    }
<<<<<<< HEAD
    return result;
}

template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::recoverCollapsed()
{
=======
    return result; 
}

template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::recoverCollapsed() {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* deleted = fDeleted;
    while (deleted) {
        SkTSpan<TCurve, OppCurve>* delNext = deleted->fNext;
        if (deleted->fCollapsed) {
            SkTSpan<TCurve, OppCurve>** spanPtr = &fHead;
            while (*spanPtr && (*spanPtr)->fEndT <= deleted->fStartT) {
                spanPtr = &(*spanPtr)->fNext;
            }
            deleted->fNext = *spanPtr;
            *spanPtr = deleted;
        }
        deleted = delNext;
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeAllBut(const SkTSpan<OppCurve, TCurve>* keep,
    SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeAllBut(const SkTSpan<OppCurve, TCurve>* keep,
        SkTSpan<TCurve, OppCurve>* span, SkTSect<OppCurve, TCurve>* opp) {
>>>>>>> miniblink49
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = span->fBounded;
    while (testBounded) {
        SkTSpan<OppCurve, TCurve>* bounded = testBounded->fBounded;
        const SkTSpanBounded<OppCurve, TCurve>* next = testBounded->fNext;
        // may have been deleted when opp did 'remove all but'
        if (bounded != keep && !bounded->fDeleted) {
            SkAssertResult(SkDEBUGCODE(!) span->removeBounded(bounded));
            if (bounded->removeBounded(span)) {
                opp->removeSpan(bounded);
            }
        }
        testBounded = next;
    }
    SkASSERT(!span->fDeleted);
    SkASSERT(span->findOppSpan(keep));
    SkASSERT(keep->findOppSpan(span));
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeByPerpendicular(SkTSect<OppCurve, TCurve>* opp)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeByPerpendicular(SkTSect<OppCurve, TCurve>* opp) {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* test = fHead;
    SkTSpan<TCurve, OppCurve>* next;
    do {
        next = test->fNext;
        if (test->fCoinStart.perpT() < 0 || test->fCoinEnd.perpT() < 0) {
            continue;
        }
        SkDVector startV = test->fCoinStart.perpPt() - test->fPart[0];
        SkDVector endV = test->fCoinEnd.perpPt() - test->fPart[TCurve::kPointLast];
#if DEBUG_T_SECT
        SkDebugf("%s startV=(%1.9g,%1.9g) endV=(%1.9g,%1.9g) dot=%1.9g\n", __FUNCTION__,
<<<<<<< HEAD
            startV.fX, startV.fY, endV.fX, endV.fY, startV.dot(endV));
=======
                startV.fX, startV.fY, endV.fX, endV.fY, startV.dot(endV));
>>>>>>> miniblink49
#endif
        if (startV.dot(endV) <= 0) {
            continue;
        }
        this->removeSpans(test, opp);
    } while ((test = next));
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeCoincident(SkTSpan<TCurve, OppCurve>* span, bool isBetween)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeCoincident(SkTSpan<TCurve, OppCurve>* span, bool isBetween) {
>>>>>>> miniblink49
    this->unlinkSpan(span);
    if (isBetween || between(0, span->fCoinStart.perpT(), 1)) {
        --fActiveCount;
        span->fNext = fCoincident;
        fCoincident = span;
    } else {
        this->markSpanGone(span);
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeSpan(SkTSpan<TCurve, OppCurve>* span)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeSpan(SkTSpan<TCurve, OppCurve>* span) {
>>>>>>> miniblink49
    this->unlinkSpan(span);
    this->markSpanGone(span);
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeSpanRange(SkTSpan<TCurve, OppCurve>* first,
    SkTSpan<TCurve, OppCurve>* last)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeSpanRange(SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>* last) {
>>>>>>> miniblink49
    if (first == last) {
        return;
    }
    SkTSpan<TCurve, OppCurve>* span = first;
    SkASSERT(span);
    SkTSpan<TCurve, OppCurve>* final = last->fNext;
    SkTSpan<TCurve, OppCurve>* next = span->fNext;
    while ((span = next) && span != final) {
        next = span->fNext;
        this->markSpanGone(span);
    }
    if (final) {
        final->fPrev = first;
    }
    first->fNext = final;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeSpans(SkTSpan<TCurve, OppCurve>* span,
    SkTSect<OppCurve, TCurve>* opp)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::removeSpans(SkTSpan<TCurve, OppCurve>* span,
        SkTSect<OppCurve, TCurve>* opp) {
>>>>>>> miniblink49
    SkTSpanBounded<OppCurve, TCurve>* bounded = span->fBounded;
    while (bounded) {
        SkTSpan<OppCurve, TCurve>* spanBounded = bounded->fBounded;
        SkTSpanBounded<OppCurve, TCurve>* next = bounded->fNext;
<<<<<<< HEAD
        if (span->removeBounded(spanBounded)) { // shuffles last into position 0
=======
        if (span->removeBounded(spanBounded)) {  // shuffles last into position 0
>>>>>>> miniblink49
            this->removeSpan(span);
        }
        if (spanBounded->removeBounded(span)) {
            opp->removeSpan(spanBounded);
        }
        SkASSERT(!span->fDeleted || !opp->debugHasBounded(span));
        bounded = next;
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::spanAtT(double t,
    SkTSpan<TCurve, OppCurve>** priorSpan)
{
    SkTSpan<TCurve, OppCurve>* test = fHead;
    SkTSpan<TCurve, OppCurve>* prev = nullptr;
=======
template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::spanAtT(double t,
        SkTSpan<TCurve, OppCurve>** priorSpan) {
    SkTSpan<TCurve, OppCurve>* test = fHead;
    SkTSpan<TCurve, OppCurve>* prev = NULL;
>>>>>>> miniblink49
    while (test && test->fEndT < t) {
        prev = test;
        test = test->fNext;
    }
    *priorSpan = prev;
<<<<<<< HEAD
    return test && test->fStartT <= t ? test : nullptr;
}

template <typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::tail()
{
=======
    return test && test->fStartT <= t ? test : NULL;
}

template<typename TCurve, typename OppCurve>
SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::tail() {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* result = fHead;
    SkTSpan<TCurve, OppCurve>* next = fHead;
    while ((next = next->fNext)) {
        if (next->fEndT > result->fEndT) {
            result = next;
        }
    }
    return result;
}

/* Each span has a range of opposite spans it intersects. After the span is split in two,
    adjust the range to its new size */
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::trim(SkTSpan<TCurve, OppCurve>* span,
    SkTSect<OppCurve, TCurve>* opp)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::trim(SkTSpan<TCurve, OppCurve>* span,
        SkTSect<OppCurve, TCurve>* opp) {
>>>>>>> miniblink49
    span->initBounds(fCurve);
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = span->fBounded;
    while (testBounded) {
        SkTSpan<OppCurve, TCurve>* test = testBounded->fBounded;
        const SkTSpanBounded<OppCurve, TCurve>* next = testBounded->fNext;
        int oppSects, sects = this->intersects(span, opp, test, &oppSects);
        if (sects >= 1) {
            if (oppSects == 2) {
                test->initBounds(opp->fCurve);
                opp->removeAllBut(span, test, this);
            }
            if (sects == 2) {
                span->initBounds(fCurve);
                this->removeAllBut(test, span, opp);
                return;
            }
        } else {
            if (span->removeBounded(test)) {
                this->removeSpan(span);
            }
            if (test->removeBounded(span)) {
                opp->removeSpan(test);
            }
        }
        testBounded = next;
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::unlinkSpan(SkTSpan<TCurve, OppCurve>* span)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::unlinkSpan(SkTSpan<TCurve, OppCurve>* span) {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* prev = span->fPrev;
    SkTSpan<TCurve, OppCurve>* next = span->fNext;
    if (prev) {
        prev->fNext = next;
        if (next) {
            next->fPrev = prev;
        }
    } else {
        fHead = next;
        if (next) {
<<<<<<< HEAD
            next->fPrev = nullptr;
=======
            next->fPrev = NULL;
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::updateBounded(SkTSpan<TCurve, OppCurve>* first,
    SkTSpan<TCurve, OppCurve>* last, SkTSpan<OppCurve, TCurve>* oppFirst)
{
=======
template<typename TCurve, typename OppCurve>
bool SkTSect<TCurve, OppCurve>::updateBounded(SkTSpan<TCurve, OppCurve>* first,
        SkTSpan<TCurve, OppCurve>* last, SkTSpan<OppCurve, TCurve>* oppFirst) {
>>>>>>> miniblink49
    SkTSpan<TCurve, OppCurve>* test = first;
    const SkTSpan<TCurve, OppCurve>* final = last->next();
    bool deleteSpan = false;
    do {
        deleteSpan |= test->removeAllBounded();
    } while ((test = test->fNext) != final);
<<<<<<< HEAD
    first->fBounded = nullptr;
=======
    first->fBounded = NULL;
>>>>>>> miniblink49
    first->addBounded(oppFirst, &fHeap);
    // cannot call validate until remove span range is called
    return deleteSpan;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::validate() const
{
=======

template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::validate() const {
>>>>>>> miniblink49
#if DEBUG_T_SECT
    int count = 0;
    if (fHead) {
        const SkTSpan<TCurve, OppCurve>* span = fHead;
        SkASSERT(!span->fPrev);
        SkDEBUGCODE(double last = 0);
        do {
            span->validate();
            SkASSERT(span->fStartT >= last);
            SkDEBUGCODE(last = span->fEndT);
            ++count;
<<<<<<< HEAD
        } while ((span = span->fNext) != nullptr);
=======
        } while ((span = span->fNext) != NULL);
>>>>>>> miniblink49
    }
    SkASSERT(count == fActiveCount);
    SkASSERT(fActiveCount <= fDebugAllocatedCount);
    int deletedCount = 0;
    const SkTSpan<TCurve, OppCurve>* deleted = fDeleted;
    while (deleted) {
        ++deletedCount;
        deleted = deleted->fNext;
    }
    const SkTSpan<TCurve, OppCurve>* coincident = fCoincident;
    while (coincident) {
        ++deletedCount;
        coincident = coincident->fNext;
    }
    SkASSERT(fActiveCount + deletedCount == fDebugAllocatedCount);
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::validateBounded() const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::validateBounded() const {
>>>>>>> miniblink49
#if DEBUG_T_SECT
    if (!fHead) {
        return;
    }
    const SkTSpan<TCurve, OppCurve>* span = fHead;
    do {
        span->validateBounded();
<<<<<<< HEAD
    } while ((span = span->fNext) != nullptr);
#endif
}

template <typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::EndsEqual(const SkTSect<TCurve, OppCurve>* sect1,
    const SkTSect<OppCurve, TCurve>* sect2, SkIntersections* intersections)
{
=======
    } while ((span = span->fNext) != NULL);
#endif
}

template<typename TCurve, typename OppCurve>
int SkTSect<TCurve, OppCurve>::EndsEqual(const SkTSect<TCurve, OppCurve>* sect1,
        const SkTSect<OppCurve, TCurve>* sect2, SkIntersections* intersections) {
>>>>>>> miniblink49
    int zeroOneSet = 0;
    if (sect1->fCurve[0] == sect2->fCurve[0]) {
        zeroOneSet |= kZeroS1Set | kZeroS2Set;
        intersections->insert(0, 0, sect1->fCurve[0]);
    }
    if (sect1->fCurve[0] == sect2->fCurve[OppCurve::kPointLast]) {
        zeroOneSet |= kZeroS1Set | kOneS2Set;
        intersections->insert(0, 1, sect1->fCurve[0]);
    }
    if (sect1->fCurve[TCurve::kPointLast] == sect2->fCurve[0]) {
        zeroOneSet |= kOneS1Set | kZeroS2Set;
        intersections->insert(1, 0, sect1->fCurve[TCurve::kPointLast]);
    }
    if (sect1->fCurve[TCurve::kPointLast] == sect2->fCurve[OppCurve::kPointLast]) {
        zeroOneSet |= kOneS1Set | kOneS2Set;
<<<<<<< HEAD
        intersections->insert(1, 1, sect1->fCurve[TCurve::kPointLast]);
    }
    // check for zero
    if (!(zeroOneSet & (kZeroS1Set | kZeroS2Set))
        && sect1->fCurve[0].approximatelyEqual(sect2->fCurve[0])) {
=======
            intersections->insert(1, 1, sect1->fCurve[TCurve::kPointLast]);
    }
    // check for zero
    if (!(zeroOneSet & (kZeroS1Set | kZeroS2Set))
            && sect1->fCurve[0].approximatelyEqual(sect2->fCurve[0])) {
>>>>>>> miniblink49
        zeroOneSet |= kZeroS1Set | kZeroS2Set;
        intersections->insertNear(0, 0, sect1->fCurve[0], sect2->fCurve[0]);
    }
    if (!(zeroOneSet & (kZeroS1Set | kOneS2Set))
<<<<<<< HEAD
        && sect1->fCurve[0].approximatelyEqual(sect2->fCurve[OppCurve::kPointLast])) {
=======
            && sect1->fCurve[0].approximatelyEqual(sect2->fCurve[OppCurve::kPointLast])) {
>>>>>>> miniblink49
        zeroOneSet |= kZeroS1Set | kOneS2Set;
        intersections->insertNear(0, 1, sect1->fCurve[0], sect2->fCurve[OppCurve::kPointLast]);
    }
    // check for one
    if (!(zeroOneSet & (kOneS1Set | kZeroS2Set))
<<<<<<< HEAD
        && sect1->fCurve[TCurve::kPointLast].approximatelyEqual(sect2->fCurve[0])) {
=======
            && sect1->fCurve[TCurve::kPointLast].approximatelyEqual(sect2->fCurve[0])) {
>>>>>>> miniblink49
        zeroOneSet |= kOneS1Set | kZeroS2Set;
        intersections->insertNear(1, 0, sect1->fCurve[TCurve::kPointLast], sect2->fCurve[0]);
    }
    if (!(zeroOneSet & (kOneS1Set | kOneS2Set))
<<<<<<< HEAD
        && sect1->fCurve[TCurve::kPointLast].approximatelyEqual(sect2->fCurve[OppCurve::kPointLast])) {
        zeroOneSet |= kOneS1Set | kOneS2Set;
        intersections->insertNear(1, 1, sect1->fCurve[TCurve::kPointLast],
            sect2->fCurve[OppCurve::kPointLast]);
=======
            && sect1->fCurve[TCurve::kPointLast].approximatelyEqual(sect2->fCurve[
            OppCurve::kPointLast])) {
        zeroOneSet |= kOneS1Set | kOneS2Set;
        intersections->insertNear(1, 1, sect1->fCurve[TCurve::kPointLast],
                sect2->fCurve[OppCurve::kPointLast]);
>>>>>>> miniblink49
    }
    return zeroOneSet;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
struct SkClosestRecord {
    bool operator<(const SkClosestRecord& rh) const
    {
        return fClosest < rh.fClosest;
    }

    void addIntersection(SkIntersections* intersections) const
    {
=======
template<typename TCurve, typename OppCurve>
struct SkClosestRecord {
    bool operator<(const SkClosestRecord& rh) const {
        return fClosest < rh.fClosest;
    }

    void addIntersection(SkIntersections* intersections) const {
>>>>>>> miniblink49
        double r1t = fC1Index ? fC1Span->endT() : fC1Span->startT();
        double r2t = fC2Index ? fC2Span->endT() : fC2Span->startT();
        intersections->insert(r1t, r2t, fC1Span->part()[fC1Index]);
    }

    void findEnd(const SkTSpan<TCurve, OppCurve>* span1, const SkTSpan<OppCurve, TCurve>* span2,
<<<<<<< HEAD
        int c1Index, int c2Index)
    {
=======
            int c1Index, int c2Index) {
>>>>>>> miniblink49
        const TCurve& c1 = span1->part();
        const OppCurve& c2 = span2->part();
        if (!c1[c1Index].approximatelyEqual(c2[c2Index])) {
            return;
        }
        double dist = c1[c1Index].distanceSquared(c2[c2Index]);
        if (fClosest < dist) {
            return;
        }
        fC1Span = span1;
        fC2Span = span2;
        fC1StartT = span1->startT();
        fC1EndT = span1->endT();
        fC2StartT = span2->startT();
        fC2EndT = span2->endT();
        fC1Index = c1Index;
        fC2Index = c2Index;
        fClosest = dist;
    }

<<<<<<< HEAD
    bool matesWith(const SkClosestRecord& mate) const
    {
        SkASSERT(fC1Span == mate.fC1Span || fC1Span->endT() <= mate.fC1Span->startT()
            || mate.fC1Span->endT() <= fC1Span->startT());
        SkASSERT(fC2Span == mate.fC2Span || fC2Span->endT() <= mate.fC2Span->startT()
            || mate.fC2Span->endT() <= fC2Span->startT());
        return fC1Span == mate.fC1Span || fC1Span->endT() == mate.fC1Span->startT()
            || fC1Span->startT() == mate.fC1Span->endT()
            || fC2Span == mate.fC2Span
            || fC2Span->endT() == mate.fC2Span->startT()
            || fC2Span->startT() == mate.fC2Span->endT();
    }

    void merge(const SkClosestRecord& mate)
    {
=======
    bool matesWith(const SkClosestRecord& mate) const {
        SkASSERT(fC1Span == mate.fC1Span || fC1Span->endT() <= mate.fC1Span->startT()
                || mate.fC1Span->endT() <= fC1Span->startT());
        SkASSERT(fC2Span == mate.fC2Span || fC2Span->endT() <= mate.fC2Span->startT()
                || mate.fC2Span->endT() <= fC2Span->startT());
        return fC1Span == mate.fC1Span || fC1Span->endT() == mate.fC1Span->startT()
                || fC1Span->startT() == mate.fC1Span->endT()
                || fC2Span == mate.fC2Span
                || fC2Span->endT() == mate.fC2Span->startT()
                || fC2Span->startT() == mate.fC2Span->endT();
    }

    void merge(const SkClosestRecord& mate) {
>>>>>>> miniblink49
        fC1Span = mate.fC1Span;
        fC2Span = mate.fC2Span;
        fClosest = mate.fClosest;
        fC1Index = mate.fC1Index;
        fC2Index = mate.fC2Index;
    }
<<<<<<< HEAD

    void reset()
    {
        fClosest = FLT_MAX;
        SkDEBUGCODE(fC1Span = nullptr);
        SkDEBUGCODE(fC2Span = nullptr);
        SkDEBUGCODE(fC1Index = fC2Index = -1);
    }

    void update(const SkClosestRecord& mate)
    {
=======
    
    void reset() {
        fClosest = FLT_MAX;
        SkDEBUGCODE(fC1Span = NULL);
        SkDEBUGCODE(fC2Span = NULL);
        SkDEBUGCODE(fC1Index = fC2Index = -1);
    }

    void update(const SkClosestRecord& mate) {
>>>>>>> miniblink49
        fC1StartT = SkTMin(fC1StartT, mate.fC1StartT);
        fC1EndT = SkTMax(fC1EndT, mate.fC1EndT);
        fC2StartT = SkTMin(fC2StartT, mate.fC2StartT);
        fC2EndT = SkTMax(fC2EndT, mate.fC2EndT);
    }

    const SkTSpan<TCurve, OppCurve>* fC1Span;
    const SkTSpan<OppCurve, TCurve>* fC2Span;
    double fC1StartT;
    double fC1EndT;
    double fC2StartT;
    double fC2EndT;
    double fClosest;
    int fC1Index;
    int fC2Index;
};

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
struct SkClosestSect {
    SkClosestSect()
        : fUsed(0)
    {
        fClosest.push_back().reset();
    }

    bool find(const SkTSpan<TCurve, OppCurve>* span1, const SkTSpan<OppCurve, TCurve>* span2)
    {
=======
template<typename TCurve, typename OppCurve>
struct SkClosestSect {
    SkClosestSect()
        : fUsed(0) {
        fClosest.push_back().reset();
    }

    bool find(const SkTSpan<TCurve, OppCurve>* span1, const SkTSpan<OppCurve, TCurve>* span2) {
>>>>>>> miniblink49
        SkClosestRecord<TCurve, OppCurve>* record = &fClosest[fUsed];
        record->findEnd(span1, span2, 0, 0);
        record->findEnd(span1, span2, 0, OppCurve::kPointLast);
        record->findEnd(span1, span2, TCurve::kPointLast, 0);
        record->findEnd(span1, span2, TCurve::kPointLast, OppCurve::kPointLast);
        if (record->fClosest == FLT_MAX) {
            return false;
        }
        for (int index = 0; index < fUsed; ++index) {
            SkClosestRecord<TCurve, OppCurve>* test = &fClosest[index];
            if (test->matesWith(*record)) {
                if (test->fClosest > record->fClosest) {
                    test->merge(*record);
                }
                test->update(*record);
                record->reset();
                return false;
            }
        }
        ++fUsed;
        fClosest.push_back().reset();
        return true;
    }

<<<<<<< HEAD
    void finish(SkIntersections* intersections) const
    {
        SkSTArray<TCurve::kMaxIntersections * 3,
            const SkClosestRecord<TCurve, OppCurve>*, true>
            closestPtrs;
        for (int index = 0; index < fUsed; ++index) {
            closestPtrs.push_back(&fClosest[index]);
        }
        SkTQSort<const SkClosestRecord<TCurve, OppCurve>>(closestPtrs.begin(), closestPtrs.end() - 1);
=======
    void finish(SkIntersections* intersections) const {
        SkSTArray<TCurve::kMaxIntersections * 3,
                const SkClosestRecord<TCurve, OppCurve>*, true> closestPtrs;
        for (int index = 0; index < fUsed; ++index) {
            closestPtrs.push_back(&fClosest[index]);
        }
        SkTQSort<const SkClosestRecord<TCurve, OppCurve> >(closestPtrs.begin(), closestPtrs.end()
                - 1);
>>>>>>> miniblink49
        for (int index = 0; index < fUsed; ++index) {
            const SkClosestRecord<TCurve, OppCurve>* test = closestPtrs[index];
            test->addIntersection(intersections);
        }
    }

    // this is oversized so that an extra records can merge into final one
    SkSTArray<TCurve::kMaxIntersections * 2, SkClosestRecord<TCurve, OppCurve>, true> fClosest;
    int fUsed;
};

// returns true if the rect is too small to consider
<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::BinarySearch(SkTSect<TCurve, OppCurve>* sect1,
    SkTSect<OppCurve, TCurve>* sect2, SkIntersections* intersections)
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::BinarySearch(SkTSect<TCurve, OppCurve>* sect1,
        SkTSect<OppCurve, TCurve>* sect2, SkIntersections* intersections) {
>>>>>>> miniblink49
#if DEBUG_T_SECT_DUMP > 1
    gDumpTSectNum = 0;
#endif
    SkDEBUGCODE(sect1->fOppSect = sect2);
    SkDEBUGCODE(sect2->fOppSect = sect1);
    intersections->reset();
<<<<<<< HEAD
    intersections->setMax(TCurve::kMaxIntersections + 3); // give extra for slop
    SkTSpan<TCurve, OppCurve>* span1 = sect1->fHead;
    SkTSpan<OppCurve, TCurve>* span2 = sect2->fHead;
    int oppSect, sect = sect1->intersects(span1, sect2, span2, &oppSect);
    //    SkASSERT(between(0, sect, 2));
=======
    intersections->setMax(TCurve::kMaxIntersections * 3);  // give extra for slop
    SkTSpan<TCurve, OppCurve>* span1 = sect1->fHead;
    SkTSpan<OppCurve, TCurve>* span2 = sect2->fHead;
    int oppSect, sect = sect1->intersects(span1, sect2, span2, &oppSect);
//    SkASSERT(between(0, sect, 2));
>>>>>>> miniblink49
    if (!sect) {
        return;
    }
    if (sect == 2 && oppSect == 2) {
<<<<<<< HEAD
        (void)EndsEqual(sect1, sect2, intersections);
=======
        (void) EndsEqual(sect1, sect2, intersections);
>>>>>>> miniblink49
        return;
    }
    span1->addBounded(span2, &sect1->fHeap);
    span2->addBounded(span1, &sect2->fHeap);
<<<<<<< HEAD
    const int kMaxCoinLoopCount = 8;
    int coinLoopCount = kMaxCoinLoopCount;
    double start1s SK_INIT_TO_AVOID_WARNING;
    double start1e SK_INIT_TO_AVOID_WARNING;
=======
>>>>>>> miniblink49
    do {
        // find the largest bounds
        SkTSpan<TCurve, OppCurve>* largest1 = sect1->boundsMax();
        if (!largest1) {
            break;
        }
        SkTSpan<OppCurve, TCurve>* largest2 = sect2->boundsMax();
        // split it
<<<<<<< HEAD
        if (!largest2 || (largest1 && (largest1->fBoundsMax > largest2->fBoundsMax || (!largest1->fCollapsed && largest2->fCollapsed)))) {
=======
        if (!largest2 || (largest1 && (largest1->fBoundsMax > largest2->fBoundsMax
                || (!largest1->fCollapsed && largest2->fCollapsed)))) {
>>>>>>> miniblink49
            if (largest1->fCollapsed) {
                break;
            }
            // trim parts that don't intersect the opposite
            SkTSpan<TCurve, OppCurve>* half1 = sect1->addOne();
            if (!half1->split(largest1, &sect1->fHeap)) {
                break;
            }
            sect1->trim(largest1, sect2);
            sect1->trim(half1, sect2);
        } else {
            if (largest2->fCollapsed) {
                break;
            }
            // trim parts that don't intersect the opposite
            SkTSpan<OppCurve, TCurve>* half2 = sect2->addOne();
            if (!half2->split(largest2, &sect2->fHeap)) {
                break;
            }
            sect2->trim(largest2, sect1);
            sect2->trim(half2, sect1);
        }
        sect1->validate();
        sect2->validate();
<<<<<<< HEAD
#if DEBUG_T_SECT_LOOP_COUNT
        intersections->debugBumpLoopCount(SkIntersections::kIterations_DebugLoop);
#endif
        // if there are 9 or more continuous spans on both sects, suspect coincidence
        if (sect1->fActiveCount >= COINCIDENT_SPAN_COUNT
            && sect2->fActiveCount >= COINCIDENT_SPAN_COUNT) {
            if (coinLoopCount == kMaxCoinLoopCount) {
                start1s = sect1->fHead->fStartT;
                start1e = sect1->tail()->fEndT;
            }
            sect1->coincidentCheck(sect2);
            sect1->validate();
            sect2->validate();
#if DEBUG_T_SECT_LOOP_COUNT
            intersections->debugBumpLoopCount(SkIntersections::kCoinCheck_DebugLoop);
#endif
            if (!--coinLoopCount && sect1->fHead && sect2->fHead) {
                /* All known working cases resolve in two tries. Sadly, cubicConicTests[0]
                   gets stuck in a loop. It adds an extension to allow a coincident end
                   perpendicular to track its intersection in the opposite curve. However,
                   the bounding box of the extension does not intersect the original curve,
                   so the extension is discarded, only to be added again the next time around. */
                sect1->coincidentForce(sect2, start1s, start1e);
                sect1->validate();
                sect2->validate();
            }
        }
        if (sect1->fActiveCount >= COINCIDENT_SPAN_COUNT
            && sect2->fActiveCount >= COINCIDENT_SPAN_COUNT) {
=======
        // if there are 9 or more continuous spans on both sects, suspect coincidence
        if (sect1->fActiveCount >= COINCIDENT_SPAN_COUNT
                && sect2->fActiveCount >= COINCIDENT_SPAN_COUNT) {
            sect1->coincidentCheck(sect2);
            sect1->validate();
            sect2->validate();
        }
        if (sect1->fActiveCount >= COINCIDENT_SPAN_COUNT
                && sect2->fActiveCount >= COINCIDENT_SPAN_COUNT) {
>>>>>>> miniblink49
            sect1->computePerpendiculars(sect2, sect1->fHead, sect1->tail());
            sect2->computePerpendiculars(sect1, sect2->fHead, sect2->tail());
            sect1->removeByPerpendicular(sect2);
            sect1->validate();
            sect2->validate();
<<<<<<< HEAD
#if DEBUG_T_SECT_LOOP_COUNT
            intersections->debugBumpLoopCount(SkIntersections::kComputePerp_DebugLoop);
#endif
=======
>>>>>>> miniblink49
            if (sect1->collapsed() > TCurve::kMaxIntersections) {
                break;
            }
        }
#if DEBUG_T_SECT_DUMP
        sect1->dumpBoth(sect2);
#endif
        if (!sect1->fHead || !sect2->fHead) {
            break;
        }
    } while (true);
    SkTSpan<TCurve, OppCurve>* coincident = sect1->fCoincident;
    if (coincident) {
        // if there is more than one coincident span, check loosely to see if they should be joined
        if (coincident->fNext) {
            sect1->mergeCoincidence(sect2);
            coincident = sect1->fCoincident;
        }
<<<<<<< HEAD
        SkASSERT(sect2->fCoincident); // courtesy check : coincidence only looks at sect 1
        do {
            if (!coincident->fCoinStart.isCoincident()) {
                continue;
            }
            if (!coincident->fCoinEnd.isCoincident()) {
                continue;
            }
            int index = intersections->insertCoincident(coincident->fStartT,
                coincident->fCoinStart.perpT(), coincident->fPart[0]);
            if ((intersections->insertCoincident(coincident->fEndT,
                     coincident->fCoinEnd.perpT(),
                     coincident->fPart[TCurve::kPointLast])
                    < 0)
                && index >= 0) {
=======
        SkASSERT(sect2->fCoincident);  // courtesy check : coincidence only looks at sect 1
        do {
            SkASSERT(coincident->fCoinStart.isCoincident());
            SkASSERT(coincident->fCoinEnd.isCoincident());
            int index = intersections->insertCoincident(coincident->fStartT,
                    coincident->fCoinStart.perpT(), coincident->fPart[0]);
            if ((intersections->insertCoincident(coincident->fEndT,
                    coincident->fCoinEnd.perpT(),
                    coincident->fPart[TCurve::kPointLast]) < 0) && index >= 0) {
>>>>>>> miniblink49
                intersections->clearCoincidence(index);
            }
        } while ((coincident = coincident->fNext));
    }
    int zeroOneSet = EndsEqual(sect1, sect2, intersections);
    if (!sect1->fHead || !sect2->fHead) {
        return;
    }
    sect1->recoverCollapsed();
    sect2->recoverCollapsed();
    SkTSpan<TCurve, OppCurve>* result1 = sect1->fHead;
    // check heads and tails for zero and ones and insert them if we haven't already done so
    const SkTSpan<TCurve, OppCurve>* head1 = result1;
    if (!(zeroOneSet & kZeroS1Set) && approximately_less_than_zero(head1->fStartT)) {
        const SkDPoint& start1 = sect1->fCurve[0];
        if (head1->isBounded()) {
            double t = head1->closestBoundedT(start1);
            if (sect2->fCurve.ptAtT(t).approximatelyEqual(start1)) {
                intersections->insert(0, t, start1);
            }
        }
    }
    const SkTSpan<OppCurve, TCurve>* head2 = sect2->fHead;
    if (!(zeroOneSet & kZeroS2Set) && approximately_less_than_zero(head2->fStartT)) {
        const SkDPoint& start2 = sect2->fCurve[0];
        if (head2->isBounded()) {
            double t = head2->closestBoundedT(start2);
            if (sect1->fCurve.ptAtT(t).approximatelyEqual(start2)) {
                intersections->insert(t, 0, start2);
            }
        }
    }
    const SkTSpan<TCurve, OppCurve>* tail1 = sect1->tail();
    if (!(zeroOneSet & kOneS1Set) && approximately_greater_than_one(tail1->fEndT)) {
        const SkDPoint& end1 = sect1->fCurve[TCurve::kPointLast];
        if (tail1->isBounded()) {
            double t = tail1->closestBoundedT(end1);
            if (sect2->fCurve.ptAtT(t).approximatelyEqual(end1)) {
                intersections->insert(1, t, end1);
            }
        }
    }
    const SkTSpan<OppCurve, TCurve>* tail2 = sect2->tail();
    if (!(zeroOneSet & kOneS2Set) && approximately_greater_than_one(tail2->fEndT)) {
        const SkDPoint& end2 = sect2->fCurve[OppCurve::kPointLast];
        if (tail2->isBounded()) {
            double t = tail2->closestBoundedT(end2);
            if (sect1->fCurve.ptAtT(t).approximatelyEqual(end2)) {
                intersections->insert(t, 1, end2);
            }
        }
    }
    SkClosestSect<TCurve, OppCurve> closest;
    do {
        while (result1 && result1->fCoinStart.isCoincident() && result1->fCoinEnd.isCoincident()) {
            result1 = result1->fNext;
        }
        if (!result1) {
            break;
        }
        SkTSpan<OppCurve, TCurve>* result2 = sect2->fHead;
        bool found = false;
        while (result2) {
            found |= closest.find(result1, result2);
            result2 = result2->fNext;
        }
    } while ((result1 = result1->fNext));
    closest.finish(intersections);
    // if there is more than one intersection and it isn't already coincident, check
    int last = intersections->used() - 1;
<<<<<<< HEAD
    for (int index = 0; index < last;) {
=======
    for (int index = 0; index < last; ) {
>>>>>>> miniblink49
        if (intersections->isCoincident(index) && intersections->isCoincident(index + 1)) {
            ++index;
            continue;
        }
        double midT = ((*intersections)[0][index] + (*intersections)[0][index + 1]) / 2;
        SkDPoint midPt = sect1->fCurve.ptAtT(midT);
        // intersect perpendicular with opposite curve
        SkTCoincident<TCurve, OppCurve> perp;
        perp.setPerp(sect1->fCurve, midT, midPt, sect2->fCurve);
        if (!perp.isCoincident()) {
            ++index;
            continue;
        }
        if (intersections->isCoincident(index)) {
            intersections->removeOne(index);
            --last;
        } else if (intersections->isCoincident(index + 1)) {
            intersections->removeOne(index + 1);
            --last;
        } else {
            intersections->setCoincident(index++);
        }
        intersections->setCoincident(index);
    }
    SkASSERT(intersections->used() <= TCurve::kMaxIntersections);
}
<<<<<<< HEAD

#endif
=======
>>>>>>> miniblink49
