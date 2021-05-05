// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_H_
#define GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/gpu_preferences.mojom-shared.h"
#include "gpu/ipc/common/surface_handle.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include <string>
#include <vector>

namespace gpu {
namespace mojom {
    class GpuPreferences;
    using GpuPreferencesPtr = mojo::StructPtr<GpuPreferences>;

    class GpuPreferences {
    public:
        using DataView = GpuPreferencesDataView;
        using Data_ = internal::GpuPreferences_Data;

        static GpuPreferencesPtr New();

        template <typename U>
        static GpuPreferencesPtr From(const U& u)
        {
            return mojo::TypeConverter<GpuPreferencesPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GpuPreferences>::Convert(*this);
        }

        GpuPreferences();
        ~GpuPreferences();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GpuPreferencesPtr>
        GpuPreferencesPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GpuPreferences>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GpuPreferences::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GpuPreferences::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool single_process;
        bool in_process_gpu;
        bool ui_prioritize_in_gpu_process;
        bool disable_accelerated_video_decode;
        bool disable_vaapi_accelerated_video_encode;
        bool disable_web_rtc_hw_encoding;
        gpu::GpuPreferences::VpxDecodeVendors enable_accelerated_vpx_decode;
        bool enable_low_latency_dxva;
        bool enable_zero_copy_dxgi_video;
        bool enable_nv12_dxgi_video;
        bool compile_shader_always_succeeds;
        bool disable_gl_error_limit;
        bool disable_glsl_translator;
        bool disable_gpu_driver_bug_workarounds;
        bool disable_shader_name_hashing;
        bool enable_gpu_command_logging;
        bool enable_gpu_debugging;
        bool enable_gpu_service_logging_gpu;
        bool enable_gpu_driver_debug_logging;
        bool disable_gpu_program_cache;
        bool enforce_gl_minimums;
        uint32_t force_gpu_mem_available;
        uint32_t gpu_program_cache_size;
        bool disable_gpu_shader_disk_cache;
        bool enable_threaded_texture_mailboxes;
        bool gl_shader_interm_output;
        bool emulate_shader_precision;
        bool enable_gpu_service_logging;
        bool enable_gpu_service_tracing;
        bool enable_es3_apis;
        bool use_passthrough_cmd_decoder;
    };

