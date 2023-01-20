/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkStrokeRec.h"
#include "SkPaintDefaults.h"

// must be < 0, since ==0 means hairline, and >0 means normal stroke
<<<<<<< HEAD
#define kStrokeRec_FillStyleWidth (-SK_Scalar1)

SkStrokeRec::SkStrokeRec(InitStyle s)
{
    fResScale = 1;
    fWidth = (kFill_InitStyle == s) ? kStrokeRec_FillStyleWidth : 0;
    fMiterLimit = SkPaintDefaults_MiterLimit;
    fCap = SkPaint::kDefault_Cap;
    fJoin = SkPaint::kDefault_Join;
    fStrokeAndFill = false;
}

SkStrokeRec::SkStrokeRec(const SkPaint& paint, SkScalar resScale)
{
    this->init(paint, paint.getStyle(), resScale);
}

SkStrokeRec::SkStrokeRec(const SkPaint& paint, SkPaint::Style styleOverride, SkScalar resScale)
{
    this->init(paint, styleOverride, resScale);
}

void SkStrokeRec::init(const SkPaint& paint, SkPaint::Style style, SkScalar resScale)
{
    fResScale = resScale;

    switch (style) {
    case SkPaint::kFill_Style:
        fWidth = kStrokeRec_FillStyleWidth;
        fStrokeAndFill = false;
        break;
    case SkPaint::kStroke_Style:
        fWidth = paint.getStrokeWidth();
        fStrokeAndFill = false;
        break;
    case SkPaint::kStrokeAndFill_Style:
        if (0 == paint.getStrokeWidth()) {
            // hairline+fill == fill
            fWidth = kStrokeRec_FillStyleWidth;
            fStrokeAndFill = false;
        } else {
            fWidth = paint.getStrokeWidth();
            fStrokeAndFill = true;
        }
        break;
    default:
        SkDEBUGFAIL("unknown paint style");
        // fall back on just fill
        fWidth = kStrokeRec_FillStyleWidth;
        fStrokeAndFill = false;
        break;
=======
#define kStrokeRec_FillStyleWidth     (-SK_Scalar1)

SkStrokeRec::SkStrokeRec(InitStyle s) {
    fResScale       = 1;
    fWidth          = (kFill_InitStyle == s) ? kStrokeRec_FillStyleWidth : 0;
    fMiterLimit     = SkPaintDefaults_MiterLimit;
    fCap            = SkPaint::kDefault_Cap;
    fJoin           = SkPaint::kDefault_Join;
    fStrokeAndFill  = false;
}

SkStrokeRec::SkStrokeRec(const SkPaint& paint, SkScalar resScale) {
    this->init(paint, paint.getStyle(), resScale);
}

SkStrokeRec::SkStrokeRec(const SkPaint& paint, SkPaint::Style styleOverride, SkScalar resScale) {
    this->init(paint, styleOverride, resScale);
}

void SkStrokeRec::init(const SkPaint& paint, SkPaint::Style style, SkScalar resScale) {
    fResScale = resScale;

    switch (style) {
        case SkPaint::kFill_Style:
            fWidth = kStrokeRec_FillStyleWidth;
            fStrokeAndFill = false;
            break;
        case SkPaint::kStroke_Style:
            fWidth = paint.getStrokeWidth();
            fStrokeAndFill = false;
            break;
        case SkPaint::kStrokeAndFill_Style:
            if (0 == paint.getStrokeWidth()) {
                // hairline+fill == fill
                fWidth = kStrokeRec_FillStyleWidth;
                fStrokeAndFill = false;
            } else {
                fWidth = paint.getStrokeWidth();
                fStrokeAndFill = true;
            }
            break;
        default:
            SkDEBUGFAIL("unknown paint style");
            // fall back on just fill
            fWidth = kStrokeRec_FillStyleWidth;
            fStrokeAndFill = false;
            break;
>>>>>>> miniblink49
    }

    // copy these from the paint, regardless of our "style"
    fMiterLimit = paint.getStrokeMiter();
<<<<<<< HEAD
    fCap = paint.getStrokeCap();
    fJoin = paint.getStrokeJoin();
}

SkStrokeRec::Style SkStrokeRec::getStyle() const
{
=======
    fCap        = paint.getStrokeCap();
    fJoin       = paint.getStrokeJoin();
}

SkStrokeRec::Style SkStrokeRec::getStyle() const {
>>>>>>> miniblink49
    if (fWidth < 0) {
        return kFill_Style;
    } else if (0 == fWidth) {
        return kHairline_Style;
    } else {
        return fStrokeAndFill ? kStrokeAndFill_Style : kStroke_Style;
    }
}

<<<<<<< HEAD
void SkStrokeRec::setFillStyle()
{
=======
void SkStrokeRec::setFillStyle() {
>>>>>>> miniblink49
    fWidth = kStrokeRec_FillStyleWidth;
    fStrokeAndFill = false;
}

<<<<<<< HEAD
void SkStrokeRec::setHairlineStyle()
{
=======
void SkStrokeRec::setHairlineStyle() {
>>>>>>> miniblink49
    fWidth = 0;
    fStrokeAndFill = false;
}

<<<<<<< HEAD
void SkStrokeRec::setStrokeStyle(SkScalar width, bool strokeAndFill)
{
=======
void SkStrokeRec::setStrokeStyle(SkScalar width, bool strokeAndFill) {
>>>>>>> miniblink49
    if (strokeAndFill && (0 == width)) {
        // hairline+fill == fill
        this->setFillStyle();
    } else {
        fWidth = width;
        fStrokeAndFill = strokeAndFill;
    }
}

#include "SkStroke.h"

<<<<<<< HEAD
#ifdef SK_DEBUG
// enables tweaking these values at runtime from SampleApp
bool gDebugStrokerErrorSet = false;
SkScalar gDebugStrokerError;
#endif

bool SkStrokeRec::applyToPath(SkPath* dst, const SkPath& src) const
{
    if (fWidth <= 0) { // hairline or fill
=======
#ifdef SK_DEBUG  
    // enables tweaking these values at runtime from SampleApp
    bool gDebugStrokerErrorSet = false;
    SkScalar gDebugStrokerError;
#endif

bool SkStrokeRec::applyToPath(SkPath* dst, const SkPath& src) const {
    if (fWidth <= 0) {  // hairline or fill
>>>>>>> miniblink49
        return false;
    }

    SkStroke stroker;
<<<<<<< HEAD
    stroker.setCap((SkPaint::Cap)fCap);
    stroker.setJoin((SkPaint::Join)fJoin);
=======
    stroker.setCap(fCap);
    stroker.setJoin(fJoin);
>>>>>>> miniblink49
    stroker.setMiterLimit(fMiterLimit);
    stroker.setWidth(fWidth);
    stroker.setDoFill(fStrokeAndFill);
#ifdef SK_DEBUG
    stroker.setResScale(gDebugStrokerErrorSet ? gDebugStrokerError : fResScale);
#else
    stroker.setResScale(fResScale);
#endif
    stroker.strokePath(src, dst);
    return true;
}

<<<<<<< HEAD
void SkStrokeRec::applyToPaint(SkPaint* paint) const
{
    if (fWidth < 0) { // fill
=======
void SkStrokeRec::applyToPaint(SkPaint* paint) const {
    if (fWidth < 0) {  // fill
>>>>>>> miniblink49
        paint->setStyle(SkPaint::kFill_Style);
        return;
    }

    paint->setStyle(fStrokeAndFill ? SkPaint::kStrokeAndFill_Style : SkPaint::kStroke_Style);
    paint->setStrokeWidth(fWidth);
    paint->setStrokeMiter(fMiterLimit);
<<<<<<< HEAD
    paint->setStrokeCap((SkPaint::Cap)fCap);
    paint->setStrokeJoin((SkPaint::Join)fJoin);
}

static inline SkScalar get_inflation_bounds(SkPaint::Join join,
    SkScalar strokeWidth,
    SkScalar miterLimit)
{
    if (strokeWidth < 0) { // fill
        return 0;
    } else if (0 == strokeWidth) {
        return SK_Scalar1;
    }
    // since we're stroked, outset the rect by the radius (and join type)
    SkScalar radius = SkScalarHalf(strokeWidth);
    if (SkPaint::kMiter_Join == join) {
        if (miterLimit > SK_Scalar1) {
            radius = SkScalarMul(miterLimit, radius);
        }
    }
    return radius;
}

SkScalar SkStrokeRec::getInflationRadius() const
{
    return get_inflation_bounds((SkPaint::Join)fJoin, fWidth, fMiterLimit);
}

SkScalar SkStrokeRec::GetInflationRadius(const SkPaint& paint, SkPaint::Style style)
{
    SkScalar width = SkPaint::kFill_Style == style ? -SK_Scalar1 : paint.getStrokeWidth();
    return get_inflation_bounds(paint.getStrokeJoin(), width, paint.getStrokeMiter());
=======
    paint->setStrokeCap(fCap);
    paint->setStrokeJoin(fJoin);
>>>>>>> miniblink49
}
