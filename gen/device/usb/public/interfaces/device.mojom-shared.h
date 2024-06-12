// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_H_
#define DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/usb/public/interfaces/device.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace device {
namespace usb {
    class EndpointInfoDataView;

    class AlternateInterfaceInfoDataView;

    class InterfaceInfoDataView;

    class ConfigurationInfoDataView;

    class DeviceInfoDataView;

    class ControlTransferParamsDataView;

    class IsochronousPacketDataView;

} // namespace usb
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::usb::EndpointInfoDataView> {
        using Data = ::device::usb::internal::EndpointInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::AlternateInterfaceInfoDataView> {
        using Data = ::device::usb::internal::AlternateInterfaceInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::InterfaceInfoDataView> {
        using Data = ::device::usb::internal::InterfaceInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::ConfigurationInfoDataView> {
        using Data = ::device::usb::internal::ConfigurationInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::DeviceInfoDataView> {
        using Data = ::device::usb::internal::DeviceInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::ControlTransferParamsDataView> {
        using Data = ::device::usb::internal::ControlTransferParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::IsochronousPacketDataView> {
        using Data = ::device::usb::internal::IsochronousPacket_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace usb {

    enum class OpenDeviceError : int32_t {
        OK,
        ACCESS_DENIED,
        ALREADY_OPEN,
    };

    inline std::ostream& operator<<(std::ostream& os, OpenDeviceError value)
    {
        switch (value) {
        case OpenDeviceError::OK:
            return os << "OpenDeviceError::OK";
        case OpenDeviceError::ACCESS_DENIED:
            return os << "OpenDeviceError::ACCESS_DENIED";
        case OpenDeviceError::ALREADY_OPEN:
            return os << "OpenDeviceError::ALREADY_OPEN";
        default:
            return os << "Unknown OpenDeviceError value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(OpenDeviceError value)
    {
        return internal::OpenDeviceError_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class TransferDirection : int32_t {
        INBOUND,
        OUTBOUND,
    };

    inline std::ostream& operator<<(std::ostream& os, TransferDirection value)
    {
        switch (value) {
        case TransferDirection::INBOUND:
            return os << "TransferDirection::INBOUND";
        case TransferDirection::OUTBOUND:
            return os << "TransferDirection::OUTBOUND";
        default:
            return os << "Unknown TransferDirection value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(TransferDirection value)
    {
        return internal::TransferDirection_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class ControlTransferType : int32_t {
        STANDARD,
        CLASS,
        VENDOR,
        RESERVED,
    };

    inline std::ostream& operator<<(std::ostream& os, ControlTransferType value)
    {
        switch (value) {
        case ControlTransferType::STANDARD:
            return os << "ControlTransferType::STANDARD";
        case ControlTransferType::CLASS:
            return os << "ControlTransferType::CLASS";
        case ControlTransferType::VENDOR:
            return os << "ControlTransferType::VENDOR";
        case ControlTransferType::RESERVED:
            return os << "ControlTransferType::RESERVED";
        default:
            return os << "Unknown ControlTransferType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ControlTransferType value)
    {
        return internal::ControlTransferType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class ControlTransferRecipient : int32_t {
        DEVICE,
        INTERFACE,
        ENDPOINT,
        OTHER,
    };

    inline std::ostream& operator<<(std::ostream& os, ControlTransferRecipient value)
    {
        switch (value) {
        case ControlTransferRecipient::DEVICE:
            return os << "ControlTransferRecipient::DEVICE";
        case ControlTransferRecipient::INTERFACE:
            return os << "ControlTransferRecipient::INTERFACE";
        case ControlTransferRecipient::ENDPOINT:
            return os << "ControlTransferRecipient::ENDPOINT";
        case ControlTransferRecipient::OTHER:
            return os << "ControlTransferRecipient::OTHER";
        default:
            return os << "Unknown ControlTransferRecipient value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ControlTransferRecipient value)
    {
        return internal::ControlTransferRecipient_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class EndpointType : int32_t {
        BULK,
        INTERRUPT,
        ISOCHRONOUS,
    };

    inline std::ostream& operator<<(std::ostream& os, EndpointType value)
    {
        switch (value) {
        case EndpointType::BULK:
            return os << "EndpointType::BULK";
        case EndpointType::INTERRUPT:
            return os << "EndpointType::INTERRUPT";
        case EndpointType::ISOCHRONOUS:
            return os << "EndpointType::ISOCHRONOUS";
        default:
            return os << "Unknown EndpointType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(EndpointType value)
    {
        return internal::EndpointType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class TransferStatus : int32_t {
        COMPLETED,
        TRANSFER_ERROR,
        PERMISSION_DENIED,
        TIMEOUT,
        CANCELLED,
        STALLED,
        DISCONNECT,
        BABBLE,
        SHORT_PACKET,
    };

    inline std::ostream& operator<<(std::ostream& os, TransferStatus value)
    {
        switch (value) {
        case TransferStatus::COMPLETED:
            return os << "TransferStatus::COMPLETED";
        case TransferStatus::TRANSFER_ERROR:
            return os << "TransferStatus::TRANSFER_ERROR";
        case TransferStatus::PERMISSION_DENIED:
            return os << "TransferStatus::PERMISSION_DENIED";
        case TransferStatus::TIMEOUT:
            return os << "TransferStatus::TIMEOUT";
        case TransferStatus::CANCELLED:
            return os << "TransferStatus::CANCELLED";
        case TransferStatus::STALLED:
            return os << "TransferStatus::STALLED";
        case TransferStatus::DISCONNECT:
            return os << "TransferStatus::DISCONNECT";
        case TransferStatus::BABBLE:
            return os << "TransferStatus::BABBLE";
        case TransferStatus::SHORT_PACKET:
            return os << "TransferStatus::SHORT_PACKET";
        default:
            return os << "Unknown TransferStatus value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(TransferStatus value)
    {
        return internal::TransferStatus_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class DeviceInterfaceBase {
    };

    using DevicePtrDataView = mojo::InterfacePtrDataView<DeviceInterfaceBase>;
    using DeviceRequestDataView = mojo::InterfaceRequestDataView<DeviceInterfaceBase>;
    using DeviceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DeviceInterfaceBase>;
    using DeviceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DeviceInterfaceBase>;
    class EndpointInfoDataView {
    public:
        EndpointInfoDataView() { }

        EndpointInfoDataView(
            internal::EndpointInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t endpoint_number() const
        {
            return data_->endpoint_number;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDirection(UserType* output) const
        {
            auto data_value = data_->direction;
            return mojo::internal::Deserialize<::device::usb::TransferDirection>(
                data_value, output);
        }

        TransferDirection direction() const
        {
            return static_cast<TransferDirection>(data_->direction);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::device::usb::EndpointType>(
                data_value, output);
        }

        EndpointType type() const
        {
            return static_cast<EndpointType>(data_->type);
        }
        uint32_t packet_size() const
        {
            return data_->packet_size;
        }

    private:
        internal::EndpointInfo_Data* data_ = nullptr;
    };

    class AlternateInterfaceInfoDataView {
    public:
        AlternateInterfaceInfoDataView() { }

        AlternateInterfaceInfoDataView(
            internal::AlternateInterfaceInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t alternate_setting() const
        {
            return data_->alternate_setting;
        }
        uint8_t class_code() const
        {
            return data_->class_code;
        }
        uint8_t subclass_code() const
        {
            return data_->subclass_code;
        }
        uint8_t protocol_code() const
        {
            return data_->protocol_code;
        }
        inline void GetInterfaceNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterfaceName(UserType* output)
        {
            auto* pointer = data_->interface_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetEndpointsDataView(
            mojo::ArrayDataView<EndpointInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEndpoints(UserType* output)
        {
            auto* pointer = data_->endpoints.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::EndpointInfoDataView>>(
                pointer, output, context_);
        }

    private:
        internal::AlternateInterfaceInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InterfaceInfoDataView {
    public:
        InterfaceInfoDataView() { }

        InterfaceInfoDataView(
            internal::InterfaceInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t interface_number() const
        {
            return data_->interface_number;
        }
        inline void GetAlternatesDataView(
            mojo::ArrayDataView<AlternateInterfaceInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAlternates(UserType* output)
        {
            auto* pointer = data_->alternates.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::AlternateInterfaceInfoDataView>>(
                pointer, output, context_);
        }

    private:
        internal::InterfaceInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ConfigurationInfoDataView {
    public:
        ConfigurationInfoDataView() { }

        ConfigurationInfoDataView(
            internal::ConfigurationInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t configuration_value() const
        {
            return data_->configuration_value;
        }
        inline void GetConfigurationNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfigurationName(UserType* output)
        {
            auto* pointer = data_->configuration_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetInterfacesDataView(
            mojo::ArrayDataView<InterfaceInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterfaces(UserType* output)
        {
            auto* pointer = data_->interfaces.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::InterfaceInfoDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ConfigurationInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceInfoDataView {
    public:
        DeviceInfoDataView() { }

        DeviceInfoDataView(
            internal::DeviceInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetGuidDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGuid(UserType* output)
        {
            auto* pointer = data_->guid.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint8_t usb_version_major() const
        {
            return data_->usb_version_major;
        }
        uint8_t usb_version_minor() const
        {
            return data_->usb_version_minor;
        }
        uint8_t usb_version_subminor() const
        {
            return data_->usb_version_subminor;
        }
        uint8_t class_code() const
        {
            return data_->class_code;
        }
        uint8_t subclass_code() const
        {
            return data_->subclass_code;
        }
        uint8_t protocol_code() const
        {
            return data_->protocol_code;
        }
        uint16_t vendor_id() const
        {
            return data_->vendor_id;
        }
        uint16_t product_id() const
        {
            return data_->product_id;
        }
        uint8_t device_version_major() const
        {
            return data_->device_version_major;
        }
        uint8_t device_version_minor() const
        {
            return data_->device_version_minor;
        }
        uint8_t device_version_subminor() const
        {
            return data_->device_version_subminor;
        }
        inline void GetManufacturerNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadManufacturerName(UserType* output)
        {
            auto* pointer = data_->manufacturer_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetProductNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProductName(UserType* output)
        {
            auto* pointer = data_->product_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetSerialNumberDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSerialNumber(UserType* output)
        {
            auto* pointer = data_->serial_number.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint8_t active_configuration() const
        {
            return data_->active_configuration;
        }
        inline void GetConfigurationsDataView(
            mojo::ArrayDataView<ConfigurationInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfigurations(UserType* output)
        {
            auto* pointer = data_->configurations.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::ConfigurationInfoDataView>>(
                pointer, output, context_);
        }

    private:
        internal::DeviceInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ControlTransferParamsDataView {
    public:
        ControlTransferParamsDataView() { }

        ControlTransferParamsDataView(
            internal::ControlTransferParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::device::usb::ControlTransferType>(
                data_value, output);
        }

        ControlTransferType type() const
        {
            return static_cast<ControlTransferType>(data_->type);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRecipient(UserType* output) const
        {
            auto data_value = data_->recipient;
            return mojo::internal::Deserialize<::device::usb::ControlTransferRecipient>(
                data_value, output);
        }

        ControlTransferRecipient recipient() const
        {
            return static_cast<ControlTransferRecipient>(data_->recipient);
        }
        uint8_t request() const
        {
            return data_->request;
        }
        uint16_t value() const
        {
            return data_->value;
        }
        uint16_t index() const
        {
            return data_->index;
        }

    private:
        internal::ControlTransferParams_Data* data_ = nullptr;
    };

    class IsochronousPacketDataView {
    public:
        IsochronousPacketDataView() { }

        IsochronousPacketDataView(
            internal::IsochronousPacket_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t length() const
        {
            return data_->length;
        }
        uint32_t transferred_length() const
        {
            return data_->transferred_length;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::device::usb::TransferStatus>(
                data_value, output);
        }

        TransferStatus status() const
        {
            return static_cast<TransferStatus>(data_->status);
        }

    private:
        internal::IsochronousPacket_Data* data_ = nullptr;
    };

    class Device_GetDeviceInfo_ParamsDataView {
    public:
        Device_GetDeviceInfo_ParamsDataView() { }

        Device_GetDeviceInfo_ParamsDataView(
            internal::Device_GetDeviceInfo_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Device_GetDeviceInfo_Params_Data* data_ = nullptr;
    };

    class Device_GetDeviceInfo_ResponseParamsDataView {
    public:
        Device_GetDeviceInfo_ResponseParamsDataView() { }

        Device_GetDeviceInfo_ResponseParamsDataView(
            internal::Device_GetDeviceInfo_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInfoDataView(
            DeviceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInfo(UserType* output)
        {
            auto* pointer = data_->info.Get();
            return mojo::internal::Deserialize<::device::usb::DeviceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::Device_GetDeviceInfo_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_Open_ParamsDataView {
    public:
        Device_Open_ParamsDataView() { }

        Device_Open_ParamsDataView(
            internal::Device_Open_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Device_Open_Params_Data* data_ = nullptr;
    };

    class Device_Open_ResponseParamsDataView {
    public:
        Device_Open_ResponseParamsDataView() { }

        Device_Open_ResponseParamsDataView(
            internal::Device_Open_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::device::usb::OpenDeviceError>(
                data_value, output);
        }

        OpenDeviceError error() const
        {
            return static_cast<OpenDeviceError>(data_->error);
        }

    private:
        internal::Device_Open_ResponseParams_Data* data_ = nullptr;
    };

    class Device_Close_ParamsDataView {
    public:
        Device_Close_ParamsDataView() { }

        Device_Close_ParamsDataView(
            internal::Device_Close_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Device_Close_Params_Data* data_ = nullptr;
    };

    class Device_Close_ResponseParamsDataView {
    public:
        Device_Close_ResponseParamsDataView() { }

        Device_Close_ResponseParamsDataView(
            internal::Device_Close_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Device_Close_ResponseParams_Data* data_ = nullptr;
    };

    class Device_SetConfiguration_ParamsDataView {
    public:
        Device_SetConfiguration_ParamsDataView() { }

        Device_SetConfiguration_ParamsDataView(
            internal::Device_SetConfiguration_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t value() const
        {
            return data_->value;
        }

    private:
        internal::Device_SetConfiguration_Params_Data* data_ = nullptr;
    };

    class Device_SetConfiguration_ResponseParamsDataView {
    public:
        Device_SetConfiguration_ResponseParamsDataView() { }

        Device_SetConfiguration_ResponseParamsDataView(
            internal::Device_SetConfiguration_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Device_SetConfiguration_ResponseParams_Data* data_ = nullptr;
    };

    class Device_ClaimInterface_ParamsDataView {
    public:
        Device_ClaimInterface_ParamsDataView() { }

        Device_ClaimInterface_ParamsDataView(
            internal::Device_ClaimInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t interface_number() const
        {
            return data_->interface_number;
        }

    private:
        internal::Device_ClaimInterface_Params_Data* data_ = nullptr;
    };

    class Device_ClaimInterface_ResponseParamsDataView {
    public:
        Device_ClaimInterface_ResponseParamsDataView() { }

        Device_ClaimInterface_ResponseParamsDataView(
            internal::Device_ClaimInterface_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Device_ClaimInterface_ResponseParams_Data* data_ = nullptr;
    };

    class Device_ReleaseInterface_ParamsDataView {
    public:
        Device_ReleaseInterface_ParamsDataView() { }

        Device_ReleaseInterface_ParamsDataView(
            internal::Device_ReleaseInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t interface_number() const
        {
            return data_->interface_number;
        }

    private:
        internal::Device_ReleaseInterface_Params_Data* data_ = nullptr;
    };

    class Device_ReleaseInterface_ResponseParamsDataView {
    public:
        Device_ReleaseInterface_ResponseParamsDataView() { }

        Device_ReleaseInterface_ResponseParamsDataView(
            internal::Device_ReleaseInterface_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Device_ReleaseInterface_ResponseParams_Data* data_ = nullptr;
    };

    class Device_SetInterfaceAlternateSetting_ParamsDataView {
    public:
        Device_SetInterfaceAlternateSetting_ParamsDataView() { }

        Device_SetInterfaceAlternateSetting_ParamsDataView(
            internal::Device_SetInterfaceAlternateSetting_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t interface_number() const
        {
            return data_->interface_number;
        }
        uint8_t alternate_setting() const
        {
            return data_->alternate_setting;
        }

    private:
        internal::Device_SetInterfaceAlternateSetting_Params_Data* data_ = nullptr;
    };

    class Device_SetInterfaceAlternateSetting_ResponseParamsDataView {
    public:
        Device_SetInterfaceAlternateSetting_ResponseParamsDataView() { }

        Device_SetInterfaceAlternateSetting_ResponseParamsDataView(
            internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Device_SetInterfaceAlternateSetting_ResponseParams_Data* data_ = nullptr;
    };

    class Device_Reset_ParamsDataView {
    public:
        Device_Reset_ParamsDataView() { }

        Device_Reset_ParamsDataView(
            internal::Device_Reset_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Device_Reset_Params_Data* data_ = nullptr;
    };

    class Device_Reset_ResponseParamsDataView {
    public:
        Device_Reset_ResponseParamsDataView() { }

        Device_Reset_ResponseParamsDataView(
            internal::Device_Reset_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Device_Reset_ResponseParams_Data* data_ = nullptr;
    };

    class Device_ClearHalt_ParamsDataView {
    public:
        Device_ClearHalt_ParamsDataView() { }

        Device_ClearHalt_ParamsDataView(
            internal::Device_ClearHalt_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t endpoint() const
        {
            return data_->endpoint;
        }

    private:
        internal::Device_ClearHalt_Params_Data* data_ = nullptr;
    };

    class Device_ClearHalt_ResponseParamsDataView {
    public:
        Device_ClearHalt_ResponseParamsDataView() { }

        Device_ClearHalt_ResponseParamsDataView(
            internal::Device_ClearHalt_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Device_ClearHalt_ResponseParams_Data* data_ = nullptr;
    };

    class Device_ControlTransferIn_ParamsDataView {
    public:
        Device_ControlTransferIn_ParamsDataView() { }

        Device_ControlTransferIn_ParamsDataView(
            internal::Device_ControlTransferIn_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            ControlTransferParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::device::usb::ControlTransferParamsDataView>(
                pointer, output, context_);
        }
        uint32_t length() const
        {
            return data_->length;
        }
        uint32_t timeout() const
        {
            return data_->timeout;
        }

    private:
        internal::Device_ControlTransferIn_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_ControlTransferIn_ResponseParamsDataView {
    public:
        Device_ControlTransferIn_ResponseParamsDataView() { }

        Device_ControlTransferIn_ResponseParamsDataView(
            internal::Device_ControlTransferIn_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::device::usb::TransferStatus>(
                data_value, output);
        }

        TransferStatus status() const
        {
            return static_cast<TransferStatus>(data_->status);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Device_ControlTransferIn_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_ControlTransferOut_ParamsDataView {
    public:
        Device_ControlTransferOut_ParamsDataView() { }

        Device_ControlTransferOut_ParamsDataView(
            internal::Device_ControlTransferOut_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            ControlTransferParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::device::usb::ControlTransferParamsDataView>(
                pointer, output, context_);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        uint32_t timeout() const
        {
            return data_->timeout;
        }

    private:
        internal::Device_ControlTransferOut_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_ControlTransferOut_ResponseParamsDataView {
    public:
        Device_ControlTransferOut_ResponseParamsDataView() { }

        Device_ControlTransferOut_ResponseParamsDataView(
            internal::Device_ControlTransferOut_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::device::usb::TransferStatus>(
                data_value, output);
        }

        TransferStatus status() const
        {
            return static_cast<TransferStatus>(data_->status);
        }

    private:
        internal::Device_ControlTransferOut_ResponseParams_Data* data_ = nullptr;
    };

    class Device_GenericTransferIn_ParamsDataView {
    public:
        Device_GenericTransferIn_ParamsDataView() { }

        Device_GenericTransferIn_ParamsDataView(
            internal::Device_GenericTransferIn_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t endpoint_number() const
        {
            return data_->endpoint_number;
        }
        uint32_t length() const
        {
            return data_->length;
        }
        uint32_t timeout() const
        {
            return data_->timeout;
        }

    private:
        internal::Device_GenericTransferIn_Params_Data* data_ = nullptr;
    };

    class Device_GenericTransferIn_ResponseParamsDataView {
    public:
        Device_GenericTransferIn_ResponseParamsDataView() { }

        Device_GenericTransferIn_ResponseParamsDataView(
            internal::Device_GenericTransferIn_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::device::usb::TransferStatus>(
                data_value, output);
        }

        TransferStatus status() const
        {
            return static_cast<TransferStatus>(data_->status);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Device_GenericTransferIn_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_GenericTransferOut_ParamsDataView {
    public:
        Device_GenericTransferOut_ParamsDataView() { }

        Device_GenericTransferOut_ParamsDataView(
            internal::Device_GenericTransferOut_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t endpoint_number() const
        {
            return data_->endpoint_number;
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        uint32_t timeout() const
        {
            return data_->timeout;
        }

    private:
        internal::Device_GenericTransferOut_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_GenericTransferOut_ResponseParamsDataView {
    public:
        Device_GenericTransferOut_ResponseParamsDataView() { }

        Device_GenericTransferOut_ResponseParamsDataView(
            internal::Device_GenericTransferOut_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::device::usb::TransferStatus>(
                data_value, output);
        }

        TransferStatus status() const
        {
            return static_cast<TransferStatus>(data_->status);
        }

    private:
        internal::Device_GenericTransferOut_ResponseParams_Data* data_ = nullptr;
    };

    class Device_IsochronousTransferIn_ParamsDataView {
    public:
        Device_IsochronousTransferIn_ParamsDataView() { }

        Device_IsochronousTransferIn_ParamsDataView(
            internal::Device_IsochronousTransferIn_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t endpoint_number() const
        {
            return data_->endpoint_number;
        }
        inline void GetPacketLengthsDataView(
            mojo::ArrayDataView<uint32_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPacketLengths(UserType* output)
        {
            auto* pointer = data_->packet_lengths.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint32_t>>(
                pointer, output, context_);
        }
        uint32_t timeout() const
        {
            return data_->timeout;
        }

    private:
        internal::Device_IsochronousTransferIn_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_IsochronousTransferIn_ResponseParamsDataView {
    public:
        Device_IsochronousTransferIn_ResponseParamsDataView() { }

        Device_IsochronousTransferIn_ResponseParamsDataView(
            internal::Device_IsochronousTransferIn_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetPacketsDataView(
            mojo::ArrayDataView<IsochronousPacketDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPackets(UserType* output)
        {
            auto* pointer = data_->packets.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::IsochronousPacketDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Device_IsochronousTransferIn_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_IsochronousTransferOut_ParamsDataView {
    public:
        Device_IsochronousTransferOut_ParamsDataView() { }

        Device_IsochronousTransferOut_ParamsDataView(
            internal::Device_IsochronousTransferOut_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint8_t endpoint_number() const
        {
            return data_->endpoint_number;
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetPacketLengthsDataView(
            mojo::ArrayDataView<uint32_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPacketLengths(UserType* output)
        {
            auto* pointer = data_->packet_lengths.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint32_t>>(
                pointer, output, context_);
        }
        uint32_t timeout() const
        {
            return data_->timeout;
        }

    private:
        internal::Device_IsochronousTransferOut_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Device_IsochronousTransferOut_ResponseParamsDataView {
    public:
        Device_IsochronousTransferOut_ResponseParamsDataView() { }

        Device_IsochronousTransferOut_ResponseParamsDataView(
            internal::Device_IsochronousTransferOut_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPacketsDataView(
            mojo::ArrayDataView<IsochronousPacketDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPackets(UserType* output)
        {
            auto* pointer = data_->packets.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::IsochronousPacketDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Device_IsochronousTransferOut_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace usb
} // namespace device

namespace std {

template <>
struct hash<::device::usb::OpenDeviceError>
    : public mojo::internal::EnumHashImpl<::device::usb::OpenDeviceError> {
};

template <>
struct hash<::device::usb::TransferDirection>
    : public mojo::internal::EnumHashImpl<::device::usb::TransferDirection> {
};

template <>
struct hash<::device::usb::ControlTransferType>
    : public mojo::internal::EnumHashImpl<::device::usb::ControlTransferType> {
};

template <>
struct hash<::device::usb::ControlTransferRecipient>
    : public mojo::internal::EnumHashImpl<::device::usb::ControlTransferRecipient> {
};

template <>
struct hash<::device::usb::EndpointType>
    : public mojo::internal::EnumHashImpl<::device::usb::EndpointType> {
};

template <>
struct hash<::device::usb::TransferStatus>
    : public mojo::internal::EnumHashImpl<::device::usb::TransferStatus> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::usb::OpenDeviceError, ::device::usb::OpenDeviceError> {
    static ::device::usb::OpenDeviceError ToMojom(::device::usb::OpenDeviceError input) { return input; }
    static bool FromMojom(::device::usb::OpenDeviceError input, ::device::usb::OpenDeviceError* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::OpenDeviceError, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::usb::OpenDeviceError, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::usb::OpenDeviceError>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::usb::TransferDirection, ::device::usb::TransferDirection> {
    static ::device::usb::TransferDirection ToMojom(::device::usb::TransferDirection input) { return input; }
    static bool FromMojom(::device::usb::TransferDirection input, ::device::usb::TransferDirection* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::TransferDirection, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::usb::TransferDirection, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::usb::TransferDirection>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::usb::ControlTransferType, ::device::usb::ControlTransferType> {
    static ::device::usb::ControlTransferType ToMojom(::device::usb::ControlTransferType input) { return input; }
    static bool FromMojom(::device::usb::ControlTransferType input, ::device::usb::ControlTransferType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::ControlTransferType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::usb::ControlTransferType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::usb::ControlTransferType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::usb::ControlTransferRecipient, ::device::usb::ControlTransferRecipient> {
    static ::device::usb::ControlTransferRecipient ToMojom(::device::usb::ControlTransferRecipient input) { return input; }
    static bool FromMojom(::device::usb::ControlTransferRecipient input, ::device::usb::ControlTransferRecipient* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::ControlTransferRecipient, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::usb::ControlTransferRecipient, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::usb::ControlTransferRecipient>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::usb::EndpointType, ::device::usb::EndpointType> {
    static ::device::usb::EndpointType ToMojom(::device::usb::EndpointType input) { return input; }
    static bool FromMojom(::device::usb::EndpointType input, ::device::usb::EndpointType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::EndpointType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::usb::EndpointType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::usb::EndpointType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::usb::TransferStatus, ::device::usb::TransferStatus> {
    static ::device::usb::TransferStatus ToMojom(::device::usb::TransferStatus input) { return input; }
    static bool FromMojom(::device::usb::TransferStatus input, ::device::usb::TransferStatus* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::TransferStatus, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::usb::TransferStatus, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::usb::TransferStatus>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::EndpointInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::EndpointInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::EndpointInfo_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::EndpointInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::EndpointInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->endpoint_number = CallWithContext(Traits::endpoint_number, input, custom_context);
            mojo::internal::Serialize<::device::usb::TransferDirection>(
                CallWithContext(Traits::direction, input, custom_context), &result->direction);
            mojo::internal::Serialize<::device::usb::EndpointType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            result->packet_size = CallWithContext(Traits::packet_size, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::EndpointInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::EndpointInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::AlternateInterfaceInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::AlternateInterfaceInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::AlternateInterfaceInfo_Data);
            decltype(CallWithContext(Traits::interface_name, input, custom_context)) in_interface_name = CallWithContext(Traits::interface_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_interface_name, context);
            decltype(CallWithContext(Traits::endpoints, input, custom_context)) in_endpoints = CallWithContext(Traits::endpoints, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::EndpointInfoDataView>>(
                in_endpoints, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::AlternateInterfaceInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::AlternateInterfaceInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->alternate_setting = CallWithContext(Traits::alternate_setting, input, custom_context);
            result->class_code = CallWithContext(Traits::class_code, input, custom_context);
            result->subclass_code = CallWithContext(Traits::subclass_code, input, custom_context);
            result->protocol_code = CallWithContext(Traits::protocol_code, input, custom_context);
            decltype(CallWithContext(Traits::interface_name, input, custom_context)) in_interface_name = CallWithContext(Traits::interface_name, input, custom_context);
            typename decltype(result->interface_name)::BaseType* interface_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_interface_name, buffer, &interface_name_ptr, context);
            result->interface_name.Set(interface_name_ptr);
            decltype(CallWithContext(Traits::endpoints, input, custom_context)) in_endpoints = CallWithContext(Traits::endpoints, input, custom_context);
            typename decltype(result->endpoints)::BaseType* endpoints_ptr;
            const mojo::internal::ContainerValidateParams endpoints_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::EndpointInfoDataView>>(
                in_endpoints, buffer, &endpoints_ptr, &endpoints_validate_params,
                context);
            result->endpoints.Set(endpoints_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->endpoints.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null endpoints in AlternateInterfaceInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::AlternateInterfaceInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::AlternateInterfaceInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::InterfaceInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::InterfaceInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::InterfaceInfo_Data);
            decltype(CallWithContext(Traits::alternates, input, custom_context)) in_alternates = CallWithContext(Traits::alternates, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::AlternateInterfaceInfoDataView>>(
                in_alternates, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::InterfaceInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::InterfaceInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->interface_number = CallWithContext(Traits::interface_number, input, custom_context);
            decltype(CallWithContext(Traits::alternates, input, custom_context)) in_alternates = CallWithContext(Traits::alternates, input, custom_context);
            typename decltype(result->alternates)::BaseType* alternates_ptr;
            const mojo::internal::ContainerValidateParams alternates_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::AlternateInterfaceInfoDataView>>(
                in_alternates, buffer, &alternates_ptr, &alternates_validate_params,
                context);
            result->alternates.Set(alternates_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->alternates.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null alternates in InterfaceInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::InterfaceInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::InterfaceInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::ConfigurationInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::ConfigurationInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::ConfigurationInfo_Data);
            decltype(CallWithContext(Traits::configuration_name, input, custom_context)) in_configuration_name = CallWithContext(Traits::configuration_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_configuration_name, context);
            decltype(CallWithContext(Traits::interfaces, input, custom_context)) in_interfaces = CallWithContext(Traits::interfaces, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::InterfaceInfoDataView>>(
                in_interfaces, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::ConfigurationInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::ConfigurationInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->configuration_value = CallWithContext(Traits::configuration_value, input, custom_context);
            decltype(CallWithContext(Traits::configuration_name, input, custom_context)) in_configuration_name = CallWithContext(Traits::configuration_name, input, custom_context);
            typename decltype(result->configuration_name)::BaseType* configuration_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_configuration_name, buffer, &configuration_name_ptr, context);
            result->configuration_name.Set(configuration_name_ptr);
            decltype(CallWithContext(Traits::interfaces, input, custom_context)) in_interfaces = CallWithContext(Traits::interfaces, input, custom_context);
            typename decltype(result->interfaces)::BaseType* interfaces_ptr;
            const mojo::internal::ContainerValidateParams interfaces_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::InterfaceInfoDataView>>(
                in_interfaces, buffer, &interfaces_ptr, &interfaces_validate_params,
                context);
            result->interfaces.Set(interfaces_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->interfaces.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null interfaces in ConfigurationInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::ConfigurationInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::ConfigurationInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::DeviceInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::DeviceInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::DeviceInfo_Data);
            decltype(CallWithContext(Traits::guid, input, custom_context)) in_guid = CallWithContext(Traits::guid, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_guid, context);
            decltype(CallWithContext(Traits::manufacturer_name, input, custom_context)) in_manufacturer_name = CallWithContext(Traits::manufacturer_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_manufacturer_name, context);
            decltype(CallWithContext(Traits::product_name, input, custom_context)) in_product_name = CallWithContext(Traits::product_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_product_name, context);
            decltype(CallWithContext(Traits::serial_number, input, custom_context)) in_serial_number = CallWithContext(Traits::serial_number, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_serial_number, context);
            decltype(CallWithContext(Traits::configurations, input, custom_context)) in_configurations = CallWithContext(Traits::configurations, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::ConfigurationInfoDataView>>(
                in_configurations, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::DeviceInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::DeviceInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::guid, input, custom_context)) in_guid = CallWithContext(Traits::guid, input, custom_context);
            typename decltype(result->guid)::BaseType* guid_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_guid, buffer, &guid_ptr, context);
            result->guid.Set(guid_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->guid.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null guid in DeviceInfo struct");
            result->usb_version_major = CallWithContext(Traits::usb_version_major, input, custom_context);
            result->usb_version_minor = CallWithContext(Traits::usb_version_minor, input, custom_context);
            result->usb_version_subminor = CallWithContext(Traits::usb_version_subminor, input, custom_context);
            result->class_code = CallWithContext(Traits::class_code, input, custom_context);
            result->subclass_code = CallWithContext(Traits::subclass_code, input, custom_context);
            result->protocol_code = CallWithContext(Traits::protocol_code, input, custom_context);
            result->vendor_id = CallWithContext(Traits::vendor_id, input, custom_context);
            result->product_id = CallWithContext(Traits::product_id, input, custom_context);
            result->device_version_major = CallWithContext(Traits::device_version_major, input, custom_context);
            result->device_version_minor = CallWithContext(Traits::device_version_minor, input, custom_context);
            result->device_version_subminor = CallWithContext(Traits::device_version_subminor, input, custom_context);
            decltype(CallWithContext(Traits::manufacturer_name, input, custom_context)) in_manufacturer_name = CallWithContext(Traits::manufacturer_name, input, custom_context);
            typename decltype(result->manufacturer_name)::BaseType* manufacturer_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_manufacturer_name, buffer, &manufacturer_name_ptr, context);
            result->manufacturer_name.Set(manufacturer_name_ptr);
            decltype(CallWithContext(Traits::product_name, input, custom_context)) in_product_name = CallWithContext(Traits::product_name, input, custom_context);
            typename decltype(result->product_name)::BaseType* product_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_product_name, buffer, &product_name_ptr, context);
            result->product_name.Set(product_name_ptr);
            decltype(CallWithContext(Traits::serial_number, input, custom_context)) in_serial_number = CallWithContext(Traits::serial_number, input, custom_context);
            typename decltype(result->serial_number)::BaseType* serial_number_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_serial_number, buffer, &serial_number_ptr, context);
            result->serial_number.Set(serial_number_ptr);
            result->active_configuration = CallWithContext(Traits::active_configuration, input, custom_context);
            decltype(CallWithContext(Traits::configurations, input, custom_context)) in_configurations = CallWithContext(Traits::configurations, input, custom_context);
            typename decltype(result->configurations)::BaseType* configurations_ptr;
            const mojo::internal::ContainerValidateParams configurations_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::ConfigurationInfoDataView>>(
                in_configurations, buffer, &configurations_ptr, &configurations_validate_params,
                context);
            result->configurations.Set(configurations_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->configurations.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null configurations in DeviceInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::DeviceInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::DeviceInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::ControlTransferParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::ControlTransferParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::ControlTransferParams_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::ControlTransferParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::ControlTransferParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::device::usb::ControlTransferType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            mojo::internal::Serialize<::device::usb::ControlTransferRecipient>(
                CallWithContext(Traits::recipient, input, custom_context), &result->recipient);
            result->request = CallWithContext(Traits::request, input, custom_context);
            result->value = CallWithContext(Traits::value, input, custom_context);
            result->index = CallWithContext(Traits::index, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::ControlTransferParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::ControlTransferParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::IsochronousPacketDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::IsochronousPacketDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::IsochronousPacket_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::IsochronousPacket_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::IsochronousPacket_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->length = CallWithContext(Traits::length, input, custom_context);
            result->transferred_length = CallWithContext(Traits::transferred_length, input, custom_context);
            mojo::internal::Serialize<::device::usb::TransferStatus>(
                CallWithContext(Traits::status, input, custom_context), &result->status);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::IsochronousPacket_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::IsochronousPacketDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace usb {

    inline void AlternateInterfaceInfoDataView::GetInterfaceNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->interface_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void AlternateInterfaceInfoDataView::GetEndpointsDataView(
        mojo::ArrayDataView<EndpointInfoDataView>* output)
    {
        auto pointer = data_->endpoints.Get();
        *output = mojo::ArrayDataView<EndpointInfoDataView>(pointer, context_);
    }

    inline void InterfaceInfoDataView::GetAlternatesDataView(
        mojo::ArrayDataView<AlternateInterfaceInfoDataView>* output)
    {
        auto pointer = data_->alternates.Get();
        *output = mojo::ArrayDataView<AlternateInterfaceInfoDataView>(pointer, context_);
    }

    inline void ConfigurationInfoDataView::GetConfigurationNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->configuration_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ConfigurationInfoDataView::GetInterfacesDataView(
        mojo::ArrayDataView<InterfaceInfoDataView>* output)
    {
        auto pointer = data_->interfaces.Get();
        *output = mojo::ArrayDataView<InterfaceInfoDataView>(pointer, context_);
    }

    inline void DeviceInfoDataView::GetGuidDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->guid.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DeviceInfoDataView::GetManufacturerNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->manufacturer_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DeviceInfoDataView::GetProductNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->product_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DeviceInfoDataView::GetSerialNumberDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->serial_number.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DeviceInfoDataView::GetConfigurationsDataView(
        mojo::ArrayDataView<ConfigurationInfoDataView>* output)
    {
        auto pointer = data_->configurations.Get();
        *output = mojo::ArrayDataView<ConfigurationInfoDataView>(pointer, context_);
    }

    inline void Device_GetDeviceInfo_ResponseParamsDataView::GetInfoDataView(
        DeviceInfoDataView* output)
    {
        auto pointer = data_->info.Get();
        *output = DeviceInfoDataView(pointer, context_);
    }

    inline void Device_ControlTransferIn_ParamsDataView::GetParamsDataView(
        ControlTransferParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = ControlTransferParamsDataView(pointer, context_);
    }

    inline void Device_ControlTransferIn_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void Device_ControlTransferOut_ParamsDataView::GetParamsDataView(
        ControlTransferParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = ControlTransferParamsDataView(pointer, context_);
    }
    inline void Device_ControlTransferOut_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void Device_GenericTransferIn_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void Device_GenericTransferOut_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void Device_IsochronousTransferIn_ParamsDataView::GetPacketLengthsDataView(
        mojo::ArrayDataView<uint32_t>* output)
    {
        auto pointer = data_->packet_lengths.Get();
        *output = mojo::ArrayDataView<uint32_t>(pointer, context_);
    }

    inline void Device_IsochronousTransferIn_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void Device_IsochronousTransferIn_ResponseParamsDataView::GetPacketsDataView(
        mojo::ArrayDataView<IsochronousPacketDataView>* output)
    {
        auto pointer = data_->packets.Get();
        *output = mojo::ArrayDataView<IsochronousPacketDataView>(pointer, context_);
    }

    inline void Device_IsochronousTransferOut_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void Device_IsochronousTransferOut_ParamsDataView::GetPacketLengthsDataView(
        mojo::ArrayDataView<uint32_t>* output)
    {
        auto pointer = data_->packet_lengths.Get();
        *output = mojo::ArrayDataView<uint32_t>(pointer, context_);
    }

    inline void Device_IsochronousTransferOut_ResponseParamsDataView::GetPacketsDataView(
        mojo::ArrayDataView<IsochronousPacketDataView>* output)
    {
        auto pointer = data_->packets.Get();
        *output = mojo::ArrayDataView<IsochronousPacketDataView>(pointer, context_);
    }

} // namespace usb
} // namespace device

#endif // DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_H_
