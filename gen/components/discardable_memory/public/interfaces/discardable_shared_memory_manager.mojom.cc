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

#include "components/discardable_memory/public/interfaces/discardable_shared_memory_manager.mojom.h"

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
namespace discardable_memory {
namespace mojom {
    const char DiscardableSharedMemoryManager::Name_[] = "discardable_memory::mojom::DiscardableSharedMemoryManager";

    class DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ForwardToCallback(
            const DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemoryCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemoryCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ForwardToCallback);
    };
    bool DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data* params = reinterpret_cast<internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        mojo::ScopedSharedBufferHandle p_memory {};
        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_memory = input_data_view.TakeMemory();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemory response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_memory));
        }
        return true;
    }

    DiscardableSharedMemoryManagerProxy::DiscardableSharedMemoryManagerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DiscardableSharedMemoryManagerProxy::AllocateLockedDiscardableSharedMemory(
        uint32_t in_size, int32_t in_id, const AllocateLockedDiscardableSharedMemoryCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::discardable_memory::mojom::internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name, size);

        auto params = ::discardable_memory::mojom::internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->size = in_size;
        params->id = in_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DiscardableSharedMemoryManagerProxy::DeletedDiscardableSharedMemory(
        int32_t in_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::discardable_memory::mojom::internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name, size);

        auto params = ::discardable_memory::mojom::internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->id = in_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder {
    public:
        static DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemoryCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder> proxy(
                new DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemory() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder(
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
            mojo::ScopedSharedBufferHandle in_memory);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder);
    };

    void DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder::Run(
        mojo::ScopedSharedBufferHandle in_memory)
    {
        size_t size = sizeof(::discardable_memory::mojom::internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::discardable_memory::mojom::internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_memory, &params->memory, &serialization_context_);
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
    bool DiscardableSharedMemoryManagerStubDispatch::Accept(
        DiscardableSharedMemoryManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name: {
            break;
        }
        case internal::kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name: {
            internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data* params = reinterpret_cast<internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_id {};
            DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_ParamsDataView input_data_view(params,
                context);

            p_id = input_data_view.id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DiscardableSharedMemoryManager::DeletedDiscardableSharedMemory deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DiscardableSharedMemoryManager::DeletedDiscardableSharedMemory");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeletedDiscardableSharedMemory(
                std::move(p_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool DiscardableSharedMemoryManagerStubDispatch::AcceptWithResponder(
        DiscardableSharedMemoryManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name: {
            internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data* params = reinterpret_cast<internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_size {};
            int32_t p_id {};
            DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ParamsDataView input_data_view(params,
                context);

            p_size = input_data_view.size();
            p_id = input_data_view.id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemory deserializer");
                return false;
            }
            DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemoryCallback callback = DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DiscardableSharedMemoryManager::AllocateLockedDiscardableSharedMemory");
            mojo::internal::MessageDispatchContext context(message);
            impl->AllocateLockedDiscardableSharedMemory(
                std::move(p_size),
                std::move(p_id), std::move(callback));
            return true;
        }
        case internal::kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name: {
            break;
        }
        }
        return false;
    }

    bool DiscardableSharedMemoryManagerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DiscardableSharedMemoryManager RequestValidator");

        switch (message->header()->name) {
        case internal::kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data>(
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

    bool DiscardableSharedMemoryManagerResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DiscardableSharedMemoryManager ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data>(
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
} // namespace discardable_memory

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif