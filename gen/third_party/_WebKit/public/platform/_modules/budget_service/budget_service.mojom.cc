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

#include "third_party/WebKit/public/platform/modules/budget_service/budget_service.mojom.h"

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
    BudgetStatePtr BudgetState::New()
    {
        BudgetStatePtr rv;
        mojo::internal::StructHelper<BudgetState>::Initialize(&rv);
        return rv;
    }

    BudgetState::BudgetState()
        : budget_at()
        , time()
    {
    }

    BudgetState::~BudgetState()
    {
    }
    size_t BudgetState::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->budget_at);
        seed = mojo::internal::Hash(seed, this->time);
        return seed;
    }
    const char BudgetService::Name_[] = "blink::mojom::BudgetService";

    class BudgetService_GetCost_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        BudgetService_GetCost_ForwardToCallback(
            const BudgetService::GetCostCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        BudgetService::GetCostCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(BudgetService_GetCost_ForwardToCallback);
    };
    bool BudgetService_GetCost_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::BudgetService_GetCost_ResponseParams_Data* params = reinterpret_cast<internal::BudgetService_GetCost_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        double p_cost {};
        BudgetService_GetCost_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_cost = input_data_view.cost();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BudgetService::GetCost response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_cost));
        }
        return true;
    }

    class BudgetService_GetBudget_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        BudgetService_GetBudget_ForwardToCallback(
            const BudgetService::GetBudgetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        BudgetService::GetBudgetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(BudgetService_GetBudget_ForwardToCallback);
    };
    bool BudgetService_GetBudget_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::BudgetService_GetBudget_ResponseParams_Data* params = reinterpret_cast<internal::BudgetService_GetBudget_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        BudgetServiceErrorType p_error_type {};
        std::vector<BudgetStatePtr> p_budget {};
        BudgetService_GetBudget_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadErrorType(&p_error_type))
            success = false;
        if (!input_data_view.ReadBudget(&p_budget))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BudgetService::GetBudget response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error_type),
                std::move(p_budget));
        }
        return true;
    }

    class BudgetService_Reserve_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        BudgetService_Reserve_ForwardToCallback(
            const BudgetService::ReserveCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        BudgetService::ReserveCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(BudgetService_Reserve_ForwardToCallback);
    };
    bool BudgetService_Reserve_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::BudgetService_Reserve_ResponseParams_Data* params = reinterpret_cast<internal::BudgetService_Reserve_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        BudgetServiceErrorType p_error_type {};
        bool p_success {};
        BudgetService_Reserve_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadErrorType(&p_error_type))
            success = false;
        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BudgetService::Reserve response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error_type),
                std::move(p_success));
        }
        return true;
    }

    BudgetServiceProxy::BudgetServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void BudgetServiceProxy::GetCost(
        BudgetOperationType in_operation, const GetCostCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::BudgetService_GetCost_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kBudgetService_GetCost_Name, size);

        auto params = ::blink::mojom::internal::BudgetService_GetCost_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::BudgetOperationType>(
            in_operation, &params->operation);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new BudgetService_GetCost_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void BudgetServiceProxy::GetBudget(
        const url::Origin& in_origin, const GetBudgetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::BudgetService_GetBudget_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kBudgetService_GetBudget_Name, size);

        auto params = ::blink::mojom::internal::BudgetService_GetBudget_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in BudgetService.GetBudget request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new BudgetService_GetBudget_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void BudgetServiceProxy::Reserve(
        const url::Origin& in_origin, BudgetOperationType in_operation, const ReserveCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::BudgetService_Reserve_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kBudgetService_Reserve_Name, size);

        auto params = ::blink::mojom::internal::BudgetService_Reserve_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in BudgetService.Reserve request");
        mojo::internal::Serialize<::blink::mojom::BudgetOperationType>(
            in_operation, &params->operation);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new BudgetService_Reserve_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class BudgetService_GetCost_ProxyToResponder {
    public:
        static BudgetService::GetCostCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<BudgetService_GetCost_ProxyToResponder> proxy(
                new BudgetService_GetCost_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&BudgetService_GetCost_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~BudgetService_GetCost_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "BudgetService::GetCost() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        BudgetService_GetCost_ProxyToResponder(
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
            double in_cost);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(BudgetService_GetCost_ProxyToResponder);
    };

    void BudgetService_GetCost_ProxyToResponder::Run(
        double in_cost)
    {
        size_t size = sizeof(::blink::mojom::internal::BudgetService_GetCost_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kBudgetService_GetCost_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::BudgetService_GetCost_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->cost = in_cost;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class BudgetService_GetBudget_ProxyToResponder {
    public:
        static BudgetService::GetBudgetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<BudgetService_GetBudget_ProxyToResponder> proxy(
                new BudgetService_GetBudget_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&BudgetService_GetBudget_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~BudgetService_GetBudget_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "BudgetService::GetBudget() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        BudgetService_GetBudget_ProxyToResponder(
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
            BudgetServiceErrorType in_error_type, std::vector<BudgetStatePtr> in_budget);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(BudgetService_GetBudget_ProxyToResponder);
    };

    void BudgetService_GetBudget_ProxyToResponder::Run(
        BudgetServiceErrorType in_error_type, std::vector<BudgetStatePtr> in_budget)
    {
        size_t size = sizeof(::blink::mojom::internal::BudgetService_GetBudget_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::BudgetStateDataView>>(
            in_budget, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kBudgetService_GetBudget_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::BudgetService_GetBudget_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::BudgetServiceErrorType>(
            in_error_type, &params->error_type);
        typename decltype(params->budget)::BaseType* budget_ptr;
        const mojo::internal::ContainerValidateParams budget_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::BudgetStateDataView>>(
            in_budget, builder.buffer(), &budget_ptr, &budget_validate_params,
            &serialization_context_);
        params->budget.Set(budget_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->budget.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null budget in BudgetService.GetBudget response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class BudgetService_Reserve_ProxyToResponder {
    public:
        static BudgetService::ReserveCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<BudgetService_Reserve_ProxyToResponder> proxy(
                new BudgetService_Reserve_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&BudgetService_Reserve_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~BudgetService_Reserve_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "BudgetService::Reserve() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        BudgetService_Reserve_ProxyToResponder(
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
            BudgetServiceErrorType in_error_type, bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(BudgetService_Reserve_ProxyToResponder);
    };

    void BudgetService_Reserve_ProxyToResponder::Run(
        BudgetServiceErrorType in_error_type, bool in_success)
    {
        size_t size = sizeof(::blink::mojom::internal::BudgetService_Reserve_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kBudgetService_Reserve_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::BudgetService_Reserve_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::BudgetServiceErrorType>(
            in_error_type, &params->error_type);
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
    bool BudgetServiceStubDispatch::Accept(
        BudgetService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kBudgetService_GetCost_Name: {
            break;
        }
        case internal::kBudgetService_GetBudget_Name: {
            break;
        }
        case internal::kBudgetService_Reserve_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool BudgetServiceStubDispatch::AcceptWithResponder(
        BudgetService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kBudgetService_GetCost_Name: {
            internal::BudgetService_GetCost_Params_Data* params = reinterpret_cast<internal::BudgetService_GetCost_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            BudgetOperationType p_operation {};
            BudgetService_GetCost_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOperation(&p_operation))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "BudgetService::GetCost deserializer");
                return false;
            }
            BudgetService::GetCostCallback callback = BudgetService_GetCost_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "BudgetService::GetCost");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetCost(
                std::move(p_operation), std::move(callback));
            return true;
        }
        case internal::kBudgetService_GetBudget_Name: {
            internal::BudgetService_GetBudget_Params_Data* params = reinterpret_cast<internal::BudgetService_GetBudget_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            url::Origin p_origin {};
            BudgetService_GetBudget_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "BudgetService::GetBudget deserializer");
                return false;
            }
            BudgetService::GetBudgetCallback callback = BudgetService_GetBudget_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "BudgetService::GetBudget");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetBudget(
                std::move(p_origin), std::move(callback));
            return true;
        }
        case internal::kBudgetService_Reserve_Name: {
            internal::BudgetService_Reserve_Params_Data* params = reinterpret_cast<internal::BudgetService_Reserve_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            url::Origin p_origin {};
            BudgetOperationType p_operation {};
            BudgetService_Reserve_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!input_data_view.ReadOperation(&p_operation))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "BudgetService::Reserve deserializer");
                return false;
            }
            BudgetService::ReserveCallback callback = BudgetService_Reserve_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "BudgetService::Reserve");
            mojo::internal::MessageDispatchContext context(message);
            impl->Reserve(
                std::move(p_origin),
                std::move(p_operation), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool BudgetServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "BudgetService RequestValidator");

        switch (message->header()->name) {
        case internal::kBudgetService_GetCost_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BudgetService_GetCost_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kBudgetService_GetBudget_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BudgetService_GetBudget_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kBudgetService_Reserve_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BudgetService_Reserve_Params_Data>(
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

    bool BudgetServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "BudgetService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kBudgetService_GetCost_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BudgetService_GetCost_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kBudgetService_GetBudget_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BudgetService_GetBudget_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kBudgetService_Reserve_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::BudgetService_Reserve_ResponseParams_Data>(
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
bool StructTraits<::blink::mojom::BudgetState::DataView, ::blink::mojom::BudgetStatePtr>::Read(
    ::blink::mojom::BudgetState::DataView input,
    ::blink::mojom::BudgetStatePtr* output)
{
    bool success = true;
    ::blink::mojom::BudgetStatePtr result(::blink::mojom::BudgetState::New());

    result->budget_at = input.budget_at();
    result->time = input.time();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif