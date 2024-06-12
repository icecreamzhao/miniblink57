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

#include "services/video_capture/public/interfaces/capture_settings.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/capture/ipc/capture_param_traits.h"
#include "media/capture/ipc/capture_param_traits_macros.h"
#include "media/capture/mojo/video_capture_types_typemap_traits.h"
#include "media/mojo/interfaces/pipeline_statistics_struct_traits.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace video_capture {
namespace mojom { // static
    I420CaptureFormatPtr I420CaptureFormat::New()
    {
        I420CaptureFormatPtr rv;
        mojo::internal::StructHelper<I420CaptureFormat>::Initialize(&rv);
        return rv;
    }

    I420CaptureFormat::I420CaptureFormat()
        : frame_size()
        , frame_rate()
    {
    }

    I420CaptureFormat::~I420CaptureFormat()
    {
    } // static
    CaptureSettingsPtr CaptureSettings::New()
    {
        CaptureSettingsPtr rv;
        mojo::internal::StructHelper<CaptureSettings>::Initialize(&rv);
        return rv;
    }

    CaptureSettings::CaptureSettings()
        : format()
        , resolution_change_policy()
        , power_line_frequency()
    {
    }

    CaptureSettings::~CaptureSettings()
    {
    }
} // namespace mojom
} // namespace video_capture

namespace mojo {

// static
bool StructTraits<::video_capture::mojom::I420CaptureFormat::DataView, ::video_capture::mojom::I420CaptureFormatPtr>::Read(
    ::video_capture::mojom::I420CaptureFormat::DataView input,
    ::video_capture::mojom::I420CaptureFormatPtr* output)
{
    bool success = true;
    ::video_capture::mojom::I420CaptureFormatPtr result(::video_capture::mojom::I420CaptureFormat::New());

    if (!input.ReadFrameSize(&result->frame_size))
        success = false;
    result->frame_rate = input.frame_rate();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::video_capture::mojom::CaptureSettings::DataView, ::video_capture::mojom::CaptureSettingsPtr>::Read(
    ::video_capture::mojom::CaptureSettings::DataView input,
    ::video_capture::mojom::CaptureSettingsPtr* output)
{
    bool success = true;
    ::video_capture::mojom::CaptureSettingsPtr result(::video_capture::mojom::CaptureSettings::New());

    if (!input.ReadFormat(&result->format))
        success = false;
    if (!input.ReadResolutionChangePolicy(&result->resolution_change_policy))
        success = false;
    if (!input.ReadPowerLineFrequency(&result->power_line_frequency))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif