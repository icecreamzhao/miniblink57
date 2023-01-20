
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkAnimateActive.h"
#include "SkAnimateBase.h"
#include "SkAnimateMaker.h"
#include "SkAnimateSet.h"
#include "SkDrawGroup.h"
#ifdef SK_DEBUG
#include "SkTime.h"
#endif

// SkActive holds array of interpolators

<<<<<<< HEAD
SkActive::SkActive(SkApply& apply, SkAnimateMaker& maker)
    : fApply(apply)
    , fMaxTime(0)
    , fMaker(maker)
    , fDrawIndex(0)
    , fDrawMax(0)
{
=======
SkActive::SkActive(SkApply& apply, SkAnimateMaker& maker) : fApply(apply),
    fMaxTime(0), fMaker(maker), fDrawIndex(0), fDrawMax(0) {
>>>>>>> miniblink49
}

void SkActive::init()
{
    fAnimators = fApply.fAnimators;
    int animators = fAnimators.count();
    fInterpolators.setCount(animators);
    memset(fInterpolators.begin(), 0, animators * sizeof(SkOperandInterpolator*));
    fState.setCount(animators);
    int index;
    for (index = 0; index < animators; index++)
<<<<<<< HEAD
        fInterpolators[index] = new SkOperandInterpolator;
    initState(&fApply, 0);
    //  for (index = 0; index < animators; index++)
    //      fState[index].bumpSave();
    SkASSERT(fInterpolators.count() == fAnimators.count());
}

SkActive::~SkActive()
{
=======
        fInterpolators[index] = SkNEW(SkOperandInterpolator);
    initState(&fApply, 0);
//  for (index = 0; index < animators; index++)
//      fState[index].bumpSave();
    SkASSERT(fInterpolators.count() == fAnimators.count());
}

SkActive::~SkActive() {
>>>>>>> miniblink49
    int index;
    for (index = 0; index < fSaveRestore.count(); index++)
        delete[] fSaveRestore[index];
    for (index = 0; index < fSaveInterpolators.count(); index++)
        delete[] fSaveInterpolators[index];
    for (index = 0; index < fInterpolators.count(); index++)
        delete fInterpolators[index];
}

<<<<<<< HEAD
void SkActive::advance()
{
=======
void SkActive::advance() {
>>>>>>> miniblink49
    if (fDrawMax < fDrawIndex)
        fDrawMax = fDrawIndex;
    fDrawIndex += fAnimators.count();
}

<<<<<<< HEAD
void SkActive::append(SkApply* apply)
{
=======
void SkActive::append(SkApply* apply) {
>>>>>>> miniblink49
    int oldCount = fAnimators.count();
    SkTDAnimateArray& animates = apply->fAnimators;
    int newCount = animates.count();
    int index;
    int total = oldCount + newCount;
    if (total == 0)
        return;
    fInterpolators.setCount(total);
    memset(&fInterpolators.begin()[oldCount], 0, newCount * sizeof(SkOperandInterpolator*));
    for (index = oldCount; index < total; index++)
<<<<<<< HEAD
        fInterpolators[index] = new SkOperandInterpolator;
    fAnimators.setCount(total);
    memcpy(&fAnimators[oldCount], animates.begin(), sizeof(fAnimators[0]) * newCount);
=======
        fInterpolators[index] = SkNEW(SkOperandInterpolator);
    fAnimators.setCount(total);
    memcpy(&fAnimators[oldCount], animates.begin(), sizeof(fAnimators[0]) *
        newCount);
>>>>>>> miniblink49
    fState.setCount(total);
    initState(apply, oldCount);
    SkASSERT(fApply.scope == apply->scope);
    for (index = 0; index < newCount; index++) {
        SkAnimateBase* test = animates[index];
<<<<<<< HEAD
        //      SkASSERT(fApply.scope == test->fTarget || fApply.scope->contains(test->fTarget));
=======
//      SkASSERT(fApply.scope == test->fTarget || fApply.scope->contains(test->fTarget));
>>>>>>> miniblink49
        SkActive::SkState& testState = fState[oldCount + index];
        for (int inner = 0; inner < oldCount; inner++) {
            SkAnimateBase* oldGuard = fAnimators[inner];
            SkActive::SkState& oldState = fState[inner];
<<<<<<< HEAD
            if (oldGuard->fTarget == test->fTarget && oldGuard->fFieldInfo == test->fFieldInfo && testState.fBegin == oldState.fBegin) {
=======
            if (oldGuard->fTarget == test->fTarget && oldGuard->fFieldInfo == test->fFieldInfo &&
                    testState.fBegin == oldState.fBegin) {
>>>>>>> miniblink49
                delete fInterpolators[inner];
                fInterpolators.remove(inner);
                fAnimators.remove(inner);
                testState.fSave = oldState.fSave;
                if (oldState.fUnpostedEndEvent) {
<<<<<<< HEAD
                    //                  SkDEBUGF(("%8x %8x active append: post on end\n", this, oldGuard));
=======
//                  SkDEBUGF(("%8x %8x active append: post on end\n", this, oldGuard));
>>>>>>> miniblink49
                    fMaker.postOnEnd(oldGuard, oldState.fBegin + oldState.fDuration);
                }
                fState.remove(inner);
                if (fApply.restore) {
                    int saveIndex = fSaveRestore.count();
                    SkASSERT(fSaveInterpolators.count() == saveIndex);
                    saveIndex += inner;
                    do {
                        saveIndex -= oldCount;
                        delete[] fSaveRestore[saveIndex];
                        fSaveRestore.remove(saveIndex);
                        delete[] fSaveInterpolators[saveIndex];
                        fSaveInterpolators.remove(saveIndex);
                    } while (saveIndex > 0);
                }
                oldCount--;
                break;
            }
        }
    }
<<<<<<< HEAD
    //  total = oldCount + newCount;
    //  for (index = oldCount; index < total; index++)
    //      fState[index].bumpSave();
    SkASSERT(fInterpolators.count() == fAnimators.count());
}

void SkActive::appendSave(int oldCount)
{
    SkASSERT(fDrawMax == 0); // if true, we can optimize below quite a bit
=======
//  total = oldCount + newCount;
//  for (index = oldCount; index < total; index++)
//      fState[index].bumpSave();
    SkASSERT(fInterpolators.count() == fAnimators.count());
}

void SkActive::appendSave(int oldCount) {
    SkASSERT(fDrawMax == 0);    // if true, we can optimize below quite a bit
>>>>>>> miniblink49
    int newCount = fAnimators.count();
    int saveIndex = fSaveRestore.count();
    SkASSERT(fSaveInterpolators.count() == saveIndex);
    int records = saveIndex / oldCount;
    int newTotal = records * newCount;
    fSaveRestore.setCount(newTotal);
    do {
        saveIndex -= oldCount;
        newTotal -= newCount;
        SkASSERT(saveIndex >= 0);
        SkASSERT(newTotal >= 0);
        memmove(&fSaveRestore[newTotal], &fSaveRestore[saveIndex], oldCount);
        memset(&fSaveRestore[newTotal + oldCount], 0,
            sizeof(fSaveRestore[0]) * (newCount - oldCount));
        memmove(&fSaveInterpolators[newTotal],
            &fSaveInterpolators[saveIndex], oldCount);
        memset(&fSaveInterpolators[newTotal + oldCount], 0,
            sizeof(fSaveRestore[0]) * (newCount - oldCount));
    } while (saveIndex > 0);
    SkASSERT(newTotal == 0);
}

void SkActive::calcDurations(int index)
{
    SkAnimateBase* animate = fAnimators[index];
    SkMSec duration = animate->dur;
    SkState& state = fState[index];
    switch (state.fMode) {
<<<<<<< HEAD
    case SkApply::kMode_immediate:
    case SkApply::kMode_create:
        duration = state.fSteps ? state.fSteps * SK_MSec1 : 1;
        break;
        //    case SkApply::kMode_hold: {
        //      int entries = animate->entries();
        //      SkScriptValue value;
        //      value.fOperand = animate->getValues()[entries - 1];
        //      value.fType = animate->getValuesType();
        //      bool result = SkScriptEngine::ConvertTo(nullptr, SkType_Int, &value);
        //      SkASSERT(result);
        //      duration = value.fOperand.fS32 * SK_MSec1;
        //      break;
        //    }
=======
      case SkApply::kMode_immediate:
      case SkApply::kMode_create:
        duration = state.fSteps ? state.fSteps * SK_MSec1 : 1;
        break;
//    case SkApply::kMode_hold: {
//      int entries = animate->entries();
//      SkScriptValue value;
//      value.fOperand = animate->getValues()[entries - 1];
//      value.fType = animate->getValuesType();
//      bool result = SkScriptEngine::ConvertTo(NULL, SkType_Int, &value);
//      SkASSERT(result);
//      duration = value.fOperand.fS32 * SK_MSec1;
//      break;
//    }
>>>>>>> miniblink49
    }
    state.fDuration = duration;
    SkMSec maxTime = state.fBegin + duration;
    if (fMaxTime < maxTime)
        fMaxTime = maxTime;
}

<<<<<<< HEAD
void SkActive::create(SkADrawable* drawable, SkMSec time)
{
=======
void SkActive::create(SkADrawable* drawable, SkMSec time) {
>>>>>>> miniblink49
    fApply.fLastTime = time;
    fApply.refresh(fMaker);
    for (int index = 0; index < fAnimators.count(); index++) {
        SkAnimateBase* animate = fAnimators[index];
        SkOperandInterpolator& interpolator = *fInterpolators[index];
        int count = animate->components();
        if (animate->formula.size() > 0) {
            SkTDOperandArray values;
            values.setCount(count);
<<<<<<< HEAD
            SkDEBUGCODE(bool success =) animate->fFieldInfo->setValue(fMaker, &values, 0, 0, nullptr,
=======
            SkDEBUGCODE(bool success = ) animate->fFieldInfo->setValue(fMaker, &values, 0, 0, NULL,
>>>>>>> miniblink49
                animate->getValuesType(), animate->formula);
            SkASSERT(success);
            fApply.applyValues(index, values.begin(), count, animate->getValuesType(), time);
        } else {
            SkAutoSTMalloc<16, SkOperand> values(count);
            interpolator.timeToValues(time, values.get());
            fApply.applyValues(index, values.get(), count, animate->getValuesType(), time);
        }
    }
    drawable->enable(fMaker);
    SkASSERT(fAnimators.count() == fInterpolators.count());
}

<<<<<<< HEAD
bool SkActive::immediate(bool enable)
{
=======
bool SkActive::immediate(bool enable) {
>>>>>>> miniblink49
    SkMSec time = 0;
    bool result = false;
    SkADrawable* drawable = fApply.scope;
    SkMSec final = fMaxTime;
    do {
        bool applied = fAnimators.count() == 0;
        fApply.fLastTime = time;
        fApply.refresh(fMaker);
        for (int index = 0; index < fAnimators.count(); index++) {
            SkAnimateBase* animate = fAnimators[index];
            SkState& state = fState[index];
            if (state.fMode != SkApply::kMode_immediate)
                continue;
            if (state.fBegin > time)
                continue;
            if (time > state.fBegin + state.fDuration)
                continue;
            applied = true;
            SkOperandInterpolator& interpolator = *fInterpolators[index];
            int count = animate->components();
            if (animate->formula.size() > 0) {
                SkTDOperandArray values;
                values.setCount(count);
<<<<<<< HEAD
                SkDEBUGCODE(bool success =) animate->fFieldInfo->setValue(fMaker, &values, 0, 0, nullptr,
=======
                SkDEBUGCODE(bool success = ) animate->fFieldInfo->setValue(fMaker, &values, 0, 0, NULL,
>>>>>>> miniblink49
                    animate->getValuesType(), animate->formula);
                SkASSERT(success);
                fApply.applyValues(index, values.begin(), count, animate->getValuesType(), time);
            } else {
                SkAutoSTMalloc<16, SkOperand> values(count);
                interpolator.timeToValues(time, values.get());
                fApply.applyValues(index, values.get(), count, animate->getValuesType(), time);
            }
        }
        if (enable)
            drawable->enable(fMaker);
        else if (applied)
            result |= drawable->draw(fMaker);
        time += SK_MSec1;
    } while (time <= final);
    return result;
}

<<<<<<< HEAD
void SkActive::fixInterpolator(SkBool save)
{
=======
void SkActive::fixInterpolator(SkBool save) {
>>>>>>> miniblink49
    int animators = fAnimators.count();
    for (int index = 0; index < animators; index++) {
        SkAnimateBase* animate = fAnimators[index];
        if (save) { // saved slots increased
            animate->refresh(fMaker);
            SkOperand* values = animate->getValues();
            setInterpolator(index, values);
            saveInterpolatorValues(index);
        } else
            restoreInterpolatorValues(index);
    }
}

<<<<<<< HEAD
SkMSec SkActive::getTime(SkMSec inTime, int animatorIndex)
{
=======
SkMSec SkActive::getTime(SkMSec inTime, int animatorIndex) {
>>>>>>> miniblink49
    fState[animatorIndex].fTicks = inTime;
    return inTime - fState[animatorIndex].fStartTime;
}

<<<<<<< HEAD
bool SkActive::initializeSave()
{
=======
bool SkActive::initializeSave() {
>>>>>>> miniblink49
    int animators = fAnimators.count();
    int activeTotal = fDrawIndex + animators;
    int oldCount = fSaveRestore.count();
    if (oldCount < activeTotal) {
        fSaveRestore.setCount(activeTotal);
        memset(&fSaveRestore[oldCount], 0, sizeof(fSaveRestore[0]) * (activeTotal - oldCount));
        SkASSERT(fSaveInterpolators.count() == oldCount);
        fSaveInterpolators.setCount(activeTotal);
        memset(&fSaveInterpolators[oldCount], 0,
            sizeof(fSaveInterpolators[0]) * (activeTotal - oldCount));
        return true;
    }
    return false;
}

<<<<<<< HEAD
void SkActive::initState(SkApply* apply, int offset)
{
=======
void SkActive::initState(SkApply* apply, int offset) {
>>>>>>> miniblink49
    int count = fState.count();
    for (int index = offset; index < count; index++) {
        SkState& state = fState[index];
        SkAnimateBase* animate = fAnimators[index];
#if 0 // def SK_DEBUG
        if (animate->fHasEndEvent)
            SkDebugf("%8x %8x active initState:\n", this, animate);
#endif
        SkOperand* from = animate->getValues();
        state.fStartTime = state.fBegin = apply->begin + animate->begin;
        state.fMode = apply->mode;
        state.fTransition = apply->transition;
#if 0
        state.fPickup = (SkBool8) apply->pickup;
#endif
<<<<<<< HEAD
        state.fRestore = (SkBool8)apply->restore;
=======
        state.fRestore = (SkBool8) apply->restore;
>>>>>>> miniblink49
        state.fSave = apply->begin;
        state.fStarted = false;
        state.fSteps = apply->steps;
        state.fTicks = 0;
<<<<<<< HEAD
        state.fUnpostedEndEvent = (SkBool8)animate->fHasEndEvent;
=======
        state.fUnpostedEndEvent = (SkBool8) animate->fHasEndEvent;
>>>>>>> miniblink49
        calcDurations(index);
        setInterpolator(index, from);
    }
    if (count == 0 && (apply->mode == SkApply::kMode_immediate || apply->mode == SkApply::kMode_create))
        fMaxTime = apply->begin + apply->steps * SK_MSec1;
}

<<<<<<< HEAD
void SkActive::pickUp(SkActive* existing)
{
=======
void SkActive::pickUp(SkActive* existing) {
>>>>>>> miniblink49
    SkTDOperandArray existingValues;
    for (int index = 0; index < fAnimators.count(); index++) {
        SkAnimateBase* animate = fAnimators[index];
        SkASSERT(animate->getValuesType() == SkType_Float);
        int components = animate->components();
        SkOperand* from = animate->getValues();
        SkOperand* to = &from[animate->components()];
        existingValues.setCount(components);
        existing->fInterpolators[index]->timeToValues(
            existing->fState[index].fTicks - existing->fState[index].fStartTime, existingValues.begin());
        SkScalar originalSum = 0;
        SkScalar workingSum = 0;
        for (int cIndex = 0; cIndex < components; cIndex++) {
            SkScalar delta = to[cIndex].fScalar - from[cIndex].fScalar;
            originalSum += SkScalarMul(delta, delta);
            delta = to[cIndex].fScalar - existingValues[cIndex].fScalar;
            workingSum += SkScalarMul(delta, delta);
        }
        if (workingSum < originalSum) {
            SkScalar originalDistance = SkScalarSqrt(originalSum);
            SkScalar workingDistance = SkScalarSqrt(workingSum);
<<<<<<< HEAD
            existing->fState[index].fDuration = (SkMSec)SkScalarMulDiv(fState[index].fDuration,
=======
            existing->fState[index].fDuration = (SkMSec) SkScalarMulDiv(fState[index].fDuration,
>>>>>>> miniblink49
                workingDistance, originalDistance);
        }
        fInterpolators[index]->reset(components, 2, SkType_Float);
        fInterpolators[index]->setKeyFrame(0, 0, existingValues.begin(), animate->blend[0]);
        fInterpolators[index]->setKeyFrame(1, fState[index].fDuration, to, animate->blend[0]);
    }
}

<<<<<<< HEAD
void SkActive::resetInterpolators()
{
=======
void SkActive::resetInterpolators() {
>>>>>>> miniblink49
    int animators = fAnimators.count();
    for (int index = 0; index < animators; index++) {
        SkAnimateBase* animate = fAnimators[index];
        SkOperand* values = animate->getValues();
        setInterpolator(index, values);
    }
}

<<<<<<< HEAD
void SkActive::resetState()
{
=======
void SkActive::resetState() {
>>>>>>> miniblink49
    fDrawIndex = 0;
    int count = fState.count();
    for (int index = 0; index < count; index++) {
        SkState& state = fState[index];
        SkAnimateBase* animate = fAnimators[index];
#if 0 // def SK_DEBUG
        if (animate->fHasEndEvent)
            SkDebugf("%8x %8x active resetState: has end event\n", this, animate);
#endif
        state.fStartTime = state.fBegin = fApply.begin + animate->begin;
        state.fStarted = false;
        state.fTicks = 0;
    }
}

<<<<<<< HEAD
void SkActive::restoreInterpolatorValues(int index)
{
    SkOperandInterpolator& interpolator = *fInterpolators[index];
    index += fDrawIndex;
=======
void SkActive::restoreInterpolatorValues(int index) {
    SkOperandInterpolator& interpolator = *fInterpolators[index];
    index += fDrawIndex ;
>>>>>>> miniblink49
    int count = interpolator.getValuesCount();
    memcpy(interpolator.getValues(), fSaveInterpolators[index], count * sizeof(SkOperand));
}

<<<<<<< HEAD
void SkActive::saveInterpolatorValues(int index)
{
    SkOperandInterpolator& interpolator = *fInterpolators[index];
    index += fDrawIndex;
    int count = interpolator.getValuesCount();
    SkOperand* cache = new SkOperand[count]; // this should use sk_malloc/sk_free since SkOperand does not have a constructor/destructor
    fSaveInterpolators[index] = cache;
    memcpy(cache, interpolator.getValues(), count * sizeof(SkOperand));
}

void SkActive::setInterpolator(int index, SkOperand* from)
{
    if (from == nullptr) // legitimate for set string
=======
void SkActive::saveInterpolatorValues(int index) {
    SkOperandInterpolator& interpolator = *fInterpolators[index];
    index += fDrawIndex ;
    int count = interpolator.getValuesCount();
    SkOperand* cache = new SkOperand[count];    // this should use sk_malloc/sk_free since SkOperand does not have a constructor/destructor
    fSaveInterpolators[index] = cache;
    memcpy(cache,   interpolator.getValues(), count * sizeof(SkOperand));
}

void SkActive::setInterpolator(int index, SkOperand* from) {
    if (from == NULL) // legitimate for set string
>>>>>>> miniblink49
        return;
    SkAnimateBase* animate = fAnimators[index];
    int entries = animate->entries();
    SkASSERT(entries > 0);
    SkMSec duration = fState[index].fDuration;
    int components = animate->components();
    SkOperandInterpolator& interpolator = *fInterpolators[index];
    interpolator.reset(components, entries == 1 ? 2 : entries, animate->getValuesType());
    interpolator.setMirror(SkToBool(animate->fMirror));
    interpolator.setReset(SkToBool(animate->fReset));
    interpolator.setRepeatCount(animate->repeat);
    if (entries == 1) {
        interpolator.setKeyFrame(0, 0, from, animate->blend[0]);
        interpolator.setKeyFrame(1, duration, from, animate->blend[0]);
        return;
    }
    for (int entry = 0; entry < entries; entry++) {
        int blendIndex = SkMin32(animate->blend.count() - 1, entry);
        interpolator.setKeyFrame(entry, entry * duration / (entries - 1), from,
            animate->blend[blendIndex]);
        from += components;
    }
}

<<<<<<< HEAD
void SkActive::setSteps(int steps)
{
=======
void SkActive::setSteps(int steps) {
>>>>>>> miniblink49
    int count = fState.count();
    fMaxTime = 0;
    for (int index = 0; index < count; index++) {
        SkState& state = fState[index];
        state.fSteps = steps;
        calcDurations(index);
    }
}

<<<<<<< HEAD
void SkActive::start()
{
=======
void SkActive::start() {
>>>>>>> miniblink49
    int count = fState.count();
    SkASSERT(count == fAnimators.count());
    SkASSERT(count == fInterpolators.count());
    for (int index = 0; index < count; index++) {
        SkState& state = fState[index];
        if (state.fStarted)
            continue;
        state.fStarted = true;
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
        SkString debugOut;
        SkMSec time = fMaker.getAppTime();
        debugOut.appendS32(time - fMaker.fDebugTimeBase);
        debugOut.append(" active start adjust delay id=");
        debugOut.append(fApply._id);
        debugOut.append("; ");
        debugOut.append(fAnimators[index]->_id);
        debugOut.append("=");
        debugOut.appendS32(fAnimators[index]->fStart - fMaker.fDebugTimeBase);
        debugOut.append(":");
        debugOut.appendS32(state.fStartTime);
#endif
        if (state.fStartTime > 0) {
            SkMSec future = fAnimators[index]->fStart + state.fStartTime;
            if (future > fMaker.fEnableTime)
                fMaker.notifyInvalTime(future);
            else
                fMaker.notifyInval();
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
            debugOut.append(":");
            debugOut.appendS32(future - fMaker.fDebugTimeBase);
#endif
        }
        if (state.fStartTime >= fMaker.fAdjustedStart) {
            state.fStartTime -= fMaker.fAdjustedStart;
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
            debugOut.append(" (less adjust = ");
            debugOut.appendS32(fMaker.fAdjustedStart);
#endif
        }
        state.fStartTime += fAnimators[index]->fStart;
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
        debugOut.append(") new start = ");
        debugOut.appendS32(state.fStartTime - fMaker.fDebugTimeBase);
        SkDebugf("%s\n", debugOut.c_str());
//      SkASSERT((int) (state.fStartTime - fMaker.fDebugTimeBase) >= 0);
#endif
    }
    SkASSERT(fAnimators.count() == fInterpolators.count());
}

#ifdef SK_DEBUG
<<<<<<< HEAD
void SkActive::validate()
{
=======
void SkActive::validate() {
>>>>>>> miniblink49
    int count = fState.count();
    SkASSERT(count == fAnimators.count());
    SkASSERT(count == fInterpolators.count());
    for (int index = 0; index < count; index++) {
        SkASSERT(fAnimators[index]);
        SkASSERT(fInterpolators[index]);
<<<<<<< HEAD
        //      SkAnimateBase* test = fAnimators[index];
        //      SkASSERT(fApply.scope == test->fTarget || fApply.scope->contains(test->fTarget));
=======
//      SkAnimateBase* test = fAnimators[index];
//      SkASSERT(fApply.scope == test->fTarget || fApply.scope->contains(test->fTarget));
>>>>>>> miniblink49
    }
}
#endif

// think about this
// there should only be one animate object, not two, to go up and down
// when the apply with reverse came into play, it needs to pick up the value
// of the existing animate object then remove it from the list
// the code below should only be bumping fSave, and there shouldn't be anything
// it needs to be synchronized with

// however, if there are two animates both operating on the same field, then
// when one replaces the other, it may make sense to pick up the old value as a starting
// value for the new one somehow.

//void SkActive::SkState::bumpSave() {
//  if (fMode != SkApply::kMode_hold)
//      return;
//  if (fTransition == SkApply::kTransition_reverse) {
//      if (fSave > 0)
//          fSave -= SK_MSec1;
//  } else if (fSave < fDuration)
//      fSave += SK_MSec1;
//}

<<<<<<< HEAD
SkMSec SkActive::SkState::getRelativeTime(SkMSec time)
{
    SkMSec result = time;
    //  if (fMode == SkApply::kMode_hold)
    //      result = fSave;
    //  else
=======
SkMSec SkActive::SkState::getRelativeTime(SkMSec time) {
    SkMSec result = time;
//  if (fMode == SkApply::kMode_hold)
//      result = fSave;
//  else
>>>>>>> miniblink49
    if (fTransition == SkApply::kTransition_reverse) {
        if (SkMSec_LT(fDuration, time))
            result = 0;
        else
            result = fDuration - time;
    }
    return result;
}
