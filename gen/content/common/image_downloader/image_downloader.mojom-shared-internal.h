// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_IMAGE_DOWNLOADER_IMAGE_DOWNLOADER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_IMAGE_DOWNLOADER_IMAGE_DOWNLOADER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "skia/public/interfaces/bitmap.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
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
        constexpr uint32_t kImageDownloader_DownloadImage_Name = 0;
        class ImageDownloader_DownloadImage_Params_Data {
        public:
            static ImageDownloader_DownloadImage_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ImageDownloader_DownloadImage_Params_Data))) ImageDownloader_DownloadImage_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            uint8_t is_favicon : 1;
            uint8_t bypass_cache : 1;
            uint8_t pad2_[3];
            uint32_t max_bitmap_size;

        private:
            ImageDownloader_DownloadImage_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ImageDownloader_DownloadImage_Params_Data() = delete;
        };
        static_assert(sizeof(ImageDownloader_DownloadImage_Params_Data) == 24,
            "Bad sizeof(ImageDownloader_DownloadImage_Params_Data)");
        class ImageDownloader_DownloadImage_ResponseParams_Data {
        public:
            static ImageDownloader_DownloadImage_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ImageDownloader_DownloadImage_ResponseParams_Data))) ImageDownloader_DownloadImage_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t http_status_code;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::skia::mojom::internal::Bitmap_Data>>> images;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::Size_Data>>> original_image_sizes;

        private:
            ImageDownloader_DownloadImage_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ImageDownloader_DownloadImage_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ImageDownloader_DownloadImage_ResponseParams_Data) == 32,
            "Bad sizeof(ImageDownloader_DownloadImage_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_IMAGE_DOWNLOADER_IMAGE_DOWNLOADER_MOJOM_SHARED_INTERNAL_H_