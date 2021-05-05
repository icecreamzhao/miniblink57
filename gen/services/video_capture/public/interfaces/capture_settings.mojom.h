// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_H_

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
#include "media/capture/mojo/video_capture_types.mojom.h"
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
#include "services/video_capture/public/interfaces/capture_settings.mojom-shared.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
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
    class I420CaptureFormat;
    using I420CaptureFormatPtr = mojo::StructPtr<I420CaptureFormat>;

    class CaptureSettings;
    using CaptureSettingsPtr = mojo::StructPtr<CaptureSettings>;

    class I420CaptureFormat {
    public:
        using DataView = I420CaptureFormatDataView;
        using Data_ = internal::I420CaptureFormat_Data;

        static I420CaptureFormatPtr New();

        template <typename U>
        static I420CaptureFormatPtr From(const U& u)
        {
            return mojo::TypeConverter<I420CaptureFormatPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, I420CaptureFormat>::Convert(*this);
        }

        I420CaptureFormat();
        ~I420CaptureFormat();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = I420CaptureFormatPtr>
        I420CaptureFormatPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, I420CaptureFormat>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                I420CaptureFormat::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                I420CaptureFormat::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::Size frame_size;
        float frame_rate;
    };

    class CaptureSettings {
    public:
        using DataView = CaptureSettingsDataView;
        using Data_ = internal::CaptureSettings_Data;

        static CaptureSettingsPtr New();

        template <typename U>
        static CaptureSettingsPtr From(const U& u)
        {
            return mojo::TypeConverter<CaptureSettingsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CaptureSettings>::Convert(*this);
        }

        CaptureSettings();
        ~CaptureSettings();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CaptureSettingsPtr>
        CaptureSettingsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CaptureSettings>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CaptureSettings::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CaptureSettings::DataView, std::vector<uint8_t>>(
                input, output);
        }

        video_capture::I420CaptureFormat format;
        media::ResolutionChangePolicy resolution_change_policy;
        media::PowerLineFrequency power_line_frequency;
    };

    template <typename StructPtrType>
    I420CaptureFormatPtr I420CaptureFormat::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->frame_size = mojo::internal::Clone(frame_size);
        rv->frame_rate = mojo::internal::Clone(frame_rate);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, I420CaptureFormat>::value>::type*>
    bool I420CaptureFormat::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->frame_size, other.frame_size))
            return false;
        if (!mojo::internal::Equals(this->frame_rate, other.frame_rate))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CaptureSettingsPtr CaptureSettings::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->format = mojo::internal::Clone(format);
        rv->resolution_change_policy = mojo::internal::Clone(resolution_change_policy);
        rv->power_line_frequency = mojo::internal::Clone(power_line_frequency);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CaptureSettings>::value>::type*>
    bool CaptureSettings::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->format, other.format))
            return false;
        if (!mojo::internal::Equals(this->resolution_change_policy, other.resolution_change_policy))
            return false;
        if (!mojo::internal::Equals(this->power_line_frequency, other.power_line_frequency))
            return false;
        return true;
    }

} // namespace mojom
} // namespace video_capture

namespace mojo {

template <>
struct StructTraits<::video_capture::mojom::I420CaptureFormat::DataView,
    ::video_capture::mojom::I420CaptureFormatPtr> {
    static bool IsNull(const ::video_capture::mojom::I420CaptureFormatPtr& input) { return !input; }
    static void SetToNull(::video_capture::mojom::I420CaptureFormatPtr* output) { output->reset(); }

    static const decltype(::video_capture::mojom::I420CaptureFormat::frame_size)& frame_size(
        const ::video_capture::mojom::I420CaptureFormatPtr& input)
    {
        return input->frame_size;
    }

    static decltype(::video_capture::mojom::I420CaptureFormat::frame_rate) frame_rate(
        const ::video_capture::mojom::I420CaptureFormatPtr& input)
    {
        return input->frame_rate;
    }

    static bool Read(::video_capture::mojom::I420CaptureFormat::DataView input, ::video_capture::mojom::I420CaptureFormatPtr* output);
};

template <>
struct StructTraits<::video_capture::mojom::CaptureSettings::DataView,
    ::video_capture::mojom::CaptureSettingsPtr> {
    static bool IsNull(const ::video_capture::mojom::CaptureSettingsPtr& input) { return !input; }
    static void SetToNull(::video_capture::mojom::CaptureSettingsPtr* output) { output->reset(); }

    static const decltype(::video_capture::mojom::CaptureSettings::format)& format(
        const ::video_capture::mojom::CaptureSettingsPtr& input)
    {
        return input->format;
    }

    static decltype(::video_capture::mojom::CaptureSettings::resolution_change_policy) resolution_change_policy(
        const ::video_capture::mojom::CaptureSettingsPtr& input)
    {
        return input->resolution_change_policy;
    }

    static decltype(::video_capture::mojom::CaptureSettings::power_line_frequency) power_line_frequency(
        const ::video_capture::mojom::CaptureSettingsPtr& input)
    {
        return input->power_line_frequency;
    }

    static bool Read(::video_capture::mojom::CaptureSettings::DataView input, ::video_capture::mojom::CaptureSettingsPtr* output);
};

} // namespace mojo

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_H_