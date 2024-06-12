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

#include "services/ui/public/interfaces/display/test_display_controller.mojom.h"

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
    const char TestDisplayController::Name_[] = "display::mojom::TestDisplayController";

    TestDisplayControllerProxy::TestDisplayControllerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void TestDisplayControllerProxy::ToggleAddRemoveDisplay()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kTestDisplayController_ToggleAddRemoveDisplay_Name, size);

        auto params = ::display::mojom::internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void TestDisplayControllerProxy::ToggleDisplayResolution()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::display::mojom::internal::TestDisplayController_ToggleDisplayResolution_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kTestDisplayController_ToggleDisplayResolution_Name, size);

        auto params = ::display::mojom::internal::TestDisplayController_ToggleDisplayResolution_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool TestDisplayControllerStubDispatch::Accept(
        TestDisplayController* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kTestDisplayController_ToggleAddRemoveDisplay_Name: {
            internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data* params = reinterpret_cast<internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TestDisplayController_ToggleAddRemoveDisplay_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TestDisplayController::ToggleAddRemoveDisplay deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TestDisplayController::ToggleAddRemoveDisplay");
            mojo::internal::MessageDispatchContext context(message);
            impl->ToggleAddRemoveDisplay();
            return true;
        }
        case internal::kTestDisplayController_ToggleDisplayResolution_Name: {
            internal::TestDisplayController_ToggleDisplayResolution_Params_Data* params = reinterpret_cast<internal::TestDisplayController_ToggleDisplayResolution_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TestDisplayController_ToggleDisplayResolution_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "TestDisplayController::ToggleDisplayResolution deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "TestDisplayController::ToggleDisplayResolution");
            mojo::internal::MessageDispatchContext context(message);
            impl->ToggleDisplayResolution();
            return true;
        }
        }
        return false;
    }

    // static
    bool TestDisplayControllerStubDispatch::AcceptWithResponder(
        TestDisplayController* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kTestDisplayController_ToggleAddRemoveDisplay_Name: {
            break;
        }
        case internal::kTestDisplayController_ToggleDisplayResolution_Name: {
            break;
        }
        }
        return false;
    }

    bool TestDisplayControllerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "TestDisplayController RequestValidator");

        switch (message->header()->name) {
        case internal::kTestDisplayController_ToggleAddRemoveDisplay_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kTestDisplayController_ToggleDisplayResolution_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::TestDisplayController_ToggleDisplayResolution_Params_Data>(
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