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

#include "services/video_capture/public/interfaces/device_descriptor.mojom.h"

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
    DeviceDescriptorPtr DeviceDescriptor::New()
    {
        DeviceDescriptorPtr rv;
        mojo::internal::StructHelper<DeviceDescriptor>::Initialize(&rv);
        return rv;
    }

    DeviceDescriptor::DeviceDescriptor()
        : display_name()
        , device_id()
        , model_id()
        , capture_api()
        , transport_type()
    {
    }

    DeviceDescriptor::~DeviceDescriptor()
    {
    }
} // namespace mojom
} // namespace video_capture

namespace mojo {

// static
bool StructTraits<::video_capture::mojom::DeviceDescriptor::DataView, ::video_capture::mojom::DeviceDescriptorPtr>::Read(
    ::video_capture::mojom::DeviceDescriptor::DataView input,
    ::video_capture::mojom::DeviceDescriptorPtr* output)
{
    bool success = true;
    ::video_capture::mojom::DeviceDescriptorPtr result(::video_capture::mojom::DeviceDescriptor::New());

    if (!input.ReadDisplayName(&result->display_name))
        success = false;
    if (!input.ReadDeviceId(&result->device_id))
        success = false;
    if (!input.ReadModelId(&result->model_id))
        success = false;
    if (!input.ReadCaptureApi(&result->capture_api))
        success = false;
    if (!input.ReadTransportType(&result->transport_type))
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