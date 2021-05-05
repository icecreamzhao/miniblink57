// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_SHARED_H_
#define DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/usb/public/interfaces/chooser_service.mojom-shared-internal.h"
#include "device/usb/public/interfaces/device.mojom-shared.h"
#include "device/usb/public/interfaces/device_manager.mojom-shared.h"
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

} // namespace usb
} // namespace device

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace device {
namespace usb {
    // Interface base classes. They are used for type safety check.
    class ChooserServiceInterfaceBase {
    };

    using ChooserServicePtrDataView = mojo::InterfacePtrDataView<ChooserServiceInterfaceBase>;
    using ChooserServiceRequestDataView = mojo::InterfaceRequestDataView<ChooserServiceInterfaceBase>;
    using ChooserServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ChooserServiceInterfaceBase>;
    using ChooserServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ChooserServiceInterfaceBase>;
    class ChooserService_GetPermission_ParamsDataView {
    public:
        ChooserService_GetPermission_ParamsDataView() { }

        ChooserService_GetPermission_ParamsDataView(
            internal::ChooserService_GetPermission_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceFiltersDataView(
            mojo::ArrayDataView<::device::usb::DeviceFilterDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceFilters(UserType* output)
        {
            auto* pointer = data_->device_filters.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::usb::DeviceFilterDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ChooserService_GetPermission_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ChooserService_GetPermission_ResponseParamsDataView {
    public:
        ChooserService_GetPermission_ResponseParamsDataView() { }

        ChooserService_GetPermission_ResponseParamsDataView(
            internal::ChooserService_GetPermission_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultDataView(
            ::device::usb::DeviceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output)
        {
            auto* pointer = data_->result.Get();
            return mojo::internal::Deserialize<::device::usb::DeviceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::ChooserService_GetPermission_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace usb
} // namespace device

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace device {
namespace usb {

    inline void ChooserService_GetPermission_ParamsDataView::GetDeviceFiltersDataView(
        mojo::ArrayDataView<::device::usb::DeviceFilterDataView>* output)
    {
        auto pointer = data_->device_filters.Get();
        *output = mojo::ArrayDataView<::device::usb::DeviceFilterDataView>(pointer, context_);
    }

    inline void ChooserService_GetPermission_ResponseParamsDataView::GetResultDataView(
        ::device::usb::DeviceInfoDataView* output)
    {
        auto pointer = data_->result.Get();
        *output = ::device::usb::DeviceInfoDataView(pointer, context_);
    }

} // namespace usb
} // namespace device

#endif // DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_SHARED_H_
