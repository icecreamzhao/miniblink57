// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SyncManager_h
#define SyncManager_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
//#include "public/platform/modules/background_sync/background_sync.mojom-blink.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
class ScriptPromise;
class ScriptPromiseResolver;
class ScriptState;
class ServiceWorkerRegistration;

class SyncManager final : public GarbageCollectedFinalized<SyncManager>,
                          public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

=======
class SyncRegistrationOptions;
class ScriptPromise;
class ScriptState;
class ServiceWorkerRegistration;

class SyncManager final : public GarbageCollected<SyncManager> , public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();
>>>>>>> miniblink49
public:
    static SyncManager* create(ServiceWorkerRegistration* registration)
    {
        return new SyncManager(registration);
    }

<<<<<<< HEAD
    ScriptPromise registerFunction(ScriptState*, const String& tag);
    ScriptPromise getTags(ScriptState*);

    DECLARE_TRACE();

    enum { kUnregisteredSyncID = -1 };

private:
    explicit SyncManager(ServiceWorkerRegistration*);

    // Returns an initialized BackgroundSyncServicePtr. A connection with the
    // the browser's BackgroundSyncService is created the first time this method
    // is called.
    //   const mojom::blink::BackgroundSyncServicePtr& getBackgroundSyncServicePtr();
    //
    //   // Callbacks
    //   static void registerCallback(ScriptPromiseResolver*,
    //                                mojom::blink::BackgroundSyncError,
    //                                mojom::blink::SyncRegistrationPtr options);
    //   static void getRegistrationsCallback(
    //       ScriptPromiseResolver*,
    //       mojom::blink::BackgroundSyncError,
    //       WTF::Vector<mojom::blink::SyncRegistrationPtr> registrations);
    //
    //   Member<ServiceWorkerRegistration> m_registration;
    //   mojom::blink::BackgroundSyncServicePtr m_backgroundSyncService;
=======
    unsigned long minAllowablePeriod();

    ScriptPromise registerFunction(ScriptState*);
    ScriptPromise registerFunction(ScriptState*, const SyncRegistrationOptions&);
    ScriptPromise getRegistration(ScriptState*, const String&);
    ScriptPromise getRegistrations(ScriptState*);
    ScriptPromise permissionState(ScriptState*);

    DECLARE_TRACE();

private:
    explicit SyncManager(ServiceWorkerRegistration*);

    Member<ServiceWorkerRegistration> m_registration;
>>>>>>> miniblink49
};

} // namespace blink

#endif // SyncManager_h
