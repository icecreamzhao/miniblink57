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

#include "device/vibration/vibration_manager.mojom.h"

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
namespace device {
const char VibrationManager::Name_[] = "device::VibrationManager";

class VibrationManager_Vibrate_ForwardToCallback
    : public mojo::MessageReceiver {
public:
    VibrationManager_Vibrate_ForwardToCallback(
        const VibrationManager::VibrateCallback& callback,
        scoped_refptr<mojo::AssociatedGroupController> group_controller)
        : callback_(std::move(callback))
        , serialization_context_(std::move(group_controller))
    {
    }
    bool Accept(mojo::Message* message) override;

private:
    VibrationManager::VibrateCallback callback_;
    mojo::internal::SerializationContext serialization_context_;
    DISALLOW_COPY_AND_ASSIGN(VibrationManager_Vibrate_ForwardToCallback);
};
bool VibrationManager_Vibrate_ForwardToCallback::Accept(
    mojo::Message* message)
{
    internal::VibrationManager_Vibrate_ResponseParams_Data* params = reinterpret_cast<internal::VibrationManager_Vibrate_ResponseParams_Data*>(
        message->mutable_payload());

    (&serialization_context_)->handles.Swap((message)->mutable_handles());
    bool success = true;
    VibrationManager_Vibrate_ResponseParamsDataView input_data_view(params,
        &serialization_context_);

    if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "VibrationManager::Vibrate response deserializer");
        return false;
    }
    if (!callback_.is_null()) {
        mojo::internal::MessageDispatchContext context(message);
        std::move(callback_).Run();
    }
    return true;
}

class VibrationManager_Cancel_ForwardToCallback
    : public mojo::MessageReceiver {
public:
    VibrationManager_Cancel_ForwardToCallback(
        const VibrationManager::CancelCallback& callback,
        scoped_refptr<mojo::AssociatedGroupController> group_controller)
        : callback_(std::move(callback))
        , serialization_context_(std::move(group_controller))
    {
    }
    bool Accept(mojo::Message* message) override;

private:
    VibrationManager::CancelCallback callback_;
    mojo::internal::SerializationContext serialization_context_;
    DISALLOW_COPY_AND_ASSIGN(VibrationManager_Cancel_ForwardToCallback);
};
bool VibrationManager_Cancel_ForwardToCallback::Accept(
    mojo::Message* message)
{
    internal::VibrationManager_Cancel_ResponseParams_Data* params = reinterpret_cast<internal::VibrationManager_Cancel_ResponseParams_Data*>(
        message->mutable_payload());

    (&serialization_context_)->handles.Swap((message)->mutable_handles());
    bool success = true;
    VibrationManager_Cancel_ResponseParamsDataView input_data_view(params,
        &serialization_context_);

    if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "VibrationManager::Cancel response deserializer");
        return false;
    }
    if (!callback_.is_null()) {
        mojo::internal::MessageDispatchContext context(message);
        std::move(callback_).Run();
    }
    return true;
}

VibrationManagerProxy::VibrationManagerProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver)
{
}

void VibrationManagerProxy::Vibrate(
    int64_t in_milliseconds, const VibrateCallback& callback)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::device::internal::VibrationManager_Vibrate_Params_Data);
    mojo::internal::RequestMessageBuilder builder(internal::kVibrationManager_Vibrate_Name, size);

    auto params = ::device::internal::VibrationManager_Vibrate_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    params->milliseconds = in_milliseconds;
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    mojo::MessageReceiver* responder = new VibrationManager_Vibrate_ForwardToCallback(
        std::move(callback), group_controller_);
    if (!receiver_->AcceptWithResponder(builder.message(), responder))
        delete responder;
}

void VibrationManagerProxy::Cancel(
    const CancelCallback& callback)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::device::internal::VibrationManager_Cancel_Params_Data);
    mojo::internal::RequestMessageBuilder builder(internal::kVibrationManager_Cancel_Name, size);

    auto params = ::device::internal::VibrationManager_Cancel_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    mojo::MessageReceiver* responder = new VibrationManager_Cancel_ForwardToCallback(
        std::move(callback), group_controller_);
    if (!receiver_->AcceptWithResponder(builder.message(), responder))
        delete responder;
}
class VibrationManager_Vibrate_ProxyToResponder {
public:
    static VibrationManager::VibrateCallback CreateCallback(
        uint64_t request_id,
        bool is_sync,
        mojo::MessageReceiverWithStatus* responder,
        scoped_refptr<mojo::AssociatedGroupController>
            group_controller)
    {
        std::unique_ptr<VibrationManager_Vibrate_ProxyToResponder> proxy(
            new VibrationManager_Vibrate_ProxyToResponder(
                request_id, is_sync, responder, group_controller));
        return base::Bind(&VibrationManager_Vibrate_ProxyToResponder::Run,
            base::Passed(&proxy));
    }

    ~VibrationManager_Vibrate_ProxyToResponder()
    {
#if DCHECK_IS_ON()
        if (responder_) {
            // Is the Service destroying the callback without running it
            // and without first closing the pipe?
            responder_->DCheckInvalid("The callback passed to "
                                      "VibrationManager::Vibrate() was never run.");
        }
#endif
        // If the Callback was dropped then deleting the responder will close
        // the pipe so the calling application knows to stop waiting for a reply.
        delete responder_;
    }

private:
    VibrationManager_Vibrate_ProxyToResponder(
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

    void Run();

    uint64_t request_id_;
    bool is_sync_;
    mojo::MessageReceiverWithStatus* responder_;
    // TODO(yzshen): maybe I should use a ref to the original one?
    mojo::internal::SerializationContext serialization_context_;

    DISALLOW_COPY_AND_ASSIGN(VibrationManager_Vibrate_ProxyToResponder);
};

void VibrationManager_Vibrate_ProxyToResponder::Run()
{
    size_t size = sizeof(::device::internal::VibrationManager_Vibrate_ResponseParams_Data);
    mojo::internal::ResponseMessageBuilder builder(
        internal::kVibrationManager_Vibrate_Name, size, request_id_,
        is_sync_ ? mojo::Message::kFlagIsSync : 0);
    auto params = ::device::internal::VibrationManager_Vibrate_ResponseParams_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
    bool ok = responder_->Accept(builder.message());
    ALLOW_UNUSED_LOCAL(ok);
    // TODO(darin): !ok returned here indicates a malformed message, and that may
    // be good reason to close the connection. However, we don't have a way to do
    // that from here. We should add a way.
    delete responder_;
    responder_ = nullptr;
}
class VibrationManager_Cancel_ProxyToResponder {
public:
    static VibrationManager::CancelCallback CreateCallback(
        uint64_t request_id,
        bool is_sync,
        mojo::MessageReceiverWithStatus* responder,
        scoped_refptr<mojo::AssociatedGroupController>
            group_controller)
    {
        std::unique_ptr<VibrationManager_Cancel_ProxyToResponder> proxy(
            new VibrationManager_Cancel_ProxyToResponder(
                request_id, is_sync, responder, group_controller));
        return base::Bind(&VibrationManager_Cancel_ProxyToResponder::Run,
            base::Passed(&proxy));
    }

