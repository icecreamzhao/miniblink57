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
#include "SkEvent.h"

void SkEvent::initialize(const char* type, size_t typeLen,
    SkEventSinkID targetID)
{
    fType = nullptr;
    setType(type, typeLen);
    f32 = 0;
    fTargetID = targetID;
    fTargetProc = nullptr;
#ifdef SK_DEBUG
    fTime = 0;
    fNextEvent = nullptr;
=======

#include "SkEvent.h"

void SkEvent::initialize(const char* type, size_t typeLen,
                         SkEventSinkID targetID) {
    fType = NULL;
    setType(type, typeLen);
    f32 = 0;
    fTargetID = targetID;
    fTargetProc = NULL;
#ifdef SK_DEBUG
    fTime = 0;
    fNextEvent = NULL;
>>>>>>> miniblink49
#endif
}

SkEvent::SkEvent()
{
    initialize("", 0, 0);
}

SkEvent::SkEvent(const SkEvent& src)
{
    *this = src;
<<<<<<< HEAD
    if (((size_t)fType & 1) == 0)
=======
    if (((size_t) fType & 1) == 0)
>>>>>>> miniblink49
        setType(src.fType);
}

SkEvent::SkEvent(const SkString& type, SkEventSinkID targetID)
{
    initialize(type.c_str(), type.size(), targetID);
}

SkEvent::SkEvent(const char type[], SkEventSinkID targetID)
{
    SkASSERT(type);
    initialize(type, strlen(type), targetID);
}

SkEvent::~SkEvent()
{
<<<<<<< HEAD
    if (((size_t)fType & 1) == 0)
        sk_free((void*)fType);
=======
    if (((size_t) fType & 1) == 0)
        sk_free((void*) fType);
>>>>>>> miniblink49
}

static size_t makeCharArray(char* buffer, size_t compact)
{
<<<<<<< HEAD
    size_t bits = (size_t)compact >> 1;
=======
    size_t bits = (size_t) compact >> 1;
>>>>>>> miniblink49
    memcpy(buffer, &bits, sizeof(compact));
    buffer[sizeof(compact)] = 0;
    return strlen(buffer);
}

void SkEvent::getType(SkString* str) const
{
<<<<<<< HEAD
    if (str) {
        if ((size_t)fType & 1) // not a pointer
        {
            char chars[sizeof(size_t) + 1];
            size_t len = makeCharArray(chars, (size_t)fType);
            str->set(chars, len);
        } else
=======
    if (str)
    {
        if ((size_t) fType & 1) // not a pointer
        {
            char chars[sizeof(size_t) + 1];
            size_t len = makeCharArray(chars, (size_t) fType);
            str->set(chars, len);
        }
        else
>>>>>>> miniblink49
            str->set(fType);
    }
}

bool SkEvent::isType(const SkString& str) const
{
    return this->isType(str.c_str(), str.size());
}

bool SkEvent::isType(const char type[], size_t typeLen) const
{
    if (typeLen == 0)
        typeLen = strlen(type);
<<<<<<< HEAD
    if ((size_t)fType & 1) { // not a pointer
        char chars[sizeof(size_t) + 1];
        size_t len = makeCharArray(chars, (size_t)fType);
=======
    if ((size_t) fType & 1) {   // not a pointer
        char chars[sizeof(size_t) + 1];
        size_t len = makeCharArray(chars, (size_t) fType);
>>>>>>> miniblink49
        return len == typeLen && strncmp(chars, type, typeLen) == 0;
    }
    return strncmp(fType, type, typeLen) == 0 && fType[typeLen] == 0;
}

void SkEvent::setType(const char type[], size_t typeLen)
{
    if (typeLen == 0)
        typeLen = strlen(type);
    if (typeLen <= sizeof(fType)) {
        size_t slot = 0;
        memcpy(&slot, type, typeLen);
        if (slot << 1 >> 1 != slot)
            goto useCharStar;
        slot <<= 1;
        slot |= 1;
<<<<<<< HEAD
        fType = (char*)slot;
    } else {
    useCharStar:
        fType = (char*)sk_malloc_throw(typeLen + 1);
        SkASSERT(((size_t)fType & 1) == 0);
=======
        fType = (char*) slot;
    } else {
useCharStar:
        fType = (char*) sk_malloc_throw(typeLen + 1);
        SkASSERT(((size_t) fType & 1) == 0);
>>>>>>> miniblink49
        memcpy(fType, type, typeLen);
        fType[typeLen] = 0;
    }
}

void SkEvent::setType(const SkString& type)
{
    setType(type.c_str());
}

////////////////////////////////////////////////////////////////////////////

#include "SkParse.h"

void SkEvent::inflate(const SkDOM& dom, const SkDOM::Node* node)
{
    const char* name = dom.findAttr(node, "type");
    if (name)
        this->setType(name);

    const char* value;
<<<<<<< HEAD
    if ((value = dom.findAttr(node, "fast32")) != nullptr) {
=======
    if ((value = dom.findAttr(node, "fast32")) != NULL)
    {
>>>>>>> miniblink49
        int32_t n;
        if (SkParse::FindS32(value, &n))
            this->setFast32(n);
    }

<<<<<<< HEAD
    for (node = dom.getFirstChild(node); node; node = dom.getNextSibling(node)) {
        if (strcmp(dom.getName(node), "data")) {
            SkDEBUGCODE(SkDebugf("SkEvent::inflate unrecognized subelement <%s>\n", dom.getName(node));) continue;
        }

        name = dom.findAttr(node, "name");
        if (name == nullptr) {
            SkDEBUGCODE(SkDebugf("SkEvent::inflate missing required \"name\" attribute in <data> subelement\n");) continue;
        }

        if ((value = dom.findAttr(node, "s32")) != nullptr) {
            int32_t n;
            if (SkParse::FindS32(value, &n))
                this->setS32(name, n);
        } else if ((value = dom.findAttr(node, "scalar")) != nullptr) {
            SkScalar x;
            if (SkParse::FindScalar(value, &x))
                this->setScalar(name, x);
        } else if ((value = dom.findAttr(node, "string")) != nullptr)
            this->setString(name, value);
#ifdef SK_DEBUG
        else {
=======
    for (node = dom.getFirstChild(node); node; node = dom.getNextSibling(node))
    {
        if (strcmp(dom.getName(node), "data"))
        {
            SkDEBUGCODE(SkDebugf("SkEvent::inflate unrecognized subelement <%s>\n", dom.getName(node));)
            continue;
        }

        name = dom.findAttr(node, "name");
        if (name == NULL)
        {
            SkDEBUGCODE(SkDebugf("SkEvent::inflate missing required \"name\" attribute in <data> subelement\n");)
            continue;
        }

        if ((value = dom.findAttr(node, "s32")) != NULL)
        {
            int32_t n;
            if (SkParse::FindS32(value, &n))
                this->setS32(name, n);
        }
        else if ((value = dom.findAttr(node, "scalar")) != NULL)
        {
            SkScalar x;
            if (SkParse::FindScalar(value, &x))
                this->setScalar(name, x);
        }
        else if ((value = dom.findAttr(node, "string")) != NULL)
            this->setString(name, value);
#ifdef SK_DEBUG
        else
        {
>>>>>>> miniblink49
            SkDebugf("SkEvent::inflate <data name=\"%s\"> subelement missing required type attribute [S32 | scalar | string]\n", name);
        }
#endif
    }
}

#ifdef SK_DEBUG

<<<<<<< HEAD
#ifndef SkScalarToFloat
#define SkScalarToFloat(x) ((x) / 65536.f)
#endif

void SkEvent::dump(const char title[])
{
    if (title)
        SkDebugf("%s ", title);

    SkString etype;
    this->getType(&etype);
    SkDebugf("event<%s> fast32=%d", etype.c_str(), this->getFast32());

    const SkMetaData& md = this->getMetaData();
    SkMetaData::Iter iter(md);
    SkMetaData::Type mtype;
    int count;
    const char* name;

    while ((name = iter.next(&mtype, &count)) != nullptr) {
        SkASSERT(count > 0);

        SkDebugf(" <%s>=", name);
        switch (mtype) {
        case SkMetaData::kS32_Type: // vector version???
        {
            int32_t value;
            md.findS32(name, &value);
            SkDebugf("%d ", value);
        } break;
        case SkMetaData::kScalar_Type: {
            const SkScalar* values = md.findScalars(name, &count, nullptr);
            SkDebugf("%f", SkScalarToFloat(values[0]));
            for (int i = 1; i < count; i++)
                SkDebugf(", %f", SkScalarToFloat(values[i]));
            SkDebugf(" ");
        } break;
        case SkMetaData::kString_Type: {
            const char* value = md.findString(name);
            SkASSERT(value);
            SkDebugf("<%s> ", value);
        } break;
        case SkMetaData::kPtr_Type: // vector version???
        {
            void* value;
            md.findPtr(name, &value);
            SkDebugf("%p ", value);
        } break;
        case SkMetaData::kBool_Type: // vector version???
        {
            bool value;
            md.findBool(name, &value);
            SkDebugf("%s ", value ? "true" : "false");
        } break;
        default:
            SkDEBUGFAIL("unknown metadata type returned from iterator");
            break;
        }
    }
    SkDebugf("\n");
}
=======
    #ifndef SkScalarToFloat
        #define SkScalarToFloat(x)  ((x) / 65536.f)
    #endif

    void SkEvent::dump(const char title[])
    {
        if (title)
            SkDebugf("%s ", title);

        SkString    etype;
        this->getType(&etype);
        SkDebugf("event<%s> fast32=%d", etype.c_str(), this->getFast32());

        const SkMetaData&   md = this->getMetaData();
        SkMetaData::Iter    iter(md);
        SkMetaData::Type    mtype;
        int                 count;
        const char*         name;

        while ((name = iter.next(&mtype, &count)) != NULL)
        {
            SkASSERT(count > 0);

            SkDebugf(" <%s>=", name);
            switch (mtype) {
            case SkMetaData::kS32_Type:     // vector version???
                {
                    int32_t value;
                    md.findS32(name, &value);
                    SkDebugf("%d ", value);
                }
                break;
            case SkMetaData::kScalar_Type:
                {
                    const SkScalar* values = md.findScalars(name, &count, NULL);
                    SkDebugf("%f", SkScalarToFloat(values[0]));
                    for (int i = 1; i < count; i++)
                        SkDebugf(", %f", SkScalarToFloat(values[i]));
                    SkDebugf(" ");
                }
                break;
            case SkMetaData::kString_Type:
                {
                    const char* value = md.findString(name);
                    SkASSERT(value);
                    SkDebugf("<%s> ", value);
                }
                break;
            case SkMetaData::kPtr_Type:     // vector version???
                {
                    void*   value;
                    md.findPtr(name, &value);
                    SkDebugf("%p ", value);
                }
                break;
            case SkMetaData::kBool_Type:    // vector version???
                {
                    bool    value;
                    md.findBool(name, &value);
                    SkDebugf("%s ", value ? "true" : "false");
                }
                break;
            default:
                SkDEBUGFAIL("unknown metadata type returned from iterator");
                break;
            }
        }
        SkDebugf("\n");
    }
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG
// #define SK_TRACE_EVENTSx
#endif

#ifdef SK_TRACE_EVENTS
<<<<<<< HEAD
static void event_log(const char s[])
{
    SkDEBUGF(("%s\n", s));
}

#define EVENT_LOG(s) event_log(s)
#define EVENT_LOGN(s, n)        \
    do {                        \
        SkString str(s);        \
        str.append(" ");        \
        str.appendS32(n);       \
        event_log(str.c_str()); \
    } while (0)
#else
#define EVENT_LOG(s)
#define EVENT_LOGN(s, n)
=======
    static void event_log(const char s[])
    {
        SkDEBUGF(("%s\n", s));
    }

    #define EVENT_LOG(s)        event_log(s)
    #define EVENT_LOGN(s, n)    do { SkString str(s); str.append(" "); str.appendS32(n); event_log(str.c_str()); } while (0)
#else
    #define EVENT_LOG(s)
    #define EVENT_LOGN(s, n)
>>>>>>> miniblink49
#endif

#include "SkMutex.h"
#include "SkTime.h"

class SkEvent_Globals {
public:
<<<<<<< HEAD
    SkEvent_Globals()
    {
        fEventQHead = nullptr;
        fEventQTail = nullptr;
        fDelayQHead = nullptr;
        SkDEBUGCODE(fEventCounter = 0;)
    }

    SkMutex fEventMutex;
    SkEvent *fEventQHead, *fEventQTail;
    SkEvent* fDelayQHead;
    SkDEBUGCODE(int fEventCounter;)
};

static SkEvent_Globals& getGlobals()
{
=======
    SkEvent_Globals() {
        fEventQHead = NULL;
        fEventQTail = NULL;
        fDelayQHead = NULL;
        SkDEBUGCODE(fEventCounter = 0;)
    }

    SkMutex     fEventMutex;
    SkEvent*    fEventQHead, *fEventQTail;
    SkEvent*    fDelayQHead;
    SkDEBUGCODE(int fEventCounter;)
};

static SkEvent_Globals& getGlobals() {
>>>>>>> miniblink49
    // leak this, so we don't incure any shutdown perf hit
    static SkEvent_Globals* gGlobals = new SkEvent_Globals;
    return *gGlobals;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkEvent::postDelay(SkMSec delay)
{
=======
void SkEvent::postDelay(SkMSec delay) {
>>>>>>> miniblink49
    if (!fTargetID && !fTargetProc) {
        delete this;
        return;
    }

    if (delay) {
<<<<<<< HEAD
        this->postTime(GetMSecsSinceStartup() + delay);
=======
        this->postTime(SkTime::GetMSecs() + delay);
>>>>>>> miniblink49
        return;
    }

    SkEvent_Globals& globals = getGlobals();

    globals.fEventMutex.acquire();
    bool wasEmpty = SkEvent::Enqueue(this);
    globals.fEventMutex.release();

    // call outside of us holding the mutex
    if (wasEmpty) {
        SkEvent::SignalNonEmptyQueue();
    }
}

<<<<<<< HEAD
void SkEvent::postTime(SkMSec time)
{
=======
void SkEvent::postTime(SkMSec time) {
>>>>>>> miniblink49
    if (!fTargetID && !fTargetProc) {
        delete this;
        return;
    }

    SkEvent_Globals& globals = getGlobals();

    globals.fEventMutex.acquire();
    SkMSec queueDelay = SkEvent::EnqueueTime(this, time);
    globals.fEventMutex.release();

    // call outside of us holding the mutex
    if ((int32_t)queueDelay != ~0) {
        SkEvent::SignalQueueTimer(queueDelay);
    }
}

<<<<<<< HEAD
bool SkEvent::Enqueue(SkEvent* evt)
{
=======
bool SkEvent::Enqueue(SkEvent* evt) {
>>>>>>> miniblink49
    SkEvent_Globals& globals = getGlobals();
    //  gEventMutex acquired by caller

    SkASSERT(evt);

<<<<<<< HEAD
    bool wasEmpty = globals.fEventQHead == nullptr;
=======
    bool wasEmpty = globals.fEventQHead == NULL;
>>>>>>> miniblink49

    if (globals.fEventQTail)
        globals.fEventQTail->fNextEvent = evt;
    globals.fEventQTail = evt;
<<<<<<< HEAD
    if (globals.fEventQHead == nullptr)
        globals.fEventQHead = evt;
    evt->fNextEvent = nullptr;
=======
    if (globals.fEventQHead == NULL)
        globals.fEventQHead = evt;
    evt->fNextEvent = NULL;
>>>>>>> miniblink49

    SkDEBUGCODE(++globals.fEventCounter);

    return wasEmpty;
}

<<<<<<< HEAD
SkEvent* SkEvent::Dequeue()
{
=======
SkEvent* SkEvent::Dequeue() {
>>>>>>> miniblink49
    SkEvent_Globals& globals = getGlobals();
    globals.fEventMutex.acquire();

    SkEvent* evt = globals.fEventQHead;
    if (evt) {
        SkDEBUGCODE(--globals.fEventCounter);

        globals.fEventQHead = evt->fNextEvent;
<<<<<<< HEAD
        if (globals.fEventQHead == nullptr) {
            globals.fEventQTail = nullptr;
=======
        if (globals.fEventQHead == NULL) {
            globals.fEventQTail = NULL;
>>>>>>> miniblink49
        }
    }
    globals.fEventMutex.release();

    return evt;
}

<<<<<<< HEAD
bool SkEvent::QHasEvents()
{
    SkEvent_Globals& globals = getGlobals();

    // this is not thread accurate, need a semaphore for that
    return globals.fEventQHead != nullptr;
}

#ifdef SK_TRACE_EVENTS
static int gDelayDepth;
#endif

SkMSec SkEvent::EnqueueTime(SkEvent* evt, SkMSec time)
{
=======
bool SkEvent::QHasEvents() {
    SkEvent_Globals& globals = getGlobals();

    // this is not thread accurate, need a semaphore for that
    return globals.fEventQHead != NULL;
}

#ifdef SK_TRACE_EVENTS
    static int gDelayDepth;
#endif

SkMSec SkEvent::EnqueueTime(SkEvent* evt, SkMSec time) {
>>>>>>> miniblink49
    SkEvent_Globals& globals = getGlobals();
    //  gEventMutex acquired by caller

    SkEvent* curr = globals.fDelayQHead;
<<<<<<< HEAD
    SkEvent* prev = nullptr;
=======
    SkEvent* prev = NULL;
>>>>>>> miniblink49

    while (curr) {
        if (SkMSec_LT(time, curr->fTime)) {
            break;
        }
        prev = curr;
        curr = curr->fNextEvent;
    }

    evt->fTime = time;
    evt->fNextEvent = curr;
<<<<<<< HEAD
    if (prev == nullptr) {
=======
    if (prev == NULL) {
>>>>>>> miniblink49
        globals.fDelayQHead = evt;
    } else {
        prev->fNextEvent = evt;
    }

<<<<<<< HEAD
    SkMSec delay = globals.fDelayQHead->fTime - GetMSecsSinceStartup();
=======
    SkMSec delay = globals.fDelayQHead->fTime - SkTime::GetMSecs();
>>>>>>> miniblink49
    if ((int32_t)delay <= 0) {
        delay = 1;
    }
    return delay;
}

///////////////////////////////////////////////////////////////////////////////

#include "SkEventSink.h"

<<<<<<< HEAD
bool SkEvent::ProcessEvent()
{
    SkEvent* evt = SkEvent::Dequeue();
    SkAutoTDelete<SkEvent> autoDelete(evt);
    bool again = false;
=======
bool SkEvent::ProcessEvent() {
    SkEvent*                evt = SkEvent::Dequeue();
    SkAutoTDelete<SkEvent>  autoDelete(evt);
    bool                    again = false;
>>>>>>> miniblink49

    EVENT_LOGN("ProcessEvent", (int32_t)evt);

    if (evt) {
        (void)SkEventSink::DoEvent(*evt);
        again = SkEvent::QHasEvents();
    }
    return again;
}

void SkEvent::ServiceQueueTimer()
{
    SkEvent_Globals& globals = getGlobals();

    globals.fEventMutex.acquire();

<<<<<<< HEAD
    bool wasEmpty = false;
    SkMSec now = GetMSecsSinceStartup();
    SkEvent* evt = globals.fDelayQHead;

    while (evt) {
=======
    bool        wasEmpty = false;
    SkMSec      now = SkTime::GetMSecs();
    SkEvent*    evt = globals.fDelayQHead;

    while (evt)
    {
>>>>>>> miniblink49
        if (SkMSec_LT(now, evt->fTime))
            break;

#ifdef SK_TRACE_EVENTS
        --gDelayDepth;
        SkDebugf("dequeue-delay %s (%d)", evt->getType(), gDelayDepth);
        const char* idStr = evt->findString("id");
        if (idStr)
            SkDebugf(" (%s)", idStr);
        SkDebugf("\n");
#endif

        SkEvent* next = evt->fNextEvent;
        if (SkEvent::Enqueue(evt))
            wasEmpty = true;
        evt = next;
    }
    globals.fDelayQHead = evt;

    SkMSec time = evt ? evt->fTime - now : 0;

    globals.fEventMutex.release();

    if (wasEmpty)
        SkEvent::SignalNonEmptyQueue();

    SkEvent::SignalQueueTimer(time);
}

<<<<<<< HEAD
int SkEvent::CountEventsOnQueue()
{
=======
int SkEvent::CountEventsOnQueue() {
>>>>>>> miniblink49
    SkEvent_Globals& globals = getGlobals();
    globals.fEventMutex.acquire();

    int count = 0;
    const SkEvent* evt = globals.fEventQHead;
    while (evt) {
        count += 1;
        evt = evt->fNextEvent;
    }
    globals.fEventMutex.release();

    return count;
}

<<<<<<< HEAD
SkMSec SkEvent::GetMSecsSinceStartup()
{
    static const double kEpoch = SkTime::GetMSecs();
    return static_cast<SkMSec>(SkTime::GetMSecs() - kEpoch);
}

///////////////////////////////////////////////////////////////////////////////

void SkEvent::Init() { }

void SkEvent::Term()
{
=======
///////////////////////////////////////////////////////////////////////////////

void SkEvent::Init() {}

void SkEvent::Term() {
>>>>>>> miniblink49
    SkEvent_Globals& globals = getGlobals();

    SkEvent* evt = globals.fEventQHead;
    while (evt) {
        SkEvent* next = evt->fNextEvent;
        delete evt;
        evt = next;
    }

    evt = globals.fDelayQHead;
    while (evt) {
        SkEvent* next = evt->fNextEvent;
        delete evt;
        evt = next;
    }
}
