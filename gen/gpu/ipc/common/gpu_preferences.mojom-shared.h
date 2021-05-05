// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_SHARED_H_
#define GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/gpu_preferences.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace gpu {
namespace mojom {
    class GpuPreferencesDataView;

} // namespace mojom
} // namespace gpu

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gpu::mojom::GpuPreferencesDataView> {
        using Data = ::gpu::mojom::internal::GpuPreferences_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gpu {
namespace mojom {

    enum class VpxDecodeVendors : int32_t {
        VPX_VENDOR_NONE = 0,
        VPX_VENDOR_MICROSOFT = 1,
        VPX_VENDOR_AMD = 2,
        VPX_VENDOR_ALL = 3,
    };

    inline std::ostream& operator<<(std::ostream& os, VpxDecodeVendors value)
    {
        switch (value) {
        case VpxDecodeVendors::VPX_VENDOR_NONE:
            return os << "VpxDecodeVendors::VPX_VENDOR_NONE";
        case VpxDecodeVendors::VPX_VENDOR_MICROSOFT:
            return os << "VpxDecodeVendors::VPX_VENDOR_MICROSOFT";
        case VpxDecodeVendors::VPX_VENDOR_AMD:
            return os << "VpxDecodeVendors::VPX_VENDOR_AMD";
        case VpxDecodeVendors::VPX_VENDOR_ALL:
            return os << "VpxDecodeVendors::VPX_VENDOR_ALL";
        default:
            return os << "Unknown VpxDecodeVendors value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VpxDecodeVendors value)
    {
        return internal::VpxDecodeVendors_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class GpuPreferencesDataView {
    public:
        GpuPreferencesDataView() { }

        GpuPreferencesDataView(
            internal::GpuPreferences_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool single_process() const
        {
            return data_->single_process;
        }
        bool in_process_gpu() const
        {
            return data_->in_process_gpu;
        }
        bool ui_prioritize_in_gpu_process() const
        {
            return data_->ui_prioritize_in_gpu_process;
        }
        bool disable_accelerated_video_decode() const
        {
            return data_->disable_accelerated_video_decode;
        }
        bool disable_vaapi_accelerated_video_encode() const
        {
            return data_->disable_vaapi_accelerated_video_encode;
        }
        bool disable_web_rtc_hw_encoding() const
        {
            return data_->disable_web_rtc_hw_encoding;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEnableAcceleratedVpxDecode(UserType* output) const
        {
            auto data_value = data_->enable_accelerated_vpx_decode;
            return mojo::internal::Deserialize<::gpu::mojom::VpxDecodeVendors>(
                data_value, output);
        }

        VpxDecodeVendors enable_accelerated_vpx_decode() const
        {
            return static_cast<VpxDecodeVendors>(data_->enable_accelerated_vpx_decode);
        }
        bool enable_low_latency_dxva() const
        {
            return data_->enable_low_latency_dxva;
        }
        bool enable_zero_copy_dxgi_video() const
        {
            return data_->enable_zero_copy_dxgi_video;
        }
        bool enable_nv12_dxgi_video() const
        {
            return data_->enable_nv12_dxgi_video;
        }
        bool compile_shader_always_succeeds() const
        {
            return data_->compile_shader_always_succeeds;
        }
        bool disable_gl_error_limit() const
        {
            return data_->disable_gl_error_limit;
        }
        bool disable_glsl_translator() const
        {
            return data_->disable_glsl_translator;
        }
        bool disable_gpu_driver_bug_workarounds() const
        {
            return data_->disable_gpu_driver_bug_workarounds;
        }
        bool disable_shader_name_hashing() const
        {
            return data_->disable_shader_name_hashing;
        }
        bool enable_gpu_command_logging() const
        {
            return data_->enable_gpu_command_logging;
        }
        bool enable_gpu_debugging() const
        {
            return data_->enable_gpu_debugging;
        }
        bool enable_gpu_service_logging_gpu() const
        {
            return data_->enable_gpu_service_logging_gpu;
        }
        bool enable_gpu_driver_debug_logging() const
        {
            return data_->enable_gpu_driver_debug_logging;
        }
        bool disable_gpu_program_cache() const
        {
            return data_->disable_gpu_program_cache;
        }
        bool enforce_gl_minimums() const
        {
            return data_->enforce_gl_minimums;
        }
        uint32_t force_gpu_mem_available() const
        {
            return data_->force_gpu_mem_available;
        }
        uint32_t gpu_program_cache_size() const
        {
            return data_->gpu_program_cache_size;
        }
        bool disable_gpu_shader_disk_cache() const
        {
            return data_->disable_gpu_shader_disk_cache;
        }
        bool enable_threaded_texture_mailboxes() const
        {
            return data_->enable_threaded_texture_mailboxes;
        }
        bool gl_shader_interm_output() const
        {
            return data_->gl_shader_interm_output;
        }
        bool emulate_shader_precision() const
        {
            return data_->emulate_shader_precision;
        }
        bool enable_gpu_service_logging() const
        {
            return data_->enable_gpu_service_logging;
        }
        bool enable_gpu_service_tracing() const
        {
            return data_->enable_gpu_service_tracing;
        }
        bool enable_es3_apis() const
        {
            return data_->enable_es3_apis;
        }
        bool use_passthrough_cmd_decoder() const
        {
            return data_->use_passthrough_cmd_decoder;
        }

    private:
        internal::GpuPreferences_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace gpu

namespace std {

template <>
struct hash<::gpu::mojom::VpxDecodeVendors>
    : public mojo::internal::EnumHashImpl<::gpu::mojom::VpxDecodeVendors> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::gpu::mojom::VpxDecodeVendors, ::gpu::mojom::VpxDecodeVendors> {
    static ::gpu::mojom::VpxDecodeVendors ToMojom(::gpu::mojom::VpxDecodeVendors input) { return input; }
    static bool FromMojom(::gpu::mojom::VpxDecodeVendors input, ::gpu::mojom::VpxDecodeVendors* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::VpxDecodeVendors, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gpu::mojom::VpxDecodeVendors, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gpu::mojom::VpxDecodeVendors>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::GpuPreferencesDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::GpuPreferencesDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::GpuPreferences_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::GpuPreferences_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::GpuPreferences_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->single_process = CallWithContext(Traits::single_process, input, custom_context);
            result->in_process_gpu = CallWithContext(Traits::in_process_gpu, input, custom_context);
            result->ui_prioritize_in_gpu_process = CallWithContext(Traits::ui_prioritize_in_gpu_process, input, custom_context);
            result->disable_accelerated_video_decode = CallWithContext(Traits::disable_accelerated_video_decode, input, custom_context);
            result->disable_vaapi_accelerated_video_encode = CallWithContext(Traits::disable_vaapi_accelerated_video_encode, input, custom_context);
            result->disable_web_rtc_hw_encoding = CallWithContext(Traits::disable_web_rtc_hw_encoding, input, custom_context);
            mojo::internal::Serialize<::gpu::mojom::VpxDecodeVendors>(
                CallWithContext(Traits::enable_accelerated_vpx_decode, input, custom_context), &result->enable_accelerated_vpx_decode);
            result->enable_low_latency_dxva = CallWithContext(Traits::enable_low_latency_dxva, input, custom_context);
            result->enable_zero_copy_dxgi_video = CallWithContext(Traits::enable_zero_copy_dxgi_video, input, custom_context);
            result->enable_nv12_dxgi_video = CallWithContext(Traits::enable_nv12_dxgi_video, input, custom_context);
            result->compile_shader_always_succeeds = CallWithContext(Traits::compile_shader_always_succeeds, input, custom_context);
            result->disable_gl_error_limit = CallWithContext(Traits::disable_gl_error_limit, input, custom_context);
            result->disable_glsl_translator = CallWithContext(Traits::disable_glsl_translator, input, custom_context);
            result->disable_gpu_driver_bug_workarounds = CallWithContext(Traits::disable_gpu_driver_bug_workarounds, input, custom_context);
            result->disable_shader_name_hashing = CallWithContext(Traits::disable_shader_name_hashing, input, custom_context);
            result->enable_gpu_command_logging = CallWithContext(Traits::enable_gpu_command_logging, input, custom_context);
            result->enable_gpu_debugging = CallWithContext(Traits::enable_gpu_debugging, input, custom_context);
            result->enable_gpu_service_logging_gpu = CallWithContext(Traits::enable_gpu_service_logging_gpu, input, custom_context);
            result->enable_gpu_driver_debug_logging = CallWithContext(Traits::enable_gpu_driver_debug_logging, input, custom_context);
            result->disable_gpu_program_cache = CallWithContext(Traits::disable_gpu_program_cache, input, custom_context);
            result->enforce_gl_minimums = CallWithContext(Traits::enforce_gl_minimums, input, custom_context);
            result->force_gpu_mem_available = CallWithContext(Traits::force_gpu_mem_available, input, custom_context);
            result->gpu_program_cache_size = CallWithContext(Traits::gpu_program_cache_size, input, custom_context);
            result->disable_gpu_shader_disk_cache = CallWithContext(Traits::disable_gpu_shader_disk_cache, input, custom_context);
            result->enable_threaded_texture_mailboxes = CallWithContext(Traits::enable_threaded_texture_mailboxes, input, custom_context);
            result->gl_shader_interm_output = CallWithContext(Traits::gl_shader_interm_output, input, custom_context);
            result->emulate_shader_precision = CallWithContext(Traits::emulate_shader_precision, input, custom_context);
            result->enable_gpu_service_logging = CallWithContext(Traits::enable_gpu_service_logging, input, custom_context);
            result->enable_gpu_service_tracing = CallWithContext(Traits::enable_gpu_service_tracing, input, custom_context);
            result->enable_es3_apis = CallWithContext(Traits::enable_es3_apis, input, custom_context);
            result->use_passthrough_cmd_decoder = CallWithContext(Traits::use_passthrough_cmd_decoder, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::GpuPreferences_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::GpuPreferencesDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gpu {
namespace mojom {

} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_SHARED_H_
