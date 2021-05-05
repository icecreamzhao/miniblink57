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

#include "components/payments/payment_app.mojom.h"

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
#include "url/mojo/url_gurl_struct_traits.h"
namespace payments {
namespace mojom { // static
    PaymentAppOptionPtr PaymentAppOption::New()
    {
        PaymentAppOptionPtr rv;
        mojo::internal::StructHelper<PaymentAppOption>::Initialize(&rv);
        return rv;
    }

    PaymentAppOption::PaymentAppOption()
        : name()
        , icon()
        , id()
        , enabled_methods()
    {
    }

    PaymentAppOption::~PaymentAppOption()
    {
    } // static
    PaymentAppManifestPtr PaymentAppManifest::New()
    {
        PaymentAppManifestPtr rv;
        mojo::internal::StructHelper<PaymentAppManifest>::Initialize(&rv);
        return rv;
    }

    PaymentAppManifest::PaymentAppManifest()
        : name()
        , icon()
        , options()
    {
    }

    PaymentAppManifest::~PaymentAppManifest()
    {
    } // static
    PaymentAppRequestDataPtr PaymentAppRequestData::New()
    {
        PaymentAppRequestDataPtr rv;
        mojo::internal::StructHelper<PaymentAppRequestData>::Initialize(&rv);
        return rv;
    }

    PaymentAppRequestData::PaymentAppRequestData()
        : origin()
        , methodData()
        , total()
        , modifiers()
        , optionId()
    {
    }

    PaymentAppRequestData::~PaymentAppRequestData()
    {
    }
    const char PaymentAppManager::Name_[] = "payments::mojom::PaymentAppManager";

