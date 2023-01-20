/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/notifications/Notification.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptState.h"
<<<<<<< HEAD
#include "bindings/core/v8/SerializedScriptValueFactory.h"
#include "bindings/modules/v8/V8NotificationAction.h"
#include "core/dom/Document.h"
#include "core/dom/DocumentUserGestureToken.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/ExecutionContextTask.h"
#include "core/dom/ScopedWindowFocusAllowedIndicator.h"
#include "core/dom/TaskRunnerHelper.h"
#include "core/events/Event.h"
#include "core/frame/UseCounter.h"
#include "modules/notifications/NotificationAction.h"
#include "modules/notifications/NotificationData.h"
#include "modules/notifications/NotificationManager.h"
#include "modules/notifications/NotificationOptions.h"
#include "modules/notifications/NotificationResourcesLoader.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/UserGestureIndicator.h"
#include "public/platform/Platform.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/modules/notifications/WebNotificationAction.h"
#include "public/platform/modules/notifications/WebNotificationConstants.h"
#include "public/platform/modules/notifications/WebNotificationManager.h"
#include "wtf/Assertions.h"
#include "wtf/Functional.h"
=======
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/SerializedScriptValueFactory.h"
#include "core/dom/Document.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/ExecutionContextTask.h"
#include "core/dom/ScopedWindowFocusAllowedIndicator.h"
#include "core/events/Event.h"
#include "core/frame/UseCounter.h"
#include "modules/notifications/NotificationOptions.h"
#include "modules/notifications/NotificationPermissionClient.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/UserGestureIndicator.h"
#include "public/platform/Platform.h"
#include "public/platform/WebSerializedOrigin.h"
#include "public/platform/WebString.h"
#include "public/platform/modules/notifications/WebNotificationData.h"
#include "public/platform/modules/notifications/WebNotificationManager.h"
>>>>>>> miniblink49

