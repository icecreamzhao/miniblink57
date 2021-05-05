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

#include "services/ui/public/interfaces/display/display_controller.mojom.h"

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
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
namespace display {
namespace mojom {
    const char DisplayController::Name_[] = "display::mojom::DisplayController";

    DisplayControllerProxy::DisplayControllerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DisplayControllerProxy::IncreaseInternalDisplayZoom()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_IncreaseInternalDisplayZoom_Name, size);

        auto params = ::display::mojom::internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayControllerProxy::DecreaseInternalDisplayZoom()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_DecreaseInternalDisplayZoom_Name, size);

        auto params = ::display::mojom::internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayControllerProxy::ResetInternalDisplayZoom()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_ResetInternalDisplayZoom_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_ResetInternalDisplayZoom_Name, size);

        auto params = ::display::mojom::internal::DisplayController_ResetInternalDisplayZoom_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayControllerProxy::RotateCurrentDisplayCW()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_RotateCurrentDisplayCW_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_RotateCurrentDisplayCW_Name, size);

        auto params = ::display::mojom::internal::DisplayController_RotateCurrentDisplayCW_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayControllerProxy::SwapPrimaryDisplay()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_SwapPrimaryDisplay_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_SwapPrimaryDisplay_Name, size);

        auto params = ::display::mojom::internal::DisplayController_SwapPrimaryDisplay_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayControllerProxy::ToggleMirrorMode()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_ToggleMirrorMode_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_ToggleMirrorMode_Name, size);

        auto params = ::display::mojom::internal::DisplayController_ToggleMirrorMode_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayControllerProxy::SetDisplayWorkArea(
        int64_t in_display_id, const gfx::Size& in_size, const gfx::Insets& in_insets)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::DisplayController_SetDisplayWorkArea_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
            in_size, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::InsetsDataView>(
            in_insets, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayController_SetDisplayWorkArea_Name, size);

        auto params = ::display::mojom::internal::DisplayController_SetDisplayWorkArea_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->display_id = in_display_id;
        typename decltype(params->size)::BaseType* size_ptr;
        mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
            in_size, builder.buffer(), &size_ptr, &serialization_context);
        params->size.Set(size_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->size.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null size in DisplayController.SetDisplayWorkArea request");
        typename decltype(params->insets)::BaseType* insets_ptr;
        mojo::internal::Serialize<::gfx::mojom::InsetsDataView>(
            in_insets, builder.buffer(), &insets_ptr, &serialization_context);
        params->insets.Set(insets_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->insets.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null insets in DisplayController.SetDisplayWorkArea request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DisplayControllerStubDispatch::Accept(
        DisplayController* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDisplayController_IncreaseInternalDisplayZoom_Name: {
            internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data* params = reinterpret_cast<internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayController_IncreaseInternalDisplayZoom_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::IncreaseInternalDisplayZoom deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::IncreaseInternalDisplayZoom");
            mojo::internal::MessageDispatchContext context(message);
            impl->IncreaseInternalDisplayZoom();
            return true;
        }
        case internal::kDisplayController_DecreaseInternalDisplayZoom_Name: {
            internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data* params = reinterpret_cast<internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayController_DecreaseInternalDisplayZoom_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::DecreaseInternalDisplayZoom deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::DecreaseInternalDisplayZoom");
            mojo::internal::MessageDispatchContext context(message);
            impl->DecreaseInternalDisplayZoom();
            return true;
        }
        case internal::kDisplayController_ResetInternalDisplayZoom_Name: {
            internal::DisplayController_ResetInternalDisplayZoom_Params_Data* params = reinterpret_cast<internal::DisplayController_ResetInternalDisplayZoom_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayController_ResetInternalDisplayZoom_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::ResetInternalDisplayZoom deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::ResetInternalDisplayZoom");
            mojo::internal::MessageDispatchContext context(message);
            impl->ResetInternalDisplayZoom();
            return true;
        }
        case internal::kDisplayController_RotateCurrentDisplayCW_Name: {
            internal::DisplayController_RotateCurrentDisplayCW_Params_Data* params = reinterpret_cast<internal::DisplayController_RotateCurrentDisplayCW_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayController_RotateCurrentDisplayCW_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::RotateCurrentDisplayCW deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::RotateCurrentDisplayCW");
            mojo::internal::MessageDispatchContext context(message);
            impl->RotateCurrentDisplayCW();
            return true;
        }
        case internal::kDisplayController_SwapPrimaryDisplay_Name: {
            internal::DisplayController_SwapPrimaryDisplay_Params_Data* params = reinterpret_cast<internal::DisplayController_SwapPrimaryDisplay_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayController_SwapPrimaryDisplay_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::SwapPrimaryDisplay deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::SwapPrimaryDisplay");
            mojo::internal::MessageDispatchContext context(message);
            impl->SwapPrimaryDisplay();
            return true;
        }
        case internal::kDisplayController_ToggleMirrorMode_Name: {
            internal::DisplayController_ToggleMirrorMode_Params_Data* params = reinterpret_cast<internal::DisplayController_ToggleMirrorMode_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayController_ToggleMirrorMode_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::ToggleMirrorMode deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::ToggleMirrorMode");
            mojo::internal::MessageDispatchContext context(message);
            impl->ToggleMirrorMode();
            return true;
        }
        case internal::kDisplayController_SetDisplayWorkArea_Name: {
            internal::DisplayController_SetDisplayWorkArea_Params_Data* params = reinterpret_cast<internal::DisplayController_SetDisplayWorkArea_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_display_id {};
            gfx::Size p_size {};
            gfx::Insets p_insets {};
            DisplayController_SetDisplayWorkArea_ParamsDataView input_data_view(params,
                context);

            p_display_id = input_data_view.display_id();
            if (!input_data_view.ReadSize(&p_size))
                success = false;
            if (!input_data_view.ReadInsets(&p_insets))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayController::SetDisplayWorkArea deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayController::SetDisplayWorkArea");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetDisplayWorkArea(
                std::move(p_display_id),
                std::move(p_size),
                std::move(p_insets));
            return true;
        }
        }
        return false;
    }

    // static
    bool DisplayControllerStubDispatch::AcceptWithResponder(
        DisplayController* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDisplayController_IncreaseInternalDisplayZoom_Name: {
            break;
        }
        case internal::kDisplayController_DecreaseInternalDisplayZoom_Name: {
            break;
        }
        case internal::kDisplayController_ResetInternalDisplayZoom_Name: {
            break;
        }
        case internal::kDisplayController_RotateCurrentDisplayCW_Name: {
            break;
        }
        case internal::kDisplayController_SwapPrimaryDisplay_Name: {
            break;
        }
        case internal::kDisplayController_ToggleMirrorMode_Name: {
            break;
        }
        case internal::kDisplayController_SetDisplayWorkArea_Name: {
            break;
        }
        }
        return false;
    }

    bool DisplayControllerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DisplayController RequestValidator");

        switch (message->header()->name) {
        case internal::kDisplayController_IncreaseInternalDisplayZoom_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayController_DecreaseInternalDisplayZoom_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayController_ResetInternalDisplayZoom_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_ResetInternalDisplayZoom_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayController_RotateCurrentDisplayCW_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_RotateCurrentDisplayCW_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayController_SwapPrimaryDisplay_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_SwapPrimaryDisplay_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayController_ToggleMirrorMode_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_ToggleMirrorMode_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayController_SetDisplayWorkArea_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayController_SetDisplayWorkArea_Params_Data>(
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
} // namespace display

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif