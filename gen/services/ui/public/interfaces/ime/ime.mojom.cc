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

#include "services/ui/public/interfaces/ime/ime.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
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
namespace mojom { // static
    CompositionUnderlinePtr CompositionUnderline::New()
    {
        CompositionUnderlinePtr rv;
        mojo::internal::StructHelper<CompositionUnderline>::Initialize(&rv);
        return rv;
    }

    CompositionUnderline::CompositionUnderline()
        : start_offset()
        , end_offset()
        , thick()
        , color()
        , background_color()
    {
    }

    CompositionUnderline::~CompositionUnderline()
    {
    } // static
    CompositionTextPtr CompositionText::New()
    {
        CompositionTextPtr rv;
        mojo::internal::StructHelper<CompositionText>::Initialize(&rv);
        return rv;
    }

    CompositionText::CompositionText()
        : text()
        , underlines()
        , selection()
    {
    }

    CompositionText::~CompositionText()
    {
    } // static
    StartSessionDetailsPtr StartSessionDetails::New()
    {
        StartSessionDetailsPtr rv;
        mojo::internal::StructHelper<StartSessionDetails>::Initialize(&rv);
        return rv;
    }

    StartSessionDetails::StartSessionDetails()
        : client()
        , input_method_request()
        , text_input_type()
        , text_input_mode()
        , text_direction()
        , text_input_flags()
        , caret_bounds()
    {
    }

    StartSessionDetails::~StartSessionDetails()
    {
    }
    const char IMEDriver::Name_[] = "ui::mojom::IMEDriver";

    IMEDriverProxy::IMEDriverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void IMEDriverProxy::StartSession(
        int32_t in_session_id, StartSessionDetailsPtr in_details)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::IMEDriver_StartSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::StartSessionDetailsDataView>(
            in_details, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kIMEDriver_StartSession_Name, size);