namespace blink {
namespace {

<<<<<<< HEAD
    WebNotificationManager* notificationManager()
    {
        return Platform::current()->notificationManager();
    }

} // namespace

Notification* Notification::create(ExecutionContext* context,
    const String& title,
    const NotificationOptions& options,
    ExceptionState& exceptionState)
{
    // The Notification constructor may be disabled through a runtime feature when
    // the platform does not support non-persistent notifications.
    if (!RuntimeEnabledFeatures::notificationConstructorEnabled()) {
        exceptionState.throwTypeError(
            "Illegal constructor. Use ServiceWorkerRegistration.showNotification() "
            "instead.");
        return nullptr;
    }

    // The Notification constructor may not be used in Service Worker contexts.
=======
const int64_t kInvalidPersistentId = -1;

WebNotificationManager* notificationManager()
{
    return Platform::current()->notificationManager();
}

} // namespace

Notification* Notification::create(ExecutionContext* context, const String& title, const NotificationOptions& options, ExceptionState& exceptionState)
{
    // The Web Notification constructor may be disabled through a runtime feature. The
    // behavior of the constructor is changing, but not completely agreed upon yet.
    if (!RuntimeEnabledFeatures::notificationConstructorEnabled()) {
        exceptionState.throwTypeError("Illegal constructor. Use ServiceWorkerRegistration.showNotification() instead.");
        return nullptr;
    }

    // The Web Notification constructor may not be used in Service Worker contexts.
>>>>>>> miniblink49
    if (context->isServiceWorkerGlobalScope()) {
        exceptionState.throwTypeError("Illegal constructor.");
        return nullptr;
    }

<<<<<<< HEAD
    if (!options.actions().isEmpty()) {
        exceptionState.throwTypeError(
            "Actions are only supported for persistent notifications shown using "
            "ServiceWorkerRegistration.showNotification().");
        return nullptr;
    }

    if (context->isSecureContext()) {
        UseCounter::count(context, UseCounter::NotificationSecureOrigin);
        if (context->isDocument())
            UseCounter::countCrossOriginIframe(
                *toDocument(context), UseCounter::NotificationAPISecureOriginIframe);
    } else {
        UseCounter::count(context, UseCounter::NotificationInsecureOrigin);
        if (context->isDocument())
            UseCounter::countCrossOriginIframe(
                *toDocument(context),
                UseCounter::NotificationAPIInsecureOriginIframe);
    }

    WebNotificationData data = createWebNotificationData(context, title, options, exceptionState);
    if (exceptionState.hadException())
        return nullptr;

    Notification* notification = new Notification(context, Type::NonPersistent, data);
    notification->schedulePrepareShow();
    return notification;
}

Notification* Notification::create(ExecutionContext* context,
    const String& notificationId,
    const WebNotificationData& data,
    bool showing)
{
    Notification* notification = new Notification(context, Type::Persistent, data);
    notification->setState(showing ? State::Showing : State::Closed);
    notification->setNotificationId(notificationId);
    return notification;
}

Notification::Notification(ExecutionContext* context,
    Type type,
    const WebNotificationData& data)
    : ContextLifecycleObserver(context)
    , m_type(type)
    , m_state(State::Loading)
    , m_data(data)
{
    DCHECK(notificationManager());
}

Notification::~Notification() { }

void Notification::schedulePrepareShow()
{
    DCHECK_EQ(m_state, State::Loading);
    DCHECK(!m_prepareShowMethodRunner);

    m_prepareShowMethodRunner = AsyncMethodRunner<Notification>::create(this, &Notification::prepareShow);
    m_prepareShowMethodRunner->runAsync();
}

void Notification::prepareShow()
{
    DCHECK_EQ(m_state, State::Loading);
    if (NotificationManager::from(getExecutionContext())
            ->permissionStatus(getExecutionContext())
        != mojom::blink::PermissionStatus::GRANTED) {
=======
    // If options's silent is true, and options's vibrate is present, throw a TypeError exception.
    if (options.hasVibrate() && options.silent()) {
        exceptionState.throwTypeError("Silent notifications must not specify vibration patterns.");
        return nullptr;
    }

    RefPtr<SerializedScriptValue> data;
    if (options.hasData()) {
        data = SerializedScriptValueFactory::instance().create(options.data().isolate(), options.data(), nullptr, exceptionState);
        if (exceptionState.hadException())
            return nullptr;
    }

    Notification* notification = new Notification(title, context);

    notification->setBody(options.body());
    notification->setTag(options.tag());
    notification->setLang(options.lang());
    notification->setDir(options.dir());
    notification->setVibrate(NavigatorVibration::sanitizeVibrationPattern(options.vibrate()));
    notification->setSilent(options.silent());
    notification->setSerializedData(data.release());
    if (options.hasIcon()) {
        KURL iconUrl = options.icon().isEmpty() ? KURL() : context->completeURL(options.icon());
        if (!iconUrl.isEmpty() && iconUrl.isValid())
            notification->setIconUrl(iconUrl);
    }

    String insecureOriginMessage;
    UseCounter::Feature feature = context->isPrivilegedContext(insecureOriginMessage)
        ? UseCounter::NotificationSecureOrigin
        : UseCounter::NotificationInsecureOrigin;
    UseCounter::count(context, feature);

    notification->scheduleShow();
    notification->suspendIfNeeded();
    return notification;
}

Notification* Notification::create(ExecutionContext* context, int64_t persistentId, const WebNotificationData& data)
{
    Notification* notification = new Notification(data.title, context);

    notification->setPersistentId(persistentId);
    notification->setDir(data.direction == WebNotificationData::DirectionLeftToRight ? "ltr" : "rtl");
    notification->setLang(data.lang);
    notification->setBody(data.body);
    notification->setTag(data.tag);
    notification->setSilent(data.silent);

    if (!data.icon.isEmpty())
        notification->setIconUrl(data.icon);

    if (!data.vibrate.isEmpty()) {
        NavigatorVibration::VibrationPattern pattern;
        pattern.appendRange(data.vibrate.begin(), data.vibrate.end());
        notification->setVibrate(pattern);
    }

    const WebVector<char>& dataBytes = data.data;
    if (!dataBytes.isEmpty()) {
        notification->setSerializedData(SerializedScriptValueFactory::instance().createFromWireBytes(dataBytes.data(), dataBytes.size()));
        notification->serializedData()->registerMemoryAllocatedWithCurrentScriptContext();
    }

    notification->setState(NotificationStateShowing);
    notification->suspendIfNeeded();
    return notification;
}

Notification::Notification(const String& title, ExecutionContext* context)
    : ActiveDOMObject(context)
    , m_title(title)
    , m_dir("auto")
    , m_silent(false)
    , m_persistentId(kInvalidPersistentId)
    , m_state(NotificationStateIdle)
    , m_asyncRunner(this, &Notification::show)
{
    ASSERT(notificationManager());
}

Notification::~Notification()
{
}

void Notification::scheduleShow()
{
    ASSERT(m_state == NotificationStateIdle);
    ASSERT(!m_asyncRunner.isActive());

    m_asyncRunner.runAsync();
}

void Notification::show()
{
    ASSERT(m_state == NotificationStateIdle);
    if (Notification::checkPermission(executionContext()) != WebNotificationPermissionAllowed) {
>>>>>>> miniblink49
        dispatchErrorEvent();
        return;
    }

<<<<<<< HEAD
    m_loader = new NotificationResourcesLoader(
        WTF::bind(&Notification::didLoadResources, wrapWeakPersistent(this)));
    m_loader->start(getExecutionContext(), m_data);
}

void Notification::didLoadResources(NotificationResourcesLoader* loader)
{
    DCHECK_EQ(loader, m_loader.get());

    SecurityOrigin* origin = getExecutionContext()->getSecurityOrigin();
    DCHECK(origin);

    notificationManager()->show(WebSecurityOrigin(origin), m_data,
        loader->getResources(), this);
    m_loader.clear();

    m_state = State::Showing;
=======
    SecurityOrigin* origin = executionContext()->securityOrigin();
    ASSERT(origin);

    // FIXME: Do CSP checks on the associated notification icon.
    WebNotificationData::Direction dir = m_dir == "rtl" ? WebNotificationData::DirectionRightToLeft : WebNotificationData::DirectionLeftToRight;

    // The lifetime and availability of non-persistent notifications is tied to the page
    // they were created by, and thus the data doesn't have to be known to the embedder.
    Vector<char> emptyDataWireBytes;

    WebNotificationData notificationData(m_title, dir, m_lang, m_body, m_tag, m_iconUrl, m_vibrate, m_silent, emptyDataWireBytes);
    notificationManager()->show(WebSerializedOrigin(*origin), notificationData, this);

    m_state = NotificationStateShowing;
>>>>>>> miniblink49
}

void Notification::close()
{
<<<<<<< HEAD
    if (m_state != State::Showing)
        return;

    // Schedule the "close" event to be fired for non-persistent notifications.
    // Persistent notifications won't get such events for programmatic closes.
    if (m_type == Type::NonPersistent) {
        getExecutionContext()->postTask(
            TaskType::UserInteraction, BLINK_FROM_HERE,
            createSameThreadTask(&Notification::dispatchCloseEvent,
                wrapPersistent(this)));
        m_state = State::Closing;

        notificationManager()->close(this);
        return;
    }

    m_state = State::Closed;

    SecurityOrigin* origin = getExecutionContext()->getSecurityOrigin();
    DCHECK(origin);

    notificationManager()->closePersistent(WebSecurityOrigin(origin), m_data.tag,
        m_notificationId);
=======
    if (m_state != NotificationStateShowing)
        return;

    if (m_persistentId == kInvalidPersistentId) {
        // Fire the close event asynchronously.
        executionContext()->postTask(FROM_HERE, createSameThreadTask(&Notification::dispatchCloseEvent, this));

        m_state = NotificationStateClosing;
        notificationManager()->close(this);
    } else {
        m_state = NotificationStateClosed;

        SecurityOrigin* origin = executionContext()->securityOrigin();
        ASSERT(origin);

        notificationManager()->closePersistent(WebSerializedOrigin(*origin), m_persistentId);
    }
>>>>>>> miniblink49
}

void Notification::dispatchShowEvent()
{
    dispatchEvent(Event::create(EventTypeNames::show));
}

void Notification::dispatchClickEvent()
{
<<<<<<< HEAD
    ExecutionContext* context = getExecutionContext();
    UserGestureIndicator gestureIndicator(DocumentUserGestureToken::create(
        context->isDocument() ? toDocument(context) : nullptr,
        UserGestureToken::NewGesture));
    ScopedWindowFocusAllowedIndicator windowFocusAllowed(getExecutionContext());
=======
    UserGestureIndicator gestureIndicator(DefinitelyProcessingNewUserGesture);
    ScopedWindowFocusAllowedIndicator windowFocusAllowed(executionContext());
>>>>>>> miniblink49
    dispatchEvent(Event::create(EventTypeNames::click));
}

void Notification::dispatchErrorEvent()
{
    dispatchEvent(Event::create(EventTypeNames::error));
}

void Notification::dispatchCloseEvent()
{
<<<<<<< HEAD
    // The notification should be Showing if the user initiated the close, or it
    // should be Closing if the developer initiated the close.
    if (m_state != State::Showing && m_state != State::Closing)
        return;

    m_state = State::Closed;
    dispatchEvent(Event::create(EventTypeNames::close));
}

String Notification::title() const
{
    return m_data.title;
}

String Notification::dir() const
{
    switch (m_data.direction) {
    case WebNotificationData::DirectionLeftToRight:
        return "ltr";
    case WebNotificationData::DirectionRightToLeft:
        return "rtl";
    case WebNotificationData::DirectionAuto:
        return "auto";
    }

    NOTREACHED();
    return String();
}

String Notification::lang() const
{
    return m_data.lang;
}

String Notification::body() const
{
    return m_data.body;
}

String Notification::tag() const
{
    return m_data.tag;
}

String Notification::image() const
{
    return m_data.image.string();
}

String Notification::icon() const
{
    return m_data.icon.string();
}

String Notification::badge() const
{
    return m_data.badge.string();
}

NavigatorVibration::VibrationPattern Notification::vibrate() const
{
    NavigatorVibration::VibrationPattern pattern;
    pattern.appendRange(m_data.vibrate.begin(), m_data.vibrate.end());

    return pattern;
}

DOMTimeStamp Notification::timestamp() const
{
    return m_data.timestamp;
}

bool Notification::renotify() const
{
    return m_data.renotify;
}

bool Notification::silent() const
{
    return m_data.silent;
}

bool Notification::requireInteraction() const
{
    return m_data.requireInteraction;
}

ScriptValue Notification::data(ScriptState* scriptState)
{
    const WebVector<char>& serializedData = m_data.data;
    RefPtr<SerializedScriptValue> serializedValue = SerializedScriptValue::create(
        serializedData.data(), serializedData.size());

    return ScriptValue(scriptState,
        serializedValue->deserialize(scriptState->isolate()));
}

Vector<v8::Local<v8::Value>> Notification::actions(
    ScriptState* scriptState) const
{
    Vector<v8::Local<v8::Value>> actions;
    actions.grow(m_data.actions.size());

    for (size_t i = 0; i < m_data.actions.size(); ++i) {
        NotificationAction action;

        switch (m_data.actions[i].type) {
        case WebNotificationAction::Button:
            action.setType("button");
            break;
        case WebNotificationAction::Text:
            action.setType("text");
            break;
        default:
            NOTREACHED() << "Unknown action type: " << m_data.actions[i].type;
        }

        action.setAction(m_data.actions[i].action);
        action.setTitle(m_data.actions[i].title);
        action.setIcon(m_data.actions[i].icon.string());
        action.setPlaceholder(m_data.actions[i].placeholder);

        // Both the Action dictionaries themselves and the sequence they'll be
        // returned in are expected to the frozen. This cannot be done with WebIDL.
        actions[i] = freezeV8Object(ToV8(action, scriptState), scriptState->isolate());
    }

    return actions;
}

String Notification::permissionString(
    mojom::blink::PermissionStatus permission)
{
    switch (permission) {
    case mojom::blink::PermissionStatus::GRANTED:
        return "granted";
    case mojom::blink::PermissionStatus::DENIED:
        return "denied";
    case mojom::blink::PermissionStatus::ASK:
        return "default";
    }

    NOTREACHED();
=======
    // The notification will be showing when the user initiated the close, or it will be
    // closing if the developer initiated the close.
    if (m_state != NotificationStateShowing && m_state != NotificationStateClosing)
        return;

    m_state = NotificationStateClosed;
    dispatchEvent(Event::create(EventTypeNames::close));
}

NavigatorVibration::VibrationPattern Notification::vibrate(bool& isNull) const
{
    isNull = m_vibrate.isEmpty();
    return m_vibrate;
}

TextDirection Notification::direction() const
{
    // FIXME: Resolve dir()=="auto" against the document.
    return dir() == "rtl" ? RTL : LTR;
}

String Notification::permissionString(WebNotificationPermission permission)
{
    switch (permission) {
    case WebNotificationPermissionAllowed:
        return "granted";
    case WebNotificationPermissionDenied:
        return "denied";
    case WebNotificationPermissionDefault:
        return "default";
    }

    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return "denied";
}

String Notification::permission(ExecutionContext* context)
{
<<<<<<< HEAD
    return permissionString(
        NotificationManager::from(context)->permissionStatus(context));
}

ScriptPromise Notification::requestPermission(
    ScriptState* scriptState,
    NotificationPermissionCallback* deprecatedCallback)
{
    return NotificationManager::from(scriptState->getExecutionContext())
        ->requestPermission(scriptState, deprecatedCallback);
}

size_t Notification::maxActions()
{
    return kWebNotificationMaxActions;
}

DispatchEventResult Notification::dispatchEventInternal(Event* event)
{
    DCHECK(getExecutionContext()->isContextThread());
    return EventTarget::dispatchEventInternal(event);
=======
    return permissionString(checkPermission(context));
}

WebNotificationPermission Notification::checkPermission(ExecutionContext* context)
{
    SecurityOrigin* origin = context->securityOrigin();
    ASSERT(origin);

    return notificationManager()->checkPermission(WebSerializedOrigin(*origin));
}

void Notification::requestPermission(ExecutionContext* context, NotificationPermissionCallback* callback)
{
    // FIXME: Assert that this code-path will only be reached for Document environments
    // when Blink supports [Exposed] annotations on class members in IDL definitions.
    if (NotificationPermissionClient* permissionClient = NotificationPermissionClient::from(context))
        permissionClient->requestPermission(context, callback);
}

bool Notification::dispatchEvent(PassRefPtrWillBeRawPtr<Event> event)
{
    ASSERT(executionContext()->isContextThread());
    return EventTarget::dispatchEvent(event);
>>>>>>> miniblink49
}

const AtomicString& Notification::interfaceName() const
{
    return EventTargetNames::Notification;
}

<<<<<<< HEAD
void Notification::contextDestroyed(ExecutionContext*)
{
    notificationManager()->notifyDelegateDestroyed(this);

    m_state = State::Closed;

    if (m_prepareShowMethodRunner)
        m_prepareShowMethodRunner->stop();

    if (m_loader)
        m_loader->stop();
=======
void Notification::stop()
{
    notificationManager()->notifyDelegateDestroyed(this);

    m_state = NotificationStateClosed;

    m_asyncRunner.stop();
>>>>>>> miniblink49
}

bool Notification::hasPendingActivity() const
{
<<<<<<< HEAD
    // Non-persistent notification can receive events until they've been closed.
    // Persistent notifications should be subject to regular garbage collection.
    if (m_type == Type::NonPersistent)
        return m_state != State::Closed;

    return false;
=======
    return m_state == NotificationStateShowing || m_asyncRunner.isActive();
}

ScriptValue Notification::data(ScriptState* scriptState) const
{
    if (!m_serializedData)
        return ScriptValue::createNull(scriptState);

    return ScriptValue(scriptState, m_serializedData->deserialize(scriptState->isolate()));
>>>>>>> miniblink49
}

DEFINE_TRACE(Notification)
{
<<<<<<< HEAD
    visitor->trace(m_prepareShowMethodRunner);
    visitor->trace(m_loader);
    EventTargetWithInlineData::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<Notification>::trace(visitor);
    ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
