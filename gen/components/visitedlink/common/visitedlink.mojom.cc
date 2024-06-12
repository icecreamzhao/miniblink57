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

#include "components/visitedlink/common/visitedlink.mojom.h"

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
namespace visitedlink {
namespace mojom {
    const char VisitedLinkNotificationSink::Name_[] = "visitedlink::mojom::VisitedLinkNotificationSink";

    VisitedLinkNotificationSinkProxy::VisitedLinkNotificationSinkProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VisitedLinkNotificationSinkProxy::UpdateVisitedLinks(
        mojo::ScopedSharedBufferHandle in_table_handle)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::visitedlink::mojom::internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVisitedLinkNotificationSink_UpdateVisitedLinks_Name, size);

        auto params = ::visitedlink::mojom::internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_table_handle, &params->table_handle, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->table_handle),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid table_handle in VisitedLinkNotificationSink.UpdateVisitedLinks request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VisitedLinkNotificationSinkProxy::AddVisitedLinks(
        const std::vector<uint64_t>& in_link_hashes)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::visitedlink::mojom::internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint64_t>>(
            in_link_hashes, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVisitedLinkNotificationSink_AddVisitedLinks_Name, size);

        auto params = ::visitedlink::mojom::internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->link_hashes)::BaseType* link_hashes_ptr;
        const mojo::internal::ContainerValidateParams link_hashes_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint64_t>>(
            in_link_hashes, builder.buffer(), &link_hashes_ptr, &link_hashes_validate_params,
            &serialization_context);
        params->link_hashes.Set(link_hashes_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->link_hashes.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null link_hashes in VisitedLinkNotificationSink.AddVisitedLinks request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VisitedLinkNotificationSinkProxy::ResetVisitedLinks(
        bool in_invalidate_cached_hashes)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::visitedlink::mojom::internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVisitedLinkNotificationSink_ResetVisitedLinks_Name, size);

        auto params = ::visitedlink::mojom::internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->invalidate_cached_hashes = in_invalidate_cached_hashes;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool VisitedLinkNotificationSinkStubDispatch::Accept(
        VisitedLinkNotificationSink* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVisitedLinkNotificationSink_UpdateVisitedLinks_Name: {
            internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data* params = reinterpret_cast<internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedSharedBufferHandle p_table_handle {};
            VisitedLinkNotificationSink_UpdateVisitedLinks_ParamsDataView input_data_view(params,
                context);

            p_table_handle = input_data_view.TakeTableHandle();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VisitedLinkNotificationSink::UpdateVisitedLinks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VisitedLinkNotificationSink::UpdateVisitedLinks");
            mojo::internal::MessageDispatchContext context(message);
            impl->UpdateVisitedLinks(
                std::move(p_table_handle));
            return true;
        }
        case internal::kVisitedLinkNotificationSink_AddVisitedLinks_Name: {
            internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data* params = reinterpret_cast<internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint64_t> p_link_hashes {};
            VisitedLinkNotificationSink_AddVisitedLinks_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadLinkHashes(&p_link_hashes))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VisitedLinkNotificationSink::AddVisitedLinks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VisitedLinkNotificationSink::AddVisitedLinks");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddVisitedLinks(
                std::move(p_link_hashes));
            return true;
        }
        case internal::kVisitedLinkNotificationSink_ResetVisitedLinks_Name: {
            internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data* params = reinterpret_cast<internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_invalidate_cached_hashes {};
            VisitedLinkNotificationSink_ResetVisitedLinks_ParamsDataView input_data_view(params,
                context);

            p_invalidate_cached_hashes = input_data_view.invalidate_cached_hashes();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VisitedLinkNotificationSink::ResetVisitedLinks deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VisitedLinkNotificationSink::ResetVisitedLinks");
            mojo::internal::MessageDispatchContext context(message);
            impl->ResetVisitedLinks(
                std::move(p_invalidate_cached_hashes));
            return true;
        }
        }
        return false;
    }

    // static
    bool VisitedLinkNotificationSinkStubDispatch::AcceptWithResponder(
        VisitedLinkNotificationSink* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVisitedLinkNotificationSink_UpdateVisitedLinks_Name: {
            break;
        }
        case internal::kVisitedLinkNotificationSink_AddVisitedLinks_Name: {
            break;
        }
        case internal::kVisitedLinkNotificationSink_ResetVisitedLinks_Name: {
            break;
        }
        }
        return false;
    }

    bool VisitedLinkNotificationSinkRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VisitedLinkNotificationSink RequestValidator");

        switch (message->header()->name) {
        case internal::kVisitedLinkNotificationSink_UpdateVisitedLinks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVisitedLinkNotificationSink_AddVisitedLinks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVisitedLinkNotificationSink_ResetVisitedLinks_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data>(
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
} // namespace visitedlink

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif