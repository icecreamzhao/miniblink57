// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace media {
namespace mojom {
    namespace internal {
        class Pattern_Data;
        class EncryptionScheme_Data;
        class AudioDecoderConfig_Data;
        class VideoDecoderConfig_Data;
        using SubsampleEntry_Data = mojo::internal::NativeStruct_Data;
        class DecryptConfig_Data;
        class DecoderBuffer_Data;
        class AudioBuffer_Data;
        class VideoFrame_Data;
        class PipelineStatistics_Data;
        using BufferingState_Data = mojo::internal::NativeEnum_Data;
        using DecodeStatus_Data = mojo::internal::NativeEnum_Data;
        using AudioCodec_Data = mojo::internal::NativeEnum_Data;
        using ChannelLayout_Data = mojo::internal::NativeEnum_Data;
        using SampleFormat_Data = mojo::internal::NativeEnum_Data;
        using VideoPixelFormat_Data = mojo::internal::NativeEnum_Data;
        using ColorSpace_Data = mojo::internal::NativeEnum_Data;
        using VideoCodec_Data = mojo::internal::NativeEnum_Data;
        using VideoCodecProfile_Data = mojo::internal::NativeEnum_Data;
        using EncryptionScheme_CipherMode_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)
        class Pattern_Data {
        public:
            static Pattern_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Pattern_Data))) Pattern_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t encrypt_blocks;
            uint32_t skip_blocks;

        private:
            Pattern_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Pattern_Data() = delete;
        };
        static_assert(sizeof(Pattern_Data) == 16,
            "Bad sizeof(Pattern_Data)");
        class EncryptionScheme_Data {
        public:
            static EncryptionScheme_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EncryptionScheme_Data))) EncryptionScheme_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t mode;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::Pattern_Data> pattern;

        private:
            EncryptionScheme_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EncryptionScheme_Data() = delete;
        };
        static_assert(sizeof(EncryptionScheme_Data) == 24,
            "Bad sizeof(EncryptionScheme_Data)");
        class AudioDecoderConfig_Data {
        public:
            static AudioDecoderConfig_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoderConfig_Data))) AudioDecoderConfig_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t codec;
            int32_t sample_format;
            int32_t channel_layout;
            int32_t samples_per_second;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> extra_data;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> seek_preroll;
            int32_t codec_delay;
            uint8_t pad6_[4];
            mojo::internal::Pointer<internal::EncryptionScheme_Data> encryption_scheme;

        private:
            AudioDecoderConfig_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoderConfig_Data() = delete;
        };
        static_assert(sizeof(AudioDecoderConfig_Data) == 56,
            "Bad sizeof(AudioDecoderConfig_Data)");
        class VideoDecoderConfig_Data {
        public:
            static VideoDecoderConfig_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoderConfig_Data))) VideoDecoderConfig_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t codec;
            int32_t profile;
            int32_t format;
            int32_t color_space;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> coded_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> visible_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> natural_size;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> extra_data;
            mojo::internal::Pointer<internal::EncryptionScheme_Data> encryption_scheme;

        private:
            VideoDecoderConfig_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoderConfig_Data() = delete;
        };
        static_assert(sizeof(VideoDecoderConfig_Data) == 64,
            "Bad sizeof(VideoDecoderConfig_Data)");
        class DecryptConfig_Data {
        public:
            static DecryptConfig_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DecryptConfig_Data))) DecryptConfig_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> key_id;
            mojo::internal::Pointer<mojo::internal::String_Data> iv;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::SubsampleEntry_Data>>> subsamples;

        private:
            DecryptConfig_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DecryptConfig_Data() = delete;
        };
        static_assert(sizeof(DecryptConfig_Data) == 32,
            "Bad sizeof(DecryptConfig_Data)");
        class DecoderBuffer_Data {
        public:
            static DecoderBuffer_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DecoderBuffer_Data))) DecoderBuffer_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> timestamp;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> duration;
            uint8_t is_end_of_stream : 1;
            uint8_t is_key_frame : 1;
            uint8_t pad3_[3];
            uint32_t data_size;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> side_data;
            mojo::internal::Pointer<internal::DecryptConfig_Data> decrypt_config;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> front_discard;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> back_discard;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> splice_timestamp;

        private:
            DecoderBuffer_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DecoderBuffer_Data() = delete;
        };
        static_assert(sizeof(DecoderBuffer_Data) == 72,
            "Bad sizeof(DecoderBuffer_Data)");
        class AudioBuffer_Data {
        public:
            static AudioBuffer_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioBuffer_Data))) AudioBuffer_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t sample_format;
            int32_t channel_layout;
            int32_t channel_count;
            int32_t sample_rate;
            int32_t frame_count;
            uint8_t end_of_stream : 1;
            uint8_t pad5_[3];
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> timestamp;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            AudioBuffer_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioBuffer_Data() = delete;
        };
        static_assert(sizeof(AudioBuffer_Data) == 48,
            "Bad sizeof(AudioBuffer_Data)");
        class VideoFrame_Data {
        public:
            static VideoFrame_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoFrame_Data))) VideoFrame_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t format;
            uint8_t end_of_stream : 1;
            uint8_t pad1_[3];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> coded_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> visible_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> natural_size;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> timestamp;
            mojo::internal::Handle_Data frame_data;
            int32_t y_stride;
            uint64_t frame_data_size;
            int32_t u_stride;
            int32_t v_stride;
            uint64_t y_offset;
            uint64_t u_offset;
            uint64_t v_offset;

        private:
            VideoFrame_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoFrame_Data() = delete;
        };
        static_assert(sizeof(VideoFrame_Data) == 96,
            "Bad sizeof(VideoFrame_Data)");
        class PipelineStatistics_Data {
        public:
            static PipelineStatistics_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PipelineStatistics_Data))) PipelineStatistics_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint64_t audio_bytes_decoded;
            uint64_t video_bytes_decoded;
            uint32_t video_frames_decoded;
            uint32_t video_frames_dropped;
            int64_t audio_memory_usage;
            int64_t video_memory_usage;

        private:
            PipelineStatistics_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PipelineStatistics_Data() = delete;
        };
        static_assert(sizeof(PipelineStatistics_Data) == 48,
            "Bad sizeof(PipelineStatistics_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_MEDIA_TYPES_MOJOM_SHARED_INTERNAL_H_