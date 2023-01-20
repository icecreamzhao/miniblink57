
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkAnimateMaker.h"
#include "SkAnimator.h"
#include "SkAnimatorScript.h"
=======

#include "SkAnimateMaker.h"
#include "SkAnimator.h"
#include "SkAnimatorScript.h"
#include "SkDisplayable.h"
>>>>>>> miniblink49
#include "SkDisplayApply.h"
#include "SkDisplayList.h"
#include "SkDisplayMovie.h"
#include "SkDisplayType.h"
<<<<<<< HEAD
#include "SkDisplayable.h"
=======
>>>>>>> miniblink49
#include "SkExtras.h"
#include "SkMemberInfo.h"
#include "SkStream.h"
#include "SkSystemEventTypes.h"
#include "SkTime.h"

class DefaultTimeline : public SkAnimator::Timeline {
<<<<<<< HEAD
    virtual SkMSec getMSecs() const
    {
        return SkEvent::GetMSecsSinceStartup();
=======
    virtual SkMSec getMSecs() const {
        return SkTime::GetMSecs();
>>>>>>> miniblink49
    }
} gDefaultTimeline;

SkAnimateMaker::SkAnimateMaker(SkAnimator* animator, SkCanvas* canvas, SkPaint* paint)
<<<<<<< HEAD
    : fActiveEvent(nullptr)
    , fAdjustedStart(0)
    , fCanvas(canvas)
    , fEnableTime(0)
    , fHostEventSinkID(0)
    , fMinimumInterval((SkMSec)-1)
    , fPaint(paint)
    , fParentMaker(nullptr)
    , fTimeline(&gDefaultTimeline)
    , fInInclude(false)
    , fInMovie(false)
    , fFirstScriptError(false)
    , fLoaded(false)
    , fIDs(256)
    , fAnimator(animator)
{
    fScreenplay.time = 0;
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
    fDebugTimeBase = (SkMSec)-1;
=======
    : fActiveEvent(NULL), fAdjustedStart(0), fCanvas(canvas), fEnableTime(0),
        fHostEventSinkID(0), fMinimumInterval((SkMSec) -1), fPaint(paint), fParentMaker(NULL),
        fTimeline(&gDefaultTimeline), fInInclude(false), fInMovie(false),
        fFirstScriptError(false), fLoaded(false), fIDs(256), fAnimator(animator)
{
    fScreenplay.time = 0;
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
    fDebugTimeBase = (SkMSec) -1;
>>>>>>> miniblink49
#endif
#ifdef SK_DUMP_ENABLED
    fDumpEvents = fDumpGConditions = fDumpPosts = false;
#endif
}

<<<<<<< HEAD
SkAnimateMaker::~SkAnimateMaker()
{
=======
SkAnimateMaker::~SkAnimateMaker() {
>>>>>>> miniblink49
    deleteMembers();
}

#if 0
SkMSec SkAnimateMaker::adjustDelay(SkMSec expectedBase, SkMSec delay) {
    SkMSec appTime = (*fTimeCallBack)();
    if (appTime)
        delay -= appTime - expectedBase;
    if (delay < 0)
        delay = 0;
    return delay;
}
#endif

<<<<<<< HEAD
void SkAnimateMaker::appendActive(SkActive* active)
{
    fDisplayList.append(active);
}

void SkAnimateMaker::clearExtraPropertyCallBack(SkDisplayTypes type)
{
=======
void SkAnimateMaker::appendActive(SkActive* active) {
    fDisplayList.append(active);
}

void SkAnimateMaker::clearExtraPropertyCallBack(SkDisplayTypes type) {
>>>>>>> miniblink49
    SkExtras** end = fExtras.end();
    for (SkExtras** extraPtr = fExtras.begin(); extraPtr < end; extraPtr++) {
        SkExtras* extra = *extraPtr;
        if (extra->definesType(type)) {
<<<<<<< HEAD
            extra->fExtraCallBack = nullptr;
            extra->fExtraStorage = nullptr;
=======
            extra->fExtraCallBack = NULL;
            extra->fExtraStorage = NULL;
>>>>>>> miniblink49
            break;
        }
    }
}

<<<<<<< HEAD
bool SkAnimateMaker::computeID(SkDisplayable* displayable, SkDisplayable* parent, SkString* newID)
{
    const char* script;
    if (findKey(displayable, &script) == false)
=======
bool SkAnimateMaker::computeID(SkDisplayable* displayable, SkDisplayable* parent, SkString* newID) {
    const char* script;
  if (findKey(displayable, &script) == false)
>>>>>>> miniblink49
        return true;
    return SkAnimatorScript::EvaluateString(*this, displayable, parent, script, newID);
}

<<<<<<< HEAD
SkDisplayable* SkAnimateMaker::createInstance(const char name[], size_t len)
{
    SkDisplayTypes type = SkDisplayType::GetType(this, name, len);
    if ((int)type >= 0)
        return SkDisplayType::CreateInstance(this, type);
    return nullptr;
=======
SkDisplayable* SkAnimateMaker::createInstance(const char name[], size_t len) {
    SkDisplayTypes type = SkDisplayType::GetType(this, name, len );
    if ((int)type >= 0)
        return SkDisplayType::CreateInstance(this, type);
    return NULL;
>>>>>>> miniblink49
}

// differs from SkAnimator::decodeStream in that it does not reset error state
bool SkAnimateMaker::decodeStream(SkStream* stream)
{
    SkDisplayXMLParser parser(*this);
    return parser.parse(*stream);
}

// differs from SkAnimator::decodeURI in that it does not set URI base
<<<<<<< HEAD
bool SkAnimateMaker::decodeURI(const char uri[])
{
    //  SkDebugf("animator decode %s\n", uri);

    //    SkStream* stream = SkStream::GetURIStream(fPrefix.c_str(), uri);
=======
bool SkAnimateMaker::decodeURI(const char uri[]) {
//  SkDebugf("animator decode %s\n", uri);

//    SkStream* stream = SkStream::GetURIStream(fPrefix.c_str(), uri);
>>>>>>> miniblink49
    SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(uri));
    if (stream.get()) {
        bool success = decodeStream(stream);
        if (hasError() && fError.hasNoun() == false)
            fError.setNoun(uri);
        return success;
    } else {
        return false;
    }
}

#if defined SK_DEBUG && 0
//used for the if'd out section of deleteMembers
#include "SkTSearch.h"

extern "C" {
<<<<<<< HEAD
int compare_disp(const void* a, const void* b)
{
    return *(const SkDisplayable**)a - *(const SkDisplayable**)b;
}
}
#endif

void SkAnimateMaker::delayEnable(SkApply* apply, SkMSec time)
{
=======
    int compare_disp(const void* a, const void* b) {
        return *(const SkDisplayable**)a - *(const SkDisplayable**)b;
    }
}
#endif

void SkAnimateMaker::delayEnable(SkApply* apply, SkMSec time) {
>>>>>>> miniblink49
    int index = fDelayed.find(apply);
    if (index < 0) {
        *fDelayed.append() = apply;
    }

    (new SkEvent(SK_EventType_Delay, fAnimator->getSinkID()))->postTime(time);
}

<<<<<<< HEAD
void SkAnimateMaker::deleteMembers()
{
=======
void SkAnimateMaker::deleteMembers() {
>>>>>>> miniblink49
    int index;
#if defined SK_DEBUG && 0
    //this code checks to see if helpers are among the children, but it is not complete -
    //it should check the children of the children
    int result;
    SkTDArray<SkDisplayable*> children(fChildren.begin(), fChildren.count());
<<<<<<< HEAD
    SkQSort(children.begin(), children.count(), sizeof(SkDisplayable*), compare_disp);
=======
    SkQSort(children.begin(), children.count(), sizeof(SkDisplayable*),compare_disp);
>>>>>>> miniblink49
    for (index = 0; index < fHelpers.count(); index++) {
        SkDisplayable* helper = fHelpers[index];
        result = SkTSearch(children.begin(), children.count(), helper, sizeof(SkDisplayable*));
        SkASSERT(result < 0);
    }
#endif
    for (index = 0; index < fChildren.count(); index++) {
        SkDisplayable* child = fChildren[index];
        delete child;
    }
    for (index = 0; index < fHelpers.count(); index++) {
        SkDisplayable* helper = fHelpers[index];
        delete helper;
    }
    for (index = 0; index < fExtras.count(); index++) {
        SkExtras* extras = fExtras[index];
        delete extras;
    }
}

<<<<<<< HEAD
void SkAnimateMaker::doDelayedEvent()
{
    fEnableTime = getAppTime();
    for (int index = 0; index < fDelayed.count();) {
        SkDisplayable* child = fDelayed[index];
        SkASSERT(child->isApply());
        SkApply* apply = (SkApply*)child;
=======
void SkAnimateMaker::doDelayedEvent() {
    fEnableTime = getAppTime();
    for (int index = 0; index < fDelayed.count(); ) {
        SkDisplayable* child = fDelayed[index];
        SkASSERT(child->isApply());
        SkApply* apply = (SkApply*) child;
>>>>>>> miniblink49
        apply->interpolate(*this, fEnableTime);
        if (apply->hasDelayedAnimator())
            index++;
        else
            fDelayed.remove(index);
    }
}

<<<<<<< HEAD
bool SkAnimateMaker::doEvent(const SkEvent& event)
{
=======
bool SkAnimateMaker::doEvent(const SkEvent& event) {
>>>>>>> miniblink49
    return (!fInMovie || fLoaded) && fAnimator->doEvent(event);
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkAnimateMaker::dump(const char* match)
{
    SkTDict<SkDisplayable*>::Iter iter(fIDs);
    const char* name;
    SkDisplayable* result;
    while ((name = iter.next(&result)) != nullptr) {
        if (strcmp(match, name) == 0)
            result->dump(this);
    }
}
#endif

int SkAnimateMaker::dynamicProperty(SkString& nameStr, SkDisplayable** displayablePtr)
{
=======
void SkAnimateMaker::dump(const char* match) {
        SkTDict<SkDisplayable*>::Iter iter(fIDs);
        const char* name;
        SkDisplayable* result;
        while ((name = iter.next(&result)) != NULL) {
            if (strcmp(match,name) == 0)
                result->dump(this);
        }
}
#endif

int SkAnimateMaker::dynamicProperty(SkString& nameStr, SkDisplayable** displayablePtr ) {
>>>>>>> miniblink49
    const char* name = nameStr.c_str();
    const char* dot = strchr(name, '.');
    SkASSERT(dot);
    SkDisplayable* displayable;
    if (find(name, dot - name, &displayable) == false) {
        SkASSERT(0);
        return 0;
    }
    const char* fieldName = dot + 1;
    const SkMemberInfo* memberInfo = displayable->getMember(fieldName);
    *displayablePtr = displayable;
<<<<<<< HEAD
    return (int)memberInfo->fOffset;
}

SkMSec SkAnimateMaker::getAppTime() const
{
=======
    return (int) memberInfo->fOffset;
}

SkMSec SkAnimateMaker::getAppTime() const {
>>>>>>> miniblink49
    return fTimeline->getMSecs();
}

#ifdef SK_DEBUG
SkAnimator* SkAnimateMaker::getRoot()
{
    SkAnimateMaker* maker = this;
    while (maker->fParentMaker)
        maker = maker->fParentMaker;
<<<<<<< HEAD
    return maker == this ? nullptr : maker->fAnimator;
}
#endif

void SkAnimateMaker::helperAdd(SkDisplayable* trackMe)
{
=======
    return maker == this ? NULL : maker->fAnimator;
}
#endif

void SkAnimateMaker::helperAdd(SkDisplayable* trackMe) {
>>>>>>> miniblink49
    SkASSERT(fHelpers.find(trackMe) < 0);
    *fHelpers.append() = trackMe;
}

<<<<<<< HEAD
void SkAnimateMaker::helperRemove(SkDisplayable* alreadyTracked)
{
=======
void SkAnimateMaker::helperRemove(SkDisplayable* alreadyTracked) {
>>>>>>> miniblink49
    int helperIndex = fHelpers.find(alreadyTracked);
    if (helperIndex >= 0)
        fHelpers.remove(helperIndex);
}

#if 0
void SkAnimateMaker::loadMovies() {
    for (SkDisplayable** dispPtr = fMovies.begin(); dispPtr < fMovies.end(); dispPtr++) {
        SkDisplayable* displayable = *dispPtr;
        SkASSERT(displayable->getType() == SkType_Movie);
        SkDisplayMovie* movie = (SkDisplayMovie*) displayable;
        SkAnimateMaker* movieMaker = movie->fMovie.fMaker;
<<<<<<< HEAD
        movieMaker->fEvents.doEvent(*movieMaker, SkDisplayEvent::kOnload, nullptr);
        movieMaker->fEvents.removeEvent(SkDisplayEvent::kOnload, nullptr);
=======
        movieMaker->fEvents.doEvent(*movieMaker, SkDisplayEvent::kOnload, NULL);
        movieMaker->fEvents.removeEvent(SkDisplayEvent::kOnload, NULL);
>>>>>>> miniblink49
        movieMaker->loadMovies();
    }
}
#endif

<<<<<<< HEAD
void SkAnimateMaker::notifyInval()
{
=======
void SkAnimateMaker::notifyInval() {
>>>>>>> miniblink49
    if (fHostEventSinkID)
        fAnimator->onEventPost(new SkEvent(SK_EventType_Inval), fHostEventSinkID);
}

<<<<<<< HEAD
void SkAnimateMaker::notifyInvalTime(SkMSec time)
{
=======
void SkAnimateMaker::notifyInvalTime(SkMSec time) {
>>>>>>> miniblink49
    if (fHostEventSinkID)
        fAnimator->onEventPostTime(new SkEvent(SK_EventType_Inval), fHostEventSinkID, time);
}

<<<<<<< HEAD
void SkAnimateMaker::postOnEnd(SkAnimateBase* animate, SkMSec end)
{
    SkEvent evt;
    evt.setS32("time", animate->getStart() + end);
    evt.setPtr("anim", animate);
    evt.setType(SK_EventType_OnEnd);
    SkEventSinkID sinkID = fAnimator->getSinkID();
    fAnimator->onEventPost(new SkEvent(evt), sinkID);
}

void SkAnimateMaker::reset()
{
=======
void SkAnimateMaker::postOnEnd(SkAnimateBase* animate, SkMSec end) {
        SkEvent evt;
        evt.setS32("time", animate->getStart() + end);
        evt.setPtr("anim", animate);
        evt.setType(SK_EventType_OnEnd);
        SkEventSinkID sinkID = fAnimator->getSinkID();
        fAnimator->onEventPost(new SkEvent(evt), sinkID);
}

void SkAnimateMaker::reset() {
>>>>>>> miniblink49
    deleteMembers();
    fChildren.reset();
    fHelpers.reset();
    fIDs.reset();
    fEvents.reset();
    fDisplayList.hardReset();
}

<<<<<<< HEAD
void SkAnimateMaker::removeActive(SkActive* active)
{
    if (active == nullptr)
=======
void SkAnimateMaker::removeActive(SkActive* active) {
    if (active == NULL)
>>>>>>> miniblink49
        return;
    fDisplayList.remove(active);
}

<<<<<<< HEAD
bool SkAnimateMaker::resolveID(SkDisplayable* displayable, SkDisplayable* original)
{
    SkString newID;
    bool success = computeID(original, nullptr, &newID);
=======
bool SkAnimateMaker::resolveID(SkDisplayable* displayable, SkDisplayable* original) {
    SkString newID;
    bool success = computeID(original, NULL, &newID);
>>>>>>> miniblink49
    if (success)
        setID(displayable, newID);
    return success;
}

<<<<<<< HEAD
void SkAnimateMaker::setErrorString()
{
=======
void SkAnimateMaker::setErrorString() {
>>>>>>> miniblink49
    fErrorString.reset();
    if (fError.hasError()) {
        SkString err;
        if (fFileName.size() > 0)
            fErrorString.set(fFileName.c_str());
        else
            fErrorString.set("screenplay error");
        int line = fError.getLineNumber();
        if (line >= 0) {
            fErrorString.append(", ");
            fErrorString.append("line ");
            fErrorString.appendS32(line);
        }
        fErrorString.append(": ");
        fError.getErrorString(&err);
        fErrorString.append(err);
#if defined SK_DEBUG
        SkDebugf("%s\n", fErrorString.c_str());
#endif
    }
}

<<<<<<< HEAD
void SkAnimateMaker::setEnableTime(SkMSec appTime, SkMSec expectedTime)
{
=======
void SkAnimateMaker::setEnableTime(SkMSec appTime, SkMSec expectedTime) {
>>>>>>> miniblink49
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
    SkString debugOut;
    SkMSec time = getAppTime();
    debugOut.appendS32(time - fDebugTimeBase);
    debugOut.append(" set enable old enable=");
    debugOut.appendS32(fEnableTime - fDebugTimeBase);
    debugOut.append(" old adjust=");
    debugOut.appendS32(fAdjustedStart);
    debugOut.append(" new enable=");
    debugOut.appendS32(expectedTime - fDebugTimeBase);
    debugOut.append(" new adjust=");
    debugOut.appendS32(appTime - expectedTime);
    SkDebugf("%s\n", debugOut.c_str());
#endif
    fAdjustedStart = appTime - expectedTime;
    fEnableTime = expectedTime;
    SkDisplayable** firstMovie = fMovies.begin();
    SkDisplayable** endMovie = fMovies.end();
    for (SkDisplayable** ptr = firstMovie; ptr < endMovie; ptr++) {
<<<<<<< HEAD
        SkDisplayMovie* movie = (SkDisplayMovie*)*ptr;
=======
        SkDisplayMovie* movie = (SkDisplayMovie*) *ptr;
>>>>>>> miniblink49
        movie->fMovie.fMaker->setEnableTime(appTime, expectedTime);
    }
}

void SkAnimateMaker::setExtraPropertyCallBack(SkDisplayTypes type,
<<<<<<< HEAD
    SkScriptEngine::_propertyCallBack callBack, void* userStorage)
{
=======
        SkScriptEngine::_propertyCallBack callBack, void* userStorage) {
>>>>>>> miniblink49
    SkExtras** end = fExtras.end();
    for (SkExtras** extraPtr = fExtras.begin(); extraPtr < end; extraPtr++) {
        SkExtras* extra = *extraPtr;
        if (extra->definesType(type)) {
            extra->fExtraCallBack = callBack;
            extra->fExtraStorage = userStorage;
            break;
        }
    }
}

<<<<<<< HEAD
void SkAnimateMaker::setID(SkDisplayable* displayable, const SkString& newID)
{
=======
void SkAnimateMaker::setID(SkDisplayable* displayable, const SkString& newID) {
>>>>>>> miniblink49
    fIDs.set(newID.c_str(), displayable);
#ifdef SK_DEBUG
    displayable->_id.set(newID);
    displayable->id = displayable->_id.c_str();
#endif
}

<<<<<<< HEAD
void SkAnimateMaker::setScriptError(const SkScriptEngine& engine)
{
=======
void SkAnimateMaker::setScriptError(const SkScriptEngine& engine) {
>>>>>>> miniblink49
    SkString errorString;
#ifdef SK_DEBUG
    engine.getErrorString(&errorString);
#endif
    setErrorNoun(errorString);
    setErrorCode(SkDisplayXMLParserError::kErrorInScript);
}

<<<<<<< HEAD
bool SkAnimateMaker::GetStep(const char* token, size_t len, void* stepPtr, SkScriptValue* value)
{
    if (SK_LITERAL_STR_EQUAL("step", token, len)) {
        value->fOperand.fS32 = *(int32_t*)stepPtr;
=======
bool SkAnimateMaker::GetStep(const char* token, size_t len, void* stepPtr, SkScriptValue* value) {
    if (SK_LITERAL_STR_EQUAL("step", token, len)) {
        value->fOperand.fS32 = *(int32_t*) stepPtr;
>>>>>>> miniblink49
        value->fType = SkType_Int;
        return true;
    }
    return false;
}
