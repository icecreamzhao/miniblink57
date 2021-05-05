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

#include "media/mojo/interfaces/media_types.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
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
    PatternPtr Pattern::New()
    {
        PatternPtr rv;
        mojo::internal::StructHelper<Pattern>::Initialize(&rv);
        return rv;
    }

    Pattern::Pattern()
        : encrypt_blocks()
        , skip_blocks()
    {
    }

    Pattern::~Pattern()
    {
    }
    size_t Pattern::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->encrypt_blocks);
        seed = mojo::internal::Hash(seed, this->skip_blocks);
        return seed;
    } // static
    EncryptionSchemePtr EncryptionScheme::New()
    {
        EncryptionSchemePtr rv;
        mojo::internal::StructHelper<EncryptionScheme>::Initialize(&rv);
        return rv;
    }

    EncryptionScheme::EncryptionScheme()
        : mode()
        , pattern()
    {
    }

    EncryptionScheme::~EncryptionScheme()
    {
    } // static
    AudioDecoderConfigPtr AudioDecoderConfig::New()
    {
        AudioDecoderConfigPtr rv;
        mojo::internal::StructHelper<AudioDecoderConfig>::Initialize(&rv);
        return rv;
    }

    AudioDecoderConfig::AudioDecoderConfig()
        : codec()
        , sample_format()
        , channel_layout()
        , samples_per_second()
        , extra_data()
        , seek_preroll()
        , codec_delay()
        , encryption_scheme()
    {
    }

    AudioDecoderConfig::~AudioDecoderConfig()
    {
    } // static
    VideoDecoderConfigPtr VideoDecoderConfig::New()
    {
        VideoDecoderConfigPtr rv;
        mojo::internal::StructHelper<VideoDecoderConfig>::Initialize(&rv);
        return rv;
    }

    VideoDecoderConfig::VideoDecoderConfig()
        : codec()
        , profile()
        , format()
        , color_space()
        , coded_size()
        , visible_rect()
        , natural_size()
        , extra_data()
        , encryption_scheme()
    {
    }

    VideoDecoderConfig::~VideoDecoderConfig()
    {
    } // static
    DecryptConfigPtr DecryptConfig::New()
    {
        DecryptConfigPtr rv;
        mojo::internal::StructHelper<DecryptConfig>::Initialize(&rv);
        return rv;
    }

    DecryptConfig::DecryptConfig()
        : key_id()
        , iv()
        , subsamples()
    {
    }

    DecryptConfig::~DecryptConfig()
    {
    } // static
    DecoderBufferPtr DecoderBuffer::New()
    {
        DecoderBufferPtr rv;
        mojo::internal::StructHelper<DecoderBuffer>::Initialize(&rv);
        return rv;
    }

    DecoderBuffer::DecoderBuffer()
        : timestamp()
        , duration()
        , is_end_of_stream()
        , data_size()
        , is_key_frame()
        , side_data()
        , decrypt_config()
        , front_discard()
        , back_discard()
        , splice_timestamp()
    {
    }

    DecoderBuffer::~DecoderBuffer()
    {
    } // static
    AudioBufferPtr AudioBuffer::New()
    {
        AudioBufferPtr rv;
        mojo::internal::StructHelper<AudioBuffer>::Initialize(&rv);
        return rv;
    }

    AudioBuffer::AudioBuffer()
        : sample_format()
        , channel_layout()
        , channel_count()
        , sample_rate()
        , frame_count()
        , end_of_stream()
        , timestamp()
        , data()
    {
    }

    AudioBuffer::~AudioBuffer()
    {
    } // static
    VideoFramePtr VideoFrame::New()
    {
        VideoFramePtr rv;
        mojo::internal::StructHelper<VideoFrame>::Initialize(&rv);
        return rv;
    }

    VideoFrame::VideoFrame()
        : format()
        , coded_size()
        , visible_rect()
        , natural_size()
        , end_of_stream()
        , timestamp()
        , frame_data()
        , frame_data_size()
        , y_stride()
        , u_stride()
        , v_stride()
        , y_offset()
        , u_offset()
        , v_offset()
    {
    }

    VideoFrame::~VideoFrame()
    {
    } // static
    PipelineStatisticsPtr PipelineStatistics::New()
    {
        PipelineStatisticsPtr rv;
        mojo::internal::StructHelper<PipelineStatistics>::Initialize(&rv);
        return rv;
    }

    PipelineStatistics::PipelineStatistics()
        : audio_bytes_decoded()
        , video_bytes_decoded()
        , video_frames_decoded()
        , video_frames_dropped()
        , audio_memory_usage()
        , video_memory_usage()
    {
    }

    PipelineStatistics::~PipelineStatistics()
    {
    }
} // namespace mojom
} // namespace media

