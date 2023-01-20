// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/mediastream/MediaDevices.h"

#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/ScriptState.h"
#include "core/dom/DOMException.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
<<<<<<< HEAD
#include "core/events/Event.h"
#include "modules/mediastream/MediaErrorState.h"
#include "modules/mediastream/MediaStream.h"
#include "modules/mediastream/MediaStreamConstraints.h"
=======
#include "modules/mediastream/MediaStream.h"
>>>>>>> miniblink49
#include "modules/mediastream/NavigatorMediaStream.h"
#include "modules/mediastream/NavigatorUserMediaErrorCallback.h"
#include "modules/mediastream/NavigatorUserMediaSuccessCallback.h"
#include "modules/mediastream/UserMediaController.h"

namespace blink {

<<<<<<< HEAD
namespace {

    class PromiseSuccessCallback final : public NavigatorUserMediaSuccessCallback {
    public:
        explicit PromiseSuccessCallback(ScriptPromiseResolver* resolver)
            : m_resolver(resolver)
        {
        }

        ~PromiseSuccessCallback() { }

        void handleEvent(MediaStream* stream) { m_resolver->resolve(stream); }

        DEFINE_INLINE_VIRTUAL_TRACE()
        {
            visitor->trace(m_resolver);
            NavigatorUserMediaSuccessCallback::trace(visitor);
        }

    private:
        Member<ScriptPromiseResolver> m_resolver;
    };

    class PromiseErrorCallback final : public NavigatorUserMediaErrorCallback {
    public:
        explicit PromiseErrorCallback(ScriptPromiseResolver* resolver)
            : m_resolver(resolver)
        {
        }

        ~PromiseErrorCallback() { }

        void handleEvent(NavigatorUserMediaError* error)
        {
            m_resolver->reject(error);
        }

        DEFINE_INLINE_VIRTUAL_TRACE()
        {
            visitor->trace(m_resolver);
            NavigatorUserMediaErrorCallback::trace(visitor);
        }

    private:
        Member<ScriptPromiseResolver> m_resolver;
    };

} // namespace

MediaDevices* MediaDevices::create(ExecutionContext* context)
{
    MediaDevices* mediaDevices = new MediaDevices(context);
    mediaDevices->suspendIfNeeded();
    return mediaDevices;
}

MediaDevices::MediaDevices(ExecutionContext* context)
    : SuspendableObject(context)
    , m_observing(false)
    , m_stopped(false)
    , m_dispatchScheduledEventRunner(AsyncMethodRunner<MediaDevices>::create(
          this,
          &MediaDevices::dispatchScheduledEvent))
{
}

MediaDevices::~MediaDevices() { }

ScriptPromise MediaDevices::enumerateDevices(ScriptState* scriptState)
{
    Document* document = toDocument(scriptState->getExecutionContext());
    UserMediaController* userMedia = UserMediaController::from(document->frame());
    if (!userMedia)
        return ScriptPromise::rejectWithDOMException(
            scriptState,
            DOMException::create(NotSupportedError,
                "No media device controller available; is this a "
                "detached window?"));
=======
ScriptPromise MediaDevices::enumerateDevices(ScriptState* scriptState)
{
    Document* document = toDocument(scriptState->executionContext());
    UserMediaController* userMedia = UserMediaController::from(document->frame());
    if (!userMedia)
        return ScriptPromise::rejectWithDOMException(scriptState, DOMException::create(NotSupportedError, "No media device controller available; is this a detached window?"));
>>>>>>> miniblink49

    MediaDevicesRequest* request = MediaDevicesRequest::create(scriptState, userMedia);
    return request->start();
}

<<<<<<< HEAD
ScriptPromise MediaDevices::getUserMedia(ScriptState* scriptState,
    const MediaStreamConstraints& options,
    ExceptionState& exceptionState)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
=======
namespace {

class PromiseSuccessCallback final : public NavigatorUserMediaSuccessCallback {
public:
    PromiseSuccessCallback(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver)
    {
    }

    ~PromiseSuccessCallback()
    {
    }

    void handleEvent(MediaStream* stream)
    {
        m_resolver->resolve(stream);
    }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_resolver);
        NavigatorUserMediaSuccessCallback::trace(visitor);
    }

private:
    RefPtrWillBeMember<ScriptPromiseResolver> m_resolver;
};

class PromiseErrorCallback final : public NavigatorUserMediaErrorCallback {
public:
    PromiseErrorCallback(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver)
    {
    }

    ~PromiseErrorCallback()
    {
    }

    void handleEvent(NavigatorUserMediaError* error)
    {
        m_resolver->reject(error);
    }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_resolver);
        NavigatorUserMediaErrorCallback::trace(visitor);
    }

private:
    RefPtrWillBeMember<ScriptPromiseResolver> m_resolver;
};

} // namespace

ScriptPromise MediaDevices::getUserMedia(ScriptState* scriptState, const Dictionary& options, ExceptionState& exceptionState)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
>>>>>>> miniblink49

    NavigatorUserMediaSuccessCallback* successCallback = new PromiseSuccessCallback(resolver);
    NavigatorUserMediaErrorCallback* errorCallback = new PromiseErrorCallback(resolver);

