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

#include "services/service_manager/public/interfaces/resolver.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
namespace service_manager {
namespace mojom {
    namespace blink { // static
        ResolveResultPtr ResolveResult::New()
        {
            ResolveResultPtr rv;
            mojo::internal::StructHelper<ResolveResult>::Initialize(&rv);
            return rv;
        }

        ResolveResult::ResolveResult()
            : name()
            , interface_provider_specs()
            , package_path()
        {
        }

        ResolveResult::~ResolveResult()
        {
        }
        const char Resolver::Name_[] = "service_manager::mojom::Resolver";

        class Resolver_ResolveServiceName_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Resolver_ResolveServiceName_ForwardToCallback(
                const Resolver::ResolveServiceNameCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Resolver::ResolveServiceNameCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Resolver_ResolveServiceName_ForwardToCallback);
        };
        bool Resolver_ResolveServiceName_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Resolver_ResolveServiceName_ResponseParams_Data* params = reinterpret_cast<internal::Resolver_ResolveServiceName_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ResolveResultPtr p_result {};
            ResolveResultPtr p_parent {};
            Resolver_ResolveServiceName_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadParent(&p_parent))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Resolver::ResolveServiceName response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_parent));
            }
            return true;
        }

        ResolverProxy::ResolverProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void ResolverProxy::ResolveServiceName(
            const WTF::String& in_service_name, const ResolveServiceNameCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::Resolver_ResolveServiceName_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_service_name, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kResolver_ResolveServiceName_Name, size);

            auto params = ::service_manager::mojom::internal::Resolver_ResolveServiceName_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->service_name)::BaseType* service_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_service_name, builder.buffer(), &service_name_ptr, &serialization_context);
            params->service_name.Set(service_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->service_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null service_name in Resolver.ResolveServiceName request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Resolver_ResolveServiceName_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }
        class Resolver_ResolveServiceName_ProxyToResponder {
        public:
            static Resolver::ResolveServiceNameCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Resolver_ResolveServiceName_ProxyToResponder> proxy(
                    new Resolver_ResolveServiceName_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Resolver_ResolveServiceName_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Resolver_ResolveServiceName_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Resolver::ResolveServiceName() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Resolver_ResolveServiceName_ProxyToResponder(
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
                ResolveResultPtr in_result, ResolveResultPtr in_parent);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Resolver_ResolveServiceName_ProxyToResponder);
        };

        void Resolver_ResolveServiceName_ProxyToResponder::Run(
            ResolveResultPtr in_result, ResolveResultPtr in_parent)
        {
            size_t size = sizeof(::service_manager::mojom::internal::Resolver_ResolveServiceName_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::ResolveResultDataView>(
                in_result, &serialization_context_);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::ResolveResultDataView>(
                in_parent, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kResolver_ResolveServiceName_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::service_manager::mojom::internal::Resolver_ResolveServiceName_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->result)::BaseType* result_ptr;
            mojo::internal::Serialize<::service_manager::mojom::ResolveResultDataView>(
                in_result, builder.buffer(), &result_ptr, &serialization_context_);
            params->result.Set(result_ptr);
            typename decltype(params->parent)::BaseType* parent_ptr;
            mojo::internal::Serialize<::service_manager::mojom::ResolveResultDataView>(
                in_parent, builder.buffer(), &parent_ptr, &serialization_context_);
            params->parent.Set(parent_ptr);
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
        bool ResolverStubDispatch::Accept(
            Resolver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kResolver_ResolveServiceName_Name: {
                break;
            }
            }
            return false;
        }

        // static
        bool ResolverStubDispatch::AcceptWithResponder(
            Resolver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kResolver_ResolveServiceName_Name: {
                internal::Resolver_ResolveServiceName_Params_Data* params = reinterpret_cast<internal::Resolver_ResolveServiceName_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_service_name {};
                Resolver_ResolveServiceName_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadServiceName(&p_service_name))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Resolver::ResolveServiceName deserializer");
                    return false;
                }
                Resolver::ResolveServiceNameCallback callback = Resolver_ResolveServiceName_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Resolver::ResolveServiceName");
                mojo::internal::MessageDispatchContext context(message);
                impl->ResolveServiceName(
                    std::move(p_service_name), std::move(callback));
                return true;
            }
            }
            return false;
        }

        bool ResolverRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Resolver RequestValidator");

            switch (message->header()->name) {
            case internal::kResolver_ResolveServiceName_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Resolver_ResolveServiceName_Params_Data>(
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

        bool ResolverResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Resolver ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kResolver_ResolveServiceName_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Resolver_ResolveServiceName_ResponseParams_Data>(
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
} // namespace service_manager

namespace mojo {

// static
bool StructTraits<::service_manager::mojom::blink::ResolveResult::DataView, ::service_manager::mojom::blink::ResolveResultPtr>::Read(
    ::service_manager::mojom::blink::ResolveResult::DataView input,
    ::service_manager::mojom::blink::ResolveResultPtr* output)
{
    bool success = true;
    ::service_manager::mojom::blink::ResolveResultPtr result(::service_manager::mojom::blink::ResolveResult::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadInterfaceProviderSpecs(&result->interface_provider_specs))
        success = false;
    if (!input.ReadPackagePath(&result->package_path))
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