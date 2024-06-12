// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_SHARED_INTERNAL_H_

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
        using Decryptor_Status_Data = mojo::internal::NativeEnum_Data;
        using Decryptor_StreamType_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)
        constexpr uint32_t kDecryptor_Initialize_Name = 0;
        class Decryptor_Initialize_Params_Data {
        public:
            static Decryptor_Initialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_Initialize_Params_Data))) Decryptor_Initialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data receive_pipe;
            mojo::internal::Handle_Data transmit_pipe;

        private:
            Decryptor_Initialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_Initialize_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_Initialize_Params_Data) == 16,
            "Bad sizeof(Decryptor_Initialize_Params_Data)");
        constexpr uint32_t kDecryptor_Decrypt_Name = 1;
        class Decryptor_Decrypt_Params_Data {
        public:
            static Decryptor_Decrypt_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_Decrypt_Params_Data))) Decryptor_Decrypt_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t stream_type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> encrypted;

        private:
            Decryptor_Decrypt_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_Decrypt_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_Decrypt_Params_Data) == 24,
            "Bad sizeof(Decryptor_Decrypt_Params_Data)");
        class Decryptor_Decrypt_ResponseParams_Data {
        public:
            static Decryptor_Decrypt_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_Decrypt_ResponseParams_Data))) Decryptor_Decrypt_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> buffer;

        private:
            Decryptor_Decrypt_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_Decrypt_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Decryptor_Decrypt_ResponseParams_Data) == 24,
            "Bad sizeof(Decryptor_Decrypt_ResponseParams_Data)");
        constexpr uint32_t kDecryptor_CancelDecrypt_Name = 2;
        class Decryptor_CancelDecrypt_Params_Data {
        public:
            static Decryptor_CancelDecrypt_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_CancelDecrypt_Params_Data))) Decryptor_CancelDecrypt_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t stream_type;
            uint8_t padfinal_[4];

        private:
            Decryptor_CancelDecrypt_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_CancelDecrypt_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_CancelDecrypt_Params_Data) == 16,
            "Bad sizeof(Decryptor_CancelDecrypt_Params_Data)");
        constexpr uint32_t kDecryptor_InitializeAudioDecoder_Name = 3;
        class Decryptor_InitializeAudioDecoder_Params_Data {
        public:
            static Decryptor_InitializeAudioDecoder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_InitializeAudioDecoder_Params_Data))) Decryptor_InitializeAudioDecoder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::AudioDecoderConfig_Data> config;

        private:
            Decryptor_InitializeAudioDecoder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_InitializeAudioDecoder_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_InitializeAudioDecoder_Params_Data) == 16,
            "Bad sizeof(Decryptor_InitializeAudioDecoder_Params_Data)");
        class Decryptor_InitializeAudioDecoder_ResponseParams_Data {
        public:
            static Decryptor_InitializeAudioDecoder_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_InitializeAudioDecoder_ResponseParams_Data))) Decryptor_InitializeAudioDecoder_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Decryptor_InitializeAudioDecoder_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_InitializeAudioDecoder_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Decryptor_InitializeAudioDecoder_ResponseParams_Data) == 16,
            "Bad sizeof(Decryptor_InitializeAudioDecoder_ResponseParams_Data)");
        constexpr uint32_t kDecryptor_InitializeVideoDecoder_Name = 4;
        class Decryptor_InitializeVideoDecoder_Params_Data {
        public:
            static Decryptor_InitializeVideoDecoder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_InitializeVideoDecoder_Params_Data))) Decryptor_InitializeVideoDecoder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::VideoDecoderConfig_Data> config;

        private:
            Decryptor_InitializeVideoDecoder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_InitializeVideoDecoder_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_InitializeVideoDecoder_Params_Data) == 16,
            "Bad sizeof(Decryptor_InitializeVideoDecoder_Params_Data)");
        class Decryptor_InitializeVideoDecoder_ResponseParams_Data {
        public:
            static Decryptor_InitializeVideoDecoder_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_InitializeVideoDecoder_ResponseParams_Data))) Decryptor_InitializeVideoDecoder_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Decryptor_InitializeVideoDecoder_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_InitializeVideoDecoder_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Decryptor_InitializeVideoDecoder_ResponseParams_Data) == 16,
            "Bad sizeof(Decryptor_InitializeVideoDecoder_ResponseParams_Data)");
        constexpr uint32_t kDecryptor_DecryptAndDecodeAudio_Name = 5;
        class Decryptor_DecryptAndDecodeAudio_Params_Data {
        public:
            static Decryptor_DecryptAndDecodeAudio_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_DecryptAndDecodeAudio_Params_Data))) Decryptor_DecryptAndDecodeAudio_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> encrypted;

        private:
            Decryptor_DecryptAndDecodeAudio_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_DecryptAndDecodeAudio_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_DecryptAndDecodeAudio_Params_Data) == 16,
            "Bad sizeof(Decryptor_DecryptAndDecodeAudio_Params_Data)");
        class Decryptor_DecryptAndDecodeAudio_ResponseParams_Data {
        public:
            static Decryptor_DecryptAndDecodeAudio_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_DecryptAndDecodeAudio_ResponseParams_Data))) Decryptor_DecryptAndDecodeAudio_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::media::mojom::internal::AudioBuffer_Data>>> audio_buffers;

        private:
            Decryptor_DecryptAndDecodeAudio_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_DecryptAndDecodeAudio_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Decryptor_DecryptAndDecodeAudio_ResponseParams_Data) == 24,
            "Bad sizeof(Decryptor_DecryptAndDecodeAudio_ResponseParams_Data)");
        constexpr uint32_t kDecryptor_DecryptAndDecodeVideo_Name = 6;
        class Decryptor_DecryptAndDecodeVideo_Params_Data {
        public:
            static Decryptor_DecryptAndDecodeVideo_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_DecryptAndDecodeVideo_Params_Data))) Decryptor_DecryptAndDecodeVideo_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> encrypted;

        private:
            Decryptor_DecryptAndDecodeVideo_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_DecryptAndDecodeVideo_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_DecryptAndDecodeVideo_Params_Data) == 16,
            "Bad sizeof(Decryptor_DecryptAndDecodeVideo_Params_Data)");
        class Decryptor_DecryptAndDecodeVideo_ResponseParams_Data {
        public:
            static Decryptor_DecryptAndDecodeVideo_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_DecryptAndDecodeVideo_ResponseParams_Data))) Decryptor_DecryptAndDecodeVideo_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::media::mojom::internal::VideoFrame_Data> video_frame;

        private:
            Decryptor_DecryptAndDecodeVideo_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_DecryptAndDecodeVideo_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Decryptor_DecryptAndDecodeVideo_ResponseParams_Data) == 24,
            "Bad sizeof(Decryptor_DecryptAndDecodeVideo_ResponseParams_Data)");
        constexpr uint32_t kDecryptor_ResetDecoder_Name = 7;
        class Decryptor_ResetDecoder_Params_Data {
        public:
            static Decryptor_ResetDecoder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_ResetDecoder_Params_Data))) Decryptor_ResetDecoder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t stream_type;
            uint8_t padfinal_[4];

        private:
            Decryptor_ResetDecoder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_ResetDecoder_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_ResetDecoder_Params_Data) == 16,
            "Bad sizeof(Decryptor_ResetDecoder_Params_Data)");
        constexpr uint32_t kDecryptor_DeinitializeDecoder_Name = 8;
        class Decryptor_DeinitializeDecoder_Params_Data {
        public:
            static Decryptor_DeinitializeDecoder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_DeinitializeDecoder_Params_Data))) Decryptor_DeinitializeDecoder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t stream_type;
            uint8_t padfinal_[4];

        private:
            Decryptor_DeinitializeDecoder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_DeinitializeDecoder_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_DeinitializeDecoder_Params_Data) == 16,
            "Bad sizeof(Decryptor_DeinitializeDecoder_Params_Data)");
        constexpr uint32_t kDecryptor_ReleaseSharedBuffer_Name = 9;
        class Decryptor_ReleaseSharedBuffer_Params_Data {
        public:
            static Decryptor_ReleaseSharedBuffer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Decryptor_ReleaseSharedBuffer_Params_Data))) Decryptor_ReleaseSharedBuffer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data buffer;
            uint8_t pad0_[4];
            uint64_t buffer_size;

        private:
            Decryptor_ReleaseSharedBuffer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Decryptor_ReleaseSharedBuffer_Params_Data() = delete;
        };
        static_assert(sizeof(Decryptor_ReleaseSharedBuffer_Params_Data) == 24,
            "Bad sizeof(Decryptor_ReleaseSharedBuffer_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_SHARED_INTERNAL_H_