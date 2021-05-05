// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/common/values.mojom-shared-internal.h"
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
namespace media {
namespace mojom {
    namespace internal {
        class VideoCaptureFormat_Data;
        class VideoCaptureParams_Data;
        class VideoFrameInfo_Data;

        struct ResolutionChangePolicy_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct PowerLineFrequency_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct VideoPixelStorage_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct VideoCaptureApi_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct VideoCaptureTransportType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class VideoCaptureFormat_Data {
        public:
            static VideoCaptureFormat_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureFormat_Data))) VideoCaptureFormat_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> frame_size;
            float frame_rate;
            int32_t pixel_format;
            int32_t pixel_storage;
            uint8_t padfinal_[4];

        private:
            VideoCaptureFormat_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureFormat_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureFormat_Data) == 32,
            "Bad sizeof(VideoCaptureFormat_Data)");
        class VideoCaptureParams_Data {
        public:
            static VideoCaptureParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureParams_Data))) VideoCaptureParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::VideoCaptureFormat_Data> requested_format;
            int32_t resolution_change_policy;
            int32_t power_line_frequency;

        private:
            VideoCaptureParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureParams_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureParams_Data) == 24,
            "Bad sizeof(VideoCaptureParams_Data)");
        class VideoFrameInfo_Data {
        public:
            static VideoFrameInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoFrameInfo_Data))) VideoFrameInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> timestamp;
            mojo::internal::Pointer<::mojo::common::mojom::internal::DictionaryValue_Data> metadata;
            int32_t pixel_format;
            int32_t storage_type;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> coded_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> visible_rect;

        private:
            VideoFrameInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoFrameInfo_Data() = delete;
        };
        static_assert(sizeof(VideoFrameInfo_Data) == 48,
            "Bad sizeof(VideoFrameInfo_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_SHARED_INTERNAL_H_