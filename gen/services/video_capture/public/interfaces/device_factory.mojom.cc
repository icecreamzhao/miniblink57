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

#include "services/video_capture/public/interfaces/device_factory.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/capture/ipc/capture_param_traits.h"
#include "media/capture/ipc/capture_param_traits_macros.h"
#include "media/capture/mojo/video_capture_types_typemap_traits.h"
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
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace video_capture {
namespace mojom {
    const char DeviceFactory::Name_[] = "video_capture::mojom::DeviceFactory";

    class DeviceFactory_EnumerateDeviceDescriptors_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        DeviceFactory_EnumerateDeviceDescriptors_ForwardToCallback(
            const DeviceFactory::EnumerateDeviceDescriptorsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        DeviceFactory::EnumerateDeviceDescriptorsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(DeviceFactory_EnumerateDeviceDescriptors_ForwardToCallback);
    };
    bool DeviceFactory_EnumerateDeviceDescriptors_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data* params = reinterpret_cast<internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<media::VideoCaptureDeviceDescriptor> p_descriptors {};
        DeviceFactory_EnumerateDeviceDescriptors_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadDescriptors(&p_descriptors))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "DeviceFactory::EnumerateDeviceDescriptors response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_descriptors));
        }
        return true;
    }

    class DeviceFactory_GetSupportedFormats_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        DeviceFactory_GetSupportedFormats_ForwardToCallback(
            const DeviceFactory::GetSupportedFormatsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        DeviceFactory::GetSupportedFormatsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(DeviceFactory_GetSupportedFormats_ForwardToCallback);
    };
    bool DeviceFactory_GetSupportedFormats_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data* params = reinterpret_cast<internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<video_capture::I420CaptureFormat> p_supported_formats {};
        DeviceFactory_GetSupportedFormats_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadSupportedFormats(&p_supported_formats))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "DeviceFactory::GetSupportedFormats response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_supported_formats));
        }
        return true;
    }

    class DeviceFactory_CreateDevice_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        DeviceFactory_CreateDevice_ForwardToCallback(
            const DeviceFactory::CreateDeviceCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        DeviceFactory::CreateDeviceCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(DeviceFactory_CreateDevice_ForwardToCallback);
    };
    bool DeviceFactory_CreateDevice_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::DeviceFactory_CreateDevice_ResponseParams_Data* params = reinterpret_cast<internal::DeviceFactory_CreateDevice_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DeviceAccessResultCode p_result_code {};
        DeviceFactory_CreateDevice_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResultCode(&p_result_code))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "DeviceFactory::CreateDevice response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result_code));
        }
        return true;
    }

    DeviceFactoryProxy::DeviceFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DeviceFactoryProxy::EnumerateDeviceDescriptors(
        const EnumerateDeviceDescriptorsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kDeviceFactory_EnumerateDeviceDescriptors_Name, size);

        auto params = ::video_capture::mojom::internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new DeviceFactory_EnumerateDeviceDescriptors_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DeviceFactoryProxy::GetSupportedFormats(
        const std::string& in_device_id, const GetSupportedFormatsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::DeviceFactory_GetSupportedFormats_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_device_id, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDeviceFactory_GetSupportedFormats_Name, size);

        auto params = ::video_capture::mojom::internal::DeviceFactory_GetSupportedFormats_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->device_id)::BaseType* device_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_device_id, builder.buffer(), &device_id_ptr, &serialization_context);
        params->device_id.Set(device_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->device_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null device_id in DeviceFactory.GetSupportedFormats request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new DeviceFactory_GetSupportedFormats_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DeviceFactoryProxy::CreateDevice(
        const std::string& in_device_id, ::video_capture::mojom::DeviceRequest in_device_request, const CreateDeviceCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::DeviceFactory_CreateDevice_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_device_id, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDeviceFactory_CreateDevice_Name, size);

        auto params = ::video_capture::mojom::internal::DeviceFactory_CreateDevice_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->device_id)::BaseType* device_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_device_id, builder.buffer(), &device_id_ptr, &serialization_context);
        params->device_id.Set(device_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->device_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null device_id in DeviceFactory.CreateDevice request");
        mojo::internal::Serialize<::video_capture::mojom::DeviceRequestDataView>(
            in_device_request, &params->device_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->device_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid device_request in DeviceFactory.CreateDevice request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new DeviceFactory_CreateDevice_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder {
    public:
        static DeviceFactory::EnumerateDeviceDescriptorsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder> proxy(
                new DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "DeviceFactory::EnumerateDeviceDescriptors() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder(
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
            const std::vector<media::VideoCaptureDeviceDescriptor>& in_descriptors);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder);
    };

    void DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder::Run(
        const std::vector<media::VideoCaptureDeviceDescriptor>& in_descriptors)
    {
        size_t size = sizeof(::video_capture::mojom::internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::video_capture::mojom::DeviceDescriptorDataView>>(
            in_descriptors, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDeviceFactory_EnumerateDeviceDescriptors_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::video_capture::mojom::internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->descriptors)::BaseType* descriptors_ptr;
        const mojo::internal::ContainerValidateParams descriptors_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::video_capture::mojom::DeviceDescriptorDataView>>(
            in_descriptors, builder.buffer(), &descriptors_ptr, &descriptors_validate_params,
            &serialization_context_);
        params->descriptors.Set(descriptors_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->descriptors.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null descriptors in DeviceFactory.EnumerateDeviceDescriptors response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class DeviceFactory_GetSupportedFormats_ProxyToResponder {
    public:
        static DeviceFactory::GetSupportedFormatsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<DeviceFactory_GetSupportedFormats_ProxyToResponder> proxy(
                new DeviceFactory_GetSupportedFormats_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&DeviceFactory_GetSupportedFormats_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~DeviceFactory_GetSupportedFormats_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "DeviceFactory::GetSupportedFormats() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        DeviceFactory_GetSupportedFormats_ProxyToResponder(
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
            const std::vector<video_capture::I420CaptureFormat>& in_supported_formats);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(DeviceFactory_GetSupportedFormats_ProxyToResponder);
    };

    void DeviceFactory_GetSupportedFormats_ProxyToResponder::Run(
        const std::vector<video_capture::I420CaptureFormat>& in_supported_formats)
    {
        size_t size = sizeof(::video_capture::mojom::internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::video_capture::mojom::I420CaptureFormatDataView>>(
            in_supported_formats, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDeviceFactory_GetSupportedFormats_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::video_capture::mojom::internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->supported_formats)::BaseType* supported_formats_ptr;
        const mojo::internal::ContainerValidateParams supported_formats_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::video_capture::mojom::I420CaptureFormatDataView>>(
            in_supported_formats, builder.buffer(), &supported_formats_ptr, &supported_formats_validate_params,
            &serialization_context_);
        params->supported_formats.Set(supported_formats_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->supported_formats.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null supported_formats in DeviceFactory.GetSupportedFormats response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class DeviceFactory_CreateDevice_ProxyToResponder {
    public:
        static DeviceFactory::CreateDeviceCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<DeviceFactory_CreateDevice_ProxyToResponder> proxy(
                new DeviceFactory_CreateDevice_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&DeviceFactory_CreateDevice_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~DeviceFactory_CreateDevice_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "DeviceFactory::CreateDevice() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        DeviceFactory_CreateDevice_ProxyToResponder(
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
            DeviceAccessResultCode in_result_code);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(DeviceFactory_CreateDevice_ProxyToResponder);
    };

    void DeviceFactory_CreateDevice_ProxyToResponder::Run(
        DeviceAccessResultCode in_result_code)
    {
        size_t size = sizeof(::video_capture::mojom::internal::DeviceFactory_CreateDevice_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDeviceFactory_CreateDevice_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::video_capture::mojom::internal::DeviceFactory_CreateDevice_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::video_capture::mojom::DeviceAccessResultCode>(
            in_result_code, &params->result_code);
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
    bool DeviceFactoryStubDispatch::Accept(
        DeviceFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDeviceFactory_EnumerateDeviceDescriptors_Name: {
            break;
        }
        case internal::kDeviceFactory_GetSupportedFormats_Name: {
            break;
        }
        case internal::kDeviceFactory_CreateDevice_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool DeviceFactoryStubDispatch::AcceptWithResponder(
        DeviceFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDeviceFactory_EnumerateDeviceDescriptors_Name: {
            internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data* params = reinterpret_cast<internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DeviceFactory_EnumerateDeviceDescriptors_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceFactory::EnumerateDeviceDescriptors deserializer");
                return false;
            }
            DeviceFactory::EnumerateDeviceDescriptorsCallback callback = DeviceFactory_EnumerateDeviceDescriptors_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceFactory::EnumerateDeviceDescriptors");
            mojo::internal::MessageDispatchContext context(message);
            impl->EnumerateDeviceDescriptors(std::move(callback));
            return true;
        }
        case internal::kDeviceFactory_GetSupportedFormats_Name: {
            internal::DeviceFactory_GetSupportedFormats_Params_Data* params = reinterpret_cast<internal::DeviceFactory_GetSupportedFormats_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_device_id {};
            DeviceFactory_GetSupportedFormats_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDeviceId(&p_device_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceFactory::GetSupportedFormats deserializer");
                return false;
            }
            DeviceFactory::GetSupportedFormatsCallback callback = DeviceFactory_GetSupportedFormats_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceFactory::GetSupportedFormats");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetSupportedFormats(
                std::move(p_device_id), std::move(callback));
            return true;
        }
        case internal::kDeviceFactory_CreateDevice_Name: {
            internal::DeviceFactory_CreateDevice_Params_Data* params = reinterpret_cast<internal::DeviceFactory_CreateDevice_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_device_id {};
            ::video_capture::mojom::DeviceRequest p_device_request {};
            DeviceFactory_CreateDevice_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDeviceId(&p_device_id))
                success = false;
            p_device_request = input_data_view.TakeDeviceRequest<decltype(p_device_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DeviceFactory::CreateDevice deserializer");
                return false;
            }
            DeviceFactory::CreateDeviceCallback callback = DeviceFactory_CreateDevice_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DeviceFactory::CreateDevice");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateDevice(
                std::move(p_device_id),
                std::move(p_device_request), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool DeviceFactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DeviceFactory RequestValidator");

        switch (message->header()->name) {
        case internal::kDeviceFactory_EnumerateDeviceDescriptors_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceFactory_GetSupportedFormats_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceFactory_GetSupportedFormats_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceFactory_CreateDevice_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceFactory_CreateDevice_Params_Data>(
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

    bool DeviceFactoryResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DeviceFactory ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kDeviceFactory_EnumerateDeviceDescriptors_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceFactory_GetSupportedFormats_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDeviceFactory_CreateDevice_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DeviceFactory_CreateDevice_ResponseParams_Data>(
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
} // namespace video_capture

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif