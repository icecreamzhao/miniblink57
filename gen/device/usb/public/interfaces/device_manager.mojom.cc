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

#include "device/usb/public/interfaces/device_manager.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "device/usb/public/interfaces/device_manager_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace usb { // static
    DeviceFilterPtr DeviceFilter::New()
    {
        DeviceFilterPtr rv;
        mojo::internal::StructHelper<DeviceFilter>::Initialize(&rv);
        return rv;
    }

    DeviceFilter::DeviceFilter()
        : has_vendor_id()
        , vendor_id()
        , has_product_id()
        , product_id()
        , has_class_code()
        , class_code()
        , has_subclass_code()
        , subclass_code()
        , has_protocol_code()
        , protocol_code()
        , serial_number()
    {
    }

    DeviceFilter::~DeviceFilter()
    {
    } // static
    EnumerationOptionsPtr EnumerationOptions::New()
    {
        EnumerationOptionsPtr rv;
        mojo::internal::StructHelper<EnumerationOptions>::Initialize(&rv);
        return rv;
    }

    EnumerationOptions::EnumerationOptions()
        : filters()
    {
    }

    EnumerationOptions::~EnumerationOptions()
    {
    }
    const char DeviceManager::Name_[] = "device::usb::DeviceManager";

    class DeviceManager_GetDevices_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        DeviceManager_GetDevices_ForwardToCallback(
            const DeviceManager::GetDevicesCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        DeviceManager::GetDevicesCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(DeviceManager_GetDevices_ForwardToCallback);
    };
    bool DeviceManager_GetDevices_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::DeviceManager_GetDevices_ResponseParams_Data* params = reinterpret_cast<internal::DeviceManager_GetDevices_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<::device::usb::DeviceInfoPtr> p_results {};
        DeviceManager_GetDevices_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResults(&p_results))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "DeviceManager::GetDevices response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_results));
        }
        return true;
    }

    DeviceManagerProxy::DeviceManagerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DeviceManagerProxy::GetDevices(
        EnumerationOptionsPtr in_options, const GetDevicesCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::usb::internal::DeviceManager_GetDevices_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::usb::EnumerationOptionsDataView>(
            in_options, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDeviceManager_GetDevices_Name, size);

        auto params = ::device::usb::internal::DeviceManager_GetDevices_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->options)::BaseType* options_ptr;
        mojo::internal::Serialize<::device::usb::EnumerationOptionsDataView>(
            in_options, builder.buffer(), &options_ptr, &serialization_context);
        params->options.Set(options_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new DeviceManager_GetDevices_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DeviceManagerProxy::GetDevice(
        const std::string& in_guid, ::device::usb::DeviceRequest in_device_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::usb::internal::DeviceManager_GetDevice_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_guid, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDeviceManager_GetDevice_Name, size);

        auto params = ::device::usb::internal::DeviceManager_GetDevice_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->guid)::BaseType* guid_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_guid, builder.buffer(), &guid_ptr, &serialization_context);
        params->guid.Set(guid_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->guid.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null guid in DeviceManager.GetDevice request");
        mojo::internal::Serialize<::device::usb::DeviceRequestDataView>(
            in_device_request, &params->device_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->device_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid device_request in DeviceManager.GetDevice request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DeviceManagerProxy::SetClient(
        DeviceManagerClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::usb::internal::DeviceManager_SetClient_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDeviceManager_SetClient_Name, size);

        auto params = ::device::usb::internal::DeviceManager_SetClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::usb::DeviceManagerClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in DeviceManager.SetClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class DeviceManager_GetDevices_ProxyToResponder {
    public:
        static DeviceManager::GetDevicesCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<DeviceManager_GetDevices_ProxyToResponder> proxy(
                new DeviceManager_GetDevices_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&DeviceManager_GetDevices_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~DeviceManager_GetDevices_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "DeviceManager::GetDevices() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        DeviceManager_GetDevices_ProxyToResponder(
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
            std::vector<::device::usb::DeviceInfoPtr> in_results);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(DeviceManager_GetDevices_ProxyToResponder);
    };

    void DeviceManager_GetDevices_ProxyToResponder::Run(
        std::vector<::device::usb::DeviceInfoPtr> in_results)
    {
        size_t size = sizeof(::device::usb::internal::DeviceManager_GetDevices_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::DeviceInfoDataView>>(
            in_results, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDeviceManager_GetDevices_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::usb::internal::DeviceManager_GetDevices_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->results)::BaseType* results_ptr;
        const mojo::internal::ContainerValidateParams results_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::DeviceInfoDataView>>(
            in_results, builder.buffer(), &results_ptr, &results_validate_params,
            &serialization_context_);
        params->results.Set(results_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->results.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null results in DeviceManager.GetDevices response");
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
    bool DeviceManagerStubDispatch::Accept(
        DeviceManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDeviceManager_GetDevices_Name: {
            break;
        }
        case internal::kDeviceManager_GetDevice_Name: {
            internal::DeviceManager_GetDevice_Params_Data* params = reinterpret_cast<internal::DeviceManager_GetDevice_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_guid {};
            ::device::usb::DeviceRequest p_device_request {};
            DeviceManager_GetDevice_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadGuid(&p_guid))
                success = false;
            p_device_request = input_data_view.TakeDeviceRequest<decltype(p_device_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceManager::GetDevice deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceManager::GetDevice");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetDevice(
                std::move(p_guid),
                std::move(p_device_request));
            return true;
        }
        case internal::kDeviceManager_SetClient_Name: {
            internal::DeviceManager_SetClient_Params_Data* params = reinterpret_cast<internal::DeviceManager_SetClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DeviceManagerClientPtr p_client {};
            DeviceManager_SetClient_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceManager::SetClient deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceManager::SetClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClient(
                std::move(p_client));
            return true;
        }
        }
        return false;
    }

    // static
    bool DeviceManagerStubDispatch::AcceptWithResponder(
        DeviceManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDeviceManager_GetDevices_Name: {
            internal::DeviceManager_GetDevices_Params_Data* params = reinterpret_cast<internal::DeviceManager_GetDevices_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            EnumerationOptionsPtr p_options {};
            DeviceManager_GetDevices_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOptions(&p_options))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceManager::GetDevices deserializer");
                return false;
            }
            DeviceManager::GetDevicesCallback callback = DeviceManager_GetDevices_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceManager::GetDevices");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetDevices(
                std::move(p_options), std::move(callback));
            return true;
        }
        case internal::kDeviceManager_GetDevice_Name: {
            break;
        }
        case internal::kDeviceManager_SetClient_Name: {
            break;
        }
        }
        return false;
    }

    bool DeviceManagerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DeviceManager RequestValidator");

        switch (message->header()->name) {
        case internal::kDeviceManager_GetDevices_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceManager_GetDevices_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceManager_GetDevice_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceManager_GetDevice_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceManager_SetClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceManager_SetClient_Params_Data>(
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

    bool DeviceManagerResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DeviceManager ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kDeviceManager_GetDevices_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceManager_GetDevices_ResponseParams_Data>(
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
    const char DeviceManagerClient::Name_[] = "device::usb::DeviceManagerClient";

    DeviceManagerClientProxy::DeviceManagerClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DeviceManagerClientProxy::OnDeviceAdded(
        ::device::usb::DeviceInfoPtr in_device_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::usb::internal::DeviceManagerClient_OnDeviceAdded_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::usb::DeviceInfoDataView>(
            in_device_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDeviceManagerClient_OnDeviceAdded_Name, size);

        auto params = ::device::usb::internal::DeviceManagerClient_OnDeviceAdded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->device_info)::BaseType* device_info_ptr;
        mojo::internal::Serialize<::device::usb::DeviceInfoDataView>(
            in_device_info, builder.buffer(), &device_info_ptr, &serialization_context);
        params->device_info.Set(device_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->device_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null device_info in DeviceManagerClient.OnDeviceAdded request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DeviceManagerClientProxy::OnDeviceRemoved(
        ::device::usb::DeviceInfoPtr in_device_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::usb::internal::DeviceManagerClient_OnDeviceRemoved_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::usb::DeviceInfoDataView>(
            in_device_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDeviceManagerClient_OnDeviceRemoved_Name, size);

        auto params = ::device::usb::internal::DeviceManagerClient_OnDeviceRemoved_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->device_info)::BaseType* device_info_ptr;
        mojo::internal::Serialize<::device::usb::DeviceInfoDataView>(
            in_device_info, builder.buffer(), &device_info_ptr, &serialization_context);
        params->device_info.Set(device_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->device_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null device_info in DeviceManagerClient.OnDeviceRemoved request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DeviceManagerClientStubDispatch::Accept(
        DeviceManagerClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDeviceManagerClient_OnDeviceAdded_Name: {
            internal::DeviceManagerClient_OnDeviceAdded_Params_Data* params = reinterpret_cast<internal::DeviceManagerClient_OnDeviceAdded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::device::usb::DeviceInfoPtr p_device_info {};
            DeviceManagerClient_OnDeviceAdded_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDeviceInfo(&p_device_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceManagerClient::OnDeviceAdded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceManagerClient::OnDeviceAdded");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDeviceAdded(
                std::move(p_device_info));
            return true;
        }
        case internal::kDeviceManagerClient_OnDeviceRemoved_Name: {
            internal::DeviceManagerClient_OnDeviceRemoved_Params_Data* params = reinterpret_cast<internal::DeviceManagerClient_OnDeviceRemoved_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::device::usb::DeviceInfoPtr p_device_info {};
            DeviceManagerClient_OnDeviceRemoved_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDeviceInfo(&p_device_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceManagerClient::OnDeviceRemoved deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceManagerClient::OnDeviceRemoved");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDeviceRemoved(
                std::move(p_device_info));
            return true;
        }
        }
        return false;
    }

    // static
    bool DeviceManagerClientStubDispatch::AcceptWithResponder(
        DeviceManagerClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDeviceManagerClient_OnDeviceAdded_Name: {
            break;
        }
        case internal::kDeviceManagerClient_OnDeviceRemoved_Name: {
            break;
        }
        }
        return false;
    }

    bool DeviceManagerClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DeviceManagerClient RequestValidator");

        switch (message->header()->name) {
        case internal::kDeviceManagerClient_OnDeviceAdded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceManagerClient_OnDeviceAdded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceManagerClient_OnDeviceRemoved_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceManagerClient_OnDeviceRemoved_Params_Data>(
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

} // namespace usb
} // namespace device

namespace mojo {

// static
bool StructTraits<::device::usb::DeviceFilter::DataView, ::device::usb::DeviceFilterPtr>::Read(
    ::device::usb::DeviceFilter::DataView input,
    ::device::usb::DeviceFilterPtr* output)
{
    bool success = true;
    ::device::usb::DeviceFilterPtr result(::device::usb::DeviceFilter::New());

    result->has_vendor_id = input.has_vendor_id();
    result->vendor_id = input.vendor_id();
    result->has_product_id = input.has_product_id();
    result->product_id = input.product_id();
    result->has_class_code = input.has_class_code();
    result->class_code = input.class_code();
    result->has_subclass_code = input.has_subclass_code();
    result->subclass_code = input.subclass_code();
    result->has_protocol_code = input.has_protocol_code();
    result->protocol_code = input.protocol_code();
    if (!input.ReadSerialNumber(&result->serial_number))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::EnumerationOptions::DataView, ::device::usb::EnumerationOptionsPtr>::Read(
    ::device::usb::EnumerationOptions::DataView input,
    ::device::usb::EnumerationOptionsPtr* output)
{
    bool success = true;
    ::device::usb::EnumerationOptionsPtr result(::device::usb::EnumerationOptions::New());

    if (!input.ReadFilters(&result->filters))
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