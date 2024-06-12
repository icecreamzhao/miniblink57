// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/system_info.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace SystemInfo {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "SystemInfo";
        const char Metainfo::commandPrefix[] = "SystemInfo.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<GPUDevice> GPUDevice::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<GPUDevice> result(new GPUDevice());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* vendorIdValue = object->get("vendorId");
            errors->setName("vendorId");
            result->m_vendorId = ValueConversions<double>::fromValue(vendorIdValue, errors);
            protocol::Value* deviceIdValue = object->get("deviceId");
            errors->setName("deviceId");
            result->m_deviceId = ValueConversions<double>::fromValue(deviceIdValue, errors);
            protocol::Value* vendorStringValue = object->get("vendorString");
            errors->setName("vendorString");
            result->m_vendorString = ValueConversions<String>::fromValue(vendorStringValue, errors);
            protocol::Value* deviceStringValue = object->get("deviceString");
            errors->setName("deviceString");
            result->m_deviceString = ValueConversions<String>::fromValue(deviceStringValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> GPUDevice::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("vendorId", ValueConversions<double>::toValue(m_vendorId));
            result->setValue("deviceId", ValueConversions<double>::toValue(m_deviceId));
            result->setValue("vendorString", ValueConversions<String>::toValue(m_vendorString));
            result->setValue("deviceString", ValueConversions<String>::toValue(m_deviceString));
            return result;
        }

        std::unique_ptr<GPUDevice> GPUDevice::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<GPUInfo> GPUInfo::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<GPUInfo> result(new GPUInfo());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* devicesValue = object->get("devices");
            errors->setName("devices");
            result->m_devices = ValueConversions<protocol::Array<protocol::SystemInfo::GPUDevice>>::fromValue(devicesValue, errors);
            protocol::Value* auxAttributesValue = object->get("auxAttributes");
            if (auxAttributesValue) {
                errors->setName("auxAttributes");
                result->m_auxAttributes = ValueConversions<protocol::DictionaryValue>::fromValue(auxAttributesValue, errors);
            }
            protocol::Value* featureStatusValue = object->get("featureStatus");
            if (featureStatusValue) {
                errors->setName("featureStatus");
                result->m_featureStatus = ValueConversions<protocol::DictionaryValue>::fromValue(featureStatusValue, errors);
            }
            protocol::Value* driverBugWorkaroundsValue = object->get("driverBugWorkarounds");
            errors->setName("driverBugWorkarounds");
            result->m_driverBugWorkarounds = ValueConversions<protocol::Array<String>>::fromValue(driverBugWorkaroundsValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> GPUInfo::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("devices", ValueConversions<protocol::Array<protocol::SystemInfo::GPUDevice>>::toValue(m_devices.get()));
            if (m_auxAttributes.isJust())
                result->setValue("auxAttributes", ValueConversions<protocol::DictionaryValue>::toValue(m_auxAttributes.fromJust()));
            if (m_featureStatus.isJust())
                result->setValue("featureStatus", ValueConversions<protocol::DictionaryValue>::toValue(m_featureStatus.fromJust()));
            result->setValue("driverBugWorkarounds", ValueConversions<protocol::Array<String>>::toValue(m_driverBugWorkarounds.get()));
            return result;
        }

        std::unique_ptr<GPUInfo> GPUInfo::clone() const
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
                m_dispatchMap["SystemInfo.getInfo"] = &DispatcherImpl::getInfo;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status getInfo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        class GetInfoCallbackImpl : public Backend::GetInfoCallback, public DispatcherBase::Callback {
        public:
            GetInfoCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(std::unique_ptr<protocol::SystemInfo::GPUInfo> gpu, const String& modelName, const String& modelVersion) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("gpu", ValueConversions<protocol::SystemInfo::GPUInfo>::toValue(gpu.get()));
                resultObject->setValue("modelName", ValueConversions<String>::toValue(modelName));
                resultObject->setValue("modelVersion", ValueConversions<String>::toValue(modelVersion));
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

        DispatchResponse::Status DispatcherImpl::getInfo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<GetInfoCallbackImpl> callback(new GetInfoCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->GetInfo(std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("SystemInfo", std::move(dispatcher));
        }

    } // SystemInfo
} // namespace content
} // namespace protocol
