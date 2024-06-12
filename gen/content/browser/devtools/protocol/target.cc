// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/target.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace Target {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Target";
        const char Metainfo::commandPrefix[] = "Target.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<TargetInfo> TargetInfo::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<TargetInfo> result(new TargetInfo());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* targetIdValue = object->get("targetId");
            errors->setName("targetId");
            result->m_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* titleValue = object->get("title");
            errors->setName("title");
            result->m_title = ValueConversions<String>::fromValue(titleValue, errors);
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> TargetInfo::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("targetId", ValueConversions<String>::toValue(m_targetId));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            result->setValue("title", ValueConversions<String>::toValue(m_title));
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            return result;
        }

        std::unique_ptr<TargetInfo> TargetInfo::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<RemoteLocation> RemoteLocation::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<RemoteLocation> result(new RemoteLocation());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* hostValue = object->get("host");
            errors->setName("host");
            result->m_host = ValueConversions<String>::fromValue(hostValue, errors);
            protocol::Value* portValue = object->get("port");
            errors->setName("port");
            result->m_port = ValueConversions<int>::fromValue(portValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> RemoteLocation::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("host", ValueConversions<String>::toValue(m_host));
            result->setValue("port", ValueConversions<int>::toValue(m_port));
            return result;
        }

        std::unique_ptr<RemoteLocation> RemoteLocation::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<TargetCreatedNotification> TargetCreatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<TargetCreatedNotification> result(new TargetCreatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* targetInfoValue = object->get("targetInfo");
            errors->setName("targetInfo");
            result->m_targetInfo = ValueConversions<protocol::Target::TargetInfo>::fromValue(targetInfoValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> TargetCreatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("targetInfo", ValueConversions<protocol::Target::TargetInfo>::toValue(m_targetInfo.get()));
            return result;
        }

        std::unique_ptr<TargetCreatedNotification> TargetCreatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<TargetDestroyedNotification> TargetDestroyedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<TargetDestroyedNotification> result(new TargetDestroyedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* targetIdValue = object->get("targetId");
            errors->setName("targetId");
            result->m_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> TargetDestroyedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("targetId", ValueConversions<String>::toValue(m_targetId));
            return result;
        }

        std::unique_ptr<TargetDestroyedNotification> TargetDestroyedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AttachedToTargetNotification> AttachedToTargetNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AttachedToTargetNotification> result(new AttachedToTargetNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* targetInfoValue = object->get("targetInfo");
            errors->setName("targetInfo");
            result->m_targetInfo = ValueConversions<protocol::Target::TargetInfo>::fromValue(targetInfoValue, errors);
            protocol::Value* waitingForDebuggerValue = object->get("waitingForDebugger");
            errors->setName("waitingForDebugger");
            result->m_waitingForDebugger = ValueConversions<bool>::fromValue(waitingForDebuggerValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AttachedToTargetNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("targetInfo", ValueConversions<protocol::Target::TargetInfo>::toValue(m_targetInfo.get()));
            result->setValue("waitingForDebugger", ValueConversions<bool>::toValue(m_waitingForDebugger));
            return result;
        }

        std::unique_ptr<AttachedToTargetNotification> AttachedToTargetNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DetachedFromTargetNotification> DetachedFromTargetNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DetachedFromTargetNotification> result(new DetachedFromTargetNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* targetIdValue = object->get("targetId");
            errors->setName("targetId");
            result->m_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DetachedFromTargetNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("targetId", ValueConversions<String>::toValue(m_targetId));
            return result;
        }

        std::unique_ptr<DetachedFromTargetNotification> DetachedFromTargetNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ReceivedMessageFromTargetNotification> ReceivedMessageFromTargetNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ReceivedMessageFromTargetNotification> result(new ReceivedMessageFromTargetNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* targetIdValue = object->get("targetId");
            errors->setName("targetId");
            result->m_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            protocol::Value* messageValue = object->get("message");
            errors->setName("message");
            result->m_message = ValueConversions<String>::fromValue(messageValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ReceivedMessageFromTargetNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("targetId", ValueConversions<String>::toValue(m_targetId));
            result->setValue("message", ValueConversions<String>::toValue(m_message));
            return result;
        }

        std::unique_ptr<ReceivedMessageFromTargetNotification> ReceivedMessageFromTargetNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::TargetCreated(std::unique_ptr<protocol::Target::TargetInfo> targetInfo)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<TargetCreatedNotification> messageData = TargetCreatedNotification::Create()
                                                                         .SetTargetInfo(std::move(targetInfo))
                                                                         .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Target.targetCreated", std::move(messageData)));
        }

        void Frontend::TargetDestroyed(const String& targetId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<TargetDestroyedNotification> messageData = TargetDestroyedNotification::Create()
                                                                           .SetTargetId(targetId)
                                                                           .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Target.targetDestroyed", std::move(messageData)));
        }

        void Frontend::AttachedToTarget(std::unique_ptr<protocol::Target::TargetInfo> targetInfo, bool waitingForDebugger)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<AttachedToTargetNotification> messageData = AttachedToTargetNotification::Create()
                                                                            .SetTargetInfo(std::move(targetInfo))
                                                                            .SetWaitingForDebugger(waitingForDebugger)
                                                                            .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Target.attachedToTarget", std::move(messageData)));
        }

        void Frontend::DetachedFromTarget(const String& targetId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DetachedFromTargetNotification> messageData = DetachedFromTargetNotification::Create()
                                                                              .SetTargetId(targetId)
                                                                              .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Target.detachedFromTarget", std::move(messageData)));
        }

        void Frontend::ReceivedMessageFromTarget(const String& targetId, const String& message)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ReceivedMessageFromTargetNotification> messageData = ReceivedMessageFromTargetNotification::Create()
                                                                                     .SetTargetId(targetId)
                                                                                     .SetMessage(message)
                                                                                     .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Target.receivedMessageFromTarget", std::move(messageData)));
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
                m_dispatchMap["Target.setDiscoverTargets"] = &DispatcherImpl::setDiscoverTargets;
                m_dispatchMap["Target.setAutoAttach"] = &DispatcherImpl::setAutoAttach;
                m_dispatchMap["Target.setAttachToFrames"] = &DispatcherImpl::setAttachToFrames;
                m_dispatchMap["Target.setRemoteLocations"] = &DispatcherImpl::setRemoteLocations;
                m_dispatchMap["Target.sendMessageToTarget"] = &DispatcherImpl::sendMessageToTarget;
                m_dispatchMap["Target.getTargetInfo"] = &DispatcherImpl::getTargetInfo;
                m_dispatchMap["Target.activateTarget"] = &DispatcherImpl::activateTarget;
                m_dispatchMap["Target.closeTarget"] = &DispatcherImpl::closeTarget;
                m_dispatchMap["Target.attachToTarget"] = &DispatcherImpl::attachToTarget;
                m_dispatchMap["Target.detachFromTarget"] = &DispatcherImpl::detachFromTarget;
                m_dispatchMap["Target.createBrowserContext"] = &DispatcherImpl::createBrowserContext;
                m_dispatchMap["Target.disposeBrowserContext"] = &DispatcherImpl::disposeBrowserContext;
                m_dispatchMap["Target.createTarget"] = &DispatcherImpl::createTarget;
                m_dispatchMap["Target.getTargets"] = &DispatcherImpl::getTargets;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status setDiscoverTargets(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setAutoAttach(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setAttachToFrames(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setRemoteLocations(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status sendMessageToTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getTargetInfo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status activateTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status closeTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status attachToTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status detachFromTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status createBrowserContext(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status disposeBrowserContext(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status createTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getTargets(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::setDiscoverTargets(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* discoverValue = object ? object->get("discover") : nullptr;
            errors->setName("discover");
            bool in_discover = ValueConversions<bool>::fromValue(discoverValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetDiscoverTargets(in_discover);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setAutoAttach(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* autoAttachValue = object ? object->get("autoAttach") : nullptr;
            errors->setName("autoAttach");
            bool in_autoAttach = ValueConversions<bool>::fromValue(autoAttachValue, errors);
            protocol::Value* waitForDebuggerOnStartValue = object ? object->get("waitForDebuggerOnStart") : nullptr;
            errors->setName("waitForDebuggerOnStart");
            bool in_waitForDebuggerOnStart = ValueConversions<bool>::fromValue(waitForDebuggerOnStartValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetAutoAttach(in_autoAttach, in_waitForDebuggerOnStart);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setAttachToFrames(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* valueValue = object ? object->get("value") : nullptr;
            errors->setName("value");
            bool in_value = ValueConversions<bool>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetAttachToFrames(in_value);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setRemoteLocations(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* locationsValue = object ? object->get("locations") : nullptr;
            errors->setName("locations");
            std::unique_ptr<protocol::Array<protocol::Target::RemoteLocation>> in_locations = ValueConversions<protocol::Array<protocol::Target::RemoteLocation>>::fromValue(locationsValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetRemoteLocations(std::move(in_locations));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::sendMessageToTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* targetIdValue = object ? object->get("targetId") : nullptr;
            errors->setName("targetId");
            String in_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            protocol::Value* messageValue = object ? object->get("message") : nullptr;
            errors->setName("message");
            String in_message = ValueConversions<String>::fromValue(messageValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SendMessageToTarget(in_targetId, in_message);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getTargetInfo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* targetIdValue = object ? object->get("targetId") : nullptr;
            errors->setName("targetId");
            String in_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Target::TargetInfo> out_targetInfo;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->GetTargetInfo(in_targetId, &out_targetInfo);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("targetInfo", ValueConversions<protocol::Target::TargetInfo>::toValue(out_targetInfo.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::activateTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* targetIdValue = object ? object->get("targetId") : nullptr;
            errors->setName("targetId");
            String in_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->ActivateTarget(in_targetId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::closeTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* targetIdValue = object ? object->get("targetId") : nullptr;
            errors->setName("targetId");
            String in_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            bool out_success;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->CloseTarget(in_targetId, &out_success);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("success", ValueConversions<bool>::toValue(out_success));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::attachToTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* targetIdValue = object ? object->get("targetId") : nullptr;
            errors->setName("targetId");
            String in_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            bool out_success;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->AttachToTarget(in_targetId, &out_success);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("success", ValueConversions<bool>::toValue(out_success));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::detachFromTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* targetIdValue = object ? object->get("targetId") : nullptr;
            errors->setName("targetId");
            String in_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->DetachFromTarget(in_targetId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::createBrowserContext(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            String out_browserContextId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->CreateBrowserContext(&out_browserContextId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("browserContextId", ValueConversions<String>::toValue(out_browserContextId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::disposeBrowserContext(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* browserContextIdValue = object ? object->get("browserContextId") : nullptr;
            errors->setName("browserContextId");
            String in_browserContextId = ValueConversions<String>::fromValue(browserContextIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            bool out_success;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->DisposeBrowserContext(in_browserContextId, &out_success);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("success", ValueConversions<bool>::toValue(out_success));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::createTarget(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* widthValue = object ? object->get("width") : nullptr;
            Maybe<int> in_width;
            if (widthValue) {
                errors->setName("width");
                in_width = ValueConversions<int>::fromValue(widthValue, errors);
            }
            protocol::Value* heightValue = object ? object->get("height") : nullptr;
            Maybe<int> in_height;
            if (heightValue) {
                errors->setName("height");
                in_height = ValueConversions<int>::fromValue(heightValue, errors);
            }
            protocol::Value* browserContextIdValue = object ? object->get("browserContextId") : nullptr;
            Maybe<String> in_browserContextId;
            if (browserContextIdValue) {
                errors->setName("browserContextId");
                in_browserContextId = ValueConversions<String>::fromValue(browserContextIdValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_targetId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->CreateTarget(in_url, std::move(in_width), std::move(in_height), std::move(in_browserContextId), &out_targetId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("targetId", ValueConversions<String>::toValue(out_targetId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getTargets(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            std::unique_ptr<protocol::Array<protocol::Target::TargetInfo>> out_targetInfos;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->GetTargets(&out_targetInfos);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("targetInfos", ValueConversions<protocol::Array<protocol::Target::TargetInfo>>::toValue(out_targetInfos.get()));
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
            uber->registerBackend("Target", std::move(dispatcher));
        }

    } // Target
} // namespace content
} // namespace protocol
