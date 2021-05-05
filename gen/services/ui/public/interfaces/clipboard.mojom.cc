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

#include "services/ui/public/interfaces/clipboard.mojom.h"

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
    const char kMimeTypeHTML[] = "text/html";
    const char kMimeTypeMozillaURL[] = "text/x-moz-url";
    const char kMimeTypePNG[] = "image/png";
    const char kMimeTypeRTF[] = "text/rtf";
    const char kMimeTypeText[] = "text/plain";
    const char kMimeTypeURIList[] = "text/uri-list";
    const char kMimeTypeURL[] = "text/url";
    const char Clipboard::Name_[] = "ui::mojom::Clipboard";
    bool Clipboard::GetSequenceNumber(Clipboard::Type clipboard_type, uint64_t* sequence)
    {
        NOTREACHED();
        return false;
    }
    bool Clipboard::GetAvailableMimeTypes(Clipboard::Type clipboard_types, uint64_t* sequence, std::vector<std::string>* types)
    {
        NOTREACHED();
        return false;
    }
    bool Clipboard::ReadClipboardData(Clipboard::Type clipboard_type, const std::string& mime_type, uint64_t* sequence, base::Optional<std::vector<uint8_t>>* data)
    {
        NOTREACHED();
        return false;
    }
    bool Clipboard::WriteClipboardData(Clipboard::Type clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& data, uint64_t* sequence)
    {
        NOTREACHED();
        return false;
    }
    class Clipboard_GetSequenceNumber_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Clipboard_GetSequenceNumber_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, uint64_t* out_sequence)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_sequence_(out_sequence)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        uint64_t* out_sequence_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_GetSequenceNumber_HandleSyncResponse);
    };
    bool Clipboard_GetSequenceNumber_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_GetSequenceNumber_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_GetSequenceNumber_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        Clipboard_GetSequenceNumber_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::GetSequenceNumber response deserializer");
            return false;
        }
        *out_sequence_ = std::move(p_sequence);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Clipboard_GetSequenceNumber_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Clipboard_GetSequenceNumber_ForwardToCallback(
            const Clipboard::GetSequenceNumberCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Clipboard::GetSequenceNumberCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_GetSequenceNumber_ForwardToCallback);
    };
    bool Clipboard_GetSequenceNumber_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_GetSequenceNumber_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_GetSequenceNumber_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        Clipboard_GetSequenceNumber_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::GetSequenceNumber response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_sequence));
        }
        return true;
    }
    class Clipboard_GetAvailableMimeTypes_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Clipboard_GetAvailableMimeTypes_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, uint64_t* out_sequence, std::vector<std::string>* out_types)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_sequence_(out_sequence)
            , out_types_(out_types)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        uint64_t* out_sequence_;
        std::vector<std::string>* out_types_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_GetAvailableMimeTypes_HandleSyncResponse);
    };
    bool Clipboard_GetAvailableMimeTypes_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        std::vector<std::string> p_types {};
        Clipboard_GetAvailableMimeTypes_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!input_data_view.ReadTypes(&p_types))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::GetAvailableMimeTypes response deserializer");
            return false;
        }
        *out_sequence_ = std::move(p_sequence);
        *out_types_ = std::move(p_types);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Clipboard_GetAvailableMimeTypes_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Clipboard_GetAvailableMimeTypes_ForwardToCallback(
            const Clipboard::GetAvailableMimeTypesCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Clipboard::GetAvailableMimeTypesCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_GetAvailableMimeTypes_ForwardToCallback);
    };
    bool Clipboard_GetAvailableMimeTypes_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        std::vector<std::string> p_types {};
        Clipboard_GetAvailableMimeTypes_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!input_data_view.ReadTypes(&p_types))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::GetAvailableMimeTypes response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_sequence),
                std::move(p_types));
        }
        return true;
    }
    class Clipboard_ReadClipboardData_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Clipboard_ReadClipboardData_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, uint64_t* out_sequence, base::Optional<std::vector<uint8_t>>* out_data)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_sequence_(out_sequence)
            , out_data_(out_data)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        uint64_t* out_sequence_;
        base::Optional<std::vector<uint8_t>>* out_data_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_ReadClipboardData_HandleSyncResponse);
    };
    bool Clipboard_ReadClipboardData_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_ReadClipboardData_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_ReadClipboardData_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        base::Optional<std::vector<uint8_t>> p_data {};
        Clipboard_ReadClipboardData_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::ReadClipboardData response deserializer");
            return false;
        }
        *out_sequence_ = std::move(p_sequence);
        *out_data_ = std::move(p_data);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Clipboard_ReadClipboardData_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Clipboard_ReadClipboardData_ForwardToCallback(
            const Clipboard::ReadClipboardDataCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Clipboard::ReadClipboardDataCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_ReadClipboardData_ForwardToCallback);
    };
    bool Clipboard_ReadClipboardData_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_ReadClipboardData_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_ReadClipboardData_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        base::Optional<std::vector<uint8_t>> p_data {};
        Clipboard_ReadClipboardData_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::ReadClipboardData response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_sequence),
                std::move(p_data));
        }
        return true;
    }
    class Clipboard_WriteClipboardData_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Clipboard_WriteClipboardData_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, uint64_t* out_sequence)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_sequence_(out_sequence)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        uint64_t* out_sequence_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_WriteClipboardData_HandleSyncResponse);
    };
    bool Clipboard_WriteClipboardData_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_WriteClipboardData_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_WriteClipboardData_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        Clipboard_WriteClipboardData_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::WriteClipboardData response deserializer");
            return false;
        }
        *out_sequence_ = std::move(p_sequence);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Clipboard_WriteClipboardData_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Clipboard_WriteClipboardData_ForwardToCallback(
            const Clipboard::WriteClipboardDataCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Clipboard::WriteClipboardDataCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Clipboard_WriteClipboardData_ForwardToCallback);
    };
    bool Clipboard_WriteClipboardData_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Clipboard_WriteClipboardData_ResponseParams_Data* params = reinterpret_cast<internal::Clipboard_WriteClipboardData_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint64_t p_sequence {};
        Clipboard_WriteClipboardData_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_sequence = input_data_view.sequence();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Clipboard::WriteClipboardData response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_sequence));
        }
        return true;
    }

    ClipboardProxy::ClipboardProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool ClipboardProxy::GetSequenceNumber(
        Clipboard::Type param_clipboard_type, uint64_t* param_sequence)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_GetSequenceNumber_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_GetSequenceNumber_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::ui::mojom::internal::Clipboard_GetSequenceNumber_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            param_clipboard_type, &params->clipboard_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Clipboard_GetSequenceNumber_HandleSyncResponse(
            group_controller_, &result, param_sequence);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void ClipboardProxy::GetSequenceNumber(
        Clipboard::Type in_clipboard_type, const GetSequenceNumberCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_GetSequenceNumber_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_GetSequenceNumber_Name, size);

        auto params = ::ui::mojom::internal::Clipboard_GetSequenceNumber_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            in_clipboard_type, &params->clipboard_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Clipboard_GetSequenceNumber_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool ClipboardProxy::GetAvailableMimeTypes(
        Clipboard::Type param_clipboard_types, uint64_t* param_sequence, std::vector<std::string>* param_types)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_GetAvailableMimeTypes_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_GetAvailableMimeTypes_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::ui::mojom::internal::Clipboard_GetAvailableMimeTypes_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            param_clipboard_types, &params->clipboard_types);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Clipboard_GetAvailableMimeTypes_HandleSyncResponse(
            group_controller_, &result, param_sequence, param_types);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void ClipboardProxy::GetAvailableMimeTypes(
        Clipboard::Type in_clipboard_types, const GetAvailableMimeTypesCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_GetAvailableMimeTypes_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_GetAvailableMimeTypes_Name, size);

        auto params = ::ui::mojom::internal::Clipboard_GetAvailableMimeTypes_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            in_clipboard_types, &params->clipboard_types);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Clipboard_GetAvailableMimeTypes_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool ClipboardProxy::ReadClipboardData(
        Clipboard::Type param_clipboard_type, const std::string& param_mime_type, uint64_t* param_sequence, base::Optional<std::vector<uint8_t>>* param_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_ReadClipboardData_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_mime_type, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_ReadClipboardData_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::ui::mojom::internal::Clipboard_ReadClipboardData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            param_clipboard_type, &params->clipboard_type);
        typename decltype(params->mime_type)::BaseType* mime_type_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_mime_type, builder.buffer(), &mime_type_ptr, &serialization_context);
        params->mime_type.Set(mime_type_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->mime_type.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null mime_type in Clipboard.ReadClipboardData request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Clipboard_ReadClipboardData_HandleSyncResponse(
            group_controller_, &result, param_sequence, param_data);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void ClipboardProxy::ReadClipboardData(
        Clipboard::Type in_clipboard_type, const std::string& in_mime_type, const ReadClipboardDataCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_ReadClipboardData_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_mime_type, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_ReadClipboardData_Name, size);

        auto params = ::ui::mojom::internal::Clipboard_ReadClipboardData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            in_clipboard_type, &params->clipboard_type);
        typename decltype(params->mime_type)::BaseType* mime_type_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_mime_type, builder.buffer(), &mime_type_ptr, &serialization_context);
        params->mime_type.Set(mime_type_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->mime_type.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null mime_type in Clipboard.ReadClipboardData request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Clipboard_ReadClipboardData_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool ClipboardProxy::WriteClipboardData(
        Clipboard::Type param_clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& param_data, uint64_t* param_sequence)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_WriteClipboardData_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            param_data, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_WriteClipboardData_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::ui::mojom::internal::Clipboard_WriteClipboardData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            param_clipboard_type, &params->clipboard_type);
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
        mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            param_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context);
        params->data.Set(data_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Clipboard_WriteClipboardData_HandleSyncResponse(
            group_controller_, &result, param_sequence);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void ClipboardProxy::WriteClipboardData(
        Clipboard::Type in_clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& in_data, const WriteClipboardDataCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::Clipboard_WriteClipboardData_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_data, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kClipboard_WriteClipboardData_Name, size);

        auto params = ::ui::mojom::internal::Clipboard_WriteClipboardData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::Clipboard_Type>(
            in_clipboard_type, &params->clipboard_type);
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
        mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context);
        params->data.Set(data_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Clipboard_WriteClipboardData_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class Clipboard_GetSequenceNumber_ProxyToResponder {
    public:
        static Clipboard::GetSequenceNumberCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Clipboard_GetSequenceNumber_ProxyToResponder> proxy(
                new Clipboard_GetSequenceNumber_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Clipboard_GetSequenceNumber_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Clipboard_GetSequenceNumber_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Clipboard::GetSequenceNumber() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Clipboard_GetSequenceNumber_ProxyToResponder(
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
            uint64_t in_sequence);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Clipboard_GetSequenceNumber_ProxyToResponder);
    };

    void Clipboard_GetSequenceNumber_ProxyToResponder::Run(
        uint64_t in_sequence)
    {
        size_t size = sizeof(::ui::mojom::internal::Clipboard_GetSequenceNumber_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kClipboard_GetSequenceNumber_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::Clipboard_GetSequenceNumber_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->sequence = in_sequence;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Clipboard_GetAvailableMimeTypes_ProxyToResponder {
    public:
        static Clipboard::GetAvailableMimeTypesCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Clipboard_GetAvailableMimeTypes_ProxyToResponder> proxy(
                new Clipboard_GetAvailableMimeTypes_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Clipboard_GetAvailableMimeTypes_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Clipboard_GetAvailableMimeTypes_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Clipboard::GetAvailableMimeTypes() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Clipboard_GetAvailableMimeTypes_ProxyToResponder(
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
            uint64_t in_sequence, const std::vector<std::string>& in_types);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Clipboard_GetAvailableMimeTypes_ProxyToResponder);
    };

    void Clipboard_GetAvailableMimeTypes_ProxyToResponder::Run(
        uint64_t in_sequence, const std::vector<std::string>& in_types)
    {
        size_t size = sizeof(::ui::mojom::internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_types, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kClipboard_GetAvailableMimeTypes_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->sequence = in_sequence;
        typename decltype(params->types)::BaseType* types_ptr;
        const mojo::internal::ContainerValidateParams types_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_types, builder.buffer(), &types_ptr, &types_validate_params,
            &serialization_context_);
        params->types.Set(types_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->types.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null types in Clipboard.GetAvailableMimeTypes response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Clipboard_ReadClipboardData_ProxyToResponder {
    public:
        static Clipboard::ReadClipboardDataCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Clipboard_ReadClipboardData_ProxyToResponder> proxy(
                new Clipboard_ReadClipboardData_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Clipboard_ReadClipboardData_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Clipboard_ReadClipboardData_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Clipboard::ReadClipboardData() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Clipboard_ReadClipboardData_ProxyToResponder(
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
            uint64_t in_sequence, const base::Optional<std::vector<uint8_t>>& in_data);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Clipboard_ReadClipboardData_ProxyToResponder);
    };

    void Clipboard_ReadClipboardData_ProxyToResponder::Run(
        uint64_t in_sequence, const base::Optional<std::vector<uint8_t>>& in_data)
    {
        size_t size = sizeof(::ui::mojom::internal::Clipboard_ReadClipboardData_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_data, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kClipboard_ReadClipboardData_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::Clipboard_ReadClipboardData_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->sequence = in_sequence;
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context_);
        params->data.Set(data_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Clipboard_WriteClipboardData_ProxyToResponder {
    public:
        static Clipboard::WriteClipboardDataCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Clipboard_WriteClipboardData_ProxyToResponder> proxy(
                new Clipboard_WriteClipboardData_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Clipboard_WriteClipboardData_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Clipboard_WriteClipboardData_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Clipboard::WriteClipboardData() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Clipboard_WriteClipboardData_ProxyToResponder(
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
            uint64_t in_sequence);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Clipboard_WriteClipboardData_ProxyToResponder);
    };

    void Clipboard_WriteClipboardData_ProxyToResponder::Run(
        uint64_t in_sequence)
    {
        size_t size = sizeof(::ui::mojom::internal::Clipboard_WriteClipboardData_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kClipboard_WriteClipboardData_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::Clipboard_WriteClipboardData_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->sequence = in_sequence;
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
    bool ClipboardStubDispatch::Accept(
        Clipboard* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kClipboard_GetSequenceNumber_Name: {
            break;
        }
        case internal::kClipboard_GetAvailableMimeTypes_Name: {
            break;
        }
        case internal::kClipboard_ReadClipboardData_Name: {
            break;
        }
        case internal::kClipboard_WriteClipboardData_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ClipboardStubDispatch::AcceptWithResponder(
        Clipboard* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kClipboard_GetSequenceNumber_Name: {
            internal::Clipboard_GetSequenceNumber_Params_Data* params = reinterpret_cast<internal::Clipboard_GetSequenceNumber_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Clipboard::Type p_clipboard_type {};
            Clipboard_GetSequenceNumber_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadClipboardType(&p_clipboard_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Clipboard::GetSequenceNumber deserializer");
                return false;
            }
            Clipboard::GetSequenceNumberCallback callback = Clipboard_GetSequenceNumber_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Clipboard::GetSequenceNumber");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetSequenceNumber(
                std::move(p_clipboard_type), std::move(callback));
            return true;
        }
        case internal::kClipboard_GetAvailableMimeTypes_Name: {
            internal::Clipboard_GetAvailableMimeTypes_Params_Data* params = reinterpret_cast<internal::Clipboard_GetAvailableMimeTypes_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Clipboard::Type p_clipboard_types {};
            Clipboard_GetAvailableMimeTypes_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadClipboardTypes(&p_clipboard_types))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Clipboard::GetAvailableMimeTypes deserializer");
                return false;
            }
            Clipboard::GetAvailableMimeTypesCallback callback = Clipboard_GetAvailableMimeTypes_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Clipboard::GetAvailableMimeTypes");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetAvailableMimeTypes(
                std::move(p_clipboard_types), std::move(callback));
            return true;
        }
        case internal::kClipboard_ReadClipboardData_Name: {
            internal::Clipboard_ReadClipboardData_Params_Data* params = reinterpret_cast<internal::Clipboard_ReadClipboardData_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Clipboard::Type p_clipboard_type {};
            std::string p_mime_type {};
            Clipboard_ReadClipboardData_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadClipboardType(&p_clipboard_type))
                success = false;
            if (!input_data_view.ReadMimeType(&p_mime_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Clipboard::ReadClipboardData deserializer");
                return false;
            }
            Clipboard::ReadClipboardDataCallback callback = Clipboard_ReadClipboardData_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Clipboard::ReadClipboardData");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReadClipboardData(
                std::move(p_clipboard_type),
                std::move(p_mime_type), std::move(callback));
            return true;
        }
        case internal::kClipboard_WriteClipboardData_Name: {
            internal::Clipboard_WriteClipboardData_Params_Data* params = reinterpret_cast<internal::Clipboard_WriteClipboardData_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Clipboard::Type p_clipboard_type {};
            base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>> p_data {};
            Clipboard_WriteClipboardData_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadClipboardType(&p_clipboard_type))
                success = false;
            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Clipboard::WriteClipboardData deserializer");
                return false;
            }
            Clipboard::WriteClipboardDataCallback callback = Clipboard_WriteClipboardData_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Clipboard::WriteClipboardData");
            mojo::internal::MessageDispatchContext context(message);
            impl->WriteClipboardData(
                std::move(p_clipboard_type),
                std::move(p_data), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ClipboardRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Clipboard RequestValidator");

        switch (message->header()->name) {
        case internal::kClipboard_GetSequenceNumber_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_GetSequenceNumber_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kClipboard_GetAvailableMimeTypes_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_GetAvailableMimeTypes_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kClipboard_ReadClipboardData_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_ReadClipboardData_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kClipboard_WriteClipboardData_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_WriteClipboardData_Params_Data>(
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

    bool ClipboardResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Clipboard ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kClipboard_GetSequenceNumber_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_GetSequenceNumber_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kClipboard_GetAvailableMimeTypes_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kClipboard_ReadClipboardData_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_ReadClipboardData_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kClipboard_WriteClipboardData_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Clipboard_WriteClipboardData_ResponseParams_Data>(
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