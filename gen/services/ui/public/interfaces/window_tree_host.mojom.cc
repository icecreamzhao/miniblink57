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

#include "services/ui/public/interfaces/window_tree_host.mojom.h"

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
namespace ui {
namespace mojom {
    const char WindowTreeHost::Name_[] = "ui::mojom::WindowTreeHost";

    WindowTreeHostProxy::WindowTreeHostProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowTreeHostProxy::SetSize(
        const gfx::Size& in_size)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeHost_SetSize_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
            in_size, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeHost_SetSize_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeHost_SetSize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->size)::BaseType* size_ptr;
        mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
            in_size, builder.buffer(), &size_ptr, &serialization_context);
        params->size.Set(size_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->size.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null size in WindowTreeHost.SetSize request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeHostProxy::SetTitle(
        const std::string& in_title)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeHost_SetTitle_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_title, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeHost_SetTitle_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeHost_SetTitle_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->title)::BaseType* title_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_title, builder.buffer(), &title_ptr, &serialization_context);
        params->title.Set(title_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->title.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null title in WindowTreeHost.SetTitle request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool WindowTreeHostStubDispatch::Accept(
        WindowTreeHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeHost_SetSize_Name: {
            internal::WindowTreeHost_SetSize_Params_Data* params = reinterpret_cast<internal::WindowTreeHost_SetSize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::Size p_size {};
            WindowTreeHost_SetSize_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSize(&p_size))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeHost::SetSize deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeHost::SetSize");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetSize(
                std::move(p_size));
            return true;
        }
        case internal::kWindowTreeHost_SetTitle_Name: {
            internal::WindowTreeHost_SetTitle_Params_Data* params = reinterpret_cast<internal::WindowTreeHost_SetTitle_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_title {};
            WindowTreeHost_SetTitle_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTitle(&p_title))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeHost::SetTitle deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeHost::SetTitle");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetTitle(
                std::move(p_title));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowTreeHostStubDispatch::AcceptWithResponder(
        WindowTreeHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeHost_SetSize_Name: {
            break;
        }
        case internal::kWindowTreeHost_SetTitle_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowTreeHostRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTreeHost RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowTreeHost_SetSize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeHost_SetSize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeHost_SetTitle_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeHost_SetTitle_Params_Data>(
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

    const char WindowTreeHostFactory::Name_[] = "ui::mojom::WindowTreeHostFactory";

    WindowTreeHostFactoryProxy::WindowTreeHostFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowTreeHostFactoryProxy::CreateWindowTreeHost(
        WindowTreeHostRequest in_window_tree_host, ::ui::mojom::WindowTreeClientPtr in_tree_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeHostFactory_CreateWindowTreeHost_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::WindowTreeHostRequestDataView>(
            in_window_tree_host, &params->window_tree_host, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->window_tree_host),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid window_tree_host in WindowTreeHostFactory.CreateWindowTreeHost request");
        mojo::internal::Serialize<::ui::mojom::WindowTreeClientPtrDataView>(
            in_tree_client, &params->tree_client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->tree_client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid tree_client in WindowTreeHostFactory.CreateWindowTreeHost request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool WindowTreeHostFactoryStubDispatch::Accept(
        WindowTreeHostFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeHostFactory_CreateWindowTreeHost_Name: {
            internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data* params = reinterpret_cast<internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WindowTreeHostRequest p_window_tree_host {};
            ::ui::mojom::WindowTreeClientPtr p_tree_client {};
            WindowTreeHostFactory_CreateWindowTreeHost_ParamsDataView input_data_view(params,
                context);

            p_window_tree_host = input_data_view.TakeWindowTreeHost<decltype(p_window_tree_host)>();
            p_tree_client = input_data_view.TakeTreeClient<decltype(p_tree_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeHostFactory::CreateWindowTreeHost deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeHostFactory::CreateWindowTreeHost");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateWindowTreeHost(
                std::move(p_window_tree_host),
                std::move(p_tree_client));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowTreeHostFactoryStubDispatch::AcceptWithResponder(
        WindowTreeHostFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeHostFactory_CreateWindowTreeHost_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowTreeHostFactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTreeHostFactory RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowTreeHostFactory_CreateWindowTreeHost_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data>(
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