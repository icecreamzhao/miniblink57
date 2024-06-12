// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_H_
#define MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_H_

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
#include "media/capture/mojo/video_capture_types.mojom-shared.h"
#include "media/capture/video_capture_types.h"
#include "media/mojo/interfaces/media_types.mojom.h"
#include "mojo/common/time.mojom.h"
#include "mojo/common/values.mojom.h"
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

namespace media {
namespace mojom {
    class VideoCaptureFormat;
    using VideoCaptureFormatPtr = mojo::StructPtr<VideoCaptureFormat>;

    class VideoCaptureParams;
    using VideoCaptureParamsPtr = mojo::StructPtr<VideoCaptureParams>;

    class VideoFrameInfo;
    using VideoFrameInfoPtr = mojo::StructPtr<VideoFrameInfo>;

    class VideoCaptureFormat {
    public:
        using DataView = VideoCaptureFormatDataView;
        using Data_ = internal::VideoCaptureFormat_Data;

        static VideoCaptureFormatPtr New();

        template <typename U>
        static VideoCaptureFormatPtr From(const U& u)
        {
            return mojo::TypeConverter<VideoCaptureFormatPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, VideoCaptureFormat>::Convert(*this);
        }

        VideoCaptureFormat();
        ~VideoCaptureFormat();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = VideoCaptureFormatPtr>
        VideoCaptureFormatPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoCaptureFormat>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                VideoCaptureFormat::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                VideoCaptureFormat::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::Size frame_size;
        float frame_rate;
        media::VideoPixelFormat pixel_format;
        media::VideoPixelStorage pixel_storage;
    };

    class VideoCaptureParams {
    public:
        using DataView = VideoCaptureParamsDataView;
        using Data_ = internal::VideoCaptureParams_Data;

        static VideoCaptureParamsPtr New();

        template <typename U>
        static VideoCaptureParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<VideoCaptureParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, VideoCaptureParams>::Convert(*this);
        }

        VideoCaptureParams();
        ~VideoCaptureParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = VideoCaptureParamsPtr>
        VideoCaptureParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoCaptureParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                VideoCaptureParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                VideoCaptureParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        media::VideoCaptureFormat requested_format;
        media::ResolutionChangePolicy resolution_change_policy;
        media::PowerLineFrequency power_line_frequency;
    };

    class VideoFrameInfo {
    public:
        using DataView = VideoFrameInfoDataView;
        using Data_ = internal::VideoFrameInfo_Data;

        static VideoFrameInfoPtr New();

        template <typename U>
        static VideoFrameInfoPtr From(const U& u)
        {
            return mojo::TypeConverter<VideoFrameInfoPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, VideoFrameInfo>::Convert(*this);
        }

        VideoFrameInfo();
        ~VideoFrameInfo();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = VideoFrameInfoPtr>
        VideoFrameInfoPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoFrameInfo>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                VideoFrameInfo::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                VideoFrameInfo::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::TimeDelta timestamp;
        std::unique_ptr<base::DictionaryValue> metadata;
        media::VideoPixelFormat pixel_format;
        media::VideoPixelStorage storage_type;
        gfx::Size coded_size;
        gfx::Rect visible_rect;

    private:
        DISALLOW_COPY_AND_ASSIGN(VideoFrameInfo);
    };

    template <typename StructPtrType>
    VideoCaptureFormatPtr VideoCaptureFormat::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->frame_size = mojo::internal::Clone(frame_size);
        rv->frame_rate = mojo::internal::Clone(frame_rate);
        rv->pixel_format = mojo::internal::Clone(pixel_format);
        rv->pixel_storage = mojo::internal::Clone(pixel_storage);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, VideoCaptureFormat>::value>::type*>
    bool VideoCaptureFormat::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->frame_size, other.frame_size))
            return false;
        if (!mojo::internal::Equals(this->frame_rate, other.frame_rate))
            return false;
        if (!mojo::internal::Equals(this->pixel_format, other.pixel_format))
            return false;
        if (!mojo::internal::Equals(this->pixel_storage, other.pixel_storage))
            return false;
        return true;
    }
    template <typename StructPtrType>
    VideoCaptureParamsPtr VideoCaptureParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->requested_format = mojo::internal::Clone(requested_format);
        rv->resolution_change_policy = mojo::internal::Clone(resolution_change_policy);
        rv->power_line_frequency = mojo::internal::Clone(power_line_frequency);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, VideoCaptureParams>::value>::type*>
    bool VideoCaptureParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->requested_format, other.requested_format))
            return false;
        if (!mojo::internal::Equals(this->resolution_change_policy, other.resolution_change_policy))
            return false;
        if (!mojo::internal::Equals(this->power_line_frequency, other.power_line_frequency))
            return false;
        return true;
    }
    template <typename StructPtrType>
    VideoFrameInfoPtr VideoFrameInfo::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->metadata = mojo::internal::Clone(metadata);
        rv->pixel_format = mojo::internal::Clone(pixel_format);
        rv->storage_type = mojo::internal::Clone(storage_type);
        rv->coded_size = mojo::internal::Clone(coded_size);
        rv->visible_rect = mojo::internal::Clone(visible_rect);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, VideoFrameInfo>::value>::type*>
    bool VideoFrameInfo::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->metadata, other.metadata))
            return false;
        if (!mojo::internal::Equals(this->pixel_format, other.pixel_format))
            return false;
        if (!mojo::internal::Equals(this->storage_type, other.storage_type))
            return false;
        if (!mojo::internal::Equals(this->coded_size, other.coded_size))
            return false;
        if (!mojo::internal::Equals(this->visible_rect, other.visible_rect))
            return false;
        return true;
    }

} // namespace mojom
} // namespace media

