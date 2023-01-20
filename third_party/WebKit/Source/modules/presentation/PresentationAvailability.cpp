// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/presentation/PresentationAvailability.h"

#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/Document.h"
#include "core/events/Event.h"
<<<<<<< HEAD
#include "core/frame/UseCounter.h"
=======
>>>>>>> miniblink49
#include "modules/EventTargetModulesNames.h"
#include "modules/presentation/PresentationController.h"
#include "public/platform/Platform.h"
#include "public/platform/modules/presentation/WebPresentationClient.h"
<<<<<<< HEAD
#include "wtf/Vector.h"
=======
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    WebPresentationClient* presentationClient(ExecutionContext* executionContext)
    {
        if (!executionContext)
            return nullptr;
        DCHECK(executionContext->isDocument());
        Document* document = toDocument(executionContext);
        if (!document->frame())
            return nullptr;
        PresentationController* controller = PresentationController::from(*document->frame());
        return controller ? controller->client() : nullptr;
    }
=======
WebPresentationClient* presentationClient(ExecutionContext* executionContext)
{
    ASSERT(executionContext && executionContext->isDocument());

    Document* document = toDocument(executionContext);
    if (!document->frame())
        return nullptr;
    PresentationController* controller = PresentationController::from(*document->frame());
    return controller ? controller->client() : nullptr;
}
>>>>>>> miniblink49

} // anonymous namespace

// static
<<<<<<< HEAD
PresentationAvailability* PresentationAvailability::take(
    PresentationAvailabilityProperty* resolver,
    const WTF::Vector<KURL>& urls,
    bool value)
{
    PresentationAvailability* presentationAvailability = new PresentationAvailability(resolver->getExecutionContext(), urls,
        value);
=======
PresentationAvailability* PresentationAvailability::take(ScriptPromiseResolver* resolver, bool value)
{
    PresentationAvailability* presentationAvailability = new PresentationAvailability(resolver->executionContext(), value);
>>>>>>> miniblink49
    presentationAvailability->suspendIfNeeded();
    presentationAvailability->updateListening();
    return presentationAvailability;
}

<<<<<<< HEAD
PresentationAvailability::PresentationAvailability(
    ExecutionContext* executionContext,
    const WTF::Vector<KURL>& urls,
    bool value)
    : SuspendableObject(executionContext)
    , PageVisibilityObserver(toDocument(executionContext)->page())
    , m_urls(urls)
=======
PresentationAvailability::PresentationAvailability(ExecutionContext* executionContext, bool value)
    : ActiveDOMObject(executionContext)
    , DocumentVisibilityObserver(*toDocument(executionContext))
>>>>>>> miniblink49
    , m_value(value)
    , m_state(State::Active)
{
    ASSERT(executionContext->isDocument());
<<<<<<< HEAD
    WebVector<WebURL> data(urls.size());
    for (size_t i = 0; i < urls.size(); ++i)
        data[i] = WebURL(urls[i]);

    m_urls.swap(data);
}

PresentationAvailability::~PresentationAvailability() { }
=======
}

PresentationAvailability::~PresentationAvailability()
{
    setState(State::Inactive);
}
>>>>>>> miniblink49

const AtomicString& PresentationAvailability::interfaceName() const
{
    return EventTargetNames::PresentationAvailability;
}

<<<<<<< HEAD
ExecutionContext* PresentationAvailability::getExecutionContext() const
{
    return SuspendableObject::getExecutionContext();
}

void PresentationAvailability::addedEventListener(
    const AtomicString& eventType,
    RegisteredEventListener& registeredListener)
{
    EventTargetWithInlineData::addedEventListener(eventType, registeredListener);
    if (eventType == EventTypeNames::change)
        UseCounter::count(getExecutionContext(),
            UseCounter::PresentationAvailabilityChangeEventListener);
=======
ExecutionContext* PresentationAvailability::executionContext() const
{
    return ActiveDOMObject::executionContext();
>>>>>>> miniblink49
}

void PresentationAvailability::availabilityChanged(bool value)
{
    if (m_value == value)
        return;

    m_value = value;
    dispatchEvent(Event::create(EventTypeNames::change));
}

bool PresentationAvailability::hasPendingActivity() const
{
    return m_state != State::Inactive;
}

void PresentationAvailability::resume()
{
    setState(State::Active);
}

void PresentationAvailability::suspend()
{
    setState(State::Suspended);
}

<<<<<<< HEAD
void PresentationAvailability::contextDestroyed(ExecutionContext*)
=======
void PresentationAvailability::stop()
>>>>>>> miniblink49
{
    setState(State::Inactive);
}

<<<<<<< HEAD
void PresentationAvailability::pageVisibilityChanged()
{
    if (m_state == State::Inactive)
        return;
=======
void PresentationAvailability::didChangeVisibilityState(PageVisibilityState visibility)
{
>>>>>>> miniblink49
    updateListening();
}

void PresentationAvailability::setState(State state)
{
    m_state = state;
    updateListening();
}

void PresentationAvailability::updateListening()
{
<<<<<<< HEAD
    WebPresentationClient* client = presentationClient(getExecutionContext());
    if (!client)
        return;

    if (m_state == State::Active && (toDocument(getExecutionContext())->pageVisibilityState() == PageVisibilityStateVisible))
=======
    WebPresentationClient* client = presentationClient(executionContext());
    if (!client)
        return;

    if (m_state == State::Active && (toDocument(executionContext())->pageVisibilityState() == PageVisibilityStateVisible))
>>>>>>> miniblink49
        client->startListening(this);
    else
        client->stopListening(this);
}

<<<<<<< HEAD
const WebVector<WebURL>& PresentationAvailability::urls() const
{
    return m_urls;
}

=======
>>>>>>> miniblink49
bool PresentationAvailability::value() const
{
    return m_value;
}

DEFINE_TRACE(PresentationAvailability)
{
<<<<<<< HEAD
    EventTargetWithInlineData::trace(visitor);
    PageVisibilityObserver::trace(visitor);
    SuspendableObject::trace(visitor);
}

} // namespace blink
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<PresentationAvailability>::trace(visitor);
    DocumentVisibilityObserver::trace(visitor);
    ActiveDOMObject::trace(visitor);
}

} // namespace
>>>>>>> miniblink49
