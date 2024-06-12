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

#include "device/geolocation/public/interfaces/geolocation.mojom.h"

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
namespace device {
namespace mojom { // static
    GeopositionPtr Geoposition::New()
    {
        GeopositionPtr rv;
        mojo::internal::StructHelper<Geoposition>::Initialize(&rv);
        return rv;
    }

    Geoposition::Geoposition()
        : valid()
        , latitude()
        , longitude()
        , altitude()
        , accuracy()
        , altitude_accuracy()
        , heading()
        , speed()
        , timestamp()
        , error_code()
        , error_message()
    {
    }

    Geoposition::~Geoposition()
    {
    }
    size_t Geoposition::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->valid);
        seed = mojo::internal::Hash(seed, this->latitude);
        seed = mojo::internal::Hash(seed, this->longitude);
        seed = mojo::internal::Hash(seed, this->altitude);
        seed = mojo::internal::Hash(seed, this->accuracy);
        seed = mojo::internal::Hash(seed, this->altitude_accuracy);
        seed = mojo::internal::Hash(seed, this->heading);
        seed = mojo::internal::Hash(seed, this->speed);
        seed = mojo::internal::Hash(seed, this->timestamp);
        seed = mojo::internal::Hash(seed, this->error_code);
        seed = mojo::internal::Hash(seed, this->error_message);
        return seed;
    }
    const char GeolocationService::Name_[] = "device::mojom::GeolocationService";

    class GeolocationService_QueryNextPosition_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        GeolocationService_QueryNextPosition_ForwardToCallback(
            const GeolocationService::QueryNextPositionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        GeolocationService::QueryNextPositionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(GeolocationService_QueryNextPosition_ForwardToCallback);
    };
    bool GeolocationService_QueryNextPosition_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::GeolocationService_QueryNextPosition_ResponseParams_Data* params = reinterpret_cast<internal::GeolocationService_QueryNextPosition_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        GeopositionPtr p_geoposition {};
        GeolocationService_QueryNextPosition_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadGeoposition(&p_geoposition))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GeolocationService::QueryNextPosition response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_geoposition));
        }
        return true;
    }

    GeolocationServiceProxy::GeolocationServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void GeolocationServiceProxy::SetHighAccuracy(
        bool in_high_accuracy)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GeolocationService_SetHighAccuracy_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kGeolocationService_SetHighAccuracy_Name, size);

        auto params = ::device::mojom::internal::GeolocationService_SetHighAccuracy_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->high_accuracy = in_high_accuracy;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GeolocationServiceProxy::QueryNextPosition(
        const QueryNextPositionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GeolocationService_QueryNextPosition_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kGeolocationService_QueryNextPosition_Name, size);

        auto params = ::device::mojom::internal::GeolocationService_QueryNextPosition_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new GeolocationService_QueryNextPosition_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class GeolocationService_QueryNextPosition_ProxyToResponder {
    public:
        static GeolocationService::QueryNextPositionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<GeolocationService_QueryNextPosition_ProxyToResponder> proxy(
                new GeolocationService_QueryNextPosition_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&GeolocationService_QueryNextPosition_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~GeolocationService_QueryNextPosition_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "GeolocationService::QueryNextPosition() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        GeolocationService_QueryNextPosition_ProxyToResponder(
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
            GeopositionPtr in_geoposition);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(GeolocationService_QueryNextPosition_ProxyToResponder);
    };

    void GeolocationService_QueryNextPosition_ProxyToResponder::Run(
        GeopositionPtr in_geoposition)
    {
        size_t size = sizeof(::device::mojom::internal::GeolocationService_QueryNextPosition_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::GeopositionDataView>(
            in_geoposition, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kGeolocationService_QueryNextPosition_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::GeolocationService_QueryNextPosition_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->geoposition)::BaseType* geoposition_ptr;
        mojo::internal::Serialize<::device::mojom::GeopositionDataView>(
            in_geoposition, builder.buffer(), &geoposition_ptr, &serialization_context_);
        params->geoposition.Set(geoposition_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->geoposition.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null geoposition in GeolocationService.QueryNextPosition response");
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
    bool GeolocationServiceStubDispatch::Accept(
        GeolocationService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kGeolocationService_SetHighAccuracy_Name: {
            internal::GeolocationService_SetHighAccuracy_Params_Data* params = reinterpret_cast<internal::GeolocationService_SetHighAccuracy_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_high_accuracy {};
            GeolocationService_SetHighAccuracy_ParamsDataView input_data_view(params,
                context);

            p_high_accuracy = input_data_view.high_accuracy();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GeolocationService::SetHighAccuracy deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GeolocationService::SetHighAccuracy");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetHighAccuracy(
                std::move(p_high_accuracy));
            return true;
        }
        case internal::kGeolocationService_QueryNextPosition_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool GeolocationServiceStubDispatch::AcceptWithResponder(
        GeolocationService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kGeolocationService_SetHighAccuracy_Name: {
            break;
        }
        case internal::kGeolocationService_QueryNextPosition_Name: {
            internal::GeolocationService_QueryNextPosition_Params_Data* params = reinterpret_cast<internal::GeolocationService_QueryNextPosition_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GeolocationService_QueryNextPosition_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GeolocationService::QueryNextPosition deserializer");
                return false;
            }
            GeolocationService::QueryNextPositionCallback callback = GeolocationService_QueryNextPosition_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GeolocationService::QueryNextPosition");
            mojo::internal::MessageDispatchContext context(message);
            impl->QueryNextPosition(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool GeolocationServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GeolocationService RequestValidator");

        switch (message->header()->name) {
        case internal::kGeolocationService_SetHighAccuracy_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GeolocationService_SetHighAccuracy_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGeolocationService_QueryNextPosition_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GeolocationService_QueryNextPosition_Params_Data>(
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

    bool GeolocationServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GeolocationService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kGeolocationService_QueryNextPosition_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GeolocationService_QueryNextPosition_ResponseParams_Data>(
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
} // namespace device

namespace mojo {

// static
bool StructTraits<::device::mojom::Geoposition::DataView, ::device::mojom::GeopositionPtr>::Read(
    ::device::mojom::Geoposition::DataView input,
    ::device::mojom::GeopositionPtr* output)
{
    bool success = true;
    ::device::mojom::GeopositionPtr result(::device::mojom::Geoposition::New());

    result->valid = input.valid();
    result->latitude = input.latitude();
    result->longitude = input.longitude();
    result->altitude = input.altitude();
    result->accuracy = input.accuracy();
    result->altitude_accuracy = input.altitude_accuracy();
    result->heading = input.heading();
    result->speed = input.speed();
    result->timestamp = input.timestamp();
    if (!input.ReadErrorCode(&result->error_code))
        success = false;
    if (!input.ReadErrorMessage(&result->error_message))
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