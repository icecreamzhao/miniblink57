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

#include "ipc/ipc.mojom.h"

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
namespace IPC {
namespace mojom { // static
    SerializedHandlePtr SerializedHandle::New()
    {
        SerializedHandlePtr rv;
        mojo::internal::StructHelper<SerializedHandle>::Initialize(&rv);
        return rv;
    }

    SerializedHandle::SerializedHandle()
        : the_handle()
        , type()
    {
    }

    SerializedHandle::~SerializedHandle()
    {
    }
    const char GenericInterface::Name_[] = "IPC::mojom::GenericInterface";

    GenericInterfaceProxy::GenericInterfaceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    // static
    bool GenericInterfaceStubDispatch::Accept(
        GenericInterface* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        return false;
    }

    // static
    bool GenericInterfaceStubDispatch::AcceptWithResponder(
        GenericInterface* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        return false;
    }

    bool GenericInterfaceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GenericInterface RequestValidator");

        switch (message->header()->name) {
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char Channel::Name_[] = "IPC::mojom::Channel";

    ChannelProxy::ChannelProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ChannelProxy::SetPeerPid(
        int32_t in_pid)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::IPC::mojom::internal::Channel_SetPeerPid_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kChannel_SetPeerPid_Name, size);

        auto params = ::IPC::mojom::internal::Channel_SetPeerPid_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->pid = in_pid;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ChannelProxy::Receive(
        const std::vector<uint8_t>& in_data, base::Optional<std::vector<SerializedHandlePtr>> in_handles)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::IPC::mojom::internal::Channel_Receive_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_data, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::IPC::mojom::SerializedHandleDataView>>(
            in_handles, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kChannel_Receive_Name, size);

        auto params = ::IPC::mojom::internal::Channel_Receive_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in Channel.Receive request");
        typename decltype(params->handles)::BaseType* handles_ptr;
        const mojo::internal::ContainerValidateParams handles_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::IPC::mojom::SerializedHandleDataView>>(
            in_handles, builder.buffer(), &handles_ptr, &handles_validate_params,
            &serialization_context);
        params->handles.Set(handles_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ChannelProxy::GetAssociatedInterface(
        const std::string& in_name, GenericInterfaceAssociatedRequest in_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::IPC::mojom::internal::Channel_GetAssociatedInterface_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_name, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kChannel_GetAssociatedInterface_Name, size);

        auto params = ::IPC::mojom::internal::Channel_GetAssociatedInterface_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in Channel.GetAssociatedInterface request");
        mojo::internal::Serialize<::IPC::mojom::GenericInterfaceAssociatedRequestDataView>(
            in_request, &params->request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid request in Channel.GetAssociatedInterface request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ChannelStubDispatch::Accept(
        Channel* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kChannel_SetPeerPid_Name: {
            internal::Channel_SetPeerPid_Params_Data* params = reinterpret_cast<internal::Channel_SetPeerPid_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_pid {};
            Channel_SetPeerPid_ParamsDataView input_data_view(params,
                context);

            p_pid = input_data_view.pid();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Channel::SetPeerPid deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Channel::SetPeerPid");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetPeerPid(
                std::move(p_pid));
            return true;
        }
        case internal::kChannel_Receive_Name: {
            internal::Channel_Receive_Params_Data* params = reinterpret_cast<internal::Channel_Receive_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_data {};
            base::Optional<std::vector<SerializedHandlePtr>> p_handles {};
            Channel_Receive_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!input_data_view.ReadHandles(&p_handles))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Channel::Receive deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Channel::Receive");
            mojo::internal::MessageDispatchContext context(message);
            impl->Receive(
                std::move(p_data),
                std::move(p_handles));
            return true;
        }
        case internal::kChannel_GetAssociatedInterface_Name: {
            internal::Channel_GetAssociatedInterface_Params_Data* params = reinterpret_cast<internal::Channel_GetAssociatedInterface_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_name {};
            GenericInterfaceAssociatedRequest p_request {};
            Channel_GetAssociatedInterface_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadName(&p_name))
                success = false;
            p_request = input_data_view.TakeRequest<decltype(p_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Channel::GetAssociatedInterface deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Channel::GetAssociatedInterface");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetAssociatedInterface(
                std::move(p_name),
                std::move(p_request));
            return true;
        }
        }
        return false;
    }

    // static
    bool ChannelStubDispatch::AcceptWithResponder(
        Channel* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kChannel_SetPeerPid_Name: {
            break;
        }
        case internal::kChannel_Receive_Name: {
            break;
        }
        case internal::kChannel_GetAssociatedInterface_Name: {
            break;
        }
        }
        return false;
    }

    bool ChannelRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Channel RequestValidator");

        switch (message->header()->name) {
        case internal::kChannel_SetPeerPid_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Channel_SetPeerPid_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kChannel_Receive_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Channel_Receive_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kChannel_GetAssociatedInterface_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Channel_GetAssociatedInterface_Params_Data>(
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

    const char ChannelBootstrap::Name_[] = "IPC::mojom::ChannelBootstrap";

    ChannelBootstrapProxy::ChannelBootstrapProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    // static
    bool ChannelBootstrapStubDispatch::Accept(
        ChannelBootstrap* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        return false;
    }

    // static
    bool ChannelBootstrapStubDispatch::AcceptWithResponder(
        ChannelBootstrap* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        return false;
    }

    bool ChannelBootstrapRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ChannelBootstrap RequestValidator");

        switch (message->header()->name) {
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
} // namespace IPC

namespace mojo {

// static
bool StructTraits<::IPC::mojom::SerializedHandle::DataView, ::IPC::mojom::SerializedHandlePtr>::Read(
    ::IPC::mojom::SerializedHandle::DataView input,
    ::IPC::mojom::SerializedHandlePtr* output)
{
    bool success = true;
    ::IPC::mojom::SerializedHandlePtr result(::IPC::mojom::SerializedHandle::New());

    result->the_handle = input.TakeTheHandle();
    if (!input.ReadType(&result->type))
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