// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/dom.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace DOM {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "DOM";
        const char Metainfo::commandPrefix[] = "DOM.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<RGBA> RGBA::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<RGBA> result(new RGBA());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* rValue = object->get("r");
            errors->setName("r");
            result->m_r = ValueConversions<int>::fromValue(rValue, errors);
            protocol::Value* gValue = object->get("g");
            errors->setName("g");
            result->m_g = ValueConversions<int>::fromValue(gValue, errors);
            protocol::Value* bValue = object->get("b");
            errors->setName("b");
            result->m_b = ValueConversions<int>::fromValue(bValue, errors);
            protocol::Value* aValue = object->get("a");
            if (aValue) {
                errors->setName("a");
                result->m_a = ValueConversions<double>::fromValue(aValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> RGBA::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("r", ValueConversions<int>::toValue(m_r));
            result->setValue("g", ValueConversions<int>::toValue(m_g));
            result->setValue("b", ValueConversions<int>::toValue(m_b));
            if (m_a.isJust())
                result->setValue("a", ValueConversions<double>::toValue(m_a.fromJust()));
            return result;
        }

        std::unique_ptr<RGBA> RGBA::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

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
                m_dispatchMap["DOM.setFileInputFiles"] = &DispatcherImpl::setFileInputFiles;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status setFileInputFiles(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::setFileInputFiles(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* filesValue = object ? object->get("files") : nullptr;
            errors->setName("files");
            std::unique_ptr<protocol::Array<String>> in_files = ValueConversions<protocol::Array<String>>::fromValue(filesValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetFileInputFiles(in_nodeId, std::move(in_files));
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
            uber->registerBackend("DOM", std::move(dispatcher));
        }

    } // DOM
} // namespace content
} // namespace protocol
