// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_SHARED_INTERNAL_H_
#define GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace gpu {
namespace mojom {
    namespace internal {
        class GpuPreferences_Data;

        struct VpxDecodeVendors_Data {
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

#pragma pack(push, 1)
        class GpuPreferences_Data {
        public:
            static GpuPreferences_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuPreferences_Data))) GpuPreferences_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t single_process : 1;
            uint8_t in_process_gpu : 1;
            uint8_t ui_prioritize_in_gpu_process : 1;
            uint8_t disable_accelerated_video_decode : 1;
            uint8_t disable_vaapi_accelerated_video_encode : 1;
            uint8_t disable_web_rtc_hw_encoding : 1;
            uint8_t enable_low_latency_dxva : 1;
            uint8_t enable_zero_copy_dxgi_video : 1;
            uint8_t enable_nv12_dxgi_video : 1;
            uint8_t compile_shader_always_succeeds : 1;
            uint8_t disable_gl_error_limit : 1;
            uint8_t disable_glsl_translator : 1;
            uint8_t disable_gpu_driver_bug_workarounds : 1;
            uint8_t disable_shader_name_hashing : 1;
            uint8_t enable_gpu_command_logging : 1;
            uint8_t enable_gpu_debugging : 1;
            uint8_t enable_gpu_service_logging_gpu : 1;
            uint8_t enable_gpu_driver_debug_logging : 1;
            uint8_t disable_gpu_program_cache : 1;
            uint8_t enforce_gl_minimums : 1;
            uint8_t disable_gpu_shader_disk_cache : 1;
            uint8_t enable_threaded_texture_mailboxes : 1;
            uint8_t gl_shader_interm_output : 1;
            uint8_t emulate_shader_precision : 1;
            uint8_t enable_gpu_service_logging : 1;
            uint8_t enable_gpu_service_tracing : 1;
            uint8_t enable_es3_apis : 1;
            uint8_t use_passthrough_cmd_decoder : 1;
            int32_t enable_accelerated_vpx_decode;
            uint32_t force_gpu_mem_available;
            uint32_t gpu_program_cache_size;

        private:
            GpuPreferences_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuPreferences_Data() = delete;
        };
        static_assert(sizeof(GpuPreferences_Data) == 24,
            "Bad sizeof(GpuPreferences_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_SHARED_INTERNAL_H_