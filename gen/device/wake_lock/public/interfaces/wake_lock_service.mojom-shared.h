// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_SHARED_H_
#define DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/wake_lock/public/interfaces/wake_lock_service.mojom-shared-internal.h"
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
    class WakeLockServiceInterfaceBase {
    };

    using WakeLockServicePtrDataView = mojo::InterfacePtrDataView<WakeLockServiceInterfaceBase>;
    using WakeLockServiceRequestDataView = mojo::InterfaceRequestDataView<WakeLockServiceInterfaceBase>;
    using WakeLockServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WakeLockServiceInterfaceBase>;
    using WakeLockServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WakeLockServiceInterfaceBase>;
    class WakeLockService_RequestWakeLock_ParamsDataView {
    public:
        WakeLockService_RequestWakeLock_ParamsDataView() { }

        WakeLockService_RequestWakeLock_ParamsDataView(
            internal::WakeLockService_RequestWakeLock_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WakeLockService_RequestWakeLock_Params_Data* data_ = nullptr;
    };

    class WakeLockService_CancelWakeLock_ParamsDataView {
    public:
        WakeLockService_CancelWakeLock_ParamsDataView() { }

        WakeLockService_CancelWakeLock_ParamsDataView(
            internal::WakeLockService_CancelWakeLock_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WakeLockService_CancelWakeLock_Params_Data* data_ = nullptr;
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

#endif // DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_SHARED_H_
