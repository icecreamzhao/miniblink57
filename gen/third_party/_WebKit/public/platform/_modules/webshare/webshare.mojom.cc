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

#include "third_party/WebKit/public/platform/modules/webshare/webshare.mojom.h"

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
namespace blink {
namespace mojom {
    const char ShareService::Name_[] = "blink::mojom::ShareService";

    class ShareService_Share_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ShareService_Share_ForwardToCallback(
            const ShareService::ShareCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ShareService::ShareCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ShareService_Share_ForwardToCallback);
    };
    bool ShareService_Share_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ShareService_Share_ResponseParams_Data* params = reinterpret_cast<internal::ShareService_Share_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        base::Optional<std::string> p_error {};
        ShareService_Share_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ShareService::Share response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }

    ShareServiceProxy::ShareServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ShareServiceProxy::Share(
        const std::string& in_title, const std::string& in_text, const GURL& in_url, const ShareCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::ShareService_Share_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_title, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_text, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kShareService_Share_Name, size);

        auto params = ::blink::mojom::internal::ShareService_Share_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->title)::BaseType* title_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_title, builder.buffer(), &title_ptr, &serialization_context);
        params->title.Set(title_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->title.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null title in ShareService.Share request");
        typename decltype(params->text)::BaseType* text_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_text, builder.buffer(), &text_ptr, &serialization_context);
        params->text.Set(text_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->text.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null text in ShareService.Share request");
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in ShareService.Share request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ShareService_Share_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class ShareService_Share_ProxyToResponder {
    public:
        static ShareService::ShareCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ShareService_Share_ProxyToResponder> proxy(
                new ShareService_Share_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ShareService_Share_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ShareService_Share_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ShareService::Share() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ShareService_Share_ProxyToResponder(
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
            const base::Optional<std::string>& in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ShareService_Share_ProxyToResponder);
    };

    void ShareService_Share_ProxyToResponder::Run(
        const base::Optional<std::string>& in_error)
    {
        size_t size = sizeof(::blink::mojom::internal::ShareService_Share_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_error, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kShareService_Share_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::ShareService_Share_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->error)::BaseType* error_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_error, builder.buffer(), &error_ptr, &serialization_context_);
        params->error.Set(error_ptr);
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
    bool ShareServiceStubDispatch::Accept(
        ShareService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kShareService_Share_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ShareServiceStubDispatch::AcceptWithResponder(
        ShareService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kShareService_Share_Name: {
            internal::ShareService_Share_Params_Data* params = reinterpret_cast<internal::ShareService_Share_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_title {};
            std::string p_text {};
            GURL p_url {};
            ShareService_Share_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTitle(&p_title))
                success = false;
            if (!input_data_view.ReadText(&p_text))
                success = false;
            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ShareService::Share deserializer");
                return false;
            }
            ShareService::ShareCallback callback = ShareService_Share_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ShareService::Share");
            mojo::internal::MessageDispatchContext context(message);
            impl->Share(
                std::move(p_title),
                std::move(p_text),
                std::move(p_url), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ShareServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ShareService RequestValidator");

        switch (message->header()->name) {
        case internal::kShareService_Share_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ShareService_Share_Params_Data>(
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

    bool ShareServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ShareService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kShareService_Share_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ShareService_Share_ResponseParams_Data>(
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

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif