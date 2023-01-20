// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NotificationEvent_h
#define NotificationEvent_h

#include "modules/EventModules.h"
#include "modules/ModulesExport.h"
#include "modules/notifications/Notification.h"
<<<<<<< HEAD
=======
#include "modules/notifications/NotificationEventInit.h"
>>>>>>> miniblink49
#include "modules/serviceworkers/ExtendableEvent.h"
#include "platform/heap/Handle.h"

namespace blink {

<<<<<<< HEAD
class NotificationEventInit;

class MODULES_EXPORT NotificationEvent final : public ExtendableEvent {
    DEFINE_WRAPPERTYPEINFO();

public:
    static NotificationEvent* create(const AtomicString& type,
        const NotificationEventInit& initializer)
    {
        return new NotificationEvent(type, initializer);
    }
    static NotificationEvent* create(const AtomicString& type,
        const NotificationEventInit& initializer,
        WaitUntilObserver* observer)
    {
        return new NotificationEvent(type, initializer, observer);
=======
class MODULES_EXPORT NotificationEvent final : public ExtendableEvent {
    DEFINE_WRAPPERTYPEINFO();
public:
    static PassRefPtrWillBeRawPtr<NotificationEvent> create()
    {
        return adoptRefWillBeNoop(new NotificationEvent);
    }
    static PassRefPtrWillBeRawPtr<NotificationEvent> create(const AtomicString& type, const NotificationEventInit& initializer)
    {
        return adoptRefWillBeNoop(new NotificationEvent(type, initializer));
    }
    static PassRefPtrWillBeRawPtr<NotificationEvent> create(const AtomicString& type, const NotificationEventInit& initializer, WaitUntilObserver* observer)
    {
        return adoptRefWillBeNoop(new NotificationEvent(type, initializer, observer));
>>>>>>> miniblink49
    }

    ~NotificationEvent() override;

<<<<<<< HEAD
    Notification* getNotification() const { return m_notification.get(); }
    String action() const { return m_action; }
    String reply() const { return m_reply; }

    // ExtendableEvent interface.
=======
    Notification* notification() const { return m_notification.get(); }

>>>>>>> miniblink49
    const AtomicString& interfaceName() const override;

    DECLARE_VIRTUAL_TRACE();

private:
<<<<<<< HEAD
    NotificationEvent(const AtomicString& type, const NotificationEventInit&);
    NotificationEvent(const AtomicString& type,
        const NotificationEventInit&,
        WaitUntilObserver*);

    Member<Notification> m_notification;
    String m_action;
    String m_reply;
=======
    NotificationEvent();
    NotificationEvent(const AtomicString& type, const NotificationEventInit&);
    NotificationEvent(const AtomicString& type, const NotificationEventInit&, WaitUntilObserver*);

    PersistentWillBeMember<Notification> m_notification;
>>>>>>> miniblink49
};

} // namespace blink

#endif // NotificationEvent_h
