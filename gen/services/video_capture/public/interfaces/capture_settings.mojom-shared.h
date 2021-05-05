// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_SHARED_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/capture/mojo/video_capture_types.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/video_capture/public/interfaces/capture_settings.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace video_capture {
namespace mojom {
    class I420CaptureFormatDataView;

    class CaptureSettingsDataView;

} // namespace mojom
} // namespace video_capture

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::video_capture::mojom::I420CaptureFormatDataView> {
        using Data = ::video_capture::mojom::internal::I420CaptureFormat_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::video_capture::mojom::CaptureSettingsDataView> {
        using Data = ::video_capture::mojom::internal::CaptureSettings_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace video_capture {
namespace mojom {
    class I420CaptureFormatDataView {
    public:
        I420CaptureFormatDataView() { }

        I420CaptureFormatDataView(
            internal::I420CaptureFormat_Data* data,
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

    private:
        internal::I420CaptureFormat_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class CaptureSettingsDataView {
    public:
        CaptureSettingsDataView() { }

        CaptureSettingsDataView(
            internal::CaptureSettings_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormatDataView(
            I420CaptureFormatDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormat(UserType* output)
        {
            auto* pointer = data_->format.Get();
            return mojo::internal::Deserialize<::video_capture::mojom::I420CaptureFormatDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResolutionChangePolicy(UserType* output) const
        {
            auto data_value = data_->resolution_change_policy;
            return mojo::internal::Deserialize<::media::mojom::ResolutionChangePolicy>(
                data_value, output);
        }

        ::media::mojom::ResolutionChangePolicy resolution_change_policy() const
        {
            return static_cast<::media::mojom::ResolutionChangePolicy>(data_->resolution_change_policy);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPowerLineFrequency(UserType* output) const
        {
            auto data_value = data_->power_line_frequency;
            return mojo::internal::Deserialize<::media::mojom::PowerLineFrequency>(
                data_value, output);
        }

        ::media::mojom::PowerLineFrequency power_line_frequency() const
        {
            return static_cast<::media::mojom::PowerLineFrequency>(data_->power_line_frequency);
        }

    private:
        internal::CaptureSettings_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace video_capture

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::video_capture::mojom::I420CaptureFormatDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::video_capture::mojom::I420CaptureFormatDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::video_capture::mojom::internal::I420CaptureFormat_Data);
            decltype(CallWithContext(Traits::frame_size, input, custom_context)) in_frame_size = CallWithContext(Traits::frame_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_frame_size, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::video_capture::mojom::internal::I420CaptureFormat_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::video_capture::mojom::internal::I420CaptureFormat_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::frame_size, input, custom_context)) in_frame_size = CallWithContext(Traits::frame_size, input, custom_context);
            typename decltype(result->frame_size)::BaseType* frame_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_frame_size, buffer, &frame_size_ptr, context);
            result->frame_size.Set(frame_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_size in I420CaptureFormat struct");
            result->frame_rate = CallWithContext(Traits::frame_rate, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::video_capture::mojom::internal::I420CaptureFormat_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::video_capture::mojom::I420CaptureFormatDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::video_capture::mojom::CaptureSettingsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::video_capture::mojom::CaptureSettingsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::video_capture::mojom::internal::CaptureSettings_Data);
            decltype(CallWithContext(Traits::format, input, custom_context)) in_format = CallWithContext(Traits::format, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::video_capture::mojom::I420CaptureFormatDataView>(
                in_format, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::video_capture::mojom::internal::CaptureSettings_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::video_capture::mojom::internal::CaptureSettings_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::format, input, custom_context)) in_format = CallWithContext(Traits::format, input, custom_context);
            typename decltype(result->format)::BaseType* format_ptr;
            mojo::internal::Serialize<::video_capture::mojom::I420CaptureFormatDataView>(
                in_format, buffer, &format_ptr, context);
            result->format.Set(format_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->format.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null format in CaptureSettings struct");
            mojo::internal::Serialize<::media::mojom::ResolutionChangePolicy>(
                CallWithContext(Traits::resolution_change_policy, input, custom_context), &result->resolution_change_policy);
            mojo::internal::Serialize<::media::mojom::PowerLineFrequency>(
                CallWithContext(Traits::power_line_frequency, input, custom_context), &result->power_line_frequency);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::video_capture::mojom::internal::CaptureSettings_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::video_capture::mojom::CaptureSettingsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace video_capture {
namespace mojom {

    inline void I420CaptureFormatDataView::GetFrameSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->frame_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void CaptureSettingsDataView::GetFormatDataView(
        I420CaptureFormatDataView* output)
    {
        auto pointer = data_->format.Get();
        *output = I420CaptureFormatDataView(pointer, context_);
    }

} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_CAPTURE_SETTINGS_MOJOM_SHARED_H_
