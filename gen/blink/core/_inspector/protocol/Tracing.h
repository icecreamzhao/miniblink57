// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Tracing_h
#define blink_protocol_Tracing_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "core/inspector/protocol/IO.h"

namespace blink {
namespace protocol {
    namespace Tracing {

        // ------------- Forward and enum declarations.
        // Configuration for memory dump. Used only when "memory-infra" category is enabled.
        using MemoryDumpConfig = Object;
        //
        class TraceConfig;
        // Wrapper for notification params
        class DataCollectedNotification;
        // Wrapper for notification params
        class TracingCompleteNotification;
        // Wrapper for notification params
        class BufferUsageNotification;

        namespace Start {
            namespace TransferModeEnum {
                CORE_EXPORT extern const char* ReportEvents;
                CORE_EXPORT extern const char* ReturnAsStream;
            } // TransferModeEnum
        } // Start

        // ------------- Type and builder declarations.

        //
        class CORE_EXPORT TraceConfig : public Serializable {
            PROTOCOL_DISALLOW_COPY(TraceConfig);

        public:
            static std::unique_ptr<TraceConfig> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~TraceConfig() override { }

            struct CORE_EXPORT RecordModeEnum {
                static const char* RecordUntilFull;
                static const char* RecordContinuously;
                static const char* RecordAsMuchAsPossible;
                static const char* EchoToConsole;
            }; // RecordModeEnum

            bool hasRecordMode() { return m_recordMode.isJust(); }
            String getRecordMode(const String& defaultValue) { return m_recordMode.isJust() ? m_recordMode.fromJust() : defaultValue; }
            void setRecordMode(const String& value) { m_recordMode = value; }

            bool hasEnableSampling() { return m_enableSampling.isJust(); }
            bool getEnableSampling(bool defaultValue) { return m_enableSampling.isJust() ? m_enableSampling.fromJust() : defaultValue; }
            void setEnableSampling(bool value) { m_enableSampling = value; }

            bool hasEnableSystrace() { return m_enableSystrace.isJust(); }
            bool getEnableSystrace(bool defaultValue) { return m_enableSystrace.isJust() ? m_enableSystrace.fromJust() : defaultValue; }
            void setEnableSystrace(bool value) { m_enableSystrace = value; }

            bool hasEnableArgumentFilter() { return m_enableArgumentFilter.isJust(); }
            bool getEnableArgumentFilter(bool defaultValue) { return m_enableArgumentFilter.isJust() ? m_enableArgumentFilter.fromJust() : defaultValue; }
            void setEnableArgumentFilter(bool value) { m_enableArgumentFilter = value; }

            bool hasIncludedCategories() { return m_includedCategories.isJust(); }
            protocol::Array<String>* getIncludedCategories(protocol::Array<String>* defaultValue) { return m_includedCategories.isJust() ? m_includedCategories.fromJust() : defaultValue; }
            void setIncludedCategories(std::unique_ptr<protocol::Array<String>> value) { m_includedCategories = std::move(value); }

            bool hasExcludedCategories() { return m_excludedCategories.isJust(); }
            protocol::Array<String>* getExcludedCategories(protocol::Array<String>* defaultValue) { return m_excludedCategories.isJust() ? m_excludedCategories.fromJust() : defaultValue; }
            void setExcludedCategories(std::unique_ptr<protocol::Array<String>> value) { m_excludedCategories = std::move(value); }

            bool hasSyntheticDelays() { return m_syntheticDelays.isJust(); }
            protocol::Array<String>* getSyntheticDelays(protocol::Array<String>* defaultValue) { return m_syntheticDelays.isJust() ? m_syntheticDelays.fromJust() : defaultValue; }
            void setSyntheticDelays(std::unique_ptr<protocol::Array<String>> value) { m_syntheticDelays = std::move(value); }

            bool hasMemoryDumpConfig() { return m_memoryDumpConfig.isJust(); }
            protocol::Tracing::MemoryDumpConfig* getMemoryDumpConfig(protocol::Tracing::MemoryDumpConfig* defaultValue) { return m_memoryDumpConfig.isJust() ? m_memoryDumpConfig.fromJust() : defaultValue; }
            void setMemoryDumpConfig(std::unique_ptr<protocol::Tracing::MemoryDumpConfig> value) { m_memoryDumpConfig = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<TraceConfig> clone() const;

            template <int STATE>
            class TraceConfigBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    AllFieldsSet = (0)
                };

