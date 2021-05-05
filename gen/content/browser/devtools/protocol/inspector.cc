// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/inspector.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace Inspector {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Inspector";
        const char Metainfo::commandPrefix[] = "Inspector.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<DetachedNotification> DetachedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DetachedNotification> result(new DetachedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* reasonValue = object->get("reason");
            errors->setName("reason");
            result->m_reason = ValueConversions<String>::fromValue(reasonValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DetachedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("reason", ValueConversions<String>::toValue(m_reason));
            return result;
        }

        std::unique_ptr<DetachedNotification> DetachedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::Detached(const String& reason)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DetachedNotification> messageData = DetachedNotification::Create()
                                                                    .SetReason(reason)
                                                                    .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Inspector.detached", std::move(messageData)));
        }

        void Frontend::TargetCrashed()
        {
            if (!m_frontendChannel)
                return;
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Inspector.targetCrashed"));
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
                m_dispatchMap["Inspector.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["Inspector.disable"] = &DispatcherImpl::disable;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->Enable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->Disable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Inspector", std::move(dispatcher));
        }

    } // Inspector
} // namespace content
} // namespace protocol
