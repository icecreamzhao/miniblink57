// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/credentialmanager/CredentialManagerClient.h"

#include "bindings/core/v8/ScriptState.h"
#include "core/dom/Document.h"
#include "core/dom/ExecutionContext.h"
#include "core/page/Page.h"

namespace blink {

<<<<<<< HEAD
CredentialManagerClient::CredentialManagerClient(
    WebCredentialManagerClient* client)
=======
CredentialManagerClient::CredentialManagerClient(WebCredentialManagerClient* client)
>>>>>>> miniblink49
    : m_client(client)
{
}

<<<<<<< HEAD
CredentialManagerClient::~CredentialManagerClient() { }

DEFINE_TRACE(CredentialManagerClient)
{
    Supplement<Page>::trace(visitor);
=======
CredentialManagerClient::~CredentialManagerClient()
{
}

DEFINE_TRACE(CredentialManagerClient)
{
    WillBeHeapSupplement<Page>::trace(visitor);
>>>>>>> miniblink49
}

// static
const char* CredentialManagerClient::supplementName()
{
    return "CredentialManagerClient";
}

// static
<<<<<<< HEAD
CredentialManagerClient* CredentialManagerClient::from(
    ExecutionContext* executionContext)
=======
CredentialManagerClient* CredentialManagerClient::from(ExecutionContext* executionContext)
>>>>>>> miniblink49
{
    if (!executionContext->isDocument() || !toDocument(executionContext)->page())
        return 0;
    return from(toDocument(executionContext)->page());
}

// static
CredentialManagerClient* CredentialManagerClient::from(Page* page)
{
<<<<<<< HEAD
    return static_cast<CredentialManagerClient*>(
        Supplement<Page>::from(page, supplementName()));
}

void provideCredentialManagerClientTo(Page& page,
    CredentialManagerClient* client)
{
    CredentialManagerClient::provideTo(
        page, CredentialManagerClient::supplementName(), client);
}

void CredentialManagerClient::dispatchFailedSignIn(
    const WebCredential& credential,
    WebCredentialManagerClient::NotificationCallbacks* callbacks)
=======
    return static_cast<CredentialManagerClient*>(WillBeHeapSupplement<Page>::from(page, supplementName()));
}

void provideCredentialManagerClientTo(Page& page, CredentialManagerClient* client)
{
    CredentialManagerClient::provideTo(page, CredentialManagerClient::supplementName(), adoptPtrWillBeNoop(client));
}

void CredentialManagerClient::dispatchFailedSignIn(const WebCredential& credential, WebCredentialManagerClient::NotificationCallbacks* callbacks)
>>>>>>> miniblink49
{
    if (!m_client)
        return;
    m_client->dispatchFailedSignIn(credential, callbacks);
}

<<<<<<< HEAD
void CredentialManagerClient::dispatchStore(
    const WebCredential& credential,
    WebCredentialManagerClient::NotificationCallbacks* callbacks)
{
    if (!m_client)
        return;
    m_client->dispatchStore(credential, callbacks);
}

void CredentialManagerClient::dispatchRequireUserMediation(
    WebCredentialManagerClient::NotificationCallbacks* callbacks)
=======
void CredentialManagerClient::dispatchSignedIn(const WebCredential& credential, WebCredentialManagerClient::NotificationCallbacks* callbacks)
{
    if (!m_client)
        return;
    m_client->dispatchSignedIn(credential, callbacks);
}

void CredentialManagerClient::dispatchRequireUserMediation(WebCredentialManagerClient::NotificationCallbacks* callbacks)
>>>>>>> miniblink49
{
    if (!m_client)
        return;
    m_client->dispatchRequireUserMediation(callbacks);
}

<<<<<<< HEAD
void CredentialManagerClient::dispatchGet(
    bool zeroClickOnly,
    bool includePasswords,
    const WebVector<WebURL>& federations,
    WebCredentialManagerClient::RequestCallbacks* callbacks)
{
    if (!m_client)
        return;
    m_client->dispatchGet(zeroClickOnly, includePasswords, federations,
        callbacks);
=======
void CredentialManagerClient::dispatchRequest(bool zeroClickOnly, const WebVector<WebURL>& federations, WebCredentialManagerClient::RequestCallbacks* callbacks)
{
    if (!m_client)
        return;
    m_client->dispatchRequest(zeroClickOnly, federations, callbacks);
>>>>>>> miniblink49
}

} // namespace blink
