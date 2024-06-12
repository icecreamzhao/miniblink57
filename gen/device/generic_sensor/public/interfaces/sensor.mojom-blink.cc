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

#include "device/generic_sensor/public/interfaces/sensor.mojom-blink.h"

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
namespace device {
namespace mojom {
    namespace blink { // static
        SensorConfigurationPtr SensorConfiguration::New()
        {
            SensorConfigurationPtr rv;
            mojo::internal::StructHelper<SensorConfiguration>::Initialize(&rv);
            return rv;
        }

        SensorConfiguration::SensorConfiguration()
            : frequency()
        {
        }

        SensorConfiguration::~SensorConfiguration()
        {
        }
        size_t SensorConfiguration::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->frequency);
            return seed;
        }
        const char Sensor::Name_[] = "device::mojom::Sensor";

        class Sensor_GetDefaultConfiguration_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Sensor_GetDefaultConfiguration_ForwardToCallback(
                const Sensor::GetDefaultConfigurationCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Sensor::GetDefaultConfigurationCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Sensor_GetDefaultConfiguration_ForwardToCallback);
        };
        bool Sensor_GetDefaultConfiguration_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Sensor_GetDefaultConfiguration_ResponseParams_Data* params = reinterpret_cast<internal::Sensor_GetDefaultConfiguration_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            SensorConfigurationPtr p_configuration {};
            Sensor_GetDefaultConfiguration_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadConfiguration(&p_configuration))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Sensor::GetDefaultConfiguration response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_configuration));
            }
            return true;
        }

        class Sensor_AddConfiguration_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Sensor_AddConfiguration_ForwardToCallback(
                const Sensor::AddConfigurationCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Sensor::AddConfigurationCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Sensor_AddConfiguration_ForwardToCallback);
        };
        bool Sensor_AddConfiguration_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Sensor_AddConfiguration_ResponseParams_Data* params = reinterpret_cast<internal::Sensor_AddConfiguration_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Sensor_AddConfiguration_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Sensor::AddConfiguration response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Sensor_RemoveConfiguration_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Sensor_RemoveConfiguration_ForwardToCallback(
                const Sensor::RemoveConfigurationCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Sensor::RemoveConfigurationCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Sensor_RemoveConfiguration_ForwardToCallback);
        };
        bool Sensor_RemoveConfiguration_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Sensor_RemoveConfiguration_ResponseParams_Data* params = reinterpret_cast<internal::Sensor_RemoveConfiguration_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Sensor_RemoveConfiguration_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Sensor::RemoveConfiguration response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        SensorProxy::SensorProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void SensorProxy::GetDefaultConfiguration(
            const GetDefaultConfigurationCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::Sensor_GetDefaultConfiguration_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kSensor_GetDefaultConfiguration_Name, size);

            auto params = ::device::mojom::internal::Sensor_GetDefaultConfiguration_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Sensor_GetDefaultConfiguration_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void SensorProxy::AddConfiguration(
            SensorConfigurationPtr in_configuration, const AddConfigurationCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::Sensor_AddConfiguration_Params_Data);
            size += mojo::internal::PrepareToSerialize<::device::mojom::SensorConfigurationDataView>(
                in_configuration, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kSensor_AddConfiguration_Name, size);

            auto params = ::device::mojom::internal::Sensor_AddConfiguration_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->configuration)::BaseType* configuration_ptr;
            mojo::internal::Serialize<::device::mojom::SensorConfigurationDataView>(
                in_configuration, builder.buffer(), &configuration_ptr, &serialization_context);
            params->configuration.Set(configuration_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->configuration.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null configuration in Sensor.AddConfiguration request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Sensor_AddConfiguration_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void SensorProxy::RemoveConfiguration(
            SensorConfigurationPtr in_configuration, const RemoveConfigurationCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::Sensor_RemoveConfiguration_Params_Data);
            size += mojo::internal::PrepareToSerialize<::device::mojom::SensorConfigurationDataView>(
                in_configuration, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kSensor_RemoveConfiguration_Name, size);

            auto params = ::device::mojom::internal::Sensor_RemoveConfiguration_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->configuration)::BaseType* configuration_ptr;
            mojo::internal::Serialize<::device::mojom::SensorConfigurationDataView>(
                in_configuration, builder.buffer(), &configuration_ptr, &serialization_context);
            params->configuration.Set(configuration_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->configuration.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null configuration in Sensor.RemoveConfiguration request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Sensor_RemoveConfiguration_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void SensorProxy::Suspend()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::Sensor_Suspend_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kSensor_Suspend_Name, size);

            auto params = ::device::mojom::internal::Sensor_Suspend_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void SensorProxy::Resume()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::Sensor_Resume_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kSensor_Resume_Name, size);

            auto params = ::device::mojom::internal::Sensor_Resume_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }
        class Sensor_GetDefaultConfiguration_ProxyToResponder {
        public:
            static Sensor::GetDefaultConfigurationCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Sensor_GetDefaultConfiguration_ProxyToResponder> proxy(
                    new Sensor_GetDefaultConfiguration_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Sensor_GetDefaultConfiguration_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Sensor_GetDefaultConfiguration_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Sensor::GetDefaultConfiguration() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Sensor_GetDefaultConfiguration_ProxyToResponder(
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
                SensorConfigurationPtr in_configuration);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Sensor_GetDefaultConfiguration_ProxyToResponder);
        };

        void Sensor_GetDefaultConfiguration_ProxyToResponder::Run(
            SensorConfigurationPtr in_configuration)
        {
            size_t size = sizeof(::device::mojom::internal::Sensor_GetDefaultConfiguration_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<::device::mojom::SensorConfigurationDataView>(
                in_configuration, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kSensor_GetDefaultConfiguration_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::mojom::internal::Sensor_GetDefaultConfiguration_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->configuration)::BaseType* configuration_ptr;
            mojo::internal::Serialize<::device::mojom::SensorConfigurationDataView>(
                in_configuration, builder.buffer(), &configuration_ptr, &serialization_context_);
            params->configuration.Set(configuration_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->configuration.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null configuration in Sensor.GetDefaultConfiguration response");
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Sensor_AddConfiguration_ProxyToResponder {
        public:
            static Sensor::AddConfigurationCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Sensor_AddConfiguration_ProxyToResponder> proxy(
                    new Sensor_AddConfiguration_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Sensor_AddConfiguration_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Sensor_AddConfiguration_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Sensor::AddConfiguration() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Sensor_AddConfiguration_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Sensor_AddConfiguration_ProxyToResponder);
        };

        void Sensor_AddConfiguration_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::mojom::internal::Sensor_AddConfiguration_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kSensor_AddConfiguration_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::mojom::internal::Sensor_AddConfiguration_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Sensor_RemoveConfiguration_ProxyToResponder {
        public:
            static Sensor::RemoveConfigurationCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Sensor_RemoveConfiguration_ProxyToResponder> proxy(
                    new Sensor_RemoveConfiguration_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Sensor_RemoveConfiguration_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Sensor_RemoveConfiguration_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Sensor::RemoveConfiguration() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Sensor_RemoveConfiguration_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Sensor_RemoveConfiguration_ProxyToResponder);
        };

        void Sensor_RemoveConfiguration_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::mojom::internal::Sensor_RemoveConfiguration_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kSensor_RemoveConfiguration_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::mojom::internal::Sensor_RemoveConfiguration_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
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
        bool SensorStubDispatch::Accept(
            Sensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kSensor_GetDefaultConfiguration_Name: {
                break;
            }
            case internal::kSensor_AddConfiguration_Name: {
                break;
            }
            case internal::kSensor_RemoveConfiguration_Name: {
                break;
            }
            case internal::kSensor_Suspend_Name: {
                internal::Sensor_Suspend_Params_Data* params = reinterpret_cast<internal::Sensor_Suspend_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Sensor_Suspend_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Sensor::Suspend deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Sensor::Suspend");
                mojo::internal::MessageDispatchContext context(message);
                impl->Suspend();
                return true;
            }
            case internal::kSensor_Resume_Name: {
                internal::Sensor_Resume_Params_Data* params = reinterpret_cast<internal::Sensor_Resume_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Sensor_Resume_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Sensor::Resume deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Sensor::Resume");
                mojo::internal::MessageDispatchContext context(message);
                impl->Resume();
                return true;
            }
            }
            return false;
        }

        // static
        bool SensorStubDispatch::AcceptWithResponder(
            Sensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kSensor_GetDefaultConfiguration_Name: {
                internal::Sensor_GetDefaultConfiguration_Params_Data* params = reinterpret_cast<internal::Sensor_GetDefaultConfiguration_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Sensor_GetDefaultConfiguration_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Sensor::GetDefaultConfiguration deserializer");
                    return false;
                }
                Sensor::GetDefaultConfigurationCallback callback = Sensor_GetDefaultConfiguration_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Sensor::GetDefaultConfiguration");
                mojo::internal::MessageDispatchContext context(message);
                impl->GetDefaultConfiguration(std::move(callback));
                return true;
            }
            case internal::kSensor_AddConfiguration_Name: {
                internal::Sensor_AddConfiguration_Params_Data* params = reinterpret_cast<internal::Sensor_AddConfiguration_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                SensorConfigurationPtr p_configuration {};
                Sensor_AddConfiguration_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadConfiguration(&p_configuration))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Sensor::AddConfiguration deserializer");
                    return false;
                }
                Sensor::AddConfigurationCallback callback = Sensor_AddConfiguration_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Sensor::AddConfiguration");
                mojo::internal::MessageDispatchContext context(message);
                impl->AddConfiguration(
                    std::move(p_configuration), std::move(callback));
                return true;
            }
            case internal::kSensor_RemoveConfiguration_Name: {
                internal::Sensor_RemoveConfiguration_Params_Data* params = reinterpret_cast<internal::Sensor_RemoveConfiguration_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                SensorConfigurationPtr p_configuration {};
                Sensor_RemoveConfiguration_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadConfiguration(&p_configuration))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Sensor::RemoveConfiguration deserializer");
                    return false;
                }
                Sensor::RemoveConfigurationCallback callback = Sensor_RemoveConfiguration_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Sensor::RemoveConfiguration");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoveConfiguration(
                    std::move(p_configuration), std::move(callback));
                return true;
            }
            case internal::kSensor_Suspend_Name: {
                break;
            }
            case internal::kSensor_Resume_Name: {
                break;
            }
            }
            return false;
        }

        bool SensorRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Sensor RequestValidator");

            switch (message->header()->name) {
            case internal::kSensor_GetDefaultConfiguration_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_GetDefaultConfiguration_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensor_AddConfiguration_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_AddConfiguration_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensor_RemoveConfiguration_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_RemoveConfiguration_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensor_Suspend_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_Suspend_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensor_Resume_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_Resume_Params_Data>(
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

        bool SensorResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Sensor ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kSensor_GetDefaultConfiguration_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_GetDefaultConfiguration_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensor_AddConfiguration_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_AddConfiguration_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensor_RemoveConfiguration_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Sensor_RemoveConfiguration_ResponseParams_Data>(
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
        const char SensorClient::Name_[] = "device::mojom::SensorClient";

        SensorClientProxy::SensorClientProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void SensorClientProxy::RaiseError()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::SensorClient_RaiseError_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kSensorClient_RaiseError_Name, size);

            auto params = ::device::mojom::internal::SensorClient_RaiseError_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void SensorClientProxy::SensorReadingChanged()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::SensorClient_SensorReadingChanged_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kSensorClient_SensorReadingChanged_Name, size);

            auto params = ::device::mojom::internal::SensorClient_SensorReadingChanged_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool SensorClientStubDispatch::Accept(
            SensorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kSensorClient_RaiseError_Name: {
                internal::SensorClient_RaiseError_Params_Data* params = reinterpret_cast<internal::SensorClient_RaiseError_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                SensorClient_RaiseError_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "SensorClient::RaiseError deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "SensorClient::RaiseError");
                mojo::internal::MessageDispatchContext context(message);
                impl->RaiseError();
                return true;
            }
            case internal::kSensorClient_SensorReadingChanged_Name: {
                internal::SensorClient_SensorReadingChanged_Params_Data* params = reinterpret_cast<internal::SensorClient_SensorReadingChanged_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                SensorClient_SensorReadingChanged_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "SensorClient::SensorReadingChanged deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "SensorClient::SensorReadingChanged");
                mojo::internal::MessageDispatchContext context(message);
                impl->SensorReadingChanged();
                return true;
            }
            }
            return false;
        }

        // static
        bool SensorClientStubDispatch::AcceptWithResponder(
            SensorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kSensorClient_RaiseError_Name: {
                break;
            }
            case internal::kSensorClient_SensorReadingChanged_Name: {
                break;
            }
            }
            return false;
        }

        bool SensorClientRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "SensorClient RequestValidator");

            switch (message->header()->name) {
            case internal::kSensorClient_RaiseError_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::SensorClient_RaiseError_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensorClient_SensorReadingChanged_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::SensorClient_SensorReadingChanged_Params_Data>(
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
} // namespace device

namespace mojo {

// static
bool StructTraits<::device::mojom::blink::SensorConfiguration::DataView, ::device::mojom::blink::SensorConfigurationPtr>::Read(
    ::device::mojom::blink::SensorConfiguration::DataView input,
    ::device::mojom::blink::SensorConfigurationPtr* output)
{
    bool success = true;
    ::device::mojom::blink::SensorConfigurationPtr result(::device::mojom::blink::SensorConfiguration::New());

    result->frequency = input.frequency();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif