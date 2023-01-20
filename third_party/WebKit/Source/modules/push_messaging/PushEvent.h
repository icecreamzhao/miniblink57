// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PushEvent_h
#define PushEvent_h

#include "modules/EventModules.h"
#include "modules/ModulesExport.h"
<<<<<<< HEAD
=======
#include "modules/push_messaging/PushEventInit.h"
>>>>>>> miniblink49
#include "modules/push_messaging/PushMessageData.h"
#include "modules/serviceworkers/ExtendableEvent.h"
#include "platform/heap/Handle.h"
#include "wtf/text/AtomicString.h"
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
class PushEventInit;

class MODULES_EXPORT PushEvent final : public ExtendableEvent {
    DEFINE_WRAPPERTYPEINFO();

public:
    static PushEvent* create(const AtomicString& type,
        PushMessageData* data,
        WaitUntilObserver* observer)
    {
        return new PushEvent(type, data, observer);
    }
    static PushEvent* create(const AtomicString& type,
        const PushEventInit& initializer)
    {
        return new PushEvent(type, initializer);
=======
class MODULES_EXPORT PushEvent final : public ExtendableEvent {
    DEFINE_WRAPPERTYPEINFO();
public:
    static PassRefPtrWillBeRawPtr<PushEvent> create()
    {
        return adoptRefWillBeNoop(new PushEvent);
    }
    static PassRefPtrWillBeRawPtr<PushEvent> create(const AtomicString& type, PushMessageData* data, WaitUntilObserver* observer)
    {
        return adoptRefWillBeNoop(new PushEvent(type, data, observer));
    }
    static PassRefPtrWillBeRawPtr<PushEvent> create(const AtomicString& type, const PushEventInit& initializer)
    {
        return adoptRefWillBeNoop(new PushEvent(type, initializer));
>>>>>>> miniblink49
    }

    ~PushEvent() override;

<<<<<<< HEAD
    // ExtendableEvent interface.
=======
>>>>>>> miniblink49
    const AtomicString& interfaceName() const override;

    PushMessageData* data();

    DECLARE_VIRTUAL_TRACE();

private:
<<<<<<< HEAD
    PushEvent(const AtomicString& type, PushMessageData*, WaitUntilObserver*);
    PushEvent(const AtomicString& type, const PushEventInit&);

    Member<PushMessageData> m_data;
=======
    PushEvent();
    PushEvent(const AtomicString& type, PushMessageData*, WaitUntilObserver*);
    PushEvent(const AtomicString& type, const PushEventInit&);

    PersistentWillBeMember<PushMessageData> m_data;
>>>>>>> miniblink49
};

} // namespace blink

#endif // PushEvent_h
