// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/presentation/PresentationController.h"

#include "core/dom/Document.h"
#include "core/frame/LocalFrame.h"
#include "modules/presentation/PresentationConnection.h"
#include "public/platform/WebString.h"
#include "public/platform/WebVector.h"
#include "public/platform/modules/presentation/WebPresentationClient.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

PresentationController::PresentationController(LocalFrame& frame,
    WebPresentationClient* client)
    : Supplement<LocalFrame>(frame)
    , ContextLifecycleObserver(frame.document())
=======
#include "config.h"
#include "modules/presentation/PresentationController.h"

#include "core/frame/LocalFrame.h"
#include "modules/presentation/PresentationSession.h"
#include "public/platform/modules/presentation/WebPresentationClient.h"

namespace blink {

PresentationController::PresentationController(LocalFrame& frame, WebPresentationClient* client)
    : LocalFrameLifecycleObserver(&frame)
>>>>>>> miniblink49
    , m_client(client)
{
    if (m_client)
        m_client->setController(this);
}

PresentationController::~PresentationController()
{
    if (m_client)
        m_client->setController(nullptr);
}

// static
<<<<<<< HEAD
PresentationController* PresentationController::create(
    LocalFrame& frame,
    WebPresentationClient* client)
{
    return new PresentationController(frame, client);
=======
PassOwnPtrWillBeRawPtr<PresentationController> PresentationController::create(LocalFrame& frame, WebPresentationClient* client)
{
    return adoptPtrWillBeNoop(new PresentationController(frame, client));
>>>>>>> miniblink49
}

// static
const char* PresentationController::supplementName()
{
    return "PresentationController";
}

// static
PresentationController* PresentationController::from(LocalFrame& frame)
{
<<<<<<< HEAD
    return static_cast<PresentationController*>(
        Supplement<LocalFrame>::from(frame, supplementName()));
}

// static
void PresentationController::provideTo(LocalFrame& frame,
    WebPresentationClient* client)
{
    Supplement<LocalFrame>::provideTo(
        frame, PresentationController::supplementName(),
        PresentationController::create(frame, client));
=======
    return static_cast<PresentationController*>(WillBeHeapSupplement<LocalFrame>::from(frame, supplementName()));
}

// static
void PresentationController::provideTo(LocalFrame& frame, WebPresentationClient* client)
{
    WillBeHeapSupplement<LocalFrame>::provideTo(frame, PresentationController::supplementName(), PresentationController::create(frame, client));
>>>>>>> miniblink49
}

WebPresentationClient* PresentationController::client()
{
    return m_client;
}

DEFINE_TRACE(PresentationController)
{
    visitor->trace(m_presentation);
<<<<<<< HEAD
    visitor->trace(m_connections);
    Supplement<LocalFrame>::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
}

void PresentationController::didStartDefaultSession(
    const WebPresentationSessionInfo& sessionInfo)
{
    if (!m_presentation || !m_presentation->defaultRequest())
        return;
    PresentationConnection::take(this, sessionInfo,
        m_presentation->defaultRequest());
}

void PresentationController::didChangeSessionState(
    const WebPresentationSessionInfo& sessionInfo,
    WebPresentationConnectionState state)
{
    PresentationConnection* connection = findConnection(sessionInfo);
    if (!connection)
        return;
    connection->didChangeState(state);
}

void PresentationController::didCloseConnection(
    const WebPresentationSessionInfo& sessionInfo,
    WebPresentationConnectionCloseReason reason,
    const WebString& message)
{
    PresentationConnection* connection = findConnection(sessionInfo);
    if (!connection)
        return;
    connection->didClose(reason, message);
}

void PresentationController::didReceiveSessionTextMessage(
    const WebPresentationSessionInfo& sessionInfo,
    const WebString& message)
{
    PresentationConnection* connection = findConnection(sessionInfo);
    if (!connection)
        return;
    connection->didReceiveTextMessage(message);
}

void PresentationController::didReceiveSessionBinaryMessage(
    const WebPresentationSessionInfo& sessionInfo,
    const uint8_t* data,
    size_t length)
{
    PresentationConnection* connection = findConnection(sessionInfo);
    if (!connection)
        return;
    connection->didReceiveBinaryMessage(data, length);
=======
    WillBeHeapSupplement<LocalFrame>::trace(visitor);
    LocalFrameLifecycleObserver::trace(visitor);
}

void PresentationController::didStartDefaultSession(WebPresentationSessionClient* sessionClient)
{
    if (!m_presentation) {
        delete sessionClient;
        return;
    }

    PresentationSession* session = PresentationSession::take(sessionClient, m_presentation);
    m_presentation->didStartDefaultSession(session);
}

void PresentationController::didChangeSessionState(WebPresentationSessionClient* sessionClient, WebPresentationSessionState state)
{
    if (!m_presentation) {
        delete sessionClient;
        return;
    }

    m_presentation->didChangeSessionState(sessionClient, state);
}

void PresentationController::didReceiveSessionTextMessage(WebPresentationSessionClient* sessionClient, const WebString& message)
{
    if (!m_presentation) {
        delete sessionClient;
        return;
    }

    m_presentation->didReceiveSessionTextMessage(sessionClient, message);
}

void PresentationController::didReceiveSessionBinaryMessage(WebPresentationSessionClient* sessionClient, const uint8_t* data, size_t length)
{
    if (!m_presentation) {
        delete sessionClient;
        return;
    }

    m_presentation->didReceiveSessionBinaryMessage(sessionClient, data, length);
>>>>>>> miniblink49
}

void PresentationController::setPresentation(Presentation* presentation)
{
    m_presentation = presentation;
}

<<<<<<< HEAD
void PresentationController::setDefaultRequestUrl(
    const WTF::Vector<KURL>& urls)
{
    if (!m_client)
        return;

    WebVector<WebURL> presentationUrls(urls.size());
    for (size_t i = 0; i < urls.size(); ++i) {
        if (urls[i].isValid())
            presentationUrls[i] = urls[i];
    }

    m_client->setDefaultPresentationUrls(presentationUrls);
}

void PresentationController::registerConnection(
    PresentationConnection* connection)
{
    m_connections.add(connection);
}

void PresentationController::contextDestroyed(ExecutionContext*)
=======
void PresentationController::willDetachFrameHost()
>>>>>>> miniblink49
{
    if (m_client) {
        m_client->setController(nullptr);
        m_client = nullptr;
    }
}

<<<<<<< HEAD
PresentationConnection* PresentationController::findExistingConnection(
    const blink::WebVector<blink::WebURL>& presentationUrls,
    const blink::WebString& presentationId)
{
    for (const auto& connection : m_connections) {
        for (const auto& presentationUrl : presentationUrls) {
            if (connection->getState() != WebPresentationConnectionState::Terminated && connection->matches(presentationId, presentationUrl)) {
                return connection.get();
            }
        }
    }
    return nullptr;
}

PresentationConnection* PresentationController::findConnection(
    const WebPresentationSessionInfo& sessionInfo)
{
    for (const auto& connection : m_connections) {
        if (connection->matches(sessionInfo))
            return connection.get();
    }

    return nullptr;
}

=======
>>>>>>> miniblink49
} // namespace blink
