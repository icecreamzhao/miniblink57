<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include <algorithm>

#include "SkMatrix.h"
#include "SkTime.h"
#include "SkTouchGesture.h"

#define DISCRETIZE_TRANSLATE_TO_AVOID_FLICKER true

static const SkScalar MAX_FLING_SPEED = SkIntToScalar(1500);

static SkScalar pin_max_fling(SkScalar speed)
{
=======


#include "SkTouchGesture.h"
#include "SkMatrix.h"
#include "SkTime.h"

#define DISCRETIZE_TRANSLATE_TO_AVOID_FLICKER   true

static const SkScalar MAX_FLING_SPEED = SkIntToScalar(1500);

static SkScalar pin_max_fling(SkScalar speed) {
>>>>>>> miniblink49
    if (speed > MAX_FLING_SPEED) {
        speed = MAX_FLING_SPEED;
    }
    return speed;
}

<<<<<<< HEAD
static double getseconds()
{
=======
static double getseconds() {
>>>>>>> miniblink49
    return SkTime::GetMSecs() * 0.001;
}

// returns +1 or -1, depending on the sign of x
// returns +1 if z is zero
<<<<<<< HEAD
static SkScalar SkScalarSignNonZero(SkScalar x)
{
=======
static SkScalar SkScalarSignNonZero(SkScalar x) {
>>>>>>> miniblink49
    SkScalar sign = SK_Scalar1;
    if (x < 0) {
        sign = -sign;
    }
    return sign;
}

<<<<<<< HEAD
static void unit_axis_align(SkVector* unit)
{
=======
static void unit_axis_align(SkVector* unit) {
>>>>>>> miniblink49
    const SkScalar TOLERANCE = SkDoubleToScalar(0.15);
    if (SkScalarAbs(unit->fX) < TOLERANCE) {
        unit->fX = 0;
        unit->fY = SkScalarSignNonZero(unit->fY);
    } else if (SkScalarAbs(unit->fY) < TOLERANCE) {
        unit->fX = SkScalarSignNonZero(unit->fX);
        unit->fY = 0;
    }
}

<<<<<<< HEAD
void SkFlingState::reset(float sx, float sy)
{
=======
void SkFlingState::reset(float sx, float sy) {
>>>>>>> miniblink49
    fActive = true;
    fDirection.set(sx, sy);
    fSpeed0 = SkPoint::Normalize(&fDirection);
    fSpeed0 = pin_max_fling(fSpeed0);
    fTime0 = getseconds();

    unit_axis_align(&fDirection);
<<<<<<< HEAD
    //    printf("---- speed %g dir %g %g\n", fSpeed0, fDirection.fX, fDirection.fY);
}

bool SkFlingState::evaluateMatrix(SkMatrix* matrix)
{
=======
//    printf("---- speed %g dir %g %g\n", fSpeed0, fDirection.fX, fDirection.fY);
}

bool SkFlingState::evaluateMatrix(SkMatrix* matrix) {
>>>>>>> miniblink49
    if (!fActive) {
        return false;
    }

<<<<<<< HEAD
    const float t = (float)(getseconds() - fTime0);
    const float MIN_SPEED = 2;
    const float K0 = 5;
    const float K1 = 0.02f;
    const float speed = fSpeed0 * (sk_float_exp(-K0 * t) - K1);
=======
    const float t =  (float)(getseconds() - fTime0);
    const float MIN_SPEED = 2;
    const float K0 = 5;
    const float K1 = 0.02f;
    const float speed = fSpeed0 * (sk_float_exp(- K0 * t) - K1);
>>>>>>> miniblink49
    if (speed <= MIN_SPEED) {
        fActive = false;
        return false;
    }
    float dist = (fSpeed0 - speed) / K0;

<<<<<<< HEAD
    //    printf("---- time %g speed %g dist %g\n", t, speed, dist);
=======
//    printf("---- time %g speed %g dist %g\n", t, speed, dist);
>>>>>>> miniblink49
    float tx = fDirection.fX * dist;
    float ty = fDirection.fY * dist;
    if (DISCRETIZE_TRANSLATE_TO_AVOID_FLICKER) {
        tx = (float)sk_float_round2int(tx);
        ty = (float)sk_float_round2int(ty);
    }
    matrix->setTranslate(tx, ty);
<<<<<<< HEAD
    //    printf("---- evaluate (%g %g)\n", tx, ty);
=======
//    printf("---- evaluate (%g %g)\n", tx, ty);
>>>>>>> miniblink49

    return true;
}

///////////////////////////////////////////////////////////////////////////////

static const SkMSec MAX_DBL_TAP_INTERVAL = 300;
static const float MAX_DBL_TAP_DISTANCE = 100;
static const float MAX_JITTER_RADIUS = 2;

// if true, then ignore the touch-move, 'cause its probably just jitter
<<<<<<< HEAD
static bool close_enough_for_jitter(float x0, float y0, float x1, float y1)
{
    return sk_float_abs(x0 - x1) <= MAX_JITTER_RADIUS && sk_float_abs(y0 - y1) <= MAX_JITTER_RADIUS;
=======
static bool close_enough_for_jitter(float x0, float y0, float x1, float y1) {
    return  sk_float_abs(x0 - x1) <= MAX_JITTER_RADIUS &&
            sk_float_abs(y0 - y1) <= MAX_JITTER_RADIUS;
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkTouchGesture::SkTouchGesture()
{
    this->reset();
}

SkTouchGesture::~SkTouchGesture()
{
}

void SkTouchGesture::reset()
{
    fIsTransLimited = false;
=======
SkTouchGesture::SkTouchGesture() {
    this->reset();
}

SkTouchGesture::~SkTouchGesture() {
}

void SkTouchGesture::reset() {
>>>>>>> miniblink49
    fTouches.reset();
    fState = kEmpty_State;
    fLocalM.reset();
    fGlobalM.reset();

<<<<<<< HEAD
    fLastUpMillis = SkTime::GetMSecs() - 2 * MAX_DBL_TAP_INTERVAL;
    fLastUpP.set(0, 0);
}

void SkTouchGesture::flushLocalM()
{
=======
    fLastUpT = SkTime::GetMSecs() - 2*MAX_DBL_TAP_INTERVAL;
    fLastUpP.set(0, 0);
}

void SkTouchGesture::flushLocalM() {
>>>>>>> miniblink49
    fGlobalM.postConcat(fLocalM);
    fLocalM.reset();
}

<<<<<<< HEAD
const SkMatrix& SkTouchGesture::localM()
{
=======
const SkMatrix& SkTouchGesture::localM() {
>>>>>>> miniblink49
    if (fFlinger.isActive()) {
        if (!fFlinger.evaluateMatrix(&fLocalM)) {
            this->flushLocalM();
        }
    }
    return fLocalM;
}

<<<<<<< HEAD
void SkTouchGesture::appendNewRec(void* owner, float x, float y)
{
=======
void SkTouchGesture::appendNewRec(void* owner, float x, float y) {
>>>>>>> miniblink49
    Rec* rec = fTouches.append();
    rec->fOwner = owner;
    rec->fStartX = rec->fPrevX = rec->fLastX = x;
    rec->fStartY = rec->fPrevY = rec->fLastY = y;
<<<<<<< HEAD
    rec->fLastT = rec->fPrevT = static_cast<float>(SkTime::GetSecs());
}

void SkTouchGesture::touchBegin(void* owner, float x, float y)
{
    //    SkDebugf("--- %d touchBegin %p %g %g\n", fTouches.count(), owner, x, y);
=======
    rec->fLastT = rec->fPrevT = SkTime::GetMSecs();
}

void SkTouchGesture::touchBegin(void* owner, float x, float y) {
//    SkDebugf("--- %d touchBegin %p %g %g\n", fTouches.count(), owner, x, y);
>>>>>>> miniblink49

    int index = this->findRec(owner);
    if (index >= 0) {
        this->flushLocalM();
        fTouches.removeShuffle(index);
        SkDebugf("---- already exists, removing\n");
    }

    if (fTouches.count() == 2) {
        return;
    }

    this->flushLocalM();
    fFlinger.stop();

    this->appendNewRec(owner, x, y);

    switch (fTouches.count()) {
<<<<<<< HEAD
    case 1:
        fState = kTranslate_State;
        break;
    case 2:
        fState = kZoom_State;
        break;
    default:
        break;
    }
}

int SkTouchGesture::findRec(void* owner) const
{
=======
        case 1:
            fState = kTranslate_State;
            break;
        case 2:
            fState = kZoom_State;
            break;
        default:
            break;
    }
}

int SkTouchGesture::findRec(void* owner) const {
>>>>>>> miniblink49
    for (int i = 0; i < fTouches.count(); i++) {
        if (owner == fTouches[i].fOwner) {
            return i;
        }
    }
    return -1;
}

<<<<<<< HEAD
static SkScalar center(float pos0, float pos1)
{
=======
static SkScalar center(float pos0, float pos1) {
>>>>>>> miniblink49
    return (pos0 + pos1) * 0.5f;
}

static const float MAX_ZOOM_SCALE = 4;
static const float MIN_ZOOM_SCALE = 0.25f;

<<<<<<< HEAD
float SkTouchGesture::limitTotalZoom(float scale) const
{
=======
float SkTouchGesture::limitTotalZoom(float scale) const {
>>>>>>> miniblink49
    // this query works 'cause we know that we're square-scale w/ no skew/rotation
    const float curr = SkScalarToFloat(fGlobalM[0]);

    if (scale > 1 && curr * scale > MAX_ZOOM_SCALE) {
        scale = MAX_ZOOM_SCALE / curr;
    } else if (scale < 1 && curr * scale < MIN_ZOOM_SCALE) {
        scale = MIN_ZOOM_SCALE / curr;
    }
    return scale;
}

<<<<<<< HEAD
void SkTouchGesture::touchMoved(void* owner, float x, float y)
{
    //    SkDebugf("--- %d touchMoved %p %g %g\n", fTouches.count(), owner, x, y);
=======
void SkTouchGesture::touchMoved(void* owner, float x, float y) {
//    SkDebugf("--- %d touchMoved %p %g %g\n", fTouches.count(), owner, x, y);
>>>>>>> miniblink49

    if (kEmpty_State == fState) {
        return;
    }

    int index = this->findRec(owner);
    if (index < 0) {
        // not found, so I guess we should add it...
        SkDebugf("---- add missing begin\n");
        this->appendNewRec(owner, x, y);
        index = fTouches.count() - 1;
    }

    Rec& rec = fTouches[index];

    // not sure how valuable this is
    if (fTouches.count() == 2) {
        if (close_enough_for_jitter(rec.fLastX, rec.fLastY, x, y)) {
<<<<<<< HEAD
            //            SkDebugf("--- drop touchMove, withing jitter tolerance %g %g\n", rec.fLastX - x, rec.fLastY - y);
=======
//            SkDebugf("--- drop touchMove, withing jitter tolerance %g %g\n", rec.fLastX - x, rec.fLastY - y);
>>>>>>> miniblink49
            return;
        }
    }

<<<<<<< HEAD
    rec.fPrevX = rec.fLastX;
    rec.fLastX = x;
    rec.fPrevY = rec.fLastY;
    rec.fLastY = y;
    rec.fPrevT = rec.fLastT;
    rec.fLastT = static_cast<float>(SkTime::GetSecs());

    switch (fTouches.count()) {
    case 1: {
        float dx = rec.fLastX - rec.fStartX;
        float dy = rec.fLastY - rec.fStartY;
        dx = (float)sk_float_round2int(dx);
        dy = (float)sk_float_round2int(dy);
        fLocalM.setTranslate(dx, dy);
    } break;
    case 2: {
        SkASSERT(kZoom_State == fState);
        const Rec& rec0 = fTouches[0];
        const Rec& rec1 = fTouches[1];

        float scale = this->computePinch(rec0, rec1);
        scale = this->limitTotalZoom(scale);

        fLocalM.setTranslate(-center(rec0.fStartX, rec1.fStartX),
            -center(rec0.fStartY, rec1.fStartY));
        fLocalM.postScale(scale, scale);
        fLocalM.postTranslate(center(rec0.fLastX, rec1.fLastX),
            center(rec0.fLastY, rec1.fLastY));
    } break;
    default:
        break;
    }
}

void SkTouchGesture::touchEnd(void* owner)
{
    //    SkDebugf("--- %d touchEnd   %p\n", fTouches.count(), owner);
=======
    rec.fPrevX = rec.fLastX; rec.fLastX = x;
    rec.fPrevY = rec.fLastY; rec.fLastY = y;
    rec.fPrevT = rec.fLastT; rec.fLastT = SkTime::GetMSecs();

    switch (fTouches.count()) {
        case 1: {
            float dx = rec.fLastX - rec.fStartX;
            float dy = rec.fLastY - rec.fStartY;
            dx = (float)sk_float_round2int(dx);
            dy = (float)sk_float_round2int(dy);
            fLocalM.setTranslate(dx, dy);
        } break;
        case 2: {
            SkASSERT(kZoom_State == fState);
            const Rec& rec0 = fTouches[0];
            const Rec& rec1 = fTouches[1];

            float scale = this->computePinch(rec0, rec1);
            scale = this->limitTotalZoom(scale);

            fLocalM.setTranslate(-center(rec0.fStartX, rec1.fStartX),
                                 -center(rec0.fStartY, rec1.fStartY));
            fLocalM.postScale(scale, scale);
            fLocalM.postTranslate(center(rec0.fLastX, rec1.fLastX),
                                  center(rec0.fLastY, rec1.fLastY));
        } break;
        default:
            break;
    }
}

void SkTouchGesture::touchEnd(void* owner) {
//    SkDebugf("--- %d touchEnd   %p\n", fTouches.count(), owner);
>>>>>>> miniblink49

    int index = this->findRec(owner);
    if (index < 0) {
        SkDebugf("--- not found\n");
        return;
    }

    const Rec& rec = fTouches[index];
    if (this->handleDblTap(rec.fLastX, rec.fLastY)) {
        return;
    }

    // count() reflects the number before we removed the owner
    switch (fTouches.count()) {
<<<<<<< HEAD
    case 1: {
        this->flushLocalM();
        float dx = rec.fLastX - rec.fPrevX;
        float dy = rec.fLastY - rec.fPrevY;
        float dur = rec.fLastT - rec.fPrevT;
        if (dur > 0) {
            fFlinger.reset(dx / dur, dy / dur);
        }
        fState = kEmpty_State;
    } break;
    case 2:
        this->flushLocalM();
        SkASSERT(kZoom_State == fState);
        fState = kEmpty_State;
        break;
    default:
        SkASSERT(kZoom_State == fState);
        break;
    }

    fTouches.removeShuffle(index);

    limitTrans();
}

float SkTouchGesture::computePinch(const Rec& rec0, const Rec& rec1)
{
    double dx = rec0.fStartX - rec1.fStartX;
    double dy = rec0.fStartY - rec1.fStartY;
    double dist0 = sqrt(dx * dx + dy * dy);

    dx = rec0.fLastX - rec1.fLastX;
    dy = rec0.fLastY - rec1.fLastY;
    double dist1 = sqrt(dx * dx + dy * dy);
=======
        case 1: {
            this->flushLocalM();
            float dx = rec.fLastX - rec.fPrevX;
            float dy = rec.fLastY - rec.fPrevY;
            float dur = (rec.fLastT - rec.fPrevT) * 0.001f;
            if (dur > 0) {
                fFlinger.reset(dx / dur, dy / dur);
            }
            fState = kEmpty_State;
        } break;
        case 2:
            this->flushLocalM();
            SkASSERT(kZoom_State == fState);
            fState = kEmpty_State;
            break;
        default:
            SkASSERT(kZoom_State == fState);
            break;
    }

    fTouches.removeShuffle(index);
}

float SkTouchGesture::computePinch(const Rec& rec0, const Rec& rec1) {
    double dx = rec0.fStartX - rec1.fStartX;
    double dy = rec0.fStartY - rec1.fStartY;
    double dist0 = sqrt(dx*dx + dy*dy);

    dx = rec0.fLastX - rec1.fLastX;
    dy = rec0.fLastY - rec1.fLastY;
    double dist1 = sqrt(dx*dx + dy*dy);
>>>>>>> miniblink49

    double scale = dist1 / dist0;
    return (float)scale;
}

<<<<<<< HEAD
bool SkTouchGesture::handleDblTap(float x, float y)
{
    bool found = false;
    double now = SkTime::GetMSecs();
    if (now - fLastUpMillis <= MAX_DBL_TAP_INTERVAL) {
        if (SkPoint::Length(fLastUpP.fX - x,
                fLastUpP.fY - y)
            <= MAX_DBL_TAP_DISTANCE) {
=======
bool SkTouchGesture::handleDblTap(float x, float y) {
    bool found = false;
    SkMSec now = SkTime::GetMSecs();
    if (now - fLastUpT <= MAX_DBL_TAP_INTERVAL) {
        if (SkPoint::Length(fLastUpP.fX - x,
                            fLastUpP.fY - y) <= MAX_DBL_TAP_DISTANCE) {
>>>>>>> miniblink49
            fFlinger.stop();
            fLocalM.reset();
            fGlobalM.reset();
            fTouches.reset();
            fState = kEmpty_State;
            found = true;
        }
    }

<<<<<<< HEAD
    fLastUpMillis = now;
    fLastUpP.set(x, y);
    return found;
}

void SkTouchGesture::setTransLimit(const SkRect& contentRect, const SkRect& windowRect)
{
    fIsTransLimited = true;
    fContentRect = contentRect;
    fWindowRect = windowRect;
}

void SkTouchGesture::limitTrans()
{
    if (!fIsTransLimited) {
        return;
    }

    SkRect scaledContent = fContentRect;
    fGlobalM.mapRect(&scaledContent);
    const SkScalar ZERO = 0;

    fGlobalM.postTranslate(ZERO, std::min(ZERO, fWindowRect.fBottom - scaledContent.fTop));
    fGlobalM.postTranslate(ZERO, std::max(ZERO, fWindowRect.fTop - scaledContent.fBottom));
    fGlobalM.postTranslate(std::min(ZERO, fWindowRect.fRight - scaledContent.fLeft), ZERO);
    fGlobalM.postTranslate(std::max(ZERO, fWindowRect.fLeft - scaledContent.fRight), ZERO);
}
=======
    fLastUpT = now;
    fLastUpP.set(x, y);
    return found;
}
>>>>>>> miniblink49