    template <typename StructPtrType>
    GpuPreferencesPtr GpuPreferences::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->single_process = mojo::internal::Clone(single_process);
        rv->in_process_gpu = mojo::internal::Clone(in_process_gpu);
        rv->ui_prioritize_in_gpu_process = mojo::internal::Clone(ui_prioritize_in_gpu_process);
        rv->disable_accelerated_video_decode = mojo::internal::Clone(disable_accelerated_video_decode);
        rv->disable_vaapi_accelerated_video_encode = mojo::internal::Clone(disable_vaapi_accelerated_video_encode);
        rv->disable_web_rtc_hw_encoding = mojo::internal::Clone(disable_web_rtc_hw_encoding);
        rv->enable_accelerated_vpx_decode = mojo::internal::Clone(enable_accelerated_vpx_decode);
        rv->enable_low_latency_dxva = mojo::internal::Clone(enable_low_latency_dxva);
        rv->enable_zero_copy_dxgi_video = mojo::internal::Clone(enable_zero_copy_dxgi_video);
        rv->enable_nv12_dxgi_video = mojo::internal::Clone(enable_nv12_dxgi_video);
        rv->compile_shader_always_succeeds = mojo::internal::Clone(compile_shader_always_succeeds);
        rv->disable_gl_error_limit = mojo::internal::Clone(disable_gl_error_limit);
        rv->disable_glsl_translator = mojo::internal::Clone(disable_glsl_translator);
        rv->disable_gpu_driver_bug_workarounds = mojo::internal::Clone(disable_gpu_driver_bug_workarounds);
        rv->disable_shader_name_hashing = mojo::internal::Clone(disable_shader_name_hashing);
        rv->enable_gpu_command_logging = mojo::internal::Clone(enable_gpu_command_logging);
        rv->enable_gpu_debugging = mojo::internal::Clone(enable_gpu_debugging);
        rv->enable_gpu_service_logging_gpu = mojo::internal::Clone(enable_gpu_service_logging_gpu);
        rv->enable_gpu_driver_debug_logging = mojo::internal::Clone(enable_gpu_driver_debug_logging);
        rv->disable_gpu_program_cache = mojo::internal::Clone(disable_gpu_program_cache);
        rv->enforce_gl_minimums = mojo::internal::Clone(enforce_gl_minimums);
        rv->force_gpu_mem_available = mojo::internal::Clone(force_gpu_mem_available);
        rv->gpu_program_cache_size = mojo::internal::Clone(gpu_program_cache_size);
        rv->disable_gpu_shader_disk_cache = mojo::internal::Clone(disable_gpu_shader_disk_cache);
        rv->enable_threaded_texture_mailboxes = mojo::internal::Clone(enable_threaded_texture_mailboxes);
        rv->gl_shader_interm_output = mojo::internal::Clone(gl_shader_interm_output);
        rv->emulate_shader_precision = mojo::internal::Clone(emulate_shader_precision);
        rv->enable_gpu_service_logging = mojo::internal::Clone(enable_gpu_service_logging);
        rv->enable_gpu_service_tracing = mojo::internal::Clone(enable_gpu_service_tracing);
        rv->enable_es3_apis = mojo::internal::Clone(enable_es3_apis);
        rv->use_passthrough_cmd_decoder = mojo::internal::Clone(use_passthrough_cmd_decoder);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GpuPreferences>::value>::type*>
    bool GpuPreferences::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->single_process, other.single_process))
            return false;
        if (!mojo::internal::Equals(this->in_process_gpu, other.in_process_gpu))
            return false;
        if (!mojo::internal::Equals(this->ui_prioritize_in_gpu_process, other.ui_prioritize_in_gpu_process))
            return false;
        if (!mojo::internal::Equals(this->disable_accelerated_video_decode, other.disable_accelerated_video_decode))
            return false;
        if (!mojo::internal::Equals(this->disable_vaapi_accelerated_video_encode, other.disable_vaapi_accelerated_video_encode))
            return false;
        if (!mojo::internal::Equals(this->disable_web_rtc_hw_encoding, other.disable_web_rtc_hw_encoding))
            return false;
        if (!mojo::internal::Equals(this->enable_accelerated_vpx_decode, other.enable_accelerated_vpx_decode))
            return false;
        if (!mojo::internal::Equals(this->enable_low_latency_dxva, other.enable_low_latency_dxva))
            return false;
        if (!mojo::internal::Equals(this->enable_zero_copy_dxgi_video, other.enable_zero_copy_dxgi_video))
            return false;
        if (!mojo::internal::Equals(this->enable_nv12_dxgi_video, other.enable_nv12_dxgi_video))
            return false;
        if (!mojo::internal::Equals(this->compile_shader_always_succeeds, other.compile_shader_always_succeeds))
            return false;
        if (!mojo::internal::Equals(this->disable_gl_error_limit, other.disable_gl_error_limit))
            return false;
        if (!mojo::internal::Equals(this->disable_glsl_translator, other.disable_glsl_translator))
            return false;
        if (!mojo::internal::Equals(this->disable_gpu_driver_bug_workarounds, other.disable_gpu_driver_bug_workarounds))
            return false;
        if (!mojo::internal::Equals(this->disable_shader_name_hashing, other.disable_shader_name_hashing))
            return false;
        if (!mojo::internal::Equals(this->enable_gpu_command_logging, other.enable_gpu_command_logging))
            return false;
        if (!mojo::internal::Equals(this->enable_gpu_debugging, other.enable_gpu_debugging))
            return false;
        if (!mojo::internal::Equals(this->enable_gpu_service_logging_gpu, other.enable_gpu_service_logging_gpu))
            return false;
        if (!mojo::internal::Equals(this->enable_gpu_driver_debug_logging, other.enable_gpu_driver_debug_logging))
            return false;
        if (!mojo::internal::Equals(this->disable_gpu_program_cache, other.disable_gpu_program_cache))
            return false;
        if (!mojo::internal::Equals(this->enforce_gl_minimums, other.enforce_gl_minimums))
            return false;
        if (!mojo::internal::Equals(this->force_gpu_mem_available, other.force_gpu_mem_available))
            return false;
        if (!mojo::internal::Equals(this->gpu_program_cache_size, other.gpu_program_cache_size))
            return false;
        if (!mojo::internal::Equals(this->disable_gpu_shader_disk_cache, other.disable_gpu_shader_disk_cache))
            return false;
        if (!mojo::internal::Equals(this->enable_threaded_texture_mailboxes, other.enable_threaded_texture_mailboxes))
            return false;
        if (!mojo::internal::Equals(this->gl_shader_interm_output, other.gl_shader_interm_output))
            return false;
        if (!mojo::internal::Equals(this->emulate_shader_precision, other.emulate_shader_precision))
            return false;
        if (!mojo::internal::Equals(this->enable_gpu_service_logging, other.enable_gpu_service_logging))
            return false;
        if (!mojo::internal::Equals(this->enable_gpu_service_tracing, other.enable_gpu_service_tracing))
            return false;
        if (!mojo::internal::Equals(this->enable_es3_apis, other.enable_es3_apis))
            return false;
        if (!mojo::internal::Equals(this->use_passthrough_cmd_decoder, other.use_passthrough_cmd_decoder))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::GpuPreferences::DataView,
    ::gpu::mojom::GpuPreferencesPtr> {
    static bool IsNull(const ::gpu::mojom::GpuPreferencesPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::GpuPreferencesPtr* output) { output->reset(); }

    static decltype(::gpu::mojom::GpuPreferences::single_process) single_process(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->single_process;
    }

    static decltype(::gpu::mojom::GpuPreferences::in_process_gpu) in_process_gpu(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->in_process_gpu;
    }

    static decltype(::gpu::mojom::GpuPreferences::ui_prioritize_in_gpu_process) ui_prioritize_in_gpu_process(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->ui_prioritize_in_gpu_process;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_accelerated_video_decode) disable_accelerated_video_decode(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_accelerated_video_decode;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_vaapi_accelerated_video_encode) disable_vaapi_accelerated_video_encode(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_vaapi_accelerated_video_encode;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_web_rtc_hw_encoding) disable_web_rtc_hw_encoding(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_web_rtc_hw_encoding;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_accelerated_vpx_decode) enable_accelerated_vpx_decode(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_accelerated_vpx_decode;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_low_latency_dxva) enable_low_latency_dxva(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_low_latency_dxva;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_zero_copy_dxgi_video) enable_zero_copy_dxgi_video(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_zero_copy_dxgi_video;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_nv12_dxgi_video) enable_nv12_dxgi_video(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_nv12_dxgi_video;
    }

    static decltype(::gpu::mojom::GpuPreferences::compile_shader_always_succeeds) compile_shader_always_succeeds(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->compile_shader_always_succeeds;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_gl_error_limit) disable_gl_error_limit(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_gl_error_limit;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_glsl_translator) disable_glsl_translator(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_glsl_translator;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_gpu_driver_bug_workarounds) disable_gpu_driver_bug_workarounds(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_gpu_driver_bug_workarounds;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_shader_name_hashing) disable_shader_name_hashing(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_shader_name_hashing;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_gpu_command_logging) enable_gpu_command_logging(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_gpu_command_logging;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_gpu_debugging) enable_gpu_debugging(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_gpu_debugging;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_gpu_service_logging_gpu) enable_gpu_service_logging_gpu(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_gpu_service_logging_gpu;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_gpu_driver_debug_logging) enable_gpu_driver_debug_logging(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_gpu_driver_debug_logging;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_gpu_program_cache) disable_gpu_program_cache(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_gpu_program_cache;
    }

    static decltype(::gpu::mojom::GpuPreferences::enforce_gl_minimums) enforce_gl_minimums(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enforce_gl_minimums;
    }

    static decltype(::gpu::mojom::GpuPreferences::force_gpu_mem_available) force_gpu_mem_available(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->force_gpu_mem_available;
    }

    static decltype(::gpu::mojom::GpuPreferences::gpu_program_cache_size) gpu_program_cache_size(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->gpu_program_cache_size;
    }

    static decltype(::gpu::mojom::GpuPreferences::disable_gpu_shader_disk_cache) disable_gpu_shader_disk_cache(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->disable_gpu_shader_disk_cache;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_threaded_texture_mailboxes) enable_threaded_texture_mailboxes(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_threaded_texture_mailboxes;
    }

    static decltype(::gpu::mojom::GpuPreferences::gl_shader_interm_output) gl_shader_interm_output(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->gl_shader_interm_output;
    }

    static decltype(::gpu::mojom::GpuPreferences::emulate_shader_precision) emulate_shader_precision(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->emulate_shader_precision;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_gpu_service_logging) enable_gpu_service_logging(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_gpu_service_logging;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_gpu_service_tracing) enable_gpu_service_tracing(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_gpu_service_tracing;
    }

    static decltype(::gpu::mojom::GpuPreferences::enable_es3_apis) enable_es3_apis(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->enable_es3_apis;
    }

    static decltype(::gpu::mojom::GpuPreferences::use_passthrough_cmd_decoder) use_passthrough_cmd_decoder(
        const ::gpu::mojom::GpuPreferencesPtr& input)
    {
        return input->use_passthrough_cmd_decoder;
    }

    static bool Read(::gpu::mojom::GpuPreferences::DataView input, ::gpu::mojom::GpuPreferencesPtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_GPU_PREFERENCES_MOJOM_H_