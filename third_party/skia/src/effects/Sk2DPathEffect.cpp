<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "Sk2DPathEffect.h"
#include "SkPath.h"
#include "SkReadBuffer.h"
#include "SkRegion.h"
#include "SkStrokeRec.h"
#include "SkWriteBuffer.h"

Sk2DPathEffect::Sk2DPathEffect(const SkMatrix& mat)
    : fMatrix(mat)
{
=======

#include "Sk2DPathEffect.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkPath.h"
#include "SkRegion.h"

Sk2DPathEffect::Sk2DPathEffect(const SkMatrix& mat) : fMatrix(mat) {
>>>>>>> miniblink49
    fMatrixIsInvertible = mat.invert(&fInverse);
}

bool Sk2DPathEffect::filterPath(SkPath* dst, const SkPath& src,
<<<<<<< HEAD
    SkStrokeRec*, const SkRect*) const
{
=======
                                SkStrokeRec*, const SkRect*) const {
>>>>>>> miniblink49
    if (!fMatrixIsInvertible) {
        return false;
    }

<<<<<<< HEAD
    SkPath tmp;
=======
    SkPath  tmp;
>>>>>>> miniblink49
    SkIRect ir;

    src.transform(fInverse, &tmp);
    tmp.getBounds().round(&ir);
    if (!ir.isEmpty()) {
        this->begin(ir, dst);

        SkRegion rgn;
        rgn.setPath(tmp, SkRegion(ir));
        SkRegion::Iterator iter(rgn);
        for (; !iter.done(); iter.next()) {
            const SkIRect& rect = iter.rect();
            for (int y = rect.fTop; y < rect.fBottom; ++y) {
                this->nextSpan(rect.fLeft, y, rect.width(), dst);
            }
        }

        this->end(dst);
    }
    return true;
}

<<<<<<< HEAD
void Sk2DPathEffect::nextSpan(int x, int y, int count, SkPath* path) const
{
=======
void Sk2DPathEffect::nextSpan(int x, int y, int count, SkPath* path) const {
>>>>>>> miniblink49
    if (!fMatrixIsInvertible) {
        return;
    }

    const SkMatrix& mat = this->getMatrix();
    SkPoint src, dst;

    src.set(SkIntToScalar(x) + SK_ScalarHalf, SkIntToScalar(y) + SK_ScalarHalf);
    do {
        mat.mapPoints(&dst, &src, 1);
        this->next(dst, x++, y, path);
        src.fX += SK_Scalar1;
    } while (--count > 0);
}

<<<<<<< HEAD
void Sk2DPathEffect::begin(const SkIRect& uvBounds, SkPath* dst) const { }
void Sk2DPathEffect::next(const SkPoint& loc, int u, int v, SkPath* dst) const { }
void Sk2DPathEffect::end(SkPath* dst) const { }

///////////////////////////////////////////////////////////////////////////////

void Sk2DPathEffect::flatten(SkWriteBuffer& buffer) const
{
=======
void Sk2DPathEffect::begin(const SkIRect& uvBounds, SkPath* dst) const {}
void Sk2DPathEffect::next(const SkPoint& loc, int u, int v, SkPath* dst) const {}
void Sk2DPathEffect::end(SkPath* dst) const {}

///////////////////////////////////////////////////////////////////////////////

void Sk2DPathEffect::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeMatrix(fMatrix);
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void Sk2DPathEffect::toString(SkString* str) const
{
    str->appendf("(matrix: %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f)",
        fMatrix[SkMatrix::kMScaleX], fMatrix[SkMatrix::kMSkewX], fMatrix[SkMatrix::kMTransX],
        fMatrix[SkMatrix::kMSkewY], fMatrix[SkMatrix::kMScaleY], fMatrix[SkMatrix::kMTransY],
        fMatrix[SkMatrix::kMPersp0], fMatrix[SkMatrix::kMPersp1], fMatrix[SkMatrix::kMPersp2]);
=======
void Sk2DPathEffect::toString(SkString* str) const {
    str->appendf("(matrix: %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f)",
            fMatrix[SkMatrix::kMScaleX], fMatrix[SkMatrix::kMSkewX],  fMatrix[SkMatrix::kMTransX],
            fMatrix[SkMatrix::kMSkewY],  fMatrix[SkMatrix::kMScaleY], fMatrix[SkMatrix::kMTransY],
            fMatrix[SkMatrix::kMPersp0], fMatrix[SkMatrix::kMPersp1], fMatrix[SkMatrix::kMPersp2]);
>>>>>>> miniblink49
}
#endif

///////////////////////////////////////////////////////////////////////////////

bool SkLine2DPathEffect::filterPath(SkPath* dst, const SkPath& src,
<<<<<<< HEAD
    SkStrokeRec* rec, const SkRect* cullRect) const
{
=======
                            SkStrokeRec* rec, const SkRect* cullRect) const {
>>>>>>> miniblink49
    if (this->INHERITED::filterPath(dst, src, rec, cullRect)) {
        rec->setStrokeStyle(fWidth);
        return true;
    }
    return false;
}

<<<<<<< HEAD
void SkLine2DPathEffect::nextSpan(int u, int v, int ucount, SkPath* dst) const
{
    if (ucount > 1) {
        SkPoint src[2], dstP[2];

        src[0].set(SkIntToScalar(u) + SK_ScalarHalf, SkIntToScalar(v) + SK_ScalarHalf);
        src[1].set(SkIntToScalar(u + ucount) + SK_ScalarHalf, SkIntToScalar(v) + SK_ScalarHalf);
=======
void SkLine2DPathEffect::nextSpan(int u, int v, int ucount, SkPath* dst) const {
    if (ucount > 1) {
        SkPoint    src[2], dstP[2];

        src[0].set(SkIntToScalar(u) + SK_ScalarHalf, SkIntToScalar(v) + SK_ScalarHalf);
        src[1].set(SkIntToScalar(u+ucount) + SK_ScalarHalf, SkIntToScalar(v) + SK_ScalarHalf);
>>>>>>> miniblink49
        this->getMatrix().mapPoints(dstP, src, 2);

        dst->moveTo(dstP[0]);
        dst->lineTo(dstP[1]);
    }
}

<<<<<<< HEAD
sk_sp<SkFlattenable> SkLine2DPathEffect::CreateProc(SkReadBuffer& buffer)
{
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    SkScalar width = buffer.readScalar();
    return SkLine2DPathEffect::Make(width, matrix);
}

void SkLine2DPathEffect::flatten(SkWriteBuffer& buffer) const
{
=======
SkFlattenable* SkLine2DPathEffect::CreateProc(SkReadBuffer& buffer) {
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    SkScalar width = buffer.readScalar();
    return SkLine2DPathEffect::Create(width, matrix);
}

void SkLine2DPathEffect::flatten(SkWriteBuffer &buffer) const {
>>>>>>> miniblink49
    buffer.writeMatrix(this->getMatrix());
    buffer.writeScalar(fWidth);
}

<<<<<<< HEAD
#ifndef SK_IGNORE_TO_STRING
void SkLine2DPathEffect::toString(SkString* str) const
{
=======

#ifndef SK_IGNORE_TO_STRING
void SkLine2DPathEffect::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkLine2DPathEffect: (");
    this->INHERITED::toString(str);
    str->appendf("width: %f", fWidth);
    str->appendf(")");
}
#endif

///////////////////////////////////////////////////////////////////////////////

SkPath2DPathEffect::SkPath2DPathEffect(const SkMatrix& m, const SkPath& p)
<<<<<<< HEAD
    : INHERITED(m)
    , fPath(p)
{
}

sk_sp<SkFlattenable> SkPath2DPathEffect::CreateProc(SkReadBuffer& buffer)
{
=======
    : INHERITED(m), fPath(p) {
}

SkFlattenable* SkPath2DPathEffect::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    SkPath path;
    buffer.readPath(&path);
<<<<<<< HEAD
    return SkPath2DPathEffect::Make(matrix, path);
}

void SkPath2DPathEffect::flatten(SkWriteBuffer& buffer) const
{
=======
    return SkPath2DPathEffect::Create(matrix, path);
}

void SkPath2DPathEffect::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    buffer.writeMatrix(this->getMatrix());
    buffer.writePath(fPath);
}

void SkPath2DPathEffect::next(const SkPoint& loc, int u, int v,
<<<<<<< HEAD
    SkPath* dst) const
{
=======
                              SkPath* dst) const {
>>>>>>> miniblink49
    dst->addPath(fPath, loc.fX, loc.fY);
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkPath2DPathEffect::toString(SkString* str) const
{
=======
void SkPath2DPathEffect::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkPath2DPathEffect: (");
    this->INHERITED::toString(str);
    // TODO: print out path information
    str->appendf(")");
}
#endif
