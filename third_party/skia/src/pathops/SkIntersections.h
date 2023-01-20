/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkIntersections_DEFINE
#define SkIntersections_DEFINE

#include "SkPathOpsConic.h"
#include "SkPathOpsCubic.h"
#include "SkPathOpsLine.h"
#include "SkPathOpsPoint.h"
#include "SkPathOpsQuad.h"

class SkIntersections {
public:
<<<<<<< HEAD
    SkIntersections(SkDEBUGCODE(SkOpGlobalState* globalState = nullptr))
        : fSwap(0)
#ifdef SK_DEBUG
            SkDEBUGPARAMS(fDebugGlobalState(globalState))
=======
    SkIntersections()
        : fSwap(0)
#ifdef SK_DEBUG
>>>>>>> miniblink49
        , fDepth(0)
#endif
    {
        sk_bzero(fPt, sizeof(fPt));
        sk_bzero(fPt2, sizeof(fPt2));
        sk_bzero(fT, sizeof(fT));
        sk_bzero(fNearlySame, sizeof(fNearlySame));
<<<<<<< HEAD
#if DEBUG_T_SECT_LOOP_COUNT
        sk_bzero(fDebugLoopCount, sizeof(fDebugLoopCount));
#endif
        reset();
        fMax = 0; // require that the caller set the max
=======
        reset();
        fMax = 0;  // require that the caller set the max
>>>>>>> miniblink49
    }

    class TArray {
    public:
<<<<<<< HEAD
        explicit TArray(const double ts[10])
            : fTArray(ts)
        {
        }
        double operator[](int n) const
        {
=======
        explicit TArray(const double ts[10]) : fTArray(ts) {}
        double operator[](int n) const {
>>>>>>> miniblink49
            return fTArray[n];
        }
        const double* fTArray;
    };
    TArray operator[](int n) const { return TArray(fT[n]); }

<<<<<<< HEAD
    void allowNear(bool nearAllowed)
    {
        fAllowNear = nearAllowed;
    }

