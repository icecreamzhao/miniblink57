// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_SHARED_H_
#define DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/usb/public/interfaces/device.mojom-shared.h"
#include "device/usb/public/interfaces/device_manager.mojom-shared-internal.h"
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
    class DeviceFilterDataView;

    class EnumerationOptionsDataView;

} // namespace usb
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::usb::DeviceFilterDataView> {
        using Data = ::device::usb::internal::DeviceFilter_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::usb::EnumerationOptionsDataView> {
        using Data = ::device::usb::internal::EnumerationOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace usb {
    // Interface base classes. They are used for type safety check.
    class DeviceManagerInterfaceBase {
    };

    using DeviceManagerPtrDataView = mojo::InterfacePtrDataView<DeviceManagerInterfaceBase>;
    using DeviceManagerRequestDataView = mojo::InterfaceRequestDataView<DeviceManagerInterfaceBase>;
    using DeviceManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DeviceManagerInterfaceBase>;
    using DeviceManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DeviceManagerInterfaceBase>;
    class DeviceManagerClientInterfaceBase {
    };

    using DeviceManagerClientPtrDataView = mojo::InterfacePtrDataView<DeviceManagerClientInterfaceBase>;
    using DeviceManagerClientRequestDataView = mojo::InterfaceRequestDataView<DeviceManagerClientInterfaceBase>;
    using DeviceManagerClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DeviceManagerClientInterfaceBase>;
    using DeviceManagerClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DeviceManagerClientInterfaceBase>;
    class DeviceFilterDataView {
    public:
        DeviceFilterDataView() { }

        DeviceFilterDataView(
            internal::DeviceFilter_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool has_vendor_id() const
        {
            return data_->has_vendor_id;
        }
        uint16_t vendor_id() const
        {
            return data_->vendor_id;
        }
        bool has_product_id() const
        {
            return data_->has_product_id;
        }
        uint16_t product_id() const
        {
            return data_->product_id;
        }
        bool has_class_code() const
        {
            return data_->has_class_code;
        }
        uint8_t class_code() const
        {
            return data_->class_code;
        }
        bool has_subclass_code() const
        {
            return data_->has_subclass_code;
        }
        uint8_t subclass_code() const
        {
            return data_->subclass_code;
        }
        bool has_protocol_code() const
        {
            return data_->has_protocol_code;
        }
        uint8_t protocol_code() const
        {
            return data_->protocol_code;
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

    private:
        internal::DeviceFilter_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class EnumerationOptionsDataView {
    public:
        EnumerationOptionsDataView() { }

        EnumerationOptionsDataView(
            internal::EnumerationOptions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFiltersDataView(
            mojo::ArrayDataView<DeviceFilterDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFilters(UserType* output)
        {
            auto* pointer = data_->filters.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::DeviceFilterDataView>>(
                pointer, output, context_);
        }

    private:
        internal::EnumerationOptions_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceManager_GetDevices_ParamsDataView {
    public:
        DeviceManager_GetDevices_ParamsDataView() { }

        DeviceManager_GetDevices_ParamsDataView(
            internal::DeviceManager_GetDevices_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOptionsDataView(
            EnumerationOptionsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::device::usb::EnumerationOptionsDataView>(
                pointer, output, context_);
        }

    private:
        internal::DeviceManager_GetDevices_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceManager_GetDevices_ResponseParamsDataView {
    public:
        DeviceManager_GetDevices_ResponseParamsDataView() { }

        DeviceManager_GetDevices_ResponseParamsDataView(
            internal::DeviceManager_GetDevices_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultsDataView(
            mojo::ArrayDataView<::device::usb::DeviceInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResults(UserType* output)
        {
            auto* pointer = data_->results.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::DeviceInfoDataView>>(
                pointer, output, context_);
        }

    private:
        internal::DeviceManager_GetDevices_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceManager_GetDevice_ParamsDataView {
    public:
        DeviceManager_GetDevice_ParamsDataView() { }

        DeviceManager_GetDevice_ParamsDataView(
            internal::DeviceManager_GetDevice_Params_Data* data,
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
        template <typename UserType>
        UserType TakeDeviceRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::usb::DeviceRequestDataView>(
                &data_->device_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DeviceManager_GetDevice_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceManager_SetClient_ParamsDataView {
    public:
        DeviceManager_SetClient_ParamsDataView() { }

        DeviceManager_SetClient_ParamsDataView(
            internal::DeviceManager_SetClient_Params_Data* data,
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
            bool ret = mojo::internal::Deserialize<::device::usb::DeviceManagerClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DeviceManager_SetClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceManagerClient_OnDeviceAdded_ParamsDataView {
    public:
        DeviceManagerClient_OnDeviceAdded_ParamsDataView() { }

        DeviceManagerClient_OnDeviceAdded_ParamsDataView(
            internal::DeviceManagerClient_OnDeviceAdded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceInfoDataView(
            ::device::usb::DeviceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceInfo(UserType* output)
        {
            auto* pointer = data_->device_info.Get();
            return mojo::internal::Deserialize<::device::usb::DeviceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::DeviceManagerClient_OnDeviceAdded_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceManagerClient_OnDeviceRemoved_ParamsDataView {
    public:
        DeviceManagerClient_OnDeviceRemoved_ParamsDataView() { }

        DeviceManagerClient_OnDeviceRemoved_ParamsDataView(
            internal::DeviceManagerClient_OnDeviceRemoved_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceInfoDataView(
            ::device::usb::DeviceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceInfo(UserType* output)
        {
            auto* pointer = data_->device_info.Get();
            return mojo::internal::Deserialize<::device::usb::DeviceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::DeviceManagerClient_OnDeviceRemoved_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace usb
} // namespace device

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::DeviceFilterDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::DeviceFilterDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::DeviceFilter_Data);
            decltype(CallWithContext(Traits::serial_number, input, custom_context)) in_serial_number = CallWithContext(Traits::serial_number, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_serial_number, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::DeviceFilter_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::DeviceFilter_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->has_vendor_id = CallWithContext(Traits::has_vendor_id, input, custom_context);
            result->vendor_id = CallWithContext(Traits::vendor_id, input, custom_context);
            result->has_product_id = CallWithContext(Traits::has_product_id, input, custom_context);
            result->product_id = CallWithContext(Traits::product_id, input, custom_context);
            result->has_class_code = CallWithContext(Traits::has_class_code, input, custom_context);
            result->class_code = CallWithContext(Traits::class_code, input, custom_context);
            result->has_subclass_code = CallWithContext(Traits::has_subclass_code, input, custom_context);
            result->subclass_code = CallWithContext(Traits::subclass_code, input, custom_context);
            result->has_protocol_code = CallWithContext(Traits::has_protocol_code, input, custom_context);
            result->protocol_code = CallWithContext(Traits::protocol_code, input, custom_context);
            decltype(CallWithContext(Traits::serial_number, input, custom_context)) in_serial_number = CallWithContext(Traits::serial_number, input, custom_context);
            typename decltype(result->serial_number)::BaseType* serial_number_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_serial_number, buffer, &serial_number_ptr, context);
            result->serial_number.Set(serial_number_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::DeviceFilter_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::DeviceFilterDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::usb::EnumerationOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::usb::EnumerationOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::usb::internal::EnumerationOptions_Data);
            decltype(CallWithContext(Traits::filters, input, custom_context)) in_filters = CallWithContext(Traits::filters, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::DeviceFilterDataView>>(
                in_filters, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::usb::internal::EnumerationOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::usb::internal::EnumerationOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::filters, input, custom_context)) in_filters = CallWithContext(Traits::filters, input, custom_context);
            typename decltype(result->filters)::BaseType* filters_ptr;
            const mojo::internal::ContainerValidateParams filters_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::DeviceFilterDataView>>(
                in_filters, buffer, &filters_ptr, &filters_validate_params,
                context);
            result->filters.Set(filters_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::usb::internal::EnumerationOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::usb::EnumerationOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace usb {

    inline void DeviceFilterDataView::GetSerialNumberDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->serial_number.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void EnumerationOptionsDataView::GetFiltersDataView(
        mojo::ArrayDataView<DeviceFilterDataView>* output)
    {
        auto pointer = data_->filters.Get();
        *output = mojo::ArrayDataView<DeviceFilterDataView>(pointer, context_);
    }

    inline void DeviceManager_GetDevices_ParamsDataView::GetOptionsDataView(
        EnumerationOptionsDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = EnumerationOptionsDataView(pointer, context_);
    }

    inline void DeviceManager_GetDevices_ResponseParamsDataView::GetResultsDataView(
        mojo::ArrayDataView<::device::usb::DeviceInfoDataView>* output)
    {
        auto pointer = data_->results.Get();
        *output = mojo::ArrayDataView<::device::usb::DeviceInfoDataView>(pointer, context_);
    }

    inline void DeviceManager_GetDevice_ParamsDataView::GetGuidDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->guid.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void DeviceManagerClient_OnDeviceAdded_ParamsDataView::GetDeviceInfoDataView(
        ::device::usb::DeviceInfoDataView* output)
    {
        auto pointer = data_->device_info.Get();
        *output = ::device::usb::DeviceInfoDataView(pointer, context_);
    }

    inline void DeviceManagerClient_OnDeviceRemoved_ParamsDataView::GetDeviceInfoDataView(
        ::device::usb::DeviceInfoDataView* output)
    {
        auto pointer = data_->device_info.Get();
        *output = ::device::usb::DeviceInfoDataView(pointer, context_);
    }

} // namespace usb
} // namespace device

#endif // DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_SHARED_H_
