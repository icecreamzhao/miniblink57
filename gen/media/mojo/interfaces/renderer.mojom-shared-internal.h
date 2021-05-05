// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/demuxer_stream.mojom-shared-internal.h"
#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/common/unguessable_token.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace media {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kRenderer_Initialize_Name = 0;
        class Renderer_Initialize_Params_Data {
        public:
            static Renderer_Initialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_Initialize_Params_Data))) Renderer_Initialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data client;
            mojo::internal::Interface_Data audio;
            mojo::internal::Interface_Data video;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> media_url;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> first_party_for_cookies;

        private:
            Renderer_Initialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_Initialize_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_Initialize_Params_Data) == 48,
            "Bad sizeof(Renderer_Initialize_Params_Data)");
        class Renderer_Initialize_ResponseParams_Data {
        public:
            static Renderer_Initialize_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_Initialize_ResponseParams_Data))) Renderer_Initialize_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Renderer_Initialize_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_Initialize_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Renderer_Initialize_ResponseParams_Data) == 16,
            "Bad sizeof(Renderer_Initialize_ResponseParams_Data)");
        constexpr uint32_t kRenderer_Flush_Name = 1;
        class Renderer_Flush_Params_Data {
        public:
            static Renderer_Flush_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_Flush_Params_Data))) Renderer_Flush_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Renderer_Flush_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_Flush_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_Flush_Params_Data) == 8,
            "Bad sizeof(Renderer_Flush_Params_Data)");
        class Renderer_Flush_ResponseParams_Data {
        public:
            static Renderer_Flush_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_Flush_ResponseParams_Data))) Renderer_Flush_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Renderer_Flush_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_Flush_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Renderer_Flush_ResponseParams_Data) == 8,
            "Bad sizeof(Renderer_Flush_ResponseParams_Data)");
        constexpr uint32_t kRenderer_StartPlayingFrom_Name = 2;
        class Renderer_StartPlayingFrom_Params_Data {
        public:
            static Renderer_StartPlayingFrom_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_StartPlayingFrom_Params_Data))) Renderer_StartPlayingFrom_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> time;

        private:
            Renderer_StartPlayingFrom_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_StartPlayingFrom_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_StartPlayingFrom_Params_Data) == 16,
            "Bad sizeof(Renderer_StartPlayingFrom_Params_Data)");
        constexpr uint32_t kRenderer_SetPlaybackRate_Name = 3;
        class Renderer_SetPlaybackRate_Params_Data {
        public:
            static Renderer_SetPlaybackRate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_SetPlaybackRate_Params_Data))) Renderer_SetPlaybackRate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            double playback_rate;

        private:
            Renderer_SetPlaybackRate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_SetPlaybackRate_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_SetPlaybackRate_Params_Data) == 16,
            "Bad sizeof(Renderer_SetPlaybackRate_Params_Data)");
        constexpr uint32_t kRenderer_SetVolume_Name = 4;
        class Renderer_SetVolume_Params_Data {
        public:
            static Renderer_SetVolume_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_SetVolume_Params_Data))) Renderer_SetVolume_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float volume;
            uint8_t padfinal_[4];

        private:
            Renderer_SetVolume_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_SetVolume_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_SetVolume_Params_Data) == 16,
            "Bad sizeof(Renderer_SetVolume_Params_Data)");
        constexpr uint32_t kRenderer_SetCdm_Name = 5;
        class Renderer_SetCdm_Params_Data {
        public:
            static Renderer_SetCdm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_SetCdm_Params_Data))) Renderer_SetCdm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t cdm_id;
            uint8_t padfinal_[4];

        private:
            Renderer_SetCdm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_SetCdm_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_SetCdm_Params_Data) == 16,
            "Bad sizeof(Renderer_SetCdm_Params_Data)");
        class Renderer_SetCdm_ResponseParams_Data {
        public:
            static Renderer_SetCdm_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_SetCdm_ResponseParams_Data))) Renderer_SetCdm_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Renderer_SetCdm_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_SetCdm_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Renderer_SetCdm_ResponseParams_Data) == 16,
            "Bad sizeof(Renderer_SetCdm_ResponseParams_Data)");
        constexpr uint32_t kRenderer_InitiateScopedSurfaceRequest_Name = 6;
        class Renderer_InitiateScopedSurfaceRequest_Params_Data {
        public:
            static Renderer_InitiateScopedSurfaceRequest_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_InitiateScopedSurfaceRequest_Params_Data))) Renderer_InitiateScopedSurfaceRequest_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Renderer_InitiateScopedSurfaceRequest_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_InitiateScopedSurfaceRequest_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_InitiateScopedSurfaceRequest_Params_Data) == 8,
            "Bad sizeof(Renderer_InitiateScopedSurfaceRequest_Params_Data)");
        class Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data {
        public:
            static Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data))) Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> request_token;

        private:
            Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data) == 16,
            "Bad sizeof(Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data)");
        constexpr uint32_t kRendererClient_OnTimeUpdate_Name = 0;
        class RendererClient_OnTimeUpdate_Params_Data {
        public:
            static RendererClient_OnTimeUpdate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnTimeUpdate_Params_Data))) RendererClient_OnTimeUpdate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> time;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> max_time;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> capture_time;

        private:
            RendererClient_OnTimeUpdate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnTimeUpdate_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnTimeUpdate_Params_Data) == 32,
            "Bad sizeof(RendererClient_OnTimeUpdate_Params_Data)");
        constexpr uint32_t kRendererClient_OnBufferingStateChange_Name = 1;
        class RendererClient_OnBufferingStateChange_Params_Data {
        public:
            static RendererClient_OnBufferingStateChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnBufferingStateChange_Params_Data))) RendererClient_OnBufferingStateChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t state;
            uint8_t padfinal_[4];

        private:
            RendererClient_OnBufferingStateChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnBufferingStateChange_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnBufferingStateChange_Params_Data) == 16,
            "Bad sizeof(RendererClient_OnBufferingStateChange_Params_Data)");
        constexpr uint32_t kRendererClient_OnEnded_Name = 2;
        class RendererClient_OnEnded_Params_Data {
        public:
            static RendererClient_OnEnded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnEnded_Params_Data))) RendererClient_OnEnded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RendererClient_OnEnded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnEnded_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnEnded_Params_Data) == 8,
            "Bad sizeof(RendererClient_OnEnded_Params_Data)");
        constexpr uint32_t kRendererClient_OnError_Name = 3;
        class RendererClient_OnError_Params_Data {
        public:
            static RendererClient_OnError_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnError_Params_Data))) RendererClient_OnError_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RendererClient_OnError_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnError_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnError_Params_Data) == 8,
            "Bad sizeof(RendererClient_OnError_Params_Data)");
        constexpr uint32_t kRendererClient_OnVideoNaturalSizeChange_Name = 4;
        class RendererClient_OnVideoNaturalSizeChange_Params_Data {
        public:
            static RendererClient_OnVideoNaturalSizeChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnVideoNaturalSizeChange_Params_Data))) RendererClient_OnVideoNaturalSizeChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size;

        private:
            RendererClient_OnVideoNaturalSizeChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnVideoNaturalSizeChange_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnVideoNaturalSizeChange_Params_Data) == 16,
            "Bad sizeof(RendererClient_OnVideoNaturalSizeChange_Params_Data)");
        constexpr uint32_t kRendererClient_OnVideoOpacityChange_Name = 5;
        class RendererClient_OnVideoOpacityChange_Params_Data {
        public:
            static RendererClient_OnVideoOpacityChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnVideoOpacityChange_Params_Data))) RendererClient_OnVideoOpacityChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t opaque : 1;
            uint8_t padfinal_[7];

        private:
            RendererClient_OnVideoOpacityChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnVideoOpacityChange_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnVideoOpacityChange_Params_Data) == 16,
            "Bad sizeof(RendererClient_OnVideoOpacityChange_Params_Data)");
        constexpr uint32_t kRendererClient_OnStatisticsUpdate_Name = 6;
        class RendererClient_OnStatisticsUpdate_Params_Data {
        public:
            static RendererClient_OnStatisticsUpdate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnStatisticsUpdate_Params_Data))) RendererClient_OnStatisticsUpdate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::PipelineStatistics_Data> stats;

        private:
            RendererClient_OnStatisticsUpdate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnStatisticsUpdate_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnStatisticsUpdate_Params_Data) == 16,
            "Bad sizeof(RendererClient_OnStatisticsUpdate_Params_Data)");
        constexpr uint32_t kRendererClient_OnWaitingForDecryptionKey_Name = 7;
        class RendererClient_OnWaitingForDecryptionKey_Params_Data {
        public:
            static RendererClient_OnWaitingForDecryptionKey_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnWaitingForDecryptionKey_Params_Data))) RendererClient_OnWaitingForDecryptionKey_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RendererClient_OnWaitingForDecryptionKey_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnWaitingForDecryptionKey_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnWaitingForDecryptionKey_Params_Data) == 8,
            "Bad sizeof(RendererClient_OnWaitingForDecryptionKey_Params_Data)");
        constexpr uint32_t kRendererClient_OnDurationChange_Name = 8;
        class RendererClient_OnDurationChange_Params_Data {
        public:
            static RendererClient_OnDurationChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RendererClient_OnDurationChange_Params_Data))) RendererClient_OnDurationChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> duration;

        private:
            RendererClient_OnDurationChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RendererClient_OnDurationChange_Params_Data() = delete;
        };
        static_assert(sizeof(RendererClient_OnDurationChange_Params_Data) == 16,
            "Bad sizeof(RendererClient_OnDurationChange_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_SHARED_INTERNAL_H_