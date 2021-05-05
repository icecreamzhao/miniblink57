// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_SHARED_H_
#define DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/battery/battery_monitor.mojom-shared-internal.h"
#include "device/battery/battery_status.mojom-shared.h"
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

} // namespace device

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace device {
// Interface base classes. They are used for type safety check.
class BatteryMonitorInterfaceBase {
};

using BatteryMonitorPtrDataView = mojo::InterfacePtrDataView<BatteryMonitorInterfaceBase>;
using BatteryMonitorRequestDataView = mojo::InterfaceRequestDataView<BatteryMonitorInterfaceBase>;
using BatteryMonitorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<BatteryMonitorInterfaceBase>;
using BatteryMonitorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<BatteryMonitorInterfaceBase>;
class BatteryMonitor_QueryNextStatus_ParamsDataView {
public:
    BatteryMonitor_QueryNextStatus_ParamsDataView() { }

    BatteryMonitor_QueryNextStatus_ParamsDataView(
        internal::BatteryMonitor_QueryNextStatus_Params_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }

private:
    internal::BatteryMonitor_QueryNextStatus_Params_Data* data_ = nullptr;
};

class BatteryMonitor_QueryNextStatus_ResponseParamsDataView {
public:
    BatteryMonitor_QueryNextStatus_ResponseParamsDataView() { }

    BatteryMonitor_QueryNextStatus_ResponseParamsDataView(
        internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
        , context_(context)
    {
    }

    bool is_null() const { return !data_; }
    inline void GetStatusDataView(
        ::device::BatteryStatusDataView* output);

    template <typename UserType>
    WARN_UNUSED_RESULT bool ReadStatus(UserType* output)
    {
        auto* pointer = data_->status.Get();
        return mojo::internal::Deserialize<::device::BatteryStatusDataView>(
            pointer, output, context_);
    }

private:
    internal::BatteryMonitor_QueryNextStatus_ResponseParams_Data* data_ = nullptr;
    mojo::internal::SerializationContext* context_ = nullptr;
};

} // namespace device

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace device {

inline void BatteryMonitor_QueryNextStatus_ResponseParamsDataView::GetStatusDataView(
    ::device::BatteryStatusDataView* output)
{
    auto pointer = data_->status.Get();
    *output = ::device::BatteryStatusDataView(pointer, context_);
}

} // namespace device

#endif // DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_SHARED_H_
