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

#include "media/capture/mojo/video_capture_types.mojom.h"

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
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace media {
namespace mojom { // static
    VideoCaptureFormatPtr VideoCaptureFormat::New()
    {
        VideoCaptureFormatPtr rv;
        mojo::internal::StructHelper<VideoCaptureFormat>::Initialize(&rv);
        return rv;
    }

    VideoCaptureFormat::VideoCaptureFormat()
        : frame_size()
        , frame_rate()
        , pixel_format()
        , pixel_storage()
    {
    }

    VideoCaptureFormat::~VideoCaptureFormat()
    {
    } // static
    VideoCaptureParamsPtr VideoCaptureParams::New()
    {
        VideoCaptureParamsPtr rv;
        mojo::internal::StructHelper<VideoCaptureParams>::Initialize(&rv);
        return rv;
    }

    VideoCaptureParams::VideoCaptureParams()
        : requested_format()
        , resolution_change_policy()
        , power_line_frequency()
    {
    }

    VideoCaptureParams::~VideoCaptureParams()
    {
    } // static
    VideoFrameInfoPtr VideoFrameInfo::New()
    {
        VideoFrameInfoPtr rv;
        mojo::internal::StructHelper<VideoFrameInfo>::Initialize(&rv);
        return rv;
    }

    VideoFrameInfo::VideoFrameInfo()
        : timestamp()
        , metadata()
        , pixel_format()
        , storage_type()
        , coded_size()
        , visible_rect()
    {
    }

    VideoFrameInfo::~VideoFrameInfo()
    {
    }
} // namespace mojom
} // namespace media

namespace mojo {

// static
bool StructTraits<::media::mojom::VideoCaptureFormat::DataView, ::media::mojom::VideoCaptureFormatPtr>::Read(
    ::media::mojom::VideoCaptureFormat::DataView input,
    ::media::mojom::VideoCaptureFormatPtr* output)
{
    bool success = true;
    ::media::mojom::VideoCaptureFormatPtr result(::media::mojom::VideoCaptureFormat::New());

    if (!input.ReadFrameSize(&result->frame_size))
        success = false;
    result->frame_rate = input.frame_rate();
    if (!input.ReadPixelFormat(&result->pixel_format))
        success = false;
    if (!input.ReadPixelStorage(&result->pixel_storage))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::VideoCaptureParams::DataView, ::media::mojom::VideoCaptureParamsPtr>::Read(
    ::media::mojom::VideoCaptureParams::DataView input,
    ::media::mojom::VideoCaptureParamsPtr* output)
{
    bool success = true;
    ::media::mojom::VideoCaptureParamsPtr result(::media::mojom::VideoCaptureParams::New());

    if (!input.ReadRequestedFormat(&result->requested_format))
        success = false;
    if (!input.ReadResolutionChangePolicy(&result->resolution_change_policy))
        success = false;
    if (!input.ReadPowerLineFrequency(&result->power_line_frequency))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::VideoFrameInfo::DataView, ::media::mojom::VideoFrameInfoPtr>::Read(
    ::media::mojom::VideoFrameInfo::DataView input,
    ::media::mojom::VideoFrameInfoPtr* output)
{
    bool success = true;
    ::media::mojom::VideoFrameInfoPtr result(::media::mojom::VideoFrameInfo::New());

    if (!input.ReadTimestamp(&result->timestamp))
        success = false;
    if (!input.ReadMetadata(&result->metadata))
        success = false;
    if (!input.ReadPixelFormat(&result->pixel_format))
        success = false;
    if (!input.ReadStorageType(&result->storage_type))
        success = false;
    if (!input.ReadCodedSize(&result->coded_size))
        success = false;
    if (!input.ReadVisibleRect(&result->visible_rect))
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