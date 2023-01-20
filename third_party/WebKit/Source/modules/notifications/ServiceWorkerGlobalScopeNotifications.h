// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ServiceWorkerGlobalScopeNotifications_h
#define ServiceWorkerGlobalScopeNotifications_h

#include "core/events/EventTarget.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49

namespace blink {

class ServiceWorkerGlobalScopeNotifications {
<<<<<<< HEAD
    STATIC_ONLY(ServiceWorkerGlobalScopeNotifications);

public:
    DEFINE_STATIC_ATTRIBUTE_EVENT_LISTENER(notificationclick);
    DEFINE_STATIC_ATTRIBUTE_EVENT_LISTENER(notificationclose);
=======
public:
    DEFINE_STATIC_ATTRIBUTE_EVENT_LISTENER(notificationclick);
    DEFINE_STATIC_ATTRIBUTE_EVENT_LISTENER(notificationerror);
>>>>>>> miniblink49
};

} // namespace blink

#endif // ServiceWorkerGlobalScopeNotifications_h
