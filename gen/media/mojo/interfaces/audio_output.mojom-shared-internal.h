// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/audio_parameters.mojom-shared-internal.h"
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
        constexpr uint32_t kAudioOutputStream_Close_Name = 0;
        class AudioOutputStream_Close_Params_Data {
        public:
            static AudioOutputStream_Close_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioOutputStream_Close_Params_Data))) AudioOutputStream_Close_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AudioOutputStream_Close_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioOutputStream_Close_Params_Data() = delete;
        };
        static_assert(sizeof(AudioOutputStream_Close_Params_Data) == 8,
            "Bad sizeof(AudioOutputStream_Close_Params_Data)");
        constexpr uint32_t kAudioOutput_CreateStream_Name = 0;
        class AudioOutput_CreateStream_Params_Data {
        public:
            static AudioOutput_CreateStream_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioOutput_CreateStream_Params_Data))) AudioOutput_CreateStream_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t stream_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::media::mojom::internal::AudioParameters_Data> params;

        private:
            AudioOutput_CreateStream_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioOutput_CreateStream_Params_Data() = delete;
        };
        static_assert(sizeof(AudioOutput_CreateStream_Params_Data) == 24,
            "Bad sizeof(AudioOutput_CreateStream_Params_Data)");
        class AudioOutput_CreateStream_ResponseParams_Data {
        public:
            static AudioOutput_CreateStream_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AudioOutput_CreateStream_ResponseParams_Data))) AudioOutput_CreateStream_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t stream_id;
            mojo::internal::Interface_Data stream;
            mojo::internal::Handle_Data shared_buffer;
            mojo::internal::Handle_Data socket_descriptor;
            uint8_t padfinal_[4];

        private:
            AudioOutput_CreateStream_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AudioOutput_CreateStream_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(AudioOutput_CreateStream_ResponseParams_Data) == 32,
            "Bad sizeof(AudioOutput_CreateStream_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_SHARED_INTERNAL_H_