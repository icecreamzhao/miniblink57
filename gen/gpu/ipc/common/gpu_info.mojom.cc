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

#include "gpu/ipc/common/gpu_info.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
namespace gpu {
namespace mojom { // static
    GpuDevicePtr GpuDevice::New()
    {
        GpuDevicePtr rv;
        mojo::internal::StructHelper<GpuDevice>::Initialize(&rv);
        return rv;
    }

    GpuDevice::GpuDevice()
        : vendor_id()
        , device_id()
        , active()
        , vendor_string()
        , device_string()
    {
    }

    GpuDevice::~GpuDevice()
    {
    } // static
    VideoDecodeAcceleratorSupportedProfilePtr VideoDecodeAcceleratorSupportedProfile::New()
    {
        VideoDecodeAcceleratorSupportedProfilePtr rv;
        mojo::internal::StructHelper<VideoDecodeAcceleratorSupportedProfile>::Initialize(&rv);
        return rv;
    }

    VideoDecodeAcceleratorSupportedProfile::VideoDecodeAcceleratorSupportedProfile()
        : profile()
        , max_resolution()
        , min_resolution()
        , encrypted_only()
    {
    }

    VideoDecodeAcceleratorSupportedProfile::~VideoDecodeAcceleratorSupportedProfile()
    {
    } // static
    VideoDecodeAcceleratorCapabilitiesPtr VideoDecodeAcceleratorCapabilities::New()
    {
        VideoDecodeAcceleratorCapabilitiesPtr rv;
        mojo::internal::StructHelper<VideoDecodeAcceleratorCapabilities>::Initialize(&rv);
        return rv;
    }

    VideoDecodeAcceleratorCapabilities::VideoDecodeAcceleratorCapabilities()
        : supported_profiles()
        , flags()
    {
    }

    VideoDecodeAcceleratorCapabilities::~VideoDecodeAcceleratorCapabilities()
    {
    } // static
    VideoEncodeAcceleratorSupportedProfilePtr VideoEncodeAcceleratorSupportedProfile::New()
    {
        VideoEncodeAcceleratorSupportedProfilePtr rv;
        mojo::internal::StructHelper<VideoEncodeAcceleratorSupportedProfile>::Initialize(&rv);
        return rv;
    }

    VideoEncodeAcceleratorSupportedProfile::VideoEncodeAcceleratorSupportedProfile()
        : profile()
        , max_resolution()
        , max_framerate_numerator()
        , max_framerate_denominator()
    {
    }

    VideoEncodeAcceleratorSupportedProfile::~VideoEncodeAcceleratorSupportedProfile()
    {
    } // static
    GpuInfoPtr GpuInfo::New()
    {
        GpuInfoPtr rv;
        mojo::internal::StructHelper<GpuInfo>::Initialize(&rv);
        return rv;
    }

    GpuInfo::GpuInfo()
        : initialization_time()
        , optimus()
        , amd_switchable()
        , lenovo_dcute()
        , display_link_version()
        , gpu()
        , secondary_gpus()
        , adapter_luid()
        , driver_vendor()
        , driver_version()
        , driver_date()
        , pixel_shader_version()
        , vertex_shader_version()
        , max_msaa_samples()
        , machine_model_name()
        , machine_model_version()
        , gl_version()
        , gl_vendor()
        , gl_renderer()
        , gl_extensions()
        , gl_ws_vendor()
        , gl_ws_version()
        , gl_ws_extensions()
        , gl_reset_notification_strategy()
        , software_rendering()
        , direct_rendering()
        , sandboxed()
        , process_crash_count()
        , in_process_gpu()
        , passthrough_cmd_decoder()
        , basic_info_state()
        , context_info_state()
        , dx_diagnostics_info_state()
        , dx_diagnostics()
        , video_decode_accelerator_capabilities()
        , video_encode_accelerator_supported_profiles()
        , jpeg_decode_accelerator_supported()
        , system_visual()
        , rgba_visual()
    {
    }

    GpuInfo::~GpuInfo()
    {
    }
} // namespace mojom
} // namespace gpu

namespace mojo {

// static
bool StructTraits<::gpu::mojom::GpuDevice::DataView, ::gpu::mojom::GpuDevicePtr>::Read(
    ::gpu::mojom::GpuDevice::DataView input,
    ::gpu::mojom::GpuDevicePtr* output)
{
    bool success = true;
    ::gpu::mojom::GpuDevicePtr result(::gpu::mojom::GpuDevice::New());

    result->vendor_id = input.vendor_id();
    result->device_id = input.device_id();
    result->active = input.active();
    if (!input.ReadVendorString(&result->vendor_string))
        success = false;
    if (!input.ReadDeviceString(&result->device_string))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gpu::mojom::VideoDecodeAcceleratorSupportedProfile::DataView, ::gpu::mojom::VideoDecodeAcceleratorSupportedProfilePtr>::Read(
    ::gpu::mojom::VideoDecodeAcceleratorSupportedProfile::DataView input,
    ::gpu::mojom::VideoDecodeAcceleratorSupportedProfilePtr* output)
{
    bool success = true;
    ::gpu::mojom::VideoDecodeAcceleratorSupportedProfilePtr result(::gpu::mojom::VideoDecodeAcceleratorSupportedProfile::New());

    if (!input.ReadProfile(&result->profile))
        success = false;
    if (!input.ReadMaxResolution(&result->max_resolution))
        success = false;
    if (!input.ReadMinResolution(&result->min_resolution))
        success = false;
    result->encrypted_only = input.encrypted_only();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gpu::mojom::VideoDecodeAcceleratorCapabilities::DataView, ::gpu::mojom::VideoDecodeAcceleratorCapabilitiesPtr>::Read(
    ::gpu::mojom::VideoDecodeAcceleratorCapabilities::DataView input,
    ::gpu::mojom::VideoDecodeAcceleratorCapabilitiesPtr* output)
{
    bool success = true;
    ::gpu::mojom::VideoDecodeAcceleratorCapabilitiesPtr result(::gpu::mojom::VideoDecodeAcceleratorCapabilities::New());

    if (!input.ReadSupportedProfiles(&result->supported_profiles))
        success = false;
    result->flags = input.flags();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gpu::mojom::VideoEncodeAcceleratorSupportedProfile::DataView, ::gpu::mojom::VideoEncodeAcceleratorSupportedProfilePtr>::Read(
    ::gpu::mojom::VideoEncodeAcceleratorSupportedProfile::DataView input,
    ::gpu::mojom::VideoEncodeAcceleratorSupportedProfilePtr* output)
{
    bool success = true;
    ::gpu::mojom::VideoEncodeAcceleratorSupportedProfilePtr result(::gpu::mojom::VideoEncodeAcceleratorSupportedProfile::New());

    if (!input.ReadProfile(&result->profile))
        success = false;
    if (!input.ReadMaxResolution(&result->max_resolution))
        success = false;
    result->max_framerate_numerator = input.max_framerate_numerator();
    result->max_framerate_denominator = input.max_framerate_denominator();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gpu::mojom::GpuInfo::DataView, ::gpu::mojom::GpuInfoPtr>::Read(
    ::gpu::mojom::GpuInfo::DataView input,
    ::gpu::mojom::GpuInfoPtr* output)
{
    bool success = true;
    ::gpu::mojom::GpuInfoPtr result(::gpu::mojom::GpuInfo::New());

    if (!input.ReadInitializationTime(&result->initialization_time))
        success = false;
    result->optimus = input.optimus();
    result->amd_switchable = input.amd_switchable();
    result->lenovo_dcute = input.lenovo_dcute();
    if (!input.ReadDisplayLinkVersion(&result->display_link_version))
        success = false;
    if (!input.ReadGpu(&result->gpu))
        success = false;
    if (!input.ReadSecondaryGpus(&result->secondary_gpus))
        success = false;
    result->adapter_luid = input.adapter_luid();
    if (!input.ReadDriverVendor(&result->driver_vendor))
        success = false;
    if (!input.ReadDriverVersion(&result->driver_version))
        success = false;
    if (!input.ReadDriverDate(&result->driver_date))
        success = false;
    if (!input.ReadPixelShaderVersion(&result->pixel_shader_version))
        success = false;
    if (!input.ReadVertexShaderVersion(&result->vertex_shader_version))
        success = false;
    if (!input.ReadMaxMsaaSamples(&result->max_msaa_samples))
        success = false;
    if (!input.ReadMachineModelName(&result->machine_model_name))
        success = false;
    if (!input.ReadMachineModelVersion(&result->machine_model_version))
        success = false;
    if (!input.ReadGlVersion(&result->gl_version))
        success = false;
    if (!input.ReadGlVendor(&result->gl_vendor))
        success = false;
    if (!input.ReadGlRenderer(&result->gl_renderer))
        success = false;
    if (!input.ReadGlExtensions(&result->gl_extensions))
        success = false;
    if (!input.ReadGlWsVendor(&result->gl_ws_vendor))
        success = false;
    if (!input.ReadGlWsVersion(&result->gl_ws_version))
        success = false;
    if (!input.ReadGlWsExtensions(&result->gl_ws_extensions))
        success = false;
    result->gl_reset_notification_strategy = input.gl_reset_notification_strategy();
    result->software_rendering = input.software_rendering();
    result->direct_rendering = input.direct_rendering();
    result->sandboxed = input.sandboxed();
    result->process_crash_count = input.process_crash_count();
    result->in_process_gpu = input.in_process_gpu();
    result->passthrough_cmd_decoder = input.passthrough_cmd_decoder();
    if (!input.ReadBasicInfoState(&result->basic_info_state))
        success = false;
    if (!input.ReadContextInfoState(&result->context_info_state))
        success = false;
    if (!input.ReadDxDiagnosticsInfoState(&result->dx_diagnostics_info_state))
        success = false;
    if (!input.ReadDxDiagnostics(&result->dx_diagnostics))
        success = false;
    if (!input.ReadVideoDecodeAcceleratorCapabilities(&result->video_decode_accelerator_capabilities))
        success = false;
    if (!input.ReadVideoEncodeAcceleratorSupportedProfiles(&result->video_encode_accelerator_supported_profiles))
        success = false;
    result->jpeg_decode_accelerator_supported = input.jpeg_decode_accelerator_supported();
    result->system_visual = input.system_visual();
    result->rgba_visual = input.rgba_visual();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif