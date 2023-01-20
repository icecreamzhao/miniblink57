
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkAnimator.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkDisplayApply.h"
#include "SkDisplayMovie.h"
#include "SkDisplayTypes.h"
#include "SkDisplayXMLParser.h"
<<<<<<< HEAD
#include "SkScript.h"
#include "SkScript2.h" //   compiled script experiment
#include "SkStream.h"
=======
#include "SkStream.h"
#include "SkScript.h"
#include "SkScript2.h" //   compiled script experiment
>>>>>>> miniblink49
#include "SkSystemEventTypes.h"
#include "SkTypedArray.h"
#ifdef SK_BUILD_FOR_ANDROID
#include "SkDrawExtraPathEffect.h"
#endif
#ifdef SK_DEBUG
#include "SkTime.h"
#endif

#if defined SK_BUILD_FOR_WIN32 && defined SK_DEBUG
<<<<<<< HEAD
#define _static
extern const char gMathPrimerText[];
extern const char gMathPrimerBinary[];
#else
#define _static static
#endif

_static const char gMathPrimerText[] = "<screenplay>"
                                       "<Math id=\"Math\"/>"
                                       "<Number id=\"Number\"/>"
                                       "</screenplay>";

#define gMathPrimer gMathPrimerText

SkAnimator::SkAnimator()
    : fMaker(nullptr)
{
    initialize();
}

SkAnimator::~SkAnimator() { delete fMaker; }

void SkAnimator::addExtras(SkExtras* extras)
{
    *fMaker->fExtras.append() = extras;
}

bool SkAnimator::appendStream(SkStream* stream)
{
=======
    #define _static
    extern const char gMathPrimerText[];
    extern const char gMathPrimerBinary[];
#else
    #define _static static
#endif

_static const char gMathPrimerText[] =
"<screenplay>"
    "<Math id=\"Math\"/>"
    "<Number id=\"Number\"/>"
"</screenplay>";

#define gMathPrimer gMathPrimerText

SkAnimator::SkAnimator() : fMaker(NULL) {
    initialize();
}

SkAnimator::~SkAnimator() {
    SkDELETE(fMaker);
}

void SkAnimator::addExtras(SkExtras* extras) {
    *fMaker->fExtras.append() = extras;
}

bool SkAnimator::appendStream(SkStream* stream) {
>>>>>>> miniblink49
    return decodeStream(stream);
}

bool SkAnimator::decodeMemory(const void* buffer, size_t size)
{
    fMaker->fFileName.reset();
    SkDisplayXMLParser parser(*fMaker);
    return parser.parse((const char*)buffer, size);
}

bool SkAnimator::decodeStream(SkStream* stream)
{
    SkDisplayXMLParser parser(*fMaker);
    bool result = parser.parse(*stream);
    fMaker->setErrorString();
    return result;
}

bool SkAnimator::decodeDOM(const SkDOM& dom, const SkDOMNode* node)
{
    fMaker->fFileName.reset();
    SkDisplayXMLParser parser(*fMaker);
    return parser.parse(dom, node);
}

<<<<<<< HEAD
bool SkAnimator::decodeURI(const char uri[])
{
    //  SkDebugf("animator decode %s\n", uri);

    //    SkStream* stream = SkStream::GetURIStream(fMaker->fPrefix.c_str(), uri);
=======
bool SkAnimator::decodeURI(const char uri[]) {
//  SkDebugf("animator decode %s\n", uri);

//    SkStream* stream = SkStream::GetURIStream(fMaker->fPrefix.c_str(), uri);
>>>>>>> miniblink49
    SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(uri));
    if (stream.get()) {
        this->setURIBase(uri);
        return decodeStream(stream);
    } else {
        return false;
    }
}

<<<<<<< HEAD
bool SkAnimator::doCharEvent(SkUnichar code)
{
=======
bool SkAnimator::doCharEvent(SkUnichar code) {
>>>>>>> miniblink49
    if (code == 0)
        return false;
    struct SkEventState state;
    state.fCode = code;
    fMaker->fEnableTime = fMaker->getAppTime();
    bool result = fMaker->fEvents.doEvent(*fMaker, SkDisplayEvent::kKeyChar, &state);
    fMaker->notifyInval();
    return result;
}

<<<<<<< HEAD
bool SkAnimator::doClickEvent(int clickState, SkScalar x, SkScalar y)
{
=======
bool SkAnimator::doClickEvent(int clickState, SkScalar x, SkScalar y) {
>>>>>>> miniblink49
    SkASSERT(clickState >= 0 && clickState <= 2);
    struct SkEventState state;
    state.fX = x;
    state.fY = y;
    fMaker->fEnableTime = fMaker->getAppTime();
    bool result = fMaker->fEvents.doEvent(*fMaker,
<<<<<<< HEAD
        clickState == 0 ? SkDisplayEvent::kMouseDown : clickState == 1 ? SkDisplayEvent::kMouseDrag : SkDisplayEvent::kMouseUp, &state);
=======
        clickState == 0 ? SkDisplayEvent::kMouseDown :
        clickState == 1 ? SkDisplayEvent::kMouseDrag :
        SkDisplayEvent::kMouseUp, &state);
>>>>>>> miniblink49
    fMaker->notifyInval();
    return result;
}

<<<<<<< HEAD
bool SkAnimator::doKeyEvent(SkKey code)
{
=======
bool SkAnimator::doKeyEvent(SkKey code) {
>>>>>>> miniblink49
    if (code == 0)
        return false;
    struct SkEventState state;
    state.fCode = code;
    fMaker->fEnableTime = fMaker->getAppTime();
    bool result = fMaker->fEvents.doEvent(*fMaker, SkDisplayEvent::kKeyPress, &state);
    fMaker->notifyInval();
    return result;
}

<<<<<<< HEAD
bool SkAnimator::doKeyUpEvent(SkKey code)
{
=======
bool SkAnimator::doKeyUpEvent(SkKey code) {
>>>>>>> miniblink49
    if (code == 0)
        return false;
    struct SkEventState state;
    state.fCode = code;
    fMaker->fEnableTime = fMaker->getAppTime();
    bool result = fMaker->fEvents.doEvent(*fMaker, SkDisplayEvent::kKeyPressUp, &state);
    fMaker->notifyInval();
    return result;
}

<<<<<<< HEAD
bool SkAnimator::doUserEvent(const SkEvent& evt)
{
=======
bool SkAnimator::doUserEvent(const SkEvent& evt) {
>>>>>>> miniblink49
    fMaker->fEnableTime = fMaker->getAppTime();
    return onEvent(evt);
}

<<<<<<< HEAD
SkAnimator::DifferenceType SkAnimator::draw(SkCanvas* canvas, SkPaint* paint, SkMSec time)
{
    if (paint == nullptr)
=======
SkAnimator::DifferenceType SkAnimator::draw(SkCanvas* canvas, SkPaint* paint, SkMSec time) {
    if (paint == NULL)
>>>>>>> miniblink49
        return draw(canvas, time);
    fMaker->fScreenplay.time = time;
    fMaker->fCanvas = canvas;
    fMaker->fPaint = paint;
    fMaker->fDisplayList.fHasUnion = false;
    int result = fMaker->fDisplayList.draw(*fMaker, time);
    if (result)
        result += fMaker->fDisplayList.fHasUnion;
<<<<<<< HEAD
    return (DifferenceType)result;
}

SkAnimator::DifferenceType SkAnimator::draw(SkCanvas* canvas, SkMSec time)
{
=======
    return (DifferenceType) result;
}

SkAnimator::DifferenceType SkAnimator::draw(SkCanvas* canvas, SkMSec time) {
>>>>>>> miniblink49
    SkPaint paint;
    return draw(canvas, &paint, time);
}

#ifdef SK_DEBUG
<<<<<<< HEAD
void SkAnimator::eventDone(const SkEvent&)
{
}
#endif

bool SkAnimator::findClickEvent(SkScalar x, SkScalar y)
{
=======
void SkAnimator::eventDone(const SkEvent& ) {
}
#endif

bool SkAnimator::findClickEvent(SkScalar x, SkScalar y) {
>>>>>>> miniblink49
    struct SkEventState state;
    state.fDisable = true;
    state.fX = x;
    state.fY = y;
    fMaker->fEnableTime = fMaker->getAppTime();
    bool result = fMaker->fEvents.doEvent(*fMaker, SkDisplayEvent::kMouseDown, &state);
    fMaker->notifyInval();
    return result;
}

<<<<<<< HEAD
const SkAnimator* SkAnimator::getAnimator(const SkDisplayable* displayable) const
{
    if (displayable->getType() != SkType_Movie)
        return nullptr;
    const SkDisplayMovie* movie = (const SkDisplayMovie*)displayable;
    return movie->getAnimator();
}

const SkDisplayable* SkAnimator::getElement(const char* id)
{
    SkDisplayable* element;
    if (fMaker->find(id, &element) == false)
        return nullptr;
    return (const SkDisplayable*)element;
}

SkElementType SkAnimator::getElementType(const SkDisplayable* ae)
{
    SkDisplayable* element = (SkDisplayable*)ae;
    const SkMemberInfo* info = SkDisplayType::GetMembers(fMaker, element->getType(), nullptr);
    return (SkElementType)SkDisplayType::Find(fMaker, info);
}

SkElementType SkAnimator::getElementType(const char* id)
{
=======
const SkAnimator* SkAnimator::getAnimator(const SkDisplayable* displayable) const {
    if (displayable->getType() != SkType_Movie)
        return NULL;
    const SkDisplayMovie* movie = (const SkDisplayMovie*) displayable;
    return movie->getAnimator();
}

const SkDisplayable* SkAnimator::getElement(const char* id) {
    SkDisplayable* element;
    if (fMaker->find(id, &element) == false)
        return NULL;
    return (const SkDisplayable*) element;
}

SkElementType SkAnimator::getElementType(const SkDisplayable* ae) {
    SkDisplayable* element = (SkDisplayable*) ae;
    const SkMemberInfo* info = SkDisplayType::GetMembers(fMaker, element->getType(), NULL);
    return (SkElementType) SkDisplayType::Find(fMaker, info);
}

SkElementType SkAnimator::getElementType(const char* id) {
>>>>>>> miniblink49
    const SkDisplayable* element = getElement(id);
    return getElementType(element);
}

<<<<<<< HEAD
const SkMemberInfo* SkAnimator::getField(const SkDisplayable* ae, const char* field)
{
    SkDisplayable* element = (SkDisplayable*)ae;
    const SkMemberInfo* info = element->getMember(field);
    return (const SkMemberInfo*)info;
}

const SkMemberInfo* SkAnimator::getField(const char* elementID, const char* field)
{
=======
const SkMemberInfo* SkAnimator::getField(const SkDisplayable* ae, const char* field) {
    SkDisplayable* element = (SkDisplayable*) ae;
    const SkMemberInfo* info = element->getMember(field);
    return (const SkMemberInfo*) info;
}

const SkMemberInfo* SkAnimator::getField(const char* elementID, const char* field) {
>>>>>>> miniblink49
    const SkDisplayable* element = getElement(elementID);
    return getField(element, field);
}

<<<<<<< HEAD
SkFieldType SkAnimator::getFieldType(const SkMemberInfo* ai)
{
    const SkMemberInfo* info = (const SkMemberInfo*)ai;
    return (SkFieldType)info->getType();
}

SkFieldType SkAnimator::getFieldType(const char* id, const char* fieldID)
{
=======
SkFieldType SkAnimator::getFieldType(const SkMemberInfo* ai) {
    const SkMemberInfo* info = (const SkMemberInfo*) ai;
    return (SkFieldType) info->getType();
}

SkFieldType SkAnimator::getFieldType(const char* id, const char* fieldID) {
>>>>>>> miniblink49
    const SkMemberInfo* field = getField(id, fieldID);
    return getFieldType(field);
}

static bool getArrayCommon(const SkDisplayable* ae, const SkMemberInfo* ai,
<<<<<<< HEAD
    int index, SkOperand* operand)
{
    const SkDisplayable* element = (const SkDisplayable*)ae;
    const SkMemberInfo* info = (const SkMemberInfo*)ai;
=======
                           int index, SkOperand* operand) {
    const SkDisplayable* element = (const SkDisplayable*) ae;
    const SkMemberInfo* info = (const SkMemberInfo*) ai;
>>>>>>> miniblink49
    SkASSERT(info->fType == SkType_Array);
    return info->getArrayValue(element, index, operand);
}

int32_t SkAnimator::getArrayInt(const SkDisplayable* ae,
<<<<<<< HEAD
    const SkMemberInfo* ai, int index)
{
=======
        const SkMemberInfo* ai, int index) {
>>>>>>> miniblink49
    SkOperand operand;
    bool result = getArrayCommon(ae, ai, index, &operand);
    return result ? operand.fS32 : SK_NaN32;
}

<<<<<<< HEAD
int32_t SkAnimator::getArrayInt(const char* id, const char* fieldID, int index)
{
    const SkDisplayable* element = getElement(id);
    if (element == nullptr)
        return SK_NaN32;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
int32_t SkAnimator::getArrayInt(const char* id, const char* fieldID, int index) {
    const SkDisplayable* element = getElement(id);
    if (element == NULL)
        return SK_NaN32;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return SK_NaN32;
    return getArrayInt(element, field, index);
}

SkScalar SkAnimator::getArrayScalar(const SkDisplayable* ae,
<<<<<<< HEAD
    const SkMemberInfo* ai, int index)
{
=======
        const SkMemberInfo* ai, int index) {
>>>>>>> miniblink49
    SkOperand operand;
    bool result = getArrayCommon(ae, ai, index, &operand);
    return result ? operand.fScalar : SK_ScalarNaN;
}

<<<<<<< HEAD
SkScalar SkAnimator::getArrayScalar(const char* id, const char* fieldID, int index)
{
    const SkDisplayable* element = getElement(id);
    if (element == nullptr)
        return SK_ScalarNaN;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
SkScalar SkAnimator::getArrayScalar(const char* id, const char* fieldID, int index) {
    const SkDisplayable* element = getElement(id);
    if (element == NULL)
        return SK_ScalarNaN;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return SK_ScalarNaN;
    return getArrayScalar(element, field, index);
}

const char* SkAnimator::getArrayString(const SkDisplayable* ae,
<<<<<<< HEAD
    const SkMemberInfo* ai, int index)
{
    SkOperand operand;
    bool result = getArrayCommon(ae, ai, index, &operand);
    return result ? operand.fString->c_str() : nullptr;
}

const char* SkAnimator::getArrayString(const char* id, const char* fieldID, int index)
{
    const SkDisplayable* element = getElement(id);
    if (element == nullptr)
        return nullptr;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
        return nullptr;
    return getArrayString(element, field, index);
}

SkMSec SkAnimator::getInterval()
{
    return fMaker->fMinimumInterval == (SkMSec)-1 ? 0 : fMaker->fMinimumInterval;
}

void SkAnimator::getInvalBounds(SkRect* inval)
{
=======
        const SkMemberInfo* ai, int index) {
    SkOperand operand;
    bool result = getArrayCommon(ae, ai, index, &operand);
    return result ? operand.fString->c_str() : NULL;
}

const char* SkAnimator::getArrayString(const char* id, const char* fieldID, int index) {
    const SkDisplayable* element = getElement(id);
    if (element == NULL)
        return NULL;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
        return NULL;
    return getArrayString(element, field, index);
}

SkMSec SkAnimator::getInterval() {
    return fMaker->fMinimumInterval == (SkMSec) -1 ? 0 : fMaker->fMinimumInterval;
}

void SkAnimator::getInvalBounds(SkRect* inval) {
>>>>>>> miniblink49
    if (fMaker->fDisplayList.fHasUnion) {
        inval->fLeft = SkIntToScalar(fMaker->fDisplayList.fInvalBounds.fLeft);
        inval->fTop = SkIntToScalar(fMaker->fDisplayList.fInvalBounds.fTop);
        inval->fRight = SkIntToScalar(fMaker->fDisplayList.fInvalBounds.fRight);
        inval->fBottom = SkIntToScalar(fMaker->fDisplayList.fInvalBounds.fBottom);
    } else {
        inval->fLeft = inval->fTop = -SK_ScalarMax;
        inval->fRight = inval->fBottom = SK_ScalarMax;
    }
}

<<<<<<< HEAD
const SkXMLParserError* SkAnimator::getParserError()
{
    return &fMaker->fError;
}

const char* SkAnimator::getParserErrorString()
{
=======
const SkXMLParserError* SkAnimator::getParserError() {
    return &fMaker->fError;
}

const char* SkAnimator::getParserErrorString() {
>>>>>>> miniblink49
    if (fMaker->fErrorString.size() == 0 && fMaker->fError.hasError())
        fMaker->setErrorString();
    return fMaker->fErrorString.c_str();
}

<<<<<<< HEAD
int32_t SkAnimator::getInt(const SkDisplayable* element, const SkMemberInfo* info)
{
=======
int32_t SkAnimator::getInt(const SkDisplayable* element, const SkMemberInfo* info) {
>>>>>>> miniblink49
    if (info->fType != SkType_MemberProperty) {
        SkOperand operand;
        if (info->getType() == SkType_Int) {
            info->getValue(element, &operand, 1);
            return operand.fS32;
        }
        return SK_NaN32;
    }
    SkScriptValue scriptValue;
    bool success = element->getProperty(info->propertyIndex(), &scriptValue);
    if (success && scriptValue.fType == SkType_Int)
        return scriptValue.fOperand.fS32;
    return SK_NaN32;
}

<<<<<<< HEAD
int32_t SkAnimator::getInt(const char* id, const char* fieldID)
{
    const SkDisplayable* element = getElement(id);
    if (element == nullptr)
        return SK_NaN32;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
int32_t SkAnimator::getInt(const char* id, const char* fieldID) {
    const SkDisplayable* element = getElement(id);
    if (element == NULL)
        return SK_NaN32;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return SK_NaN32;
    return getInt(element, field);
}

<<<<<<< HEAD
SkScalar SkAnimator::getScalar(const SkDisplayable* element, const SkMemberInfo* info)
{
=======
SkScalar SkAnimator::getScalar(const SkDisplayable* element, const SkMemberInfo* info) {
>>>>>>> miniblink49
    if (info->fType != SkType_MemberProperty) {
        SkOperand operand;
        if (info->getType() == SkType_Float) {
            info->getValue(element, &operand, 1);
            return operand.fScalar;
        }
        return SK_ScalarNaN;
    }
    SkScriptValue scriptValue;
    bool success = element->getProperty(info->propertyIndex(), &scriptValue);
    if (success && scriptValue.fType == SkType_Float)
        return scriptValue.fOperand.fScalar;
    return SK_ScalarNaN;
}

<<<<<<< HEAD
SkScalar SkAnimator::getScalar(const char* id, const char* fieldID)
{
    const SkDisplayable* element = getElement(id);
    if (element == nullptr)
        return SK_ScalarNaN;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
SkScalar SkAnimator::getScalar(const char* id, const char* fieldID) {
    const SkDisplayable* element = getElement(id);
    if (element == NULL)
        return SK_ScalarNaN;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return SK_ScalarNaN;
    return getScalar(element, field);
}

const char* SkAnimator::getString(const SkDisplayable* ae,
<<<<<<< HEAD
    const SkMemberInfo* ai)
{
    const SkDisplayable* element = (const SkDisplayable*)ae;
    const SkMemberInfo* info = (const SkMemberInfo*)ai;
=======
        const SkMemberInfo* ai) {
    const SkDisplayable* element = (const SkDisplayable*) ae;
    const SkMemberInfo* info = (const SkMemberInfo*) ai;
>>>>>>> miniblink49
    SkString* temp;
    info->getString(element, &temp);
    return temp->c_str();
}

<<<<<<< HEAD
const char* SkAnimator::getString(const char* id, const char* fieldID)
{
    const SkDisplayable* element = getElement(id);
    if (element == nullptr)
        return nullptr;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
        return nullptr;
    return getString(element, field);
}

const char* SkAnimator::getURIBase()
{
    return fMaker->fPrefix.c_str();
}

void SkAnimator::initialize()
{
    delete fMaker;
    fMaker = new SkAnimateMaker(this, nullptr, nullptr);
    decodeMemory(gMathPrimer, sizeof(gMathPrimer) - 1);
=======
const char* SkAnimator::getString(const char* id, const char* fieldID) {
    const SkDisplayable* element = getElement(id);
    if (element == NULL)
        return NULL;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
        return NULL;
    return getString(element, field);
}

const char* SkAnimator::getURIBase() {
    return fMaker->fPrefix.c_str();
}

void SkAnimator::initialize() {
    SkDELETE(fMaker);
    fMaker = SkNEW_ARGS(SkAnimateMaker, (this, NULL, NULL));
    decodeMemory(gMathPrimer, sizeof(gMathPrimer)-1);
>>>>>>> miniblink49
#ifdef SK_BUILD_FOR_ANDROID
    InitializeSkExtraPathEffects(this);
#endif
}

<<<<<<< HEAD
#ifdef SK_DEBUG
bool SkAnimator::isTrackingEvents()
{
=======

#ifdef SK_DEBUG
bool SkAnimator::isTrackingEvents() {
>>>>>>> miniblink49
    return false;
}
#endif

<<<<<<< HEAD
bool SkAnimator::onEvent(const SkEvent& evt)
{
#ifdef SK_DEBUG
    SkAnimator* root = fMaker->getRoot();
    if (root == nullptr)
=======
bool SkAnimator::onEvent(const SkEvent& evt) {
#ifdef SK_DEBUG
    SkAnimator* root = fMaker->getRoot();
    if (root == NULL)
>>>>>>> miniblink49
        root = this;
    if (root->isTrackingEvents())
        root->eventDone(evt);
#endif
    if (evt.isType(SK_EventType_OnEnd)) {
        SkEventState eventState;
<<<<<<< HEAD
        SkDEBUGCODE(bool success =) evt.findPtr("anim", (void**)&eventState.fDisplayable);
        SkASSERT(success);
        SkDEBUGCODE(success =) evt.findS32("time", (int32_t*)&fMaker->fEnableTime);
=======
        SkDEBUGCODE(bool success =) evt.findPtr("anim", (void**) &eventState.fDisplayable);
        SkASSERT(success);
        SkDEBUGCODE(success =) evt.findS32("time", (int32_t*) &fMaker->fEnableTime);
>>>>>>> miniblink49
        SkASSERT(success);
        fMaker->fAdjustedStart = fMaker->getAppTime() - fMaker->fEnableTime;
        fMaker->fEvents.doEvent(*fMaker, SkDisplayEvent::kOnEnd, &eventState);
        fMaker->fAdjustedStart = 0;
        goto inval;
    }
    if (evt.isType(SK_EventType_Delay)) {
        fMaker->doDelayedEvent();
        goto inval;
    }
    {
        const char* id = evt.findString("id");
<<<<<<< HEAD
        if (id == nullptr)
=======
        if (id == NULL)
>>>>>>> miniblink49
            return false;
        SkDisplayable** firstMovie = fMaker->fMovies.begin();
        SkDisplayable** endMovie = fMaker->fMovies.end();
        for (SkDisplayable** ptr = firstMovie; ptr < endMovie; ptr++) {
<<<<<<< HEAD
            SkDisplayMovie* movie = (SkDisplayMovie*)*ptr;
=======
            SkDisplayMovie* movie = (SkDisplayMovie*) *ptr;
>>>>>>> miniblink49
            movie->doEvent(evt);
        }
        {
            SkDisplayable* event;
            if (fMaker->find(id, &event) == false)
                return false;
<<<<<<< HEAD
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
=======
    #if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
>>>>>>> miniblink49
            SkString debugOut;
            SkMSec realTime = fMaker->getAppTime();
            debugOut.appendS32(realTime - fMaker->fDebugTimeBase);
            debugOut.append(" onEvent id=");
            debugOut.append(id);
<<<<<<< HEAD
#endif
            SkMSec time = evt.getFast32();
            if (time != 0) {
                SkMSec app = fMaker->getAppTime();
                fMaker->setEnableTime(app, time);
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
=======
    #endif
            SkMSec time = evt.getFast32();
            if (time != 0) {
                SkMSec app  = fMaker->getAppTime();
                fMaker->setEnableTime(app, time);
    #if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
>>>>>>> miniblink49
                debugOut.append(" time=");
                debugOut.appendS32(time - fMaker->fDebugTimeBase);
                debugOut.append(" adjust=");
                debugOut.appendS32(fMaker->fAdjustedStart);
<<<<<<< HEAD
#endif
            }
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
            SkDebugf("%s\n", debugOut.c_str());
#endif
            SkASSERT(event->isEvent());
            SkDisplayEvent* displayEvent = (SkDisplayEvent*)event;
=======
    #endif
            }
    #if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
            SkDebugf("%s\n", debugOut.c_str());
    #endif
            SkASSERT(event->isEvent());
            SkDisplayEvent* displayEvent = (SkDisplayEvent*) event;
>>>>>>> miniblink49
            displayEvent->populateInput(*fMaker, evt);
            displayEvent->enableEvent(*fMaker);
        }
    }
inval:
    fMaker->notifyInval();
    return true;
}

void SkAnimator::onEventPost(SkEvent* evt, SkEventSinkID sinkID)
{
#ifdef SK_DEBUG
    SkAnimator* root = fMaker->getRoot();
    if (root) {
        root->onEventPost(evt, sinkID);
        return;
    }
#else
    SkASSERT(sinkID == this->getSinkID() || this->getHostEventSinkID() == sinkID);
#endif
    evt->setTargetID(sinkID)->post();
}

void SkAnimator::onEventPostTime(SkEvent* evt, SkEventSinkID sinkID, SkMSec time)
{
#ifdef SK_DEBUG
    SkAnimator* root = fMaker->getRoot();
    if (root) {
        root->onEventPostTime(evt, sinkID, time);
        return;
    }
#else
    SkASSERT(sinkID == this->getSinkID() || this->getHostEventSinkID() == sinkID);
#endif
    evt->setTargetID(sinkID)->postTime(time);
}

<<<<<<< HEAD
void SkAnimator::reset()
{
    fMaker->fDisplayList.reset();
}

SkEventSinkID SkAnimator::getHostEventSinkID() const
{
    return fMaker->fHostEventSinkID;
}

void SkAnimator::setHostEventSinkID(SkEventSinkID target)
{
    fMaker->fHostEventSinkID = target;
}

void SkAnimator::onSetHostHandler(Handler)
{
}

void SkAnimator::setJavaOwner(Handler)
{
=======
void SkAnimator::reset() {
    fMaker->fDisplayList.reset();
}

SkEventSinkID SkAnimator::getHostEventSinkID() const {
    return fMaker->fHostEventSinkID;
}

void SkAnimator::setHostEventSinkID(SkEventSinkID target) {
    fMaker->fHostEventSinkID = target;
}

void SkAnimator::onSetHostHandler(Handler ) {
}

void SkAnimator::setJavaOwner(Handler ) {
>>>>>>> miniblink49
}

bool SkAnimator::setArrayString(const char* id, const char* fieldID, const char** array, int num)
{
    SkTypedArray tArray(SkType_String);
    tArray.setCount(num);
    for (int i = 0; i < num; i++) {
        SkOperand op;
        op.fString = new SkString(array[i]);
        tArray[i] = op;
    }
    return setArray(id, fieldID, tArray);
}
bool SkAnimator::setArrayInt(const char* id, const char* fieldID, const int* array, int num)
{
    SkTypedArray tArray(SkType_Int);
    tArray.setCount(num);
    for (int i = 0; i < num; i++) {
        SkOperand op;
        op.fS32 = array[i];
        tArray[i] = op;
    }
    return setArray(id, fieldID, tArray);
}

<<<<<<< HEAD
bool SkAnimator::setArray(SkDisplayable* element, const SkMemberInfo* info, SkTypedArray array)
{
    if (info->fType != SkType_Array)
        return false; //the field is not an array
=======
bool SkAnimator::setArray(SkDisplayable* element, const SkMemberInfo* info, SkTypedArray array) {
    if (info->fType != SkType_Array)
        return false;   //the field is not an array
>>>>>>> miniblink49
    //i think we can handle the case where the displayable itself is an array differently from the
    //case where it has an array - for one thing, if it is an array, i think we can change its type
    //if it's not, we cannot
    SkDisplayTypes type = element->getType();
    if (type == SkType_Array) {
<<<<<<< HEAD
        SkDisplayArray* dispArray = (SkDisplayArray*)element;
        dispArray->values = array;
        return true;
    } else
        return false; //currently i don't care about this case
}

bool SkAnimator::setArray(const char* id, const char* fieldID, SkTypedArray array)
{
    SkDisplayable* element = (SkDisplayable*)getElement(id);
    //should I go ahead and change all 'nullptr's to 'nullptr'?
    if (element == nullptr)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
        SkDisplayArray* dispArray = (SkDisplayArray*) element;
        dispArray->values = array;
        return true;
    }
    else
        return false;   //currently i don't care about this case
}

bool SkAnimator::setArray(const char* id, const char* fieldID, SkTypedArray array) {
    SkDisplayable* element = (SkDisplayable*) getElement(id);
    //should I go ahead and change all 'NULL's to 'NULL'?
    if (element == NULL)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return false;
    return setArray(element, field, array);
}

<<<<<<< HEAD
bool SkAnimator::setInt(SkDisplayable* element, const SkMemberInfo* info, int32_t s32)
{
=======
bool SkAnimator::setInt(SkDisplayable* element, const SkMemberInfo* info, int32_t s32) {
>>>>>>> miniblink49
    if (info->fType != SkType_MemberProperty) {
        SkOperand operand;
        operand.fS32 = s32;
        SkASSERT(info->getType() == SkType_Int);
        info->setValue(element, &operand, 1);
    } else {
        SkScriptValue scriptValue;
        scriptValue.fType = SkType_Int;
        scriptValue.fOperand.fS32 = s32;
        element->setProperty(info->propertyIndex(), scriptValue);
    }
    return true;
}

<<<<<<< HEAD
bool SkAnimator::setInt(const char* id, const char* fieldID, int32_t s32)
{
    SkDisplayable* element = (SkDisplayable*)getElement(id);
    if (element == nullptr)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
bool SkAnimator::setInt(const char* id, const char* fieldID, int32_t s32) {
    SkDisplayable* element = (SkDisplayable*) getElement(id);
    if (element == NULL)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return false;
    return setInt(element, field, s32);
}

<<<<<<< HEAD
bool SkAnimator::setScalar(SkDisplayable* element, const SkMemberInfo* info, SkScalar scalar)
{
=======
bool SkAnimator::setScalar(SkDisplayable* element, const SkMemberInfo* info, SkScalar scalar) {
>>>>>>> miniblink49
    if (info->fType != SkType_MemberProperty) {
        SkOperand operand;
        operand.fScalar = scalar;
        SkASSERT(info->getType() == SkType_Float);
        info->setValue(element, &operand, 1);
    } else {
        SkScriptValue scriptValue;
        scriptValue.fType = SkType_Float;
        scriptValue.fOperand.fScalar = scalar;
        element->setProperty(info->propertyIndex(), scriptValue);
    }
    return true;
}

<<<<<<< HEAD
bool SkAnimator::setScalar(const char* id, const char* fieldID, SkScalar scalar)
{
    SkDisplayable* element = (SkDisplayable*)getElement(id);
    if (element == nullptr)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
bool SkAnimator::setScalar(const char* id, const char* fieldID, SkScalar scalar) {
    SkDisplayable* element = (SkDisplayable*) getElement(id);
    if (element == NULL)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return false;
    return setScalar(element, field, scalar);
}

bool SkAnimator::setString(SkDisplayable* element,
<<<<<<< HEAD
    const SkMemberInfo* info, const char* str)
{
    // !!! until this is fixed, can't call script with global references from here
    info->setValue(*fMaker, nullptr, 0, info->fCount, element, info->getType(), str, strlen(str));
    return true;
}

bool SkAnimator::setString(const char* id, const char* fieldID, const char* str)
{
    SkDisplayable* element = (SkDisplayable*)getElement(id);
    if (element == nullptr)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == nullptr)
=======
        const SkMemberInfo* info, const char* str) {
    // !!! until this is fixed, can't call script with global references from here
    info->setValue(*fMaker, NULL, 0, info->fCount, element, info->getType(), str, strlen(str));
    return true;
}

bool SkAnimator::setString(const char* id, const char* fieldID, const char* str) {
    SkDisplayable* element = (SkDisplayable*) getElement(id);
    if (element == NULL)
        return false;
    const SkMemberInfo* field = getField(element, fieldID);
    if (field == NULL)
>>>>>>> miniblink49
        return false;
    return setString(element, field, str);
}

<<<<<<< HEAD
void SkAnimator::setTimeline(const Timeline& timeline)
{
    fMaker->fTimeline = &timeline;
}

void SkAnimator::setURIBase(const char* uri)
{
    if (uri) {
=======
void SkAnimator::setTimeline(const Timeline& timeline) {
    fMaker->fTimeline = &timeline;
}

void SkAnimator::setURIBase(const char* uri) {
    if (uri)
    {
>>>>>>> miniblink49
        const char* tail = strrchr(uri, '/');
        if (tail) {
            SkString prefix(uri, tail - uri + 1);
            if (uri[0] != '.' /*SkStream::IsAbsoluteURI(uri)*/)
                fMaker->fPrefix.reset();
            fMaker->fPrefix.append(prefix);
            fMaker->fFileName.set(tail + 1);
        } else
            fMaker->fFileName.set(uri);
    }
}

#ifdef SK_DEBUG
<<<<<<< HEAD
bool SkAnimator::NoLeaks()
{
#ifdef SK_BUILD_FOR_MAC
    if (SkDisplayable::fAllocations.count() == 0)
        return true;
    //  return SkDisplayable::fAllocationCount == 0;
=======
bool SkAnimator::NoLeaks() {
#ifdef SK_BUILD_FOR_MAC
    if (SkDisplayable::fAllocations.count() == 0)
        return true;
//  return SkDisplayable::fAllocationCount == 0;
>>>>>>> miniblink49
    SkDebugf("!!! leaked %d displayables:\n", SkDisplayable::fAllocations.count());
    for (SkDisplayable** leak = SkDisplayable::fAllocations.begin(); leak < SkDisplayable::fAllocations.end(); leak++)
        SkDebugf("%08x %s\n", *leak, (*leak)->id);
#endif
    return false;
}
#endif

#ifdef SK_SUPPORT_UNITTEST
#include "SkAnimatorScript.h"
#include "SkBase64.h"
<<<<<<< HEAD
#include "SkMemberInfo.h"
#include "SkParse.h"

#define unittestline(type)    \
    {                         \
#type, type::UnitTest \
    }
#endif

#ifdef SK_SUPPORT_UNITTEST
void SkAnimator::Init(bool runUnitTests)
{
=======
#include "SkParse.h"
#include "SkMemberInfo.h"

#define unittestline(type)  { #type , type::UnitTest }
#endif


#ifdef SK_SUPPORT_UNITTEST
void SkAnimator::Init(bool runUnitTests) {
>>>>>>> miniblink49
    if (runUnitTests == false)
        return;
    static const struct {
        const char* fTypeName;
<<<<<<< HEAD
        void (*fUnitTest)();
=======
        void (*fUnitTest)( );
>>>>>>> miniblink49
    } gUnitTests[] = {
        unittestline(SkBase64),
        unittestline(SkDisplayType),
        unittestline(SkParse),
        unittestline(SkScriptEngine),
<<<<<<< HEAD
        //      unittestline(SkScriptEngine2),  // compiled script experiment
        unittestline(SkAnimatorScript)
    };
    for (int i = 0; i < (int)SK_ARRAY_COUNT(gUnitTests); i++) {
=======
//      unittestline(SkScriptEngine2),  // compiled script experiment
        unittestline(SkAnimatorScript)
    };
    for (int i = 0; i < (int)SK_ARRAY_COUNT(gUnitTests); i++)
    {
>>>>>>> miniblink49
        SkDebugf("SkAnimator: Running UnitTest for %s\n", gUnitTests[i].fTypeName);
        gUnitTests[i].fUnitTest();
        SkDebugf("SkAnimator: End UnitTest for %s\n", gUnitTests[i].fTypeName);
    }
}
#else
<<<<<<< HEAD
void SkAnimator::Init(bool)
{
}
#endif

void SkAnimator::Term()
{
=======
void SkAnimator::Init(bool) {}
#endif

void SkAnimator::Term() {
>>>>>>> miniblink49
}
