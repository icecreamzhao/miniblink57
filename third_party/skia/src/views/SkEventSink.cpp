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
=======

>>>>>>> miniblink49
#include "SkEventSink.h"
#include "SkMutex.h"
#include "SkTagList.h"
#include "SkTime.h"

class SkEventSink_Globals {
public:
<<<<<<< HEAD
    SkEventSink_Globals()
    {
        fNextSinkID = 0;
        fSinkHead = nullptr;
    }

    SkMutex fSinkMutex;
    SkEventSinkID fNextSinkID;
    SkEventSink* fSinkHead;
};

static SkEventSink_Globals& getGlobals()
{
=======
    SkEventSink_Globals() {
        fNextSinkID = 0;
        fSinkHead = NULL;
    }

    SkMutex         fSinkMutex;
    SkEventSinkID   fNextSinkID;
    SkEventSink*    fSinkHead;
};

static SkEventSink_Globals& getGlobals() {
>>>>>>> miniblink49
    // leak this, so we don't incur any shutdown perf hit
    static SkEventSink_Globals* gGlobals = new SkEventSink_Globals;
    return *gGlobals;
}

<<<<<<< HEAD
SkEventSink::SkEventSink()
    : fTagHead(nullptr)
{
=======
SkEventSink::SkEventSink() : fTagHead(NULL) {
>>>>>>> miniblink49
    SkEventSink_Globals& globals = getGlobals();

    globals.fSinkMutex.acquire();

    fID = ++globals.fNextSinkID;
    fNextSink = globals.fSinkHead;
    globals.fSinkHead = this;

    globals.fSinkMutex.release();
}

<<<<<<< HEAD
SkEventSink::~SkEventSink()
{
=======
SkEventSink::~SkEventSink() {
>>>>>>> miniblink49
    SkEventSink_Globals& globals = getGlobals();

    if (fTagHead)
        SkTagList::DeleteAll(fTagHead);

    globals.fSinkMutex.acquire();

    SkEventSink* sink = globals.fSinkHead;
<<<<<<< HEAD
    SkEventSink* prev = nullptr;
=======
    SkEventSink* prev = NULL;
>>>>>>> miniblink49

    for (;;) {
        SkEventSink* next = sink->fNextSink;
        if (sink == this) {
            if (prev) {
                prev->fNextSink = next;
            } else {
                globals.fSinkHead = next;
            }
            break;
        }
        prev = sink;
        sink = next;
    }
    globals.fSinkMutex.release();
}

<<<<<<< HEAD
bool SkEventSink::doEvent(const SkEvent& evt)
{
    return this->onEvent(evt);
}

bool SkEventSink::doQuery(SkEvent* evt)
{
=======
bool SkEventSink::doEvent(const SkEvent& evt) {
    return this->onEvent(evt);
}

bool SkEventSink::doQuery(SkEvent* evt) {
>>>>>>> miniblink49
    SkASSERT(evt);
    return this->onQuery(evt);
}

<<<<<<< HEAD
bool SkEventSink::onEvent(const SkEvent&)
{
    return false;
}

bool SkEventSink::onQuery(SkEvent*)
{
=======
bool SkEventSink::onEvent(const SkEvent&) {
    return false;
}

bool SkEventSink::onQuery(SkEvent*) {
>>>>>>> miniblink49
    return false;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkTagList* SkEventSink::findTagList(U8CPU tag) const
{
    return fTagHead ? SkTagList::Find(fTagHead, tag) : nullptr;
}

void SkEventSink::addTagList(SkTagList* rec)
{
    SkASSERT(rec);
    SkASSERT(fTagHead == nullptr || SkTagList::Find(fTagHead, rec->fTag) == nullptr);
=======
SkTagList* SkEventSink::findTagList(U8CPU tag) const {
    return fTagHead ? SkTagList::Find(fTagHead, tag) : NULL;
}

void SkEventSink::addTagList(SkTagList* rec) {
    SkASSERT(rec);
    SkASSERT(fTagHead == NULL || SkTagList::Find(fTagHead, rec->fTag) == NULL);
>>>>>>> miniblink49

    rec->fNext = fTagHead;
    fTagHead = rec;
}

<<<<<<< HEAD
void SkEventSink::removeTagList(U8CPU tag)
{
=======
void SkEventSink::removeTagList(U8CPU tag) {
>>>>>>> miniblink49
    if (fTagHead) {
        SkTagList::DeleteTag(&fTagHead, tag);
    }
}

///////////////////////////////////////////////////////////////////////////////

struct SkListenersTagList : SkTagList {
<<<<<<< HEAD
    SkListenersTagList(U16CPU count)
        : SkTagList(kListeners_SkTagList)
=======
    SkListenersTagList(U16CPU count) : SkTagList(kListeners_SkTagList)
>>>>>>> miniblink49
    {
        fExtra16 = SkToU16(count);
        fIDs = (SkEventSinkID*)sk_malloc_throw(count * sizeof(SkEventSinkID));
    }
    virtual ~SkListenersTagList()
    {
        sk_free(fIDs);
    }

    int countListners() const { return fExtra16; }

    int find(SkEventSinkID id) const
    {
        const SkEventSinkID* idptr = fIDs;
        for (int i = fExtra16 - 1; i >= 0; --i)
            if (idptr[i] == id)
                return i;
        return -1;
    }

<<<<<<< HEAD
    SkEventSinkID* fIDs;
=======
    SkEventSinkID*  fIDs;
>>>>>>> miniblink49
};

void SkEventSink::addListenerID(SkEventSinkID id)
{
    if (id == 0)
        return;

    SkListenersTagList* prev = (SkListenersTagList*)this->findTagList(kListeners_SkTagList);
<<<<<<< HEAD
    int count = 0;

    if (prev) {
=======
    int                 count = 0;

    if (prev)
    {
>>>>>>> miniblink49
        if (prev->find(id) >= 0)
            return;
        count = prev->countListners();
    }

<<<<<<< HEAD
    SkListenersTagList* next = new SkListenersTagList(count + 1);

    if (prev) {
=======
    SkListenersTagList* next = SkNEW_ARGS(SkListenersTagList, (count + 1));

    if (prev)
    {
>>>>>>> miniblink49
        memcpy(next->fIDs, prev->fIDs, count * sizeof(SkEventSinkID));
        this->removeTagList(kListeners_SkTagList);
    }
    next->fIDs[count] = id;
    this->addTagList(next);
}

void SkEventSink::copyListeners(const SkEventSink& sink)
{
    SkListenersTagList* sinkList = (SkListenersTagList*)sink.findTagList(kListeners_SkTagList);
<<<<<<< HEAD
    if (sinkList == nullptr)
=======
    if (sinkList == NULL)
>>>>>>> miniblink49
        return;
    SkASSERT(sinkList->countListners() > 0);
    const SkEventSinkID* iter = sinkList->fIDs;
    const SkEventSinkID* stop = iter + sinkList->countListners();
    while (iter < stop)
        addListenerID(*iter++);
}

void SkEventSink::removeListenerID(SkEventSinkID id)
{
    if (id == 0)
        return;

    SkListenersTagList* list = (SkListenersTagList*)this->findTagList(kListeners_SkTagList);

<<<<<<< HEAD
    if (list == nullptr)
        return;

    int index = list->find(id);
    if (index >= 0) {
=======
    if (list == NULL)
        return;

    int index = list->find(id);
    if (index >= 0)
    {
>>>>>>> miniblink49
        int count = list->countListners();
        SkASSERT(count > 0);
        if (count == 1)
            this->removeTagList(kListeners_SkTagList);
<<<<<<< HEAD
        else {
=======
        else
        {
>>>>>>> miniblink49
            // overwrite without resize/reallocating our struct (for speed)
            list->fIDs[index] = list->fIDs[count - 1];
            list->fExtra16 = SkToU16(count - 1);
        }
    }
}

bool SkEventSink::hasListeners() const
{
<<<<<<< HEAD
    return this->findTagList(kListeners_SkTagList) != nullptr;
}

void SkEventSink::postToListeners(const SkEvent& evt, SkMSec delay)
{
=======
    return this->findTagList(kListeners_SkTagList) != NULL;
}

void SkEventSink::postToListeners(const SkEvent& evt, SkMSec delay) {
>>>>>>> miniblink49
    SkListenersTagList* list = (SkListenersTagList*)this->findTagList(kListeners_SkTagList);
    if (list) {
        SkASSERT(list->countListners() > 0);
        const SkEventSinkID* iter = list->fIDs;
        const SkEventSinkID* stop = iter + list->countListners();
        while (iter < stop) {
<<<<<<< HEAD
            SkEvent* copy = new SkEvent(evt);
=======
            SkEvent* copy = SkNEW_ARGS(SkEvent, (evt));
>>>>>>> miniblink49
            copy->setTargetID(*iter++)->postDelay(delay);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkEventSink::EventResult SkEventSink::DoEvent(const SkEvent& evt)
{
=======
SkEventSink::EventResult SkEventSink::DoEvent(const SkEvent& evt) {
>>>>>>> miniblink49
    SkEvent::Proc proc = evt.getTargetProc();
    if (proc) {
        return proc(evt) ? kHandled_EventResult : kNotHandled_EventResult;
    }

    SkEventSink* sink = SkEventSink::FindSink(evt.getTargetID());
    if (sink) {
        return sink->doEvent(evt) ? kHandled_EventResult : kNotHandled_EventResult;
    }

    return kSinkNotFound_EventResult;
}

SkEventSink* SkEventSink::FindSink(SkEventSinkID sinkID)
{
    if (sinkID == 0)
        return 0;

<<<<<<< HEAD
    SkEventSink_Globals& globals = getGlobals();
    SkAutoMutexAcquire ac(globals.fSinkMutex);
    SkEventSink* sink = globals.fSinkHead;

    while (sink) {
=======
    SkEventSink_Globals&    globals = getGlobals();
    SkAutoMutexAcquire      ac(globals.fSinkMutex);
    SkEventSink*            sink = globals.fSinkHead;

    while (sink)
    {
>>>>>>> miniblink49
        if (sink->getSinkID() == sinkID)
            return sink;
        sink = sink->fNextSink;
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#if 0 // experimental, not tested
=======
#if 0   // experimental, not tested
>>>>>>> miniblink49

#include "SkMutex.h"
#include "SkTDict.h"

<<<<<<< HEAD
#define kMinStringBufferSize 128
=======
#define kMinStringBufferSize    128
>>>>>>> miniblink49
SK_DECLARE_STATIC_MUTEX(gNamedSinkMutex);
static SkTDict<SkEventSinkID>   gNamedSinkIDs(kMinStringBufferSize);

/** Register a name/id pair with the system. If the name already exists,
    replace its ID with the new id. This pair will persist until UnregisterNamedSink()
    is called.
*/
void SkEventSink::RegisterNamedSinkID(const char name[], SkEventSinkID id)
{
    if (id && name && *name)
    {
        SkAutoMutexAcquire  ac(gNamedSinkMutex);
        gNamedSinkIDs.set(name, id);
    }
}

/** Return the id that matches the specified name (from a previous call to
    RegisterNamedSinkID(). If no match is found, return 0
*/
SkEventSinkID SkEventSink::FindNamedSinkID(const char name[])
{
    SkEventSinkID id = 0;

    if (name && *name)
    {
        SkAutoMutexAcquire  ac(gNamedSinkMutex);
        (void)gNamedSinkIDs.find(name, &id);
    }
    return id;
}

/** Remove all name/id pairs from the system. This is call internally
    on shutdown, to ensure no memory leaks. It should not be called
    before shutdown.
*/
void SkEventSink::RemoveAllNamedSinkIDs()
{
    SkAutoMutexAcquire  ac(gNamedSinkMutex);
    (void)gNamedSinkIDs.reset();
}
#endif
