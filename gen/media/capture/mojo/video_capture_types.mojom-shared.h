// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_SHARED_H_
#define MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/capture/mojo/video_capture_types.mojom-shared-internal.h"
#include "media/mojo/interfaces/media_types.mojom-shared.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/common/values.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace media {
namespace mojom {
    class VideoCaptureFormatDataView;

    class VideoCaptureParamsDataView;

    class VideoFrameInfoDataView;

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::media::mojom::VideoCaptureFormatDataView> {
        using Data = ::media::mojom::internal::VideoCaptureFormat_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::VideoCaptureParamsDataView> {
        using Data = ::media::mojom::internal::VideoCaptureParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::VideoFrameInfoDataView> {
        using Data = ::media::mojom::internal::VideoFrameInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {

    enum class ResolutionChangePolicy : int32_t {
        FIXED_RESOLUTION,
        FIXED_ASPECT_RATIO,
        ANY_WITHIN_LIMIT,
    };

    inline std::ostream& operator<<(std::ostream& os, ResolutionChangePolicy value)
    {
        switch (value) {
        case ResolutionChangePolicy::FIXED_RESOLUTION:
            return os << "ResolutionChangePolicy::FIXED_RESOLUTION";
        case ResolutionChangePolicy::FIXED_ASPECT_RATIO:
            return os << "ResolutionChangePolicy::FIXED_ASPECT_RATIO";
        case ResolutionChangePolicy::ANY_WITHIN_LIMIT:
            return os << "ResolutionChangePolicy::ANY_WITHIN_LIMIT";
        default:
            return os << "Unknown ResolutionChangePolicy value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ResolutionChangePolicy value)
    {
        return internal::ResolutionChangePolicy_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PowerLineFrequency : int32_t {
        DEFAULT,
        HZ_50,
        HZ_60,
    };

    inline std::ostream& operator<<(std::ostream& os, PowerLineFrequency value)
    {
        switch (value) {
        case PowerLineFrequency::DEFAULT:
            return os << "PowerLineFrequency::DEFAULT";
        case PowerLineFrequency::HZ_50:
            return os << "PowerLineFrequency::HZ_50";
        case PowerLineFrequency::HZ_60:
            return os << "PowerLineFrequency::HZ_60";
        default:
            return os << "Unknown PowerLineFrequency value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PowerLineFrequency value)
    {
        return internal::PowerLineFrequency_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class VideoPixelStorage : int32_t {
        CPU,
        GPUMEMORYBUFFER,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoPixelStorage value)
    {
        switch (value) {
        case VideoPixelStorage::CPU:
            return os << "VideoPixelStorage::CPU";
        case VideoPixelStorage::GPUMEMORYBUFFER:
            return os << "VideoPixelStorage::GPUMEMORYBUFFER";
        default:
            return os << "Unknown VideoPixelStorage value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoPixelStorage value)
    {
        return internal::VideoPixelStorage_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class VideoCaptureApi : int32_t {
        LINUX_V4L2_SINGLE_PLANE,
        WIN_MEDIA_FOUNDATION,
        WIN_DIRECT_SHOW,
        MACOSX_AVFOUNDATION,
        MACOSX_DECKLINK,
        ANDROID_API1,
        ANDROID_API2_LEGACY,
        ANDROID_API2_FULL,
        ANDROID_API2_LIMITED,
        ANDROID_TANGO,
        UNKNOWN,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoCaptureApi value)
    {
        switch (value) {
        case VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE:
            return os << "VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE";
        case VideoCaptureApi::WIN_MEDIA_FOUNDATION:
            return os << "VideoCaptureApi::WIN_MEDIA_FOUNDATION";
        case VideoCaptureApi::WIN_DIRECT_SHOW:
            return os << "VideoCaptureApi::WIN_DIRECT_SHOW";
        case VideoCaptureApi::MACOSX_AVFOUNDATION:
            return os << "VideoCaptureApi::MACOSX_AVFOUNDATION";
        case VideoCaptureApi::MACOSX_DECKLINK:
            return os << "VideoCaptureApi::MACOSX_DECKLINK";
        case VideoCaptureApi::ANDROID_API1:
            return os << "VideoCaptureApi::ANDROID_API1";
        case VideoCaptureApi::ANDROID_API2_LEGACY:
            return os << "VideoCaptureApi::ANDROID_API2_LEGACY";
        case VideoCaptureApi::ANDROID_API2_FULL:
            return os << "VideoCaptureApi::ANDROID_API2_FULL";
        case VideoCaptureApi::ANDROID_API2_LIMITED:
            return os << "VideoCaptureApi::ANDROID_API2_LIMITED";
        case VideoCaptureApi::ANDROID_TANGO:
            return os << "VideoCaptureApi::ANDROID_TANGO";
        case VideoCaptureApi::UNKNOWN:
            return os << "VideoCaptureApi::UNKNOWN";
        default:
            return os << "Unknown VideoCaptureApi value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoCaptureApi value)
    {
        return internal::VideoCaptureApi_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class VideoCaptureTransportType : int32_t {
        MACOSX_USB_OR_BUILT_IN,
        OTHER_TRANSPORT,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoCaptureTransportType value)
    {
        switch (value) {
        case VideoCaptureTransportType::MACOSX_USB_OR_BUILT_IN:
            return os << "VideoCaptureTransportType::MACOSX_USB_OR_BUILT_IN";
        case VideoCaptureTransportType::OTHER_TRANSPORT:
            return os << "VideoCaptureTransportType::OTHER_TRANSPORT";
        default:
            return os << "Unknown VideoCaptureTransportType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoCaptureTransportType value)
    {
        return internal::VideoCaptureTransportType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class VideoCaptureFormatDataView {
    public:
        VideoCaptureFormatDataView() { }

        VideoCaptureFormatDataView(
            internal::VideoCaptureFormat_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameSize(UserType* output)
        {
            auto* pointer = data_->frame_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        float frame_rate() const
        {
            return data_->frame_rate;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPixelFormat(UserType* output) const
        {
            auto data_value = data_->pixel_format;
            return mojo::internal::Deserialize<::media::mojom::VideoPixelFormat>(
                data_value, output);
        }

        ::media::mojom::VideoPixelFormat pixel_format() const
        {
            return static_cast<::media::mojom::VideoPixelFormat>(data_->pixel_format);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPixelStorage(UserType* output) const
        {
            auto data_value = data_->pixel_storage;
            return mojo::internal::Deserialize<::media::mojom::VideoPixelStorage>(
                data_value, output);
        }

        VideoPixelStorage pixel_storage() const
        {
            return static_cast<VideoPixelStorage>(data_->pixel_storage);
        }

    private:
        internal::VideoCaptureFormat_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoCaptureParamsDataView {
    public:
        VideoCaptureParamsDataView() { }

        VideoCaptureParamsDataView(
            internal::VideoCaptureParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRequestedFormatDataView(
            VideoCaptureFormatDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequestedFormat(UserType* output)
        {
            auto* pointer = data_->requested_format.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoCaptureFormatDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResolutionChangePolicy(UserType* output) const
        {
            auto data_value = data_->resolution_change_policy;
            return mojo::internal::Deserialize<::media::mojom::ResolutionChangePolicy>(
                data_value, output);
        }

        ResolutionChangePolicy resolution_change_policy() const
        {
            return static_cast<ResolutionChangePolicy>(data_->resolution_change_policy);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPowerLineFrequency(UserType* output) const
        {
            auto data_value = data_->power_line_frequency;
            return mojo::internal::Deserialize<::media::mojom::PowerLineFrequency>(
                data_value, output);
        }

        PowerLineFrequency power_line_frequency() const
        {
            return static_cast<PowerLineFrequency>(data_->power_line_frequency);
        }

    private:
        internal::VideoCaptureParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoFrameInfoDataView {
    public:
        VideoFrameInfoDataView() { }

        VideoFrameInfoDataView(
            internal::VideoFrameInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        inline void GetMetadataDataView(
            ::mojo::common::mojom::DictionaryValueDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMetadata(UserType* output)
        {
            auto* pointer = data_->metadata.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::DictionaryValueDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPixelFormat(UserType* output) const
        {
            auto data_value = data_->pixel_format;
            return mojo::internal::Deserialize<::media::mojom::VideoPixelFormat>(
                data_value, output);
        }

        ::media::mojom::VideoPixelFormat pixel_format() const
        {
            return static_cast<::media::mojom::VideoPixelFormat>(data_->pixel_format);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStorageType(UserType* output) const
        {
            auto data_value = data_->storage_type;
            return mojo::internal::Deserialize<::media::mojom::VideoPixelStorage>(
                data_value, output);
        }

        VideoPixelStorage storage_type() const
        {
            return static_cast<VideoPixelStorage>(data_->storage_type);
        }
        inline void GetCodedSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCodedSize(UserType* output)
        {
            auto* pointer = data_->coded_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetVisibleRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVisibleRect(UserType* output)
        {
            auto* pointer = data_->visible_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }

    private:
        internal::VideoFrameInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

template <>
struct hash<::media::mojom::ResolutionChangePolicy>
    : public mojo::internal::EnumHashImpl<::media::mojom::ResolutionChangePolicy> {
};

template <>
struct hash<::media::mojom::PowerLineFrequency>
    : public mojo::internal::EnumHashImpl<::media::mojom::PowerLineFrequency> {
};

template <>
struct hash<::media::mojom::VideoPixelStorage>
    : public mojo::internal::EnumHashImpl<::media::mojom::VideoPixelStorage> {
};

template <>
struct hash<::media::mojom::VideoCaptureApi>
    : public mojo::internal::EnumHashImpl<::media::mojom::VideoCaptureApi> {
};

template <>
struct hash<::media::mojom::VideoCaptureTransportType>
    : public mojo::internal::EnumHashImpl<::media::mojom::VideoCaptureTransportType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::media::mojom::ResolutionChangePolicy, ::media::mojom::ResolutionChangePolicy> {
    static ::media::mojom::ResolutionChangePolicy ToMojom(::media::mojom::ResolutionChangePolicy input) { return input; }
    static bool FromMojom(::media::mojom::ResolutionChangePolicy input, ::media::mojom::ResolutionChangePolicy* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::ResolutionChangePolicy, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::ResolutionChangePolicy, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::ResolutionChangePolicy>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::PowerLineFrequency, ::media::mojom::PowerLineFrequency> {
    static ::media::mojom::PowerLineFrequency ToMojom(::media::mojom::PowerLineFrequency input) { return input; }
    static bool FromMojom(::media::mojom::PowerLineFrequency input, ::media::mojom::PowerLineFrequency* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::PowerLineFrequency, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::PowerLineFrequency, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::PowerLineFrequency>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::VideoPixelStorage, ::media::mojom::VideoPixelStorage> {
    static ::media::mojom::VideoPixelStorage ToMojom(::media::mojom::VideoPixelStorage input) { return input; }
    static bool FromMojom(::media::mojom::VideoPixelStorage input, ::media::mojom::VideoPixelStorage* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoPixelStorage, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::VideoPixelStorage, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::VideoPixelStorage>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::VideoCaptureApi, ::media::mojom::VideoCaptureApi> {
    static ::media::mojom::VideoCaptureApi ToMojom(::media::mojom::VideoCaptureApi input) { return input; }
    static bool FromMojom(::media::mojom::VideoCaptureApi input, ::media::mojom::VideoCaptureApi* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoCaptureApi, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::VideoCaptureApi, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::VideoCaptureApi>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::VideoCaptureTransportType, ::media::mojom::VideoCaptureTransportType> {
    static ::media::mojom::VideoCaptureTransportType ToMojom(::media::mojom::VideoCaptureTransportType input) { return input; }
    static bool FromMojom(::media::mojom::VideoCaptureTransportType input, ::media::mojom::VideoCaptureTransportType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoCaptureTransportType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::VideoCaptureTransportType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::VideoCaptureTransportType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoCaptureFormatDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::VideoCaptureFormatDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::VideoCaptureFormat_Data);
            decltype(CallWithContext(Traits::frame_size, input, custom_context)) in_frame_size = CallWithContext(Traits::frame_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_frame_size, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::VideoCaptureFormat_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::VideoCaptureFormat_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::frame_size, input, custom_context)) in_frame_size = CallWithContext(Traits::frame_size, input, custom_context);
            typename decltype(result->frame_size)::BaseType* frame_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_frame_size, buffer, &frame_size_ptr, context);
            result->frame_size.Set(frame_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_size in VideoCaptureFormat struct");
            result->frame_rate = CallWithContext(Traits::frame_rate, input, custom_context);
            mojo::internal::Serialize<::media::mojom::VideoPixelFormat>(
                CallWithContext(Traits::pixel_format, input, custom_context), &result->pixel_format);
            mojo::internal::Serialize<::media::mojom::VideoPixelStorage>(
                CallWithContext(Traits::pixel_storage, input, custom_context), &result->pixel_storage);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::VideoCaptureFormat_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::VideoCaptureFormatDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoCaptureParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::VideoCaptureParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::VideoCaptureParams_Data);
            decltype(CallWithContext(Traits::requested_format, input, custom_context)) in_requested_format = CallWithContext(Traits::requested_format, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::VideoCaptureFormatDataView>(
                in_requested_format, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::VideoCaptureParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::VideoCaptureParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::requested_format, input, custom_context)) in_requested_format = CallWithContext(Traits::requested_format, input, custom_context);
            typename decltype(result->requested_format)::BaseType* requested_format_ptr;
            mojo::internal::Serialize<::media::mojom::VideoCaptureFormatDataView>(
                in_requested_format, buffer, &requested_format_ptr, context);
            result->requested_format.Set(requested_format_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->requested_format.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null requested_format in VideoCaptureParams struct");
            mojo::internal::Serialize<::media::mojom::ResolutionChangePolicy>(
                CallWithContext(Traits::resolution_change_policy, input, custom_context), &result->resolution_change_policy);
            mojo::internal::Serialize<::media::mojom::PowerLineFrequency>(
                CallWithContext(Traits::power_line_frequency, input, custom_context), &result->power_line_frequency);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::VideoCaptureParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::VideoCaptureParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoFrameInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::VideoFrameInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::VideoFrameInfo_Data);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, context);
            decltype(CallWithContext(Traits::metadata, input, custom_context)) in_metadata = CallWithContext(Traits::metadata, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::DictionaryValueDataView>(
                in_metadata, context);
            decltype(CallWithContext(Traits::coded_size, input, custom_context)) in_coded_size = CallWithContext(Traits::coded_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_coded_size, context);
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_visible_rect, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::VideoFrameInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::VideoFrameInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            typename decltype(result->timestamp)::BaseType* timestamp_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, buffer, &timestamp_ptr, context);
            result->timestamp.Set(timestamp_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->timestamp.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null timestamp in VideoFrameInfo struct");
            decltype(CallWithContext(Traits::metadata, input, custom_context)) in_metadata = CallWithContext(Traits::metadata, input, custom_context);
            typename decltype(result->metadata)::BaseType* metadata_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::DictionaryValueDataView>(
                in_metadata, buffer, &metadata_ptr, context);
            result->metadata.Set(metadata_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->metadata.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null metadata in VideoFrameInfo struct");
            mojo::internal::Serialize<::media::mojom::VideoPixelFormat>(
                CallWithContext(Traits::pixel_format, input, custom_context), &result->pixel_format);
            mojo::internal::Serialize<::media::mojom::VideoPixelStorage>(
                CallWithContext(Traits::storage_type, input, custom_context), &result->storage_type);
            decltype(CallWithContext(Traits::coded_size, input, custom_context)) in_coded_size = CallWithContext(Traits::coded_size, input, custom_context);
            typename decltype(result->coded_size)::BaseType* coded_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_coded_size, buffer, &coded_size_ptr, context);
            result->coded_size.Set(coded_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->coded_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null coded_size in VideoFrameInfo struct");
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            typename decltype(result->visible_rect)::BaseType* visible_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_visible_rect, buffer, &visible_rect_ptr, context);
            result->visible_rect.Set(visible_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->visible_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null visible_rect in VideoFrameInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::VideoFrameInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::VideoFrameInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace media {
namespace mojom {

    inline void VideoCaptureFormatDataView::GetFrameSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->frame_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void VideoCaptureParamsDataView::GetRequestedFormatDataView(
        VideoCaptureFormatDataView* output)
    {
        auto pointer = data_->requested_format.Get();
        *output = VideoCaptureFormatDataView(pointer, context_);
    }

    inline void VideoFrameInfoDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void VideoFrameInfoDataView::GetMetadataDataView(
        ::mojo::common::mojom::DictionaryValueDataView* output)
    {
        auto pointer = data_->metadata.Get();
        *output = ::mojo::common::mojom::DictionaryValueDataView(pointer, context_);
    }
    inline void VideoFrameInfoDataView::GetCodedSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->coded_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void VideoFrameInfoDataView::GetVisibleRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->visible_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_CAPTURE_MOJO_VIDEO_CAPTURE_TYPES_MOJOM_SHARED_H_
