// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_SHARED_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/sensors/public/interfaces/light.mojom-shared-internal.h"
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
    class LightSensorInterfaceBase {
    };

    using LightSensorPtrDataView = mojo::InterfacePtrDataView<LightSensorInterfaceBase>;
    using LightSensorRequestDataView = mojo::InterfaceRequestDataView<LightSensorInterfaceBase>;
    using LightSensorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<LightSensorInterfaceBase>;
    using LightSensorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<LightSensorInterfaceBase>;
    class LightSensor_StartPolling_ParamsDataView {
    public:
        LightSensor_StartPolling_ParamsDataView() { }

        LightSensor_StartPolling_ParamsDataView(
            internal::LightSensor_StartPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::LightSensor_StartPolling_Params_Data* data_ = nullptr;
    };

    class LightSensor_StartPolling_ResponseParamsDataView {
    public:
        LightSensor_StartPolling_ResponseParamsDataView() { }

        LightSensor_StartPolling_ResponseParamsDataView(
            internal::LightSensor_StartPolling_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeMemoryHandle()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->memory_handle, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::LightSensor_StartPolling_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LightSensor_StopPolling_ParamsDataView {
    public:
        LightSensor_StopPolling_ParamsDataView() { }

        LightSensor_StopPolling_ParamsDataView(
            internal::LightSensor_StopPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::LightSensor_StopPolling_Params_Data* data_ = nullptr;
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

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_SHARED_H_
