
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkMatrixParts.h"
#include "SkAnimateMaker.h"
#include "SkDrawMatrix.h"
#include "SkDrawPath.h"
#include "SkDrawRectangle.h"

SkMatrixPart::SkMatrixPart()
    : fMatrix(nullptr)
{
}

void SkMatrixPart::dirty()
{
    fMatrix->dirty();
}

SkDisplayable* SkMatrixPart::getParent() const
{
    return fMatrix;
}

bool SkMatrixPart::setParent(SkDisplayable* parent)
{
    SkASSERT(parent != nullptr);
    if (parent->isMatrix() == false)
        return true;
    fMatrix = (SkDrawMatrix*)parent;
    return false;
}

=======

#include "SkMatrixParts.h"
#include "SkAnimateMaker.h"
#include "SkDrawMatrix.h"
#include "SkDrawRectangle.h"
#include "SkDrawPath.h"

SkMatrixPart::SkMatrixPart() : fMatrix(NULL) {
}

void SkMatrixPart::dirty() {
    fMatrix->dirty();
}

SkDisplayable* SkMatrixPart::getParent() const {
    return fMatrix;
}

bool SkMatrixPart::setParent(SkDisplayable* parent) {
    SkASSERT(parent != NULL);
    if (parent->isMatrix() == false)
        return true;
    fMatrix = (SkDrawMatrix*) parent;
    return false;
}


>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRotate::fInfo[] = {
    SK_MEMBER(center, Point),
    SK_MEMBER(degrees, Float)
};

#endif

DEFINE_GET_MEMBER(SkRotate);

<<<<<<< HEAD
SkRotate::SkRotate()
    : degrees(0)
{
    center.fX = center.fY = 0;
}