                TraceConfigBuilder<STATE>& setRecordMode(const String& value)
                {
                    m_result->setRecordMode(value);
                    return *this;
                }

                TraceConfigBuilder<STATE>& setEnableSampling(bool value)
                {
                    m_result->setEnableSampling(value);
                    return *this;
                }

                TraceConfigBuilder<STATE>& setEnableSystrace(bool value)
                {
                    m_result->setEnableSystrace(value);
                    return *this;
                }

                TraceConfigBuilder<STATE>& setEnableArgumentFilter(bool value)
                {
                    m_result->setEnableArgumentFilter(value);
                    return *this;
                }

                TraceConfigBuilder<STATE>& setIncludedCategories(std::unique_ptr<protocol::Array<String>> value)
                {
                    m_result->setIncludedCategories(std::move(value));
                    return *this;
                }

                TraceConfigBuilder<STATE>& setExcludedCategories(std::unique_ptr<protocol::Array<String>> value)
                {
                    m_result->setExcludedCategories(std::move(value));
                    return *this;
                }

                TraceConfigBuilder<STATE>& setSyntheticDelays(std::unique_ptr<protocol::Array<String>> value)
                {
                    m_result->setSyntheticDelays(std::move(value));
                    return *this;
                }

                TraceConfigBuilder<STATE>& setMemoryDumpConfig(std::unique_ptr<protocol::Tracing::MemoryDumpConfig> value)
                {
                    m_result->setMemoryDumpConfig(std::move(value));
                    return *this;
                }

                std::unique_ptr<TraceConfig> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class TraceConfig;
                TraceConfigBuilder()
                    : m_result(new TraceConfig())
                {
                }

                template <int STEP>
                TraceConfigBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<TraceConfigBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Tracing::TraceConfig> m_result;
            };

            static TraceConfigBuilder<0> create()
            {
                return TraceConfigBuilder<0>();
            }

        private:
            TraceConfig()
            {
            }

            Maybe<String> m_recordMode;
            Maybe<bool> m_enableSampling;
            Maybe<bool> m_enableSystrace;
            Maybe<bool> m_enableArgumentFilter;
            Maybe<protocol::Array<String>> m_includedCategories;
            Maybe<protocol::Array<String>> m_excludedCategories;
            Maybe<protocol::Array<String>> m_syntheticDelays;
            Maybe<protocol::Tracing::MemoryDumpConfig> m_memoryDumpConfig;
        };

        // Wrapper for notification params
        class CORE_EXPORT DataCollectedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DataCollectedNotification);

        public:
            static std::unique_ptr<DataCollectedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DataCollectedNotification() override { }

            protocol::Array<protocol::DictionaryValue>* getValue() { return m_value.get(); }
            void setValue(std::unique_ptr<protocol::Array<protocol::DictionaryValue>> value) { m_value = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DataCollectedNotification> clone() const;

            template <int STATE>
            class DataCollectedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ValueSet = 1 << 1,
                    AllFieldsSet = (ValueSet | 0)
                };

                DataCollectedNotificationBuilder<STATE | ValueSet>& setValue(std::unique_ptr<protocol::Array<protocol::DictionaryValue>> value)
                {
                    static_assert(!(STATE & ValueSet), "property value should not be set yet");
                    m_result->setValue(std::move(value));
                    return castState<ValueSet>();
                }

                std::unique_ptr<DataCollectedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DataCollectedNotification;
                DataCollectedNotificationBuilder()
                    : m_result(new DataCollectedNotification())
                {
                }

                template <int STEP>
                DataCollectedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DataCollectedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Tracing::DataCollectedNotification> m_result;
            };

            static DataCollectedNotificationBuilder<0> create()
            {
                return DataCollectedNotificationBuilder<0>();
            }

        private:
            DataCollectedNotification()
            {
            }

            std::unique_ptr<protocol::Array<protocol::DictionaryValue>> m_value;
        };

        // Wrapper for notification params
        class CORE_EXPORT TracingCompleteNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(TracingCompleteNotification);

        public:
            static std::unique_ptr<TracingCompleteNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~TracingCompleteNotification() override { }

            bool hasStream() { return m_stream.isJust(); }
            String getStream(const String& defaultValue) { return m_stream.isJust() ? m_stream.fromJust() : defaultValue; }
            void setStream(const String& value) { m_stream = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<TracingCompleteNotification> clone() const;

            template <int STATE>
            class TracingCompleteNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    AllFieldsSet = (0)
                };

                TracingCompleteNotificationBuilder<STATE>& setStream(const String& value)
                {
                    m_result->setStream(value);
                    return *this;
                }

                std::unique_ptr<TracingCompleteNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class TracingCompleteNotification;
                TracingCompleteNotificationBuilder()
                    : m_result(new TracingCompleteNotification())
                {
                }

                template <int STEP>
                TracingCompleteNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<TracingCompleteNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Tracing::TracingCompleteNotification> m_result;
            };

            static TracingCompleteNotificationBuilder<0> create()
            {
                return TracingCompleteNotificationBuilder<0>();
            }

        private:
            TracingCompleteNotification()
            {
            }

            Maybe<String> m_stream;
        };

        // Wrapper for notification params
        class CORE_EXPORT BufferUsageNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(BufferUsageNotification);

        public:
            static std::unique_ptr<BufferUsageNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~BufferUsageNotification() override { }

            bool hasPercentFull() { return m_percentFull.isJust(); }
            double getPercentFull(double defaultValue) { return m_percentFull.isJust() ? m_percentFull.fromJust() : defaultValue; }
            void setPercentFull(double value) { m_percentFull = value; }

            bool hasEventCount() { return m_eventCount.isJust(); }
            double getEventCount(double defaultValue) { return m_eventCount.isJust() ? m_eventCount.fromJust() : defaultValue; }
            void setEventCount(double value) { m_eventCount = value; }

            bool hasValue() { return m_value.isJust(); }
            double getValue(double defaultValue) { return m_value.isJust() ? m_value.fromJust() : defaultValue; }
            void setValue(double value) { m_value = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<BufferUsageNotification> clone() const;

            template <int STATE>
            class BufferUsageNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    AllFieldsSet = (0)
                };

                BufferUsageNotificationBuilder<STATE>& setPercentFull(double value)
                {
                    m_result->setPercentFull(value);
                    return *this;
                }

                BufferUsageNotificationBuilder<STATE>& setEventCount(double value)
                {
                    m_result->setEventCount(value);
                    return *this;
                }

                BufferUsageNotificationBuilder<STATE>& setValue(double value)
                {
                    m_result->setValue(value);
                    return *this;
                }

                std::unique_ptr<BufferUsageNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class BufferUsageNotification;
                BufferUsageNotificationBuilder()
                    : m_result(new BufferUsageNotification())
                {
                }

                template <int STEP>
                BufferUsageNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<BufferUsageNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Tracing::BufferUsageNotification> m_result;
            };

            static BufferUsageNotificationBuilder<0> create()
            {
                return BufferUsageNotificationBuilder<0>();
            }

        private:
            BufferUsageNotification()
            {
            }

            Maybe<double> m_percentFull;
            Maybe<double> m_eventCount;
            Maybe<double> m_value;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            class CORE_EXPORT StartCallback {
            public:
                virtual void sendSuccess() = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~StartCallback() { }
            };
            virtual void start(Maybe<String> in_categories, Maybe<String> in_options, Maybe<double> in_bufferUsageReportingInterval, Maybe<String> in_transferMode, Maybe<protocol::Tracing::TraceConfig> in_traceConfig, std::unique_ptr<StartCallback> callback) = 0;
            class CORE_EXPORT EndCallback {
            public:
                virtual void sendSuccess() = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~EndCallback() { }
            };
            virtual void end(std::unique_ptr<EndCallback> callback) = 0;

            virtual DispatchResponse disable()
            {
                return DispatchResponse::OK();
            }
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void dataCollected(std::unique_ptr<protocol::Array<protocol::DictionaryValue>> value);
            void tracingComplete(Maybe<String> stream = Maybe<String>());
            void bufferUsage(Maybe<double> percentFull = Maybe<double>(), Maybe<double> eventCount = Maybe<double>(), Maybe<double> value = Maybe<double>());

            void flush();
            void sendRawNotification(const String&);

        private:
            FrontendChannel* m_frontendChannel;
        };

        // ------------- Dispatcher.

        class CORE_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CORE_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace Tracing
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Tracing_h)
