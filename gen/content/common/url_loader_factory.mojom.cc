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

#include "content/common/url_loader_factory.mojom.h"

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
    const char URLLoaderFactory::Name_[] = "content::mojom::URLLoaderFactory";
    bool URLLoaderFactory::SyncLoad(int32_t routing_id, int32_t request_id, const content::ResourceRequest& request, content::SyncLoadResult* result)
    {
        NOTREACHED();
        return false;
    }
    class URLLoaderFactory_SyncLoad_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        URLLoaderFactory_SyncLoad_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, content::SyncLoadResult* out_result)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_result_(out_result)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        content::SyncLoadResult* out_result_;
        DISALLOW_COPY_AND_ASSIGN(URLLoaderFactory_SyncLoad_HandleSyncResponse);
    };
    bool URLLoaderFactory_SyncLoad_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::URLLoaderFactory_SyncLoad_ResponseParams_Data* params = reinterpret_cast<internal::URLLoaderFactory_SyncLoad_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        content::SyncLoadResult p_result {};
        URLLoaderFactory_SyncLoad_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "URLLoaderFactory::SyncLoad response deserializer");
            return false;
        }
        *out_result_ = std::move(p_result);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class URLLoaderFactory_SyncLoad_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        URLLoaderFactory_SyncLoad_ForwardToCallback(
            const URLLoaderFactory::SyncLoadCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        URLLoaderFactory::SyncLoadCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(URLLoaderFactory_SyncLoad_ForwardToCallback);
    };
    bool URLLoaderFactory_SyncLoad_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::URLLoaderFactory_SyncLoad_ResponseParams_Data* params = reinterpret_cast<internal::URLLoaderFactory_SyncLoad_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        content::SyncLoadResult p_result {};
        URLLoaderFactory_SyncLoad_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "URLLoaderFactory::SyncLoad response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    URLLoaderFactoryProxy::URLLoaderFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void URLLoaderFactoryProxy::CreateLoaderAndStart(
        ::content::mojom::URLLoaderAssociatedRequest in_loader, int32_t in_routing_id, int32_t in_request_id, const content::ResourceRequest& in_request, ::content::mojom::URLLoaderClientAssociatedPtrInfo in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLRequestDataView>(
            in_request, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderFactory_CreateLoaderAndStart_Name, size);

        auto params = ::content::mojom::internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::content::mojom::URLLoaderAssociatedRequestDataView>(
            in_loader, &params->loader, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->loader),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid loader in URLLoaderFactory.CreateLoaderAndStart request");
        params->routing_id = in_routing_id;
        params->request_id = in_request_id;
        typename decltype(params->request)::BaseType* request_ptr;
        mojo::internal::Serialize<::content::mojom::URLRequestDataView>(
            in_request, builder.buffer(), &request_ptr, &serialization_context);
        params->request.Set(request_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->request.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null request in URLLoaderFactory.CreateLoaderAndStart request");
        mojo::internal::Serialize<::content::mojom::URLLoaderClientAssociatedPtrInfoDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid client in URLLoaderFactory.CreateLoaderAndStart request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    bool URLLoaderFactoryProxy::SyncLoad(
        int32_t param_routing_id, int32_t param_request_id, const content::ResourceRequest& param_request, content::SyncLoadResult* param_result)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderFactory_SyncLoad_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLRequestDataView>(
            param_request, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kURLLoaderFactory_SyncLoad_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::URLLoaderFactory_SyncLoad_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->routing_id = param_routing_id;
        params->request_id = param_request_id;
        typename decltype(params->request)::BaseType* request_ptr;
        mojo::internal::Serialize<::content::mojom::URLRequestDataView>(
            param_request, builder.buffer(), &request_ptr, &serialization_context);
        params->request.Set(request_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->request.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null request in URLLoaderFactory.SyncLoad request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new URLLoaderFactory_SyncLoad_HandleSyncResponse(
            group_controller_, &result, param_result);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void URLLoaderFactoryProxy::SyncLoad(
        int32_t in_routing_id, int32_t in_request_id, const content::ResourceRequest& in_request, const SyncLoadCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderFactory_SyncLoad_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLRequestDataView>(
            in_request, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kURLLoaderFactory_SyncLoad_Name, size);

        auto params = ::content::mojom::internal::URLLoaderFactory_SyncLoad_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->routing_id = in_routing_id;
        params->request_id = in_request_id;
        typename decltype(params->request)::BaseType* request_ptr;
        mojo::internal::Serialize<::content::mojom::URLRequestDataView>(
            in_request, builder.buffer(), &request_ptr, &serialization_context);
        params->request.Set(request_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->request.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null request in URLLoaderFactory.SyncLoad request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new URLLoaderFactory_SyncLoad_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class URLLoaderFactory_SyncLoad_ProxyToResponder {
    public:
        static URLLoaderFactory::SyncLoadCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<URLLoaderFactory_SyncLoad_ProxyToResponder> proxy(
                new URLLoaderFactory_SyncLoad_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&URLLoaderFactory_SyncLoad_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~URLLoaderFactory_SyncLoad_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "URLLoaderFactory::SyncLoad() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        URLLoaderFactory_SyncLoad_ProxyToResponder(
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
            const content::SyncLoadResult& in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(URLLoaderFactory_SyncLoad_ProxyToResponder);
    };

    void URLLoaderFactory_SyncLoad_ProxyToResponder::Run(
        const content::SyncLoadResult& in_result)
    {
        size_t size = sizeof(::content::mojom::internal::URLLoaderFactory_SyncLoad_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLSyncLoadResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kURLLoaderFactory_SyncLoad_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::URLLoaderFactory_SyncLoad_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::content::mojom::URLSyncLoadResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in URLLoaderFactory.SyncLoad response");
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
    bool URLLoaderFactoryStubDispatch::Accept(
        URLLoaderFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kURLLoaderFactory_CreateLoaderAndStart_Name: {
            internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data* params = reinterpret_cast<internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::content::mojom::URLLoaderAssociatedRequest p_loader {};
            int32_t p_routing_id {};
            int32_t p_request_id {};
            content::ResourceRequest p_request {};
            ::content::mojom::URLLoaderClientAssociatedPtrInfo p_client {};
            URLLoaderFactory_CreateLoaderAndStart_ParamsDataView input_data_view(params,
                context);

            p_loader = input_data_view.TakeLoader<decltype(p_loader)>();
            p_routing_id = input_data_view.routing_id();
            p_request_id = input_data_view.request_id();
            if (!input_data_view.ReadRequest(&p_request))
                success = false;
            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderFactory::CreateLoaderAndStart deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderFactory::CreateLoaderAndStart");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateLoaderAndStart(
                std::move(p_loader),
                std::move(p_routing_id),
                std::move(p_request_id),
                std::move(p_request),
                std::move(p_client));
            return true;
        }
        case internal::kURLLoaderFactory_SyncLoad_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool URLLoaderFactoryStubDispatch::AcceptWithResponder(
        URLLoaderFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kURLLoaderFactory_CreateLoaderAndStart_Name: {
            break;
        }
        case internal::kURLLoaderFactory_SyncLoad_Name: {
            internal::URLLoaderFactory_SyncLoad_Params_Data* params = reinterpret_cast<internal::URLLoaderFactory_SyncLoad_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_routing_id {};
            int32_t p_request_id {};
            content::ResourceRequest p_request {};
            URLLoaderFactory_SyncLoad_ParamsDataView input_data_view(params,
                context);

            p_routing_id = input_data_view.routing_id();
            p_request_id = input_data_view.request_id();
            if (!input_data_view.ReadRequest(&p_request))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderFactory::SyncLoad deserializer");
                return false;
            }
            URLLoaderFactory::SyncLoadCallback callback = URLLoaderFactory_SyncLoad_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderFactory::SyncLoad");
            mojo::internal::MessageDispatchContext context(message);
            impl->SyncLoad(
                std::move(p_routing_id),
                std::move(p_request_id),
                std::move(p_request), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool URLLoaderFactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "URLLoaderFactory RequestValidator");

        switch (message->header()->name) {
        case internal::kURLLoaderFactory_CreateLoaderAndStart_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderFactory_SyncLoad_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderFactory_SyncLoad_Params_Data>(
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

    bool URLLoaderFactoryResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "URLLoaderFactory ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kURLLoaderFactory_SyncLoad_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderFactory_SyncLoad_ResponseParams_Data>(
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