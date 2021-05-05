// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_FRAME_MESSAGE_FILTER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_RENDER_FRAME_MESSAGE_FILTER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kRenderFrameMessageFilter_SetCookie_Name = 0;
        class RenderFrameMessageFilter_SetCookie_Params_Data {
        public:
            static RenderFrameMessageFilter_SetCookie_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderFrameMessageFilter_SetCookie_Params_Data))) RenderFrameMessageFilter_SetCookie_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t render_frame_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> first_party_for_cookies;
            mojo::internal::Pointer<mojo::internal::String_Data> cookie;

        private:
            RenderFrameMessageFilter_SetCookie_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderFrameMessageFilter_SetCookie_Params_Data() = delete;
        };
        static_assert(sizeof(RenderFrameMessageFilter_SetCookie_Params_Data) == 40,
            "Bad sizeof(RenderFrameMessageFilter_SetCookie_Params_Data)");
        constexpr uint32_t kRenderFrameMessageFilter_GetCookies_Name = 1;
        class RenderFrameMessageFilter_GetCookies_Params_Data {
        public:
            static RenderFrameMessageFilter_GetCookies_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderFrameMessageFilter_GetCookies_Params_Data))) RenderFrameMessageFilter_GetCookies_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t render_frame_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> first_party_for_cookies;

        private:
            RenderFrameMessageFilter_GetCookies_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderFrameMessageFilter_GetCookies_Params_Data() = delete;
        };
        static_assert(sizeof(RenderFrameMessageFilter_GetCookies_Params_Data) == 32,
            "Bad sizeof(RenderFrameMessageFilter_GetCookies_Params_Data)");
        class RenderFrameMessageFilter_GetCookies_ResponseParams_Data {
        public:
            static RenderFrameMessageFilter_GetCookies_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderFrameMessageFilter_GetCookies_ResponseParams_Data))) RenderFrameMessageFilter_GetCookies_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> cookies;

        private:
            RenderFrameMessageFilter_GetCookies_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderFrameMessageFilter_GetCookies_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(RenderFrameMessageFilter_GetCookies_ResponseParams_Data) == 16,
            "Bad sizeof(RenderFrameMessageFilter_GetCookies_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDER_FRAME_MESSAGE_FILTER_MOJOM_SHARED_INTERNAL_H_