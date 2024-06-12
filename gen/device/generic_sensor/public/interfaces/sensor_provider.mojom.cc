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

#include "device/generic_sensor/public/interfaces/sensor_provider.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "device/generic_sensor/public/cpp/sensor_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace mojom { // static
    SensorInitParamsPtr SensorInitParams::New()
    {
        SensorInitParamsPtr rv;
        mojo::internal::StructHelper<SensorInitParams>::Initialize(&rv);
        return rv;
    }

    SensorInitParams::SensorInitParams()
        : memory()
        , buffer_offset()
        , mode()
        , default_configuration()
        , maximum_frequency()
    {
    }

    SensorInitParams::~SensorInitParams()
    {
    }
    const char SensorProvider::Name_[] = "device::mojom::SensorProvider";

    class SensorProvider_GetSensor_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        SensorProvider_GetSensor_ForwardToCallback(
            const SensorProvider::GetSensorCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        SensorProvider::GetSensorCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(SensorProvider_GetSensor_ForwardToCallback);
    };
    bool SensorProvider_GetSensor_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::SensorProvider_GetSensor_ResponseParams_Data* params = reinterpret_cast<internal::SensorProvider_GetSensor_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        SensorInitParamsPtr p_init_params {};
        ::device::mojom::SensorClientRequest p_client_request {};
        SensorProvider_GetSensor_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadInitParams(&p_init_params))
            success = false;
        p_client_request = input_data_view.TakeClientRequest<decltype(p_client_request)>();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "SensorProvider::GetSensor response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_init_params),
                std::move(p_client_request));
        }
        return true;
    }

    SensorProviderProxy::SensorProviderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void SensorProviderProxy::GetSensor(
        ::device::mojom::SensorType in_type, ::device::mojom::SensorRequest in_sensor_request, const GetSensorCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::SensorProvider_GetSensor_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kSensorProvider_GetSensor_Name, size);

        auto params = ::device::mojom::internal::SensorProvider_GetSensor_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::SensorType>(
            in_type, &params->type);
        mojo::internal::Serialize<::device::mojom::SensorRequestDataView>(
            in_sensor_request, &params->sensor_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->sensor_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid sensor_request in SensorProvider.GetSensor request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new SensorProvider_GetSensor_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class SensorProvider_GetSensor_ProxyToResponder {
    public:
        static SensorProvider::GetSensorCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<SensorProvider_GetSensor_ProxyToResponder> proxy(
                new SensorProvider_GetSensor_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&SensorProvider_GetSensor_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~SensorProvider_GetSensor_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "SensorProvider::GetSensor() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        SensorProvider_GetSensor_ProxyToResponder(
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
            SensorInitParamsPtr in_init_params, ::device::mojom::SensorClientRequest in_client_request);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(SensorProvider_GetSensor_ProxyToResponder);
    };

    void SensorProvider_GetSensor_ProxyToResponder::Run(
        SensorInitParamsPtr in_init_params, ::device::mojom::SensorClientRequest in_client_request)
    {
        size_t size = sizeof(::device::mojom::internal::SensorProvider_GetSensor_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::SensorInitParamsDataView>(
            in_init_params, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kSensorProvider_GetSensor_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::SensorProvider_GetSensor_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->init_params)::BaseType* init_params_ptr;
        mojo::internal::Serialize<::device::mojom::SensorInitParamsDataView>(
            in_init_params, builder.buffer(), &init_params_ptr, &serialization_context_);
        params->init_params.Set(init_params_ptr);
        mojo::internal::Serialize<::device::mojom::SensorClientRequestDataView>(
            in_client_request, &params->client_request, &serialization_context_);
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
    bool SensorProviderStubDispatch::Accept(
        SensorProvider* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kSensorProvider_GetSensor_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool SensorProviderStubDispatch::AcceptWithResponder(
        SensorProvider* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kSensorProvider_GetSensor_Name: {
            internal::SensorProvider_GetSensor_Params_Data* params = reinterpret_cast<internal::SensorProvider_GetSensor_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::device::mojom::SensorType p_type {};
            ::device::mojom::SensorRequest p_sensor_request {};
            SensorProvider_GetSensor_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadType(&p_type))
                success = false;
            p_sensor_request = input_data_view.TakeSensorRequest<decltype(p_sensor_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "SensorProvider::GetSensor deserializer");
                return false;
            }
            SensorProvider::GetSensorCallback callback = SensorProvider_GetSensor_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "SensorProvider::GetSensor");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetSensor(
                std::move(p_type),
                std::move(p_sensor_request), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool SensorProviderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "SensorProvider RequestValidator");

        switch (message->header()->name) {
        case internal::kSensorProvider_GetSensor_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::SensorProvider_GetSensor_Params_Data>(
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

    bool SensorProviderResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "SensorProvider ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kSensorProvider_GetSensor_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::SensorProvider_GetSensor_ResponseParams_Data>(
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
bool StructTraits<::device::mojom::SensorInitParams::DataView, ::device::mojom::SensorInitParamsPtr>::Read(
    ::device::mojom::SensorInitParams::DataView input,
    ::device::mojom::SensorInitParamsPtr* output)
{
    bool success = true;
    ::device::mojom::SensorInitParamsPtr result(::device::mojom::SensorInitParams::New());

    result->memory = input.TakeMemory();
    result->buffer_offset = input.buffer_offset();
    if (!input.ReadMode(&result->mode))
        success = false;
    if (!input.ReadDefaultConfiguration(&result->default_configuration))
        success = false;
    result->maximum_frequency = input.maximum_frequency();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif