// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/background_sync/SyncEvent.h"

namespace blink {

<<<<<<< HEAD
SyncEvent::SyncEvent(const AtomicString& type,
    const String& tag,
    bool lastChance,
    WaitUntilObserver* observer)
    : ExtendableEvent(type, ExtendableEventInit(), observer)
    , m_tag(tag)
    , m_lastChance(lastChance)
=======
SyncEvent::SyncEvent()
{
}

SyncEvent::SyncEvent(const AtomicString& type, SyncRegistration* syncRegistration, WaitUntilObserver* observer)
    : ExtendableEvent(type, ExtendableEventInit(), observer)
    , m_syncRegistration(syncRegistration)
>>>>>>> miniblink49
{
}

SyncEvent::SyncEvent(const AtomicString& type, const SyncEventInit& init)
    : ExtendableEvent(type, init)
{
<<<<<<< HEAD
    m_tag = init.tag();
    m_lastChance = init.lastChance();
}

SyncEvent::~SyncEvent() { }
=======
    m_syncRegistration = init.registration();
}

SyncEvent::~SyncEvent()
{
}
>>>>>>> miniblink49

const AtomicString& SyncEvent::interfaceName() const
{
    return EventNames::SyncEvent;
}

<<<<<<< HEAD
String SyncEvent::tag()
{
    return m_tag;
}

bool SyncEvent::lastChance()
{
    return m_lastChance;
=======
SyncRegistration* SyncEvent::registration()
{
    return m_syncRegistration.get();
>>>>>>> miniblink49
}

DEFINE_TRACE(SyncEvent)
{
<<<<<<< HEAD
=======
    visitor->trace(m_syncRegistration);
>>>>>>> miniblink49
    ExtendableEvent::trace(visitor);
}

} // namespace blink
