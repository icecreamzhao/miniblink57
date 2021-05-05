// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_SHARED_H_
#define DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/time_zone_monitor/public/interfaces/time_zone_monitor.mojom-shared-internal.h"
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
    class TimeZoneMonitorInterfaceBase {
    };

    using TimeZoneMonitorPtrDataView = mojo::InterfacePtrDataView<TimeZoneMonitorInterfaceBase>;
    using TimeZoneMonitorRequestDataView = mojo::InterfaceRequestDataView<TimeZoneMonitorInterfaceBase>;
    using TimeZoneMonitorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<TimeZoneMonitorInterfaceBase>;
    using TimeZoneMonitorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<TimeZoneMonitorInterfaceBase>;
    class TimeZoneMonitorClientInterfaceBase {
    };

    using TimeZoneMonitorClientPtrDataView = mojo::InterfacePtrDataView<TimeZoneMonitorClientInterfaceBase>;
    using TimeZoneMonitorClientRequestDataView = mojo::InterfaceRequestDataView<TimeZoneMonitorClientInterfaceBase>;
    using TimeZoneMonitorClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<TimeZoneMonitorClientInterfaceBase>;
    using TimeZoneMonitorClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<TimeZoneMonitorClientInterfaceBase>;
    class TimeZoneMonitor_AddClient_ParamsDataView {
    public:
        TimeZoneMonitor_AddClient_ParamsDataView() { }

        TimeZoneMonitor_AddClient_ParamsDataView(
            internal::TimeZoneMonitor_AddClient_Params_Data* data,
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
            bool ret = mojo::internal::Deserialize<::device::mojom::TimeZoneMonitorClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::TimeZoneMonitor_AddClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TimeZoneMonitorClient_OnTimeZoneChange_ParamsDataView {
    public:
        TimeZoneMonitorClient_OnTimeZoneChange_ParamsDataView() { }

        TimeZoneMonitorClient_OnTimeZoneChange_ParamsDataView(
            internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTzInfoDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTzInfo(UserType* output)
        {
            auto* pointer = data_->tz_info.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace device {
namespace mojom {

    inline void TimeZoneMonitorClient_OnTimeZoneChange_ParamsDataView::GetTzInfoDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->tz_info.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace device

#endif // DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_SHARED_H_
