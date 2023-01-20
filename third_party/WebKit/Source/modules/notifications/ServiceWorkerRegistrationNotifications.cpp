// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/notifications/ServiceWorkerRegistrationNotifications.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
<<<<<<< HEAD
#include "core/dom/ExecutionContext.h"
#include "modules/notifications/GetNotificationOptions.h"
#include "modules/notifications/Notification.h"
#include "modules/notifications/NotificationData.h"
#include "modules/notifications/NotificationManager.h"
#include "modules/notifications/NotificationOptions.h"
#include "modules/notifications/NotificationResourcesLoader.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "platform/Histogram.h"
#include "platform/heap/Handle.h"
#include "public/platform/Platform.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/modules/notifications/WebNotificationData.h"
#include "wtf/Assertions.h"
#include "wtf/PtrUtil.h"
#include "wtf/RefPtr.h"
#include <memory>
#include <utility>
=======
#include "bindings/core/v8/SerializedScriptValue.h"
#include "bindings/core/v8/SerializedScriptValueFactory.h"
#include "bindings/core/v8/V8ThrowException.h"
#include "core/dom/DOMException.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "modules/notifications/GetNotificationOptions.h"
#include "modules/notifications/Notification.h"
#include "modules/notifications/NotificationOptions.h"
#include "modules/vibration/NavigatorVibration.h"
#include "platform/weborigin/KURL.h"
#include "public/platform/Platform.h"
#include "public/platform/WebSerializedOrigin.h"
#include "public/platform/modules/notifications/WebNotificationData.h"
#include "public/platform/modules/notifications/WebNotificationManager.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {
namespace {

<<<<<<< HEAD
    // Allows using a CallbackPromiseAdapter with a WebVector to resolve the
    // getNotifications() promise with a HeapVector owning Notifications.
    class NotificationArray {
    public:
        using WebType = const WebVector<WebPersistentNotificationInfo>&;

        static HeapVector<Member<Notification>> take(
            ScriptPromiseResolver* resolver,
            const WebVector<WebPersistentNotificationInfo>& notificationInfos)
        {
            HeapVector<Member<Notification>> notifications;
            for (const WebPersistentNotificationInfo& notificationInfo :
                notificationInfos)
                notifications.push_back(Notification::create(
                    resolver->getExecutionContext(), notificationInfo.notificationId,
                    notificationInfo.data, true /* showing */));

            return notifications;
        }

    private:
        NotificationArray() = delete;
    };

} // namespace

ServiceWorkerRegistrationNotifications::ServiceWorkerRegistrationNotifications(
    ExecutionContext* executionContext,
    ServiceWorkerRegistration* registration)
    : ContextLifecycleObserver(executionContext)
    , m_registration(registration)
{
}

ScriptPromise ServiceWorkerRegistrationNotifications::showNotification(
    ScriptState* scriptState,
    ServiceWorkerRegistration& registration,
    const String& title,
    const NotificationOptions& options,
    ExceptionState& exceptionState)
{
    ExecutionContext* executionContext = scriptState->getExecutionContext();

    // If context object's active worker is null, reject the promise with a
    // TypeError exception.
    if (!registration.active())
        return ScriptPromise::reject(
            scriptState,
            V8ThrowException::createTypeError(scriptState->isolate(),
                "No active registration available on "
                "the ServiceWorkerRegistration."));

    // If permission for notification's origin is not "granted", reject the
    // promise with a TypeError exception, and terminate these substeps.
    if (NotificationManager::from(executionContext)
            ->permissionStatus(executionContext)
        != mojom::blink::PermissionStatus::GRANTED)
        return ScriptPromise::reject(
            scriptState,
            V8ThrowException::createTypeError(
                scriptState->isolate(),
                "No notification permission has been granted for this origin."));

    // Validate the developer-provided options to get the WebNotificationData.
    WebNotificationData data = createWebNotificationData(executionContext, title,
        options, exceptionState);
    if (exceptionState.hadException())
        return exceptionState.reject(scriptState);

    // Log number of actions developer provided in linear histogram:
    //     0    -> underflow bucket,
    //     1-16 -> distinct buckets,
    //     17+  -> overflow bucket.
    DEFINE_THREAD_SAFE_STATIC_LOCAL(
        EnumerationHistogram, notificationCountHistogram,
        new EnumerationHistogram(
            "Notifications.PersistentNotificationActionCount", 17));
    notificationCountHistogram.count(options.actions().size());

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    std::unique_ptr<WebNotificationShowCallbacks> callbacks = WTF::wrapUnique(new CallbackPromiseAdapter<void, void>(resolver));
    ServiceWorkerRegistrationNotifications::from(executionContext, registration)
        .prepareShow(data, std::move(callbacks));

    return promise;
}

ScriptPromise ServiceWorkerRegistrationNotifications::getNotifications(
    ScriptState* scriptState,
    ServiceWorkerRegistration& registration,
    const GetNotificationOptions& options)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    auto callbacks = WTF::makeUnique<CallbackPromiseAdapter<NotificationArray, void>>(
        resolver);

    WebNotificationManager* notificationManager = Platform::current()->notificationManager();
    DCHECK(notificationManager);

    notificationManager->getNotifications(
        options.tag(), registration.webRegistration(), std::move(callbacks));
    return promise;
}

void ServiceWorkerRegistrationNotifications::contextDestroyed(
    ExecutionContext*)
{
    for (auto loader : m_loaders)
        loader->stop();
}

DEFINE_TRACE(ServiceWorkerRegistrationNotifications)
{
    visitor->trace(m_registration);
    visitor->trace(m_loaders);
    Supplement<ServiceWorkerRegistration>::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
}

const char* ServiceWorkerRegistrationNotifications::supplementName()
{
    return "ServiceWorkerRegistrationNotifications";
}

ServiceWorkerRegistrationNotifications&
ServiceWorkerRegistrationNotifications::from(
    ExecutionContext* executionContext,
    ServiceWorkerRegistration& registration)
{
    ServiceWorkerRegistrationNotifications* supplement = static_cast<ServiceWorkerRegistrationNotifications*>(
        Supplement<ServiceWorkerRegistration>::from(registration,
            supplementName()));
    if (!supplement) {
        supplement = new ServiceWorkerRegistrationNotifications(executionContext,
            &registration);
        provideTo(registration, supplementName(), supplement);
    }
    return *supplement;
}

void ServiceWorkerRegistrationNotifications::prepareShow(
    const WebNotificationData& data,
    std::unique_ptr<WebNotificationShowCallbacks> callbacks)
{
    RefPtr<SecurityOrigin> origin = getExecutionContext()->getSecurityOrigin();
    NotificationResourcesLoader* loader = new NotificationResourcesLoader(
        WTF::bind(&ServiceWorkerRegistrationNotifications::didLoadResources,
            wrapWeakPersistent(this), origin.release(), data,
            WTF::passed(std::move(callbacks))));
    m_loaders.add(loader);
    loader->start(getExecutionContext(), data);
}

void ServiceWorkerRegistrationNotifications::didLoadResources(
    PassRefPtr<SecurityOrigin> origin,
    const WebNotificationData& data,
    std::unique_ptr<WebNotificationShowCallbacks> callbacks,
    NotificationResourcesLoader* loader)
{
    DCHECK(m_loaders.contains(loader));

    WebNotificationManager* notificationManager = Platform::current()->notificationManager();
    DCHECK(notificationManager);

    notificationManager->showPersistent(
        WebSecurityOrigin(origin.get()), data, loader->getResources(),
        m_registration->webRegistration(), std::move(callbacks));
    m_loaders.remove(loader);
=======
// Allows using a CallbackPromiseAdapter with a WebVector to resolve the
// getNotifications() promise with a HeapVector owning Notifications.
class NotificationArray {
public:
    using WebType = WebVector<WebPersistentNotificationInfo>;

    static HeapVector<Member<Notification>> take(ScriptPromiseResolver* resolver, PassOwnPtr<WebType> notificationInfos)
    {
        HeapVector<Member<Notification>> notifications;
        for (const WebPersistentNotificationInfo& notificationInfo : *notificationInfos)
            notifications.append(Notification::create(resolver->executionContext(), notificationInfo.persistentId, notificationInfo.data));
        return notifications;
    }

private:
    NotificationArray() = delete;
};

} // namespace

ScriptPromise ServiceWorkerRegistrationNotifications::showNotification(ScriptState* scriptState, ServiceWorkerRegistration& serviceWorkerRegistration, const String& title, const NotificationOptions& options, ExceptionState& exceptionState)
{
    ExecutionContext* executionContext = scriptState->executionContext();

    // If context object's active worker is null, reject promise with a TypeError exception.
    if (!serviceWorkerRegistration.active())
        return ScriptPromise::reject(scriptState, V8ThrowException::createTypeError(scriptState->isolate(), "No active registration available on the ServiceWorkerRegistration."));

    // If permission for notification's origin is not "granted", reject promise with a TypeError exception, and terminate these substeps.
    if (Notification::checkPermission(executionContext) != WebNotificationPermissionAllowed)
        return ScriptPromise::reject(scriptState, V8ThrowException::createTypeError(scriptState->isolate(), "No notification permission has been granted for this origin."));

    if (options.hasVibrate() && options.silent())
        return ScriptPromise::reject(scriptState, V8ThrowException::createTypeError(scriptState->isolate(), "Silent notifications must not specify vibration patterns."));

    // FIXME: Unify the code path here with the Notification.create() function.
    Vector<char> dataAsWireBytes;
    if (options.hasData()) {
        RefPtr<SerializedScriptValue> data = SerializedScriptValueFactory::instance().create(options.data().isolate(), options.data(), nullptr, exceptionState);
        if (exceptionState.hadException())
            return exceptionState.reject(scriptState);

        data->toWireBytes(dataAsWireBytes);
    }

    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    // FIXME: Do the appropriate CORS checks on the icon URL.

    KURL iconUrl;
    if (options.hasIcon() && !options.icon().isEmpty()) {
        iconUrl = executionContext->completeURL(options.icon());
        if (!iconUrl.isValid())
            iconUrl = KURL();
    }

    WebNotificationData::Direction dir = options.dir() == "rtl" ? WebNotificationData::DirectionRightToLeft : WebNotificationData::DirectionLeftToRight;
    NavigatorVibration::VibrationPattern vibrate = NavigatorVibration::sanitizeVibrationPattern(options.vibrate());
    WebNotificationData notification(title, dir, options.lang(), options.body(), options.tag(), iconUrl, vibrate, options.silent(), dataAsWireBytes);
    WebNotificationShowCallbacks* callbacks = new CallbackPromiseAdapter<void, void>(resolver);

    SecurityOrigin* origin = executionContext->securityOrigin();
    ASSERT(origin);

    WebNotificationManager* notificationManager = Platform::current()->notificationManager();
    ASSERT(notificationManager);

    notificationManager->showPersistent(WebSerializedOrigin(*origin), notification, serviceWorkerRegistration.webRegistration(), callbacks);
    return promise;
}

ScriptPromise ServiceWorkerRegistrationNotifications::getNotifications(ScriptState* scriptState, ServiceWorkerRegistration& serviceWorkerRegistration, const GetNotificationOptions& options)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    WebNotificationGetCallbacks* callbacks = new CallbackPromiseAdapter<NotificationArray, void>(resolver);

    WebNotificationManager* notificationManager = Platform::current()->notificationManager();
    ASSERT(notificationManager);

    notificationManager->getNotifications(options.tag(), serviceWorkerRegistration.webRegistration(), callbacks);
    return promise;
>>>>>>> miniblink49
}

} // namespace blink
