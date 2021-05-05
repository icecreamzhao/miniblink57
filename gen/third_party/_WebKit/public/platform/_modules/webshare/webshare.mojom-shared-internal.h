// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_SHARED_INTERNAL_H_

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
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kShareService_Share_Name = 0;
        class ShareService_Share_Params_Data {
        public:
            static ShareService_Share_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ShareService_Share_Params_Data))) ShareService_Share_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> title;
            mojo::internal::Pointer<mojo::internal::String_Data> text;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;

        private:
            ShareService_Share_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ShareService_Share_Params_Data() = delete;
        };
        static_assert(sizeof(ShareService_Share_Params_Data) == 32,
            "Bad sizeof(ShareService_Share_Params_Data)");
        class ShareService_Share_ResponseParams_Data {
        public:
            static ShareService_Share_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ShareService_Share_ResponseParams_Data))) ShareService_Share_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> error;

        private:
            ShareService_Share_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ShareService_Share_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ShareService_Share_ResponseParams_Data) == 16,
            "Bad sizeof(ShareService_Share_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_SHARED_INTERNAL_H_