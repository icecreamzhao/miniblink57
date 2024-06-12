// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_DEMUXER_STREAM_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_DEMUXER_STREAM_MOJOM_SHARED_INTERNAL_H_

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
        using DemuxerStream_Type_Data = mojo::internal::NativeEnum_Data;
        using DemuxerStream_Status_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)
        constexpr uint32_t kDemuxerStream_Initialize_Name = 0;
        class DemuxerStream_Initialize_Params_Data {
        public:
            static DemuxerStream_Initialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DemuxerStream_Initialize_Params_Data))) DemuxerStream_Initialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DemuxerStream_Initialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DemuxerStream_Initialize_Params_Data() = delete;
        };
        static_assert(sizeof(DemuxerStream_Initialize_Params_Data) == 8,
            "Bad sizeof(DemuxerStream_Initialize_Params_Data)");
        class DemuxerStream_Initialize_ResponseParams_Data {
        public:
            static DemuxerStream_Initialize_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DemuxerStream_Initialize_ResponseParams_Data))) DemuxerStream_Initialize_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            mojo::internal::Handle_Data pipe;
            mojo::internal::Pointer<::media::mojom::internal::AudioDecoderConfig_Data> audio_config;
            mojo::internal::Pointer<::media::mojom::internal::VideoDecoderConfig_Data> video_config;

        private:
            DemuxerStream_Initialize_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DemuxerStream_Initialize_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DemuxerStream_Initialize_ResponseParams_Data) == 32,
            "Bad sizeof(DemuxerStream_Initialize_ResponseParams_Data)");
        constexpr uint32_t kDemuxerStream_Read_Name = 1;
        class DemuxerStream_Read_Params_Data {
        public:
            static DemuxerStream_Read_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DemuxerStream_Read_Params_Data))) DemuxerStream_Read_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DemuxerStream_Read_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DemuxerStream_Read_Params_Data() = delete;
        };
        static_assert(sizeof(DemuxerStream_Read_Params_Data) == 8,
            "Bad sizeof(DemuxerStream_Read_Params_Data)");
        class DemuxerStream_Read_ResponseParams_Data {
        public:
            static DemuxerStream_Read_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DemuxerStream_Read_ResponseParams_Data))) DemuxerStream_Read_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::media::mojom::internal::DecoderBuffer_Data> buffer;
            mojo::internal::Pointer<::media::mojom::internal::AudioDecoderConfig_Data> audio_config;
            mojo::internal::Pointer<::media::mojom::internal::VideoDecoderConfig_Data> video_config;

        private:
            DemuxerStream_Read_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DemuxerStream_Read_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DemuxerStream_Read_ResponseParams_Data) == 40,
            "Bad sizeof(DemuxerStream_Read_ResponseParams_Data)");
        constexpr uint32_t kDemuxerStream_EnableBitstreamConverter_Name = 2;
        class DemuxerStream_EnableBitstreamConverter_Params_Data {
        public:
            static DemuxerStream_EnableBitstreamConverter_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DemuxerStream_EnableBitstreamConverter_Params_Data))) DemuxerStream_EnableBitstreamConverter_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DemuxerStream_EnableBitstreamConverter_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DemuxerStream_EnableBitstreamConverter_Params_Data() = delete;
        };
        static_assert(sizeof(DemuxerStream_EnableBitstreamConverter_Params_Data) == 8,
            "Bad sizeof(DemuxerStream_EnableBitstreamConverter_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_DEMUXER_STREAM_MOJOM_SHARED_INTERNAL_H_