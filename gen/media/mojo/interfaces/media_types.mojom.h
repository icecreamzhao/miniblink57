// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_H_

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
#include "media/mojo/interfaces/media_types.mojom-shared.h"
#include "mojo/common/time.mojom.h"
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
    class Pattern;
    using PatternPtr = mojo::InlinedStructPtr<Pattern>;

    class EncryptionScheme;
    using EncryptionSchemePtr = mojo::StructPtr<EncryptionScheme>;

    class AudioDecoderConfig;
    using AudioDecoderConfigPtr = mojo::StructPtr<AudioDecoderConfig>;

    class VideoDecoderConfig;
    using VideoDecoderConfigPtr = mojo::StructPtr<VideoDecoderConfig>;

    using SubsampleEntry = mojo::NativeStruct;
    using SubsampleEntryPtr = mojo::NativeStructPtr;

    class DecryptConfig;
    using DecryptConfigPtr = mojo::StructPtr<DecryptConfig>;

    class DecoderBuffer;
    using DecoderBufferPtr = mojo::StructPtr<DecoderBuffer>;

    class AudioBuffer;
    using AudioBufferPtr = mojo::StructPtr<AudioBuffer>;

    class VideoFrame;
    using VideoFramePtr = mojo::StructPtr<VideoFrame>;

    class PipelineStatistics;
    using PipelineStatisticsPtr = mojo::StructPtr<PipelineStatistics>;

    class Pattern {
    public:
        using DataView = PatternDataView;
        using Data_ = internal::Pattern_Data;

        static PatternPtr New();

        template <typename U>
        static PatternPtr From(const U& u)
        {
            return mojo::TypeConverter<PatternPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Pattern>::Convert(*this);
        }

        Pattern();
        ~Pattern();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PatternPtr>
        PatternPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Pattern>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Pattern::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Pattern::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t encrypt_blocks;
        uint32_t skip_blocks;
    };

    class EncryptionScheme {
    public:
        using DataView = EncryptionSchemeDataView;
        using Data_ = internal::EncryptionScheme_Data;
        using CipherMode = EncryptionScheme_CipherMode;

        static EncryptionSchemePtr New();

        template <typename U>
        static EncryptionSchemePtr From(const U& u)
        {
            return mojo::TypeConverter<EncryptionSchemePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, EncryptionScheme>::Convert(*this);
        }

        EncryptionScheme();
        ~EncryptionScheme();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = EncryptionSchemePtr>
        EncryptionSchemePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, EncryptionScheme>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                EncryptionScheme::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                EncryptionScheme::DataView, std::vector<uint8_t>>(
                input, output);
        }

        media::EncryptionScheme::CipherMode mode;
        PatternPtr pattern;

    private:
        DISALLOW_COPY_AND_ASSIGN(EncryptionScheme);
    };

    class AudioDecoderConfig {
    public:
        using DataView = AudioDecoderConfigDataView;
        using Data_ = internal::AudioDecoderConfig_Data;

        static AudioDecoderConfigPtr New();

        template <typename U>
        static AudioDecoderConfigPtr From(const U& u)
        {
            return mojo::TypeConverter<AudioDecoderConfigPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, AudioDecoderConfig>::Convert(*this);
        }

        AudioDecoderConfig();
        ~AudioDecoderConfig();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = AudioDecoderConfigPtr>
        AudioDecoderConfigPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, AudioDecoderConfig>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                AudioDecoderConfig::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                AudioDecoderConfig::DataView, std::vector<uint8_t>>(
                input, output);
        }

        media::AudioCodec codec;
        media::SampleFormat sample_format;
        media::ChannelLayout channel_layout;
        int32_t samples_per_second;
        std::vector<uint8_t> extra_data;
        base::TimeDelta seek_preroll;
        int32_t codec_delay;
        EncryptionSchemePtr encryption_scheme;

    private:
        DISALLOW_COPY_AND_ASSIGN(AudioDecoderConfig);
    };

    class VideoDecoderConfig {
    public:
        using DataView = VideoDecoderConfigDataView;
        using Data_ = internal::VideoDecoderConfig_Data;

        static VideoDecoderConfigPtr New();

        template <typename U>
        static VideoDecoderConfigPtr From(const U& u)
        {
            return mojo::TypeConverter<VideoDecoderConfigPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, VideoDecoderConfig>::Convert(*this);
        }

        VideoDecoderConfig();
        ~VideoDecoderConfig();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = VideoDecoderConfigPtr>
        VideoDecoderConfigPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoDecoderConfig>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                VideoDecoderConfig::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                VideoDecoderConfig::DataView, std::vector<uint8_t>>(
                input, output);
        }

        media::VideoCodec codec;
        media::VideoCodecProfile profile;
        media::VideoPixelFormat format;
        media::ColorSpace color_space;
        gfx::Size coded_size;
        gfx::Rect visible_rect;
        gfx::Size natural_size;
        std::vector<uint8_t> extra_data;
        EncryptionSchemePtr encryption_scheme;

    private:
        DISALLOW_COPY_AND_ASSIGN(VideoDecoderConfig);
    };

    class DecryptConfig {
    public:
        using DataView = DecryptConfigDataView;
        using Data_ = internal::DecryptConfig_Data;

        static DecryptConfigPtr New();

        template <typename U>
        static DecryptConfigPtr From(const U& u)
        {
            return mojo::TypeConverter<DecryptConfigPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DecryptConfig>::Convert(*this);
        }

        DecryptConfig();
        ~DecryptConfig();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DecryptConfigPtr>
        DecryptConfigPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DecryptConfig>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DecryptConfig::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DecryptConfig::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string key_id;
        std::string iv;
        std::vector<media::SubsampleEntry> subsamples;
    };

    class DecoderBuffer {
    public:
        using DataView = DecoderBufferDataView;
        using Data_ = internal::DecoderBuffer_Data;

        static DecoderBufferPtr New();

        template <typename U>
        static DecoderBufferPtr From(const U& u)
        {
            return mojo::TypeConverter<DecoderBufferPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DecoderBuffer>::Convert(*this);
        }

        DecoderBuffer();
        ~DecoderBuffer();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DecoderBufferPtr>
        DecoderBufferPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DecoderBuffer>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DecoderBuffer::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DecoderBuffer::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::TimeDelta timestamp;
        base::TimeDelta duration;
        bool is_end_of_stream;
        uint32_t data_size;
        bool is_key_frame;
        std::vector<uint8_t> side_data;
        DecryptConfigPtr decrypt_config;
        base::TimeDelta front_discard;
        base::TimeDelta back_discard;
        base::TimeDelta splice_timestamp;

    private:
        DISALLOW_COPY_AND_ASSIGN(DecoderBuffer);
    };

    class AudioBuffer {
    public:
        using DataView = AudioBufferDataView;
        using Data_ = internal::AudioBuffer_Data;

        static AudioBufferPtr New();

        template <typename U>
        static AudioBufferPtr From(const U& u)
        {
            return mojo::TypeConverter<AudioBufferPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, AudioBuffer>::Convert(*this);
        }

        AudioBuffer();
        ~AudioBuffer();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = AudioBufferPtr>
        AudioBufferPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, AudioBuffer>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                AudioBuffer::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                AudioBuffer::DataView, std::vector<uint8_t>>(
                input, output);
        }

        media::SampleFormat sample_format;
        media::ChannelLayout channel_layout;
        int32_t channel_count;
        int32_t sample_rate;
        int32_t frame_count;
        bool end_of_stream;
        base::TimeDelta timestamp;
        std::vector<uint8_t> data;
    };

    class VideoFrame {
    public:
        using DataView = VideoFrameDataView;
        using Data_ = internal::VideoFrame_Data;

        static VideoFramePtr New();

        template <typename U>
        static VideoFramePtr From(const U& u)
        {
            return mojo::TypeConverter<VideoFramePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, VideoFrame>::Convert(*this);
        }

        VideoFrame();
        ~VideoFrame();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = VideoFramePtr>
        VideoFramePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoFrame>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                VideoFrame::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                VideoFrame::DataView, std::vector<uint8_t>>(
                input, output);
        }

        media::VideoPixelFormat format;
        gfx::Size coded_size;
        gfx::Rect visible_rect;
        gfx::Size natural_size;
        bool end_of_stream;
        base::TimeDelta timestamp;
        mojo::ScopedSharedBufferHandle frame_data;
        uint64_t frame_data_size;
        int32_t y_stride;
        int32_t u_stride;
        int32_t v_stride;
        uint64_t y_offset;
        uint64_t u_offset;
        uint64_t v_offset;

    private:
        DISALLOW_COPY_AND_ASSIGN(VideoFrame);
    };

    class PipelineStatistics {
    public:
        using DataView = PipelineStatisticsDataView;
        using Data_ = internal::PipelineStatistics_Data;

        static PipelineStatisticsPtr New();

        template <typename U>
        static PipelineStatisticsPtr From(const U& u)
        {
            return mojo::TypeConverter<PipelineStatisticsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PipelineStatistics>::Convert(*this);
        }

        PipelineStatistics();
        ~PipelineStatistics();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PipelineStatisticsPtr>
        PipelineStatisticsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PipelineStatistics>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PipelineStatistics::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PipelineStatistics::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint64_t audio_bytes_decoded;
        uint64_t video_bytes_decoded;
        uint32_t video_frames_decoded;
        uint32_t video_frames_dropped;
        int64_t audio_memory_usage;
        int64_t video_memory_usage;
    };

    template <typename StructPtrType>
    PatternPtr Pattern::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->encrypt_blocks = mojo::internal::Clone(encrypt_blocks);
        rv->skip_blocks = mojo::internal::Clone(skip_blocks);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Pattern>::value>::type*>
    bool Pattern::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->encrypt_blocks, other.encrypt_blocks))
            return false;
        if (!mojo::internal::Equals(this->skip_blocks, other.skip_blocks))
            return false;
        return true;
    }
    template <typename StructPtrType>
    EncryptionSchemePtr EncryptionScheme::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->mode = mojo::internal::Clone(mode);
        rv->pattern = mojo::internal::Clone(pattern);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, EncryptionScheme>::value>::type*>
    bool EncryptionScheme::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->mode, other.mode))
            return false;
        if (!mojo::internal::Equals(this->pattern, other.pattern))
            return false;
        return true;
    }
    template <typename StructPtrType>
    AudioDecoderConfigPtr AudioDecoderConfig::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->codec = mojo::internal::Clone(codec);
        rv->sample_format = mojo::internal::Clone(sample_format);
        rv->channel_layout = mojo::internal::Clone(channel_layout);
        rv->samples_per_second = mojo::internal::Clone(samples_per_second);
        rv->extra_data = mojo::internal::Clone(extra_data);
        rv->seek_preroll = mojo::internal::Clone(seek_preroll);
        rv->codec_delay = mojo::internal::Clone(codec_delay);
        rv->encryption_scheme = mojo::internal::Clone(encryption_scheme);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, AudioDecoderConfig>::value>::type*>
    bool AudioDecoderConfig::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->codec, other.codec))
            return false;
        if (!mojo::internal::Equals(this->sample_format, other.sample_format))
            return false;
        if (!mojo::internal::Equals(this->channel_layout, other.channel_layout))
            return false;
        if (!mojo::internal::Equals(this->samples_per_second, other.samples_per_second))
            return false;
        if (!mojo::internal::Equals(this->extra_data, other.extra_data))
            return false;
        if (!mojo::internal::Equals(this->seek_preroll, other.seek_preroll))
            return false;
        if (!mojo::internal::Equals(this->codec_delay, other.codec_delay))
            return false;
        if (!mojo::internal::Equals(this->encryption_scheme, other.encryption_scheme))
            return false;
        return true;
    }
    template <typename StructPtrType>
    VideoDecoderConfigPtr VideoDecoderConfig::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->codec = mojo::internal::Clone(codec);
        rv->profile = mojo::internal::Clone(profile);
        rv->format = mojo::internal::Clone(format);
        rv->color_space = mojo::internal::Clone(color_space);
        rv->coded_size = mojo::internal::Clone(coded_size);
        rv->visible_rect = mojo::internal::Clone(visible_rect);
        rv->natural_size = mojo::internal::Clone(natural_size);
        rv->extra_data = mojo::internal::Clone(extra_data);
        rv->encryption_scheme = mojo::internal::Clone(encryption_scheme);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, VideoDecoderConfig>::value>::type*>
    bool VideoDecoderConfig::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->codec, other.codec))
            return false;
        if (!mojo::internal::Equals(this->profile, other.profile))
            return false;
        if (!mojo::internal::Equals(this->format, other.format))
            return false;
        if (!mojo::internal::Equals(this->color_space, other.color_space))
            return false;
        if (!mojo::internal::Equals(this->coded_size, other.coded_size))
            return false;
        if (!mojo::internal::Equals(this->visible_rect, other.visible_rect))
            return false;
        if (!mojo::internal::Equals(this->natural_size, other.natural_size))
            return false;
        if (!mojo::internal::Equals(this->extra_data, other.extra_data))
            return false;
        if (!mojo::internal::Equals(this->encryption_scheme, other.encryption_scheme))
            return false;
        return true;
    }
    template <typename StructPtrType>
    DecryptConfigPtr DecryptConfig::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key_id = mojo::internal::Clone(key_id);
        rv->iv = mojo::internal::Clone(iv);
        rv->subsamples = mojo::internal::Clone(subsamples);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DecryptConfig>::value>::type*>
    bool DecryptConfig::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key_id, other.key_id))
            return false;
        if (!mojo::internal::Equals(this->iv, other.iv))
            return false;
        if (!mojo::internal::Equals(this->subsamples, other.subsamples))
            return false;
        return true;
    }
    template <typename StructPtrType>
    DecoderBufferPtr DecoderBuffer::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->duration = mojo::internal::Clone(duration);
        rv->is_end_of_stream = mojo::internal::Clone(is_end_of_stream);
        rv->data_size = mojo::internal::Clone(data_size);
        rv->is_key_frame = mojo::internal::Clone(is_key_frame);
        rv->side_data = mojo::internal::Clone(side_data);
        rv->decrypt_config = mojo::internal::Clone(decrypt_config);
        rv->front_discard = mojo::internal::Clone(front_discard);
        rv->back_discard = mojo::internal::Clone(back_discard);
        rv->splice_timestamp = mojo::internal::Clone(splice_timestamp);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DecoderBuffer>::value>::type*>
    bool DecoderBuffer::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->duration, other.duration))
            return false;
        if (!mojo::internal::Equals(this->is_end_of_stream, other.is_end_of_stream))
            return false;
        if (!mojo::internal::Equals(this->data_size, other.data_size))
            return false;
        if (!mojo::internal::Equals(this->is_key_frame, other.is_key_frame))
            return false;
        if (!mojo::internal::Equals(this->side_data, other.side_data))
            return false;
        if (!mojo::internal::Equals(this->decrypt_config, other.decrypt_config))
            return false;
        if (!mojo::internal::Equals(this->front_discard, other.front_discard))
            return false;
        if (!mojo::internal::Equals(this->back_discard, other.back_discard))
            return false;
        if (!mojo::internal::Equals(this->splice_timestamp, other.splice_timestamp))
            return false;
        return true;
    }
    template <typename StructPtrType>
    AudioBufferPtr AudioBuffer::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->sample_format = mojo::internal::Clone(sample_format);
        rv->channel_layout = mojo::internal::Clone(channel_layout);
        rv->channel_count = mojo::internal::Clone(channel_count);
        rv->sample_rate = mojo::internal::Clone(sample_rate);
        rv->frame_count = mojo::internal::Clone(frame_count);
        rv->end_of_stream = mojo::internal::Clone(end_of_stream);
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->data = mojo::internal::Clone(data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, AudioBuffer>::value>::type*>
    bool AudioBuffer::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->sample_format, other.sample_format))
            return false;
        if (!mojo::internal::Equals(this->channel_layout, other.channel_layout))
            return false;
        if (!mojo::internal::Equals(this->channel_count, other.channel_count))
            return false;
        if (!mojo::internal::Equals(this->sample_rate, other.sample_rate))
            return false;
        if (!mojo::internal::Equals(this->frame_count, other.frame_count))
            return false;
        if (!mojo::internal::Equals(this->end_of_stream, other.end_of_stream))
            return false;
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        return true;
    }
    template <typename StructPtrType>
    VideoFramePtr VideoFrame::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->format = mojo::internal::Clone(format);
        rv->coded_size = mojo::internal::Clone(coded_size);
        rv->visible_rect = mojo::internal::Clone(visible_rect);
        rv->natural_size = mojo::internal::Clone(natural_size);
        rv->end_of_stream = mojo::internal::Clone(end_of_stream);
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->frame_data = mojo::internal::Clone(frame_data);
        rv->frame_data_size = mojo::internal::Clone(frame_data_size);
        rv->y_stride = mojo::internal::Clone(y_stride);
        rv->u_stride = mojo::internal::Clone(u_stride);
        rv->v_stride = mojo::internal::Clone(v_stride);
        rv->y_offset = mojo::internal::Clone(y_offset);
        rv->u_offset = mojo::internal::Clone(u_offset);
        rv->v_offset = mojo::internal::Clone(v_offset);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, VideoFrame>::value>::type*>
    bool VideoFrame::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->format, other.format))
            return false;
        if (!mojo::internal::Equals(this->coded_size, other.coded_size))
            return false;
        if (!mojo::internal::Equals(this->visible_rect, other.visible_rect))
            return false;
        if (!mojo::internal::Equals(this->natural_size, other.natural_size))
            return false;
        if (!mojo::internal::Equals(this->end_of_stream, other.end_of_stream))
            return false;
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->frame_data, other.frame_data))
            return false;
        if (!mojo::internal::Equals(this->frame_data_size, other.frame_data_size))
            return false;
        if (!mojo::internal::Equals(this->y_stride, other.y_stride))
            return false;
        if (!mojo::internal::Equals(this->u_stride, other.u_stride))
            return false;
        if (!mojo::internal::Equals(this->v_stride, other.v_stride))
            return false;
        if (!mojo::internal::Equals(this->y_offset, other.y_offset))
            return false;
        if (!mojo::internal::Equals(this->u_offset, other.u_offset))
            return false;
        if (!mojo::internal::Equals(this->v_offset, other.v_offset))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PipelineStatisticsPtr PipelineStatistics::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->audio_bytes_decoded = mojo::internal::Clone(audio_bytes_decoded);
        rv->video_bytes_decoded = mojo::internal::Clone(video_bytes_decoded);
        rv->video_frames_decoded = mojo::internal::Clone(video_frames_decoded);
        rv->video_frames_dropped = mojo::internal::Clone(video_frames_dropped);
        rv->audio_memory_usage = mojo::internal::Clone(audio_memory_usage);
        rv->video_memory_usage = mojo::internal::Clone(video_memory_usage);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PipelineStatistics>::value>::type*>
    bool PipelineStatistics::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->audio_bytes_decoded, other.audio_bytes_decoded))
            return false;
        if (!mojo::internal::Equals(this->video_bytes_decoded, other.video_bytes_decoded))
            return false;
        if (!mojo::internal::Equals(this->video_frames_decoded, other.video_frames_decoded))
            return false;
        if (!mojo::internal::Equals(this->video_frames_dropped, other.video_frames_dropped))
            return false;
        if (!mojo::internal::Equals(this->audio_memory_usage, other.audio_memory_usage))
            return false;
        if (!mojo::internal::Equals(this->video_memory_usage, other.video_memory_usage))
            return false;
        return true;
    }

} // namespace mojom
} // namespace media

namespace mojo {

template <>
struct StructTraits<::media::mojom::Pattern::DataView,
    ::media::mojom::PatternPtr> {
    static bool IsNull(const ::media::mojom::PatternPtr& input) { return !input; }
    static void SetToNull(::media::mojom::PatternPtr* output) { output->reset(); }

    static decltype(::media::mojom::Pattern::encrypt_blocks) encrypt_blocks(
        const ::media::mojom::PatternPtr& input)
    {
        return input->encrypt_blocks;
    }

    static decltype(::media::mojom::Pattern::skip_blocks) skip_blocks(
        const ::media::mojom::PatternPtr& input)
    {
        return input->skip_blocks;
    }

    static bool Read(::media::mojom::Pattern::DataView input, ::media::mojom::PatternPtr* output);
};

template <>
struct StructTraits<::media::mojom::EncryptionScheme::DataView,
    ::media::mojom::EncryptionSchemePtr> {
    static bool IsNull(const ::media::mojom::EncryptionSchemePtr& input) { return !input; }
    static void SetToNull(::media::mojom::EncryptionSchemePtr* output) { output->reset(); }

    static decltype(::media::mojom::EncryptionScheme::mode) mode(
        const ::media::mojom::EncryptionSchemePtr& input)
    {
        return input->mode;
    }

    static const decltype(::media::mojom::EncryptionScheme::pattern)& pattern(
        const ::media::mojom::EncryptionSchemePtr& input)
    {
        return input->pattern;
    }

    static bool Read(::media::mojom::EncryptionScheme::DataView input, ::media::mojom::EncryptionSchemePtr* output);
};

template <>
struct StructTraits<::media::mojom::AudioDecoderConfig::DataView,
    ::media::mojom::AudioDecoderConfigPtr> {
    static bool IsNull(const ::media::mojom::AudioDecoderConfigPtr& input) { return !input; }
    static void SetToNull(::media::mojom::AudioDecoderConfigPtr* output) { output->reset(); }

    static decltype(::media::mojom::AudioDecoderConfig::codec) codec(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->codec;
    }

    static decltype(::media::mojom::AudioDecoderConfig::sample_format) sample_format(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->sample_format;
    }

    static decltype(::media::mojom::AudioDecoderConfig::channel_layout) channel_layout(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->channel_layout;
    }

    static decltype(::media::mojom::AudioDecoderConfig::samples_per_second) samples_per_second(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->samples_per_second;
    }

    static const decltype(::media::mojom::AudioDecoderConfig::extra_data)& extra_data(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->extra_data;
    }

    static const decltype(::media::mojom::AudioDecoderConfig::seek_preroll)& seek_preroll(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->seek_preroll;
    }

    static decltype(::media::mojom::AudioDecoderConfig::codec_delay) codec_delay(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->codec_delay;
    }

    static const decltype(::media::mojom::AudioDecoderConfig::encryption_scheme)& encryption_scheme(
        const ::media::mojom::AudioDecoderConfigPtr& input)
    {
        return input->encryption_scheme;
    }

    static bool Read(::media::mojom::AudioDecoderConfig::DataView input, ::media::mojom::AudioDecoderConfigPtr* output);
};

template <>
struct StructTraits<::media::mojom::VideoDecoderConfig::DataView,
    ::media::mojom::VideoDecoderConfigPtr> {
    static bool IsNull(const ::media::mojom::VideoDecoderConfigPtr& input) { return !input; }
    static void SetToNull(::media::mojom::VideoDecoderConfigPtr* output) { output->reset(); }

    static decltype(::media::mojom::VideoDecoderConfig::codec) codec(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->codec;
    }

    static decltype(::media::mojom::VideoDecoderConfig::profile) profile(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->profile;
    }

    static decltype(::media::mojom::VideoDecoderConfig::format) format(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->format;
    }

    static decltype(::media::mojom::VideoDecoderConfig::color_space) color_space(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->color_space;
    }

    static const decltype(::media::mojom::VideoDecoderConfig::coded_size)& coded_size(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->coded_size;
    }

    static const decltype(::media::mojom::VideoDecoderConfig::visible_rect)& visible_rect(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->visible_rect;
    }

    static const decltype(::media::mojom::VideoDecoderConfig::natural_size)& natural_size(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->natural_size;
    }

    static const decltype(::media::mojom::VideoDecoderConfig::extra_data)& extra_data(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->extra_data;
    }

    static const decltype(::media::mojom::VideoDecoderConfig::encryption_scheme)& encryption_scheme(
        const ::media::mojom::VideoDecoderConfigPtr& input)
    {
        return input->encryption_scheme;
    }

    static bool Read(::media::mojom::VideoDecoderConfig::DataView input, ::media::mojom::VideoDecoderConfigPtr* output);
};

template <>
struct StructTraits<::media::mojom::DecryptConfig::DataView,
    ::media::mojom::DecryptConfigPtr> {
    static bool IsNull(const ::media::mojom::DecryptConfigPtr& input) { return !input; }
    static void SetToNull(::media::mojom::DecryptConfigPtr* output) { output->reset(); }

    static const decltype(::media::mojom::DecryptConfig::key_id)& key_id(
        const ::media::mojom::DecryptConfigPtr& input)
    {
        return input->key_id;
    }

    static const decltype(::media::mojom::DecryptConfig::iv)& iv(
        const ::media::mojom::DecryptConfigPtr& input)
    {
        return input->iv;
    }

    static const decltype(::media::mojom::DecryptConfig::subsamples)& subsamples(
        const ::media::mojom::DecryptConfigPtr& input)
    {
        return input->subsamples;
    }

    static bool Read(::media::mojom::DecryptConfig::DataView input, ::media::mojom::DecryptConfigPtr* output);
};

template <>
struct StructTraits<::media::mojom::DecoderBuffer::DataView,
    ::media::mojom::DecoderBufferPtr> {
    static bool IsNull(const ::media::mojom::DecoderBufferPtr& input) { return !input; }
    static void SetToNull(::media::mojom::DecoderBufferPtr* output) { output->reset(); }

    static const decltype(::media::mojom::DecoderBuffer::timestamp)& timestamp(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->timestamp;
    }

    static const decltype(::media::mojom::DecoderBuffer::duration)& duration(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->duration;
    }

    static decltype(::media::mojom::DecoderBuffer::is_end_of_stream) is_end_of_stream(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->is_end_of_stream;
    }

    static decltype(::media::mojom::DecoderBuffer::data_size) data_size(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->data_size;
    }

    static decltype(::media::mojom::DecoderBuffer::is_key_frame) is_key_frame(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->is_key_frame;
    }

    static const decltype(::media::mojom::DecoderBuffer::side_data)& side_data(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->side_data;
    }

    static const decltype(::media::mojom::DecoderBuffer::decrypt_config)& decrypt_config(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->decrypt_config;
    }

    static const decltype(::media::mojom::DecoderBuffer::front_discard)& front_discard(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->front_discard;
    }

    static const decltype(::media::mojom::DecoderBuffer::back_discard)& back_discard(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->back_discard;
    }

    static const decltype(::media::mojom::DecoderBuffer::splice_timestamp)& splice_timestamp(
        const ::media::mojom::DecoderBufferPtr& input)
    {
        return input->splice_timestamp;
    }

    static bool Read(::media::mojom::DecoderBuffer::DataView input, ::media::mojom::DecoderBufferPtr* output);
};

template <>
struct StructTraits<::media::mojom::AudioBuffer::DataView,
    ::media::mojom::AudioBufferPtr> {
    static bool IsNull(const ::media::mojom::AudioBufferPtr& input) { return !input; }
    static void SetToNull(::media::mojom::AudioBufferPtr* output) { output->reset(); }

    static decltype(::media::mojom::AudioBuffer::sample_format) sample_format(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->sample_format;
    }

    static decltype(::media::mojom::AudioBuffer::channel_layout) channel_layout(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->channel_layout;
    }

    static decltype(::media::mojom::AudioBuffer::channel_count) channel_count(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->channel_count;
    }

    static decltype(::media::mojom::AudioBuffer::sample_rate) sample_rate(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->sample_rate;
    }

    static decltype(::media::mojom::AudioBuffer::frame_count) frame_count(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->frame_count;
    }

    static decltype(::media::mojom::AudioBuffer::end_of_stream) end_of_stream(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->end_of_stream;
    }

    static const decltype(::media::mojom::AudioBuffer::timestamp)& timestamp(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->timestamp;
    }

    static const decltype(::media::mojom::AudioBuffer::data)& data(
        const ::media::mojom::AudioBufferPtr& input)
    {
        return input->data;
    }

    static bool Read(::media::mojom::AudioBuffer::DataView input, ::media::mojom::AudioBufferPtr* output);
};

template <>
struct StructTraits<::media::mojom::VideoFrame::DataView,
    ::media::mojom::VideoFramePtr> {
    static bool IsNull(const ::media::mojom::VideoFramePtr& input) { return !input; }
    static void SetToNull(::media::mojom::VideoFramePtr* output) { output->reset(); }

    static decltype(::media::mojom::VideoFrame::format) format(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->format;
    }

    static const decltype(::media::mojom::VideoFrame::coded_size)& coded_size(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->coded_size;
    }

    static const decltype(::media::mojom::VideoFrame::visible_rect)& visible_rect(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->visible_rect;
    }

    static const decltype(::media::mojom::VideoFrame::natural_size)& natural_size(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->natural_size;
    }

    static decltype(::media::mojom::VideoFrame::end_of_stream) end_of_stream(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->end_of_stream;
    }

    static const decltype(::media::mojom::VideoFrame::timestamp)& timestamp(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->timestamp;
    }

    static decltype(::media::mojom::VideoFrame::frame_data)& frame_data(
        ::media::mojom::VideoFramePtr& input)
    {
        return input->frame_data;
    }

    static decltype(::media::mojom::VideoFrame::frame_data_size) frame_data_size(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->frame_data_size;
    }

    static decltype(::media::mojom::VideoFrame::y_stride) y_stride(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->y_stride;
    }

    static decltype(::media::mojom::VideoFrame::u_stride) u_stride(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->u_stride;
    }

    static decltype(::media::mojom::VideoFrame::v_stride) v_stride(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->v_stride;
    }

    static decltype(::media::mojom::VideoFrame::y_offset) y_offset(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->y_offset;
    }

    static decltype(::media::mojom::VideoFrame::u_offset) u_offset(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->u_offset;
    }

    static decltype(::media::mojom::VideoFrame::v_offset) v_offset(
        const ::media::mojom::VideoFramePtr& input)
    {
        return input->v_offset;
    }

    static bool Read(::media::mojom::VideoFrame::DataView input, ::media::mojom::VideoFramePtr* output);
};

template <>
struct StructTraits<::media::mojom::PipelineStatistics::DataView,
    ::media::mojom::PipelineStatisticsPtr> {
    static bool IsNull(const ::media::mojom::PipelineStatisticsPtr& input) { return !input; }
    static void SetToNull(::media::mojom::PipelineStatisticsPtr* output) { output->reset(); }

    static decltype(::media::mojom::PipelineStatistics::audio_bytes_decoded) audio_bytes_decoded(
        const ::media::mojom::PipelineStatisticsPtr& input)
    {
        return input->audio_bytes_decoded;
    }

    static decltype(::media::mojom::PipelineStatistics::video_bytes_decoded) video_bytes_decoded(
        const ::media::mojom::PipelineStatisticsPtr& input)
    {
        return input->video_bytes_decoded;
    }

    static decltype(::media::mojom::PipelineStatistics::video_frames_decoded) video_frames_decoded(
        const ::media::mojom::PipelineStatisticsPtr& input)
    {
        return input->video_frames_decoded;
    }

    static decltype(::media::mojom::PipelineStatistics::video_frames_dropped) video_frames_dropped(
        const ::media::mojom::PipelineStatisticsPtr& input)
    {
        return input->video_frames_dropped;
    }

    static decltype(::media::mojom::PipelineStatistics::audio_memory_usage) audio_memory_usage(
        const ::media::mojom::PipelineStatisticsPtr& input)
    {
        return input->audio_memory_usage;
    }

    static decltype(::media::mojom::PipelineStatistics::video_memory_usage) video_memory_usage(
        const ::media::mojom::PipelineStatisticsPtr& input)
    {
        return input->video_memory_usage;
    }

    static bool Read(::media::mojom::PipelineStatistics::DataView input, ::media::mojom::PipelineStatisticsPtr* output);
};

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_H_