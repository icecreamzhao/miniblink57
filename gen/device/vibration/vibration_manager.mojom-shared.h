// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_SHARED_H_
#define DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/vibration/vibration_manager.mojom-shared-internal.h"
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
class VibrationManagerInterfaceBase {
};

using VibrationManagerPtrDataView = mojo::InterfacePtrDataView<VibrationManagerInterfaceBase>;
using VibrationManagerRequestDataView = mojo::InterfaceRequestDataView<VibrationManagerInterfaceBase>;
using VibrationManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VibrationManagerInterfaceBase>;
using VibrationManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VibrationManagerInterfaceBase>;
class VibrationManager_Vibrate_ParamsDataView {
public:
    VibrationManager_Vibrate_ParamsDataView() { }

    VibrationManager_Vibrate_ParamsDataView(
        internal::VibrationManager_Vibrate_Params_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }
    int64_t milliseconds() const
    {
        return data_->milliseconds;
    }

private:
    internal::VibrationManager_Vibrate_Params_Data* data_ = nullptr;
};

class VibrationManager_Vibrate_ResponseParamsDataView {
public:
    VibrationManager_Vibrate_ResponseParamsDataView() { }

    VibrationManager_Vibrate_ResponseParamsDataView(
        internal::VibrationManager_Vibrate_ResponseParams_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }

private:
    internal::VibrationManager_Vibrate_ResponseParams_Data* data_ = nullptr;
};

class VibrationManager_Cancel_ParamsDataView {
public:
    VibrationManager_Cancel_ParamsDataView() { }

    VibrationManager_Cancel_ParamsDataView(
        internal::VibrationManager_Cancel_Params_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }

private:
    internal::VibrationManager_Cancel_Params_Data* data_ = nullptr;
};

class VibrationManager_Cancel_ResponseParamsDataView {
public:
    VibrationManager_Cancel_ResponseParamsDataView() { }

    VibrationManager_Cancel_ResponseParamsDataView(
        internal::VibrationManager_Cancel_ResponseParams_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }

private:
    internal::VibrationManager_Cancel_ResponseParams_Data* data_ = nullptr;
};

} // namespace device

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace device {

} // namespace device

#endif // DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_SHARED_H_
