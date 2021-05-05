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

#include "services/shape_detection/public/interfaces/barcodedetection.mojom.h"

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
    BarcodeDetectionResultPtr BarcodeDetectionResult::New()
    {
        BarcodeDetectionResultPtr rv;
        mojo::internal::StructHelper<BarcodeDetectionResult>::Initialize(&rv);
        return rv;
    }

    BarcodeDetectionResult::BarcodeDetectionResult()
        : raw_value()
        , bounding_box()
        , corner_points()
    {
    }

    BarcodeDetectionResult::~BarcodeDetectionResult()
    {
    }
    const char BarcodeDetection::Name_[] = "shape_detection::mojom::BarcodeDetection";

    class BarcodeDetection_Detect_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        BarcodeDetection_Detect_ForwardToCallback(
            const BarcodeDetection::DetectCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        BarcodeDetection::DetectCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(BarcodeDetection_Detect_ForwardToCallback);
    };
    bool BarcodeDetection_Detect_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::BarcodeDetection_Detect_ResponseParams_Data* params = reinterpret_cast<internal::BarcodeDetection_Detect_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<BarcodeDetectionResultPtr> p_results {};
        BarcodeDetection_Detect_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResults(&p_results))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BarcodeDetection::Detect response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_results));
        }
        return true;
    }

    BarcodeDetectionProxy::BarcodeDetectionProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void BarcodeDetectionProxy::Detect(
        mojo::ScopedSharedBufferHandle in_frame_data, uint32_t in_width, uint32_t in_height, const DetectCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::shape_detection::mojom::internal::BarcodeDetection_Detect_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kBarcodeDetection_Detect_Name, size);

        auto params = ::shape_detection::mojom::internal::BarcodeDetection_Detect_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_frame_data, &params->frame_data, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->frame_data),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid frame_data in BarcodeDetection.Detect request");
        params->width = in_width;
        params->height = in_height;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new BarcodeDetection_Detect_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class BarcodeDetection_Detect_ProxyToResponder {
    public:
        static BarcodeDetection::DetectCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<BarcodeDetection_Detect_ProxyToResponder> proxy(
                new BarcodeDetection_Detect_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&BarcodeDetection_Detect_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~BarcodeDetection_Detect_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "BarcodeDetection::Detect() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        BarcodeDetection_Detect_ProxyToResponder(
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
            std::vector<BarcodeDetectionResultPtr> in_results);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(BarcodeDetection_Detect_ProxyToResponder);
    };

    void BarcodeDetection_Detect_ProxyToResponder::Run(
        std::vector<BarcodeDetectionResultPtr> in_results)
    {
        size_t size = sizeof(::shape_detection::mojom::internal::BarcodeDetection_Detect_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::shape_detection::mojom::BarcodeDetectionResultDataView>>(
            in_results, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kBarcodeDetection_Detect_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::shape_detection::mojom::internal::BarcodeDetection_Detect_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->results)::BaseType* results_ptr;
        const mojo::internal::ContainerValidateParams results_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::shape_detection::mojom::BarcodeDetectionResultDataView>>(
            in_results, builder.buffer(), &results_ptr, &results_validate_params,
            &serialization_context_);
        params->results.Set(results_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->results.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null results in BarcodeDetection.Detect response");
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
    bool BarcodeDetectionStubDispatch::Accept(
        BarcodeDetection* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kBarcodeDetection_Detect_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool BarcodeDetectionStubDispatch::AcceptWithResponder(
        BarcodeDetection* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kBarcodeDetection_Detect_Name: {
            internal::BarcodeDetection_Detect_Params_Data* params = reinterpret_cast<internal::BarcodeDetection_Detect_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedSharedBufferHandle p_frame_data {};
            uint32_t p_width {};
            uint32_t p_height {};
            BarcodeDetection_Detect_ParamsDataView input_data_view(params,
                context);

            p_frame_data = input_data_view.TakeFrameData();
            p_width = input_data_view.width();
            p_height = input_data_view.height();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "BarcodeDetection::Detect deserializer");
                return false;
            }
            BarcodeDetection::DetectCallback callback = BarcodeDetection_Detect_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "BarcodeDetection::Detect");
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

    bool BarcodeDetectionRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "BarcodeDetection RequestValidator");

        switch (message->header()->name) {
        case internal::kBarcodeDetection_Detect_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BarcodeDetection_Detect_Params_Data>(
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

    bool BarcodeDetectionResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "BarcodeDetection ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kBarcodeDetection_Detect_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BarcodeDetection_Detect_ResponseParams_Data>(
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
bool StructTraits<::shape_detection::mojom::BarcodeDetectionResult::DataView, ::shape_detection::mojom::BarcodeDetectionResultPtr>::Read(
    ::shape_detection::mojom::BarcodeDetectionResult::DataView input,
    ::shape_detection::mojom::BarcodeDetectionResultPtr* output)
{
    bool success = true;
    ::shape_detection::mojom::BarcodeDetectionResultPtr result(::shape_detection::mojom::BarcodeDetectionResult::New());

    if (!input.ReadRawValue(&result->raw_value))
        success = false;
    if (!input.ReadBoundingBox(&result->bounding_box))
        success = false;
    if (!input.ReadCornerPoints(&result->corner_points))
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