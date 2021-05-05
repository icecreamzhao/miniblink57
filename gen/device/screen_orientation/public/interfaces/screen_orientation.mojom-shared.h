// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_SHARED_H_
#define DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/screen_orientation/public/interfaces/screen_orientation.mojom-shared-internal.h"
#include "device/screen_orientation/public/interfaces/screen_orientation_lock_types.mojom-shared.h"
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
namespace mojom {

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ScreenOrientationInterfaceBase {
    };

    using ScreenOrientationPtrDataView = mojo::InterfacePtrDataView<ScreenOrientationInterfaceBase>;
    using ScreenOrientationRequestDataView = mojo::InterfaceRequestDataView<ScreenOrientationInterfaceBase>;
    using ScreenOrientationAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ScreenOrientationInterfaceBase>;
    using ScreenOrientationAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ScreenOrientationInterfaceBase>;
    class ScreenOrientationListenerInterfaceBase {
    };

    using ScreenOrientationListenerPtrDataView = mojo::InterfacePtrDataView<ScreenOrientationListenerInterfaceBase>;
    using ScreenOrientationListenerRequestDataView = mojo::InterfaceRequestDataView<ScreenOrientationListenerInterfaceBase>;
    using ScreenOrientationListenerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ScreenOrientationListenerInterfaceBase>;
    using ScreenOrientationListenerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ScreenOrientationListenerInterfaceBase>;
    class ScreenOrientation_LockOrientation_ParamsDataView {
    public:
        ScreenOrientation_LockOrientation_ParamsDataView() { }

        ScreenOrientation_LockOrientation_ParamsDataView(
            internal::ScreenOrientation_LockOrientation_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrientation(UserType* output) const
        {
            auto data_value = data_->orientation;
            return mojo::internal::Deserialize<::device::mojom::ScreenOrientationLockType>(
                data_value, output);
        }

        ::device::mojom::ScreenOrientationLockType orientation() const
        {
            return static_cast<::device::mojom::ScreenOrientationLockType>(data_->orientation);
        }

    private:
        internal::ScreenOrientation_LockOrientation_Params_Data* data_ = nullptr;
    };

    class ScreenOrientation_LockOrientation_ResponseParamsDataView {
    public:
        ScreenOrientation_LockOrientation_ResponseParamsDataView() { }

        ScreenOrientation_LockOrientation_ResponseParamsDataView(
            internal::ScreenOrientation_LockOrientation_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::device::mojom::ScreenOrientationLockResult>(
                data_value, output);
        }

        ::device::mojom::ScreenOrientationLockResult result() const
        {
            return static_cast<::device::mojom::ScreenOrientationLockResult>(data_->result);
        }

    private:
        internal::ScreenOrientation_LockOrientation_ResponseParams_Data* data_ = nullptr;
    };

    class ScreenOrientation_UnlockOrientation_ParamsDataView {
    public:
        ScreenOrientation_UnlockOrientation_ParamsDataView() { }

        ScreenOrientation_UnlockOrientation_ParamsDataView(
            internal::ScreenOrientation_UnlockOrientation_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::ScreenOrientation_UnlockOrientation_Params_Data* data_ = nullptr;
    };

    class ScreenOrientationListener_Start_ParamsDataView {
    public:
        ScreenOrientationListener_Start_ParamsDataView() { }

        ScreenOrientationListener_Start_ParamsDataView(
            internal::ScreenOrientationListener_Start_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::ScreenOrientationListener_Start_Params_Data* data_ = nullptr;
    };

    class ScreenOrientationListener_Stop_ParamsDataView {
    public:
        ScreenOrientationListener_Stop_ParamsDataView() { }

        ScreenOrientationListener_Stop_ParamsDataView(
            internal::ScreenOrientationListener_Stop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::ScreenOrientationListener_Stop_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace device {
namespace mojom {

} // namespace mojom
} // namespace device

#endif // DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_SHARED_H_
