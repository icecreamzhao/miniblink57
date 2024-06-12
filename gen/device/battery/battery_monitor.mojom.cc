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

#include "device/battery/battery_monitor.mojom.h"

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
const char BatteryMonitor::Name_[] = "device::BatteryMonitor";

class BatteryMonitor_QueryNextStatus_ForwardToCallback
    : public mojo::MessageReceiver {
public:
    BatteryMonitor_QueryNextStatus_ForwardToCallback(
        const BatteryMonitor::QueryNextStatusCallback& callback,
        scoped_refptr<mojo::AssociatedGroupController> group_controller)
        : callback_(std::move(callback))
        , serialization_context_(std::move(group_controller))
    {
    }
    bool Accept(mojo::Message* message) override;

private:
    BatteryMonitor::QueryNextStatusCallback callback_;
    mojo::internal::SerializationContext serialization_context_;
    DISALLOW_COPY_AND_ASSIGN(BatteryMonitor_QueryNextStatus_ForwardToCallback);
};
bool BatteryMonitor_QueryNextStatus_ForwardToCallback::Accept(
    mojo::Message* message)
{
    internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data* params = reinterpret_cast<internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data*>(
        message->mutable_payload());

    (&serialization_context_)->handles.Swap((message)->mutable_handles());
    bool success = true;
    ::device::BatteryStatusPtr p_status {};
    BatteryMonitor_QueryNextStatus_ResponseParamsDataView input_data_view(params,
        &serialization_context_);

    if (!input_data_view.ReadStatus(&p_status))
        success = false;
    if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "BatteryMonitor::QueryNextStatus response deserializer");
        return false;
    }
    if (!callback_.is_null()) {
        mojo::internal::MessageDispatchContext context(message);
        std::move(callback_).Run(
            std::move(p_status));
    }
    return true;
}

BatteryMonitorProxy::BatteryMonitorProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver)
{
}

void BatteryMonitorProxy::QueryNextStatus(
    const QueryNextStatusCallback& callback)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::device::internal::BatteryMonitor_QueryNextStatus_Params_Data);
    mojo::internal::RequestMessageBuilder builder(internal::kBatteryMonitor_QueryNextStatus_Name, size);

    auto params = ::device::internal::BatteryMonitor_QueryNextStatus_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    mojo::MessageReceiver* responder = new BatteryMonitor_QueryNextStatus_ForwardToCallback(
        std::move(callback), group_controller_);
    if (!receiver_->AcceptWithResponder(builder.message(), responder))
        delete responder;
}
class BatteryMonitor_QueryNextStatus_ProxyToResponder {
public:
    static BatteryMonitor::QueryNextStatusCallback CreateCallback(
        uint64_t request_id,
        bool is_sync,
        mojo::MessageReceiverWithStatus* responder,
        scoped_refptr<mojo::AssociatedGroupController>
            group_controller)
    {
        std::unique_ptr<BatteryMonitor_QueryNextStatus_ProxyToResponder> proxy(
            new BatteryMonitor_QueryNextStatus_ProxyToResponder(
                request_id, is_sync, responder, group_controller));
        return base::Bind(&BatteryMonitor_QueryNextStatus_ProxyToResponder::Run,
            base::Passed(&proxy));
    }

    ~BatteryMonitor_QueryNextStatus_ProxyToResponder()
    {
#if DCHECK_IS_ON()
        if (responder_) {
            // Is the Service destroying the callback without running it
            // and without first closing the pipe?
            responder_->DCheckInvalid("The callback passed to "
                                      "BatteryMonitor::QueryNextStatus() was never run.");
        }
#endif
        // If the Callback was dropped then deleting the responder will close
        // the pipe so the calling application knows to stop waiting for a reply.
        delete responder_;
    }

private:
    BatteryMonitor_QueryNextStatus_ProxyToResponder(
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
        ::device::BatteryStatusPtr in_status);

    uint64_t request_id_;
    bool is_sync_;
    mojo::MessageReceiverWithStatus* responder_;
    // TODO(yzshen): maybe I should use a ref to the original one?
    mojo::internal::SerializationContext serialization_context_;

    DISALLOW_COPY_AND_ASSIGN(BatteryMonitor_QueryNextStatus_ProxyToResponder);
};

void BatteryMonitor_QueryNextStatus_ProxyToResponder::Run(
    ::device::BatteryStatusPtr in_status)
{
    size_t size = sizeof(::device::internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data);
    size += mojo::internal::PrepareToSerialize<::device::BatteryStatusDataView>(
        in_status, &serialization_context_);
    mojo::internal::ResponseMessageBuilder builder(
        internal::kBatteryMonitor_QueryNextStatus_Name, size, request_id_,
        is_sync_ ? mojo::Message::kFlagIsSync : 0);
    auto params = ::device::internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    typename decltype(params->status)::BaseType* status_ptr;
    mojo::internal::Serialize<::device::BatteryStatusDataView>(
        in_status, builder.buffer(), &status_ptr, &serialization_context_);
    params->status.Set(status_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        params->status.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null status in BatteryMonitor.QueryNextStatus response");
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
bool BatteryMonitorStubDispatch::Accept(
    BatteryMonitor* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message)
{
    switch (message->header()->name) {
    case internal::kBatteryMonitor_QueryNextStatus_Name: {
        break;
    }
    }
    return false;
}

// static
bool BatteryMonitorStubDispatch::AcceptWithResponder(
    BatteryMonitor* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder)
{
    switch (message->header()->name) {
    case internal::kBatteryMonitor_QueryNextStatus_Name: {
        internal::BatteryMonitor_QueryNextStatus_Params_Data* params = reinterpret_cast<internal::BatteryMonitor_QueryNextStatus_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        BatteryMonitor_QueryNextStatus_ParamsDataView input_data_view(params,
            context);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "BatteryMonitor::QueryNextStatus deserializer");
            return false;
        }
        BatteryMonitor::QueryNextStatusCallback callback = BatteryMonitor_QueryNextStatus_ProxyToResponder::CreateCallback(
            message->request_id(),
            message->has_flag(mojo::Message::kFlagIsSync), responder,
            context->group_controller);
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "BatteryMonitor::QueryNextStatus");
        mojo::internal::MessageDispatchContext context(message);
        impl->QueryNextStatus(std::move(callback));
        return true;
    }
    }
    return false;
}

bool BatteryMonitorRequestValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "BatteryMonitor RequestValidator");

    switch (message->header()->name) {
    case internal::kBatteryMonitor_QueryNextStatus_Name: {
        if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::BatteryMonitor_QueryNextStatus_Params_Data>(
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

bool BatteryMonitorResponseValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "BatteryMonitor ResponseValidator");

    if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
        return false;
    switch (message->header()->name) {
    case internal::kBatteryMonitor_QueryNextStatus_Name: {
        if (!mojo::internal::ValidateMessagePayload<
                internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data>(
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