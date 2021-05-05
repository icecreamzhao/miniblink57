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

#include "services/shape_detection/public/interfaces/facedetection.mojom.h"

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
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
namespace shape_detection {
namespace mojom { // static
    FaceDetectionResultPtr FaceDetectionResult::New()
    {
        FaceDetectionResultPtr rv;
        mojo::internal::StructHelper<FaceDetectionResult>::Initialize(&rv);
        return rv;
    }

    FaceDetectionResult::FaceDetectionResult()
        : bounding_boxes()
    {
    }

    FaceDetectionResult::~FaceDetectionResult()
    {
    } // static
    FaceDetectorOptionsPtr FaceDetectorOptions::New()
    {
        FaceDetectorOptionsPtr rv;
        mojo::internal::StructHelper<FaceDetectorOptions>::Initialize(&rv);
        return rv;
    }

    FaceDetectorOptions::FaceDetectorOptions()
        : max_detected_faces()
        , fast_mode()
    {
    }

    FaceDetectorOptions::~FaceDetectorOptions()
    {
    }
    size_t FaceDetectorOptions::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->max_detected_faces);
        seed = mojo::internal::Hash(seed, this->fast_mode);
        return seed;
    }
    const char FaceDetection::Name_[] = "shape_detection::mojom::FaceDetection";

    class FaceDetection_Detect_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        FaceDetection_Detect_ForwardToCallback(
            const FaceDetection::DetectCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        FaceDetection::DetectCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(FaceDetection_Detect_ForwardToCallback);
    };
    bool FaceDetection_Detect_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::FaceDetection_Detect_ResponseParams_Data* params = reinterpret_cast<internal::FaceDetection_Detect_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        FaceDetectionResultPtr p_result {};
        FaceDetection_Detect_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "FaceDetection::Detect response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    FaceDetectionProxy::FaceDetectionProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void FaceDetectionProxy::Detect(
        mojo::ScopedSharedBufferHandle in_frame_data, uint32_t in_width, uint32_t in_height, const DetectCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::shape_detection::mojom::internal::FaceDetection_Detect_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kFaceDetection_Detect_Name, size);

        auto params = ::shape_detection::mojom::internal::FaceDetection_Detect_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_frame_data, &params->frame_data, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->frame_data),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid frame_data in FaceDetection.Detect request");
        params->width = in_width;
        params->height = in_height;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new FaceDetection_Detect_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class FaceDetection_Detect_ProxyToResponder {
    public:
        static FaceDetection::DetectCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<FaceDetection_Detect_ProxyToResponder> proxy(
                new FaceDetection_Detect_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&FaceDetection_Detect_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~FaceDetection_Detect_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "FaceDetection::Detect() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        FaceDetection_Detect_ProxyToResponder(
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
            FaceDetectionResultPtr in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(FaceDetection_Detect_ProxyToResponder);
    };

    void FaceDetection_Detect_ProxyToResponder::Run(
        FaceDetectionResultPtr in_result)
    {
        size_t size = sizeof(::shape_detection::mojom::internal::FaceDetection_Detect_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::shape_detection::mojom::FaceDetectionResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kFaceDetection_Detect_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::shape_detection::mojom::internal::FaceDetection_Detect_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::shape_detection::mojom::FaceDetectionResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in FaceDetection.Detect response");
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
    bool FaceDetectionStubDispatch::Accept(
        FaceDetection* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kFaceDetection_Detect_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool FaceDetectionStubDispatch::AcceptWithResponder(
        FaceDetection* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kFaceDetection_Detect_Name: {
            internal::FaceDetection_Detect_Params_Data* params = reinterpret_cast<internal::FaceDetection_Detect_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedSharedBufferHandle p_frame_data {};
            uint32_t p_width {};
            uint32_t p_height {};
            FaceDetection_Detect_ParamsDataView input_data_view(params,
                context);

            p_frame_data = input_data_view.TakeFrameData();
            p_width = input_data_view.width();
            p_height = input_data_view.height();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "FaceDetection::Detect deserializer");
                return false;
            }
            FaceDetection::DetectCallback callback = FaceDetection_Detect_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "FaceDetection::Detect");
            mojo::internal::MessageDispatchContext context(message);
            impl->Detect(
                std::move(p_frame_data),
                std::move(p_width),
                std::move(p_height), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool FaceDetectionRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "FaceDetection RequestValidator");

        switch (message->header()->name) {
        case internal::kFaceDetection_Detect_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::FaceDetection_Detect_Params_Data>(
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

    bool FaceDetectionResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "FaceDetection ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kFaceDetection_Detect_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::FaceDetection_Detect_ResponseParams_Data>(
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
} // namespace shape_detection

namespace mojo {

// static
bool StructTraits<::shape_detection::mojom::FaceDetectionResult::DataView, ::shape_detection::mojom::FaceDetectionResultPtr>::Read(
    ::shape_detection::mojom::FaceDetectionResult::DataView input,
    ::shape_detection::mojom::FaceDetectionResultPtr* output)
{
    bool success = true;
    ::shape_detection::mojom::FaceDetectionResultPtr result(::shape_detection::mojom::FaceDetectionResult::New());

    if (!input.ReadBoundingBoxes(&result->bounding_boxes))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::shape_detection::mojom::FaceDetectorOptions::DataView, ::shape_detection::mojom::FaceDetectorOptionsPtr>::Read(
    ::shape_detection::mojom::FaceDetectorOptions::DataView input,
    ::shape_detection::mojom::FaceDetectorOptionsPtr* output)
{
    bool success = true;
    ::shape_detection::mojom::FaceDetectorOptionsPtr result(::shape_detection::mojom::FaceDetectorOptions::New());

    result->max_detected_faces = input.max_detected_faces();
    result->fast_mode = input.fast_mode();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif