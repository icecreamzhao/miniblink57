// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/push_messaging/PushEvent.h"

#include "modules/push_messaging/PushEventInit.h"

namespace blink {

PushEvent::PushEvent(const AtomicString& type,
    PushMessageData* data,
    WaitUntilObserver* observer)
=======
#include "config.h"
#include "modules/push_messaging/PushEvent.h"

namespace blink {

PushEvent::PushEvent()
{
}

PushEvent::PushEvent(const AtomicString& type, PushMessageData* data, WaitUntilObserver* observer)
>>>>>>> miniblink49
    : ExtendableEvent(type, ExtendableEventInit(), observer)
    , m_data(data)
{
}

PushEvent::PushEvent(const AtomicString& type, const PushEventInit& initializer)
    : ExtendableEvent(type, initializer)
{
    if (initializer.hasData())
<<<<<<< HEAD
        m_data = PushMessageData::create(initializer.data());
}

PushEvent::~PushEvent() { }
=======
        m_data = initializer.data();
}

PushEvent::~PushEvent()
{
}
>>>>>>> miniblink49

const AtomicString& PushEvent::interfaceName() const
{
    return EventNames::PushEvent;
}

PushMessageData* PushEvent::data()
{
<<<<<<< HEAD
=======
    if (!m_data)
        m_data = PushMessageData::create();

>>>>>>> miniblink49
    return m_data.get();
}

DEFINE_TRACE(PushEvent)
{
    visitor->trace(m_data);
    ExtendableEvent::trace(visitor);
}

} // namespace blink
