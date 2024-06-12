// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/string16.mojom-shared-internal.h"
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
namespace blink {
namespace mojom {
    namespace internal {
        class MediaImage_Data;
        class MediaMetadata_Data;

        struct MediaSessionAction_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct MediaSessionPlaybackState_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class MediaImage_Data {
        public:
            static MediaImage_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaImage_Data))) MediaImage_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> src;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> type;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::Size_Data>>> sizes;

        private:
            MediaImage_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaImage_Data() = delete;
        };
        static_assert(sizeof(MediaImage_Data) == 32,
            "Bad sizeof(MediaImage_Data)");
        class MediaMetadata_Data {
        public:
            static MediaMetadata_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaMetadata_Data))) MediaMetadata_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> title;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> artist;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> album;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::MediaImage_Data>>> artwork;

        private:
            MediaMetadata_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaMetadata_Data() = delete;
        };
        static_assert(sizeof(MediaMetadata_Data) == 40,
            "Bad sizeof(MediaMetadata_Data)");
        constexpr uint32_t kMediaSessionClient_DidReceiveAction_Name = 0;
        class MediaSessionClient_DidReceiveAction_Params_Data {
        public:
            static MediaSessionClient_DidReceiveAction_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaSessionClient_DidReceiveAction_Params_Data))) MediaSessionClient_DidReceiveAction_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t action;
            uint8_t padfinal_[4];

        private:
            MediaSessionClient_DidReceiveAction_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaSessionClient_DidReceiveAction_Params_Data() = delete;
        };
        static_assert(sizeof(MediaSessionClient_DidReceiveAction_Params_Data) == 16,
            "Bad sizeof(MediaSessionClient_DidReceiveAction_Params_Data)");
        constexpr uint32_t kMediaSessionService_SetClient_Name = 0;
        class MediaSessionService_SetClient_Params_Data {
        public:
            static MediaSessionService_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaSessionService_SetClient_Params_Data))) MediaSessionService_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            MediaSessionService_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaSessionService_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(MediaSessionService_SetClient_Params_Data) == 16,
            "Bad sizeof(MediaSessionService_SetClient_Params_Data)");
        constexpr uint32_t kMediaSessionService_SetPlaybackState_Name = 1;
        class MediaSessionService_SetPlaybackState_Params_Data {
        public:
            static MediaSessionService_SetPlaybackState_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaSessionService_SetPlaybackState_Params_Data))) MediaSessionService_SetPlaybackState_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t state;
            uint8_t padfinal_[4];

        private:
            MediaSessionService_SetPlaybackState_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaSessionService_SetPlaybackState_Params_Data() = delete;
        };
        static_assert(sizeof(MediaSessionService_SetPlaybackState_Params_Data) == 16,
            "Bad sizeof(MediaSessionService_SetPlaybackState_Params_Data)");
        constexpr uint32_t kMediaSessionService_SetMetadata_Name = 2;
        class MediaSessionService_SetMetadata_Params_Data {
        public:
            static MediaSessionService_SetMetadata_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaSessionService_SetMetadata_Params_Data))) MediaSessionService_SetMetadata_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::MediaMetadata_Data> metadata;

        private:
            MediaSessionService_SetMetadata_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaSessionService_SetMetadata_Params_Data() = delete;
        };
        static_assert(sizeof(MediaSessionService_SetMetadata_Params_Data) == 16,
            "Bad sizeof(MediaSessionService_SetMetadata_Params_Data)");
        constexpr uint32_t kMediaSessionService_EnableAction_Name = 3;
        class MediaSessionService_EnableAction_Params_Data {
        public:
            static MediaSessionService_EnableAction_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaSessionService_EnableAction_Params_Data))) MediaSessionService_EnableAction_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t action;
            uint8_t padfinal_[4];

        private:
            MediaSessionService_EnableAction_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaSessionService_EnableAction_Params_Data() = delete;
        };
        static_assert(sizeof(MediaSessionService_EnableAction_Params_Data) == 16,
            "Bad sizeof(MediaSessionService_EnableAction_Params_Data)");
        constexpr uint32_t kMediaSessionService_DisableAction_Name = 4;
        class MediaSessionService_DisableAction_Params_Data {
        public:
            static MediaSessionService_DisableAction_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaSessionService_DisableAction_Params_Data))) MediaSessionService_DisableAction_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t action;
            uint8_t padfinal_[4];

        private:
            MediaSessionService_DisableAction_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaSessionService_DisableAction_Params_Data() = delete;
        };
        static_assert(sizeof(MediaSessionService_DisableAction_Params_Data) == 16,
            "Bad sizeof(MediaSessionService_DisableAction_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_SHARED_INTERNAL_H_