    ~VibrationManager_Cancel_ProxyToResponder()
    {
#if DCHECK_IS_ON()
        if (responder_) {
            // Is the Service destroying the callback without running it
            // and without first closing the pipe?
            responder_->DCheckInvalid("The callback passed to "
                                      "VibrationManager::Cancel() was never run.");
        }
#endif
        // If the Callback was dropped then deleting the responder will close
        // the pipe so the calling application knows to stop waiting for a reply.
        delete responder_;
    }

private:
    VibrationManager_Cancel_ProxyToResponder(
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

    void Run();

    uint64_t request_id_;
    bool is_sync_;
    mojo::MessageReceiverWithStatus* responder_;
    // TODO(yzshen): maybe I should use a ref to the original one?
    mojo::internal::SerializationContext serialization_context_;

    DISALLOW_COPY_AND_ASSIGN(VibrationManager_Cancel_ProxyToResponder);
};

void VibrationManager_Cancel_ProxyToResponder::Run()
{
    size_t size = sizeof(::device::internal::VibrationManager_Cancel_ResponseParams_Data);
    mojo::internal::ResponseMessageBuilder builder(
        internal::kVibrationManager_Cancel_Name, size, request_id_,
        is_sync_ ? mojo::Message::kFlagIsSync : 0);
    auto params = ::device::internal::VibrationManager_Cancel_ResponseParams_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
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
bool VibrationManagerStubDispatch::Accept(
    VibrationManager* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message)
{
    switch (message->header()->name) {
    case internal::kVibrationManager_Vibrate_Name: {
        break;
    }
    case internal::kVibrationManager_Cancel_Name: {
        break;
    }
    }
    return false;
}

// static
bool VibrationManagerStubDispatch::AcceptWithResponder(
    VibrationManager* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder)
{
    switch (message->header()->name) {
    case internal::kVibrationManager_Vibrate_Name: {
        internal::VibrationManager_Vibrate_Params_Data* params = reinterpret_cast<internal::VibrationManager_Vibrate_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int64_t p_milliseconds {};
        VibrationManager_Vibrate_ParamsDataView input_data_view(params,
            context);

        p_milliseconds = input_data_view.milliseconds();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VibrationManager::Vibrate deserializer");
            return false;
        }
        VibrationManager::VibrateCallback callback = VibrationManager_Vibrate_ProxyToResponder::CreateCallback(
            message->request_id(),
            message->has_flag(mojo::Message::kFlagIsSync), responder,
            context->group_controller);
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "VibrationManager::Vibrate");
        mojo::internal::MessageDispatchContext context(message);
        impl->Vibrate(
            std::move(p_milliseconds), std::move(callback));
        return true;
    }
    case internal::kVibrationManager_Cancel_Name: {
        internal::VibrationManager_Cancel_Params_Data* params = reinterpret_cast<internal::VibrationManager_Cancel_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        VibrationManager_Cancel_ParamsDataView input_data_view(params,
            context);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VibrationManager::Cancel deserializer");
            return false;
        }
        VibrationManager::CancelCallback callback = VibrationManager_Cancel_ProxyToResponder::CreateCallback(
            message->request_id(),
            message->has_flag(mojo::Message::kFlagIsSync), responder,
            context->group_controller);
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "VibrationManager::Cancel");
        mojo::internal::MessageDispatchContext context(message);
        impl->Cancel(std::move(callback));
        return true;
    }
    }
    return false;
}

bool VibrationManagerRequestValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "VibrationManager RequestValidator");

    switch (message->header()->name) {
    case internal::kVibrationManager_Vibrate_Name: {
        if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::VibrationManager_Vibrate_Params_Data>(
                message, &validation_context)) {
            return false;
        }
        return true;
    }
    case internal::kVibrationManager_Cancel_Name: {
        if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::VibrationManager_Cancel_Params_Data>(
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

bool VibrationManagerResponseValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "VibrationManager ResponseValidator");

    if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
        return false;
    switch (message->header()->name) {
    case internal::kVibrationManager_Vibrate_Name: {
        if (!mojo::internal::ValidateMessagePayload<
                internal::VibrationManager_Vibrate_ResponseParams_Data>(
                message, &validation_context)) {
            return false;
        }
        return true;
    }
    case internal::kVibrationManager_Cancel_Name: {
        if (!mojo::internal::ValidateMessagePayload<
                internal::VibrationManager_Cancel_ResponseParams_Data>(
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
} // namespace device

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif