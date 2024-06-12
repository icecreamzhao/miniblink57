// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/capture/mojo/video_capture_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/video_capture/public/interfaces/capture_settings.mojom-shared-internal.h"
#include "services/video_capture/public/interfaces/receiver.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace video_capture {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kDevice_Start_Name = 0;
        class Device_Start_Params_Data {
        public:
            static Device_Start_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Start_Params_Data))) Device_Start_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::video_capture::mojom::internal::CaptureSettings_Data> requested_settings;
            mojo::internal::Interface_Data receiver;

        private:
            Device_Start_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Start_Params_Data() = delete;
        };
        static_assert(sizeof(Device_Start_Params_Data) == 24,
            "Bad sizeof(Device_Start_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_INTERNAL_H_