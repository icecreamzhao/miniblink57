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

#include "third_party/WebKit/public/platform/modules/hyphenation/hyphenation.mojom-blink.h"

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
#include "third_party/WebKit/Source/platform/mojo/BluetoothStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/KURLStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/SecurityOriginStructTraits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
namespace blink {
namespace mojom {
    namespace blink {
        const char Hyphenation::Name_[] = "blink::mojom::Hyphenation";
        bool Hyphenation::OpenDictionary(const WTF::String& locale, base::File* hyphenation_dictionary_handle)
        {
            NOTREACHED();
            return false;
        }
        class Hyphenation_OpenDictionary_HandleSyncResponse
            : public mojo::MessageReceiver {
        public:
            Hyphenation_OpenDictionary_HandleSyncResponse(
                scoped_refptr<mojo::AssociatedGroupController> group_controller,
                bool* result, base::File* out_hyphenation_dictionary_handle)
                : serialization_context_(std::move(group_controller))
                , result_(result)
                , out_hyphenation_dictionary_handle_(out_hyphenation_dictionary_handle)
            {
                DCHECK(!*result_);
            }
            bool Accept(mojo::Message* message) override;

        private:
            mojo::internal::SerializationContext serialization_context_;
            bool* result_;
            base::File* out_hyphenation_dictionary_handle_;
            DISALLOW_COPY_AND_ASSIGN(Hyphenation_OpenDictionary_HandleSyncResponse);
        };
        bool Hyphenation_OpenDictionary_HandleSyncResponse::Accept(
            mojo::Message* message)
        {
            internal::Hyphenation_OpenDictionary_ResponseParams_Data* params = reinterpret_cast<internal::Hyphenation_OpenDictionary_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::File p_hyphenation_dictionary_handle {};
            Hyphenation_OpenDictionary_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadHyphenationDictionaryHandle(&p_hyphenation_dictionary_handle))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Hyphenation::OpenDictionary response deserializer");
                return false;
            }
            *out_hyphenation_dictionary_handle_ = std::move(p_hyphenation_dictionary_handle);
            mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
                message);
            *result_ = true;
            return true;
        }

        class Hyphenation_OpenDictionary_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Hyphenation_OpenDictionary_ForwardToCallback(
                const Hyphenation::OpenDictionaryCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Hyphenation::OpenDictionaryCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Hyphenation_OpenDictionary_ForwardToCallback);
        };
        bool Hyphenation_OpenDictionary_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Hyphenation_OpenDictionary_ResponseParams_Data* params = reinterpret_cast<internal::Hyphenation_OpenDictionary_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::File p_hyphenation_dictionary_handle {};
            Hyphenation_OpenDictionary_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadHyphenationDictionaryHandle(&p_hyphenation_dictionary_handle))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Hyphenation::OpenDictionary response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_hyphenation_dictionary_handle));
            }
            return true;
        }

        HyphenationProxy::HyphenationProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }
        bool HyphenationProxy::OpenDictionary(
            const WTF::String& param_locale, base::File* param_hyphenation_dictionary_handle)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::Hyphenation_OpenDictionary_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                param_locale, &serialization_context);

            mojo::internal::RequestMessageBuilder builder(internal::kHyphenation_OpenDictionary_Name, size,
                mojo::Message::kFlagIsSync);

            auto params = ::blink::mojom::internal::Hyphenation_OpenDictionary_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->locale)::BaseType* locale_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                param_locale, builder.buffer(), &locale_ptr, &serialization_context);
            params->locale.Set(locale_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->locale.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null locale in Hyphenation.OpenDictionary request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

            bool result = false;
            mojo::MessageReceiver* responder = new Hyphenation_OpenDictionary_HandleSyncResponse(
                group_controller_, &result, param_hyphenation_dictionary_handle);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
            return result;
        }

        void HyphenationProxy::OpenDictionary(
            const WTF::String& in_locale, const OpenDictionaryCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::Hyphenation_OpenDictionary_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_locale, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kHyphenation_OpenDictionary_Name, size);

            auto params = ::blink::mojom::internal::Hyphenation_OpenDictionary_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->locale)::BaseType* locale_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_locale, builder.buffer(), &locale_ptr, &serialization_context);
            params->locale.Set(locale_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->locale.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null locale in Hyphenation.OpenDictionary request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Hyphenation_OpenDictionary_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }
        class Hyphenation_OpenDictionary_ProxyToResponder {
        public:
            static Hyphenation::OpenDictionaryCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Hyphenation_OpenDictionary_ProxyToResponder> proxy(
                    new Hyphenation_OpenDictionary_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Hyphenation_OpenDictionary_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Hyphenation_OpenDictionary_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Hyphenation::OpenDictionary() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Hyphenation_OpenDictionary_ProxyToResponder(
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
                base::File in_hyphenation_dictionary_handle);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Hyphenation_OpenDictionary_ProxyToResponder);
        };

        void Hyphenation_OpenDictionary_ProxyToResponder::Run(
            base::File in_hyphenation_dictionary_handle)
        {
            size_t size = sizeof(::blink::mojom::internal::Hyphenation_OpenDictionary_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::FileDataView>(
                in_hyphenation_dictionary_handle, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kHyphenation_OpenDictionary_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::Hyphenation_OpenDictionary_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->hyphenation_dictionary_handle)::BaseType* hyphenation_dictionary_handle_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::FileDataView>(
                in_hyphenation_dictionary_handle, builder.buffer(), &hyphenation_dictionary_handle_ptr, &serialization_context_);
            params->hyphenation_dictionary_handle.Set(hyphenation_dictionary_handle_ptr);
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
        bool HyphenationStubDispatch::Accept(
            Hyphenation* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kHyphenation_OpenDictionary_Name: {
                break;
            }
            }
            return false;
        }

        // static
        bool HyphenationStubDispatch::AcceptWithResponder(
            Hyphenation* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kHyphenation_OpenDictionary_Name: {
                internal::Hyphenation_OpenDictionary_Params_Data* params = reinterpret_cast<internal::Hyphenation_OpenDictionary_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_locale {};
                Hyphenation_OpenDictionary_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadLocale(&p_locale))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Hyphenation::OpenDictionary deserializer");
                    return false;
                }
                Hyphenation::OpenDictionaryCallback callback = Hyphenation_OpenDictionary_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Hyphenation::OpenDictionary");
                mojo::internal::MessageDispatchContext context(message);
                impl->OpenDictionary(
                    std::move(p_locale), std::move(callback));
                return true;
            }
            }
            return false;
        }

        bool HyphenationRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Hyphenation RequestValidator");

            switch (message->header()->name) {
            case internal::kHyphenation_OpenDictionary_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Hyphenation_OpenDictionary_Params_Data>(
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

        bool HyphenationResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Hyphenation ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kHyphenation_OpenDictionary_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Hyphenation_OpenDictionary_ResponseParams_Data>(
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
} // namespace blink

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif