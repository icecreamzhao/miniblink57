// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
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

#pragma pack(push, 1)
        constexpr uint32_t kAudioDecoder_Construct_Name = 0;
        class AudioDecoder_Construct_Params_Data {
        public:
            static AudioDecoder_Construct_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Construct_Params_Data))) AudioDecoder_Construct_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data client;

        private:
            AudioDecoder_Construct_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Construct_Params_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Construct_Params_Data) == 16,
            "Bad sizeof(AudioDecoder_Construct_Params_Data)");
        constexpr uint32_t kAudioDecoder_Initialize_Name = 1;
        class AudioDecoder_Initialize_Params_Data {
        public:
            static AudioDecoder_Initialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Initialize_Params_Data))) AudioDecoder_Initialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::AudioDecoderConfig_Data> config;
            int32_t cdm_id;
            uint8_t padfinal_[4];

        private:
            AudioDecoder_Initialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Initialize_Params_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Initialize_Params_Data) == 24,
            "Bad sizeof(AudioDecoder_Initialize_Params_Data)");
        class AudioDecoder_Initialize_ResponseParams_Data {
        public:
            static AudioDecoder_Initialize_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Initialize_ResponseParams_Data))) AudioDecoder_Initialize_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t needs_bitstream_conversion : 1;
            uint8_t padfinal_[7];

        private:
            AudioDecoder_Initialize_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Initialize_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Initialize_ResponseParams_Data) == 16,
            "Bad sizeof(AudioDecoder_Initialize_ResponseParams_Data)");
        constexpr uint32_t kAudioDecoder_SetDataSource_Name = 2;
        class AudioDecoder_SetDataSource_Params_Data {
        public:
            static AudioDecoder_SetDataSource_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_SetDataSource_Params_Data))) AudioDecoder_SetDataSource_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data receive_pipe;
            uint8_t padfinal_[4];

        private:
            AudioDecoder_SetDataSource_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_SetDataSource_Params_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_SetDataSource_Params_Data) == 16,
            "Bad sizeof(AudioDecoder_SetDataSource_Params_Data)");
        constexpr uint32_t kAudioDecoder_Decode_Name = 3;
        class AudioDecoder_Decode_Params_Data {
        public:
            static AudioDecoder_Decode_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Decode_Params_Data))) AudioDecoder_Decode_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> buffer;

        private:
            AudioDecoder_Decode_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Decode_Params_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Decode_Params_Data) == 16,
            "Bad sizeof(AudioDecoder_Decode_Params_Data)");
        class AudioDecoder_Decode_ResponseParams_Data {
        public:
            static AudioDecoder_Decode_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Decode_ResponseParams_Data))) AudioDecoder_Decode_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            AudioDecoder_Decode_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Decode_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Decode_ResponseParams_Data) == 16,
            "Bad sizeof(AudioDecoder_Decode_ResponseParams_Data)");
        constexpr uint32_t kAudioDecoder_Reset_Name = 4;
        class AudioDecoder_Reset_Params_Data {
        public:
            static AudioDecoder_Reset_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Reset_Params_Data))) AudioDecoder_Reset_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AudioDecoder_Reset_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Reset_Params_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Reset_Params_Data) == 8,
            "Bad sizeof(AudioDecoder_Reset_Params_Data)");
        class AudioDecoder_Reset_ResponseParams_Data {
        public:
            static AudioDecoder_Reset_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoder_Reset_ResponseParams_Data))) AudioDecoder_Reset_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AudioDecoder_Reset_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoder_Reset_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(AudioDecoder_Reset_ResponseParams_Data) == 8,
            "Bad sizeof(AudioDecoder_Reset_ResponseParams_Data)");
        constexpr uint32_t kAudioDecoderClient_OnBufferDecoded_Name = 0;
        class AudioDecoderClient_OnBufferDecoded_Params_Data {
        public:
            static AudioDecoderClient_OnBufferDecoded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioDecoderClient_OnBufferDecoded_Params_Data))) AudioDecoderClient_OnBufferDecoded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::AudioBuffer_Data> buffer;

        private:
            AudioDecoderClient_OnBufferDecoded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioDecoderClient_OnBufferDecoded_Params_Data() = delete;
        };
        static_assert(sizeof(AudioDecoderClient_OnBufferDecoded_Params_Data) == 16,
            "Bad sizeof(AudioDecoderClient_OnBufferDecoded_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_SHARED_INTERNAL_H_