
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPathParts.h"
#include "SkAnimateMaker.h"
#include "SkDrawMatrix.h"
#include "SkDrawPath.h"
#include "SkDrawRectangle.h"

SkPathPart::SkPathPart()
    : fPath(nullptr)
{
}

void SkPathPart::dirty()
{
    fPath->dirty();
}

SkDisplayable* SkPathPart::getParent() const
{
    return fPath;
}

bool SkPathPart::setParent(SkDisplayable* parent)
{
    SkASSERT(parent != nullptr);
    if (parent->isPath() == false)
        return true;
    fPath = (SkDrawPath*)parent;
=======

#include "SkPathParts.h"
#include "SkAnimateMaker.h"
#include "SkDrawMatrix.h"
#include "SkDrawRectangle.h"
#include "SkDrawPath.h"

SkPathPart::SkPathPart() : fPath(NULL) {
}

void SkPathPart::dirty() {
    fPath->dirty();
}

SkDisplayable* SkPathPart::getParent() const {
    return fPath;
}

bool SkPathPart::setParent(SkDisplayable* parent) {
    SkASSERT(parent != NULL);
    if (parent->isPath() == false)
        return true;
    fPath = (SkDrawPath*) parent;
>>>>>>> miniblink49
    return false;
}

// MoveTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkMoveTo::fInfo[] = {
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkMoveTo);

<<<<<<< HEAD
SkMoveTo::SkMoveTo()
    : x(0)
    , y(0)
{
}

