// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Tracing.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Tracing {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Tracing";
        const char Metainfo::commandPrefix[] = "Tracing.";
        const char Metainfo::version[] = "1.2";

        const char* TraceConfig::RecordModeEnum::RecordUntilFull = "recordUntilFull";
        const char* TraceConfig::RecordModeEnum::RecordContinuously = "recordContinuously";
        const char* TraceConfig::RecordModeEnum::RecordAsMuchAsPossible = "recordAsMuchAsPossible";
        const char* TraceConfig::RecordModeEnum::EchoToConsole = "echoToConsole";

        std::unique_ptr<TraceConfig> TraceConfig::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<TraceConfig> result(new TraceConfig());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* recordModeValue = object->get("recordMode");
            if (recordModeValue) {
                errors->setName("recordMode");
                result->m_recordMode = ValueConversions<String>::fromValue(recordModeValue, errors);
            }
            protocol::Value* enableSamplingValue = object->get("enableSampling");
            if (enableSamplingValue) {
                errors->setName("enableSampling");
                result->m_enableSampling = ValueConversions<bool>::fromValue(enableSamplingValue, errors);
            }
            protocol::Value* enableSystraceValue = object->get("enableSystrace");
            if (enableSystraceValue) {
                errors->setName("enableSystrace");
                result->m_enableSystrace = ValueConversions<bool>::fromValue(enableSystraceValue, errors);
            }
            protocol::Value* enableArgumentFilterValue = object->get("enableArgumentFilter");
            if (enableArgumentFilterValue) {
                errors->setName("enableArgumentFilter");
                result->m_enableArgumentFilter = ValueConversions<bool>::fromValue(enableArgumentFilterValue, errors);
            }
            protocol::Value* includedCategoriesValue = object->get("includedCategories");
            if (includedCategoriesValue) {
                errors->setName("includedCategories");
                result->m_includedCategories = ValueConversions<protocol::Array<String>>::fromValue(includedCategoriesValue, errors);
            }
            protocol::Value* excludedCategoriesValue = object->get("excludedCategories");
            if (excludedCategoriesValue) {
                errors->setName("excludedCategories");
                result->m_excludedCategories = ValueConversions<protocol::Array<String>>::fromValue(excludedCategoriesValue, errors);
            }
            protocol::Value* syntheticDelaysValue = object->get("syntheticDelays");
            if (syntheticDelaysValue) {
                errors->setName("syntheticDelays");
                result->m_syntheticDelays = ValueConversions<protocol::Array<String>>::fromValue(syntheticDelaysValue, errors);
            }
            protocol::Value* memoryDumpConfigValue = object->get("memoryDumpConfig");
            if (memoryDumpConfigValue) {
                errors->setName("memoryDumpConfig");
                result->m_memoryDumpConfig = ValueConversions<protocol::Tracing::MemoryDumpConfig>::fromValue(memoryDumpConfigValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> TraceConfig::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (m_recordMode.isJust())
                result->setValue("recordMode", ValueConversions<String>::toValue(m_recordMode.fromJust()));
            if (m_enableSampling.isJust())
                result->setValue("enableSampling", ValueConversions<bool>::toValue(m_enableSampling.fromJust()));
            if (m_enableSystrace.isJust())
                result->setValue("enableSystrace", ValueConversions<bool>::toValue(m_enableSystrace.fromJust()));
            if (m_enableArgumentFilter.isJust())
                result->setValue("enableArgumentFilter", ValueConversions<bool>::toValue(m_enableArgumentFilter.fromJust()));
            if (m_includedCategories.isJust())
                result->setValue("includedCategories", ValueConversions<protocol::Array<String>>::toValue(m_includedCategories.fromJust()));
            if (m_excludedCategories.isJust())
                result->setValue("excludedCategories", ValueConversions<protocol::Array<String>>::toValue(m_excludedCategories.fromJust()));
            if (m_syntheticDelays.isJust())
                result->setValue("syntheticDelays", ValueConversions<protocol::Array<String>>::toValue(m_syntheticDelays.fromJust()));
            if (m_memoryDumpConfig.isJust())
                result->setValue("memoryDumpConfig", ValueConversions<protocol::Tracing::MemoryDumpConfig>::toValue(m_memoryDumpConfig.fromJust()));
            return result;
        }

        std::unique_ptr<TraceConfig> TraceConfig::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DataCollectedNotification> DataCollectedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DataCollectedNotification> result(new DataCollectedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* valueValue = object->get("value");
            errors->setName("value");
            result->m_value = ValueConversions<protocol::Array<protocol::DictionaryValue>>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DataCollectedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("value", ValueConversions<protocol::Array<protocol::DictionaryValue>>::toValue(m_value.get()));
            return result;
        }

        std::unique_ptr<DataCollectedNotification> DataCollectedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<TracingCompleteNotification> TracingCompleteNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<TracingCompleteNotification> result(new TracingCompleteNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* streamValue = object->get("stream");
            if (streamValue) {
                errors->setName("stream");
                result->m_stream = ValueConversions<String>::fromValue(streamValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> TracingCompleteNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (m_stream.isJust())
                result->setValue("stream", ValueConversions<String>::toValue(m_stream.fromJust()));
            return result;
        }

        std::unique_ptr<TracingCompleteNotification> TracingCompleteNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<BufferUsageNotification> BufferUsageNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<BufferUsageNotification> result(new BufferUsageNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* percentFullValue = object->get("percentFull");
            if (percentFullValue) {
                errors->setName("percentFull");
                result->m_percentFull = ValueConversions<double>::fromValue(percentFullValue, errors);
            }
            protocol::Value* eventCountValue = object->get("eventCount");
            if (eventCountValue) {
                errors->setName("eventCount");
                result->m_eventCount = ValueConversions<double>::fromValue(eventCountValue, errors);
            }
            protocol::Value* valueValue = object->get("value");
            if (valueValue) {
                errors->setName("value");
                result->m_value = ValueConversions<double>::fromValue(valueValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> BufferUsageNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (m_percentFull.isJust())
                result->setValue("percentFull", ValueConversions<double>::toValue(m_percentFull.fromJust()));
            if (m_eventCount.isJust())
                result->setValue("eventCount", ValueConversions<double>::toValue(m_eventCount.fromJust()));
            if (m_value.isJust())
                result->setValue("value", ValueConversions<double>::toValue(m_value.fromJust()));
            return result;
        }

        std::unique_ptr<BufferUsageNotification> BufferUsageNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        namespace Start {
            namespace TransferModeEnum {
                const char* ReportEvents = "ReportEvents";
                const char* ReturnAsStream = "ReturnAsStream";
            } // namespace TransferModeEnum
        } // namespace Start

        // ------------- Frontend notifications.

        void Frontend::dataCollected(std::unique_ptr<protocol::Array<protocol::DictionaryValue>> value)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DataCollectedNotification> messageData = DataCollectedNotification::create()
                                                                         .setValue(std::move(value))
                                                                         .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Tracing.dataCollected", std::move(messageData)));
        }

        void Frontend::tracingComplete(Maybe<String> stream)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<TracingCompleteNotification> messageData = TracingCompleteNotification::create()
                                                                           .build();
            if (stream.isJust())
                messageData->setStream(std::move(stream).takeJust());
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Tracing.tracingComplete", std::move(messageData)));
        }

        void Frontend::bufferUsage(Maybe<double> percentFull, Maybe<double> eventCount, Maybe<double> value)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<BufferUsageNotification> messageData = BufferUsageNotification::create()
                                                                       .build();
            if (percentFull.isJust())
                messageData->setPercentFull(std::move(percentFull).takeJust());
            if (eventCount.isJust())
                messageData->setEventCount(std::move(eventCount).takeJust());
            if (value.isJust())
                messageData->setValue(std::move(value).takeJust());
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Tracing.bufferUsage", std::move(messageData)));
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
                m_dispatchMap["Tracing.start"] = &DispatcherImpl::start;
                m_dispatchMap["Tracing.end"] = &DispatcherImpl::end;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status start(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status end(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        class StartCallbackImpl : public Backend::StartCallback, public DispatcherBase::Callback {
        public:
            StartCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
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

        DispatchResponse::Status DispatcherImpl::start(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* categoriesValue = object ? object->get("categories") : nullptr;
            Maybe<String> in_categories;
            if (categoriesValue) {
                errors->setName("categories");
                in_categories = ValueConversions<String>::fromValue(categoriesValue, errors);
            }
            protocol::Value* optionsValue = object ? object->get("options") : nullptr;
            Maybe<String> in_options;
            if (optionsValue) {
                errors->setName("options");
                in_options = ValueConversions<String>::fromValue(optionsValue, errors);
            }
            protocol::Value* bufferUsageReportingIntervalValue = object ? object->get("bufferUsageReportingInterval") : nullptr;
            Maybe<double> in_bufferUsageReportingInterval;
            if (bufferUsageReportingIntervalValue) {
                errors->setName("bufferUsageReportingInterval");
                in_bufferUsageReportingInterval = ValueConversions<double>::fromValue(bufferUsageReportingIntervalValue, errors);
            }
            protocol::Value* transferModeValue = object ? object->get("transferMode") : nullptr;
            Maybe<String> in_transferMode;
            if (transferModeValue) {
                errors->setName("transferMode");
                in_transferMode = ValueConversions<String>::fromValue(transferModeValue, errors);
            }
            protocol::Value* traceConfigValue = object ? object->get("traceConfig") : nullptr;
            Maybe<protocol::Tracing::TraceConfig> in_traceConfig;
            if (traceConfigValue) {
                errors->setName("traceConfig");
                in_traceConfig = ValueConversions<protocol::Tracing::TraceConfig>::fromValue(traceConfigValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<StartCallbackImpl> callback(new StartCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->start(std::move(in_categories), std::move(in_options), std::move(in_bufferUsageReportingInterval), std::move(in_transferMode), std::move(in_traceConfig), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class EndCallbackImpl : public Backend::EndCallback, public DispatcherBase::Callback {
        public:
            EndCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
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

        DispatchResponse::Status DispatcherImpl::end(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<EndCallbackImpl> callback(new EndCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->end(std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Tracing", std::move(dispatcher));
        }

    } // Tracing
} // namespace blink
} // namespace protocol
