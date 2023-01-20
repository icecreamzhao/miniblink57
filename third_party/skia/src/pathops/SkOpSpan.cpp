/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkOpCoincidence.h"
#include "SkOpContour.h"
#include "SkOpSegment.h"
#include "SkPathWriter.h"

<<<<<<< HEAD
bool SkOpPtT::alias() const
{
    return this->span()->ptT() != this;
}

bool SkOpPtT::collapsed(const SkOpPtT* check) const
{
    if (fPt != check->fPt) {
        return false;
    }
    SkASSERT(this != check);
    const SkOpSegment* segment = this->segment();
    SkASSERT(segment == check->segment());
    return segment->collapsed();
}

bool SkOpPtT::contains(const SkOpPtT* check) const
{
=======
bool SkOpPtT::alias() const {
    return this->span()->ptT() != this;
}

bool SkOpPtT::contains(const SkOpPtT* check) const {
>>>>>>> miniblink49
    SkASSERT(this != check);
    const SkOpPtT* ptT = this;
    const SkOpPtT* stopPtT = ptT;
    while ((ptT = ptT->next()) != stopPtT) {
        if (ptT == check) {
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
SkOpPtT* SkOpPtT::contains(const SkOpSegment* check)
{
=======
SkOpPtT* SkOpPtT::contains(const SkOpSegment* check) {
>>>>>>> miniblink49
    SkASSERT(this->segment() != check);
    SkOpPtT* ptT = this;
    const SkOpPtT* stopPtT = ptT;
    while ((ptT = ptT->next()) != stopPtT) {
        if (ptT->segment() == check) {
            return ptT;
        }
    }
<<<<<<< HEAD
    return nullptr;
}

SkOpContour* SkOpPtT::contour() const
{
    return segment()->contour();
}

SkOpPtT* SkOpPtT::doppelganger()
{
=======
    return NULL;
}

SkOpContour* SkOpPtT::contour() const {
    return segment()->contour();
}

SkOpPtT* SkOpPtT::doppelganger() {
>>>>>>> miniblink49
    SkASSERT(fDeleted);
    SkOpPtT* ptT = fNext;
    while (ptT->fDeleted) {
        ptT = ptT->fNext;
    }
    const SkOpPtT* stopPtT = ptT;
    do {
        if (ptT->fSpan == fSpan) {
            return ptT;
        }
        ptT = ptT->fNext;
    } while (stopPtT != ptT);
    SkASSERT(0);
<<<<<<< HEAD
    return nullptr;
}

SkOpPtT* SkOpPtT::find(SkOpSegment* segment)
{
=======
    return NULL;
}

SkOpPtT* SkOpPtT::find(SkOpSegment* segment) {
>>>>>>> miniblink49
    SkOpPtT* ptT = this;
    const SkOpPtT* stopPtT = ptT;
    do {
        if (ptT->segment() == segment) {
            return ptT;
        }
        ptT = ptT->fNext;
    } while (stopPtT != ptT);
    SkASSERT(0);
<<<<<<< HEAD
    return nullptr;
}

SkOpGlobalState* SkOpPtT::globalState() const
{
    return contour()->globalState();
}

void SkOpPtT::init(SkOpSpanBase* span, double t, const SkPoint& pt, bool duplicate)
{
=======
    return NULL;
}

SkOpGlobalState* SkOpPtT::globalState() const {
    return contour()->globalState(); 
}

void SkOpPtT::init(SkOpSpanBase* span, double t, const SkPoint& pt, bool duplicate) {
>>>>>>> miniblink49
    fT = t;
    fPt = pt;
    fSpan = span;
    fNext = this;
    fDuplicatePt = duplicate;
    fDeleted = false;
    SkDEBUGCODE(fID = span->globalState()->nextPtTID());
}

<<<<<<< HEAD
bool SkOpPtT::onEnd() const
{
=======
bool SkOpPtT::onEnd() const {
>>>>>>> miniblink49
    const SkOpSpanBase* span = this->span();
    if (span->ptT() != this) {
        return false;
    }
    const SkOpSegment* segment = this->segment();
    return span == segment->head() || span == segment->tail();
}

<<<<<<< HEAD
SkOpPtT* SkOpPtT::prev()
{
=======
SkOpPtT* SkOpPtT::prev() {
>>>>>>> miniblink49
    SkOpPtT* result = this;
    SkOpPtT* next = this;
    while ((next = next->fNext) != this) {
        result = next;
    }
    SkASSERT(result->fNext == this);
    return result;
}

<<<<<<< HEAD
SkOpPtT* SkOpPtT::remove()
{
=======
SkOpPtT* SkOpPtT::remove() {
>>>>>>> miniblink49
    SkOpPtT* prev = this;
    do {
        SkOpPtT* next = prev->fNext;
        if (next == this) {
            prev->removeNext(this);
            SkASSERT(prev->fNext != prev);
            fDeleted = true;
            return prev;
        }
        prev = next;
    } while (prev != this);
    SkASSERT(0);
<<<<<<< HEAD
    return nullptr;
}

void SkOpPtT::removeNext(SkOpPtT* kept)
{
=======
    return NULL;
}

void SkOpPtT::removeNext(SkOpPtT* kept) {
>>>>>>> miniblink49
    SkASSERT(this->fNext);
    SkOpPtT* next = this->fNext;
    SkASSERT(this != next->fNext);
    this->fNext = next->fNext;
    SkOpSpanBase* span = next->span();
    next->setDeleted();
    if (span->ptT() == next) {
<<<<<<< HEAD
        span->upCast()->release(kept);
    }
}

const SkOpSegment* SkOpPtT::segment() const
{
    return span()->segment();
}

SkOpSegment* SkOpPtT::segment()
{
    return span()->segment();
}

void SkOpSpanBase::align()
{
=======
        span->upCast()->detach(kept);
    }
}

const SkOpSegment* SkOpPtT::segment() const {
    return span()->segment();
}

SkOpSegment* SkOpPtT::segment() {
    return span()->segment();
}

void SkOpSpanBase::align() {
>>>>>>> miniblink49
    if (this->fAligned) {
        return;
    }
    SkASSERT(!zero_or_one(this->fPtT.fT));
    SkASSERT(this->fPtT.next());
    // if a linked pt/t pair has a t of zero or one, use it as the base for alignment
<<<<<<< HEAD
    SkOpPtT *ptT = &this->fPtT, *stopPtT = ptT;
=======
    SkOpPtT* ptT = &this->fPtT, * stopPtT = ptT;
>>>>>>> miniblink49
    while ((ptT = ptT->next()) != stopPtT) {
        if (zero_or_one(ptT->fT)) {
            SkOpSegment* segment = ptT->segment();
            SkASSERT(this->segment() != segment);
            SkASSERT(segment->head()->ptT() == ptT || segment->tail()->ptT() == ptT);
            if (ptT->fT) {
                segment->tail()->alignEnd(1, segment->lastPt());
            } else {
                segment->head()->alignEnd(0, segment->pts()[0]);
            }
            return;
        }
    }
    alignInner();
    this->fAligned = true;
}

<<<<<<< HEAD
// FIXME: delete spans that collapse
// delete segments that collapse
// delete contours that collapse
void SkOpSpanBase::alignEnd(double t, const SkPoint& pt)
{
=======

// FIXME: delete spans that collapse
// delete segments that collapse
// delete contours that collapse
void SkOpSpanBase::alignEnd(double t, const SkPoint& pt) {
>>>>>>> miniblink49
    SkASSERT(zero_or_one(t));
    SkOpSegment* segment = this->segment();
    SkASSERT(t ? segment->lastPt() == pt : segment->pts()[0] == pt);
    alignInner();
    *segment->writablePt(!!t) = pt;
    SkOpPtT* ptT = &this->fPtT;
    SkASSERT(t == ptT->fT);
    SkASSERT(pt == ptT->fPt);
<<<<<<< HEAD
    SkOpPtT *test = ptT, *stopPtT = ptT;
=======
    SkOpPtT* test = ptT, * stopPtT = ptT;
>>>>>>> miniblink49
    while ((test = test->next()) != stopPtT) {
        SkOpSegment* other = test->segment();
        if (other == this->segment()) {
            continue;
        }
        if (!zero_or_one(test->fT)) {
            continue;
        }
        *other->writablePt(!!test->fT) = pt;
    }
    this->fAligned = true;
}

<<<<<<< HEAD
void SkOpSpanBase::alignInner()
{
    // force the spans to share points and t values
    SkOpPtT *ptT = &this->fPtT, *stopPtT = ptT;
=======
void SkOpSpanBase::alignInner() {
    // force the spans to share points and t values
    SkOpPtT* ptT = &this->fPtT, * stopPtT = ptT;
>>>>>>> miniblink49
    const SkPoint& pt = ptT->fPt;
    do {
        ptT->fPt = pt;
        const SkOpSpanBase* span = ptT->span();
        SkOpPtT* test = ptT;
        do {
            SkOpPtT* prev = test;
            if ((test = test->next()) == stopPtT) {
                break;
            }
            if (span == test->span() && !span->segment()->ptsDisjoint(*ptT, *test)) {
                // omit aliases that alignment makes redundant
                if ((!ptT->alias() || test->alias()) && (ptT->onEnd() || !test->onEnd())) {
                    SkASSERT(test->alias());
                    prev->removeNext(ptT);
                    test = prev;
                } else {
                    SkASSERT(ptT->alias());
                    stopPtT = ptT = ptT->remove();
                    break;
                }
            }
        } while (true);
    } while ((ptT = ptT->next()) != stopPtT);
}

<<<<<<< HEAD
bool SkOpSpanBase::contains(const SkOpSpanBase* span) const
{
=======
bool SkOpSpanBase::contains(const SkOpSpanBase* span) const {
>>>>>>> miniblink49
    const SkOpPtT* start = &fPtT;
    const SkOpPtT* check = &span->fPtT;
    SkASSERT(start != check);
    const SkOpPtT* walk = start;
    while ((walk = walk->next()) != start) {
        if (walk == check) {
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
SkOpPtT* SkOpSpanBase::contains(const SkOpSegment* segment)
{
=======
SkOpPtT* SkOpSpanBase::contains(const SkOpSegment* segment) {
>>>>>>> miniblink49
    SkOpPtT* start = &fPtT;
    SkOpPtT* walk = start;
    while ((walk = walk->next()) != start) {
        if (walk->segment() == segment) {
            return walk;
        }
    }
<<<<<<< HEAD
    return nullptr;
}

bool SkOpSpanBase::containsCoinEnd(const SkOpSegment* segment) const
{
=======
    return NULL;
}

bool SkOpSpanBase::containsCoinEnd(const SkOpSegment* segment) const {
>>>>>>> miniblink49
    SkASSERT(this->segment() != segment);
    const SkOpSpanBase* next = this;
    while ((next = next->fCoinEnd) != this) {
        if (next->segment() == segment) {
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
SkOpContour* SkOpSpanBase::contour() const
{
    return segment()->contour();
}

SkOpGlobalState* SkOpSpanBase::globalState() const
{
    return contour()->globalState();
}

void SkOpSpanBase::initBase(SkOpSegment* segment, SkOpSpan* prev, double t, const SkPoint& pt)
{
    fSegment = segment;
    fPtT.init(this, t, pt, false);
    fCoinEnd = this;
    fFromAngle = nullptr;
=======
SkOpContour* SkOpSpanBase::contour() const {
    return segment()->contour();
}

SkOpGlobalState* SkOpSpanBase::globalState() const {
    return contour()->globalState(); 
}

void SkOpSpanBase::initBase(SkOpSegment* segment, SkOpSpan* prev, double t, const SkPoint& pt) {
    fSegment = segment;
    fPtT.init(this, t, pt, false);
    fCoinEnd = this;
    fFromAngle = NULL;
>>>>>>> miniblink49
    fPrev = prev;
    fSpanAdds = 0;
    fAligned = true;
    fChased = false;
    SkDEBUGCODE(fCount = 1);
    SkDEBUGCODE(fID = globalState()->nextSpanID());
}

// this pair of spans share a common t value or point; merge them and eliminate duplicates
// this does not compute the best t or pt value; this merely moves all data into a single list
<<<<<<< HEAD
void SkOpSpanBase::merge(SkOpSpan* span)
{
    SkOpPtT* spanPtT = span->ptT();
    SkASSERT(this->t() != spanPtT->fT);
    SkASSERT(!zero_or_one(spanPtT->fT));
    span->release(this->ptT());
=======
void SkOpSpanBase::merge(SkOpSpan* span) {
    SkOpPtT* spanPtT = span->ptT();
    SkASSERT(this->t() != spanPtT->fT);
    SkASSERT(!zero_or_one(spanPtT->fT));
    span->detach(this->ptT());
>>>>>>> miniblink49
    SkOpPtT* remainder = spanPtT->next();
    ptT()->insert(spanPtT);
    while (remainder != spanPtT) {
        SkOpPtT* next = remainder->next();
        SkOpPtT* compare = spanPtT->next();
        while (compare != spanPtT) {
            SkOpPtT* nextC = compare->next();
            if (nextC->span() == remainder->span() && nextC->fT == remainder->fT) {
                goto tryNextRemainder;
            }
            compare = nextC;
        }
        spanPtT->insert(remainder);
<<<<<<< HEAD
    tryNextRemainder:
=======
tryNextRemainder:
>>>>>>> miniblink49
        remainder = next;
    }
    fSpanAdds += span->fSpanAdds;
}

<<<<<<< HEAD
int SkOpSpan::computeWindSum()
{
=======
int SkOpSpan::computeWindSum() {
>>>>>>> miniblink49
    SkOpGlobalState* globals = this->globalState();
    SkOpContour* contourHead = globals->contourHead();
    int windTry = 0;
    while (!this->sortableTop(contourHead) && ++windTry < SkOpGlobalState::kMaxWindingTries) {
        ;
    }
    return this->windSum();
}

<<<<<<< HEAD
bool SkOpSpan::containsCoincidence(const SkOpSegment* segment) const
{
=======
bool SkOpSpan::containsCoincidence(const SkOpSegment* segment) const {
>>>>>>> miniblink49
    SkASSERT(this->segment() != segment);
    const SkOpSpan* next = fCoincident;
    do {
        if (next->segment() == segment) {
            return true;
        }
    } while ((next = next->fCoincident) != this);
    return false;
}

<<<<<<< HEAD
void SkOpSpan::release(SkOpPtT* kept)
{
=======
void SkOpSpan::detach(SkOpPtT* kept) {
>>>>>>> miniblink49
    SkASSERT(!final());
    SkOpSpan* prev = this->prev();
    SkASSERT(prev);
    SkOpSpanBase* next = this->next();
    SkASSERT(next);
    prev->setNext(next);
    next->setPrev(prev);
<<<<<<< HEAD
    this->segment()->release(this);
=======
    this->segment()->detach(this);
>>>>>>> miniblink49
    SkOpCoincidence* coincidence = this->globalState()->coincidence();
    if (coincidence) {
        coincidence->fixUp(this->ptT(), kept);
    }
    this->ptT()->setDeleted();
}

<<<<<<< HEAD
void SkOpSpan::init(SkOpSegment* segment, SkOpSpan* prev, double t, const SkPoint& pt)
{
    SkASSERT(t != 1);
    initBase(segment, prev, t, pt);
    fCoincident = this;
    fToAngle = nullptr;
=======
void SkOpSpan::init(SkOpSegment* segment, SkOpSpan* prev, double t, const SkPoint& pt) {
    SkASSERT(t != 1);
    initBase(segment, prev, t, pt);
    fCoincident = this;
    fToAngle = NULL;
>>>>>>> miniblink49
    fWindSum = fOppSum = SK_MinS32;
    fWindValue = 1;
    fOppValue = 0;
    fTopTTry = 0;
    fChased = fDone = false;
    segment->bumpCount();
<<<<<<< HEAD
    fAlreadyAdded = false;
}

void SkOpSpan::setOppSum(int oppSum)
{
=======
}

void SkOpSpan::setOppSum(int oppSum) {
>>>>>>> miniblink49
    SkASSERT(!final());
    if (fOppSum != SK_MinS32 && fOppSum != oppSum) {
        this->globalState()->setWindingFailed();
        return;
    }
<<<<<<< HEAD
    SkASSERT(!DEBUG_LIMIT_WIND_SUM || SkTAbs(oppSum) <= DEBUG_LIMIT_WIND_SUM);
    fOppSum = oppSum;
}

void SkOpSpan::setWindSum(int windSum)
{
=======
    SkASSERT(!DEBUG_LIMIT_WIND_SUM || abs(oppSum) <= DEBUG_LIMIT_WIND_SUM);
    fOppSum = oppSum;
}

void SkOpSpan::setWindSum(int windSum) {
>>>>>>> miniblink49
    SkASSERT(!final());
    if (fWindSum != SK_MinS32 && fWindSum != windSum) {
        this->globalState()->setWindingFailed();
        return;
    }
<<<<<<< HEAD
    SkASSERT(!DEBUG_LIMIT_WIND_SUM || SkTAbs(windSum) <= DEBUG_LIMIT_WIND_SUM);
=======
    SkASSERT(!DEBUG_LIMIT_WIND_SUM || abs(windSum) <= DEBUG_LIMIT_WIND_SUM);
>>>>>>> miniblink49
    fWindSum = windSum;
}
