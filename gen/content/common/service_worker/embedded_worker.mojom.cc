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

#include "content/common/service_worker/embedded_worker.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/frame_messages.h"
#include "content/common/indexed_db/indexed_db_enum_traits.h"
#include "content/common/indexed_db/indexed_db_struct_traits.h"
#include "content/common/media/media_devices_param_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/common/resource_messages.h"
#include "content/common/service_worker/embedded_worker_messages.h"
#include "content/common/service_worker/service_worker_messages.h"
#include "content/common/service_worker/service_worker_status_code_traits.h"
#include "content/common/service_worker/service_worker_types_traits.h"
#include "content/common/view_messages.h"
#include "content/public/common/common_param_traits.h"
#include "content/public/common/common_param_traits_macros.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/capture/ipc/capture_param_traits.h"
#include "media/capture/ipc/capture_param_traits_macros.h"
#include "media/capture/mojo/video_capture_types_typemap_traits.h"
#include "media/mojo/interfaces/pipeline_statistics_struct_traits.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/base/mojo/window_open_disposition_enum_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
#include "ui/gfx/range/mojo/range_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace content {
namespace mojom {
    const char EmbeddedWorkerInstanceClient::Name_[] = "content::mojom::EmbeddedWorkerInstanceClient";

    class EmbeddedWorkerInstanceClient_StopWorker_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        EmbeddedWorkerInstanceClient_StopWorker_ForwardToCallback(
            const EmbeddedWorkerInstanceClient::StopWorkerCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        EmbeddedWorkerInstanceClient::StopWorkerCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(EmbeddedWorkerInstanceClient_StopWorker_ForwardToCallback);
    };
    bool EmbeddedWorkerInstanceClient_StopWorker_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data* params = reinterpret_cast<internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        EmbeddedWorkerInstanceClient_StopWorker_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "EmbeddedWorkerInstanceClient::StopWorker response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    EmbeddedWorkerInstanceClientProxy::EmbeddedWorkerInstanceClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void EmbeddedWorkerInstanceClientProxy::StartWorker(
        const ::content::EmbeddedWorkerStartParams& in_params, ::content::mojom::ServiceWorkerEventDispatcherRequest in_dispatcher_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::EmbeddedWorkerStartParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kEmbeddedWorkerInstanceClient_StartWorker_Name, size);

        auto params = ::content::mojom::internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::content::mojom::EmbeddedWorkerStartParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in EmbeddedWorkerInstanceClient.StartWorker request");
        mojo::internal::Serialize<::content::mojom::ServiceWorkerEventDispatcherRequestDataView>(
            in_dispatcher_request, &params->dispatcher_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->dispatcher_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid dispatcher_request in EmbeddedWorkerInstanceClient.StartWorker request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void EmbeddedWorkerInstanceClientProxy::StopWorker(
        const StopWorkerCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kEmbeddedWorkerInstanceClient_StopWorker_Name, size);

        auto params = ::content::mojom::internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new EmbeddedWorkerInstanceClient_StopWorker_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void EmbeddedWorkerInstanceClientProxy::ResumeAfterDownload()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kEmbeddedWorkerInstanceClient_ResumeAfterDownload_Name, size);

        auto params = ::content::mojom::internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void EmbeddedWorkerInstanceClientProxy::AddMessageToConsole(
        ::blink::WebConsoleMessage::Level in_level, const std::string& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kEmbeddedWorkerInstanceClient_AddMessageToConsole_Name, size);

        auto params = ::content::mojom::internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::ConsoleMessageLevel>(
            in_level, &params->level);
        typename decltype(params->message)::BaseType* message_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_message, builder.buffer(), &message_ptr, &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in EmbeddedWorkerInstanceClient.AddMessageToConsole request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder {
    public:
        static EmbeddedWorkerInstanceClient::StopWorkerCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder> proxy(
                new EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "EmbeddedWorkerInstanceClient::StopWorker() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder(
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

        void Run();

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder);
    };

    void EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder::Run()
    {
        size_t size = sizeof(::content::mojom::internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kEmbeddedWorkerInstanceClient_StopWorker_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
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
    bool EmbeddedWorkerInstanceClientStubDispatch::Accept(
        EmbeddedWorkerInstanceClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kEmbeddedWorkerInstanceClient_StartWorker_Name: {
            internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data* params = reinterpret_cast<internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::content::EmbeddedWorkerStartParams p_params {};
            ::content::mojom::ServiceWorkerEventDispatcherRequest p_dispatcher_request {};
            EmbeddedWorkerInstanceClient_StartWorker_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadParams(&p_params))
                success = false;
            p_dispatcher_request = input_data_view.TakeDispatcherRequest<decltype(p_dispatcher_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "EmbeddedWorkerInstanceClient::StartWorker deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "EmbeddedWorkerInstanceClient::StartWorker");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartWorker(
                std::move(p_params),
                std::move(p_dispatcher_request));
            return true;
        }
        case internal::kEmbeddedWorkerInstanceClient_StopWorker_Name: {
            break;
        }
        case internal::kEmbeddedWorkerInstanceClient_ResumeAfterDownload_Name: {
            internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data* params = reinterpret_cast<internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            EmbeddedWorkerInstanceClient_ResumeAfterDownload_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "EmbeddedWorkerInstanceClient::ResumeAfterDownload deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "EmbeddedWorkerInstanceClient::ResumeAfterDownload");
            mojo::internal::MessageDispatchContext context(message);
            impl->ResumeAfterDownload();
            return true;
        }
        case internal::kEmbeddedWorkerInstanceClient_AddMessageToConsole_Name: {
            internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data* params = reinterpret_cast<internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::blink::WebConsoleMessage::Level p_level {};
            std::string p_message {};
            EmbeddedWorkerInstanceClient_AddMessageToConsole_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadLevel(&p_level))
                success = false;
            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "EmbeddedWorkerInstanceClient::AddMessageToConsole deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "EmbeddedWorkerInstanceClient::AddMessageToConsole");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddMessageToConsole(
                std::move(p_level),
                std::move(p_message));
            return true;
        }
        }
        return false;
    }

    // static
    bool EmbeddedWorkerInstanceClientStubDispatch::AcceptWithResponder(
        EmbeddedWorkerInstanceClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kEmbeddedWorkerInstanceClient_StartWorker_Name: {
            break;
        }
        case internal::kEmbeddedWorkerInstanceClient_StopWorker_Name: {
            internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data* params = reinterpret_cast<internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            EmbeddedWorkerInstanceClient_StopWorker_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "EmbeddedWorkerInstanceClient::StopWorker deserializer");
                return false;
            }
            EmbeddedWorkerInstanceClient::StopWorkerCallback callback = EmbeddedWorkerInstanceClient_StopWorker_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "EmbeddedWorkerInstanceClient::StopWorker");
            mojo::internal::MessageDispatchContext context(message);
            impl->StopWorker(std::move(callback));
            return true;
        }
        case internal::kEmbeddedWorkerInstanceClient_ResumeAfterDownload_Name: {
            break;
        }
        case internal::kEmbeddedWorkerInstanceClient_AddMessageToConsole_Name: {
            break;
        }
        }
        return false;
    }

    bool EmbeddedWorkerInstanceClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "EmbeddedWorkerInstanceClient RequestValidator");

        switch (message->header()->name) {
        case internal::kEmbeddedWorkerInstanceClient_StartWorker_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kEmbeddedWorkerInstanceClient_StopWorker_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kEmbeddedWorkerInstanceClient_ResumeAfterDownload_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kEmbeddedWorkerInstanceClient_AddMessageToConsole_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data>(
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

    bool EmbeddedWorkerInstanceClientResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "EmbeddedWorkerInstanceClient ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kEmbeddedWorkerInstanceClient_StopWorker_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data>(
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
} // namespace content

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif