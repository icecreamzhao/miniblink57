// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_URL_LOADER_MOJOM_SHARED_H_
#define CONTENT_COMMON_URL_LOADER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/url_loader.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace content {
namespace mojom {
    using URLRequestDataView = mojo::NativeStructDataView;

    using URLResponseHeadDataView = mojo::NativeStructDataView;

    using URLRequestRedirectInfoDataView = mojo::NativeStructDataView;

    using URLLoaderStatusDataView = mojo::NativeStructDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class URLLoaderInterfaceBase {
    };

    using URLLoaderPtrDataView = mojo::InterfacePtrDataView<URLLoaderInterfaceBase>;
    using URLLoaderRequestDataView = mojo::InterfaceRequestDataView<URLLoaderInterfaceBase>;
    using URLLoaderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<URLLoaderInterfaceBase>;
    using URLLoaderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<URLLoaderInterfaceBase>;
    class DownloadedTempFileInterfaceBase {
    };

    using DownloadedTempFilePtrDataView = mojo::InterfacePtrDataView<DownloadedTempFileInterfaceBase>;
    using DownloadedTempFileRequestDataView = mojo::InterfaceRequestDataView<DownloadedTempFileInterfaceBase>;
    using DownloadedTempFileAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DownloadedTempFileInterfaceBase>;
    using DownloadedTempFileAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DownloadedTempFileInterfaceBase>;
    class URLLoaderClientInterfaceBase {
    };

    using URLLoaderClientPtrDataView = mojo::InterfacePtrDataView<URLLoaderClientInterfaceBase>;
    using URLLoaderClientRequestDataView = mojo::InterfaceRequestDataView<URLLoaderClientInterfaceBase>;
    using URLLoaderClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<URLLoaderClientInterfaceBase>;
    using URLLoaderClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<URLLoaderClientInterfaceBase>;
    class URLLoader_FollowRedirect_ParamsDataView {
    public:
        URLLoader_FollowRedirect_ParamsDataView() { }

        URLLoader_FollowRedirect_ParamsDataView(
            internal::URLLoader_FollowRedirect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::URLLoader_FollowRedirect_Params_Data* data_ = nullptr;
    };

    class URLLoaderClient_OnReceiveResponse_ParamsDataView {
    public:
        URLLoaderClient_OnReceiveResponse_ParamsDataView() { }

        URLLoaderClient_OnReceiveResponse_ParamsDataView(
            internal::URLLoaderClient_OnReceiveResponse_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetHeadDataView(
            URLResponseHeadDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHead(UserType* output)
        {
            auto* pointer = data_->head.Get();
            return mojo::internal::Deserialize<::content::mojom::URLResponseHeadDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDownloadedFile()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::DownloadedTempFilePtrDataView>(
                &data_->downloaded_file, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::URLLoaderClient_OnReceiveResponse_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class URLLoaderClient_OnReceiveRedirect_ParamsDataView {
    public:
        URLLoaderClient_OnReceiveRedirect_ParamsDataView() { }

        URLLoaderClient_OnReceiveRedirect_ParamsDataView(
            internal::URLLoaderClient_OnReceiveRedirect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRedirectInfoDataView(
            URLRequestRedirectInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRedirectInfo(UserType* output)
        {
            auto* pointer = data_->redirect_info.Get();
            return mojo::internal::Deserialize<::content::mojom::URLRequestRedirectInfoDataView>(
                pointer, output, context_);
        }
        inline void GetHeadDataView(
            URLResponseHeadDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHead(UserType* output)
        {
            auto* pointer = data_->head.Get();
            return mojo::internal::Deserialize<::content::mojom::URLResponseHeadDataView>(
                pointer, output, context_);
        }

    private:
        internal::URLLoaderClient_OnReceiveRedirect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class URLLoaderClient_OnDataDownloaded_ParamsDataView {
    public:
        URLLoaderClient_OnDataDownloaded_ParamsDataView() { }

        URLLoaderClient_OnDataDownloaded_ParamsDataView(
            internal::URLLoaderClient_OnDataDownloaded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t data_length() const
        {
            return data_->data_length;
        }
        int64_t encoded_length() const
        {
            return data_->encoded_length;
        }

    private:
        internal::URLLoaderClient_OnDataDownloaded_Params_Data* data_ = nullptr;
    };

    class URLLoaderClient_OnReceiveCachedMetadata_ParamsDataView {
    public:
        URLLoaderClient_OnReceiveCachedMetadata_ParamsDataView() { }

        URLLoaderClient_OnReceiveCachedMetadata_ParamsDataView(
            internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class URLLoaderClient_OnTransferSizeUpdated_ParamsDataView {
    public:
        URLLoaderClient_OnTransferSizeUpdated_ParamsDataView() { }

        URLLoaderClient_OnTransferSizeUpdated_ParamsDataView(
            internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t transfer_size_diff() const
        {
            return data_->transfer_size_diff;
        }

    private:
        internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data* data_ = nullptr;
    };

    class URLLoaderClient_OnStartLoadingResponseBody_ParamsDataView {
    public:
        URLLoaderClient_OnStartLoadingResponseBody_ParamsDataView() { }

        URLLoaderClient_OnStartLoadingResponseBody_ParamsDataView(
            internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedDataPipeConsumerHandle TakeBody()
        {
            mojo::ScopedDataPipeConsumerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeConsumerHandle>(
                &data_->body, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class URLLoaderClient_OnComplete_ParamsDataView {
    public:
        URLLoaderClient_OnComplete_ParamsDataView() { }

        URLLoaderClient_OnComplete_ParamsDataView(
            internal::URLLoaderClient_OnComplete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCompletionStatusDataView(
            URLLoaderStatusDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCompletionStatus(UserType* output)
        {
            auto* pointer = data_->completion_status.Get();
            return mojo::internal::Deserialize<::content::mojom::URLLoaderStatusDataView>(
                pointer, output, context_);
        }

    private:
        internal::URLLoaderClient_OnComplete_Params_Data* data_ = nullptr;
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

    inline void URLLoaderClient_OnReceiveResponse_ParamsDataView::GetHeadDataView(
        URLResponseHeadDataView* output)
    {
        auto pointer = data_->head.Get();
        *output = URLResponseHeadDataView(pointer, context_);
    }

    inline void URLLoaderClient_OnReceiveRedirect_ParamsDataView::GetRedirectInfoDataView(
        URLRequestRedirectInfoDataView* output)
    {
        auto pointer = data_->redirect_info.Get();
        *output = URLRequestRedirectInfoDataView(pointer, context_);
    }
    inline void URLLoaderClient_OnReceiveRedirect_ParamsDataView::GetHeadDataView(
        URLResponseHeadDataView* output)
    {
        auto pointer = data_->head.Get();
        *output = URLResponseHeadDataView(pointer, context_);
    }

    inline void URLLoaderClient_OnReceiveCachedMetadata_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void URLLoaderClient_OnComplete_ParamsDataView::GetCompletionStatusDataView(
        URLLoaderStatusDataView* output)
    {
        auto pointer = data_->completion_status.Get();
        *output = URLLoaderStatusDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_URL_LOADER_MOJOM_SHARED_H_
