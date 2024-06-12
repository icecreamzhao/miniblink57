// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_GPU_INFO_MOJOM_SHARED_INTERNAL_H_
#define GPU_IPC_COMMON_GPU_INFO_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "gpu/ipc/common/dx_diag_node.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/common/version.mojom-shared-internal.h"
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
namespace gpu {
namespace mojom {
    namespace internal {
        class GpuDevice_Data;
        class VideoDecodeAcceleratorSupportedProfile_Data;
        class VideoDecodeAcceleratorCapabilities_Data;
        class VideoEncodeAcceleratorSupportedProfile_Data;
        class GpuInfo_Data;

        struct CollectInfoResult_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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

        struct VideoCodecProfile_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case -1:
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
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
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
        class GpuDevice_Data {
        public:
            static GpuDevice_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuDevice_Data))) GpuDevice_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t vendor_id;
            uint32_t device_id;
            uint8_t active : 1;
            uint8_t pad2_[7];
            mojo::internal::Pointer<mojo::internal::String_Data> vendor_string;
            mojo::internal::Pointer<mojo::internal::String_Data> device_string;

        private:
            GpuDevice_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuDevice_Data() = delete;
        };
        static_assert(sizeof(GpuDevice_Data) == 40,
            "Bad sizeof(GpuDevice_Data)");
        class VideoDecodeAcceleratorSupportedProfile_Data {
        public:
            static VideoDecodeAcceleratorSupportedProfile_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecodeAcceleratorSupportedProfile_Data))) VideoDecodeAcceleratorSupportedProfile_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t profile;
            uint8_t encrypted_only : 1;
            uint8_t pad1_[3];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> max_resolution;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> min_resolution;

        private:
            VideoDecodeAcceleratorSupportedProfile_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecodeAcceleratorSupportedProfile_Data() = delete;
        };
        static_assert(sizeof(VideoDecodeAcceleratorSupportedProfile_Data) == 32,
            "Bad sizeof(VideoDecodeAcceleratorSupportedProfile_Data)");
        class VideoDecodeAcceleratorCapabilities_Data {
        public:
            static VideoDecodeAcceleratorCapabilities_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecodeAcceleratorCapabilities_Data))) VideoDecodeAcceleratorCapabilities_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::VideoDecodeAcceleratorSupportedProfile_Data>>> supported_profiles;
            uint32_t flags;
            uint8_t padfinal_[4];

        private:
            VideoDecodeAcceleratorCapabilities_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecodeAcceleratorCapabilities_Data() = delete;
        };
        static_assert(sizeof(VideoDecodeAcceleratorCapabilities_Data) == 24,
            "Bad sizeof(VideoDecodeAcceleratorCapabilities_Data)");
        class VideoEncodeAcceleratorSupportedProfile_Data {
        public:
            static VideoEncodeAcceleratorSupportedProfile_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoEncodeAcceleratorSupportedProfile_Data))) VideoEncodeAcceleratorSupportedProfile_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t profile;
            uint32_t max_framerate_numerator;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> max_resolution;
            uint32_t max_framerate_denominator;
            uint8_t padfinal_[4];

        private:
            VideoEncodeAcceleratorSupportedProfile_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoEncodeAcceleratorSupportedProfile_Data() = delete;
        };
        static_assert(sizeof(VideoEncodeAcceleratorSupportedProfile_Data) == 32,
            "Bad sizeof(VideoEncodeAcceleratorSupportedProfile_Data)");
        class GpuInfo_Data {
        public:
            static GpuInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuInfo_Data))) GpuInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> initialization_time;
            uint8_t optimus : 1;
            uint8_t amd_switchable : 1;
            uint8_t lenovo_dcute : 1;
            uint8_t software_rendering : 1;
            uint8_t direct_rendering : 1;
            uint8_t sandboxed : 1;
            uint8_t in_process_gpu : 1;
            uint8_t passthrough_cmd_decoder : 1;
            uint8_t jpeg_decode_accelerator_supported : 1;
            uint8_t pad9_[2];
            uint32_t gl_reset_notification_strategy;
            mojo::internal::Pointer<::mojo::common::mojom::internal::Version_Data> display_link_version;
            mojo::internal::Pointer<internal::GpuDevice_Data> gpu;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::GpuDevice_Data>>> secondary_gpus;
            uint64_t adapter_luid;
            mojo::internal::Pointer<mojo::internal::String_Data> driver_vendor;
            mojo::internal::Pointer<mojo::internal::String_Data> driver_version;
            mojo::internal::Pointer<mojo::internal::String_Data> driver_date;
            mojo::internal::Pointer<mojo::internal::String_Data> pixel_shader_version;
            mojo::internal::Pointer<mojo::internal::String_Data> vertex_shader_version;
            mojo::internal::Pointer<mojo::internal::String_Data> max_msaa_samples;
            mojo::internal::Pointer<mojo::internal::String_Data> machine_model_name;
            mojo::internal::Pointer<mojo::internal::String_Data> machine_model_version;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_version;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_vendor;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_renderer;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_extensions;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_ws_vendor;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_ws_version;
            mojo::internal::Pointer<mojo::internal::String_Data> gl_ws_extensions;
            int32_t process_crash_count;
            int32_t basic_info_state;
            int32_t context_info_state;
            int32_t dx_diagnostics_info_state;
            mojo::internal::Pointer<::gpu::mojom::internal::DxDiagNode_Data> dx_diagnostics;
            mojo::internal::Pointer<internal::VideoDecodeAcceleratorCapabilities_Data> video_decode_accelerator_capabilities;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::VideoEncodeAcceleratorSupportedProfile_Data>>> video_encode_accelerator_supported_profiles;
            uint64_t system_visual;
            uint64_t rgba_visual;

        private:
            GpuInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuInfo_Data() = delete;
        };
        static_assert(sizeof(GpuInfo_Data) == 232,
            "Bad sizeof(GpuInfo_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_GPU_INFO_MOJOM_SHARED_INTERNAL_H_