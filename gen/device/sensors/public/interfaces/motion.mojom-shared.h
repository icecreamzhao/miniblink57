// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_SHARED_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/sensors/public/interfaces/motion.mojom-shared-internal.h"
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
    class MotionSensorInterfaceBase {
    };

    using MotionSensorPtrDataView = mojo::InterfacePtrDataView<MotionSensorInterfaceBase>;
    using MotionSensorRequestDataView = mojo::InterfaceRequestDataView<MotionSensorInterfaceBase>;
    using MotionSensorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MotionSensorInterfaceBase>;
    using MotionSensorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MotionSensorInterfaceBase>;
    class MotionSensor_StartPolling_ParamsDataView {
    public:
        MotionSensor_StartPolling_ParamsDataView() { }

        MotionSensor_StartPolling_ParamsDataView(
            internal::MotionSensor_StartPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::MotionSensor_StartPolling_Params_Data* data_ = nullptr;
    };

    class MotionSensor_StartPolling_ResponseParamsDataView {
    public:
        MotionSensor_StartPolling_ResponseParamsDataView() { }

        MotionSensor_StartPolling_ResponseParamsDataView(
            internal::MotionSensor_StartPolling_ResponseParams_Data* data,
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
        internal::MotionSensor_StartPolling_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MotionSensor_StopPolling_ParamsDataView {
    public:
        MotionSensor_StopPolling_ParamsDataView() { }

        MotionSensor_StopPolling_ParamsDataView(
            internal::MotionSensor_StopPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::MotionSensor_StopPolling_Params_Data* data_ = nullptr;
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

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_SHARED_H_
