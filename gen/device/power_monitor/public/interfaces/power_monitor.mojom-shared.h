// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_SHARED_H_
#define DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/power_monitor/public/interfaces/power_monitor.mojom-shared-internal.h"
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
    class PowerMonitorInterfaceBase {
    };

    using PowerMonitorPtrDataView = mojo::InterfacePtrDataView<PowerMonitorInterfaceBase>;
    using PowerMonitorRequestDataView = mojo::InterfaceRequestDataView<PowerMonitorInterfaceBase>;
    using PowerMonitorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PowerMonitorInterfaceBase>;
    using PowerMonitorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PowerMonitorInterfaceBase>;
    class PowerMonitorClientInterfaceBase {
    };

    using PowerMonitorClientPtrDataView = mojo::InterfacePtrDataView<PowerMonitorClientInterfaceBase>;
    using PowerMonitorClientRequestDataView = mojo::InterfaceRequestDataView<PowerMonitorClientInterfaceBase>;
    using PowerMonitorClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PowerMonitorClientInterfaceBase>;
    using PowerMonitorClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PowerMonitorClientInterfaceBase>;
    class PowerMonitor_SetClient_ParamsDataView {
    public:
        PowerMonitor_SetClient_ParamsDataView() { }

        PowerMonitor_SetClient_ParamsDataView(
            internal::PowerMonitor_SetClient_Params_Data* data,
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
            bool ret = mojo::internal::Deserialize<::device::mojom::PowerMonitorClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::PowerMonitor_SetClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PowerMonitorClient_PowerStateChange_ParamsDataView {
    public:
        PowerMonitorClient_PowerStateChange_ParamsDataView() { }

        PowerMonitorClient_PowerStateChange_ParamsDataView(
            internal::PowerMonitorClient_PowerStateChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool on_battery_power() const
        {
            return data_->on_battery_power;
        }

    private:
        internal::PowerMonitorClient_PowerStateChange_Params_Data* data_ = nullptr;
    };

    class PowerMonitorClient_Suspend_ParamsDataView {
    public:
        PowerMonitorClient_Suspend_ParamsDataView() { }

        PowerMonitorClient_Suspend_ParamsDataView(
            internal::PowerMonitorClient_Suspend_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PowerMonitorClient_Suspend_Params_Data* data_ = nullptr;
    };

    class PowerMonitorClient_Resume_ParamsDataView {
    public:
        PowerMonitorClient_Resume_ParamsDataView() { }

        PowerMonitorClient_Resume_ParamsDataView(
            internal::PowerMonitorClient_Resume_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PowerMonitorClient_Resume_Params_Data* data_ = nullptr;
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

#endif // DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_SHARED_H_