        auto params = ::ui::mojom::internal::IMEDriver_StartSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->session_id = in_session_id;
        typename decltype(params->details)::BaseType* details_ptr;
        mojo::internal::Serialize<::ui::mojom::StartSessionDetailsDataView>(
            in_details, builder.buffer(), &details_ptr, &serialization_context);
        params->details.Set(details_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->details.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null details in IMEDriver.StartSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void IMEDriverProxy::CancelSession(
        int32_t in_session_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::IMEDriver_CancelSession_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kIMEDriver_CancelSession_Name, size);

        auto params = ::ui::mojom::internal::IMEDriver_CancelSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->session_id = in_session_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool IMEDriverStubDispatch::Accept(
        IMEDriver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kIMEDriver_StartSession_Name: {
            internal::IMEDriver_StartSession_Params_Data* params = reinterpret_cast<internal::IMEDriver_StartSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_session_id {};
            StartSessionDetailsPtr p_details {};
            IMEDriver_StartSession_ParamsDataView input_data_view(params,
                context);

            p_session_id = input_data_view.session_id();
            if (!input_data_view.ReadDetails(&p_details))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "IMEDriver::StartSession deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "IMEDriver::StartSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartSession(
                std::move(p_session_id),
                std::move(p_details));
            return true;
        }
        case internal::kIMEDriver_CancelSession_Name: {
            internal::IMEDriver_CancelSession_Params_Data* params = reinterpret_cast<internal::IMEDriver_CancelSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_session_id {};
            IMEDriver_CancelSession_ParamsDataView input_data_view(params,
                context);

            p_session_id = input_data_view.session_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "IMEDriver::CancelSession deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "IMEDriver::CancelSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->CancelSession(
                std::move(p_session_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool IMEDriverStubDispatch::AcceptWithResponder(
        IMEDriver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kIMEDriver_StartSession_Name: {
            break;
        }
        case internal::kIMEDriver_CancelSession_Name: {
            break;
        }
        }
        return false;
    }

    bool IMEDriverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "IMEDriver RequestValidator");

        switch (message->header()->name) {
        case internal::kIMEDriver_StartSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::IMEDriver_StartSession_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kIMEDriver_CancelSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::IMEDriver_CancelSession_Params_Data>(
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

    const char IMEServer::Name_[] = "ui::mojom::IMEServer";

    IMEServerProxy::IMEServerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void IMEServerProxy::StartSession(
        StartSessionDetailsPtr in_details)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::IMEServer_StartSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::StartSessionDetailsDataView>(
            in_details, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kIMEServer_StartSession_Name, size);

        auto params = ::ui::mojom::internal::IMEServer_StartSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->details)::BaseType* details_ptr;
        mojo::internal::Serialize<::ui::mojom::StartSessionDetailsDataView>(
            in_details, builder.buffer(), &details_ptr, &serialization_context);
        params->details.Set(details_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->details.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null details in IMEServer.StartSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool IMEServerStubDispatch::Accept(
        IMEServer* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kIMEServer_StartSession_Name: {
            internal::IMEServer_StartSession_Params_Data* params = reinterpret_cast<internal::IMEServer_StartSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            StartSessionDetailsPtr p_details {};
            IMEServer_StartSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDetails(&p_details))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "IMEServer::StartSession deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "IMEServer::StartSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartSession(
                std::move(p_details));
            return true;
        }
        }
        return false;
    }

    // static
    bool IMEServerStubDispatch::AcceptWithResponder(
        IMEServer* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kIMEServer_StartSession_Name: {
            break;
        }
        }
        return false;
    }

    bool IMEServerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "IMEServer RequestValidator");

        switch (message->header()->name) {
        case internal::kIMEServer_StartSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::IMEServer_StartSession_Params_Data>(
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

    const char IMERegistrar::Name_[] = "ui::mojom::IMERegistrar";

    IMERegistrarProxy::IMERegistrarProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void IMERegistrarProxy::RegisterDriver(
        IMEDriverPtr in_driver)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::IMERegistrar_RegisterDriver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kIMERegistrar_RegisterDriver_Name, size);

        auto params = ::ui::mojom::internal::IMERegistrar_RegisterDriver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::IMEDriverPtrDataView>(
            in_driver, &params->driver, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->driver),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid driver in IMERegistrar.RegisterDriver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool IMERegistrarStubDispatch::Accept(
        IMERegistrar* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kIMERegistrar_RegisterDriver_Name: {
            internal::IMERegistrar_RegisterDriver_Params_Data* params = reinterpret_cast<internal::IMERegistrar_RegisterDriver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            IMEDriverPtr p_driver {};
            IMERegistrar_RegisterDriver_ParamsDataView input_data_view(params,
                context);

            p_driver = input_data_view.TakeDriver<decltype(p_driver)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "IMERegistrar::RegisterDriver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "IMERegistrar::RegisterDriver");
            mojo::internal::MessageDispatchContext context(message);
            impl->RegisterDriver(
                std::move(p_driver));
            return true;
        }
        }
        return false;
    }

    // static
    bool IMERegistrarStubDispatch::AcceptWithResponder(
        IMERegistrar* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kIMERegistrar_RegisterDriver_Name: {
            break;
        }
        }
        return false;
    }

    bool IMERegistrarRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "IMERegistrar RequestValidator");

        switch (message->header()->name) {
        case internal::kIMERegistrar_RegisterDriver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::IMERegistrar_RegisterDriver_Params_Data>(
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

    const char InputMethod::Name_[] = "ui::mojom::InputMethod";

    class InputMethod_ProcessKeyEvent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        InputMethod_ProcessKeyEvent_ForwardToCallback(
            const InputMethod::ProcessKeyEventCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        InputMethod::ProcessKeyEventCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(InputMethod_ProcessKeyEvent_ForwardToCallback);
    };
    bool InputMethod_ProcessKeyEvent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::InputMethod_ProcessKeyEvent_ResponseParams_Data* params = reinterpret_cast<internal::InputMethod_ProcessKeyEvent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_handled {};
        InputMethod_ProcessKeyEvent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_handled = input_data_view.handled();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "InputMethod::ProcessKeyEvent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_handled));
        }
        return true;
    }

    InputMethodProxy::InputMethodProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void InputMethodProxy::OnTextInputTypeChanged(
        ui::TextInputType in_text_input_type)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::InputMethod_OnTextInputTypeChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kInputMethod_OnTextInputTypeChanged_Name, size);

        auto params = ::ui::mojom::internal::InputMethod_OnTextInputTypeChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::TextInputType>(
            in_text_input_type, &params->text_input_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void InputMethodProxy::OnCaretBoundsChanged(
        const gfx::Rect& in_caret_bounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::InputMethod_OnCaretBoundsChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
            in_caret_bounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kInputMethod_OnCaretBoundsChanged_Name, size);

        auto params = ::ui::mojom::internal::InputMethod_OnCaretBoundsChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->caret_bounds)::BaseType* caret_bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectDataView>(
            in_caret_bounds, builder.buffer(), &caret_bounds_ptr, &serialization_context);
        params->caret_bounds.Set(caret_bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->caret_bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null caret_bounds in InputMethod.OnCaretBoundsChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void InputMethodProxy::ProcessKeyEvent(
        std::unique_ptr<ui::Event> in_key_event, const ProcessKeyEventCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::InputMethod_ProcessKeyEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::EventDataView>(
            in_key_event, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kInputMethod_ProcessKeyEvent_Name, size);

        auto params = ::ui::mojom::internal::InputMethod_ProcessKeyEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key_event)::BaseType* key_event_ptr;
        mojo::internal::Serialize<::ui::mojom::EventDataView>(
            in_key_event, builder.buffer(), &key_event_ptr, &serialization_context);
        params->key_event.Set(key_event_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_event.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_event in InputMethod.ProcessKeyEvent request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new InputMethod_ProcessKeyEvent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void InputMethodProxy::CancelComposition()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::InputMethod_CancelComposition_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kInputMethod_CancelComposition_Name, size);

        auto params = ::ui::mojom::internal::InputMethod_CancelComposition_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class InputMethod_ProcessKeyEvent_ProxyToResponder {
    public:
        static InputMethod::ProcessKeyEventCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<InputMethod_ProcessKeyEvent_ProxyToResponder> proxy(
                new InputMethod_ProcessKeyEvent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&InputMethod_ProcessKeyEvent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~InputMethod_ProcessKeyEvent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "InputMethod::ProcessKeyEvent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        InputMethod_ProcessKeyEvent_ProxyToResponder(
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
            bool in_handled);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(InputMethod_ProcessKeyEvent_ProxyToResponder);
    };

    void InputMethod_ProcessKeyEvent_ProxyToResponder::Run(
        bool in_handled)
    {
        size_t size = sizeof(::ui::mojom::internal::InputMethod_ProcessKeyEvent_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kInputMethod_ProcessKeyEvent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::InputMethod_ProcessKeyEvent_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->handled = in_handled;
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
    bool InputMethodStubDispatch::Accept(
        InputMethod* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kInputMethod_OnTextInputTypeChanged_Name: {
            internal::InputMethod_OnTextInputTypeChanged_Params_Data* params = reinterpret_cast<internal::InputMethod_OnTextInputTypeChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ui::TextInputType p_text_input_type {};
            InputMethod_OnTextInputTypeChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTextInputType(&p_text_input_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InputMethod::OnTextInputTypeChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InputMethod::OnTextInputTypeChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnTextInputTypeChanged(
                std::move(p_text_input_type));
            return true;
        }
        case internal::kInputMethod_OnCaretBoundsChanged_Name: {
            internal::InputMethod_OnCaretBoundsChanged_Params_Data* params = reinterpret_cast<internal::InputMethod_OnCaretBoundsChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::Rect p_caret_bounds {};
            InputMethod_OnCaretBoundsChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadCaretBounds(&p_caret_bounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InputMethod::OnCaretBoundsChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InputMethod::OnCaretBoundsChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnCaretBoundsChanged(
                std::move(p_caret_bounds));
            return true;
        }
        case internal::kInputMethod_ProcessKeyEvent_Name: {
            break;
        }
        case internal::kInputMethod_CancelComposition_Name: {
            internal::InputMethod_CancelComposition_Params_Data* params = reinterpret_cast<internal::InputMethod_CancelComposition_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            InputMethod_CancelComposition_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InputMethod::CancelComposition deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InputMethod::CancelComposition");
            mojo::internal::MessageDispatchContext context(message);
            impl->CancelComposition();
            return true;
        }
        }
        return false;
    }

    // static
    bool InputMethodStubDispatch::AcceptWithResponder(
        InputMethod* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kInputMethod_OnTextInputTypeChanged_Name: {
            break;
        }
        case internal::kInputMethod_OnCaretBoundsChanged_Name: {
            break;
        }
        case internal::kInputMethod_ProcessKeyEvent_Name: {
            internal::InputMethod_ProcessKeyEvent_Params_Data* params = reinterpret_cast<internal::InputMethod_ProcessKeyEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::unique_ptr<ui::Event> p_key_event {};
            InputMethod_ProcessKeyEvent_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKeyEvent(&p_key_event))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InputMethod::ProcessKeyEvent deserializer");
                return false;
            }
            InputMethod::ProcessKeyEventCallback callback = InputMethod_ProcessKeyEvent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InputMethod::ProcessKeyEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->ProcessKeyEvent(
                std::move(p_key_event), std::move(callback));
            return true;
        }
        case internal::kInputMethod_CancelComposition_Name: {
            break;
        }
        }
        return false;
    }

    bool InputMethodRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "InputMethod RequestValidator");

        switch (message->header()->name) {
        case internal::kInputMethod_OnTextInputTypeChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InputMethod_OnTextInputTypeChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kInputMethod_OnCaretBoundsChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InputMethod_OnCaretBoundsChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kInputMethod_ProcessKeyEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InputMethod_ProcessKeyEvent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kInputMethod_CancelComposition_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InputMethod_CancelComposition_Params_Data>(
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

    bool InputMethodResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "InputMethod ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kInputMethod_ProcessKeyEvent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InputMethod_ProcessKeyEvent_ResponseParams_Data>(
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
    const char TextInputClient::Name_[] = "ui::mojom::TextInputClient";

    TextInputClientProxy::TextInputClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void TextInputClientProxy::SetCompositionText(
        const ui::CompositionText& in_composition)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::TextInputClient_SetCompositionText_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::CompositionTextDataView>(
            in_composition, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kTextInputClient_SetCompositionText_Name, size);

        auto params = ::ui::mojom::internal::TextInputClient_SetCompositionText_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->composition)::BaseType* composition_ptr;
        mojo::internal::Serialize<::ui::mojom::CompositionTextDataView>(
            in_composition, builder.buffer(), &composition_ptr, &serialization_context);
        params->composition.Set(composition_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->composition.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null composition in TextInputClient.SetCompositionText request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void TextInputClientProxy::ConfirmCompositionText()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::TextInputClient_ConfirmCompositionText_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kTextInputClient_ConfirmCompositionText_Name, size);

        auto params = ::ui::mojom::internal::TextInputClient_ConfirmCompositionText_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void TextInputClientProxy::ClearCompositionText()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::TextInputClient_ClearCompositionText_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kTextInputClient_ClearCompositionText_Name, size);

        auto params = ::ui::mojom::internal::TextInputClient_ClearCompositionText_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void TextInputClientProxy::InsertText(
        const std::string& in_text)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::TextInputClient_InsertText_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_text, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kTextInputClient_InsertText_Name, size);

        auto params = ::ui::mojom::internal::TextInputClient_InsertText_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->text)::BaseType* text_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_text, builder.buffer(), &text_ptr, &serialization_context);
        params->text.Set(text_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->text.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null text in TextInputClient.InsertText request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void TextInputClientProxy::InsertChar(
        std::unique_ptr<ui::Event> in_event)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::TextInputClient_InsertChar_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::EventDataView>(
            in_event, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kTextInputClient_InsertChar_Name, size);

        auto params = ::ui::mojom::internal::TextInputClient_InsertChar_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->event)::BaseType* event_ptr;
        mojo::internal::Serialize<::ui::mojom::EventDataView>(
            in_event, builder.buffer(), &event_ptr, &serialization_context);
        params->event.Set(event_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->event.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null event in TextInputClient.InsertChar request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool TextInputClientStubDispatch::Accept(
        TextInputClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kTextInputClient_SetCompositionText_Name: {
            internal::TextInputClient_SetCompositionText_Params_Data* params = reinterpret_cast<internal::TextInputClient_SetCompositionText_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ui::CompositionText p_composition {};
            TextInputClient_SetCompositionText_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadComposition(&p_composition))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TextInputClient::SetCompositionText deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TextInputClient::SetCompositionText");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCompositionText(
                std::move(p_composition));
            return true;
        }
        case internal::kTextInputClient_ConfirmCompositionText_Name: {
            internal::TextInputClient_ConfirmCompositionText_Params_Data* params = reinterpret_cast<internal::TextInputClient_ConfirmCompositionText_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TextInputClient_ConfirmCompositionText_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TextInputClient::ConfirmCompositionText deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TextInputClient::ConfirmCompositionText");
            mojo::internal::MessageDispatchContext context(message);
            impl->ConfirmCompositionText();
            return true;
        }
        case internal::kTextInputClient_ClearCompositionText_Name: {
            internal::TextInputClient_ClearCompositionText_Params_Data* params = reinterpret_cast<internal::TextInputClient_ClearCompositionText_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TextInputClient_ClearCompositionText_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TextInputClient::ClearCompositionText deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TextInputClient::ClearCompositionText");
            mojo::internal::MessageDispatchContext context(message);
            impl->ClearCompositionText();
            return true;
        }
        case internal::kTextInputClient_InsertText_Name: {
            internal::TextInputClient_InsertText_Params_Data* params = reinterpret_cast<internal::TextInputClient_InsertText_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_text {};
            TextInputClient_InsertText_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadText(&p_text))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TextInputClient::InsertText deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TextInputClient::InsertText");
            mojo::internal::MessageDispatchContext context(message);
            impl->InsertText(
                std::move(p_text));
            return true;
        }
        case internal::kTextInputClient_InsertChar_Name: {
            internal::TextInputClient_InsertChar_Params_Data* params = reinterpret_cast<internal::TextInputClient_InsertChar_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::unique_ptr<ui::Event> p_event {};
            TextInputClient_InsertChar_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadEvent(&p_event))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TextInputClient::InsertChar deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TextInputClient::InsertChar");
            mojo::internal::MessageDispatchContext context(message);
            impl->InsertChar(
                std::move(p_event));
            return true;
        }
        }
        return false;
    }

    // static
    bool TextInputClientStubDispatch::AcceptWithResponder(
        TextInputClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kTextInputClient_SetCompositionText_Name: {
            break;
        }
        case internal::kTextInputClient_ConfirmCompositionText_Name: {
            break;
        }
        case internal::kTextInputClient_ClearCompositionText_Name: {
            break;
        }
        case internal::kTextInputClient_InsertText_Name: {
            break;
        }
        case internal::kTextInputClient_InsertChar_Name: {
            break;
        }
        }
        return false;
    }

    bool TextInputClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "TextInputClient RequestValidator");

        switch (message->header()->name) {
        case internal::kTextInputClient_SetCompositionText_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TextInputClient_SetCompositionText_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kTextInputClient_ConfirmCompositionText_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TextInputClient_ConfirmCompositionText_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kTextInputClient_ClearCompositionText_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TextInputClient_ClearCompositionText_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kTextInputClient_InsertText_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TextInputClient_InsertText_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kTextInputClient_InsertChar_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TextInputClient_InsertChar_Params_Data>(
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

// static
bool StructTraits<::ui::mojom::CompositionUnderline::DataView, ::ui::mojom::CompositionUnderlinePtr>::Read(
    ::ui::mojom::CompositionUnderline::DataView input,
    ::ui::mojom::CompositionUnderlinePtr* output)
{
    bool success = true;
    ::ui::mojom::CompositionUnderlinePtr result(::ui::mojom::CompositionUnderline::New());

    result->start_offset = input.start_offset();
    result->end_offset = input.end_offset();
    result->thick = input.thick();
    result->color = input.color();
    result->background_color = input.background_color();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::CompositionText::DataView, ::ui::mojom::CompositionTextPtr>::Read(
    ::ui::mojom::CompositionText::DataView input,
    ::ui::mojom::CompositionTextPtr* output)
{
    bool success = true;
    ::ui::mojom::CompositionTextPtr result(::ui::mojom::CompositionText::New());

    if (!input.ReadText(&result->text))
        success = false;
    if (!input.ReadUnderlines(&result->underlines))
        success = false;
    if (!input.ReadSelection(&result->selection))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::StartSessionDetails::DataView, ::ui::mojom::StartSessionDetailsPtr>::Read(
    ::ui::mojom::StartSessionDetails::DataView input,
    ::ui::mojom::StartSessionDetailsPtr* output)
{
    bool success = true;
    ::ui::mojom::StartSessionDetailsPtr result(::ui::mojom::StartSessionDetails::New());

    result->client = input.TakeClient<decltype(result->client)>();
    result->input_method_request = input.TakeInputMethodRequest<decltype(result->input_method_request)>();
    if (!input.ReadTextInputType(&result->text_input_type))
        success = false;
    if (!input.ReadTextInputMode(&result->text_input_mode))
        success = false;
    if (!input.ReadTextDirection(&result->text_direction))
        success = false;
    result->text_input_flags = input.text_input_flags();
    if (!input.ReadCaretBounds(&result->caret_bounds))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif