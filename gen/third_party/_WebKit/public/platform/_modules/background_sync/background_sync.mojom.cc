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

#include "third_party/WebKit/public/platform/modules/background_sync/background_sync.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace blink {
namespace mojom { // static
    SyncRegistrationPtr SyncRegistration::New()
    {
        SyncRegistrationPtr rv;
        mojo::internal::StructHelper<SyncRegistration>::Initialize(&rv);
        return rv;
    }

    SyncRegistration::SyncRegistration()
        : id(-1)
        , tag("")
        , network_state(BackgroundSyncNetworkState::ONLINE)
    {
    }

    SyncRegistration::~SyncRegistration()
    {
    }
    size_t SyncRegistration::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->id);
        seed = mojo::internal::Hash(seed, this->tag);
        seed = mojo::internal::Hash(seed, this->network_state);
        return seed;
    }
    const char BackgroundSyncService::Name_[] = "blink::mojom::BackgroundSyncService";

    class BackgroundSyncService_Register_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        BackgroundSyncService_Register_ForwardToCallback(
            const BackgroundSyncService::RegisterCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        BackgroundSyncService::RegisterCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(BackgroundSyncService_Register_ForwardToCallback);
    };
    bool BackgroundSyncService_Register_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::BackgroundSyncService_Register_ResponseParams_Data* params = reinterpret_cast<internal::BackgroundSyncService_Register_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        BackgroundSyncError p_err {};
        SyncRegistrationPtr p_options {};
        BackgroundSyncService_Register_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadErr(&p_err))
            success = false;
        if (!input_data_view.ReadOptions(&p_options))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BackgroundSyncService::Register response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_err),
                std::move(p_options));
        }
        return true;
    }

    class BackgroundSyncService_GetRegistrations_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        BackgroundSyncService_GetRegistrations_ForwardToCallback(
            const BackgroundSyncService::GetRegistrationsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        BackgroundSyncService::GetRegistrationsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(BackgroundSyncService_GetRegistrations_ForwardToCallback);
    };
    bool BackgroundSyncService_GetRegistrations_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data* params = reinterpret_cast<internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        BackgroundSyncError p_err {};
        std::vector<SyncRegistrationPtr> p_registrations {};
        BackgroundSyncService_GetRegistrations_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadErr(&p_err))
            success = false;
        if (!input_data_view.ReadRegistrations(&p_registrations))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BackgroundSyncService::GetRegistrations response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_err),
                std::move(p_registrations));
        }
        return true;
    }

    BackgroundSyncServiceProxy::BackgroundSyncServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void BackgroundSyncServiceProxy::Register(
        SyncRegistrationPtr in_options, int64_t in_service_worker_registration_id, const RegisterCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::BackgroundSyncService_Register_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::SyncRegistrationDataView>(
            in_options, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kBackgroundSyncService_Register_Name, size);

        auto params = ::blink::mojom::internal::BackgroundSyncService_Register_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->options)::BaseType* options_ptr;
        mojo::internal::Serialize<::blink::mojom::SyncRegistrationDataView>(
            in_options, builder.buffer(), &options_ptr, &serialization_context);
        params->options.Set(options_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->options.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null options in BackgroundSyncService.Register request");
        params->service_worker_registration_id = in_service_worker_registration_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new BackgroundSyncService_Register_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void BackgroundSyncServiceProxy::GetRegistrations(
        int64_t in_service_worker_registration_id, const GetRegistrationsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::BackgroundSyncService_GetRegistrations_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kBackgroundSyncService_GetRegistrations_Name, size);

        auto params = ::blink::mojom::internal::BackgroundSyncService_GetRegistrations_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->service_worker_registration_id = in_service_worker_registration_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new BackgroundSyncService_GetRegistrations_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class BackgroundSyncService_Register_ProxyToResponder {
    public:
        static BackgroundSyncService::RegisterCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<BackgroundSyncService_Register_ProxyToResponder> proxy(
                new BackgroundSyncService_Register_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&BackgroundSyncService_Register_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~BackgroundSyncService_Register_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "BackgroundSyncService::Register() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        BackgroundSyncService_Register_ProxyToResponder(
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
            BackgroundSyncError in_err, SyncRegistrationPtr in_options);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(BackgroundSyncService_Register_ProxyToResponder);
    };

    void BackgroundSyncService_Register_ProxyToResponder::Run(
        BackgroundSyncError in_err, SyncRegistrationPtr in_options)
    {
        size_t size = sizeof(::blink::mojom::internal::BackgroundSyncService_Register_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::SyncRegistrationDataView>(
            in_options, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kBackgroundSyncService_Register_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::BackgroundSyncService_Register_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::BackgroundSyncError>(
            in_err, &params->err);
        typename decltype(params->options)::BaseType* options_ptr;
        mojo::internal::Serialize<::blink::mojom::SyncRegistrationDataView>(
            in_options, builder.buffer(), &options_ptr, &serialization_context_);
        params->options.Set(options_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->options.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null options in BackgroundSyncService.Register response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class BackgroundSyncService_GetRegistrations_ProxyToResponder {
    public:
        static BackgroundSyncService::GetRegistrationsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<BackgroundSyncService_GetRegistrations_ProxyToResponder> proxy(
                new BackgroundSyncService_GetRegistrations_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&BackgroundSyncService_GetRegistrations_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~BackgroundSyncService_GetRegistrations_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "BackgroundSyncService::GetRegistrations() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        BackgroundSyncService_GetRegistrations_ProxyToResponder(
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
            BackgroundSyncError in_err, std::vector<SyncRegistrationPtr> in_registrations);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(BackgroundSyncService_GetRegistrations_ProxyToResponder);
    };

    void BackgroundSyncService_GetRegistrations_ProxyToResponder::Run(
        BackgroundSyncError in_err, std::vector<SyncRegistrationPtr> in_registrations)
    {
        size_t size = sizeof(::blink::mojom::internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::SyncRegistrationDataView>>(
            in_registrations, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kBackgroundSyncService_GetRegistrations_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::BackgroundSyncError>(
            in_err, &params->err);
        typename decltype(params->registrations)::BaseType* registrations_ptr;
        const mojo::internal::ContainerValidateParams registrations_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::SyncRegistrationDataView>>(
            in_registrations, builder.buffer(), &registrations_ptr, &registrations_validate_params,
            &serialization_context_);
        params->registrations.Set(registrations_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->registrations.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null registrations in BackgroundSyncService.GetRegistrations response");
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
    bool BackgroundSyncServiceStubDispatch::Accept(
        BackgroundSyncService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kBackgroundSyncService_Register_Name: {
            break;
        }
        case internal::kBackgroundSyncService_GetRegistrations_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool BackgroundSyncServiceStubDispatch::AcceptWithResponder(
        BackgroundSyncService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kBackgroundSyncService_Register_Name: {
            internal::BackgroundSyncService_Register_Params_Data* params = reinterpret_cast<internal::BackgroundSyncService_Register_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            SyncRegistrationPtr p_options {};
            int64_t p_service_worker_registration_id {};
            BackgroundSyncService_Register_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOptions(&p_options))
                success = false;
            p_service_worker_registration_id = input_data_view.service_worker_registration_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "BackgroundSyncService::Register deserializer");
                return false;
            }
            BackgroundSyncService::RegisterCallback callback = BackgroundSyncService_Register_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "BackgroundSyncService::Register");
            mojo::internal::MessageDispatchContext context(message);
            impl->Register(
                std::move(p_options),
                std::move(p_service_worker_registration_id), std::move(callback));
            return true;
        }
        case internal::kBackgroundSyncService_GetRegistrations_Name: {
            internal::BackgroundSyncService_GetRegistrations_Params_Data* params = reinterpret_cast<internal::BackgroundSyncService_GetRegistrations_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_service_worker_registration_id {};
            BackgroundSyncService_GetRegistrations_ParamsDataView input_data_view(params,
                context);

            p_service_worker_registration_id = input_data_view.service_worker_registration_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "BackgroundSyncService::GetRegistrations deserializer");
                return false;
            }
            BackgroundSyncService::GetRegistrationsCallback callback = BackgroundSyncService_GetRegistrations_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "BackgroundSyncService::GetRegistrations");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetRegistrations(
                std::move(p_service_worker_registration_id), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool BackgroundSyncServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "BackgroundSyncService RequestValidator");

        switch (message->header()->name) {
        case internal::kBackgroundSyncService_Register_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BackgroundSyncService_Register_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kBackgroundSyncService_GetRegistrations_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BackgroundSyncService_GetRegistrations_Params_Data>(
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

    bool BackgroundSyncServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "BackgroundSyncService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kBackgroundSyncService_Register_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BackgroundSyncService_Register_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kBackgroundSyncService_GetRegistrations_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data>(
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
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::SyncRegistration::DataView, ::blink::mojom::SyncRegistrationPtr>::Read(
    ::blink::mojom::SyncRegistration::DataView input,
    ::blink::mojom::SyncRegistrationPtr* output)
{
    bool success = true;
    ::blink::mojom::SyncRegistrationPtr result(::blink::mojom::SyncRegistration::New());

    result->id = input.id();
    if (!input.ReadTag(&result->tag))
        success = false;
    if (!input.ReadNetworkState(&result->network_state))
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