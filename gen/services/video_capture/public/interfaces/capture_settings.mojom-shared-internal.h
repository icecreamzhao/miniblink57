// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/capture/mojo/video_capture_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace video_capture {
namespace mojom {
    namespace internal {
        class I420CaptureFormat_Data;
        class CaptureSettings_Data;

#pragma pack(push, 1)
        class I420CaptureFormat_Data {
        public:
            static I420CaptureFormat_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(I420CaptureFormat_Data))) I420CaptureFormat_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> frame_size;
            float frame_rate;
            uint8_t padfinal_[4];

        private:
            I420CaptureFormat_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~I420CaptureFormat_Data() = delete;
        };
        static_assert(sizeof(I420CaptureFormat_Data) == 24,
            "Bad sizeof(I420CaptureFormat_Data)");
        class CaptureSettings_Data {
        public:
            static CaptureSettings_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CaptureSettings_Data))) CaptureSettings_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::I420CaptureFormat_Data> format;
            int32_t resolution_change_policy;
            int32_t power_line_frequency;

        private:
            CaptureSettings_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CaptureSettings_Data() = delete;
        };
        static_assert(sizeof(CaptureSettings_Data) == 24,
            "Bad sizeof(CaptureSettings_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_SHARED_INTERNAL_H_