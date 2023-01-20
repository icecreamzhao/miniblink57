// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebNotificationManager_h
#define WebNotificationManager_h

#include "public/platform/WebCallbacks.h"
#include "public/platform/WebString.h"
#include "public/platform/WebVector.h"
#include "public/platform/modules/notifications/WebNotificationData.h"
<<<<<<< HEAD
#include "public/platform/modules/notifications/WebNotificationResources.h"
#include <memory>
=======
#include "public/platform/modules/notifications/WebNotificationPermission.h"
>>>>>>> miniblink49
#include <stdint.h>

namespace blink {

class WebNotificationDelegate;
<<<<<<< HEAD
class WebSecurityOrigin;
=======
class WebSerializedOrigin;
>>>>>>> miniblink49
class WebServiceWorkerRegistration;

// Structure representing the info associated with a persistent notification.
struct WebPersistentNotificationInfo {
<<<<<<< HEAD
    WebString notificationId;
    WebNotificationData data;
};

using WebNotificationGetCallbacks = WebCallbacks<const WebVector<WebPersistentNotificationInfo>&, void>;
=======
    int64_t persistentId = 0;
    WebNotificationData data;
};

using WebNotificationGetCallbacks = WebCallbacks<WebVector<WebPersistentNotificationInfo>, void>;
>>>>>>> miniblink49
using WebNotificationShowCallbacks = WebCallbacks<void, void>;

// Provides the services to show platform notifications to the user.
class WebNotificationManager {
public:
    virtual ~WebNotificationManager() { }

<<<<<<< HEAD
    // Shows a page notification on the user's system. These notifications will
    // have their events delivered to the delegate specified in this call.
    virtual void show(const WebSecurityOrigin&,
        const WebNotificationData&,
        std::unique_ptr<WebNotificationResources>,
        WebNotificationDelegate*)
        = 0;

    // Shows a persistent notification on the user's system. These notifications
    // will have their events delivered to a Service Worker rather than the
    // object's delegate. Will take ownership of the WebNotificationShowCallbacks
    // object.
    virtual void showPersistent(
        const WebSecurityOrigin&,
        const WebNotificationData&,
        std::unique_ptr<WebNotificationResources>,
        WebServiceWorkerRegistration*,
        std::unique_ptr<WebNotificationShowCallbacks>)
        = 0;

    // Asynchronously gets the persistent notifications belonging to the Service
    // Worker Registration.  If |filterTag| is not an empty string, only the
    // notification with the given tag will be considered. Will take ownership of
    // the WebNotificationGetCallbacks object.
    virtual void getNotifications(
        const WebString& filterTag,
        WebServiceWorkerRegistration*,
        std::unique_ptr<WebNotificationGetCallbacks>)
        = 0;
=======
    // Shows a page notification on the user's system. These notifications will have their
    // events delivered to the delegate specified in this call.
    virtual void show(const WebSerializedOrigin&, const WebNotificationData&, WebNotificationDelegate*) = 0;

    // Shows a persistent notification on the user's system. These notifications will have
    // their events delivered to a Service Worker rather than the object's delegate. Will
    // take ownership of the WebNotificationShowCallbacks object.
    virtual void showPersistent(const WebSerializedOrigin&, const WebNotificationData&, WebServiceWorkerRegistration*, WebNotificationShowCallbacks*) = 0;

    // Asynchronously gets the persistent notifications belonging to the Service Worker Registration.
    // If |filterTag| is not an empty string, only the notification with the given tag will be
    // considered. Will take ownership of the WebNotificationGetCallbacks object.
    virtual void getNotifications(const WebString& filterTag, WebServiceWorkerRegistration*, WebNotificationGetCallbacks*) = 0;
>>>>>>> miniblink49

    // Closes a notification previously shown, and removes it if being shown.
    virtual void close(WebNotificationDelegate*) = 0;

<<<<<<< HEAD
    // Closes a persistent notification identified by its notification Id.
    virtual void closePersistent(const WebSecurityOrigin&,
        const WebString& tag,
        const WebString& notificationId)
        = 0;
=======
    // Closes a persistent notification identified by its persistent notification Id.
    virtual void closePersistent(const WebSerializedOrigin&, int64_t persistentNotificationId) = 0;
>>>>>>> miniblink49

    // Indicates that the delegate object is being destroyed, and must no longer
    // be used by the embedder to dispatch events.
    virtual void notifyDelegateDestroyed(WebNotificationDelegate*) = 0;
<<<<<<< HEAD
=======

    // Synchronously checks the permission level for the given origin.
    virtual WebNotificationPermission checkPermission(const WebSerializedOrigin&) = 0;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebNotificationManager_h