namespace mojo {

template <>
struct StructTraits<::media::mojom::VideoCaptureFormat::DataView,
    ::media::mojom::VideoCaptureFormatPtr> {
    static bool IsNull(const ::media::mojom::VideoCaptureFormatPtr& input) { return !input; }
    static void SetToNull(::media::mojom::VideoCaptureFormatPtr* output) { output->reset(); }

    static const decltype(::media::mojom::VideoCaptureFormat::frame_size)& frame_size(
        const ::media::mojom::VideoCaptureFormatPtr& input)
    {
        return input->frame_size;
    }

    static decltype(::media::mojom::VideoCaptureFormat::frame_rate) frame_rate(
        const ::media::mojom::VideoCaptureFormatPtr& input)
    {
        return input->frame_rate;
    }

    static decltype(::media::mojom::VideoCaptureFormat::pixel_format) pixel_format(
        const ::media::mojom::VideoCaptureFormatPtr& input)
    {
        return input->pixel_format;
    }

    static decltype(::media::mojom::VideoCaptureFormat::pixel_storage) pixel_storage(
        const ::media::mojom::VideoCaptureFormatPtr& input)
    {
        return input->pixel_storage;
    }

    static bool Read(::media::mojom::VideoCaptureFormat::DataView input, ::media::mojom::VideoCaptureFormatPtr* output);
};

template <>
struct StructTraits<::media::mojom::VideoCaptureParams::DataView,
    ::media::mojom::VideoCaptureParamsPtr> {
    static bool IsNull(const ::media::mojom::VideoCaptureParamsPtr& input) { return !input; }
    static void SetToNull(::media::mojom::VideoCaptureParamsPtr* output) { output->reset(); }

    static const decltype(::media::mojom::VideoCaptureParams::requested_format)& requested_format(
        const ::media::mojom::VideoCaptureParamsPtr& input)
    {
        return input->requested_format;
    }

    static decltype(::media::mojom::VideoCaptureParams::resolution_change_policy) resolution_change_policy(
        const ::media::mojom::VideoCaptureParamsPtr& input)
    {
        return input->resolution_change_policy;
    }

    static decltype(::media::mojom::VideoCaptureParams::power_line_frequency) power_line_frequency(
        const ::media::mojom::VideoCaptureParamsPtr& input)
    {
        return input->power_line_frequency;
    }

    static bool Read(::media::mojom::VideoCaptureParams::DataView input, ::media::mojom::VideoCaptureParamsPtr* output);
};

template <>
struct StructTraits<::media::mojom::VideoFrameInfo::DataView,
    ::media::mojom::VideoFrameInfoPtr> {
    static bool IsNull(const ::media::mojom::VideoFrameInfoPtr& input) { return !input; }
    static void SetToNull(::media::mojom::VideoFrameInfoPtr* output) { output->reset(); }

    static const decltype(::media::mojom::VideoFrameInfo::timestamp)& timestamp(
        const ::media::mojom::VideoFrameInfoPtr& input)
    {
        return input->timestamp;
    }

    static const decltype(::media::mojom::VideoFrameInfo::metadata)& metadata(
        const ::media::mojom::VideoFrameInfoPtr& input)
    {
        return input->metadata;
    }

    static decltype(::media::mojom::VideoFrameInfo::pixel_format) pixel_format(
        const ::media::mojom::VideoFrameInfoPtr& input)
    {
        return input->pixel_format;
    }

    static decltype(::media::mojom::VideoFrameInfo::storage_type) storage_type(
        const ::media::mojom::VideoFrameInfoPtr& input)
    {
        return input->storage_type;
    }

    static const decltype(::media::mojom::VideoFrameInfo::coded_size)& coded_size(
        const ::media::mojom::VideoFrameInfoPtr& input)
    {
        return input->coded_size;
    }

    static const decltype(::media::mojom::VideoFrameInfo::visible_rect)& visible_rect(
        const ::media::mojom::VideoFrameInfoPtr& input)
    {
        return input->visible_rect;
    }

    static bool Read(::media::mojom::VideoFrameInfo::DataView input, ::media::mojom::VideoFrameInfoPtr* output);
};

} // namespace mojo

#endif // MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_H_