    void clearCoincidence(int index)
    {
=======
    void allowNear(bool nearAllowed) {
        fAllowNear = nearAllowed;
    }

    void clearCoincidence(int index) {
>>>>>>> miniblink49
        SkASSERT(index >= 0);
        int bit = 1 << index;
        fIsCoincident[0] &= ~bit;
        fIsCoincident[1] &= ~bit;
    }

    int conicHorizontal(const SkPoint a[3], SkScalar weight, SkScalar left, SkScalar right,
<<<<<<< HEAD
        SkScalar y, bool flipped)
    {
=======
                SkScalar y, bool flipped) {
>>>>>>> miniblink49
        SkDConic conic;
        conic.set(a, weight);
        fMax = 2;
        return horizontal(conic, left, right, y, flipped);
    }

    int conicVertical(const SkPoint a[3], SkScalar weight, SkScalar top, SkScalar bottom,
<<<<<<< HEAD
        SkScalar x, bool flipped)
    {
=======
            SkScalar x, bool flipped) {
>>>>>>> miniblink49
        SkDConic conic;
        conic.set(a, weight);
        fMax = 2;
        return vertical(conic, top, bottom, x, flipped);
    }

<<<<<<< HEAD
    int conicLine(const SkPoint a[3], SkScalar weight, const SkPoint b[2])
    {
=======
    int conicLine(const SkPoint a[3], SkScalar weight, const SkPoint b[2]) {
>>>>>>> miniblink49
        SkDConic conic;
        conic.set(a, weight);
        SkDLine line;
        line.set(b);
        fMax = 3; // 2;  permit small coincident segment + non-coincident intersection
        return intersect(conic, line);
    }

    int cubicHorizontal(const SkPoint a[4], SkScalar left, SkScalar right, SkScalar y,
<<<<<<< HEAD
        bool flipped)
    {
=======
                        bool flipped) {
>>>>>>> miniblink49
        SkDCubic cubic;
        cubic.set(a);
        fMax = 3;
        return horizontal(cubic, left, right, y, flipped);
    }

<<<<<<< HEAD
    int cubicVertical(const SkPoint a[4], SkScalar top, SkScalar bottom, SkScalar x, bool flipped)
    {
=======
    int cubicVertical(const SkPoint a[4], SkScalar top, SkScalar bottom, SkScalar x, bool flipped) {
>>>>>>> miniblink49
        SkDCubic cubic;
        cubic.set(a);
        fMax = 3;
        return vertical(cubic, top, bottom, x, flipped);
    }

<<<<<<< HEAD
    int cubicLine(const SkPoint a[4], const SkPoint b[2])
    {
=======
    int cubicLine(const SkPoint a[4], const SkPoint b[2]) {
>>>>>>> miniblink49
        SkDCubic cubic;
        cubic.set(a);
        SkDLine line;
        line.set(b);
        fMax = 3;
        return intersect(cubic, line);
    }

<<<<<<< HEAD
#ifdef SK_DEBUG
    SkOpGlobalState* debugGlobalState()
    {
        return fDebugGlobalState;
    }
#endif

    bool hasT(double t) const
    {
=======
    bool hasT(double t) const {
>>>>>>> miniblink49
        SkASSERT(t == 0 || t == 1);
        return fUsed > 0 && (t == 0 ? fT[0][0] == 0 : fT[0][fUsed - 1] == 1);
    }

<<<<<<< HEAD
    int insertSwap(double one, double two, const SkDPoint& pt)
    {
=======
    int insertSwap(double one, double two, const SkDPoint& pt) {
>>>>>>> miniblink49
        if (fSwap) {
            return insert(two, one, pt);
        } else {
            return insert(one, two, pt);
        }
    }

<<<<<<< HEAD
    bool isCoincident(int index)
    {
=======
    bool isCoincident(int index) {
>>>>>>> miniblink49
        return (fIsCoincident[0] & 1 << index) != 0;
    }

    int lineHorizontal(const SkPoint a[2], SkScalar left, SkScalar right, SkScalar y,
<<<<<<< HEAD
        bool flipped)
    {
=======
                       bool flipped) {
>>>>>>> miniblink49
        SkDLine line;
        line.set(a);
        fMax = 2;
        return horizontal(line, left, right, y, flipped);
    }

<<<<<<< HEAD
    int lineVertical(const SkPoint a[2], SkScalar top, SkScalar bottom, SkScalar x, bool flipped)
    {
=======
    int lineVertical(const SkPoint a[2], SkScalar top, SkScalar bottom, SkScalar x, bool flipped) {
>>>>>>> miniblink49
        SkDLine line;
        line.set(a);
        fMax = 2;
        return vertical(line, top, bottom, x, flipped);
    }

<<<<<<< HEAD
    int lineLine(const SkPoint a[2], const SkPoint b[2])
    {
=======
    int lineLine(const SkPoint a[2], const SkPoint b[2]) {
>>>>>>> miniblink49
        SkDLine aLine, bLine;
        aLine.set(a);
        bLine.set(b);
        fMax = 2;
        return intersect(aLine, bLine);
    }

<<<<<<< HEAD
    bool nearlySame(int index) const
    {
=======
    bool nearlySame(int index) const {
>>>>>>> miniblink49
        SkASSERT(index == 0 || index == 1);
        return fNearlySame[index];
    }

<<<<<<< HEAD
    const SkDPoint& pt(int index) const
    {
        return fPt[index];
    }

    const SkDPoint& pt2(int index) const
    {
=======
    const SkDPoint& pt(int index) const {
        return fPt[index];
    }

    const SkDPoint& pt2(int index) const {
>>>>>>> miniblink49
        return fPt2[index];
    }

    int quadHorizontal(const SkPoint a[3], SkScalar left, SkScalar right, SkScalar y,
<<<<<<< HEAD
        bool flipped)
    {
=======
                       bool flipped) {
>>>>>>> miniblink49
        SkDQuad quad;
        quad.set(a);
        fMax = 2;
        return horizontal(quad, left, right, y, flipped);
    }

<<<<<<< HEAD
    int quadVertical(const SkPoint a[3], SkScalar top, SkScalar bottom, SkScalar x, bool flipped)
    {
=======
    int quadVertical(const SkPoint a[3], SkScalar top, SkScalar bottom, SkScalar x, bool flipped) {
>>>>>>> miniblink49
        SkDQuad quad;
        quad.set(a);
        fMax = 2;
        return vertical(quad, top, bottom, x, flipped);
    }

<<<<<<< HEAD
    int quadLine(const SkPoint a[3], const SkPoint b[2])
    {
=======
    int quadLine(const SkPoint a[3], const SkPoint b[2]) {
>>>>>>> miniblink49
        SkDQuad quad;
        quad.set(a);
        SkDLine line;
        line.set(b);
        fMax = 3; // 2;  permit small coincident segment + non-coincident intersection
        return intersect(quad, line);
    }

    // leaves swap, max alone
<<<<<<< HEAD
    void reset()
    {
=======
    void reset() {
>>>>>>> miniblink49
        fAllowNear = true;
        fUsed = 0;
        sk_bzero(fIsCoincident, sizeof(fIsCoincident));
    }

<<<<<<< HEAD
    void set(bool swap, int tIndex, double t)
    {
        fT[(int)swap][tIndex] = t;
    }

    void setMax(int max)
    {
        SkASSERT(max <= (int)SK_ARRAY_COUNT(fPt));
        fMax = max;
    }

    void swap()
    {
        fSwap ^= true;
    }

    bool swapped() const
    {
        return fSwap;
    }

    int used() const
    {
        return fUsed;
    }

    void downDepth()
    {
        SkASSERT(--fDepth >= 0);
    }

    bool unBumpT(int index)
    {
=======
    void set(bool swap, int tIndex, double t) {
        fT[(int) swap][tIndex] = t;
    }

    void setMax(int max) {
        fMax = max;
    }

    void swap() {
        fSwap ^= true;
    }

    bool swapped() const {
        return fSwap;
    }
    
    int used() const {
        return fUsed;
    }

    void downDepth() {
        SkASSERT(--fDepth >= 0);
    }

    bool unBumpT(int index) {
>>>>>>> miniblink49
        SkASSERT(fUsed == 1);
        fT[0][index] = fT[0][index] * (1 + BUMP_EPSILON * 2) - BUMP_EPSILON;
        if (!between(0, fT[0][index], 1)) {
            fUsed = 0;
            return false;
        }
        return true;
    }

<<<<<<< HEAD
    void upDepth()
    {
=======
    void upDepth() {
>>>>>>> miniblink49
        SkASSERT(++fDepth < 16);
    }

    void alignQuadPts(const SkPoint a[3], const SkPoint b[3]);
    int cleanUpCoincidence();
    int closestTo(double rangeStart, double rangeEnd, const SkDPoint& testPt, double* dist) const;
    void cubicInsert(double one, double two, const SkDPoint& pt, const SkDCubic& c1,
<<<<<<< HEAD
        const SkDCubic& c2);
=======
                     const SkDCubic& c2);
>>>>>>> miniblink49
    void flip();
    int horizontal(const SkDLine&, double left, double right, double y, bool flipped);
    int horizontal(const SkDQuad&, double left, double right, double y, bool flipped);
    int horizontal(const SkDQuad&, double left, double right, double y, double tRange[2]);
    int horizontal(const SkDCubic&, double y, double tRange[3]);
    int horizontal(const SkDConic&, double left, double right, double y, bool flipped);
    int horizontal(const SkDCubic&, double left, double right, double y, bool flipped);
    int horizontal(const SkDCubic&, double left, double right, double y, double tRange[3]);
    static double HorizontalIntercept(const SkDLine& line, double y);
    static int HorizontalIntercept(const SkDQuad& quad, SkScalar y, double* roots);
    static int HorizontalIntercept(const SkDConic& conic, SkScalar y, double* roots);
    // FIXME : does not respect swap
    int insert(double one, double two, const SkDPoint& pt);
    void insertNear(double one, double two, const SkDPoint& pt1, const SkDPoint& pt2);
    // start if index == 0 : end if index == 1
    int insertCoincident(double one, double two, const SkDPoint& pt);
    int intersect(const SkDLine&, const SkDLine&);
    int intersect(const SkDQuad&, const SkDLine&);
    int intersect(const SkDQuad&, const SkDQuad&);
    int intersect(const SkDConic&, const SkDLine&);
    int intersect(const SkDConic&, const SkDQuad&);
    int intersect(const SkDConic&, const SkDConic&);
    int intersect(const SkDCubic&, const SkDLine&);
    int intersect(const SkDCubic&, const SkDQuad&);
    int intersect(const SkDCubic&, const SkDConic&);
    int intersect(const SkDCubic&, const SkDCubic&);
    int intersectRay(const SkDLine&, const SkDLine&);
    int intersectRay(const SkDQuad&, const SkDLine&);
    int intersectRay(const SkDConic&, const SkDLine&);
    int intersectRay(const SkDCubic&, const SkDLine&);
<<<<<<< HEAD
    void merge(const SkIntersections&, int, const SkIntersections&, int);
=======
    void merge(const SkIntersections& , int , const SkIntersections& , int );
>>>>>>> miniblink49
    int mostOutside(double rangeStart, double rangeEnd, const SkDPoint& origin) const;
    void removeOne(int index);
    void setCoincident(int index);
    int vertical(const SkDLine&, double top, double bottom, double x, bool flipped);
    int vertical(const SkDQuad&, double top, double bottom, double x, bool flipped);
    int vertical(const SkDConic&, double top, double bottom, double x, bool flipped);
    int vertical(const SkDCubic&, double top, double bottom, double x, bool flipped);
    static double VerticalIntercept(const SkDLine& line, double x);
    static int VerticalIntercept(const SkDQuad& quad, SkScalar x, double* roots);
    static int VerticalIntercept(const SkDConic& conic, SkScalar x, double* roots);

<<<<<<< HEAD
    int depth() const
    {
=======
    int depth() const {
>>>>>>> miniblink49
#ifdef SK_DEBUG
        return fDepth;
#else
        return 0;
#endif
    }

<<<<<<< HEAD
    enum DebugLoop {
        kIterations_DebugLoop,
        kCoinCheck_DebugLoop,
        kComputePerp_DebugLoop,
    };

    void debugBumpLoopCount(DebugLoop);
    int debugCoincidentUsed() const;
    int debugLoopCount(DebugLoop) const;
    void debugResetLoopCount();
    void dump() const; // implemented for testing only
=======
    int debugCoincidentUsed() const;
    void dump() const;  // implemented for testing only
>>>>>>> miniblink49

private:
    bool cubicCheckCoincidence(const SkDCubic& c1, const SkDCubic& c2);
    bool cubicExactEnd(const SkDCubic& cubic1, bool start, const SkDCubic& cubic2);
<<<<<<< HEAD
    void cubicNearEnd(const SkDCubic& cubic1, bool start, const SkDCubic& cubic2, const SkDRect&);
    void cleanUpParallelLines(bool parallel);
    void computePoints(const SkDLine& line, int used);

    SkDPoint fPt[12]; // FIXME: since scans store points as SkPoint, this should also
    SkDPoint fPt2[2]; // used by nearly same to store alternate intersection point
    double fT[2][12];
    uint16_t fIsCoincident[2]; // bit set for each curve's coincident T
    bool fNearlySame[2]; // true if end points nearly match
=======
    void cubicNearEnd(const SkDCubic& cubic1, bool start, const SkDCubic& cubic2, const SkDRect& );
    void cleanUpParallelLines(bool parallel);
    void computePoints(const SkDLine& line, int used);

    SkDPoint fPt[10];  // FIXME: since scans store points as SkPoint, this should also
    SkDPoint fPt2[2];  // used by nearly same to store alternate intersection point
    double fT[2][10];
    uint16_t fIsCoincident[2];  // bit set for each curve's coincident T
    bool fNearlySame[2];  // true if end points nearly match
>>>>>>> miniblink49
    unsigned char fUsed;
    unsigned char fMax;
    bool fAllowNear;
    bool fSwap;
#ifdef SK_DEBUG
<<<<<<< HEAD
    SkOpGlobalState* fDebugGlobalState;
    int fDepth;
#endif
#if DEBUG_T_SECT_LOOP_COUNT
    int fDebugLoopCount[3];
#endif
=======
    int fDepth;
#endif
>>>>>>> miniblink49
};

#endif
