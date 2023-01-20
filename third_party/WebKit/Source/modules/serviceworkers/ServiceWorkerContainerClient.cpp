// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/serviceworkers/ServiceWorkerContainerClient.h"
=======
#include "config.h"
#include "ServiceWorkerContainerClient.h"
>>>>>>> miniblink49

#include "core/dom/Document.h"
#include "core/dom/ExecutionContext.h"
#include "core/frame/LocalFrame.h"
#include "core/loader/FrameLoaderClient.h"
#include "core/workers/WorkerGlobalScope.h"
<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerProvider.h"
#include <memory>

namespace blink {

ServiceWorkerContainerClient::ServiceWorkerContainerClient(
    Document& document,
    std::unique_ptr<WebServiceWorkerProvider> provider)
    : Supplement<Document>(document)
    , m_provider(std::move(provider))
{
}

ServiceWorkerContainerClient::ServiceWorkerContainerClient(
    WorkerClients& clients,
    std::unique_ptr<WebServiceWorkerProvider> provider)
    : Supplement<WorkerClients>(clients)
    , m_provider(std::move(provider))
{
}

ServiceWorkerContainerClient::~ServiceWorkerContainerClient() { }

=======
#include "public/platform/WebServiceWorkerProvider.h"

namespace blink {

PassOwnPtrWillBeRawPtr<ServiceWorkerContainerClient> ServiceWorkerContainerClient::create(PassOwnPtr<WebServiceWorkerProvider> provider)
{
    return adoptPtrWillBeNoop(new ServiceWorkerContainerClient(provider));
}

ServiceWorkerContainerClient::~ServiceWorkerContainerClient()
{
}

>>>>>>> miniblink49
const char* ServiceWorkerContainerClient::supplementName()
{
    return "ServiceWorkerContainerClient";
}

<<<<<<< HEAD
ServiceWorkerContainerClient* ServiceWorkerContainerClient::from(
    ExecutionContext* context)
{
    if (!context)
        return nullptr;
    if (context->isWorkerGlobalScope()) {
        WorkerClients* workerClients = toWorkerGlobalScope(context)->clients();
        DCHECK(workerClients);
        ServiceWorkerContainerClient* client = static_cast<ServiceWorkerContainerClient*>(
            Supplement<WorkerClients>::from(workerClients, supplementName()));
        DCHECK(client);
        return client;
    }
    Document* document = toDocument(context);
    if (!document->frame())
        return nullptr;

    ServiceWorkerContainerClient* client = static_cast<ServiceWorkerContainerClient*>(
        Supplement<Document>::from(document, supplementName()));
    if (!client) {
        client = new ServiceWorkerContainerClient(
            *document,
            document->frame()->loader().client()->createServiceWorkerProvider());
        Supplement<Document>::provideTo(*document, supplementName(), client);
    }
    return client;
}

void provideServiceWorkerContainerClientToWorker(
    WorkerClients* clients,
    std::unique_ptr<WebServiceWorkerProvider> provider)
{
    clients->provideSupplement(
        ServiceWorkerContainerClient::supplementName(),
        new ServiceWorkerContainerClient(*clients, std::move(provider)));
=======
ServiceWorkerContainerClient* ServiceWorkerContainerClient::from(ExecutionContext* context)
{
    if (context->isDocument()) {
        Document* document = toDocument(context);
        if (!document->frame())
            return 0;

        ServiceWorkerContainerClient* client = static_cast<ServiceWorkerContainerClient*>(WillBeHeapSupplement<Document>::from(document, supplementName()));
        if (client)
            return client;

        // If it's not provided yet, create it lazily.
        document->WillBeHeapSupplementable<Document>::provideSupplement(ServiceWorkerContainerClient::supplementName(), ServiceWorkerContainerClient::create(document->frame()->loader().client()->createServiceWorkerProvider()));
        return static_cast<ServiceWorkerContainerClient*>(WillBeHeapSupplement<Document>::from(document, supplementName()));
    }

    WorkerClients* clients = toWorkerGlobalScope(context)->clients();
    ASSERT(clients);
    return static_cast<ServiceWorkerContainerClient*>(WillBeHeapSupplement<WorkerClients>::from(clients, supplementName()));
}

ServiceWorkerContainerClient::ServiceWorkerContainerClient(PassOwnPtr<WebServiceWorkerProvider> provider)
    : m_provider(provider)
{
}

void provideServiceWorkerContainerClientToWorker(WorkerClients* clients, PassOwnPtr<WebServiceWorkerProvider> provider)
{
    clients->provideSupplement(ServiceWorkerContainerClient::supplementName(), ServiceWorkerContainerClient::create(provider));
>>>>>>> miniblink49
}

} // namespace blink
