// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_H_

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
#include "media/base/audio_codecs.h"
#include "media/base/audio_parameters.h"
#include "media/base/buffering_state.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise.h"
#include "media/base/channel_layout.h"
#include "media/base/content_decryption_module.h"
#include "media/base/decode_status.h"
#include "media/base/decryptor.h"
#include "media/base/demuxer_stream.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/pipeline_status.h"
#include "media/base/sample_format.h"
#include "media/base/subsample_entry.h"
#include "media/base/video_codecs.h"
#include "media/base/video_types.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
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
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/video_capture/public/cpp/capture_settings.h"
#include "services/video_capture/public/interfaces/device_descriptor.mojom-shared.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include <string>
#include <vector>

namespace video_capture {
namespace mojom {
    class DeviceDescriptor;
    using DeviceDescriptorPtr = mojo::StructPtr<DeviceDescriptor>;

    class DeviceDescriptor {
    public:
        using DataView = DeviceDescriptorDataView;
        using Data_ = internal::DeviceDescriptor_Data;

        static DeviceDescriptorPtr New();

        template <typename U>
        static DeviceDescriptorPtr From(const U& u)
        {
            return mojo::TypeConverter<DeviceDescriptorPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DeviceDescriptor>::Convert(*this);
        }

        DeviceDescriptor();
        ~DeviceDescriptor();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DeviceDescriptorPtr>
        DeviceDescriptorPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DeviceDescriptor>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DeviceDescriptor::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DeviceDescriptor::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string display_name;
        std::string device_id;
        std::string model_id;
        VideoCaptureApi capture_api;
        VideoCaptureTransportType transport_type;
    };

    template <typename StructPtrType>
    DeviceDescriptorPtr DeviceDescriptor::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->display_name = mojo::internal::Clone(display_name);
        rv->device_id = mojo::internal::Clone(device_id);
        rv->model_id = mojo::internal::Clone(model_id);
        rv->capture_api = mojo::internal::Clone(capture_api);
        rv->transport_type = mojo::internal::Clone(transport_type);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DeviceDescriptor>::value>::type*>
    bool DeviceDescriptor::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->display_name, other.display_name))
            return false;
        if (!mojo::internal::Equals(this->device_id, other.device_id))
            return false;
        if (!mojo::internal::Equals(this->model_id, other.model_id))
            return false;
        if (!mojo::internal::Equals(this->capture_api, other.capture_api))
            return false;
        if (!mojo::internal::Equals(this->transport_type, other.transport_type))
            return false;
        return true;
    }

} // namespace mojom
} // namespace video_capture

namespace mojo {

template <>
struct StructTraits<::video_capture::mojom::DeviceDescriptor::DataView,
    ::video_capture::mojom::DeviceDescriptorPtr> {
    static bool IsNull(const ::video_capture::mojom::DeviceDescriptorPtr& input) { return !input; }
    static void SetToNull(::video_capture::mojom::DeviceDescriptorPtr* output) { output->reset(); }

    static const decltype(::video_capture::mojom::DeviceDescriptor::display_name)& display_name(
        const ::video_capture::mojom::DeviceDescriptorPtr& input)
    {
        return input->display_name;
    }

    static const decltype(::video_capture::mojom::DeviceDescriptor::device_id)& device_id(
        const ::video_capture::mojom::DeviceDescriptorPtr& input)
    {
        return input->device_id;
    }

    static const decltype(::video_capture::mojom::DeviceDescriptor::model_id)& model_id(
        const ::video_capture::mojom::DeviceDescriptorPtr& input)
    {
        return input->model_id;
    }

    static decltype(::video_capture::mojom::DeviceDescriptor::capture_api) capture_api(
        const ::video_capture::mojom::DeviceDescriptorPtr& input)
    {
        return input->capture_api;
    }

    static decltype(::video_capture::mojom::DeviceDescriptor::transport_type) transport_type(
        const ::video_capture::mojom::DeviceDescriptorPtr& input)
    {
        return input->transport_type;
    }

    static bool Read(::video_capture::mojom::DeviceDescriptor::DataView input, ::video_capture::mojom::DeviceDescriptorPtr* output);
};

} // namespace mojo

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_H_