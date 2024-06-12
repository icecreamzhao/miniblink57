// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "gpu/ipc/common/gpu_preferences.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace gpu {
namespace mojom {
    namespace blink { // static
        GpuPreferencesPtr GpuPreferences::New()
        {
            GpuPreferencesPtr rv;
            mojo::internal::StructHelper<GpuPreferences>::Initialize(&rv);
            return rv;
        }

        GpuPreferences::GpuPreferences()
            : single_process()
            , in_process_gpu()
            , ui_prioritize_in_gpu_process()
            , disable_accelerated_video_decode()
            , disable_vaapi_accelerated_video_encode()
            , disable_web_rtc_hw_encoding()
            , enable_accelerated_vpx_decode()
            , enable_low_latency_dxva()
            , enable_zero_copy_dxgi_video()
            , enable_nv12_dxgi_video()
            , compile_shader_always_succeeds()
            , disable_gl_error_limit()
            , disable_glsl_translator()
            , disable_gpu_driver_bug_workarounds()
            , disable_shader_name_hashing()
            , enable_gpu_command_logging()
            , enable_gpu_debugging()
            , enable_gpu_service_logging_gpu()
            , enable_gpu_driver_debug_logging()
            , disable_gpu_program_cache()
            , enforce_gl_minimums()
            , force_gpu_mem_available()
            , gpu_program_cache_size()
            , disable_gpu_shader_disk_cache()
            , enable_threaded_texture_mailboxes()
            , gl_shader_interm_output()
            , emulate_shader_precision()
            , enable_gpu_service_logging()
            , enable_gpu_service_tracing()
            , enable_es3_apis()
            , use_passthrough_cmd_decoder()
        {
        }

        GpuPreferences::~GpuPreferences()
        {
        }
        size_t GpuPreferences::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->single_process);
            seed = mojo::internal::WTFHash(seed, this->in_process_gpu);
            seed = mojo::internal::WTFHash(seed, this->ui_prioritize_in_gpu_process);
            seed = mojo::internal::WTFHash(seed, this->disable_accelerated_video_decode);
            seed = mojo::internal::WTFHash(seed, this->disable_vaapi_accelerated_video_encode);
            seed = mojo::internal::WTFHash(seed, this->disable_web_rtc_hw_encoding);
            seed = mojo::internal::WTFHash(seed, this->enable_accelerated_vpx_decode);
            seed = mojo::internal::WTFHash(seed, this->enable_low_latency_dxva);
            seed = mojo::internal::WTFHash(seed, this->enable_zero_copy_dxgi_video);
            seed = mojo::internal::WTFHash(seed, this->enable_nv12_dxgi_video);
            seed = mojo::internal::WTFHash(seed, this->compile_shader_always_succeeds);
            seed = mojo::internal::WTFHash(seed, this->disable_gl_error_limit);
            seed = mojo::internal::WTFHash(seed, this->disable_glsl_translator);
            seed = mojo::internal::WTFHash(seed, this->disable_gpu_driver_bug_workarounds);
            seed = mojo::internal::WTFHash(seed, this->disable_shader_name_hashing);
            seed = mojo::internal::WTFHash(seed, this->enable_gpu_command_logging);
            seed = mojo::internal::WTFHash(seed, this->enable_gpu_debugging);
            seed = mojo::internal::WTFHash(seed, this->enable_gpu_service_logging_gpu);
            seed = mojo::internal::WTFHash(seed, this->enable_gpu_driver_debug_logging);
            seed = mojo::internal::WTFHash(seed, this->disable_gpu_program_cache);
            seed = mojo::internal::WTFHash(seed, this->enforce_gl_minimums);
            seed = mojo::internal::WTFHash(seed, this->force_gpu_mem_available);
            seed = mojo::internal::WTFHash(seed, this->gpu_program_cache_size);
            seed = mojo::internal::WTFHash(seed, this->disable_gpu_shader_disk_cache);
            seed = mojo::internal::WTFHash(seed, this->enable_threaded_texture_mailboxes);
            seed = mojo::internal::WTFHash(seed, this->gl_shader_interm_output);
            seed = mojo::internal::WTFHash(seed, this->emulate_shader_precision);
            seed = mojo::internal::WTFHash(seed, this->enable_gpu_service_logging);
            seed = mojo::internal::WTFHash(seed, this->enable_gpu_service_tracing);
            seed = mojo::internal::WTFHash(seed, this->enable_es3_apis);
            seed = mojo::internal::WTFHash(seed, this->use_passthrough_cmd_decoder);
            return seed;
        }
    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

// static
bool StructTraits<::gpu::mojom::blink::GpuPreferences::DataView, ::gpu::mojom::blink::GpuPreferencesPtr>::Read(
    ::gpu::mojom::blink::GpuPreferences::DataView input,
    ::gpu::mojom::blink::GpuPreferencesPtr* output)
{
    bool success = true;
    ::gpu::mojom::blink::GpuPreferencesPtr result(::gpu::mojom::blink::GpuPreferences::New());

    result->single_process = input.single_process();
    result->in_process_gpu = input.in_process_gpu();
    result->ui_prioritize_in_gpu_process = input.ui_prioritize_in_gpu_process();
    result->disable_accelerated_video_decode = input.disable_accelerated_video_decode();
    result->disable_vaapi_accelerated_video_encode = input.disable_vaapi_accelerated_video_encode();
    result->disable_web_rtc_hw_encoding = input.disable_web_rtc_hw_encoding();
    if (!input.ReadEnableAcceleratedVpxDecode(&result->enable_accelerated_vpx_decode))
        success = false;
    result->enable_low_latency_dxva = input.enable_low_latency_dxva();
    result->enable_zero_copy_dxgi_video = input.enable_zero_copy_dxgi_video();
    result->enable_nv12_dxgi_video = input.enable_nv12_dxgi_video();
    result->compile_shader_always_succeeds = input.compile_shader_always_succeeds();
    result->disable_gl_error_limit = input.disable_gl_error_limit();
    result->disable_glsl_translator = input.disable_glsl_translator();
    result->disable_gpu_driver_bug_workarounds = input.disable_gpu_driver_bug_workarounds();
    result->disable_shader_name_hashing = input.disable_shader_name_hashing();
    result->enable_gpu_command_logging = input.enable_gpu_command_logging();
    result->enable_gpu_debugging = input.enable_gpu_debugging();
    result->enable_gpu_service_logging_gpu = input.enable_gpu_service_logging_gpu();
    result->enable_gpu_driver_debug_logging = input.enable_gpu_driver_debug_logging();
    result->disable_gpu_program_cache = input.disable_gpu_program_cache();
    result->enforce_gl_minimums = input.enforce_gl_minimums();
    result->force_gpu_mem_available = input.force_gpu_mem_available();
    result->gpu_program_cache_size = input.gpu_program_cache_size();
    result->disable_gpu_shader_disk_cache = input.disable_gpu_shader_disk_cache();
    result->enable_threaded_texture_mailboxes = input.enable_threaded_texture_mailboxes();
    result->gl_shader_interm_output = input.gl_shader_interm_output();
    result->emulate_shader_precision = input.emulate_shader_precision();
    result->enable_gpu_service_logging = input.enable_gpu_service_logging();
    result->enable_gpu_service_tracing = input.enable_gpu_service_tracing();
    result->enable_es3_apis = input.enable_es3_apis();
    result->use_passthrough_cmd_decoder = input.use_passthrough_cmd_decoder();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif