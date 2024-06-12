// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BATTERY_BATTERY_STATUS_MOJOM_SHARED_H_
#define DEVICE_BATTERY_BATTERY_STATUS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/battery/battery_status.mojom-shared-internal.h"
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
class BatteryStatusDataView;

} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::BatteryStatusDataView> {
        using Data = ::device::internal::BatteryStatus_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
class BatteryStatusDataView {
public:
    BatteryStatusDataView() { }

    BatteryStatusDataView(
        internal::BatteryStatus_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }
    bool charging() const
    {
        return data_->charging;
    }
    double charging_time() const
    {
        return data_->charging_time;
    }
    double discharging_time() const
    {
        return data_->discharging_time;
    }
    double level() const
    {
        return data_->level;
    }

private:
    internal::BatteryStatus_Data* data_ = nullptr;
};

} // namespace device

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::BatteryStatusDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::BatteryStatusDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::internal::BatteryStatus_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::internal::BatteryStatus_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::internal::BatteryStatus_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->charging = CallWithContext(Traits::charging, input, custom_context);
            result->charging_time = CallWithContext(Traits::charging_time, input, custom_context);
            result->discharging_time = CallWithContext(Traits::discharging_time, input, custom_context);
            result->level = CallWithContext(Traits::level, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::internal::BatteryStatus_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::BatteryStatusDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {

} // namespace device

#endif // DEVICE_BATTERY_BATTERY_STATUS_MOJOM_SHARED_H_