namespace mojo {

// static
bool StructTraits<::media::mojom::Pattern::DataView, ::media::mojom::PatternPtr>::Read(
    ::media::mojom::Pattern::DataView input,
    ::media::mojom::PatternPtr* output)
{
    bool success = true;
    ::media::mojom::PatternPtr result(::media::mojom::Pattern::New());

    result->encrypt_blocks = input.encrypt_blocks();
    result->skip_blocks = input.skip_blocks();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::EncryptionScheme::DataView, ::media::mojom::EncryptionSchemePtr>::Read(
    ::media::mojom::EncryptionScheme::DataView input,
    ::media::mojom::EncryptionSchemePtr* output)
{
    bool success = true;
    ::media::mojom::EncryptionSchemePtr result(::media::mojom::EncryptionScheme::New());

    if (!input.ReadMode(&result->mode))
        success = false;
    if (!input.ReadPattern(&result->pattern))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::AudioDecoderConfig::DataView, ::media::mojom::AudioDecoderConfigPtr>::Read(
    ::media::mojom::AudioDecoderConfig::DataView input,
    ::media::mojom::AudioDecoderConfigPtr* output)
{
    bool success = true;
    ::media::mojom::AudioDecoderConfigPtr result(::media::mojom::AudioDecoderConfig::New());

    if (!input.ReadCodec(&result->codec))
        success = false;
    if (!input.ReadSampleFormat(&result->sample_format))
        success = false;
    if (!input.ReadChannelLayout(&result->channel_layout))
        success = false;
    result->samples_per_second = input.samples_per_second();
    if (!input.ReadExtraData(&result->extra_data))
        success = false;
    if (!input.ReadSeekPreroll(&result->seek_preroll))
        success = false;
    result->codec_delay = input.codec_delay();
    if (!input.ReadEncryptionScheme(&result->encryption_scheme))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::VideoDecoderConfig::DataView, ::media::mojom::VideoDecoderConfigPtr>::Read(
    ::media::mojom::VideoDecoderConfig::DataView input,
    ::media::mojom::VideoDecoderConfigPtr* output)
{
    bool success = true;
    ::media::mojom::VideoDecoderConfigPtr result(::media::mojom::VideoDecoderConfig::New());

    if (!input.ReadCodec(&result->codec))
        success = false;
    if (!input.ReadProfile(&result->profile))
        success = false;
    if (!input.ReadFormat(&result->format))
        success = false;
    if (!input.ReadColorSpace(&result->color_space))
        success = false;
    if (!input.ReadCodedSize(&result->coded_size))
        success = false;
    if (!input.ReadVisibleRect(&result->visible_rect))
        success = false;
    if (!input.ReadNaturalSize(&result->natural_size))
        success = false;
    if (!input.ReadExtraData(&result->extra_data))
        success = false;
    if (!input.ReadEncryptionScheme(&result->encryption_scheme))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::DecryptConfig::DataView, ::media::mojom::DecryptConfigPtr>::Read(
    ::media::mojom::DecryptConfig::DataView input,
    ::media::mojom::DecryptConfigPtr* output)
{
    bool success = true;
    ::media::mojom::DecryptConfigPtr result(::media::mojom::DecryptConfig::New());

    if (!input.ReadKeyId(&result->key_id))
        success = false;
    if (!input.ReadIv(&result->iv))
        success = false;
    if (!input.ReadSubsamples(&result->subsamples))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::DecoderBuffer::DataView, ::media::mojom::DecoderBufferPtr>::Read(
    ::media::mojom::DecoderBuffer::DataView input,
    ::media::mojom::DecoderBufferPtr* output)
{
    bool success = true;
    ::media::mojom::DecoderBufferPtr result(::media::mojom::DecoderBuffer::New());

    if (!input.ReadTimestamp(&result->timestamp))
        success = false;
    if (!input.ReadDuration(&result->duration))
        success = false;
    result->is_end_of_stream = input.is_end_of_stream();
    result->data_size = input.data_size();
    result->is_key_frame = input.is_key_frame();
    if (!input.ReadSideData(&result->side_data))
        success = false;
    if (!input.ReadDecryptConfig(&result->decrypt_config))
        success = false;
    if (!input.ReadFrontDiscard(&result->front_discard))
        success = false;
    if (!input.ReadBackDiscard(&result->back_discard))
        success = false;
    if (!input.ReadSpliceTimestamp(&result->splice_timestamp))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::AudioBuffer::DataView, ::media::mojom::AudioBufferPtr>::Read(
    ::media::mojom::AudioBuffer::DataView input,
    ::media::mojom::AudioBufferPtr* output)
{
    bool success = true;
    ::media::mojom::AudioBufferPtr result(::media::mojom::AudioBuffer::New());

    if (!input.ReadSampleFormat(&result->sample_format))
        success = false;
    if (!input.ReadChannelLayout(&result->channel_layout))
        success = false;
    result->channel_count = input.channel_count();
    result->sample_rate = input.sample_rate();
    result->frame_count = input.frame_count();
    result->end_of_stream = input.end_of_stream();
    if (!input.ReadTimestamp(&result->timestamp))
        success = false;
    if (!input.ReadData(&result->data))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::VideoFrame::DataView, ::media::mojom::VideoFramePtr>::Read(
    ::media::mojom::VideoFrame::DataView input,
    ::media::mojom::VideoFramePtr* output)
{
    bool success = true;
    ::media::mojom::VideoFramePtr result(::media::mojom::VideoFrame::New());

    if (!input.ReadFormat(&result->format))
        success = false;
    if (!input.ReadCodedSize(&result->coded_size))
        success = false;
    if (!input.ReadVisibleRect(&result->visible_rect))
        success = false;
    if (!input.ReadNaturalSize(&result->natural_size))
        success = false;
    result->end_of_stream = input.end_of_stream();
    if (!input.ReadTimestamp(&result->timestamp))
        success = false;
    result->frame_data = input.TakeFrameData();
    result->frame_data_size = input.frame_data_size();
    result->y_stride = input.y_stride();
    result->u_stride = input.u_stride();
    result->v_stride = input.v_stride();
    result->y_offset = input.y_offset();
    result->u_offset = input.u_offset();
    result->v_offset = input.v_offset();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::PipelineStatistics::DataView, ::media::mojom::PipelineStatisticsPtr>::Read(
    ::media::mojom::PipelineStatistics::DataView input,
    ::media::mojom::PipelineStatisticsPtr* output)
{
    bool success = true;
    ::media::mojom::PipelineStatisticsPtr result(::media::mojom::PipelineStatistics::New());

    result->audio_bytes_decoded = input.audio_bytes_decoded();
    result->video_bytes_decoded = input.video_bytes_decoded();
    result->video_frames_decoded = input.video_frames_decoded();
    result->video_frames_dropped = input.video_frames_dropped();
    result->audio_memory_usage = input.audio_memory_usage();
    result->video_memory_usage = input.video_memory_usage();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif