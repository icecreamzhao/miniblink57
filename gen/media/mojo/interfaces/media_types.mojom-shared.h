// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared.h"
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
    class PatternDataView;

    class EncryptionSchemeDataView;

    class AudioDecoderConfigDataView;

    class VideoDecoderConfigDataView;

    using SubsampleEntryDataView = mojo::NativeStructDataView;

    class DecryptConfigDataView;

    class DecoderBufferDataView;

    class AudioBufferDataView;

    class VideoFrameDataView;

    class PipelineStatisticsDataView;

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::media::mojom::PatternDataView> {
        using Data = ::media::mojom::internal::Pattern_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::EncryptionSchemeDataView> {
        using Data = ::media::mojom::internal::EncryptionScheme_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::AudioDecoderConfigDataView> {
        using Data = ::media::mojom::internal::AudioDecoderConfig_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::VideoDecoderConfigDataView> {
        using Data = ::media::mojom::internal::VideoDecoderConfig_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::DecryptConfigDataView> {
        using Data = ::media::mojom::internal::DecryptConfig_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::DecoderBufferDataView> {
        using Data = ::media::mojom::internal::DecoderBuffer_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::AudioBufferDataView> {
        using Data = ::media::mojom::internal::AudioBuffer_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::VideoFrameDataView> {
        using Data = ::media::mojom::internal::VideoFrame_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::PipelineStatisticsDataView> {
        using Data = ::media::mojom::internal::PipelineStatistics_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {
    using BufferingState = mojo::NativeEnum;
    using DecodeStatus = mojo::NativeEnum;
    using AudioCodec = mojo::NativeEnum;
    using ChannelLayout = mojo::NativeEnum;
    using SampleFormat = mojo::NativeEnum;
    using VideoPixelFormat = mojo::NativeEnum;
    using ColorSpace = mojo::NativeEnum;
    using VideoCodec = mojo::NativeEnum;
    using VideoCodecProfile = mojo::NativeEnum;
    using EncryptionScheme_CipherMode = mojo::NativeEnum;
    class PatternDataView {
    public:
        PatternDataView() { }

        PatternDataView(
            internal::Pattern_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t encrypt_blocks() const
        {
            return data_->encrypt_blocks;
        }
        uint32_t skip_blocks() const
        {
            return data_->skip_blocks;
        }

    private:
        internal::Pattern_Data* data_ = nullptr;
    };

    class EncryptionSchemeDataView {
    public:
        EncryptionSchemeDataView() { }

        EncryptionSchemeDataView(
            internal::EncryptionScheme_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMode(UserType* output) const
        {
            auto data_value = data_->mode;
            return mojo::internal::Deserialize<::media::mojom::EncryptionScheme_CipherMode>(
                data_value, output);
        }

        EncryptionScheme_CipherMode mode() const
        {
            return static_cast<EncryptionScheme_CipherMode>(data_->mode);
        }
        inline void GetPatternDataView(
            PatternDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPattern(UserType* output)
        {
            auto* pointer = data_->pattern.Get();
            return mojo::internal::Deserialize<::media::mojom::PatternDataView>(
                pointer, output, context_);
        }

    private:
        internal::EncryptionScheme_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioDecoderConfigDataView {
    public:
        AudioDecoderConfigDataView() { }

        AudioDecoderConfigDataView(
            internal::AudioDecoderConfig_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCodec(UserType* output) const
        {
            auto data_value = data_->codec;
            return mojo::internal::Deserialize<::media::mojom::AudioCodec>(
                data_value, output);
        }

        AudioCodec codec() const
        {
            return static_cast<AudioCodec>(data_->codec);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSampleFormat(UserType* output) const
        {
            auto data_value = data_->sample_format;
            return mojo::internal::Deserialize<::media::mojom::SampleFormat>(
                data_value, output);
        }

        SampleFormat sample_format() const
        {
            return static_cast<SampleFormat>(data_->sample_format);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChannelLayout(UserType* output) const
        {
            auto data_value = data_->channel_layout;
            return mojo::internal::Deserialize<::media::mojom::ChannelLayout>(
                data_value, output);
        }

        ChannelLayout channel_layout() const
        {
            return static_cast<ChannelLayout>(data_->channel_layout);
        }
        int32_t samples_per_second() const
        {
            return data_->samples_per_second;
        }
        inline void GetExtraDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExtraData(UserType* output)
        {
            auto* pointer = data_->extra_data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetSeekPrerollDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSeekPreroll(UserType* output)
        {
            auto* pointer = data_->seek_preroll.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        int32_t codec_delay() const
        {
            return data_->codec_delay;
        }
        inline void GetEncryptionSchemeDataView(
            EncryptionSchemeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEncryptionScheme(UserType* output)
        {
            auto* pointer = data_->encryption_scheme.Get();
            return mojo::internal::Deserialize<::media::mojom::EncryptionSchemeDataView>(
                pointer, output, context_);
        }

    private:
        internal::AudioDecoderConfig_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecoderConfigDataView {
    public:
        VideoDecoderConfigDataView() { }

        VideoDecoderConfigDataView(
            internal::VideoDecoderConfig_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCodec(UserType* output) const
        {
            auto data_value = data_->codec;
            return mojo::internal::Deserialize<::media::mojom::VideoCodec>(
                data_value, output);
        }

        VideoCodec codec() const
        {
            return static_cast<VideoCodec>(data_->codec);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProfile(UserType* output) const
        {
            auto data_value = data_->profile;
            return mojo::internal::Deserialize<::media::mojom::VideoCodecProfile>(
                data_value, output);
        }

        VideoCodecProfile profile() const
        {
            return static_cast<VideoCodecProfile>(data_->profile);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormat(UserType* output) const
        {
            auto data_value = data_->format;
            return mojo::internal::Deserialize<::media::mojom::VideoPixelFormat>(
                data_value, output);
        }

        VideoPixelFormat format() const
        {
            return static_cast<VideoPixelFormat>(data_->format);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadColorSpace(UserType* output) const
        {
            auto data_value = data_->color_space;
            return mojo::internal::Deserialize<::media::mojom::ColorSpace>(
                data_value, output);
        }

        ColorSpace color_space() const
        {
            return static_cast<ColorSpace>(data_->color_space);
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
        inline void GetNaturalSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNaturalSize(UserType* output)
        {
            auto* pointer = data_->natural_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetExtraDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExtraData(UserType* output)
        {
            auto* pointer = data_->extra_data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetEncryptionSchemeDataView(
            EncryptionSchemeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEncryptionScheme(UserType* output)
        {
            auto* pointer = data_->encryption_scheme.Get();
            return mojo::internal::Deserialize<::media::mojom::EncryptionSchemeDataView>(
                pointer, output, context_);
        }

    private:
        internal::VideoDecoderConfig_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DecryptConfigDataView {
    public:
        DecryptConfigDataView() { }

        DecryptConfigDataView(
            internal::DecryptConfig_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyId(UserType* output)
        {
            auto* pointer = data_->key_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIvDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIv(UserType* output)
        {
            auto* pointer = data_->iv.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetSubsamplesDataView(
            mojo::ArrayDataView<SubsampleEntryDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSubsamples(UserType* output)
        {
            auto* pointer = data_->subsamples.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::media::mojom::SubsampleEntryDataView>>(
                pointer, output, context_);
        }

    private:
        internal::DecryptConfig_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DecoderBufferDataView {
    public:
        DecoderBufferDataView() { }

        DecoderBufferDataView(
            internal::DecoderBuffer_Data* data,
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
        inline void GetDurationDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDuration(UserType* output)
        {
            auto* pointer = data_->duration.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        bool is_end_of_stream() const
        {
            return data_->is_end_of_stream;
        }
        uint32_t data_size() const
        {
            return data_->data_size;
        }
        bool is_key_frame() const
        {
            return data_->is_key_frame;
        }
        inline void GetSideDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSideData(UserType* output)
        {
            auto* pointer = data_->side_data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetDecryptConfigDataView(
            DecryptConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDecryptConfig(UserType* output)
        {
            auto* pointer = data_->decrypt_config.Get();
            return mojo::internal::Deserialize<::media::mojom::DecryptConfigDataView>(
                pointer, output, context_);
        }
        inline void GetFrontDiscardDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrontDiscard(UserType* output)
        {
            auto* pointer = data_->front_discard.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        inline void GetBackDiscardDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBackDiscard(UserType* output)
        {
            auto* pointer = data_->back_discard.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        inline void GetSpliceTimestampDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSpliceTimestamp(UserType* output)
        {
            auto* pointer = data_->splice_timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }

    private:
        internal::DecoderBuffer_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioBufferDataView {
    public:
        AudioBufferDataView() { }

        AudioBufferDataView(
            internal::AudioBuffer_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSampleFormat(UserType* output) const
        {
            auto data_value = data_->sample_format;
            return mojo::internal::Deserialize<::media::mojom::SampleFormat>(
                data_value, output);
        }

        SampleFormat sample_format() const
        {
            return static_cast<SampleFormat>(data_->sample_format);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChannelLayout(UserType* output) const
        {
            auto data_value = data_->channel_layout;
            return mojo::internal::Deserialize<::media::mojom::ChannelLayout>(
                data_value, output);
        }

        ChannelLayout channel_layout() const
        {
            return static_cast<ChannelLayout>(data_->channel_layout);
        }
        int32_t channel_count() const
        {
            return data_->channel_count;
        }
        int32_t sample_rate() const
        {
            return data_->sample_rate;
        }
        int32_t frame_count() const
        {
            return data_->frame_count;
        }
        bool end_of_stream() const
        {
            return data_->end_of_stream;
        }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::AudioBuffer_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoFrameDataView {
    public:
        VideoFrameDataView() { }

        VideoFrameDataView(
            internal::VideoFrame_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormat(UserType* output) const
        {
            auto data_value = data_->format;
            return mojo::internal::Deserialize<::media::mojom::VideoPixelFormat>(
                data_value, output);
        }

        VideoPixelFormat format() const
        {
            return static_cast<VideoPixelFormat>(data_->format);
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
        inline void GetNaturalSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNaturalSize(UserType* output)
        {
            auto* pointer = data_->natural_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        bool end_of_stream() const
        {
            return data_->end_of_stream;
        }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        mojo::ScopedSharedBufferHandle TakeFrameData()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->frame_data, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint64_t frame_data_size() const
        {
            return data_->frame_data_size;
        }
        int32_t y_stride() const
        {
            return data_->y_stride;
        }
        int32_t u_stride() const
        {
            return data_->u_stride;
        }
        int32_t v_stride() const
        {
            return data_->v_stride;
        }
        uint64_t y_offset() const
        {
            return data_->y_offset;
        }
        uint64_t u_offset() const
        {
            return data_->u_offset;
        }
        uint64_t v_offset() const
        {
            return data_->v_offset;
        }

    private:
        internal::VideoFrame_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PipelineStatisticsDataView {
    public:
        PipelineStatisticsDataView() { }

        PipelineStatisticsDataView(
            internal::PipelineStatistics_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t audio_bytes_decoded() const
        {
            return data_->audio_bytes_decoded;
        }
        uint64_t video_bytes_decoded() const
        {
            return data_->video_bytes_decoded;
        }
        uint32_t video_frames_decoded() const
        {
            return data_->video_frames_decoded;
        }
        uint32_t video_frames_dropped() const
        {
            return data_->video_frames_dropped;
        }
        int64_t audio_memory_usage() const
        {
            return data_->audio_memory_usage;
        }
        int64_t video_memory_usage() const
        {
            return data_->video_memory_usage;
        }

    private:
        internal::PipelineStatistics_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::PatternDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::PatternDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::Pattern_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::Pattern_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::Pattern_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->encrypt_blocks = CallWithContext(Traits::encrypt_blocks, input, custom_context);
            result->skip_blocks = CallWithContext(Traits::skip_blocks, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::Pattern_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::PatternDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::EncryptionSchemeDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::EncryptionSchemeDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::EncryptionScheme_Data);
            decltype(CallWithContext(Traits::pattern, input, custom_context)) in_pattern = CallWithContext(Traits::pattern, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::PatternDataView>(
                in_pattern, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::EncryptionScheme_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::EncryptionScheme_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::media::mojom::EncryptionScheme_CipherMode>(
                CallWithContext(Traits::mode, input, custom_context), &result->mode);
            decltype(CallWithContext(Traits::pattern, input, custom_context)) in_pattern = CallWithContext(Traits::pattern, input, custom_context);
            typename decltype(result->pattern)::BaseType* pattern_ptr;
            mojo::internal::Serialize<::media::mojom::PatternDataView>(
                in_pattern, buffer, &pattern_ptr, context);
            result->pattern.Set(pattern_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->pattern.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null pattern in EncryptionScheme struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::EncryptionScheme_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::EncryptionSchemeDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::AudioDecoderConfigDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::AudioDecoderConfigDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::AudioDecoderConfig_Data);
            decltype(CallWithContext(Traits::extra_data, input, custom_context)) in_extra_data = CallWithContext(Traits::extra_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_extra_data, context);
            decltype(CallWithContext(Traits::seek_preroll, input, custom_context)) in_seek_preroll = CallWithContext(Traits::seek_preroll, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_seek_preroll, context);
            decltype(CallWithContext(Traits::encryption_scheme, input, custom_context)) in_encryption_scheme = CallWithContext(Traits::encryption_scheme, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::EncryptionSchemeDataView>(
                in_encryption_scheme, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::AudioDecoderConfig_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::AudioDecoderConfig_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::media::mojom::AudioCodec>(
                CallWithContext(Traits::codec, input, custom_context), &result->codec);
            mojo::internal::Serialize<::media::mojom::SampleFormat>(
                CallWithContext(Traits::sample_format, input, custom_context), &result->sample_format);
            mojo::internal::Serialize<::media::mojom::ChannelLayout>(
                CallWithContext(Traits::channel_layout, input, custom_context), &result->channel_layout);
            result->samples_per_second = CallWithContext(Traits::samples_per_second, input, custom_context);
            decltype(CallWithContext(Traits::extra_data, input, custom_context)) in_extra_data = CallWithContext(Traits::extra_data, input, custom_context);
            typename decltype(result->extra_data)::BaseType* extra_data_ptr;
            const mojo::internal::ContainerValidateParams extra_data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_extra_data, buffer, &extra_data_ptr, &extra_data_validate_params,
                context);
            result->extra_data.Set(extra_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->extra_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null extra_data in AudioDecoderConfig struct");
            decltype(CallWithContext(Traits::seek_preroll, input, custom_context)) in_seek_preroll = CallWithContext(Traits::seek_preroll, input, custom_context);
            typename decltype(result->seek_preroll)::BaseType* seek_preroll_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_seek_preroll, buffer, &seek_preroll_ptr, context);
            result->seek_preroll.Set(seek_preroll_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->seek_preroll.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null seek_preroll in AudioDecoderConfig struct");
            result->codec_delay = CallWithContext(Traits::codec_delay, input, custom_context);
            decltype(CallWithContext(Traits::encryption_scheme, input, custom_context)) in_encryption_scheme = CallWithContext(Traits::encryption_scheme, input, custom_context);
            typename decltype(result->encryption_scheme)::BaseType* encryption_scheme_ptr;
            mojo::internal::Serialize<::media::mojom::EncryptionSchemeDataView>(
                in_encryption_scheme, buffer, &encryption_scheme_ptr, context);
            result->encryption_scheme.Set(encryption_scheme_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->encryption_scheme.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null encryption_scheme in AudioDecoderConfig struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::AudioDecoderConfig_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::AudioDecoderConfigDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoDecoderConfigDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::VideoDecoderConfigDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::VideoDecoderConfig_Data);
            decltype(CallWithContext(Traits::coded_size, input, custom_context)) in_coded_size = CallWithContext(Traits::coded_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_coded_size, context);
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_visible_rect, context);
            decltype(CallWithContext(Traits::natural_size, input, custom_context)) in_natural_size = CallWithContext(Traits::natural_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_natural_size, context);
            decltype(CallWithContext(Traits::extra_data, input, custom_context)) in_extra_data = CallWithContext(Traits::extra_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_extra_data, context);
            decltype(CallWithContext(Traits::encryption_scheme, input, custom_context)) in_encryption_scheme = CallWithContext(Traits::encryption_scheme, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::EncryptionSchemeDataView>(
                in_encryption_scheme, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::VideoDecoderConfig_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::VideoDecoderConfig_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::media::mojom::VideoCodec>(
                CallWithContext(Traits::codec, input, custom_context), &result->codec);
            mojo::internal::Serialize<::media::mojom::VideoCodecProfile>(
                CallWithContext(Traits::profile, input, custom_context), &result->profile);
            mojo::internal::Serialize<::media::mojom::VideoPixelFormat>(
                CallWithContext(Traits::format, input, custom_context), &result->format);
            mojo::internal::Serialize<::media::mojom::ColorSpace>(
                CallWithContext(Traits::color_space, input, custom_context), &result->color_space);
            decltype(CallWithContext(Traits::coded_size, input, custom_context)) in_coded_size = CallWithContext(Traits::coded_size, input, custom_context);
            typename decltype(result->coded_size)::BaseType* coded_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_coded_size, buffer, &coded_size_ptr, context);
            result->coded_size.Set(coded_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->coded_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null coded_size in VideoDecoderConfig struct");
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            typename decltype(result->visible_rect)::BaseType* visible_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_visible_rect, buffer, &visible_rect_ptr, context);
            result->visible_rect.Set(visible_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->visible_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null visible_rect in VideoDecoderConfig struct");
            decltype(CallWithContext(Traits::natural_size, input, custom_context)) in_natural_size = CallWithContext(Traits::natural_size, input, custom_context);
            typename decltype(result->natural_size)::BaseType* natural_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_natural_size, buffer, &natural_size_ptr, context);
            result->natural_size.Set(natural_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->natural_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null natural_size in VideoDecoderConfig struct");
            decltype(CallWithContext(Traits::extra_data, input, custom_context)) in_extra_data = CallWithContext(Traits::extra_data, input, custom_context);
            typename decltype(result->extra_data)::BaseType* extra_data_ptr;
            const mojo::internal::ContainerValidateParams extra_data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_extra_data, buffer, &extra_data_ptr, &extra_data_validate_params,
                context);
            result->extra_data.Set(extra_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->extra_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null extra_data in VideoDecoderConfig struct");
            decltype(CallWithContext(Traits::encryption_scheme, input, custom_context)) in_encryption_scheme = CallWithContext(Traits::encryption_scheme, input, custom_context);
            typename decltype(result->encryption_scheme)::BaseType* encryption_scheme_ptr;
            mojo::internal::Serialize<::media::mojom::EncryptionSchemeDataView>(
                in_encryption_scheme, buffer, &encryption_scheme_ptr, context);
            result->encryption_scheme.Set(encryption_scheme_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->encryption_scheme.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null encryption_scheme in VideoDecoderConfig struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::VideoDecoderConfig_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::VideoDecoderConfigDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::DecryptConfigDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::DecryptConfigDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::DecryptConfig_Data);
            decltype(CallWithContext(Traits::key_id, input, custom_context)) in_key_id = CallWithContext(Traits::key_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_key_id, context);
            decltype(CallWithContext(Traits::iv, input, custom_context)) in_iv = CallWithContext(Traits::iv, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_iv, context);
            decltype(CallWithContext(Traits::subsamples, input, custom_context)) in_subsamples = CallWithContext(Traits::subsamples, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::media::mojom::SubsampleEntryDataView>>(
                in_subsamples, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::DecryptConfig_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::DecryptConfig_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::key_id, input, custom_context)) in_key_id = CallWithContext(Traits::key_id, input, custom_context);
            typename decltype(result->key_id)::BaseType* key_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_key_id, buffer, &key_id_ptr, context);
            result->key_id.Set(key_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->key_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null key_id in DecryptConfig struct");
            decltype(CallWithContext(Traits::iv, input, custom_context)) in_iv = CallWithContext(Traits::iv, input, custom_context);
            typename decltype(result->iv)::BaseType* iv_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_iv, buffer, &iv_ptr, context);
            result->iv.Set(iv_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->iv.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null iv in DecryptConfig struct");
            decltype(CallWithContext(Traits::subsamples, input, custom_context)) in_subsamples = CallWithContext(Traits::subsamples, input, custom_context);
            typename decltype(result->subsamples)::BaseType* subsamples_ptr;
            const mojo::internal::ContainerValidateParams subsamples_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::media::mojom::SubsampleEntryDataView>>(
                in_subsamples, buffer, &subsamples_ptr, &subsamples_validate_params,
                context);
            result->subsamples.Set(subsamples_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->subsamples.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null subsamples in DecryptConfig struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::DecryptConfig_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::DecryptConfigDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::DecoderBufferDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::DecoderBufferDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::DecoderBuffer_Data);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, context);
            decltype(CallWithContext(Traits::duration, input, custom_context)) in_duration = CallWithContext(Traits::duration, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_duration, context);
            decltype(CallWithContext(Traits::side_data, input, custom_context)) in_side_data = CallWithContext(Traits::side_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_side_data, context);
            decltype(CallWithContext(Traits::decrypt_config, input, custom_context)) in_decrypt_config = CallWithContext(Traits::decrypt_config, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::DecryptConfigDataView>(
                in_decrypt_config, context);
            decltype(CallWithContext(Traits::front_discard, input, custom_context)) in_front_discard = CallWithContext(Traits::front_discard, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_front_discard, context);
            decltype(CallWithContext(Traits::back_discard, input, custom_context)) in_back_discard = CallWithContext(Traits::back_discard, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_back_discard, context);
            decltype(CallWithContext(Traits::splice_timestamp, input, custom_context)) in_splice_timestamp = CallWithContext(Traits::splice_timestamp, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_splice_timestamp, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::DecoderBuffer_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::DecoderBuffer_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            typename decltype(result->timestamp)::BaseType* timestamp_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, buffer, &timestamp_ptr, context);
            result->timestamp.Set(timestamp_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->timestamp.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null timestamp in DecoderBuffer struct");
            decltype(CallWithContext(Traits::duration, input, custom_context)) in_duration = CallWithContext(Traits::duration, input, custom_context);
            typename decltype(result->duration)::BaseType* duration_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_duration, buffer, &duration_ptr, context);
            result->duration.Set(duration_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->duration.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null duration in DecoderBuffer struct");
            result->is_end_of_stream = CallWithContext(Traits::is_end_of_stream, input, custom_context);
            result->data_size = CallWithContext(Traits::data_size, input, custom_context);
            result->is_key_frame = CallWithContext(Traits::is_key_frame, input, custom_context);
            decltype(CallWithContext(Traits::side_data, input, custom_context)) in_side_data = CallWithContext(Traits::side_data, input, custom_context);
            typename decltype(result->side_data)::BaseType* side_data_ptr;
            const mojo::internal::ContainerValidateParams side_data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_side_data, buffer, &side_data_ptr, &side_data_validate_params,
                context);
            result->side_data.Set(side_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->side_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null side_data in DecoderBuffer struct");
            decltype(CallWithContext(Traits::decrypt_config, input, custom_context)) in_decrypt_config = CallWithContext(Traits::decrypt_config, input, custom_context);
            typename decltype(result->decrypt_config)::BaseType* decrypt_config_ptr;
            mojo::internal::Serialize<::media::mojom::DecryptConfigDataView>(
                in_decrypt_config, buffer, &decrypt_config_ptr, context);
            result->decrypt_config.Set(decrypt_config_ptr);
            decltype(CallWithContext(Traits::front_discard, input, custom_context)) in_front_discard = CallWithContext(Traits::front_discard, input, custom_context);
            typename decltype(result->front_discard)::BaseType* front_discard_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_front_discard, buffer, &front_discard_ptr, context);
            result->front_discard.Set(front_discard_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->front_discard.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null front_discard in DecoderBuffer struct");
            decltype(CallWithContext(Traits::back_discard, input, custom_context)) in_back_discard = CallWithContext(Traits::back_discard, input, custom_context);
            typename decltype(result->back_discard)::BaseType* back_discard_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_back_discard, buffer, &back_discard_ptr, context);
            result->back_discard.Set(back_discard_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->back_discard.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null back_discard in DecoderBuffer struct");
            decltype(CallWithContext(Traits::splice_timestamp, input, custom_context)) in_splice_timestamp = CallWithContext(Traits::splice_timestamp, input, custom_context);
            typename decltype(result->splice_timestamp)::BaseType* splice_timestamp_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_splice_timestamp, buffer, &splice_timestamp_ptr, context);
            result->splice_timestamp.Set(splice_timestamp_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->splice_timestamp.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null splice_timestamp in DecoderBuffer struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::DecoderBuffer_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::DecoderBufferDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::AudioBufferDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::AudioBufferDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::AudioBuffer_Data);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::AudioBuffer_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::AudioBuffer_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::media::mojom::SampleFormat>(
                CallWithContext(Traits::sample_format, input, custom_context), &result->sample_format);
            mojo::internal::Serialize<::media::mojom::ChannelLayout>(
                CallWithContext(Traits::channel_layout, input, custom_context), &result->channel_layout);
            result->channel_count = CallWithContext(Traits::channel_count, input, custom_context);
            result->sample_rate = CallWithContext(Traits::sample_rate, input, custom_context);
            result->frame_count = CallWithContext(Traits::frame_count, input, custom_context);
            result->end_of_stream = CallWithContext(Traits::end_of_stream, input, custom_context);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            typename decltype(result->timestamp)::BaseType* timestamp_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, buffer, &timestamp_ptr, context);
            result->timestamp.Set(timestamp_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->timestamp.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null timestamp in AudioBuffer struct");
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in AudioBuffer struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::AudioBuffer_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::AudioBufferDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::VideoFrameDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::VideoFrameDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::VideoFrame_Data);
            decltype(CallWithContext(Traits::coded_size, input, custom_context)) in_coded_size = CallWithContext(Traits::coded_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_coded_size, context);
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_visible_rect, context);
            decltype(CallWithContext(Traits::natural_size, input, custom_context)) in_natural_size = CallWithContext(Traits::natural_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_natural_size, context);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::VideoFrame_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::VideoFrame_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::media::mojom::VideoPixelFormat>(
                CallWithContext(Traits::format, input, custom_context), &result->format);
            decltype(CallWithContext(Traits::coded_size, input, custom_context)) in_coded_size = CallWithContext(Traits::coded_size, input, custom_context);
            typename decltype(result->coded_size)::BaseType* coded_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_coded_size, buffer, &coded_size_ptr, context);
            result->coded_size.Set(coded_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->coded_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null coded_size in VideoFrame struct");
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            typename decltype(result->visible_rect)::BaseType* visible_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_visible_rect, buffer, &visible_rect_ptr, context);
            result->visible_rect.Set(visible_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->visible_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null visible_rect in VideoFrame struct");
            decltype(CallWithContext(Traits::natural_size, input, custom_context)) in_natural_size = CallWithContext(Traits::natural_size, input, custom_context);
            typename decltype(result->natural_size)::BaseType* natural_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_natural_size, buffer, &natural_size_ptr, context);
            result->natural_size.Set(natural_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->natural_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null natural_size in VideoFrame struct");
            result->end_of_stream = CallWithContext(Traits::end_of_stream, input, custom_context);
            decltype(CallWithContext(Traits::timestamp, input, custom_context)) in_timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            typename decltype(result->timestamp)::BaseType* timestamp_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_timestamp, buffer, &timestamp_ptr, context);
            result->timestamp.Set(timestamp_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->timestamp.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null timestamp in VideoFrame struct");
            decltype(CallWithContext(Traits::frame_data, input, custom_context)) in_frame_data = CallWithContext(Traits::frame_data, input, custom_context);
            mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
                in_frame_data, &result->frame_data, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->frame_data),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid frame_data in VideoFrame struct");
            result->frame_data_size = CallWithContext(Traits::frame_data_size, input, custom_context);
            result->y_stride = CallWithContext(Traits::y_stride, input, custom_context);
            result->u_stride = CallWithContext(Traits::u_stride, input, custom_context);
            result->v_stride = CallWithContext(Traits::v_stride, input, custom_context);
            result->y_offset = CallWithContext(Traits::y_offset, input, custom_context);
            result->u_offset = CallWithContext(Traits::u_offset, input, custom_context);
            result->v_offset = CallWithContext(Traits::v_offset, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::VideoFrame_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::VideoFrameDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::PipelineStatisticsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::PipelineStatisticsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::PipelineStatistics_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::PipelineStatistics_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::PipelineStatistics_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->audio_bytes_decoded = CallWithContext(Traits::audio_bytes_decoded, input, custom_context);
            result->video_bytes_decoded = CallWithContext(Traits::video_bytes_decoded, input, custom_context);
            result->video_frames_decoded = CallWithContext(Traits::video_frames_decoded, input, custom_context);
            result->video_frames_dropped = CallWithContext(Traits::video_frames_dropped, input, custom_context);
            result->audio_memory_usage = CallWithContext(Traits::audio_memory_usage, input, custom_context);
            result->video_memory_usage = CallWithContext(Traits::video_memory_usage, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::PipelineStatistics_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::PipelineStatisticsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace media {
namespace mojom {

    inline void EncryptionSchemeDataView::GetPatternDataView(
        PatternDataView* output)
    {
        auto pointer = data_->pattern.Get();
        *output = PatternDataView(pointer, context_);
    }

    inline void AudioDecoderConfigDataView::GetExtraDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->extra_data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void AudioDecoderConfigDataView::GetSeekPrerollDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->seek_preroll.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void AudioDecoderConfigDataView::GetEncryptionSchemeDataView(
        EncryptionSchemeDataView* output)
    {
        auto pointer = data_->encryption_scheme.Get();
        *output = EncryptionSchemeDataView(pointer, context_);
    }

    inline void VideoDecoderConfigDataView::GetCodedSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->coded_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void VideoDecoderConfigDataView::GetVisibleRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->visible_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void VideoDecoderConfigDataView::GetNaturalSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->natural_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void VideoDecoderConfigDataView::GetExtraDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->extra_data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void VideoDecoderConfigDataView::GetEncryptionSchemeDataView(
        EncryptionSchemeDataView* output)
    {
        auto pointer = data_->encryption_scheme.Get();
        *output = EncryptionSchemeDataView(pointer, context_);
    }

    inline void DecryptConfigDataView::GetKeyIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->key_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DecryptConfigDataView::GetIvDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->iv.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DecryptConfigDataView::GetSubsamplesDataView(
        mojo::ArrayDataView<SubsampleEntryDataView>* output)
    {
        auto pointer = data_->subsamples.Get();
        *output = mojo::ArrayDataView<SubsampleEntryDataView>(pointer, context_);
    }

    inline void DecoderBufferDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void DecoderBufferDataView::GetDurationDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->duration.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void DecoderBufferDataView::GetSideDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->side_data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void DecoderBufferDataView::GetDecryptConfigDataView(
        DecryptConfigDataView* output)
    {
        auto pointer = data_->decrypt_config.Get();
        *output = DecryptConfigDataView(pointer, context_);
    }
    inline void DecoderBufferDataView::GetFrontDiscardDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->front_discard.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void DecoderBufferDataView::GetBackDiscardDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->back_discard.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void DecoderBufferDataView::GetSpliceTimestampDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->splice_timestamp.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }

    inline void AudioBufferDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void AudioBufferDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void VideoFrameDataView::GetCodedSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->coded_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void VideoFrameDataView::GetVisibleRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->visible_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void VideoFrameDataView::GetNaturalSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->natural_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void VideoFrameDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_SHARED_H_
