// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SyncEvent_h
#define SyncEvent_h

#include "modules/EventModules.h"
#include "modules/background_sync/SyncEventInit.h"
<<<<<<< HEAD
=======
#include "modules/background_sync/SyncRegistration.h"
>>>>>>> miniblink49
#include "modules/serviceworkers/ExtendableEvent.h"
#include "platform/heap/Handle.h"
#include "wtf/text/AtomicString.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT SyncEvent final : public ExtendableEvent {
    DEFINE_WRAPPERTYPEINFO();
<<<<<<< HEAD

public:
    static SyncEvent* create(const AtomicString& type,
        const String& tag,
        bool lastChance,
        WaitUntilObserver* observer)
    {
        return new SyncEvent(type, tag, lastChance, observer);
    }
    static SyncEvent* create(const AtomicString& type,
        const SyncEventInit& init)
    {
        return new SyncEvent(type, init);
=======
public:
    static PassRefPtrWillBeRawPtr<SyncEvent> create()
    {
        return adoptRefWillBeNoop(new SyncEvent);
    }
    static PassRefPtrWillBeRawPtr<SyncEvent> create(const AtomicString& type, SyncRegistration* syncRegistration, WaitUntilObserver* observer)
    {
        return adoptRefWillBeNoop(new SyncEvent(type, syncRegistration, observer));
    }
    static PassRefPtrWillBeRawPtr<SyncEvent> create(const AtomicString& type, const SyncEventInit& init)
    {
        return adoptRefWillBeNoop(new SyncEvent(type, init));
>>>>>>> miniblink49
    }

    ~SyncEvent() override;

    const AtomicString& interfaceName() const override;

<<<<<<< HEAD
    String tag();
    bool lastChance();
=======
    SyncRegistration* registration();
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
<<<<<<< HEAD
    SyncEvent(const AtomicString& type, const String&, bool, WaitUntilObserver*);
    SyncEvent(const AtomicString& type, const SyncEventInit&);

    String m_tag;
    bool m_lastChance;
=======
    SyncEvent();
    SyncEvent(const AtomicString& type, SyncRegistration*, WaitUntilObserver*);
    SyncEvent(const AtomicString& type, const SyncEventInit&);

    PersistentWillBeMember<SyncRegistration> m_syncRegistration;
>>>>>>> miniblink49
};

} // namespace blink

#endif // SyncEvent_h
