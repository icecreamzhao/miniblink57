/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPathOpsTSect.h"

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
char SkTCoincident<TCurve, OppCurve>::dumpIsCoincidentStr() const
{
    if (!!fCoincident != fCoincident) {
        return '?';
    }
    return fCoincident ? '*' : 0;
}

template <typename TCurve, typename OppCurve>
void SkTCoincident<TCurve, OppCurve>::dump() const
{
    SkDebugf("t=%1.9g pt=(%1.9g,%1.9g)%s\n", fPerpT, fPerpPt.fX, fPerpPt.fY,
        fCoincident ? " coincident" : "");
}

template <typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::debugSpan(int id) const
{
=======
template<typename TCurve, typename OppCurve>
void SkTCoincident<TCurve, OppCurve>::dump() const {
    SkDebugf("t=%1.9g pt=(%1.9g,%1.9g)%s\n", fPerpT, fPerpPt.fX, fPerpPt.fY,
            fCoincident ? " coincident" : "");
}

template<typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::debugSpan(int id) const {
>>>>>>> miniblink49
    const SkTSpan<TCurve, OppCurve>* test = fHead;
    do {
        if (test->debugID() == id) {
            return test;
        }
    } while ((test = test->next()));
<<<<<<< HEAD
    return nullptr;
}

template <typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::debugT(double t) const
{
    const SkTSpan<TCurve, OppCurve>* test = fHead;
    const SkTSpan<TCurve, OppCurve>* closest = nullptr;
=======
    return NULL;
}

template<typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSect<TCurve, OppCurve>::debugT(double t) const {
    const SkTSpan<TCurve, OppCurve>* test = fHead;
    const SkTSpan<TCurve, OppCurve>* closest = NULL;
>>>>>>> miniblink49
    double bestDist = DBL_MAX;
    do {
        if (between(test->fStartT, t, test->fEndT)) {
            return test;
        }
        double testDist = SkTMin(fabs(test->fStartT - t), fabs(test->fEndT - t));
        if (bestDist > testDist) {
            bestDist = testDist;
            closest = test;
        }
    } while ((test = test->next()));
    SkASSERT(closest);
    return closest;
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dump() const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dump() const {
>>>>>>> miniblink49
    dumpCommon(fHead);
}

extern int gDumpTSectNum;

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpBoth(SkTSect<OppCurve, TCurve>* opp) const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpBoth(SkTSect<OppCurve, TCurve>* opp) const {
>>>>>>> miniblink49
#if DEBUG_T_SECT_DUMP <= 2
#if DEBUG_T_SECT_DUMP == 2
    SkDebugf("%d ", ++gDumpTSectNum);
#endif
    this->dump();
    SkDebugf(" ");
    opp->dump();
    SkDebugf("\n");
#elif DEBUG_T_SECT_DUMP == 3
    SkDebugf("<div id=\"sect%d\">\n", ++gDumpTSectNum);
    if (this->fHead) {
        this->dumpCurves();
    }
    if (opp->fHead) {
        opp->dumpCurves();
    }
    SkDebugf("</div>\n\n");
#endif
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpBounded(int id) const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpBounded(int id) const {
>>>>>>> miniblink49
    const SkTSpan<TCurve, OppCurve>* bounded = debugSpan(id);
    if (!bounded) {
        SkDebugf("no span matches %d\n", id);
        return;
    }
    const SkTSpan<OppCurve, TCurve>* test = bounded->debugOpp()->fHead;
    do {
        if (test->findOppSpan(bounded)) {
            test->dump();
<<<<<<< HEAD
            SkDebugf(" ");
        }
    } while ((test = test->next()));
    SkDebugf("\n");
}

template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpBounds() const
{
=======
        }
    } while ((test = test->next()));
}

template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpBounds() const {
>>>>>>> miniblink49
    const SkTSpan<TCurve, OppCurve>* test = fHead;
    do {
        test->dumpBounds();
    } while ((test = test->next()));
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCoin() const
{
    dumpCommon(fCoincident);
}

template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCoinCurves() const
{
    dumpCommonCurves(fCoincident);
}

template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCommon(const SkTSpan<TCurve, OppCurve>* test) const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCoin() const {
    dumpCommon(fCoincident);
}

template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCoinCurves() const {
    dumpCommonCurves(fCoincident);
}

template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCommon(const SkTSpan<TCurve, OppCurve>* test) const {
>>>>>>> miniblink49
    SkDebugf("id=%d", debugID());
    if (!test) {
        SkDebugf(" (empty)");
        return;
    }
    do {
        SkDebugf(" ");
        test->dump();
    } while ((test = test->next()));
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCommonCurves(const SkTSpan<TCurve, OppCurve>* test) const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCommonCurves(const SkTSpan<TCurve, OppCurve>* test) const {
>>>>>>> miniblink49
    do {
        test->fPart.dumpID(test->debugID());
    } while ((test = test->next()));
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCurves() const
{
    dumpCommonCurves(fHead);
}

template <typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSpan<TCurve, OppCurve>::debugSpan(int id) const
{
    return SkDEBUGRELEASE(fDebugSect->debugSpan(id), nullptr);
}

template <typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSpan<TCurve, OppCurve>::debugT(double t) const
{
    return SkDEBUGRELEASE(fDebugSect->debugT(t), nullptr);
}

template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpAll() const
{
    dumpID();
    SkDebugf("=(%g,%g) [", fStartT, fEndT);
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = fBounded;
    while (testBounded) {
        const SkTSpan<OppCurve, TCurve>* span = testBounded->fBounded;
        const SkTSpanBounded<OppCurve, TCurve>* next = testBounded->fNext;
        span->dumpID();
        SkDebugf("=(%g,%g)", span->fStartT, span->fEndT);
        if (next) {
            SkDebugf(" ");
        }
        testBounded = next;
    }
    SkDebugf("]\n");
}

template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dump() const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSect<TCurve, OppCurve>::dumpCurves() const {
    dumpCommonCurves(fHead);
}

template<typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSpan<TCurve, OppCurve>::debugSpan(int id) const {
    return SkDEBUGRELEASE(fDebugSect->debugSpan(id), NULL);
}

template<typename TCurve, typename OppCurve>
const SkTSpan<TCurve, OppCurve>* SkTSpan<TCurve, OppCurve>::debugT(double t) const {
    return SkDEBUGRELEASE(fDebugSect->debugT(t), NULL);
}

template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dump() const {
>>>>>>> miniblink49
    dumpID();
    SkDebugf("=(%g,%g) [", fStartT, fEndT);
    const SkTSpanBounded<OppCurve, TCurve>* testBounded = fBounded;
    while (testBounded) {
        const SkTSpan<OppCurve, TCurve>* span = testBounded->fBounded;
        const SkTSpanBounded<OppCurve, TCurve>* next = testBounded->fNext;
        span->dumpID();
        if (next) {
            SkDebugf(",");
        }
        testBounded = next;
    }
    SkDebugf("]");
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpBounded(int id) const
{
    SkDEBUGCODE(fDebugSect->dumpBounded(id));
}

template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpBounds() const
{
    dumpID();
    SkDebugf(" bounds=(%1.9g,%1.9g, %1.9g,%1.9g) boundsMax=%1.9g%s\n",
        fBounds.fLeft, fBounds.fTop, fBounds.fRight, fBounds.fBottom, fBoundsMax,
        fCollapsed ? " collapsed" : "");
}

template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpCoin() const
{
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpBounded(int id) const {
    SkDEBUGCODE(fDebugSect->dumpBounded(id));
}

template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpBounds() const {
    dumpID();
    SkDebugf(" bounds=(%1.9g,%1.9g, %1.9g,%1.9g) boundsMax=%1.9g%s\n",
            fBounds.fLeft, fBounds.fTop, fBounds.fRight, fBounds.fBottom, fBoundsMax,
            fCollapsed ? " collapsed" : ""); 
}

template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpCoin() const {
>>>>>>> miniblink49
    dumpID();
    SkDebugf(" coinStart ");
    fCoinStart.dump();
    SkDebugf(" coinEnd ");
    fCoinEnd.dump();
}

<<<<<<< HEAD
template <typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpID() const
{
    char cS = fCoinStart.dumpIsCoincidentStr();
    if (cS) {
        SkDebugf("%c", cS);
    }
    SkDebugf("%d", debugID());
    char cE = fCoinEnd.dumpIsCoincidentStr();
    if (cE) {
        SkDebugf("%c", cE);
=======
template<typename TCurve, typename OppCurve>
void SkTSpan<TCurve, OppCurve>::dumpID() const {
    if (fCoinStart.isCoincident()) {
        SkDebugf("%c", '*');
    }
    SkDebugf("%d", debugID());
    if (fCoinEnd.isCoincident()) {
        SkDebugf("%c", '*');
>>>>>>> miniblink49
    }
}
