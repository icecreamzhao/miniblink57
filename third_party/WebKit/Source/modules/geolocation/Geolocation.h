/*
 * Copyright (C) 2008, 2009, 2010, 2011 Apple Inc. All Rights Reserved.
 * Copyright 2010, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef Geolocation_h
#define Geolocation_h

#include "bindings/core/v8/ScriptWrappable.h"
<<<<<<< HEAD
#include "core/dom/ContextLifecycleObserver.h"
#include "core/page/PageVisibilityObserver.h"
#include "device/geolocation/public/interfaces/geolocation.mojom-blink.h"
=======
#include "core/dom/ActiveDOMObject.h"
>>>>>>> miniblink49
#include "modules/ModulesExport.h"
#include "modules/geolocation/GeoNotifier.h"
#include "modules/geolocation/GeolocationWatchers.h"
#include "modules/geolocation/Geoposition.h"
#include "modules/geolocation/PositionCallback.h"
#include "modules/geolocation/PositionError.h"
#include "modules/geolocation/PositionErrorCallback.h"
#include "modules/geolocation/PositionOptions.h"
#include "platform/Timer.h"
#include "platform/heap/Handle.h"

<<<<<<< HEAD
#include "third_party/WebKit/public/platform/modules/permissions/permission.mojom-blink.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-blink.h"

=======
>>>>>>> miniblink49
namespace blink {

class Document;
class LocalFrame;
<<<<<<< HEAD
class ExecutionContext;

class MODULES_EXPORT Geolocation final
    : public GarbageCollectedFinalized<Geolocation>,
      public ScriptWrappable,
      public ContextLifecycleObserver,
      public PageVisibilityObserver {
    DEFINE_WRAPPERTYPEINFO();
    USING_GARBAGE_COLLECTED_MIXIN(Geolocation);

public:
    static Geolocation* create(ExecutionContext*);
    ~Geolocation();
    DECLARE_VIRTUAL_TRACE();

    // Inherited from ContextLifecycleObserver and PageVisibilityObserver.
    void contextDestroyed(ExecutionContext*) override;

=======
class GeolocationError;
class ExecutionContext;

class MODULES_EXPORT Geolocation final
    : public GarbageCollectedFinalized<Geolocation>
    , public ScriptWrappable
    , public ActiveDOMObject {
    DEFINE_WRAPPERTYPEINFO();
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(Geolocation);
public:
    static Geolocation* create(ExecutionContext*);
    ~Geolocation() override;
    DECLARE_VIRTUAL_TRACE();

    void stop() override;
>>>>>>> miniblink49
    Document* document() const;
    LocalFrame* frame() const;

    // Creates a oneshot and attempts to obtain a position that meets the
    // constraints of the options.
<<<<<<< HEAD
    void getCurrentPosition(PositionCallback*,
        PositionErrorCallback*,
        const PositionOptions&);

    // Creates a watcher that will be notified whenever a new position is
    // available that meets the constraints of the options.
    int watchPosition(PositionCallback*,
        PositionErrorCallback*,
        const PositionOptions&);
=======
    void getCurrentPosition(PositionCallback*, PositionErrorCallback*, const PositionOptions&);

    // Creates a watcher that will be notified whenever a new position is
    // available that meets the constraints of the options.
    int watchPosition(PositionCallback*, PositionErrorCallback*, const PositionOptions&);
>>>>>>> miniblink49

    // Removes all references to the watcher, it will not be updated again.
    void clearWatch(int watchID);

<<<<<<< HEAD
    bool isAllowed() const
    {
        return m_geolocationPermission == PermissionAllowed;
    }
=======
    void setIsAllowed(bool);

    bool isAllowed() const { return m_geolocationPermission == PermissionAllowed; }
>>>>>>> miniblink49

    // Notifies this that a new position is available. Must never be called
    // before permission is granted by the user.
    void positionChanged();

<<<<<<< HEAD
=======
    // Notifies this that an error has occurred, it must be handled immediately.
    void setError(GeolocationError*);

>>>>>>> miniblink49
    // Discards the notifier because a fatal error occurred for it.
    void fatalErrorOccurred(GeoNotifier*);

    // Adds the notifier to the set awaiting a cached position. Runs the success
    // callbacks for them if permission has been granted. Requests permission if
    // it is unknown.
    void requestUsesCachedPosition(GeoNotifier*);

    // Discards the notifier if it is a oneshot because it timed it.
    void requestTimedOut(GeoNotifier*);

<<<<<<< HEAD
    // Inherited from PageVisibilityObserver.
    void pageVisibilityChanged() override;

private:
=======
private:
    // Returns the last known position, if any. May return null.
    Geoposition* lastPosition();

>>>>>>> miniblink49
    bool isDenied() const { return m_geolocationPermission == PermissionDenied; }

    explicit Geolocation(ExecutionContext*);

    typedef HeapVector<Member<GeoNotifier>> GeoNotifierVector;
    typedef HeapHashSet<Member<GeoNotifier>> GeoNotifierSet;

<<<<<<< HEAD
    bool hasListeners() const
    {
        return !m_oneShots.isEmpty() || !m_watchers.isEmpty();
    }
=======
    bool hasListeners() const { return !m_oneShots.isEmpty() || !m_watchers.isEmpty(); }
>>>>>>> miniblink49

    void sendError(GeoNotifierVector&, PositionError*);
    void sendPosition(GeoNotifierVector&, Geoposition*);

    // Removes notifiers that use a cached position from |notifiers| and
    // if |cached| is not null they are added to it.
<<<<<<< HEAD
    static void extractNotifiersWithCachedPosition(GeoNotifierVector& notifiers,
        GeoNotifierVector* cached);
=======
    static void extractNotifiersWithCachedPosition(GeoNotifierVector& notifiers, GeoNotifierVector* cached);
>>>>>>> miniblink49

    // Copies notifiers from |src| vector to |dest| set.
    static void copyToSet(const GeoNotifierVector& src, GeoNotifierSet& dest);

    static void stopTimer(GeoNotifierVector&);
    void stopTimersForOneShots();
    void stopTimersForWatchers();
    void stopTimers();

    // Sets a fatal error on the given notifiers.
    void cancelRequests(GeoNotifierVector&);

    // Sets a fatal error on all notifiers.
    void cancelAllRequests();

    // Runs the success callbacks on all notifiers. A position must be available
    // and the user must have given permission.
    void makeSuccessCallbacks();

    // Sends the given error to all notifiers, unless the error is not fatal and
    // the notifier is due to receive a cached position. Clears the oneshots,
    // and also  clears the watchers if the error is fatal.
    void handleError(PositionError*);

    // Requests permission to share positions with the page.
    void requestPermission();

<<<<<<< HEAD
    // Connects to the Geolocation mojo service and starts polling for updates.
    void startUpdating(GeoNotifier*);

    void stopUpdating();

    void updateGeolocationServiceConnection();
    void queryNextPosition();

    // Attempts to obtain a position for the given notifier, either by using
    // the cached position or by requesting one from the GeolocationService.
    // Sets a fatal error if permission is denied or no position can be
    // obtained.
=======
    // Attempts to register this with the controller for receiving updates.
    // Returns false if there is no controller to register with.
    bool startUpdating(GeoNotifier*);

    void stopUpdating();

    // Processes the notifiers that were waiting for a permission decision. If
    // granted and this can be registered with the controller then the
    // notifier's timers are started. Otherwise, a fatal error is set on them.
    void handlePendingPermissionNotifiers();

    // Attempts to obtain a position for the given notifier, either by using
    // the cached position or by requesting one from the controller. Sets a
    // fatal error if permission is denied or no position can be obtained.
>>>>>>> miniblink49
    void startRequest(GeoNotifier*);

    bool haveSuitableCachedPosition(const PositionOptions&);

<<<<<<< HEAD
=======
    // Runs the success callbacks for the set of notifiers awaiting a cached
    // position, the set is then cleared. The oneshots are removed everywhere.
    void makeCachedPositionCallbacks();

>>>>>>> miniblink49
    // Record whether the origin trying to access Geolocation would be allowed
    // to access a feature that can only be accessed by secure origins.
    // See https://goo.gl/Y0ZkNV
    void recordOriginTypeAccess() const;

<<<<<<< HEAD
    void onPositionUpdated(device::mojom::blink::GeopositionPtr);

    // Processes the notifiers that were waiting for a permission decision. If
    // granted then the notifier's timers are started. Otherwise, a fatal error
    // is set on them.
    void onGeolocationPermissionUpdated(mojom::blink::PermissionStatus);

    void onGeolocationConnectionError();
    void onPermissionConnectionError();

=======
>>>>>>> miniblink49
    GeoNotifierSet m_oneShots;
    GeolocationWatchers m_watchers;
    GeoNotifierSet m_pendingForPermissionNotifiers;
    Member<Geoposition> m_lastPosition;

    // States of Geolocation permission as granted by the embedder. Unknown
    // means that the embedder still has to be asked for the current permission
    // level; Requested means that the user has yet to make a decision.
    enum Permission {
        PermissionUnknown,
        PermissionRequested,
        PermissionAllowed,
        PermissionDenied
    };

    Permission m_geolocationPermission;
<<<<<<< HEAD
    device::mojom::blink::GeolocationServicePtr m_geolocationService;
    bool m_enableHighAccuracy = false;
    mojom::blink::PermissionServicePtr m_permissionService;

    // Whether a GeoNotifier is waiting for a position update.
    bool m_updating = false;

    // Set to true when m_geolocationService is disconnected. This is used to
    // detect when m_geolocationService is disconnected and reconnected while
    // running callbacks in response to a call to onPositionUpdated().
    bool m_disconnectedGeolocationService = false;
=======

    GeoNotifierSet m_requestsAwaitingCachedPosition;
>>>>>>> miniblink49
};

} // namespace blink

#endif // Geolocation_h