    class PaymentAppManager_SetManifest_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PaymentAppManager_SetManifest_ForwardToCallback(
            const PaymentAppManager::SetManifestCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PaymentAppManager::SetManifestCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PaymentAppManager_SetManifest_ForwardToCallback);
    };
    bool PaymentAppManager_SetManifest_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PaymentAppManager_SetManifest_ResponseParams_Data* params = reinterpret_cast<internal::PaymentAppManager_SetManifest_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        PaymentAppManifestError p_error {};
        PaymentAppManager_SetManifest_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PaymentAppManager::SetManifest response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }

    class PaymentAppManager_GetManifest_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PaymentAppManager_GetManifest_ForwardToCallback(
            const PaymentAppManager::GetManifestCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PaymentAppManager::GetManifestCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PaymentAppManager_GetManifest_ForwardToCallback);
    };
    bool PaymentAppManager_GetManifest_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PaymentAppManager_GetManifest_ResponseParams_Data* params = reinterpret_cast<internal::PaymentAppManager_GetManifest_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        PaymentAppManifestPtr p_payment_app_manifest {};
        PaymentAppManifestError p_error {};
        PaymentAppManager_GetManifest_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadPaymentAppManifest(&p_payment_app_manifest))
            success = false;
        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PaymentAppManager::GetManifest response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_payment_app_manifest),
                std::move(p_error));
        }
        return true;
    }

    PaymentAppManagerProxy::PaymentAppManagerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PaymentAppManagerProxy::Init(
        const std::string& in_service_worker_scope)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentAppManager_Init_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_service_worker_scope, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPaymentAppManager_Init_Name, size);

        auto params = ::payments::mojom::internal::PaymentAppManager_Init_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->service_worker_scope)::BaseType* service_worker_scope_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_service_worker_scope, builder.buffer(), &service_worker_scope_ptr, &serialization_context);
        params->service_worker_scope.Set(service_worker_scope_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->service_worker_scope.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null service_worker_scope in PaymentAppManager.Init request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentAppManagerProxy::SetManifest(
        PaymentAppManifestPtr in_payment_app_manifest, const SetManifestCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentAppManager_SetManifest_Params_Data);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentAppManifestDataView>(
            in_payment_app_manifest, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPaymentAppManager_SetManifest_Name, size);

        auto params = ::payments::mojom::internal::PaymentAppManager_SetManifest_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->payment_app_manifest)::BaseType* payment_app_manifest_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentAppManifestDataView>(
            in_payment_app_manifest, builder.buffer(), &payment_app_manifest_ptr, &serialization_context);
        params->payment_app_manifest.Set(payment_app_manifest_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->payment_app_manifest.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null payment_app_manifest in PaymentAppManager.SetManifest request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PaymentAppManager_SetManifest_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PaymentAppManagerProxy::GetManifest(
        const GetManifestCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentAppManager_GetManifest_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kPaymentAppManager_GetManifest_Name, size);

        auto params = ::payments::mojom::internal::PaymentAppManager_GetManifest_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PaymentAppManager_GetManifest_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class PaymentAppManager_SetManifest_ProxyToResponder {
    public:
        static PaymentAppManager::SetManifestCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PaymentAppManager_SetManifest_ProxyToResponder> proxy(
                new PaymentAppManager_SetManifest_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PaymentAppManager_SetManifest_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PaymentAppManager_SetManifest_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PaymentAppManager::SetManifest() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PaymentAppManager_SetManifest_ProxyToResponder(
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
            PaymentAppManifestError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PaymentAppManager_SetManifest_ProxyToResponder);
    };

    void PaymentAppManager_SetManifest_ProxyToResponder::Run(
        PaymentAppManifestError in_error)
    {
        size_t size = sizeof(::payments::mojom::internal::PaymentAppManager_SetManifest_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPaymentAppManager_SetManifest_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::payments::mojom::internal::PaymentAppManager_SetManifest_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::payments::mojom::PaymentAppManifestError>(
            in_error, &params->error);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class PaymentAppManager_GetManifest_ProxyToResponder {
    public:
        static PaymentAppManager::GetManifestCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PaymentAppManager_GetManifest_ProxyToResponder> proxy(
                new PaymentAppManager_GetManifest_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PaymentAppManager_GetManifest_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PaymentAppManager_GetManifest_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PaymentAppManager::GetManifest() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PaymentAppManager_GetManifest_ProxyToResponder(
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
            PaymentAppManifestPtr in_payment_app_manifest, PaymentAppManifestError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PaymentAppManager_GetManifest_ProxyToResponder);
    };

    void PaymentAppManager_GetManifest_ProxyToResponder::Run(
        PaymentAppManifestPtr in_payment_app_manifest, PaymentAppManifestError in_error)
    {
        size_t size = sizeof(::payments::mojom::internal::PaymentAppManager_GetManifest_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentAppManifestDataView>(
            in_payment_app_manifest, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPaymentAppManager_GetManifest_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::payments::mojom::internal::PaymentAppManager_GetManifest_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->payment_app_manifest)::BaseType* payment_app_manifest_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentAppManifestDataView>(
            in_payment_app_manifest, builder.buffer(), &payment_app_manifest_ptr, &serialization_context_);
        params->payment_app_manifest.Set(payment_app_manifest_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->payment_app_manifest.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null payment_app_manifest in PaymentAppManager.GetManifest response");
        mojo::internal::Serialize<::payments::mojom::PaymentAppManifestError>(
            in_error, &params->error);
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
    bool PaymentAppManagerStubDispatch::Accept(
        PaymentAppManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPaymentAppManager_Init_Name: {
            internal::PaymentAppManager_Init_Params_Data* params = reinterpret_cast<internal::PaymentAppManager_Init_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_service_worker_scope {};
            PaymentAppManager_Init_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadServiceWorkerScope(&p_service_worker_scope))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentAppManager::Init deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentAppManager::Init");
            mojo::internal::MessageDispatchContext context(message);
            impl->Init(
                std::move(p_service_worker_scope));
            return true;
        }
        case internal::kPaymentAppManager_SetManifest_Name: {
            break;
        }
        case internal::kPaymentAppManager_GetManifest_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool PaymentAppManagerStubDispatch::AcceptWithResponder(
        PaymentAppManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPaymentAppManager_Init_Name: {
            break;
        }
        case internal::kPaymentAppManager_SetManifest_Name: {
            internal::PaymentAppManager_SetManifest_Params_Data* params = reinterpret_cast<internal::PaymentAppManager_SetManifest_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentAppManifestPtr p_payment_app_manifest {};
            PaymentAppManager_SetManifest_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPaymentAppManifest(&p_payment_app_manifest))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentAppManager::SetManifest deserializer");
                return false;
            }
            PaymentAppManager::SetManifestCallback callback = PaymentAppManager_SetManifest_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentAppManager::SetManifest");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetManifest(
                std::move(p_payment_app_manifest), std::move(callback));
            return true;
        }
        case internal::kPaymentAppManager_GetManifest_Name: {
            internal::PaymentAppManager_GetManifest_Params_Data* params = reinterpret_cast<internal::PaymentAppManager_GetManifest_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentAppManager_GetManifest_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentAppManager::GetManifest deserializer");
                return false;
            }
            PaymentAppManager::GetManifestCallback callback = PaymentAppManager_GetManifest_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentAppManager::GetManifest");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetManifest(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool PaymentAppManagerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PaymentAppManager RequestValidator");

        switch (message->header()->name) {
        case internal::kPaymentAppManager_Init_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentAppManager_Init_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentAppManager_SetManifest_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentAppManager_SetManifest_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentAppManager_GetManifest_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentAppManager_GetManifest_Params_Data>(
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

    bool PaymentAppManagerResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PaymentAppManager ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kPaymentAppManager_SetManifest_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentAppManager_SetManifest_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentAppManager_GetManifest_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentAppManager_GetManifest_ResponseParams_Data>(
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
} // namespace payments

namespace mojo {

// static
bool StructTraits<::payments::mojom::PaymentAppOption::DataView, ::payments::mojom::PaymentAppOptionPtr>::Read(
    ::payments::mojom::PaymentAppOption::DataView input,
    ::payments::mojom::PaymentAppOptionPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentAppOptionPtr result(::payments::mojom::PaymentAppOption::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadIcon(&result->icon))
        success = false;
    if (!input.ReadId(&result->id))
        success = false;
    if (!input.ReadEnabledMethods(&result->enabled_methods))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentAppManifest::DataView, ::payments::mojom::PaymentAppManifestPtr>::Read(
    ::payments::mojom::PaymentAppManifest::DataView input,
    ::payments::mojom::PaymentAppManifestPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentAppManifestPtr result(::payments::mojom::PaymentAppManifest::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadIcon(&result->icon))
        success = false;
    if (!input.ReadOptions(&result->options))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentAppRequestData::DataView, ::payments::mojom::PaymentAppRequestDataPtr>::Read(
    ::payments::mojom::PaymentAppRequestData::DataView input,
    ::payments::mojom::PaymentAppRequestDataPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentAppRequestDataPtr result(::payments::mojom::PaymentAppRequestData::New());

    if (!input.ReadOrigin(&result->origin))
        success = false;
    if (!input.ReadMethoddata(&result->methodData))
        success = false;
    if (!input.ReadTotal(&result->total))
        success = false;
    if (!input.ReadModifiers(&result->modifiers))
        success = false;
    if (!input.ReadOptionid(&result->optionId))
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