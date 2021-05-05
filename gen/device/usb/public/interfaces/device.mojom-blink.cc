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

#include "device/usb/public/interfaces/device.mojom-blink.h"

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
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace usb {
    namespace blink { // static
        EndpointInfoPtr EndpointInfo::New()
        {
            EndpointInfoPtr rv;
            mojo::internal::StructHelper<EndpointInfo>::Initialize(&rv);
            return rv;
        }

        EndpointInfo::EndpointInfo()
            : endpoint_number()
            , direction()
            , type()
            , packet_size()
        {
        }

        EndpointInfo::~EndpointInfo()
        {
        }
        size_t EndpointInfo::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->endpoint_number);
            seed = mojo::internal::WTFHash(seed, this->direction);
            seed = mojo::internal::WTFHash(seed, this->type);
            seed = mojo::internal::WTFHash(seed, this->packet_size);
            return seed;
        } // static
        AlternateInterfaceInfoPtr AlternateInterfaceInfo::New()
        {
            AlternateInterfaceInfoPtr rv;
            mojo::internal::StructHelper<AlternateInterfaceInfo>::Initialize(&rv);
            return rv;
        }

        AlternateInterfaceInfo::AlternateInterfaceInfo()
            : alternate_setting()
            , class_code()
            , subclass_code()
            , protocol_code()
            , interface_name()
            , endpoints()
        {
        }

        AlternateInterfaceInfo::~AlternateInterfaceInfo()
        {
        } // static
        InterfaceInfoPtr InterfaceInfo::New()
        {
            InterfaceInfoPtr rv;
            mojo::internal::StructHelper<InterfaceInfo>::Initialize(&rv);
            return rv;
        }

        InterfaceInfo::InterfaceInfo()
            : interface_number()
            , alternates()
        {
        }

        InterfaceInfo::~InterfaceInfo()
        {
        } // static
        ConfigurationInfoPtr ConfigurationInfo::New()
        {
            ConfigurationInfoPtr rv;
            mojo::internal::StructHelper<ConfigurationInfo>::Initialize(&rv);
            return rv;
        }

        ConfigurationInfo::ConfigurationInfo()
            : configuration_value()
            , configuration_name()
            , interfaces()
        {
        }

        ConfigurationInfo::~ConfigurationInfo()
        {
        } // static
        DeviceInfoPtr DeviceInfo::New()
        {
            DeviceInfoPtr rv;
            mojo::internal::StructHelper<DeviceInfo>::Initialize(&rv);
            return rv;
        }

        DeviceInfo::DeviceInfo()
            : guid()
            , usb_version_major()
            , usb_version_minor()
            , usb_version_subminor()
            , class_code()
            , subclass_code()
            , protocol_code()
            , vendor_id()
            , product_id()
            , device_version_major()
            , device_version_minor()
            , device_version_subminor()
            , manufacturer_name()
            , product_name()
            , serial_number()
            , active_configuration()
            , configurations()
        {
        }

        DeviceInfo::~DeviceInfo()
        {
        } // static
        ControlTransferParamsPtr ControlTransferParams::New()
        {
            ControlTransferParamsPtr rv;
            mojo::internal::StructHelper<ControlTransferParams>::Initialize(&rv);
            return rv;
        }

        ControlTransferParams::ControlTransferParams()
            : type()
            , recipient()
            , request()
            , value()
            , index()
        {
        }

        ControlTransferParams::~ControlTransferParams()
        {
        }
        size_t ControlTransferParams::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->type);
            seed = mojo::internal::WTFHash(seed, this->recipient);
            seed = mojo::internal::WTFHash(seed, this->request);
            seed = mojo::internal::WTFHash(seed, this->value);
            seed = mojo::internal::WTFHash(seed, this->index);
            return seed;
        } // static
        IsochronousPacketPtr IsochronousPacket::New()
        {
            IsochronousPacketPtr rv;
            mojo::internal::StructHelper<IsochronousPacket>::Initialize(&rv);
            return rv;
        }

        IsochronousPacket::IsochronousPacket()
            : length()
            , transferred_length()
            , status()
        {
        }

        IsochronousPacket::~IsochronousPacket()
        {
        }
        size_t IsochronousPacket::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->length);
            seed = mojo::internal::WTFHash(seed, this->transferred_length);
            seed = mojo::internal::WTFHash(seed, this->status);
            return seed;
        }
        const char Device::Name_[] = "device::usb::Device";

        class Device_GetDeviceInfo_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_GetDeviceInfo_ForwardToCallback(
                const Device::GetDeviceInfoCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::GetDeviceInfoCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_GetDeviceInfo_ForwardToCallback);
        };
        bool Device_GetDeviceInfo_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_GetDeviceInfo_ResponseParams_Data* params = reinterpret_cast<internal::Device_GetDeviceInfo_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DeviceInfoPtr p_info {};
            Device_GetDeviceInfo_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadInfo(&p_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::GetDeviceInfo response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_info));
            }
            return true;
        }

        class Device_Open_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_Open_ForwardToCallback(
                const Device::OpenCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::OpenCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_Open_ForwardToCallback);
        };
        bool Device_Open_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_Open_ResponseParams_Data* params = reinterpret_cast<internal::Device_Open_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            OpenDeviceError p_error {};
            Device_Open_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadError(&p_error))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::Open response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_error));
            }
            return true;
        }

        class Device_Close_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_Close_ForwardToCallback(
                const Device::CloseCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::CloseCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_Close_ForwardToCallback);
        };
        bool Device_Close_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_Close_ResponseParams_Data* params = reinterpret_cast<internal::Device_Close_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Device_Close_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::Close response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run();
            }
            return true;
        }

        class Device_SetConfiguration_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_SetConfiguration_ForwardToCallback(
                const Device::SetConfigurationCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::SetConfigurationCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_SetConfiguration_ForwardToCallback);
        };
        bool Device_SetConfiguration_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_SetConfiguration_ResponseParams_Data* params = reinterpret_cast<internal::Device_SetConfiguration_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Device_SetConfiguration_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::SetConfiguration response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Device_ClaimInterface_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_ClaimInterface_ForwardToCallback(
                const Device::ClaimInterfaceCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::ClaimInterfaceCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_ClaimInterface_ForwardToCallback);
        };
        bool Device_ClaimInterface_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_ClaimInterface_ResponseParams_Data* params = reinterpret_cast<internal::Device_ClaimInterface_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Device_ClaimInterface_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::ClaimInterface response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Device_ReleaseInterface_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_ReleaseInterface_ForwardToCallback(
                const Device::ReleaseInterfaceCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::ReleaseInterfaceCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_ReleaseInterface_ForwardToCallback);
        };
        bool Device_ReleaseInterface_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_ReleaseInterface_ResponseParams_Data* params = reinterpret_cast<internal::Device_ReleaseInterface_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Device_ReleaseInterface_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::ReleaseInterface response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Device_SetInterfaceAlternateSetting_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_SetInterfaceAlternateSetting_ForwardToCallback(
                const Device::SetInterfaceAlternateSettingCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::SetInterfaceAlternateSettingCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_SetInterfaceAlternateSetting_ForwardToCallback);
        };
        bool Device_SetInterfaceAlternateSetting_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data* params = reinterpret_cast<internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Device_SetInterfaceAlternateSetting_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::SetInterfaceAlternateSetting response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Device_Reset_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_Reset_ForwardToCallback(
                const Device::ResetCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::ResetCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_Reset_ForwardToCallback);
        };
        bool Device_Reset_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_Reset_ResponseParams_Data* params = reinterpret_cast<internal::Device_Reset_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Device_Reset_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::Reset response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Device_ClearHalt_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_ClearHalt_ForwardToCallback(
                const Device::ClearHaltCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::ClearHaltCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_ClearHalt_ForwardToCallback);
        };
        bool Device_ClearHalt_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_ClearHalt_ResponseParams_Data* params = reinterpret_cast<internal::Device_ClearHalt_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            Device_ClearHalt_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::ClearHalt response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_success));
            }
            return true;
        }

        class Device_ControlTransferIn_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_ControlTransferIn_ForwardToCallback(
                const Device::ControlTransferInCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::ControlTransferInCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_ControlTransferIn_ForwardToCallback);
        };
        bool Device_ControlTransferIn_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_ControlTransferIn_ResponseParams_Data* params = reinterpret_cast<internal::Device_ControlTransferIn_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TransferStatus p_status {};
            WTF::Optional<WTF::Vector<uint8_t>> p_data {};
            Device_ControlTransferIn_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadStatus(&p_status))
                success = false;
            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::ControlTransferIn response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_status),
                    std::move(p_data));
            }
            return true;
        }

        class Device_ControlTransferOut_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_ControlTransferOut_ForwardToCallback(
                const Device::ControlTransferOutCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::ControlTransferOutCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_ControlTransferOut_ForwardToCallback);
        };
        bool Device_ControlTransferOut_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_ControlTransferOut_ResponseParams_Data* params = reinterpret_cast<internal::Device_ControlTransferOut_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TransferStatus p_status {};
            Device_ControlTransferOut_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadStatus(&p_status))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::ControlTransferOut response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_status));
            }
            return true;
        }

        class Device_GenericTransferIn_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_GenericTransferIn_ForwardToCallback(
                const Device::GenericTransferInCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::GenericTransferInCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_GenericTransferIn_ForwardToCallback);
        };
        bool Device_GenericTransferIn_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_GenericTransferIn_ResponseParams_Data* params = reinterpret_cast<internal::Device_GenericTransferIn_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TransferStatus p_status {};
            WTF::Optional<WTF::Vector<uint8_t>> p_data {};
            Device_GenericTransferIn_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadStatus(&p_status))
                success = false;
            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::GenericTransferIn response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_status),
                    std::move(p_data));
            }
            return true;
        }

        class Device_GenericTransferOut_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_GenericTransferOut_ForwardToCallback(
                const Device::GenericTransferOutCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::GenericTransferOutCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_GenericTransferOut_ForwardToCallback);
        };
        bool Device_GenericTransferOut_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_GenericTransferOut_ResponseParams_Data* params = reinterpret_cast<internal::Device_GenericTransferOut_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            TransferStatus p_status {};
            Device_GenericTransferOut_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadStatus(&p_status))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::GenericTransferOut response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_status));
            }
            return true;
        }

        class Device_IsochronousTransferIn_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_IsochronousTransferIn_ForwardToCallback(
                const Device::IsochronousTransferInCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::IsochronousTransferInCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_IsochronousTransferIn_ForwardToCallback);
        };
        bool Device_IsochronousTransferIn_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_IsochronousTransferIn_ResponseParams_Data* params = reinterpret_cast<internal::Device_IsochronousTransferIn_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WTF::Optional<WTF::Vector<uint8_t>> p_data {};
            WTF::Vector<IsochronousPacketPtr> p_packets {};
            Device_IsochronousTransferIn_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!input_data_view.ReadPackets(&p_packets))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::IsochronousTransferIn response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_data),
                    std::move(p_packets));
            }
            return true;
        }

        class Device_IsochronousTransferOut_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Device_IsochronousTransferOut_ForwardToCallback(
                const Device::IsochronousTransferOutCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Device::IsochronousTransferOutCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Device_IsochronousTransferOut_ForwardToCallback);
        };
        bool Device_IsochronousTransferOut_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Device_IsochronousTransferOut_ResponseParams_Data* params = reinterpret_cast<internal::Device_IsochronousTransferOut_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WTF::Vector<IsochronousPacketPtr> p_packets {};
            Device_IsochronousTransferOut_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadPackets(&p_packets))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::IsochronousTransferOut response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_packets));
            }
            return true;
        }

        DeviceProxy::DeviceProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void DeviceProxy::GetDeviceInfo(
            const GetDeviceInfoCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_GetDeviceInfo_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_GetDeviceInfo_Name, size);

            auto params = ::device::usb::internal::Device_GetDeviceInfo_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_GetDeviceInfo_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::Open(
            const OpenCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_Open_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_Open_Name, size);

            auto params = ::device::usb::internal::Device_Open_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_Open_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::Close(
            const CloseCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_Close_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_Close_Name, size);

            auto params = ::device::usb::internal::Device_Close_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_Close_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::SetConfiguration(
            uint8_t in_value, const SetConfigurationCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_SetConfiguration_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_SetConfiguration_Name, size);

            auto params = ::device::usb::internal::Device_SetConfiguration_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->value = in_value;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_SetConfiguration_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::ClaimInterface(
            uint8_t in_interface_number, const ClaimInterfaceCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_ClaimInterface_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_ClaimInterface_Name, size);

            auto params = ::device::usb::internal::Device_ClaimInterface_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->interface_number = in_interface_number;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_ClaimInterface_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::ReleaseInterface(
            uint8_t in_interface_number, const ReleaseInterfaceCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_ReleaseInterface_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_ReleaseInterface_Name, size);

            auto params = ::device::usb::internal::Device_ReleaseInterface_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->interface_number = in_interface_number;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_ReleaseInterface_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::SetInterfaceAlternateSetting(
            uint8_t in_interface_number, uint8_t in_alternate_setting, const SetInterfaceAlternateSettingCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_SetInterfaceAlternateSetting_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_SetInterfaceAlternateSetting_Name, size);

            auto params = ::device::usb::internal::Device_SetInterfaceAlternateSetting_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->interface_number = in_interface_number;
            params->alternate_setting = in_alternate_setting;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_SetInterfaceAlternateSetting_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::Reset(
            const ResetCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_Reset_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_Reset_Name, size);

            auto params = ::device::usb::internal::Device_Reset_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_Reset_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::ClearHalt(
            uint8_t in_endpoint, const ClearHaltCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_ClearHalt_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_ClearHalt_Name, size);

            auto params = ::device::usb::internal::Device_ClearHalt_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->endpoint = in_endpoint;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_ClearHalt_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::ControlTransferIn(
            ControlTransferParamsPtr in_params, uint32_t in_length, uint32_t in_timeout, const ControlTransferInCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_ControlTransferIn_Params_Data);
            size += mojo::internal::PrepareToSerialize<::device::usb::ControlTransferParamsDataView>(
                in_params, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_ControlTransferIn_Name, size);

            auto params = ::device::usb::internal::Device_ControlTransferIn_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->params)::BaseType* params_ptr;
            mojo::internal::Serialize<::device::usb::ControlTransferParamsDataView>(
                in_params, builder.buffer(), &params_ptr, &serialization_context);
            params->params.Set(params_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->params.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null params in Device.ControlTransferIn request");
            params->length = in_length;
            params->timeout = in_timeout;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_ControlTransferIn_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::ControlTransferOut(
            ControlTransferParamsPtr in_params, const WTF::Vector<uint8_t>& in_data, uint32_t in_timeout, const ControlTransferOutCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_ControlTransferOut_Params_Data);
            size += mojo::internal::PrepareToSerialize<::device::usb::ControlTransferParamsDataView>(
                in_params, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_ControlTransferOut_Name, size);

            auto params = ::device::usb::internal::Device_ControlTransferOut_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->params)::BaseType* params_ptr;
            mojo::internal::Serialize<::device::usb::ControlTransferParamsDataView>(
                in_params, builder.buffer(), &params_ptr, &serialization_context);
            params->params.Set(params_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->params.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null params in Device.ControlTransferOut request");
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
                "null data in Device.ControlTransferOut request");
            params->timeout = in_timeout;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_ControlTransferOut_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::GenericTransferIn(
            uint8_t in_endpoint_number, uint32_t in_length, uint32_t in_timeout, const GenericTransferInCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_GenericTransferIn_Params_Data);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_GenericTransferIn_Name, size);

            auto params = ::device::usb::internal::Device_GenericTransferIn_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->endpoint_number = in_endpoint_number;
            params->length = in_length;
            params->timeout = in_timeout;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_GenericTransferIn_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::GenericTransferOut(
            uint8_t in_endpoint_number, const WTF::Vector<uint8_t>& in_data, uint32_t in_timeout, const GenericTransferOutCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_GenericTransferOut_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_GenericTransferOut_Name, size);

            auto params = ::device::usb::internal::Device_GenericTransferOut_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->endpoint_number = in_endpoint_number;
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
                "null data in Device.GenericTransferOut request");
            params->timeout = in_timeout;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_GenericTransferOut_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::IsochronousTransferIn(
            uint8_t in_endpoint_number, const WTF::Vector<uint32_t>& in_packet_lengths, uint32_t in_timeout, const IsochronousTransferInCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_IsochronousTransferIn_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint32_t>>(
                in_packet_lengths, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_IsochronousTransferIn_Name, size);

            auto params = ::device::usb::internal::Device_IsochronousTransferIn_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->endpoint_number = in_endpoint_number;
            typename decltype(params->packet_lengths)::BaseType* packet_lengths_ptr;
            const mojo::internal::ContainerValidateParams packet_lengths_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint32_t>>(
                in_packet_lengths, builder.buffer(), &packet_lengths_ptr, &packet_lengths_validate_params,
                &serialization_context);
            params->packet_lengths.Set(packet_lengths_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->packet_lengths.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null packet_lengths in Device.IsochronousTransferIn request");
            params->timeout = in_timeout;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_IsochronousTransferIn_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void DeviceProxy::IsochronousTransferOut(
            uint8_t in_endpoint_number, const WTF::Vector<uint8_t>& in_data, const WTF::Vector<uint32_t>& in_packet_lengths, uint32_t in_timeout, const IsochronousTransferOutCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::Device_IsochronousTransferOut_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint32_t>>(
                in_packet_lengths, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kDevice_IsochronousTransferOut_Name, size);

            auto params = ::device::usb::internal::Device_IsochronousTransferOut_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->endpoint_number = in_endpoint_number;
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
                "null data in Device.IsochronousTransferOut request");
            typename decltype(params->packet_lengths)::BaseType* packet_lengths_ptr;
            const mojo::internal::ContainerValidateParams packet_lengths_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint32_t>>(
                in_packet_lengths, builder.buffer(), &packet_lengths_ptr, &packet_lengths_validate_params,
                &serialization_context);
            params->packet_lengths.Set(packet_lengths_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->packet_lengths.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null packet_lengths in Device.IsochronousTransferOut request");
            params->timeout = in_timeout;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Device_IsochronousTransferOut_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }
        class Device_GetDeviceInfo_ProxyToResponder {
        public:
            static Device::GetDeviceInfoCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_GetDeviceInfo_ProxyToResponder> proxy(
                    new Device_GetDeviceInfo_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_GetDeviceInfo_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_GetDeviceInfo_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::GetDeviceInfo() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_GetDeviceInfo_ProxyToResponder(
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
                DeviceInfoPtr in_info);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_GetDeviceInfo_ProxyToResponder);
        };

        void Device_GetDeviceInfo_ProxyToResponder::Run(
            DeviceInfoPtr in_info)
        {
            size_t size = sizeof(::device::usb::internal::Device_GetDeviceInfo_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<::device::usb::DeviceInfoDataView>(
                in_info, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_GetDeviceInfo_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_GetDeviceInfo_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->info)::BaseType* info_ptr;
            mojo::internal::Serialize<::device::usb::DeviceInfoDataView>(
                in_info, builder.buffer(), &info_ptr, &serialization_context_);
            params->info.Set(info_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_Open_ProxyToResponder {
        public:
            static Device::OpenCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_Open_ProxyToResponder> proxy(
                    new Device_Open_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_Open_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_Open_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::Open() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_Open_ProxyToResponder(
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
                OpenDeviceError in_error);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_Open_ProxyToResponder);
        };

        void Device_Open_ProxyToResponder::Run(
            OpenDeviceError in_error)
        {
            size_t size = sizeof(::device::usb::internal::Device_Open_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_Open_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_Open_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::device::usb::OpenDeviceError>(
                in_error, &params->error);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_Close_ProxyToResponder {
        public:
            static Device::CloseCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_Close_ProxyToResponder> proxy(
                    new Device_Close_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_Close_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_Close_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::Close() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_Close_ProxyToResponder(
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

            DISALLOW_COPY_AND_ASSIGN(Device_Close_ProxyToResponder);
        };

        void Device_Close_ProxyToResponder::Run()
        {
            size_t size = sizeof(::device::usb::internal::Device_Close_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_Close_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_Close_ResponseParams_Data::New(builder.buffer());
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
        class Device_SetConfiguration_ProxyToResponder {
        public:
            static Device::SetConfigurationCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_SetConfiguration_ProxyToResponder> proxy(
                    new Device_SetConfiguration_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_SetConfiguration_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_SetConfiguration_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::SetConfiguration() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_SetConfiguration_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_SetConfiguration_ProxyToResponder);
        };

        void Device_SetConfiguration_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::usb::internal::Device_SetConfiguration_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_SetConfiguration_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_SetConfiguration_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_ClaimInterface_ProxyToResponder {
        public:
            static Device::ClaimInterfaceCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_ClaimInterface_ProxyToResponder> proxy(
                    new Device_ClaimInterface_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_ClaimInterface_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_ClaimInterface_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::ClaimInterface() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_ClaimInterface_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_ClaimInterface_ProxyToResponder);
        };

        void Device_ClaimInterface_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::usb::internal::Device_ClaimInterface_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_ClaimInterface_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_ClaimInterface_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_ReleaseInterface_ProxyToResponder {
        public:
            static Device::ReleaseInterfaceCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_ReleaseInterface_ProxyToResponder> proxy(
                    new Device_ReleaseInterface_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_ReleaseInterface_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_ReleaseInterface_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::ReleaseInterface() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_ReleaseInterface_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_ReleaseInterface_ProxyToResponder);
        };

        void Device_ReleaseInterface_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::usb::internal::Device_ReleaseInterface_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_ReleaseInterface_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_ReleaseInterface_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_SetInterfaceAlternateSetting_ProxyToResponder {
        public:
            static Device::SetInterfaceAlternateSettingCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_SetInterfaceAlternateSetting_ProxyToResponder> proxy(
                    new Device_SetInterfaceAlternateSetting_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_SetInterfaceAlternateSetting_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_SetInterfaceAlternateSetting_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::SetInterfaceAlternateSetting() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_SetInterfaceAlternateSetting_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_SetInterfaceAlternateSetting_ProxyToResponder);
        };

        void Device_SetInterfaceAlternateSetting_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::usb::internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_SetInterfaceAlternateSetting_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_Reset_ProxyToResponder {
        public:
            static Device::ResetCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_Reset_ProxyToResponder> proxy(
                    new Device_Reset_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_Reset_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_Reset_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::Reset() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_Reset_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_Reset_ProxyToResponder);
        };

        void Device_Reset_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::usb::internal::Device_Reset_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_Reset_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_Reset_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_ClearHalt_ProxyToResponder {
        public:
            static Device::ClearHaltCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_ClearHalt_ProxyToResponder> proxy(
                    new Device_ClearHalt_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_ClearHalt_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_ClearHalt_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::ClearHalt() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_ClearHalt_ProxyToResponder(
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
                bool in_success);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_ClearHalt_ProxyToResponder);
        };

        void Device_ClearHalt_ProxyToResponder::Run(
            bool in_success)
        {
            size_t size = sizeof(::device::usb::internal::Device_ClearHalt_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_ClearHalt_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_ClearHalt_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->success = in_success;
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_ControlTransferIn_ProxyToResponder {
        public:
            static Device::ControlTransferInCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_ControlTransferIn_ProxyToResponder> proxy(
                    new Device_ControlTransferIn_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_ControlTransferIn_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_ControlTransferIn_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::ControlTransferIn() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_ControlTransferIn_ProxyToResponder(
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
                TransferStatus in_status, const WTF::Optional<WTF::Vector<uint8_t>>& in_data);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_ControlTransferIn_ProxyToResponder);
        };

        void Device_ControlTransferIn_ProxyToResponder::Run(
            TransferStatus in_status, const WTF::Optional<WTF::Vector<uint8_t>>& in_data)
        {
            size_t size = sizeof(::device::usb::internal::Device_ControlTransferIn_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_ControlTransferIn_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_ControlTransferIn_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::device::usb::TransferStatus>(
                in_status, &params->status);
            typename decltype(params->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, builder.buffer(), &data_ptr, &data_validate_params,
                &serialization_context_);
            params->data.Set(data_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_ControlTransferOut_ProxyToResponder {
        public:
            static Device::ControlTransferOutCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_ControlTransferOut_ProxyToResponder> proxy(
                    new Device_ControlTransferOut_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_ControlTransferOut_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_ControlTransferOut_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::ControlTransferOut() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_ControlTransferOut_ProxyToResponder(
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
                TransferStatus in_status);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_ControlTransferOut_ProxyToResponder);
        };

        void Device_ControlTransferOut_ProxyToResponder::Run(
            TransferStatus in_status)
        {
            size_t size = sizeof(::device::usb::internal::Device_ControlTransferOut_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_ControlTransferOut_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_ControlTransferOut_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::device::usb::TransferStatus>(
                in_status, &params->status);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_GenericTransferIn_ProxyToResponder {
        public:
            static Device::GenericTransferInCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_GenericTransferIn_ProxyToResponder> proxy(
                    new Device_GenericTransferIn_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_GenericTransferIn_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_GenericTransferIn_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::GenericTransferIn() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_GenericTransferIn_ProxyToResponder(
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
                TransferStatus in_status, const WTF::Optional<WTF::Vector<uint8_t>>& in_data);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_GenericTransferIn_ProxyToResponder);
        };

        void Device_GenericTransferIn_ProxyToResponder::Run(
            TransferStatus in_status, const WTF::Optional<WTF::Vector<uint8_t>>& in_data)
        {
            size_t size = sizeof(::device::usb::internal::Device_GenericTransferIn_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_GenericTransferIn_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_GenericTransferIn_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::device::usb::TransferStatus>(
                in_status, &params->status);
            typename decltype(params->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, builder.buffer(), &data_ptr, &data_validate_params,
                &serialization_context_);
            params->data.Set(data_ptr);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_GenericTransferOut_ProxyToResponder {
        public:
            static Device::GenericTransferOutCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_GenericTransferOut_ProxyToResponder> proxy(
                    new Device_GenericTransferOut_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_GenericTransferOut_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_GenericTransferOut_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::GenericTransferOut() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_GenericTransferOut_ProxyToResponder(
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
                TransferStatus in_status);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_GenericTransferOut_ProxyToResponder);
        };

        void Device_GenericTransferOut_ProxyToResponder::Run(
            TransferStatus in_status)
        {
            size_t size = sizeof(::device::usb::internal::Device_GenericTransferOut_ResponseParams_Data);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_GenericTransferOut_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_GenericTransferOut_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::device::usb::TransferStatus>(
                in_status, &params->status);
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_IsochronousTransferIn_ProxyToResponder {
        public:
            static Device::IsochronousTransferInCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_IsochronousTransferIn_ProxyToResponder> proxy(
                    new Device_IsochronousTransferIn_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_IsochronousTransferIn_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_IsochronousTransferIn_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::IsochronousTransferIn() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_IsochronousTransferIn_ProxyToResponder(
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
                const WTF::Optional<WTF::Vector<uint8_t>>& in_data, WTF::Vector<IsochronousPacketPtr> in_packets);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_IsochronousTransferIn_ProxyToResponder);
        };

        void Device_IsochronousTransferIn_ProxyToResponder::Run(
            const WTF::Optional<WTF::Vector<uint8_t>>& in_data, WTF::Vector<IsochronousPacketPtr> in_packets)
        {
            size_t size = sizeof(::device::usb::internal::Device_IsochronousTransferIn_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context_);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::IsochronousPacketDataView>>(
                in_packets, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_IsochronousTransferIn_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_IsochronousTransferIn_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, builder.buffer(), &data_ptr, &data_validate_params,
                &serialization_context_);
            params->data.Set(data_ptr);
            typename decltype(params->packets)::BaseType* packets_ptr;
            const mojo::internal::ContainerValidateParams packets_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::IsochronousPacketDataView>>(
                in_packets, builder.buffer(), &packets_ptr, &packets_validate_params,
                &serialization_context_);
            params->packets.Set(packets_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->packets.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null packets in Device.IsochronousTransferIn response");
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Device_IsochronousTransferOut_ProxyToResponder {
        public:
            static Device::IsochronousTransferOutCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Device_IsochronousTransferOut_ProxyToResponder> proxy(
                    new Device_IsochronousTransferOut_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Device_IsochronousTransferOut_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Device_IsochronousTransferOut_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Device::IsochronousTransferOut() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Device_IsochronousTransferOut_ProxyToResponder(
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
                WTF::Vector<IsochronousPacketPtr> in_packets);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Device_IsochronousTransferOut_ProxyToResponder);
        };

        void Device_IsochronousTransferOut_ProxyToResponder::Run(
            WTF::Vector<IsochronousPacketPtr> in_packets)
        {
            size_t size = sizeof(::device::usb::internal::Device_IsochronousTransferOut_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::IsochronousPacketDataView>>(
                in_packets, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kDevice_IsochronousTransferOut_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::Device_IsochronousTransferOut_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->packets)::BaseType* packets_ptr;
            const mojo::internal::ContainerValidateParams packets_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::IsochronousPacketDataView>>(
                in_packets, builder.buffer(), &packets_ptr, &packets_validate_params,
                &serialization_context_);
            params->packets.Set(packets_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->packets.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null packets in Device.IsochronousTransferOut response");
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
        bool DeviceStubDispatch::Accept(
            Device* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kDevice_GetDeviceInfo_Name: {
                break;
            }
            case internal::kDevice_Open_Name: {
                break;
            }
            case internal::kDevice_Close_Name: {
                break;
            }
            case internal::kDevice_SetConfiguration_Name: {
                break;
            }
            case internal::kDevice_ClaimInterface_Name: {
                break;
            }
            case internal::kDevice_ReleaseInterface_Name: {
                break;
            }
            case internal::kDevice_SetInterfaceAlternateSetting_Name: {
                break;
            }
            case internal::kDevice_Reset_Name: {
                break;
            }
            case internal::kDevice_ClearHalt_Name: {
                break;
            }
            case internal::kDevice_ControlTransferIn_Name: {
                break;
            }
            case internal::kDevice_ControlTransferOut_Name: {
                break;
            }
            case internal::kDevice_GenericTransferIn_Name: {
                break;
            }
            case internal::kDevice_GenericTransferOut_Name: {
                break;
            }
            case internal::kDevice_IsochronousTransferIn_Name: {
                break;
            }
            case internal::kDevice_IsochronousTransferOut_Name: {
                break;
            }
            }
            return false;
        }

        // static
        bool DeviceStubDispatch::AcceptWithResponder(
            Device* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kDevice_GetDeviceInfo_Name: {
                internal::Device_GetDeviceInfo_Params_Data* params = reinterpret_cast<internal::Device_GetDeviceInfo_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Device_GetDeviceInfo_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::GetDeviceInfo deserializer");
                    return false;
                }
                Device::GetDeviceInfoCallback callback = Device_GetDeviceInfo_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::GetDeviceInfo");
                mojo::internal::MessageDispatchContext context(message);
                impl->GetDeviceInfo(std::move(callback));
                return true;
            }
            case internal::kDevice_Open_Name: {
                internal::Device_Open_Params_Data* params = reinterpret_cast<internal::Device_Open_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Device_Open_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::Open deserializer");
                    return false;
                }
                Device::OpenCallback callback = Device_Open_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::Open");
                mojo::internal::MessageDispatchContext context(message);
                impl->Open(std::move(callback));
                return true;
            }
            case internal::kDevice_Close_Name: {
                internal::Device_Close_Params_Data* params = reinterpret_cast<internal::Device_Close_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Device_Close_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::Close deserializer");
                    return false;
                }
                Device::CloseCallback callback = Device_Close_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::Close");
                mojo::internal::MessageDispatchContext context(message);
                impl->Close(std::move(callback));
                return true;
            }
            case internal::kDevice_SetConfiguration_Name: {
                internal::Device_SetConfiguration_Params_Data* params = reinterpret_cast<internal::Device_SetConfiguration_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_value {};
                Device_SetConfiguration_ParamsDataView input_data_view(params,
                    context);

                p_value = input_data_view.value();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::SetConfiguration deserializer");
                    return false;
                }
                Device::SetConfigurationCallback callback = Device_SetConfiguration_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::SetConfiguration");
                mojo::internal::MessageDispatchContext context(message);
                impl->SetConfiguration(
                    std::move(p_value), std::move(callback));
                return true;
            }
            case internal::kDevice_ClaimInterface_Name: {
                internal::Device_ClaimInterface_Params_Data* params = reinterpret_cast<internal::Device_ClaimInterface_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_interface_number {};
                Device_ClaimInterface_ParamsDataView input_data_view(params,
                    context);

                p_interface_number = input_data_view.interface_number();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::ClaimInterface deserializer");
                    return false;
                }
                Device::ClaimInterfaceCallback callback = Device_ClaimInterface_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::ClaimInterface");
                mojo::internal::MessageDispatchContext context(message);
                impl->ClaimInterface(
                    std::move(p_interface_number), std::move(callback));
                return true;
            }
            case internal::kDevice_ReleaseInterface_Name: {
                internal::Device_ReleaseInterface_Params_Data* params = reinterpret_cast<internal::Device_ReleaseInterface_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_interface_number {};
                Device_ReleaseInterface_ParamsDataView input_data_view(params,
                    context);

                p_interface_number = input_data_view.interface_number();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::ReleaseInterface deserializer");
                    return false;
                }
                Device::ReleaseInterfaceCallback callback = Device_ReleaseInterface_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::ReleaseInterface");
                mojo::internal::MessageDispatchContext context(message);
                impl->ReleaseInterface(
                    std::move(p_interface_number), std::move(callback));
                return true;
            }
            case internal::kDevice_SetInterfaceAlternateSetting_Name: {
                internal::Device_SetInterfaceAlternateSetting_Params_Data* params = reinterpret_cast<internal::Device_SetInterfaceAlternateSetting_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_interface_number {};
                uint8_t p_alternate_setting {};
                Device_SetInterfaceAlternateSetting_ParamsDataView input_data_view(params,
                    context);

                p_interface_number = input_data_view.interface_number();
                p_alternate_setting = input_data_view.alternate_setting();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::SetInterfaceAlternateSetting deserializer");
                    return false;
                }
                Device::SetInterfaceAlternateSettingCallback callback = Device_SetInterfaceAlternateSetting_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::SetInterfaceAlternateSetting");
                mojo::internal::MessageDispatchContext context(message);
                impl->SetInterfaceAlternateSetting(
                    std::move(p_interface_number),
                    std::move(p_alternate_setting), std::move(callback));
                return true;
            }
            case internal::kDevice_Reset_Name: {
                internal::Device_Reset_Params_Data* params = reinterpret_cast<internal::Device_Reset_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                Device_Reset_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::Reset deserializer");
                    return false;
                }
                Device::ResetCallback callback = Device_Reset_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::Reset");
                mojo::internal::MessageDispatchContext context(message);
                impl->Reset(std::move(callback));
                return true;
            }
            case internal::kDevice_ClearHalt_Name: {
                internal::Device_ClearHalt_Params_Data* params = reinterpret_cast<internal::Device_ClearHalt_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_endpoint {};
                Device_ClearHalt_ParamsDataView input_data_view(params,
                    context);

                p_endpoint = input_data_view.endpoint();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::ClearHalt deserializer");
                    return false;
                }
                Device::ClearHaltCallback callback = Device_ClearHalt_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::ClearHalt");
                mojo::internal::MessageDispatchContext context(message);
                impl->ClearHalt(
                    std::move(p_endpoint), std::move(callback));
                return true;
            }
            case internal::kDevice_ControlTransferIn_Name: {
                internal::Device_ControlTransferIn_Params_Data* params = reinterpret_cast<internal::Device_ControlTransferIn_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                ControlTransferParamsPtr p_params {};
                uint32_t p_length {};
                uint32_t p_timeout {};
                Device_ControlTransferIn_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadParams(&p_params))
                    success = false;
                p_length = input_data_view.length();
                p_timeout = input_data_view.timeout();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::ControlTransferIn deserializer");
                    return false;
                }
                Device::ControlTransferInCallback callback = Device_ControlTransferIn_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::ControlTransferIn");
                mojo::internal::MessageDispatchContext context(message);
                impl->ControlTransferIn(
                    std::move(p_params),
                    std::move(p_length),
                    std::move(p_timeout), std::move(callback));
                return true;
            }
            case internal::kDevice_ControlTransferOut_Name: {
                internal::Device_ControlTransferOut_Params_Data* params = reinterpret_cast<internal::Device_ControlTransferOut_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                ControlTransferParamsPtr p_params {};
                WTF::Vector<uint8_t> p_data {};
                uint32_t p_timeout {};
                Device_ControlTransferOut_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadParams(&p_params))
                    success = false;
                if (!input_data_view.ReadData(&p_data))
                    success = false;
                p_timeout = input_data_view.timeout();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::ControlTransferOut deserializer");
                    return false;
                }
                Device::ControlTransferOutCallback callback = Device_ControlTransferOut_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::ControlTransferOut");
                mojo::internal::MessageDispatchContext context(message);
                impl->ControlTransferOut(
                    std::move(p_params),
                    std::move(p_data),
                    std::move(p_timeout), std::move(callback));
                return true;
            }
            case internal::kDevice_GenericTransferIn_Name: {
                internal::Device_GenericTransferIn_Params_Data* params = reinterpret_cast<internal::Device_GenericTransferIn_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_endpoint_number {};
                uint32_t p_length {};
                uint32_t p_timeout {};
                Device_GenericTransferIn_ParamsDataView input_data_view(params,
                    context);

                p_endpoint_number = input_data_view.endpoint_number();
                p_length = input_data_view.length();
                p_timeout = input_data_view.timeout();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::GenericTransferIn deserializer");
                    return false;
                }
                Device::GenericTransferInCallback callback = Device_GenericTransferIn_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::GenericTransferIn");
                mojo::internal::MessageDispatchContext context(message);
                impl->GenericTransferIn(
                    std::move(p_endpoint_number),
                    std::move(p_length),
                    std::move(p_timeout), std::move(callback));
                return true;
            }
            case internal::kDevice_GenericTransferOut_Name: {
                internal::Device_GenericTransferOut_Params_Data* params = reinterpret_cast<internal::Device_GenericTransferOut_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_endpoint_number {};
                WTF::Vector<uint8_t> p_data {};
                uint32_t p_timeout {};
                Device_GenericTransferOut_ParamsDataView input_data_view(params,
                    context);

                p_endpoint_number = input_data_view.endpoint_number();
                if (!input_data_view.ReadData(&p_data))
                    success = false;
                p_timeout = input_data_view.timeout();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::GenericTransferOut deserializer");
                    return false;
                }
                Device::GenericTransferOutCallback callback = Device_GenericTransferOut_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::GenericTransferOut");
                mojo::internal::MessageDispatchContext context(message);
                impl->GenericTransferOut(
                    std::move(p_endpoint_number),
                    std::move(p_data),
                    std::move(p_timeout), std::move(callback));
                return true;
            }
            case internal::kDevice_IsochronousTransferIn_Name: {
                internal::Device_IsochronousTransferIn_Params_Data* params = reinterpret_cast<internal::Device_IsochronousTransferIn_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_endpoint_number {};
                WTF::Vector<uint32_t> p_packet_lengths {};
                uint32_t p_timeout {};
                Device_IsochronousTransferIn_ParamsDataView input_data_view(params,
                    context);

                p_endpoint_number = input_data_view.endpoint_number();
                if (!input_data_view.ReadPacketLengths(&p_packet_lengths))
                    success = false;
                p_timeout = input_data_view.timeout();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::IsochronousTransferIn deserializer");
                    return false;
                }
                Device::IsochronousTransferInCallback callback = Device_IsochronousTransferIn_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::IsochronousTransferIn");
                mojo::internal::MessageDispatchContext context(message);
                impl->IsochronousTransferIn(
                    std::move(p_endpoint_number),
                    std::move(p_packet_lengths),
                    std::move(p_timeout), std::move(callback));
                return true;
            }
            case internal::kDevice_IsochronousTransferOut_Name: {
                internal::Device_IsochronousTransferOut_Params_Data* params = reinterpret_cast<internal::Device_IsochronousTransferOut_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint8_t p_endpoint_number {};
                WTF::Vector<uint8_t> p_data {};
                WTF::Vector<uint32_t> p_packet_lengths {};
                uint32_t p_timeout {};
                Device_IsochronousTransferOut_ParamsDataView input_data_view(params,
                    context);

                p_endpoint_number = input_data_view.endpoint_number();
                if (!input_data_view.ReadData(&p_data))
                    success = false;
                if (!input_data_view.ReadPacketLengths(&p_packet_lengths))
                    success = false;
                p_timeout = input_data_view.timeout();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Device::IsochronousTransferOut deserializer");
                    return false;
                }
                Device::IsochronousTransferOutCallback callback = Device_IsochronousTransferOut_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Device::IsochronousTransferOut");
                mojo::internal::MessageDispatchContext context(message);
                impl->IsochronousTransferOut(
                    std::move(p_endpoint_number),
                    std::move(p_data),
                    std::move(p_packet_lengths),
                    std::move(p_timeout), std::move(callback));
                return true;
            }
            }
            return false;
        }

        bool DeviceRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Device RequestValidator");

            switch (message->header()->name) {
            case internal::kDevice_GetDeviceInfo_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_GetDeviceInfo_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_Open_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_Open_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_Close_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_Close_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_SetConfiguration_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_SetConfiguration_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ClaimInterface_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ClaimInterface_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ReleaseInterface_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ReleaseInterface_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_SetInterfaceAlternateSetting_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_SetInterfaceAlternateSetting_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_Reset_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_Reset_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ClearHalt_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ClearHalt_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ControlTransferIn_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ControlTransferIn_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ControlTransferOut_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ControlTransferOut_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_GenericTransferIn_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_GenericTransferIn_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_GenericTransferOut_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_GenericTransferOut_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_IsochronousTransferIn_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_IsochronousTransferIn_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_IsochronousTransferOut_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_IsochronousTransferOut_Params_Data>(
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

        bool DeviceResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Device ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kDevice_GetDeviceInfo_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_GetDeviceInfo_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_Open_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_Open_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_Close_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_Close_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_SetConfiguration_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_SetConfiguration_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ClaimInterface_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ClaimInterface_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ReleaseInterface_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ReleaseInterface_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_SetInterfaceAlternateSetting_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_Reset_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_Reset_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ClearHalt_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ClearHalt_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ControlTransferIn_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ControlTransferIn_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_ControlTransferOut_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_ControlTransferOut_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_GenericTransferIn_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_GenericTransferIn_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_GenericTransferOut_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_GenericTransferOut_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_IsochronousTransferIn_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_IsochronousTransferIn_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kDevice_IsochronousTransferOut_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Device_IsochronousTransferOut_ResponseParams_Data>(
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
} // namespace usb
} // namespace device

namespace mojo {

// static
bool StructTraits<::device::usb::blink::EndpointInfo::DataView, ::device::usb::blink::EndpointInfoPtr>::Read(
    ::device::usb::blink::EndpointInfo::DataView input,
    ::device::usb::blink::EndpointInfoPtr* output)
{
    bool success = true;
    ::device::usb::blink::EndpointInfoPtr result(::device::usb::blink::EndpointInfo::New());

    result->endpoint_number = input.endpoint_number();
    if (!input.ReadDirection(&result->direction))
        success = false;
    if (!input.ReadType(&result->type))
        success = false;
    result->packet_size = input.packet_size();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::blink::AlternateInterfaceInfo::DataView, ::device::usb::blink::AlternateInterfaceInfoPtr>::Read(
    ::device::usb::blink::AlternateInterfaceInfo::DataView input,
    ::device::usb::blink::AlternateInterfaceInfoPtr* output)
{
    bool success = true;
    ::device::usb::blink::AlternateInterfaceInfoPtr result(::device::usb::blink::AlternateInterfaceInfo::New());

    result->alternate_setting = input.alternate_setting();
    result->class_code = input.class_code();
    result->subclass_code = input.subclass_code();
    result->protocol_code = input.protocol_code();
    if (!input.ReadInterfaceName(&result->interface_name))
        success = false;
    if (!input.ReadEndpoints(&result->endpoints))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::blink::InterfaceInfo::DataView, ::device::usb::blink::InterfaceInfoPtr>::Read(
    ::device::usb::blink::InterfaceInfo::DataView input,
    ::device::usb::blink::InterfaceInfoPtr* output)
{
    bool success = true;
    ::device::usb::blink::InterfaceInfoPtr result(::device::usb::blink::InterfaceInfo::New());

    result->interface_number = input.interface_number();
    if (!input.ReadAlternates(&result->alternates))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::blink::ConfigurationInfo::DataView, ::device::usb::blink::ConfigurationInfoPtr>::Read(
    ::device::usb::blink::ConfigurationInfo::DataView input,
    ::device::usb::blink::ConfigurationInfoPtr* output)
{
    bool success = true;
    ::device::usb::blink::ConfigurationInfoPtr result(::device::usb::blink::ConfigurationInfo::New());

    result->configuration_value = input.configuration_value();
    if (!input.ReadConfigurationName(&result->configuration_name))
        success = false;
    if (!input.ReadInterfaces(&result->interfaces))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::blink::DeviceInfo::DataView, ::device::usb::blink::DeviceInfoPtr>::Read(
    ::device::usb::blink::DeviceInfo::DataView input,
    ::device::usb::blink::DeviceInfoPtr* output)
{
    bool success = true;
    ::device::usb::blink::DeviceInfoPtr result(::device::usb::blink::DeviceInfo::New());

    if (!input.ReadGuid(&result->guid))
        success = false;
    result->usb_version_major = input.usb_version_major();
    result->usb_version_minor = input.usb_version_minor();
    result->usb_version_subminor = input.usb_version_subminor();
    result->class_code = input.class_code();
    result->subclass_code = input.subclass_code();
    result->protocol_code = input.protocol_code();
    result->vendor_id = input.vendor_id();
    result->product_id = input.product_id();
    result->device_version_major = input.device_version_major();
    result->device_version_minor = input.device_version_minor();
    result->device_version_subminor = input.device_version_subminor();
    if (!input.ReadManufacturerName(&result->manufacturer_name))
        success = false;
    if (!input.ReadProductName(&result->product_name))
        success = false;
    if (!input.ReadSerialNumber(&result->serial_number))
        success = false;
    result->active_configuration = input.active_configuration();
    if (!input.ReadConfigurations(&result->configurations))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::blink::ControlTransferParams::DataView, ::device::usb::blink::ControlTransferParamsPtr>::Read(
    ::device::usb::blink::ControlTransferParams::DataView input,
    ::device::usb::blink::ControlTransferParamsPtr* output)
{
    bool success = true;
    ::device::usb::blink::ControlTransferParamsPtr result(::device::usb::blink::ControlTransferParams::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadRecipient(&result->recipient))
        success = false;
    result->request = input.request();
    result->value = input.value();
    result->index = input.index();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::usb::blink::IsochronousPacket::DataView, ::device::usb::blink::IsochronousPacketPtr>::Read(
    ::device::usb::blink::IsochronousPacket::DataView input,
    ::device::usb::blink::IsochronousPacketPtr* output)
{
    bool success = true;
    ::device::usb::blink::IsochronousPacketPtr result(::device::usb::blink::IsochronousPacket::New());

    result->length = input.length();
    result->transferred_length = input.transferred_length();
    if (!input.ReadStatus(&result->status))
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