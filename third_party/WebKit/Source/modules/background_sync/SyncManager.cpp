// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/background_sync/SyncManager.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/ScriptState.h"
#include "core/dom/DOMException.h"
<<<<<<< HEAD
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "platform/heap/Persistent.h"
#include "public/platform/InterfaceProvider.h"
#include "public/platform/Platform.h"
#include "wtf/Functional.h"
#include "wtf/PtrUtil.h"

namespace blink {
=======
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "modules/background_sync/SyncCallbacks.h"
#include "modules/background_sync/SyncRegistrationOptions.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "public/platform/Platform.h"
#include "public/platform/modules/background_sync/WebSyncProvider.h"
#include "public/platform/modules/background_sync/WebSyncRegistration.h"
#include "wtf/RefPtr.h"


namespace blink {
namespace {

WebSyncProvider* backgroundSyncProvider()
{
    WebSyncProvider* webSyncProvider = Platform::current()->backgroundSyncProvider();
    ASSERT(webSyncProvider);
    return webSyncProvider;
}

}
>>>>>>> miniblink49

SyncManager::SyncManager(ServiceWorkerRegistration* registration)
    : m_registration(registration)
{
<<<<<<< HEAD
    DCHECK(registration);
}

ScriptPromise SyncManager::registerFunction(ScriptState* scriptState,
    const String& tag)
{
    // TODO(jkarlin): Wait for the registration to become active instead of
    // rejecting. See crbug.com/542437.
    if (!m_registration->active())
        return ScriptPromise::rejectWithDOMException(
            scriptState,
            DOMException::create(AbortError,
                "Registration failed - no active Service Worker"));

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    //   mojom::blink::SyncRegistrationPtr syncRegistration =
    //       mojom::blink::SyncRegistration::New();
    //   syncRegistration->id = SyncManager::kUnregisteredSyncID;
    //   syncRegistration->tag = tag;
    //   syncRegistration->network_state =
    //       blink::mojom::BackgroundSyncNetworkState::ONLINE;
    //
    //   getBackgroundSyncServicePtr()->Register(
    //       std::move(syncRegistration),
    //       m_registration->webRegistration()->registrationId(),
    //       convertToBaseCallback(
    //           WTF::bind(SyncManager::registerCallback, wrapPersistent(resolver))));
    DebugBreak();
    return promise;
}

ScriptPromise SyncManager::getTags(ScriptState* scriptState)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    DebugBreak();
    //   getBackgroundSyncServicePtr()->GetRegistrations(
    //       m_registration->webRegistration()->registrationId(),
    //       convertToBaseCallback(WTF::bind(&SyncManager::getRegistrationsCallback,
    //                                       wrapPersistent(resolver))));
=======
    ASSERT(registration);
}

ScriptPromise SyncManager::registerFunction(ScriptState* scriptState, const SyncRegistrationOptions& options)
{
    if (!m_registration->active())
        return ScriptPromise::rejectWithDOMException(scriptState, DOMException::create(AbortError, "Registration failed - no active Service Worker"));

    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    WebSyncRegistration* webSyncRegistration = new WebSyncRegistration(
        WebSyncRegistration::UNREGISTERED_SYNC_ID /* id */,
        WebSyncRegistration::PeriodicityOneShot,
        options.tag(),
        0 /* minPeriod */,
        WebSyncRegistration::NetworkStateOnline /* networkState */,
        WebSyncRegistration::PowerStateAuto /* powerState */
    );
    backgroundSyncProvider()->registerBackgroundSync(webSyncRegistration, m_registration->webRegistration(), new SyncRegistrationCallbacks(resolver, m_registration));

    return promise;
}

ScriptPromise SyncManager::getRegistration(ScriptState* scriptState, const String& syncRegistrationId)
{
    if (!m_registration->active())
        return ScriptPromise::rejectWithDOMException(scriptState, DOMException::create(AbortError, "Operation failed - no active Service Worker"));

    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    backgroundSyncProvider()->getRegistration(WebSyncRegistration::PeriodicityOneShot, syncRegistrationId, m_registration->webRegistration(), new SyncRegistrationCallbacks(resolver, m_registration));
>>>>>>> miniblink49

    return promise;
}

<<<<<<< HEAD
// const mojom::blink::BackgroundSyncServicePtr&
// SyncManager::getBackgroundSyncServicePtr() {
//   if (!m_backgroundSyncService.get()) {
//     Platform::current()->interfaceProvider()->getInterface(
//         mojo::MakeRequest(&m_backgroundSyncService));
//   }
//   return m_backgroundSyncService;
// }
//
// // static
// void SyncManager::registerCallback(ScriptPromiseResolver* resolver,
//                                    mojom::blink::BackgroundSyncError error,
//                                    mojom::blink::SyncRegistrationPtr options) {
//   // TODO(iclelland): Determine the correct error message to return in each case
//   switch (error) {
//     case mojom::blink::BackgroundSyncError::NONE:
//       if (!options) {
//         resolver->resolve(v8::Null(resolver->getScriptState()->isolate()));
//         return;
//       }
//       resolver->resolve();
//       break;
//     case mojom::blink::BackgroundSyncError::NOT_FOUND:
//       NOTREACHED();
//       break;
//     case mojom::blink::BackgroundSyncError::STORAGE:
//       resolver->reject(
//           DOMException::create(UnknownError, "Background Sync is disabled."));
//       break;
//     case mojom::blink::BackgroundSyncError::NOT_ALLOWED:
//       resolver->reject(
//           DOMException::create(InvalidAccessError,
//                                "Attempted to register a sync event without a "
//                                "window or registration tag too long."));
//       break;
//     case mojom::blink::BackgroundSyncError::PERMISSION_DENIED:
//       resolver->reject(
//           DOMException::create(PermissionDeniedError, "Permission denied."));
//       break;
//     case mojom::blink::BackgroundSyncError::NO_SERVICE_WORKER:
//       resolver->reject(
//           DOMException::create(UnknownError, "No service worker is active."));
//       break;
//   }
// }
//
// // static
// void SyncManager::getRegistrationsCallback(
//     ScriptPromiseResolver* resolver,
//     mojom::blink::BackgroundSyncError error,
//     WTF::Vector<mojom::blink::SyncRegistrationPtr> registrations) {
//   // TODO(iclelland): Determine the correct error message to return in each case
//   switch (error) {
//     case mojom::blink::BackgroundSyncError::NONE: {
//       Vector<String> tags;
//       for (const auto& r : registrations) {
//         tags.push_back(r->tag);
//       }
//       resolver->resolve(tags);
//       break;
//     }
//     case mojom::blink::BackgroundSyncError::NOT_FOUND:
//     case mojom::blink::BackgroundSyncError::NOT_ALLOWED:
//     case mojom::blink::BackgroundSyncError::PERMISSION_DENIED:
//       // These errors should never be returned from
//       // BackgroundSyncManager::GetRegistrations
//       NOTREACHED();
//       break;
//     case mojom::blink::BackgroundSyncError::STORAGE:
//       resolver->reject(
//           DOMException::create(UnknownError, "Background Sync is disabled."));
//       break;
//     case mojom::blink::BackgroundSyncError::NO_SERVICE_WORKER:
//       resolver->reject(
//           DOMException::create(UnknownError, "No service worker is active."));
//       break;
//   }
// }
=======
ScriptPromise SyncManager::getRegistrations(ScriptState* scriptState)
{
    if (!m_registration->active())
        return ScriptPromise::rejectWithDOMException(scriptState, DOMException::create(AbortError, "Operation failed - no active Service Worker"));

    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    backgroundSyncProvider()->getRegistrations(WebSyncRegistration::PeriodicityOneShot, m_registration->webRegistration(), new SyncGetRegistrationsCallbacks(resolver, m_registration));

    return promise;
}

ScriptPromise SyncManager::permissionState(ScriptState* scriptState)
{
    if (!m_registration->active())
        return ScriptPromise::rejectWithDOMException(scriptState, DOMException::create(AbortError, "Operation failed - no active Service Worker"));

    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    backgroundSyncProvider()->getPermissionStatus(WebSyncRegistration::PeriodicityOneShot, m_registration->webRegistration(), new SyncGetPermissionStatusCallbacks(resolver, m_registration));

    return promise;
}
>>>>>>> miniblink49

DEFINE_TRACE(SyncManager)
{
    visitor->trace(m_registration);
}

} // namespace blink
