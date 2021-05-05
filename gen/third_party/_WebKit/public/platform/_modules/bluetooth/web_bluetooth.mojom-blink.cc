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

#include "third_party/WebKit/public/platform/modules/bluetooth/web_bluetooth.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/BluetoothStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/KURLStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/SecurityOriginStructTraits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
namespace blink {
namespace mojom {
    namespace blink { // static
        WebBluetoothScanFilterPtr WebBluetoothScanFilter::New()
        {
            WebBluetoothScanFilterPtr rv;
            mojo::internal::StructHelper<WebBluetoothScanFilter>::Initialize(&rv);
            return rv;
        }

        WebBluetoothScanFilter::WebBluetoothScanFilter()
            : services()
            , name()
            , name_prefix()
        {
        }

        WebBluetoothScanFilter::~WebBluetoothScanFilter()
        {
        } // static
        WebBluetoothRequestDeviceOptionsPtr WebBluetoothRequestDeviceOptions::New()
        {
            WebBluetoothRequestDeviceOptionsPtr rv;
            mojo::internal::StructHelper<WebBluetoothRequestDeviceOptions>::Initialize(&rv);
            return rv;
        }

        WebBluetoothRequestDeviceOptions::WebBluetoothRequestDeviceOptions()
            : filters()
            , optional_services()
            , accept_all_devices()
        {
        }

        WebBluetoothRequestDeviceOptions::~WebBluetoothRequestDeviceOptions()
        {
        } // static
        WebBluetoothDeviceIdPtr WebBluetoothDeviceId::New()
        {
            WebBluetoothDeviceIdPtr rv;
            mojo::internal::StructHelper<WebBluetoothDeviceId>::Initialize(&rv);
            return rv;
        }

        WebBluetoothDeviceId::WebBluetoothDeviceId()
            : device_id()
        {
        }

        WebBluetoothDeviceId::~WebBluetoothDeviceId()
        {
        } // static
        WebBluetoothDevicePtr WebBluetoothDevice::New()
        {
            WebBluetoothDevicePtr rv;
            mojo::internal::StructHelper<WebBluetoothDevice>::Initialize(&rv);
            return rv;
        }

        WebBluetoothDevice::WebBluetoothDevice()
            : id()
            , name()
        {
        }

        WebBluetoothDevice::~WebBluetoothDevice()
        {
        } // static
        WebBluetoothRemoteGATTServicePtr WebBluetoothRemoteGATTService::New()
        {
            WebBluetoothRemoteGATTServicePtr rv;
            mojo::internal::StructHelper<WebBluetoothRemoteGATTService>::Initialize(&rv);
            return rv;
        }

        WebBluetoothRemoteGATTService::WebBluetoothRemoteGATTService()
            : instance_id()
            , uuid()
        {
        }

        WebBluetoothRemoteGATTService::~WebBluetoothRemoteGATTService()
        {
        } // static
        WebBluetoothRemoteGATTCharacteristicPtr WebBluetoothRemoteGATTCharacteristic::New()
        {
            WebBluetoothRemoteGATTCharacteristicPtr rv;
            mojo::internal::StructHelper<WebBluetoothRemoteGATTCharacteristic>::Initialize(&rv);
            return rv;
        }

        WebBluetoothRemoteGATTCharacteristic::WebBluetoothRemoteGATTCharacteristic()
            : instance_id()
            , uuid()
            , properties()
        {
        }

        WebBluetoothRemoteGATTCharacteristic::~WebBluetoothRemoteGATTCharacteristic()
        {
        } // static
        WebBluetoothRemoteGATTDescriptorPtr WebBluetoothRemoteGATTDescriptor::New()
        {
            WebBluetoothRemoteGATTDescriptorPtr rv;
            mojo::internal::StructHelper<WebBluetoothRemoteGATTDescriptor>::Initialize(&rv);
            return rv;
        }

        WebBluetoothRemoteGATTDescriptor::WebBluetoothRemoteGATTDescriptor()
            : instance_id()
            , uuid()
        {
        }

        WebBluetoothRemoteGATTDescriptor::~WebBluetoothRemoteGATTDescriptor()
        {
        }
        const char WebBluetoothService::Name_[] = "blink::mojom::WebBluetoothService";

        class WebBluetoothService_RequestDevice_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RequestDevice_ForwardToCallback(
                const WebBluetoothService::RequestDeviceCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RequestDeviceCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RequestDevice_ForwardToCallback);
        };
        bool WebBluetoothService_RequestDevice_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RequestDevice_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RequestDevice_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WebBluetoothDevicePtr p_device {};
            WebBluetoothService_RequestDevice_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadDevice(&p_device))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RequestDevice response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_device));
            }
            return true;
        }

        class WebBluetoothService_RemoteServerConnect_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteServerConnect_ForwardToCallback(
                const WebBluetoothService::RemoteServerConnectCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteServerConnectCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteServerConnect_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteServerConnect_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WebBluetoothService_RemoteServerConnect_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteServerConnect response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result));
            }
            return true;
        }

        class WebBluetoothService_RemoteServerGetPrimaryServices_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteServerGetPrimaryServices_ForwardToCallback(
                const WebBluetoothService::RemoteServerGetPrimaryServicesCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteServerGetPrimaryServicesCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteServerGetPrimaryServices_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteServerGetPrimaryServices_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTServicePtr>> p_services {};
            WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadServices(&p_services))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteServerGetPrimaryServices response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_services));
            }
            return true;
        }

        class WebBluetoothService_RemoteServiceGetCharacteristics_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteServiceGetCharacteristics_ForwardToCallback(
                const WebBluetoothService::RemoteServiceGetCharacteristicsCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteServiceGetCharacteristicsCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteServiceGetCharacteristics_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteServiceGetCharacteristics_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTCharacteristicPtr>> p_characteristics {};
            WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadCharacteristics(&p_characteristics))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteServiceGetCharacteristics response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_characteristics));
            }
            return true;
        }

        class WebBluetoothService_RemoteCharacteristicReadValue_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteCharacteristicReadValue_ForwardToCallback(
                const WebBluetoothService::RemoteCharacteristicReadValueCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteCharacteristicReadValueCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicReadValue_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteCharacteristicReadValue_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WTF::Optional<WTF::Vector<uint8_t>> p_value {};
            WebBluetoothService_RemoteCharacteristicReadValue_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteCharacteristicReadValue response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_value));
            }
            return true;
        }

        class WebBluetoothService_RemoteCharacteristicWriteValue_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteCharacteristicWriteValue_ForwardToCallback(
                const WebBluetoothService::RemoteCharacteristicWriteValueCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteCharacteristicWriteValueCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicWriteValue_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteCharacteristicWriteValue_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteCharacteristicWriteValue response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result));
            }
            return true;
        }

        class WebBluetoothService_RemoteCharacteristicStartNotifications_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteCharacteristicStartNotifications_ForwardToCallback(
                const WebBluetoothService::RemoteCharacteristicStartNotificationsCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteCharacteristicStartNotificationsCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicStartNotifications_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteCharacteristicStartNotifications_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteCharacteristicStartNotifications response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result));
            }
            return true;
        }

        class WebBluetoothService_RemoteCharacteristicStopNotifications_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteCharacteristicStopNotifications_ForwardToCallback(
                const WebBluetoothService::RemoteCharacteristicStopNotificationsCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteCharacteristicStopNotificationsCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicStopNotifications_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteCharacteristicStopNotifications_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteCharacteristicStopNotifications response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run();
            }
            return true;
        }

        class WebBluetoothService_RemoteCharacteristicGetDescriptors_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            WebBluetoothService_RemoteCharacteristicGetDescriptors_ForwardToCallback(
                const WebBluetoothService::RemoteCharacteristicGetDescriptorsCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            WebBluetoothService::RemoteCharacteristicGetDescriptorsCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicGetDescriptors_ForwardToCallback);
        };
        bool WebBluetoothService_RemoteCharacteristicGetDescriptors_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WebBluetoothResult p_result {};
            WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTDescriptorPtr>> p_descriptors {};
            WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadDescriptors(&p_descriptors))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WebBluetoothService::RemoteCharacteristicGetDescriptors response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_descriptors));
            }
            return true;
        }

        WebBluetoothServiceProxy::WebBluetoothServiceProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void WebBluetoothServiceProxy::SetClient(
            WebBluetoothServiceClientAssociatedPtrInfo in_client)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_SetClient_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kWebBluetoothService_SetClient_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_SetClient_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothServiceClientAssociatedPtrInfoDataView>(
                in_client, &params->client, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->client),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
                "invalid client in WebBluetoothService.SetClient request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebBluetoothServiceProxy::RequestDevice(
            WebBluetoothRequestDeviceOptionsPtr in_options, const RequestDeviceCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RequestDevice_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothRequestDeviceOptionsDataView>(
                in_options, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RequestDevice_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RequestDevice_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->options)::BaseType* options_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothRequestDeviceOptionsDataView>(
                in_options, builder.buffer(), &options_ptr, &serialization_context);
            params->options.Set(options_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->options.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null options in WebBluetoothService.RequestDevice request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RequestDevice_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteServerConnect(
            const WTF::String& in_device_id, const RemoteServerConnectCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServerConnect_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteServerConnect_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServerConnect_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->device_id)::BaseType* device_id_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, builder.buffer(), &device_id_ptr, &serialization_context);
            params->device_id.Set(device_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->device_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_id in WebBluetoothService.RemoteServerConnect request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteServerConnect_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteServerDisconnect(
            const WTF::String& in_device_id)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServerDisconnect_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebBluetoothService_RemoteServerDisconnect_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServerDisconnect_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->device_id)::BaseType* device_id_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, builder.buffer(), &device_id_ptr, &serialization_context);
            params->device_id.Set(device_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->device_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_id in WebBluetoothService.RemoteServerDisconnect request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebBluetoothServiceProxy::RemoteServerGetPrimaryServices(
            const WTF::String& in_device_id, WebBluetoothGATTQueryQuantity in_quantity, const WTF::Optional<WTF::String>& in_services_uuid, const RemoteServerGetPrimaryServicesCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, &serialization_context);
            size += mojo::internal::PrepareToSerialize<::bluetooth::mojom::UUIDDataView>(
                in_services_uuid, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteServerGetPrimaryServices_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->device_id)::BaseType* device_id_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, builder.buffer(), &device_id_ptr, &serialization_context);
            params->device_id.Set(device_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->device_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_id in WebBluetoothService.RemoteServerGetPrimaryServices request");
            mojo::internal::Serialize<::blink::mojom::WebBluetoothGATTQueryQuantity>(
                in_quantity, &params->quantity);
            typename decltype(params->services_uuid)::BaseType* services_uuid_ptr;
            mojo::internal::Serialize<::bluetooth::mojom::UUIDDataView>(
                in_services_uuid, builder.buffer(), &services_uuid_ptr, &serialization_context);
            params->services_uuid.Set(services_uuid_ptr);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteServerGetPrimaryServices_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteServiceGetCharacteristics(
            const WTF::String& in_service_instance_id, WebBluetoothGATTQueryQuantity in_quantity, const WTF::Optional<WTF::String>& in_characteristics_uuid, const RemoteServiceGetCharacteristicsCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_service_instance_id, &serialization_context);
            size += mojo::internal::PrepareToSerialize<::bluetooth::mojom::UUIDDataView>(
                in_characteristics_uuid, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteServiceGetCharacteristics_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->service_instance_id)::BaseType* service_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_service_instance_id, builder.buffer(), &service_instance_id_ptr, &serialization_context);
            params->service_instance_id.Set(service_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->service_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null service_instance_id in WebBluetoothService.RemoteServiceGetCharacteristics request");
            mojo::internal::Serialize<::blink::mojom::WebBluetoothGATTQueryQuantity>(
                in_quantity, &params->quantity);
            typename decltype(params->characteristics_uuid)::BaseType* characteristics_uuid_ptr;
            mojo::internal::Serialize<::bluetooth::mojom::UUIDDataView>(
                in_characteristics_uuid, builder.buffer(), &characteristics_uuid_ptr, &serialization_context);
            params->characteristics_uuid.Set(characteristics_uuid_ptr);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteServiceGetCharacteristics_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteCharacteristicReadValue(
            const WTF::String& in_characteristic_instance_id, const RemoteCharacteristicReadValueCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_characteristic_instance_id, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteCharacteristicReadValue_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->characteristic_instance_id)::BaseType* characteristic_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_characteristic_instance_id, builder.buffer(), &characteristic_instance_id_ptr, &serialization_context);
            params->characteristic_instance_id.Set(characteristic_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->characteristic_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null characteristic_instance_id in WebBluetoothService.RemoteCharacteristicReadValue request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteCharacteristicReadValue_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteCharacteristicWriteValue(
            const WTF::String& in_characteristic_instance_id, const WTF::Vector<uint8_t>& in_value, const RemoteCharacteristicWriteValueCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_characteristic_instance_id, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_value, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteCharacteristicWriteValue_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->characteristic_instance_id)::BaseType* characteristic_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_characteristic_instance_id, builder.buffer(), &characteristic_instance_id_ptr, &serialization_context);
            params->characteristic_instance_id.Set(characteristic_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->characteristic_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null characteristic_instance_id in WebBluetoothService.RemoteCharacteristicWriteValue request");
            typename decltype(params->value)::BaseType* value_ptr;
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_value, builder.buffer(), &value_ptr, &value_validate_params,
                &serialization_context);
            params->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in WebBluetoothService.RemoteCharacteristicWriteValue request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteCharacteristicWriteValue_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteCharacteristicStartNotifications(
            const WTF::String& in_characteristic_instance_id, const RemoteCharacteristicStartNotificationsCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_characteristic_instance_id, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteCharacteristicStartNotifications_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->characteristic_instance_id)::BaseType* characteristic_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_characteristic_instance_id, builder.buffer(), &characteristic_instance_id_ptr, &serialization_context);
            params->characteristic_instance_id.Set(characteristic_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->characteristic_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null characteristic_instance_id in WebBluetoothService.RemoteCharacteristicStartNotifications request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteCharacteristicStartNotifications_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteCharacteristicStopNotifications(
            const WTF::String& in_characteristic_instance_id, const RemoteCharacteristicStopNotificationsCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_characteristic_instance_id, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteCharacteristicStopNotifications_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->characteristic_instance_id)::BaseType* characteristic_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_characteristic_instance_id, builder.buffer(), &characteristic_instance_id_ptr, &serialization_context);
            params->characteristic_instance_id.Set(characteristic_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->characteristic_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null characteristic_instance_id in WebBluetoothService.RemoteCharacteristicStopNotifications request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteCharacteristicStopNotifications_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void WebBluetoothServiceProxy::RemoteCharacteristicGetDescriptors(
            const WTF::String& in_characteristics_instance_id, WebBluetoothGATTQueryQuantity in_quantity, const WTF::Optional<WTF::String>& in_descriptor_uuid, const RemoteCharacteristicGetDescriptorsCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_characteristics_instance_id, &serialization_context);
            size += mojo::internal::PrepareToSerialize<::bluetooth::mojom::UUIDDataView>(
                in_descriptor_uuid, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->characteristics_instance_id)::BaseType* characteristics_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_characteristics_instance_id, builder.buffer(), &characteristics_instance_id_ptr, &serialization_context);
            params->characteristics_instance_id.Set(characteristics_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->characteristics_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null characteristics_instance_id in WebBluetoothService.RemoteCharacteristicGetDescriptors request");
            mojo::internal::Serialize<::blink::mojom::WebBluetoothGATTQueryQuantity>(
                in_quantity, &params->quantity);
            typename decltype(params->descriptor_uuid)::BaseType* descriptor_uuid_ptr;
            mojo::internal::Serialize<::bluetooth::mojom::UUIDDataView>(
                in_descriptor_uuid, builder.buffer(), &descriptor_uuid_ptr, &serialization_context);
            params->descriptor_uuid.Set(descriptor_uuid_ptr);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new WebBluetoothService_RemoteCharacteristicGetDescriptors_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }
        class WebBluetoothService_RequestDevice_ProxyToResponder {
        public:
            static WebBluetoothService::RequestDeviceCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RequestDevice_ProxyToResponder> proxy(
                    new WebBluetoothService_RequestDevice_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RequestDevice_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RequestDevice_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RequestDevice() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RequestDevice_ProxyToResponder(
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
                WebBluetoothResult in_result, WebBluetoothDevicePtr in_device);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RequestDevice_ProxyToResponder);
        };

        void WebBluetoothService_RequestDevice_ProxyToResponder::Run(
            WebBluetoothResult in_result, WebBluetoothDevicePtr in_device)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RequestDevice_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothDeviceDataView>(
                in_device, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RequestDevice_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RequestDevice_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            typename decltype(params->device)::BaseType* device_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothDeviceDataView>(
                in_device, builder.buffer(), &device_ptr, &serialization_context_);
            params->device.Set(device_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteServerConnect_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteServerConnectCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteServerConnect_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteServerConnect_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteServerConnect_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteServerConnect_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteServerConnect() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteServerConnect_ProxyToResponder(
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
                WebBluetoothResult in_result);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteServerConnect_ProxyToResponder);
        };

        void WebBluetoothService_RemoteServerConnect_ProxyToResponder::Run(
            WebBluetoothResult in_result)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteServerConnect_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteServerGetPrimaryServicesCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteServerGetPrimaryServices() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder(
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
                WebBluetoothResult in_result, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTServicePtr>> in_services);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder);
        };

        void WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder::Run(
            WebBluetoothResult in_result, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTServicePtr>> in_services)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTServiceDataView>>(
                in_services, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteServerGetPrimaryServices_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            typename decltype(params->services)::BaseType* services_ptr;
            const mojo::internal::ContainerValidateParams services_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTServiceDataView>>(
                in_services, builder.buffer(), &services_ptr, &services_validate_params,
                &serialization_context_);
            params->services.Set(services_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteServiceGetCharacteristicsCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteServiceGetCharacteristics() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder(
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
                WebBluetoothResult in_result, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTCharacteristicPtr>> in_characteristics);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder);
        };

        void WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder::Run(
            WebBluetoothResult in_result, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTCharacteristicPtr>> in_characteristics)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView>>(
                in_characteristics, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteServiceGetCharacteristics_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            typename decltype(params->characteristics)::BaseType* characteristics_ptr;
            const mojo::internal::ContainerValidateParams characteristics_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView>>(
                in_characteristics, builder.buffer(), &characteristics_ptr, &characteristics_validate_params,
                &serialization_context_);
            params->characteristics.Set(characteristics_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteCharacteristicReadValueCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteCharacteristicReadValue() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder(
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
                WebBluetoothResult in_result, const WTF::Optional<WTF::Vector<uint8_t>>& in_value);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder);
        };

        void WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder::Run(
            WebBluetoothResult in_result, const WTF::Optional<WTF::Vector<uint8_t>>& in_value)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_value, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteCharacteristicReadValue_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            typename decltype(params->value)::BaseType* value_ptr;
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_value, builder.buffer(), &value_ptr, &value_validate_params,
                &serialization_context_);
            params->value.Set(value_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteCharacteristicWriteValueCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteCharacteristicWriteValue() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder(
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
                WebBluetoothResult in_result);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder);
        };

        void WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder::Run(
            WebBluetoothResult in_result)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteCharacteristicWriteValue_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteCharacteristicStartNotificationsCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteCharacteristicStartNotifications() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder(
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
                WebBluetoothResult in_result);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder);
        };

        void WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder::Run(
            WebBluetoothResult in_result)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteCharacteristicStartNotifications_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteCharacteristicStopNotificationsCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteCharacteristicStopNotifications() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder(
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

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder);
        };

        void WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder::Run()
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteCharacteristicStopNotifications_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data::New(builder.buffer());
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
        class WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder {
        public:
            static WebBluetoothService::RemoteCharacteristicGetDescriptorsCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder> proxy(
                    new WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "WebBluetoothService::RemoteCharacteristicGetDescriptors() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder(
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
                WebBluetoothResult in_result, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTDescriptorPtr>> in_descriptors);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder);
        };

        void WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder::Run(
            WebBluetoothResult in_result, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTDescriptorPtr>> in_descriptors)
        {
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView>>(
                in_descriptors, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::blink::mojom::internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::blink::mojom::WebBluetoothResult>(
                in_result, &params->result);
            typename decltype(params->descriptors)::BaseType* descriptors_ptr;
            const mojo::internal::ContainerValidateParams descriptors_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView>>(
                in_descriptors, builder.buffer(), &descriptors_ptr, &descriptors_validate_params,
                &serialization_context_);
            params->descriptors.Set(descriptors_ptr);
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
        bool WebBluetoothServiceStubDispatch::Accept(
            WebBluetoothService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kWebBluetoothService_SetClient_Name: {
                internal::WebBluetoothService_SetClient_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_SetClient_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WebBluetoothServiceClientAssociatedPtrInfo p_client {};
                WebBluetoothService_SetClient_ParamsDataView input_data_view(params,
                    context);

                p_client = input_data_view.TakeClient<decltype(p_client)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::SetClient deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::SetClient");
                mojo::internal::MessageDispatchContext context(message);
                impl->SetClient(
                    std::move(p_client));
                return true;
            }
            case internal::kWebBluetoothService_RequestDevice_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteServerConnect_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteServerDisconnect_Name: {
                internal::WebBluetoothService_RemoteServerDisconnect_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServerDisconnect_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_device_id {};
                WebBluetoothService_RemoteServerDisconnect_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadDeviceId(&p_device_id))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteServerDisconnect deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteServerDisconnect");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteServerDisconnect(
                    std::move(p_device_id));
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerGetPrimaryServices_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteServiceGetCharacteristics_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicReadValue_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicWriteValue_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStartNotifications_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStopNotifications_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name: {
                break;
            }
            }
            return false;
        }

        // static
        bool WebBluetoothServiceStubDispatch::AcceptWithResponder(
            WebBluetoothService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kWebBluetoothService_SetClient_Name: {
                break;
            }
            case internal::kWebBluetoothService_RequestDevice_Name: {
                internal::WebBluetoothService_RequestDevice_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RequestDevice_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WebBluetoothRequestDeviceOptionsPtr p_options {};
                WebBluetoothService_RequestDevice_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadOptions(&p_options))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RequestDevice deserializer");
                    return false;
                }
                WebBluetoothService::RequestDeviceCallback callback = WebBluetoothService_RequestDevice_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RequestDevice");
                mojo::internal::MessageDispatchContext context(message);
                impl->RequestDevice(
                    std::move(p_options), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerConnect_Name: {
                internal::WebBluetoothService_RemoteServerConnect_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServerConnect_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_device_id {};
                WebBluetoothService_RemoteServerConnect_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadDeviceId(&p_device_id))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteServerConnect deserializer");
                    return false;
                }
                WebBluetoothService::RemoteServerConnectCallback callback = WebBluetoothService_RemoteServerConnect_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteServerConnect");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteServerConnect(
                    std::move(p_device_id), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerDisconnect_Name: {
                break;
            }
            case internal::kWebBluetoothService_RemoteServerGetPrimaryServices_Name: {
                internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_device_id {};
                WebBluetoothGATTQueryQuantity p_quantity {};
                WTF::Optional<WTF::String> p_services_uuid {};
                WebBluetoothService_RemoteServerGetPrimaryServices_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadDeviceId(&p_device_id))
                    success = false;
                if (!input_data_view.ReadQuantity(&p_quantity))
                    success = false;
                if (!input_data_view.ReadServicesUuid(&p_services_uuid))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteServerGetPrimaryServices deserializer");
                    return false;
                }
                WebBluetoothService::RemoteServerGetPrimaryServicesCallback callback = WebBluetoothService_RemoteServerGetPrimaryServices_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteServerGetPrimaryServices");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteServerGetPrimaryServices(
                    std::move(p_device_id),
                    std::move(p_quantity),
                    std::move(p_services_uuid), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteServiceGetCharacteristics_Name: {
                internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_service_instance_id {};
                WebBluetoothGATTQueryQuantity p_quantity {};
                WTF::Optional<WTF::String> p_characteristics_uuid {};
                WebBluetoothService_RemoteServiceGetCharacteristics_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadServiceInstanceId(&p_service_instance_id))
                    success = false;
                if (!input_data_view.ReadQuantity(&p_quantity))
                    success = false;
                if (!input_data_view.ReadCharacteristicsUuid(&p_characteristics_uuid))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteServiceGetCharacteristics deserializer");
                    return false;
                }
                WebBluetoothService::RemoteServiceGetCharacteristicsCallback callback = WebBluetoothService_RemoteServiceGetCharacteristics_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteServiceGetCharacteristics");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteServiceGetCharacteristics(
                    std::move(p_service_instance_id),
                    std::move(p_quantity),
                    std::move(p_characteristics_uuid), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicReadValue_Name: {
                internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_characteristic_instance_id {};
                WebBluetoothService_RemoteCharacteristicReadValue_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadCharacteristicInstanceId(&p_characteristic_instance_id))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteCharacteristicReadValue deserializer");
                    return false;
                }
                WebBluetoothService::RemoteCharacteristicReadValueCallback callback = WebBluetoothService_RemoteCharacteristicReadValue_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteCharacteristicReadValue");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteCharacteristicReadValue(
                    std::move(p_characteristic_instance_id), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicWriteValue_Name: {
                internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_characteristic_instance_id {};
                WTF::Vector<uint8_t> p_value {};
                WebBluetoothService_RemoteCharacteristicWriteValue_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadCharacteristicInstanceId(&p_characteristic_instance_id))
                    success = false;
                if (!input_data_view.ReadValue(&p_value))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteCharacteristicWriteValue deserializer");
                    return false;
                }
                WebBluetoothService::RemoteCharacteristicWriteValueCallback callback = WebBluetoothService_RemoteCharacteristicWriteValue_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteCharacteristicWriteValue");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteCharacteristicWriteValue(
                    std::move(p_characteristic_instance_id),
                    std::move(p_value), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStartNotifications_Name: {
                internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_characteristic_instance_id {};
                WebBluetoothService_RemoteCharacteristicStartNotifications_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadCharacteristicInstanceId(&p_characteristic_instance_id))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteCharacteristicStartNotifications deserializer");
                    return false;
                }
                WebBluetoothService::RemoteCharacteristicStartNotificationsCallback callback = WebBluetoothService_RemoteCharacteristicStartNotifications_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteCharacteristicStartNotifications");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteCharacteristicStartNotifications(
                    std::move(p_characteristic_instance_id), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStopNotifications_Name: {
                internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_characteristic_instance_id {};
                WebBluetoothService_RemoteCharacteristicStopNotifications_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadCharacteristicInstanceId(&p_characteristic_instance_id))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteCharacteristicStopNotifications deserializer");
                    return false;
                }
                WebBluetoothService::RemoteCharacteristicStopNotificationsCallback callback = WebBluetoothService_RemoteCharacteristicStopNotifications_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteCharacteristicStopNotifications");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteCharacteristicStopNotifications(
                    std::move(p_characteristic_instance_id), std::move(callback));
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name: {
                internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data* params = reinterpret_cast<internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_characteristics_instance_id {};
                WebBluetoothGATTQueryQuantity p_quantity {};
                WTF::Optional<WTF::String> p_descriptor_uuid {};
                WebBluetoothService_RemoteCharacteristicGetDescriptors_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadCharacteristicsInstanceId(&p_characteristics_instance_id))
                    success = false;
                if (!input_data_view.ReadQuantity(&p_quantity))
                    success = false;
                if (!input_data_view.ReadDescriptorUuid(&p_descriptor_uuid))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothService::RemoteCharacteristicGetDescriptors deserializer");
                    return false;
                }
                WebBluetoothService::RemoteCharacteristicGetDescriptorsCallback callback = WebBluetoothService_RemoteCharacteristicGetDescriptors_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothService::RemoteCharacteristicGetDescriptors");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteCharacteristicGetDescriptors(
                    std::move(p_characteristics_instance_id),
                    std::move(p_quantity),
                    std::move(p_descriptor_uuid), std::move(callback));
                return true;
            }
            }
            return false;
        }

        bool WebBluetoothServiceRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "WebBluetoothService RequestValidator");

            switch (message->header()->name) {
            case internal::kWebBluetoothService_SetClient_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_SetClient_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RequestDevice_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RequestDevice_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerConnect_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServerConnect_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerDisconnect_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServerDisconnect_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerGetPrimaryServices_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServiceGetCharacteristics_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicReadValue_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicWriteValue_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStartNotifications_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStopNotifications_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data>(
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

        bool WebBluetoothServiceResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "WebBluetoothService ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kWebBluetoothService_RequestDevice_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RequestDevice_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerConnect_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServerGetPrimaryServices_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteServiceGetCharacteristics_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicReadValue_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicWriteValue_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStartNotifications_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicStopNotifications_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data>(
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
        const char WebBluetoothServiceClient::Name_[] = "blink::mojom::WebBluetoothServiceClient";

        WebBluetoothServiceClientProxy::WebBluetoothServiceClientProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void WebBluetoothServiceClientProxy::RemoteCharacteristicValueChanged(
            const WTF::String& in_characteristic_instance_id, const WTF::Vector<uint8_t>& in_value)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_characteristic_instance_id, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_value, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebBluetoothServiceClient_RemoteCharacteristicValueChanged_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->characteristic_instance_id)::BaseType* characteristic_instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_characteristic_instance_id, builder.buffer(), &characteristic_instance_id_ptr, &serialization_context);
            params->characteristic_instance_id.Set(characteristic_instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->characteristic_instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null characteristic_instance_id in WebBluetoothServiceClient.RemoteCharacteristicValueChanged request");
            typename decltype(params->value)::BaseType* value_ptr;
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_value, builder.buffer(), &value_ptr, &value_validate_params,
                &serialization_context);
            params->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in WebBluetoothServiceClient.RemoteCharacteristicValueChanged request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebBluetoothServiceClientProxy::GattServerDisconnected(
            const WTF::String& in_device_id)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebBluetoothServiceClient_GattServerDisconnected_Name, size);

            auto params = ::blink::mojom::internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->device_id)::BaseType* device_id_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_device_id, builder.buffer(), &device_id_ptr, &serialization_context);
            params->device_id.Set(device_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->device_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_id in WebBluetoothServiceClient.GattServerDisconnected request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool WebBluetoothServiceClientStubDispatch::Accept(
            WebBluetoothServiceClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kWebBluetoothServiceClient_RemoteCharacteristicValueChanged_Name: {
                internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data* params = reinterpret_cast<internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_characteristic_instance_id {};
                WTF::Vector<uint8_t> p_value {};
                WebBluetoothServiceClient_RemoteCharacteristicValueChanged_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadCharacteristicInstanceId(&p_characteristic_instance_id))
                    success = false;
                if (!input_data_view.ReadValue(&p_value))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothServiceClient::RemoteCharacteristicValueChanged deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothServiceClient::RemoteCharacteristicValueChanged");
                mojo::internal::MessageDispatchContext context(message);
                impl->RemoteCharacteristicValueChanged(
                    std::move(p_characteristic_instance_id),
                    std::move(p_value));
                return true;
            }
            case internal::kWebBluetoothServiceClient_GattServerDisconnected_Name: {
                internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data* params = reinterpret_cast<internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_device_id {};
                WebBluetoothServiceClient_GattServerDisconnected_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadDeviceId(&p_device_id))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebBluetoothServiceClient::GattServerDisconnected deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebBluetoothServiceClient::GattServerDisconnected");
                mojo::internal::MessageDispatchContext context(message);
                impl->GattServerDisconnected(
                    std::move(p_device_id));
                return true;
            }
            }
            return false;
        }

        // static
        bool WebBluetoothServiceClientStubDispatch::AcceptWithResponder(
            WebBluetoothServiceClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kWebBluetoothServiceClient_RemoteCharacteristicValueChanged_Name: {
                break;
            }
            case internal::kWebBluetoothServiceClient_GattServerDisconnected_Name: {
                break;
            }
            }
            return false;
        }

        bool WebBluetoothServiceClientRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "WebBluetoothServiceClient RequestValidator");

            switch (message->header()->name) {
            case internal::kWebBluetoothServiceClient_RemoteCharacteristicValueChanged_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebBluetoothServiceClient_GattServerDisconnected_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data>(
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

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothScanFilter::DataView, ::blink::mojom::blink::WebBluetoothScanFilterPtr>::Read(
    ::blink::mojom::blink::WebBluetoothScanFilter::DataView input,
    ::blink::mojom::blink::WebBluetoothScanFilterPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothScanFilterPtr result(::blink::mojom::blink::WebBluetoothScanFilter::New());

    if (!input.ReadServices(&result->services))
        success = false;
    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadNamePrefix(&result->name_prefix))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothRequestDeviceOptions::DataView, ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr>::Read(
    ::blink::mojom::blink::WebBluetoothRequestDeviceOptions::DataView input,
    ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr result(::blink::mojom::blink::WebBluetoothRequestDeviceOptions::New());

    if (!input.ReadFilters(&result->filters))
        success = false;
    if (!input.ReadOptionalServices(&result->optional_services))
        success = false;
    result->accept_all_devices = input.accept_all_devices();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothDeviceId::DataView, ::blink::mojom::blink::WebBluetoothDeviceIdPtr>::Read(
    ::blink::mojom::blink::WebBluetoothDeviceId::DataView input,
    ::blink::mojom::blink::WebBluetoothDeviceIdPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothDeviceIdPtr result(::blink::mojom::blink::WebBluetoothDeviceId::New());

    if (!input.ReadDeviceId(&result->device_id))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothDevice::DataView, ::blink::mojom::blink::WebBluetoothDevicePtr>::Read(
    ::blink::mojom::blink::WebBluetoothDevice::DataView input,
    ::blink::mojom::blink::WebBluetoothDevicePtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothDevicePtr result(::blink::mojom::blink::WebBluetoothDevice::New());

    if (!input.ReadId(&result->id))
        success = false;
    if (!input.ReadName(&result->name))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothRemoteGATTService::DataView, ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr>::Read(
    ::blink::mojom::blink::WebBluetoothRemoteGATTService::DataView input,
    ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr result(::blink::mojom::blink::WebBluetoothRemoteGATTService::New());

    if (!input.ReadInstanceId(&result->instance_id))
        success = false;
    if (!input.ReadUuid(&result->uuid))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::DataView, ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr>::Read(
    ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::DataView input,
    ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr result(::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::New());

    if (!input.ReadInstanceId(&result->instance_id))
        success = false;
    if (!input.ReadUuid(&result->uuid))
        success = false;
    result->properties = input.properties();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::DataView, ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr>::Read(
    ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::DataView input,
    ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr result(::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::New());

    if (!input.ReadInstanceId(&result->instance_id))
        success = false;
    if (!input.ReadUuid(&result->uuid))
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