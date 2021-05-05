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

#include "components/web_restrictions/interfaces/web_restrictions.mojom.h"

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
namespace web_restrictions {
namespace mojom { // static
    ClientResultPtr ClientResult::New()
    {
        ClientResultPtr rv;
        mojo::internal::StructHelper<ClientResult>::Initialize(&rv);
        return rv;
    }

    ClientResult::ClientResult()
        : intParams()
        , stringParams()
    {
    }

    ClientResult::~ClientResult()
    {
    }
    const char WebRestrictions::Name_[] = "web_restrictions::mojom::WebRestrictions";
    bool WebRestrictions::GetResult(const std::string& url, ClientResultPtr* reply)
    {
        NOTREACHED();
        return false;
    }
    class WebRestrictions_GetResult_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        WebRestrictions_GetResult_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ClientResultPtr* out_reply)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_reply_(out_reply)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ClientResultPtr* out_reply_;
        DISALLOW_COPY_AND_ASSIGN(WebRestrictions_GetResult_HandleSyncResponse);
    };
    bool WebRestrictions_GetResult_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::WebRestrictions_GetResult_ResponseParams_Data* params = reinterpret_cast<internal::WebRestrictions_GetResult_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ClientResultPtr p_reply {};
        WebRestrictions_GetResult_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadReply(&p_reply))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WebRestrictions::GetResult response deserializer");
            return false;
        }
        *out_reply_ = std::move(p_reply);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class WebRestrictions_GetResult_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WebRestrictions_GetResult_ForwardToCallback(
            const WebRestrictions::GetResultCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WebRestrictions::GetResultCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WebRestrictions_GetResult_ForwardToCallback);
    };
    bool WebRestrictions_GetResult_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WebRestrictions_GetResult_ResponseParams_Data* params = reinterpret_cast<internal::WebRestrictions_GetResult_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ClientResultPtr p_reply {};
        WebRestrictions_GetResult_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadReply(&p_reply))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WebRestrictions::GetResult response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_reply));
        }
        return true;
    }

    class WebRestrictions_RequestPermission_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WebRestrictions_RequestPermission_ForwardToCallback(
            const WebRestrictions::RequestPermissionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WebRestrictions::RequestPermissionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WebRestrictions_RequestPermission_ForwardToCallback);
    };
    bool WebRestrictions_RequestPermission_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WebRestrictions_RequestPermission_ResponseParams_Data* params = reinterpret_cast<internal::WebRestrictions_RequestPermission_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_result {};
        WebRestrictions_RequestPermission_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_result = input_data_view.result();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WebRestrictions::RequestPermission response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    WebRestrictionsProxy::WebRestrictionsProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool WebRestrictionsProxy::GetResult(
        const std::string& param_url, ClientResultPtr* param_reply)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::web_restrictions::mojom::internal::WebRestrictions_GetResult_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_url, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kWebRestrictions_GetResult_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::web_restrictions::mojom::internal::WebRestrictions_GetResult_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in WebRestrictions.GetResult request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new WebRestrictions_GetResult_HandleSyncResponse(
            group_controller_, &result, param_reply);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void WebRestrictionsProxy::GetResult(
        const std::string& in_url, const GetResultCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::web_restrictions::mojom::internal::WebRestrictions_GetResult_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_url, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kWebRestrictions_GetResult_Name, size);

        auto params = ::web_restrictions::mojom::internal::WebRestrictions_GetResult_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in WebRestrictions.GetResult request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WebRestrictions_GetResult_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WebRestrictionsProxy::RequestPermission(
        const std::string& in_url, const RequestPermissionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::web_restrictions::mojom::internal::WebRestrictions_RequestPermission_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_url, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kWebRestrictions_RequestPermission_Name, size);

        auto params = ::web_restrictions::mojom::internal::WebRestrictions_RequestPermission_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in WebRestrictions.RequestPermission request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WebRestrictions_RequestPermission_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class WebRestrictions_GetResult_ProxyToResponder {
    public:
        static WebRestrictions::GetResultCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WebRestrictions_GetResult_ProxyToResponder> proxy(
                new WebRestrictions_GetResult_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WebRestrictions_GetResult_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WebRestrictions_GetResult_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WebRestrictions::GetResult() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WebRestrictions_GetResult_ProxyToResponder(
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
            ClientResultPtr in_reply);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WebRestrictions_GetResult_ProxyToResponder);
    };

    void WebRestrictions_GetResult_ProxyToResponder::Run(
        ClientResultPtr in_reply)
    {
        size_t size = sizeof(::web_restrictions::mojom::internal::WebRestrictions_GetResult_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::web_restrictions::mojom::ClientResultDataView>(
            in_reply, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWebRestrictions_GetResult_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::web_restrictions::mojom::internal::WebRestrictions_GetResult_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->reply)::BaseType* reply_ptr;
        mojo::internal::Serialize<::web_restrictions::mojom::ClientResultDataView>(
            in_reply, builder.buffer(), &reply_ptr, &serialization_context_);
        params->reply.Set(reply_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->reply.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null reply in WebRestrictions.GetResult response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class WebRestrictions_RequestPermission_ProxyToResponder {
    public:
        static WebRestrictions::RequestPermissionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WebRestrictions_RequestPermission_ProxyToResponder> proxy(
                new WebRestrictions_RequestPermission_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WebRestrictions_RequestPermission_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WebRestrictions_RequestPermission_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WebRestrictions::RequestPermission() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WebRestrictions_RequestPermission_ProxyToResponder(
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
            bool in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WebRestrictions_RequestPermission_ProxyToResponder);
    };

    void WebRestrictions_RequestPermission_ProxyToResponder::Run(
        bool in_result)
    {
        size_t size = sizeof(::web_restrictions::mojom::internal::WebRestrictions_RequestPermission_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWebRestrictions_RequestPermission_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::web_restrictions::mojom::internal::WebRestrictions_RequestPermission_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->result = in_result;
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
    bool WebRestrictionsStubDispatch::Accept(
        WebRestrictions* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWebRestrictions_GetResult_Name: {
            break;
        }
        case internal::kWebRestrictions_RequestPermission_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool WebRestrictionsStubDispatch::AcceptWithResponder(
        WebRestrictions* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWebRestrictions_GetResult_Name: {
            internal::WebRestrictions_GetResult_Params_Data* params = reinterpret_cast<internal::WebRestrictions_GetResult_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_url {};
            WebRestrictions_GetResult_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebRestrictions::GetResult deserializer");
                return false;
            }
            WebRestrictions::GetResultCallback callback = WebRestrictions_GetResult_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WebRestrictions::GetResult");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetResult(
                std::move(p_url), std::move(callback));
            return true;
        }
        case internal::kWebRestrictions_RequestPermission_Name: {
            internal::WebRestrictions_RequestPermission_Params_Data* params = reinterpret_cast<internal::WebRestrictions_RequestPermission_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_url {};
            WebRestrictions_RequestPermission_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebRestrictions::RequestPermission deserializer");
                return false;
            }
            WebRestrictions::RequestPermissionCallback callback = WebRestrictions_RequestPermission_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WebRestrictions::RequestPermission");
            mojo::internal::MessageDispatchContext context(message);
            impl->RequestPermission(
                std::move(p_url), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool WebRestrictionsRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WebRestrictions RequestValidator");

        switch (message->header()->name) {
        case internal::kWebRestrictions_GetResult_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WebRestrictions_GetResult_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWebRestrictions_RequestPermission_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WebRestrictions_RequestPermission_Params_Data>(
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

    bool WebRestrictionsResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WebRestrictions ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kWebRestrictions_GetResult_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WebRestrictions_GetResult_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWebRestrictions_RequestPermission_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WebRestrictions_RequestPermission_ResponseParams_Data>(
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
} // namespace web_restrictions

namespace mojo {

// static
bool StructTraits<::web_restrictions::mojom::ClientResult::DataView, ::web_restrictions::mojom::ClientResultPtr>::Read(
    ::web_restrictions::mojom::ClientResult::DataView input,
    ::web_restrictions::mojom::ClientResultPtr* output)
{
    bool success = true;
    ::web_restrictions::mojom::ClientResultPtr result(::web_restrictions::mojom::ClientResult::New());

    if (!input.ReadIntparams(&result->intParams))
        success = false;
    if (!input.ReadStringparams(&result->stringParams))
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