
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDrawRectangle.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkMatrixParts.h"
#include "SkPaint.h"
#include "SkScript.h"

enum SkRectangle_Properties {
    SK_PROPERTY(height),
    SK_PROPERTY(needsRedraw),
    SK_PROPERTY(width)
};

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDrawRect::fInfo[] = {
    SK_MEMBER_ALIAS(bottom, fRect.fBottom, Float),
    SK_MEMBER_PROPERTY(height, Float),
    SK_MEMBER_ALIAS(left, fRect.fLeft, Float),
    SK_MEMBER_PROPERTY(needsRedraw, Boolean),
    SK_MEMBER_ALIAS(right, fRect.fRight, Float),
    SK_MEMBER_ALIAS(top, fRect.fTop, Float),
    SK_MEMBER_PROPERTY(width, Float)
};

#endif

DEFINE_GET_MEMBER(SkDrawRect);

<<<<<<< HEAD
SkDrawRect::SkDrawRect()
    : fParent(nullptr)
{
    fRect.setEmpty();
}

void SkDrawRect::dirty()
{
=======
SkDrawRect::SkDrawRect() : fParent(NULL) {
    fRect.setEmpty();
}

void SkDrawRect::dirty() {
>>>>>>> miniblink49
    if (fParent)
        fParent->dirty();
}

<<<<<<< HEAD
bool SkDrawRect::draw(SkAnimateMaker& maker)
{
=======
bool SkDrawRect::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    SkBoundableAuto boundable(this, maker);
    maker.fCanvas->drawRect(fRect, *maker.fPaint);
    return false;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkDrawRect::dump(SkAnimateMaker* maker)
{
=======
void SkDrawRect::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    dumpBase(maker);
    SkDebugf("left=\"%g\" top=\"%g\" right=\"%g\" bottom=\"%g\" />\n",
        SkScalarToFloat(fRect.fLeft), SkScalarToFloat(fRect.fTop), SkScalarToFloat(fRect.fRight),
        SkScalarToFloat(fRect.fBottom));
}
#endif

<<<<<<< HEAD
SkDisplayable* SkDrawRect::getParent() const
{
    return fParent;
}

bool SkDrawRect::getProperty(int index, SkScriptValue* value) const
{
    SkScalar result;
    switch (index) {
    case SK_PROPERTY(height):
        result = fRect.height();
        break;
    case SK_PROPERTY(needsRedraw):
        value->fType = SkType_Boolean;
        value->fOperand.fS32 = fBounds.isEmpty() == false;
        return true;
    case SK_PROPERTY(width):
        result = fRect.width();
        break;
    default:
        SkASSERT(0);
        return false;
=======
SkDisplayable* SkDrawRect::getParent() const {
    return fParent;
}

bool SkDrawRect::getProperty(int index, SkScriptValue* value) const {
    SkScalar result;
    switch (index) {
        case SK_PROPERTY(height):
            result = fRect.height();
            break;
        case SK_PROPERTY(needsRedraw):
            value->fType = SkType_Boolean;
            value->fOperand.fS32 = fBounds.isEmpty() == false;
            return true;
        case SK_PROPERTY(width):
            result = fRect.width();
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    value->fType = SkType_Float;
    value->fOperand.fScalar = result;
    return true;
}

<<<<<<< HEAD
bool SkDrawRect::setParent(SkDisplayable* parent)
{
=======

bool SkDrawRect::setParent(SkDisplayable* parent) {
>>>>>>> miniblink49
    fParent = parent;
    return false;
}

<<<<<<< HEAD
bool SkDrawRect::setProperty(int index, SkScriptValue& value)
{
    SkScalar scalar = value.fOperand.fScalar;
    switch (index) {
    case SK_PROPERTY(height):
        SkASSERT(value.fType == SkType_Float);
        fRect.fBottom = scalar + fRect.fTop;
        return true;
    case SK_PROPERTY(needsRedraw):
        return false;
    case SK_PROPERTY(width):
        SkASSERT(value.fType == SkType_Float);
        fRect.fRight = scalar + fRect.fLeft;
        return true;
    default:
        SkASSERT(0);
=======
bool SkDrawRect::setProperty(int index, SkScriptValue& value) {
    SkScalar scalar = value.fOperand.fScalar;
    switch (index) {
        case SK_PROPERTY(height):
            SkASSERT(value.fType == SkType_Float);
            fRect.fBottom = scalar + fRect.fTop;
            return true;
        case SK_PROPERTY(needsRedraw):
            return false;
        case SK_PROPERTY(width):
            SkASSERT(value.fType == SkType_Float);
            fRect.fRight = scalar + fRect.fLeft;
            return true;
        default:
            SkASSERT(0);
>>>>>>> miniblink49
    }
    return false;
}

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRoundRect::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER(rx, Float),
    SK_MEMBER(ry, Float),
};

#endif

DEFINE_GET_MEMBER(SkRoundRect);

<<<<<<< HEAD
SkRoundRect::SkRoundRect()
    : rx(0)
    , ry(0)
{
}

bool SkRoundRect::draw(SkAnimateMaker& maker)
{
=======
SkRoundRect::SkRoundRect() : rx(0), ry(0) {
}

bool SkRoundRect::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    SkBoundableAuto boundable(this, maker);
    maker.fCanvas->drawRoundRect(fRect, rx, ry, *maker.fPaint);
    return false;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkRoundRect::dump(SkAnimateMaker* maker)
{
    dumpBase(maker);
    SkDebugf("left=\"%g\" top=\"%g\" right=\"%g\" bottom=\"%g\" rx=\"%g\" ry=\"%g\" />\n",
        SkScalarToFloat(fRect.fLeft), SkScalarToFloat(fRect.fTop), SkScalarToFloat(fRect.fRight),
        SkScalarToFloat(fRect.fBottom), SkScalarToFloat(rx), SkScalarToFloat(ry));
=======
void SkRoundRect::dump(SkAnimateMaker* maker) {
    dumpBase(maker);
    SkDebugf("left=\"%g\" top=\"%g\" right=\"%g\" bottom=\"%g\" rx=\"%g\" ry=\"%g\" />\n",
            SkScalarToFloat(fRect.fLeft), SkScalarToFloat(fRect.fTop), SkScalarToFloat(fRect.fRight),
            SkScalarToFloat(fRect.fBottom), SkScalarToFloat(rx), SkScalarToFloat(ry));
>>>>>>> miniblink49
}
#endif
