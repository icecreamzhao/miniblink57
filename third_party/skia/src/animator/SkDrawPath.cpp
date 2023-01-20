
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDrawPath.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkMath.h"
#include "SkMatrixParts.h"
#include "SkPaint.h"
#include "SkPathParts.h"

enum SkPath_Properties {
    SK_PROPERTY(fillType),
    SK_PROPERTY(length)
};

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDrawPath::fInfo[] = {
    SK_MEMBER(d, String),
    SK_MEMBER_PROPERTY(fillType, FillType),
    SK_MEMBER_PROPERTY(length, Float)
};

#endif

DEFINE_GET_MEMBER(SkDrawPath);

SkDrawPath::SkDrawPath()
{
<<<<<<< HEAD
    fParent = nullptr;
=======
    fParent = NULL;
>>>>>>> miniblink49
    fLength = SK_ScalarNaN;
    fChildHasID = false;
    fDirty = false;
}

<<<<<<< HEAD
SkDrawPath::~SkDrawPath()
{
    for (SkPathPart** part = fParts.begin(); part < fParts.end(); part++)
        delete *part;
}

bool SkDrawPath::addChild(SkAnimateMaker& maker, SkDisplayable* child)
{
    SkASSERT(child && child->isPathPart());
    SkPathPart* part = (SkPathPart*)child;
=======
SkDrawPath::~SkDrawPath() {
    for (SkPathPart** part = fParts.begin(); part < fParts.end();  part++)
        delete *part;
}

bool SkDrawPath::addChild(SkAnimateMaker& maker, SkDisplayable* child) {
    SkASSERT(child && child->isPathPart());
    SkPathPart* part = (SkPathPart*) child;
>>>>>>> miniblink49
    *fParts.append() = part;
    if (part->add())
        maker.setErrorCode(SkDisplayXMLParserError::kErrorAddingToPath);
    fDirty = false;
    return true;
}

<<<<<<< HEAD
bool SkDrawPath::childrenNeedDisposing() const
{
    return false;
}

void SkDrawPath::dirty()
{
=======
bool SkDrawPath::childrenNeedDisposing() const {
    return false;
}

void SkDrawPath::dirty() {
>>>>>>> miniblink49
    fDirty = true;
    fLength = SK_ScalarNaN;
    if (fParent)
        fParent->dirty();
}

<<<<<<< HEAD
bool SkDrawPath::draw(SkAnimateMaker& maker)
{
=======
bool SkDrawPath::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    SkPath& path = getPath();
    SkBoundableAuto boundable(this, maker);
    maker.fCanvas->drawPath(path, *maker.fPaint);
    return false;
}

<<<<<<< HEAD
SkDisplayable* SkDrawPath::getParent() const
{
=======
SkDisplayable* SkDrawPath::getParent() const {
>>>>>>> miniblink49
    return fParent;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkDrawPath::dump(SkAnimateMaker* maker)
{
=======
void SkDrawPath::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    dumpBase(maker);
    dumpAttrs(maker);
    bool closedYet = false;
    SkDisplayList::fIndent += 4;
<<<<<<< HEAD
    for (SkPathPart** part = fParts.begin(); part < fParts.end(); part++) {
=======
    for(SkPathPart** part = fParts.begin(); part < fParts.end(); part++) {
>>>>>>> miniblink49
        if (closedYet == false) {
            SkDebugf(">\n");
            closedYet = true;
        }
        (*part)->dump(maker);
    }
    SkDisplayList::fIndent -= 4;
    if (closedYet)
        dumpEnd(maker);
    else
        SkDebugf("/>\n");
}
#endif

<<<<<<< HEAD
SkPath& SkDrawPath::getPath()
{
    if (fDirty == false)
        return fPath;
    if (d.size() > 0) {
        parseSVG();
        d.reset();
    } else {
        fPath.reset();
        for (SkPathPart** part = fParts.begin(); part < fParts.end(); part++)
=======
SkPath& SkDrawPath::getPath() {
    if (fDirty == false)
        return fPath;
    if (d.size() > 0)
    {
        parseSVG();
        d.reset();
    }
    else
    {
        fPath.reset();
        for (SkPathPart** part = fParts.begin(); part < fParts.end();  part++)
>>>>>>> miniblink49
            (*part)->add();
    }
    fDirty = false;
    return fPath;
}

<<<<<<< HEAD
void SkDrawPath::onEndElement(SkAnimateMaker&)
{
=======
void SkDrawPath::onEndElement(SkAnimateMaker& ) {
>>>>>>> miniblink49
    if (d.size() > 0) {
        parseSVG();
        d.reset();
        fDirty = false;
        return;
    }
    if (fChildHasID == false) {
<<<<<<< HEAD
        for (SkPathPart** part = fParts.begin(); part < fParts.end(); part++)
=======
        for (SkPathPart** part = fParts.begin(); part < fParts.end();  part++)
>>>>>>> miniblink49
            delete *part;
        fParts.reset();
        fDirty = false;
    }
}

<<<<<<< HEAD
bool SkDrawPath::getProperty(int index, SkScriptValue* value) const
{
    switch (index) {
    case SK_PROPERTY(length):
        if (SkScalarIsNaN(fLength)) {
            const SkPath& path = ((SkDrawPath*)this)->getPath();
            SkPathMeasure pathMeasure(path, false);
            fLength = pathMeasure.getLength();
        }
        value->fType = SkType_Float;
        value->fOperand.fScalar = fLength;
        break;
    case SK_PROPERTY(fillType):
        value->fType = SkType_FillType;
        value->fOperand.fS32 = (int)fPath.getFillType();
        break;
    default:
        SkASSERT(0);
        return false;
=======
bool SkDrawPath::getProperty(int index, SkScriptValue* value) const {
    switch (index) {
        case SK_PROPERTY(length):
            if (SkScalarIsNaN(fLength)) {
                const SkPath& path = ((SkDrawPath*) this)->getPath();
                SkPathMeasure pathMeasure(path, false);
                fLength = pathMeasure.getLength();
            }
            value->fType = SkType_Float;
            value->fOperand.fScalar = fLength;
            break;
        case SK_PROPERTY(fillType):
            value->fType = SkType_FillType;
            value->fOperand.fS32 = (int) fPath.getFillType();
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true;
}

<<<<<<< HEAD
void SkDrawPath::setChildHasID()
{
    fChildHasID = true;
}

bool SkDrawPath::setParent(SkDisplayable* parent)
{
=======
void SkDrawPath::setChildHasID() {
    fChildHasID = true;
}

bool SkDrawPath::setParent(SkDisplayable* parent) {
>>>>>>> miniblink49
    fParent = parent;
    return false;
}

bool SkDrawPath::setProperty(int index, SkScriptValue& value)
{
    switch (index) {
<<<<<<< HEAD
    case SK_PROPERTY(fillType):
        SkASSERT(value.fType == SkType_FillType);
        SkASSERT(value.fOperand.fS32 >= SkPath::kWinding_FillType && value.fOperand.fS32 <= SkPath::kEvenOdd_FillType);
        fPath.setFillType((SkPath::FillType)value.fOperand.fS32);
        break;
    default:
        SkASSERT(0);
        return false;
=======
        case SK_PROPERTY(fillType):
            SkASSERT(value.fType == SkType_FillType);
            SkASSERT(value.fOperand.fS32 >= SkPath::kWinding_FillType &&
                value.fOperand.fS32 <= SkPath::kEvenOdd_FillType);
            fPath.setFillType((SkPath::FillType) value.fOperand.fS32);
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true;
}

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkPolyline::fInfo[] = {
    SK_MEMBER_ARRAY(points, Float)
};

#endif

DEFINE_GET_MEMBER(SkPolyline);

<<<<<<< HEAD
bool SkPolyline::addChild(SkAnimateMaker&, SkDisplayable*)
{
    return false;
}

void SkPolyline::onEndElement(SkAnimateMaker& maker)
{
=======
bool SkPolyline::addChild(SkAnimateMaker& , SkDisplayable*) {
    return false;
}

void SkPolyline::onEndElement(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    INHERITED::onEndElement(maker);
    if (points.count() <= 0)
        return;
    fPath.reset();
    fPath.moveTo(points[0], points[1]);
    int count = points.count();
    for (int index = 2; index < count; index += 2)
<<<<<<< HEAD
        fPath.lineTo(points[index], points[index + 1]);
}

=======
        fPath.lineTo(points[index], points[index+1]);
}


>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkPolygon::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkPolygon);

<<<<<<< HEAD
void SkPolygon::onEndElement(SkAnimateMaker& maker)
{
=======
void SkPolygon::onEndElement(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    INHERITED::onEndElement(maker);
    fPath.close();
}
