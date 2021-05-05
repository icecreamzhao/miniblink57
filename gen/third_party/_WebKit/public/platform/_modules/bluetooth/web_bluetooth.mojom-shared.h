// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/bluetooth/public/interfaces/uuid.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/bluetooth/web_bluetooth.mojom-shared-internal.h"

namespace blink {
namespace mojom {
    class WebBluetoothScanFilterDataView;

    class WebBluetoothRequestDeviceOptionsDataView;

    class WebBluetoothDeviceIdDataView;

    class WebBluetoothDeviceDataView;

    class WebBluetoothRemoteGATTServiceDataView;

    class WebBluetoothRemoteGATTCharacteristicDataView;

    class WebBluetoothRemoteGATTDescriptorDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothScanFilterDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothScanFilter_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothRequestDeviceOptionsDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothRequestDeviceOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothDeviceIdDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothDeviceId_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothDeviceDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothDevice_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothRemoteGATTServiceDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothRemoteGATTService_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothRemoteGATTCharacteristic_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView> {
        using Data = ::blink::mojom::internal::WebBluetoothRemoteGATTDescriptor_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class WebBluetoothResult : int32_t {
        SUCCESS,
        GATT_INVALID_ATTRIBUTE_LENGTH,
        SERVICE_NO_LONGER_EXISTS,
        CHARACTERISTIC_NO_LONGER_EXISTS,
        CONNECT_ALREADY_IN_PROGRESS,
        CONNECT_ATTRIBUTE_LENGTH_INVALID,
        CONNECT_AUTH_CANCELED,
        CONNECT_AUTH_FAILED,
        CONNECT_AUTH_REJECTED,
        CONNECT_AUTH_TIMEOUT,
        CONNECT_CONNECTION_CONGESTED,
        CONNECT_INSUFFICIENT_ENCRYPTION,
        CONNECT_OFFSET_INVALID,
        CONNECT_READ_NOT_PERMITTED,
        CONNECT_REQUEST_NOT_SUPPORTED,
        CONNECT_UNKNOWN_ERROR,
        CONNECT_UNKNOWN_FAILURE,
        CONNECT_UNSUPPORTED_DEVICE,
        CONNECT_WRITE_NOT_PERMITTED,
        DEVICE_NO_LONGER_IN_RANGE,
        GATT_NOT_PAIRED,
        GATT_OPERATION_IN_PROGRESS,
        UNTRANSLATED_CONNECT_ERROR_CODE,
        NO_BLUETOOTH_ADAPTER,
        CHOSEN_DEVICE_VANISHED,
        CHOOSER_CANCELLED,
        CHOOSER_NOT_SHOWN_API_GLOBALLY_DISABLED,
        CHOOSER_NOT_SHOWN_API_LOCALLY_DISABLED,
        CHOOSER_NOT_SHOWN_USER_DENIED_PERMISSION_TO_SCAN,
        SERVICE_NOT_FOUND,
        NO_SERVICES_FOUND,
        CHARACTERISTIC_NOT_FOUND,
        NO_CHARACTERISTICS_FOUND,
        DESCRIPTOR_NOT_FOUND,
        NO_DESCRIPTORS_FOUND,
        WEB_BLUETOOTH_NOT_SUPPORTED,
        BLUETOOTH_LOW_ENERGY_NOT_AVAILABLE,
        GATT_UNKNOWN_ERROR,
        GATT_UNKNOWN_FAILURE,
        GATT_NOT_PERMITTED,
        GATT_NOT_SUPPORTED,
        GATT_UNTRANSLATED_ERROR_CODE,
        GATT_NOT_AUTHORIZED,
        BLOCKLISTED_DESCRIPTOR_UUID,
        BLOCKLISTED_CHARACTERISTIC_UUID,
        BLOCKLISTED_READ,
        BLOCKLISTED_WRITE,
        NOT_ALLOWED_TO_ACCESS_ANY_SERVICE,
        NOT_ALLOWED_TO_ACCESS_SERVICE,
        REQUEST_DEVICE_WITH_BLOCKLISTED_UUID,
        REQUEST_DEVICE_FROM_CROSS_ORIGIN_IFRAME,
        REQUEST_DEVICE_WITHOUT_FRAME,
    };

    inline std::ostream& operator<<(std::ostream& os, WebBluetoothResult value)
    {
        switch (value) {
        case WebBluetoothResult::SUCCESS:
            return os << "WebBluetoothResult::SUCCESS";
        case WebBluetoothResult::GATT_INVALID_ATTRIBUTE_LENGTH:
            return os << "WebBluetoothResult::GATT_INVALID_ATTRIBUTE_LENGTH";
        case WebBluetoothResult::SERVICE_NO_LONGER_EXISTS:
            return os << "WebBluetoothResult::SERVICE_NO_LONGER_EXISTS";
        case WebBluetoothResult::CHARACTERISTIC_NO_LONGER_EXISTS:
            return os << "WebBluetoothResult::CHARACTERISTIC_NO_LONGER_EXISTS";
        case WebBluetoothResult::CONNECT_ALREADY_IN_PROGRESS:
            return os << "WebBluetoothResult::CONNECT_ALREADY_IN_PROGRESS";
        case WebBluetoothResult::CONNECT_ATTRIBUTE_LENGTH_INVALID:
            return os << "WebBluetoothResult::CONNECT_ATTRIBUTE_LENGTH_INVALID";
        case WebBluetoothResult::CONNECT_AUTH_CANCELED:
            return os << "WebBluetoothResult::CONNECT_AUTH_CANCELED";
        case WebBluetoothResult::CONNECT_AUTH_FAILED:
            return os << "WebBluetoothResult::CONNECT_AUTH_FAILED";
        case WebBluetoothResult::CONNECT_AUTH_REJECTED:
            return os << "WebBluetoothResult::CONNECT_AUTH_REJECTED";
        case WebBluetoothResult::CONNECT_AUTH_TIMEOUT:
            return os << "WebBluetoothResult::CONNECT_AUTH_TIMEOUT";
        case WebBluetoothResult::CONNECT_CONNECTION_CONGESTED:
            return os << "WebBluetoothResult::CONNECT_CONNECTION_CONGESTED";
        case WebBluetoothResult::CONNECT_INSUFFICIENT_ENCRYPTION:
            return os << "WebBluetoothResult::CONNECT_INSUFFICIENT_ENCRYPTION";
        case WebBluetoothResult::CONNECT_OFFSET_INVALID:
            return os << "WebBluetoothResult::CONNECT_OFFSET_INVALID";
        case WebBluetoothResult::CONNECT_READ_NOT_PERMITTED:
            return os << "WebBluetoothResult::CONNECT_READ_NOT_PERMITTED";
        case WebBluetoothResult::CONNECT_REQUEST_NOT_SUPPORTED:
            return os << "WebBluetoothResult::CONNECT_REQUEST_NOT_SUPPORTED";
        case WebBluetoothResult::CONNECT_UNKNOWN_ERROR:
            return os << "WebBluetoothResult::CONNECT_UNKNOWN_ERROR";
        case WebBluetoothResult::CONNECT_UNKNOWN_FAILURE:
            return os << "WebBluetoothResult::CONNECT_UNKNOWN_FAILURE";
        case WebBluetoothResult::CONNECT_UNSUPPORTED_DEVICE:
            return os << "WebBluetoothResult::CONNECT_UNSUPPORTED_DEVICE";
        case WebBluetoothResult::CONNECT_WRITE_NOT_PERMITTED:
            return os << "WebBluetoothResult::CONNECT_WRITE_NOT_PERMITTED";
        case WebBluetoothResult::DEVICE_NO_LONGER_IN_RANGE:
            return os << "WebBluetoothResult::DEVICE_NO_LONGER_IN_RANGE";
        case WebBluetoothResult::GATT_NOT_PAIRED:
            return os << "WebBluetoothResult::GATT_NOT_PAIRED";
        case WebBluetoothResult::GATT_OPERATION_IN_PROGRESS:
            return os << "WebBluetoothResult::GATT_OPERATION_IN_PROGRESS";
        case WebBluetoothResult::UNTRANSLATED_CONNECT_ERROR_CODE:
            return os << "WebBluetoothResult::UNTRANSLATED_CONNECT_ERROR_CODE";
        case WebBluetoothResult::NO_BLUETOOTH_ADAPTER:
            return os << "WebBluetoothResult::NO_BLUETOOTH_ADAPTER";
        case WebBluetoothResult::CHOSEN_DEVICE_VANISHED:
            return os << "WebBluetoothResult::CHOSEN_DEVICE_VANISHED";
        case WebBluetoothResult::CHOOSER_CANCELLED:
            return os << "WebBluetoothResult::CHOOSER_CANCELLED";
        case WebBluetoothResult::CHOOSER_NOT_SHOWN_API_GLOBALLY_DISABLED:
            return os << "WebBluetoothResult::CHOOSER_NOT_SHOWN_API_GLOBALLY_DISABLED";
        case WebBluetoothResult::CHOOSER_NOT_SHOWN_API_LOCALLY_DISABLED:
            return os << "WebBluetoothResult::CHOOSER_NOT_SHOWN_API_LOCALLY_DISABLED";
        case WebBluetoothResult::CHOOSER_NOT_SHOWN_USER_DENIED_PERMISSION_TO_SCAN:
            return os << "WebBluetoothResult::CHOOSER_NOT_SHOWN_USER_DENIED_PERMISSION_TO_SCAN";
        case WebBluetoothResult::SERVICE_NOT_FOUND:
            return os << "WebBluetoothResult::SERVICE_NOT_FOUND";
        case WebBluetoothResult::NO_SERVICES_FOUND:
            return os << "WebBluetoothResult::NO_SERVICES_FOUND";
        case WebBluetoothResult::CHARACTERISTIC_NOT_FOUND:
            return os << "WebBluetoothResult::CHARACTERISTIC_NOT_FOUND";
        case WebBluetoothResult::NO_CHARACTERISTICS_FOUND:
            return os << "WebBluetoothResult::NO_CHARACTERISTICS_FOUND";
        case WebBluetoothResult::DESCRIPTOR_NOT_FOUND:
            return os << "WebBluetoothResult::DESCRIPTOR_NOT_FOUND";
        case WebBluetoothResult::NO_DESCRIPTORS_FOUND:
            return os << "WebBluetoothResult::NO_DESCRIPTORS_FOUND";
        case WebBluetoothResult::WEB_BLUETOOTH_NOT_SUPPORTED:
            return os << "WebBluetoothResult::WEB_BLUETOOTH_NOT_SUPPORTED";
        case WebBluetoothResult::BLUETOOTH_LOW_ENERGY_NOT_AVAILABLE:
            return os << "WebBluetoothResult::BLUETOOTH_LOW_ENERGY_NOT_AVAILABLE";
        case WebBluetoothResult::GATT_UNKNOWN_ERROR:
            return os << "WebBluetoothResult::GATT_UNKNOWN_ERROR";
        case WebBluetoothResult::GATT_UNKNOWN_FAILURE:
            return os << "WebBluetoothResult::GATT_UNKNOWN_FAILURE";
        case WebBluetoothResult::GATT_NOT_PERMITTED:
            return os << "WebBluetoothResult::GATT_NOT_PERMITTED";
        case WebBluetoothResult::GATT_NOT_SUPPORTED:
            return os << "WebBluetoothResult::GATT_NOT_SUPPORTED";
        case WebBluetoothResult::GATT_UNTRANSLATED_ERROR_CODE:
            return os << "WebBluetoothResult::GATT_UNTRANSLATED_ERROR_CODE";
        case WebBluetoothResult::GATT_NOT_AUTHORIZED:
            return os << "WebBluetoothResult::GATT_NOT_AUTHORIZED";
        case WebBluetoothResult::BLOCKLISTED_DESCRIPTOR_UUID:
            return os << "WebBluetoothResult::BLOCKLISTED_DESCRIPTOR_UUID";
        case WebBluetoothResult::BLOCKLISTED_CHARACTERISTIC_UUID:
            return os << "WebBluetoothResult::BLOCKLISTED_CHARACTERISTIC_UUID";
        case WebBluetoothResult::BLOCKLISTED_READ:
            return os << "WebBluetoothResult::BLOCKLISTED_READ";
        case WebBluetoothResult::BLOCKLISTED_WRITE:
            return os << "WebBluetoothResult::BLOCKLISTED_WRITE";
        case WebBluetoothResult::NOT_ALLOWED_TO_ACCESS_ANY_SERVICE:
            return os << "WebBluetoothResult::NOT_ALLOWED_TO_ACCESS_ANY_SERVICE";
        case WebBluetoothResult::NOT_ALLOWED_TO_ACCESS_SERVICE:
            return os << "WebBluetoothResult::NOT_ALLOWED_TO_ACCESS_SERVICE";
        case WebBluetoothResult::REQUEST_DEVICE_WITH_BLOCKLISTED_UUID:
            return os << "WebBluetoothResult::REQUEST_DEVICE_WITH_BLOCKLISTED_UUID";
        case WebBluetoothResult::REQUEST_DEVICE_FROM_CROSS_ORIGIN_IFRAME:
            return os << "WebBluetoothResult::REQUEST_DEVICE_FROM_CROSS_ORIGIN_IFRAME";
        case WebBluetoothResult::REQUEST_DEVICE_WITHOUT_FRAME:
            return os << "WebBluetoothResult::REQUEST_DEVICE_WITHOUT_FRAME";
        default:
            return os << "Unknown WebBluetoothResult value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(WebBluetoothResult value)
    {
        return internal::WebBluetoothResult_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class WebBluetoothGATTQueryQuantity : int32_t {
        SINGLE,
        MULTIPLE,
    };

    inline std::ostream& operator<<(std::ostream& os, WebBluetoothGATTQueryQuantity value)
    {
        switch (value) {
        case WebBluetoothGATTQueryQuantity::SINGLE:
            return os << "WebBluetoothGATTQueryQuantity::SINGLE";
        case WebBluetoothGATTQueryQuantity::MULTIPLE:
            return os << "WebBluetoothGATTQueryQuantity::MULTIPLE";
        default:
            return os << "Unknown WebBluetoothGATTQueryQuantity value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(WebBluetoothGATTQueryQuantity value)
    {
        return internal::WebBluetoothGATTQueryQuantity_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class WebBluetoothServiceInterfaceBase {
    };

    using WebBluetoothServicePtrDataView = mojo::InterfacePtrDataView<WebBluetoothServiceInterfaceBase>;
    using WebBluetoothServiceRequestDataView = mojo::InterfaceRequestDataView<WebBluetoothServiceInterfaceBase>;
    using WebBluetoothServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WebBluetoothServiceInterfaceBase>;
    using WebBluetoothServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WebBluetoothServiceInterfaceBase>;
    class WebBluetoothServiceClientInterfaceBase {
    };

    using WebBluetoothServiceClientPtrDataView = mojo::InterfacePtrDataView<WebBluetoothServiceClientInterfaceBase>;
    using WebBluetoothServiceClientRequestDataView = mojo::InterfaceRequestDataView<WebBluetoothServiceClientInterfaceBase>;
    using WebBluetoothServiceClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WebBluetoothServiceClientInterfaceBase>;
    using WebBluetoothServiceClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WebBluetoothServiceClientInterfaceBase>;
    class WebBluetoothScanFilterDataView {
    public:
        WebBluetoothScanFilterDataView() { }

        WebBluetoothScanFilterDataView(
            internal::WebBluetoothScanFilter_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetServicesDataView(
            mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServices(UserType* output)
        {
            auto* pointer = data_->services.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>>(
                pointer, output, context_);
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetNamePrefixDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNamePrefix(UserType* output)
        {
            auto* pointer = data_->name_prefix.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothScanFilter_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothRequestDeviceOptionsDataView {
    public:
        WebBluetoothRequestDeviceOptionsDataView() { }

        WebBluetoothRequestDeviceOptionsDataView(
            internal::WebBluetoothRequestDeviceOptions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFiltersDataView(
            mojo::ArrayDataView<WebBluetoothScanFilterDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFilters(UserType* output)
        {
            auto* pointer = data_->filters.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothScanFilterDataView>>(
                pointer, output, context_);
        }
        inline void GetOptionalServicesDataView(
            mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptionalServices(UserType* output)
        {
            auto* pointer = data_->optional_services.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>>(
                pointer, output, context_);
        }
        bool accept_all_devices() const
        {
            return data_->accept_all_devices;
        }

    private:
        internal::WebBluetoothRequestDeviceOptions_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothDeviceIdDataView {
    public:
        WebBluetoothDeviceIdDataView() { }

        WebBluetoothDeviceIdDataView(
            internal::WebBluetoothDeviceId_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothDeviceId_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothDeviceDataView {
    public:
        WebBluetoothDeviceDataView() { }

        WebBluetoothDeviceDataView(
            internal::WebBluetoothDevice_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIdDataView(
            WebBluetoothDeviceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                pointer, output, context_);
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothDevice_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothRemoteGATTServiceDataView {
    public:
        WebBluetoothRemoteGATTServiceDataView() { }

        WebBluetoothRemoteGATTServiceDataView(
            internal::WebBluetoothRemoteGATTService_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInstanceId(UserType* output)
        {
            auto* pointer = data_->instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetUuidDataView(
            ::bluetooth::mojom::UUIDDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUuid(UserType* output)
        {
            auto* pointer = data_->uuid.Get();
            return mojo::internal::Deserialize<::bluetooth::mojom::UUIDDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothRemoteGATTService_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothRemoteGATTCharacteristicDataView {
    public:
        WebBluetoothRemoteGATTCharacteristicDataView() { }

        WebBluetoothRemoteGATTCharacteristicDataView(
            internal::WebBluetoothRemoteGATTCharacteristic_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInstanceId(UserType* output)
        {
            auto* pointer = data_->instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetUuidDataView(
            ::bluetooth::mojom::UUIDDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUuid(UserType* output)
        {
            auto* pointer = data_->uuid.Get();
            return mojo::internal::Deserialize<::bluetooth::mojom::UUIDDataView>(
                pointer, output, context_);
        }
        uint32_t properties() const
        {
            return data_->properties;
        }

    private:
        internal::WebBluetoothRemoteGATTCharacteristic_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothRemoteGATTDescriptorDataView {
    public:
        WebBluetoothRemoteGATTDescriptorDataView() { }

        WebBluetoothRemoteGATTDescriptorDataView(
            internal::WebBluetoothRemoteGATTDescriptor_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInstanceId(UserType* output)
        {
            auto* pointer = data_->instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetUuidDataView(
            ::bluetooth::mojom::UUIDDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUuid(UserType* output)
        {
            auto* pointer = data_->uuid.Get();
            return mojo::internal::Deserialize<::bluetooth::mojom::UUIDDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothRemoteGATTDescriptor_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_SetClient_ParamsDataView {
    public:
        WebBluetoothService_SetClient_ParamsDataView() { }

        WebBluetoothService_SetClient_ParamsDataView(
            internal::WebBluetoothService_SetClient_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::WebBluetoothServiceClientAssociatedPtrInfoDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WebBluetoothService_SetClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RequestDevice_ParamsDataView {
    public:
        WebBluetoothService_RequestDevice_ParamsDataView() { }

        WebBluetoothService_RequestDevice_ParamsDataView(
            internal::WebBluetoothService_RequestDevice_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOptionsDataView(
            WebBluetoothRequestDeviceOptionsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothRequestDeviceOptionsDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RequestDevice_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RequestDevice_ResponseParamsDataView {
    public:
        WebBluetoothService_RequestDevice_ResponseParamsDataView() { }

        WebBluetoothService_RequestDevice_ResponseParamsDataView(
            internal::WebBluetoothService_RequestDevice_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }
        inline void GetDeviceDataView(
            WebBluetoothDeviceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDevice(UserType* output)
        {
            auto* pointer = data_->device.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothDeviceDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RequestDevice_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteServerConnect_ParamsDataView {
    public:
        WebBluetoothService_RemoteServerConnect_ParamsDataView() { }

        WebBluetoothService_RemoteServerConnect_ParamsDataView(
            internal::WebBluetoothService_RemoteServerConnect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            WebBluetoothDeviceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteServerConnect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteServerConnect_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteServerConnect_ResponseParamsDataView() { }

        WebBluetoothService_RemoteServerConnect_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }

    private:
        internal::WebBluetoothService_RemoteServerConnect_ResponseParams_Data* data_ = nullptr;
    };

    class WebBluetoothService_RemoteServerDisconnect_ParamsDataView {
    public:
        WebBluetoothService_RemoteServerDisconnect_ParamsDataView() { }

        WebBluetoothService_RemoteServerDisconnect_ParamsDataView(
            internal::WebBluetoothService_RemoteServerDisconnect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            WebBluetoothDeviceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteServerDisconnect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteServerGetPrimaryServices_ParamsDataView {
    public:
        WebBluetoothService_RemoteServerGetPrimaryServices_ParamsDataView() { }

        WebBluetoothService_RemoteServerGetPrimaryServices_ParamsDataView(
            internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            WebBluetoothDeviceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQuantity(UserType* output) const
        {
            auto data_value = data_->quantity;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothGATTQueryQuantity>(
                data_value, output);
        }

        WebBluetoothGATTQueryQuantity quantity() const
        {
            return static_cast<WebBluetoothGATTQueryQuantity>(data_->quantity);
        }
        inline void GetServicesUuidDataView(
            ::bluetooth::mojom::UUIDDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServicesUuid(UserType* output)
        {
            auto* pointer = data_->services_uuid.Get();
            return mojo::internal::Deserialize<::bluetooth::mojom::UUIDDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParamsDataView() { }

        WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }
        inline void GetServicesDataView(
            mojo::ArrayDataView<WebBluetoothRemoteGATTServiceDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServices(UserType* output)
        {
            auto* pointer = data_->services.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTServiceDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteServiceGetCharacteristics_ParamsDataView {
    public:
        WebBluetoothService_RemoteServiceGetCharacteristics_ParamsDataView() { }

        WebBluetoothService_RemoteServiceGetCharacteristics_ParamsDataView(
            internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetServiceInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServiceInstanceId(UserType* output)
        {
            auto* pointer = data_->service_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQuantity(UserType* output) const
        {
            auto data_value = data_->quantity;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothGATTQueryQuantity>(
                data_value, output);
        }

        WebBluetoothGATTQueryQuantity quantity() const
        {
            return static_cast<WebBluetoothGATTQueryQuantity>(data_->quantity);
        }
        inline void GetCharacteristicsUuidDataView(
            ::bluetooth::mojom::UUIDDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicsUuid(UserType* output)
        {
            auto* pointer = data_->characteristics_uuid.Get();
            return mojo::internal::Deserialize<::bluetooth::mojom::UUIDDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParamsDataView() { }

        WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }
        inline void GetCharacteristicsDataView(
            mojo::ArrayDataView<WebBluetoothRemoteGATTCharacteristicDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristics(UserType* output)
        {
            auto* pointer = data_->characteristics.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicReadValue_ParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicReadValue_ParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicReadValue_ParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCharacteristicInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicInstanceId(UserType* output)
        {
            auto* pointer = data_->characteristic_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicReadValue_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicReadValue_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicReadValue_ResponseParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicReadValue_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicWriteValue_ParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicWriteValue_ParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicWriteValue_ParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCharacteristicInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicInstanceId(UserType* output)
        {
            auto* pointer = data_->characteristic_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data* data_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicStartNotifications_ParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicStartNotifications_ParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicStartNotifications_ParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCharacteristicInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicInstanceId(UserType* output)
        {
            auto* pointer = data_->characteristic_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data* data_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicStopNotifications_ParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicStopNotifications_ParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicStopNotifications_ParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCharacteristicInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicInstanceId(UserType* output)
        {
            auto* pointer = data_->characteristic_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data* data_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicGetDescriptors_ParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicGetDescriptors_ParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicGetDescriptors_ParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCharacteristicsInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicsInstanceId(UserType* output)
        {
            auto* pointer = data_->characteristics_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQuantity(UserType* output) const
        {
            auto data_value = data_->quantity;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothGATTQueryQuantity>(
                data_value, output);
        }

        WebBluetoothGATTQueryQuantity quantity() const
        {
            return static_cast<WebBluetoothGATTQueryQuantity>(data_->quantity);
        }
        inline void GetDescriptorUuidDataView(
            ::bluetooth::mojom::UUIDDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDescriptorUuid(UserType* output)
        {
            auto* pointer = data_->descriptor_uuid.Get();
            return mojo::internal::Deserialize<::bluetooth::mojom::UUIDDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParamsDataView {
    public:
        WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParamsDataView() { }

        WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParamsDataView(
            internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothResult>(
                data_value, output);
        }

        WebBluetoothResult result() const
        {
            return static_cast<WebBluetoothResult>(data_->result);
        }
        inline void GetDescriptorsDataView(
            mojo::ArrayDataView<WebBluetoothRemoteGATTDescriptorDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDescriptors(UserType* output)
        {
            auto* pointer = data_->descriptors.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothServiceClient_RemoteCharacteristicValueChanged_ParamsDataView {
    public:
        WebBluetoothServiceClient_RemoteCharacteristicValueChanged_ParamsDataView() { }

        WebBluetoothServiceClient_RemoteCharacteristicValueChanged_ParamsDataView(
            internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCharacteristicInstanceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCharacteristicInstanceId(UserType* output)
        {
            auto* pointer = data_->characteristic_instance_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebBluetoothServiceClient_GattServerDisconnected_ParamsDataView {
    public:
        WebBluetoothServiceClient_GattServerDisconnected_ParamsDataView() { }

        WebBluetoothServiceClient_GattServerDisconnected_ParamsDataView(
            internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            WebBluetoothDeviceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebBluetoothServiceClient_GattServerDisconnected_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::WebBluetoothResult>
    : public mojo::internal::EnumHashImpl<::blink::mojom::WebBluetoothResult> {
};

template <>
struct hash<::blink::mojom::WebBluetoothGATTQueryQuantity>
    : public mojo::internal::EnumHashImpl<::blink::mojom::WebBluetoothGATTQueryQuantity> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::WebBluetoothResult, ::blink::mojom::WebBluetoothResult> {
    static ::blink::mojom::WebBluetoothResult ToMojom(::blink::mojom::WebBluetoothResult input) { return input; }
    static bool FromMojom(::blink::mojom::WebBluetoothResult input, ::blink::mojom::WebBluetoothResult* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothResult, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::WebBluetoothResult, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::WebBluetoothResult>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::WebBluetoothGATTQueryQuantity, ::blink::mojom::WebBluetoothGATTQueryQuantity> {
    static ::blink::mojom::WebBluetoothGATTQueryQuantity ToMojom(::blink::mojom::WebBluetoothGATTQueryQuantity input) { return input; }
    static bool FromMojom(::blink::mojom::WebBluetoothGATTQueryQuantity input, ::blink::mojom::WebBluetoothGATTQueryQuantity* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothGATTQueryQuantity, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::WebBluetoothGATTQueryQuantity, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::WebBluetoothGATTQueryQuantity>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothScanFilterDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothScanFilterDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothScanFilter_Data);
            decltype(CallWithContext(Traits::services, input, custom_context)) in_services = CallWithContext(Traits::services, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>>(
                in_services, context);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::name_prefix, input, custom_context)) in_name_prefix = CallWithContext(Traits::name_prefix, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name_prefix, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothScanFilter_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothScanFilter_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::services, input, custom_context)) in_services = CallWithContext(Traits::services, input, custom_context);
            typename decltype(result->services)::BaseType* services_ptr;
            const mojo::internal::ContainerValidateParams services_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>>(
                in_services, buffer, &services_ptr, &services_validate_params,
                context);
            result->services.Set(services_ptr);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            decltype(CallWithContext(Traits::name_prefix, input, custom_context)) in_name_prefix = CallWithContext(Traits::name_prefix, input, custom_context);
            typename decltype(result->name_prefix)::BaseType* name_prefix_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name_prefix, buffer, &name_prefix_ptr, context);
            result->name_prefix.Set(name_prefix_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothScanFilter_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothScanFilterDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothRequestDeviceOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothRequestDeviceOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothRequestDeviceOptions_Data);
            decltype(CallWithContext(Traits::filters, input, custom_context)) in_filters = CallWithContext(Traits::filters, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothScanFilterDataView>>(
                in_filters, context);
            decltype(CallWithContext(Traits::optional_services, input, custom_context)) in_optional_services = CallWithContext(Traits::optional_services, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>>(
                in_optional_services, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothRequestDeviceOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothRequestDeviceOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::filters, input, custom_context)) in_filters = CallWithContext(Traits::filters, input, custom_context);
            typename decltype(result->filters)::BaseType* filters_ptr;
            const mojo::internal::ContainerValidateParams filters_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::WebBluetoothScanFilterDataView>>(
                in_filters, buffer, &filters_ptr, &filters_validate_params,
                context);
            result->filters.Set(filters_ptr);
            decltype(CallWithContext(Traits::optional_services, input, custom_context)) in_optional_services = CallWithContext(Traits::optional_services, input, custom_context);
            typename decltype(result->optional_services)::BaseType* optional_services_ptr;
            const mojo::internal::ContainerValidateParams optional_services_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>>(
                in_optional_services, buffer, &optional_services_ptr, &optional_services_validate_params,
                context);
            result->optional_services.Set(optional_services_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->optional_services.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null optional_services in WebBluetoothRequestDeviceOptions struct");
            result->accept_all_devices = CallWithContext(Traits::accept_all_devices, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothRequestDeviceOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothRequestDeviceOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothDeviceIdDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothDeviceIdDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothDeviceId_Data);
            decltype(CallWithContext(Traits::device_id, input, custom_context)) in_device_id = CallWithContext(Traits::device_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_device_id, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothDeviceId_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothDeviceId_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::device_id, input, custom_context)) in_device_id = CallWithContext(Traits::device_id, input, custom_context);
            typename decltype(result->device_id)::BaseType* device_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_device_id, buffer, &device_id_ptr, context);
            result->device_id.Set(device_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->device_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_id in WebBluetoothDeviceId struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothDeviceId_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothDeviceIdDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothDeviceDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothDeviceDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothDevice_Data);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_id, context);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothDevice_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothDevice_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            typename decltype(result->id)::BaseType* id_ptr;
            mojo::internal::Serialize<::blink::mojom::WebBluetoothDeviceIdDataView>(
                in_id, buffer, &id_ptr, context);
            result->id.Set(id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null id in WebBluetoothDevice struct");
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothDevice_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothDeviceDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothRemoteGATTServiceDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothRemoteGATTServiceDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothRemoteGATTService_Data);
            decltype(CallWithContext(Traits::instance_id, input, custom_context)) in_instance_id = CallWithContext(Traits::instance_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_instance_id, context);
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::bluetooth::mojom::UUIDDataView>(
                in_uuid, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothRemoteGATTService_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothRemoteGATTService_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::instance_id, input, custom_context)) in_instance_id = CallWithContext(Traits::instance_id, input, custom_context);
            typename decltype(result->instance_id)::BaseType* instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_instance_id, buffer, &instance_id_ptr, context);
            result->instance_id.Set(instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null instance_id in WebBluetoothRemoteGATTService struct");
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            typename decltype(result->uuid)::BaseType* uuid_ptr;
            mojo::internal::Serialize<::bluetooth::mojom::UUIDDataView>(
                in_uuid, buffer, &uuid_ptr, context);
            result->uuid.Set(uuid_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uuid.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uuid in WebBluetoothRemoteGATTService struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothRemoteGATTService_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothRemoteGATTServiceDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothRemoteGATTCharacteristic_Data);
            decltype(CallWithContext(Traits::instance_id, input, custom_context)) in_instance_id = CallWithContext(Traits::instance_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_instance_id, context);
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::bluetooth::mojom::UUIDDataView>(
                in_uuid, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothRemoteGATTCharacteristic_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothRemoteGATTCharacteristic_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::instance_id, input, custom_context)) in_instance_id = CallWithContext(Traits::instance_id, input, custom_context);
            typename decltype(result->instance_id)::BaseType* instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_instance_id, buffer, &instance_id_ptr, context);
            result->instance_id.Set(instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null instance_id in WebBluetoothRemoteGATTCharacteristic struct");
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            typename decltype(result->uuid)::BaseType* uuid_ptr;
            mojo::internal::Serialize<::bluetooth::mojom::UUIDDataView>(
                in_uuid, buffer, &uuid_ptr, context);
            result->uuid.Set(uuid_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uuid.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uuid in WebBluetoothRemoteGATTCharacteristic struct");
            result->properties = CallWithContext(Traits::properties, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothRemoteGATTCharacteristic_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothRemoteGATTCharacteristicDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebBluetoothRemoteGATTDescriptor_Data);
            decltype(CallWithContext(Traits::instance_id, input, custom_context)) in_instance_id = CallWithContext(Traits::instance_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_instance_id, context);
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::bluetooth::mojom::UUIDDataView>(
                in_uuid, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebBluetoothRemoteGATTDescriptor_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebBluetoothRemoteGATTDescriptor_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::instance_id, input, custom_context)) in_instance_id = CallWithContext(Traits::instance_id, input, custom_context);
            typename decltype(result->instance_id)::BaseType* instance_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_instance_id, buffer, &instance_id_ptr, context);
            result->instance_id.Set(instance_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->instance_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null instance_id in WebBluetoothRemoteGATTDescriptor struct");
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            typename decltype(result->uuid)::BaseType* uuid_ptr;
            mojo::internal::Serialize<::bluetooth::mojom::UUIDDataView>(
                in_uuid, buffer, &uuid_ptr, context);
            result->uuid.Set(uuid_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uuid.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uuid in WebBluetoothRemoteGATTDescriptor struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebBluetoothRemoteGATTDescriptor_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebBluetoothRemoteGATTDescriptorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void WebBluetoothScanFilterDataView::GetServicesDataView(
        mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>* output)
    {
        auto pointer = data_->services.Get();
        *output = mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>(pointer, context_);
    }
    inline void WebBluetoothScanFilterDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothScanFilterDataView::GetNamePrefixDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name_prefix.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebBluetoothRequestDeviceOptionsDataView::GetFiltersDataView(
        mojo::ArrayDataView<WebBluetoothScanFilterDataView>* output)
    {
        auto pointer = data_->filters.Get();
        *output = mojo::ArrayDataView<WebBluetoothScanFilterDataView>(pointer, context_);
    }
    inline void WebBluetoothRequestDeviceOptionsDataView::GetOptionalServicesDataView(
        mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>* output)
    {
        auto pointer = data_->optional_services.Get();
        *output = mojo::ArrayDataView<::bluetooth::mojom::UUIDDataView>(pointer, context_);
    }

    inline void WebBluetoothDeviceIdDataView::GetDeviceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebBluetoothDeviceDataView::GetIdDataView(
        WebBluetoothDeviceIdDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = WebBluetoothDeviceIdDataView(pointer, context_);
    }
    inline void WebBluetoothDeviceDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebBluetoothRemoteGATTServiceDataView::GetInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothRemoteGATTServiceDataView::GetUuidDataView(
        ::bluetooth::mojom::UUIDDataView* output)
    {
        auto pointer = data_->uuid.Get();
        *output = ::bluetooth::mojom::UUIDDataView(pointer, context_);
    }

    inline void WebBluetoothRemoteGATTCharacteristicDataView::GetInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothRemoteGATTCharacteristicDataView::GetUuidDataView(
        ::bluetooth::mojom::UUIDDataView* output)
    {
        auto pointer = data_->uuid.Get();
        *output = ::bluetooth::mojom::UUIDDataView(pointer, context_);
    }

    inline void WebBluetoothRemoteGATTDescriptorDataView::GetInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothRemoteGATTDescriptorDataView::GetUuidDataView(
        ::bluetooth::mojom::UUIDDataView* output)
    {
        auto pointer = data_->uuid.Get();
        *output = ::bluetooth::mojom::UUIDDataView(pointer, context_);
    }

    inline void WebBluetoothService_RequestDevice_ParamsDataView::GetOptionsDataView(
        WebBluetoothRequestDeviceOptionsDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = WebBluetoothRequestDeviceOptionsDataView(pointer, context_);
    }

    inline void WebBluetoothService_RequestDevice_ResponseParamsDataView::GetDeviceDataView(
        WebBluetoothDeviceDataView* output)
    {
        auto pointer = data_->device.Get();
        *output = WebBluetoothDeviceDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteServerConnect_ParamsDataView::GetDeviceIdDataView(
        WebBluetoothDeviceIdDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = WebBluetoothDeviceIdDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteServerDisconnect_ParamsDataView::GetDeviceIdDataView(
        WebBluetoothDeviceIdDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = WebBluetoothDeviceIdDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteServerGetPrimaryServices_ParamsDataView::GetDeviceIdDataView(
        WebBluetoothDeviceIdDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = WebBluetoothDeviceIdDataView(pointer, context_);
    }
    inline void WebBluetoothService_RemoteServerGetPrimaryServices_ParamsDataView::GetServicesUuidDataView(
        ::bluetooth::mojom::UUIDDataView* output)
    {
        auto pointer = data_->services_uuid.Get();
        *output = ::bluetooth::mojom::UUIDDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParamsDataView::GetServicesDataView(
        mojo::ArrayDataView<WebBluetoothRemoteGATTServiceDataView>* output)
    {
        auto pointer = data_->services.Get();
        *output = mojo::ArrayDataView<WebBluetoothRemoteGATTServiceDataView>(pointer, context_);
    }

    inline void WebBluetoothService_RemoteServiceGetCharacteristics_ParamsDataView::GetServiceInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->service_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothService_RemoteServiceGetCharacteristics_ParamsDataView::GetCharacteristicsUuidDataView(
        ::bluetooth::mojom::UUIDDataView* output)
    {
        auto pointer = data_->characteristics_uuid.Get();
        *output = ::bluetooth::mojom::UUIDDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParamsDataView::GetCharacteristicsDataView(
        mojo::ArrayDataView<WebBluetoothRemoteGATTCharacteristicDataView>* output)
    {
        auto pointer = data_->characteristics.Get();
        *output = mojo::ArrayDataView<WebBluetoothRemoteGATTCharacteristicDataView>(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicReadValue_ParamsDataView::GetCharacteristicInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->characteristic_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicReadValue_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicWriteValue_ParamsDataView::GetCharacteristicInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->characteristic_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothService_RemoteCharacteristicWriteValue_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicStartNotifications_ParamsDataView::GetCharacteristicInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->characteristic_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicStopNotifications_ParamsDataView::GetCharacteristicInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->characteristic_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicGetDescriptors_ParamsDataView::GetCharacteristicsInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->characteristics_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothService_RemoteCharacteristicGetDescriptors_ParamsDataView::GetDescriptorUuidDataView(
        ::bluetooth::mojom::UUIDDataView* output)
    {
        auto pointer = data_->descriptor_uuid.Get();
        *output = ::bluetooth::mojom::UUIDDataView(pointer, context_);
    }

    inline void WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParamsDataView::GetDescriptorsDataView(
        mojo::ArrayDataView<WebBluetoothRemoteGATTDescriptorDataView>* output)
    {
        auto pointer = data_->descriptors.Get();
        *output = mojo::ArrayDataView<WebBluetoothRemoteGATTDescriptorDataView>(pointer, context_);
    }

    inline void WebBluetoothServiceClient_RemoteCharacteristicValueChanged_ParamsDataView::GetCharacteristicInstanceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->characteristic_instance_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebBluetoothServiceClient_RemoteCharacteristicValueChanged_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WebBluetoothServiceClient_GattServerDisconnected_ParamsDataView::GetDeviceIdDataView(
        WebBluetoothDeviceIdDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = WebBluetoothDeviceIdDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_SHARED_H_
