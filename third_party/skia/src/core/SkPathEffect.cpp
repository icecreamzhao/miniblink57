<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPathEffect.h"
#include "SkPath.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkPathEffect::computeFastBounds(SkRect* dst, const SkRect& src) const
{
=======
void SkPathEffect::computeFastBounds(SkRect* dst, const SkRect& src) const {
>>>>>>> miniblink49
    *dst = src;
}

bool SkPathEffect::asPoints(PointData* results, const SkPath& src,
<<<<<<< HEAD
    const SkStrokeRec&, const SkMatrix&, const SkRect*) const
{
    return false;
}

SkPathEffect::DashType SkPathEffect::asADash(DashInfo* info) const
{
=======
                    const SkStrokeRec&, const SkMatrix&, const SkRect*) const {
    return false;
}

SkPathEffect::DashType SkPathEffect::asADash(DashInfo* info) const {
>>>>>>> miniblink49
    return kNone_DashType;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkPairPathEffect::SkPairPathEffect(sk_sp<SkPathEffect> pe0, sk_sp<SkPathEffect> pe1)
    : fPE0(std::move(pe0))
    , fPE1(std::move(pe1))
{
    SkASSERT(fPE0.get());
    SkASSERT(fPE1.get());
=======
SkPairPathEffect::SkPairPathEffect(SkPathEffect* pe0, SkPathEffect* pe1)
        : fPE0(pe0), fPE1(pe1) {
    SkASSERT(pe0);
    SkASSERT(pe1);
    fPE0->ref();
    fPE1->ref();
}

SkPairPathEffect::~SkPairPathEffect() {
    SkSafeUnref(fPE0);
    SkSafeUnref(fPE1);
>>>>>>> miniblink49
}

/*
    Format: [oe0-factory][pe1-factory][pe0-size][pe0-data][pe1-data]
*/
<<<<<<< HEAD
void SkPairPathEffect::flatten(SkWriteBuffer& buffer) const
{
    buffer.writeFlattenable(fPE0.get());
    buffer.writeFlattenable(fPE1.get());
}

#ifndef SK_IGNORE_TO_STRING
void SkPairPathEffect::toString(SkString* str) const
{
=======
void SkPairPathEffect::flatten(SkWriteBuffer& buffer) const {
    buffer.writeFlattenable(fPE0);
    buffer.writeFlattenable(fPE1);
}

#ifndef SK_IGNORE_TO_STRING
void SkPairPathEffect::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("first: ");
    if (fPE0) {
        fPE0->toString(str);
    }
    str->appendf(" second: ");
    if (fPE1) {
        fPE1->toString(str);
    }
}
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkFlattenable> SkComposePathEffect::CreateProc(SkReadBuffer& buffer)
{
    sk_sp<SkPathEffect> pe0(buffer.readPathEffect());
    sk_sp<SkPathEffect> pe1(buffer.readPathEffect());
    return SkComposePathEffect::Make(std::move(pe0), std::move(pe1));
}

bool SkComposePathEffect::filterPath(SkPath* dst, const SkPath& src,
    SkStrokeRec* rec, const SkRect* cullRect) const
{
    SkPath tmp;
    const SkPath* ptr = &src;
=======
SkFlattenable* SkComposePathEffect::CreateProc(SkReadBuffer& buffer) {
    SkAutoTUnref<SkPathEffect> pe0(buffer.readPathEffect());
    SkAutoTUnref<SkPathEffect> pe1(buffer.readPathEffect());
    return SkComposePathEffect::Create(pe0, pe1);
}

bool SkComposePathEffect::filterPath(SkPath* dst, const SkPath& src,
                             SkStrokeRec* rec, const SkRect* cullRect) const {
    // we may have failed to unflatten these, so we have to check
    if (!fPE0 || !fPE1) {
        return false;
    }

    SkPath          tmp;
    const SkPath*   ptr = &src;
>>>>>>> miniblink49

    if (fPE1->filterPath(&tmp, src, rec, cullRect)) {
        ptr = &tmp;
    }
    return fPE0->filterPath(dst, *ptr, rec, cullRect);
}

<<<<<<< HEAD
#ifndef SK_IGNORE_TO_STRING
void SkComposePathEffect::toString(SkString* str) const
{
=======

#ifndef SK_IGNORE_TO_STRING
void SkComposePathEffect::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkComposePathEffect: (");
    this->INHERITED::toString(str);
    str->appendf(")");
}
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkFlattenable> SkSumPathEffect::CreateProc(SkReadBuffer& buffer)
{
    sk_sp<SkPathEffect> pe0(buffer.readPathEffect());
    sk_sp<SkPathEffect> pe1(buffer.readPathEffect());
    return SkSumPathEffect::Make(pe0, pe1);
}

bool SkSumPathEffect::filterPath(SkPath* dst, const SkPath& src,
    SkStrokeRec* rec, const SkRect* cullRect) const
{
    // use bit-or so that we always call both, even if the first one succeeds
    return fPE0->filterPath(dst, src, rec, cullRect) | fPE1->filterPath(dst, src, rec, cullRect);
}

#ifndef SK_IGNORE_TO_STRING
void SkSumPathEffect::toString(SkString* str) const
{
=======
SkFlattenable* SkSumPathEffect::CreateProc(SkReadBuffer& buffer) {
    SkAutoTUnref<SkPathEffect> pe0(buffer.readPathEffect());
    SkAutoTUnref<SkPathEffect> pe1(buffer.readPathEffect());
    return SkSumPathEffect::Create(pe0, pe1);
}

bool SkSumPathEffect::filterPath(SkPath* dst, const SkPath& src,
                             SkStrokeRec* rec, const SkRect* cullRect) const {
    // use bit-or so that we always call both, even if the first one succeeds
    return fPE0->filterPath(dst, src, rec, cullRect) |
           fPE1->filterPath(dst, src, rec, cullRect);
}


#ifndef SK_IGNORE_TO_STRING
void SkSumPathEffect::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkSumPathEffect: (");
    this->INHERITED::toString(str);
    str->appendf(")");
}
#endif