bool SkRotate::add()
{
=======
SkRotate::SkRotate() : degrees(0) {
    center.fX = center.fY = 0;
}

bool SkRotate::add() {
>>>>>>> miniblink49
    fMatrix->rotate(degrees, center);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkScale::fInfo[] = {
    SK_MEMBER(center, Point),
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkScale);

<<<<<<< HEAD
SkScale::SkScale()
    : x(SK_Scalar1)
    , y(SK_Scalar1)
{
    center.fX = center.fY = 0;
}

bool SkScale::add()
{
=======
SkScale::SkScale() : x(SK_Scalar1), y(SK_Scalar1) {
    center.fX = center.fY = 0;
}

bool SkScale::add() {
>>>>>>> miniblink49
    fMatrix->scale(x, y, center);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkSkew::fInfo[] = {
    SK_MEMBER(center, Point),
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkSkew);

<<<<<<< HEAD
SkSkew::SkSkew()
    : x(0)
    , y(0)
{
    center.fX = center.fY = 0;
}

bool SkSkew::add()
{
=======
SkSkew::SkSkew() : x(0), y(0) {
    center.fX = center.fY = 0;
}

bool SkSkew::add() {
>>>>>>> miniblink49
    fMatrix->skew(x, y, center);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkTranslate::fInfo[] = {
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkTranslate);

<<<<<<< HEAD
SkTranslate::SkTranslate()
    : x(0)
    , y(0)
{
}

bool SkTranslate::add()
{
=======
SkTranslate::SkTranslate() : x(0), y(0) {
}

bool SkTranslate::add() {
>>>>>>> miniblink49
    fMatrix->translate(x, y);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkFromPath::fInfo[] = {
    SK_MEMBER(mode, FromPathMode),
    SK_MEMBER(offset, Float),
    SK_MEMBER(path, Path)
};

#endif

DEFINE_GET_MEMBER(SkFromPath);

<<<<<<< HEAD
SkFromPath::SkFromPath()
    : mode(0)
    , offset(0)
    , path(nullptr)
{
}

SkFromPath::~SkFromPath()
{
}

bool SkFromPath::add()
{
    if (path == nullptr)
        return true;
    static const uint8_t gFlags[] = {
        SkPathMeasure::kGetPosAndTan_MatrixFlag, // normal
        SkPathMeasure::kGetTangent_MatrixFlag, // angle
        SkPathMeasure::kGetPosition_MatrixFlag // position
=======
SkFromPath::SkFromPath() :
    mode(0), offset(0), path(NULL) {
}

SkFromPath::~SkFromPath() {
}

bool SkFromPath::add() {
    if (path == NULL)
        return true;
    static const uint8_t gFlags[] = {
        SkPathMeasure::kGetPosAndTan_MatrixFlag,    // normal
        SkPathMeasure::kGetTangent_MatrixFlag,      // angle
        SkPathMeasure::kGetPosition_MatrixFlag      // position
>>>>>>> miniblink49
    };
    if ((unsigned)mode >= SK_ARRAY_COUNT(gFlags))
        return true;
    SkMatrix result;
    fPathMeasure.setPath(&path->getPath(), false);
    if (fPathMeasure.getMatrix(offset, &result, (SkPathMeasure::MatrixFlags)gFlags[mode]))
        fMatrix->set(result);
    return false;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkRectToRect::fInfo[] = {
    SK_MEMBER(destination, Rect),
    SK_MEMBER(source, Rect)
};

#endif

DEFINE_GET_MEMBER(SkRectToRect);

<<<<<<< HEAD
SkRectToRect::SkRectToRect()
    : source(nullptr)
    , destination(nullptr)
{
}

SkRectToRect::~SkRectToRect()
{
}

bool SkRectToRect::add()
{
    if (source == nullptr || destination == nullptr)
        return true;
    SkMatrix temp;
    temp.setRectToRect(source->fRect, destination->fRect,
        SkMatrix::kFill_ScaleToFit);
=======
SkRectToRect::SkRectToRect() :
    source(NULL), destination(NULL) {
}

SkRectToRect::~SkRectToRect() {
}

bool SkRectToRect::add() {
    if (source == NULL || destination == NULL)
        return true;
    SkMatrix temp;
    temp.setRectToRect(source->fRect, destination->fRect,
                       SkMatrix::kFill_ScaleToFit);
>>>>>>> miniblink49
    fMatrix->set(temp);
    return false;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkRectToRect::dump(SkAnimateMaker* maker)
{
=======
void SkRectToRect::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    dumpBase(maker);
    SkDebugf("/>\n");
    SkDisplayList::fIndent += 4;
    if (source) {
        SkDebugf("%*s<source>\n", SkDisplayList::fIndent, "");
        SkDisplayList::fIndent += 4;
        source->dump(maker);
        SkDisplayList::fIndent -= 4;
        SkDebugf("%*s</source>\n", SkDisplayList::fIndent, "");
    }
    if (destination) {
        SkDebugf("%*s<destination>\n", SkDisplayList::fIndent, "");
        SkDisplayList::fIndent += 4;
        destination->dump(maker);
        SkDisplayList::fIndent -= 4;
        SkDebugf("%*s</destination>\n", SkDisplayList::fIndent, "");
    }
    SkDisplayList::fIndent -= 4;
    dumpEnd(maker);
}
#endif

<<<<<<< HEAD
const SkMemberInfo* SkRectToRect::preferredChild(SkDisplayTypes)
{
    if (source == nullptr)
        return getMember("source"); // !!! cwap! need to refer to member through enum like kScope instead
    else {
        SkASSERT(destination == nullptr);
=======
const SkMemberInfo* SkRectToRect::preferredChild(SkDisplayTypes ) {
    if (source == NULL)
        return getMember("source"); // !!! cwap! need to refer to member through enum like kScope instead
    else {
        SkASSERT(destination == NULL);
>>>>>>> miniblink49
        return getMember("destination");
    }
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkPolyToPoly::fInfo[] = {
    SK_MEMBER(destination, Polygon),
    SK_MEMBER(source, Polygon)
};

#endif

DEFINE_GET_MEMBER(SkPolyToPoly);

<<<<<<< HEAD
SkPolyToPoly::SkPolyToPoly()
    : source(nullptr)
    , destination(nullptr)
{
}

SkPolyToPoly::~SkPolyToPoly()
{
}

bool SkPolyToPoly::add()
{
=======
SkPolyToPoly::SkPolyToPoly() : source(NULL), destination(NULL) {
}

SkPolyToPoly::~SkPolyToPoly() {
}

bool SkPolyToPoly::add() {
>>>>>>> miniblink49
    SkASSERT(source);
    SkASSERT(destination);
    SkPoint src[4];
    SkPoint dst[4];
    SkPath& sourcePath = source->getPath();
    int srcPts = sourcePath.getPoints(src, 4);
    SkPath& destPath = destination->getPath();
    int dstPts = destPath.getPoints(dst, 4);
    if (srcPts != dstPts)
        return true;
    SkMatrix temp;
    temp.setPolyToPoly(src, dst, srcPts);
    fMatrix->set(temp);
    return false;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkPolyToPoly::dump(SkAnimateMaker* maker)
{
=======
void SkPolyToPoly::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    dumpBase(maker);
    SkDebugf("/>\n");
    SkDisplayList::fIndent += 4;
    if (source) {
        SkDebugf("%*s<source>\n", SkDisplayList::fIndent, "");
        SkDisplayList::fIndent += 4;
        source->dump(maker);
        SkDisplayList::fIndent -= 4;
        SkDebugf("%*s</source>\n", SkDisplayList::fIndent, "");
    }
    if (destination) {
        SkDebugf("%*s<destination>\n", SkDisplayList::fIndent, "");
        SkDisplayList::fIndent += 4;
        destination->dump(maker);
        SkDisplayList::fIndent -= 4;
        SkDebugf("%*s</destination>\n", SkDisplayList::fIndent, "");
    }
    SkDisplayList::fIndent -= 4;
    dumpEnd(maker);
}
#endif

<<<<<<< HEAD
void SkPolyToPoly::onEndElement(SkAnimateMaker&)
{
=======
void SkPolyToPoly::onEndElement(SkAnimateMaker& ) {
>>>>>>> miniblink49
    SkASSERT(source);
    SkASSERT(destination);
    if (source->childHasID() || destination->childHasID())
        fMatrix->setChildHasID();
}

<<<<<<< HEAD
const SkMemberInfo* SkPolyToPoly::preferredChild(SkDisplayTypes)
{
    if (source == nullptr)
        return getMember("source"); // !!! cwap! need to refer to member through enum like kScope instead
    else {
        SkASSERT(destination == nullptr);
=======
const SkMemberInfo* SkPolyToPoly::preferredChild(SkDisplayTypes ) {
    if (source == NULL)
        return getMember("source"); // !!! cwap! need to refer to member through enum like kScope instead
    else {
        SkASSERT(destination == NULL);
>>>>>>> miniblink49
        return getMember("destination");
    }
}
