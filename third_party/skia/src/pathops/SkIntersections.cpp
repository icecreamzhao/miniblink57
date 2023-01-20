/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkIntersections.h"

int SkIntersections::closestTo(double rangeStart, double rangeEnd, const SkDPoint& testPt,
<<<<<<< HEAD
    double* closestDist) const
{
=======
        double* closestDist) const {
>>>>>>> miniblink49
    int closest = -1;
    *closestDist = SK_ScalarMax;
    for (int index = 0; index < fUsed; ++index) {
        if (!between(rangeStart, fT[0][index], rangeEnd)) {
            continue;
        }
        const SkDPoint& iPt = fPt[index];
        double dist = testPt.distanceSquared(iPt);
        if (*closestDist > dist) {
            *closestDist = dist;
            closest = index;
        }
    }
    return closest;
}

<<<<<<< HEAD
void SkIntersections::flip()
{
=======
void SkIntersections::flip() {
>>>>>>> miniblink49
    for (int index = 0; index < fUsed; ++index) {
        fT[1][index] = 1 - fT[1][index];
    }
}

<<<<<<< HEAD
int SkIntersections::insert(double one, double two, const SkDPoint& pt)
{
=======
int SkIntersections::insert(double one, double two, const SkDPoint& pt) {
>>>>>>> miniblink49
    if (fIsCoincident[0] == 3 && between(fT[0][0], one, fT[0][1])) {
        // For now, don't allow a mix of coincident and non-coincident intersections
        return -1;
    }
    SkASSERT(fUsed <= 1 || fT[0][0] <= fT[0][1]);
    int index;
    for (index = 0; index < fUsed; ++index) {
        double oldOne = fT[0][index];
        double oldTwo = fT[1][index];
        if (one == oldOne && two == oldTwo) {
            return -1;
        }
        if (more_roughly_equal(oldOne, one) && more_roughly_equal(oldTwo, two)) {
            if ((precisely_zero(one) && !precisely_zero(oldOne))
<<<<<<< HEAD
                || (precisely_equal(one, 1) && !precisely_equal(oldOne, 1))
                || (precisely_zero(two) && !precisely_zero(oldTwo))
                || (precisely_equal(two, 1) && !precisely_equal(oldTwo, 1))) {
=======
                    || (precisely_equal(one, 1) && !precisely_equal(oldOne, 1))
                    || (precisely_zero(two) && !precisely_zero(oldTwo))
                    || (precisely_equal(two, 1) && !precisely_equal(oldTwo, 1))) {
>>>>>>> miniblink49
                SkASSERT(one >= 0 && one <= 1);
                SkASSERT(two >= 0 && two <= 1);
                fT[0][index] = one;
                fT[1][index] = two;
                fPt[index] = pt;
            }
            return -1;
        }
<<<<<<< HEAD
#if ONE_OFF_DEBUG
        if (pt.roughlyEqual(fPt[index])) {
            SkDebugf("%s t=%1.9g pts roughly equal\n", __FUNCTION__, one);
        }
#endif
=======
    #if ONE_OFF_DEBUG
        if (pt.roughlyEqual(fPt[index])) {
            SkDebugf("%s t=%1.9g pts roughly equal\n", __FUNCTION__, one);
        }
    #endif
>>>>>>> miniblink49
        if (fT[0][index] > one) {
            break;
        }
    }
    if (fUsed >= fMax) {
<<<<<<< HEAD
        SkASSERT(0); // FIXME : this error, if it is to be handled at runtime in release, must
            // be propagated all the way back down to the caller, and return failure.
=======
        SkASSERT(0);  // FIXME : this error, if it is to be handled at runtime in release, must
                      // be propagated all the way back down to the caller, and return failure.
>>>>>>> miniblink49
        fUsed = 0;
        return 0;
    }
    int remaining = fUsed - index;
    if (remaining > 0) {
        memmove(&fPt[index + 1], &fPt[index], sizeof(fPt[0]) * remaining);
        memmove(&fT[0][index + 1], &fT[0][index], sizeof(fT[0][0]) * remaining);
        memmove(&fT[1][index + 1], &fT[1][index], sizeof(fT[1][0]) * remaining);
        int clearMask = ~((1 << index) - 1);
        fIsCoincident[0] += fIsCoincident[0] & clearMask;
        fIsCoincident[1] += fIsCoincident[1] & clearMask;
    }
    fPt[index] = pt;
    SkASSERT(one >= 0 && one <= 1);
    SkASSERT(two >= 0 && two <= 1);
    fT[0][index] = one;
    fT[1][index] = two;
    ++fUsed;
<<<<<<< HEAD
    SkASSERT(fUsed <= SK_ARRAY_COUNT(fPt));
    return index;
}

void SkIntersections::insertNear(double one, double two, const SkDPoint& pt1, const SkDPoint& pt2)
{
=======
    return index;
}

void SkIntersections::insertNear(double one, double two, const SkDPoint& pt1, const SkDPoint& pt2) {
>>>>>>> miniblink49
    SkASSERT(one == 0 || one == 1);
    SkASSERT(two == 0 || two == 1);
    SkASSERT(pt1 != pt2);
    fNearlySame[one ? 1 : 0] = true;
<<<<<<< HEAD
    (void)insert(one, two, pt1);
    fPt2[one ? 1 : 0] = pt2;
}

int SkIntersections::insertCoincident(double one, double two, const SkDPoint& pt)
{
=======
    (void) insert(one, two, pt1);
    fPt2[one ? 1 : 0] = pt2;
}

int SkIntersections::insertCoincident(double one, double two, const SkDPoint& pt) {
>>>>>>> miniblink49
    int index = insertSwap(one, two, pt);
    if (index >= 0) {
        setCoincident(index);
    }
    return index;
}

<<<<<<< HEAD
void SkIntersections::setCoincident(int index)
{
=======
void SkIntersections::setCoincident(int index) {
>>>>>>> miniblink49
    SkASSERT(index >= 0);
    int bit = 1 << index;
    fIsCoincident[0] |= bit;
    fIsCoincident[1] |= bit;
}

void SkIntersections::merge(const SkIntersections& a, int aIndex, const SkIntersections& b,
<<<<<<< HEAD
    int bIndex)
{
=======
        int bIndex) {
>>>>>>> miniblink49
    this->reset();
    fT[0][0] = a.fT[0][aIndex];
    fT[1][0] = b.fT[0][bIndex];
    fPt[0] = a.fPt[aIndex];
    fPt2[0] = b.fPt[bIndex];
    fUsed = 1;
}

<<<<<<< HEAD
int SkIntersections::mostOutside(double rangeStart, double rangeEnd, const SkDPoint& origin) const
{
=======
int SkIntersections::mostOutside(double rangeStart, double rangeEnd, const SkDPoint& origin) const {
>>>>>>> miniblink49
    int result = -1;
    for (int index = 0; index < fUsed; ++index) {
        if (!between(rangeStart, fT[0][index], rangeEnd)) {
            continue;
        }
        if (result < 0) {
            result = index;
            continue;
        }
        SkDVector best = fPt[result] - origin;
        SkDVector test = fPt[index] - origin;
        if (test.crossCheck(best) < 0) {
            result = index;
        }
    }
    return result;
}

<<<<<<< HEAD
void SkIntersections::removeOne(int index)
{
=======
void SkIntersections::removeOne(int index) {
>>>>>>> miniblink49
    int remaining = --fUsed - index;
    if (remaining <= 0) {
        return;
    }
    memmove(&fPt[index], &fPt[index + 1], sizeof(fPt[0]) * remaining);
    memmove(&fT[0][index], &fT[0][index + 1], sizeof(fT[0][0]) * remaining);
    memmove(&fT[1][index], &fT[1][index + 1], sizeof(fT[1][0]) * remaining);
<<<<<<< HEAD
    //    SkASSERT(fIsCoincident[0] == 0);
=======
//    SkASSERT(fIsCoincident[0] == 0);
>>>>>>> miniblink49
    int coBit = fIsCoincident[0] & (1 << index);
    fIsCoincident[0] -= ((fIsCoincident[0] >> 1) & ~((1 << index) - 1)) + coBit;
    SkASSERT(!(coBit ^ (fIsCoincident[1] & (1 << index))));
    fIsCoincident[1] -= ((fIsCoincident[1] >> 1) & ~((1 << index) - 1)) + coBit;
}
