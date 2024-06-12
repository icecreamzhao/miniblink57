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

#include "media/mojo/interfaces/provision_fetcher.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/mojo/interfaces/pipeline_statistics_struct_traits.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace media {
namespace mojom {
    const char ProvisionFetcher::Name_[] = "media::mojom::ProvisionFetcher";

    class ProvisionFetcher_Retrieve_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ProvisionFetcher_Retrieve_ForwardToCallback(
            const ProvisionFetcher::RetrieveCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ProvisionFetcher::RetrieveCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ProvisionFetcher_Retrieve_ForwardToCallback);
    };
    bool ProvisionFetcher_Retrieve_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ProvisionFetcher_Retrieve_ResponseParams_Data* params = reinterpret_cast<internal::ProvisionFetcher_Retrieve_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_result {};
        std::string p_response {};
        ProvisionFetcher_Retrieve_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_result = input_data_view.result();
        if (!input_data_view.ReadResponse(&p_response))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ProvisionFetcher::Retrieve response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result),
                std::move(p_response));
        }
        return true;
    }

    ProvisionFetcherProxy::ProvisionFetcherProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ProvisionFetcherProxy::Retrieve(
        const std::string& in_default_url, const std::string& in_request_data, const RetrieveCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ProvisionFetcher_Retrieve_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_default_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_request_data, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kProvisionFetcher_Retrieve_Name, size);

        auto params = ::media::mojom::internal::ProvisionFetcher_Retrieve_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->default_url)::BaseType* default_url_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_default_url, builder.buffer(), &default_url_ptr, &serialization_context);
        params->default_url.Set(default_url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->default_url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null default_url in ProvisionFetcher.Retrieve request");
        typename decltype(params->request_data)::BaseType* request_data_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_request_data, builder.buffer(), &request_data_ptr, &serialization_context);
        params->request_data.Set(request_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->request_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null request_data in ProvisionFetcher.Retrieve request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ProvisionFetcher_Retrieve_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class ProvisionFetcher_Retrieve_ProxyToResponder {
    public:
        static ProvisionFetcher::RetrieveCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ProvisionFetcher_Retrieve_ProxyToResponder> proxy(
                new ProvisionFetcher_Retrieve_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ProvisionFetcher_Retrieve_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ProvisionFetcher_Retrieve_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ProvisionFetcher::Retrieve() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ProvisionFetcher_Retrieve_ProxyToResponder(
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
            bool in_result, const std::string& in_response);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ProvisionFetcher_Retrieve_ProxyToResponder);
    };

    void ProvisionFetcher_Retrieve_ProxyToResponder::Run(
        bool in_result, const std::string& in_response)
    {
        size_t size = sizeof(::media::mojom::internal::ProvisionFetcher_Retrieve_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_response, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kProvisionFetcher_Retrieve_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ProvisionFetcher_Retrieve_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->result = in_result;
        typename decltype(params->response)::BaseType* response_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_response, builder.buffer(), &response_ptr, &serialization_context_);
        params->response.Set(response_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->response.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null response in ProvisionFetcher.Retrieve response");
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
    bool ProvisionFetcherStubDispatch::Accept(
        ProvisionFetcher* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kProvisionFetcher_Retrieve_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ProvisionFetcherStubDispatch::AcceptWithResponder(
        ProvisionFetcher* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kProvisionFetcher_Retrieve_Name: {
            internal::ProvisionFetcher_Retrieve_Params_Data* params = reinterpret_cast<internal::ProvisionFetcher_Retrieve_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_default_url {};
            std::string p_request_data {};
            ProvisionFetcher_Retrieve_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDefaultUrl(&p_default_url))
                success = false;
            if (!input_data_view.ReadRequestData(&p_request_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ProvisionFetcher::Retrieve deserializer");
                return false;
            }
            ProvisionFetcher::RetrieveCallback callback = ProvisionFetcher_Retrieve_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ProvisionFetcher::Retrieve");
            mojo::internal::MessageDispatchContext context(message);
            impl->Retrieve(
                std::move(p_default_url),
                std::move(p_request_data), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ProvisionFetcherRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ProvisionFetcher RequestValidator");

        switch (message->header()->name) {
        case internal::kProvisionFetcher_Retrieve_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ProvisionFetcher_Retrieve_Params_Data>(
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

    bool ProvisionFetcherResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ProvisionFetcher ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kProvisionFetcher_Retrieve_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ProvisionFetcher_Retrieve_ResponseParams_Data>(
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
} // namespace media

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif