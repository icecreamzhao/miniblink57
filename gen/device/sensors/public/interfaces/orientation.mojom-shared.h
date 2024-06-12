// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_SHARED_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/sensors/public/interfaces/orientation.mojom-shared-internal.h"
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
    class OrientationAbsoluteSensorInterfaceBase {
    };

    using OrientationAbsoluteSensorPtrDataView = mojo::InterfacePtrDataView<OrientationAbsoluteSensorInterfaceBase>;
    using OrientationAbsoluteSensorRequestDataView = mojo::InterfaceRequestDataView<OrientationAbsoluteSensorInterfaceBase>;
    using OrientationAbsoluteSensorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<OrientationAbsoluteSensorInterfaceBase>;
    using OrientationAbsoluteSensorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<OrientationAbsoluteSensorInterfaceBase>;
    class OrientationSensorInterfaceBase {
    };

    using OrientationSensorPtrDataView = mojo::InterfacePtrDataView<OrientationSensorInterfaceBase>;
    using OrientationSensorRequestDataView = mojo::InterfaceRequestDataView<OrientationSensorInterfaceBase>;
    using OrientationSensorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<OrientationSensorInterfaceBase>;
    using OrientationSensorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<OrientationSensorInterfaceBase>;
    class OrientationAbsoluteSensor_StartPolling_ParamsDataView {
    public:
        OrientationAbsoluteSensor_StartPolling_ParamsDataView() { }

        OrientationAbsoluteSensor_StartPolling_ParamsDataView(
            internal::OrientationAbsoluteSensor_StartPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::OrientationAbsoluteSensor_StartPolling_Params_Data* data_ = nullptr;
    };

    class OrientationAbsoluteSensor_StartPolling_ResponseParamsDataView {
    public:
        OrientationAbsoluteSensor_StartPolling_ResponseParamsDataView() { }

        OrientationAbsoluteSensor_StartPolling_ResponseParamsDataView(
            internal::OrientationAbsoluteSensor_StartPolling_ResponseParams_Data* data,
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
        internal::OrientationAbsoluteSensor_StartPolling_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OrientationAbsoluteSensor_StopPolling_ParamsDataView {
    public:
        OrientationAbsoluteSensor_StopPolling_ParamsDataView() { }

        OrientationAbsoluteSensor_StopPolling_ParamsDataView(
            internal::OrientationAbsoluteSensor_StopPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::OrientationAbsoluteSensor_StopPolling_Params_Data* data_ = nullptr;
    };

    class OrientationSensor_StartPolling_ParamsDataView {
    public:
        OrientationSensor_StartPolling_ParamsDataView() { }

        OrientationSensor_StartPolling_ParamsDataView(
            internal::OrientationSensor_StartPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::OrientationSensor_StartPolling_Params_Data* data_ = nullptr;
    };

    class OrientationSensor_StartPolling_ResponseParamsDataView {
    public:
        OrientationSensor_StartPolling_ResponseParamsDataView() { }

        OrientationSensor_StartPolling_ResponseParamsDataView(
            internal::OrientationSensor_StartPolling_ResponseParams_Data* data,
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
        internal::OrientationSensor_StartPolling_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OrientationSensor_StopPolling_ParamsDataView {
    public:
        OrientationSensor_StopPolling_ParamsDataView() { }

        OrientationSensor_StopPolling_ParamsDataView(
            internal::OrientationSensor_StopPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::OrientationSensor_StopPolling_Params_Data* data_ = nullptr;
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

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_SHARED_H_
