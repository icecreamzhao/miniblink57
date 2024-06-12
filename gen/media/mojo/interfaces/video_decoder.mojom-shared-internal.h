// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
#include "mojo/common/unguessable_token.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace media {
namespace mojom {
    namespace internal {
        class CommandBufferId_Data;

#pragma pack(push, 1)
        class CommandBufferId_Data {
        public:
            static CommandBufferId_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CommandBufferId_Data))) CommandBufferId_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> channel_token;
            int32_t route_id;
            uint8_t padfinal_[4];

        private:
            CommandBufferId_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CommandBufferId_Data() = delete;
        };
        static_assert(sizeof(CommandBufferId_Data) == 24,
            "Bad sizeof(CommandBufferId_Data)");
        constexpr uint32_t kVideoDecoder_Construct_Name = 0;
        class VideoDecoder_Construct_Params_Data {
        public:
            static VideoDecoder_Construct_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Construct_Params_Data))) VideoDecoder_Construct_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data client;
            mojo::internal::Handle_Data decoder_buffer_pipe;
            uint8_t pad1_[4];
            mojo::internal::Pointer<internal::CommandBufferId_Data> command_buffer_id;

        private:
            VideoDecoder_Construct_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Construct_Params_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Construct_Params_Data) == 32,
            "Bad sizeof(VideoDecoder_Construct_Params_Data)");
        constexpr uint32_t kVideoDecoder_Initialize_Name = 1;
        class VideoDecoder_Initialize_Params_Data {
        public:
            static VideoDecoder_Initialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Initialize_Params_Data))) VideoDecoder_Initialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::VideoDecoderConfig_Data> config;
            uint8_t low_delay : 1;
            uint8_t padfinal_[7];

        private:
            VideoDecoder_Initialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Initialize_Params_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Initialize_Params_Data) == 24,
            "Bad sizeof(VideoDecoder_Initialize_Params_Data)");
        class VideoDecoder_Initialize_ResponseParams_Data {
        public:
            static VideoDecoder_Initialize_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Initialize_ResponseParams_Data))) VideoDecoder_Initialize_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t needs_bitstream_conversion : 1;
            uint8_t pad1_[3];
            int32_t max_decode_requests;

        private:
            VideoDecoder_Initialize_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Initialize_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Initialize_ResponseParams_Data) == 16,
            "Bad sizeof(VideoDecoder_Initialize_ResponseParams_Data)");
        constexpr uint32_t kVideoDecoder_Decode_Name = 2;
        class VideoDecoder_Decode_Params_Data {
        public:
            static VideoDecoder_Decode_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Decode_Params_Data))) VideoDecoder_Decode_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> buffer;

        private:
            VideoDecoder_Decode_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Decode_Params_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Decode_Params_Data) == 16,
            "Bad sizeof(VideoDecoder_Decode_Params_Data)");
        class VideoDecoder_Decode_ResponseParams_Data {
        public:
            static VideoDecoder_Decode_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Decode_ResponseParams_Data))) VideoDecoder_Decode_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            VideoDecoder_Decode_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Decode_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Decode_ResponseParams_Data) == 16,
            "Bad sizeof(VideoDecoder_Decode_ResponseParams_Data)");
        constexpr uint32_t kVideoDecoder_Reset_Name = 3;
        class VideoDecoder_Reset_Params_Data {
        public:
            static VideoDecoder_Reset_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Reset_Params_Data))) VideoDecoder_Reset_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VideoDecoder_Reset_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Reset_Params_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Reset_Params_Data) == 8,
            "Bad sizeof(VideoDecoder_Reset_Params_Data)");
        class VideoDecoder_Reset_ResponseParams_Data {
        public:
            static VideoDecoder_Reset_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoder_Reset_ResponseParams_Data))) VideoDecoder_Reset_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VideoDecoder_Reset_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoder_Reset_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VideoDecoder_Reset_ResponseParams_Data) == 8,
            "Bad sizeof(VideoDecoder_Reset_ResponseParams_Data)");
        constexpr uint32_t kVideoDecoderClient_OnVideoFrameDecoded_Name = 0;
        class VideoDecoderClient_OnVideoFrameDecoded_Params_Data {
        public:
            static VideoDecoderClient_OnVideoFrameDecoded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoDecoderClient_OnVideoFrameDecoded_Params_Data))) VideoDecoderClient_OnVideoFrameDecoded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::VideoFrame_Data> frame;

        private:
            VideoDecoderClient_OnVideoFrameDecoded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoDecoderClient_OnVideoFrameDecoded_Params_Data() = delete;
        };
        static_assert(sizeof(VideoDecoderClient_OnVideoFrameDecoded_Params_Data) == 16,
            "Bad sizeof(VideoDecoderClient_OnVideoFrameDecoded_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_SHARED_INTERNAL_H_