// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_IMAGE_DOWNLOADER_IMAGE_DOWNLOADER_MOJOM_SHARED_H_
#define CONTENT_COMMON_IMAGE_DOWNLOADER_IMAGE_DOWNLOADER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/image_downloader/image_downloader.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "skia/public/interfaces/bitmap.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ImageDownloaderInterfaceBase {
    };

    using ImageDownloaderPtrDataView = mojo::InterfacePtrDataView<ImageDownloaderInterfaceBase>;
    using ImageDownloaderRequestDataView = mojo::InterfaceRequestDataView<ImageDownloaderInterfaceBase>;
    using ImageDownloaderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ImageDownloaderInterfaceBase>;
    using ImageDownloaderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ImageDownloaderInterfaceBase>;
    class ImageDownloader_DownloadImage_ParamsDataView {
    public:
        ImageDownloader_DownloadImage_ParamsDataView() { }

        ImageDownloader_DownloadImage_ParamsDataView(
            internal::ImageDownloader_DownloadImage_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        bool is_favicon() const
        {
            return data_->is_favicon;
        }
        uint32_t max_bitmap_size() const
        {
            return data_->max_bitmap_size;
        }
        bool bypass_cache() const
        {
            return data_->bypass_cache;
        }

    private:
        internal::ImageDownloader_DownloadImage_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ImageDownloader_DownloadImage_ResponseParamsDataView {
    public:
        ImageDownloader_DownloadImage_ResponseParamsDataView() { }

        ImageDownloader_DownloadImage_ResponseParamsDataView(
            internal::ImageDownloader_DownloadImage_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t http_status_code() const
        {
            return data_->http_status_code;
        }
        inline void GetImagesDataView(
            mojo::ArrayDataView<::skia::mojom::BitmapDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadImages(UserType* output)
        {
            auto* pointer = data_->images.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::skia::mojom::BitmapDataView>>(
                pointer, output, context_);
        }
        inline void GetOriginalImageSizesDataView(
            mojo::ArrayDataView<::gfx::mojom::SizeDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOriginalImageSizes(UserType* output)
        {
            auto* pointer = data_->original_image_sizes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::SizeDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ImageDownloader_DownloadImage_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace content {
namespace mojom {

    inline void ImageDownloader_DownloadImage_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void ImageDownloader_DownloadImage_ResponseParamsDataView::GetImagesDataView(
        mojo::ArrayDataView<::skia::mojom::BitmapDataView>* output)
    {
        auto pointer = data_->images.Get();
        *output = mojo::ArrayDataView<::skia::mojom::BitmapDataView>(pointer, context_);
    }
    inline void ImageDownloader_DownloadImage_ResponseParamsDataView::GetOriginalImageSizesDataView(
        mojo::ArrayDataView<::gfx::mojom::SizeDataView>* output)
    {
        auto pointer = data_->original_image_sizes.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::SizeDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_IMAGE_DOWNLOADER_IMAGE_DOWNLOADER_MOJOM_SHARED_H_
