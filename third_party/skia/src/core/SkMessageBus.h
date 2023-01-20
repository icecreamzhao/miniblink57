/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkMessageBus_DEFINED
#define SkMessageBus_DEFINED

<<<<<<< HEAD
#include "SkMutex.h"
#include "SkOnce.h"
=======
#include "SkLazyPtr.h"
#include "SkMutex.h"
>>>>>>> miniblink49
#include "SkTArray.h"
#include "SkTDArray.h"
#include "SkTypes.h"

template <typename Message>
class SkMessageBus : SkNoncopyable {
public:
    // Post a message to be received by all Inboxes for this Message type.  Threadsafe.
    static void Post(const Message& m);

    class Inbox {
    public:
        Inbox();
        ~Inbox();

        // Overwrite out with all the messages we've received since the last call.  Threadsafe.
        void poll(SkTArray<Message>* out);

    private:
<<<<<<< HEAD
        SkTArray<Message> fMessages;
        SkMutex fMessagesMutex;

        friend class SkMessageBus;
        void receive(const Message& m); // SkMessageBus is a friend only to call this.
=======
        SkTArray<Message>  fMessages;
        SkMutex            fMessagesMutex;

        friend class SkMessageBus;
        void receive(const Message& m);  // SkMessageBus is a friend only to call this.
>>>>>>> miniblink49
    };

private:
    SkMessageBus();
    static SkMessageBus* Get();

<<<<<<< HEAD
    SkTDArray<Inbox*> fInboxes;
    SkMutex fInboxesMutex;
=======
    // Allow SkLazyPtr to call SkMessageBus::SkMessageBus().
    template <typename T> friend T* Private::sk_new();

    SkTDArray<Inbox*> fInboxes;
    SkMutex           fInboxesMutex;
>>>>>>> miniblink49
};

// This must go in a single .cpp file, not some .h, or we risk creating more than one global
// SkMessageBus per type when using shared libraries.  NOTE: at most one per file will compile.
<<<<<<< HEAD
#define DECLARE_SKMESSAGEBUS_MESSAGE(Message)            \
    template <>                                          \
    SkMessageBus<Message>* SkMessageBus<Message>::Get()  \
    {                                                    \
        static SkOnce once;                              \
        static SkMessageBus<Message>* bus;               \
        once([] { bus = new SkMessageBus<Message>(); }); \
        return bus;                                      \
=======
#define DECLARE_SKMESSAGEBUS_MESSAGE(Message)               \
    SK_DECLARE_STATIC_LAZY_PTR(SkMessageBus<Message>, bus); \
    template <>                                             \
    SkMessageBus<Message>* SkMessageBus<Message>::Get() {   \
        return bus.get();                                   \
>>>>>>> miniblink49
    }

//   ----------------------- Implementation of SkMessageBus::Inbox -----------------------

<<<<<<< HEAD
template <typename Message>
SkMessageBus<Message>::Inbox::Inbox()
{
=======
template<typename Message>
SkMessageBus<Message>::Inbox::Inbox() {
>>>>>>> miniblink49
    // Register ourselves with the corresponding message bus.
    SkMessageBus<Message>* bus = SkMessageBus<Message>::Get();
    SkAutoMutexAcquire lock(bus->fInboxesMutex);
    bus->fInboxes.push(this);
}

<<<<<<< HEAD
template <typename Message>
SkMessageBus<Message>::Inbox::~Inbox()
{
=======
template<typename Message>
SkMessageBus<Message>::Inbox::~Inbox() {
>>>>>>> miniblink49
    // Remove ourselves from the corresponding message bus.
    SkMessageBus<Message>* bus = SkMessageBus<Message>::Get();
    SkAutoMutexAcquire lock(bus->fInboxesMutex);
    // This is a cheaper fInboxes.remove(fInboxes.find(this)) when order doesn't matter.
    for (int i = 0; i < bus->fInboxes.count(); i++) {
        if (this == bus->fInboxes[i]) {
            bus->fInboxes.removeShuffle(i);
            break;
        }
    }
}

<<<<<<< HEAD
template <typename Message>
void SkMessageBus<Message>::Inbox::receive(const Message& m)
{
=======
template<typename Message>
void SkMessageBus<Message>::Inbox::receive(const Message& m) {
>>>>>>> miniblink49
    SkAutoMutexAcquire lock(fMessagesMutex);
    fMessages.push_back(m);
}

<<<<<<< HEAD
template <typename Message>
void SkMessageBus<Message>::Inbox::poll(SkTArray<Message>* messages)
{
=======
template<typename Message>
void SkMessageBus<Message>::Inbox::poll(SkTArray<Message>* messages) {
>>>>>>> miniblink49
    SkASSERT(messages);
    messages->reset();
    SkAutoMutexAcquire lock(fMessagesMutex);
    fMessages.swap(messages);
}

//   ----------------------- Implementation of SkMessageBus -----------------------

template <typename Message>
<<<<<<< HEAD
SkMessageBus<Message>::SkMessageBus() { }

template <typename Message>
/*static*/ void SkMessageBus<Message>::Post(const Message& m)
{
=======
SkMessageBus<Message>::SkMessageBus() {}

template <typename Message>
/*static*/ void SkMessageBus<Message>::Post(const Message& m) {
>>>>>>> miniblink49
    SkMessageBus<Message>* bus = SkMessageBus<Message>::Get();
    SkAutoMutexAcquire lock(bus->fInboxesMutex);
    for (int i = 0; i < bus->fInboxes.count(); i++) {
        bus->fInboxes[i]->receive(m);
    }
}

<<<<<<< HEAD
#endif // SkMessageBus_DEFINED
=======
#endif  // SkMessageBus_DEFINED
>>>>>>> miniblink49
