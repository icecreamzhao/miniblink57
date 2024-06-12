// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/DOMDebugger.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace DOMDebugger {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "DOMDebugger";
        const char Metainfo::commandPrefix[] = "DOMDebugger.";
        const char Metainfo::version[] = "1.2";

        namespace DOMBreakpointTypeEnum {
            const char* SubtreeModified = "subtree-modified";
            const char* AttributeModified = "attribute-modified";
            const char* NodeRemoved = "node-removed";
        } // namespace DOMBreakpointTypeEnum

        std::unique_ptr<EventListener> EventListener::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<EventListener> result(new EventListener());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* useCaptureValue = object->get("useCapture");
            errors->setName("useCapture");
            result->m_useCapture = ValueConversions<bool>::fromValue(useCaptureValue, errors);
            protocol::Value* passiveValue = object->get("passive");
            errors->setName("passive");
            result->m_passive = ValueConversions<bool>::fromValue(passiveValue, errors);
            protocol::Value* onceValue = object->get("once");
            errors->setName("once");
            result->m_once = ValueConversions<bool>::fromValue(onceValue, errors);
            protocol::Value* scriptIdValue = object->get("scriptId");
            errors->setName("scriptId");
            result->m_scriptId = ValueConversions<String>::fromValue(scriptIdValue, errors);
            protocol::Value* lineNumberValue = object->get("lineNumber");
            errors->setName("lineNumber");
            result->m_lineNumber = ValueConversions<int>::fromValue(lineNumberValue, errors);
            protocol::Value* columnNumberValue = object->get("columnNumber");
            errors->setName("columnNumber");
            result->m_columnNumber = ValueConversions<int>::fromValue(columnNumberValue, errors);
            protocol::Value* handlerValue = object->get("handler");
            if (handlerValue) {
                errors->setName("handler");
                result->m_handler = ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::fromValue(handlerValue, errors);
            }
            protocol::Value* originalHandlerValue = object->get("originalHandler");
            if (originalHandlerValue) {
                errors->setName("originalHandler");
                result->m_originalHandler = ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::fromValue(originalHandlerValue, errors);
            }
            protocol::Value* removeFunctionValue = object->get("removeFunction");
            if (removeFunctionValue) {
                errors->setName("removeFunction");
                result->m_removeFunction = ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::fromValue(removeFunctionValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> EventListener::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            result->setValue("useCapture", ValueConversions<bool>::toValue(m_useCapture));
            result->setValue("passive", ValueConversions<bool>::toValue(m_passive));
            result->setValue("once", ValueConversions<bool>::toValue(m_once));
            result->setValue("scriptId", ValueConversions<String>::toValue(m_scriptId));
            result->setValue("lineNumber", ValueConversions<int>::toValue(m_lineNumber));
            result->setValue("columnNumber", ValueConversions<int>::toValue(m_columnNumber));
            if (m_handler.isJust())
                result->setValue("handler", ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::toValue(m_handler.fromJust()));
            if (m_originalHandler.isJust())
                result->setValue("originalHandler", ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::toValue(m_originalHandler.fromJust()));
            if (m_removeFunction.isJust())
                result->setValue("removeFunction", ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::toValue(m_removeFunction.fromJust()));
            return result;
        }

        std::unique_ptr<EventListener> EventListener::clone() const
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
                m_dispatchMap["DOMDebugger.setDOMBreakpoint"] = &DispatcherImpl::setDOMBreakpoint;
                m_dispatchMap["DOMDebugger.removeDOMBreakpoint"] = &DispatcherImpl::removeDOMBreakpoint;
                m_dispatchMap["DOMDebugger.setEventListenerBreakpoint"] = &DispatcherImpl::setEventListenerBreakpoint;
                m_dispatchMap["DOMDebugger.removeEventListenerBreakpoint"] = &DispatcherImpl::removeEventListenerBreakpoint;
                m_dispatchMap["DOMDebugger.setInstrumentationBreakpoint"] = &DispatcherImpl::setInstrumentationBreakpoint;
                m_dispatchMap["DOMDebugger.removeInstrumentationBreakpoint"] = &DispatcherImpl::removeInstrumentationBreakpoint;
                m_dispatchMap["DOMDebugger.setXHRBreakpoint"] = &DispatcherImpl::setXHRBreakpoint;
                m_dispatchMap["DOMDebugger.removeXHRBreakpoint"] = &DispatcherImpl::removeXHRBreakpoint;
                m_dispatchMap["DOMDebugger.getEventListeners"] = &DispatcherImpl::getEventListeners;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status setDOMBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeDOMBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setEventListenerBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeEventListenerBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setInstrumentationBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeInstrumentationBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setXHRBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeXHRBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getEventListeners(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::setDOMBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* typeValue = object ? object->get("type") : nullptr;
            errors->setName("type");
            String in_type = ValueConversions<String>::fromValue(typeValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setDOMBreakpoint(in_nodeId, in_type);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeDOMBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* typeValue = object ? object->get("type") : nullptr;
            errors->setName("type");
            String in_type = ValueConversions<String>::fromValue(typeValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeDOMBreakpoint(in_nodeId, in_type);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setEventListenerBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* eventNameValue = object ? object->get("eventName") : nullptr;
            errors->setName("eventName");
            String in_eventName = ValueConversions<String>::fromValue(eventNameValue, errors);
            protocol::Value* targetNameValue = object ? object->get("targetName") : nullptr;
            Maybe<String> in_targetName;
            if (targetNameValue) {
                errors->setName("targetName");
                in_targetName = ValueConversions<String>::fromValue(targetNameValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setEventListenerBreakpoint(in_eventName, std::move(in_targetName));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeEventListenerBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* eventNameValue = object ? object->get("eventName") : nullptr;
            errors->setName("eventName");
            String in_eventName = ValueConversions<String>::fromValue(eventNameValue, errors);
            protocol::Value* targetNameValue = object ? object->get("targetName") : nullptr;
            Maybe<String> in_targetName;
            if (targetNameValue) {
                errors->setName("targetName");
                in_targetName = ValueConversions<String>::fromValue(targetNameValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeEventListenerBreakpoint(in_eventName, std::move(in_targetName));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setInstrumentationBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* eventNameValue = object ? object->get("eventName") : nullptr;
            errors->setName("eventName");
            String in_eventName = ValueConversions<String>::fromValue(eventNameValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setInstrumentationBreakpoint(in_eventName);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeInstrumentationBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* eventNameValue = object ? object->get("eventName") : nullptr;
            errors->setName("eventName");
            String in_eventName = ValueConversions<String>::fromValue(eventNameValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeInstrumentationBreakpoint(in_eventName);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setXHRBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setXHRBreakpoint(in_url);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeXHRBreakpoint(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeXHRBreakpoint(in_url);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getEventListeners(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* objectIdValue = object ? object->get("objectId") : nullptr;
            errors->setName("objectId");
            String in_objectId = ValueConversions<String>::fromValue(objectIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<protocol::DOMDebugger::EventListener>> out_listeners;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getEventListeners(in_objectId, &out_listeners);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("listeners", ValueConversions<protocol::Array<protocol::DOMDebugger::EventListener>>::toValue(out_listeners.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("DOMDebugger", std::move(dispatcher));
        }

    } // DOMDebugger
} // namespace blink
} // namespace protocol