<<<<<<< HEAD
    Document* document = toDocument(scriptState->getExecutionContext());
    UserMediaController* userMedia = UserMediaController::from(document->frame());
    if (!userMedia)
        return ScriptPromise::rejectWithDOMException(
            scriptState,
            DOMException::create(NotSupportedError,
                "No media device controller available; is this a "
                "detached window?"));

    MediaErrorState errorState;
    UserMediaRequest* request = UserMediaRequest::create(
        document, userMedia, options, successCallback, errorCallback, errorState);
    if (!request) {
        DCHECK(errorState.hadException());
        if (errorState.canGenerateException()) {
            errorState.raiseException(exceptionState);
            return exceptionState.reject(scriptState);
        }
        ScriptPromise rejectedPromise = resolver->promise();
        resolver->reject(errorState.createError());
        return rejectedPromise;
    }

    String errorMessage;
    if (!request->isSecureContextUse(errorMessage)) {
        return ScriptPromise::rejectWithDOMException(
            scriptState, DOMException::create(NotSupportedError, errorMessage));
=======
    Document* document = toDocument(scriptState->executionContext());
    UserMediaController* userMedia = UserMediaController::from(document->frame());
    if (!userMedia)
        return ScriptPromise::rejectWithDOMException(scriptState, DOMException::create(NotSupportedError, "No media device controller available; is this a detached window?"));

    UserMediaRequest* request = UserMediaRequest::create(document, userMedia, options, successCallback, errorCallback, exceptionState);
    if (!request) {
        ASSERT(exceptionState.hadException());
        return exceptionState.reject(scriptState);
>>>>>>> miniblink49
    }

    request->start();
    return resolver->promise();
}

<<<<<<< HEAD
void MediaDevices::didChangeMediaDevices()
{
    Document* document = toDocument(getExecutionContext());
    DCHECK(document);

    if (RuntimeEnabledFeatures::onDeviceChangeEnabled())
        scheduleDispatchEvent(Event::create(EventTypeNames::devicechange));
}

const AtomicString& MediaDevices::interfaceName() const
{
    return EventTargetNames::MediaDevices;
}

ExecutionContext* MediaDevices::getExecutionContext() const
{
    return SuspendableObject::getExecutionContext();
}

void MediaDevices::removeAllEventListeners()
{
    EventTargetWithInlineData::removeAllEventListeners();
    DCHECK(!hasEventListeners());
    stopObserving();
}

void MediaDevices::addedEventListener(
    const AtomicString& eventType,
    RegisteredEventListener& registeredListener)
{
    EventTargetWithInlineData::addedEventListener(eventType, registeredListener);
    startObserving();
}

void MediaDevices::removedEventListener(
    const AtomicString& eventType,
    const RegisteredEventListener& registeredListener)
{
    EventTargetWithInlineData::removedEventListener(eventType,
        registeredListener);
    if (!hasEventListeners())
        stopObserving();
}

bool MediaDevices::hasPendingActivity() const
{
    DCHECK(m_stopped || m_observing == hasEventListeners());
    return m_observing;
}

void MediaDevices::contextDestroyed(ExecutionContext*)
{
    if (m_stopped)
        return;

    m_stopped = true;
    stopObserving();
}

void MediaDevices::suspend()
{
    m_dispatchScheduledEventRunner->suspend();
}

void MediaDevices::resume()
{
    m_dispatchScheduledEventRunner->resume();
}

void MediaDevices::scheduleDispatchEvent(Event* event)
{
    m_scheduledEvents.push_back(event);
    m_dispatchScheduledEventRunner->runAsync();
}

void MediaDevices::dispatchScheduledEvent()
{
    HeapVector<Member<Event>> events;
    events.swap(m_scheduledEvents);

    for (const auto& event : events)
        dispatchEvent(event);
}

void MediaDevices::startObserving()
{
    if (m_observing || m_stopped)
        return;

    UserMediaController* userMedia = getUserMediaController();
    if (!userMedia)
        return;

    userMedia->setMediaDeviceChangeObserver(this);
    m_observing = true;
}

void MediaDevices::stopObserving()
{
    if (!m_observing)
        return;

    UserMediaController* userMedia = getUserMediaController();
    if (!userMedia)
        return;

    userMedia->setMediaDeviceChangeObserver(nullptr);
    m_observing = false;
}

UserMediaController* MediaDevices::getUserMediaController()
{
    Document* document = toDocument(getExecutionContext());
    if (!document)
        return nullptr;

    return UserMediaController::from(document->frame());
}

void MediaDevices::dispose()
{
    stopObserving();
}

DEFINE_TRACE(MediaDevices)
{
    visitor->trace(m_dispatchScheduledEventRunner);
    visitor->trace(m_scheduledEvents);
    EventTargetWithInlineData::trace(visitor);
    SuspendableObject::trace(visitor);
}

=======
>>>>>>> miniblink49
} // namespace blink
