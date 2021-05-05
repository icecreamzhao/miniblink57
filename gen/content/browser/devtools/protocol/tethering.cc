// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/tethering.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace Tethering {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Tethering";
        const char Metainfo::commandPrefix[] = "Tethering.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<AcceptedNotification> AcceptedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AcceptedNotification> result(new AcceptedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* portValue = object->get("port");
            errors->setName("port");
            result->m_port = ValueConversions<int>::fromValue(portValue, errors);
            protocol::Value* connectionIdValue = object->get("connectionId");
            errors->setName("connectionId");
            result->m_connectionId = ValueConversions<String>::fromValue(connectionIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AcceptedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("port", ValueConversions<int>::toValue(m_port));
            result->setValue("connectionId", ValueConversions<String>::toValue(m_connectionId));
            return result;
        }

        std::unique_ptr<AcceptedNotification> AcceptedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::Accepted(int port, const String& connectionId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<AcceptedNotification> messageData = AcceptedNotification::Create()
                                                                    .SetPort(port)
                                                                    .SetConnectionId(connectionId)
                                                                    .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Tethering.accepted", std::move(messageData)));
        }

        void Frontend::flush()
        {
            m_frontendChannel->flushProtocolNotifications();
        }

        void Frontend::sendRawNotification(const String& notification)
        {
            m_frontendChannel->sendProtocolNotification(InternalRawNotification::create(notification));
        }

        // --------------------- Dispatcher.

        class DispatcherImpl : public protocol::DispatcherBase {
        public:
            DispatcherImpl(FrontendChannel* frontendChannel, Backend* backend, bool fallThroughForNotFound)
                : DispatcherBase(frontendChannel)
                , m_backend(backend)
                , m_fallThroughForNotFound(fallThroughForNotFound)
            {
                m_dispatchMap["Tethering.bind"] = &DispatcherImpl::bind;
                m_dispatchMap["Tethering.unbind"] = &DispatcherImpl::unbind;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status bind(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status unbind(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

            Backend* m_backend;
            bool m_fallThroughForNotFound;
        };

        DispatchResponse::Status DispatcherImpl::dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject)
        {
            protocol::HashMap<String, CallHandler>::iterator it = m_dispatchMap.find(method);
            if (it == m_dispatchMap.end()) {
                if (m_fallThroughForNotFound)
                    return DispatchResponse::kFallThrough;
                reportProtocolError(callId, DispatchResponse::kMethodNotFound, "'" + method + "' wasn't found", nullptr);
                return DispatchResponse::kError;
            }

            protocol::ErrorSupport errors;
            return (this->*(it->second))(callId, std::move(messageObject), &errors);
        }

        class BindCallbackImpl : public Backend::BindCallback, public DispatcherBase::Callback {
        public:
            BindCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::bind(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* portValue = object ? object->get("port") : nullptr;
            errors->setName("port");
            int in_port = ValueConversions<int>::fromValue(portValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<BindCallbackImpl> callback(new BindCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->Bind(in_port, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class UnbindCallbackImpl : public Backend::UnbindCallback, public DispatcherBase::Callback {
        public:
            UnbindCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::unbind(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* portValue = object ? object->get("port") : nullptr;
            errors->setName("port");
            int in_port = ValueConversions<int>::fromValue(portValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<UnbindCallbackImpl> callback(new UnbindCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->Unbind(in_port, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Tethering", std::move(dispatcher));
        }

    } // Tethering
} // namespace content
} // namespace protocol
