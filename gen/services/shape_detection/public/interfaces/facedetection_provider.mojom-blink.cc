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

#include "services/shape_detection/public/interfaces/facedetection_provider.mojom-blink.h"

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
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace shape_detection {
namespace mojom {
    namespace blink {
        const char FaceDetectionProvider::Name_[] = "shape_detection::mojom::FaceDetectionProvider";

        FaceDetectionProviderProxy::FaceDetectionProviderProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void FaceDetectionProviderProxy::CreateFaceDetection(
            ::shape_detection::mojom::blink::FaceDetectionRequest in_request, ::shape_detection::mojom::blink::FaceDetectorOptionsPtr in_options)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::shape_detection::mojom::internal::FaceDetectionProvider_CreateFaceDetection_Params_Data);
            size += mojo::internal::PrepareToSerialize<::shape_detection::mojom::FaceDetectorOptionsDataView>(
                in_options, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kFaceDetectionProvider_CreateFaceDetection_Name, size);

            auto params = ::shape_detection::mojom::internal::FaceDetectionProvider_CreateFaceDetection_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::shape_detection::mojom::FaceDetectionRequestDataView>(
                in_request, &params->request, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->request),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid request in FaceDetectionProvider.CreateFaceDetection request");
            typename decltype(params->options)::BaseType* options_ptr;
            mojo::internal::Serialize<::shape_detection::mojom::FaceDetectorOptionsDataView>(
                in_options, builder.buffer(), &options_ptr, &serialization_context);
            params->options.Set(options_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->options.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null options in FaceDetectionProvider.CreateFaceDetection request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool FaceDetectionProviderStubDispatch::Accept(
            FaceDetectionProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kFaceDetectionProvider_CreateFaceDetection_Name: {
                internal::FaceDetectionProvider_CreateFaceDetection_Params_Data* params = reinterpret_cast<internal::FaceDetectionProvider_CreateFaceDetection_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                ::shape_detection::mojom::blink::FaceDetectionRequest p_request {};
                ::shape_detection::mojom::blink::FaceDetectorOptionsPtr p_options {};
                FaceDetectionProvider_CreateFaceDetection_ParamsDataView input_data_view(params,
                    context);

                p_request = input_data_view.TakeRequest<decltype(p_request)>();
                if (!input_data_view.ReadOptions(&p_options))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "FaceDetectionProvider::CreateFaceDetection deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "FaceDetectionProvider::CreateFaceDetection");
                mojo::internal::MessageDispatchContext context(message);
                impl->CreateFaceDetection(
                    std::move(p_request),
                    std::move(p_options));
                return true;
            }
            }
            return false;
        }

        // static
        bool FaceDetectionProviderStubDispatch::AcceptWithResponder(
            FaceDetectionProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kFaceDetectionProvider_CreateFaceDetection_Name: {
                break;
            }
            }
            return false;
        }

        bool FaceDetectionProviderRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "FaceDetectionProvider RequestValidator");

            switch (message->header()->name) {
            case internal::kFaceDetectionProvider_CreateFaceDetection_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::FaceDetectionProvider_CreateFaceDetection_Params_Data>(
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

    } // namespace blink
} // namespace mojom
} // namespace shape_detection

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif