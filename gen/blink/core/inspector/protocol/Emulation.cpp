// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Emulation.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Emulation {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Emulation";
        const char Metainfo::commandPrefix[] = "Emulation.";
        const char Metainfo::version[] = "1.2";

        const char* ScreenOrientation::TypeEnum::PortraitPrimary = "portraitPrimary";
        const char* ScreenOrientation::TypeEnum::PortraitSecondary = "portraitSecondary";
        const char* ScreenOrientation::TypeEnum::LandscapePrimary = "landscapePrimary";
        const char* ScreenOrientation::TypeEnum::LandscapeSecondary = "landscapeSecondary";

        std::unique_ptr<ScreenOrientation> ScreenOrientation::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ScreenOrientation> result(new ScreenOrientation());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* angleValue = object->get("angle");
            errors->setName("angle");
            result->m_angle = ValueConversions<int>::fromValue(angleValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ScreenOrientation::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            result->setValue("angle", ValueConversions<int>::toValue(m_angle));
            return result;
        }

        std::unique_ptr<ScreenOrientation> ScreenOrientation::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace VirtualTimePolicyEnum {
            const char* Advance = "advance";
            const char* Pause = "pause";
            const char* PauseIfNetworkFetchesPending = "pauseIfNetworkFetchesPending";
        } // namespace VirtualTimePolicyEnum

        // ------------- Enum values from params.

        namespace SetTouchEmulationEnabled {
            namespace ConfigurationEnum {
                const char* Mobile = "mobile";
                const char* Desktop = "desktop";
            } // namespace ConfigurationEnum
        } // namespace SetTouchEmulationEnabled

        // ------------- Frontend notifications.

        void Frontend::virtualTimeBudgetExpired()
        {
            if (!m_frontendChannel)
                return;
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Emulation.virtualTimeBudgetExpired"));
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
                m_dispatchMap["Emulation.forceViewport"] = &DispatcherImpl::forceViewport;
                m_dispatchMap["Emulation.resetViewport"] = &DispatcherImpl::resetViewport;
                m_dispatchMap["Emulation.resetPageScaleFactor"] = &DispatcherImpl::resetPageScaleFactor;
                m_dispatchMap["Emulation.setPageScaleFactor"] = &DispatcherImpl::setPageScaleFactor;
                m_dispatchMap["Emulation.setScriptExecutionDisabled"] = &DispatcherImpl::setScriptExecutionDisabled;
                m_dispatchMap["Emulation.setTouchEmulationEnabled"] = &DispatcherImpl::setTouchEmulationEnabled;
                m_dispatchMap["Emulation.setEmulatedMedia"] = &DispatcherImpl::setEmulatedMedia;
                m_dispatchMap["Emulation.setCPUThrottlingRate"] = &DispatcherImpl::setCPUThrottlingRate;
                m_dispatchMap["Emulation.setVirtualTimePolicy"] = &DispatcherImpl::setVirtualTimePolicy;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status forceViewport(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status resetViewport(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status resetPageScaleFactor(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setPageScaleFactor(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setScriptExecutionDisabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setTouchEmulationEnabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setEmulatedMedia(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setCPUThrottlingRate(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setVirtualTimePolicy(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::forceViewport(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            double in_x = ValueConversions<double>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            double in_y = ValueConversions<double>::fromValue(yValue, errors);
            protocol::Value* scaleValue = object ? object->get("scale") : nullptr;
            errors->setName("scale");
            double in_scale = ValueConversions<double>::fromValue(scaleValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->forceViewport(in_x, in_y, in_scale);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::resetViewport(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->resetViewport();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::resetPageScaleFactor(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->resetPageScaleFactor();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setPageScaleFactor(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* pageScaleFactorValue = object ? object->get("pageScaleFactor") : nullptr;
            errors->setName("pageScaleFactor");
            double in_pageScaleFactor = ValueConversions<double>::fromValue(pageScaleFactorValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setPageScaleFactor(in_pageScaleFactor);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setScriptExecutionDisabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
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
            DispatchResponse response = m_backend->setScriptExecutionDisabled(in_value);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setTouchEmulationEnabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* enabledValue = object ? object->get("enabled") : nullptr;
            errors->setName("enabled");
            bool in_enabled = ValueConversions<bool>::fromValue(enabledValue, errors);
            protocol::Value* configurationValue = object ? object->get("configuration") : nullptr;
            Maybe<String> in_configuration;
            if (configurationValue) {
                errors->setName("configuration");
                in_configuration = ValueConversions<String>::fromValue(configurationValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setTouchEmulationEnabled(in_enabled, std::move(in_configuration));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setEmulatedMedia(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* mediaValue = object ? object->get("media") : nullptr;
            errors->setName("media");
            String in_media = ValueConversions<String>::fromValue(mediaValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setEmulatedMedia(in_media);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setCPUThrottlingRate(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* rateValue = object ? object->get("rate") : nullptr;
            errors->setName("rate");
            double in_rate = ValueConversions<double>::fromValue(rateValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setCPUThrottlingRate(in_rate);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setVirtualTimePolicy(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* policyValue = object ? object->get("policy") : nullptr;
            errors->setName("policy");
            String in_policy = ValueConversions<String>::fromValue(policyValue, errors);
            protocol::Value* budgetValue = object ? object->get("budget") : nullptr;
            Maybe<int> in_budget;
            if (budgetValue) {
                errors->setName("budget");
                in_budget = ValueConversions<int>::fromValue(budgetValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setVirtualTimePolicy(in_policy, std::move(in_budget));
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
            uber->registerBackend("Emulation", std::move(dispatcher));
        }

    } // Emulation
} // namespace blink
} // namespace protocol
