// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/serviceworkers/ServiceWorkerClient.h"
#include "modules/serviceworkers/ServiceWorkerWindowClient.h"
=======
#include "config.h"
#include "modules/serviceworkers/ServiceWorkerClient.h"
>>>>>>> miniblink49

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/SerializedScriptValue.h"
#include "modules/serviceworkers/ServiceWorkerGlobalScopeClient.h"
#include "public/platform/WebString.h"
#include "wtf/RefPtr.h"
<<<<<<< HEAD
#include <memory>

namespace blink {

ServiceWorkerClient* ServiceWorkerClient::take(
    ScriptPromiseResolver*,
    std::unique_ptr<WebServiceWorkerClientInfo> webClient)
{
    if (!webClient)
        return nullptr;

    switch (webClient->clientType) {
    case WebServiceWorkerClientTypeWindow:
        return ServiceWorkerWindowClient::create(*webClient);
    case WebServiceWorkerClientTypeWorker:
    case WebServiceWorkerClientTypeSharedWorker:
        return ServiceWorkerClient::create(*webClient);
    case WebServiceWorkerClientTypeLast:
        ASSERT_NOT_REACHED();
        return nullptr;
    }
    ASSERT_NOT_REACHED();
    return nullptr;
}

ServiceWorkerClient* ServiceWorkerClient::create(
    const WebServiceWorkerClientInfo& info)
=======

namespace blink {

ServiceWorkerClient* ServiceWorkerClient::create(const WebServiceWorkerClientInfo& info)
>>>>>>> miniblink49
{
    return new ServiceWorkerClient(info);
}

ServiceWorkerClient::ServiceWorkerClient(const WebServiceWorkerClientInfo& info)
    : m_uuid(info.uuid)
    , m_url(info.url.string())
    , m_frameType(info.frameType)
{
}

<<<<<<< HEAD
ServiceWorkerClient::~ServiceWorkerClient() { }
=======
ServiceWorkerClient::~ServiceWorkerClient()
{
}
>>>>>>> miniblink49

String ServiceWorkerClient::frameType() const
{
    switch (m_frameType) {
    case WebURLRequest::FrameTypeAuxiliary:
        return "auxiliary";
    case WebURLRequest::FrameTypeNested:
        return "nested";
    case WebURLRequest::FrameTypeNone:
        return "none";
    case WebURLRequest::FrameTypeTopLevel:
        return "top-level";
    }

    ASSERT_NOT_REACHED();
    return String();
}

<<<<<<< HEAD
void ServiceWorkerClient::postMessage(ExecutionContext* context,
    PassRefPtr<SerializedScriptValue> message,
    const MessagePortArray& ports,
    ExceptionState& exceptionState)
{
    // Disentangle the port in preparation for sending it to the remote context.
    std::unique_ptr<MessagePortChannelArray> channels = MessagePort::disentanglePorts(context, ports, exceptionState);
=======
void ServiceWorkerClient::postMessage(ExecutionContext* context, PassRefPtr<SerializedScriptValue> message, const MessagePortArray* ports, ExceptionState& exceptionState)
{
    // Disentangle the port in preparation for sending it to the remote context.
    OwnPtr<MessagePortChannelArray> channels = MessagePort::disentanglePorts(context, ports, exceptionState);
>>>>>>> miniblink49
    if (exceptionState.hadException())
        return;

    WebString messageString = message->toWireString();
<<<<<<< HEAD
    std::unique_ptr<WebMessagePortChannelArray> webChannels = MessagePort::toWebMessagePortChannelArray(std::move(channels));
    ServiceWorkerGlobalScopeClient::from(context)->postMessageToClient(
        m_uuid, messageString, std::move(webChannels));
=======
    OwnPtr<WebMessagePortChannelArray> webChannels = MessagePort::toWebMessagePortChannelArray(channels.release());
    ServiceWorkerGlobalScopeClient::from(context)->postMessageToClient(m_uuid, messageString, webChannels.release());
>>>>>>> miniblink49
}

} // namespace blink
