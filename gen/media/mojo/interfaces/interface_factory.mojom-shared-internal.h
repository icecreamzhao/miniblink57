// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/audio_decoder.mojom-shared-internal.h"
#include "media/mojo/interfaces/content_decryption_module.mojom-shared-internal.h"
#include "media/mojo/interfaces/renderer.mojom-shared-internal.h"
#include "media/mojo/interfaces/video_decoder.mojom-shared-internal.h"
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
        constexpr uint32_t kInterfaceFactory_CreateAudioDecoder_Name = 0;
        class InterfaceFactory_CreateAudioDecoder_Params_Data {
        public:
            static InterfaceFactory_CreateAudioDecoder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceFactory_CreateAudioDecoder_Params_Data))) InterfaceFactory_CreateAudioDecoder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data audio_decoder;
            uint8_t padfinal_[4];

        private:
            InterfaceFactory_CreateAudioDecoder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceFactory_CreateAudioDecoder_Params_Data() = delete;
        };
        static_assert(sizeof(InterfaceFactory_CreateAudioDecoder_Params_Data) == 16,
            "Bad sizeof(InterfaceFactory_CreateAudioDecoder_Params_Data)");
        constexpr uint32_t kInterfaceFactory_CreateVideoDecoder_Name = 1;
        class InterfaceFactory_CreateVideoDecoder_Params_Data {
        public:
            static InterfaceFactory_CreateVideoDecoder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceFactory_CreateVideoDecoder_Params_Data))) InterfaceFactory_CreateVideoDecoder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data video_decoder;
            uint8_t padfinal_[4];

        private:
            InterfaceFactory_CreateVideoDecoder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceFactory_CreateVideoDecoder_Params_Data() = delete;
        };
        static_assert(sizeof(InterfaceFactory_CreateVideoDecoder_Params_Data) == 16,
            "Bad sizeof(InterfaceFactory_CreateVideoDecoder_Params_Data)");
        constexpr uint32_t kInterfaceFactory_CreateRenderer_Name = 2;
        class InterfaceFactory_CreateRenderer_Params_Data {
        public:
            static InterfaceFactory_CreateRenderer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceFactory_CreateRenderer_Params_Data))) InterfaceFactory_CreateRenderer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> audio_device_id;
            mojo::internal::Handle_Data renderer;
            uint8_t padfinal_[4];

        private:
            InterfaceFactory_CreateRenderer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceFactory_CreateRenderer_Params_Data() = delete;
        };
        static_assert(sizeof(InterfaceFactory_CreateRenderer_Params_Data) == 24,
            "Bad sizeof(InterfaceFactory_CreateRenderer_Params_Data)");
        constexpr uint32_t kInterfaceFactory_CreateCdm_Name = 3;
        class InterfaceFactory_CreateCdm_Params_Data {
        public:
            static InterfaceFactory_CreateCdm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceFactory_CreateCdm_Params_Data))) InterfaceFactory_CreateCdm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data cdm;
            uint8_t padfinal_[4];

        private:
            InterfaceFactory_CreateCdm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceFactory_CreateCdm_Params_Data() = delete;
        };
        static_assert(sizeof(InterfaceFactory_CreateCdm_Params_Data) == 16,
            "Bad sizeof(InterfaceFactory_CreateCdm_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_SHARED_INTERNAL_H_