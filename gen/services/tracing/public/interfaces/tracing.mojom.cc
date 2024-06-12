// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "services/tracing/public/interfaces/tracing.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace tracing {
namespace mojom { // static
    StartupPerformanceTimesPtr StartupPerformanceTimes::New()
    {
        StartupPerformanceTimesPtr rv;
        mojo::internal::StructHelper<StartupPerformanceTimes>::Initialize(&rv);
        return rv;
    }

    StartupPerformanceTimes::StartupPerformanceTimes()
        : service_manager_process_creation_time()
        , service_manager_main_entry_point_time()
        , browser_message_loop_start_ticks()
        , browser_window_display_ticks()
        , browser_open_tabs_time_delta()
        , first_web_contents_main_frame_load_ticks()
        , first_visually_non_empty_layout_ticks()
    {
    }

    StartupPerformanceTimes::~StartupPerformanceTimes()
    {
    }
    size_t StartupPerformanceTimes::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->service_manager_process_creation_time);
        seed = mojo::internal::Hash(seed, this->service_manager_main_entry_point_time);
        seed = mojo::internal::Hash(seed, this->browser_message_loop_start_ticks);
        seed = mojo::internal::Hash(seed, this->browser_window_display_ticks);
        seed = mojo::internal::Hash(seed, this->browser_open_tabs_time_delta);
        seed = mojo::internal::Hash(seed, this->first_web_contents_main_frame_load_ticks);
        seed = mojo::internal::Hash(seed, this->first_visually_non_empty_layout_ticks);
        return seed;
    }
    const char Provider::Name_[] = "tracing::mojom::Provider";

    ProviderProxy::ProviderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ProviderProxy::StartTracing(
        const std::string& in_categories, RecorderPtr in_recorder)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::Provider_StartTracing_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_categories, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kProvider_StartTracing_Name, size);

        auto params = ::tracing::mojom::internal::Provider_StartTracing_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->categories)::BaseType* categories_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_categories, builder.buffer(), &categories_ptr, &serialization_context);
        params->categories.Set(categories_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->categories.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null categories in Provider.StartTracing request");
        mojo::internal::Serialize<::tracing::mojom::RecorderPtrDataView>(
            in_recorder, &params->recorder, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->recorder),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid recorder in Provider.StartTracing request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ProviderProxy::StopTracing()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::Provider_StopTracing_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kProvider_StopTracing_Name, size);

        auto params = ::tracing::mojom::internal::Provider_StopTracing_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ProviderStubDispatch::Accept(
        Provider* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kProvider_StartTracing_Name: {
            internal::Provider_StartTracing_Params_Data* params = reinterpret_cast<internal::Provider_StartTracing_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_categories {};
            RecorderPtr p_recorder {};
            Provider_StartTracing_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadCategories(&p_categories))
                success = false;
            p_recorder = input_data_view.TakeRecorder<decltype(p_recorder)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Provider::StartTracing deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Provider::StartTracing");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartTracing(
                std::move(p_categories),
                std::move(p_recorder));
            return true;
        }
        case internal::kProvider_StopTracing_Name: {
            internal::Provider_StopTracing_Params_Data* params = reinterpret_cast<internal::Provider_StopTracing_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Provider_StopTracing_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Provider::StopTracing deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Provider::StopTracing");
            mojo::internal::MessageDispatchContext context(message);
            impl->StopTracing();
            return true;
        }
        }
        return false;
    }

    // static
    bool ProviderStubDispatch::AcceptWithResponder(
        Provider* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kProvider_StartTracing_Name: {
            break;
        }
        case internal::kProvider_StopTracing_Name: {
            break;
        }
        }
        return false;
    }

    bool ProviderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Provider RequestValidator");

        switch (message->header()->name) {
        case internal::kProvider_StartTracing_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Provider_StartTracing_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kProvider_StopTracing_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Provider_StopTracing_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char Recorder::Name_[] = "tracing::mojom::Recorder";

    RecorderProxy::RecorderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RecorderProxy::Record(
        const std::string& in_json)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::Recorder_Record_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_json, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRecorder_Record_Name, size);

        auto params = ::tracing::mojom::internal::Recorder_Record_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->json)::BaseType* json_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_json, builder.buffer(), &json_ptr, &serialization_context);
        params->json.Set(json_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->json.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null json in Recorder.Record request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RecorderStubDispatch::Accept(
        Recorder* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRecorder_Record_Name: {
            internal::Recorder_Record_Params_Data* params = reinterpret_cast<internal::Recorder_Record_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_json {};
            Recorder_Record_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadJson(&p_json))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Recorder::Record deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Recorder::Record");
            mojo::internal::MessageDispatchContext context(message);
            impl->Record(
                std::move(p_json));
            return true;
        }
        }
        return false;
    }

    // static
    bool RecorderStubDispatch::AcceptWithResponder(
        Recorder* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRecorder_Record_Name: {
            break;
        }
        }
        return false;
    }

    bool RecorderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Recorder RequestValidator");

        switch (message->header()->name) {
        case internal::kRecorder_Record_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Recorder_Record_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char Collector::Name_[] = "tracing::mojom::Collector";

    CollectorProxy::CollectorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void CollectorProxy::Start(
        mojo::ScopedDataPipeProducerHandle in_stream, const std::string& in_categories)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::Collector_Start_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_categories, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCollector_Start_Name, size);

        auto params = ::tracing::mojom::internal::Collector_Start_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedDataPipeProducerHandle>(
            in_stream, &params->stream, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->stream),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid stream in Collector.Start request");
        typename decltype(params->categories)::BaseType* categories_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_categories, builder.buffer(), &categories_ptr, &serialization_context);
        params->categories.Set(categories_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->categories.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null categories in Collector.Start request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CollectorProxy::StopAndFlush()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::Collector_StopAndFlush_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kCollector_StopAndFlush_Name, size);

        auto params = ::tracing::mojom::internal::Collector_StopAndFlush_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool CollectorStubDispatch::Accept(
        Collector* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kCollector_Start_Name: {
            internal::Collector_Start_Params_Data* params = reinterpret_cast<internal::Collector_Start_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedDataPipeProducerHandle p_stream {};
            std::string p_categories {};
            Collector_Start_ParamsDataView input_data_view(params,
                context);

            p_stream = input_data_view.TakeStream();
            if (!input_data_view.ReadCategories(&p_categories))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Collector::Start deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Collector::Start");
            mojo::internal::MessageDispatchContext context(message);
            impl->Start(
                std::move(p_stream),
                std::move(p_categories));
            return true;
        }
        case internal::kCollector_StopAndFlush_Name: {
            internal::Collector_StopAndFlush_Params_Data* params = reinterpret_cast<internal::Collector_StopAndFlush_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Collector_StopAndFlush_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Collector::StopAndFlush deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Collector::StopAndFlush");
            mojo::internal::MessageDispatchContext context(message);
            impl->StopAndFlush();
            return true;
        }
        }
        return false;
    }

    // static
    bool CollectorStubDispatch::AcceptWithResponder(
        Collector* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kCollector_Start_Name: {
            break;
        }
        case internal::kCollector_StopAndFlush_Name: {
            break;
        }
        }
        return false;
    }

    bool CollectorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Collector RequestValidator");

        switch (message->header()->name) {
        case internal::kCollector_Start_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Collector_Start_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCollector_StopAndFlush_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Collector_StopAndFlush_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char StartupPerformanceDataCollector::Name_[] = "tracing::mojom::StartupPerformanceDataCollector";

    class StartupPerformanceDataCollector_GetStartupPerformanceTimes_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ForwardToCallback(
            const StartupPerformanceDataCollector::GetStartupPerformanceTimesCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        StartupPerformanceDataCollector::GetStartupPerformanceTimesCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(StartupPerformanceDataCollector_GetStartupPerformanceTimes_ForwardToCallback);
    };
    bool StartupPerformanceDataCollector_GetStartupPerformanceTimes_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        StartupPerformanceTimesPtr p_times {};
        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadTimes(&p_times))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "StartupPerformanceDataCollector::GetStartupPerformanceTimes response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_times));
        }
        return true;
    }

    StartupPerformanceDataCollectorProxy::StartupPerformanceDataCollectorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void StartupPerformanceDataCollectorProxy::SetServiceManagerProcessCreationTime(
        int64_t in_time)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->time = in_time;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::SetServiceManagerMainEntryPointTime(
        int64_t in_time)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->time = in_time;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::SetBrowserMessageLoopStartTicks(
        int64_t in_ticks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->ticks = in_ticks;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::SetBrowserWindowDisplayTicks(
        int64_t in_ticks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->ticks = in_ticks;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::SetBrowserOpenTabsTimeDelta(
        int64_t in_delta)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->delta = in_delta;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::SetFirstWebContentsMainFrameLoadTicks(
        int64_t in_ticks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->ticks = in_ticks;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::SetFirstVisuallyNonEmptyLayoutTicks(
        int64_t in_ticks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kStartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->ticks = in_ticks;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void StartupPerformanceDataCollectorProxy::GetStartupPerformanceTimes(
        const GetStartupPerformanceTimesCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name, size);

        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new StartupPerformanceDataCollector_GetStartupPerformanceTimes_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder {
    public:
        static StartupPerformanceDataCollector::GetStartupPerformanceTimesCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder> proxy(
                new StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "StartupPerformanceDataCollector::GetStartupPerformanceTimes() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            StartupPerformanceTimesPtr in_times);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder);
    };

    void StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder::Run(
        StartupPerformanceTimesPtr in_times)
    {
        size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::tracing::mojom::StartupPerformanceTimesDataView>(
            in_times, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::tracing::mojom::internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->times)::BaseType* times_ptr;
        mojo::internal::Serialize<::tracing::mojom::StartupPerformanceTimesDataView>(
            in_times, builder.buffer(), &times_ptr, &serialization_context_);
        params->times.Set(times_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->times.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null times in StartupPerformanceDataCollector.GetStartupPerformanceTimes response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool StartupPerformanceDataCollectorStubDispatch::Accept(
        StartupPerformanceDataCollector* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kStartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Name: {
            internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_time {};
            StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_ParamsDataView input_data_view(params,
                context);

            p_time = input_data_view.time();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetServiceManagerProcessCreationTime deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetServiceManagerProcessCreationTime");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetServiceManagerProcessCreationTime(
                std::move(p_time));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Name: {
            internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_time {};
            StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_ParamsDataView input_data_view(params,
                context);

            p_time = input_data_view.time();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetServiceManagerMainEntryPointTime deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetServiceManagerMainEntryPointTime");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetServiceManagerMainEntryPointTime(
                std::move(p_time));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Name: {
            internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_ticks {};
            StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_ParamsDataView input_data_view(params,
                context);

            p_ticks = input_data_view.ticks();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetBrowserMessageLoopStartTicks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetBrowserMessageLoopStartTicks");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetBrowserMessageLoopStartTicks(
                std::move(p_ticks));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Name: {
            internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_ticks {};
            StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_ParamsDataView input_data_view(params,
                context);

            p_ticks = input_data_view.ticks();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetBrowserWindowDisplayTicks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetBrowserWindowDisplayTicks");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetBrowserWindowDisplayTicks(
                std::move(p_ticks));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Name: {
            internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_delta {};
            StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_ParamsDataView input_data_view(params,
                context);

            p_delta = input_data_view.delta();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetBrowserOpenTabsTimeDelta deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetBrowserOpenTabsTimeDelta");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetBrowserOpenTabsTimeDelta(
                std::move(p_delta));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Name: {
            internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_ticks {};
            StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_ParamsDataView input_data_view(params,
                context);

            p_ticks = input_data_view.ticks();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetFirstWebContentsMainFrameLoadTicks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetFirstWebContentsMainFrameLoadTicks");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetFirstWebContentsMainFrameLoadTicks(
                std::move(p_ticks));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Name: {
            internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_ticks {};
            StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_ParamsDataView input_data_view(params,
                context);

            p_ticks = input_data_view.ticks();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::SetFirstVisuallyNonEmptyLayoutTicks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::SetFirstVisuallyNonEmptyLayoutTicks");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetFirstVisuallyNonEmptyLayoutTicks(
                std::move(p_ticks));
            return true;
        }
        case internal::kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool StartupPerformanceDataCollectorStubDispatch::AcceptWithResponder(
        StartupPerformanceDataCollector* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kStartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Name: {
            break;
        }
        case internal::kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name: {
            internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data* params = reinterpret_cast<internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            StartupPerformanceDataCollector_GetStartupPerformanceTimes_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "StartupPerformanceDataCollector::GetStartupPerformanceTimes deserializer");
                return false;
            }
            StartupPerformanceDataCollector::GetStartupPerformanceTimesCallback callback = StartupPerformanceDataCollector_GetStartupPerformanceTimes_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "StartupPerformanceDataCollector::GetStartupPerformanceTimes");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetStartupPerformanceTimes(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool StartupPerformanceDataCollectorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "StartupPerformanceDataCollector RequestValidator");

        switch (message->header()->name) {
        case internal::kStartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    bool StartupPerformanceDataCollectorResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "StartupPerformanceDataCollector ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }
    const char Factory::Name_[] = "tracing::mojom::Factory";

    FactoryProxy::FactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void FactoryProxy::CreateRecorder(
        ProviderPtr in_provider)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::tracing::mojom::internal::Factory_CreateRecorder_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kFactory_CreateRecorder_Name, size);

        auto params = ::tracing::mojom::internal::Factory_CreateRecorder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::tracing::mojom::ProviderPtrDataView>(
            in_provider, &params->provider, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->provider),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid provider in Factory.CreateRecorder request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool FactoryStubDispatch::Accept(
        Factory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kFactory_CreateRecorder_Name: {
            internal::Factory_CreateRecorder_Params_Data* params = reinterpret_cast<internal::Factory_CreateRecorder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ProviderPtr p_provider {};
            Factory_CreateRecorder_ParamsDataView input_data_view(params,
                context);

            p_provider = input_data_view.TakeProvider<decltype(p_provider)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Factory::CreateRecorder deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Factory::CreateRecorder");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateRecorder(
                std::move(p_provider));
            return true;
        }
        }
        return false;
    }

    // static
    bool FactoryStubDispatch::AcceptWithResponder(
        Factory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kFactory_CreateRecorder_Name: {
            break;
        }
        }
        return false;
    }

    bool FactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Factory RequestValidator");

        switch (message->header()->name) {
        case internal::kFactory_CreateRecorder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Factory_CreateRecorder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

} // namespace mojom
} // namespace tracing

namespace mojo {

// static
bool StructTraits<::tracing::mojom::StartupPerformanceTimes::DataView, ::tracing::mojom::StartupPerformanceTimesPtr>::Read(
    ::tracing::mojom::StartupPerformanceTimes::DataView input,
    ::tracing::mojom::StartupPerformanceTimesPtr* output)
{
    bool success = true;
    ::tracing::mojom::StartupPerformanceTimesPtr result(::tracing::mojom::StartupPerformanceTimes::New());

    result->service_manager_process_creation_time = input.service_manager_process_creation_time();
    result->service_manager_main_entry_point_time = input.service_manager_main_entry_point_time();
    result->browser_message_loop_start_ticks = input.browser_message_loop_start_ticks();
    result->browser_window_display_ticks = input.browser_window_display_ticks();
    result->browser_open_tabs_time_delta = input.browser_open_tabs_time_delta();
    result->first_web_contents_main_frame_load_ticks = input.first_web_contents_main_frame_load_ticks();
    result->first_visually_non_empty_layout_ticks = input.first_visually_non_empty_layout_ticks();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif