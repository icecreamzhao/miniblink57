// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/capture/mojo/video_capture_types.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/video_capture/public/interfaces/capture_settings.mojom-shared.h"
#include "services/video_capture/public/interfaces/device.mojom-shared-internal.h"
#include "services/video_capture/public/interfaces/receiver.mojom-shared.h"

namespace video_capture {
namespace mojom {

} // namespace mojom
} // namespace video_capture

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace video_capture {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class DeviceInterfaceBase {
    };

    using DevicePtrDataView = mojo::InterfacePtrDataView<DeviceInterfaceBase>;
    using DeviceRequestDataView = mojo::InterfaceRequestDataView<DeviceInterfaceBase>;
    using DeviceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DeviceInterfaceBase>;
    using DeviceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DeviceInterfaceBase>;
    class Device_Start_ParamsDataView {
    public:
        Device_Start_ParamsDataView() { }

        Device_Start_ParamsDataView(
            internal::Device_Start_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRequestedSettingsDataView(
            ::video_capture::mojom::CaptureSettingsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequestedSettings(UserType* output)
        {
            auto* pointer = data_->requested_settings.Get();
            return mojo::internal::Deserialize<::video_capture::mojom::CaptureSettingsDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeReceiver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::video_capture::mojom::ReceiverPtrDataView>(
                &data_->receiver, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Device_Start_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace video_capture

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace video_capture {
namespace mojom {

    inline void Device_Start_ParamsDataView::GetRequestedSettingsDataView(
        ::video_capture::mojom::CaptureSettingsDataView* output)
    {
        auto pointer = data_->requested_settings.Get();
        *output = ::video_capture::mojom::CaptureSettingsDataView(pointer, context_);
    }

} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_H_