bool SkMoveTo::add()
{
=======
SkMoveTo::SkMoveTo() : x(0), y(0) {
}

bool SkMoveTo::add() {
>>>>>>> miniblink49
    fPath->fPath.moveTo(x, y);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// RMoveTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRMoveTo::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkRMoveTo);

<<<<<<< HEAD
bool SkRMoveTo::add()
{
=======
bool SkRMoveTo::add() {
>>>>>>> miniblink49
    fPath->fPath.rMoveTo(x, y);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// LineTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkLineTo::fInfo[] = {
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkLineTo);

<<<<<<< HEAD
SkLineTo::SkLineTo()
    : x(0)
    , y(0)
{
}

bool SkLineTo::add()
{
=======
SkLineTo::SkLineTo() : x(0), y(0) {
}

bool SkLineTo::add() {
>>>>>>> miniblink49
    fPath->fPath.lineTo(x, y);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// RLineTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRLineTo::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkRLineTo);

<<<<<<< HEAD
bool SkRLineTo::add()
{
=======
bool SkRLineTo::add() {
>>>>>>> miniblink49
    fPath->fPath.rLineTo(x, y);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// QuadTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkQuadTo::fInfo[] = {
    SK_MEMBER(x1, Float),
    SK_MEMBER(x2, Float),
    SK_MEMBER(y1, Float),
    SK_MEMBER(y2, Float)
};

#endif

DEFINE_GET_MEMBER(SkQuadTo);

<<<<<<< HEAD
SkQuadTo::SkQuadTo()
    : x1(0)
    , y1(0)
    , x2(0)
    , y2(0)
{
}

bool SkQuadTo::add()
{
=======
SkQuadTo::SkQuadTo() : x1(0), y1(0), x2(0), y2(0) {
}

bool SkQuadTo::add() {
>>>>>>> miniblink49
    fPath->fPath.quadTo(x1, y1, x2, y2);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// RQuadTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRQuadTo::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkRQuadTo);

<<<<<<< HEAD
bool SkRQuadTo::add()
{
=======
bool SkRQuadTo::add() {
>>>>>>> miniblink49
    fPath->fPath.rQuadTo(x1, y1, x2, y2);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// CubicTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkCubicTo::fInfo[] = {
    SK_MEMBER(x1, Float),
    SK_MEMBER(x2, Float),
    SK_MEMBER(x3, Float),
    SK_MEMBER(y1, Float),
    SK_MEMBER(y2, Float),
    SK_MEMBER(y3, Float)
};

#endif

DEFINE_GET_MEMBER(SkCubicTo);

<<<<<<< HEAD
SkCubicTo::SkCubicTo()
    : x1(0)
    , y1(0)
    , x2(0)
    , y2(0)
    , x3(0)
    , y3(0)
{
}

bool SkCubicTo::add()
{
=======
SkCubicTo::SkCubicTo() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {
}

bool SkCubicTo::add() {
>>>>>>> miniblink49
    fPath->fPath.cubicTo(x1, y1, x2, y2, x3, y3);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// RCubicTo
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRCubicTo::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkRCubicTo);

<<<<<<< HEAD
bool SkRCubicTo::add()
{
=======
bool SkRCubicTo::add() {
>>>>>>> miniblink49
    fPath->fPath.rCubicTo(x1, y1, x2, y2, x3, y3);
    return false;
}

<<<<<<< HEAD
// SkClose
bool SkClose::add()
{
=======

// SkClose
bool SkClose::add() {
>>>>>>> miniblink49
    fPath->fPath.close();
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// SkAddGeom
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkAddGeom::fInfo[] = {
    SK_MEMBER(direction, PathDirection)
};

#endif

DEFINE_GET_MEMBER(SkAddGeom);

<<<<<<< HEAD
SkAddGeom::SkAddGeom()
    : direction(SkPath::kCCW_Direction)
{
=======
SkAddGeom::SkAddGeom() : direction(SkPath::kCCW_Direction) {
>>>>>>> miniblink49
}

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkAddRect::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER_ALIAS(bottom, fRect.fBottom, Float),
    SK_MEMBER_ALIAS(left, fRect.fLeft, Float),
    SK_MEMBER_ALIAS(right, fRect.fRight, Float),
    SK_MEMBER_ALIAS(top, fRect.fTop, Float)
};

#endif

DEFINE_GET_MEMBER(SkAddRect);

<<<<<<< HEAD
SkAddRect::SkAddRect()
{
    fRect.setEmpty();
}

bool SkAddRect::add()
{
    fPath->fPath.addRect(fRect, (SkPath::Direction)direction);
    return false;
}

=======
SkAddRect::SkAddRect() {
    fRect.setEmpty();
}

bool SkAddRect::add() {
    fPath->fPath.addRect(fRect, (SkPath::Direction) direction);
    return false;
}


>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkAddOval::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkAddOval);

<<<<<<< HEAD
bool SkAddOval::add()
{
    fPath->fPath.addOval(fRect, (SkPath::Direction)direction);
    return false;
}

=======
bool SkAddOval::add() {
    fPath->fPath.addOval(fRect,  (SkPath::Direction) direction);
    return false;
}


>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkAddCircle::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER(radius, Float),
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkAddCircle);

<<<<<<< HEAD
SkAddCircle::SkAddCircle()
    : radius(0)
    , x(0)
    , y(0)
{
}

bool SkAddCircle::add()
{
    fPath->fPath.addCircle(x, y, radius, (SkPath::Direction)direction);
    return false;
}

=======
SkAddCircle::SkAddCircle() : radius(0), x(0), y(0) {
}

bool SkAddCircle::add() {
    fPath->fPath.addCircle(x, y, radius,  (SkPath::Direction) direction);
    return false;
}


>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkAddRoundRect::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER(rx, Float),
    SK_MEMBER(ry, Float)
};

#endif

DEFINE_GET_MEMBER(SkAddRoundRect);

<<<<<<< HEAD
SkAddRoundRect::SkAddRoundRect()
    : rx(0)
    , ry(0)
{
}

bool SkAddRoundRect::add()
{
    fPath->fPath.addRoundRect(fRect, rx, ry, (SkPath::Direction)direction);
    return false;
}

=======
SkAddRoundRect::SkAddRoundRect() : rx(0), ry(0) {
}

bool SkAddRoundRect::add() {
    fPath->fPath.addRoundRect(fRect, rx, ry,  (SkPath::Direction) direction);
    return false;
}


>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkAddPath::fInfo[] = {
    SK_MEMBER(matrix, Matrix),
    SK_MEMBER(path, Path)
};

#endif

DEFINE_GET_MEMBER(SkAddPath);

<<<<<<< HEAD
SkAddPath::SkAddPath()
    : matrix(nullptr)
    , path(nullptr)
{
}

bool SkAddPath::add()
{
    SkASSERT(path != nullptr);
=======
SkAddPath::SkAddPath() : matrix(NULL), path(NULL) {
}

bool SkAddPath::add() {
    SkASSERT (path != NULL);
>>>>>>> miniblink49
    if (matrix)
        fPath->fPath.addPath(path->fPath, matrix->getMatrix());
    else
        fPath->fPath.addPath(path->fPath);
    return false;
}
