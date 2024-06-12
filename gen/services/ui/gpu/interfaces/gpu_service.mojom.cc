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

#include "services/ui/gpu/interfaces/gpu_service.mojom.h"

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
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/gpu/interfaces/context_lost_reason_traits.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
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
#include "url/mojo/url_gurl_struct_traits.h"
namespace ui {
namespace mojom {
    const char GpuService::Name_[] = "ui::mojom::GpuService";
    bool GpuService::CreateGpuMemoryBuffer(gfx::GpuMemoryBufferId id, const gfx::Size& size, gfx::BufferFormat format, gfx::BufferUsage usage, int32_t client_id, ::gpu::SurfaceHandle surface_handle, gfx::GpuMemoryBufferHandle* buffer_handle)
    {
        NOTREACHED();
        return false;
    }

    class GpuService_EstablishGpuChannel_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        GpuService_EstablishGpuChannel_ForwardToCallback(
            const GpuService::EstablishGpuChannelCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        GpuService::EstablishGpuChannelCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(GpuService_EstablishGpuChannel_ForwardToCallback);
    };
    bool GpuService_EstablishGpuChannel_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::GpuService_EstablishGpuChannel_ResponseParams_Data* params = reinterpret_cast<internal::GpuService_EstablishGpuChannel_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        mojo::ScopedMessagePipeHandle p_channel_handle {};
        GpuService_EstablishGpuChannel_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_channel_handle = input_data_view.TakeChannelHandle();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GpuService::EstablishGpuChannel response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_channel_handle));
        }
        return true;
    }
    class GpuService_CreateGpuMemoryBuffer_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        GpuService_CreateGpuMemoryBuffer_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, gfx::GpuMemoryBufferHandle* out_buffer_handle)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_buffer_handle_(out_buffer_handle)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        gfx::GpuMemoryBufferHandle* out_buffer_handle_;
        DISALLOW_COPY_AND_ASSIGN(GpuService_CreateGpuMemoryBuffer_HandleSyncResponse);
    };
    bool GpuService_CreateGpuMemoryBuffer_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data* params = reinterpret_cast<internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        gfx::GpuMemoryBufferHandle p_buffer_handle {};
        GpuService_CreateGpuMemoryBuffer_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadBufferHandle(&p_buffer_handle))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GpuService::CreateGpuMemoryBuffer response deserializer");
            return false;
        }
        *out_buffer_handle_ = std::move(p_buffer_handle);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class GpuService_CreateGpuMemoryBuffer_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        GpuService_CreateGpuMemoryBuffer_ForwardToCallback(
            const GpuService::CreateGpuMemoryBufferCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        GpuService::CreateGpuMemoryBufferCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(GpuService_CreateGpuMemoryBuffer_ForwardToCallback);
    };
    bool GpuService_CreateGpuMemoryBuffer_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data* params = reinterpret_cast<internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        gfx::GpuMemoryBufferHandle p_buffer_handle {};
        GpuService_CreateGpuMemoryBuffer_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadBufferHandle(&p_buffer_handle))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GpuService::CreateGpuMemoryBuffer response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_buffer_handle));
        }
        return true;
    }

    GpuServiceProxy::GpuServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void GpuServiceProxy::EstablishGpuChannel(
        int32_t in_client_id, uint64_t in_client_tracing_id, bool in_is_gpu_host, const EstablishGpuChannelCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuService_EstablishGpuChannel_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kGpuService_EstablishGpuChannel_Name, size);

        auto params = ::ui::mojom::internal::GpuService_EstablishGpuChannel_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->client_id = in_client_id;
        params->client_tracing_id = in_client_tracing_id;
        params->is_gpu_host = in_is_gpu_host;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new GpuService_EstablishGpuChannel_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool GpuServiceProxy::CreateGpuMemoryBuffer(
        gfx::GpuMemoryBufferId param_id, const gfx::Size& param_size, gfx::BufferFormat param_format, gfx::BufferUsage param_usage, int32_t param_client_id, ::gpu::SurfaceHandle param_surface_handle, gfx::GpuMemoryBufferHandle* param_buffer_handle)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuService_CreateGpuMemoryBuffer_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
            param_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
            param_size, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::SurfaceHandleDataView>(
            param_surface_handle, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kGpuService_CreateGpuMemoryBuffer_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::ui::mojom::internal::GpuService_CreateGpuMemoryBuffer_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->id)::BaseType* id_ptr;
        mojo::internal::Serialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
            param_id, builder.buffer(), &id_ptr, &serialization_context);
        params->id.Set(id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null id in GpuService.CreateGpuMemoryBuffer request");
        typename decltype(params->size)::BaseType* size_ptr;
        mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
            param_size, builder.buffer(), &size_ptr, &serialization_context);
        params->size.Set(size_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->size.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null size in GpuService.CreateGpuMemoryBuffer request");
        mojo::internal::Serialize<::gfx::mojom::BufferFormat>(
            param_format, &params->format);
        mojo::internal::Serialize<::gfx::mojom::BufferUsage>(
            param_usage, &params->usage);
        params->client_id = param_client_id;
        typename decltype(params->surface_handle)::BaseType* surface_handle_ptr;
        mojo::internal::Serialize<::gpu::mojom::SurfaceHandleDataView>(
            param_surface_handle, builder.buffer(), &surface_handle_ptr, &serialization_context);
        params->surface_handle.Set(surface_handle_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->surface_handle.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null surface_handle in GpuService.CreateGpuMemoryBuffer request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new GpuService_CreateGpuMemoryBuffer_HandleSyncResponse(
            group_controller_, &result, param_buffer_handle);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void GpuServiceProxy::CreateGpuMemoryBuffer(
        gfx::GpuMemoryBufferId in_id, const gfx::Size& in_size, gfx::BufferFormat in_format, gfx::BufferUsage in_usage, int32_t in_client_id, ::gpu::SurfaceHandle in_surface_handle, const CreateGpuMemoryBufferCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuService_CreateGpuMemoryBuffer_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
            in_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
            in_size, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::SurfaceHandleDataView>(
            in_surface_handle, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kGpuService_CreateGpuMemoryBuffer_Name, size);

        auto params = ::ui::mojom::internal::GpuService_CreateGpuMemoryBuffer_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->id)::BaseType* id_ptr;
        mojo::internal::Serialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
            in_id, builder.buffer(), &id_ptr, &serialization_context);
        params->id.Set(id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null id in GpuService.CreateGpuMemoryBuffer request");
        typename decltype(params->size)::BaseType* size_ptr;
        mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
            in_size, builder.buffer(), &size_ptr, &serialization_context);
        params->size.Set(size_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->size.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null size in GpuService.CreateGpuMemoryBuffer request");
        mojo::internal::Serialize<::gfx::mojom::BufferFormat>(
            in_format, &params->format);
        mojo::internal::Serialize<::gfx::mojom::BufferUsage>(
            in_usage, &params->usage);
        params->client_id = in_client_id;
        typename decltype(params->surface_handle)::BaseType* surface_handle_ptr;
        mojo::internal::Serialize<::gpu::mojom::SurfaceHandleDataView>(
            in_surface_handle, builder.buffer(), &surface_handle_ptr, &serialization_context);
        params->surface_handle.Set(surface_handle_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->surface_handle.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null surface_handle in GpuService.CreateGpuMemoryBuffer request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new GpuService_CreateGpuMemoryBuffer_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void GpuServiceProxy::DestroyGpuMemoryBuffer(
        gfx::GpuMemoryBufferId in_id, int32_t in_client_id, const ::gpu::SyncToken& in_sync_token)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuService_DestroyGpuMemoryBuffer_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
            in_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::SyncTokenDataView>(
            in_sync_token, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuService_DestroyGpuMemoryBuffer_Name, size);

        auto params = ::ui::mojom::internal::GpuService_DestroyGpuMemoryBuffer_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->id)::BaseType* id_ptr;
        mojo::internal::Serialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
            in_id, builder.buffer(), &id_ptr, &serialization_context);
        params->id.Set(id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null id in GpuService.DestroyGpuMemoryBuffer request");
        params->client_id = in_client_id;
        typename decltype(params->sync_token)::BaseType* sync_token_ptr;
        mojo::internal::Serialize<::gpu::mojom::SyncTokenDataView>(
            in_sync_token, builder.buffer(), &sync_token_ptr, &serialization_context);
        params->sync_token.Set(sync_token_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sync_token.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sync_token in GpuService.DestroyGpuMemoryBuffer request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class GpuService_EstablishGpuChannel_ProxyToResponder {
    public:
        static GpuService::EstablishGpuChannelCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<GpuService_EstablishGpuChannel_ProxyToResponder> proxy(
                new GpuService_EstablishGpuChannel_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&GpuService_EstablishGpuChannel_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~GpuService_EstablishGpuChannel_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "GpuService::EstablishGpuChannel() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        GpuService_EstablishGpuChannel_ProxyToResponder(
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
            mojo::ScopedMessagePipeHandle in_channel_handle);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(GpuService_EstablishGpuChannel_ProxyToResponder);
    };

    void GpuService_EstablishGpuChannel_ProxyToResponder::Run(
        mojo::ScopedMessagePipeHandle in_channel_handle)
    {
        size_t size = sizeof(::ui::mojom::internal::GpuService_EstablishGpuChannel_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kGpuService_EstablishGpuChannel_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::GpuService_EstablishGpuChannel_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedMessagePipeHandle>(
            in_channel_handle, &params->channel_handle, &serialization_context_);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->channel_handle),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid channel_handle in GpuService.EstablishGpuChannel response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class GpuService_CreateGpuMemoryBuffer_ProxyToResponder {
    public:
        static GpuService::CreateGpuMemoryBufferCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<GpuService_CreateGpuMemoryBuffer_ProxyToResponder> proxy(
                new GpuService_CreateGpuMemoryBuffer_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&GpuService_CreateGpuMemoryBuffer_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~GpuService_CreateGpuMemoryBuffer_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "GpuService::CreateGpuMemoryBuffer() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        GpuService_CreateGpuMemoryBuffer_ProxyToResponder(
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
            const gfx::GpuMemoryBufferHandle& in_buffer_handle);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(GpuService_CreateGpuMemoryBuffer_ProxyToResponder);
    };

    void GpuService_CreateGpuMemoryBuffer_ProxyToResponder::Run(
        const gfx::GpuMemoryBufferHandle& in_buffer_handle)
    {
        size_t size = sizeof(::ui::mojom::internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::GpuMemoryBufferHandleDataView>(
            in_buffer_handle, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kGpuService_CreateGpuMemoryBuffer_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->buffer_handle)::BaseType* buffer_handle_ptr;
        mojo::internal::Serialize<::gfx::mojom::GpuMemoryBufferHandleDataView>(
            in_buffer_handle, builder.buffer(), &buffer_handle_ptr, &serialization_context_);
        params->buffer_handle.Set(buffer_handle_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->buffer_handle.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null buffer_handle in GpuService.CreateGpuMemoryBuffer response");
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
    bool GpuServiceStubDispatch::Accept(
        GpuService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kGpuService_EstablishGpuChannel_Name: {
            break;
        }
        case internal::kGpuService_CreateGpuMemoryBuffer_Name: {
            break;
        }
        case internal::kGpuService_DestroyGpuMemoryBuffer_Name: {
            internal::GpuService_DestroyGpuMemoryBuffer_Params_Data* params = reinterpret_cast<internal::GpuService_DestroyGpuMemoryBuffer_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::GpuMemoryBufferId p_id {};
            int32_t p_client_id {};
            ::gpu::SyncToken p_sync_token {};
            GpuService_DestroyGpuMemoryBuffer_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadId(&p_id))
                success = false;
            p_client_id = input_data_view.client_id();
            if (!input_data_view.ReadSyncToken(&p_sync_token))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuService::DestroyGpuMemoryBuffer deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuService::DestroyGpuMemoryBuffer");
            mojo::internal::MessageDispatchContext context(message);
            impl->DestroyGpuMemoryBuffer(
                std::move(p_id),
                std::move(p_client_id),
                std::move(p_sync_token));
            return true;
        }
        }
        return false;
    }

    // static
    bool GpuServiceStubDispatch::AcceptWithResponder(
        GpuService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kGpuService_EstablishGpuChannel_Name: {
            internal::GpuService_EstablishGpuChannel_Params_Data* params = reinterpret_cast<internal::GpuService_EstablishGpuChannel_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_client_id {};
            uint64_t p_client_tracing_id {};
            bool p_is_gpu_host {};
            GpuService_EstablishGpuChannel_ParamsDataView input_data_view(params,
                context);

            p_client_id = input_data_view.client_id();
            p_client_tracing_id = input_data_view.client_tracing_id();
            p_is_gpu_host = input_data_view.is_gpu_host();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuService::EstablishGpuChannel deserializer");
                return false;
            }
            GpuService::EstablishGpuChannelCallback callback = GpuService_EstablishGpuChannel_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuService::EstablishGpuChannel");
            mojo::internal::MessageDispatchContext context(message);
            impl->EstablishGpuChannel(
                std::move(p_client_id),
                std::move(p_client_tracing_id),
                std::move(p_is_gpu_host), std::move(callback));
            return true;
        }
        case internal::kGpuService_CreateGpuMemoryBuffer_Name: {
            internal::GpuService_CreateGpuMemoryBuffer_Params_Data* params = reinterpret_cast<internal::GpuService_CreateGpuMemoryBuffer_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::GpuMemoryBufferId p_id {};
            gfx::Size p_size {};
            gfx::BufferFormat p_format {};
            gfx::BufferUsage p_usage {};
            int32_t p_client_id {};
            ::gpu::SurfaceHandle p_surface_handle {};
            GpuService_CreateGpuMemoryBuffer_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadId(&p_id))
                success = false;
            if (!input_data_view.ReadSize(&p_size))
                success = false;
            if (!input_data_view.ReadFormat(&p_format))
                success = false;
            if (!input_data_view.ReadUsage(&p_usage))
                success = false;
            p_client_id = input_data_view.client_id();
            if (!input_data_view.ReadSurfaceHandle(&p_surface_handle))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuService::CreateGpuMemoryBuffer deserializer");
                return false;
            }
            GpuService::CreateGpuMemoryBufferCallback callback = GpuService_CreateGpuMemoryBuffer_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuService::CreateGpuMemoryBuffer");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateGpuMemoryBuffer(
                std::move(p_id),
                std::move(p_size),
                std::move(p_format),
                std::move(p_usage),
                std::move(p_client_id),
                std::move(p_surface_handle), std::move(callback));
            return true;
        }
        case internal::kGpuService_DestroyGpuMemoryBuffer_Name: {
            break;
        }
        }
        return false;
    }

    bool GpuServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GpuService RequestValidator");

        switch (message->header()->name) {
        case internal::kGpuService_EstablishGpuChannel_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuService_EstablishGpuChannel_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuService_CreateGpuMemoryBuffer_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuService_CreateGpuMemoryBuffer_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuService_DestroyGpuMemoryBuffer_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuService_DestroyGpuMemoryBuffer_Params_Data>(
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

    bool GpuServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GpuService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kGpuService_EstablishGpuChannel_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuService_EstablishGpuChannel_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuService_CreateGpuMemoryBuffer_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuService_CreateGpuMemoryBuffer_ResponseParams_Data>(
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
} // namespace ui

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif