/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkPathWriter.h"
#include "SkPathOpsPoint.h"
=======
#include "SkPathOpsPoint.h"
#include "SkPathWriter.h"
>>>>>>> miniblink49

// wrap path to keep track of whether the contour is initialized and non-empty
SkPathWriter::SkPathWriter(SkPath& path)
    : fPathPtr(&path)
    , fCloses(0)
    , fMoves(0)
{
    init();
}

<<<<<<< HEAD
void SkPathWriter::close()
{
=======
void SkPathWriter::close() {
>>>>>>> miniblink49
    if (!fHasMove) {
        return;
    }
    bool callClose = isClosed();
    lineTo();
    if (fEmpty) {
        return;
    }
    if (callClose) {
#if DEBUG_PATH_CONSTRUCTION
        SkDebugf("path.close();\n");
#endif
        fPathPtr->close();
        fCloses++;
    }
    init();
}

<<<<<<< HEAD
void SkPathWriter::conicTo(const SkPoint& pt1, const SkPoint& pt2, SkScalar weight)
{
=======
void SkPathWriter::conicTo(const SkPoint& pt1, const SkPoint& pt2, SkScalar weight) {
>>>>>>> miniblink49
    lineTo();
    if (fEmpty && AlmostEqualUlps(fDefer[0], pt1) && AlmostEqualUlps(pt1, pt2)) {
        deferredLine(pt2);
        return;
    }
    moveTo();
    fDefer[1] = pt2;
    nudge();
    fDefer[0] = fDefer[1];
#if DEBUG_PATH_CONSTRUCTION
    SkDebugf("path.conicTo(%1.9g,%1.9g, %1.9g,%1.9g, %1.9g);\n",
<<<<<<< HEAD
        pt1.fX, pt1.fY, fDefer[1].fX, fDefer[1].fY, weight);
=======
            pt1.fX, pt1.fY, fDefer[1].fX, fDefer[1].fY, weight);
>>>>>>> miniblink49
#endif
    fPathPtr->conicTo(pt1.fX, pt1.fY, fDefer[1].fX, fDefer[1].fY, weight);
    fEmpty = false;
}

<<<<<<< HEAD
void SkPathWriter::cubicTo(const SkPoint& pt1, const SkPoint& pt2, const SkPoint& pt3)
{
    lineTo();
    if (fEmpty && AlmostEqualUlps(fDefer[0], pt1) && AlmostEqualUlps(pt1, pt2)
        && AlmostEqualUlps(pt2, pt3)) {
=======
void SkPathWriter::cubicTo(const SkPoint& pt1, const SkPoint& pt2, const SkPoint& pt3) {
    lineTo();
    if (fEmpty && AlmostEqualUlps(fDefer[0], pt1) && AlmostEqualUlps(pt1, pt2)
            && AlmostEqualUlps(pt2, pt3)) {
>>>>>>> miniblink49
        deferredLine(pt3);
        return;
    }
    moveTo();
    fDefer[1] = pt3;
    nudge();
    fDefer[0] = fDefer[1];
#if DEBUG_PATH_CONSTRUCTION
    SkDebugf("path.cubicTo(%1.9g,%1.9g, %1.9g,%1.9g, %1.9g,%1.9g);\n",
<<<<<<< HEAD
        pt1.fX, pt1.fY, pt2.fX, pt2.fY, fDefer[1].fX, fDefer[1].fY);
=======
            pt1.fX, pt1.fY, pt2.fX, pt2.fY, fDefer[1].fX, fDefer[1].fY);
>>>>>>> miniblink49
#endif
    fPathPtr->cubicTo(pt1.fX, pt1.fY, pt2.fX, pt2.fY, fDefer[1].fX, fDefer[1].fY);
    fEmpty = false;
}

<<<<<<< HEAD
void SkPathWriter::deferredLine(const SkPoint& pt)
{
=======
void SkPathWriter::deferredLine(const SkPoint& pt) {
>>>>>>> miniblink49
    if (pt == fDefer[1]) {
        return;
    }
    if (changedSlopes(pt)) {
        lineTo();
        fDefer[0] = fDefer[1];
    }
    fDefer[1] = pt;
}

<<<<<<< HEAD
void SkPathWriter::deferredMove(const SkPoint& pt)
{
=======
void SkPathWriter::deferredMove(const SkPoint& pt) {
>>>>>>> miniblink49
    fMoved = true;
    fHasMove = true;
    fEmpty = true;
    fDefer[0] = fDefer[1] = pt;
}

<<<<<<< HEAD
void SkPathWriter::deferredMoveLine(const SkPoint& pt)
{
=======
void SkPathWriter::deferredMoveLine(const SkPoint& pt) {
>>>>>>> miniblink49
    if (!fHasMove) {
        deferredMove(pt);
    }
    deferredLine(pt);
}

<<<<<<< HEAD
bool SkPathWriter::hasMove() const
{
    return fHasMove;
}

void SkPathWriter::init()
{
=======
bool SkPathWriter::hasMove() const {
    return fHasMove;
}

void SkPathWriter::init() {
>>>>>>> miniblink49
    fEmpty = true;
    fHasMove = false;
    fMoved = false;
}

<<<<<<< HEAD
bool SkPathWriter::isClosed() const
{
    return !fEmpty && SkDPoint::ApproximatelyEqual(fFirstPt, fDefer[1]);
}

void SkPathWriter::lineTo()
{
=======
bool SkPathWriter::isClosed() const {
    return !fEmpty && SkDPoint::ApproximatelyEqual(fFirstPt, fDefer[1]);
}

void SkPathWriter::lineTo() {
>>>>>>> miniblink49
    if (fDefer[0] == fDefer[1]) {
        return;
    }
    moveTo();
    nudge();
    fEmpty = false;
#if DEBUG_PATH_CONSTRUCTION
    SkDebugf("path.lineTo(%1.9g,%1.9g);\n", fDefer[1].fX, fDefer[1].fY);
#endif
    fPathPtr->lineTo(fDefer[1].fX, fDefer[1].fY);
    fDefer[0] = fDefer[1];
}

<<<<<<< HEAD
const SkPath* SkPathWriter::nativePath() const
{
    return fPathPtr;
}

void SkPathWriter::nudge()
{
    if (fEmpty || !AlmostEqualUlps(fDefer[1].fX, fFirstPt.fX)
        || !AlmostEqualUlps(fDefer[1].fY, fFirstPt.fY)) {
=======
const SkPath* SkPathWriter::nativePath() const {
    return fPathPtr;
}

void SkPathWriter::nudge() {
    if (fEmpty || !AlmostEqualUlps(fDefer[1].fX, fFirstPt.fX)
            || !AlmostEqualUlps(fDefer[1].fY, fFirstPt.fY)) {
>>>>>>> miniblink49
        return;
    }
    fDefer[1] = fFirstPt;
}

<<<<<<< HEAD
void SkPathWriter::quadTo(const SkPoint& pt1, const SkPoint& pt2)
{
=======
void SkPathWriter::quadTo(const SkPoint& pt1, const SkPoint& pt2) {
>>>>>>> miniblink49
    lineTo();
    if (fEmpty && AlmostEqualUlps(fDefer[0], pt1) && AlmostEqualUlps(pt1, pt2)) {
        deferredLine(pt2);
        return;
    }
    moveTo();
    fDefer[1] = pt2;
    nudge();
    fDefer[0] = fDefer[1];
#if DEBUG_PATH_CONSTRUCTION
    SkDebugf("path.quadTo(%1.9g,%1.9g, %1.9g,%1.9g);\n",
<<<<<<< HEAD
        pt1.fX, pt1.fY, fDefer[1].fX, fDefer[1].fY);
=======
            pt1.fX, pt1.fY, fDefer[1].fX, fDefer[1].fY);
>>>>>>> miniblink49
#endif
    fPathPtr->quadTo(pt1.fX, pt1.fY, fDefer[1].fX, fDefer[1].fY);
    fEmpty = false;
}

<<<<<<< HEAD
bool SkPathWriter::someAssemblyRequired() const
{
    return fCloses < fMoves;
}

bool SkPathWriter::changedSlopes(const SkPoint& pt) const
{
=======
bool SkPathWriter::someAssemblyRequired() const {
    return fCloses < fMoves;
}

bool SkPathWriter::changedSlopes(const SkPoint& pt) const {
>>>>>>> miniblink49
    if (fDefer[0] == fDefer[1]) {
        return false;
    }
    SkScalar deferDx = fDefer[1].fX - fDefer[0].fX;
    SkScalar deferDy = fDefer[1].fY - fDefer[0].fY;
    SkScalar lineDx = pt.fX - fDefer[1].fX;
    SkScalar lineDy = pt.fY - fDefer[1].fY;
    return deferDx * lineDy != deferDy * lineDx;
}

<<<<<<< HEAD
void SkPathWriter::moveTo()
{
=======
void SkPathWriter::moveTo() {
>>>>>>> miniblink49
    if (!fMoved) {
        return;
    }
    fFirstPt = fDefer[0];
#if DEBUG_PATH_CONSTRUCTION
    SkDebugf("path.moveTo(%1.9g,%1.9g);\n", fDefer[0].fX, fDefer[0].fY);
#endif
    fPathPtr->moveTo(fDefer[0].fX, fDefer[0].fY);
    fMoved = false;
    fMoves++;
}
